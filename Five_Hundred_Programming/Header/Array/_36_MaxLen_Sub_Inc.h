//
//  MaxLen_Sub_Inc.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/11/4.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef MaxLen_Sub_Inc_h
#define MaxLen_Sub_Inc_h

/*查找最长增序的子序列，每个元素不一定连续
 Longest Increasing Subsequence
 The longest increasing subsequence problem is to find a subsequence of a 
 given sequence in which the subsequence’s elements are in sorted order, lowest to highest,
 and in which the subsequence is as long as possible.
 This subsequence is not necessarily contiguous, or unique.
 For example, consider subsequence {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}
 The Longest increasing subsequence is {0, 2, 6, 9, 11, 15}
 This subsequence has length 6; the input sequence has no 7-member increasing subsequences. 
 The longest increasing subsequence in this example is not unique: for instance,
 {0, 4, 6, 9, 11, 15} or
 {0, 4, 6, 9, 13, 15}
 are other increasing subsequences of equal length in the same input sequence.
 **/
/*
 We have already discussed a O(n2) time complexity solution of LIS here 
 which uses Dynamic Programming. In this post, a O(nlogn)
 time Non-DP solution is discussed.
 Let S[i] be defined as the smallest integer that ends an increasing sequence of length i. 
 Now iterate through every integer X of the input set and do the following:
 If X is more than the last element in S, then append X to the end of S. 
 This essentially means we have found a new largest LIS.
 Otherwise find the smallest element in S, which is more than or equal to X, 
 and replace it with X. Because S is sorted at any time, the element can be found
 using binary search in log(N) time.
 Let’s illustrate this with the help of a example. Consider below array of integers –
 {2, 6, 3, 4, 1, 2, 9, 5, 8}
 Below are the steps followed by the algorithm –
 
 Initialize to an empty set S = {}
 Inserting 2 —- S = {2} – New largest LIS
 Inserting 6 —- S = {2, 6} – New largest LIS
 Inserting 3 —- S = {2, 3} – Replaced 6 with 3
 Inserting 4 —- S = {2, 3, 4} – New largest LIS
 Inserting 1 —- S = {1, 3, 4} – Replaced 2 with 1
 Inserting 2 —- S = {1, 2, 4} – Replaced 3 with 2
 Inserting 9 —- S = {1, 2, 4, 9} – New largest LIS
 Inserting 5 —- S = {1, 2, 4, 5} – Replaced 9 with 5
 Inserting 8 —- S = {1, 2, 4, 5, 8} – New largest LIS
 So, the length of the LIS is 5 (the size of S). Please note that here S[i] is defined as the smallest integer that ends an increasing sequence of length i. Therefore, S does not represent an actual 
 sequence but the size of S represents the length of the LIS.
 Below solution uses std::set which is implemented as a red-black binary search tree which has a worst-case time complexity of O(logn) for insertion.
 注意：这个算法只是计算了长度，实际的元素不是最大增长子序列
 **/
#include <set>
using namespace std;

int MaxLen_Sub_Inc(int a[],int n){
    set<int> S;
//    set的使用技巧，删除比当前元素大的最小值元素
    for(int i = 0;i < n;i++){
//        insertion current element into the set
        auto ret = S.insert(a[i]);
        
        set<int>::iterator it;
        
        if(ret.second){
            it = ret.first;
        }
//        注意set添加时按照增序添加的，如果插入的元素不是最后的元素
//        则删除它最后的元素
        if(++it != S.end()){ //it已经加一
            S.erase(it);
        }
    }
    return S.size();
}

/***
 How to print LIS?
 To make things simpler, we can keep in the S, not the actual integers, but their indices in the set. 
 That is we do not keep {1, 2, 4, 5, 8}, but keep {4, 5, 3, 7, 8} since arr[4] = 1, arr[5] = 2,
 arr[3] = 4, arr[7] = 5 and arr[8] = 8.
 To reconstruct the actual LIS we have to use a parent array. Let parent[i] be the predecessor of element with index i in the LIS ending at element with index i. If we update properly the parent array, the actual LIS is:
 arr[S[lastElementOfS]],
 arr[parent[S[lastElementOfS]]],
 arr[parent[parent[S[lastElementOfS]]]],
 …………………………………
 Below solution stores both actual integers and their indices in the set for easier implementation –
 相当于用并查集纪录替换索引的值，然后追溯出真正的增序序列
 **/
struct Node
{
    int elem;
    int index;
};

// overload compare operator for inserting into set
inline bool operator<(const Node& lhs, const Node& rhs)
{
    return lhs.elem < rhs.elem;
}

// Function to print LIS using parent array
void print(int input[], auto parent, set<Node> S)
{
    // container to store LIS in reverse order
    stack<int> lis;
    
    // start from the last element of S
    int index = S.rbegin()->index;
    
    // get length of LIS
    int n = S.size();
    
    // retrieve LIS from parent array
    while (n--)
    {
        lis.push(input[index]);
        index = parent[index];
    }
    
    // print LIS
    cout << "LIS is ";
    while(!lis.empty())
    {
        cout << lis.top() << " ";
        lis.pop();
    }
}

// Function to find Longest Increasing Subsequence in given array
void printLIS(int arr[], int n)
{
    // create an empty ordered set S (ith element in S is defined as the
    // smallest integer that ends an increasing sequence of length i)
    set<Node> S;
    
    // parent[i] will store the predecessor of element with index i in the
    // LIS ending at element with index i
    map<int, int> parent;
    
    // process every element one by one
    for (int i = 0; i < n; i++)
    {
        // construct node from current element and its index
        Node curr = {arr[i], i};
        
        // insert current node into the set and get iterator to the
        // inserted node
        auto it = S.insert(curr).first;
        
        // if the node is not inserted at the end, then delete the next node
        if (++it != S.end())
            S.erase(it);
        
        // get iterator to the current node and update parent
//        重新查找it，因为插入数据，使的set变化
        it = S.find(curr);
        parent[i] = (--it)->index;
    }
    
    // print LIS using parent map
    print(arr, parent, S);
}



#endif /* MaxLen_Sub_Inc_h */
