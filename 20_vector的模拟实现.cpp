#include"20_test_vector.h"

using std::cout;
using std::cin;
using std::endl;
using namespace llk;
using std::string;
#include<string>



using std::sort;//此外补充一个全局函数的排序       这个排序是传入迭代器区间的
//在vector.h中有具体规定，参数要求    这个sort函数接受的就是随机类型的迭代器
//void sort (RandomAccessIterator first, RandomAccessIterator last);     尽量传对应的类型,否则可能会出错


using std::reverse;//再补充一个全局函数，逆置函数，这个要求的迭代器是双向迭代器
//void reverse (BidirectionalIterator first, BidirectionalIterator last);


using std::find;//补充一个全局函数,这个函数查找指定的值,返回的是这个值的地址
//InputIterator find (InputIterator first, InputIterator last, const T& val);
//可以看出来这个函数参数的类型是迭代器类型,并且是只写类型



void test1(vector<int>&t1)
{
    llk::vector<int>::iterator it=t1.begin();
    while(it!=t1.end())
    {
        cout<<*it<<' ';
        ++it;
    }

}


void test2(vector<int>&t1)
{
    t1.resize(0);
}



void test3(vector<int>&t1)
{
    llk::vector<int>::iterator it=t1.begin();
    while(it!=t1.end())
    {
        cout<<*it<<' ';
        ++it;
    }
}




void test4(vector<int>&v1)
{
    std::sort(v1.begin(),v1.end());
    test1(v1);
    cout<<endl;
    std::reverse(v1.begin(),v1.end());
    test1(v1);
    cout<<endl;
}



void test_erase(vector<int>&v)//erase也会存在迭代器失效的问题,最根本的原因就是因为在删除了一个元素之后，其他的位置都发生了改变，
{
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator it=v.begin();
    while(it!=v.end())
    {
        int flag=1;//所以要判断有没有删除，有删除这个步骤，it就已经相当于++过了，像这样使用就没事，但是由于是用户调用，只能改变erase的内部实现
        if((*it)%2==0)
        {
            v.erase(it);
            flag=0;
        }
        if(flag)
        {
            ++it;
        }
    }
    test1(v);
}



void test_string()
{
    vector<string>v;
    v.push_back("111111111111");
    v.push_back("1111111111111");
    v.push_back("1111111111111");
    v.push_back("1111111111111");
    v.push_back("1111111111111");
    v.push_back("1111111111111");
    v.push_back("1111111111111");


    for(auto& e:v)
    {
        cout<<e<<' ';
    }//程序会崩溃的主要原因在于扩容的时候用了memcpy
}

//
//int main()
//{
//    test_string();
//    return 0;
//}

//总结：只要是使用迭代器访问的容器都可能会涉及迭代器失效      一般是发生在insert和erase中
//string失效的场景和vector非常类似，但是string很少涉及迭代器失效，因为它一般使用的是下标