#include<algorithm>
#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<list>
using namespace std;

int main()
{
    list<string> lst{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    lst.sort();
    lst.unique();
    for(auto i:lst){
        cout<<i<<" ";
    }
    return 0;
}

