#include<iostream>
using namespace std;


//一、内联函数                 -----这就是为了解决频繁调用的小函数的优化

// int add(int x,int y)
//{
//     int z=x+y;
//     return z;
//}

//2.解决办法
//使用宏替换
//#define Add(x,y) ((x)+(y))
//
//int main(void)
//{
//     Add(1,2);//每次调用函数需要建立栈帧，栈帧中要保存一些寄存器，结束后又要恢复，这些都是需要消耗时间的
//     Add(1,2);
//     printf("%d",Add(1,2));
//}


//使用inline 内联函数
//inline int add(int x,int y)   //这种调用就不会再调用栈帧，而是会将这个add函数在main函数展开
// 只在release版本才会启动内联函数，debug版本下需要自己设置才能
//有了内联就不去用宏乐，宏比较复杂。
//{
//    int z=x+y;
//    return z;
//}
//
//int main(void)
//{
//    cout<<add(1,2)<<endl;
//    cout<<add(2,2)<<endl;
//    cout<<add(3,2)<<endl;
//}
//内联是拿空间换时间的做法，长度较长的函数（一般是10行以上）和递归函数不适合内敛



//inline不建议声明和定义分离，分离会导致链接错误，因为inline展开就没有函数地址了
//也就是不要.h和.cpp那种写法

