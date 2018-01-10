//
// Created by lizhe on 17-12-20.
//
#include"QueryResult.h"
void print_12(std::ostream& ot,const QueryResult& qr)
{
    auto ss=qr.ptr2map->find(qr.word);
    if(ss!=(*qr.ptr2map).end()){
        const auto& search=ss->second;
        ot<<qr.word<<" occurs "<<search.size()<<" times"<<std::endl;
        for(const auto& item:search)
        {
            std::ostringstream temp;
            temp<<"(line "<<item<<") "<<(*qr.ptr2vec)[item-1]<<std::endl;
            ot<<temp.str();
        }
    }
    else{
        ot<<"cannot found"<<std::endl;
    }
    return;
}