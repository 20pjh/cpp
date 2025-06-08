#ifndef RANKINGMANAGER_H
#define RANKINGMANAGER_H

#include "Ranking.h"
#include <iostream>
#include <exception>
using namespace std;

class FileOpenException : public exception {
public:
    const char* what() const noexcept override {
        return "파일을 열 수 없습니다.";
    }
};

class PasswordMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "비밀번호가 틀렸습니다. 프로그램을 종료합니다.";
    }
};

class RankingManager {
private:
    Ranking ranking;
    const string adminPassword = "admin123";

public:
    RankingManager(const string& filename);
    void loadRankingsSafely();
    void saveRankingsSafely();
    void addRank(const RankEntry& entry);
    void exportRankingsWithPassword();
};

#endif