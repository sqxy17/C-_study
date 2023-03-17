//前言:之前的通讯录使用数据结构，比如链表，为什么没有模板呢，既然还要使用       -----因为c语言不支持泛型编程

#include<iostream>
using namespace std;
//一、模板
//模板分两种   函数模板      类模板
//1.
//void swap1(int& x1,int& x2)
//{
//    int tmp=x1;
//    x1=x2;
//    x2=tmp;
//}
//
//void swap2(double& d1,double& d2)
//{
//    double tmp=d1;
//    d1=d2;
//    d2=tmp;
//}
//
//
//int main(void)
//{
//    int a=1;
//    int b=2;
//    double c=1.1;
//    double d=2.2;
////    swap1(a,b);//交换不同的类型需要设计不同参数的交换函数，很麻烦   所以我们需要定义一个具体的类型，就像下面一样
////    swap2(c,d);
//}




//2.template     模板
//看见llk就知道啥意思了
//template<class llk>//   也可以这样定义名字   template<typename llk>         typename就是类型名称的意思   class也是定义类型的。总的来说两个方式都差不错，后面有区别碰见再说
//void  Swap(llk& x1,llk& x2)//函数参数列表----参数对象
//{
//    llk tmp=x1;//llk表示类型的名字   就和int一样
//    x1=x2;
//    x2=tmp;
//}


//如果需要多个类型，就可以这样定义
//template<class llk1,class llk2>    //模板参数列表----参数类型     参数可以是自定义类型，也可以是内置类型
//{
////    ......;//
//}



//3.
//所以上面的各种swap就可以搞成这样
//template<class T>
//void Swap(T& x1,T& x2)
//{
//    T tmp=x1;
//    x1=x2;
//    x2=tmp;
//}
//int main(void)
//{
//    int a=1;
//    int b=2;
//    double c=1.1;
//    double d=2.2;
//
//    Swap(a,b);//这两个调用的函数并不是一个函数，这两个函数在调用之前会将模板实例化
//    cout<<a<<' '<<b<<endl;
//    Swap(c,d);
//    cout<<c<<' '<<d<<endl;
//}
//所以上面的函数实际上是调用的模版实例化后的函数，比如啊a,b,就是调用的下面的这个
//void Swap(int& x1,int& x2)
//{
//    int tmp=x1;
//    x1=x2;
//    x2=tmp;
//}

//总结：也就是说我们写一个模板由编译器推出类型并替换
//心里面先有一个准备  stl就是标准模板库












//二、函数模板的实例化
//1.
//template<class TT>
//TT add(const TT& x1,const TT& x2)
//{
//    return x1+x2;
//}

//int main(void)
//{
//    int a=1;
//    int b=2;
//    double c=1.1;
//    double d=2.2;
//
//    cout<<add(a,b)<<endl;
//    cout<<add(c,d)<<endl;//这样是可以的
//}





//template<class TT>//当然这里可以直接定义两个类型<class T1,class T2>
//TT add1(const TT& x1,const TT& x2)
//{
//    return x1+x2;
//}
//
//int add1(int& x1,int&x2)//两个函数名一样，优先调用这个
//{
//    return x1+x2;
//}
//
//int main()
//{
//    int a=1;
//    int b=2;
//    double c=1.1;
//    double d=2.2;
//////    cout<<add(a,d)<<endl;//参数类型不相同会报错    解决方法如下
//
//    cout<<add1(a,(int)d)<<endl;//解决办法之一，将参数先强制类型转换再使用
//
//    cout<<add1<double>(a,d)<<endl;//解决办法之二，指明该函数的转换类型
//    cout<<add1<int>(b,c)<<endl;//但是仅仅支持类型相近的，发生隐式类型转转换
//}


