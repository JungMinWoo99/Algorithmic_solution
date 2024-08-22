from collections import Counter
import math

N = int(input())

A, B, C, D = [], [], [], []

for _ in range(N):
    a, b, c, d = map(int, input().split())
    A.append(a)
    B.append(b)
    C.append(c)
    D.append(d)

AB, CD = [], []
for i in range(N):
    for j in range(N):
        AB.append(A[i] + B[j])
        CD.append(C[i] + D[j])


AB_counter = list(Counter(AB).items())
CD_counter = list(Counter(CD).items())

AB_counter.sort(key=lambda x: x[0], reverse=True)
CD_counter.sort(key=lambda x: x[0])

def find_val(value):
    start = 0
    end = len(CD_counter)-1
    mid = 0
    while start <= end:
        mid = (start + end) // 2
        if CD_counter[mid][0] == value:
            break
        elif CD_counter[mid][0] < value:
            start = mid + 1
        else:
            end = mid - 1
    if CD_counter[mid][0] == value:
        return CD_counter[mid][1]
    else:
        return 0


answer = 0
for AB in AB_counter:
    ret = find_val(-AB[0])
    answer += AB[1] * ret

print(answer)
