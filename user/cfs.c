#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(){
     printf("starting the cfs");
    int pid1=fork();
    if (pid1==0){
        if( set_cfs_priority(0)==-1){
            return -1;
        }
        for (int i=0;i<1000000;i++){
            if(i%100000==0){
                sleep(1);
            }
            }
        int p[5];
        get_cfs_status((int*)&p);
        sleep(15);
        printf("process pid %d with cfs priority: %d - status: run time %d , runnable time %d, sleep time:%d\n",p[0],p[1],p[2], p[3],p[4]);
        exit(0,"");
    }
    else{
        int pid2=fork();
        if (pid2==0){
        if( set_cfs_priority(1)==-1){
            return -1;
        }
            for (int i=0;i<1000000;i++){
                if(i%100000==0){
                sleep(1);
            }
        }
            int p[5];
            get_cfs_status((int*)&p);
            sleep(10);
            printf("process pid %d with cfs priority: %d - status: run time %d , runnable time %d, sleep time:%d\n",p[0],p[1],p[2], p[3],p[4]);
            exit(0,"");

     }
     else{
        int pid3=fork();
        if (pid3==0){
        if( set_cfs_priority(2)==-1){
            return -1;
        }
            for (int i=0;i<1000000;i++){
                if(i%100000==0){
                sleep(1);

            }
        }
            int p[5];
            get_cfs_status((int*)&p);
            sleep(5);
            printf("process pid %d with cfs priority: %d - status: run time %d , runnable time %d, sleep time:%d\n",p[0],p[1],p[2], p[3],p[4]);
            exit(0,"");
        }
        else{
        wait(0,0);   
        wait(0,0); 
        wait(0,0); 
   
        }


     }
    }
    exit(0,"finished cfs.c");   
    return 1;
}
