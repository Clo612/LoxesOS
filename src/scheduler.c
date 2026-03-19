#include "kernel.h"

typedef struct {
    uint64_t rip;
} Task;

#define MAX_TASKS 2
Task tasks[MAX_TASKS];
int current_task = 0;

void init_scheduler() {
    tasks[0].rip = (uint64_t)&&task1;
    tasks[1].rip = (uint64_t)&&task2;

task1:
    kprint("Task 1 running...\n");
    goto *tasks[1].rip;

task2:
    kprint("Task 2 running...\n");
    goto *tasks[0].rip;
}
