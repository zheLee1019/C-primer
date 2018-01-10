#include<algorithm>
#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<list>
using namespace std;

int main()
{
    vector<int> vec{0,1,2,3,4,5,6,7,8,9,10};//10-34
    ostream_iterator<int> out(cout," ");
    copy(vec.crbegin(),vec.crend(),out);
    cout<<endl;
    for(auto i=vec.end()-1;i!=vec.begin()-1;--i){//10-35
        cout<<*i<<" ";
    }
    cout<<endl;
    list<int> lst{1,2,3,4,0,5,6,7,8,0,9};//10-36
    auto find_0=find(lst.crbegin(),lst.crend(),0);
    cout<<distance(find_0,lst.crend())<<endl;
    list<int> rlist;
    copy(vec.cbegin()+4,vec.cbegin()+7,front_inserter(rlist));//10-37
    copy(rlist.cbegin(),rlist.cend(),out);
    return 0;
}

