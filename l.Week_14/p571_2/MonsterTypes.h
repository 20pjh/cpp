#ifndef MONSTERTYPES_H
#define MONSTERTYPES_H

#include "Monster.h"

class Zombie : public Monster {
private:
    int directions[8][2];
public:
    Zombie(int x, int y);
    void move(const vector<vector<int>>& grid) override;
};

class Vampire : public Monster {
private:
    int directions[4][2];
public:
    Vampire(int x, int y);
    void move(const vector<vector<int>>& grid) override;
};

class Kangshi : public Monster {
protected:
    bool horizontal;
public:
    Kangshi(int x, int y);
    void move(const vector<vector<int>>& grid) override;
};

class GhostGirl : public Monster {
public:
    GhostGirl(int x, int y);
    void move(const vector<vector<int>>& grid) override;
};

class Smombie : public Monster {
private:
    int directions[4][2];
public:
    Smombie(int x, int y);
    void move(const vector<vector<int>>& grid) override;
};

class Sangshi : public Kangshi {
private:
    bool flipped;
public:
    Sangshi(int x, int y);
    void move(const vector<vector<int>>& grid) override;
    void onMoveCount(int moveCount) override;
};

class SuperVampire : public Vampire {
public:
    SuperVampire(int x, int y);
    void move(const vector<vector<int>>& grid) override;
    void onMoveCount(int moveCount) override;
};

#endif