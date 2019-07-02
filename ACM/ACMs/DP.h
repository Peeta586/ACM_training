#ifndef DP_H
#include <math.h>

///******01背包问题求解
/**
1) 记忆化搜索DP方式
*/
//动态规划
int dp[MAX_N+1][MAX_M+1];
//i表示第几个物品，其中前面的已经选择过了
//j表示从i选择开始，最大不超过的重量j
int rec(int i,int j){
    if (dp[i][j]>=0){
        return dp[i][j];
    }
    if(i == n){
        res = 0;
    }else if(j<w[i]){
        res = rec(i+1,j);
    }else{
        res= max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
    }

    return dp[i][j]=res;
}

/**
2) 递推公式方法DP方式，逆向，正向  **/

/**
a)逆向，i表示从i开始选择，j表示不超过的重量
    dp[n][j] =0，从n开始选择，都为0，因为最大编号为n-1
    dp[i][j]=
        I) dp[i+1][j]   j<w[i],表示i不被选择，则它的情况和从i+1开始选择时一样的
        II) max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]) (从i+1开始选择时，算上i的话，则i+1只需要重量不超过j-w[i])
*/
void rec(){
    for(int i=N-1;i>=0,i--){
        for(int j=0;j<=W;i++){
            if(j<w[i]){
                dp[i][j]=dp[i+1][j];
            }else{
                dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[0][W]<<endl;
}
/**
a)正向，i表示从0到i这i+1个物品中选择，j表示不超过的重量
    dp[0][j] =0，从0选择，都为0，没的选
    dp[i+1][j]=    注意，dp[i+1]中的i+1对应着的重量是w[i],即dp数组中的i表示第i个，
        I) dp[i][j]   j<w[i],表示第i+1个不被选择，则它的情况和从前i个选择情况时一样的
        II) max(dp[i][j],dp[i][j-w[i]]+v[i]) d[i][j]表示0到第i-1个商品被选择小于j的情况
*/
void rec(){
    for(int i=0;i<N;i++){
        for(int j=0;j<=W;j++){
            if(j<w[i]){
                dp[i+1][j]=dp[i][j];
            }else{
                dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
            }
        }
    }
    cout<<d[n][w]<<endl;
}

/**
3) 状态转移DP方式
从“前i个物品中选取总重量不超过j时的状态”
向
“前 i+1 个物品中选取总重量不超过j” 和 “前i+1个物品中选择总重量不超过j+w[i]时的状态”
的转移
*/
void rec(){
    for(int i=0;i<N;i++){
        for(int j=0;j<=W;j++){
            dp[i+1][j] = max(dp[i+1][j],d[i][j]);
            if(j+w[i]<=W){
                dp[i+1][j+w[i]] = max(dp[i+1][j+w[i],dp[i][j]+v[i]);
            }
        }
    }
    cout<<dp[n][W]<<endl;
}



#endif // DP_H
