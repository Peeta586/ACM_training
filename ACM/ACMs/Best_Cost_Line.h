#ifndef BEST_COST_H
#include<cstdio>
class Best_Cow_Line{
private:
    int N;
    char * S;
public:
    Best_Cow_Line(char *S,int N){
        this->N = N;
        this->S = S;
    }
    void solve(){
        int a = 0, b = N-1;
        while(a <= b){
            bool left = false;
            for(int i = 0; a+i<= b;i++){
                if (S[a+i]<S[b-i]){
                    left=true;
                    break;
                }else if (S[a+i]>S[b-i]){
                    left=false;
                    break;
                }
            }
            //注意，将判断写在外面
            //如果写在训练里面，对于最后一个字符，即a=b，会导致死循环。
            //这在编程时，应该注意，对于最开始与最后结束最为主要考察点，
            //防止特殊性存在。
            if (left)
                putchar(S[a++]);
            else
                putchar(S[b--]);
        }
        putchar('\n');
    }

};

#endif // BEST_COST_H
