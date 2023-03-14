#include<iostream>
using namespace std;
//本章除了迭代器，剩余的介绍的都是string类常用的成员函数
//总的概括一下就是在介绍增删查改这些功能，包含18_string类的使用_1.cpp



//一、迭代器          iterator:迭代器
//1.正向迭代器        库函数有const类型正向迭代器
//迭代器都是在类里面定义的，所以使用的时候就像下面的一样   string::iterator it


//迭代器都是在类里面定义的       （理解成在类里面定义的新类型，it就是由这个新类型定义出来的，并且迭代器这个类型和指针有点类似）
//void test_string1(string& st)//遍历的方式一，使用重载的[]，操作下标
//{
//    for(int i=0;i<st.size();i++)
//    {
//        st[i]+=1;
//    }
//
//    for(int i=0;i<st.size();i++)
//    {
//        cout<<st[i]<<' ';//（此外还能用s1.at(i)）
//    }
//}
//
//
////遍历的方式二，迭代器            这个阶段先将迭代器暂时理解成类似于指针的诶行
//void test_string2(string& st)
////这东西类似于指针。但并不是指针
//{//可以看作it是先指向h的一个指针
//    string::iterator it=st.begin();//st.begin()会返回字符串中第一个字符的位置     it类似于指针的作用用于接收指针
//    while(it!=st.end())//st.end()会返回最后一个有效元素的下一个位置  ----也就是\0的位置
//    {
//        *it+=1;//还可像指针一样操作
//        cout<<*it<<' ';//使用的方式也像指针一样
//        ++it;
//    }
//    cout<<endl;
//    it=st.begin();
//    while(it!=st.end())
//    {
//        *it-=1;
//        cout<<*it<<' ';
//        ++it;
//    }
//}
//
//
//
////遍历字符串的方式三，范围for（语法糖）            -----本质上范围for就会替换成迭代器
//void test_string3(string& st)
//{
//    for(auto& i:st)//引用使用后每次都会销毁
//    {
//        i+=1;
//        cout<<i<<' ';
//    }
//    cout<<endl;
//    for(auto& i:st)//引用使用后每次都会销毁     并且引用引用的是那一块空间的名字          注意中间的是：
//    {
//        i-=1;
//        cout<<i<<' ';
//    }
//}



//int main(void)
//{
//    string s1("hello world");//string本身就是有basic_string这个模板实例化出来的
////    test_string1(s1);
////    test_string2(s1);
//    test_string3(s1);
//}






//2.反向迭代器              库函数有const类型的反向迭代器
//和正向迭代器是一样的，反向迭代器同样是类里面的成员
//反向迭代器的类型是 reverse_iterator,用它定义一个类指针的变量
//#include<string>
//void test_reverse_iterator(string& st)
//{
//    string::reverse_iterator rit=st.rbegin();//s1.rbegin()是取末尾的
//    while(rit!=st.rend())
//    {
////        rit+=1;//同样可支持修改
//        cout<<*rit<<' ';
//    }
//}
//
//int main(void)
//{
//    string s1("hello world");
//    test_reverse_iterator(s1);
//}






//3.const类型的引用如何遍历
//const类型的参数使用迭代器      迭代器定义的变量可以进行修改，但是const的参数类型不能修改，所以需要使用const类型的迭代器
//void test_const_string(const string& st)
//{
//    string::const_iterator it=st.begin();//const类型的参数因为不能操作元素，所以也要用一个const类型的迭代器         反向迭代器同样也是这个道理
//}
//
//int main(void)
//{
//    const string s2("hellobit");//既然是定义的变量，那就可以用const来修饰
//    test_const_string(s2);
//}
//此外反向的迭代器的const返回类型    const_reverse_iterator it





//4.迭代器使用的意义
//对于string，下标和[]就已经足够好用，确实可以不用迭代器，但是如果是其他容器（数据结构）就可能不支持这种方式了

//比如list  map/set   这些是不支持下标+[]的方式进行遍历的，因为这两个不是数组的方式进行存储的










//二、查看string增容的方式  （是二倍的扩充，还是1.5倍的扩充）   以及自己手动的增加容量  reserve          resize            当然请记住这些函数都是针对string类的成员函数
//reserve()只是单单的申请空间
//resize()除了申请空间，还能将申请的空间进行初始化
//#include<string>
//
//void testpushback()
//{
//    string s;
//    int sz=s.capacity();//（查看当前的容量的函数 capacity()）并且请记住，这个函数给出的是有效字符的容量，实际容量还要加上1，因为还要存放\0
//    cout<<sz<<endl;
////    cout<<"making s grow:\n";
////    for(int i=0;i<100;++i)
////    {
////        s+='c';
////        if(sz!=s.capacity())
////        {
////            sz=s.capacity();
////            cout<<"capacity changed:"<<sz<<endl;
////        }
////    }
//    //除了系统自己增容，此外还能手动的增加容量
//    s.reserve(1000);//这个函数的意思是申请至少能存放1000个字符的空间   可能会大于1000，因为涉及到字符串对齐（类和结构体的对齐方式）
//    s.resize(10086);//不去制定初始化什么字符默认的是\0
//    s.resize(10087,'c');//还能制定的进行初始化
//}


