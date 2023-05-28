#include "param.h"

struct pstat {
    int cnt;
    int pids[NPROC];
    int tickets[NPROC];
    int ticks[NPROC];
};
