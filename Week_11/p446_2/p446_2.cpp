#include "p446_2.h"
#include <limits>
#include <cstdlib>  // rand
#include <ctime>    // time

bool waitForEnterKey() {
    string input;
    cout << "Press Enter to continue..." << endl;
    getline(cin, input);
    return true;
}

int main() {
    srand((unsigned)time(nullptr));  // 랜덤 시드 초기화

    int width, height, numMonsters;

    cout << "Enter map width (max 50): ";
    cin >> width;
    cout << "Enter map height (max 50): ";
    cin >> height;
    cout << "Enter number of monsters: ";
    cin >> numMonsters;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    MonsterWorld gameWorld(width, height, numMonsters);


    while (!gameWorld.isGameOver()) {
        gameWorld.printGameState();
        waitForEnterKey();

        gameWorld.moveMonsters();
        gameWorld.checkStarvation();

        int moveCount = gameWorld.getMoveCount();
        if (moveCount > 0 && moveCount % 50 == 0) {
            auto& monsters = gameWorld.getMonsters();
            for (auto m : monsters) {
                SuperVampire* sv = dynamic_cast<SuperVampire*>(m);
                if (sv && sv->alive()) {
                    vector<Monster*> candidates;
                    for (auto other : monsters) {
                        if (other != sv && other->alive() && other->getEnergy() >= 10) {
                            candidates.push_back(other);
                        }
                    }
                    if (!candidates.empty()) {
                        int idx = rand() % candidates.size();
                        candidates[idx]->changeEnergy(-10);
                        sv->changeEnergy(10);
                    }
                }
            }
        }
    }

    cout << "Game Over!" << endl;
    return 0;
}