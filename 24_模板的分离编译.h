#pragma once
#include<iostream>
using namespace std;
template<class T>
void add(T,T);//声明的意义就是想通过这个函数,告诉编译器有这个函数,在后面再去找,就是在链接的时候进行查找这个函数


template <class T>
void add(T x,T y)
{
    cout<<x+y<<endl;
}

//声明和定义不分离,头文件展开以后,直接就有模板定义和实例化,那么直接就可以填上函数地址调用.不需要链接去找

void sub(int,int);





//除了函数模板,类模板也是有相同的问题,有点区别的是,类模板可以用这个类型,但是不能用类里面的函数(包括默认函数),原因也是链接不上
template<class T>
class A
{
public:
    A();
private:
    T _con;
};


