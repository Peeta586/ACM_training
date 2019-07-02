//
//  Find_maximum_len_01.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/20.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_maximum_len_01_h
#define Find_maximum_len_01_h
#include <iostream>
#include <unordered_map>
using namespace std;

/********
 Find maximum length sub-array having number of 
 0's and 1's,也就是最长的子串，满足子串中0，1个数相同
 Given an binary array containing 0 and 1, find maximum length sub-array having equal number of 0's and 1's
*******/
//solution 1:遍历这种子串，共O(n^2) 个子串，然后计算子串中0，1是否个数相同，不是就退出，两个循环

//solution 2:将这个问题转化为子串sum的形式，也就是将子串sum ＝0，这样可以利用map形式，实现O(n)，如何转化为sum形式呢，我们可以将0转化为－1，这样，只有子串0，1数目相等才是的sum＝0

void maxLengthSubArr01(int a[],int n){
    unordered_map<int,int> maps;
    
    maps[0] = -1;//sum = s的情况
    
    int len = 0;
    int ending_index = -1;
    int sum = 0;
    for (int i = 0;i < n;i++){
        sum += (a[i]==0)? -1:1;///不用改变原数组，只需要累加的时候判断即可
        
        if(maps.find(sum)== maps.end())
            maps[sum] = i;
        else{
            if(len < i - maps[sum]){
                len = i - maps[sum];
                ending_index = i;
            }
        }
    }
    if(ending_index != -1){
        cout<<ending_index - len + 1<<','<<ending_index<<endl;
    }else{
        cout<<"not found"<<endl;
    }
}



#endif /* Find_maximum_len_01_h */
