//
//  Find_Max_Profit.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/11/3.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Max_Profit_h
#define Find_Max_Profit_h

/***
 Maximum profit earned by buying and selling shares any number
 of times.
 Given a list containing future prediction of share prices, and maximum
 profit that can be earned by buying and selling shares any
 number of times with constraint that a new transaction can only
 start after previous transaction is complete. i.e. we can only hold at most
 one share at a time.
 For example,
 rate[]: {1, 5, 2, 3, 7, 6, 4, 5}
 Total profit earned is 10
 Buy on day 1 and sell on day 2
 Buy on day 3 and sell on day 5
 Buy on day 7 and sell on day 8
 */
/*solution 1: 也就是找序列中的所有增序子序列。
 The idea is very simple. We traverse the given list of prices and 􀃒nd local minimum
 of every increasing sequence. For example, in the array {1, 5, 2, 3, 7, 6,
 4, 5}, below are three increasing sequences of length 2 or more.
 {1, 5}
 {2, 3, 7}
 {4, 5}
 The local minimum of each sequence is 1, 2 and 4 respectively. We can gain
 maximum profit if we buy the shares at the starting of every increasing sequence
 (local minimum) and sell them at the end of the increasing sequence
 (local maximum).
 */

int Find_Max_Profit(int a[],int n){
    int profit = 0;
    
    int j = 0;
    
    for(int i = 1;i < n;i++){
        if(a[i - 1] > a[i]){
            j = i;
        }
        if(a[i - 1] < a[i] && (i + 1 == n || a[i] > a[i + 1])){
            profit += a[i] - a[j];
            cout<<"Buy on day"<<j<<"and sell on day"
            <<i<<endl;
        }
    }
    return profit;
    
}


#endif /* Find_Max_Profit_h */
