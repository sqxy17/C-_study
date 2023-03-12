#include<iostream>
using namespace std;

//一、运算符重载            -----operator（机器）操作员、运算符号
//1.c++为了增强代码的可读性引入了运算符重载，运算符重载是具有特殊函数名的函数，也具有返回值类型、函数名字以及参数列表。  其中返回值类型和参数列表和普通的函数类似
//运算符重载的出现就是为了计算自定义类型


//2.运算符重载的使用
//class data
//{
//public:
//    data(int year=0,int month=1,int day=1)
//    {
//        _year=year;
//        _month=month;
//        _day=day;
//    }
////private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
////具体使用例子
//bool operator>(const  data& d1,const data& d2)
////使用方法：int(这个返回值类型自己定义)  operator-(+、—、*、/、等运算符都可以)（变量，变量）
////函数名就是    operator操作符      操作符就是加减乘除那些
////返回类型看你return返回什么       甚至可以是自定义类型
////操作符能操作几个数，这种运算符重载函数就有几个参数
//{
//    if(d1._year>d2._year)//还要想办法把对象里面的变量访问
//        //粗暴点就是将类成员公有化      再或者设置取成员变量的函数           再或者用友元函数（后面才会学到）           或者像4.一样放在类里面
//    {
//        return true;
//    }
//    else if(d1._year==d2._year && d1._month>d2._month)
//    {
//        return true;
//    }
//    else if(d1._year==d2._year && d1._month==d2._month && d1._day>d2._day)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//int operator-(const data& d1,const data& d2)
//{
//    ;
//}
//
//
//int main(void)
//{
//    data d1(2022,1,16);
//    data d2(2022,1,31);
//    //    d1-d2;//默认情况下，c++是不支持自定义类型使用运算符  d1 d2是类这个类型          而自定义类型一般是指类、结构体
//
////  int a=(d2>d1);//这样也能成功的调用运算符重载函数，但是一般不这样使用，一般情况下会像下面这样使用
//    int a=operator>(d1,d2);//也就是像普通函数那样调用
//    //编译阶段会查看有没有重载这个运算符，如果重载这个运算符了，那么d1>d2会替换成operator>(d1,d2);
//
//    cout<<a<<endl;
//}






//3.运算符重载注意
//不能通过连接运算符以外的其他操作符进行重载    比如@不是运算符   然后这样使用就是错误的   int operator@(变量，变量)
//重载操作符函数里面，参数必须要有一个类（自定义）的类型参数
//运算符不重载不能改变其含义      也就是不能将d1+d2      实际上变成d1-d2
//作为类成员的重载函数时，其形参看起来比操作数目少1成员函数的
//操作符有一个默认的形参this，限定为第一个形参

//最重要的是这五个操作符不能进行运算符重载         .*     ::      sizeof      ?:       .(这个点是结构体、类成员的那个data._year的点)






//4.运算符重载设置为成员函数
//class data
//{
//public:
//    data(int year=0,int month=1,int day=1)
//    {
//        _year=year;
//        _month=month;
//        _day=day;
//    }
//
//    bool operator>(const data& d2)//在这里为什么只能有一个参数，因为d1调用，默认已经将d1的地址传过来了。用隐藏的this指针接收
//    //也就是说调用这个函数在编译后会变成 bool operator(data* const this,const datta& d2);
//    //又因为>只能操作两个变量，所以函数里面只能有两个参数。隐含的this指针也算一个
//    {
//        if(this->_year>d2._year)//这个this不写，后续编译器也会将其添上，这里只是为了明确表示出     类里面的_year都代表本对象的    if(_year>d2._year)
//
//        {
//            return true;
//        }
//        else if(this->_year==d2._year && this->_month>d2._month)
//        {
//            return true;
//        }
//        else if(this->_year==d2._year && this->_month==d2._month && this->_day>d2._day)
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main(void)
//{
//    data d1(2022,1,16);
//    data d2(2022,1,31);
//
//    int c=(d1>d2);//这样d1>d2也会转换成下面的  d1.operator>(d2);    所以后续工作可以这样写省点劲
//
//    int a=d1.operator>(d2);//放在类的里面就是成员函数了，成员函数的调用是   对象.成员函数名()
//    //就算有一个在类外面定义的同名的运算符重载函数也会和成员函数重载，优先调用类里面的函数
//    cout<<a<<endl;
//}










//二、赋值运算符重载                  赋值运算符重载也是默认成员函数之一，不定义也可以使用 并且使用规则和拷贝构造函数类似
//1.
//class data
//{
//public:
//    data(int year=0,int month=1,int day=1)//构造函数
//    {
//        _year=year;
//        _month=month;
//        _day=day;
//    }
//
//    data(const data& dd)
//    {
//        cout<<"hehe"<<endl;
//    }
//
//    data& operator=(const data& d2)//赋值操作符重载函数返回值是对象       返回引用效率高
//    {
//        if(this!=&d2)//这个是避免赋值的和被赋值的是相同的参数
//        {
//            _year=d2._year;
//            _month=d2._month;
//            _day=d2._day;
//        }
//        return *this;//this是本体的指针，所以应该进行解引用，解引用之后就是原本的参数
//        //但是请注意，这是传值，传值的时候会生成一个临时变量，临时变量拷贝了*this，调用一次         d5
//    }
//
//    bool operator>(const data& d2)
//    {
//        if(this->_year>d2._year)
//
//        {
//            return true;
//        }
//        else if(this->_year==d2._year && this->_month>d2._month)
//        {
//            return true;
//        }
//        else if(this->_year==d2._year && this->_month==d2._month && this->_day>d2._day)
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main(void)
//{
//    data d1(2001,1,2);
//    data d2(2002,3,4);
//    data d3(2003,4,5);
//
////    data d4(d1);//这样是用已经存在的对象初始化另一个对象，并创建出来      用的是拷贝构造函数
//    //
//
//    data d5;
////    d5=d1;//这样是调用成员函数（运算符重载函数）          成员内的函数会被抓换成d5.operator=(d1);
//    printf("----------------------------\n");
////    j=k=l;    =赋值运算符在赋值之后其实会有返回值，也就是所谓的左值，在连等之后会变成下个数字的右操作数
//    d3=d2=d1;     //两两赋值以后会有返回值，如果没有就会出错      返回值也就是左值，用来下一次赋值，下一次充当右值d4=d3    d5=d4
////所以这个运算符重载函数眼返回data类对象
////并且
//    d3=d5;
//}










//三、常量成员
//前面的运算符重载扩展里面的函数不改变参数的情况下可以加上const
//并且const不但要在函数后面加，也要在声明的后面加上
//class data
//{
//public:
//    void print()const     //如果对象定义的是const data d2这样常属性的对象，那么就会出现错误，因为this指针接收的data* const this 涉及到权限的放大了
//    //所以在函数的后面加上const就不会出现错误了       此时this指针是这样被定义的  const data* const this;
//    {
//        cout<<_year<<' '<<_month<<' '<<_day<<endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main(void)
//{
//    data d1;
//    d1.print();//权限缩小照样可以被访问
//
//    const data d2{};
//    d2.print();
//}






//四、取地址运算符的重载
//&就是取地址，可以对类进行取地址。同样是成员函数，不用去定义，系统给的就够用




