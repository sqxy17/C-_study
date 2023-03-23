#include"22_queue的模拟.h"
using namespace test1;



void test_st()
{
    container_test<int,list<int>>st1;   //vector容器是不支持头删的，因为数组头删，数组后面的元素往前移，代价太大
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);

    while(!st1.empty())
    {
        cout<<st1.front()<<' ';
        st1.pop();
    }

}


//int main(void)
//{
//    test_st();
//}