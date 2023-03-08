#include <bits/stdc++.h>
#include <sstream>
using namespace std;
/*
    这节课讲解流的内容，也解答我长期的疑问:为什么关掉流同步会是程序变快很多，也是卡常的技巧
*/
void Stringstream_1();
void istringstream_1();
void istring_and_ostring();
void PrintstreamState(const istream &iss);
int stringToInteger(const string& s);
void stringToIntegerTest();
void bufferedExperiment(ostream &oss);
int mindlessWork();

int main(){

        /*
        
        */
    //istringstream_1();
    //string_and_ostring();
    //stringToInteger("543");
    //stringstreamState();
    //stringToIntegerTest();
    //bufferedExperiment(cout); //直观感受cout缓冲区导致程序运行会很慢
    //bufferedExperiment(cerr);

}
void Stringstream_1(){
    stringstream s;
    string str;
    /*
        读入一行
    */   
    int num;
    vector<int>nums;
    while(getline(s,str,',')){
        num=stoi(str);
        nums.push_back(num);
    }
    for(auto x:nums){
        cout<<x<<" "<<endl;
    }
}
void istringstream_1(){
    istringstream iss("16.9 Ounces");
    double amount;
    string unit;
    iss >> amount;
    iss >> unit;
    cout << amount/2 << " " << unit << endl;
}
void istring_and_ostring(){
    istringstream iss("Test ");
    ostringstream oss;
    string str;
    iss >> str;
    oss << str;
    cout<< oss.str()<<endl;
}
void PrintstreamState(const istream &iss){ //直观判断流读入的状态
    cout<<"State bits:";
    cout<<(iss.good() ? "G" : "-");
    cout<<(iss.fail() ? "F" : "-");
    cout<<(iss.eof() ? "E" : "-");
    cout<<(iss.bad() ? "B" : "-");
    cout<<"\n";
}
int stringToInteger(const string& s){
    istringstream iss(s);
    PrintstreamState(iss);
    int result;
    iss >> result;
    if(iss.fail()) throw domain_error("no value in that beginning");
    //等同 if(!(iss >> result))
    if(!iss.eof()) throw domain_error("more than a single valid int");
    /*  等同于
        char remain;
        if(iss >> remain)
    */
    /*
        fail 是读入失败
        eof 是读入文件最后一行返回true
    */
    PrintstreamState(iss);
    return result;
}
void stringToIntegerTest(){
    while(true){
        cout<<"Please input string"<<endl;
        string str;
        if(!getline(cin,str)) throw domain_error("getline Fail");
        /*
            除以零 new 内存不足，分配失败等 会出现异常 此时需要使用throw 将异常抛出
            domain_error 此类用作所有引发报告域错误（按数学方式，而不是网络）的异常的基类。
        */
        cout<<"You typed in : "<<str<<endl;
        int result = stringToInteger(str);
        cout<<"As an integer is "<<result<<endl;
        cout<<"its half is "<<result/2<<endl;
    }  
}
void bufferedExperiment(ostream &oss){
    oss << "CS";
    mindlessWork();
    oss << "106";
    mindlessWork();
    oss << "L";
    mindlessWork();
    oss << endl;
}
int mindlessWork(){
    double ans=0;
    for(int i=0;i<400000000;i++){
        ans+=i/999959;
    }
    return ans;
}