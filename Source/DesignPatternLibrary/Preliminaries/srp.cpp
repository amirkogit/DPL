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
        : title{title}
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

