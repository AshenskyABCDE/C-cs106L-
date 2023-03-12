#include <bits/stdc++.h>
using namespace std;

//------构造函数------- 
class box {//class 默认把元素设为私有
    public :
        int hight,length,weith;
        int S(void){//内部函数
            return hight * length * weith;
        }
        int S1(void);
        box();//构造函数
};
int box::S1(void){
    return hight * length * weith;
}
box::box(){
    cout<<"You are running a function"<<endl;
}

class Line {
    public :
        void setlength(double len);
        double getlength(void);
        Line(double len);
    private:
        double length;
};
void Line::setlength(double len){
    length = len;
}
double Line::getlength(void){
    return length;
}
Line::Line(double len){
    cout<<"len is "<<len<<endl;
    length=len;
}


template <class numtype>
class Compare{
    public :
        Compare(numtype a,numtype b){
            x = a;
            y= b;
        };
        numtype max(){ return (x > y) ? x : y;}
        numtype min(){ return (x < y) ? x : y;}
    private:
        numtype x,y;
};

template <typename T> // 指定参数类型
pair<T,T> my_minmax(T a,T b){
    if(a < b)return {a,b};
    else return {b,a};
}
void Test(){
    auto [min1,max1] = my_minmax<long long>(1e18,1e9+7);
    cout<<min1<<" "<<max1<<endl;
}
struct node{
    int data;
};
//To finish a template that whatever container you can find the number upper than val in the half second 
template<typename InPut,typename DataType>
int count0ccurences(InPut begin,InPut end,DataType &val){
    int count = 0;
    for(auto iter = begin ; iter != end ;iter ++){
        if(*iter >=val)count ++;
    }
    return count;
}

template<typename InPut>
InPut read(){
    InPut x;
    cin>>x;
    return x;
}
template<typename InPut>
void read1(InPut &x){
    cin>>x;
}
template<typename OutPut>
void write(OutPut x){
    x = x+1;
    cout<<x<<endl;
}
template<typename T>
T calc() {
    return  ;
}
void Test_1(){
    vector<int> phoneNumber{5,5,5,8,2,6,5,5,3,5};
    int val=0;
    cin>>val;
    int times1 = count0ccurences(phoneNumber.begin() + phoneNumber.size()/2 ,
                                 phoneNumber.end(),val);
    cout<<times1<<endl;
}
int main(){
    //Line line(10.0);
    Test();
    node * t;
    //Test_1();
    char tt;
    // tt = read<char>();
    // cout<<"now tt is "<<tt<<endl;
    // read1(tt);
    // cout<<"now tt is "<<tt<<endl;
    // write(tt);
    int a = calc<int>();
    cout << a << endl;
}