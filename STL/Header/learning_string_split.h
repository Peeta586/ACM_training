#ifndef LEARNING_CIN_H_INCLUDED
#define LEARNING_CIN_H_INCLUDED
#include <iostream>
#include<vector>
#include<string>
#include <cstdlib>
//#include<cstring>

using namespace std;

vector<int> split(const string &str, const string & delim){
    vector<int> vecInt;
    if ("" == str){
        return vecInt;
    }
    string str_new=str; //判断有无空格的情况
    if (str_new[str_new.length()-1]!=' '){
         str_new += delim;
    }

    size_t pos= str_new.find(delim);
    size_t size_str = str_new.size();//str.length();

    while(pos != string::npos){
        string x = str_new.substr(0,pos);
        vecInt.push_back(atoi(x.c_str()));
        str_new = str_new.substr(pos+1,size_str);
        pos = str_new.find(delim);
    }
    return vecInt;
}

void TestCin(){
    char c[20];
    int d;
    vector<int> vecInt;
    //cin.getline()实际上有三个参数，cin.getline(接受字符串的看哦那间m,接受个数5,结束字符)
//当第三个参数省略时，系统默认为'\0'
//如果将例子中cin.getline()改为cin.getline(m,5,'a');当输入jlkjkljkl时输出jklj，输入jkaljkljkl时，输出jk
/********
首先是cin.getline()
**/
    //cin.getline(c,20);

/**************
其次是string库中的
getline(string)库函数

上面这段代码，如果输入abc，那么需要按两次回车键才能显示abc（在VC6中），
因为getline有三个参数，第三个参数是字符串的结束符，
也就是当getline遇到这个结束符时，就不在接受输入了，
比如写成 getline(cin,st,'s'); 即使输入的是abcsabc 那么也只会显示 abc ，
因此对于上面出现的情况，有人说getline默认情况下以回车('\n')作为结束符，
第一次按回车表示字符串结束，第二次按回车才开始输出。

######注意：
strlen的参数是char *
而string类型有成员函数length计算其长度
*/
    string str;
    getline(cin,str);
    cout<<"str:"<<str<<endl;
    cout<<"str length:"<<str.length()<<endl;

    vector<int> vec_int = split(str,"+");

    switch(str[str.length()-1]){
case ' ':
    cout<<"空格"<<endl;
    break;
case '\n':
    cout<<"回车"<<endl;
    break;
    }

    cout<<"str strlen:"<<strlen(str.c_str())<<endl;

/******
    while((c=cin.get())!='\n') //对于最后又空格的情况不适用
    {
        cin.unget();
        cin>>d;
        vecInt.push_back(d);
    }
*/

    for(vector<int>::iterator it=vec_int.begin();
    it!=vec_int.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

#endif // LEARNING_CIN_H_INCLUDED
