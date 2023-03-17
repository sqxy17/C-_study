//前言  vector可以看作为一个用数组实现的顺序增长的容器      -----容器就是来存储东西的
//类模板声明  template<class T,class Alloc=allocator<T>>class vector;
//本章节记录的是vector的使用
//vector底层就是一个顺序表（也就是数组）      顺序表的底层就是一个动态开辟的数组  vector<类型>就是告诉编译器要开辟出什么类型的空间
//vector是类的模板   vector<int>是模板的实例化，也就是说把一个类具体的实例化了。  vector<int> v1;这是实例化对象

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




void test_vector8()//比较用动态开辟和vector创建二维数组的区别       这个函数分别用两种方式创建10行5列的二维数组
{
    //首先先看看一维数组是怎么样的
    int* arr=(int*)malloc(sizeof(int)*5);//这个就是创建了一个能存放5个整型的空间，这个懂该开辟的数组使用一维指针表示的       思考一下二维数组怎么办？
    //二维数组无非就是数组里面存放数组         两者结和就是动态开辟的二维数组（带上下面的for循环）
    int** parr=(int**)malloc(sizeof(int*)*10);//用动态开辟的方式去创建
    for(size_t i=0;i<10;++i)//
    {
        parr[i]=(int*)malloc(sizeof(int*)*5);
    }
    //parr[i][j]是两次原生指针的解引用
    //并且parr在不使用的时候，需要手动去销毁，比较麻烦


    //接下来使用vector创建一个动态开辟的数组
    vector<vector<int>> vv;//相对于上面的复杂形式，用vector创建就简单的多了     具体的申请空间在下面
    //vv[i][j]是两次函数的调用  ps：[]是被重载过得符号
    //但是vv不用去手动销毁，因为会自动调用两次析构函数
}




//vector的初始化
vector<vector<int>>  test_vector9()//用的是杨辉三角举例子
{
    vector<vector<int>> vv;
    vv.resize(5);//因为这是个二维数组，所以resize5，开辟了5个用来存放一维数组的空间          官方一点就是存放了五个vector<int>
    //接下来对这五个vector<int>在进行申请空间
    for(size_t i=0;i<5;i++)
    {
        vv[i].resize(i+1);//可以理解为对一位数组进行开辟空间,后面的参数是为一维数组开辟的空间的大小(元素个数)
//        vv[i].front()=vv[i].back()=1;//这两个函数一个是头替换，一个是尾替换，两个函数返回的都是头（尾）位置的引用
        vv[i][0]=vv[i][vv[i].size()-1]=1;//要注意区分vv.size   vv[i].size
    }

    for(size_t i=0;i<vv.size();++i)
    {
        for(size_t j=0;j<vv[i].size();++j)
        {
            if(vv[i][j]==0)
            {
                vv[i][j]=vv[i-1][j]+vv[i-1][j-1];
            }
        }
    }
    return  vv;
}
//另外vector只是一个容器，他可以存放任何类型的，也就是说他能存放自定义类型的数据  那就可以这样定义 vector(string)//完全可以
//17节  1：30：00 oj题      涉及到回溯算法




//int main(void)
//{
////  test_vector1();
////  test_vector3();
////  test_vector4();
////  test_vector5();
////  test_vector6();
////    test_vector7();
//    test_vector8();
/////   test_vector2();
//
//    return 0;
//}

//string模板和vector的区别
//vector不支持字符串的一些比较 + - += > <之类运算符
//这个vector不适合查找，因为时间复杂度为O(N)，所以想要查找使用库函数中的<algorithm> 的find
//为什么就string提供find呢？因为字符串查找可能是要查找子串（也就是可能查找多个值），而其他的容器都是查找某一个值，相似性比较高
//reserve增容的过程基本还是1.5倍的增容

//有兴趣看源码，先看框架，如果需要实现某些细节再看源码