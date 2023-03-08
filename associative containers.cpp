#include <iostream>
#include <set>
#include <vector>
#include <string>

using std::cin;
using std::cout;

void Stl_Work1(std::set<int> &s){//若不引用，则会调用构造函数，所以速度会快
    auto a = s.begin();
}
void Stl_Work2(std::set<int> s){
    auto a=s.begin();
}
void STL_Work3(){
    std::set<int>s;
    s.insert(1);
    int t = clock();
    for(int i=0;i<10000020;i++){
        Stl_Work1(s);
    }
    // cout<<"___"<<std::endl;
    cout << clock() - t << std::endl;
    t = clock();
    for(int i=0;i<10000020;i++){
        Stl_Work2(s);
    }
    cout << clock() - t << std::endl;
}
void vector_find(std::vector<int> &vec,int Elem){
    auto it =std::find(vec.begin(),vec.end(),Elem);
    if(it != vec.end()){
        cout<<"No"<<std::endl;
    }else{
        cout<<"have"<<std::endl;
    }

}
int main(){
    STL_Work3();
}