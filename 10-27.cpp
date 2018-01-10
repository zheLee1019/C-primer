#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<list>

using namespace std;

int main()
{
    vector<int> vec{ 1, 1, 3, 3, 5, 5, 7, 7, 9 };
    list<int> res;
    unique_copy(vec.begin(),vec.end(),back_inserter(res));
    for_each(res.begin(),res.end(),[](const int& s){cout<<s<<" ";});
    return 0;
}

