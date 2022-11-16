#include "kernel/memlayout.h"
#include "kernel/types.h"
#include "user/user.h"

int main() {
    uint64 free = freemem();
    uint64 all = PHYSTOP - KERNBASE;
    printf("free memory: %d bytes.\n", free);
    printf("used memory: %d bytes.\n", all - free);
    printf("all memory: %d bytes.\n", all);
    printf("all memory: %d ",free);
    exit(0);
}