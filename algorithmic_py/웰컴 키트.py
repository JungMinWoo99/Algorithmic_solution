import math

N = int(input())
s, m, l, xl, xxl, xxxl = map(int, input().split())
T, P = map(int, input().split())

answer1 = math.ceil(s/T) + math.ceil(m/T) + math.ceil(l/T) + math.ceil(xl/T) + math.ceil(xxl/T) + math.ceil(xxxl/T)
answer2 = N//P
answer3 = N % P

print(answer1)
print(answer2, answer3)
