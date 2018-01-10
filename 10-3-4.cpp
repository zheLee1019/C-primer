#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
int main()
{
    vector<int> vc={ 1, 2, 3, 4, 5, 6, 6, 6, 2 };
    int result=accumulate(vc.cbegin(),vc.cend(),0);
    cout<<result;
    vector<double> vd={2.3,4.6,5.2};
    double res=accumulate(vd.cbegin(),vd.cend(),0.0);
    cout<<endl<<res<<endl;
    return 0;
}
