#include "search-view.h"

#include <iostream>

SearchView::SearchView(SearchModel& searchModel, SearchController& searchController) : searchModel_(searchModel), searchController_(searchController)
{
    this->searchModel_.addObserver(this);
    this->searchController_.addObserver(this);
}

SearchView::~SearchView()
{
    ;
}

void SearchView::update(const Event event)
{
    switch (event)
    {
        case Event::FindFiles:
        {
            for (auto i : this->searchModel_.getFiles())
            {
                std::cout << i << std::endl;
            }
            break;
        }
        case Event::OnLoad:
        {
            break;
        }
        case Event::UnLoad:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}
