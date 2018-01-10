#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Sales_data;
std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

class Sales_data {
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data() = default;
    Sales_data(const std::string &s):bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(n*p){ }
    Sales_data(std::istream &is) { read(is, *this); }

    std::string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data& rhs){
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }

private:
    inline double avg_price() const{
        return units_sold ? revenue/units_sold : 0;
    }

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}


int main()
{
    vector<Sales_data> vc{Sales_data{"C"},Sales_data{"A"},Sales_data{"B"}};
    sort(vc.begin(),vc.end(),[](Sales_data& s1,Sales_data& s2){return s1.isbn()<s2.isbn();});
    for(auto i:vc){
        cout<<i.isbn()<<" ";
    }
    return 0;
}
