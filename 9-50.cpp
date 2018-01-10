#include <iostream>
#include<vector>
#include<string>
using namespace std;
int calsumint(vector<string>&ipt)
{
    int temp=0;
    int sum=0;
    for(auto i:ipt)
    {
        temp=stoi(i);
        sum+=temp;
    }
    return sum;
}
double calsumdouble(vector<string> & ipt)
{
    double temp=0;
    double sum=0;
    for(auto i:ipt){
        temp=stod(i);
        sum+=temp;
    }
    return sum;
}
int main() {
    vector<string> ipt{"12","25","100"};
    cout<<calsumint(ipt);
    vector<string> iptd{"12.4","25.8","100.3"};
    cout<<endl<<calsumdouble(iptd);
    return 0;
}