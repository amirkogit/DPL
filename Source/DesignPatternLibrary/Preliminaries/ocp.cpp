/*
* Design Patterns Library (DPL)
* Implementation of various design patterns in C++
*
* Copyright (C) 2016  Amir Shrestha
* amirkomail@gmail.com
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "preliminariesdemo.h"

#include <string>
#include <vector>
#include <iostream>

namespace DPL {

enum class Color { Red, Green, Blue };
enum class Size { Small, Medium, Large };

struct Product
{
    std::string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    typedef std::vector<Product*> Items;

    // naive way of doing filtering is to define a method like this
    static Items ItemsByColor(Items items, Color color)
    {
        Items result;
        for(auto &item : items) {
            if(item->color == color) {
                result.push_back(item);
            }
        }
        return result;
    }

    // now if we need to filter by size, we pretty much repeat the same code as
    static Items ItemsBySize(Items items, Size size)
    {
        Items result;
        for(auto &item : items) {
            if(item->size == size) {
                result.push_back(item);
            }
        }
        return result;
    }

    // also, if we need to do filter by both color and size, we end up as follows
    static Items ItemBySizeAndColor(Items items, Color color, Size size)
    {
        Items result;
        for(auto &item : items) {
            if(item->color == color && item->size == size) {
                result.push_back(item);
            }
        }
        return result;
    }

    // NOTE: Here we see that the number of methods added for doing specific filtering
    // increases and is not a good design. So, a better way of doing is to follow a Specification pattern
};

//---------------------------------------------------------
// Specification pattern
// Here, we define a specification (interface) to do a check for filtering.
// Then, we define a concrete filter implementation using template classes
//---------------------------------------------------------

// Interface for a base Specification
template<typename T> struct ISpecification
{
    virtual bool IsSatisfied(T* item) = 0;
};

// Interface for filter
template <typename T> struct IFilter
{
    virtual std::vector<T*> Filter(std::vector<T*> items, ISpecification<T>& spec) = 0;
};

// Better product filter class that implements the filter specifications
struct BetterFilter : IFilter<Product>
{
    typedef std::vector<Product*> Items;

    std::vector<Product*> Filter(std::vector<Product*> items,
                                 ISpecification<Product>& spec) override
    {
        Items result;
        for(auto& p : items){
            if(spec.IsSatisfied(p)) {
                result.push_back(p);
            }
        }
        return result;
    }
};

// specialization for color filter
struct ColorSpecification : ISpecification<Product>
{
    Color color;

    explicit ColorSpecification(const Color color)
        : color {color}
    {
    }

    bool IsSatisfied(Product *item) override
    {
        return item->color == color;
    }
};

// specialization for size filter
struct SizeSpecification : ISpecification<Product>
{
  Size size;

  explicit SizeSpecification(const Size size)
      : size {size}
  {

  }

  bool IsSatisfied(Product *item)
  {
      return item->size == size;
  }
};

// specialization for combining two specifications (AND)
template <typename T> struct AndSpecification : ISpecification<T>
{
  ISpecification<T>& first;
  ISpecification<T>& second;

  AndSpecification(ISpecification<T>& first, ISpecification<T>& second)
      : first {first},
        second {second}
  {
  }

  bool IsSatisfied(T* item) override
  {
      return first.IsSatisfied(item) && second.IsSatisfied(item);
  }
};

//---------------------------------------------------------

// main method to test this demo
void DPL::PreliminariesDemo::RunOpenClosedPrincipleDemo()
{
    // sample test data
    Product apple { "Apple", Color::Green, Size::Small };
    Product house { "House", Color::Blue, Size::Large };
    Product tree { "Tree", Color::Green, Size::Large };

    // container containing all items
    std::vector<Product*> all {&apple, &tree, &house};

    BetterFilter betterFilter;

    // filter using color specification
    ColorSpecification green(Color::Green);

    auto green_things = betterFilter.Filter(all,green);
    for(auto&x : green_things) {
        std::cout << x->name << " is green" << std::endl;
    }

    // filter using both color and size specification
    SizeSpecification big(Size::Large);
    AndSpecification<Product> greenAndBig { big, green };

    auto greenAndBigThings = betterFilter.Filter (all, greenAndBig);
    for (auto& item : greenAndBigThings) {
        std::cout << item->name << " is green and big" << std::endl;
    }
}

} // end of namespace DPL
