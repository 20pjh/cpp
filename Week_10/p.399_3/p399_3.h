#ifndef MONSTERWORLD_H
#define MONSTERWORLD_H

#include <iostream>
#include <vector>

using namespace std;

class Monster {
private:
    int x, y;
    int itemsEaten;
    int nEnergy;
    char symbol;
    bool isAlive;
    int deathTime;

public:
    Monster(int x, int y, char symbol);
    int getEnergy() const;
    void eat(bool itemEaten, int moveCount);
    void print() const;
    friend class MonsterWorld;
};

class MonsterWorld {
private:
    int width, height;
    int moveCount;
    vector<vector<int>> grid;
    vector<Monster*> monsters;
    const int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

public:
    MonsterWorld(int w, int h, int numMonsters);
    ~MonsterWorld();
    void printMap();
    void moveMonsters();
    void printGameState();
    bool isGameOver();
    void checkStarvation();
    int getMonsterCount() const;
};

bool waitForEnterKey();

#endif // MONSTERWORLD_H
