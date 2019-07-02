#ifndef MAZE_H
#include <iostream>
#include<queue>
#include<utility>

using namespace std;
typedef pair<int,int> P;
int INF=100000000;

class Maze{
private:
    int *maze;//迷宫矩阵
    int N,M;//迷宫行列
public:
    Maze(int *maze,int N,int M){
        this->maze =maze;
        this->N=N;
        this->M=M;
    }
    void bfs(){
        int *d = new int[N*M];
        queue<P> que;
        int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++) d[i*M+j]=INF;
        //初始化初始点
        que.push(P(N-1,M-1));
        d[N*M-1]=0;
        //res.push(P(0,0));

        while(que.size()){
            P p=que.front();que.pop();
            //如果已到达终点，就break
            if (p.first == 0 && p.second == 0) break;

            for(int i=0;i<4;i++){
                int nx=p.first+dx[i],ny=p.second+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<M && maze[nx*M+ny]==0
                   && d[nx*M+ny]==INF){  //注意下面两行在一个if中
                        que.push(P(nx,ny));
                        d[nx*M+ny] = d[p.first*M+p.second]+1;
                   }
            }
        }
        cout<<"("<<0<<","<<0<<")"<<endl;
        int x=0,y=0;
        for(int i=0;i<N+M;i++){
            for(int j=0;j<4;j++){
                int nx=x+dx[j],ny=y+dy[j];
                if(nx>=0 && nx<N && ny>=0 && ny<M && d[nx*M+ny]==d[x*M+y]-1){
                    cout<<"("<<nx<<","<<ny<<")"<<endl;
                    x = nx;y=ny;
                    break;
                }
            }
        }
        delete []d;
        return;
    }
};

#endif // MAZE_H
