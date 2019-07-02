#ifndef LEARNING_MINIMUM_PATH_H_INCLUDED
#define LEARNING_MINIMUM_PATH_H_INCLUDED

#include <algorithm>
#include <queue>
using namespace std;

/*********************************************
最小路径计算：
Bellman-Ford算法：
*****/
#define MAX_E 100
#define MAX_V 100
#define MAX_N 100
#define INF 100000000

struct edge{int from,to,cost;};

edge es[MAX_E];
int d[MAX_N];///表示s点到任一点最短的距离
int V,E;

void shortest_path(int s){
    for(int i=0;i<V;i++) d[i] = INF;
    d[s] = 0; ///s

    while(true){
        bool update = false; ///用于判断退出，当没有任何更新的时候退出
        for(int i=0;i<E;i++){
            edge e = es[i];///当前结点
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){///判断是否为新的点，
                d[e.to] = d[e.from] + e.cost;///并且去向的顶距离大于该顶点带来的距离，则更行新的距离
                update = true;
            }
        }
        if(!update) break;
    } ///可以用该算法检查是否存在负圈
}

bool find_negative_loop(){
    memset(d,0,sizeof(d));///初始化为0，区别于上面的算法

    for(int i=0;i<V;i++){
        for(int j=0;j<E;j++){
            edge e = es[j];
            if(d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;

                //如果第n次仍然更新，则存在负圈
                if(i == V-1) return true;
            }
        }
    }
    return false;
}

/**********************************
Dijkstra:
1)找到最短距离已经确定的顶点，从它出发更新相邻顶点的最短距离
2）此后不需要再关心1中的“最短距离已经确定的顶点”
注意该算法只是单源最短路径问题，
也就是单个源数据到每个点的最短距离，没有路劲考察
**/

int cost[MAX_V][MAX_V];
///int d[MAX_V]; ///顶点s出发的最短距离
bool used[MAX_V];
///int V;

void disjkstra(int s){
    fill(d,d+V,INF);
    fill(used,used + V,false);
    d[s] = 0;

    while(true){
        int v =-1;
        for(int u=0;u<V;u++){
            if(!used[u] &&(v == -1 || d[u] < d[v])) v =u; ///找出最短距离的点，且没有没访问过的
        }///当访问到最新的点，后开始比较最新点与后面点到原点的距离，选小的保留
        if(v == -1) break;
        used[v] =true;  ///v为最短距离的顶点

        for(int u=0;u<V;u++){///将最短距离的顶点，周围点进行更新
            d[u] = min(d[u],d[v] + cost[v][u]);
        }
    }
}

/**********************************
由于遍历边的时候要不断从点集中找出最小距离点，则可以用
最小堆来实现
***/
typedef pair<int,int> P; ///first最短距离，second顶点的编号

///int V;
vector<edge> G[MAX_V];
//int d[MAX_V];  //s到每个顶点的最小边

int pre[MAX_V];///记录最短路径的，记录顶点坐标的前一个顶点

void dijkstra_dui(int s){
    priority_queue<P,vector<P>,greater<P>> que;///中间的vector定义是，表示堆用vector数组来存储
    fill(d,d+V,INF);
    fill(pre,pre+V,-1);
    d[s] =0;
    que.push(P(0,s)); ///pair类型直接用带参声明即可

    while(!que.empty()){///其实这种过程和宽度搜索差不多
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v]<p.first) continue;///避免后面已经更新了d[v]的值，使其变得更小了
        for(int i=0;i<G[v].size();i++){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){ ///更新最短距离点的邻居
                d[e.to] = d[v] + e.cost;
                pre[e.to] = v;  ///每次更新最短路径是，记录被更新节点的最前节点
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
void get_path(int t){
    vector<int> path;
    ///注意这种写法
    for(; t!=-1;t =pre[t]) path.push_back(t); ///不断沿着prev[t]走直到t=s
    reverse(path.begin(),path.end());

    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
    //return path;
}


void create_graph(){
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int from,to,cost;
        cin>>from>>to>>cost;
        G[from].push_back((edge){from,to,cost});
        G[to].push_back((edge){to,from,cost});
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<G[i].size();j++){
            cout<<G[i][j].from<<" "<<G[i][j].to<<" "<<G[i][j].cost<<endl;
        }
    }
    dijkstra_dui(0);
    get_path(6);
}
/****
7 10
0 1 2
0 2 5
1 2 4
2 4 2
1 4 6
1 3 10
4 5 1
3 5 3
5 6 9
3 6 5
**/

/**********************************

****/







#endif // LEARNING_MINIMUM_PATH_H_INCLUDED
