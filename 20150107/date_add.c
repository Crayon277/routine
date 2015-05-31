#include<stdio.h>
#define ISLEAPYEAR(year) (year % 4 == 0 && year %100 != 0 || year % 400 == 0)
typedef struct date{
    int year;
    int month;
    int day;
}date;

void date_add(){
    date oneday;
    
    while(fflush(stdin),scanf("%d%d%d",&oneday.year,&oneday.month,&oneday.day)!=EOF){
    switch (oneday.month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            oneday.year = oneday.year + (oneday.month + 1) / 13;
            oneday.month = ((oneday.day+1)/32+oneday.month)%13+((oneday.day+1)/32+oneday.month)/13;
            oneday.day = (oneday.day+1)%32 + (oneday.day+1)/32;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            oneday.month = ((oneday.day+1)/31 + oneday.month)% 13 + ((oneday.day + 1)/31 + oneday.month) /13;
            oneday.day = (oneday.day+1)%31+(oneday.day+1)/31;
            break;
            
        case 2:
            if (ISLEAPYEAR(oneday.year)) {
                oneday.month = ((oneday.day+1)/30 + oneday.month)% 13 + ((oneday.day +1)/30 + oneday.month)/13;
                oneday.day =(oneday.day + 1) %30 + (oneday.day+ 1)/30;
            }
            else{
                oneday.month = ((oneday.day+1)/29 + oneday.month)% 13 + ((oneday.day +1)/29+ oneday.month)/13;
                oneday.day =(oneday.day+ 1) %29 + (oneday.day + 1)/29;
                
            }
    }
    printf("Tomorrow is %d 年 %d 月 %d 日\n",oneday.year, oneday.month ,oneday.day);
    }
}

int main(){
    date_add();
    return 0;
}