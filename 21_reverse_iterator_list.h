#pragma once


//反向的迭代器里面是包含着一个正向的迭代器的
//反向迭代器的++调用的是正向迭代器的--，反向迭代器的--，调用的就是正向迭代器的++
//反向迭代器的本质就是对正向迭代器的一种封装
//反向迭代器的解引用就是解引用正向迭代器的前面的一个位置

//反向迭代器其实就是一种适配器，他是对已有的的东西进行一种封装



namespace r_iterator
{
    //iterator是哪个容器的迭代器，reverse_iterator<iterator>就可以适配出哪个容器的反向迭代器，是一种复用的体现
    //无论传过来的哪个容器的迭代器，传过来正向的，就能适配出反向的迭代器
    template<class iterator,class ref,class ptr>//反向迭代器的本质就是对正向迭代器的一种封装
            class reverse_iterator
            {
            public:
                typedef reverse_iterator<iterator,ref,ptr> self;
                reverse_iterator(iterator it)
                :_it(it)
                {}


                ref operator*()
                {
                    iterator prev=_it;
                    return *--prev;
                }


                ptr operator->()
                {
                    return &operator*();
                }


                self& operator++()
                {
                    --_it;
                    return *this;
                }


                self& operator--()
                {
                    ++_it;
                    return *this;
                }



                bool operator!=(const self& rit)
                {
                    return _it!=rit._it;
                }
            private:
                iterator _it;
            };
}
//operator*取前一个位置，主要就是为了让反向迭代器的开始和结束，与正向迭代器的相对称     //完全可以不考虑对称自己去实现


//22节 00：00：00   typename在这个反向迭代器的使用，用到的话可以看

//重点推荐《stl源码剖析》