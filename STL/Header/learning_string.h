#ifndef LEARNING_STRING_H_INCLUDED
#define LEARNING_STRING_H_INCLUDED
#include<string>
#include<exception>
using namespace std;


bool chkRotation(string A, int lena, string B, int lenb) {
    // write code here
    if(lena != lenb)
        return false;
    string AA = A.append(A);
    int i=0;
    while(i<AA.length()-lenb){
        if(B.compare(AA.substr(i,B.length()))==0){
            return true;
        }else{
            i++;
        }
    }
    return false;
}

void test_string(){
    /**
    构造函数：
    1）string()
    2) string(const string & str);
    3) string(const char *s);
    4) string(int n, char c);

    **/
    string str = string(); //1)
    string str5;//1)
    string str1 = string("234"); //3) string(const char *s)
    string str2 = string(str1); //2)
    string str3 = string(5,'r');

    cout<<str<<str1<<str2<<str3<<endl;
    /**
    存取字符操作：
    用于读取
    1）下标方式读取const char & operator[](int n) const;
    2) const char & at(int n) const;
    用于赋值
    3) char & operator[](int n);
    4) char & at(int n);
    ***********************
    at和[]的区别：
    at越界时会抛出异常，而[]在刚好越界返回(char)0,再往后越界抛出异常；

    **/
    //1),2)
    char s =str1.at(1);
    char s1 = str1[1];
    cout<<s<<s1<<endl;

    //3)4)
    str1.at(1) = 'h';
    cout<<str1<<endl;
    str1[1] = 'm';
    cout<<str1<<endl;
    char c;
    try{
        c =str1[3]; //刚好越界没有异常抛出
    }catch (exception & e){
        cout<<c<<" error"<<endl;
    }
    /**
    const char ->string
    const char*c_str() const;

    string拷贝到char* 指向的内存中,从pos开始n个字符拷贝到s中
    int copy(char *s,int n,int pos=0) const;

    ***/
    string str_name("lishiming");
    const char * c_name= str_name.c_str(); //作为实例对象的成员函数进行调用
    cout<<c_name<<endl;

    char *c_name1 = new char[5];
    str_name.copy(c_name1,4,3);
    cout<<c_name1<<endl;

    /**
    string的长度
    int length() const; 后面const表示不会更改成员变量的值
    bool empty() const;
    **/
    cout<<str_name.length()<<endl;
    cout<<str.empty()<<' '<<str1.empty()<<endl;
    /***
    string & operator=(const string &s);
    string & assign(const char *s);
    string & assign(const char *s, int n);
    string & assign(const string &s);
    string & assign(int n,char c);n个字符c赋值给字符串
    string & assign(const string &s,int start,int n);

    **/
    string name = str_name;
    const char * char_name ="liok";
    string name1,name2;
    name1.assign("liok");  //成员函数
    name2.assign(char_name,2);
    cout<<name1<<" "<<name2<<endl;
    /**
    字符串的链接：
    string & operator+=(const string&s);
    string &operator+=(const char*s);
    string &append(const char*s);链接到字符串结尾
    string &append(const char*s,int n);s的前n个字符连接到字符串结尾
    string &append(const string&s) 等于operator+=()
    string &append(const string&s,int pos,int n)
    string &append(int n,char c);

    **/
    string ap_str ="lishiming";
    string append_str="My name is";
    append_str +=ap_str;
    cout<<append_str<<endl;
    append_str.append(ap_str);
    cout<<append_str<<endl;
    append_str.append(ap_str,3,5);
    cout<<append_str<<endl;
    append_str.append(5,'c');
    cout<<append_str<<endl;
    /**
    比较：
    int compare(const string&s)const;
    int compare(const char *s)const;
    >时返回1，<返回-1，==时返回0
    **/
    cout<<append_str.compare(ap_str)<<endl;//append_str与ap_str比较
    string ss("a"),sss("b"); //要双引号
    cout<<sss.compare(ss)<<endl;
    /**
    string substr(int pos=0,int n=npos)const;
    返回pos开头的npos个字符的子字符串
    ***/
    string substr_app_str = append_str.substr(0,10);
    cout<<substr_app_str<<endl;

    /************************************************************
    int find(char c,int pos=0) const;从pos开始查找字符c
    int find(const char*s, int pos=0)const;
    int find(const string &s,int pos=0)const;从pos开始查找字符串s
    find函数如果查抄不到，返回-1；
    从后向前查找字符
    int rfind(char c,int pos=0) const;从pos开始查找字符c
    int rfind(const char*s, int pos=0)const;
    int rfind(const string &s,int pos=0)const;从pos开始查找字符串s
    int find_first_of(const string&str,int pos=0)从pos开始，查找第一个匹配str字符串中任何一个字符的字符位置

    */
    cout<<append_str.find('m')<<endl;
    cout<<append_str.rfind('m')<<endl;
    /****
    string & insert(int pos,const char*s);
    string &insert(int pos,const string &s);
    pos位置插入字符串s
    string & insert(int pos,int n,char c);
    ***************删除
    string&erase(int pos=0,int n=npos);
    删除pos开始的n个字符，返回修改后的字符串
    **/
    ap_str.insert(2,"*****");
    ap_str.insert(12,1,'*');
    cout<<ap_str<<endl;

    append_str.erase(16,10);
    cout<<append_str<<endl;
    /************************
    替换：
    string &replace(int pos,int n,const char*s);删除从pos开始的n个字符，然后在pos处插入串s
    string &replace(int pos,int n,const string &s);

    void swap(string &s2) //交换当前字符串与s2
    */
    append_str.replace(20,10,str1);
    cout<<append_str<<endl;
    append_str.swap(ap_str);
    cout<<append_str<<endl;
}




#endif // LEARNING_STRING_H_INCLUDED
