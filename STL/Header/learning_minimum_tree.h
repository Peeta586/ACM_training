#ifndef LEARNING_MINIMUM_TREE_H_INCLUDED
#define LEARNING_MINIMUM_TREE_H_INCLUDED

/*************************************************
最小生成树
注意：图的表示方式
邻接矩阵表示和邻接表的表示

而最小生成树是prim用邻接矩阵方式
kruskal用的是边集，没有用邻接矩阵或者邻接表
**/
///**1)首先对图的构建方式有两种：

///1, 邻接矩阵的方式，用vector
vector<int> G[MAX_N]; ///每个元素是vector<int>
///如果边上有属性则
struct edge {int to,cost;};
vector<edge> G[MAX_N];

void test_G(){
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        ///从s向t连边
        int s,t;
        cin>>s>>t;
        G[s].push_back(t);
    }
    /**
    图的操作
    **/
}

///2,邻接表的方式
struct vertex{
    vector<vertex*> edge;
    /*****
    定义一些定点的属性
    **/
};
vertex G[MAX_N];

void test_G1(){
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int s,t;
        cin>>s>>t;
        G[s].edge.push_back(&G[t]);//有向图
        //G[t].edge.push_back(&G[s]);无向图
    }
    /**
    图的操作
    **/
}
/****************************************************************************
prim算法：
先声明一个集合，将该一个起始点最短链接的点加到该集合，
然后不断地重复将该集合到集合外的点最短边的
链接点添加到集合中。
*********/
///首先声明几个重要的变量
#define MAX_V 10

int cost[MAX_V][MAX_V]; ///表明每两个点之间连线代价
int mincost[MAX_V]; ///很关键，表示集合X到集合外的每个点的最小距离，通过选择相对最小的，将新的点添加到X中
bool used[MAX_V]; ///表示X中有哪些点
int V; ///顶点个数

int prim(){
    ///首先将mincost,used初始化
    for(int i=0;i<V;i++){
        mincost[i] =INF;
        used[i] = false;
    }

    mincost[0] =0;
    int res =0;

    while(true){
        int v = -1; //当前点
        //从不属于X集合的顶点中，选取离集合X最近的点添加到X中
        for(int u=0;u<V;u++){
            if(!used[u] && (v==-1 || mincost[u]<mincost[v])) v=u; //将X外面更近的点，赋给当前点
        }
        /*************编程技巧：**
        (v==-1 || mincost[u]<mincost[v])：每次循环，将v=-1,然后会使得第一个符合条件的数记录，
        然后后面的数和第一个数进行对比更新
        **/

        if (v==-1) break;
        used[v] = true; //将当前结点v加到集合X中
        res += mincost[v];
        for(int u=0;u<V;u++){
            mincost[u] = min(mincost[u],cost[v][u]);//更新X集合到每个外部定点的最短距离
        }
    }
    return res;
}


/***************************************************************************
Kruskal算法
需要判断是否会产生圈，这就需要用并查集高效地判断是否属于同一个连通分量
*/
struct edge{int u,v,cost;};

edge es[MAX_N];  //边集的表示方法，结构体数组
int V,E;

bool comp(const edge&e1, const edge &e2){
    return edge.cost<e2.cost;
}

int kruskal(){
    sort(es,es+E,comp);
    init(V);
    int res =0;
    for(int i=0;i<E;i++){
        edge e =es[i];
        if(! same(e.u,e.v)){ //如果不属于同一组，则合并，因为已经从小到大的顺序排了序，
                             //那么从0->E的遍历，肯定得到最小生成树
            unite(e.u,e.v);
            res += e.cost;
        }
    }
}



#endif // LEARNING_MINIMUM_TREE_H_INCLUDED
