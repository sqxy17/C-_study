//一、引用
//1.引用并不是新定义一个变量，而是给已存在的变量取了一个别名，编译器不会为引用变量开辟新的空间，它和它引用的变量公用同一块内存空间
//不管是原来的变量名还是新的引用名都是存在符号表中的
//记住这句话看下面的笔记     已存在的变量可以是定义的，也可以是临时的           临时变量是具有常属性的，是右值，右值不能被改变，所以给右值引用需要是const属性

//2.引用的简单的小例子
//#include<iostream>
//using namespace std;

//int main(void)
//{
//    int a=6;
//    int& b=a;//这个b就是a变量的别名，也就是对a的引用              放在类型名字后面就是引用
//    printf("%d\n%d\n",&a,&b);//输出a变量的地址，在输出b变量的地址会发现两是一样的
//    int* p=&a;//这样用就是取地址
//
//    a=10086;
//    b=10087;//别名和变量a进行赋值都可以对这个地址保存的数字进行改动    例如这个输出a就是10087
//}





//二、引用的特性
//1.引用在定义的时候必须初始化               ----因为引用是一次性的，在引用之后就一直是某个变量的别名，就不能用作其他变量的别名
//2.一个变量可以有多个引用
//3.引用一旦引用了一个实体（指变量），就不能再引用其他的实体（指变量）

//例如：
//int main(void)
//{
//    int a=999;
////    int&  b;//不能这样只定义但是不初始化
//    int& c=a;
//    int& d=a;//c d都是a
//    int& f=c;//并且引用还可以进行引用a-->c-->f
//    cout<<c<<endl<<d<<endl;
//
////    double c=3.14//但是还是不能出现相同的名字               引用的名字和其他变量的名字还是不能相同
//
//    int num=888;
//    c=num;//c已经是a的别名了，所以这个操作只是将num的值赋给c（a）
//}






//三、引用的使用场景
//1.引用做参数
//void swap1(int* a,int* b)//这种方式叫做传址
//{
//    int tmp=*a;
//    *a=*b;
//    *b=tmp;
//}

//可以说引用的出现增加了一种函数的传参方式----传引用
//void swap2(int& x,int& y)//这种方式叫做传引用,x是a的引用，y是b的引用    并且形参里面的引用可以是int&a，int& b。   形参只是声明，并不是定义，只有传实参的时候才是初始化
////void swap2(int x,int y)   并且和这个函数名字构成重载，因为类型不同。但是调用的时候传值和传引用会出现错误。
//{
//    int tmp=x;
//    x=y;
//    y=tmp;
//}
//int main(void)
//{
//    int a=1;
//    int b=9;
//    swap1(&a,&b);
//    cout<<a<<endl<<b<<endl;
//    swap2(a,b);
//    cout<<a<<endl<<b<<endl;
//}


//2.替换二级指针的使用情况                  -----可以回头看看数据结构初阶的那几个使用二级指针的函数
//举个例子
//void test1(int* p)
//{
//    static int y=10087;
//    p=&y;
//}
//void test2(int*& pp)
//{
//    static int x=10086;
//    pp=&x;
//}
//typedef struct ListNode
//{
//    ;
//}Node,*PNode;//前面的node改名，后面的是这个结构体指针的改名。方便数据结构书上的引用
//int main(void)
//{
//    int a=6;
//    int&b=a;//这是对于常量的引用
//    cout<<"别名b对a的引用："<<b<<endl;
//
//    int* p=&a;
//    cout<<"输出变量a的地址"<<p<<endl;
//
//    test1(p);//对比一下一级指针接收参数
//    cout<<"用一级指针接收a的地址，并不能改变现在的指针p的指向"<<p<<endl;
//
//    test2(p);//传的是一级指照样能改变这个指针的指向
//    cout<<"传引用的方式就能传一级指针改变指针p的指向"<<p<<endl;
//}


//3.返回值参数的替换，
//这个就是将指针,用引用名接收，在函数内部对引用名更改就行
//void test(int* arr,int* returnsize);   //通过指针改变所保存的数组的长度
////换成这样的形式
//void test(int* arr,int& returnsize);//对returnsize赋值，改变默认长度



//4.引用做返回值
//int add(int x,int y)
//{
//    int z=x+y;
//    return z;//拐回去看看函数栈帧的创建和销毁，返回值会有一个临时变量，也就是这个右值
//}
//
//int& add1(int x,int y)//这个函数的例子就是引用做返回值   -----引用返回的意思就是，不会生成z的拷贝返回，而是直接返回z的引用
//{
//    //但是这样写是有问题的，z在返回之后，add1函数里面的栈帧会销毁（虽然里面的变量不一定被重置成其他值，z还可能是x+y）,z有可能成为随机值
//    //下面的num引用z的时候可能会引用成随机值
//    int z=x+y;
//    return z;
//}//返回引用  类与对象章节使用较多，且是正确方式
//
//
//int& add2(int x,int y)
//{
//    static int z=x+y;//像这样的出了函数作用域，返回的值没有被销毁，就可以正常使用返回引用，这样的使用是正确的
//    //也就是返回的变量如果在出了函数作用域被销毁，那么只能用返回值进行返回
//    //传引用返回不会再有临时的变量保存z，返回的是z的别名
//    return z;
//}
//
//int main(void)
//{
//    int ret=add(1,2);//我们从栈帧的角度去理解，ret接收的返回值并不是直接拷贝z的，而是有一个临时变量拷贝的z的值，然后用这个临时变量赋值给ret

