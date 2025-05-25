#ifndef MONSTERWORLD_H
#define MONSTERWORLD_H

class Monster {
protected:
    int x, y;
    char icon;
public:
    Monster(int x, int y, char icon);
    virtual ~Monster();
    virtual void move(char key) = 0;

    int getX() const;
    int getY() const;
    char getIcon() const;
};

class Zombie : public Monster {
public:
    Zombie(int x, int y);
    void move(char key) override;
};

class Vampire : public Monster {
public:
    Vampire(int x, int y);
    void move(char key) override;
};

class Gangsi : public Monster {
public:
    Gangsi(int x, int y);
    void move(char key) override;
};

class Ghost : public Monster {
public:
    Ghost(int x, int y);
    void move(char key) override;
};

class Human : public Monster {
public:
    Human(int x, int y, char icon);
    void move(char key) override;
};

class Tuman : public Human {
public:
    Tuman(int x, int y, char icon);
    void move(char key) override;
    void moveHuman(char key);
};

class MonsterWorld {
private:
    Monster** pMon;
    int nMon;
    int width, height;
public:
    MonsterWorld(int width, int height);
    ~MonsterWorld();

    void addMonster(Monster* mon);
    void Play();
    void draw();
    bool checkCollision(int x, int y);
    bool isInside(int x, int y);
};

#endif
