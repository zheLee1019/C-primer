#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
int main()
{
    vector<int> vc={ 1, 2, 3, 4, 5, 6, 6, 6, 2 };
    for(auto i:vc){
        cout<<i<<" ";
    }
    cout<<endl<<"emplace 0"<<endl;
    fill_n(vc.begin(),vc.size(),0);
    for(auto i:vc){
        cout<<i<<" ";
    }
    return 0;
}
