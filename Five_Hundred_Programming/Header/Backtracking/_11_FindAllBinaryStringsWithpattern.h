#ifndef FINDALLBINARYIWTTHPATTERN_H_
#define FINDALLBINARYIWTTHPATTERN_H_


/**
 * Given a binary pattern that contains '?' wildcard character at few positions, find all possible
 * combinations of binary strings that can be formed by replacing the wildcard character by either 0 or1
 *  也就是给出一些二进制字符串, 其中有些通配符,'?'. 这些通配符能被0,1代替; 问被替代成0,1后,打印所有情况
 * 
 * 
 * Recursive solution:
 * we can easily solve this problem using recursion. the idea is to process each character of the pattern
 * one by one and recur for the remaining pattern. if the current digit is 0 or 1. we ignore it and if the 
 * current character is a wildcard character '?' we replace it with 0& 1 and recur for the remaining
 * pattern
 * 
 * */

// C language


#include <stdio.h>

namespace printAllcombination{


char pattern[] = "1?11?00?1?";

void printAllcombinations(char pattern[], int i){
    if(pattern[i] == '\0'){
        printf("%s\n", pattern);
        return;
    }

    if(pattern[i] == '?'){
        for(int k = 0l; k < 2; k++){
            pattern[i] = k + '0';
            printAllcombinations(pattern, i+1);
            pattern[i] = '?';
        }
        return;
    }
    // if current character is 0,1; ignore it
    printAllcombinations(pattern, i+1);
}
} // namespace printAllcombinations

#endif // !FINDALLBINARYIWTTHPATTERN
