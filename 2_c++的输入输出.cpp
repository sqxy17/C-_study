//一、c++常用的输出方法

//#include<iostream>
//1.c++的头文件<iostream>和c的<stdio.h>性质上是一样的，包含着一些输入输出函数           具体的输入输出函数
////using namespace std;//看完1_的命名空间就知道这里是什么意思了         ----c++库的实现定义都封装在std这个命名空间内
//
//int main(void)
//{
//    std::cout<<"hello world"<<std::endl;
////    cout<<"hello world"<<endl;//这样是将命名空间展开了之后才能这样使用
////所以可将常用的std::out展开
//}


//二、cout解释
//<<   官方给的名字叫流插入运算符


//1.    i---in    o---out     stream流动，也就是流的意思
//using std::cout;
//using std::endl;
//int main(void)
//{
//    cout<<"hello world";//<<在这里可以当做流向的符号，将后面的字符串流进cout        所以<<在这里也叫流插入运算符        cout就相当于控制台，流向控制台就是输出
//    cout<<endl;//这个东西就像相当于换行符 '\n'
//    printf("\n");//这样写和上面的endl效果是一样的
//    cout<<'\n';
//}

//2.自动识别类型
//int main(void)
//{
//    int a=3;
//    double d=3.14;
//    cout<<a<<"\n"<<d<<endl;//还能这样的连续使用，并且cout输出的时候并不用去指定格式 %d %lf....之类的
//}



//三、cin解释

//>>   官方的名字叫做流提取运算符

//2.//using std::cin;
//int main(void)
//{
//    //首先cin就相当于scanf从键盘上获取流
//    int a;
//    float b;
//    cin>>a>>b;//这样就相当于scanf对a，b从键盘上赋值     看好<<   >>     箭头指向的就是流入的方向
//    cout<<a<<'\n'<<b<<endl;//但是指定输出小数点后的小数位的时候可以使用printf,cout输出比较麻烦
//}



//四、输出输出缓冲区是和printf  scanf一样的



//补充：>> 流提取运算符     <<流插入运算符