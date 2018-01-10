#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<functional>
using namespace std;
using namespace std::placeholders;
bool check_size(const string& s,string::size_type sz)
{
    return s.size()<sz;
}
int main()
{
    string expre{"happy"};
    vector<int> mark{0,1,2,3,4,5,6,7,8,9,10};
    auto res=find_if(mark.begin(),mark.end(),bind(check_size,expre,_1));
    cout<<*res;
    return 0;
}
