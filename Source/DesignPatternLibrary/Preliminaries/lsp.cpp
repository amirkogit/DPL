/*
* Design Patterns Library (DPL)
* Implementation of various design patterns in C++
* This file implements Liskov Subsitution Principle
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

// Demonstrates classic Rectangle and Square problem

#include <iostream>
#include "preliminariestest.h"

class Rectangle
{
public:
    Rectangle(const int width, const int height)
        : m_width {width}, m_height {height}
    {
    }

    virtual int GetWidth() const
    {
        return m_width;
    }

    virtual int GetHeight() const
    {
        return m_height;
    }

    virtual void SetWidth(const int width)
    {
        m_width = width;
    }

    virtual void SetHeight(const int height)
    {
        m_height = height;
    }

    int Area() const
    {
        return m_width * m_height;
    }

protected:
    int m_width;
    int m_height;
};

class Square : public Rectangle
{
public:
    Square(int size) : Rectangle {size, size} {}

    void SetWidth(const int width) override
    {
        m_width = m_height = width;
    }

    void SetHeight(const int height) override
    {
        m_height = m_width = height;
    }
};

void Process(Rectangle& rect)
{
    int width = rect.GetWidth();
    rect.SetHeight(10);

    std::cout << "Expected area = " << (width * 10)
              << " Actual area = " << rect.Area() << std::endl;
}

void PreliminariesTest::RunLiskovSubstitutionPrincipleDemo()
{
    Rectangle rect {5,5};
    Process(rect);

    Square square {5};
    Process(square);
}

