#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main() {
    time_t current;
    struct tm inputDate = { 0 };
    struct tm* currentTimeInfo;
    double secondsDiff;
    int daysDiff;

    current = time(NULL);
    currentTimeInfo = localtime(&current);

    int year, month, day;
    printf("Enter YYYY MM DD: ");
    scanf("%d %d %d", &year, &month, &day);

    inputDate.tm_year = year - 1900; 
    inputDate.tm_mon = month - 1;   
    inputDate.tm_mday = day;

    time_t inputTime = mktime(&inputDate);

    secondsDiff = difftime(inputTime, current);
    daysDiff = (int)(secondsDiff / (60 * 60 * 24));

    if (daysDiff > 0) {
        printf("D-%d\n", daysDiff);
    }
    else if (daysDiff == 0) {
        printf("오늘\n");
    }
    else {
        printf("D+%d\n", -daysDiff);
    }

    return 0;
}
