#include "buildertest.h"

#include "Builder/person.h"
#include "Builder/personbuilder.h"
#include "Builder/personaddressbuilder.h"
#include "Builder/personjobbuilder.h"

#include <iostream>

void BuilderTest::RunPersonBuilderTest()
{
    std::cout << ">> Running Builder demo\n";
    std::cout << "-----------------------\n";

    Person p = Person::Create()
            .Lives().At("2445 Alameda").WithPostCode("94501").In("CA")
            .Works().At("Apple").AsA("Engineer").Earning(50000);

    std::cout << p << std::endl;
}
