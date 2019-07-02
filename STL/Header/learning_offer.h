#ifndef LEARNING_OFFER_H_INCLUDED
#define LEARNING_OFFER_H_INCLUDED

#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <ctime>
#include <queue>
#include <cstdio>

using namespace std;
/*************************
数组：
****/
///1)数组和指针的区别，如下面的例子：
int GetSize(int data[]){
    ///知识点1：当数组作为函数的参数进行传递时，数组会自动退化为同类型指针
    return sizeof(data);///4， data被转化为指针
}
int test_point_sum(){
    int data1[] = {1,2,3,4,5};
    int size1 = sizeof(data1);///20,数组类型

    int *data2 = data1;
    int size2 = sizeof(data2); ///4

    int size3 = GetSize(data1);///4

    cout<<size1<<","<<size2<<","<<size3<<endl;
}
///2）二维数组中查找，行从小到大顺序，列从小到大顺序的二维数组，查找某一个数
bool Find(int * matrix, int rows,int columns,int number){
    bool found = false;
    //按行存储
    if(matrix != NULL && rows >0 && columns >0){
        int row =rows-1;
        int column = 0;
        while(row >=0 && column < columns){
            cout<<'('<<row<<','<<column<<','<<endl;
            if(matrix[row * columns + column] == number){
                found = true;
                break;
            }else if(matrix[row * columns + column] > number){
                row -=1;
            }else{
                column +=1;
            }
        }
    }
    return found;
}
void test_find(){
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    cout<<Find((int *)matrix,4,4,0)<<endl;
}
/*************************
字符串：
注意C/C++中字符串都以字符'/0'作为结尾，所以在申请内存时，注意添加个1，防止越界
如：
char str[10];
strcpy(str,"0123456789");
那么会出现越界
****/
///1）注意，用字符常量初始化数组和指针时存在差别
///初始化指针时，只需要指针指向常量地址即可，多有被初始化的变量都是指向一个地址
///而初始化数组的时候，每个数组自己申请内存，然后再将地址内容拷贝到申请的内存中
///str1 != str2
char str1[] ="hello world";
char str2[] ="hello world";
///str3 == str4
char *str3 ="hello world";
char *str4 ="hello world";
///2）替换空格，将字符串中的空格替换成%20，我we are happy; --> we%20are%20happy;
///解题思路是：从后往前，进行遍历；首先要统计出空格数，从而知道多处多少个空间，然后声明两个指针，
///一个指向扩充的数组末尾，一个指向真实字符串的末尾\0处，然后开始滑动
//length为字符数组总容量
void ReplaceBlank(char str[], int length){
    if(str == NULL && length <=0) return;

    //统计空格大小
    int quad_num=0;
    int origin_length=0;
    while(str[origin_length] != '\0'){
        if(str[origin_length] == ' '){///先判断，然后在对变量进行变化
            quad_num++;
        }
        ++origin_length; ///对重要变化的变量要放到后面，
    }
    int new_length = origin_length + 2 * quad_num; //可以直接作为下标

    if(new_length+1 > length) return;

    while(origin_length >=0 && new_length > origin_length){
        if(str[origin_length] == ' '){ //此处不能处理，因为它的跳转位置，所以会硬性其他跳转
            str[new_length--] ='0';
            str[new_length--] ='2';
            str[new_length--] ='%';
        }else{
            str[new_length--] = str[origin_length];
        }
        origin_length--;
    }
}
void test_str(){
    char str[100] = {" helloword"};
    ReplaceBlank(str,100);
    cout<<str<<endl;
}
/*************************
链表:
***/
///1) 添加节点
struct ListNode{
    int m_mValue;
    ListNode * next;
};

void AddToTail(ListNode ** pHead, int value){
    ListNode * pNew = new ListNode();
    pNew->m_mValue = value;
    pNew->next =NULL;

    if(*pHead == NULL){
        *pHead = pNew; //将头指针指向第一个元素
    }else{
        ListNode * pNode = *pHead;
        while(pNode->next != NULL){
            pNode = pNode->next;
        }
        pNode->next = pNew;
    }
}
///2）删除节点
void RemoveNode(ListNode ** pHead,int value){
    if(pHead == NULL || *pHead == NULL) return;

    ListNode *deleteNode = NULL;
    if((*pHead)->m_mValue == value){
        deleteNode =*pHead;
        *pHead = (*pHead)->next;
        delete deleteNode;
    }else{
        ListNode * pNode =*pHead;
        deleteNode = pNode->next;
        while(deleteNode != NULL){
            if(deleteNode->m_mValue == value){
                (*pHead)->next = deleteNode->next;
                delete deleteNode;
            }
            pNode = pNode->next;
            deleteNode = deleteNode->next;
        }
    }
}
/*****************************
从尾到头打印链表：
****/
void PrintListReversingly(ListNode * pHead){
    if(pHead == NULL) return;
    stack<int> nodes;

    ListNode * pNode = pHead;
    while(pNode != NULL){
        nodes.push(pNode->m_mValue);
        pNode = pNode->next;
    }

    while(!nodes.empty()){
        cout<<nodes.top()<<endl;
        nodes.pop();
    }
}
/***
递归形式
**/
void PrintListReversingly1(ListNode * pHead){
    if(pHead == NULL) return;

    if(pHead->next != NULL){
        PrintListReversingly(pHead->next);
    }
    cout<<pHead->m_mValue<<endl;
}
/*************************
二叉树：
*****/
struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode * m_pLeft;
    BinaryTreeNode * m_pRight;
};

BinaryTreeNode * ConstructCore(
    int *startPreorder,int *endPreorder,
    int *startInorder,int *endInorder){
    int root_v = startPreorder[0]; //第一个为根节点已经读取，后面就要+1
    BinaryTreeNode * root = new BinaryTreeNode();
    root->m_nValue =root_v;
    root->m_pLeft =root->m_pRight =NULL;

    //注意最终条件的设置，只有树为1，且前后字数
    if(startPreorder == endPreorder){
        if(startInorder == endInorder
           && *startPreorder == *endPreorder){
            return root;
        }else{
            return NULL;//throw exception("Invalid input.");
        }
    }
    //中序中找根节点的值
    int * rootInorder = startInorder;
    while(rootInorder<=endInorder && *rootInorder != root_v)
        ++rootInorder;
    if(rootInorder <= endInorder && *rootInorder != root_v)
        return NULL;//throw exception("Invalid input.");

    int leftLength = rootInorder - startInorder;
    int *leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0){
        //构建左子树
        root->m_pLeft = ConstructCore(startPreorder + 1,leftPreorderEnd,
                                      startInorder,rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder){
        //构建右子树
        root->m_pRight = ConstructCore(leftPreorderEnd+1,endPreorder,
                                       rootInorder+1,endInorder);
    }
    return root;
}


