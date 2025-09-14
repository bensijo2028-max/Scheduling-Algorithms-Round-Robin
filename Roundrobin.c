#include <stdio.h>

int main() {
    int n, i, time, tq, count = 0, temp;
    int wt = 0, tat = 0, sq = 0;
    int flag = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int burst_time[n], rem_bt[n], wait_time[n], turn_around_time[n], process[n];
    
    printf("Enter burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &burst_time[i]);
        rem_bt[i] = burst_time[i]; 
        process[i] = i+1;
    }
    
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    
    printf("\nGantt Chart:\n|");
    
    int done = 0;
    time = 0;
    
   
    while(done < n) {
        flag = 0; 
        for(i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                flag = 1;
                if(rem_bt[i] > tq) {
                    time += tq;
                    rem_bt[i] -= tq;
                    printf("  P%d  |", process[i]);
                } else {
                    time += rem_bt[i];
                    printf("  P%d  |", process[i]);
                    wait_time[i] = time - burst_time[i];
                    rem_bt[i] = 0;
                    done++;
                }
            }
        }
        if(flag == 0) break;
    }
    
   
    for(i = 0; i < n; i++) {
        turn_around_time[i] = burst_time[i] + wait_time[i];
    }
    
    
    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", process[i], burst_time[i], wait_time[i], turn_around_time[i]);
        wt += wait_time[i];
        tat += turn_around_time[i];
    }
    
    printf("\nAverage Waiting Time = %.2f", (float)wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)tat/n);
    
    return 0;
}
