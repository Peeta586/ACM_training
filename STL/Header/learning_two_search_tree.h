#ifndef LEARNING_TWO_SEARCH_TREE_H_INCLUDED
#define LEARNING_TWO_SEARCH_TREE_H_INCLUDED

/********************************************
二叉搜索树：
性质：左孩子比自己小，右孩子比自己大；
优点：
1）插入和删除数据快，
2）查询是否存在一个数据快

删除数据比较麻烦：
1）如果删除的节点没有左孩子，右孩子提上去
2）如果删除的节点左孩子没有右孩子，左孩子提上去
3）否则，把左孩子的子孙中最大的节点提到需要的删除的节点上。
***/
struct node{
    int data;
    node * lch,* rch;
};

//插入节点
node * insert(node *p, int x){
    if(p==NULL){
        node *p_x = new node;
        p_x->data =x;
        p_x->lch = p_x->rch =NULL;
        return p_x;
    }else{
        if(p->data > x)
            p->lch = insert(p->lch,x); //左孩子遍历
        else
            p->rch = insert(p->rch,x); //右孩子遍历
        return p;
    }
}

bool find(node *p, int x){
    /****
    非递归模式

    node * head =p;
    while(head){
        if(head->data ==x){
            return true;
        }else if(head->data > x){
            head = head->lch;
        }else{
            head = head->rch;
        }
    }
    return false;
    ***/
    if(p==NULL) return false;
    else if (p->data ==x) return true;
    else if(p->data > x) return find(p->lch,x);
    else return find(p->rch,x);
}

node * remove(node *p,int x){
    if(p == NULL) return NULL;
    else if(x < p->data) p->lch = remove(p->lch,x);
    else if(x > p->data) p->rch = remove(p->rch,x);
    else if(p->lch == NULL){
        node *q_rch = p->rch;
        delete p;
        return q_rch;
    }else if(p->lch->rch ==NULL){
        node * q_lch = p->lch;
        delete p;
        return q_lch;
    }else{ //左孩子最大的节点是其最后一个右子孙
        node *q;
        for(q = p->lch; q->rch->rch != NULL; q= q->rch);
        node *r = q->rch;
        q->rch = r->lch;
        r->lch = p->lch;
        r->rch = p->rch;
        delete p;
        return r;
    }
    return p;
}

/*********************************************************************************
例子：
Description
To avoid unsightly burns while tanning, each of the C (1 ≤ C ≤ 2500) cows must cover her hide
with sunscreen when they're at the beach. Cow i has a minimum and maximum SPF rating
(1 ≤ minSPFi ≤ 1,000; minSPFi ≤ maxSPFi ≤ 1,000) that will work. If the SPF rating is too low,
 the cow suffers sunburn; if the SPF rating is too high, the cow doesn't tan at all........
The cows have a picnic basket with L (1 ≤ L ≤ 2500) bottles of sunscreen lotion, each bottle
i with an SPF rating SPFi (1 ≤ SPFi ≤ 1,000). Lotion bottle i can cover coveri cows with lotion. A cow may lotion from only one bottle.

What is the maximum number of cows that can protect themselves while tanning given the
available lotions?

Input
* Line 1: Two space-separated integers: C and L
* Lines 2..C+1: Line i describes cow i's lotion requires with two integers: minSPFi and maxSPFi
* Lines C+2..C+L+1: Line i+C+1 describes a sunscreen lotion bottle i with space-separated integers: SPFi and coveri

Output
A single line with an integer that is the maximum number of cows that can be protected while tanning

Sample Input
3 2
3 10
2 5
1 5
6 2
4 1
Sample Output
2
****/



#endif // LEARNING_TWO_SEARCH_TREE_H_INCLUDED
