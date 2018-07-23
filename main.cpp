#include "search-view.h"
#include "search-model.h"
#include "search-controller.h"

#include <iostream>

void usage(char const *argv)
{
    std::cout << "usage: " << argv << " " << "[file] [config|photo|archive]>" << std::endl;
}

int main(int argc, char const *argv[])
{
    try
    {
        SearchModel       searchModel;
        SearchController  searchController(searchModel);
        SearchView        searchView(searchModel, searchController);
        
        if (argc < 2)
        {
            usage(argv[0]);
            return 0;
        }

        searchController.routine(argc, argv);
    }
    catch (std::string string)
    {
        std::cerr << string << std::endl;
    }

    return 0;
}