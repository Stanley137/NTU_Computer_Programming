#include <stdio.h>
int main(){
    int ori_year, ori_day, day_29;
    scanf("%d %d", &ori_year, &ori_day);
    // determine 閏年
    if(ori_year % 4 != 0)
        day_29 = 0;
    else if(ori_year % 4 == 0 && ori_year % 100 !=0)
        day_29 = 1;
    else if(ori_year % 100 == 0 && ori_year % 400 != 0)
        day_29 = 0;
    else if(ori_year % 400 == 0)
        day_29 = 1;
    int arr[13];
    arr[2] = (day_29) ? 29 : 28;
    arr[1] = 31, arr[3] = 31, arr[5] = 31, arr[7] = 31, arr[8] = 31, arr[10] = 31, arr[12] = 31;
    arr[4] = 30, arr[6] = 30, arr[9] = 30, arr[11] = 30;
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        // printf("is_29 %d\n", day_29);
        int month, d_day, days = 0;
        scanf("%d %d", &month, &d_day);
        if(month > 12 || month < 1){
            printf("-1\n");
            continue;
        }
        else if(d_day > arr[month] || d_day < 1){
            // printf("%d\n%d\n", d_day, arr[month]);
            // printf("%d %d\n", arr[month], month);
            printf("-2\n");
            continue;
        }
        for(int j=1;j<month;j++) days += arr[j];
        days += (d_day - 1);
        int day = 0;
        // printf("%d %d\n", days, (days-1)%7);
        day = (ori_day + ((days) % 7)) % 7;
        printf("%d\n", day);
    }
}