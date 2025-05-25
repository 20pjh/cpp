#include <iostream>
#include <cstdlib>
#include <ctime>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <chrono>
#include <thread>
#include "p488_1.h"

using namespace std;

// conio.h 대체 함수들 (리눅스용)
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void Sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

// -------------------- Monster 구현 --------------------

Monster::Monster(int x, int y, char icon) : x(x), y(y), icon(icon) {}
Monster::~Monster() {}

int Monster::getX() const { return x; }
int Monster::getY() const { return y; }
char Monster::getIcon() const { return icon; }

// 랜덤 이동 보조 함수
void randomMove(int& x, int& y, int width, int height) {
    int dir = rand() % 4;
    int nx = x, ny = y;
    switch (dir) {
        case 0: ny--; break;
        case 1: ny++; break;
        case 2: nx--; break;
        case 3: nx++; break;
    }
    if(nx >= 0 && nx < width && ny >= 0 && ny < height) {
        x = nx; y = ny;
    }
}

Zombie::Zombie(int x, int y) : Monster(x, y, 'Z') {}
void Zombie::move(char) {
    randomMove(x, y, 20, 10);
}

Vampire::Vampire(int x, int y) : Monster(x, y, 'V') {}
void Vampire::move(char) {
    randomMove(x, y, 20, 10);
}

Gangsi::Gangsi(int x, int y) : Monster(x, y, 'G') {}
void Gangsi::move(char key) {
    int nx = x, ny = y;
    switch (key) {
        case 'w': ny--; break;
        case 's': ny++; break;
        case 'a': nx--; break;
        case 'd': nx++; break;
    }
    if(nx >= 0 && nx < 20 && ny >= 0 && ny < 10) {
        x = nx; y = ny;
    }
}

Ghost::Ghost(int x, int y) : Monster(x, y, 'F') {}
void Ghost::move(char) {
    randomMove(x, y, 20, 10);
}

Human::Human(int x, int y, char icon) : Monster(x, y, icon) {}
void Human::move(char key) {
    int nx = x, ny = y;
    switch (key) {
        case 'i': ny--; break;  // 위 (WASD 대신 i,j,k,l)
        case 'k': ny++; break;  // 아래
        case 'j': nx--; break;  // 왼쪽
        case 'l': nx++; break;  // 오른쪽
    }
    if(nx >= 0 && nx < 20 && ny >= 0 && ny < 10) {
        x = nx; y = ny;
    }
}

Tuman::Tuman(int x, int y, char icon) : Human(x, y, icon) {}
void Tuman::move(char key) {
    moveHuman(key);
}
void Tuman::moveHuman(char key) {
    int nx = x, ny = y;
    switch (key) {
        case 'w': ny--; break;
        case 's': ny++; break;
        case 'a': nx--; break;
        case 'd': nx++; break;
    }
    if(nx >= 0 && nx < 20 && ny >= 0 && ny < 10) {
        x = nx; y = ny;
    }
}

// -------------------- MonsterWorld 구현 --------------------

MonsterWorld::MonsterWorld(int width, int height) : width(width), height(height), nMon(0), pMon(nullptr) {
    srand((unsigned)time(nullptr));
}

MonsterWorld::~MonsterWorld() {
    for(int i = 0; i < nMon; i++) {
        delete pMon[i];
    }
    delete[] pMon;
}

void MonsterWorld::addMonster(Monster* mon) {
    Monster** temp = new Monster*[nMon + 1];
    for(int i = 0; i < nMon; i++) temp[i] = pMon[i];
    temp[nMon] = mon;
    delete[] pMon;
    pMon = temp;
    nMon++;
}

bool MonsterWorld::isInside(int x, int y) {
    return (x >= 0 && x < width && y >= 0 && y < height);
}

bool MonsterWorld::checkCollision(int x, int y) {
    for(int i = 0; i < nMon; i++) {
        if(pMon[i]->getX() == x && pMon[i]->getY() == y) return true;
    }
    return false;
}

void MonsterWorld::draw() {
    system("clear");
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            char ch = '.';
            for(int i = 0; i < nMon; i++) {
                if(pMon[i]->getX() == x && pMon[i]->getY() == y) {
                    ch = pMon[i]->getIcon();
                    break;
                }
            }
            cout << ch;
        }
        cout << '\n';
    }
}

void MonsterWorld::Play() {
    cout << "왼쪽 플레이어: w,a,s,d\n오른쪽 플레이어: i,j,k,l\n";
    cout << "아이콘: 좌 = '좌', 우 = '우'\n";

    draw();

    while(true) {
        if(kbhit()) {
            int ch = getch();

            // 왼쪽 플레이어 (pMon[nMon-2]) w,a,s,d
            if(ch == 'w' || ch == 'a' || ch == 's' || ch == 'd') {
                pMon[nMon-2]->move(ch);
            }
            // 오른쪽 플레이어 (pMon[nMon-1]) i,j,k,l
            else if(ch == 'i' || ch == 'j' || ch == 'k' || ch == 'l') {
                pMon[nMon-1]->move(ch);
            }

            draw();
        }

        // 일반 몬스터 자동 이동
        for(int i = 0; i < nMon-2; i++) {
            pMon[i]->move(0);
        }

        draw();
        Sleep(100);
    }
}

// -------------------- main --------------------

int main() {
    MonsterWorld world(20, 10);

    world.addMonster(new Zombie(5, 3));
    world.addMonster(new Vampire(8, 2));
    world.addMonster(new Gangsi(12, 4));
    world.addMonster(new Ghost(15, 5));

    world.addMonster(new Tuman(1, 8, 'L'));  // 왼쪽 플레이어 'L' (Left)
    world.addMonster(new Human(18, 8, 'R')); // 오른쪽 플레이어 'R' (Right)


    world.Play();

    return 0;
}
