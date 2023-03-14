#pragma once
#include<iostream>
#include<assert.h>
using std::cout;
using std::cin;
using std::endl;

namespace llk
{
    class string
    {
    public:
        //---迭代器的模拟
        typedef char* iterator;//此处的迭代器是指针类型，但是其他类里面就不一定是这样定义的了    ----也就是说各个类的迭代器是不一样的       这个定义的是不能更改的
        //---字符串首元素地址
        iterator begin()
        {
            return _str;
        }



        //---字符串尾元素地址
        iterator end()
        {
            return _str+_size;
        }

        //---这个版本的迭代器只能读取，不能进行修改
        typedef const char* const_iterator;
        const_iterator cbegin()const
        {
            return _str;
        }



        //---字符串尾元素地址
        const_iterator cend()const
        {
            return _str+_size;
        }


        //---范围for会被替换成迭代器



        //---这是构造函数(有参)
        string(const char* str="\0")//这样缺省参数就是\0了
        :_size(strlen(str))
        ,_capacity(_size)
        {
            _str=(new char[_capacity+1]);//这里就是初始化列表，专门赋值用的地方 _str=地址
            strcpy(_str,str);
        }

        //---这是拷贝构造函数---这种写法是深拷贝，保存的值拷贝过来但不保存在同一个空间         -----ps:这种也是传统的写法
//        string(const string& s)
//        {
//            _size=s._size;
//            _capacity=s._capacity;
//            _str=new char[_capacity+1];
//            strcpy(_str,s._str);
//        }

        //---这种是现代写法
        string(const string& s)
        {
            string tmp(s._str);//用s的字符串初始化tmp
        }


        //---赋值成员函数
        string& operator=(const string& s1)
        {
            if(this->_str!=s1._str)
            {
                char* tmp=new char[s1._capacity+1];//这么做是为了避免开辟空间失败
                delete[] _str;
                strcpy(tmp,s1._str);
                _str=tmp;
            }
            else
            {
                ;
            }
            return *this;
        }



        //---c_str模拟
        const char* c_str()const//函数后面的这个const证明this指针是具有常属性的
        {
            return _str;
        }


        //---size()模拟
        size_t size()const
        {
            return _size;
        }


        //---[]的重载         -----可改写的版本
        char& operator[](size_t pos)
        {
            assert(pos<this->_size);
            return _str[pos];
        }



        //---[]的重载        -----不可改写的版本
        const char& operator[](size_t pos)const
        {
            assert(pos<this->_size);
            return _str[pos];
        }


        //---push_back的模拟
        void push_back(char& ch)
        {
            if(_size==_capacity)
            {
                delete[] _str;
                _str=new char[_capacity*1.5];
            }
        }



        //---append()函数的模拟
        void append()
        {

        }




        //---operator+=的重载      -----要重载两个这个函数，一个函数的参数是字符    另一个函数的参数是字符串
        void operator+=(const string)
        {

        }

        ~string()
        {
            delete[] _str;
            _str=nullptr;
        }
    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    };

}