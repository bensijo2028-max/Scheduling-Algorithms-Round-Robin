CPU Scheduling Algorithms written in C:

Shortest Job First (SJF) – Non-Preemptive

Selects the process with the shortest burst time from the ready queue.

Non-preemptive: once a process starts, it runs until completion.

Improves average waiting time but may cause starvation for longer processes.

Output includes:

Gantt Chart

Completion Time (CT)

Turnaround Time (TAT)

Waiting Time (WT)

Average TAT & WT

Round Robin (RR)

Each process gets a fixed time quantum in cyclic order.

Preemptive: if a process doesn’t finish in its quantum, it goes back to the queue.

Provides fairness and avoids starvation.

Output includes:

Gantt Chart with time slices

CT, TAT, WT for each process

Average TAT & WT

Features

Written in C for clarity and simplicity.

Console-based input/output.

Helps in understanding CPU scheduling concepts.
