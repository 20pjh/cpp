#ifndef MONSTERWORLD_H
#define MONSTERWORLD_H

#include "MonsterTypes.h"
#include <vector>
using namespace std;

class MonsterWorld {
private:
    int width, height;
    int moveCount;
    vector<vector<int>> grid;
    vector<Monster*> monsters;

public:
    MonsterWorld(int w, int h, int numMonsters);
    ~MonsterWorld();

    void printMap();
    void moveMonsters();
    void printGameState();
    bool isGameOver();
    void checkStarvation();
    vector<Monster*>& getMonsters();
    int getMoveCount() const;
};

#endif