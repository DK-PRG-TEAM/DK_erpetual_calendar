#include <stdio.h>
#include <stdbool.h>
#define ONE_YEAR_MONTH 12
#define ONE_MONTH_DAY 30
#define COMMON_YEAR_DAYS 365
#define LEAP_YEAR_DAYS 366
const int commonMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int leapYearMonth[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int y,m,d,y1,m1,d1,togetherYears,sumDays,startDate[3],endDate[3];
    printf("Input start date:(EXP:2020,10,1)\n");
    scanf("%d,%d,%d",&startDate[0],&startDate[1],&startDate[2]);
//	printf("年：\n");
//	scanf("%d",&y);
//	printf("月：\n");
//	scanf("%d",&m);
//	printf("日：\n");
//	scanf("%d",&d);
    printf("Input end date:(EXP:2019,5,3)\n");
    scanf("%d,%d,%d",&endDate[0],&endDate[1],&endDate[2]);
    togetherYears = endDate[0] - startDate[0];
    if(togetherYears >= 1){
//   		for(int i=0;i< ONE_YEAR_MONTH - startDate[1]-1 ;i++){
//   			sumDays +=  firstYearMonth[i]
//		   }
//   		sumDays += (ONE_YEAR_MONTH - startDate[1]-1)*ONE_MONTH_DAY + ONE_MONTH_DAY-startDate[2]; //first year days
        sumDays += getThisMonthDays(startDate[0],startDate[1])-startDate[2] + monthToDays(startDate[0],startDate[1]+1,ONE_YEAR_MONTH); //first year days //BUGS:需要分段计算
//   		printf("%endDate[2]\n",getThisMonthDays(startDate[0],startDate[1]));
//   		printf("%endDate[2]\n",monthToDays(startDate[0],startDate[1]+1,ONE_YEAR_MONTH));
        sumDays += togetherYears-1>=1?manyYearToDays(startDate[0]+1,endDate[0]-1):0; //exclude first year days //BUGS
//		printf("----\n") ;
        sumDays += endDate[1]-1>=1?monthToDays(endDate[0],1,endDate[1]-1) + endDate[2]:endDate[2]; // present year days
//   		printf("%endDate[2]\n",monthToDays(endDate[0],1,endDate[1]-1));
//   		printf("%endDate[2]\n",endDate[2]);
    }else{
//   		for(int i=0;i< endDate[1]-startDate[1] ;i++){
//   			sumDays +=  presentYearMonth[i]
//		   }
//   	sumDays += (ONE_YEAR_MONTH - startDate[1])*ONE_MONTH_DAY + ONE_MONTH_DAY-startDate[2]; //first year days
        sumDays += endDate[1]-startDate[1]>=1?monthToDays(endDate[0],startDate[1]+1,endDate[1]-1):0;
        sumDays += endDate[2] + getThisMonthDays(endDate[0],startDate[1]) - startDate[2] +1;
    }
    printf("相差[%d]天\n",sumDays);
    return 0;
}
bool isCommonYear(int year){
    if (year % 4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            return false;
        }
    }
    else{
        return true;
    }
}
int getThisMonthDays(int year,int month){
    int *persentYearMonth = isCommonYear(year)?commonMonth:leapYearMonth;
    return persentYearMonth[month-1];
}
int monthToDays(int year, int startMonth, int endMonth){
//	int *persentYearMonth = isCommonYear(year)?commonMonth:leapYearMonth;
    int resultDays = 0;
    for(int i=startMonth;i<=endMonth;i++){// only C99
//		printf("%d:%d\t",i,getThisMonthDays(year,i));
        resultDays += getThisMonthDays(year,i);
    }
//	printf("\n");
    return resultDays;
}
int manyYearToDays(int startYear,int endYear){
    int resultDays = 0;
    for(int i=startYear;i<=endYear;i++){
//		printf("%d:%d\t",i,isCommonYear(i)?COMMON_YEAR_DAYS:LEAP_YEAR_DAYS);
        resultDays+= isCommonYear(i)?COMMON_YEAR_DAYS:LEAP_YEAR_DAYS;
    }
//	printf("\n");
    return resultDays;
}
//int monthToDays(int year,int month){//顺序计算
//	int *persentYearMonth = isCommonYear(year)?commonMonth:leapYearMonth;
//	int resultDays = 0;
//	for(int i=0;i<month;i++){ // only C99
//		resultDays += persentYearMonth[i];
//	}
//	return resultDays;
//}