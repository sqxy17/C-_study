#include<iostream>
using namespace std;
//这个string类就是针对字符串搞出来的

//前言：
//template<class T>//T可能是char  也可能是wchar_t（表示汉字的）等
//class basic_string
//{
////    ......
//
//private:
//    T* _str;//上面的实现都不一定一样，但是一定有一个这个
//};

//typedef basic_string<char> string;//字符串英文是一个字节，但是比如汉字就是两个字节     其他语言可能更多
//typedef basic_string<wchar_t> wstring;
//所以案子可能那个是wchar
// 为什么要对basic_string<char>重定义，是因为编码的原因
//编码： 值（也就是数字） 和   符号（文字、字母、标点等）建立映射关系   ---编码表
//ascll编码表  --表示英文
//
//int main(void)
//{
//    char arr[]="hello";
//    char arr1[]="吃饭";
//    //在内存中存放的是对应的单个字符的ascll值
//}



//现在有一个问题，那世界的其他语言怎么保存？
//出来的与之对应的   unicode编码表    ----表示全世界文字编码表
//此外还有 utf-8   utf-16     utf-32等      常用的是utf-8，     一个汉字是俩字节
//gbk   ---中文自己量身定义的编码表






//一、string类的构造函数要掌握的重点               ----这个string主要是定义字符串的
//1.string类对象的构造函数

//1.string();       -----default   无参构造（默认构造）                  必须掌握
//2.string(const string& str);           -----copy  拷贝构造            必须掌握
//3.string(const char* s);        -----from c-string 有参构造              必须掌握
//4.string(size_t n,char c);     ----fill    ---string类对象包含n个字符c
//5.string(const string& str,size_t pos,size_t len=npos);     ----使用一部分字符进行初始化  pos位置     len长度    从这个字符串


//#include<string>//有的编译器string这个库是包含在iostream中的，但是尽量还是将这个库包上
////这个库里面还会对<<  >>进行重载，能够直接输出或者输入字符串
//int main(void)
//{//如果没有上面的std展开，就需要 std::string s1
//    string s1;//默认构造
//    string s2("hello world");//带参构造
//    string s3(s2);//拷贝构造
//    string s4(s2,1,3);//从s2字符串第arr[1]的位置开始复制，长度为3    s4就被初始化为ell     长度超过s2的总长度的时候取完s2就停止
//
//    cout<<s4<<endl;
//    cout<<s2<<endl;
//    cout<<s3<<endl;
//}





//2.string类对象的部分成员函数

//1.计算字符串长度s1.size()    s1.length()
//2.计算字符串最大能保存的字符个数的     s1.max_size();
//3.查看当前对象最大容量    s1.capacity();
//4.对当前对象进行判空    s1.empty();
//5.对当前的对象所开辟的空间进行清空          -----不是很重要
//#include<string>
//int main(void)
//{
//    string s1;
//    cin>>s1;
//    cout<<s1.size()<<endl;
//    cout<<s1.length()<<endl;//这两个都是计算字符串的长度的，效果都是一样的。请注意，计算的是长度，也就是不包括\0    例如： abc\0 这个长度是3
//    //推荐使用s1.size()比较好，更符合语义，但是这两个性质作用都是相同的
//
//    cout<<s1.max_size()<<endl;//字符串能够保存的最大字符个数，这个是固定的一个值，很大就对了
//
//    cout<<s1.capacity()<<endl;//计算当前对象的最大容量
//
//    s1.clear();
//    cout<<s1<<endl;//将当前对象保存的字符全部清空
//    cout<<s1.capacity()<<endl;//当前对象所保存的字符虽然都清空了，但是当前所能保存的最大容量没有改变
//
//    cout<<s1.empty()<<endl;//对当前对象的判空操作,空就返回1，不空就返回0
//
//    s1.shrink_to_fit();//将当前对象所开辟的空间进行销毁
//}





//3.operator[]   和  at       ----对这个[]进行重载，也就是能够把这个字符串当做字符串一样去使用    这个也是string类对象的成员函数
//#include<string>
//int main(void)
//{
//    string s1("hellobit");
//    for(int i=0;i<s1.size();i++)
//    {
//        cout<<s1.at(i)<<endl;
//        s1.at(i)+=1;
//
//        s1[i]-=1;
//        cout<<s1[i]<<endl;//对这个运算符[]进行了重载
//        cout<<s1.operator[](i)<<endl;//也可以这样进行调用，两者没有任何区别
//        //s1[i],s1.at(i)均支持修改元素变量
//    }
//}
//总结：两者使用效果没有任何区别，但是两者检测越界的方式不一样
//operator[]是断言的方式
//s1.at()是抛出异常的方式






//4.插入字符  连接字符
//1.尾插单个字符 s1.push_back('s');
//2.后面增添一个字符串   s1.append("llk");
//3.operator+=       能够连接单个字符还能连接一个字符串
//#include<string>
//
//int main(void)
//{
//    string s1("hello");
//    s1.push_back('g');//尾插一个字符
//    s1.append("llk");//尾插一个字符串  append：附加，增补
//
//    string s2(s1);
//    s2+="hello bit";
//    cout<<s2<<endl;
//}












//二、string类对象的比较大小
//不但对象和对象之间能够比较，对象和字符串数组，或者对象和字符串都能进行比较
//#include<string>
//int main(void)
//{
//    string s1("hello world");
//    string s2("hello bit");
//
//    cout<<(s1<s2)<<endl;//其基本的逻辑就是ascll码相比较
////    cout<<(s1<arr)<<endl;一个对象一个字符串能比较，一个对象一个字符数组也能比较
//}

//后续补充 string类重载了很多的符号，基本不用自己在去重载










//三、c++11新增的成员函数
//1.stoi()     int stoi(const string& str,size_t* idx=0,int base =10);    int stoi(const wstring& str,size_t* idx=0,int base =10);
//-----这个函数是将字符串转换成整形
// 第一个参数是字符串   第二个参数是size_t类型的指针，是自己设置的，如果传入，最后转换出的是几位数字会给这个指针指向的变量   第三个参数是将其转换的进制，默认10进制

//#include<string>
//int main(void)
//{
//    size_t num=0;
//    size_t* p=&num;
//    cout<<stoi("12345",p)<<endl;//这个将字符串转换成整形指的是将字符串中的数字转换成整形，如果是这样就会报错stoi("abcd")
//    cout<<num<<endl;
//}
//此外与之类似的还有 stlo()转换成long的    stod()转换成double的等等



//2.to_string()   -----将整形（或者其他类型）转换成字符串
//int main(void)
//{
//    int num1=4;
//    double num2=3.14;
//
//    string s1=to_string(num1);
//    string s2=to_string(num2);
//    cout<<s1[0]<<endl;
//    cout<<s2[1]<<endl;
//}




//补充：和vector一样能够使用迭代区间进行初始化