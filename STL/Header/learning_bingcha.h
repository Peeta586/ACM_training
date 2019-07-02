#ifndef LEARNING_BINGCHA_H_INCLUDED
#define LEARNING_BINGCHA_H_INCLUDED

/********************************
并查集：
特点：下面两个操作比较快
查询两个元素是否同组，合并两个元素所在的组

每个组是一个树，并不是二叉树，可能是多叉树，
沿着树往上走，同一个根为同组元素

为了避免退化：
1)对每个树记录高度
2）如果两颗数的高度rank不同，小的向大的合并，也可以使用路径压缩，
使得每个到父节点的节点直接连接到父节点
**************/
///par[x] ==x 时，表示根节点
#define MAX_N 100

int par[MAX_N];
int rank_x[MAX_N];

//初始化n个元素
void init(int n){
    for(int i=0;i<n;i++){
        par[i] =i;
        rank_x[x]=0;
    }
}

//查询树根
int find_x(int x){
    if(par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);  //注意这种写法，而且会将根节点传到其实查询点
    }
}

///合并x,y的集合
void unite(int x,int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(rank_x(x) < rank_x[y]){
        par[x] = y;
    }else{
        par[y] =x;
        if(rank_x[x] == rank_x[y]) rank_x[x]++; ///如果两个树相同，那么就会使得x的树高加 1
    }
}
bool same(int x ,int y){
    return find_x(x) == find_y(y);
}



#endif // LEARNING_BINGCHA_H_INCLUDED
