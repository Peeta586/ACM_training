//
//  Find_Distinct_Comb_Repeat.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/28.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Distinct_Comb_Repeat_h
#define Find_Distinct_Comb_Repeat_h
/***考虑了元素相等的情况
 Find all disctinct combinations of given length with repetition
 allowed.
 {1,2,3} -> {1,1},{1,2},{1,3},{2,2},{2,3},{3,3}
 {1,2,1} -> {1,1},{1,2},{2,2}
 We can use recursion to solve this problem. The idea is to add each element
 of the array in the output starting from last element considered and recurse
 for remaining elements. To avoid printing permutations, each combination
 will be constructed in same order as array elements. If combination of given
 size is found, we print it.
 */

void recurse(int a[],vector<int> & out,int k,int i,int n){
    if(out.size() == k){
        printVector(out);
        return;
    }
    for(int j = i;j < n;j++){
        out.push_back(a[j]);
        recurse(a,out,k,j,n);
        out.pop_back();
        // 避免重复元素
        while(a[j] == a[j + 1])
            j++;
    }
}
void Find_Distinct_Comb_Repeat(int a[],int n,int k){
    sort(a,a+n);
    vector<int> out;
    recurse(a,out,k,0,n);
}





#endif /* Find_Distinct_Comb_Repeat_h */
