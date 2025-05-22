// 구구단 게임, 두 자릿수 곱셈 게임, n자릿수 덧셈 게임(1-9자릿수) 중에 하나를 골라서 푸는 프로그램의 헤더파일

#ifndef GAME_H
#define GAME_H

void PlayGuguOnce();        // 구구단 게임 함수
void PlayMultiplication();  // 두 자리 수 곱셈 문제 함수
void PlayAddition(int digits); // 덧셈 문제 함수 (문제의 자릿수에 따라 다름)

#endif