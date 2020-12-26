#include "../include/main.h"

//bool isCommonYear(int year);
//int getThisMonthDays(int year,int month);
//int monthToDays(int year, int startMonth, int endMonth);
//int manyYearToDays(int startYear,int endYear);
////void getThisMonthCalender(int year, int month);
//void setThisVarToThisMonthCalenderArray(Month *target, int year, int month);
//void printThisMonthCalender(Month *month);
//void printManyMonthsCalender(int year, int startMonth, int endMonth);
//void setThisVarToThisYearCalenderArray(Year *target, int year);
//void printThisYearCalender(int year);
//void printManyYearsCalender(int startYear, int endYear);
int main(){
    AutomaticCalender automaticCalender;
    cout<<automaticCalender.getThisDayWeekString(2020,5,3)<<endl;
//    Month month;
//    automaticCalender.setThisVarToThisMonthCalenderArray(&month,2020,2);
//    automaticCalender.printThisMonthCalender(&month);

    Year year;
    year = *automaticCalender.getThisYearCalenderArray(2020);
    automaticCalender.printThisYearCalender(&year);

//    int y,m,d,y1,m1,d1,togetherYears,sumDays,startDate[3],endDate[3];
//    printf("Input start date:(EXP:2020,10,1)\n");
//    scanf("%d,%d,%d",&startDate[0],&startDate[1],&startDate[2]);
////	printf("年：\n");
////	scanf("%d",&y);
////	printf("月：\n");
////	scanf("%d",&m);
////	printf("日：\n");
////	scanf("%d",&d);
//    printf("Input end date:(EXP:2019,5,3)\n");
//    scanf("%d,%d,%d",&endDate[0],&endDate[1],&endDate[2]);
//    togetherYears = endDate[0] - startDate[0];
//    if(togetherYears >= 1){
////   		for(int i=0;i< ONE_YEAR_MONTH - startDate[1]-1 ;i++){
////   			sumDays +=  firstYearMonth[i]
////		   }
////   		sumDays += (ONE_YEAR_MONTH - startDate[1]-1)*ONE_MONTH_DAY + ONE_MONTH_DAY-startDate[2]; //first year days
//        sumDays += getThisMonthDays(startDate[0],startDate[1])-startDate[2] + monthToDays(startDate[0],startDate[1]+1,ONE_YEAR_MONTH); //first year days //BUGS:需要分段计算
////   		printf("%endDate[2]\n",getThisMonthDays(startDate[0],startDate[1]));
////   		printf("%endDate[2]\n",monthToDays(startDate[0],startDate[1]+1,ONE_YEAR_MONTH));
//        sumDays += togetherYears-1>=1?manyYearToDays(startDate[0]+1,endDate[0]-1):0; //exclude first year days //BUGS
////		printf("----\n") ;
//        sumDays += endDate[1]-1>=1?monthToDays(endDate[0],1,endDate[1]-1) + endDate[2]:endDate[2]; // present year days
////   		printf("%endDate[2]\n",monthToDays(endDate[0],1,endDate[1]-1));
////   		printf("%endDate[2]\n",endDate[2]);
//    }else{
////   		for(int i=0;i< endDate[1]-startDate[1] ;i++){
////   			sumDays +=  presentYearMonth[i]
////		   }
////   	sumDays += (ONE_YEAR_MONTH - startDate[1])*ONE_MONTH_DAY + ONE_MONTH_DAY-startDate[2]; //first year days
//        sumDays += endDate[1]-startDate[1]>=1?monthToDays(endDate[0],startDate[1]+1,endDate[1]-1):0;
//        sumDays += endDate[2] + getThisMonthDays(endDate[0],startDate[1]) - startDate[2] +1;
//    }
//    printf("相差[%d]天\n",sumDays);
//    return 0;
}

