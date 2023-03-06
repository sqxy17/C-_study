#include<iostream>
using namespace std;
//一、this指针
//隐含的this指针
//class data
//{
//public:
//    void Init(int year,int month,int day)
//    {
//        //第一种方法，用不同的名字区别
////        _year=year;
////        _month=month;
////        _day=day;
//
//        //第二种方法,用解析域的方法
//        data::year=year;//但是尽量别这样
//        data::month=month;
//        data::day=day;
//    }
//    //这个函数被调用后会变成
////    // void Init(data* this,int year,int month,int day)
////    {
////        this->year=year;
////        this->month=month;
////        this->day=day;
////    }
//
//    void  Print()    //其实是有一个隐藏的指针，在对象调用这个函数后会变成void Print(data* this);
//    {
//        cout<<year<<' '<<month<<' '<<day<<endl;
//        //在对象调用这个语句时也会变成  cout<<this->year<<' '<<this->month<<' '<<this->day<<endl;  谁调用this指针就换成谁
//        //包括上面的那个函数，虽然不允许成员函数形参中 定义this指针，但是不定义也可以直接使用
//        cout<<this->year<<":测试成功"<<endl;//但是一般情况下我们都不会直接将this写出来。虽然可以
//    }
//
//private:
//    int year;
//    int month;
//    int day;
//};


//成员函数中规定，成员函数不能传实参给this，调用的时候，不能将对象的地址传过去
//也就是不能这样定义函数 void test(data* this)  这个隐藏的this指针是当做关键字使用的，会报错

//int main(void)
//{
//    data d1;
//    data d2;//d1和d2的成员变量是不同的，但是调用的函数是相同的
//    const int* p1=nullptr;
//    int* p2=nullptr;
////    p1=p2;//不能通过*p1改变保存的值，但是能改变p1指向的地址
////    p2=p1;//这里报错是因为p1这个地址保存的变量是const的，p2是可读可写的，权限放大了
//
//    d1.Init(2019,06,01);//这个初始化和下面的输出是怎么调用的？
//    d2.Init(2019,07,01);//在调用这个函数的时候，会变成  d2.Init(&d2,2019,07,01);
//
//    d1.Print();//调用的输出名字都是一样的编译器怎么知道输出的是哪个对象的成员变量？
//    d2.Print();//调用的时候默认变成d2.Print(&d2),因为是结构体，所以上面cout输出的方式就是指针地址this->这种方式
//}

//this指针是存在栈区的，因为他是形参，所以是在栈上




//两道测试题
//class test
//{
//public:
//    void show1()
//    {
//        cout<<"嘿嘿嘿"<<endl;
//    }
//
//    void show2()
//    {
//        cout<<a<<endl;
//    }
//private:
//    int a;
//};
//int main(void)
//{
//    test* t1=nullptr;//t1是一个结构体的地址
//    t1->show1();//这个没错    虽然是空指针，但是编译阶段检查不出来，调用成员函数show1时，不会访问指针，所以正常运行
//
//    t1->show2();//这个是错误的      访问空指针了，会将空指针传给this，然后this->a出现错误
//}












//二、类的默认成员函数                      ----还是拿data类作为例子
//1.如果一个类中什么成员都没有，简称为空类。空类中如果我们什么成员都不设置，就会默认生成6个成员函数         前四个函数比较重要



//2.初始化和清理:        ----构造函数和析构函数
//构造函数：主要完成初始化工作    类似Init
//构造函数解释：构造函数是特殊的成员函数，需要注意的是，构造函数虽然名称叫做构造，但是构造函数的主要功能是初始化对象。这个函数并不会开空间创建对象
//构造函数特征：函数名和类名相同   没有返回值    对象实例化编译器自动调用对应的构造函数        构造函数可以重载
//如果类中没有显示的定义构造函数，c++编译器会自动生成一个无参的默认构造函数，一旦用户显式定义，编译器降不造生成
class test
{
public:
    test()//如果test的默认构造函数是有参数的就会报错test(int a),但是全缺省参数可以test(int a=9)
    {
        cout<<"test()"<<endl;
        _a=10086;
    }
private:
    int _a;
};
class data
{
public:
//    data(int year=0,int month=1,int day=2)//默认构造函数，推荐使用全缺省，咱们这样是显式的写了出来          构造函数就是和类名相同的函数
//    //把这个函数注释掉，系统会生成一个无参的构造函数，但是这个系统给的构造函数，会根据参数的类型进行不同的处理
//    //类型分为两种：内置类型（int,char,double,指针,数组等）、自定义类型（struct、class定义的类型）
//    //默认生成的无参构造函数对内置类型不进行处理        自定义类型才会去调用无参默认构造函数去进行初始化（成员变量中有个类的变量）
//    {
//        _year=year;
//        _month=month;
//        _day=day;
//    }

    void Print()
    {
        cout<<_year<<' '<<_month<<' '<<_day<<endl;
    }
private:
    int _year;
    int _month;
    int _day;
    test t1;
};
int main(void)
{
    data d1;
    d1.Print();
    data d3;
    d3.Print();

//    data d2(2019,6,1);//可以直接这样进行初始化
//    d2.Print();
}


//析构函数：主要完成清理工作      类似Destory

//拷贝复制:

//取地址重载
