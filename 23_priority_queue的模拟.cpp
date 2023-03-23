#include "23_priority_queue的模拟.h"

using namespace llk;


void test1()//这个测试是在没有加入仿函数之前的优先级是大的数字
{
    llk::priority_queue<int,vector<int>,test_greater<int>>pq1;
    pq1.push(1);
    pq1.push(2);
    pq1.push(3);
    pq1.push(4);
    pq1.push(5);

    int arr[10]={1,3,5,7,9,2,4,6,8,10};
    llk::priority_queue<int,vector<int>,test_less<int>>pq2(arr,arr+10);//用迭代器区间进行初始化

//    while(!pq1.empty())
//    {
//        cout<<pq1.top()<<' ';
//        pq1.pop();
//    }

    while(!pq2.empty())
    {
        cout<<pq2.top()<<' ';
        pq2.pop();
    }
}





void test2()//这个测试是在没有加入仿函数之前的优先级是大的数字
{

//    cout<<l1.operator()(1,2)<<endl;
//    cout<<l1(3,4)<<endl;//也就是说这个括号在编译阶段被转换成上面的那种形式
}

int main(void)
{
    test1();
//    test2();
}