#include "Monster_World.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <atomic>

using namespace std;

Monster::Monster(int x, int y, char symbol) 
    : x(x), y(y), itemsEaten(0), nEnergy(100), symbol(symbol), isAlive(true), deathTime(-1) {}

void Monster::eat(bool itemEaten, int moveCount) {
    if (itemEaten) {
        nEnergy = min(nEnergy + 8, 100);  // 아이템을 먹으면 에너지 +8, 최대 100
    } else {
        nEnergy = max(nEnergy - 1, 0);    // 먹지 않으면 에너지 -1, 최소 0
    }

    if (nEnergy == 0 && isAlive) {
        isAlive = false;  // 에너지가 0이면 몬스터는 죽음
        deathTime = moveCount;  // 죽은 시간 기록
    }
}

void Monster::print() const {
    cout << "Monster " << symbol << " - Energy: " << nEnergy << ", Items Eaten: " << itemsEaten;
    if (!isAlive) {
        cout << " (Dead)";
    }
    cout << endl;
}

Map::Map(int w, int h, int numMonsters) : width(w), height(h), moveCount(0) {
    grid.resize(height, vector<int>(width, 1));  // 맵을 1로 초기화 (각 방에 하나의 아이템이 있음)
    srand(time(0));

    // 몬스터들 무작위로 배치 및 각 몬스터의 기호 설정
    char monsterSymbols[] = {'A', 'B', 'C', 'D', 'E'}; // 몬스터 기호 설정
    for (int i = 0; i < numMonsters; i++) {
        int x = rand() % width;
        int y = rand() % height;
        monsters.push_back(Monster(x, y, monsterSymbols[i]));
    }
}

void Map::printMap() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            bool monsterPresent = false;
            for (const auto& m : monsters) {
                if (m.x == j && m.y == i) {
                    cout << m.symbol << " "; // 몬스터가 있는 위치에 몬스터 기호 출력
                    monsterPresent = true;
                    break;
                }
            }
            if (!monsterPresent) {
                if (grid[i][j] > 0)
                    cout << "I "; // 아이템이 있는 칸
                else
                    cout << ". "; // 아이템이 없어지고 몬스터가 지나간 칸
            }
        }
        cout << endl;
    }
}

void Map::moveMonsters() {
    for (auto& monster : monsters) {
        if (!monster.isAlive) continue; // 죽은 몬스터는 움직이지 않음

        int dir = rand() % 8;  // 무작위로 방향 선택
        int newX = monster.x + directions[dir][0];
        int newY = monster.y + directions[dir][1];

        // 맵 경계를 벗어나지 않도록 체크
        if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
            monster.x = newX;
            monster.y = newY;

            // 아이템을 먹을 수 있으면 먹기
            bool itemEaten = false;
            if (grid[newY][newX] > 0) {
                itemEaten = true;
                grid[newY][newX] = 0;  // 아이템을 먹었으므로 해당 칸은 비워둠
            }

            monster.eat(itemEaten, moveCount);  // 몬스터가 먹었는지 확인하여 에너지 업데이트
            if (itemEaten) {
                monster.itemsEaten++;
            }
        }
    }
    moveCount++;
}

void Map::printGameState() {
    cout << "Move count: " << moveCount << endl;
    printMap();
    for (int i = 0; i < monsters.size(); i++) {
        monsters[i].print(); // 몬스터마다 에너지와 먹은 아이템 상태 출력
    }
    cout << endl;
}

bool Map::isGameOver() {
    bool allItemsConsumed = true;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] > 0) {
                allItemsConsumed = false;
                break;
            }
        }
    }

    int aliveMonsters = 0;
    for (const auto& monster : monsters) {
        if (monster.isAlive) {
            aliveMonsters++;
        }
    }
    return allItemsConsumed || moveCount >= maxMoves || aliveMonsters <= 1;
}

void Map::printRanking() {
    sort(monsters.begin(), monsters.end(), [](const Monster& a, const Monster& b) {
        if (a.nEnergy != b.nEnergy) {
            return a.nEnergy > b.nEnergy;
        }
        if (a.deathTime != b.deathTime) {
            return a.deathTime > b.deathTime;
        }
        if (a.itemsEaten != b.itemsEaten) {
            return a.itemsEaten > b.itemsEaten;
        }
        return a.deathTime > b.deathTime;
    });

    cout << "Ranking of monsters (by energy, death time, and items eaten):" << endl;
    for (const auto& monster : monsters) {
        cout << monster.symbol << " - Energy: " << monster.nEnergy;
        if (!monster.isAlive) {
            cout << " (Dead)";
        }
        cout << ", Items Eaten: " << monster.itemsEaten << endl;
    }
}

bool waitForEnterKey() {
    string input;
    cout << "Press Enter to continue..." << endl;
    getline(cin, input); // 엔터가 입력될 때까지 대기
    return true;
}

int main() {
    int width, height, numMonsters;

    cout << "Enter the width of the map (max 50): ";
    cin >> width;
    cout << "Enter the height of the map (max 50): ";
    cin >> height;
    cout << "Enter the number of monsters: ";
    cin >> numMonsters;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 입력 버퍼 정리

    Map gameMap(width, height, numMonsters);

    while (!gameMap.isGameOver()) {
        gameMap.printGameState();
        cout << "Press ENTER to move monsters..." << endl;

        waitForEnterKey();

        gameMap.moveMonsters();
        gameMap.printGameState();
    }

    cout << "Game Over!" << endl;
    gameMap.printRanking();
    return 0;
}