#ifndef LEARNING_HEAP_H_INCLUDED
#define LEARNING_HEAP_H_INCLUDED

/*****************************************************
自己定义堆的操作
****/
#define MAX_N 100

int heap[MAX_N],sz =0; //sz表示当前结点个数，也就是当前堆的大小
/*******
使用完全二叉树实现堆操作，但是不使用指针，而是使用数组存储。
添加元素的时候，将元素加到尾部，然后再根据堆的性质，调整新元素，知道元素满足堆的性质；

技巧：编号从0开始
左孩子编号为自己编号 *2 + 1
右孩子编号为自己编号 *2 + 2

**/
//假如求得是最大堆

void push(int x){
    int i = sz++;  //当添加一个数之后，sz+1

    while(i >0){
        int p = (i-1)/2;
        if(heap[p]>=x) break; //满足条件后就结束

        heap[i] =heap[p];//将父亲结点放下来
        i = p;
    }
    heap[i] = x;
}

//删除最大值，根节点
int pop(){
    int ret = heap[0]; //删除根节点

    int x = heap[--sz]; //将最后一个结点复制到根节点，然后向下走，直到满足堆的性质
    //注意将堆的元素个数减一

    int i=0;
    while(i*2+1 < sz){  //此处判断了a<sz
        int left =i*2+1,right=i*2+2;
        //选择最小的赋值到a
        if(right < sz && heap[right] < heap[left]) left = right; //此判断用于决策，最大值是哪个下标，然后做交换，
        //下面就可以只用一个变量值，这是一种编程技巧
        if(x >= heap[left]) break;
        heap[i] = heap[left];
        i = left;
    }
    heap[i] = x;

    return ret;
}

/********************************************************************
利用STL库中的有效队列，该队列使用了堆
******/
#include <queue>
#include <cstdio>
using namespace std;

void test_priority_queue(){
    //注意定义堆的顺序时的写法，也就是要添加一个vector
    priority_queue<int,vector<int>,less<int>> pq; //最大堆
    //priority_queue<int,vector<int>,greater<int>> pq;  //最小堆
    pq.push(1);
    pq.push(3);
    pq.push(5);
    while (!pq.empty()){
        printf("%d num \n",pq.top());
        pq.pop();
    }

    push(4);
    push(6);
    push(8);
    cout<<"sz:"<<sz<<endl;
    cout<<pop()<<endl;
    cout<<"sz:"<<sz<<endl;
}
/***************************
应用实例：
求最小加油次数
N=4,4个加油站
L=25，共行驶25单位距离 （速度1单位距离1单位油）
P=10，起始P单位油
A={10,14,20,21} 加油站点到起始点距离
B={10,5,2,4} 加油站点的加油量
解题思路：在最大行驶范围内，最大的加油量，然后，迭代计算，下一个最大行驶范围
***/
int solution(){
    int N=4,L=25,P=10;
    int A[]={11,14,20,21};
    int B[]={10,5,2,4};
    int ANS =0;
    priority_queue<int> pqueue;
    for(int i=0;i<N;i++){
        if(A[i]<=P){
            pqueue.push(A[i]);
        }else{
            if(pqueue.empty()) return -1;
            P = P + pqueue.top();
            pqueue.pop();
            ANS +=1;
            if (P>=L){
                break;
            }
        }
    }
    return ANS;
}



#endif // LEARNING_HEAP_H_INCLUDED
