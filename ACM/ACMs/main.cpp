#include<iostream>
#include<cstdio>
#include "Partial_Sums.h"
//#define MAX_N 20

#include "Lak_Couting.h"
//#define MAX_N 100
//#define MAX_M 100

#include "Mazes.h"
#include "Best_Cost_Line.h"

#define MAX_N 2000

using namespace std;

int test(int m,int n){
    return n=m;
}

int main()
{
    /**
    Test partial sum

    int n=4,k=13;
    int a[MAX_N]={1,2,4,7};

    Partial_sums ps(a,n,k);
    if (ps.dfs(0,0))
        cout<<"Yes!"<<endl;
    else
        cout<<"No!"<<endl;
    **/

    /**\
    Test Lake Counting

    int N=10,M=12;
    char field[N][M];
    for (int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>field[i][j];
        }
    }

    //二维数组传参，声明[][],传参时，强制转化为char*
    Lake_Counting lc((char*)field,N,M);
    lc.solve();
    **/

    /**
    Test Mazes

    int maze[5][5];
    int N=5,M=5;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++) cin>>maze[i][j];
    Maze mz((int *)maze,N,M);
    mz.bfs();*/

    /***
    Test Best Cow Line

    int N;
    char S[MAX_N+1];
    cin>>N;
    for(int i =0;i<N;){
        char c = getchar();
        if (c != '\n'){
            S[i++]=c;
        }
    }
    Best_Cow_Line bcl((char *)S,N);
    bcl.solve();*/
    int m=2,n;
    cout<<test(m,n)<<endl;

    return n=m;
}

