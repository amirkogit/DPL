#include "buildertest.h"

#include "Builder/person.h"
#include "Builder/personbuilder.h"
#include "Builder/personaddressbuilder.h"
#include "Builder/personjobbuilder.h"

#include "Builder/HTML/htmlelement.h"
#include "Builder/HTML/htmlbuilder.h"
#include "Builder/Groovy/groovystyle.h"

#include <iostream>

void BuilderTest::RunPersonBuilderTest()
{
    std::cout << ">> Running Builder demo (PersonBuilder)\n";
    std::cout << "------------------------------------------\n";

    Person p = Person::Create()
            .Lives().At("2445 Alameda").WithPostCode("94501").In("CA")
            .Works().At("Apple").AsA("Engineer").Earning(50000);

    std::cout << p << std::endl;
}

void BuilderTest::RunHTMLBuilderTest()
{
    std::cout << ">> Running Builder demo (HTML builder)\n";
    std::cout << "------------------------------------------\n";

    HtmlBuilder builder {"html"};
    builder.AddChild("head","Hello world").AddChild("title", "Welcome !!");
    std::cout << builder.ToString() << std::endl;

    auto builder2 = HtmlElement::Build("ul");
    builder2->AddChild2("li", "hello")->AddChild2("li","world");
    std::cout << builder2->ToString() << std::endl;
}

void BuilderTest::RunGroovyStyleTest()
{
    std::cout << ">> Running Builder demo (Groovy style builder)\n";
    std::cout << "-------------------------------------------------\n";

    std::cout <<
        P {
            Img {"http://google.com"}
        }
    << std::endl;
}
