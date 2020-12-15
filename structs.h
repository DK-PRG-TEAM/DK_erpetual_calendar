#define ONE_YEAR_MONTH 12
//#define ONE_MONTH_DAY 30
//#define COMMON_YEAR_DAYS 365
//#define LEAP_YEAR_DAYS 366
//const int commonMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
//const int leapYearMonth[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

//typedef struct{
//    const int ONE_YEAR_MONTH = 12;
//    const int ONE_MONTH_DAY = 30;
//    const int COMMON_YEAR_DAYS = 365;
//    const int LEAP_YEAR_DAYS = 366;
//    const int COMMON_MONTH[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
//    const int LEAP_YEAR_MONTH[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
//}StandardAboutDate;

//StandardAboutDate standardAboutDate;
//int test[1] = {0};

typedef struct {
    int yearNum;
    int monthNum;
    struct {
        int *p;
        int length;
    }data;
}Month;


typedef struct {
    Month *month;
    int length;
}Months;

typedef struct {
    Months *months;
    int length;
}Year;

typedef struct {
    Year *years;
    int length;
}Years;