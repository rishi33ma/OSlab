#include <stdio.h>

void calculateTimes(int processes[], int n, int bt[]) {
    
    int finish_time[n];
    int turnaround_time[n];
    int waiting_time[n];

    
    finish_time[0] = bt[0];
    for (int i = 1; i < n; i++) {
        finish_time[i] = finish_time[i - 1] + bt[i];
    }

    
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = finish_time[i];
        waiting_time[i] = turnaround_time[i] - bt[i];
    }

    
    printf("Process\tBurst Time\tFinish Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], finish_time[i], turnaround_time[i], waiting_time[i]);
    }
}

int main() {
    
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    
    int processes[n];
    int bt[n];

    
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        processes[i] = i + 1;
    }

   
    calculateTimes(processes, n, bt);

    return 0;
}
