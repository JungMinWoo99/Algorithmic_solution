'''
문제
성냥개비는 숫자를 나타내기에 아주 이상적인 도구이다. 보통 십진수를 성냥개비로 표현하는 방법은 다음과 같다.


성냥개비의 개수가 주어졌을 때, 성냥개비를 모두 사용해서 만들 수 있는 가장 작은 수와 큰 수를 찾는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 최대 100개 이다. 각 테스트 케이스는 한 줄로 이루어져 있고, 성냥개비의 개수 n이 주어진다. (2 ≤ n ≤ 100)

출력
각 테스트 케이스에 대해서 입력으로 주어진 성냥개비를 모두 사용해서 만들 수 있는 가장 작은 수와 가장 큰 수를 출력한다. 두 숫자는 모두 양수이어야 하고, 숫자는 0으로 시작할 수 없다.
'''

import sys

input = sys.stdin.readline


case_num = int(input())
for case in range(case_num):
    n = int(input())

    high = ''
    a = n // 2
    b = n % 2
    for _ in range(a):
        high += '1'
    if b == 1:
        high = '7' + high[:-1]

    low = ''
    low_case = ['0', '0', '1', '7', '4', '2', '6']
    if n < 7:
        low = low_case[n]
    else:
        a = n // 7
        b = n % 7
        for _ in range(a):
            low += '8'
        if 0 < b <= 2:
            for i in range(2 - b):
                low = '0' + low[:-1]
            low = '1' + low
        elif 2 < b < 6:
            for i in range(5 - b):
                low = '0' + low[:-1]
            if (5 - b) > len(low):
                low = low[:-1] + low_case[6 - ((5 - b) - len(low))]
            low = '2' + low
        elif b == 6:
            low = '6' + low

    print(low + ' ' + high)
