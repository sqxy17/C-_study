//template <class T,           class Container = vector<T>,     class Compare = less<typename Container::value_type> > class priority_queue;
//请注意这个适配器是有三个参数的，第二个参数默认的适配器是vector     第三个参数是仿函数（函数对象）

//Compare：比较，有点像qsort设计一个比较的函数才会是升序或者是降序   ----- 这个参数就是让传入一个函数

//less<typename Container::value_type> >    -----后面的这一堆就是仿函数（也叫函数对象）      这个less是库里面的函数     less是queue里面的函数  大的优先级高
//greater<typename Container::value_type>>     ---greater也是库函数   这个函数是functional  这个库里面的库函数         -----小的优先级高


//优先级队列底层的本质是堆。并且对容器的迭代器要求是一个随机类型的迭代器

//前言：首先这个优先级队列还是一个容器适配器，但是和stack，queue这两种适配器差异还是很大的

#include<iostream>
#include<queue>//想要使用适配器，不仅适配器需要头文件，容器也需要头文件
#include<vector>
using namespace std;
#include<functional>


void test_priority1()
{
    priority_queue<int>p1;   //默认第二个参数是vector<T>       默认的第三个参数是less<T>，底层也就是创建了一个大根堆        仿函数就是less
    p1.push(5);
    p1.push(2);
    p1.push(3);
    p1.push(7);
    p1.push(1);

    while(!p1.empty())
    {
        cout<<p1.top()<<' ';   //7 5 3 2 1  默认是大的优先级高，也就是说默认底层是一个大堆
        p1.pop();
    }
    cout<<endl;
}


void test_priority2()
{
    priority_queue<int,vector<int>,greater<int>>p1;//想要传入第三个参数，那么第二个参数就必须要写了          第三个参数         仿函数就是greater
    p1.push(5);
    p1.push(2);
    p1.push(3);
    p1.push(7);
    p1.push(1);

    while(!p1.empty())
    {
        cout<<p1.top()<<' ';   //1 2 3 5 7也就是说底层是一个小根堆          其实像依次取出来就是一种堆排序
        p1.pop();
    }
    cout<<endl;
//    printf("%d",greater<int>());         //像  greater<int>  就是一个就是一个类型     greater<int>() 就是一个匿名对象
}


void test_priority3()//将容器内的东西进行排序
{
    int arr[10]={1,3,5,7,9,2,4,6,8,10};
    //容器一般都会支持迭代器区间初始化
    vector<int>v1(arr,arr+10);  //可以将数组中的数据放书容器，
    priority_queue<int>p1(v1.begin(),v1.end());//适配器的本质也是一个类型，并且这个类型的参数还是类型       priority_queue<int>-这就是类型      priority<int,vector<int>>--模板里面的参数也是int
    while(!p1.empty())
    {
        cout<<p1.top()<<' ';
        p1.pop();
    }
    cout<<endl;
}

//int main(void)
//{
////    test_priority1();//默认的这个是大的优先级高    ----//class Compare = less<typename Container::value_type> > class priority_queue;
////    test_priority2();
////    test_priority3();
//
////上面的三个test只是使用，下面的测试是自己模拟的优先级队列的测试
//}