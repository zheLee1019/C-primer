//
// Created by lizhe on 17-12-20.
//
#include"QueryResult.h"
void print_12(std::ostream& ot,const QueryResult& qr)
{
    if(qr.ptr2set==nullptr)
    {
        ot<<"cannot found"<<std::endl;
    }
    else
    {
        ot<<qr.word<<" occurs "<<qr.ptr2set->size()<<" times"<<std::endl;
        for(const auto& item:(*qr.ptr2set))
        {
            std::ostringstream temp;
            temp<<"(line "<<item<<") "<<(*qr.ptr2vec)[item-1]<<std::endl;
            ot<<temp.str();
        }
    }
    return;
}