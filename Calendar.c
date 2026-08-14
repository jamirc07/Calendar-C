#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int isLeapYear(int year) {
    if ((year % 4 == 0 && !(year % 100 == 0)) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

int daysInMonth(Date j) {
    int daysInMonnths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (j.month == 2) {
        if (isLeapYear(j.year)) {
            daysInMonnths[j.month - 1]++;
        }
    }

    return daysInMonnths[j.month - 1];
}

int dayOfTheWeek(Date e) {
    int lastTwo = e.year % 100;
    int a = lastTwo / 12;
    int b = lastTwo % 12;
    int c = b / 4;
    int offset = (a + b + c) % 7;
    int dayofWeek;
    int anchors[12] = {3, 28, 14, 4, 9, 6, 11, 8, 5, 10, 7, 12};
    int centuryAnchor;

    if (e.month == 2 || e.month == 1) {
        if (isLeapYear(e.year)) {
            anchors[e.month - 1]++;
        }
    }

    int anchor = anchors[e.month - 1];

    if (e.year > 1899 && e.year < 2000) {
        centuryAnchor = 3;
        dayofWeek = (offset + centuryAnchor + e.day - anchor + 7) % 7;
    } else {
        centuryAnchor = 2;
        dayofWeek = (offset + centuryAnchor + e.day - anchor + 7) % 7;
    }

    printf("%d/%d lands on %d in %d\n", e.month, e.day, dayofWeek, e.year);
    return dayofWeek;
}

int main() {
    Date test = {7, 9, 2007};

    Date test2 = {4, 4, 1998};
   

    printf("Days in month test: %d\n", daysInMonth(test));

    return 0;
}