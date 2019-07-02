#ifndef HEAP_H
int heap[MAX_N], sz =0;
void push(int x ){
    //自己节点的编号
    int i = sz++;
    while(i>0){
        //父亲节点的编号
        int p = (i - 1) / 2;

        //如果已经没有大小颠倒就退出
        if(heap[p] <= x) break;

        //把父亲节点的数值放下来，而把自己提上去
        heap[i]=heap[p];
        i = p;
    }
    heap[i] =x;
}

void pop(){
    //最小值
    int ret = heap[0];

    //要提到根的数值，最后面的一个值
    int x = heap[--sz];

    //从根开始往下走
    int i =0;
    while(i * 2 + 1 < sz){
        int a = i*2 +1,b = i * 2 +2;
        if (b < sz &&　heap[b]<heap[a]) a = b;

        //如果没有大小颠倒则退出
        if(heap[a] >= x) break;
        //把儿子提上去
        heap[i] =heap[a];
        i= a;
    }
    heap[i] = x;

    return ret;
}


#endif // HEAP_H
