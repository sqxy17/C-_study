#include<iostream>
using namespace std;



//一、迭代器          iterator:迭代器


//迭代器都是在类里面定义的       （理解成在类里面定义的新类型，it就是由这个新类型定义出来的，并且迭代器这个类型和指针有点类似）
void test_string1(string& st)//遍历的方式一，使用重载的[]，操作下标
{
    for(int i=0;i<st.size();i++)
    {
        st[i]+=1;
    }

    for(int i=0;i<st.size();i++)
    {
        cout<<st[i]<<' ';//（此外还能用s1.at(i)）
    }
}



//遍历的方式二，迭代器            这个阶段先将迭代器暂时理解成类似于指针的诶行
void test_string2(string& st)
//这东西类似于指针。但并不是指针
{//可以看作it是先指向h的一个指针
    string::iterator it=st.begin();//st.begin()会返回字符串中第一个字符的位置     it类似于指针的作用用于接收指针
    while(it!=st.end())//st.end()会返回最后一个有效元素的下一个位置  ----也就是\0的位置
    {
        *it+=1;//还可像指针一样操作
        cout<<*it<<' ';//使用的方式也像指针一样
        ++it;
    }
    cout<<endl;
    it=st.begin();
    while(it!=st.end())
    {
        *it-=1;
        cout<<*it<<' ';
        ++it;
    }
}




//遍历字符串的方式三，范围for（语法糖）            -----本质上范围for就会替换成迭代器
void test_string3(string& st)
{
    for(auto& i:st)//引用使用后每次都会销毁
    {
        i+=1;
        cout<<i<<' ';
    }
    cout<<endl;
    for(auto& i:st)//引用使用后每次都会销毁     并且引用引用的是那一块空间的名字          注意中间的是：
    {
        i-=1;
        cout<<i<<' ';
    }
}

int main(void)
{
    string s1("hello world");//string本身就是有basic_string这个模板实例化出来的
//    test_string1(s1);
//    test_string2(s1);
    test_string3(s1);
}