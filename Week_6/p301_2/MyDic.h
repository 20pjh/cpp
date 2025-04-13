#ifndef MYDIC_H
#define MYDIC_H

#include <iostream>
#include <fstream>
#include <string>
#define MAXWORDS 100 // 최대 단어 수 정의

// WordPair 클래스 정의
class WordPair {
public:
    std::string eng; // 영어 단어
    std::string kor; // 한글 뜻

    inline WordPair(const std::string& eng = "", const std::string& kor = "")
        : eng(eng), kor(kor) {}
};

// MyDic 클래스 정의
class MyDic {
private:
    WordPair words[MAXWORDS]; // WordPair 배열로 단어와 뜻 저장
    int nWords;               // 현재 저장된 단어 수

public:
    inline MyDic() : nWords(0) {}

    // 영어 단어와 뜻 추가
    inline void add(const std::string& eng, const std::string& kor) {
        if (nWords < MAXWORDS) {
            words[nWords++] = WordPair(eng, kor);
        } else {
            std::cerr << "사전이 가득 찼습니다. 더 이상 단어를 추가할 수 없습니다." << std::endl;
        }
    }

    // 특정 ID의 영어 단어 반환
    inline std::string getEng(int id) const {
        if (id >= 0 && id < nWords) {
            return words[id].eng;
        } else {
            return "유효하지 않은 ID";
        }
    }

    // 특정 ID의 한글 뜻 반환
    inline std::string getKor(int id) const {
        if (id >= 0 && id < nWords) {
            return words[id].kor;
        } else {
            return "유효하지 않은 ID";
        }
    }

    // 파일에서 단어 목록 로드
    inline void load(const std::string& filename) {
        std::ifstream infile(filename);
        if (!infile) {
            std::cerr << "오류: 파일 " << filename << " 을(를) 열 수 없습니다." << std::endl;
            return;
        }

        nWords = 0; // 기존 데이터 초기화
        std::string eng, kor;
        while (infile >> eng >> kor) {
            add(eng, kor);
        }
        infile.close();
    }

    // 현재 단어 목록을 파일에 저장
    inline void store(const std::string& filename) const {
        std::ofstream outfile(filename);
        if (!outfile) {
            std::cerr << "오류: 파일 " << filename << " 을(를) 열 수 없습니다." << std::endl;
            return;
        }

        for (int i = 0; i < nWords; i++) {
            outfile << words[i].eng << " " << words[i].kor << std::endl;
        }
        outfile.close();
    }

    // 저장된 모든 단어를 출력
    inline void print() const {
        if (nWords == 0) {
            std::cout << "사전에 저장된 단어가 없습니다." << std::endl;
            return;
        }
        for (int i = 0; i < nWords; i++) {
            std::cout << i + 1 << ". " << words[i].eng << " - " << words[i].kor << std::endl;
        }
    }
};

#endif // MYDIC_H