#ifndef C___STUDY_8_TEST_STACK_H
#define C___STUDY_8_TEST_STACK_H

#endif //C___STUDY_8_TEST_STACK_H

class stack
{

private:
    int* _arr=nullptr;
    int _top;
    int _capacity;
public:
    void Init(int* arr);//函数的声明是在类的里面
    void push(int x);
};