//请注意，16个字节（包含16）之前，都是在栈上开辟的空间保存的，大于16个字节以后的，就是在堆上开辟的空间保存的（和realloc增容的方式一样）

//void test1()
//{
//    string s1;
//    s1.reserve(100);
//
//    string s2;
//    s2.resize(100,'x');
//
//    string s3("hello world");
////    s3.reserve(100);//已存在的数据并不会改变
//    s3.reserve(7);//就算申请的空间小与字符串，原来的字符串还是不会消失         但是resize会将小于的容量删除
//    cout<<s3<<endl;
//
//    string s4("hello world");
//    s4.resize(100,'x');//已经存放的数据并不会被初始化为x
//    s4.resize(6,'x');//已经存放的并不会被改变，但是小于容量的字符就会被删除
//    cout<<s4<<endl;
//}
//
//int main(void)
//{
////    testpushback();
//    test1();//测试两个函数会申请小于字符串的空间会不会将原有的字符串给清除了
//}







//三、字符串的查找+地址的查找            也就是将存放字符串的地址返回出来
//1.c_str使用方式
//2.在此基础上的查找  find()  有4种定义的方式   可以在cplus网站上查看std::string::find
//3.substr      取出一部分字符并返回（返回的也是字符串，也就是子字符串）
//此外除了find正向查找，还有refind反向查找
//#include<string>
//void test()
//{
//    string s("hello world");
//
//    cout<<s<<endl;
//    cout<<s.c_str()<<endl;//返回了所保存的字符串的地址    返回的地址是const类型的
//
//    //这个返回地址很重要，比如访问文件的地址
////    string file("test.txt");
//////    FILE * fout=fopen(file.c_str(),"w");
////
//////取出文件名的后缀
////    size_t pos=file.find('.');//返回的是第一次出现.的位置,以下标的形式就是4，没找到的话返回的就是npos(-1)  但是是42亿九千万，因为是size_t类型的
////    cout<<pos<<endl;
////    if(pos!=string::npos)
////    {
////        string suffix=file.substr(pos,file.size()-pos);//从pos的位置开始取（包括pos下标），第二个参数是取出字符的个数
////        //substr(size_t pos=0,size_t len=npos)const     也就是说不给参数还有缺省值，从0开始取，全部取完
////        //所以还可以这样 file.substr(pos)  第二个参数不写
////        cout<<suffix<<endl;
////    }
//
//
//    string file("test.txt.zip");//我只查最后一个后缀
////    FILE * fout=fopen(file.c_str(),"w");
//
////取出文件名的后缀
//    size_t pos=file.rfind('.');//这个函数是倒着查找的
//    cout<<pos<<endl;
//    if(pos!=string::npos)
//    {
//        string suffix=file.substr(pos,file.size()-pos);
//        cout<<suffix<<endl;
//    }
//}
//int main()
//{
//    test();
//}









//四、插入和删除         ----插入和删除一般不建议使用，因为效率很低，保存字符串的形式就是顺序表
//1.insert()插入
//2.erase() 清除
//#include<string>
//void test_insert()
//{
//    string s;
//    s.insert(0,1,'x');//在开头的位置插入1个x
//    s.insert(s.begin(),'y');//不指定就插一个y  还是从头开始
//    s.insert(0,"test");  //从开头的位置插入一个字符串
//
//    //当然还能从中间插入
//    s.insert(4,"!!!!!!");//这个位置是下标
//    cout<<s<<endl;
//}
//
//void test_erase()
//{//尽量少用头删和中间位置的删除
//    string s("hello world,hello bit");
//    s.erase(0,1);//从下标为0的位置开始删除 1个字符
//    s.erase(s.size()-1,1);
////    当然可以进行中间的删除，把那个下标位置更改一下就行
//    s.pop_back();//尾部删除
//    cout<<s<<endl;
//    s.erase(0);//不给值就全部删完
//    cout<<s<<endl;
//}
//int main(void)
//{
////    test_insert();
//    test_erase();
//}







//五、输入字符串的是时候有些小问题
//#include<string>
//int main(void)
//{
//    string s;
////    cin>>s;//输入的字符串有空格的时候会不读取空格后面的字符串，所以可以用下面的这些方式进行解决
//
//////方式一
////    char ch=getchar();//只读取了一个，剩下的还在输入缓冲区
////    while(ch!='\n')
////    {
////        s+=ch;
////        ch=getchar();//从未读取完的输入缓冲区继续读取字符
////    }
//
//
//////方式二   使用getline
////    getline(cin,s);//原理就是上面的判断，只以\n为结束标志    cout<<s<<endl;
//
//
////方式三     这种对于string类对象不适用，仅仅适用于字符数组
////scanf("%[\n]",arr);
//
//
//cout<<s<<endl;
//}







