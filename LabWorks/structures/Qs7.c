#include <stdio.h>

struct time {
    int hr;
    int min;
    int sec;
};

void add_time(int hr1, int min1, int sec1, int hr2, int min2, int sec2) {
    int time1 = 3600 * hr1 + 60 * min1 + sec1;
    int time2 = 3600 * hr2 + 60 * min2 + sec2;
    int total_seconds = time1 + time2;
    
    int final_hr = total_seconds / 3600;
    total_seconds %= 3600;
    int final_min = total_seconds / 60;
    int final_sec = total_seconds % 60;
    
    printf("Added: %dhrs %dmins %dsec\n", final_hr, final_min, final_sec);
}

void subtract_time(int hr1, int min1, int sec1, int hr2, int min2, int sec2) {
    int time1 = 3600 * hr1 + 60 * min1 + sec1;
    int time2 = 3600 * hr2 + 60 * min2 + sec2;
    int total_seconds = time1 - time2;

    if (total_seconds < 0) {
        total_seconds = 0; 
    }

    int final_hr = total_seconds / 3600;
    total_seconds %= 3600;
    int final_min = total_seconds / 60;
    int final_sec = total_seconds % 60;

    printf("Subtracted: %dhrs %dmins %dsec\n", final_hr, final_min, final_sec);
}

int main() {
    struct time t1, t2;
    printf("Time 1 (HH MM SS): ");
    scanf("%d %d %d", &t1.hr, &t1.min, &t1.sec);
    printf("Time 2 (HH MM SS): ");
    scanf("%d %d %d", &t2.hr, &t2.min, &t2.sec);

    add_time(t1.hr, t1.min, t1.sec, t2.hr, t2.min, t2.sec);
    subtract_time(t1.hr, t1.min, t1.sec, t2.hr, t2.min, t2.sec);

    return 0;
}
