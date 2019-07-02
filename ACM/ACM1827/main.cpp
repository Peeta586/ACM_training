#include <iostream>
#include<cmath>
/**
蚂蚁走路线问题，最短时间和最长时间
主要考察分析能力，程序很简单，主要分析出规律即可
*/
using namespace std;
#define MAX 1000000

int main()
{
    int num,L,ants;
    //int ants_loc[MAX][2];
    int Min=0,Max=0;
    //输入组数
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>L>>ants;
        int ant;
        for (int j=0;j<ants;j++){
            cin>>ant;
            //最小时间
            Min = max(Min,min(ant,L-ant));
            //最长时间
            Max = max(Max,max(ant,L-ant));
        }
        //ants_loc[i][0]=Min;ants_loc[i][1]=Max;
        cout<<Min<<" "<<Max<<endl;
        Max=Min=0;
    }
/*
    for (int i=0;i<num;i++){
        cout<<ants_loc[i][0]<<" "<<ants_loc[i][1]<<endl;
    }*/
    return 0;
}
