#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

typedef struct {
    int hr;
    int min;
    int sec;
} Time;

int timeToSeconds(Time t) {
    return t.hr * 3600 + t.min * 60 + t.sec;
}

int main() {
    Time t1, t2;
    int temp1, temp2, temp3;

    printf("Enter First Time (Hr Min Sec): ");
    scanf("%d %d %d", &temp1, &temp2, &temp3);
    t1.hr = temp1;
    t1.min = temp2;
    t1.sec = temp3;

    printf("Enter Second Time (Hr Min Sec): ");
    scanf("%d %d %d", &temp1, &temp2, &temp3);
    t2.hr = temp1;
    t2.min = temp2;
    t2.sec = temp3;

    int start_time = timeToSeconds(t1);
    int end_time = timeToSeconds(t2);
    int diff = end_time - start_time;

    if (diff < 0) {
        printf("End time is before start time.\n");
        return 1;
    }

    for (int i = 0; i < diff; i++) {
        printf("GOOD DAY\n");
        sleep(1); 
    }
    return 0;
}
