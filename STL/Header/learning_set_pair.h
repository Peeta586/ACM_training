#ifndef LEARNING_SET_PAIR_H_INCLUDED
#define LEARNING_SET_PAIR_H_INCLUDED
#include<set> //包含set和multiset
#include<string>
using namespace std;

class Student{
public:
    Student(int iID,string strName){
        m_id =iID;
        m_Name = strName;
    }
    int m_id;
    string m_Name;
};

//函数对象
struct StuFunctor{
    bool operator()(const Student &stu1,const Student &stu2){
        return (stu1.m_id>stu2.m_id);  //出错，吧stu2写成了stu1
    }
};

void test_set_pair(){
    /******************************
    set集合容器，元素唯一，元素插入按照一定排序规则，所以不能指定插入
    set采用红黑树变体的数据结构实现，红黑树属于平衡二叉树，
    插入删除操作比vector快
    set不可以直接存取元素，即不可以使用at或者[]

    multiset和set的区别：set支持唯一键值，每个元素只能出现一次，
    multiset中同一个值可以出现多次

    注意：不可直接修改元素值，因为容器中元素是自动排序的，
    如果要修改值，则需要先删除，然后再添加

    定义：
    set<T> setT, multiset<T> multisetT;
    **/
    set<int,less<int>> setInt;
    set<float> setFloat;
    set<string> setString;

    multiset<int> mset_Int;

    /**************************
    插入和迭代器：
    set.insert(elem);
    set.begin(),set.end();
    set.rbegin(),set.rend();

    set的排列方式：
    1）升序：set<int,less<int>> setIntA;
    2) 降序：set<int,greater<int>> setIntB;
    3) set<int> 相当于set<int,less<int>>
    4) less和greater中可以是其他类别，只要和set类型一致就行
    */

    setInt.insert(4);setInt.insert(9);setInt.insert(3);
    setInt.insert(7);setInt.insert(8);setInt.insert(5);
    for(set<int>::iterator it=setInt.begin();it!=setInt.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;

    /****************************************
    less<> greater<>是什么，如果set中包含其他的类型，如何排序，
    这就用到了一个叫functor的伪函数（容器的函数对象）
    实现函数回调：除了函数指针，就是函数对象了
    functor函数对象是重载了“()”操作符的普通类对象

    less<> greater<>是函数对象
    例如：greater<int>简易实现原理
    struct greater{
        bool operator()(const int&iLeft,const int&iRight)
        {
            return (iLeft>iRight);
        }
    }
    容器是调用函数对象的operator()方法去比较两个值的大小
    对自定义类型进行定义排序函数
    **/
    set<Student,StuFunctor> setStu;

    setStu.insert(Student(3,"liok"));
    setStu.insert(Student(5,"liok2"));
    setStu.insert(Student(2,"liok1"));
    setStu.insert(Student(1,"liok4"));
    cout<<setStu.size()<<endl;
    for(set<Student>::iterator it_s=setStu.begin();it_s!=setStu.end();++it_s){
        cout<<(*it_s).m_id<<endl;
        cout<<"tt"<<endl;
    }
    /********************************************
    拷贝构造与赋值
    set(const set&st);
    set &operator=const set&st);
    set.swap(st);
    setIntD =setIntC;

    大小
    set.size()
    set.empty()
    删除：
    set.clear()
    set.erase(pos)//pos 为iterator
    set.erase(beg,end);返回下一个迭代器
    set.erase(elem);  删除容器中值为elem的元素

    查找：set有自带的find，否则利用泛型find进行查找元素
    set.find(elem);
    set.count(elem) 返回元素中值为elem的元素个数，
    对于multiset可能大于1

    当set为升序时：
    set.low_bound(elem) 返回第一个大于等于elem的迭代器
    set.upper_bound(elem)返回第一个大于elem元素的迭代器
    降序时，小于等于或小于

    set.equal_range(elem)返回容器与elem相等的上下限的两个迭代器，
    注意一下的理解上下限----------------------------
    （这个上下限对应着上面的low_bound,upper_bound,也就是一个为>=,一个为>)
    上限闭区间，下限开区间[beg,end)即返回一个pair，
    3,4,5,7,8,9  当elem为6时，  返回的是7,7
    **/
    cout<<*setInt.find(5)<<endl;
    cout<<setInt.count(5)<<endl;
    cout<<*setInt.lower_bound(5)<<endl;
    cout<<*setInt.upper_bound(8)<<endl;
    pair<set<int>::iterator,set<int>::iterator> pairIt = setInt.equal_range(5);
    cout<<*pairIt.first<<*(pairIt.second)<<endl;
    multiset<int> mulset;
    //mulset.insert()只有插入，没有push和pop
    //set利用有序树存储的，所以只有insert，没有push


}




#endif // LEARNING_SET_PAIR_H_INCLUDED
