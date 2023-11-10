#include <stdio.h>
#include <stdlib.h>

// Structure to represent a task
struct Task {
    int id;
    int burst_time;
};

// Structure to represent a node in the queue
struct Node {
    struct Task task;
    struct Node* next;
};

// Structure to represent a queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new task
struct Task createTask(int id, int burst_time) {
    struct Task task;
    task.id = id;
    task.burst_time = burst_time;
    return task;
}

// Function to create a new node
struct Node* createNode(struct Task task) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->task = task;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue createQueue() {
    struct Queue q;
    q.front = q.rear = NULL;
    return q;
}

// Function to enqueue a task in the queue
void enqueue(struct Queue* q, struct Task task) {
    struct Node* newNode = createNode(task);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to dequeue a task from the queue
struct Task dequeue(struct Queue* q) {
    if (q->front == NULL) {
        struct Task emptyTask = createTask(-1, 0); // Empty task with ID -1
        return emptyTask;
    }

    struct Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    struct Task task = temp->task;
    free(temp);
    return task;
}

// Function to simulate the round-robin scheduling algorithm
void roundRobinScheduling(struct Task tasks[], int n, int time_quantum) {
    struct Queue q = createQueue();
    int remaining_time[n];

    for (int i = 0; i < n; i++) {
        enqueue(&q, tasks[i]);
        remaining_time[i] = tasks[i].burst_time;
    }

    int time = 0;
    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;
                if (remaining_time[i] > time_quantum) {
                    time += time_quantum;
                    remaining_time[i] -= time_quantum;
                    printf("Task %d executed for time quantum %d\n", tasks[i].id, time_quantum);
                } else {
                    time += remaining_time[i];
                    remaining_time[i] = 0;
                    printf("Task %d completed\n", tasks[i].id);
                }
            }
        }

        if (done == 1) {
            break;
        }
    }
}

int main() {
    int n = 5; // Number of tasks
    struct Task tasks[n];

    tasks[0] = createTask(1, 10);
    tasks[1] = createTask(2, 5);
    tasks[2] = createTask(3, 8);
    tasks[3] = createTask(4, 3);
    tasks[4] = createTask(5, 6);

    int time_quantum = 2;

    printf("Round-Robin Scheduling:\n");
    roundRobinScheduling(tasks, n, time_quantum);

    return 0;
}
