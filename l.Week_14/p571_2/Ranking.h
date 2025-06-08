#ifndef RANKING_H
#define RANKING_H

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct RankEntry {
    string name;
    int itemsEaten;
    int survivedMoves;
    bool operator<(const RankEntry& other) const {
        if (itemsEaten != other.itemsEaten)
            return itemsEaten > other.itemsEaten;
        return survivedMoves > other.survivedMoves;
    }
};

class Ranking {
private:
    vector<RankEntry> ranks;
    string filename;

public:
    Ranking(const string& file);
    void load();
    void save();
    void addRank(const RankEntry& entry);
    void printTop(int n = 10) const;
    const vector<RankEntry>& getRanks() const;
};

#endif