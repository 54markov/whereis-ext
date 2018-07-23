#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <vector>
#include "event.h"

class Observer
{
    public:
        Observer();
        ~Observer();

        virtual void update(const Event event) = 0;
};
 
class Observable
{
    public:
        Observable();
        ~Observable();

        void addObserver(Observer* observer);
        void notifyObserver(const Event event);

    private:
        std::vector<Observer*> observers_;
};

#endif /* _OBSERVER_H_ */
