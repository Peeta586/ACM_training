//
//  Trapping_Rain_Water_Bar.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/11/4.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Trapping_Rain_Water_Bar_h
#define Trapping_Rain_Water_Bar_h

/***也就是根据这些桩子，找出这些桩子组成的矩形槽能容纳最多的水。
 具体视图看文件夹中的图片Rain-Water-Trapping.png
 Trapping Rain Water within given set of bars
 In trapping rain water problem, we need to find the maximum
 amount of water that can be trapped within given set of bars where
 width of each bar is 1 unit.

 */

/***我们可以观察到，一个bar的水位，跟他左右两边最大bar中最小的一个bar有关
 因此，我们可以找出当前元素左边和右边的最大的bar，然后取较小的减去当前
 bar的高度即可
 The idea is to calculate maximum height bar on the left and right of every
 bar. Then the amount of water that can be stored on top of each bar is equal
 to minimum among maximum bar to the left and right minus height of current
 bar.
 */
int Trapping_Rain_Water_Bar(int bar[],int n){
    int water = 0;
    int left[n - 1];
    left[0] = INT_MIN;
    
    for(int i = 1;i < n - 1;i++){
        //注意比较当前元素的左边，不包含当前元素
        left[i] = max(left[i - 1],bar[i - 1]);
    }
    
    int right = INT_MIN;
//    注意两头的bar不用做计算[1,n-2]
    for(int i = n - 2; i >= 1;i--){
        right = max(bar[i + 1],right);
        if(min(left[i],right) > bar[i]){
            water += min(left[i],right) - bar[i];
        }
    }
    return water;
}



#endif /* Trapping_Rain_Water_Bar_h */
