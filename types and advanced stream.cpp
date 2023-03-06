#include <iostream>
#include <utility>
#include <tuple>
void auto_1(){
    auto prices = make_pair(3.4,5); // -> pair<double,int>
    auto values = make_tuple(3,4,"hi");// -> tuple<int,int,char*>

    prices.first = prices.second;// -> {5.0,5}
    get<0>(values) = get<1>(values);//get<n>()

    auto [a,b] =prices;
    const auto& [x,y,z] = values;

}
int main(){

}
