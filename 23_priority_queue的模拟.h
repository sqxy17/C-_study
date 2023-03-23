#pragma once
#include<iostream>
using namespace std;
#include<vector>

//首先我们要记起来，堆的物理结构是数组，逻辑结构才是完全二叉树

//namespace llk
//{
//    //现在默认写出的适配器的优先级是大的有限，也就是大堆
//    template<typename T,typename container=vector<T>>     //仿函数暂时先不传，仿函数的本质就是用来控制是大堆还是小堆的
//    class priority_queue
//    {
//    public:
//        //适配器和容器有点类似，也是需要有自己的构造函数
//        //适配器里面的成员变量是容器，并且这个容器是一个实例化后的，比如：vector<T>，也就是说，其成员变量也是一个自定义类型
//
//
//
//        priority_queue()//------构造函数，构造函数没啥意义，适配器就是个贴牌，实际用来存储的还是容器，容器在创建的时候已经进行初始化了，不用进行额外的操作了
//        {}
//
//
//
//
//        template <typename inputiterator>//input说明任意一种迭代器都可以
//        priority_queue(inputiterator first,inputiterator last)//这个是迭代器区间初始化
//        :_con(first,last)//虽然将一个容器内的连续的区间传了过来，但是在_con这个容器里面还可能是乱序的，因此要进行堆排序一下
//        {
//            //最重要的是这个容器是按照堆的存储方式进行存储的
//            //建堆有两种方式，这里采用向下调整的方式，先从最后一个叶结点的父节点开始
//
//            for(int i=(_con.size()-2)/2;i>=0;i--)
//            {
//                adjust_down(i);//
//            }
//        }
//
//
//
//
//
//        void adjust_up(size_t child)//这个是向上调整
//        {
//            size_t parent=(child-1)/2;
//            while(child>0)
//            {
//                if(_con[child]>_con[parent])//这个是向上调整，至于调整成为大堆还是小堆，看这个比较符号
//                {
//                    swap(_con[child],_con[parent]);//因为是vector容器，可以直接用下标的方式访问数据
//                    child=parent;
//                    parent=(child-1)/2;
//                }
//                else
//                {
//                    break;
//                }
//            }
//        }
//
//        void push(const T& x)//尾插需要用到向上调整
//        {
//            _con.push_back(x);//这个是尾插，尾插需要向上调整
//            adjust_up(_con.size()-1);//向上调整是往上查看插入的结点他的父亲是否比他大或者小
//        }
//
//
//
//
//
//
//
//
//
//        void adjust_down(size_t parent)//这个是向下调整
//        {
//            size_t child=parent*2+1;//默认的孩子是左孩子
//            while(child<_con.size())
//            {
//                if(child+1<_con.size() && _con[child]<_con[child+1])
//                {
//                    child+=1;
//                }
//
//                if(_con[child]>_con[parent])
//                {
//                    swap(_con[child],_con[parent]);
//                    parent=child;
//                    child=parent*2+1;
//                }
//                else
//                {
//                    break;
//                }
//            }
//        }
//
//        void pop()//删除需要用到向下调整      删除的整体思路是，将对堆顶元素和最后一个元素交换，然后将最后一个元素删除，在把末尾的那个元素向下调整
//        //至于调整成大堆还是小堆需要看实现的调整的比较符号是怎么样的
//        //删除的前提是已经是一个堆了，都已经是堆顶元素的删除了
//        {
//            assert(!_con.empty());
//            //
//            swap(_con[0],_con[_con.size()-1]);
//            _con.pop_back();
//            adjust_down(0);
//        }
//
//
//
//
//        const T& top()
//        {
//            return _con[0];
//        }
//
//        size_t size()
//        {
//            return _con.size();
//        }
//
//        bool empty()
//        {
//            return _con.empty();
//        }
//    private:
//        container _con;//支持传入随机的迭代器，至于模板中的T，就是这个传入的迭代器将要保存的数据的类型，容器就是用来打工的，适配器就是来操控容器的
//        //_con就是传入的容器的实例化
//    };
//
//}
//这里是没有仿函数的












//说明一点，仿函数就是用来替代函数指针的

//实现一个简单的仿函数
//struct test_less//现在这个整体就叫仿函数了          别忘了在c++中struct定义的也叫类test_less(1,2),然后还有返回值，这就是仿函数
//{
//    bool operator()(int x,int y)//这个（）实现了一个x<y
//    {
//        return x<y;
//    }
//};
//上面的还可以这样定义   class test_less   当然，如果这样定义的话，下面的那个bool函数就要在共有成员中定义


//根据上面在定义一个
//struct test_greater     //test_greater 这个就是仿函数类型      实例化的对象叫函数对象
//{
//    bool operator()(int x,int y)//形参有没有，有多少，返回值类型，都可以自己去设置，看你想要实现的功能
//    {
//        return x>y;}
//};
////test_greater t1;  t1(1,2)   也就是说这两个类实例化之后，他们的对象可以像函数调用一样调用内部的重载函数
//
//
//
//
//
////比较的类型如果不知道怎么办？
template <class T>
struct test_less
{
    bool operator()(const T& x,const T& y)const
    {
        return x<y;
    }
};
//此时使用仿函数就可以这样去使用了
//test_less<int>less;
//还能使用匿名对象 test_less<int>(1,2);
template <class T>
struct test_greater
{
    bool operator()(const T& x,const T& y)const
    {
        return x>y;
    }
};





namespace llk
{
    template<typename T,typename container=vector<T>,class compare=test_greater<T>>//现在实现的是有仿函数版本的
            //仿函数主要就是来控制大堆小堆的
    class priority_queue
    {
    public:
        compare com;//默认的less函数是左边小于右边才返回真


        priority_queue()
        {}


        template <typename inputiterator>
        priority_queue(inputiterator first,inputiterator last)
                :_con(first,last)
        {

            for(int i=(_con.size()-2)/2;i>=0;i--)
            {
                adjust_down(i);//
            }
        }



        void adjust_up(size_t child)
        {
            size_t parent=(child-1)/2;
            while(child>0)
            {
//                if(_con[child]>_con[parent])
                //用less的情况下就得这样
                if(com(_con[parent],_con[child]))//看看test_less类的定义，传入的两个x,y怎么样才会返回真
                {
                    swap(_con[child],_con[parent]);
                    child=parent;
                    parent=(child-1)/2;
                }
                else
                {
                    break;
                }
            }
        }

        void push(const T& x)
        {
            _con.push_back(x);
            adjust_up(_con.size()-1);
        }









        void adjust_down(size_t parent)
        {
            size_t child=parent*2+1;
            while(child<_con.size())
            {
                if(child+1<_con.size() && com(_con[child],_con[child+1]))
                {
                    child+=1;
                }

                if(com(_con[parent],_con[child]))
                {
                    swap(_con[child],_con[parent]);
                    parent=child;
                    child=parent*2+1;
                }
                else
                {
                    break;
                }
            }
        }

        void pop()

        {
            assert(!_con.empty());
            //
            swap(_con[0],_con[_con.size()-1]);
            _con.pop_back();
            adjust_down(0);
        }




        const T& top()
        {
            return _con[0];
        }

        size_t size()
        {
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }
    private:
        container _con;

    };

}





