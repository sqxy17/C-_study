#include<iostream>
using namespace std;
//一、模板类           -----C语言不支持模板的原因，不支持泛型编程



//这就是一个类模板
//template<class T>
//class stack                   //加上上面的template<class T>现在这个stack里面用着T，说明这个stack是个类模板
//        //模板定义过后 stack是类的名字，不能去实例化对象         stack<T>才可以，此处的T可以自己输入int，double之类的
//{
//public:
//    stack(int capacity=4)
//    :_top(0)
//    ,_capacity(capacity)
//    {
//        _a=new T[capacity];
//    }
//
//    void push(const T& x);//现在考虑一下函数的定义和声明        类模板里面的函数也会随着存入的数据而改变，所以函数在定义的时候也会有点特殊
//
//    ~stack()
//    {
//        delete[] _a;
//        _a=nullptr;
//        _capacity=_top=0;
//    }
//private:
//    T* _a;//c语言里面保存不同的数据，要建立不同类型的数组，double   int  char   int*  等等等,现在一个模板就行
//    int _top;
//    int _capacity;
//};
//
//
//template<class T>//函数在外面定义的时候一定要加上上面的template<class T>,这样就是在告诉编译器下面的函数是一个函数的模板     并且这个T还可以在此处随意更改
//void stack<T>::push(const T& x)     //类模板外面写成员函数，要表明这个函数的是类模板的成员函数   void stack<T>::push(constT& x)
//{
//    printf("hehe");
//}
//
//
//
//
//int main(void)
//{
//    stack <int>st1;//假设这个栈存放int类型的数据,在此处实例化之后，st1对象的T*就被改成int*了
//    stack <double>st2;//假设这个栈存放double类型的数据           在c语言里面是做不到的
//    //这个<double>是告诉将T变成double或者int
//    st1.push(3);
//}

