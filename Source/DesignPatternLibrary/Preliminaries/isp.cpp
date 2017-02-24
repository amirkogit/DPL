/*
* Design Patterns Library (DPL)
* Implementation of various design patterns in C++
* This file implements Interface Segregation Principle
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

#include <vector>
#include "preliminariestest.h"

// suppose we have a class named Document
class Document
{

};

using DocumentList = std::vector<Document*>;

// An interface named IMachine that defines following pure virtual methods
class IMachine
{
public:
    virtual void Print(DocumentList docs) = 0;
    virtual void Scan(DocumentList docs) = 0;
    virtual void Fax(DocumentList docs) = 0;
};

// Concrete implementation of above interface
class MultiPeripheralMachine : public IMachine
{
    void Print(DocumentList docs) override {}
    void Scan(DocumentList docs) override {}
    void Fax(DocumentList docs) override {}
};

// NOTE: The major disadvantage of this implementation is that the
// user is forced to implement all the virtual methods defined in
// IMachine eventhough the user is not interested in all of them!
// So the better design is to segregate it into different interfaces as
// below:

class IPrinter
{
    virtual void Print(DocumentList docs) = 0;
};

class IScanner
{
    virtual void Scan(DocumentList docs) = 0;
};

class IFax
{
    virtual void Fax(DocumentList docs) = 0;
};

// Now Printer can only implement IPrinter
class Printer : public IPrinter
{
    void Print(DocumentList docs) override {}
};

// Scanner class can only implement IScanner
class Scanner : public IScanner
{
    void Scan(DocumentList docs) override {}
};

// Now, MultiPeripheralMachine2 can selectively implement necessary
// interfaces
class MultiPeripheralMachine2 : public IPrinter, IScanner
{
    void Print(DocumentList docs) override {}
    void Scan(DocumentList docs) override {}
};

void PreliminariesTest::RunInterfaceSegregationPrincipleDemo()
{
    MultiPeripheralMachine machine;

    Printer printer;
    Scanner scanner;

    MultiPeripheralMachine2 machine2;
}
