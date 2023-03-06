#include<iostream>
using namespace std;
//一、面向对象和面向过程的初步认识
//c是面向过程的，关住的是过程，分析出求解问题的步骤，通过函数调用逐步解决问题
//c++是基于面向对象的，关住的是对象，将一件事情拆分成不同的对象，靠对象之间的交互完成

//举个例子：一个外卖系统
//面向过程：关住实现的是下单、接单、送餐的这些过程       这些过程在代码的层面就是--方法/函数
//面向对象：关住的是类对象以及类对象之间的关系  ，用户、商家、骑手以及他们之间的关系        代码层面--类的设计以及类之间的关系

//c++是基于面向对象的：c++可以面向对象和面向过程混合编    因为c++兼容c
//java纯面向对象的：因为只面向对象






//二、类的引入
//1.举个例子，写一个学生的类          -----类的定义有两个关键字struct   class

//2.struct          这是用struct定义的一个学生类
//struct student
//{
//    char name[20];
//    int id;
//    int age;
//};
//
//int main(void)
//{
//    //可以这样定义一个学生
//    struct student s1;//在c中是这样定义的，除非typedef
//
//    //但是在c++中可以用结构体名字定义
//    student s2;//student就是类名，并且student也是类型
//    strcpy(s2.name,"zhangsan");//字符串数组不支持直接赋值  也就是这样是错误的->s2.name=""zhangasn"
//    s2.id=1;
//    s2.age=18;
//}
//兼容c struct的用法的原因是：为了c的库还能用


//c++的类和结构体不同的是，类里面不但可以定义成员变量，还可以定义成员方法（函数）    也叫成员函数
//struct student
//{
//    char _name[20];//加_是为了和成员方法中的变量加以区分
//    int _id;
//    int _age;
//
//    void Init(const char* name,int age,int id)
//    {
//        strcpy(_name,name);
//        _age=age;
//        _id=id;
//    }
//
//    void Print()
//    {
//        cout<<_name<<endl;
//        cout<<_age<<endl;
//        cout<<_id<<endl;
//    }
//};
//
//int main(void)
//{
//    student s1;//student就是类，是类型也是类名      s1就是实例化的对象，（也可以叫变量，毕竟student是一个类型）
//    student s2;
//
//    s1.Init("zhangsan",18,10086);
//    s2.Init("lisi",20,10087);
//
//    s1.Print();
//    printf("\n");
//    s2.Print();
//}


//3.class定义类
//class student//student就是类名   除了struct名字和class不同，其他都一样
//{
//
//};









//三、类的访问限定符和封装
//三个访问限定符：  public（公共的）    protected(保护)    private(私有的)

//访问限定符说明
//1.public修饰的成员在 类的外面 可以直接被访问
//2.protected和private修饰的成员在类外不能直接被访问（在这一点这两个限定符是相似的）
//3.访问权限 作用域从该访问限定符出现的位置直到下一个访问限定符出现时为止
//4.class的默认限定符是private，struct的默认访问限定符是public

//第2、3点说明
//class student
//{
//public:   //如果想从这里往下一直都是能被外部访问，在这里加上个public就行，注意这个符号   ：
//    char _name[20];
//    int _id;
//    int _age;
//
//    void Init(const char* name,int age,int id)
//    {
//        strcpy(_name,name);
//        _age=age;
//        _id=id;
//    }
////private://如果说不想让外部访问这个Print方法，那就这这里加上Private或者prptected            如果只是不想让访问这个，还可以在下面的函数前面加上public解除
//    void Print()
//    {
//        cout<<_name<<endl;
//        cout<<_age<<endl;
//        cout<<_id<<endl;
//    }
//};
//
//int main(void)
//{
//    student s1;//student就是类，是类型也是类名      s1就是实例化的对象，（也可以叫变量，毕竟student是一个类型）
//    student s2;
//
//    s1.Init("zhangsan",18,10086);
//    s2.Init("lisi",20,10087);
//
//    s1.Print();
//    printf("\n");
//    s2.Print();
//}
//建议定义类的时候将明确的访问限定符写出来，不要使用默认的






//四、封装
//1.C++实现封装的方法：用类将对象的属性与方法结合在一块，让对象更加完，通过访问权限选择性的将其接口提供给外部的用户使用
//封装是一种更好的严格管理，不封装是一种自由管理（但是不好）


//更好的严格管理体现在哪？
//数据和方法都封装到类里面。
//可以给你访问定义成共有，不想给你访问定义成私有或者保护。

//2.面向对象编程的三大特性
//封装   继承    多态
//封装：数据和方法都放在了类的里面           以及访问限定符








//五、类的作用域
//1.类相当于定义了一个新的作用域，类的所用成员都在类的作用域中。在类体外定义成员，需要使用::作用域解析符指明成员属于哪个类域，详细见8_test_stack
//class定义的类的大小怎么计算？
//类中的方法的大小（函数）不属于对象，也就是  student s1;sizeof(s1)计算的大小只有内存对齐后的成员变量。成员方法不算大小

//类被编译后不占用内存，是存在于公共代码段的

//class student
//{
//public:
//    char name[20];
//    int age;
//    int id;
//
//    void Init(char *arr,int a,int b)
//    {
//        strcpy(name,arr);
//        age=a;
//        id=b;
//    }
//};
//
//class test
//{
//
//};
//
//int main() {
//    student s1;
//    cout << sizeof(student) << endl;//输出的大小是一样的
//    cout << sizeof(s1) << endl;//计算类和类对象大小，只看成员变量，考虑内存对齐。对齐规则和c一致
//
////    s1.Init();//调用的是公共代码段
//
//    cout<<sizeof(test)<<endl;//空类的大小是1，这个1字节不存储有效数据,只是为了占位，表示对象存在
//
////对象的大小为什么不把成员函数（方法）计入，因为这些函数是放在公共代码段的
//}








//六、类的实例化
//看懂上面就知道了
//学生是个类，创建个学生s1就是实例化



//补充：两者定义类的区别就是一个默认共有一个私有

//类中的函数可能会当成内联函数使用