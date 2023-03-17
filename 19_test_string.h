#pragma once
#include<iostream>
#include<assert.h>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
//不考虑增删查改的时候就不用管capacity  size的事情，都不用去定义


void swap(char*& p1,char*& p2)
{
    char* tmp=p1;
    p1=p2;
    p2=tmp;
}

namespace llk1
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





        //---这是构造函数(有参)
        string(const char* str="\0")//这样缺省参数就是\0了
        :_size(strlen(str))
        ,_capacity(_size)
        {
            _str=(new char[_capacity+1]);//这里就是初始化列表，专门赋值用的地方 _str=地址
            strcpy(_str,str);//是不是\0都得拷贝过去
        }


        //---这是拷贝构造函数---这种写法是深拷贝，保存的值拷贝过来但不保存在同一个空间         -----ps:这种也是传统的写法
//        string(const string& s)
//        {
//            _size=s._size;
//            _capacity=s._capacity;
//            _str=new char[_capacity+1];
//            strcpy(_str,s._str);
//        }

        //---这种拷贝构造的现代写法
        //不但在string类使用，后面的vector，list都能使用   本质上是一种代码的复用
        string(const string& s)
        :_str(nullptr)
        {
            string tmp(s._str);//用s的字符串初始化tmp    ----这个是在堆上开辟的空间，不用担心空间被释放    当然，用这个省劲的方法的时候，得需要先把拷贝构造函数实现了
            swap(tmp._str,_str);
            _size=tmp._size;
            _capacity=tmp._capacity;
        }


        //---赋值成员函数     ----这种是常见写法
//        string& operator=(const string& s1)
//        {
//            if(this->_str!=s1._str)
//            {
//                char* tmp=new char[s1._capacity+1];//这么做是为了避免开辟空间失败
//                delete[] _str;
//                strcpy(tmp,s1._str);
//                _str=tmp;
//            }
//            else
//            {
//                ;
//            }
//            return *this;
//        }





        //operator=的现代写法(其一)
        string& operator=(const string& s)
        {
            if(this!=&s)
            {
                string tmp(s);//在这里请记住，这个tmp是一个局部变量，局部变量在出了这个作用域就会调用析构函数
                swap(tmp._str,_str);//this._str会指向tmp在堆上开辟的空间，然后tmp._str会指向_str原来指向的空间
                _size=tmp._size;
                _capacity=tmp._capacity;
                //出了这个函数tmp会调用析构函数将tmp._str指向的堆的空间进行释放
            }
        }



//        operator=的现代写法（其二)//这种写法仅仅只考虑字符串在堆上的存放，在不涉及增删查改的情况下，不用去管_size,_capacity
        string& operator=(string s)//此处的s并不是引用，而是拷贝的实参的值，所以在函数结束的时候会自动销毁
        {
            swap(s._str,_str);//这里就算是自己给自己饿复制也不会产生影响
            _str=s._str;
            _capacity=s._capacity;
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


        //---[]的重载         -----返回值可改写的版本
        char& operator[](size_t pos)
        {
            assert(pos<this->_size);
            return _str[pos];
        }



        //---[]的重载        -----返回值不可改写的版本
        const char& operator[](size_t pos)const
        {
            assert(pos<this->_size);
            return _str[pos];
        }


        //---这个是用来申请空间的
        void reserve(int n)//原string类，如果给的n是小于capacity的是不会进行处理的
        {
            if(n>_capacity)
            {
                char* tmp=new char[n+1];
                strcpy(tmp,_str);
                delete[] _str;
                _str=tmp;
                _capacity=n;
            }
        }



        //---push_back的模拟                -----尾插单个字符，或者尾插一个字符串
        void push_back(char ch)
        {
            if(_size==_capacity && _size!=0)
            {
                reserve(_capacity*2);
            }
            else
            {
                reserve(1);
            }
            _str[_size]=ch;
            ++_size;
            _str[_size]='\0';
        }






        //---append()函数的模拟           -----字符串后面添加字符串的函数
        void append(const char* str)
        {
            int len=strlen(str);
            if(_capacity<len+_size)
            {
                reserve(_size+len);
            }
//            for(int i=_size;*str!='\0';++i)//可以使用for循环进赋值
//            {
//                _str[_size]=*str;
//                ++_size;
//                ++str;
//            }

            strcpy(_str+_size,str);//这就相当于从_str的\0处开始复制，一直吧str的\0复制完毕才会结束。
            _size+=len;
        }




        //---operator+=的重载      -----要重载两个这个函数，一个函数的参数是字符    另一个函数的参数是字符串
        string& operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }

        string& operator+=(const char* str)//这两个也是代码的复用
        {
            append(str);
            return *this;
        }

        string& operator+=(const string& s)
        {
            append(s._str);
            return *this;
        }



        //---resize()函数的模拟        ----申请空间并且初始化，这个size必须改变，但是capacity不要求必须改变
        void resize(size_t n,char ch='\0')
        {
            reserve(n);
            if(n<=_size)//这种情况是申请的空间比字符串长度还小或者申请的空间和字符串的长度是相同的
            {
                _str[n]='\0';
                _size=n;//
            }
            else//这种情况是申请的空间比字符串的长度要长
            {
                if(n>_capacity)
                {
                    reserve(n);
                }
                memset(_str+_size,ch,n-_size);//memset的用法就是给出一个指定的位置，复制n个ch从此地址处开始
                _size=n;
                _str[_size]='\0';
            }

        }



        //---find()函数的模拟  查找某个字符      这个函数是查找到就返回字符所在的下标，没有查找到就返回npos
        size_t find(char ch)
        {
            for(size_t i=0;i<_size;i++)
            {
                if(ch==_str[i])
                {
                    return i;
                }
            }
            return npos;
        }


        //find的函数的重载        同样的找到返回的还是下标
        size_t find(const char* s,size_t pos)//第一个参数是要查找的字符串，第二个参数是从_str+pos的位置开始查找
        {
            const char* p=strstr(_str+pos,s);
            if(p==nullptr)
            {
                return npos;
            }
            else
            {
                return p-_str;//因为要返回的是下标
            }
        }



        //字符的任意位置插入       //实在担心问题可以用指针来代替下标问题
