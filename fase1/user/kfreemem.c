#include "kernel/memlayout.h"
#include "kernel/types.h"
#include "user/user.h"

int main() {
    uint64 free = kfreememfunc();
    uint64 all = PHYSTOP - KERNBASE;//128*1024*1024
    printf("free memory: %d .\n", free);
    printf("all memory: %d .\n", all); 
    exit(0);
}