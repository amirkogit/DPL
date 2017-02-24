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

#include <QCoreApplication>
#include <QDebug>

#include <iostream>

#include "Preliminaries/preliminariesdemo.h"

#include "Builder/person.h"
#include "Builder/personbuilder.h"
#include "Builder/personaddressbuilder.h"
#include "Builder/personjobbuilder.h"

void RunPreliminariesDemo()
{
    DPL::PreliminariesDemo::RunSingleResponsibilityPrincipleDemo();
    DPL::PreliminariesDemo::RunOpenClosedPrincipleDemo();
    DPL::PreliminariesDemo::RunLiskovSubstitutionPrincipleDemo();
    DPL::PreliminariesDemo::RunInterfaceSegregationPrincipleDemo();
}

void RunPersonBuilderDemo()
{
    std::cout << ">> Running Builder demo\n";
    std::cout << "-----------------------\n";

    Person p = Person::Create()
            .Lives().At("2445 Alameda").WithPostCode("94501").In("CA")
            .Works().At("Apple").AsA("Engineer").Earning(50000);

    std::cout << p << std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << "Running DPL demos...\n";
    std::cout << "-----------------------\n";

    //RunPreliminariesDemo();

    RunPersonBuilderDemo();

    return a.exec();
}
