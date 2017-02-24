#ifndef HTMLBUILDER_H
#define HTMLBUILDER_H

#include "htmlelement.h"

class HtmlBuilder
{
public:
    HtmlBuilder(std::string root_name);

    HtmlBuilder& AddChild(std::string child_name, std::string child_text);

    // pointer based - to work with unique_ptr<>
    HtmlBuilder *AddChild2(std::string child_name, std::string child_text);

    std::string ToString();

private:
    HtmlElement _root;
};

#endif // HTMLBUILDER_H
