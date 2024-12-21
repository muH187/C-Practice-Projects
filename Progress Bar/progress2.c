#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

int const BAR_LENGTH = 50;
int const NUM_OF_TASKS = 5;


typedef struct {
    int id;
    int progress;
    int step;
} Task;

void printBar(Task task);
void clearScreen();

int main() {

    srand(time(NULL));

    Task task[NUM_OF_TASKS];

    for(int i = 0; i < NUM_OF_TASKS; i++) {
        task[i].id = i + 1;
        task[i].progress = 0;
        task[i].step = (rand() % 5) + 1;
    }

    int tasksIncomplete = 1;
    while(tasksIncomplete) {
        tasksIncomplete = 0;
        clearScreen();

        for(int i = 0; i < NUM_OF_TASKS; i++) {
            task[i].progress += task[i].step;
            if(task[i].progress < 100) {
                tasksIncomplete = 1;
            } else if(task[i].progress > 100) {
                task[i].progress = 100;
            }
            printBar(task[i]);

        }
            sleep(1);
    }

    printf("All Tasks are completed.");

    return 0;
}

void printBar(Task task) {
    int progress = task.progress;
    int barToShow = (progress * BAR_LENGTH) / 100;

    printf("Task %d: [", task.id);
    for(int i = 0; i < BAR_LENGTH; i++) {
        if(i < barToShow) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%\n", progress); 
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}