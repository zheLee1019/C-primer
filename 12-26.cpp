#include<iostream>
#include"string.h"
#include<string>
#include<memory>
using namespace std;

void inputreverse(int n)
{
    allocator<string> alloc;
    auto p=alloc.allocate(n);
    string temp;
    auto q=p;
    while(cin>>temp&&q!=p+n){
        alloc.construct(q++,temp);
    }
    auto r=p;
    while(r!=q){
        cout<<*r<<" ";
        ++r;
    }
    do{
        alloc.destroy(--q);
    }while(q!=p);
    alloc.deallocate(p,n);
}
int main()
{
    inputreverse(5);
    return 0;
}