//前言:这个章节只是大概听了一下,到时间可以看看新版的,所以此处就不详细记笔记了
#include<iostream>
using namespace  std;

//一.
//库里面的cout本质上是一个类
//cout<<1;  实际上是调用了cout这个类的重载<<函数 cout.operator<<(i)

//内置类型我们可以直接使用cout<<  cin>>  是因为库里面已经实现过了,所以碰见自定义类型需要自己再去重新定义





//二.输入字符串的常见问题
//1、普通字符数组或者指针可以用getline(char *buf, int size)函数读取整行函数，它通过换行符来确定输入的结尾，然后丢弃换行符。
//假设有char str[100];

//调用方法：cin.getline(buf,100 )。这个函数有两个参数，第一个用来存储数组名字，第二个是用来读取的字符数字。注意如果第二个参数为50，则最多输入49个字符，要留一个给末尾‘\0’



//2、string类输入
//要使用string类首先得包含头文件string，string类在实现字符数组的功能的同时使得字符串的操作更加简单、方便、安全。
//假设有string str;那输入可调用
//
//getline( cin , str ) //将一行输入到string对象中





//三.
//cout,cin真正的优势是,自己重载以后,自定义类型对象也可以简单的使用

//在使用scanf读取数据的时候,如果没有任何护具可以读取了这个scanf函数会返回EOF

//c语言的结束
int main(void)
{
//    int arr[2000];
//    while(scanf("%s",arr)!=EOF)//在win平台下俺这ctrl+z就能停止,也就是一个结束的信号
//    {
//        printf("hehe");
//    }

    string arr;
    while(cin>>arr)//但是这个并不会返回EOF,这个是函数调用,返回值还是cin,是istream的对象.也就说说对象怎么进行做while的判断
        //实际上也就是对bool进行了重载
    {
        ;
    }
}

//26节00:00:00未看