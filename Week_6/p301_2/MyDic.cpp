#include "MyDic.h"

int main() {
    MyDic myDic;
    char choice; // 사용자 선택

    while (true) {
        std::cout << "\n=== MyDic 프로그램 ===" << std::endl;
        std::cout << "1. 단어 추가" << std::endl;
        std::cout << "2. 단어 저장" << std::endl;
        std::cout << "3. 단어 로드" << std::endl;
        std::cout << "4. 단어 출력" << std::endl;
        std::cout << "5. ID로 영어 단어 검색" << std::endl;
        std::cout << "6. ID로 한글 뜻 검색" << std::endl;
        std::cout << "7. 종료" << std::endl;
        std::cout << "선택: ";
        std::cin >> choice;

        if (choice == '1') {
            std::string eng, kor;
            std::cout << "추가할 영단어를 입력하세요: ";
            std::cin >> eng;
            std::cin.ignore(); // 입력 버퍼 정리
            std::cout << "영단어의 뜻을 입력하세요: ";
            std::getline(std::cin, kor);

            myDic.add(eng, kor);
            std::cout << "단어가 추가되었습니다: " << eng << " - " << kor << std::endl;

        } else if (choice == '2') {
            std::string filename;
            std::cout << "저장할 파일명을 입력하세요: ";
            std::cin >> filename;
            myDic.store(filename);
            std::cout << "단어가 파일에 저장되었습니다." << std::endl;

        } else if (choice == '3') {
            std::string filename;
            std::cout << "로드할 파일명을 입력하세요: ";
            std::cin >> filename;
            myDic.load(filename);
            std::cout << "파일에서 단어를 로드했습니다." << std::endl;

        } else if (choice == '4') {
            myDic.print();

        } else if (choice == '5') {
            int id;
            std::cout << "검색할 단어의 ID를 입력하세요: ";
            std::cin >> id;
            std::cout << "ID " << id << "의 영어 단어: " << myDic.getEng(id - 1) << std::endl;

        } else if (choice == '6') {
            int id;
            std::cout << "검색할 단어의 ID를 입력하세요: ";
            std::cin >> id;
            std::cout << "ID " << id << "의 한글 뜻: " << myDic.getKor(id - 1) << std::endl;

        } else if (choice == '7') {
            std::cout << "프로그램을 종료합니다." << std::endl;
            break;

        } else {
            std::cout << "잘못된 입력입니다. 다시 선택하세요." << std::endl;
        }
    }

    return 0;
}