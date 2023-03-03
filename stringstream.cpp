#include <bits/stdc++.h>
#include <sstream>
using namespace std;
void Stringstream_1(){
    stringstream s;
    string str;
    /*
        读如一行
    */   
    getline(cin , str);
    s << str;
    int num;
    vector<int>nums;
    while(s >> num){
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
void PrintstreamState(const istream &iss){
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
    PrintstreamState(iss);
    return result;
}
void stringToIntegerTest(){
    while(true){
        cout<<"Please input string"<<endl;
        string str;
        if(!getline(cin,str)) throw domain_error("getline Fail");
        cout<<"You typed in : "<<str<<endl;
        int result = stringToInteger(str);
        cout<<"As an integer is "<<result<<endl;
        cout<<"its half is "<<result/2<<endl;
    }  
}
int main(){

        /*
        
        */
    //istringstream_1();
    //string_and_ostring();
    //stringToInteger("543");
    //stringstreamState();
    stringToIntegerTest();

} 