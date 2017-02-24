#ifndef PERSONADDRESSBUILDER_H
#define PERSONADDRESSBUILDER_H

#include "Builder/personbuilder.h"

class PersonAddressBuilder : public PersonBuilder
{
    typedef PersonAddressBuilder Self;

public:
    explicit PersonAddressBuilder(Person& person)
        : PersonBuilder(person)
    {

    }

    Self& At(std::string street_address)
    {
        _person._street_address = street_address;
        return *this;
    }

    Self& WithPostCode(std::string post_code)
    {
        _person._post_code = post_code;
        return *this;
    }

    Self& In(std::string city)
    {
        _person._city = city;
        return *this;
    }
};

#endif // PERSONADDRESSBUILDER_H
