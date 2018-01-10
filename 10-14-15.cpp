#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    auto f1=[](int i,int j){return i+j;};//10-14
    cout<<f1(10,14);
    int i=10;
    auto f2=[i](int j){return i+j;};
    cout<<endl<<f2(15)<<endl;
    return 0;
}
