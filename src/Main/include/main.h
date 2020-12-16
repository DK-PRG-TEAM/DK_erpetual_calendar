#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include "../../Struct/include/structs.h"
#include "../../Consts/include/consts.h"
using namespace std;

class AutomaticCalender{
public:
    void setThisVarToThisMonthCalenderArray(Month *target, int year, int month);
    void printThisMonthCalender(Month *month);
    void printManyMonthsCalender(int year, int startMonth, int endMonth);
    void setThisVarToThisMonthsCalenderArray();
    void setThisVarToThisYearCalenderArray(Year *target, int year);
    void printThisYearCalender(Year *target);
    void printManyYearsCalender(int startYear, int endYear);
private:
    bool isCommonYear(int year);
    int getThisMonthDays(int year,int month);
    int monthToDays(int year, int startMonth, int endMonth);
    int manyYearToDays(int startYear,int endYear);
    //void getThisMonthCalender(int year, int month);
};