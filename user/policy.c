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

    if(argc == 2) {
        if ( (*argv[1] >= '0' && *argv[1] <= '2') && !set_policy(atoi(argv[1]))){
                exit(0,"");
            }
            else fprintf(2,"Wrong policy code: use 0/1/2\n");
                
        }
    else if(argc > 2) 
        fprintf(2,"Too many arguments in policy\n");
   else 
        fprintf(2,"Policy code argument missing\n");
   
   exit(1,"");
}