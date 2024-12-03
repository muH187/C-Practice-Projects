#include<stdio.h>
#include<time.h>

void fill_time(char*);

int main(){

    // printf("Choose the time format:\n1. 24 Hour Format\n2. 12 Hour Format (default)\n");

    // printf("Make a choice(1/2): ");
    // scanf("%d", &choice);

    // if(choice < 1 || choice > 2) {
    //     printf("Invalid Choice!");
    // }

    
    char time[50];
    fill_time(time);

    printf("Current Time: %s", time);

    return 0;
}

void fill_time(char* buffer) {
    time_t rawtime;
    struct tm *current_time;
 

    time(&rawtime);
    current_time = localtime(&rawtime);
    strftime(buffer, 50, "%I:%M:%S %p", current_time);

}