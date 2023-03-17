#include<iostream>
#include<list>

//template<class T,class Alloc=allocator<T>> class list;     //空间配置器，还是从内存池来的空间
//list的迭代器是双向的，插入的时间复杂度是O(1)

//首先回忆一下链表  双向带头循环链表
//链表是没有容量的，没有resive()
using std::cout;
using std::cin;
using std::endl;
using std::list;



//测试无参构造，   插入操作（list因为是链表，插入的时间复杂度是O(1)）,此处测试的是尾插          使用迭代器进行正反遍历
void test1()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);

    //因为链表存储数据的都是单个的不连续的结点，所以不支持随机访问（也就是下标访问）,因此在遍历的时候就只能用迭代器或者范围for进行遍历
    list<int>::iterator it=l1.begin();
    while(it!=l1.end())
    {
        cout<<*it<<' ';
        it++;//这个++是重载后的++，并不是简单的地址进行+1，因为是链表，所以地址是不连续的
    }
    cout<<endl;
    for(auto& e:l1)
    {
        cout<<e<<' ';
    }
    cout<<endl;


    //双向链表就有双向的迭代器           请注意反向迭代器的名字
    list<int>::reverse_iterator rit=l1.rbegin();
    while(rit!=l1.rend())
    {
        cout<<*rit<<' ';
        ++rit;
    }
}




//排序  逆置  去重（去重之前必须先排序，否则去重去不干净）     unique（）去重函数
void test2()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(7);
    l1.push_back(4);
    l1.push_back(2);
    l1.push_back(0);
    l1.push_back(9);
    l1.push_back(2);
    l1.push_back(7);

    l1.sort();//数据多了就别用list容器进行存储了，尽量用vector
    list<int>::iterator it=l1.begin();
    while(it!=l1.end())
    {
        cout<<*it<<' ';
        ++it;
    }
    cout<<endl;

    l1.reverse();
    list<int>::iterator it1=l1.begin();
    while(it1!=l1.end())
    {
        cout<<*it1<<' ';
        ++it1;
    }
    cout<<endl;
    l1.unique();
    list<int>::iterator it2=l1.begin();
    while(it2!=l1.end())
    {
        cout<<*it2<<' ';
        ++it2;
    }
    cout<<endl;



}


//int main()
//{
////    test1();
//    test2();
//}

//补充：list虽然也有sort，但是list的效率很低      链表的排序底层是归并排序的一种
//std::sort(),也就是全局函数的sort不支持list对象的排序，全局函数的sort要传入的迭代器区间是随机迭代器        也就是说list只能使用自己的sort排序方法
//remove()  接口函数，（删除函数）自己指定元素找自己删
//splice() 接口函数    （结和函数） 将一个链表转移到另一个链表中，可指定位置相结合，也就是说  a链表：1，2，3，4    b链表：10，20，30，40       》》》1，10，20，30，40，2，3，4