#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
    vector<int> vc={ 1, 2, 3, 4, 5, 6, 6, 6, 2 };
    int val=0;
    cin>>val;
    cout<<"it has "<<count(vc.begin(),vc.end(),val)<<" in this vector."<<endl;
    list<string> ls={"haha","ahah","haha"};
    cout<<"it has "<<count(ls.begin(),ls.end(),"ahah")<<" in this list"<<endl;
    return 0;
}
