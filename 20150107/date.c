#include<stdio.h>
#define ISLEAPYEAR(year)  (year % 4 == 0 && year % 100 != 0 || year %400 == 0)

typedef struct date{
    int year;
    int month;
    int day;
}date;


int dayscalculate1(date oneday){
    static int DayOfMonth[2][13] = 
    {{0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}};

    int i, lp;
    lp = ((oneday.year % 4 == 0) &&( oneday.year % 100 != 0) )||( oneday.year % 400 == 0);

   for(i = 1 ; i < oneday.month ; i++){
        oneday.day += DayOfMonth[lp][i];
   } 
   return oneday.day;
}

int days_claculate_2(date oneday){
    int itotally_month_day,iloop = 1;
    while(iloop < oneday.month){
        switch(oneday.month){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                itotally_month_day += 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                itotally_month_day +=30;
            case 2:
                if(ISLEAPYEAR(oneday.year)){
                    itotally_month_day += 29;
                }else{
                    itotally_month_day += 28;
                }
        }
    }
    return itotally_month_day;
}


int Days_Diff(date date_1,date date_2){
    date DS_date_temp_min,DS_date_temp_max;
    int iyear,idiffdays;

    if(date_1.year < date_2.year){
        DS_date_temp_min  =  date_1;
        DS_date_temp_max  = date_2;
    }else{
        DS_date_temp_min  = date_2;
        DS_date_temp_max  = date_1;
    }

    for(iyear = DS_date_temp_min.year, idiffdays = 0;iyear < DS_date_temp_max.year;iyear++){
        //idiffdays += Days_calculate_1(iyear);
        if(ISLEAPYEAR(iyear)){
            idiffdays += 366;
        }else{
            idiffdays += 365;
        }
    }

    idiffdays = idiffdays + dayscalculate1(DS_date_temp_max) - dayscalculate1(DS_date_temp_min);

    return idiffdays;

}


void Week_is(){
    date d_oneday,d_standard;

    d_standard.year = 1989;
    d_standard.month = 12;
    d_standard.day = 31;
    
    char cweekname[7][4] = {"Sun","Mon","Tue","Wed","Thr","Fri","Sat"};

    int iweek,idiffdays;
    while(scanf("%d%d%d",&d_oneday.year,&d_oneday.month,&d_oneday.day)!=EOF){
       idiffdays =  Days_Diff(d_standard,d_oneday);
       if(d_standard.year < d_oneday.year){
            iweek = idiffdays % 7;
       }else{
            iweek = (7 - idiffdays % 7) % 7;
       }
    printf("The date %d 年 %d 月 %d 日 is %s\n",d_oneday.year,d_oneday.month,d_oneday.day,cweekname[iweek]);
    
    }
}




int main(){
    Week_is();
    return 0;
}
