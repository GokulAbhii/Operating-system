#include <stdio.h>
#include <stdbool.h>
struct Process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};
void sortProcessesByBurstTime(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}
void calculateTimes(struct Process processes[], int n) {
    processes[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}
void calculateAverages(struct Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}
void displayProcesses(struct Process processes[], int n) {
    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}
int main() {
    int n = 4;
    struct Process processes[] = {
        {1, 6, 0, 0},
        {2, 8, 0, 0},
        {3, 7, 0, 0},
        {4, 3, 0, 0}
    };
    sortProcessesByBurstTime(processes, n);
    calculateTimes(processes, n);

    displayProcesses(processes, n);
    calculateAverages(processes, n);
    return 0;
}
