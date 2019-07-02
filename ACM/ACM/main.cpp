#include <iostream>
#include<cstring>
#include<cctype>
#include<math.h>
using namespace std;

//全局变量声明
//注意本题中数据表示含义：每个对应的数据表示该值的数据个数。
//想到用递归形式
bool flag;
int num[6];//放权值的数组，经对应权值加的形式存储数据****************
int half_value;
void dsf(int value, int number){
    if(flag) return;
    if(value == half_value){
        flag =true;
        return;
    }///////////////////////输出每次的num值
    for(int i =number; i>=1;i--){
        if(num[i-1]){//值进行判断
                //加上该值还是小于一半，则继续递归。
            if(value+i <=half_value){//必须将加上i后的部递归
                num[i-1]--;//先将其改变，用于影响下
                dsf(value+i,i);
                num[i-1]++;/////
                if(flag) break;
            }
        }
    }
    return;
}
/*
int main(){
    int sum,k=1;
    flag =false;
    while(!flag){
        sum =0;
        for(int i =0;i<6;i++){
            cin>>num[i];
            if(num[i])
                flag =true;
        }
        if(!flag)//全为零，退出,只有这一个出口
            break;

        for(int i=1;i<=6;i++)
            sum += i*num [i-1];

        flag =false;//该标示被重用
        if(sum % 2 ==0){
            half_value =sum /2;
            dsf(0,6);
        }
        cout<<"Collection #"<<k++<<":"<<endl;
        if(flag)
            cout<<"Can be divided."<<endl;
        else
            cout<<"Can't be divided."<<endl;
        cout<<endl;

        //恢复flag循环标示的作用
        flag =false;
    }
    return 0;
}*/
double get_radian(Point p1,Point p2,Point p3){
    //get P1P2
    P12_x=p2.x-p1.x;
    P12_y=p3.y-p2.y;
    //get P2P3
    P23_x=p3.x-p2.x;
    P23_y=P3.y-P2.y;

    P12=sqrt((pow(P12_x,2)+pow(P12_y,2));
    P23=sqrt((pow(P23_x,2)+pow(P23_y,2));

    //get cos
    cos=(double)(P12_x*P23_x+P12_y*P23_y)/(P12*P23);
    return acos(cos);
}


int main(){
    double num = acos(0.5);
    cout<<num<<"  "<<3.1415/3<<endl;
    return 0;
}
