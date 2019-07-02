#ifndef LEARNING_MAP_H_INCLUDED
#define LEARNING_MAP_H_INCLUDED
#include<map>
#include<string>
using namespace std;

void test_map(){
    /******************************
    map是关联式的容器，key唯一，按照一定序列排序
    不能指定插入序列，采用变体红黑树，
    插入删除操作比vector快。
    可以直接读取key对应键值，map[key] =value
    multimap中的键可以多次出现，所以不支持[]操作
    构造：
    map<T1,T2> mapTT;
    multimap<T1,T2> multimapTT;
    **/
    map<int,char> mapA;
    map<string,float> mapB;
    /****************************
    插入与迭代：------------
    map.insert();返回pair<iterator,bool> ###
    三种方式插入：map<int,string> mapStu;
    1）通过pair方式插入对象
    mapStu.insert(pair<int,string>(3,"lis"));
    2)通过value_type的方式插入对象
    mapStu.insert(map<int,string>::value_type(1,"li"));
    3)通过数组方式插入：（该方式存在性能问题）
    mapStu[1]="mm";
    取值操作----------
    string strName = mapStu[3];
    需要注意的是，只有mapStu中存在3，才操作正确
    否则，如果不存在3，则mapStu会自动添加一个3，值默认初始化
    这样就等于无意中添加了一个项。

    map<T1,T2,greater<T1>> mapBB;

    map.begin(),map.end(),map.rbegin(),map.rend();
    构造：
    map(const map&mp);
    map & operator=(const map &mp);
    map.swap(mp);
    map.size()
    map.empty();
    删除：
    map.clear()
    map.erase(pos);
    map.erase(beg,end);
    map.erase(keyElem);按键删除
    ***/
    map<int,string> mapStu;
    pair<map<int,string>::iterator,bool> pairResult =mapStu.insert(pair<int,string>(3,"li"));
    cout<<(pairResult.first)->first<<(pairResult.first)->second<<pairResult.second<<endl;
    map<int,string,less<int>> mapAA;
    cout<<mapStu.size()<<endl;

    /***************
    只有map和set有按照元素进行删除的
    其他的容器都是按照迭代器删除的
    而且也只有map和set有内置的find函数
    map.find(key);返回迭代器，不存在的话返回map.end();
    map.count(keyElem);
    map.low_bound(keyElem); 第一个>=
    map.upper_bound(keyElem); 第一个>

    map.equal_range(keyElem)
    **/
    map<int,string>::iterator it_map = mapStu.find(3);
    if(it_map == mapStu.end()){
        //
    }else{
        pair<int,string> pairStu =*it_map;
        int iID = pairStu.first;
        string stuName = pairStu.second;
    }

}



#endif // LEARNING_MAP_H_INCLUDED
