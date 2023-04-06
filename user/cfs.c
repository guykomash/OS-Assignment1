#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void main(){

    int pid1=fork();
    printf("my pid:%d",pid1);
    if (pid1==0){
        set_cfs_priority(0);
        for (int i=0;i<100000000;i++){
            if(i%100000==0)
                sleep(1);
        }
        get_cfs_status();
    }
    else{
        int pid2=fork();
        if (pid2==0){
            set_cfs_priority(1);
            for (int i=0;i<10000000;i++){
                if(i%100000==0)
                    sleep(1);
        }
            get_cfs_status();
     }
     else{
        int pid3=fork();
        if (pid3==0){
            set_cfs_priority(2);
            for (int i=0;i<10000000;i++){
                if(i%100000==0)
                    sleep(1);
            }
            get_cfs_status();
        }
        else{
        // int s;
        // int exit_msg[32];
        // printf("trying to print cfs details\n");
        wait(0,0);   
        wait(0,0); 
        wait(0,0); 
        exit(0,"");    
        }


     }
    }
}
