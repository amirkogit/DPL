#ifndef GROOVYSTYLE_H
#define GROOVYSTYLE_H

#include <vector>

class Tag
{
public:
    friend std::ostream& operator << (std::ostream& os, const Tag& tag)
    {
        os << "<" << tag._name;

        for(const auto& att : tag._attributes) {
            os << " " << att.first << "=\"" << att.second << "\"";
        }

        if(tag._children.size() == 0 && tag._text.length() == 0) {
            os << "/>" << std::endl;
        }
        else {
            os << ">" << std::endl;

            if(tag._text.length()) {
                os << tag._text << std::endl;
            }

            for(const auto& child : tag._children) {
                os << child;
            }

            os << "</" << tag._name << ">" << std::endl;
        }

        return os;
    }

protected:
    Tag(const std::string& name, const std::string& text)
        : _name(name), _text(text)
    {
    }

    Tag(const std::string& name, const std::vector<Tag>& children)
        :_name(name), _children (children)
    {
    }

    void AddAttribute(const std::string& str1, const std::string& str2)
    {
        _attributes.emplace_back(std::make_pair(str1,str2));
    }

private:
    std::string _name;
    std::string _text;
    std::vector<Tag> _children;
    std::vector<std::pair<std::string, std::string>> _attributes;
};

// class definition representing paragraph
class P : public Tag
{
public:
    explicit P(const std::string& text)
        : Tag("p", text)
    {
    }

    P(std::initializer_list<Tag> children)
        : Tag("p", children)
    {
    }
};

// class definition representing image
class Img : public Tag
{
public:
    explicit Img(const std::string& url)
        : Tag("img", "")
    {
        AddAttribute("src", url);
    }
};

#endif // GROOVYSTYLE_H
