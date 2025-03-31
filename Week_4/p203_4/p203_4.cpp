#include "puzzle_game.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    int size;
    char type;

    // 퍼즐 크기를 사용자에게 묻습니다.
    std::cout << "Enter the size of the puzzle (3 for 3x3, 4 for 4x4, 5 for 5x5): ";
    std::cin >> size;

    // 크기 입력을 검증합니다.
    if (size < 3 || size > 5) {
        std::cerr << "Invalid size. Size must be between 3 and 5." << std::endl;
        return 1;
    }

    // 퍼즐 유형(숫자 또는 ASCII 문자)을 사용자에게 묻습니다.
    std::cout << "Do you want to use numbers (n) or ASCII characters (a)? ";
    std::cin >> type;

    bool isAscii = (type == 'a');

    // 게임 변수를 초기화합니다.
    Board board(size, std::vector<int>(size));
    std::pair<int, int> emptyPos;
    std::vector<char> moves;

    // 보드를 무작위 값으로 초기화합니다.
    initializeBoard(board, size, emptyPos, isAscii);

    // 게임 루프
    while (true) {
        // 보드의 현재 상태를 출력합니다.
        printBoard(board, size, isAscii);

        // 퍼즐이 해결되었는지 확인합니다.
        if (isSolved(board, size, isAscii)) {
            std::cout << "Congratulations! You solved the puzzle!" << std::endl;
            break;
        }

        // 다음 동작을 사용자에게 묻습니다.
        std::cout << "Enter move (w/a/s/d), save (v), load (l), or replay (r): ";
        char action;
        std::cin >> action;

        // 사용자의 동작을 처리합니다.
        if (action == 'v') {
            // 게임 저장
            std::string filename;
            std::cout << "Enter filename to save: ";
            std::cin >> filename;
            manageSaveFiles();
            saveGame(board, emptyPos, moves, filename + ".sav");
        } else if (action == 'l') {
            // 저장된 게임 로드
            std::string filename;
            std::cout << "Enter filename to load: ";
            std::cin >> filename;
            if (!loadGame(board, emptyPos, moves, filename + ".sav")) {
                std::cout << "Failed to load game." << std::endl;
            }
        } else if (action == 'r') {
            // 이동 재생
            replayMoves(moves);
        } else {
            // 이동 수행
            if (makeMove(board, size, emptyPos, action)) {
                moves.push_back(action);
            } else {
                std::cout << "Invalid move!" << std::endl;
            }
        }
    }

    return 0;
}

// 보드를 초기화하고 무작위로 숫자 또는 ASCII 문자를 섞습니다.
void initializeBoard(Board& board, int size, std::pair<int, int>& emptyPos, bool isAscii) {
    std::vector<int> numbers(size * size);
    std::iota(numbers.begin(), numbers.end(), isAscii ? 33 : 0);
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            board[i][j] = numbers[i * size + j];
            if (board[i][j] == (isAscii ? 33 : 0)) {
                emptyPos = {i, j};
            }
        }
    }
}

// 보드의 현재 상태를 콘솔에 출력합니다.
void printBoard(const Board& board, int size, bool isAscii) {
    for (const auto& row : board) {
        for (int num : row) {
            if (num == (isAscii ? 33 : 0)) {
                std::cout << "   ";
            } else {
                if (isAscii) {
                    std::cout << static_cast<char>(num) << " ";
                } else {
                    std::cout << num << " ";
                }
            }
        }
        std::cout << std::endl;
    }
}

// 보드에서 이동을 수행하고 빈 슬롯의 위치를 업데이트합니다.
bool makeMove(Board& board, int size, std::pair<int, int>& emptyPos, char move) {
    int x = emptyPos.first;
    int y = emptyPos.second;

    switch (move) {
        case 'w': if (x > 0) std::swap(board[x][y], board[x - 1][y]), --emptyPos.first; break;
        case 's': if (x < size - 1) std::swap(board[x][y], board[x + 1][y]), ++emptyPos.first; break;
        case 'a': if (y > 0) std::swap(board[x][y], board[x][y - 1]), --emptyPos.second; break;
        case 'd': if (y < size - 1) std::swap(board[x][y], board[x][y + 1]), ++emptyPos.second; break;
        default: return false;
    }
    return true;
}

// 보드가 해결된 상태인지 확인합니다.
bool isSolved(const Board& board, int size, bool isAscii) {
    int correct = isAscii ? 34 : 1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == size - 1 && j == size - 1) return true;
            if (board[i][j] != correct++) return false;
        }
    }
    return true;
}

// 현재 게임 상태를 파일에 저장합니다.
void saveGame(const Board& board, const std::pair<int, int>& emptyPos, const std::vector<char>& moves, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    if (outFile) {
        int size = board.size();
        outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
        outFile.write(reinterpret_cast<const char*>(&board[0]), size * size * sizeof(int));
        outFile.write(reinterpret_cast<const char*>(&emptyPos), sizeof(emptyPos));
        int movesSize = moves.size();
        outFile.write(reinterpret_cast<const char*>(&movesSize), sizeof(movesSize));
        outFile.write(reinterpret_cast<const char*>(&moves[0]), movesSize * sizeof(char));
    }
}

// 파일에서 게임 상태를 로드합니다.
bool loadGame(Board& board, std::pair<int, int>& emptyPos, std::vector<char>& moves, const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile) {
        int size;
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
        board.resize(size, std::vector<int>(size));
        inFile.read(reinterpret_cast<char*>(&board[0]), size * size * sizeof(int));
        inFile.read(reinterpret_cast<char*>(&emptyPos), sizeof(emptyPos));
        int movesSize;
        inFile.read(reinterpret_cast<char*>(&movesSize), sizeof(movesSize));
        moves.resize(movesSize);
        inFile.read(reinterpret_cast<char*>(&moves[0]), movesSize * sizeof(char));
        return true;
    }
    return false;
}

// 게임 중 수행된 이동을 재생합니다.
void replayMoves(const std::vector<char>& moves) {
    for (char move : moves) {
        std::cout << move << " ";
    }
    std::cout << std::endl;
}

// 저장된 게임 파일 목록을 가져옵니다.
std::vector<std::string> getSaveFiles() {
    std::vector<std::string> saveFiles;
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().extension() == ".sav") {
            saveFiles.push_back(entry.path().string());
        }
    }
    std::sort(saveFiles.begin(), saveFiles.end(), [](const std::string& a, const std::string& b) {
        return fs::last_write_time(a) < fs::last_write_time(b);
    });
    return saveFiles;
}

// 상위 10개의 최신 파일만 유지하도록 저장된 게임 파일을 관리합니다.
void manageSaveFiles() {
    auto saveFiles = getSaveFiles();
    if (saveFiles.size() > 10) {
        for (size_t i = 0; i < saveFiles.size() - 10; ++i) {
            fs::remove(saveFiles[i]);
        }
    }
}