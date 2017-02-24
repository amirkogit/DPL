#ifndef PERSON_H
#define PERSON_H

#include <string>

class PersonBuilder;

class Person
{
public:
    static PersonBuilder Create();

    Person(Person&& other)
        : _street_address(std::move(other._street_address)),
          _post_code (std::move(other._post_code)),
          _city (std::move(other._city)),
          _company_name (std::move(other._company_name)),
          _position (std::move(other._position)),
          _annual_income (std::move(other._annual_income))
    {

    }

    Person& operator = (Person&& other)
    {
        if(this == &other) {
            return *this;
        }
        _street_address = std::move(other._street_address);
        _post_code = std::move(other._post_code);
        _city = std::move(other._city);
        _company_name = std::move(other._company_name);
        _position = std::move(other._position);
        _annual_income = std::move(other._annual_income);
        return *this;
    }

    friend std::ostream& operator<< (std::ostream& os, const Person& obj)
    {
        return os << "Street Address: "  << obj._street_address << std::endl
                  << "Post code: " << obj._post_code << std::endl
                  << "City: " << obj._city << std::endl
                  << "Company Name: " << obj._company_name << std::endl
                  << "Position: " << obj._position << std::endl
                  << "Annual Income: " << obj._annual_income << std::endl;
    }

    friend class PersonBuilder;
    friend class PersonAddressBuilder;
    friend class PersonJobBuilder;

private:
    Person() {}

private:
    std::string _street_address;
    std::string _post_code;
    std::string _city;

    std::string _company_name;
    std::string _position;
    int _annual_income;
};

#endif // PERSON_H
