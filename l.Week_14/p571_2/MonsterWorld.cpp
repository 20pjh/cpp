#include "Monster.h"
#include "MonsterTypes.h"
#include "MonsterWorld.h"
#include "Ranking.h"
#include "RankingManager.h"
#include "Player.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <stdexcept>
#include <ctime>
using namespace std;

// --- Monster 기본 함수 구현 ---
Monster::Monster(int x, int y, char symbol, string name)
    : x(x), y(y), symbol(symbol), name(name), itemsEaten(0), nEnergy(50), isAlive(true), deathTime(-1) {}

Monster::~Monster() {}

int Monster::getX() const { return x; }
int Monster::getY() const { return y; }
char Monster::getSymbol() const { return symbol; }
string Monster::getName() const { return name; }
bool Monster::alive() const { return isAlive; }
int Monster::getEnergy() const { return nEnergy; }

void Monster::onMoveCount(int moveCount) {}

void Monster::eat(bool itemEaten, int moveCount) {
    if (itemEaten) {
        nEnergy = std::min(nEnergy + 8, 100);
        itemsEaten++;
    } else {
        nEnergy = std::max(nEnergy - 1, 0);
    }
    if (nEnergy == 0 && isAlive) {
        isAlive = false;
        deathTime = moveCount;
    }
}

void Monster::print() const {
    cout << name << " (" << symbol << ") - Pos: (" << x << "," << y
         << ") Energy: " << nEnergy << ", Items Eaten: " << itemsEaten;
    if (!isAlive) cout << " (Dead)";
    cout << endl;
}

void Monster::changeEnergy(int delta) {
    nEnergy += delta;
    if (nEnergy < 0) nEnergy = 0;
    if (nEnergy > 100) nEnergy = 100;
}

// --- Monster 종류 구현 (간단한 이동 구현) ---
Zombie::Zombie(int x, int y) : Monster(x, y, 'Z', "Zombie") {}
void Zombie::move(const vector<vector<int>>& grid) { x = (x + 1) % grid[0].size(); }

Vampire::Vampire(int x, int y) : Monster(x, y, 'V', "Vampire") {}
void Vampire::move(const vector<vector<int>>& grid) { y = (y + 1) % grid.size(); }

Kangshi::Kangshi(int x, int y) : Monster(x, y, 'K', "Kangshi"), horizontal(true) {}
void Kangshi::move(const vector<vector<int>>& grid) {
    if (horizontal) x = (x + 1) % grid[0].size();
    else y = (y + 1) % grid.size();
    horizontal = !horizontal;
}

GhostGirl::GhostGirl(int x, int y) : Monster(x, y, 'G', "GhostGirl") {}
void GhostGirl::move(const vector<vector<int>>& grid) { x = (x + y) % grid[0].size(); }

Smombie::Smombie(int x, int y) : Monster(x, y, 'S', "Smombie") {}
void Smombie::move(const vector<vector<int>>& grid) { x = (x + 2) % grid[0].size(); }

Sangshi::Sangshi(int x, int y) : Kangshi(x, y) { this->symbol = 's'; this->name = "Sangshi"; }
void Sangshi::move(const vector<vector<int>>& grid) { Kangshi::move(grid); }
void Sangshi::onMoveCount(int moveCount) {}

SuperVampire::SuperVampire(int x, int y) : Vampire(x, y) { this->symbol = 'U'; this->name = "SuperVampire"; }
void SuperVampire::move(const vector<vector<int>>& grid) { y = (y + 2) % grid.size(); }
void SuperVampire::onMoveCount(int moveCount) {}

// --- Human, Tuman 구현 ---
Human::Human(int x, int y, char icon, string name) : Monster(x, y, icon, name) {}
void Human::move(const vector<vector<int>>& grid) {}

Tuman::Tuman(int x, int y, char icon, string name, char controlKey)
    : Human(x, y, icon, name), controlKey(controlKey) {}
void Tuman::moveHuman(const vector<vector<int>>& grid, char input) {}

// --- MonsterWorld 구현 ---
MonsterWorld::MonsterWorld(int w, int h, int numMonsters) : width(w), height(h), moveCount(0) {
    grid.resize(height, vector<int>(width, 1));
    srand((unsigned)time(0));
    int numEach = numMonsters / 7;
    int remainder = numMonsters % 7;
    for (int i = 0; i < numEach; i++) {
        monsters.push_back(new Zombie(rand() % width, rand() % height));
        monsters.push_back(new Vampire(rand() % width, rand() % height));
        monsters.push_back(new Kangshi(rand() % width, rand() % height));
        monsters.push_back(new GhostGirl(rand() % width, rand() % height));
        monsters.push_back(new Smombie(rand() % width, rand() % height));
        monsters.push_back(new Sangshi(rand() % width, rand() % height));
        monsters.push_back(new SuperVampire(rand() % width, rand() % height));
    }
    for (int i = 0; i < remainder; i++) {
        int t = rand() % 7;
        int x = rand() % width;
        int y = rand() % height;
        if (t == 0) monsters.push_back(new Zombie(x, y));
        else if (t == 1) monsters.push_back(new Vampire(x, y));
        else if (t == 2) monsters.push_back(new Kangshi(x, y));
        else if (t == 3) monsters.push_back(new GhostGirl(x, y));
        else if (t == 4) monsters.push_back(new Smombie(x, y));
        else if (t == 5) monsters.push_back(new Sangshi(x, y));
        else monsters.push_back(new SuperVampire(x, y));
    }
}

