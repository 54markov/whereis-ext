#include "search-model.h"

#include "event.h"

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

SearchModel::SearchModel()
{
    ;
}

SearchModel::~SearchModel()
{
    ;
}

void SearchModel::searchAllFiles(const char *directory, const char *file, const char *filter)
{
    this->iterateDir_(directory, file);

    if (filter)
    {
        this->filterFiles_(file, filter);
    }

    this->notifyObserver(Event::FindFiles);
}

std::vector<std::string> SearchModel::getFiles(void)
{
    return this->files_;
}

void SearchModel::iterateDir_(const char *directory, const char *searchValue)
{
    DIR *dir = NULL;
    struct dirent *entry = NULL;

    if (!(dir = opendir(directory)))
        return;

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_DIR)
        {
            char newPath[4096] = { 0 };

            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }

            snprintf(newPath, sizeof(newPath), "%s/%s", directory, entry->d_name);

            this->iterateDir_(newPath, searchValue);
        }
        else
        {
            if (strstr(entry->d_name, searchValue))
            {
                std::string match(directory);
                match += std::string("/") + std::string(entry->d_name);
                this->files_.push_back(std::string(match.begin() + 1, match.end()));
            }
        }
    }
    closedir(dir);
}

void SearchModel::filterFiles_(const char *file, const char *filter)
{
    std::vector<std::string> vFilter;

    if (std::string(filter) == std::string("photo"))
    {
        for (auto i : this->files_)
        {
            if (this->addToFilterFiles_(vFilter, i, file, ".jpeg"))
                continue;
            if (this->addToFilterFiles_(vFilter, i, file, ".png"))
                continue;
            if (this->addToFilterFiles_(vFilter, i, file, ".bmp"))
                continue;
            if (this->addToFilterFiles_(vFilter, i, file, ".jpg"))
                continue;
        }
    }
    else if (std::string(filter) == std::string("config"))
    {
        for (auto i : this->files_)
        {
            if (this->addToFilterFiles_(vFilter, i, file, ".d"))
                continue;
            if (this->addToFilterFiles_(vFilter, i, file, ".cfg"))
                continue;
            if (this->addToFilterFiles_(vFilter, i, file, ".config"))
                continue;
        }
    }
    else if (std::string(filter) == std::string("archive"))
    {
        for (auto i : this->files_)
        {
            if (this->addToFilterFiles_(vFilter, i, file, ".tar"))
                continue;
            if (this->addToFilterFiles_(vFilter, i, file, ".gz"))
                continue;
            if (this->addToFilterFiles_(vFilter, i, file, ".tgz"))
                continue;
            if (this->addToFilterFiles_(vFilter, i, file, ".zip"))
                continue;
            if (this->addToFilterFiles_(vFilter, i, file, ".rar"))
                continue;
        }
    }

    this->files_ = vFilter;
}

bool SearchModel::addToFilterFiles_(std::vector<std::string>& v, std::string &iStr, const char *file, const char *filter)
{
    std::string str(iStr.begin() + iStr.find(file), iStr.end());

    if (str.find(filter) != std::string::npos)
    {
        v.push_back(iStr);
        return true;
    }

    return false;
}
