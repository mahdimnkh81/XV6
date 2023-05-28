#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "defs.h"

extern struct proc proc[NPROC];

uint64
sys_kfreememfunc(void)
{
  uint64 used = 0;
  struct proc *p;

  for (p = proc; p < &proc[NPROC]; ++p) {

    if (p->state == UNUSED)
      continue;

    acquire(&p->lock);
    
    used += p->sz;

    release(&p->lock);
  }

  return (128*1024*1024) - used;
  
}