#ifndef _VIEW_H_
#define _VIEW_H_

#include "event.h"
#include "observer.h"
#include "search-model.h"
#include "search-controller.h"

class SearchView : public Observer
{
    public:
        SearchView(SearchModel& searchModel, SearchController& searchController);
        ~SearchView();

        virtual void update(const Event event);

    private:
        SearchModel&      searchModel_;
        SearchController& searchController_;
};

#endif  /* _VIEW_H_ */
