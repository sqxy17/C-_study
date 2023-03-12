//#include"10_运算符重载扩展+友元函数.h"
//
//int main(void)
//{
//    data d1;
//    cin>>d1;
//    const data d2;
//    data d3(4,5,6);
//    d1.print();//我们平时输出对象里面的日期是这样输出的
//    //cout<<d1;//怎么能像内置类型一样使用cout输出对象（自定义类型）呢？           -----所谓的内置类型其实就是被ostream& operator<<(int val);已经定义过得
//    //cout也是一个对象，是ostream类的实例化
//
////    d1.operator<<(cout);
////    d1<<cout;//这样虽然能用但是不行,不符合逻辑
//
//    //使用友元函数就能解决这个问题
//    cout<<d1<<d2<<d3<<endl;
//}