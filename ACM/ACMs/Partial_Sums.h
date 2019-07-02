#ifndef PARTIAL_SUM_H

class Partial_sums{
    int *a;//a[MAX_N];
    int n,k;
public:
    //final static int MAX_N =20;
    Partial_sums(int *a,int n,int k){
        //注意，this是类指针,要用->指向成员变量
        this->a = a;
        this->n = n;
        this->k = k;
    }
    //时间复杂度O(2^2)
    bool dfs(int i, int sum){
        if (i==n) return sum == k;

        //开始计算下一个，分两种情况***********注意递归的这种逻辑关系
        //1）不算上第i个
        if(dfs(i+1,sum)) return true;
        //2）算上第i个
        if(dfs(i+1,sum+a[i])) return true;

        //如果没有和为k的，则返回false
        return false;
    }
};

#endif // PARTICAL_SUM_H
