#include "vector.h"
#include <iostream>
#include <deque>
#include <algorithm>

using namespace mycollection;
using std::cin;
using std::cout;
using std::endl;

vector<int> nums;
int main(){
    int n;
    cout<<"How many numbers do you want insert in vector?"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    cout<<"nums.front() is "<<*nums.begin()<<endl;
    cout<<"nums.end() is "<<nums.back()<<endl;
    cout<<"nums.size() is "<<nums.size()<<endl;
}