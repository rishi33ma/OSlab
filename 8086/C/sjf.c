#include<stdio.h>


void sort(int processes[], int n, int bt[]){


    for(int i=0;i<n-1;i++){

        for(int j=0;j<n-i-1;j++){

            if(bt[j+1] < bt[j]){
            int temp = bt[j];
            bt[j] = bt[j+1];
            bt[j+1] = temp;
            
            int x = processes[j];
            processes[j] = processes[j+1];
            processes[j+1] = x;
            
            
        }
        }

        
    }
}

void calcluatetime(int processes[], int n, int bt[]){

    sort(processes,n,bt);

    int finishtime[n];
    int turnaround[n];
    int waiting[n];

    finishtime[0] = bt[0];
    for(int i=1;i<n;i++){
        finishtime[i] = finishtime[i-1] + bt[i];
    }

    for(int i=0;i<n;i++){

        turnaround[i] = finishtime[i];
        waiting[i] = turnaround[i] - bt[i];
    }

    printf("Process\tFinish Time\tTurnaround Time\tWaiting Time\n");

    for(int i=0;i<n;i++){
        printf("%d\t\t %d\t\t %d\t\t %d\n",processes[i],finishtime[i], turnaround[i],waiting[i]);
    }
    
}

int main(){

    int n;
    printf("ENter the no. of processes\n");
    scanf("%d",&n);

    int processes[n];
    int bt[n];

    for(int i=0;i<n;i++){

        printf("Enter the burst time for process id %d ",i+1);
        scanf("%d",&bt[i]);
        processes[i] = i+1;
    }

    calcluatetime(processes,n,bt);

    return 0;

}