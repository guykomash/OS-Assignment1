#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"



int main( int argc, char *argv[] ) {


    if(argc==2){
        if(*argv[1] >= '0' && *argv[1] <= '2')
            if(!set_policy(atoi(argv[1])))
                  exit(0,"");
    } 

    fprintf(2,"usage: policy [policy code]\n0-default xv6 policy\n1-priority scheduling\n2-CFS with priority decay\n");
    exit(1,"");
}