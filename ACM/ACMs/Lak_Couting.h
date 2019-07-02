#ifndef LAKE_H
#include<iostream>
using namespace std;
class Lake_Counting{
    int N,M;
    char *field;//[MAX_N][MAX_N] //水洼矩阵
    int res =0;
    /**思想：深度优先搜索
    将没遇到的水洼，填了（W->.）即可以跳出递归，每次跳出递归就可表示一个水洼
    **/
    void dfs(int x,int y){
        field[x*M+y]='.';

        //循环遍历8个方向
        for(int dx =-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                int nx =x +dx,ny=y+dy;
                if(nx>=0 && nx<N && ny>=0 &&ny<M && field[nx*M+ny]=='W') dfs(nx,ny);
            }
        }
        //循环跳出便是一个水洼搜索完成
        return;
    }
public:
    /*构造函数
    */
    Lake_Counting(char *field,int N,int M){
        this->M = M;
        this->N = N;
        this->field = field;
    }

    /**遍历搜索
    **/
    void solve(){
        for (int i =0;i<N;i++){
            for(int j=0;j<M;j++){
                if(field[i*M+j]=='W'){
                    dfs(i,j);
                    res++;
                }
            }
        }
        cout<<res<<endl;
    }
};

#endif // LAKE_H
