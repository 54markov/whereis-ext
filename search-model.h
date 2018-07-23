#ifndef _SEARCH_MODEL_H_
#define _SEARCH_MODEL_H_

#include <string>
#include <vector>

#include "observer.h"

class SearchModel : public Observable
{
    public:
        SearchModel();
        ~SearchModel();

        void searchAllFiles(const char *dir, const char *file, const char *filter);
        std::vector<std::string> getFiles(void);

    private:
        std::vector<std::string> files_;

        void iterateDir_(const char *directory, const char *searchValue);
        void filterFiles_(const char *file, const char* filter);
        bool addToFilterFiles_(std::vector<std::string>& v, std::string &iStr, const char *file, const char *filter);
};

#endif /* _SEARCH_MODEL_H_ */
