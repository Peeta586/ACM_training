#ifndef LEARNING_VECTOR_H_INCLUDED
#define LEARNING_VECTOR_H_INCLUDED
#include <vector>
using namespace std;
/******
t特性：
尾部添加和删除元素特别快，但是中不和头部插入元素会费时
*/

void test_vector(){
    //vector<T> vecT;
    vector<int> vecInt;
    vector<float> vecFloat;
    vector<string> vecString;

    //类为元素
    class CA{};
    vector<CA*> vecpCA;//类的指针为元素
    vector<CA> vecCA;
    ///注意，当类为vector的指针时，当元素存放（插入，替换）时，
    ///会执行复制拷贝，操作，所以，CA必须提供CA的拷贝构造函数，保证CA对象间的拷贝

    /***************************
    尾部添加和移除操作
    push_back()添加
    pop_back() 移除
    */
    vector<int> vec_i;
    vec_i.push_back(1);
    vec_i.push_back(2);
    vec_i.pop_back();
    cout<<vec_i[0]<<endl;

    /**********************
    数据存储：
    vec.at(idx);
    vec[idx];

    数据的读取
    vector.front() 第一个数据
    vector.back()最后一个数据

    */
    vec_i.push_back(3);
    vec_i.push_back(5);
    vec_i.push_back(8);
    cout<<vec_i.at(2)<<endl;
    vec_i.at(2)=16;
    vec_i[3]=66;
    cout<<vec_i.at(2)<<endl;
    cout<<vec_i[3]<<endl;

    cout<<vec_i.front()<<" "<<vec_i.back()<<endl;
    vec_i.front()=0;
    vec_i.back()=99;
    cout<<vec_i.front()<<" "<<vec_i.back()<<endl;
    /*********************************
    遍历容器的迭代器
    迭代器如同指针，指出容器特定位置，提供了对容器的访问方法
    分为：只读迭代器，只写迭代器，
    双向迭代器（可++，可--），随机访问迭代器（组合双向迭代器且跳跃位置）
    双向：
    it++,++it,it--,--it,*it,ita=itb,ita==itb,ita!=itb  ------>list,set,map,multiset/mutimap
    随机：
    it+=i,it-=i,it+i,it[i],ita<itb,ita>itb,   --------->vector,deque
    **/

    /***********
    声明容器的迭代器：
    vector<int>::iterator it;
    it = vector.begin(), 此时*it==1;
    for(vector<int>::iterator it=vecInt.begin();it!=vecInt.end();++it){
        int iItem = *it;
        cout<<iItem;
    }
    vec.rbegin()
    vec.rend()
    还有vector<int>::reverse_iterator;
    vector对象的带参数构造

    vector(begin,end);
    vector(n,len);
    vector(const vector & vec);
    **/
    vector<int> vec(vec_i.begin(),vec_i.end());
    vector<int> vec_n(5,2);
    vector<int>::iterator it;
    for(it = vec_n.begin();it!=vec_n.end();it++){
        cout<<*it<<endl;
    }
    /*************************
    vector.assign(beg,end);
    vector.assign(n,elem);
    vector &operator=(const vector&vec);
    vector.swap(vec);vec与本身元素互换
    **/
    //vec_n.swap(vec_i);
    //vec_n = vec_i;
    for(it = vec_n.begin();it!=vec_n.end();it++){
        cout<<*it<<endl;
    }
    /**********************
    vector大小
    vector.size()
    vector.empty();
    vector.resize(num);
    vector.resize(num,elem),若变长，则填充新的位置，若变短，删除

    vector插入
    vector.insert(pos,elem);返回新数据的位置

    下面两个函数无返回值
    vector.insert(pos,n,elem);
    vector.insert(pos,beg,end);

    vector删除
    vector.clear()删除所有元素
    vector.erase(beg,end);返回下一个位置
    vector.erase(pos);返回下一个位置,pos为it
    **/
    vector<int>::iterator it_beg =vec_n.begin()+1;
    vector<int>::iterator it_end =vec_n.end();
    vec_n.insert(vec_n.begin(),3);
    //vec_n.erase(it_beg,it_end);
    //vec_n.erase(1);
    cout<<"------------"<<endl;

    for(it = vec_n.begin();it!=vec_n.end();it++){
        cout<<*it<<endl;
    }

    //循环删除vector中某个值的元素时，需要注意的写法
    for(it=vec_i.begin();it!=vec_i.end();){
        if(*it == 3){
            it = vec_i.erase(it);
        }else{
            ++it;
        }
    }
}




#endif // LEARNING_VECTOR_H_INCLUDED
