//可执行程序（二进制指令），也就是常量区代码段存放              全局变量静态变量都在静态区存在

//32位下栈（8M左右）    堆（2G左右）

//char arr[]="abc"     arr是在栈上的   "abc"是在常量区代码段，但是*arr在栈上   因为arr[]数组是在栈上开辟空间后将"abc"拷贝进去，*arr访问的是复制到栈上的a
//chat* arr1="abc"   arr1是在栈上的，  *arr1是在常量区的

//malloc calloc free等是库函数，他们是函数的用法
//new/delete 是操作符

#include<iostream>
using namespace std;
//一、c++动态管理内存的方式   new和delete

//1.基本用法
//int main(void)
//{
//    //申请5个int类型的和一个int类型的空间
//
////    c语言方式
//    int* arr1=(int*)malloc(sizeof(int)*5);
//    int* arr2=(int*)malloc(sizeof(int));
//    free(arr1);
//    free(arr2);
//
//    //c++方式        ----new是c++申请空间的关键字       delete是c++释放空间的关键字
//    int* arr3=new int[5];//向堆申请了5个int类型的空间
//    int* arr4=new int;//向堆申请了1个int类型的空间
//    int* arr5=new int(6);//动态申请一个int的空间，并且初始化为6
//    int* arr6=new int[4]{1,2,3};//申请多个空间并且进行初始化，未分配的空间被初始化为0           ps:ps：c++98标准下数组这个不支持初始化,c++11标准下可以
//
//    delete[] arr3;// delete[]   说明删除的是多个空间
//    delete arr4;//delete  说明删除的只有一个空间
//    delete arr5;
//    delete[] arr6;
//
//
////    总结：malloc/free  new/delete对于内置类型没有本质上的区别，只有用法上的区别
//}









//二、操作自定义类型 （创造new/delete的原因之一   一共有俩 ）          (不要交错的用，尽量配套使用)
//另外一个原因是：面向对象的语言，处理错误的方式一般是抛异常，c++中也要求抛异常   ---try catch
//面向过程的语言，处理错误的方式是  返回值+错误码
//class A
//{
//public:
//    A(int a=10086)
//    {
//        _a=a;
//        printf("hehe\n");
//    }
//
//    ~A()
//    {
//        printf("666\n");
//    }
//private:
//    int _a;
//};
//
//int main(void)
//{
//    //c语言申请单个A对象，5个A数组对象
//    A* a1=(A*)malloc(sizeof(A));
//    A* a2=(A*)malloc(sizeof(A)*5);//malloc申请空间仅仅只是开辟空间        ps：开辟空间失败会返回NULL
//    free(a1);
//    free(a2);
//
//
//    //C++申请单个A对象，5个A数组对象
//    A* a3=new A;//还能这样new A(10)直接对对象构造了
//    A* a4=new A[5];//new不仅仅开辟空间，还能自动调用一次构造函数，每个对象都能调用一次
//    try
//    {
//        A* a5=new A[99999999999999*999999999999999999*999999999999999*999999999999999999*999999999999999*999999999999999999*999999999999999*999999999999999999*999999999999999];//开辟失败不会返回NULL，会直接抛出异常，没有try catch会崩溃
////        xxxxx;
//    }//a5这一句错误会直接跳转到catch,不执行xxxxx，直接执行catch里面的内容。正常情况下就执行xxx；不执行catch
//    catch(const exception& e)//捕获
//    {
//        cout<<e.what()<<endl;
//    }
//    delete a3;
//    delete[] a4;//在释放空间之前还会调用析构函数   ----也就是先调用析构函数
//}

//总结：c+提出new和delete主要是解决两个问题
//自定义类型对象内存申请的时候，初始化和清理的问题。new delete会调用构造函数和析构函数
//new失败了以后要求抛异常，这样才符合面向对象语言的出错处理机制。
//ps：delete和free一般不会失败，如果失败了，都是释放空间上存在越界或者释放指针不对








//三、对于数据结构的优化
//1.对于链表的
//c语言中链表的定义很麻烦,但是c++就很简单
//class listnode
//{
//    listnode(int val=0)//不用再去调用初始化，定义节点后会直接调用构造函数
//    :next(nullptr)
//    ,prev(nullptr)
//    ,_val(val)
//    {}
//
//    ~listnode()//程序结束的时候就会自己调用析构函数
//    {
//        this->next=nullptr;
//        this->prev=nullptr;
//    }
//private:
//    int* next;
//    int* prev;
//    int _val;//结点中存放的值
//};
//int main(void)
//{
//    int* l1=new listnode;
//    delete l1;//释放空间会自动释放里面的空间
//}




//2.对于栈的优化
//class stack
//{
//public:
//    stack(int capacity=4)
//    :_top(0)
//    ,_capacity(capacity)
//    {
//        _a=new int[capacity];
//    }
//
//    ~stack()
//    {
//        delete[] _a;
//        _a=nullptr;
//        _capacity=_top=0;
//    }
//private:
//    int* _a;
//    int _top;
//    int _capacity;
//};
//
//int main(void)
//{
//    stack st;//函数里面的局部变量都是在栈上
//
//    stack* st1=new stack;//在堆上创建了一个stack大小的空间，并且由st1指针指向，st1指针是stack类类型的
////    .....
//    delete st1;//清理这个空间的资源，再析构空间
//}









