#include<iostream>
using namespace std;
//一、auto关键字      (c++11标准新增)
//1.这个auto能自动推导变量的类型并赋值

//int main(void)
//{
//    int a=3;
//    auto b=a;
//    auto c=3.14;//自己只管使用就行，他会自动推导是什么类型
//    cout<<sizeof(c)<<endl<<sizeof(b)<<endl;

//    const int v=4;
//    auto k=v;//虽然会自动推导，但是不会将常属性推导到k上
//}
//auto在这里的使用价值不是很大，实际的使用场景在迭代器、包括下面的for范围
//另外的使用价值就是类型名字过长，省点劲。因为它会根据右边的值自动推导类型，写起来更加方便


//2.推导处理灵活
//int main(void)
//{
//    int x=10;
//    auto a=&x;
//    auto* b=&x;//a和b都是int*类型的，因为存放的就是一个整形的地址，存放的不是一个指针的地址
//    auto& c=x;//能一眼看出来，很清楚
//
//    const double d=3.14;
//    const auto dd=d;//这样才是正常的使用，const属性
//    cout<<typeid(d).name();
//}


//3.注意事项
//使用auto必须在使用的时候初始化
//不能用来定义数组  int arr1[];auto arr2[]//后面的这样定义数组时错误的用法
//不能用作函数的参数,例子：void test(auto a);   这样是错误的







//二、输出变量类型的函数       ----typeid().name()
//int main(void)
//{
//    int a=4;
//    auto aa=a;
//    double b=3.14;
//    char c='v';
//    cout<<typeid(aa).name()<<endl<<typeid(b).name()<<endl<<typeid(c).name()<<endl;
//}






//三、范围for     （语法糖）用起来很甜哈哈哈
//1.遍历循环
//int main(void)
//{
//    int arr[]={1,2,3,4,5,6,7,8};
//    for(auto e:arr)//语法意思，自动依次取数组arr里面的每个元素，并且赋值给e（e可自定义任何名字）然后输出。注意中间是：号
//    {
//        cout<<e<<endl;
//    }
//
//    for(int llk:arr)//可明确的指定类型，前提是你知道数组的类型        llk是一个中间变量，拷贝值，操作llk并不会对数组造成影响
//    {
//        cout<<llk<<endl;
//    }
//}


//2.循环对元素操作怎么办
//int main(void)
//{
//    int arr[]={1,2,3,4,5,6,7,8};
//    for(int& llk:arr)//可理解别名的生命周期是一次性的，这样就可以操作元素了
//    {
//        llk++;
//    }
//
//    for(int llk:arr)
//    {
//        cout<<llk<<' ';
//    }
//}


//3.范围for后面跟的必须是数组名，自定义函数不能使用

//void test(int arr[4])
//{
//    for(auto llk:arr)//这样就会直接报错
//    {
//
//    }
//}
//
//int main(void)
//{
//    int arr[]={1,2,3,45};
//    test(arr);
//}







//四、空指针 nullptr
//1.c++里面推荐空指针使用 nullptr
//int main(void)
//{
//    int* a=nullptr;
//}
//nullptr不需要包括头文件，能直接使用
//sizeof(nullptr)   和sizeof((void*)0)都是  8个字节（64位）