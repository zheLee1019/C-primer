#include<iostream>
#include<vector>
#include<memory>
using namespace std;
vector<int>* allocvec()
{
    return new vector<int>;
}
void read(vector<int>* p1)
{
    int i;
    while(cin>>i){
        p1->push_back(i);
    }
}
void print(vector<int>* p1)
{
    for(const auto& i:(*p1)){
        cout<<i<<" ";
    }
}
int main()
{
    auto p=allocvec();
    read(p);
    print(p);
    delete p;
    return 0;
}