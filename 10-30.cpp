#include<algorithm>
#include<iostream>
#include<fstream>
#include<iterator>
using namespace std;

int main()
{
    istream_iterator<int> in(cin),eof;
    vector<int> res(in,eof);
    if(res.size()>1){
        sort(res.begin(),res.end(),[](const int& i1,const int& i2){return i1<i2;});
    }
    ostream_iterator<int> out(cout," ");
    copy(res.cbegin(),res.cend(),out);
    return 0;
}

