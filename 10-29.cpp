#include<algorithm>
#include<iostream>
#include<fstream>
#include<iterator>
using namespace std;

int main()
{
    ifstream fin("/home/lizhe/CLionProjects/learncpp/text",ios::in);
    if(!fin){
        cout<<"err";
    }
    istream_iterator<string> in(fin),end;
    vector<string> res(in,end);
    fin.close();
    ostream_iterator<string> ot(cout," ");
    copy(res.begin(),res.end(),ot);
    return 0;
}

