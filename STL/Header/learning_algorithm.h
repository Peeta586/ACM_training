#ifndef LEARNING_ALGORITHM_H_INCLUDED
#define LEARNING_ALGORITHM_H_INCLUDED
#include<vector>
#include<algorithm>
#include<ctime>
/******************
1）容器的通用能力
2）各容器的使用时机（什么时候用）
3）常用算法Algorithm的用法介绍
**/

bool greater_three(int num){
    if(num >= 3)
        return true;
    else
        return false;
}
void show(int num){
    cout<<num<<endl;
}
int increase(int elem){
    return elem+2;
}

void test_alorithem(){
    /*********
    adjacent_find:查找数组中相邻的元素相等的元素。
    */
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(3);
    vecInt.push_back(3);
    vecInt.push_back(5);
    vecInt.push_back(6);
    vector<int>::iterator it = adjacent_find(vecInt.begin(),vecInt.end());
    cout<<*it<<endl;

    set<int> setInt;
    setInt.insert(1);
    setInt.insert(2);
    setInt.insert(5);
    setInt.insert(3);
    setInt.insert(4);
    bool bFind = binary_search(setInt.begin(),setInt.end(),6);
    cout<<bFind<<endl;
    /******
    count进行计数，某个元素在数组中出现多少次;

    count_if(beg,end,if_function), 满足条件的元素个数，其中
    bool if_function（）中写条件，条件成立返回true
    */
    int mCount = count(vecInt.begin(),vecInt.end(),2);
    cout<<"vecInt's Count is :"<<mCount<<endl;
    int Mcount =count_if(vecInt.begin(),vecInt.end(),greater_three);
    cout<<"vecInt's Count is :"<<Mcount<<endl;
    /*****************
    find（beg,end,num）查找元素
    find_if(beg,end,if_function)
    **/
    vector<int>::iterator it_n =find(vecInt.begin(),vecInt.end(),8);
    if(it_n ==vecInt.end()){
        cout<<"not find"<<endl;
    }
    /*****************
    merge() :
    merge(A.beg,A.end,B.beg,B.end,C.beg)
    将A,B合并放到C中
    **/
    vector<int> vecA={1,2,3,4,5};
    vector<int> vecB ={6,7,8,9};
    vector<int> vecC;
    vecC.resize(9);
    merge(vecA.begin(),vecA.end(),vecB.begin(),vecB.end(),vecC.begin());
    for(vector<int>::iterator it=vecC.begin();it!=vecC.end();++it){
        cout<<*it<<endl;
    }
    /*****************
    sort(beg,end,cmp);
    random_shuffle(); 随机打乱
    reverse(beg,end);
    copy(A.beg,A.end,B.begin);

    replace(A.beg,A.end,old_elem,new_elem);
    replace_if(A.beg,A.end,if_funtion,new_value);
    把符合if_function条件的替换成new_value

    swap(vecA,vecB);交换
    */
    srand(time(0));
    random_shuffle(vecInt.begin(),vecInt.end());
    string name("LIshimgn");
    random_shuffle(name.begin(),name.end());
    replace(vecC.begin(),vecC.begin(),3,0);

    /*******************
    accumulate(A.beg,A.end,base_value):
    base_value+A中所有值，

    fill(A.beg,A.end,value):用value填充A
    **/
    int iSum=accumulate(vecA.begin(),vecA.end(),20);
    cout<<iSum<<endl;
    fill(vecC.begin(),vecC.end(),8);
    vector<int>::iterator iii = max_element(vecA.begin(),vecA.end());
    for(vector<int>::iterator it=vecC.begin();it!=vecC.end();++it){
        cout<<*it<<endl;
    }
    /**********************
    集合的并集，交集，差集
    A,B,C可以是任意容器
    A∪B->C  不够的补零
    set_union(A.beg,A.end,B.beg,B.end,C.beg),
    A∩B->C
    set_intersection(A.beg,A.end,B.beg,B.end,C.beg),
    set_difference(A.beg,A.end,B.beg,B.end,C.beg);
    **/

    /*************************
    for_each(A.beg,A.end,function)相当于python中的map，
    即对A每个元素执行一个function操作

    类似的是transform(A.beg,A.end,B.beg,function);
    A的每个元素处理（转换）后，放到B中其中B可以是A
    **/
    int Array[] = {1,2,3,4}; //数组初始化
    vector<int> vecD(Array,Array+sizeof(Array)/sizeof(Array[0]));
    for_each(vecD.begin(),vecD.end(),show);
    transform(vecD.begin(),vecD.end(),vecD.begin(),increase);

}




#endif // LEARNING_ALGORITHM_H_INCLUDED
