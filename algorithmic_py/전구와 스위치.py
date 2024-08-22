import sys
from math import ceil
from collections import Counter

input = sys.stdin.readline

N = int(input())
before = [i == 1 for i in map(int, input()[:-1])]
after = [i == 1 for i in map(int, input()[:-1])]

target = [i == j for i, j in zip(before, after)]
# print(target)

is_pushed = [False for _ in range(N)]


def push_button(i):
    is_pushed[i] ^= True
    if i - 1 > -1:
        target[i-1] ^= True
    target[i] ^= True
    if i + 1 < N:
        target[i + 1] ^= True


for i in range(N - 1):
    if not target[i]:
        push_button(i + 1)

# print(target)

if not target[N-1]:
    if N % 3 == 2:
        print(-1)
        exit()
    elif N % 3 == 1 or N % 3 == 0:
        for i in range(ceil(N/3.0)):
            push_button(i*3)
            if i*3 + 1 <= N-1:
                push_button(i*3 + 1)

# print(target)

print(Counter(is_pushed)[True])
