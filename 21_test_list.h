#pragma once
#include<assert.h>
#include<iostream>
#include"21_reverse_iterator_list.h"
using namespace r_iterator;



namespace llk//首先这个空间创建出来的是单个的结点，用来存储数据的单个的结点
{
    template<class T>
    struct ListNode
    {
    public:
        //是个类都得有默认构造函数
        ListNode(const T& x=T())//结点的初始化需要传参，不传参就是默认的缺省参数,这样写是方便下面的尾插，创建结点的时候直接进行初始化
        :_next(nullptr)
        ,_prev(nullptr)
        ,_data(x)//匿名对象
        {}

        ListNode<T>* _next;//除非有调用这个成员变量的函数接口，否则需要设置公共，因为下面的类还需要去调用进行赋值
        ListNode<T>* _prev;
        T _data;
    };




















    //Data* 定义的指针，++到不了下一个结点
    //迭代器不一定是原生指针
    //迭代器是否为只读类型的，关键在于迭代器重载函数的返回值是否为const类型的，关键在于*
    //Node*原生指针和一个迭代器，他们占用的空间是一样大的，都是4（8）字节，并且存的值都市一样的，但是他们对于运算符使用的意思和结果却是不一样的
    template<class T,class ref,class ptr>      //----ref是控制是否为只读迭代器的          -----除此之外，迭代器保存的数据还可能是自定义类型的  str就是对象的指针，判断是否为
    struct _list_iterator   //这里的迭代器为什么要封装成类，是因为，如果直接用typedef Data* iterator,那么对迭代器进行解引用的时候就会变成结点对象（已经被实例化的类节点），一个结点没有办法到另一个结点中去

    {
    public:
        typedef ListNode<T> Node;
        typedef _list_iterator<T,ref,ptr> self;


       _list_iterator(Node* x)//也就是说迭代器的初始化值是指针,将指针封装成一个迭代器
       :_node(x)
       {}


       ref operator*()//如果想要某个类像基本类型使用这个运算符，那么就只能在类的里面进行重载
       {
           return _node->_data;//这个data还可能是一个对象
       }



       self& operator++()
       {
           _node=_node->_next;
           return *this;//迭代器++，返回的也得是迭代器
       }


        self& operator--()
        {
            _node=_node->_prev;
            return *this;//迭代器++，返回的也得是迭代器
        }


        self operator++(int)
       {
           self tmp(*this);//拷贝构造，将当前的迭代器及济宁拷贝
           _node=_node->_next;
           return tmp;
       }



        self operator--(int)
        {
            self tmp(*this);//拷贝构造，将当前的迭代器及济宁拷贝
            _node=_node->_prev;
            return tmp;
        }



       bool operator!=(const self& it)const//重载后的运算符使用的时候就是在调用函数
       {
           return _node!=it._node;
       }


        bool operator==(const self& it)const
        {
            return _node==it._node;
        }


        ptr operator->()
        {
           return &_node->_data;//这里有编译器的优化,省略的一个
        }

        Node* _node;//既然是迭代器，总得有一个该类型的指针，所以还得在迭代器类 里面定义一个结点类型的指针,Data*类型的指针++，到不了下一个结点，但是对iterator类型的指针++，就可到下一个地址
    };

    //所有类型只要想要重载->，都会优化，省略一个->































    //这个是链表的模板
    template<class T>//这个模板T，就是为了下面的俩迭代器的使用定义出来的
    class list//这个类创建出来的就是列表，列表已经包含了一个头结点             ----list里面也需要有迭代器，迭代器只是用来模拟指针的
    {
        typedef ListNode<T> Node;//不管什么结点，通通都被重命名为Node
    public:
        typedef _list_iterator<T,T&,T*> iterator;
        typedef _list_iterator<T,const T&,const T*> const_iterator;


