/*
author:LSHM
problem:要求取凸包，然后判断每个凸包边中是否还有点
即每个边都要有点存在，才为yes
要找左下角的点
*/
/*
#include <iostream>
#include <math.h>
#include<algorithm>
using namespace std;

struct Point{
    int x,y;
    float cos;
};
#define T 10
#define N 1000

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
    if(p0.cos==p1.cos)
        if(p0.cos<=0)//取外
            if(p0.x>p1.x || p0.y >p1.y)
                return true;
            else
                return false;
        else{
            if(p0.x<p1.x || p0.y <p1.y)//取外
                return true;
            else
                return false;
        }
    else
        return p0.cos>p1.cos;
}

//这种判断必须使得凸包按照逆时针排序依次排序
void Judge(Point * P,int num,bool &is_true){
    int pos=2,prepos=1,basepos=0;
    bool is_flage=false;
    for(int i =2; i<num;i++){
        if(is_left(P[basepos],P[prepos],P[pos]) ==0){
            is_flage=true;
            pos++;
        }else{
            if(!is_flage){
                is_true=false;
                cout<<"basepos-f"<<basepos<<"->"<<"prepos"<<prepos<<"->"<<"pos"<<pos<<"flage"<<is_flage<<endl;
                return;
            }
            cout<<"flage is change"<<endl;
            is_flage=false;//恢复标志
            basepos =pos-1;
            prepos =pos;
            pos++;
        }
        cout<<"basepos"<<basepos<<"->"<<"prepos"<<prepos<<"->"<<"pos"<<pos<<"flage"<<is_flage<<endl;
    }
    if(basepos==0){
        is_true=false;
        cout<<"basepos"<<basepos<<"->"<<"prepos"<<prepos<<"->"<<"pos"<<pos<<endl;
        return;
    }
    if(is_left(P[num-2],P[num-1],P[0])!=0){
        is_true=false;
        cout<<"basepos--"<<basepos<<"->"<<"prepos"<<prepos<<"->"<<"pos"<<pos<<endl;
        return;
    }
}

//test data
/*
1
6
0 0 2 0 2 4 1 2 3 2 4 0
*/
/*
int main(){
    bool is_true;
    int cases,num_vec[T];
    Point Points[T][N];
    cin>>cases;
    for(int j=0;j<cases;j++){
        cin>>num_vec[j];
        for(int i =0;i<num_vec[j];i++)
            cin>>Points[j][i].x>>Points[j][i].y;
    }
    //get convex
    for(int i =0;i<cases;i++){
        is_true=true;
        if(num_vec[i]>=1 && num_vec[i]<=5){
            cout<<"NO"<<endl;
        }else{
            is_true=true;
            get_min_first(Points[i],num_vec[i]);//得到最低点
            get_cos(Points[i],num_vec[i]);//计算角度
            sort(&Points[i][1],&Points[i][1]+num_vec[i]-1,cmp);///按角度排序
            for(int j=0;j<num_vec[i];j++)
                cout<<"Point("<<Points[i][j].x<<","<<Points[i][j].y<<")"<<endl;
            Judge(Points[i],num_vec[i],is_true);
            cout <<(is_true ? "YES":"NO")<< endl;
        }
    }

    return 0;
}*/
