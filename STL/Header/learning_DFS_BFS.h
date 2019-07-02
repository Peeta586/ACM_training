#ifndef LEARNING_DFS_BFS_H_INCLUDED
#define LEARNING_DFS_BFS_H_INCLUDED

#define MAX_N 100
#define MAX_M 100

/******************+++++++++++++++++++++++++++++++++++++
DFS：主要思想是贪心策略，对各种情况进行下层递归
***/
int a[MAX_N];
int n,k;

//从前i项得到了和sum，然后对于i项之后的进行分支
bool DFS(int i,int sum){
    //如果前n项计算过了，则返回sum是否与k相等
    if(i == n) return sum ==k;

    /************************
    分情况进行递归传递
    **/
    //不加a[i]的情况
    if(DFS(i+1,sum)) return true;

    //加上a[i]的情况
    if(DFS(i+1,sum + a[i])) return true;

    return false;
}

/***********************************
实例：深搜遍历
******/

int N,M;
char field[MAX_N][MAX_M+1]; //注意加一

//从x,y开始
void dfs(int x,int y){
    field[x][y] ='.'; //将遍历后的点进行替换
    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){  //也就是开始遍历，新的点，如果满足要求，那么就下步递归
            //该递归算法实现了对所有满足要求的点的遍历和改变，等没有可改变的点，则退出。
            int nx = x+dx,ny = y+dy;
            if(0<=nx && nx<N &&0<=ny && ny<M && field[nx][ny] == 'W')
                dfs(nx,ny);
        }
    }
    return;
}

void solve(){
    int res =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(field[i][j]== 'W'){
                dfs(i,j);
                res++;
            }
        }
    }
}
/*************************************
POJ 1979:Red Black
***/
///将通过返回值的方式递归
///注意点：
/// field要引用，这样能使得上层函数递归影响下一层递归
int red_black_dfs1(vector<vector<char>> & field,int N,int M,int x,int y){
    int sum =0;
    if(field[x][y]!='#')
        sum +=1;
    field[x][y]='#';

    int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
    for(int i=0;i<4;i++){ //出错，注意只能上下左右，不能斜着
        int nx =x+dir[i][0],ny = y+dir[i][1];
        if(0<=nx && nx<N && 0<=ny && ny < M
        && field[nx][ny] == '.'){
            cout<<nx<<" "<<ny<<" "<<sum<<endl;
            sum +=red_black_dfs1(field,N,M,nx,ny);
        }
    }
    //cout<<"return:"<<sum<<endl;
    return sum;
}
//第二种写法，如果将sum作为引用传递过去
int red_black_dfs2(vector<vector<char>> & field,int N,int M,int x,int y,int &sum){
    field[x][y]='#';
    int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
    for(int i=0;i<4;i++){
        int nx =x+dir[i][0], ny = y+dir[i][1];
        if(0<=nx && nx<N && 0<=ny && ny < M && field[nx][ny] == '.'){
            sum +=1;
            //cout<<sum<<field[nx][ny]<<endl;
            cout<<nx<<" "<<ny<<endl;
            red_black_dfs2(field,N,M,nx,ny,sum);
        }
    }

}

void test_dfs(){
    int N,M;
    vector<vector<char>> field;
    cin>>M>>N;
    for(int i=0;i<N;i++){
        vector<char> cs;
        for(int j=0;j<M;j++){
            char c;
            cin>>c;
            cs.push_back(c);
        }
        field.push_back(cs);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<field[i][j];
        }
        cout<<endl;
    }

    int num=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(field[i][j]=='@'){
                cout<<"i:"<<i<<"j:"<<j<<endl;
                num = red_black_dfs1(field,N,M,i,j);
                break;
            }
        }
    }
    cout<<num<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<field[i][j];
        }
        cout<<endl;
    }
}

/********************++++++++++++++++++++++++++++++++++++++++++++
BFS：利用队列，对邻近点进行递归
***/
const int INF = 100000000;

typedef pair<int,int> P;

char maze[MAX_N][MAX_M];
int N,M;
int sx,sy;
int gx,gy;

int d[MAX_N][MAX_M];///各位置最短距离数组

int dx[4]={1,0,-1,0},dy[4] = {0,1,0,-1};

//求从sx,sy 到 gx,gy最短距离
int bfs(){
    queue<P> que;
    ///1) 把所有位置都初始化INF
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            d[i][j]=INF;

    ///2) 将起点加入到队列中
    que.push(P(sx,sy));
    d[sx][sy]=0;

    ///3）不断循环，直到队列长度为0
    while(que.size()){
        ///4）从队列最前端取元素
        P p = que.front(); que.pop(); ///注意要pop掉
        ///5)判断是否是终点
        if(p.first == gx && p.second == gy) break;

        ///6）如果不是终点则开始变量起点的周围
        for(int i=0;i<4;i++){
            int nx = p.first+dx[i],ny = p.second + dy[i];

            ///7) 判断是否可移动和是否已访问,d[nx][ny] != INF表示访问过
            if(0<=nx && nx<N && 0<=ny && ny <M && maze[nx][ny] != '#'  ///可走
               && d[nx][ny] == INF){ ///且没被访问过
                que.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second] +1;
               }
        }
    }
    return d[gx][gy];
}

/***************************************************
宽度搜索实例：
****/



#endif // LEARNING_DFS_BFS_H_INCLUDED
