#ifndef PUZZLE_GAME_H
#define PUZZLE_GAME_H

#include <vector>
#include <string>
#include <utility>

// Board 타입 정의
typedef std::vector<std::vector<int>> Board;

// 함수 선언

// 보드를 초기화하고 무작위로 숫자 또는 ASCII 문자를 섞습니다.
void initializeBoard(Board& board, int size, std::pair<int, int>& emptyPos, bool isAscii);

// 보드의 현재 상태를 콘솔에 출력합니다.
void printBoard(const Board& board, int size, bool isAscii);

// 보드에서 이동을 수행하고 빈 슬롯의 위치를 업데이트합니다.
bool makeMove(Board& board, int size, std::pair<int, int>& emptyPos, char move);

// 보드가 해결된 상태인지 확인합니다.
bool isSolved(const Board& board, int size, bool isAscii);

// 현재 게임 상태를 파일에 저장합니다.
void saveGame(const Board& board, const std::pair<int, int>& emptyPos, const std::vector<char>& moves, const std::string& filename);

// 파일에서 게임 상태를 로드합니다.
bool loadGame(Board& board, std::pair<int, int>& emptyPos, std::vector<char>& moves, const std::string& filename);

// 게임 중 수행된 이동을 재생합니다.
void replayMoves(const std::vector<char>& moves);

// 저장된 게임 파일 목록을 가져옵니다.
std::vector<std::string> getSaveFiles();

// 상위 10개의 최신 파일만 유지하도록 저장된 게임 파일을 관리합니다.
void manageSaveFiles();

#endif // PUZZLE_GAME_H