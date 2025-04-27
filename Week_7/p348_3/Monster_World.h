#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Monster {
public:
    int x, y;               // 몬스터의 현재 위치
    int itemsEaten;         // 몬스터가 먹은 아이템 수
    int nEnergy;            // 몬스터의 에너지
    char symbol;            // 몬스터를 구별할 기호
    bool isAlive;           // 몬스터가 살아있는지 여부
    int deathTime;          // 몬스터가 죽은 시간 (죽지 않았으면 -1)

    Monster(int x, int y, char symbol);

    // 아이템을 먹을 때 에너지 변화
    void eat(bool itemEaten, int moveCount);

    // 몬스터의 상태 출력
    void print() const;
};

class Map {
private:
    vector<vector<int>> grid;    // 맵을 나타내는 2D 배열 (아이템의 수)
    vector<Monster> monsters;    // 몬스터들
    int width, height;           // 맵의 크기
    int moveCount;               // 이동 횟수
    const int maxMoves = 1000;   // 최대 이동 횟수
    const int directions[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

public:
    Map(int w, int h, int numMonsters);

    // 맵을 출력하는 함수
    void printMap();

    // 몬스터가 이동하는 함수
    void moveMonsters();

    // 게임 상태 출력
    void printGameState();

    // 게임 종료 조건 체크
    bool isGameOver();

    // 게임 종료 후 순위 출력
    void printRanking();
};

// 엔터키 대기 함수
bool waitForEnterKey();

#endif // MONSTER_H
