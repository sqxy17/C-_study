//前言  vector可以看作为一个用数组实现的顺序增长的容器      -----容器就是来存储东西的
//类模板声明  template<class T,class Alloc=allocator<T>>class vector;
//本章节记录的是vector的使用
//vector底层就是一个顺序表      顺序表的底层就是一个动态开辟的数组  vector<类型>就是告诉编译器要开辟出什么类型的空间

#include<iostream>
#include <vector>
using namespace std;
#include<algorithm>//这个库函数里面包括的一些算法，因为这个数组的原因，
//在c++找那个，凡是使用迭代器区间，都是左闭右开

//vector同样还是用size和capacity

void test_vector1()//简单的定义
{
    vector<int> v1;//vector还是一个模板                  上一个string类是 typedef basic_string<char> string         也是模板实例化出来的，现在的这个也是模板
    //只是没有进行实例化
    vector<int> v2(10,9);//初始化只能传入两个数字       意思为v2存了10个9

    //还可以用迭代器
    vector<int> v3(++v2.begin(),--v2.end());//可用s2的迭代器区间进行初始化       存了11个8
    vector<int> v4(v3);
    //对于字符串同样能够使用
    string s1("hello world");
    string s2(s1.begin(),s1.end());
    vector<char> v5(s1.begin(),s1.end());//size为11（全部字符的个数）   capacity为11（容量的大小）
}


void test_vector2()//这个函数主要介绍vector保存的元素的遍历
{
    //vector因为是顺序表，支持+-<>之类的操作，并且只支持单个字符的插入删除
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    //接下来开始遍历     -----因为是连续的空间，所以支持[]
    //[]
//    for(size_t i=0;i<v1.size();++i)
//    {
//        v1[i]+=1;//不但支持遍历，还支持修改
//        cout<<v1[i]<<' ';
//    }printf("\n");

//    //同样支持迭代器                 -----知道正向迭代器也要知道反向迭代器
//    vector<int>::iterator it=v1.begin();      //原生指针就是天然的迭代器
//    while(it!=v1.end())
//    {
//        cout<<*it<<' ';
//        ++it;
//    }printf("\n");
//
//    //同样支持范围for
    for(auto e: v1)
    {
        cout<<e<<' ';
    }
}



//vector的申请容量
void test_vector3()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    //输出所能保存的最大长度
//    cout<<v1.max_size()<<endl;

    v1.reserve(100);//类似string
    v1.resize(100);//类似string，不给第二个参数默认初始化为0，扩容不影响之前保存的变量    但是扩容的容量小于size还是不会影响capacity
    v1.resize(2);

    v1[3];//容量为2的情况下，会断言检测是否访问越界
    v1.at(3);//这两个是一样的

}



//vector的覆盖原有数据
void test_vector4()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    v1.assign(10,5);//意思为将v1从头开始保存10个5
}



//使用<algroithm>中的find查找一个值
void test_vector5()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    vector<int>::iterator ret=find(v1.begin(),v1.end(),99);    //end()返回的还是最后一个元素的下一个位置       最后一个元素查找的要查找的值
    //这个find用的是库函数的，找得到就返回迭代器值的位置（地址，解引用就是3），找不到就返回 end位置  （位置就是地址）
    printf("%d",*ret);
}



//vector 的插入
void test_vector6()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    vector<int>::iterator ret=find(v1.begin(),v1.end(),2); //vector的查找和string有一些不一样，因为string的查找返回的是下标，这个查找返回的是地址
    //所以这个插入用的是地址
    v1.insert(ret,10086);
    v1.insert(v1.begin(),111);//这样算头插
}




//删除一个值+迭代器失效+清除所有元素          删除值用的同样不是下标，用的还是地址
void test_vector7() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    vector<int>::iterator ret=find(v1.begin(),v1.end(),2);
    if(ret!=v1.end())
    {
        v1.insert(ret,10086);
//        v1.erase(ret);//不能在这删，因为已经失效了             但是没有插入就可以直接删除
        //使用的同样是地址，并且这个地址必须是元素的地址，如果不是元素的地址就会报错,所以最好在查找之后进行判断一下
        //如果要操作的地址所保存的值发生了改变，那么就无法对其进行操作了，也就是迭代器失效了
    }

    v1.clear();//这个函数会将vector所保存的全部元素进行清空，但是却不会改变容量的大小          string也有clear()
}


int main(void)
{
//    test_vector1();
//    test_vector3();
//    test_vector4();
//    test_vector5();
//    test_vector6();
    test_vector7();
//    test_vector2();

    return 0;
}

//string模板和vector的区别
//vector不支持字符串的一些比较 + - += > <之类运算符
//这个vector不适合查找，因为时间复杂度为O(N)，所以想要查找使用库函数中的<algorithm> 的find
//为什么就string提供find呢？因为字符串查找可能是要查找子串（也就是可能查找多个值），而其他的容器都是查找某一个值，相似性比较高
//reserve增容的过程基本还是1.5倍的增容