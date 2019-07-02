#ifndef LEARNING_KMP_H_INCLUDED
#define LEARNING_KMP_H_INCLUDED
/**************************************
KMP:就是求next数组，用于计算不匹配的位置需要移动多少距离，
next[i]也就是该i索引前子串的前缀后缀最大值
如：AABAA D,D的前子串
前缀：空,A, AA, AAB,AABA,   (AABAA)删除全串
后缀：空,A, AA, BAA,ABAA,   (AABAA)删除全串
           最大
则当D不匹配时，则next[index_D]=2;
**/
void get_next(int *next,char *s2,int lens){
    //用于构建s2的next数组，kmp的前奏
    //next必需为s2的长度+1
    //next必需为s2的长度+1
    int t1=0,t2;
    next[0]=t2=-1;
    while(t1<lens){
        if((t2==-1)||s2[t1]==s2[t2]){
            //如果s2[t1]==s2[t2]，则说明前next就算加1，得到当前next值，
            next[t1+1] = t2 + 1;
            t1++;
            t2 =t2+1; //然后两个同时加1
        }else{
            t2 = next[t2]; //当不必配时，退回到开始进行计算重新匹配
        }
    }
}

/*************************************
KMP匹配1），计算是否存在串
**/
bool kmp1(int *next,char *s1,int lens1,char *s2,int lens2){
    //用于判断S2是否是S1的子串
    int t1=0,t2=0;
    while(t1<lens1 && t2<lens2){
        if(t2==-1 || s1[t1]==s2[t2]){ //t2==-1用于处理，当串没有任何匹配时，子串往后移动一位
            t1++;
            t2++;
        }else{
            t2=next[t2];
        }
    }
    if (t2==lens2){
        return true; //子串全部匹配
    }else{
        return false;
    }
}

/*************************************
KMP匹配2），有多少个子串
**/
int kmp2(int *next,char*s1,int lens1,char*s2,int lens2){
    int t1=0,t2=0;
    int times=0;
    while(t1<lens1){
        if(t2=-1 || s1[t1]==s2[t2]){
            t1++;
            t2++;
        }else{
            t2 =next[t2];
        }
        if(t2==lens2){
            times +=1;
            t2=next[t2];
        }
    }
    return times;
}
void test_kmp(){
    char *s1 ="AAABAAABAAABAAABAAAD";
    char *s="AAABAABAAABABBDBBAAB";
    char *s2="AAABAAAD";
    /****
    sizeof(s2)=4,因为s2为指针，所以大小为4个字节，
    不能表示为数组大小,
    只有定义为char s[] = "AAABAAAD";才能计算
    **/

    int next[9];
    cout<<sizeof(s2)<<endl;
    get_next(next,s2,strlen(s2));
    cout<<kmp1(next,s1,strlen(s1),s2,strlen(s2))<<endl;
    cout<<kmp1(next,s,strlen(s),s2,strlen(s2))<<endl;
}



#endif // LEARNING_KMP_H_INCLUDED
