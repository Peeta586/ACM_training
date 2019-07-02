#ifndef LEARNING_TRAVERSE_TREE_H_INCLUDED
#define LEARNING_TRAVERSE_TREE_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
/******************************
遍历树，先序，后续，中序
1)递归方式
2)非递归方式
所有的递归都可以用stack的方式进行模拟类的调用，从而转化为非递归模式
***/
struct Node{
    int data;
    Node *left,*right;
};
Node * insert(Node *p, int x){
    if(p==NULL){
        Node *p_x = new Node;
        p_x->data =x;
        p_x->left = p_x->right =NULL;
        return p_x;
    }else{
        if(p->data > x)
            p->left = insert(p->left,x); //左孩子遍历
        else
            p->right = insert(p->right,x); //右孩子遍历
        return p;
    }
}

///1) 先序*******************************************
void preOrderRecur(Node *head){
    if(head ==NULL){
        return;
    }
    cout<<head->data<<endl;
    preOrderRecur(head->left);
    preOrderRecur(head->right);
}
///非递归方式
/*******
利用stack栈，来压如两个孩子，然后每弹出一个节点读取后就压如该节点的孩子
**/

void preOrderUnRecur(Node *head){
    if(head == NULL) return;

    stack<Node *> stk_node;
    stk_node.push(head);
    while(!stk_node.empty()){
        Node * p = stk_node.top(); stk_node.pop();
        cout<<p->data<<endl;
        ///由于stack是先进后出，则先压入right节点
        if(p->right != NULL) stk_node.push(p->right);
        if(p->left !=NULL) stk_node.push(p->left);
    }
}

///2)中序遍历*****************************************
void inOrderRecur(Node *head){
    if(head == NULL){
        return;
    }
    inOrderRecur(head->left);
    cout<<head->data<<endl;
    inOrderRecur(head->right);
}
///非递归方式
/*******/

void inOrderUnRecur(Node * head){
    if(head == NULL) return;

    stack<Node*> stk_node;
    //stk_node.push(head); 循环中包含head的插入
    Node *p = head;
    while(!stk_node.empty() || p != NULL){
        if(p!=NULL){
            stk_node.push(p);
            p = p->left;
        }else{
            p = stk_node.top();stk_node.pop();
            cout<<p->data<<endl;
            p = p->right;
        }
    }
}

///3）后续遍历*****************************************
void posOrderRecur(Node *head){
    if(head ==NULL){
        return;
    }
    posOrderRecur(head->left);
    posOrderRecur(head->right);
    cout<<head->data<<endl;
}

///非递归方式
/******
用两个stack来实现，将一个stack的值放到另一个stack，然后在输出
注意：stack具有将序列调反的所用，这种特性要懂得活用
*/
void posOrderUnRecur(Node *head){
    if(head ==NULL) return;

    stack<Node *> stk_node1,stk_node2;
    stk_node1.push(head);
    while(!stk_node1.empty()){
        Node *p = stk_node1.top(); stk_node1.pop();
        if(p->left != NULL) stk_node1.push(p->left);
        if(p->right != NULL) stk_node1.push(p->right);
        stk_node2.push(p);
    }
    while(!stk_node2.empty()){
        cout<<stk_node2.top()->data<<endl;
        stk_node2.pop();
    }
}

///——————————————————————————————
///生成测试数据
void test_data(){
    Node *head=NULL;
    for(int i=0;i<10;i++){
        int num  =rand() %10;
        cout<<num<<endl;
        head = insert(head,num);
    }
    cout<<"先序----------"<<endl;
    preOrderRecur(head);
    cout<<"*************"<<endl;
    preOrderUnRecur(head);
    cout<<"中序----------"<<endl;
    inOrderRecur(head);
    cout<<"****************"<<endl;
    inOrderUnRecur(head);
    cout<<"后序----------"<<endl;
    posOrderRecur(head);
    cout<<"****************"<<endl;
    posOrderUnRecur(head);
}



#endif // LEARNING_TRAVERSE_TREE_H_INCLUDED
