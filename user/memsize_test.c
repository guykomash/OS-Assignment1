#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"


int main() {

    printf("memsize before malloc: %d \n",memsize());
    
    void * memory =  malloc(20000);

    printf("memsize after malloc : %d \n",memsize());

    
    free(memory);

    printf("memsize after free : %d \n",memsize());

    exit(0,"memsize_test");
}