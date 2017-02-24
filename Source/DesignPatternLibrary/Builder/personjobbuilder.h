#ifndef PERSONJOBBUILDER_H
#define PERSONJOBBUILDER_H

#include "Builder/personbuilder.h"

class PersonJobBuilder : public PersonBuilder
{
    typedef PersonJobBuilder Self;

public:
    explicit PersonJobBuilder(Person& person)
        : PersonBuilder(person)
    {
    }

    Self& At(std::string company_name)
    {
        _person._company_name = company_name;
        return *this;
    }

    Self& AsA(std::string position)
    {
        _person._position = position;
        return *this;
    }

    Self& Earning(int annual_income)
    {
        _person._annual_income = annual_income;
        return *this;
    }
};

#endif // PERSONJOBBUILDER_H



