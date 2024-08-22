'''
두 자연수 A, B가 주어졌을 때, A ≤ x ≤ B를 만족하는 모든 x에 대해 x를 이진수로 표현했을 때 1의 개수의 합을 구하는 프로그램을 작성하시오.

즉, f(x) = x를 이진수로 표현 했을 때 1의 개수라고 정의하고, 아래 식의 결과를 구하자.
'''

import sys
from math import floor, ceil

input = sys.stdin.readline

A, B = map(int, input().split())

bit_mask = 1
answer = 0
for _ in range(64):
    bit_mask *= 2
    if B < bit_mask//2:
        break
    a = floor(A/bit_mask)
    b = floor(B/bit_mask)
    answer += (b - a + 1) * (bit_mask//2)
    answer -= A % bit_mask - bit_mask // 2 if bit_mask // 2 < A % bit_mask else 0
    answer -= bit_mask - (B % bit_mask + 1) if bit_mask // 2 < B % bit_mask + 1 else bit_mask // 2

print(answer)