        typedef reverse_iterator<iterator,const T&,const T*> const_reverse_iterator;
        typedef reverse_iterator<iterator,T&,T*> reverse_iterator;


        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }


        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }




        //ps：为什么不在链表的类模板里面把迭代器定义出来？是因为迭在这个类的里面定义的时候，会默认this指针指向头结点，并不方便将第begin（）传来的地址进行++ --之类的操作

        //无参的构造函数
        list()//必须没有参数，因为这个是带头结点的，头结点不存储
        {
            _head=new Node;
            _head->_next=_head;
            _head->_prev=_head;

            //在创建结点的时候结点已经进行了初始化，data的值就不用再管了
        }




        template<class inputiterator>          //拷贝构造现代化写法的工具人
        list(inputiterator first,inputiterator last)
        {
            _head=new Node();
            _head->_next=_head;
            _head->_prev=_head;
            while(first!=last)
            {
                push_back(*first);
                ++first;
            }
        }






        list(const list<T>& x)//拷贝构造函数     直接就是现代写法，传统写法不搞了 ，这个现代写法和vector的一样,需要有人打工，一般打工的都是构造函数
        {
            _head=new Node();
            _head->_next=_head;
            _head->_prev=_head;
            list<T>tmp(x.begin(), x.end());
            std::swap(_head,tmp._head);
        }





        //=重载
        list<T>& operator=(list<T> x)
        {
            std::swap(_head,x._head);
        }



        ~list()
        {
            delete _head;
            _head=nullptr;
        }


        //链表的插入 (尾插)
        void push_back(const T& x)
        {
            Node* tmp=_head->_prev;
            Node* newnode=new Node(x);//看好，新的结点也是new出来的
            newnode->_next=_head;
            _head->_prev=newnode;
            newnode->_prev=tmp;
            tmp->_next=newnode;
        }




        //第一个结点的地址
        iterator begin()//begin是返回的迭代器类型的指针
        {
            return iterator(_head->_next);//将当前的这个地址构造成迭代器类型，并返回
        }


        const_iterator begin()const//begin是返回的迭代器类型的指针
        {
            return const_iterator(_head->_next);//将当前的这个地址构造成迭代器类型，并返回
        }


        //最后一个结点的地址
        iterator end()//返回的是最后一个
        {
            return iterator(_head);
        }


        const_iterator end()const//返回的是最后一个
        {
            return const_iterator(_head);
        }




        iterator insert(iterator pos,const T& x)//迭代器失效的意思是指，变成类似于野指针了，并不是消失了
        {
            Node* cur=pos._node;
            Node* prev=cur->_prev;
            Node* newnode=new Node(x);

            newnode->_prev=prev;
            prev->_next=newnode;
            newnode->_next=cur;
            cur->_prev=newnode;

            return newnode;
        }




        void erase(iterator pos)//此处的迭代器是一定是失效的
        {
            assert(pos!=end());
            Node* prev=pos._node->_prev;
            Node* next=pos._node->_next;
            delete pos._node;

            prev->_next=next;
            next->_prev=prev;
        }



        void clear()
        {
            iterator it=begin();
            while(it!=end())
            {
                iterator tmp=it++;
                delete tmp._node;
            }
            _head->_prev=_head;
            _head->_next=_head;
        }

        //尾插头插可以服用insert
        //尾删头删可用erase
    private:
        Node* _head;//创建的链表的底层是一个指向结点的指针。还是一个结点，只不过这个结点是头结点，不用来存储数据。
        //创建这个结点的时候，这个结点也会调用他的构造函数，ListNode的构造函数在调用之后，   list的构造函数也会紧跟着调用
    };

}




////链表中拷贝构造和赋值重载中并不需要自己实现，默认的就够用，并且析构函数
////c++默认实现的拷贝构造和赋值就是浅拷贝，是否需要自己实现得看是否为是不是深拷贝
////迭代器是借助结点的指针访问修改链表结点属于链表，不是鱼迭代器，所以他不管释放，默认生成即可






