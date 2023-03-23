#pragma once

#include<iostream>
#include<vector>        //数组类型的容器用这个，也就是说，需要用到连续的存储空间的用这个
#include<list>    //经常需要插入数据用这个容器，也就是存放空间并不连续的
using namespace std;
#include<deque>
#include<forward_list>

//前言：适配器是一种设计模式(又叫配接器模式)，该种模式是将一个类的接口转换成客户希望的另一个接口
//设计模式是一套被反复使用的，多数人知晓的，经过分类编目的，代码设计经验的总结
//也就是说，我们再去写一个数组栈或者一个链式栈，并不需要从头开始写了，而是适配一下之前的容器就行

//一、具体的设计

//1.早起的适配器仅仅是简单的复用
//namespace test
//{
//    template<class T>
//    class stack_t
//    {
//    public:
//        void push(const T& x)
//        {
//
//        }
//
//    private:
//        vector<T> _v;//这里的vector也用T，是因为现在的这个stack也是一个模板。但是这种适配器应用的场景非常小，比如要用链表，还得重新去定义
//    };
//}
//所以下面的才是经常使用的适配器模式





//2.常见的适配器的内部模拟
namespace test
{
    template<class T,class Container=deque<T>>//这个也是deque<T>是适配器的缺省参数，也就是说，如果不传入容器，默认调用的容器就是deque<T>
            //ps:模版参数控制的是类型，模版参数的缺省值控制的是对象
    //container:容器,直接将容器当做模版参数，传进来不同的容器，这个适配器就是不同类型的栈
    class container_test//这个是将传来的容器适配成为一个栈
            //如果适配成栈就要记住后进先出，也就不支持迭代器
    {
    public:
        bool empty()const
        {
            return _con.empty();
        }


        size_t size()const
        {
            return _con.size();
        }


        const T& top()const//栈顶的值
        {
            return _con.back();//back，尾巴，后面的  用来取尾上元素的函数
        }


        void push(const T& x)
        {
            _con.push_back(x);//使用的传入的容器的接口       如果传入的容器不支持尾插尾删是会报错的，也就是说想要用模板调用容器的接口，前提是容器的接口是存在的
        }


        void pop()
        {
            _con.pop_back();//调用的是传入的容器的接口
        }

    private:
        Container _con;//
    };
}