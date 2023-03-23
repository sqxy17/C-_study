#include "21_test_list.h"
#include<iostream>
using namespace llk;
using std::cout;
using std::cin;
using std::endl;


//struct Data
//{
//    int _year;
//    int _month;
//    int _day;
//
//    Data(int year=1,int month=1,int day=1)
//    :_year(year)
//    ,_month(month)
//    ,_day(day)
//    {}
//};

void test_print(list<int>&);
void test_push()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    list<int>l1(l);


    //使用迭代器进行遍历
// list<int>::iterator it=l1.begin();
// while(it!=l1.end())//如果迭代器是原生指针的话，那么可以直接进行比较大小，但是迭代器不是一个指针，而是一个类，就没办法进行解引用，和进行比较是否相等
// {
//     cout<<*it<<' ';//这个*是进行调用函数，并不是直接进行解引用
//     ++it;
// }
    test_print(l);

}


void test_print(list<int>& l1)//如果仅仅只是想输出l1的值，并不想改变l1的值，该怎么办？
//如果只是单纯的将迭代器里面的方法的返回值设置为const类型的，不行，因为并不是迭代器是const类型的，关键是容器是const类型的
{
    //使用迭代器进行遍历
    //迭代器原本就分为普通迭代器和只读迭代器，定义的时候就可以直接定义出来是不是const类型的迭代器
    list<int>::iterator it=l1.begin();//迭代器不要进行引用
    while(it!=l1.end())
    {
        cout<<*it<<' ';
        ++it;
    }
}
////
//void test2()
//{
//    list<Data> l;
//    l.push_back(Data(2001,1,1));
//    l.push_back(Data(2002,2,2));
//    l.push_back(Data(2003,3,3));
//    l.push_back(Data(2004,4,4));
//    l.push_back(Data(2005,5,5));
//
//
//    list<Data>::iterator it=l.begin();
//    while(it!=l.end())
//    {
//        cout<<it->_month<<' '<<it->_year<<' '<<it->_day;
//        ++it;
//    }
//}




//void test_reverse_iterator()
//{
//    list<int> lt1;
//    lt1.push_back(1);
//    lt1.push_back(2);
//    lt1.push_back(3);
//    lt1.push_back(4);
//
//    list<int>::reverse_iterator rit=lt1.rbeign();
//    while(rit!=lt1.rend())
//    {
//        cout<<*rit<<' ';
//        ++rit;
//    }
//    cout<<endl;
//
//}




//int main(void)
//{
//    test_reverse_iterator();
//}

//内置类型办不到的事情，可以将其封装成一个自定义类型的类型
//总结;迭代器：不一定是原生指针，也可能是自定义类型


//迭代器本身就是模拟指针的行为，就像指针一样去访问容器


void test()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    const list<int>l1(l);//这个const是针对不能进行更改的变量的迭代器
//    const list<Data>l1  ----只有自定义类型才会用的上T*
    llk::list<int>::const_iterator it=l1.begin();
    while(it!=l1.end())
    {
        cout<<*it<<' ';//
        ++it;
    }
    cout<<endl;
}

//
//int main(void)
//{
//    test();
//}
//
//




