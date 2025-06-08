#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Monster {
protected:
    int x, y;
    int itemsEaten;
    int nEnergy;
    char symbol;
    bool isAlive;
    int deathTime;
    string name;

public:
    Monster(int x, int y, char symbol, string name);
    virtual ~Monster();

    int getX() const;
    int getY() const;
    char getSymbol() const;
    string getName() const;
    bool alive() const;
    int getEnergy() const;

    virtual void move(const vector<vector<int>>& grid) = 0;
    virtual void onMoveCount(int moveCount);

    void eat(bool itemEaten, int moveCount);
    void print() const;
    void changeEnergy(int delta);
};

#endif