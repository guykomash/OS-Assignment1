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

    int failure = 1;

    if(argc == 2) {
        int policy = atoi(argv[1]);
        failure = set_policy(policy);

        if(!failure){
            exit(0,"");
        }
        else {
            exit(1,"ERROR: Wrong policy code");
        }
    }
    else if(argc > 2) {
        exit(1,"ERROR: Too many arguments in policy");
    }
   else {
        exit(1,"ERROR: Policy code argument missing");
   }

}