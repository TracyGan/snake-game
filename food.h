#ifndef FOOD_H
#define FOOD_H

#include <utility>

class Food {
    private: 
        std::pair<int, int> position;

    public:
        Food(int startX, int startY);
};

#endif
