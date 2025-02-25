#include <stdio.h>

void roundRobin(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n], rem_bt[n]; 
    int total_wt = 0, total_tat = 0;
    
    for (int i = 0; i < n; i++) 
        rem_bt[i] = bt[i];

    int t = 0; 

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i]; 
                    rem_bt[i] = 0;
                }
            }
        }
        if (done) break;
    }

    for (int i = 0; i < n; i++) 
        tat[i] = bt[i] + wt[i];

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int processes[n], bt[n];

    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    roundRobin(processes, n, bt, quantum);
    return 0;
}
