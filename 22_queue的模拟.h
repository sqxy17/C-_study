#pragma  once
#include<iostream>
#include<vector>        //数组类型的容器用这个，也就是说，需要用到连续的存储空间的用这个
#include<list>    //经常需要插入数据用这个容器，也就是存放空间并不连续的
using namespace std;
#include<deque>
#include<forward_list>

//一般情况下来说，适配器用删除插入较多的，尤其是头删较多的，用链表比较合适也就是list容器
namespace test1
{
    template<class T,class Container=deque<T>>
    class container_test
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


        const T& front()const
        {
            return _con.front();
        }

        const T& back()const//查看队尾的数据
        {
            return _con.back();
        }


        void push(const T& x)
        {
            _con.push_back(x);
        }


        void pop()
        {
            _con.pop_front();//队列出数据，删除数据都是要在队头，因为先进先出
        }

    private:
        Container _con;//
    };
}