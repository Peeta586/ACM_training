#ifndef MY_BFS_H
#include <utility>
#include <queue>
const int INF = 100000000;

//坐标点，用pair表示
typedef pair<int,int> P;

/**
对于char类型数组，列多一列
*/
char maze[MAX_N][MAX_M+1];//表示迷宫的字符串的数组
int N,M;
int sx,xy;
int gx,gy;

int d[MAX_N][MAX_M];  //存储各位置到原点最短距离的矩阵数组

//上下左右，直角走动，
//不同于深度搜索水洼的8个方向的-1到1的双循环结构。
int dx[4]={1,0,-1,0},dy={0,1,0,-1} //右，上，左，下

/***
宽度优先搜索
*/
int bfs(){
    //队列，存储要访问的点
    queue<P> que;

    //初始化原始距离矩阵
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) d[i][j]=INF;

    //将起点加入队列并把这一地点的距离设置为0
    que.push(P(sx,sy));
    d[sx][sy]=0;

    while(que.size()){
        //从队列中取数据
        P p = que.front();que.pop();
        //如果已到达终点，就break
        if (p.first == gx && p.second == gy) break;

        for(int i=0;i<4;i++){
            //四周搜索
            int nx=p.first +dx[i],ny = p.second +dy[i];
            //要满足所有条件
            if(nx>=0 && nx<N && ny>=0 && ny<M && maze[nx][ny]!='#'
               && d[nx][ny] == INF){
                //可以移动的话，将该点添加到队列中去
                que.push(P(nx,xy));
                d[nx][ny] = d[p.first][p.second] +1;
               }
        }
    }
    return d[gx][gy];
}

void solve(){
    int res =bfs();
}


#endif // BFS_H
