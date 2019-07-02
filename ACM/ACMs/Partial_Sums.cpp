#ifdef _PARTIAL_SUM

class Partial_sum{
    static int MAX_N =20;
    int *a;//a[MAX_N];
    int n,k;

    Partial_sum(int *a,int n,int k){
        this.a = a;
        this.n = n;
        this.k = k;
    }
    //时间复杂度O(2^2)
    bool dfs(int i, int sum){
        if (i==n) return sum == k;
        //开始计算下一个，分两种情况
        //1）不算上第i个
        if(dfs(i+1,sum)) return true;
        //2）算上第i个
        if(dfs(i+1,sum+a[i])) return true;

        //如果没有和为k的，则返回false
        return false;
    }
};

#endif // _PARTICAL_SUM
