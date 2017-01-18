
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

#include <string>
#include <vector>
#include <fstream>

#include "preliminariesdemo.h"

namespace DPL {
    struct Journal
    {
      std::string title;
      std::vector<std::string> entries;

      explicit Journal(const std::string& title)
        : title(title)
      {
      }

      // this is a bad way of doing things. Journal class should not be concerned with
      // persistence
      void add(const std::string& entry)
      {
        entries.push_back(entry);
      }
    };

    // Better way: Single Responsibility Principle
    // PersistenceManager class segregates the logic for saving of Journal objects from the Journal class
    struct PersistenceManager
    {
      static void save(const Journal& j, const std::string& filename)
      {
        std::ofstream ofs(filename);
        for (auto& s : j.entries)
          ofs << s << std::endl;
      }
    };

    void DPL::PreliminariesDemo::RunSingleResponsibilityPrincipleDemo()
    {
        Journal journal("Journal title");
        std::string filename = "/tmp/dummyfile.txt";
        PersistenceManager::save(journal,filename);
    }
} // end of namespace DPL

