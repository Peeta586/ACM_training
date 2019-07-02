/*
author:LSHM
problem:
*/

#include <iostream>
#include <math.h>
#include<algorithm>
#include<cstdio>
using namespace std;

struct Point{
    int x,y;
    float cos;
};
#define N 50

inline int
is_left(Point P0,Point P1,Point P2){
    return (P1.x-P0.x)*(P2.y-P0.y)-(P1.y-P0.y)*(P2.x-P0.x);
}

//calculate the cos value
inline float
cal_cos(Point p0,Point p1){
    float length =(p1.x-p0.x)*(p1.x-p0.x)+(p1.y-p0.y)*(p1.y-p0.y);
    return (p1.x-p0.x)/sqrt(length);
}

//查找y轴最低点，然后将其与第一个元素交换
void get_min_first(Point * p,int num){
    int min_y = p[0].y;
    int index=0;
    for(int i =1;i<num;i++){
        if(p[i].y < min_y){
            min_y = p[i].y;
            index = i;
        }else if(p[i].y == min_y){
            if(p[i].x<p[index].x){
                min_y = p[i].y;
                index = i;
            }
        }
    }
    //只交换x，y，夹脚值不交换。
    int temp=p[0].x;
    p[0].x = p[index].x;
    p[index].x=temp;
    temp =p[0].y;
    p[0].y = p[index].y;
    p[index].y = temp;
}

//得到夹脚值
void get_cos(Point *p,int num){
    //从第二个值开始算，第一个用作基准点，用于求向量
    for(int i =1;i<num;i++){
        p[i].cos = cal_cos(p[0],p[i]);
    }
}

//work for sort,该判断排序，使得形成顺序环，共线的从外到内
bool cmp(Point p0,Point p1){
    return p0.cos>p1.cos;
}

void Print_Convex(Point *p,int num){
    bool is_start=false;
    int n=0;
    for(int i = 0;n<num; i++){
        if(!is_start && p[i%num].x == 0 && p[i%num].y ==0){
            is_start=true;
        }
        if(is_start){
            cout<<"("<<p[i%num].x<<","<<p[i%num].y<<")"<<endl;
            n++;
        }
    }
}

//test data
/*
1
6
0 0 2 0 2 4 1 2 3 2 4 0
*/

int main(){
   // bool is_true;
    Point Points[N];
    int num=0;
    while(scanf("%d%d",&Points[num].x,&Points[num].y) !=EOF){
        num++;
    }
    get_min_first(Points,num);//得到最低点
    get_cos(Points,num);//计算角度
    sort(&Points[1],&Points[0]+num,cmp);///按角度排序
    Print_Convex(Points,num);

    /*for(int j=0;j<num;j++)
        cout<<"Point("<<Points[j].x<<","<<Points[j].y<<")"<<endl;
    //get convex
    for(int i =0;i<cases;i++){
        is_true=true;
        if(num_vec[i]>=1 && num_vec[i]<=5){
            cout<<"NO"<<endl;
        }else{
            is_true=true;

            for(int j=0;j<num_vec[i];j++)
                cout<<"Point("<<Points[i][j].x<<","<<Points[i][j].y<<")"<<endl;
            Judge(Points[i],num_vec[i],is_true);
            cout <<(is_true ? "YES":"NO")<< endl;
        }
    }*/
    system("pause");
    return 0;
}
