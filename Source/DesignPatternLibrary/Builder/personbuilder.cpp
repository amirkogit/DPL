#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

PersonAddressBuilder PersonBuilder::Lives()
{
    return PersonAddressBuilder(_person);
}

PersonJobBuilder PersonBuilder::Works()
{
    return PersonJobBuilder(_person);
}
