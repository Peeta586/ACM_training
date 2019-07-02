//
//  Find_Distinct_Combination.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/28.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Distinct_Combination_h
#define Find_Distinct_Combination_h
/***
 find all distinct combinations of given array.
 找出不同的组合，制定组合长度,recurse_01考虑了重复元素的情况
 注意这种01背包问题的思想使用，考虑或者不考虑，两种情况对应着不同处理
 这种递归思想一定要牢记
 如：{1,2,3} k=2
 output：｛1，2｝，｛1，3｝，｛2，3｝
 ｛1，2，1｝ k＝2
 ｛1，1｝，｛1，2｝
 */
///solution 1:
/**we can use recursion to solve this problem. the idea is to add
 each element into the output and recurse for remaining elements
 with one less element. to avoid printing permutations, each combination
 will be constructed in same order as array elements. if combination
 of given size is found, we print it. Below solution generates all 
 combinations by using above logic by traversing the array from left
 to right. to print only distinct only distinct combinations in
 case input contains repeated elements, we can sort the array and
 exclude all adjacent duplicate elements from the array.

 思想是递归，从左到右选择一个元素后，递归他后面的元素，从中选择k-1个排列， 判断条件是，如果k=0, 则跳出循环，且打印out
 1)　将重复的元素删除
 2）排序，然后依次递归查找
 */
//再i到n之间查找k长度的元素
void recurse(int a[],string out,int i,int n,int k){
    if(k > n)
        return;
    if(k == 0){//
        cout<<out<<endl;
        return;
    }
    
    for(int j = i;j < n; j++){
        if(j != i){ //j !=i 表示如果跳过i则要跳过所有的i
            while (a[j] == a[j - 1])
                j++;
        }
        recurse(a,out + " " + to_string(a[j]),j + 1,n,k - 1);
    }
}
//from right to left, so it don't need the i
void recurse_transpose(int a[],string out,int n,int k){
    if(k > n)
        return;
    if (k == 0){
        cout<<out<<endl;
        return;
    }
    for(int i = n -1;i >= 0;i--){
        recurse_transpose(a,to_string(a[i])+" "+out, i, k - 1);
    }
}
void Find_Distinct_Combination(int a[],int n,int k){
    recurse_transpose(a,"",n,k);
}

//solution 2:
/**this problem is very similar to 0/1 knapsack problem where 
 for each element in given array, we have two cases:
 1)Consider that element
 2)Don't consider that element
 In the solution below, we generate all combinations by using above logic by
 traversing the array from left to right. If combination of given size is found,
 we print it. To avoid printing permutations, each combination will be constructed
 in same order as array elements. To print only distinct combinations
 (when input contains repeated elements), we can sort the array and exclude
 all adjacent duplicate elements from the array along with the current element
 in case 2.
 */

void printVector(vector<int> out){
    for(int i:out)
        cout<<i<<" ";
    cout<<endl;
}
//该函数考虑了重复元素的情况
void recurse_01(int a[],vector<int> & out,int i,int n,int k){
    //base case: combination size is k
    if(k == 0){
        printVector(out);
        return;
    }
    if (i == n)
        return;
//    include current element in the current combination
//    如果考虑该元素的话，就不用跳过其后面的与之重复元素，因为｛1，1，2｝
//    ｛1，1｝也是一种combination，所以被当成不同的元素
//    所以我们只需要注意在不考虑该元素时，避免该元素的其他重复项也不被考虑
    out.push_back(a[i]);
    recurse_01(a, out, i + 1, n, k - 1);
    
//    exclude current element
    out.pop_back();
//    如果不算上这个元素的话，我们就要跳过所有该元素重复的项
//    这样就避免了该元素重复而导致的重复combinations
    while(i + 1 < n && a[i] == a[i + 1])
        i++;
    recurse_01(a, out, i + 1, n, k);
}
void recurse_01_transpose(int arr[], vector<int> &out, int i, int k)
{
    // base case: combination size is k
    if (k == 0) {
        printVector(out);
        return;
    }
    // return if no more elements are left
    if (i < 0)
        return;
    // include current element in the current combination an
    out.push_back(arr[i]);
    recurse_01_transpose(arr, out, i - 1, k - 1);
    // exclude current element in the current combination
    out.pop_back(); // backtrack
    // uncomment below code to handle duplicates
    // while (arr[i] == arr[i-1])
    // i--;
    // exclude current element in the current combination an
    recurse_01_transpose(arr, out, i - 1, k);
}

void Find_Distinct_Combination2(int a[],int n,int k){
    vector<int> out;
    sort(a,a+n);
    recurse_01(a,out,0,n,k);
}


#endif /* Find_Distinct_Combination_h */
