#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<list>

using namespace std;
template<typename T>
void print_my(const T& s)
{
    for(auto i: s){
        cout<<i<<" ";
    }
    cout<<endl;
}


int main()
{
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    list<int> res1;
    copy(vec.begin(),vec.end(),back_inserter(res1));
    print_my(res1);
    list<int> res2;
    copy(vec.begin(),vec.end(),front_inserter(res2));
    print_my(res2);
    list<int> res3;
    copy(vec.begin(),vec.end(),inserter(res3,res3.begin()));//the same as res3.end()
    print_my(res3);
    return 0;
}

