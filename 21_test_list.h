#pragma once


namespace llk//首先这个空间创建出来的是单个的结点，用来存储数据的单个的结点
{
    template<class T>
    struct ListNode
    {
        ListNode<T>* _next;
        ListNode<T>* _prev;
        T _data;
    };

    template<class T>
    class list//这个类创建出来的就是列表，列表已经包含了一个头结点
    {
    public:
        typedef ListNode<T> Node;//不管什么结点，通通都被重命名为Node

        //无参的构造函数
        list()
        {
            _head=new Node;
            _head->_next=_head;
            _head->_prev=_head;
        }


        //链表的插入 (尾插)
        void push_back(T& x)
        {
            Node* tmp=_head->_prev;
            Node* newnode=new Node;
            newnode->_next=_head;
            _head->prev=newnode;
            newnode->_prev=tmp;
            tmp->_next=newnode;
        }


    private:
        Node* _head;//创建的链表的底层是一个指向结点的指针。还是一个结点，只不过这个结点是头结点，不用来存储数据。
    };
}
