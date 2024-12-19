#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

int const BAR_LENGTH = 60;
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
    Task tasks[NUM_OF_TASKS];

    for(int i = 0; i < NUM_OF_TASKS; i++) {
        tasks[i].id = i + 1;
        tasks[i].progress = 0;
        tasks[i].step = (rand() % 5) + 1;
    }

    int tasks_incomplete = 1;

    while(tasks_incomplete) {
        tasks_incomplete = 0;
        clearScreen();

        for(int i = 0; i < NUM_OF_TASKS; i++) {
            tasks[i].progress += tasks[i].step;
            if(tasks[i].progress > 100) {
                tasks[i].progress = 100;
            } else if(tasks[i].progress < 100) {
                tasks_incomplete = 1;
            }
            printBar(tasks[i]);
        }

        sleep(1);

    }

    printf("\nAll tasks are completed!\n"); 

    return 0;
}

void printBar(Task task) {
    int barToShow = (task.progress * BAR_LENGTH) / 100;

    printf("\nTask %d: [", task.id);
    for(int i = 0; i < BAR_LENGTH; i++) {
        if(i < barToShow) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%", task.progress);
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}