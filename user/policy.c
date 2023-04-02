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
        if (*argv[1] >= '0' && *argv[1] <= '2') {
            if(!set_policy(atoi(argv[1]))){
                exit(0,"");
            }
            else{
                exit(1,"Wrong policy code: use 0/1/2");
            }
        }    
        else {
            exit(1,"Wrong policy code: use 0/1/2");
        }
    }
    else if(argc > 2) {
        exit(1,"Too many arguments in policy");
    }
   else {
        exit(1,"Policy code argument missing");
   }

}