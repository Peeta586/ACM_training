#ifndef PERMUTATOIN_STRING_H_
#define PERMUTATOIN_STRING_H_

/**In the post, we will see how to find all permutations of a string
 * containing all distinct characters in C++
 * 
 */
#include <iostream>
#include <algorithm>
using namespace std;


namespace PermuatationString{

string str("ABC");
string res;

/***
 * Approch 1: Using backtracking
 * 
 * we can inplace find all permutationsm: the idea is to swap each of the remaining characters
 * in the string with its first charactor and then find all the permutations of the remaining
 * characters using a recursive call. the base case of the recursion is when the string is left 
 * with only one unprocessed element. Below is the recursion tree for printing all permuatation
 * of string "ABC".
 * 
 */

void permuatation(string str, int i, int n){
  // base condition
  if (i == n - 1){
      cout<< str<<endl;
      return;
  }

  // process each character of the remaining string
  for(int j = i; j < n; j++){
    // swap character at index i with current character
    swap(str[i], str[j]);

    // recur for string [i+1,n]
    permuatation(str, i+1, n);

    // backstack (restore the string to its original state)
    swap(str[i], str[j]);
  }
}

/***
 * Using STL
 * 
 * we can use std::rotate to in-place rotate a string in linear time
 * and recursively permute on the rotated string. below is the recursion
 * tree for printing all permutations of string "ABC"
 * 
 * */

void permuatations2(string str, int n, string res){
  if(n == 1){
      cout<< res + str <<endl;
      return;
  }
  for (int i = 0; i < n; i++){
    // push current character to the output string and recur for the remaining
    // characters
    permuatations2(str.substr(1), n-1, res+str[0]);

    // left rotate the string by 1 unit for next iteration
    // to right rotate the string use reverse iterator
    /**
     * 左旋转,然后第二个位置成为第一个位置,第一个位置成为第三个位置,第三个位置成为第二个位置, 依次类推
     * */
    rotate(str.begin(), str.begin() + 1, str.end());
  }
}



} // namespace PermuatationString




#endif // !PERMUTATOIN_H_

