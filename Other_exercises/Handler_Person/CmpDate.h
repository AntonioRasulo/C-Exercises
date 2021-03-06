#ifndef CMP_DATE_H
#define CMP_DATE_H

#include "Person.h"

struct CmpDate{
        bool operator()(Person& a, Person& b) const{
                if(a.GetYear() != b.GetYear())
                        return a.GetYear() > b.GetYear();
                else if(a.GetMonth() != b.GetMonth())
                        return a.GetMonth() > b.GetMonth();
                else
                        return a.GetDay() > b.GetDay();
        }
};
#endif
