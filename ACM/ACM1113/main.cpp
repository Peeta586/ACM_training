//
//  main.cpp
//  test
// authors: LSHM
//  Created by hyx on 17/3/16.
//  Copyright © 2017年 hyx. All rights reserved.
//
#include <iostream>
#include<queue>
#include <deque>
#include<math.h>
#include<memory>
#include <algorithm>
using namespace std;

/*deque<int,int> judger;
//queue<int> result;
//因为数组初始设置为100，则NUM等于100，不能得到数组中实际有多少值
//#define NUM(array) (sizeof(array)/sizeof(array[0]))*/

#define PI 3.1415926

//Set the Point struct
struct Point{
    int x,y;
    float cos;//相对于最低点的与x轴正方向的夹脚的余弦值
};
//Point Points[100];

//判断是否为逆时针。
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
//左下角的点
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

//work for sort  返回真表示p0<p1
bool cmp(Point p0,Point p1){
    if(p0.cos==p1.cos)
        if((p0.x<p1.x)||(p0.y<p1.y))
            return true;
        else
            return false;
    else
        return p0.cos>p1.cos;
}

//注意队列end（）不指向任何单元
void MelkMan(Point * P,int num,deque<Point> &dq){
    //注意在最底部有多个点时，要判断位置

    dq.push_front(P[0]);
    dq.push_back(P[1]);
    deque<Point>::iterator head =dq.begin();
    if(is_left(P[0],P[1],P[2])==0)
        dq.pop_back();
    dq.push_front(P[2]);
    dq.push_back(P[2]);

    for(int i =3;i<num;i++){
        //内部点
        if((is_left(*(dq.begin()), *(dq.begin()+1), P[i])>0) &&
           (is_left(*(dq.end()-2), *(dq.end()-1), P[i])>0))
            continue;
        //小于等于0，表示在右边
        while(is_left(*dq.begin(), *(dq.begin()+1), P[i])<=0 && dq.begin()!=head)
            dq.pop_front();
        dq.push_front(P[i]);

        while(is_left(*(dq.end()-2), *(dq.end()-1), P[i])<=0 && dq.end()-1 != head)
            dq.pop_back();
        dq.push_back(P[i]);
    }
/*
    for(deque<Point>::iterator pos =dq.begin();pos != dq.end();pos++){
        cout<<"Point("<<pos->x<<","<<pos->y<<")"<<endl;
    }*/
}
double get_radian(Point p1,Point p2,Point p3){
    //get P1P2
    float P12_x=p2.x-p1.x;
    float P12_y=p2.y-p1.y;
    //get P2P3
    float P23_x=p3.x-p2.x;
    float P23_y=p3.y-p2.y;

    double P12=sqrt(pow(P12_x,2)+pow(P12_y,2));
    double P23=sqrt(pow(P23_x,2)+pow(P23_y,2));

    //get cos
    return acos((P12_x*P23_x+P12_y*P23_y)/(P12*P23));
}

inline float
get_vector_length(Point P1,Point P2){
    return sqrt(pow((float)(P2.x-P1.x),2)+pow((float)(P2.y-P1.y),2));
}

void get_total_circle(deque<Point> vertex,int min_feet,float & circle){
    circle=0.0;
    if(vertex.size() <= 3 )
        return;
    //first, we get the contex circle
    for(deque<Point>::iterator pos=vertex.begin();pos != vertex.end()-1;pos++){
        circle +=get_vector_length(*pos,*(pos+1));
    }
    //second, we get 每个转角的弧长
    for(deque<Point>::iterator pos=vertex.begin();pos != vertex.end()-2;pos++){
        circle +=get_radian(*pos,*(pos+1),*(pos+2))*min_feet;
    }
    //calculate the last vertex
    circle += get_radian(*(vertex.end()-2),*vertex.begin(),*(vertex.begin()+1))*min_feet;
}
#define N 1000
#define MIN_N 3

//sort(p[1],p[1]+NUM(p)-1,cmp)
//3 5 4 2 1 4 2 1 1 0
/*
9 100
200 400
300 400
300 300
400 300
400 400
500 400
500 200
350 200
200 200
*/
int main(int argc,char ** argv){
    Point Points[N];

    //get real number
    int num_vec=0,min_feet;
    //get number
    cin>>num_vec>>min_feet;
    //get vertexes
    for(int i =0;i<num_vec;i++){
        cin>>Points[i].x>>Points[i].y;
    }
    /*
    if(num_vec<3 || num_vec>1000)
        return 0;
    if(min_feet <1 || min_feet>1000)
        return 0;*/
    //get convex
    get_min_first(Points,num_vec);//得到最低点
    get_cos(Points,num_vec);//计算角度
    sort(&Points[1],&Points[0]+num_vec,cmp);///按角度排序
    /*for(int j=0;j<num_vec;j++){
        cout<<"Point("<<Points[j].x<<","<<Points[j].y<<")"
        <<Points[j].cos<<endl;
    }*/
    deque<Point> result;
    MelkMan(Points,num_vec,result);

    //get total feet
    float circle;
    get_total_circle(result,min_feet,circle);
    cout<<(int)(circle+0.5)<<endl;

    /*--------Test--------
    cout<<"Input num:"<<endl;
    int num=0;
    do{
        cin>>Points[num].x>>Points[num].y;
        num++;
    }while(cin.get() !=10 && num<100);
    *******test
     int num = i;//输入的个数
     cout<<"num inputs:"<<num<<endl;
     for(int j=0;j<num;j++){
     cout<<"Point("<<P[j].x<<","<<P[j].y<<")"<<endl;
     }

    get_min_first(Points,num);//得到最低点
    get_cos(Points,num);//计算角度
    sort(&Points[1],&Points[1]+num-1,cmp);///按角度排序

    //test the sorted vertexes
    for(int j=0;j<num;j++){
        cout<<"Point("<<Points[j].x<<","<<Points[j].y<<")"
        <<Points[j].cos<<endl;
    }

    //得到凸包点，存储在result中
    deque<Point> result;
    MelkMan(Points,num,result);

    //test the vertexes
    for(deque<Point>::iterator pos =result.begin();pos != result.end();pos++){
        cout<<"Point("<<pos->x<<","<<pos->y<<")"<<endl;
    }

    //test the circle
    float circle;
    get_total_circle(result,1,circle);
    cout<<"Circle:"<<circle<<endl;*/

    //system("pause");
    return 0;
}

