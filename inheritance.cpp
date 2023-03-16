#include <bits/stdc++.h>
using namespace std;
class Cfather{
public:
    virtual void fun() {
        cout<<"This is father"<<endl;
    }
    void Test(){

    }
    Cfather(){
        cout<<"construct Cfaher"<<endl;
    }
    ~Cfather(){
        cout<<"Desrtuct Cfather"<<endl;
    }
};

class Cson : public Cfather{
public:
    virtual void fun() {
        cout<<"This is son"<<endl;
    }
    Cson(){
        cout<<"construct Cson"<<endl;
    }
    ~Cson(){
        cout<<"Destruct Cson"<<endl;
    }
};
void Polymorphism(){
    Cson son;
    Cfather *p = &son;
    p->fun();// -> 用于指针
    Cfather & tt = son;
    tt.fun();// . 用于对象

    int t = 123;
    int *pp = &t;
    *pp = 456;
    cout<< t <<endl;

    Cfather *pq = new Cson();
    //定义一个指向Cfather类型的指针 pq，并用new 创建一个Cson对象，将对象地址传给pq指针
    pq->fun();
    //pq 的静态类型是Cfather 动态指针是Cson，因而调用Cson对象
    Cfather a;
    int *p1 = (int*) &a;
    int *p2 = (int*)pq;
    *p2 = *p1;
    //类型转换，这样其实很危险
    pq->fun();
}
void VirtualDistructor(){
    Cfather *pa = new Cson();
    delete pa;
    /*
    具体来说，构造函数的执行顺序如下：

    执行基类的构造函数；
    按照声明顺序依次执行成员变量的构造函数；
    执行派生类的构造函数。


    而析构函数的执行顺序则是：

    执行派生类的析构函数；
    按照声明顺序依次执行成员变量的析构函数；
    执行基类的析构函数。
    */
}
int main(){
    Polymorphism();
    VirtualDistructor();
}