BinaryTreeNode * Construct(int * preorder,int * inorder,int length){
    if(preorder == NULL || inorder ==NULL || length <=0) return NULL;

    return ConstructCore(preorder,preorder+length - 1,
                         inorder,inorder+length - 1);
}

/******************************
两个stack，组成队列
****/
template<typename T>
class CQueue{
public:
    CQueue(){};
    ~CQueue(){};

    void appendTail(const T &node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};
template<typename T>
void CQueue<T>::appendTail(const T &node){
    stack1.push(node);
}
template<typename T>
T CQueue<T>::deleteHead(){
    T result;
    if(!stack2.empty()){
        result = stack2.top();stack2.pop();
    }else{
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        if(stack2.empty()){
            cout<<"empty"<<endl;
            return result;
        }
        result = stack2.top();
        stack2.pop();
    }
    return result;
}
void test_stack_queue(){
    CQueue<int> cque;
    cque.appendTail(1);
    cque.appendTail(2);
    cque.appendTail(3);
    cque.appendTail(5);
    cout<<cque.deleteHead()<<endl;
}
/********************************
算法和数据结构
*******/
///3)快排算法
int Partition(int data[],int length , int start,int ended){
    if(data ==NULL || length<=0 || start <0 || ended >=length){
        return 0;//throw new exception("Invalid Error!");
    }
    int index = 1;//RandomInRange(start,ended); //随机选择一个数字下标
    swap(data[index],data[ended]);//将这个数存到最后一位

    int small = start -1;
    for(index =start;index < ended;++index){
        if(data[index] < data[ended]){///编程技巧，当大于的时候，small停止增加，
                ///index继续增加，等到符合条件了，就将符合条件的和前面一开始不符合条件的元素代替
                ///这样两个索引开始同步，然后遇到不同就不同步，这样能实现实时跟踪替换（技巧，技巧）
            ++small;///指示大于data[ended]的元素，index遍历元素
            if(small != index)
                swap(data[index],data[small]);
        }
    }
    ++small;///此时small指示的是小于data[ended]的左边最近的元素，因而
    swap(data[small],data[ended]);

    return small;
}
void QuickSort(int data[],int length,int start,int ended){
    if(start == ended){
        return;
    }
    int index = Partition(data,length,start,ended);
    if(index > start){
        QuickSort(data,length,start,index-1);
    }
    if(index < ended)
        QuickSort(data,length,index + 1,ended);
}

///while((scanf("%d", &temp) == 1) && (getchar() != '\n'))
///if (getchar() == '\n')  break;
/*****************************
实现一个排序O(n)复杂度，而排序的数字范围有限，则使用有限辅助空间
如：年龄排序
首先统计数组中每个数值的个数，下标为年龄，然后根据下标以及下标的值，重复该年龄
然后这样依次进行存储，就可以了
*****/
void SortAges(int ages[],int length){
    if(ages == NULL || length <= 0){
        return;
    }
    const int MaxAge = 99;
    int timesOfAges[MaxAge + 1];
    ///先初始化为0
    for(int i=0;i<=MaxAge;i++)
        timesOfAges[i] =0;
    ///然后开始统计
    for(int i=0;i<length;i++){
        int age = ages[i];///注意有效性判断
        if(age<0 || age >MaxAge) return;
        ++timesOfAges[age];
    }
    int index=0;
    for(int i=1;i<=MaxAge;i++){
        for(int j=0;j<timesOfAges[i];j++){
            ages[index] =i;
            ++index;
        }
    }
}
/***************************
对于旋转数组中查找最小数字,
首先要明白数据排列的结构，第一个元素一定大于最后一个元素
这样用二分查找，确定元素在第一段序列上，还是在第二段序列上，然后进行不同的移动
**/
///如果存在特例，则顺序查找
int MinInorder(int *numbers,int index1,int index2){
    int result = numbers[index1];
    for(int i=index1;i<index2;i++){
        if(numbers[i] < result){
            result = numbers[i];
        }
    }
    return result;
}
///二分查找
int Min(int * numbers, int length){
    if(numbers == NULL || length <= 0) return 0;

    int index1 =0;
    int index2 =length -1;
    int indexMid = index1;

    ///检查退出条件
    while(numbers[index1] >= numbers[index2]){
        if(index2 - index1 == 1){
            indexMid = index2;
            break;
        }
        ///利用二分查找最小点
        indexMid = (index2 + index1) /2;

        ///注意这边有个特例，就是先决条件是，假设end<start<mid,则该mid数位于前部分序列
        ///所以我们当相等的时候我们不知道如何确定mid属于前还是属于后
        ///所以当三个值相等时，则只能顺序查找
        if(numbers[index1] == numbers[indexMid]
           && numbers[indexMid] == numbers[index2]){
            return MinInorder(numbers,index1,index2); ///不能直接带入length，因为可能只是局部存在问题
           }
        if(numbers[indexMid] >= numbers[index1]){
            index1 = indexMid;
        }else if(numbers[indexMid] <= numbers[index2]){
            index2 = indexMid;
        }
    }
    return numbers[indexMid];
}

/**************************
递归和循环：
斐波那契数列.蛙跳的题目，分析为斐波那契数列
***/
long long Fibonacci(unsigned int n){
    if(n<=0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return Fibonacci(n-1)+Fibonacci(n-2);
}
///自底向上解法，注意递归地从上而下的方式存在很多冗余；
///所以下面改进的解
long long Fibonacci1(unsigned n){
    int result[2] ={0,1};
    if(n < 2){
        return result[n];
    }
    long long fibMinusOne =1;
    long long fibMinusTwo =0;
    long long fibN=0;
    for(unsigned int i=2;i<=n; i++){
        fibN = fibMinusOne + fibMinusTwo;
        fibMinusTwo = fibMinusOne;
        fibMinusOne = fibN;
    }
    return fibN;
}
/*********************************
10位运算,注意右移存在符号位判断的情况，较为复杂
所以将检查数左移可实现更好的效果，
两位一个技巧就是，数字-1，然后与上本身，可以实现消除最后一个为1的位
*/
int NumberOf1(int n){
    int counts = 0;
    unsigned int flag =1;
    while(flag){
        if(n & flag)
            counts++;
        flag = flag << 1;
    }
    return counts;
}
int NumberOf2(int n){
    int counts =0;
    while(n){
        counts++;
        n = (n-1) & n;
    }
    return counts;
}

/***************************
11 数值整数次方
****/
///一定要注意浮点数比较的坑，不能用==
bool equal(double base, double n){
    if(base - n > -0.0000001 && base - n < 0.0000001){
        return true;
    }
    return false;
}
double Calculate(double base, int exp){
    int result =1;
    for(int i=1;i<=exp;i++){
        result *= base;
    }
    return result;
}
double Power(double base, int exponent) {
    if(equal(base,0.0) && exponent <0){
        return 0;
    }
    unsigned int abs_exp =(unsigned int) exponent; //如果为负，不能直接进行无符号数的转换
    if(exponent < 0){
        abs_exp = (unsigned int) (-exponent);
    }
    double res = Calculate(base,abs_exp);
    if(exponent <0)
        return 1.0/res;
    return res;
}

/******************
12:n个位数打印：当位数很大的时候，不能用长整形什么的表示，所以
只能用字符串了；
***/
bool Increment(char* n){
    bool isOverflow =false;
    int nTakeOver =0;
    int nLength = strlen(n);
    for(int i=nLength-1;i>=0;i--){
        int sumN = n[i]-'0'+nTakeOver;
        if(i== nLength -1)
            sumN++; //加1
        if(sumN >= 10){
            if(i == 0)//如果走到头了，还有进位的话，那么就是溢出了，输出全部了
                isOverflow =true;
            else{
               sumN -= 10;
               n[i] = '0' +sumN;
               nTakeOver =1;
            }
        }else{
            n[i] = '0' + sumN;
            break;
        }
    }
    return isOverflow;
}
void PrintNumber(char * n){
    bool isBegining =true;
    for(int i=0;i<strlen(n);i++){
        if(isBegining && n[i] != '0')
            isBegining = false;
        if(!isBegining){
            cout<<n[i];
        }
    }
    cout<<endl;
}

void PrintToMaxOfNDigits(int n){
    if(n<=0){
        return;
    }
    char * number = new char[n+1];
    memset(number, '0',n);
    number[n] = '\0';

    while(!Increment(number)){
        PrintNumber(number);
    }
    ///记得对函数中申请的动态内存进行释放
    delete []number;
}
/******************************
13上面的解法虽然很直观，但是代码较长，可以使用递归的方式
***/

void PrintNDigitRecursively(char * number,int n,int index){
    if(index == n-1){
        PrintNumber(number);
        return;
    }
    for(int i=0;i<10;i++){
        number[index+1] = i +'0';
        PrintNDigitRecursively(number,n,index+1);
    }
}
void PrintNDigit(int n){
    if(n <= 0)
        return;
    char * number = new char[n+1];
    memset(number,'0',n);
    number[n] = '\0';
    for(int i=0;i<10;i++){
        number[0] = i + '0';
        PrintNDigitRecursively(number,n,0);
    }
}
/***********************************
14奇偶排序，将奇数排在偶数之前
*****/
void ReorderOddEven(int * pData,unsigned int length){
    if(pData == NULL || length ==0){
        return;
    }
    int *pBegin =pData;
    int *pEnd = pData +length -1;

    while(pBegin < pEnd){
        while(pBegin < pEnd && (*pBegin & 0x1) != 0) pBegin++;
        while(pBegin < pEnd && (*pEnd & 0x1) == 0) pEnd--;

        if(pBegin < pEnd){
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}
/**********************
更加通用的方式是添加一个函数指针，更改函数条件即可实现不同目的的排序
14
***/
bool isEven(int n){
    return (n & 0x1) == 0;
}
void Reorder(int * pData,unsigned int length,bool (*func)(int)){
    if(pData == NULL || length ==0){
        return;
    }
    int *pBegin =pData;
    int *pEnd = pData +length -1;

    while(pBegin < pEnd){
        while(pBegin < pEnd && !func(*pBegin)) pBegin++;
        while(pBegin < pEnd && func(*pEnd)) pEnd--;

        if(pBegin < pEnd){
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}
/*************************
代码鲁棒性考察
15 查找单链表的倒数第k个元素

struct ListNode{
    int data;
    ListNode *next;
};**/
ListNode * FindKthToTail(ListNode * pListNode,unsigned int k){
    if(pListNode ==NULL || k == 0){
        return NULL;
    }
    ListNode * pHead = pListNode;
    ListNode * pBehind = NULL; //第二个指针，当pHead到达尾部的时候，
    //pBehind指向的是倒数第k个
    for(unsigned int i =0;i<k-1;i++){
        if(pHead->next != NULL)
            pHead = pHead->next;
        else{
            return NULL;
        }
    }
    pBehind = pListNode;
    //同步前进
    while(pHead->next != NULL){
        pHead = pHead->next;
        pBehind =pBehind->next;
    }
    return pBehind;
}
/***********************************
翻转链表
***/
ListNode * ReverseList(ListNode * pHead){
    ListNode * ReverseHead =NULL;
    ListNode * pNode = pHead;
    ListNode * pPrev = NULL;
    while(pNode != NULL){
        ListNode * pNext = pNode->next;

        if(pNext ==NULL){//解决了NULL链表，一个节点的链表问题
            ReverseHead = pNode;
        }
        pNode->next = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
}
/******************
合并链表
*/
ListNode * Merge(ListNode * pHead1,ListNode * pHead2){
    if(pHead1 == NULL)
        return pHead2;
    if(pHead2 == NULL)
        return pHead1;

    ListNode *MergeNode = NULL;
    if(pHead1->m_mValue < pHead2->m_mValue){
        MergeNode = pHead1;
        MergeNode->next = Merge(pHead1->next,pHead2);
    }else{
        MergeNode = pHead2;
        MergeNode->next =Merge(pHead1,pHead2->next);
    }
    return MergeNode;
    //ListNode * pNode =MergeNode;
    /***
    非递归
    while(pHead1 != NULL && pHead2 !=NULL){
        if(pHead1->data < pHead2->data){
            pNode->next = pHead1;
            pHead1 =pHead1->next;
            pNode = pNode->next;
        }else{
            pNode->next = pHead2;
            pHead2 = pHead2->next;
            pNode = pNode->next;
        }
    }
    if(pHead1 !=NULL){
        pNode->next = pHead1;
    }
    if(pHead2 !=NULL){
        pNode->next = pHead2;
    }
    */
    return MergeNode;
}
/*****************
子树结构：

struct BinaryTreeNode{
    int data;
    BinaryTreeNode * left,right;
};**/
bool DoesTree1HaveTree2(BinaryTreeNode * pRoot1,BinaryTreeNode * pRoot2){
    if(pRoot2 == NULL){ //如果B已经遍历完了，则返回真
        return true;
    }
    if(pRoot1 == NULL){//如B没有遍历完，A已经遍历完了，则返回false
        return false;
    }
    if(pRoot1->m_nValue != pRoot2->m_nValue){ //如果遇到不相等则放回false
        return false;
    }
    //然后递归测试左右子树，分别都相等返回
    return DoesTree1HaveTree2(pRoot1->m_pLeft,pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight,pRoot2->m_pRight);
}
bool HasSubtree(BinaryTreeNode * pRoot1,BinaryTreeNode * pRoot2){
    bool result =false;

    if(pRoot1 != NULL && pRoot2 != NULL){
        if(pRoot1->m_nValue == pRoot2->m_nValue){
            result = DoesTree1HaveTree2(pRoot1,pRoot2);
        }
        if(!result)
            result = HasSubtree(pRoot1->m_pRight,pRoot2);
        if(!result)
            result = HasSubtree(pRoot1->m_pRight,pRoot2);
    }
    return result;
}

/**************************
19二叉树的镜像
****/
void MirrorRecursively(BinaryTreeNode * pNode){
    if(pNode == NULL || (pNode->m_pLeft == NULL && pNode->m_pRight == NULL))
        return;
    ///交换左右子节点
    BinaryTreeNode * pTemp = pNode->m_pRight;
    pNode->m_pRight = pNode->m_pRight;
    pNode->m_pRight = pTemp;

    if(pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight);
    if(pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight);
}
/************
顺时针打印矩阵：
一个圈一个圈的打印,注意每个圈的左上角为(a,a)，a从0开始
然后更具左上角点打印圈
**/
void PrintMatrixByCircle(int ** numbers,int columns,int rows,int start){
    ///注意：要分四种情况，而且这四种情况都是有条件的，
    ///符合条件了就执行
    int endx = columns - 1 - start;
    int endy = rows - 1 - start;

    //打印第一个个边
    for(int i=start;i<=endx;i++){
        cout<<numbers[start][i]<<' ';
    }
    //打印最右边列
    if(start < endy){
       for(int i=start+1;i<=endy;i++){
            cout<<numbers[i][endx]<<' ';
       }
    }

    //打印最下边的边
    if(start < endx && start < endy){
        for(int i=endx-1;i>=start;i--){
            cout<<numbers[endy][i]<<' ';
        }
    }
    ///打印最左边的边
    if(start < endy -1 && start < endx ){
        for(int i=endy -1;i>start;i--){//注意条件
            cout<<numbers[i][start]<<' ';
        }
    }
}

void PrintMatrix(int ** numbers,int columns,int rows){
    if(numbers ==NULL || columns <=0 || rows <= 0)
        return;
    int start =0; //用于表示左上角
    while(columns > start *2 && rows > start *2){ ///难点在于这个条件的确定
        PrintMatrixByCircle(numbers,columns,rows,start);
        ++start;
    }
}

/*********************
栈的操作；既要记录最小元素，也要保持栈的特性，所以要用辅助栈
首先要明白，最小站放入的是当前对应栈中的最小值，如果压入栈时，的值大
则最小值依然保持在前面的最小值，所以就有了m_min.push(m_min.top)
***/
template <typename T>
class Stack{
public:
    stack<T> m_data;
    stack<T> m_min;
    void push(const T & data){
        m_data.push(data);
        if(m_min.size() ==0 || data < m_min.top()){
            m_min.push(data);
        }else{
            m_min.push(m_min.top());
        }
    }
    void pop(){
        m_data.pop();
        m_min.pop();
    }
    T & min_(){
        if(m_data.size() >0 && m_min.size() >0)
            return m_min.top();
    }
};
/*****************
判断序列压栈后，输出时候是后一个序列
******/
bool IsPopOrder(const int *pPush,const int * pPop,int nlength){
    if(pPush == NULL || pPop == NULL || nlength <= 0){
        return false;
    }
    bool bPossible = false;
    /**********
    指针常量：指针的内容是常量不可改变
    指向的地址不可以重新赋值，但内容可以改变，必须初始化，地址跟随一生，
    常量指针：指针本身为常量，但其内容（某个地址）可以改变，本身累加，内容不可重新赋值
    指向的地址可以变，但内容不可以重新赋值，内容的改变只能通过修改地址指向后变换。
    ****/
    const int *pNextPush = pPush;
    const int *pNextPop = pPop;
    stack<int> stackData;
    while(pNextPop - pPop < nlength){
        ///如果栈顶和输入的不同则添加，直到相同
        while(stackData.empty() || *pNextPop != stackData.top()){
            if(pNextPush - pPush == nlength)
                break;
            stackData.push(*pNextPush);
            pNextPush++; ///注意const 常量指针可以累加，不可赋值常数
        }
        if(stackData.top() != *pNextPop)
            break;///当栈满还无法匹配，则会退出
        stackData.pop();
        pNextPush;
    }
    if(stackData.empty() && pNextPop - pPop == nlength){
        return true;
    }
    return false;
}

///23从上往下打印二叉树
void PrintFromTopToBottom(BinaryTreeNode * pTreeRoot){
    if(pTreeRoot == NULL)
        return;
    deque<BinaryTreeNode *> DequeTreeNode;

    DequeTreeNode.push_back(pTreeRoot);

    while(!DequeTreeNode.empty()){
        BinaryTreeNode * tNode = DequeTreeNode.front();
        DequeTreeNode.pop_front();
        cout<<tNode->m_nValue;
        if(tNode->m_pLeft != NULL){
            DequeTreeNode.push_back(tNode->m_pLeft);
        }
        if(tNode->m_pRight != NULL){
            DequeTreeNode.push_back(tNode->m_pRight);
        }
    }
}

/***********************
判断二叉搜索树的后续遍历序列,
注意后序遍历的特点：
最优一个数是根节点，然后根节点的前面半部分小于根节点，后半部分都大于根节点
则只要不符合就不是后序遍历序列
****/
bool VerifySquenceOfBST(int sequence[], int length){
    if(sequence == NULL || length <=0){
        return false;
    }
    int root = sequence[length - 1];
    int i =0;
    while(i<length-1){
        if(sequence[i] <= root)
            i++;
        else
            break;
    }
    int j =i;
    while(j < length -1){
        if(sequence[j] < root)
            return false;
    }
    bool left = true;
    if(i > 0){
        left = VerifySquenceOfBST(sequence,i);
    }
    bool right =true;
    if(i < length -1){
        right = VerifySquenceOfBST(sequence+i,length-1-i);
    }
    return left && right;
}

/**********************
查找二叉树的路径
***/
void FindPath(BinaryTreeNode * pRoot,int expectedSum,
    vector<int> & path,int &current_sum){
    current_sum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);

    bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;
    if(current_sum == expectedSum && isLeaf){
        vector<int>::iterator it = path.begin();
        for(;it != path.end();++it){
            cout<<*it<<endl;
        }
    }
    if(pRoot->m_pLeft != NULL)
        FindPath(pRoot->m_pLeft,expectedSum,path,current_sum);
    if(pRoot->m_pRight != NULL)
        FindPath(pRoot->m_pRight,expectedSum,path,current_sum);

    //否则退回父节点，则需要将保存的路径退回
    current_sum -= pRoot->m_nValue;
    path.pop_back();
}
void FindPath(BinaryTreeNode * pRoot,int expectedSum){
    if(pRoot == NULL)
        return;
    vector<int> path;
    int current_sum =0;
    FindPath(pRoot,expectedSum,path,current_sum);
}
/**********************
26,复杂链表的复制，对于sibling指针的指向问题，需要考虑在复制时，
将原始列表与新列表形成一种映射关系，那么sibling的映射关系也就能明了了，
那么根据映射关系，也就可以对sibling指针进行设置了
本文使用的是将新的链表每个节点是旧节点的后节点，那么sibiling的对应关系也是next节点
最后在将新旧链表组成的链表拆分
主要步骤分两步：
1）先将原始列表按照next进行复制，
2）然后在计算sibling的
所以知道了新旧的映射关系，第二遍就可以了
3）将新旧列表拆开
**/
struct ComplexListNode{
    int data;
    ComplexListNode * next;
    ComplexListNode* Sibling;
};
///1)按照next复制节点,将新的节点复制到就旧的
///节点的后面
void CloneNodes(ComplexListNode * pHead){
    ComplexListNode * pNode = pHead;
    while(pNode != NULL){
        ComplexListNode * pCloned = new ComplexListNode();
        pCloned->data = pNode->data;
        pCloned->next = pNode->next;
        pCloned->Sibling = NULL;
        pNode->next = pCloned;
        pNode = pCloned->next;
    }
}
///根据映射关系，设置sibling
void ConnectSiblingNodes(ComplexListNode * pHead){
    ComplexListNode * pNode = pHead;

    while(pNode != NULL){
        ComplexListNode * pCloned = pNode->next;
        if(pNode->Sibling != NULL){
            pCloned->Sibling = pNode->Sibling->next;
        }
        pNode = pCloned->next;
    }
}
///拆分链表
ComplexListNode * ReconnectNodes(ComplexListNode * pHead){
    ComplexListNode * pNode = pHead;
    ComplexListNode * pClonedHead = NULL;
    ComplexListNode * pCloned =NULL;
    if(pNode != NULL){
        pCloned =pClonedHead = pNode->next;
        pNode->next = pCloned->next; ///将原始的链表链连起来
        pNode = pNode->next;
    }
    while(pNode != NULL){
        pCloned->next = pNode->next;
        pCloned = pCloned->next;
        pNode->next = pCloned->next;
        pNode = pNode->next;
    }
    return pClonedHead;
}
///将上面三步合起来
ComplexListNode * Clone(ComplexListNode * pHead){
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}
/*******************
二叉搜索树，转化为双向链表，left为指向前一个指针
右子树指向后一个指针，
解题思路：因为搜索树的中序遍历是顺序的，所以利用中序遍历
方式将节点进行转换，
又因为，当回归到父节点是，左孩子都应该已经转换了，所以需要
保留左孩子转换后的尾节点，然后再将尾节点传到下一个递归
中序遍历的特点：
1）左孩子一直递归下去
2）处理
3）右孩子一直递归下去
****/
///注意一个坑，也就是第二个指针用于记录已经排序的序列最后一个节点，
///这个节点需要被内部改变，且外部也要用到内部改变的值，则要用指针的引用或者二级指针
///注意如果是指针指向的值的改变用指针可以保持内部改变被外部使用，
///但是如果是指针本身改变的话，则把指针看作值，使用二级指针或指针引用记性跟踪改变

void ConvertNodes(BinaryTreeNode * pNode,BinaryTreeNode *& pLastNodeInList){
    if(pNode == NULL){
        return;
    }
    BinaryTreeNode *pCurrentNode = pNode;
    if(pCurrentNode->m_pLeft != NULL){
        ConvertNodes(pCurrentNode->m_pLeft,pLastNodeInList);
    }
    ///开始转换
    pCurrentNode->m_pLeft = pLastNodeInList;
    if(pLastNodeInList != NULL){
        pLastNodeInList->m_pRight = pCurrentNode;
    }
    ///将左边最后一个节点设置成Current
    //因为已经转换，则最后一个节点需要变换为pCurrentNode
    pLastNodeInList = pCurrentNode;

    ///开始右孩子
    if(pCurrentNode->m_pRight != NULL){
        ConvertNodes(pCurrentNode->m_pRight,pLastNodeInList);
    }
}
BinaryTreeNode* Converts(BinaryTreeNode *pHead){
    if(pHead == NULL)
        return NULL;
    BinaryTreeNode * pLastNodes = NULL;
    ConvertNodes(pHead,pLastNodes);

    BinaryTreeNode * pHeadOfList = pLastNodes;
    while(pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL){
        pHeadOfList = pHeadOfList->m_pLeft;
    }
    return pHeadOfList;
}

/*************************
字符串排序，递归的思想
先第一个字符与后面的字符交换，然后再将第一个字符去除，
///考虑后面字符进行同等的转换
****/


void Permutation(char * pStr,char * pBegin){
    if(*pBegin == '\0'){
        cout<<pStr<<endl;
    }else{
        for(char * pCh = pBegin;*pCh != '\0';pCh++){
            ///第一个字符与后面的字符依次交换
            char pTemp = *pBegin;
            *pBegin = *pCh;
            *pCh = pTemp;
            Permutation(pStr,pBegin+1);

            ///注意^^^^^^^^^^^^^^^^^^^^^^^^^^
            ///退出来以后，要将刚才交换的再换回来，以保持不重复
            pTemp = *pBegin;
            *pBegin = *pCh;
            *pCh = pTemp;
        }
    }
}
void Permutation(char * pStr){
    if(pStr == NULL)
        return;
    Permutation(pStr,pStr); ///递归入口，
}

/*******************************
技巧，计算数组中重复数字占数组大一半以上
如果一个数的个数是数组的一般以上则该数计数上大于其他所有数
*****/
bool CheckMoreHalf(int * numbers,int length,int result){
    int times =0;
    for(int i=0;i<length;i++){
        if(numbers[i] == result)
            times++;
    }
    if(times * 2 <= length)
        return false;
    return true;
}
int MoreHalfNum(int * numbers,int length){
    if(numbers == NULL || length <=0 ){
        return 0;
    }
    int result = numbers[0];
    int times =1;
    for(int i =0;i<length;++i){
        if(times == 0){
            result = numbers[i];
            times =1;
        }else if(numbers[i] == result){
            times++;
        }else{
            times--;
        }
    }
    if(!CheckMoreHalf(numbers,length,result))
        return 0;
    return result;
}
/*********************
最小的k个数，解题思路：
1）利用快排的基础结构，进行划分，不过最小k个数是没有编序的
2）使用k长度的最大堆序列存储k个最小数字，这对于大数据适合
****/
#define RandomInRange(s,e) rand() % ((e) - (s)) + (s)
int partition_x(int *data,int length, int start,int ended){
    if(data == NULL || length <=0 || start <0 || ended >= length)
        return 0;
    srand((int)time(NULL));
    int index =RandomInRange(start,ended);
    ///交换数据，将其放到最后位置
    int temp = data[index];
    data[ended] = data[index];
    data[index] = temp;

    int small = start -1;///small用于跟踪不符合元素的索引
    for(index = start;index < ended;index++){
        if(data[index] < data[ended]){
            ++small;
            if(small != index){ //如果不相等，则small指向的是大于ended的，index指向是小于index，则需要交换
                temp = data[index];
                data[index] =data[small];
                data[small] = temp;
            }
        }
    }
    ++small;///最后将分界的元素（位于ended处），与最终small指向的元素进行替换，这样就实现
    ///了，将数组分成开始选择的数据的为分界的数组
    temp = data[ended];
    data[ended] = data[small];
    data[small] = temp;
    return small;//返回分界点的索引
}
void GetLeastNumbers(int * input, int n, int * output,int k){
    if(input == NULL || output==NULL || n<=0 || k > n || k <= 0)
        return;
    int start = 0;
    int endx =n -1;
    int index = Partition(input,n,start,endx);
    while(index != k-1){
        if(index > k-1){ //分界在右，则再分左边的
            endx = index -1;
            index = Partition(input,n,start,endx);
        }else{
            start = index + 1;//分界在左，则分右边的
            index = Partition(input,n,start,endx);
        }
    }
    for(int i =0;i<k;++i){
        output[i] = input[i];
    }
}
///另一个解法通过k个堆O(nlogk)

typedef priority_queue<int,vector<int>,less<int>> intK;


void GetLastNumber(const vector<int> & data,int k){
    if(k < 1 || data.size() < k){
        return;
    }
    intK leastKNumber;
    while(leastKNumber.size() >0)
        leastKNumber.pop();

    ///不能对元素进行修改，则使用const_iterator
    vector<int>::const_iterator iter = data.begin();
    for(;iter != data.end();++iter){
        if(leastKNumber.size() < k){
            leastKNumber.push(*iter);
        }else{
            cout<<"top: "<<leastKNumber.top()<<endl;
            if(leastKNumber.top() > *iter){
                leastKNumber.pop();
                leastKNumber.push(*iter);
            }
        }
    }
    cout<<leastKNumber.size()<<endl;
    for(int i=0;i<k;i++){
        cout<<leastKNumber.top()<<endl;
        leastKNumber.pop();
    }
}
/***
求子串的最大和
注意，要找到一个规律，就是如果子串的累加小于等于0，则串的累加从后一位重新开始
**/
int FindGreatestSumOfSubArray(int *pData,int nLength){
    if(pData == NULL || nLength <=0)
        return 0;
    int nGreatestSum = 0x80000000; //limits.h中的-INF
    int nCurSum =0;
    for(int i=0;i<nLength;i++){
        if(nCurSum <=0){
            nCurSum = pData[i];
        }else{
            nCurSum +=pData[i];
        }
        if(nCurSum > nGreatestSum){
            nGreatestSum = nCurSum;
        }
    }
    return nGreatestSum;
}

/****
计算1->n个数中，1出现的个数，
1）笨的方法
**/
int NumberOf1(unsigned int n){
    int number =0;
    while(n){
        if(n % 10 == 1)
            number++;
        n /= 10;
    }
    return number;
}
int NumberOf1Between1AndN(unsigned int n){
    int sum =0;
    for(int i=1;i<=n;i++){
        sum += NumberOf1(i);
    }
    return sum;
}

/************************
高效的方法：
1）从第一个位算起，如果第一位大于1，则需要计算1,000...->1,999...,则
第一位含1的数有10^(length-1)
2)如果第一位为1，则第一位含1的数目为1后面的数字+1
3）然后不考虑第一位时，后面位的1的个数，注意一个数可能有多个1存在
注意考虑第三种情况的时候的一种思维转换，对于1111，则1出现4次，每一个位置上都存在1，则
我们不这样合起来考虑，因为由此可以看出，每一位中有1都是独立的，则不会重复，尽管1111，被算上出现四次
但是它和1的个数是对应着的，也就是它含有4个1，所以才被计算四次，因此不算重复，注意这一思维坑
要知道每一位中有1都是相互独立的；单算  所以总数length * 10 ^(length -1)
4）否则递归传入后面的数字
最后进行这些的累加
****/

int Base10(int n){
    int sum =1;
    for(int i =0;i<n;i++)
        sum *= 10;
    return sum;
}
int NumberOf1ToN(const char *str){
    if(str == NULL || *str <'0' || *str > '9' || *str == '\0')
        return 0;
    int first = str[0]-'0';
    unsigned int length   = static_cast<unsigned int>(strlen(str));

    if(length ==1 && first>=1){
        return 1;
    }
    if(length == 1 && first == 0){
        return 0;
    }
    ///先计算第一位为·1的，如21345，则此时计算的是10000-19999
    int numFirst =0;
    if(first >1){
        numFirst = Base10(length-1);
    }else if(first == 1){
        numFirst = atoi(str+1) +1; ///后面数字加1
    }
    ///如果第一位不是1，则后面位1出现的次数，计算 1346-21345中后四位的数字，经过折叠为
    ///2个0000-9999的范围计数
    int otherFirst = first * (length -1) * Base10(length -2); ///难点

    ///开始递归计算0-1345的个数
    int RecursiveNum = NumberOf1ToN(str+1);

    return numFirst + otherFirst + RecursiveNum;
}

int NumberOf1AndN(unsigned int n){
    if(n<=0)
        return 0;
    char str[50];
    sprintf(str,"%d",n); ///将n读取为整数字符串
    return NumberOf1ToN(str);
}
/**************************
拼接数组中的数字，使其最小，
要转化为排序问题，比较函数不是比较大小，而是比较两个数谁在前谁在后
nm<mn时，n在前，m在后
拼接后比较字符串大小即可
*****/
const int MaxLength = 10;
char * g_StrNumber1 = new char[MaxLength*2 + 1];
char * g_StrNumber2 = new char[MaxLength * 2 +1];
int comp_str(const void * strNumber1,const void *strNumber2){
    strcpy(g_StrNumber1,*(const char**)strNumber1);
    strcat(g_StrNumber1,*(const char**)strNumber2);

    strcpy(g_StrNumber2,*(const char**)strNumber2);
    strcat(g_StrNumber2,*(const char**)strNumber1);
    return strcmp(g_StrNumber1,g_StrNumber2);
}
void PrintMinNumber(int * numbers,int length){
    if(numbers  == NULL || length <= 0)
        return;
    ///一种是这种转换
    char ** strNumbers = (char **) (new int[length]);
    //vector<char*> strNumbers(length);
    for(int i =0;i<length;i++){
        strNumbers[i] = new char[MaxLength + 1];
        sprintf(strNumbers[i],"%d",numbers[i]);
    }
    qsort(strNumbers,length,sizeof(char*),comp_str);

    for(int i=0;i<length;i++){
        cout<<strNumbers[i];
    }
    cout<<endl;
    for(int i=0;i<length;++i){
        delete []strNumbers[i];
    }
}
/****************
丑数的定义
***/
bool is_choushu(int n){
    while(n % 2 == 0)
        n /=2;
    while(n % 3 ==0)
        n /=3;
    while(n % 5 ==0)
        n /= 5;
    if(n == 1)
        return true;
    else
        return false;
}
int Nth_choushu(int n){
    if(n<1)
        return 0;
    int number=0;
    int ulgyFound=0;
    while(ulgyFound < n){
        ++number;
        if(is_choushu(number))
            ++ulgyFound;
    }
    return number;
}
///分析得到，上面的算法计算了很多非ulgy的数字，
///效率低，所以只需要计算丑数
int GetUglyNumber2(int n){
    if(n<=0)
        return 0;
    int * UglyNum = new int[n];
    UglyNum[0] =1;
    int nextUglyIndex =1;

    int *pMultiply2 =UglyNum;
    int *pMultiply3 =UglyNum;
    int *pMultiply5 =UglyNum;

    while(nextUglyIndex < n){
        int min_x = 0;//Min(*pMultiply2*2,*pMultiply3*3,*pMultiply5*5);
        UglyNum[nextUglyIndex] =min_x;
        ///注意此处的分析，分别取三种情况，且每个对应一种乘法
        while(*pMultiply2*2 <=UglyNum[nextUglyIndex])
            pMultiply2++;
        while(*pMultiply3*3 <=UglyNum[nextUglyIndex])
            pMultiply3++;
        while(*pMultiply5*5 <=UglyNum[nextUglyIndex])
            pMultiply5++;
        ++nextUglyIndex;
    }
    int ugly  = UglyNum[nextUglyIndex - 1];
    delete []UglyNum;
    return ugly;
}
/*****************
第一个不重复的字符，这种考察字符次数的题目可以利用简单哈希表进行辅助统计
因为char类型只有256种可能，也就是字符的ASCII最大256
*****/
char FirstNotRepeatingChar(char * pString){
    if(pString == NULL)
        return '\0';
    const int tablesize =256;
    unsigned int hashtable[tablesize];
    //cout<<sizeof(hashtable)<<endl; 1024
    memset(hashtable,0,sizeof(hashtable));

    char * pKey = pString;
    while(*pKey !='\0'){
        hashtable[*(pKey++)]++;
    }
    pKey = pString;
    while(*pKey != '\0'){
        if(hashtable[*pKey] == 1){
            return *pKey;
        }
        pKey++;
    }
    return '\0';
}
/**************
查询逆序对的数目，使用归并排序的过程
在归并排序的时候统计逆序对数目
***/
int InversePairCore(int *data,int *copy_,int start,int ended){
    if(start == ended){
        copy_[start] = data[start];
        return 0;
    }
    ///然后将数组分成左右两个子数组进行递归操作
    int length = (ended - start) /2;
    ///注意此处，将data和copy进行交换传入，
    ///copy_为未排序的，data为两个排序的子数组组成的，
    ///但data不一定有序，则start->start+length前半段是有序的
    ///start+length -> ended后半段是有序的，然后开始归并连个子序列
    ///在归并过程中统计逆序对的数目
    ///递归的下层对data进行排序归并，所以逆序考察通过data进行计算
    ///而copy有由本次归并产生，所以本次的copy应该是上次的data
    ///所以递归时要data和copy交换位置下传
    int left  = InversePairCore(copy_,data,start,start+length);
    int right = InversePairCore(copy_,data,start+length+1,ended);

    ///当下层递归跳出时，data已经被改变为要归并的模式
    ///前半段最后一个数字下标
    int i = start + length;
    int j =ended;///后半段最后下标
    int indexCopy = ended; ///这个下标用于当data归并时，将数值拷贝到copy辅助数组中
    int count_ = 0;
    while(j>=start && j>=start+length+1){
        if(data[i] > data[j]){
            copy_[indexCopy--] = data[i--];
            count_ +=j - start - length;
        }else{
            copy_[indexCopy--] = data[j--];
        }
    }
    for(;i>=start;)
        copy_[indexCopy--] = data[i--];
    for(;j>=start+length;)
        copy_[indexCopy--] = data[j--];

    return left + right + count_;
}


int InversePairs(int *data,int length){
    if(data == NULL || length <=0)
        return 0;
    int *copy_ = new int[length];
    for(int i=0;i<length;i++)
        copy_[i] = data[i];
    int count_ = InversePairCore(data,copy_,0,length-1);
    delete []copy_;
    return count_;
}
/****************
两个链表公共点，分析得到公共节点后所有节点都相同
1）通过用栈，从后向前查找，等到不相同是，最后一个相同的点为公共节点
2）因为后面公共点后的长度一样，则通过将长的链表先走；
然后在将两个链表同步走，遇到相同的节点位公共节点
****/
int GetLength(ListNode *p){
    if(p == NULL)
        return 0;
    int num=0;
    while(p!=NULL){
        num++;
        p = p->next;
    }
    return num;
}
ListNode * FindFirstCommonNode(ListNode * p1,ListNode *p2){
    if(p1 == NULL || p2 == NULL)
        return NULL;
    unsigned int nLength1 = GetLength(p1);
    unsigned int nLength2 = GetLength(p2);
    int nLengthDif = nLength1 - nLength2;

    ListNode * pLong = p1;
    ListNode * pShort =p2;
    if(nLength2 > nLength1){
        nLengthDif = nLength2- nLength1;
        pLong = p2;
        pShort = p1;
    }
    for(int i=0;i<nLengthDif;i++){
        pLong = pLong->next;
    }
    while((pLong != NULL) && pShort != NULL
          && pLong != pShort){
            pLong = pLong->next;
            pShort = pShort->next;
          }
    return pLong;
}

/****
利用二分查找的方式，将条件变化，能得到k的最左边和最右边的点
然后最右-最左就是该数字的个数，这是升级版的二分查找，学会迁移，
如果二分查找的值为k,左边也为k，则继续向左查找，否则停止，作为最左边的数
***/
int GetFirstK(int * data, int length,int k,int start,int ended){
    if(start >ended)
        return -1;
    int middle = (ended-start) /2;
    int middleData = data[middle];

    if(middleData == k){
        if((middle > 0 && data[middle -1] != k )||
           middle ==0){
            return middle;
        }else{
            ended = middle -1;
        }
    }
    else if(middleData > k){
        ended = middle - 1;
    }else{
        start = middle + 1;
    }
    return GetFirstK(data,length,k,start,ended);
}
int GetLastK(int * data, int length,int k,int start,int ended){
    if(start > ended)
        return -1;
    int middle = (ended-start) /2;
    int middleData = data[middle];

    if(middleData == k){
        if((middle > 0 && data[middle +1] != k )||
           middle ==0){
            return middle;
        }else{
            start = middle -1;
        }
    }
    else if(middleData < k){
        start = middle + 1;
    }else{
        ended = middle - 1;
    }

    return GetFirstK(data,length,k,start,ended);
}

int GetNumberOfK(int *data,int length,int k){
    int number=0;
    if(data != NULL && length > 0){
        int first = GetFirstK(data,length,k,0,length-1);
        int last = GetFirstK(data,length,k,0,length-1);
        if(first > -1 && last > -1){
            number = last -first +1;
        }
    }
    return number;
}

int TreeDepth(BinaryTreeNode * pRoot){
    if(pRoot == NULL){
        return 0;
    }

    int left =TreeDepth(pRoot->m_pLeft);
    int right = TreeDepth(pRoot->m_pRight);

    return left >right?left+1:right+1;
}

/*************
数组中查找只出现一次的数字，题目给出其他出现两次，
可以先到异或的使用，其他重复出现的数字异或为0，
对于只有一个一次出现的数组，异或整个数组元素结果就是只一次的那个数；
而对于两个出现的一次，则需要转化为一个一次出现的情况，则需要将这两个数分开
有因为相同的数，每一位都相同，则异或整个数组后，结果中某一位为1时，通过这个1，
将数组分成两个子数组，则两个子数组通过考察一个一次出现的例子就可以了
*****/
int GetBit1(int num){
    int index=0;
    while(index < 8*sizeof(int) && (num & 1) ==0){
        num = num>>1;
        ++index;
    }
    return index;
}
bool isBit1(int num,unsigned int indexBit){
    num = num>>indexBit;
    return (num & 1);
}
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    if(data.size() <=1)
        return;
    int sum =0;
    for(int i=0;i<data.size();i++){
        sum ^= data[i];
    }
    int index_1 = GetBit1(sum);
    *num1 =0;
    *num2 =0;
    for(int i=0;i<data.size();i++){
        if(isBit1(data[i],index_1)){
            *num1 ^=data[i];

        }else{
            *num2 ^=data[i];
        }
    }
}

/***************
查找两个数和为给定的数，由于数组已经是拍好了的所以用O(n)；
因此我们需要两个指针进行查找
***/




#endif // LEARNING_OFFER_H_INCLUDED
