#ifndef C___STUDY_10_默认函数总结_H
#define C___STUDY_10_默认函数总结_H

#endif //C___STUDY_10_默认函数总结_H


#include<iostream>
using namespace std;

class data
{
public:
    friend ostream& operator<<(ostream& out,const data& d);//不在类里面定义的函数就没有默认的this指针
    friend istream& operator>>(istream& in,data& d);


    data(int year=0,int month=1,int day=1);//如果定义函数缺省参数，尽量在函数的声明中缺省，定义阶段不写
    void print();
    data& operator+=(int day);
    data operator+(int day);//相加不改变原本的值，只是返回相加后的结果
    data& operator-=(int day);
    data operator-(int day);//这两个还没有实现，有时间参考+  +=实现一下

    data& operator++();//d1.operator()    这样使前置的调用
    data operator++(int);//这就是占位的参数，不用管只是为了区别，编译器会自动传参               但是必须是整形            d1.operator(10086)也可以这样后置的调用
    data& operator--();
    data operator--(int);//后置--

    bool operator>(const data& d);
    bool operator==(const data& d);//其他的>= <= <就要用这两个实现了
    bool operator<(const data& d);

    bool operator>=(const data& d);
    bool operator<=(const data& d);
    bool operator!=(const data& d);

    int operator-(const data& d);//这个-和上面的-构成了重载，没有关系   也就是两个日期相差的天数

    void operator<<(ostream& out);

    void printweekday();

private:
    int _year;
    int _month;
    int _day;

};

//友元函数的关键字 friend 朋友
//使用的方法就是在函数的声明阶段，并且在类的里面 friend void operator<<(c参数类型，参数类型)
