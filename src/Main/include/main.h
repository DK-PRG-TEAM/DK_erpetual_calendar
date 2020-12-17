#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include "../../Struct/include/structs.h"
#include "../../Consts/include/consts.h"
using namespace std;

class AutomaticCalender{
public:
    void setThisVarToThisMonthCalenderArray(Month *target, int year, int month);
    Month *getThisMonthCalenderStruct(int yearNum, int monthNum);
    Months *getContinuousManyMonthCalenderStruct(int year, int startMonth, int endMonth);
    Year *getThisYearCalenderArray(int yearNum);
    void printThisMonthCalender(Month *month);
    void printManyMonthsCalender(int year, int startMonth, int endMonth);
    void setThisVarToThisMonthsCalenderArray();
    void setThisVarToThisYearCalenderArray(Year *target, int year);
    void printThisYearCalender(Year *year);
    void printManyYearsCalender(int startYear, int endYear);
private:
    bool isCommonYear(int year);
    int getThisMonthDays(int year,int month);
    int monthToDays(int year, int startMonth, int endMonth);
    int manyYearToDays(int startYear,int endYear);

    Month *createNewMonthObject(int length);
    //void getThisMonthCalender(int year, int month);
    Months *createNewMonthsObject(int length);

    Year *createNewYearObject(int length = ONE_YEAR_MONTH);

    Years *createNewYearsObject(int length);

};