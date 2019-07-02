#ifndef LEARNING_QUEUE_STACK_H_INCLUDED
#define LEARNING_QUEUE_STACK_H_INCLUDED
#include <queue>
#include <stack>
using namespace std;

void test_queue_stack(){
    /********************************
    queue简单地修饰deque，成为另一种容器
    queue<T> queT;
    queue.push(elem) 队尾添加元素
    queue.pop() 从队头移除第一个元素
    构造函数：：
    queue(const queue &que)
    queue&operator=(const queue&que)
    数据存取
    queue.back()
    queue.front()
    大小：
    queue.empty()
    queue.size()
    ***********************************************************
    stack------先进后出
    也是简单地装饰deque容器
    stack<T> stkT;
    stack.push(elem)
    stack.pop()
    stack(const stack&stk)
    stack&operator=(const stack&stk);
    数据存取
    stack.top()
    stack.empty()
    stack.size()

    注意区分-------------
    list,deque,vector 都是push_back(),pop_back()
    stack,queue 是push和pop，没有back
    另外注意:
    stack和queue是没有迭代器的，也就是不可循环遍历
    ***/
    queue<int> queT;
    queue<float> queFloat;
    queue<string> queString;
    queT.push(1);
    queT.push(2);
    queT.push(3);
    queT.push(4);
    queT.pop();//注意，该函数无返回值，只是一种移除操作，
    //如果要读取元素，则
    cout<<queT.back()<<endl;
    cout<<queT.front()<<endl;

    stack<int> stkInt;
    stack<float> stkFLoat;
    stack<string> stkString;
    stkInt.push(1);
    stkInt.push(2);
    stkInt.push(3); //压栈
    //出站

    cout<<"first："<<stkInt.top()<<endl; //读取栈值
    stkInt.pop();//出栈



}


#endif // LEARNING_QUEUE_STACK_H_INCLUDED
