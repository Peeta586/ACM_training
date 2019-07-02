#ifndef LEARNING_DEQUE_LIST_H_INCLUDED
#define LEARNING_DEQUE_LIST_H_INCLUDED
#include <deque>
#include <list>
using namespace std;

void test_deque_list()
{
    /************************************
    deque双向队列，头尾处理元素快，中间耗时，也支持[],at
    它也采用模板类实现，deque<T> deqT; 和vector的操作极其相似
    **/
    deque<int> deqInt;
    deque<float> deqFloat;
    deque<string> deqString;

    /***********
    头尾添加和移除数据
    deque.push_back(elem) 尾部添加
    deque.push_front(elem) 头部添加
    deque.pop_back()
    deque.pop_front();

    数据存取
    deque.at
    deque[]
    deque.front()
    deque.back()
    **/
    deqInt.push_back(2);
    deqInt.push_back(3);
    deqInt.push_back(4);

    cout<<deqInt.at(1)<<endl;
    cout<<deqInt[1]<<endl;
    cout<<deqInt.front()<<endl;
    cout<<deqInt.back()<<endl;
    /*********
    deque 与迭代器
    deque.begin()
    deque.end()
    deque.rbegin()
    deque.rend();
    **/
    deque<int>::iterator it;
    for(it= deqInt.end()-1; it!= deqInt.begin()-1; it--)
    {
        cout<<*it<<endl;
    }
    /**************
    定义deque时，带参构造
    deque(beg,end)
    deque(n,elem)
    deque(const deque &deq)
    记得区间左闭右开
    **/
    deque<int> deq(deqInt);
    deque<int> deqn(5,7);
    for(it= deqn.end()-1; it!= deqn.begin()-1; it--)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    /**********
    赋值：
    deque.assign(beg,end)
    deque.assign(n,elem)
    deque &operator=(const deque&deq)
    deque.swap(deq)
    */
    deque<int> deq_1,deq_2;
    deq_1 =deqn;
    deq_2.assign(deqn.begin(),deqn.begin()+2);
    for(it= deq_2.end()-1; it!= deq_2.begin()-1; it--)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    /****************
    大小：
    deque.size()
    deque.empty()
    deque.resize(num)
    deque.resize(num,elem)
    插入：
    需要注意的是pos为iterator类型，不是int类型，特别注意这一点
    deque.insert(pos,elem)返回新数据的位置,低效
    下面无返回值,
    deque.insert(pos,elem)
    deque.insert(pos,beg,end)在pos处，插入[beg,end)区间数据

    删除，同样位置参数为iterator类型
    deque.clear()
    一下函数 返回下一个数据
    deque.erase(beg,end)
    deque.erase(pos)
    */
    cout<<deqInt.size()<<endl;
    cout<<*deqInt.insert(deqInt.begin()+2,5)<<endl;

    /********************************************************
    list:双向链表
    list不可随机存取元素
    构造函数
    list<int> lstInt;
    list<float> lstFLoat;
    list<string> lstString;
    带参构造
    list(beg,end);
    list(n,elem);
    list(const list& lst);

    添加和删除
    list.push_back()尾部添加
    list.pop_back()
    list.push_front(elem)
    list.pop_front()

    数据存取,头尾读取
    list.front()
    list.back()
    迭代器
    begin，end，rbegin，rend

    赋值
    list.assign(beg,end);
    list.assign(n,elem);
    list & operator=(const list & lst);
    list.swap(lst);
    大小
    list.size()
    list.empty()
    list.resize(num)
    list.resize(num,elem);

    插入删除
    list.insert(pos,elem)
    list.insert(pos,n,elem);
    list.insert(pos,beg,end);
    list.clear()
    list.erase(beg,end)
    list.erase(pos);
    翻转
    list.reverse()
    注意：---------
    不能对list的迭代器begin,end进行加减，其他的可以
    也就是list的迭代器只有++，--，
    没有+，-，+=，-=，
    因为list为双向链表，所以只能一步一步的加，
    因此只支持++，--运算符
    ***/
    list<int> lstInt;
    list<float> lstFLoat;
    list<string> lstString;

    lstInt.push_back(2);
    lstInt.push_back(3);
    lstInt.push_back(4);
    lstInt.push_front(5);
    lstInt.insert(lstInt.begin(),6);
    lstInt.reverse();
    list<int>::iterator it_list = lstInt.begin();
    it_list++;
    lstInt.insert(it_list,7);
    cout<<"start"<<endl;
    for(it_list =lstInt.begin();it_list!=lstInt.end(); it_list++){
        cout<<*it_list<<endl;
    }


}




#endif // LEARNING_DEQUE_LIST_H_INCLUDED