MonsterWorld::~MonsterWorld() {
    for (auto m : monsters) delete m;
}

void MonsterWorld::printGameState() {
    cout << "Move count: " << moveCount << "\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            bool found = false;
            for (auto m : monsters) {
                if (m->alive() && m->getX() == j && m->getY() == i) {
                    cout << m->getSymbol() << " ";
                    found = true;
                    break;
                }
            }
            if (!found) cout << (grid[i][j] > 0 ? "I " : ". ");
        }
        cout << "\n";
    }
    for (auto m : monsters) m->print();
    cout << "Total Monsters: " << monsters.size() << "\n\n";
}

void MonsterWorld::moveMonsters() {
    for (auto m : monsters) {
        if (!m->alive()) continue;
        m->move(grid);
        m->onMoveCount(moveCount);
        bool itemEaten = false;
        if (grid[m->getY()][m->getX()] > 0) {
            itemEaten = true;
            grid[m->getY()][m->getX()] = 0;
        }
        m->eat(itemEaten, moveCount);
    }
    moveCount++;
}

bool MonsterWorld::isGameOver() {
    bool itemsGone = true;
    for (int i = 0; i < height && itemsGone; i++)
        for (int j = 0; j < width && itemsGone; j++)
            if (grid[i][j] > 0) itemsGone = false;

    int aliveCount = 0;
    for (auto m : monsters) if (m->alive()) aliveCount++;
    return itemsGone || aliveCount <= 1;
}

void MonsterWorld::checkStarvation() {
    for (auto it = monsters.begin(); it != monsters.end(); ) {
        if (!(*it)->alive()) {
            delete *it;
            it = monsters.erase(it);
        } else ++it;
    }
}

vector<Monster*>& MonsterWorld::getMonsters() { return monsters; }
int MonsterWorld::getMoveCount() const { return moveCount; }

// --- Ranking 구현 ---
Ranking::Ranking(const string& file) : filename(file) {}
void Ranking::load() {
    ranks.clear();
    ifstream fin(filename);
    if (!fin) throw runtime_error("랭킹 파일을 열 수 없습니다.");
    string name;
    int eaten, survived;
    while (fin >> name >> eaten >> survived)
        ranks.push_back({name, eaten, survived});
}
void Ranking::save() {
    ofstream fout(filename);
    if (!fout) throw runtime_error("랭킹 저장 실패");
    sort(ranks.begin(), ranks.end());
    for (const auto& r : ranks)
        fout << r.name << " " << r.itemsEaten << " " << r.survivedMoves << endl;
}
void Ranking::addRank(const RankEntry& entry) {
    ranks.push_back(entry);
    sort(ranks.begin(), ranks.end());
}
void Ranking::printTop(int n) const {
    cout << "===== 랭킹 TOP " << n << " =====\n";
    for (int i = 0; i < min(n, (int)ranks.size()); ++i)
        cout << i + 1 << ". " << ranks[i].name << " | Items: " << ranks[i].itemsEaten << " | Moves: " << ranks[i].survivedMoves << "\n";
}
const vector<RankEntry>& Ranking::getRanks() const { return ranks; }

// --- RankingManager 구현 ---
RankingManager::RankingManager(const string& filename) : ranking(filename) {}
void RankingManager::loadRankingsSafely() {
    try { ranking.load(); } catch (...) { throw FileOpenException(); }
}
void RankingManager::saveRankingsSafely() {
    try { ranking.save(); } catch (...) { throw FileOpenException(); }
}
void RankingManager::addRank(const RankEntry& entry) {
    ranking.addRank(entry);
}
void RankingManager::exportRankingsWithPassword() {
    string input;
    cout << "관리자 비밀번호 입력: ";
    cin >> input;
    if (input != adminPassword) throw PasswordMismatchException();
    string outFile;
    cout << "저장할 파일 이름 입력: ";
    cin >> outFile;
    ofstream fout(outFile);
    if (!fout) throw FileOpenException();
    const auto& ranks = ranking.getRanks();
    for (const auto& r : ranks)
        fout << r.name << " " << r.itemsEaten << " " << r.survivedMoves << endl;
}

// --- main 함수 ---
int main() {
    const int width = 10, height = 10, numMonsters = 14;
    MonsterWorld world(width, height, numMonsters);
    RankingManager manager("ranking.txt");

    try {
        manager.loadRankingsSafely();
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    while (!world.isGameOver()) {
        world.printGameState();
        world.moveMonsters();
        world.checkStarvation();
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << "게임 종료\n";

    for (auto m : world.getMonsters()) {
        RankEntry entry;
        entry.name = m->getName();
        entry.itemsEaten = m->getEnergy() > 0 ? m->getEnergy() : 0;
        entry.survivedMoves = world.getMoveCount();
        manager.addRank(entry);
    }

    try {
        manager.saveRankingsSafely();
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    char choice;
    cout << "\n관리자 모드로 랭킹을 백업하시겠습니까? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        try {
            manager.exportRankingsWithPassword();
        } catch (const exception& e) {
            cerr << e.what() << endl;
            return 1;
        }
    }

    return 0;
}