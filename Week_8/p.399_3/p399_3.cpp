#include "p399_3.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>

using namespace std;

Monster::Monster(int x, int y, char symbol)
    : x(x), y(y), itemsEaten(0), nEnergy(100), symbol(symbol), isAlive(true), deathTime(-1) {}

int Monster::getEnergy() const {
    return nEnergy;
}

void Monster::eat(bool itemEaten, int moveCount) {
    if (itemEaten) {
        nEnergy = min(nEnergy + 8, 100);
    } else {
        nEnergy = max(nEnergy - 1, 0);
    }

    if (nEnergy == 0 && isAlive) {
        isAlive = false;
        deathTime = moveCount;
    }
}

void Monster::print() const {
    cout << "Monster " << symbol << " - Energy: " << nEnergy << ", Items Eaten: " << itemsEaten;
    if (!isAlive) {
        cout << " (Dead)";
    }
    cout << endl;
}

MonsterWorld::MonsterWorld(int w, int h, int numMonsters)
    : width(w), height(h), moveCount(0) {
    grid.resize(height, vector<int>(width, 1));
    srand(time(0));

    char monsterSymbols[] = {'A', 'B', 'C', 'D', 'E'};
    for (int i = 0; i < numMonsters; i++) {
        int x = rand() % width;
        int y = rand() % height;
        monsters.push_back(new Monster(x, y, monsterSymbols[i]));
    }
}

MonsterWorld::~MonsterWorld() {
    for (auto& monster : monsters) {
        delete monster;
    }
}

void MonsterWorld::printMap() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            bool monsterPresent = false;
            for (const auto& m : monsters) {
                if (m->x == j && m->y == i) {
                    cout << m->symbol << " ";
                    monsterPresent = true;
                    break;
                }
            }
            if (!monsterPresent) {
                if (grid[i][j] > 0)
                    cout << "I ";
                else
                    cout << ". ";
            }
        }
        cout << endl;
    }
}

void MonsterWorld::moveMonsters() {
    for (auto& monster : monsters) {
        if (!monster->isAlive) continue;

        int dir = rand() % 8;
        int newX = monster->x + directions[dir][0];
        int newY = monster->y + directions[dir][1];

        if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
            monster->x = newX;
            monster->y = newY;

            bool itemEaten = false;
            if (grid[newY][newX] > 0) {
                itemEaten = true;
                grid[newY][newX] = 0;
            }

            monster->eat(itemEaten, moveCount);
            if (itemEaten) {
                monster->itemsEaten++;
            }
        }
    }
    moveCount++;
}

void MonsterWorld::printGameState() {
    cout << "Move count: " << moveCount << endl;
    printMap();
    for (int i = 0; i < monsters.size(); i++) {
        monsters[i]->print();
    }
    cout << "Total Monsters: " << getMonsterCount() << endl;
    cout << endl;
}

bool MonsterWorld::isGameOver() {
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
        if (monster->isAlive) {
            aliveMonsters++;
        }
    }

    return allItemsConsumed || aliveMonsters <= 1;
}

void MonsterWorld::checkStarvation() {
    for (auto it = monsters.begin(); it != monsters.end();) {
        if ((*it)->getEnergy() == 0) {
            delete *it;
            it = monsters.erase(it);
        } else {
            ++it;
        }
    }
}

int MonsterWorld::getMonsterCount() const {
    return monsters.size();
}

bool waitForEnterKey() {
    string input;
    cout << "Press Enter to continue..." << endl;
    getline(cin, input);
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

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    MonsterWorld gameWorld(width, height, numMonsters);

    while (!gameWorld.isGameOver()) {
        gameWorld.printGameState();
        cout << "Press ENTER to move monsters..." << endl;

        waitForEnterKey();

        gameWorld.moveMonsters();
        gameWorld.checkStarvation();
        gameWorld.printGameState();
    }

    cout << "Game Over!" << endl;
    return 0;
}