//    //ps:有时间就看函数栈帧
//    //为什么会这样拷贝?因为在想要拷贝z的值给ret的时候，z所在的栈帧已经销毁，如果执意拷贝z的值就会出现问题
//
//    //那这个临时变量存储在哪
//    //如果这个临时变量比较小（4或者8个字节），就存放在寄存器中
//    // 如果临时变量比较大，就会存放在调用add函数的栈帧里面（如果大的话，现在的这个例子是main函数的栈帧里面）
//    cout<<ret<<endl;
//
//
//    int& num=add1(5,10);//相当于是int& num=z这个空间，add1函数返回的是z的引用           当然也可以用int num接收
//    cout<<num<<endl;
//}





//四、传参，传引用    返回值，返回引用效率的对比
//1.返回值，返回引用效率的对比             clock()函数，会返回运行到此处的运行时间，单位是毫秒

//int test1(int x,int y)
//{
//    int z=x+y;
//    return z;
//}
//
//int& test2(int x,int y)
//{
//    int z=x+y;
//    return z;
//}
//
//int main(void)
//{
//    int time1=0;
//    int time2=0;
//    for(int i=10000;i>0;i--)
//    {
//        test1(1,2);
//    }
//    time1=clock();
//    cout<<time1<<endl;
//
//    for(int i=10000;i>0;i--)
//    {
//        test2(1,2);
//    }
//    time2=clock()-time1;
//    cout<<time2<<endl;
//
//}

//2.传参，传引用效率的对比       //和上面的测试方法相同，可自行设置函数

//3.总结：
// 引用的作用主要体现在传参和返回值
//有些场景下，形参可以改变实参的值
//传递某些较大的数据（大对象、深拷贝对象之类的）可以提高性能。







//五、常引用
//1.常引用同类型的变量
//int main(void)
//{
//    const int a=10086;
////    int& b=a;//这种引用是错误的，学名叫 权限放大 ，因为a只能读不能改，但是这样设置b就可以更改a的内容
//    const int& b=a;//这样的写法就是正确的
//
//
//    //既然有放大就得有权限缩小
//    int n=8;
//    const int& c=n;//这就是权限的缩小，n能读能写，但是别名c只能读不能写
//
//
//    //所以在传引用的时候，类型上可以设置权限，如：
////    void test(const int& a);//传进去的可以是 int a
//}


//2.常引用不同类型的变量
//int main(void)
//{
//    double d=3.14;
//    int a=d;//这样赋值是可以的，发生了隐式类型的转换
//    //隐式类型的转换是怎么进行的？还是栈帧，创建了了一个临时的变量，并且这个临时的变量是int类型的，将d的整数位截断放在这个临时变量里面，最后a=临时变量
//    //a是被临时变量所赋值的。         -----临时变量是右值，具有常性    暂时这样理解
//
////    int& dd=d;//这个地方为什么不能进行 ，这个地方也发生了整型提升，并且产生了临时变量。但是这个临时变量是右值（不能被改变的，有常属性的），所以要用常属性的别名去接收
//    const int& dd=d;//这样就是正确的了        dd是临时变量的别名，只是针对这个，临时变量会保存到存储空间中
//}


//3.使用引用传参，如果不改变参数的值，建议加上const使用
//void test(const int& a);







//六、指针和引用的不同点
//1.引用必须初始化，指针不初始化也能使用
//2.引用和引用的变量同属一个空间，指针需要开辟额外的空间去保存指针变量
//3.引用过一个变量后，就不能再去引用其他变量，  指针能够反复指向不同的地址
//4.引用没有空，但是有空指针
//5.指针能够多级，但引用没有多级
//6.指针使用更复杂，容易出错




//int main(void)
//{
//    int *&ptest=(int*)malloc(sizeof(int) * 4);//这样写是错误的，因为也会有临时变量
//}



//七、后续的补充
//栈帧的临时变量具有常属性，不能修改        ----临时变量是右值。
//int test1(int i)
//{
//    static int arr[10];
//    return arr[i];
//}
//
//int& test2(int i)
//{
//    static int arr[10];
//    return arr[i];
//}
//
//int main(void)
//{
////    test1(4)=5;//可以理解为返回的是一个值   0=5；，也就是说这样写是错误的
//
//    test2(4)=5;//这样就可以成功赋值，这样返回的是arr[i]的别名
//}



//8.临时变量的产生
//1.类型转换         ----
//2.类型的阶段，类型的提升
//3.函数返回值
//4.算数表达式的值（比如1+3）



//补充：
//定义的 int a;int&b=a;像这样的变量名和别名是存放在符号表当中的
//在底层，引用使用指针实现的

//引用可理解成变量的这块空间的别名，但是只关注空间中保存的变量