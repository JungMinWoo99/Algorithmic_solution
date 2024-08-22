import math
import sys

input = sys.stdin.readline

while True:
    a, b, c = map(int, input().split())
    if a == 0 and b == 0 and c == 0:
        break

    if a > b:
        if a > c:
            max = a
        else:
            max = c
    else:
        if b > c:
            max = b
        else:
            max = c

    if 2 * max >= a + b + c:
        print("Invalid")
        continue

    if a == b:
        if b == c:
            print("Equilateral")
        else:
            print("Isosceles")
    else:
        if b == c or a == c:
            print("Isosceles ")
        else:
            print("Scalene")

