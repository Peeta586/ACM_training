//
//  Find_Duplicated.h
//  BeautyOfProgramming
//  (五）
//  Created by hyx on 17/10/20.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Duplicated_h
#define Find_Duplicated_h


#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>


using namespace std;

/***Find a dulplicate element in a limited range array
 Given a limited range array of size n  where array contains elments between 1 to n-1 with one element repeating, find the duplicate number in it.
 注意题目给出了：n个元素中有1->n-1的数，和一个重复的数，组成
*/
///Solutioin 1: auxiliary n-array to memory if it is visited
//time :O(n), space:O(n)
int Find_Duplicated(int a[],int n){
    bool visited[n];
    fill(visited,visited + n,0);
    
    for(int i = 0;i < n;i++){
        if(visited[a[i]])
           return a[i];
        
        visited[a[i]] = true;
    }
    return -1;
}

/*
 Solution 2:将元素本身进行标记，也就是将元素，因为元素没有超过数组下标，切含有的元素数和下标有一一对应关系，
 所以我们可使用元素映射成下标，对下标的元素进行正负调转，则重复的元素，下标对应的元素位置相同，且被重复调转两次，冷然为正
 */
int Find_Duplicated2(int a[],int n){
    int duplicate = -1;
    
    for(int i = 0;i < n;i++){
        int absval = (a[i] < 0)? -a[i]:a[i];//该元素的值可能被反转过，所以取绝对值
        
        if(a[absval - 1] >= 0){
            a[absval - 1] = -a[absval - 1];
        }else{
            duplicate = absval;
            break;
        }
    }
    for(int i = 0;i < n;i++){
        if(a[i] < 0){
            a[i] = -a[i];
        }
    }
    return duplicate;
}

/*********
solution 3:
 用异或性质求解；我们知道元素是1..n-1,且有一个重复的，
 则1..n-1 xor 1..n-1, 则一定为0，再异或重复的元素，为该元素
 *****/
int Find_Duplicated3(int a[],int n){
    int XOR = 0;
    
    for(int i = 0;i < n;i++){
        XOR ^= a[i];
    }
    for(int i = 1;i <= n - 1;i++){
        XOR ^= i;
    }
    return XOR;
}

/*****solution 4: 我们知道元素是1..n-1,且有一个重复，则我们将数组的和减去1..n-1的和
 Finally,
 ****/
template <typename T>
int Find_Duplicated4(T start,T finish){
    auto size = distance(start,finish);
    
    int actual_sum = accumulate(start,finish,0);
    int expected_sum = size * (size - 1) / 2;
    
    return actual_sum - expected_sum;
}



#endif /* Find_Duplicated_h */
