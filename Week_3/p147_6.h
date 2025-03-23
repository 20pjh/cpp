// 구구단 문제, 두 자리 수 곱셈 문제, 각 자리 수 덧셈 문제 중 하나를 골라 10문제 출제하고 맞히는 프로그램 작성

#ifndef GAME_H
#define GAME_H

void PlayGuguOnce();        // 구구단 게임 함수
void PlayMultiplication();  // 두 자리 수 곱셈 문제 함수
void PlayAddition(int digits); // 덧셈 문제 함수 (문제의 자릿수에 따라 다름)

#endif