#include <bits/stdc++.h>
using namespace std;
class P{
    public:
        P(int a,int b){
            cout<<"a = "<<a<<", b= "<<b<<endl;
        }
        P(initializer_list<int> list){
            cout<<"P(initializer_list<int>,value = "<<endl;;
            for(auto x:list){
                cout<<x<<endl;
            }
        }
};
void vector_1(initializer_list<string>v1){
    for(auto it=v1.begin();it!=v1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

}
void gouzaohanshu(){
    P p(1,2);//调用第一个构造函数
    P q{1,2};//调用第二个构造函数
    P r{1,2,3};//调用第二个构造函数
    P s{1,2};//调用第二个构造函数
    P t(3,4);//调用第一个构造函数
}
void vector_operator(){
    vector<int>vec(20);
    generate(vec.begin(),vec.end(),rand);
    sort(vec.begin(),vec.end());
    copy(vec.begin(),vec.end(),ostream_iterator<int>(cout,"\n"));
}
void stream__iterator(){
    cout<<"please input some numbers"<<endl;
    istream_iterator<int>int_in(cin);
    istream_iterator<int>int_eof;
    vector<int>vec;
    vector<int>voc;
    while(int_in != int_eof){
        vec.push_back(*int_in);
        int_in++;
    }
    for(auto data :vec){
        cout<<data<<endl;
    }
    //等价于 vector<int>vec(int_in,int_eof)

    ostream_iterator<string> out(cout);
    *out="test";
    cout<<endl;
    ostream_iterator<int>out_1(cout,"\n");
    *out_1=1;
    *out_1=123456;
    *out_1=114514;


    vector<int>list;
    for(int i=0;i<10;i++){
        list.push_back(i);
    }
    ostream_iterator<int> out_it(cout," ");
    copy(list.begin(),list.end(),out_it);
}
int main(){
    gouzaohanshu();
    stream__iterator();
}