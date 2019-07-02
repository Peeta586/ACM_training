//
//  FindMaxProduct.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/22.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef FindMaxProduct_h
#define FindMaxProduct_h

#include <iostream>
#include <limits.h>
using namespace std;
//找出array中乘积最大的两个数
// ｛－10，－3，5，6，2｝
// ｛－10，3｝，｛5，6｝

//方法1:遍历所有情况，找出最大
//方法2：先排序，然后比较最小的两个product和最大的两个product


void FindMaxProduct(int a[],int n){
    
    sort(a,a + n);
    
    if((a[0] * a[1]) > (a[n-1] * a[n - 2])){
        cout<<a[0] * a[1]<<endl;
    }else{
        cout<<a[n - 1] * a[n - 2]<<endl;
    }
    
}

//方法3: 我们用线性time就可以，两次遍历分别找出最大的两个和最小的两个


void FindMaxProduct3(int a[],int n){
    int max1 = a[0],max2 = INT_MIN;
    
    for(int i = 1;i < n;i++){
        if(a[i] > max1){
            max2 = max1;
            max1 = a[i];
        }else if(a[i] > max2){
            max2 = a[i];
        }
    }
    
    int min1 = a[0],min2 = INT_MAX;
    for(int i = 1;i < n;i++){
        if(a[i] < min1){
            max2 = min1;
            min1 = a[i];
        }else if(a[i] < min2){
            min2 = a[i];
        }
    }
    if(max1 * max2 > min1 * min2){
        cout<<max2 * max1;
    }else{
        cout<<min2 * min1;
    }
}


#endif /* FindMaxProduct_h */
