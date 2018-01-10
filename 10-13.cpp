#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
bool isbigger5(string& input)
{
    return (input.size()>=5)?true:false;
}

int main()
{
    vector<string> vc{"asdfa","ds","das","lksdjlfk","lsdkjflkjlkjlkm"};
    auto end=partition(vc.begin(),vc.end(),isbigger5);
    vc.erase(end,vc.end());
    for(auto i:vc){
        cout<<i<<" ";
    }
    return 0;
}
