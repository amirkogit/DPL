#ifndef HTMLELEMENT_H
#define HTMLELEMENT_H

#include <string>
#include <vector>
#include <memory>

class HtmlBuilder;

class HtmlElement
{
public:
    HtmlElement();

    HtmlElement(const std::string& name, const std::string& text);

    std::string ToString(int indent = 0) const;

    static std::unique_ptr<HtmlBuilder> Build(std::string root_name);

    void SetName(std::string name) {
        _name = name;
    }

    void SetText(std::string text) {
        _text = text;
    }

    void AddElement(HtmlElement element) {
        _elements.emplace_back(element);
    }

private:
    std::string _name;
    std::string _text;
    std::vector<HtmlElement> _elements;
    const size_t _indent_size = 2;
};

#endif // HTMLELEMENT_H
