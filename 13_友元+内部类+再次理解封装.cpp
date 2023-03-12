#include<iostream>
using namespace std;


//一、友元
//友元分为友元函数和友元类
//友元提供了一种突破封装的方式，提供了便利，但是增加耦合度，破坏了封装，所以友元不宜多用            -----但是能不用就不用


//1.说明
//友元函数可以访问类的私有成员和保护成员，但不是类的成员函数
//友元函数不能用const修饰
//一个函数可以是多个类的友元函数
//友元函数的调用和普通函数的原理相同








//二、友元类
//友元类的所用成员函数都可以是另一个类的友元函数，都可以访问另一个类的非共有成员
//友元关系是单向的，没有交换性，a'shi
//class Date;//如果在time要访问date，time类在data的上面
//
//class Time
//{
//    friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成变量
//public:
//    Time(int hour=0, int minute=0, int second=0)
//            : _hour(hour)
//            , _minute(minute)
//            , _second(second)
//    {}
//
//
//
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//
//
//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//            :_year(year)
//            ,_month(month)
//            ,_day(day)
//    {
//        _t._hour=0;
//        _t._minute=0;
//        _t._second=0;
//    }
//
//    void SetTimeOfDate(int hour, int minute, int second)
//    {
//        // 直接访问时间类私有的成员变量
//        _t._hour = hour;
//        _t._minute = minute;
//        _t._second = second;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//    Time _t;
//};
//
//








//三、内部类
//在一个类里面定义另外一个类

//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//            :_year(year)
//            ,_month(month)
//            ,_day(day)
//    {
//        _t._hour=0;
//        _t._minute=0;
//        _t._second=0;
//    }
//
//    void SetTimeOfDate(int hour, int minute, int second)
//    {
//        _t._hour = hour;
//        _t._minute = minute;
//        _t._second = second;
//    }
//
//
//    class Time    //time在data里面定义，time天生就是data的友元（time是data的朋友，time能看data）
//    {
//        friend class Date;//这句话注释后，data就不能访问time类了
//    public:
//        Time(int hour=0, int minute=0, int second=0)
//                : _hour(hour)
//                , _minute(minute)
//                , _second(second)
//        {}
//
//    private:
//        int _hour;
//        int _minute;
//        int _second;
//    };
//
//
//
//private:
//    int _year;
//    int _month;
//    int _day;
//    Time _t;
//};
//
//
//
//int main(void)
//{
//    Date d1;
//    cout<<sizeof(d1)<<endl;//计算d1只计算data里面的变量，不用去管time类里面变量的大小
//}
//静态区的变量不参与sizeof的计算
//内部类time和在全局定义的是一样的，只是受外部类data的限制
//内部类time天生就是外部类data的友元，也就是time中可以访问data的私有，但是data不能访问time的私有


//oj牛客：计算日期到天数的转换  11节课










//四、再次理解封装
//1.面向对象编程的三大特点：封装、继承、多态
//回忆一点，c语言中结构体定义的变量也能相互之间进行赋值，这个赋值仅仅只是浅拷贝。例如结构体仅仅只是将里面包含的全部变量赋值给另外的变量