#ifndef LEARNING_C++_CLASS_H_INCLUDED
#define LEARNING_C++_CLASS_H_INCLUDED

#include <iostream>
#include <cassert>
#include <typeinfo>

using namespace std;
/********************************
C++对象模型，深度探索C++
**/
/*********
1) template 类封装
**/
template <class type, int dim>  //注意这种声明
class Point{
public:
    Point();
    Point(type coords[dim]){
        for(int index=0;index < dim; index++){
            _coords[ index ] = coords[index];
        }
    }
    type & operator[](int index ){
        assert(index < dim && index >=0);
        return _coords[index];
    }
    type operator[](int index) const{
        assert(index < dim && index >= 0);
        return _coords[index];
    }
private:
    type _coords[dim];
};

template<class type, int dim> //模板函数的定义，实现运算符重载，第二个参数为自己定义的输出类型
inline ostream & operator<<(ostream & os,const Point<type,dim> &pt){
    os<<"(";
    for(int ix=0;ix<dim-1;ix++)
        os<<pt[ix]<<",";
    os<<pt[dim-1];
    os<<")";
}

class A{
public:
    A():a(0){};
    virtual void test(){
        cout<<"A"<<a<<endl;
    }
    int a;
};
class B:public A{
public:

    B(){num=1; a=1;};
    B(B &b);
    virtual void test(){
        cout<<"B"<<a<<endl;
    }
    virtual void testB(){
        cout<<"B self"<<endl;
    }
    int num;
};
B::B(B &b){
    cout<<"run memcpy"<<endl;
    memcpy(this,&b,sizeof(B));
}
class C:public  A{
public:
    C(){};
    virtual void test(){
        cout<<"C"<<endl;
    }
    virtual void testC(){
        cout<<"C self"<<endl;
    }
    int c;
};
class D:public virtual B,public virtual C{
public:
    D(){};
    virtual void testD(){
        cout<<"D"<<endl;
    }
    int d;
};

typedef int length;

class Point3d{
public:
    void mumble(length val){ _val =val;}
    void getval(){
        if (typeid(_val) == typeid(int))
            cout<<"it is int "<<endl;
        else
            cout<<"it is float"<<endl;
    }
    length mumble() {return _val;}

private:
    typedef float length; //后面又有定义
    length _val;
};

/****
虚函数表的访问实例
**/
class Base{
public:
    virtual void f(){cout<<"Base::f"<<endl;}
    virtual void g(){cout<<"Base::g"<<endl;}
    virtual void h(){cout<<"Base::h"<<endl;}
};
class Base1{
public:
    virtual void f(){cout<<"Base1::f"<<endl;}
    virtual void g(){cout<<"Base1::g"<<endl;}
    virtual void h(){cout<<"Base1::h"<<endl;}
};
class Derived:public Base,public Base1{
public:
    virtual void f(){cout<<"Derived::f"<<endl;} //不会有歧义，会全部继承
    virtual void g1(){cout<<"Derived::g"<<endl;}
    virtual void h1(){cout<<"Derived::h"<<endl;}
};


void test_class(){
    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    A a;
    B b;
    C c;
    D d;
    cout<<"sizeof(a):"<<sizeof(a)<<endl;
    cout<<"sizeof(b)"<<sizeof(b)<<endl;
    cout<<"sizeof(c)"<<sizeof(c)<<endl;
    cout<<"sizeof(d)"<<sizeof(d)<<endl;
    //d.C::test();
    B bb(b);
    a =b;
    cout<<"a.test"<<endl;
    a.test(); //因为a是A类对象，所以调用成员函数时，还是按照A类的定义来
    //尽管a被赋予b了，但是只是nonstatic成员变量变化了，而成员函数的调用没有变化

    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    /***********
    虚表地址
    **/
    typedef void(*Fun)(void); //定义函数指针类型
    Base bs;
    Fun pFun = NULL;

    cout << "虚函数表地址：" << (int*)(&bs) << endl;
    cout << "虚函数表 — 第一个函数地址：" << ((int *)*(int *)(&bs)) << endl;

    // Invoke the first virtual function
    pFun = (Fun)(*((int*)*(int*)(&bs)+1)); //转化为Fun地址类型
    pFun();
    /************************
    多重继承
    **/
    Derived dd;
    Base *b1 =&dd;
    Base1 * b2=&dd;
    b1->f();
    b2->f();
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

    Point3d p3d;
    int num=9;
    p3d.mumble(num);
    p3d.getval();
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    /**
    只有指针和引用才能实现多态
    */
    A &aa =b;
    aa.test();
    A * aaa =&b;
    aaa->test();
    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
}

/******
类的成员变量和c的struct一样，包含在类的声明中，
而成员函数虽然声明在类中，但是不出现在object中；
每个non-inline 成员函数只会诞生一个函数实体；
而inline的成员函数则会在其每个使用者(模块)身上产生一个函数体

***/

#endif // LEARNING_C++_CLASS_H_INCLUDED
