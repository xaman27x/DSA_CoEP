#include <stdio.h>
#include <stdbool.h>

struct date {
    int day;
    int month;
    int year;
};

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool is_valid_date(struct date d) {
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d.month < 1 || d.month > 12) {
        return false;
    }

    if (d.month == 2 && is_leap_year(d.year)) {
        return d.day >= 1 && d.day <= 29;
    } else if (d.month == 2) {
        return d.day >= 1 && d.day <= 28;
    }

    return d.day >= 1 && d.day <= days_in_month[d.month];
}

void read_date(struct date *d) {
    printf("DD MM YYYY: ");
    scanf("%d %d %d", &d->day, &d->month, &d->year);
}

int main() {
    struct date date;
    read_date(&date);

    if (is_valid_date(date)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}
