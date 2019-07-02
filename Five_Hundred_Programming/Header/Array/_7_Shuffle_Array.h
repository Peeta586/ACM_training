//
//  Shuffle_Array.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/22.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Shuffle_Array_h
#define Shuffle_Array_h

/***
 Shuffle a given array of elements(Fisher-Yates shuffle)
 Given an array of integers, in-place shuffle it. The 
 should produce an unbiased permutation.
 every permutation is equally likely.
 Fisher-Yates shuffle:
 对于第二个元素选择的概率，是第一次没被选择到 (n - 1) /n
 第二次被选到 1 / (n - 1)  ,相乘还是1/ n的概率
 To shuffle an array a of n elements:
 for i from n -1 downto 1 do
    j = random integer such that 0<=j<=i
 exchange a[j] and a[i]
 */
using namespace std;


void shuffle(int a[],int n){
    for(int i = n - 1;i >= 1;i--){
        int j = rand() % (i + 1);
        swap(a[j],a[i]);
    }
}
// 一个相反的遍历，是index 从0开始，然后随机选择i到n之间的数进行替换

// modify the code to generate random cyclic permutatin
//of length n insted of random permutations
//Sattolo's algorithm




#endif /* Shuffle_Array_h */
