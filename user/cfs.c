#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void main(){

    int pid1=fork();
    if (pid1==0){
        set_cfs_priority(0);
        for (int i=0;i<10000000;i++){
            if(i%100000==0){
                sleep(1);
            }
            }
        int p[4];
        get_cfs_status((int*)&p);
        sleep(15);
        printf("prcossec pid %d cfs status: runnable time %d , run time %d, sleep time:%d\n",p[0],p[1],p[2], p[3]);
    }
    else{
        int pid2=fork();
        if (pid2==0){
            set_cfs_priority(1);
            for (int i=0;i<10000000;i++){
                if(i%100000==0){
                sleep(1);
            }
        }
            int p[4];
            get_cfs_status((int*)&p);
            sleep(10);
            printf("prcossec pid %d cfs status: runnable time %d , run time %d, sleep time:%d\n",p[0],p[1],p[2], p[3]);

     }
     else{
        int pid3=fork();
        if (pid3==0){
            set_cfs_priority(2);
            for (int i=0;i<10000000;i++){
                if(i%100000==0){
                sleep(1);

            }
        }
            int p[4];
            get_cfs_status((int*)&p);
            sleep(5);
            printf("prcossec pid %d cfs status: runnable time %d , run time %d, sleep time:%d\n",p[0],p[1],p[2], p[3]);
        }
        else{
        // int s;
        // int exit_msg[32];
        // printf("trying to print cfs details\n");
        wait(0,0);   
        wait(0,0); 
        wait(0,0); 
            //    int p[4];
            // get_cfs_status((int*)&p);
            // sleep(5);
            // printf("prcossec pid %d cfs status: runnable time %d , run time %d, sleep time:%d\n",p[0],p[1],p[2], p[3]);
        exit(0,"");    
        }


     }
    }
}
