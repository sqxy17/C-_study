#include "8_test_stack.h"

void stack::Init(int* arr)//注意是在.cpp的文件中展开的  ：：查找的顺序，局部变量  全局变量  指定的域   （stack就是属于类域）
{
    _arr=arr;
    _top=_capacity=0;
}

void stack::push(int x)
{
    ;
}