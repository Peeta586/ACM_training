#ifndef LEARNING_TUBAO_H_INCLUDED
#define LEARNING_TUBAO_H_INCLUDED
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 10

/*****************************
凸包算法框架:
先把点集按照x坐标->y坐标的字典升序排序:如cmp_x()函数
那么第一个和最后一个点肯定是凸包上的点；
然后分成两个连分别求解凸包点，
在构造过程是检查新加入的点是否为凸点，通过计算向量夹角是否大于零
**/
/***
类模式
**/
class Point{
    int x,y;
public:
    Point():x(0),y(0){};
    Point(int x,int y){
        this->x =x;
        this->y =y;
    }
    //Point(const Point & p);
    Point & operator=(const Point &p);
    inline Point operator-(const Point &p); //返回副本，不用引用,只有一个参数
    int det(const Point &p); //计算向量是否为逆指针序列
    void print(){
        cout<<"("<<this->x<<","<<this->y<<")"<<endl;
    }
    friend bool cmp_z(const Point&p1,const Point &p2);
    friend Point operator+(const Point &p1,const Point &p2);

};
inline Point operator+(const Point &p1,const Point &p2){
    return Point(p1.x+p2.x,p1.y+p2.y);
}
inline Point &Point::operator=(const Point&p){
    this->x =p.x;
    this->y =p.y;
    return *this;
}

inline Point Point::operator-(const Point &p){ //
    return Point(this->x -p.x,this->y-p.y);
}
inline Point::det(const Point&p){
    return this->x*p.y -this->y*p.x;
}
bool cmp_z(const Point&p1,const Point&p2){
    if(p1.x != p2.x) return p1.x<p2.x;
    return p1.y<p2.y;
}
vector<Point> convex_hull(Point* ps,int n){
    //先字典排序
    sort(ps,ps+n,cmp_z);
    int k=0; //凸包的顶点数
    vector<Point> qs(n*2);
    //先构造下侧链，然后再构造上册链，从k开始
    for(int i=0;i<n;i++){
        //从第三个点开始，前两个点赋值到qs[1],qs[2];
        while(k>1 && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++] = ps[i];
    }
    for(int i=n-2,t=k;i>=0;i--){
        while(k>t && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}

/********************************************
结构体模式
struct P{
    int x,y;
};
bool cmp_z(const P & p1,const P & p2){
    if(p1.x != p2.x) return p1.x<p2.x;
    return p1.y<p2.y;
}
***/
void test_tubao(){
    int N=8;
    Point ps[MAX_N];
    int x[] ={0,1,3,5,6,6,8,8};
    int y[] ={5,8,4,0,2,6,3,7};
    for(int i=0;i<N;i++){
        ps[i]= Point(x[i],y[i]);
    }
    for(int i=0;i<N;i++){
        ps[i].print();
    }
    vector<Point> sorted_Point =convex_hull(ps,N);
    cout<<sorted_Point.size()<<endl;

    for(int i=0;i<sorted_Point.size();i++){
        sorted_Point[i].print();
    }
    (ps[0]+ps[1]).print();
}




#endif // LEARNING_TUBAO_H_INCLUDED
