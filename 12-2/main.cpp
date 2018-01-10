#include<iostream>

#include "StrBlob.h"

using namespace std;

int main()
{
    const StrBlob csb{"hello","world","lee"};
    StrBlob sb{"HELLO","WORLD","ZECH"};

    cout<<csb.front()<<" "<<csb.back()<<endl;
    sb.back()="lee";
    cout<<sb.front()<<" "<<sb.back()<<endl;
    return 0;
}