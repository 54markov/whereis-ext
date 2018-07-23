#include "search-controller.h"

#include "event.h"

SearchController::SearchController(SearchModel& searchModel) : searchModel_(searchModel)
{
    ;
}

SearchController::~SearchController()
{
    ;
}

void SearchController::routine(const int argc, const char **argv)
{
    this->searchModel_.searchAllFiles("/", argv[1], argv[2]);
}

void SearchController::onLoad(void)
{
    this->notifyObserver(Event::OnLoad);
}

void SearchController::unload(void)
{
    this->notifyObserver(Event::UnLoad);
}
