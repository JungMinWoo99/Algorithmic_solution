import math

C = int(input())

for _ in range(C):
    I = int(input())
    answer = 0
    for i in range(I//3 + 1):
        answer += (I - i * 3)//2 + 1
    print(answer)
