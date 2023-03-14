#include "19_test_string.h"
using std::cout;
using std::cin;
using namespace llk;

//详细见test_string.cpp  .h    这个页面只是做测试

int main()
{
    string s1("hello world");
    string s2(s1);//这个就是浅拷贝，一股脑的将s1所保存的东西全部放在s2中。      s2的_str指向的和s1的_str指向同一块空间
    string s3=s1;
    string s4;
    llk::string::iterator it=s1.begin();
    while(it!=s1.end())
    {
        cout<<*it<<' ';
        it+=1;
    }

}
