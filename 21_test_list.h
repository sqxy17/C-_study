//#pragma once
//#include<assert.h>
//
//
//namespace llk//首先这个空间创建出来的是单个的结点，用来存储数据的单个的结点
//{
//    template<class T>
//    struct ListNode
//    {
//    public:
//        //是个类都得有默认构造函数
//        ListNode(const T& x=T())//结点的初始化需要传参，不传参就是默认的缺省参数,这样写是方便下面的尾插，创建结点的时候直接进行初始化
//        :_next(nullptr)
//        ,_prev(nullptr)
//        ,_data(x)//匿名对象
//        {}
//
//        ListNode<T>* _next;//除非有调用这个成员变量的函数接口，否则需要设置公共，因为下面的类还需要去调用进行赋值
//        ListNode<T>* _prev;
//        T _data;
//    };
//
//
//
//
//
//    template<class T,class ref>      //----ref是控制是否为只读迭代器的
//    class _list_iterator//这次的迭代器不在类的里面是因为，要定义的指针是一个结点类型的指针，而不是直接数组元素的单个的地址，
//            //迭代器不一定是原生指针
////这个函数的迭代器是自定义类型的，为什么在这里要这样定义，因为这个迭代器是要指向结点的地址，如果直接定义typedef Node* iterator; 那么定义的iterator it，就没办法进行解引用直接进行输出
////才外除了可修改元素的的迭代器，还是实现一种只读的迭代器类
//
//
////Node*原生指针和一个迭代器，他们占用的可哦关键是一样大的，都是4（8）字节，并且存的值都市一样的，但是他们对于运算符使用的意思和结果却是不一样的
//    {
//    public:
//        typedef ListNode<T> Node;
//        typedef _list_iterator<T,ref> self;
//
//       _list_iterator(Node* x)//构造函数
//       :_node(x)
//       {}
//
//
//       ref operator*()
//       {
//           return _node->_data;
//       }
//
//
//
//       self& operator++()
//       {
//           _node=_node->_next;
//           return *this;//迭代器++，返回的也得是迭代器
//       }
//
//
//       self& operator++(int)
//       {
//           _list_iterator<T,ref> tmp(*this);//拷贝构造，将当前的迭代器及济宁拷贝
//           _node=_node->_next;
//           return tmp;
//       }
//
//
//
//       bool operator!=(const self& it)//重载后的运算符使用的时候就是在调用函数
//       {
//           return _node!=it._node;
//       }
//    private:
//        Node* _node;//既然是迭代器，总得有一个该类型的指针，所以还得在迭代器类 里面定义一个结点类型的指针
//    };
//
//
//
//
//
//
//
//    //这个是链表的模板
//    template<class T>
//    class list//这个类创建出来的就是列表，列表已经包含了一个头结点
//    {
//    public:
//
//        typedef ListNode<T> Node;//不管什么结点，通通都被重命名为Node
//        typedef _list_iterator<T,T&> iterator;
//        typedef _list_iterator<T,const T&> const_iterator;
//        //ps：为什么不在链表的类模板里面把迭代器定义出来？是因为迭在这个类的里面定义的时候，会默认this指针指向头结点，并不方便将第begin（）传来的地址进行++ --之类的操作
//
//        //无参的构造函数
//        list()//必须没有参数，因为这个是带头结点的，头结点不存储
//        {
//            _head=new Node;
//            _head->_next=_head;
//            _head->_prev=_head;
//
//            //在创建结点的时候结点已经进行了初始化，data的值就不用再管了
//        }
//
//
//        //链表的插入 (尾插)
//        void push_back(const T& x)
//        {
//            Node* tmp=_head->_prev;
//            Node* newnode=new Node(x);
//            newnode->_next=_head;
//            _head->_prev=newnode;
//            newnode->_prev=tmp;
//            tmp->_next=newnode;
//        }
//
//
//
//
//        //第一个结点的地址
//        _list_iterator<T,T&> begin()
//        {
//            return iterator(_head->_next);//将当前的这个地址构造成迭代器类型，并返回
//        }
//
//
//        //最后一个结点的地址
//        _list_iterator<T,T&> end()
//        {
//            return iterator(_head);
//        }
//    private:
//        Node* _head;//创建的链表的底层是一个指向结点的指针。还是一个结点，只不过这个结点是头结点，不用来存储数据。
//        //创建这个结点的时候，这个结点也会调用他的构造函数，ListNode的构造函数在调用之后，   list的构造函数也会紧跟着调用
//    };
//}
//
//
//
//
////链表中拷贝构造和赋值重载中并不需要自己实现，默认的就够用，并且析构函数
////c++默认实现的拷贝构造和赋值就是浅拷贝，是否需要自己实现得看是否为是不是深拷贝
////迭代器是借助结点的指针访问修改链表结点属于链表，不是鱼迭代器，所以他不管释放，默认生成即可

















//这里开始时杭哥写的
#pragma once

namespace bit
{
    template<class T>
    struct ListNode
    {
        ListNode<T>* _next;
        ListNode<T>* _prev;
        T _data;

        ListNode(const T& data = T())
                :_next(nullptr)
                , _prev(nullptr)
                , _data(data)
        {}
    };

