#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
    map<string,vector<int>> mp{{"Peter",{1,23,4,5}},{"Lucy",{6,7,8,9,10}}};
    auto i=mp.find("Lucy");
    cout<<i->first<<endl;
    for(auto ii:i->second){
        cout<<ii<<" ";
    }
    return 0;
}

