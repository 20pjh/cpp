#ifndef PLAYER_H
#define PLAYER_H

#include "Monster.h"

class Human : public Monster {
public:
    Human(int x, int y, char icon, string name);
    void move(const vector<vector<int>>& grid) override;
    void onMoveCount(int moveCount) override {}
};

class Tuman : public Human {
private:
    char controlKey;
public:
    Tuman(int x, int y, char icon, string name, char controlKey);
    void moveHuman(const vector<vector<int>>& grid, char input);
};

#endif