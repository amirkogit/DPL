#include <sstream>

#include "htmlelement.h"
#include "htmlbuilder.h"

HtmlElement::HtmlElement()
{

}

HtmlElement::HtmlElement(const std::string &name, const std::string &text)
    :_name(name), _text(text)
{

}

std::string HtmlElement::ToString(int indent) const
{
    std::ostringstream oss;
    std::string ind(_indent_size * indent, ' ');

    oss << ind << "<" << _name << ">" << std::endl;

    if(_text.size() > 0) {
        oss << std::string(_indent_size * (indent + 1), ' ') << _text << std::endl;
    }

    for(const auto& e : _elements) {
        oss << e.ToString(indent + 1);
    }

    oss << ind << "</" << _name << ">" << std::endl;
    return oss.str();
}

std::unique_ptr<HtmlBuilder> HtmlElement::Build(std::string root_name)
{
    return std::make_unique<HtmlBuilder>(root_name);
}
