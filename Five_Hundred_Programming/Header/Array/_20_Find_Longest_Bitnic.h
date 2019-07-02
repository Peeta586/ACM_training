//
//  Find_Longest_Bitnic.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/25.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Longest_Bitnic_h
#define Find_Longest_Bitnic_h

/*****最大子串，先增后减，先升后降，或者只增或者只降
 the longest bitonic subarray problem is to find a subarray of a 
 given sequence in which the subarray's elements are first sorted
 in increasing order,then in decreasing order, and the subarray
 is as long as possible, Strictly ascending or descending subarray
 are also accepted.
 i.e {3,5,8,4,5,9,10,8,5,3,4}
 ourput:{4,5,9,10,8,5,3}
 **/

/****solution 1:
 the idea is to maintain two arrays I[],D[]
 I[i] stores the length of the longest increasing subarray
 ending at a[i]
 D[i] stores the length of the longest decreasing subarray
 starting from a[i]
 finally, the length of longest bitonic subarray is maximum among
 all (I[i] + D[i] - 1)
 time and space : O(n)
 **/

int Find_Longest_Bitnic(int a[], int n){
    int I[n],D[n];
    I[0] = 1;
    for(int i = 1;i < n;i++){
        if(a[i] > a[i - 1]){
            I[i] = I[i - 1] + 1;
        }else{
            I[i] = 1;
        }
    }
    D[n - 1] = 1;
    for(int i = n - 2;i >= 0;i--){
        if(a[i] > a[i + 1]){
            D[i] = D[i + 1] + 1;
        }else{
            D[i] = 1;
        }
    }
    int max_length = 0;
    int start = 0,end = 0;
    for(int i = 0;i < n;i++){
        if((I[i] + D[i] - 1) > max_length){
            max_length = I[i] + D[i] - 1;
            start = i - I[i] + 1;
            end = i + D[i] - 1;
        }
    }
    cout<<'['<<start<<','<<end<<']'<<endl;
    return max_length;
}

/****solution 2:使用两个指针去标注最大bitonic串，如果失效则重新从后计算
we can solve this problem without using extra space, the idea
 is to check for longest bitonic subarray starting at a[i],
 if longest bitonic subarray starting at a[i] ends at a[j]
 the trick is to skip all elements between i and j as longest 
 bitonic subarray starting at a[j], we continue this process
 till end of array is reached and also keep trick of longest
 bitonic subarray found so far.
 **/
void Find_Bitonic(int a[],int n){
    int end_index = 0, max_len = 0;
    int i = 0;
    while(i + 1 < n){
        int len = 1;
        while(i + 1 < n && a[i] < a[i + 1])
        i++,len++;
        while(i + 1 < n && a[i] > a[i + 1])
        i++,len++;
        
        if(len > max_len){
            max_len = len;
            end_index = i;
        }
    }
    cout<<'['<<end_index - max_len + 1<<','<<end_index<<']'<<endl;
}


#endif /* Find_Longest_Bitnic_h */
