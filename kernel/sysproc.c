#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

int sched_policy;


/*
int
argstr(int n, char *buf, int max)
{
  uint64 addr;
  argaddr(n, &addr);
  return fetchstr(addr, buf, max);
}
*/

uint64
sys_exit(void)
{
  int n;
  char  msg[32];//Task3

  argstr(1, msg, 32);
  argint(0, &n);
  exit(n,msg);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  uint64 s;
  argaddr(0, &p);
  argaddr(1, &s); //task 3
  return wait(p,s); //task 3
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0) 
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

uint64
sys_memsize(void)
{
  return myproc()->sz;
}

uint64
sys_set_ps_priority(void)
{
  int p;
  argint(0,&p);
  printf("Process [id=%d] old priority: %d\n",myproc()->pid,myproc()->ps_priority);
  myproc()->ps_priority  = p;
  printf("Procees [id=%d] new priority: %d\n",myproc()->pid,myproc()->ps_priority);
  return p;
}

//task6
uint64
sys_set_cfs_priority(void){
  int p;
  argint(0,&p);
  if (p==0 || p==1 || p==2){
    printf("setting  %d priority to %s process\n",p,myproc()->name);
    myproc()->cfs_priority=p;
    return 0;
  }
  else
    return -1;
  }

void
sys_get_cfs_status(void){
  printf("prcossec pid %d cfs status: runnable time %d , run time %d, sleep time:%d\n",myproc()->pid,myproc()->retime,myproc()->rtime, myproc()->stime);
}



//task 7
uint64
sys_set_policy(void)
{
  int p;
  argint(0,&p);

  if(p == 0 || p==1 || p==2){
    printf("policy changing from %d to %d\n",sched_policy,p);
    sched_policy = p;
    return 0;
  }
  return -1;
}