#include "kernel/memlayout.h"
#include "kernel/pstat.h"
#include "kernel/types.h"
#include "user/user.h"

int heavy_calculation(void) {
    int a = 0;
    int b = 0;
    for (int i = 0; i < 100000; ++i) {
        for (int j = 0; j < 10000; ++j) {
            a = i - j;
            b = a % 10;
        }
    }
    return a * b;
}

int main() {
    settickets(10);

    int pid = fork();
    if (pid < 0) {
        printf("fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // settickets(20);

        printf("calculation res: %d\n", heavy_calculation());

        struct pstat ps;
        getpinfo(&ps);

        printf("child call to getpinfo results:\n");
        for (int j = 0; j < ps.cnt; ++j) {
            printf("pid %d, tickets %d, ticks %d\n", ps.pids[j], ps.tickets[j], ps.ticks[j]);
        }

        exit(0);
    } else {
        wait(0);
        printf("child finished\n");

        struct pstat ps;
        getpinfo(&ps);

        printf("parent call to getpinfo results:\n");
        for (int j = 0; j < ps.cnt; ++j) {
            printf("pid %d, tickets %d, ticks %d\n", ps.pids[j], ps.tickets[j], ps.ticks[j]);
        }

        exit(0);
    }
}
