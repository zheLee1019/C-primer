#include <iostream>
#include<vector>
#include<string>
using namespace std;
typedef unsigned long mytp;
class Data{
private:
    unsigned long year;
    unsigned long month;
    unsigned long day;
public:
    void print(){
        std::cout<<"year is"<<year<<",month is"<<month<<",day is"<<day<<std::endl;
    }
    Data(string & input){
        int mode=0;
        int tag=0;
        if(input.find("/")!=input.npos)// 1/1/1990
        {
            mode=1;
        }
        else if(input.find(",")!=input.npos){
            //January 1,1900
            tag=1;
            mode=2;
        }
        else{
            mode=2;
        }
        mytp pos=0;
        mytp inipos=0;
        switch(mode){
            case 1:

                while((pos=input.find_first_of("/",pos))!=input.npos){
                    if(inipos==0){
                        month=stoul(string{input.begin()+inipos,input.begin()+pos});
                        inipos=++pos;
                    }
                    else{
                        day=stoul(string{input.begin()+inipos,input.begin()+pos});
                        inipos=++pos;
                    }
                }
                year=stoul(string(input.begin()+inipos,input.end()));
                break;
            case 2:
                if(tag==1){
                    pos=input.find(",");
                    input[pos]=' ';
                }
                string mark={"0123456789"};
                if(input.find("Jan")<input.size()){
                    month=1;
                }
                if(input.find("Feb")<input.size()){
                    month=2;
                }
                if(input.find("Mar")<input.size()){
                    month=3;
                }
                if(input.find("Apr")<input.size()){
                    month=4;
                }
                if(input.find("May")<input.size()){
                    month=5;
                }
                if(input.find("Jun")<input.size()){
                    month=6;
                }
                if(input.find("Jul")<input.size()){
                    month=7;
                }
                if(input.find("Aug")<input.size()){
                    month=8;
                }
                if(input.find("Sep")<input.size()){
                    month=9;
                }
                if(input.find("Oct")<input.size()){
                    month=10;
                }
                if(input.find("Nov")<input.size()){
                    month=11;
                }
                if(input.find("Dec")<input.size()){
                    month=12;
                }
                if((pos=input.find_first_of(mark))!=input.npos){
                    auto end=input.find_first_of(" ",pos);
                    day=stoul(string{input.begin()+pos,input.begin()+end});
                    pos=end+1;
                }
                year=stoul(string{input.begin()+pos,input.end()});
                break;
        }
    }
};

int main() {
    string input="1/1/1990";
    Data dt(input);
    dt.print();
    string input1="January 1, 1900";
    Data dt1(input1);
    dt1.print();
    string input2="Jan 1 1900";
    Data dt2(input2);
    dt2.print();
    return 0;
}