//        string& insert(size_t pos,char ch)
//        {
//            assert(pos<=_size);
//            if(_size==_capacity)
//            {
//                reserve(_capacity=0?4:_capacity*2);
//            }
//            int end=_size;//从最后一个位置开始挪动
//            while(end>=(int)pos)//size_t是一个无符号类型的long型变量，不会变成负值
//            {
//                _str[end+1]=_str[end];
//                --end;
//            }
//            _str[pos]=ch;
//            ++_size;
//            return* this;
//            //从申请空间以后的这坨代码还能简介一下   就是让end=_size+1;
//        }


        string& insert(size_t pos,char ch)
        {
            assert(pos<=_size && pos>=0);
            if(_size==_capacity)
            {
                reserve(_capacity>0?4:_capacity*2);
            }
            for(size_t i=_size+1;i>pos;i--)
            {
                _str[i]=_str[i-1];
            }
            _str[pos]=ch;
            ++_size;
            return *this;
        }




        //----字符串的任意位置插入
        string& insert(size_t pos,const char* str)
        {
            assert(pos<=_size);//和_size相等的时候就是尾插了
            int len=strlen(str);
            if(_capacity<len+_size)
            {
                reserve(_size+len);
            }
            size_t end=_size+len;
            while(end>pos+len)
            {
                _str[end]=_str[end-len];
                --end;
            }
            strncpy(_str+pos,str,len);//将str中len个（也就是全部）长度的字符从_str+pos这个位置开始复制
            _size+=len;
            return *this;
        }




        //---erase（）从pos位置删除len个字符    pos默认为下标0     删的少了就往前挪
        string& erase(size_t pos=0,size_t len =npos)
        {
            assert(pos<_size);
            if(len==npos || pos+len>=_size)//这个删除后，并不会改变capacity的容量
                //这个条件是如果要清除的长度非常长，或者清除的内容超出了_size的长度   那就从pos位置置为\0
            {
                _str[pos]='\0';
                _size=pos;
            }
            else
            {
                strcpy(_str+pos,_str+pos+len);//如果只是擦除_size部分的数据，那可以_size内容 pos位置之后的未擦除的部分向前拷贝
                _size-=len;
            }
        }



        ~string()
        {
            if(_str)
            {
                delete[] _str;
                _str=nullptr;
            }
            _size=_capacity=0;
        }
    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    public:
        static const size_t npos=-1;
    };

//    在这里重载成为全局函数     string对象比较大小
    bool operator>(const string& s1,const string& s2)
    {
        if(strcmp(s1.c_str(),s2.c_str())>0)//这种写法仅仅适用于字符串总没有\0
        {
            return true;
        }
    }

    bool operator==(const string& s1,const string& s2)//相等返回真，不相等返回假
    {
        if(strcmp(s1.c_str(),s2.c_str())==0)
        {
            return true;
        }
    }

    //还可以用这两个进行其他符号的复用，有时间慢慢实现   并且这种方法适用于所用类的比较



    //此外还要完成流插入，流输入的重载
    ostream& operator<<(ostream& out,string s1)
    {
        out<<s1.c_str();//如果字符串中间有\0，那就需要根据_size来遍历长字符串了
        return out;
    }

    //流的输入有时间就写   参考之前的运算符重载
}





















