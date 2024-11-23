#include <stdio.h>
#include <time.h>

int calculate_d_day(int year, int month, int day) {
    time_t t = time(NULL);
    struct tm today = *localtime(&t);

    struct tm target_date = {0};
    target_date.tm_year = year - 1900; 
    target_date.tm_mon = month - 1;   
    target_date.tm_mday = day;
    
    time_t target_time = mktime(&target_date);

    if (target_time == -1) {
        return -1; 

    time_t current_time = mktime(&today);

    double difference = difftime(target_time, current_time) / (60 * 60 * 24);

    return (int)difference;
}

int main() {
    int year, month, day;

    printf("목표 날짜를 입력하세요 (YYYY MM DD): ");
    if (scanf("%d %d %d", &year, &month, &day) != 3) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    int d_day = calculate_d_day(year, month, day);

    if (d_day == -1) {
        printf("유효하지 않은 날짜입니다.\n");
    } else if (d_day > 0) {
        printf("D-%d\n", d_day);
    } else if (d_day == 0) {
        printf("D-Day\n");
    } else {
        printf("D+%d\n", -d_day);
    }

    return 0;
}