//四、new和delete的深层理解                   //这两个库函数就不是给我们用的，这两个库函数就是为了对这两个函数进行封装
//1.operator new 和 operator delete这两个函数
//new和delete是用户进行动态内存申请和释放的操作符，operator new和operator delete是系统提供的全局函数
// new是在底层调用operator new全局函数来申请空间
//delete是在底层调用operator delete全局函数来释放空间

//operator new：该函数实际上是通过malloc来申请空间的，当控价申请成功时直接返回，申请失败执行空间不足对应措施。如果用户设置了对应措施则执行，否则抛出异常
//operator delete：该函数最终是通过free释放空间的


//int main()
//{
//    stack* st=(stack*)operator new(sizeof(stack));//抛异常就是在operator new这个函数抛出，这个函数就有抛异常的处理
//    //operator new并不是将new重载，而是这个函数就是这个名字，这个是库函数，其功能仅仅是开辟空间，但是，为自定义类型开辟空间的时候并不会调用构造函数
//    //这个函数和malloc的用法类似
//    operator delete(st);
//}

//总结：operator new 和operator delete就是对malloc和free的封装
//new stack就相当于 call operator new+call stack构造函数

//此外还有operator new[]    operator delete[]   这两个函数就是对上面的两个函数的再次封装（可能是循环调用，也可能是先计算空间再一次性调用）






//五、new和delete的实现原理
//1.new的原理
//调用operator new函数申请空间
//在申请的空间上执行构造函数，完成对象的构造


//2.delete的原理
//在空间上执行析构函数，完成对象中资源的清理工作               先析构再释放空间
//嗲用operator delete函数释放对象的空间


//3.new 类型[n]的原理   （new int[8]）
//调用operator new[]函数，在operator new[]中实际调用operator new完成n个对象空间的申请
//在申请的空间上执行n次构造


//4.delete[] 指针名     （delete[] arr）
//在释放的对象空间上执行n次析构函数，完成n个对象中资源的清理
//调用operator delete[]释放空间，实际在operator delete[]中调用operator delete来释放空间







//六、内存池浅提一下
//向内存池申请内存，提高效率
//如果频繁的向堆申请空间，可申请一个大块的空间自己管理，用时自己分配

//下面的演示就是频繁的插入会比较麻烦
//然后定义一个专属的operator new

//class listnode
//{
//public:
//    listnode(int data=0)//不用再去调用初始化，定义节点后会直接调用构造函数
//    :next(nullptr)
//    ,prev(nullptr)
//    ,_data(data)
//    {}
//
//    void* operator new(size_t n)
//    {
//        void* p=nullptr;
//        p=allocator<listnode>().allocate(1);//stl中的内存池，空间配置器    专属的
//        cout<<"memory pool allocate"<<endl;
//        return p;
//    }
//
//    void operator delete(void* p)
//    {
//        allocator<listnode>().deallocate((listnode*)p,1);
//        cout<<"memory pool deallocate"<<endl;
//    }
//
////private:
//    listnode* next;
//    listnode* prev;
//    int _data;//结点中存放的值
//};
//
//
//class list//上面是单个的结点，这个list是对链表的各种操作
//{
//public:
//    list()
//    {
//        _head=new listnode(-1);//链表首先指向一个new出来的新结点，并且这个新结点调用构造函数-1是头结点的值
//        //上面结点中定义了一个专属operator new
//        _head->next=_head;
//        _head->prev=_head;
//    }
//
//    void  pushback(int x)//尾插
//    {
//        listnode* newnode=new listnode(x);//每次添加新的节点都需要重新向堆上申请空间，很频繁
//        listnode* phead=_head->prev;
//        phead->next=newnode;
//        newnode->prev=phead;
//        newnode->next=_head;
//        _head->prev=newnode;
//    }
//
//    ~list()//消除整个链表
//    {
//        listnode* cur=_head->next;
//        while(cur!=_head)
//        {
//            listnode* next=cur->next;
//            delete cur;
//            cur=next;
//        }
//        delete _head;
//        _head=nullptr;
//    }
//private:
//    listnode* _head;
//};
//int main(void)
//{
//    list l1;//定义一个链表的对象，随后调用构造函数，链表只保存头结点
//    l1.pushback(1);
//    l1.pushback(2);
//    l1.pushback(3);
//    l1.pushback(4);
//    return 0;
//}








//七、定位new表达式（placement-new)    了解即可
//定位new表达式是在已分配的原始内存空间中调用构造函数初始化一个对象

//使用格式
//new(place_address)type  或者 new(place_address)type(initalizer-list)
//place_addres必须是一个指针，initalizer-list是类型的初始化列表
//指针指向的是开辟的空间（一般是malloc）



//class A
//{
//public:
//    A(int a=1086)
//    {
//        _a=a;
//        cout<<"hehe"<<endl;
//    }
//    ~A()
//    {
//        cout<<"haha"<<endl;
//    }
//    int _a;
//};
//
//
//int main(void)
//{
//    //怎么显示的调用类的构造函数
//    A* p=(A*)malloc(sizeof(A));//malloc只会申请空间并不会初始化
////    new(p)A;//new(未初始化的空间,指针)开辟的空间的类型     （可以是自定义类型，可以是内置类型）
//
////    也可以这样使用
////   new(p)A(10087);//还能这样指定的初始化
//
////还能这样拆开使用
//    A* p1=new A(2);//这种使用的方式就等价于A* p1=(A*)malloc(sizeof(A))    new(p1)A(2)
//
////    析构函数能够改显示的调用
//    p1->~A();
//}