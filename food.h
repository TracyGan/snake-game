#ifndef FOOD_H
#define FOOD_H

#include <utility>

class Food {
    private: 
        std::pair<int, int> position;

    public:
        Food(int maxX, int maxY);

        void render();

        std::pair<int, int> getPosition();
};

#endif