    template<class T, class Ref, class Ptr>
    struct __list_iterator
    {
        typedef ListNode<T> Node;
        typedef __list_iterator<T, Ref, Ptr> self;
        //typedef __list_iterator
        Node* _node;

        __list_iterator(Node* x)
                :_node(x)
        {}

        // it2 = it1 浅拷贝
        // 拷贝构造和赋值重载是否需要我们自己实现
        // 析构呢？-> 迭代器是借助节点的指针访问修改链表
        // 节点属于链表，不属于迭代器，所以他不管释放
        // 都不需要自己实现，默认生成的即可
        Ref operator*()
        {
            return _node->_data;
        }

        Ptr operator->()
        {
            return &_node->_data;
        }

        // ++it
        self& operator++()
        {
            _node = _node->_next;
            return *this;
        }

        // it++
        self operator++(int)
        {
            __list_iterator<T> tmp(*this);
            _node = _node->_next;
            return tmp;
        }

        // --it
        self& operator--()
        {
            _node = _node->_prev;
            return *this;
        }

        // it--
        self operator--(int)
        {
            __list_iterator<T> tmp(*this);
            _node = _node->_prev;
            return tmp;
        }

        bool operator!=(const self& it) const
        {
            return _node != it._node;
        }

        bool operator==(const self& it) const
        {
            return _node != it._node;
        }
    };

    //template<class T>
    //struct __const_list_iterator
    //{
    //	typedef ListNode<T> Node;
    //	//typedef __list_iterator
    //	Node* _node;

    //	__const_list_iterator(Node* x)
    //		:_node(x)
    //	{}

    //	// it2 = it1 浅拷贝
    //	// 拷贝构造和赋值重载是否需要我们自己实现
    //	// 析构呢？-> 迭代器是借助节点的指针访问修改链表
    //	// 节点属于链表，不属于迭代器，所以他不管释放
    //	// 都不需要自己实现，默认生成的即可
    //	const T& operator*()
    //	{
    //		return _node->_data;
    //	}

    //	// ++it
    //	__const_list_iterator<T>& operator++()
    //	{
    //		_node = _node->_next;
    //		return *this;
    //	}

    //	// it++
    //	__const_list_iterator<T> operator++(int)
    //	{
    //		__const_list_iterator<T> tmp(*this);
    //		_node = _node->_next;
    //		return tmp;
    //	}

    //	// --it
    //	__const_list_iterator<T>& operator--()
    //	{
    //		_node = _node->_prev;
    //		return *this;
    //	}

    //	// it--
    //	__const_list_iterator<T> operator--(int)
    //	{
    //		__list_iterator<T> tmp(*this);
    //		_node = _node->_prev;
    //		return tmp;
    //	}

    //	bool operator!=(const __const_list_iterator<T>& it) const
    //	{
    //		return _node != it._node;
    //	}

    //	bool operator==(const __const_list_iterator<T>& it) const
    //	{
    //		return _node != it._node;
    //	}
    //};

    template<class T>
    class list
    {
        typedef ListNode<T> Node;
    public:
        typedef __list_iterator<T, T&, T*> iterator;
        typedef __list_iterator<T, const T&, const T*> const_iterator;


        /*void f()
        {
            Node* pnode = _head->_next;
            iterator it = _head->_next;

            *pnode;
            *it;

            ++pnode;
            ++it;
        }*/

        iterator begin()
        {
            return iterator(_head->_next);
        }

        iterator end()
        {
            return iterator(_head);
        }

        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }

        const_iterator end() const
        {
            return const_iterator(_head);
        }

        list()
        {
            _head = new Node();
            _head->_next = _head;
            _head->_prev = _head;
        }

        void push_back(const T& x)
        {
            Node* tail = _head->_prev;
            Node* newnode = new Node(x);
            tail->_next = newnode;
            newnode->_prev = tail;
            newnode->_next = _head;
            _head->_prev = newnode;
        }

        void insert(iterator pos, const T& x);
        void erase(iterator pos);
    private:
        Node* _head;
    };

    void print_list(const list<int>& lt)
    {
        list<int>::const_iterator it = lt.begin();
        while (it != lt.end())
        {
            //*it = 10;
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }

    void test_list1()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);

        //lt.f();

        // 访问修改容器
        list<int>::iterator it = lt.begin();
        while (it != lt.end())
        {
            *it *= 2; // 修改
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        print_list(lt);
    }

    struct Date
    {
        int _year;
        int _month;
        int _day;

        Date(int year = 1, int month = 1, int day = 1)
                :_year(year)
                , _month(month)
                , _day(day)
        {}
    };

    void test_list2()
    {
        list<Date> lt;
        lt.push_back(Date(2022, 3, 12));
        lt.push_back(Date(2022, 3, 13));
        lt.push_back(Date(2022, 3, 14));

        list<Date>::iterator it = lt.begin();
        while (it != lt.end())
        {
            //cout << (*it)._year << "/" << (*it)._month << "/" << (*it)._day << endl;
            cout << it->_year << "/" << it->_month << "/" << it->_day << endl;

            ++it;
        }
        cout << endl;
    }
}