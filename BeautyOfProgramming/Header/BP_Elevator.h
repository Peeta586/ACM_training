//
//  BP_Elevator.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/14.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef BP_Elevator_h
#define BP_Elevator_h
/*****
 电梯调度问题描述：
 电梯只停到某一层，然后电梯里的人下电梯走到自己的目标层；
 算法的目标是，获得每个人的目标层，然后计算出停止的层，然后使得每个人走的
 楼梯数最小
 ***/
#include <vector>
using namespace std;
int test_elevator(){
    int N,N1,N2,N3;
    ///输入数据
    cin>>N;
    vector<int> nPerson;
    nPerson.push_back(0);
    int num;
    for(int j=1;j<=N;j++){
        cin>>num;
        nPerson.push_back(num);
    }
    int nMinFloor=0,TargetFloor=1;
    int i;
    for(N1=0,N2=nPerson[1],N3=0,i=2;i<=N;i++){
        N3 += nPerson[i];
        nMinFloor += nPerson[i] * (i - 1);//电梯停在第一层，则此时，可以计算出所有员工需要爬的层数
    }
    for(i=2;i<=N;i++){
        if(N1 + N2 < N3){
            TargetFloor = i;
            nMinFloor += (N1 + N2 - N3);//每i+1层停止比i层更少，则计算新的楼层数目
            N1 += N2;
            N2 = nPerson[i];
            N3 -= nPerson[i];
        }else{
            break;
        }
    }
    cout<<TargetFloor<<endl;
    
    return 0;
}



#endif /* BP_Elevator_h */
