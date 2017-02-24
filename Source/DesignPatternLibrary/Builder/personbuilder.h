#ifndef PERSONBUILDER_H
#define PERSONBUILDER_H

#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilder
{
public:
    PersonBuilder()
        : _person(_p)
    {

    }

    operator Person()
    {
        return std::move(_person);
    }

protected:
    Person& _person;

    explicit PersonBuilder(Person& person)
        : _person(person)
    {

    }

public:
    // builder facets
    PersonAddressBuilder Lives();
    PersonJobBuilder Works();

private:
    Person _p;
};

#endif // PERSONBUILDER_H
