#pragma once
#include<iostream>
#include<assert.h>

//vector有自己的swap函数

namespace  llk
{
    template<class T>//我们此处的还是模拟，没有使用空间配置器
    class vector
    {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;//这个就不测试了，只读的就是需要将函数重载一遍
        //构造函数     无参版本
        vector()
        :_start(nullptr)
        ,_finish(nullptr)//末尾元素的指针
        ,_endofstorage(nullptr)//数组最大容量的指针
        {}



        template<class InputIterator>//一个类模板的成员函数，又可以是一个函数模板
        //InputIterator本身也是一个模板



        //拷贝构造函数  迭代器区间版本
        vector(InputIterator first,InputIterator last)//这样写就是为了不同类的迭代器都能进行迭代器区间初始化，因为有可能传的是string的迭代器类型过来
        //这里就是为了接收一段连续的空间
        //参数是迭代器类型的，名字其实是一种规范，函数模版的模版参数命名是有规范的
        :_start(nullptr)
        ,_finish(nullptr)//末尾元素的指针
        ,_endofstorage(nullptr)//数组最大容量的指针
        {
            while(first!=last)
            {
                push_back(*first);
                ++first;
            }
        }


        //拷贝构造函数     ---传统写法
//        vector(const vector<T>& v1)
//        {
//            _start=new T[v1.capacity()];
//            _finish=_start+v1.size();
//            _endofstorage=_start+v1.capacity();
//            memcpy(_start,v1._start,v1.size()*sizeof(T));//最后一个参数是字节数
            //所以说传统写法都要考虑自定义类型的深浅拷贝问题
//        }



        void swap(vector<T>&v)
        {
            std::swap(v._start,_start);
            std::swap(v._finish,_finish);
            std::swap(v._endofstorage,_endofstorage);
        }


        //拷贝构造函数      现代写法
        vector(vector<T>& v1)
        :_start(nullptr)
        ,_finish(nullptr)
        ,_endofstorage(nullptr)
        {
            vector<T>tmp(v1.begin(),v1.end());//现在问题就来了，string的现代写法是调用了有参的构造函数，这个是无参的,现在还需要一个有参的，可以使用迭代器区间的构造函数
            swap(tmp);
        }


        //析构函数
        ~vector()
        {
            if(_start)
            {
                delete[] _start;
            }
        }



        //[]的重载
        T& operator[](size_t i)
        {
            assert(i<size());
            return _start[i];
        }



        //=的重载   传统的写法谁都会，现在写一份现代的写法
        vector<T>& operator=(vector<T> v1)//这个只是形参，出了函数就会被销毁
        {
            swap(v1);
            return *this;
        }





        //begin()
        iterator begin()
        {
            return _start;
        }



        //end()
        iterator end()
        {
            return _finish;
        }



        //计算元素个数（也就是长度size）
        size_t size()const
        {
            return _finish-_start;
        }



        //数组的最大容量
        size_t capacity()const
        {
            return _endofstorage-_start;
        }






        //扩容函数
        void reserve(size_t n)//这里的扩容不仅仅要考虑存放的是内置类型的   还要考虑存放的是自定义类型的
        {//本身vector容器就是在堆上开辟的空间
            if(n>capacity())
            {
                size_t num=size();//用于计算更新后的finish的位置
                T* tmp=new T[n];
                if(_start)
                {
                    //方式一
                    memcpy(tmp,_start,sizeof(T)*size());//memcpy（空白的空间，已经存在的空间，字节数）//将已经存在的空间的内容拷贝到空白空间，最后的参数是拷贝的字节数



                    //方式二
                    for(size_t i=0;i<num;++i)//
                    {
                        tmp[i]=_start[i];
                    }
                    delete[] _start;
                }
                _start=tmp;
                _finish=_start+num;
                _endofstorage=_start+n;
            }

        }



        //尾插函数
        void push_back(const T& x)//这个x还可能是前面演示的字符串
        {
            if(_finish==_endofstorage)//因为要插入数据，原有的空间不够
            {
                //需要扩容
                reserve(capacity()==0?4:capacity()*2);//刚开始插入的只有一个，这里是直接给了能存放4个T类型的空间（T可以是内置类型）
            }
            *_finish=x;
            ++_finish;
        }



        void resize(size_t n,const T& val=T())//可能初始化为一个vector  缺省值      int()就是0   int*()就是空指针    vector()就会调默认的构造函数
//          内置类型()也可认为是调用构造函数，默认是0   指针类型默认是nullptr   能这样使用是因为兼容模板
//还能这样去使用 int k=int(10);    int m(20);
//如果T是vector类型，那么T()就是匿名对象，如果被const引用，那么他的生命周期就会被延长
        {
            if(n<size())
            {
                _finish=_start+n;
            }
            else
            {
                if(n>capacity())
                {
                    reserve(n);
                }
                while(_finish!=_start+n)//这个函数会初始化到——start+n处
                {
                    *_finish=val;
                    ++_finish;
                }
            }
        }






        //尾删
        void pop_back(vector<T>&v)
        {
            if(_finish!=_start)
            {
                --_finish;
            }
            else
            {
                assert(0);
            }
        }



        //插入
        iterator insert(iterator pos,const T& x)//插入的是地址          防止失通常的解决方法是返回整改的值，如果再去使用使用返回值
        {
            assert(pos>=_start && pos<=_finish);
            if(_finish==_endofstorage)
            {
                //这个地方需要注意，扩容会导致pos失效，也就是需要更新一下pos
                size_t len=pos-_start;
                reserve(capacity()==0?4:capacity()*2);
                pos=_start+len;
            }
            iterator end=_finish-1;
            while(end>=pos)
            {
                *(end+1)=*end;
                --end;
            }
            *pos=x;
            ++_finish;
            return pos;
        }



        //对指定位置进行删除
        iterator erase(iterator pos)//   可以说是两种解决方式吧
        {
            assert(pos>=_start && pos<_finish);
            iterator begin=pos+1;
            while(begin<_finish)
            {
                *(begin-1)=*begin;
                ++begin;
            }
            --_finish;
            return pos;
        }

    private:
        iterator _start;
        iterator _finish;//指向的最后一个元素的下一个地址
        iterator _endofstorage;//storage:仓库，信息存储的空间      指向最大容量的下一个地址的位置
    };
}


//扩展  迭代器分类          -----这么多迭代器的原因是因为容器有不同的结构
//传入类型不匹配的迭代器会报错

//1.input_iterator   只写迭代器         ----只读和只写没有固定的类型
//2.out_iterator  只读迭代器
//3.forwad_iterator  单向迭代器（forwad:向前）        ---forwad lis/    unordered map / unordered set   /  这种迭代器只能++
//4.bidirectional_iterator    双向迭代器（bidirectional:双向的）list/map/set   只能++ --

//5.randomaccess_iterator    随机迭代器   vector/deque       （这种迭代器的特征就是能++ -- + -）也就是说底层的基本结构是连续的数组，其迭代器一般是随机迭代器
//vector   string   这俩都是




//迭代器可向下但是不能向上。（1，2同级别）  也就是说参数是3的类型，4，5也能用     参数是4的类型，5也能用       但是参数是5的类型，其他都不能用
