#include "htmlbuilder.h"

HtmlBuilder::HtmlBuilder(std::string root_name)
{
    _root.SetName(root_name);
}

HtmlBuilder &HtmlBuilder::AddChild(std::string child_name, std::string child_text)
{
    HtmlElement element {child_name, child_text};
    _root.AddElement(element);
    return *this;
}

HtmlBuilder *HtmlBuilder::AddChild2(std::string child_name, std::string child_text)
{
    HtmlElement element {child_name, child_text};
    _root.AddElement(element);
    return this;
}

std::string HtmlBuilder::ToString()
{
    return _root.ToString();
}
