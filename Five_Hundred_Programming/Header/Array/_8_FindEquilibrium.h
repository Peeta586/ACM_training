//
//  FindEquilibrium.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/23.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef FindEquilibrium_h
#define FindEquilibrium_h

/*****找出平衡索引，也就是该索引的左半部分和右半部分和相同
 Find Equilibrium index of an Array
 **/
// Naive solution,遍历每种情况，复杂度为O（n^2）

//一个linear time solution：利用辅助空间，利用left存储当前索引
//的左边数组和，然后再从right到left进行遍历，且累加右边和，当遇到累加
//等于left时，就发现了一个平衡索引

void EquilibriumIndex(int a[],int n){
    //first get left
    int left[n];
    left[0] = 0;
    
    for(int i = 1;i < n;i++){
        left[i] = left[i - 1] + a[i - 1];
    }
    
    int right = 0;
    
    for(int i = n - 1;i >= 0;i--){
        if(right == left[i]){
            cout<<"index:"<<i<<endl;
        }
        right += a[i];
    }
}

//Optimized solution 3
/**先计算总的sum。然后遍历数组，使得total减去a[i],然后累加left，进行判断
 是否相同，这个方式等同于编程之美中的电梯问题的计算。
 
 ＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃总结：：：
 当计算左右各半部分的问题时，我们可以使用着这种先总，然后左累加右用total－左
 的方式
 ＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃＃
 we can avoid using extra space, the idea is to calculate the sum
 of all elements of the array. then we start from the last lement
 to the array and maintain right sub-array sum.
 we can calculate left sub-array sum in constant time by subtracting
 right sub-array sum and current element from total sum.
 */

void EquilibriumIndex2(int a[],int n){
    int total = 0;
    for(int i = 0;i < n;i++){
        total += a[i];
    }
    int left = 0;
    for(int i = 0;i < n;i++){
        total -= a[i];
        if(left == total){
            cout<<"index"<<i<<endl;
        }
        left += a[i];
    }
}


#endif /* FindEquilibrium_h */
