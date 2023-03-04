//一、开头的废话
//1.首先有时间看一本《高质量程序设计指南》
// 学完初阶看《（more）effectiveC++》《effectiveSTL》《c++编程规范》
//进阶的时候看《c++对象模型》
// 五年之内《深入探索c++对象模型》                   ----《c++primer》这玩意是c++字典


//2.C++98标准：也就是c++标准的第一个版本，，绝大多数编译器都支持，以模板方式重写C++标准库，并且引入了STL（标准模板库）
//其实也就是1998年定的标准，在这里就相对比较完善了。


//3.C++11标准：增加了许多新特性，比如：正则表达式、基于范围for循环、auto关键字、新容器、列表初始化、标准线程库等。
//11标准和98标准是两个关住的重点


//4.c++一共63个关键字，c语言一共32个关键字。详见word中图片


//5.c++是向下兼容的，也就是说c语言的语法都可以在.cpp里面使用            本章的学习旨在学习c语言特性不足的补充




//二、c语言中的命名冲突问题
#include<stdio.h>
//1.我们定义的函数名、变量名可能会和库函数里面的相同
////例如：
//#include<stdlib.h>
//int main(void)
//{
//    int rand=0;//此处的rand编译就不会通过，因为stdlib.h的头文件里面包含着随机函数就是这个名字
//}


//2.以后的项目中，需要很多人来同时完成一个项目，一个项目被划分成不同的模块，会有人在不同的模块中使用了相同的变量名字或者函数名字。
//也就是说c语言中并没有很好的办法解决这个问题




//三、关键字：namespace                 ----该关键字是用来定义命名空间的
//1.这个关键字就是用来解决，命名冲突问题的

//例如：
//#include<stdlib.h>//这个头文件里面包含着rand随机函数
//
//namespace llk   //定义了一个名为llk的命名空间，看见llk也就是说这个命名空间的名字是自定义的               -----但是这个命名空间只能在函数外面定义，本质是定义了域
//{
//    int rand=6;//虽然调用了stdlib.h头文件，但是还是能成功自定义和库函数名相同的自定义变量
//}
//
//int main(void)
//{
//    printf("%d ",rand);//这样普通的方式去访问访问的是头文件里面的函数的地址
//}


//2.补充
//定义的命名空间就是一个----域
//这个域的意思就是例如全局变量的作用域是文件，局部变量的作用域啥是这个函数
//函数使用变量的规则是：优先在局部变量中查找使用的变量，如果没有，再去全局变量中查找、再接着是引用的头文件中





//四、访问命名空间中的变量（访问自定义域中的变量）           ----使用符号   ::
//1.例如;
//#include<stdlib.h>
//
//namespace llk
//{
//    int rand =9;//此处定义的变量其性质还是全局变量，放在静态区里面
//
//    int add(int x,int y)//除了在自定义空间中定义变量，还能定义函数
//    {
//        return x+y;
//    }
//
//    typedef struct test//也能定义各种类型，还能定义的有很多,枚举、联合、等等等
//    {
//        int a=9;
//        int arr[8]={0};
//    }test;
//
//    struct test1
//    {
//        int a=9;
//    };
//}
//
//int test=99;//这个地方test的名字可以和主函数里面的test相同是因为所在的域不同，这个test变量所在的地方是全局域
////int rand=999;//局部变量里面能够定义rand，因为库函数包括的rand函数算作在全局变量中
//int main(void)
//{
//    int test=10086;//这个test在的是局部域
//    printf("%d\n",rand);//这样直接访问是访问的库函数里面的函数名字
//    printf("%d\n",llk::rand);//这样才是访问自定义域中的变量
//    printf("%d\n",test);//优先访问的这个名字肯定局部的
//    printf("%d\n",::test);//::左边是空白的，空白的意思就是去全局域中去查找。
//}



//2.如何使用命名空间中的变量       用的1的llk
//int main(void)
//{
//    llk::rand=10086;
//    llk::test t1={1,{1,2,3,4,5}};//里面递重命名后的结构体可以这样用
//    struct llk::test1 t2={2};
//    int add=llk::add(5,6);
//    printf("%d\n",llk::rand);
//    printf("%d\n",t1.a);
//    printf("%d\n",t2.a);
//    printf("%d\n",add);
//}


//3.命名空间的循环嵌套
//namespace llk1
//{
//    namespace llk2
//    {
//        int a=9;
//    }
//}
//int main(void)
//{
//    printf("%d",llk1::llk2::a);
//}



//4.命名空间的名字相同
//命名空间相同的情况下会合并在一起，
// 比如一个test.h头文件中，命名空间包含了函数声明
//namespace llk
//{
//    int add(int x,int y);
//    int sub(int x,int y);
//}
//// 另外的test.cpp文件中包含着声明函数的实现
//namespace llk
//{
//    int add(int x,int y)
//    {
//        return x+y;
//    }
//
//    int sub(int x,int y)
//    {
//        return x-y;
//    }
//}

//然后test.cpp调用test.h头文件之后，就会合并成
//namespace llk
//{
//    int add(int x,int y);
//    int sub(int x,int y);
//
//    int add(int x,int y)
//    {
//        return x+y;
//    }
//
//    int sub(int x,int y)
//    {
//        return x-y;
//    }
//}



//六、命名空间的三种使用方式
//1.使用域限定符::进行操作      -----也就是上面的那些使用的方式

//2.使用using将命名空间全部展开
//#include<stdlib.h>
//namespace llk
//{
//    int rand=9;
//    int a=1;
//    int b=2;
//}
////using namespace llk;//这就相当于将里面的变量放在全局域当中
//
//int main(void)
//{
//    printf("%d",b);
//}


//3.展开常用的个别变量
//using llk::a;
//这样输出a的时候，就可以直接输出a了