bool AutomaticCalender::isCommonYear(int year){
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
int AutomaticCalender::getThisMonthDays(int year,int month){
//    int *persentYearMonth = isCommonYear(year)?commonMonth:leapYearMonth;
//    return persentYearMonth[month-1];
    return isCommonYear(year)?commonMonth[month-1]:leapYearMonth[month-1];
}
//int monthsToDays(int year, int startMonth, int endMonth){
////	int *persentYearMonth = isCommonYear(year)?commonMonth:leapYearMonth;
//    int resultDays = 0;
//    for(int i=startMonth;i<=endMonth;i++){// only C99
////		printf("%d:%d\t",i,getThisMonthDays(year,i));
//        resultDays += getThisMonthDays(year,i);
//    }
////	printf("\n");
//    return resultDays;
//}
//int manyYearToDays(int startYear,int endYear){
//    int resultDays = 0;
//    for(int i=startYear;i<=endYear;i++){
////		printf("%d:%d\t",i,isCommonYear(i)?COMMON_YEAR_DAYS:LEAP_YEAR_DAYS);
//        resultDays+= isCommonYear(i)?COMMON_YEAR_DAYS:LEAP_YEAR_DAYS;
//    }
////	printf("\n");
//    return resultDays;
//}
//int monthToDays(int year,int month){//顺序计算
//	int *persentYearMonth = isCommonYear(year)?commonMonth:leapYearMonth;
//	int resultDays = 0;
//	for(int i=0;i<month;i++){ // only C99
//		resultDays += persentYearMonth[i];
//	}
//	return resultDays;
//}
Month *AutomaticCalender::getThisMonthCalenderStruct(int yearNum, int monthNum){
    Month *month = createNewMonthObject(getThisMonthDays(yearNum,monthNum));
    month->yearNum = yearNum;
    month->monthNum = monthNum;
    for (int i = 0; i < month->data.length; ++i) {
        month->data.day[i] = i+1;
    }
    return month;
}

Months *AutomaticCalender::getContinuousManyMonthCalenderStruct(int year, int startMonth, int endMonth){
    Months *months = createNewMonthsObject(endMonth - startMonth + 1);//例如4~5月, 5 - 4 + 1 = 2月
    for (int i = 0; i < months->data.length; i++) {
        months->data.months[i] = getThisMonthCalenderStruct(year,startMonth+i);
    }
    return months;
}

Year *AutomaticCalender::getThisYearCalenderArray(int yearNum) {
    Year *year = createNewYearObject();
    year->yearNum = yearNum;
    year->data.months = getContinuousManyMonthCalenderStruct(yearNum,1,ONE_YEAR_MONTH);
    return year;
//    int *a = new int [10];
//    a[0]  = 10;
//    a[0] =
//    Month *month;
//    month = new Month [12];
//    month[0] = *getThisMonthCalenderStruct(2020,12);
//    Month month[12];
//    month[0] = new Month;
//    Months *months = createNewMonthsObject(12);
//    months->data.months[1].data.day = new int [30];
//
//    Year *year = createNewYearObject();
//    year->data.months[0].
//    for (int i = 0; i < year->data.months->data.length; i++) {
//        year->data.months->data.months[i] =
//        year->data.months = new Months;
//        year->data.months->data.months = new Month[12];
//        year->data.months->data.months[1]
//        year->data.months->data.months[1]
//        year->data.months[1] = new Month ;
//        year->data.months->data.months[0] = *getThisMonthCalenderStruct(yearNum, i + 1);
//        year->data.months = createNewMonthsObject(12);
//        months->data.months[i] = getThisMonthCalenderStruct(yearNum,i+1);
//    }
}
//void AutomaticCalender::setThisVarToThisMonthCalenderArray(Month *target, int year, int month){ //需要传入已经初始化的target
//    target->yearNum = year;
//    target->monthNum = month;
//    target->data.length = getThisMonthDays(year,month);
////    target->data.day = isCommonYear(year) ? commonMonth : leapYearMonth;
////    const int constArray[5] = {1,2,3,4,5};
////    const int *constArrayTest = constArray; //注意这里的constArray实际上就是constArray第一个数的地址;
////    target->data.day = new int [target->data.length];
//    for (int i = 0; i < target->data.length; i++) {
//        target->data.day[i] = i + 1;
//    }
////    const int constInt = 123;
////    const int  *a = &constInt;
////
////    const int constArray[1] = {1};
////    const int *b = &constArray;
//
////    const int test[10] = {1,2,3};
////    const int *a = test;
////    int *&day = &test;
////    int &t = &test;
////    const int s = 10;
////    const int &l = &s;
////    target = const_cast<int *>(test);
////    target = commonMonth;
////    target = isCommonYear(year)?commonMonth:leapYearMonth;
//}


void AutomaticCalender::printThisMonthCalender(Month *month){
    cout<<"["<<month->yearNum<<"]"<<"年"<<"第"<<"["<<month->monthNum<<"]"<<"月"<<endl;
    cout<<"日\t一\t二\t三\t四\t五\t六"<<endl;
    int displacement = getThisDayWeekCode(month->yearNum,month->monthNum,month->data.day[0]);
    for (int i = 0; i < displacement; i++) {
        cout<<"\t";
    }
    for (int i = 0; i < month->data.length; i++) {
        cout << month->data.day[i] << "\t";
        if (month->data.day[i] % 7 == 0){
            cout<<endl;
        }
    }
    cout<<endl;
}

//void AutomaticCalender::

//void AutomaticCalender::setThisVarToThisYearCalenderArray(Year *target, int year) {
//    target->data.months = new Months;
//    for (int i = 0; i < 12; i++) {
//        target->data.months->data.months[i] = new Month;
//    }
//    target->year = year;
////    target->data.months = new Months;
//    target->data.months = new Months[ONE_YEAR_MONTH];
////    target->data.months->length
//    target->data.months->data.length = ONE_YEAR_MONTH;
//    for (int i = 0; i < target->data.months->data.length; i++) {
//        target->data.months->data[i].month = new Month;
//        target->data.months->data.months[i].data;
//        target->data.months->data.months[i] = new Month;
//        setThisVarToThisMonthCalenderArray(target->data.months[i].month, year, i+1);
//
////        cout<<"get calender:"<<endl;
////        printThisMonthCalender(target->data.months[i].month);
//    }
//    cout<<endl;
//}

void AutomaticCalender::printThisYearCalender(Year *year) {
    for (int i = 0; i <year->data.months->data.length; ++i) {
        printThisMonthCalender(year->data.months->data.months[i]);
    }
}


Month *AutomaticCalender::createNewMonthObject(int length) {//创建一个Month实例, 并且进行初始化
//    Month month;//局部变量, 不可以安全返回其指针, 该变量在return之后变成无效变量
    Month *month = new Month;//局部指针变量: 可以安全返回
    month->data.length = length;
    month->data.day = new int [month->data.length];
    return month;
}

Months *AutomaticCalender::createNewMonthsObject(int length) {//创建一个Months实例, 并且进行初始化
    Months *months = new Months;
    months->data.length = length;
    months->data.months = new Month* [length];
    return months;
}

Year *AutomaticCalender::createNewYearObject(int length) {//因为一年肯定是12个月, 所以无需长度
    Year *year;
    year = new Year;
    return year;
}

Years *AutomaticCalender::createNewYearsObject(int length) {
    Years *years;
    years->data.length = length;
    years->data.years = new Year [years->data.length];
    return years;
}

int AutomaticCalender::getThisDayWeekCode(int year, int month, int day) {
    cout<<"get week code:["<<( ((year / 100) / 4) - 2 * (year / 100) + (year % 100) + ( (year % 100) / 4 ) + (13 * ( month + 1 ) ) / 5 + day - 1 ) % 7<<"]"<<"source:[month:"<<month<<"day:"<<day<<"]"<<endl;
    return ( ((year / 100) / 4) - 2 * (year / 100) + (year % 100) + ( (year % 100) / 4 ) + (13 * ( month + 1 ) ) / 5 + day - 1 ) % 7; // 使用蔡勒公示计算星期几,取值范围0-6，其中0是星期日
//    return (month - 5) + day < 7?(month - 5) + day:((month - 5) + day) % 7;  //首先，把你想要知道的日期号，加上该月份代号，再除以7，能整除的就是星期日；不能整除的，余数是几，那天就是星期几。如果日期号和月份代号相加的和小于7，那么这个和是几，那天就是星期几。 例如：想知道2006年5月20日是星期几，就把“20”加上2006年5月的代号“0”，所得的和是 20 ，再用20除以7，余数是6，那么2006年5月20号就是星期6。 再举个例子：想知道2006年2月3日是星期几，那么就把“3”加上2月的代号“2”，和为5。由于5小于7，所以2006年2月3日就是星期5。 由于各年的月份代号不尽相同，下面给出各年月份代号的计算方法： 首先要有一本日历，然后随便找一天，例如2006年8月5日，那天是星期6，就把“6”减去“5”，所得的差为“1”，那么2006年8月的代号就是1，其他月份代号的计算方法可以次类推。 这个方法写成公式就是：该年月份代号＝该月星期几－该月日期号。 注意：式中取该月日期号时，必须小于或等于7；取星期日时，数值按7计算，该月星期几的数值要大于日期号数值。
}


string AutomaticCalender::getThisDayWeekString(int year, int month, int day) {
    return week[getThisDayWeekCode(year, month, day)];
}


//typedef struct {
//    int *day;
//    int length;
//}Month;

//typedef struct {
//    struct{
//        int b;
//    }a;
//    int monthNum;
////    Month month;
//}Month;
//
//Month month;



//typedef struct {
//    int monthNum;
//    struct {
//        int *day;
//        int length;
//    }data;
//}Month;
//
//
//typedef struct {
//    Month *month;
//    int length;
//}Months;
//
//typedef struct {
//    Months months;
//}Year;
//
//typedef struct {
//    Year *years;
//    int length;
//}Years;


void test(){
//    Month *month;
//    Month *&a = month;
//    a->data.length = 10;
//    Month *months = new Month[5];
//    Months months;
//    months.month = new Month[5];
//    months.length = 10;
//    const int test[] = {1};
//    int test1 = (int) test;
//    int a[1] = {0};
//    int b[1] = {1};
//    b = a;
//    int a = 10;
//    month.data.length = 10;
//    month.data.day=&a;
//    month.monthNum = 1;
//    Year year;
//    year.month[1];
}
