/*
author:LSHM
problem:要求取凸包，然后判断每个凸包边中是否还有点
即每个边都要有点存在，才为yes
要找左下角的点
*/
#include <iostream>
#include <math.h>
#include<algorithm>
#include<deque>
#include<queue>
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


//注意不取等于号，可将共线点去掉
void MelkMan_judge1(Point * P,int num,bool & is_true){
    deque<Point> convex;
    vector<Point> not_convex;
    //***************
    //先求取凸包
    //注意在最底部有多个点时，要判断位置
    /*if(is_left(P[0], P[1], P[2])>0){
        convex.push_front(P[0]);
        convex.push_back(P[1]);
    }else if(is_left(P[0], P[1], P[2])<0){
        convex.push_back(P[0]);
        convex.push_front(P[1]);
    }*/
    convex.push_front(P[0]);
    convex.push_back(P[1]);
    //convex.push_front(P[2]);
    //convex.push_back(P[2]);
    //没有小于的情况
    if(is_left(P[0], P[1], P[2])==0){
        not_convex.push_back(P[1]);
        convex.pop_back();
    }
    convex.push_front(P[2]);
    convex.push_back(P[2]);
    for(int i =3;i<num;i++){
        //内部点
        if((is_left(*(convex.begin()), *(convex.begin()+1), P[i])>0) &&
           (is_left(*(convex.end()-2), *(convex.end()-1), P[i])>0)){
                not_convex.push_back(P[i]);
                continue;
           }

        //小于0，表示在右边，去掉等于零的情况，即将不加入共线点
        while(is_left(*convex.begin(), *(convex.begin()+1), P[i])<0 && convex.size()>2){
            convex.pop_front();
        }
        //考虑左侧共线
        if(is_left(*convex.begin(), *(convex.begin()+1), P[i])!=0)
            convex.push_front(P[i]);

        while(is_left(*(convex.end()-2), *(convex.end()-1), P[i])<=0 && convex.size()>2){
            not_convex.push_back(convex.back());
            convex.pop_back();
        }
        //if(is_left(*(convex.end()-2), *(convex.end()-1), P[i])==0){
         //   convex.pop_back();
        //}
        convex.push_back(P[i]);
    }
    //判断最后一个点是否共线，多余
    if(is_left(*(convex.end()-2), *(convex.end()-1),*(convex.begin()+1))==0){
        not_convex.push_back(convex.back());
        convex.pop_back();
    }
    if(convex.size()<=3){
        is_true=false;
        return;
    }
    for(deque<Point>::iterator pos =convex.begin();pos != convex.end()-1;pos++){
        bool flag=false;
        for(vector<Point>::iterator pos1 =not_convex.begin();pos1 != not_convex.end();pos1++){
            if(is_left(*pos, *(pos+1),*pos1)==0){
                flag=true;
                break;
            }
        }
        //如果所有点都不是边上的点，则为NO
        if(!flag){
            is_true=false;
            return;
        }
    }
    //find(not_convex.begin(),not_convex.end(),)==not_convex.end())

    /****Test
    cout<<"*****convex"<<endl;
    for(deque<Point>::iterator pos =convex.begin();pos != convex.end();pos++){
        cout<<"Point("<<pos->x<<","<<pos->y<<")"<<endl;
    }
    cout<<"******not convex"<<endl;
    for(vector<Point>::iterator pos =not_convex.begin();pos != not_convex.end();pos++){
        cout<<"Point("<<pos->x<<","<<pos->y<<")"<<endl;
    }*/
}

void MelkMan_judge2(Point * P,int num,bool &is_true){
    deque<Point> dq;

    //注意在最底部有多个点时，要判断位置
    /*if(is_left(P[0], P[1], P[2])>0){
        dq.push_front(P[0]);
        dq.push_back(P[1]);
    }else{
        dq.push_back(P[0]);
        dq.push_front(P[1]);
    }*/
    dq.push_front(P[0]);
    dq.push_back(P[1]);
    deque<Point>::iterator head =dq.begin();
    dq.push_front(P[2]);
    dq.push_back(P[2]);

    for(int i =3;i<num;i++){
        if((is_left(*(dq.begin()), *(dq.begin()+1), P[i])>0) &&
           (is_left(*(dq.end()-2), *(dq.end()-1), P[i])>0))
            continue;
        //小于等于0，表示在右边
        while(is_left(*dq.begin(), *(dq.begin()+1), P[i])<=0 && dq.begin()!=head)
            dq.pop_front();
        dq.push_front(P[i]);

        while(is_left(*(dq.end()-2), *(dq.end()-1), P[i])<0 && (dq.end()-1) !=head)
            dq.pop_back();
        dq.push_back(P[i]);
    }
    //如果所有线在一条边上
    bool flage=false;
    for(deque<Point>::iterator pos =dq.begin()+3;pos != dq.end();pos++){
        if((*(dq.begin()+2)).cos!=(*(pos)).cos){
            flage =true;
        }
    }
    if(!flage)
        is_true =false;
    for(deque<Point>::iterator pos =dq.begin()+1;pos != dq.end();pos++){
        if(is_left(*pos,*(pos+1),*(pos+2))>0 &&is_left(*(pos+1),*(pos+2),*(pos+3))>0){
            is_true =false;
        }
    }
    if(is_left(*(dq.end()-2),*(dq.end()-1),*(dq.begin()+1))>0 &&is_left(*dq.begin(),*(dq.begin()+1),*(dq.begin()+2))>0){
        is_true =false;
    }
/*
    cout<<"*****convex"<<endl;
    for(deque<Point>::iterator pos =dq.begin();pos != dq.end();pos++){
        cout<<"Point("<<pos->x<<","<<pos->y<<")"<<endl;
    }*/
}


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
                return;
            }
            is_flage=false;//恢复标志
            basepos =pos-1;
            prepos =pos;
            pos++;
        }
    }
    if(basepos==0)
        is_true=false;
    if(is_left(P[num-2],P[num-1],P[0])!=0)
        is_true=false;
}
/*
int main()
{
    bool is_true;
    int cases,num_vec[T];
    Point Points[T][N];
    cin>>cases;
    if(cases <1 || cases>10){
        return 0;
    }
    for(int j=0;j<cases;j++){
        cin>>num_vec[j];
        for(int i =0;i<num_vec[j];i++){
            cin>>Points[j][i].x>>Points[j][i].y;
        }
    }
    //get convex
    for(int i =0;i<cases;i++){
        if(num_vec[i]<1 || num_vec[i]>1000)
            return 0;
        if(num_vec[i]>=1&&num_vec[i]<=5){
            cout<<"NO"<<endl;
        }else{
            is_true=true;
            get_min_first(Points[i],num_vec[i]);//得到最低点
            get_cos(Points[i],num_vec[i]);//计算角度
            sort(&Points[i][1],&Points[i][1]+num_vec[i]-1,cmp);///按角度排序

            Judge(Points[i],num_vec[i],is_true);
            cout <<(is_true ? "YES":"NO")<< endl;
        }
    }

    return 0;
}*/
