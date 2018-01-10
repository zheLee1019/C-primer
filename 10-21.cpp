#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    int cap=10;
    auto f=[&]()->bool{if(cap>0)
    {--cap;return false;}
    else return true;};
    while(!f()){
        cout<<cap<<endl;
    }
    return 0;
}
