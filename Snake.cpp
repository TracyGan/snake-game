#include <vector>
#include <iostream>
#include <GLFW/glfw3.h>
using namespace std;

enum Direction { NORTH, SOUTH, WEST, EAST };
struct Snake {
    vector<pair<int, int>> body;
    Direction dir;

    Snake() {
        dir = NORTH;
    }

    void changeDirection(Direction d) {

    }

    bool checkCollision() {

    };

    void eat() {

    };
};
