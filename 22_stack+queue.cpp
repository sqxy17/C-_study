//首先得说明一点，21_的反向迭代器其实就是一种适配器,他就是对已有的东西进行封装

//栈和队列都是一种适配器

//什么是适配器？（又叫配接器）
//这个东西是用来转换的，举个例子就是手机需要的充电电压是50v，但是插排的电压是220v，充电头能将电压转换成50v进行充电，这个充电头就是适配器

//stack 和queue严格上来说已经不是容器了，他们两个是适配器，这两个都是由之前的容器转换过来的

//一、正题开始
//1.stack和之前的容器的区别
//emplate <class T, class Container = deque<T> > class stack;     ---- stack的模板定义
//这个参数里面定义了一个 Container           deque：双关队列



//template < class T, class Alloc = allocator<T> > class vector; // generic template      ----vector容器的定义，对比两者的区别
//这里面的一个参数是alloc    allocator： 也就是空间配置器





//2.stack 常见的函数接口         -----stack不支持迭代器
//pop()  push()   top()      empty()//这个是判断栈是否为空的函数








//二、栈的实际使用（部分）         -----要记得栈的特性，后进先出
#include<iostream>
using namespace std;
#include<stack>

void test_stack()
{
    stack<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    while(!s1.empty())//这个函数是用来判断是否为空的，判断是否为空，真的是空的就返回帧
    {
        cout<<s1.top()<<' ';
        s1.pop();
        cout<<endl;
    }
}

//int main(void)
//{
//    test_stack();
//}












//三、队列的使用（部分）
//比较重要的几个函数  push   pop    back      front
#include<queue>

void test_queue()
{
    queue<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    while(!s1.empty())//这个函数是用来判断是否为空的，判断是否为空，真的是空的就返回帧
    {
        cout<<s1.front()<<' ';//返回队头的元素
        s1.pop();//删除队尾的元素
        cout<<endl;
    }
}

//int main(void)
//{
//    test_queue();
//}
//



//这里的使用可以看cplus有多少函数，也可以有时间坏回来看oj题
//oj  22节课  1：50：00
//oj  23节课  00：00：00-1：20：00
