#ifndef _SEARCH_CONTROLLER_H_
#define _SEARCH_CONTROLLER_H_

#include "search-model.h"

class SearchController : public Observable
{
    public:
        SearchController(SearchModel& searchModel);
        ~SearchController();

        void routine(const int argc, const char* argv[]);

        void onLoad(void); // when application starts
        void unload(void); // when application ends

    private:
        SearchModel& searchModel_;
};

#endif /* _SEARCH_CONTROLLER_H_ */
