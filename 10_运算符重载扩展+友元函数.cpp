#include "10_运算符重载扩展+友元函数.h"
//里面的运算符其他类也可以这样使用

//查看当月的最大天数
int maxday(int year,int month)
{
    int montharr[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(month==2)
    {
        if((year%400==0)||(year%4==0&&year%100!=0))
        {
            return montharr[month]+1;
        }
        else
        {
            return montharr[month];
        }
    }
    return montharr[month];
}


//日期的构造函数
data::data(int year,int month,int day)//尽量在头文件中缺省，在函数定义阶段不去缺省
//建议在初始化列表进行初始化，内置类型无所谓，但是自定义类型强烈强烈建议在初始化列表初始化
{
     _year=year;
     _month=month;
     _day=day;

     if(year<0 || (month>12 || month<0) || ( day<0||day>(maxday(year,month) )))
     {
         assert(0);
     }
}


//输出日
void data::print()
{
    cout<<_year<<' '<<_month<<' '<<_day<<endl;
}



//+=的运算符重载
data& data::operator+=(int day)//使用+=是因为要改变自身
{
    _day+=day;
    while(_day>maxday(_year,_month))
    {
        _day-=maxday(_year,_month);
        _month++;
        if(_month==13)
        {
            _month=1;
            _year++;
        }
    }
    return *this;
}



//-=的实现
data& data::operator-=(int day)
{
    _day-=day;

    while(_day<=0)
    {
        --_month;
        if(_month==0)
        {
            _month=12;
            _year--;
        }
        _day+=maxday(_year,_month);
    }
    return *this;
}

data data::operator-(int day)
{
    data tmp(*this);
    *this-=day;
    return tmp;
}


//+号的运算符重载
data data::operator+(int day)//参照实现-
{
    data dtmp(*this);//米奇妙妙屋
    dtmp+=day;
    return dtmp;
}



//下面的++   --需要考虑是前置++（++a）   还是后置++（a++）



//前置++
data& data::operator++()
{
    *this+=1;
    return *this;
}



//后置++
data data::operator++(int)
{
    data tmp(*this);
    *this+=1;
    return tmp;
}




//前置--
data& data::operator--()//本身就有一个默认的参数
{
    *this-=1;
    return *this;
}



data data::operator--(int)
{
    data tmp=*this;
    *this-=1;
    return tmp;
}


//>的实现        -----此外我们要学会复用，   复用也就是将实现过的重载用于其他符号重载的实现    比如我们用+=非常简单的实现了+
//所以后续要学会用> ,==  复用实现其他的符号 >=  <=
bool data:: operator>(const data& d)
{
    if(_year>d._year)
    {
        return true;
    }
    else if(_year==d._year && _month>d._month)
    {
        return true;
    }
    else if(_year==d._year && _month==d._month && _day>d._day)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool data::operator<(const data& d)
{
    return !(*this>d);
}




//==的实现
bool data::operator==(const data& d)
{
    if(_year==d._year && _month==d._month && _day==d._day)
    {
        return true;
    }
    else
    {
        return false;
    }
}



//>=的实现
bool data::operator>=(const data &d)
{
    return *this>d || *this==d;
}


//<=的实现
bool data::operator<=(const data& d)
{
    return *this==d || !(*this>d);
}



//!=的实现
bool data::operator!=(const data &d)
{
    return !(*this==d);
}

//计算两个日期相差多少天
int data::operator-(const data& d)
{
    data max=*this;
    data min=d;
    int flag=1;
    if(*this<d)
    {
        max=d;
        min=*this;
        flag=-1;
    }
    int count=0;
    while(min!=max)
    {
        ++count;
        ++min;
    }
    return flag*count;
}






//计算星期几
void data::printweekday()
{
    data start(1900,1,1);
    int count=*this-start;//现在和明天差一天
    int num=(count+1)%7;
    printf("星期：%d",num);
}
//传参或者传引用的过程中，如果存在连续的构造，或者拷贝构造就会被优化






void data::operator<<(ostream& out)//这个是定义在类里面的成员函数       类里面的成员函数里面的参数第一个指针默认是this，不能改变
{
    out<<_year<<' '<<_month<<' '<<_day<<endl;
}



//这个是定义在全局变量的函数
ostream& operator<<(ostream& out,const data& d)//不在类里面定义的函数就没有默认的this指针
{
    out<<d._year<<' '<<d._month<<' '<<d._day<<endl;
    return out;
}
//
//正常使用的时候可以用多个值一起输出，所以要有返回值，返回ostream，也就是返回out





//流插入运算符重载
istream& operator>>(istream& in,data& d)
{
    in>>d._year>>d._month>>d._day;
    return in;
}