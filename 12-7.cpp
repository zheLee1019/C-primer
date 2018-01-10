#include<iostream>
#include<vector>
#include<memory>
using namespace std;
shared_ptr<vector<int>> allocvec()
{
    return make_shared<vector<int>>();
}
void read(shared_ptr<vector<int>> p1)
{
    int i;
    while(cin>>i){
        p1->push_back(i);
    }
}
void print(shared_ptr<vector<int>> p1)
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
    return 0;
}