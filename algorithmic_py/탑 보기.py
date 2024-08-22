'''
문제
일직선으로 다양한 높이의 건물이 총
$N$개가 존재한다. 각 건물 옥상에서 양 옆에 존재하는 건물의 옆을 몇 개 볼 수 있는지 궁금해졌다.

 
$i$번째 건물 기준으로
$i - 1$,
$i - 2$, ...,
$1$번째 건물은 왼쪽에,
$i + 1$,
$i + 2$, ...,
$N$번째 건물은 오른쪽에 있다. 각 건물 사이의 거리는 다 동일하다.

현재 있는 건물의 높이가
$L$이라고 가정하면 높이가
$L$보다 큰 곳의 건물만 볼 수 있다.

바라보는 방향으로 높이가
$L$인 건물 뒤에 높이가
$L$이하인 건물이 있다면 가려져서 보이지 않는다.

번호	1	2	3	4	5	6	7	8
높이	3	7	1	6	3	5	1	7
보이는 건물 번호	2	x	2, 4, 8	2, 8	2,4,6,8	2,4,8	2,4,6,8	x
각 건물에서 볼 수 있는 건물들이 어떤것이 있는지 구해보자.

입력
첫번째 줄에 건물의 개수
$N$이 주어진다.

두번째 줄에는
$N$개의 건물 높이가 공백으로 구분되어 주어진다.

출력
 
$i(1 \le i \le N)$번째 건물에서 볼 수 있는 건물의 개수를 출력한다.

만약 볼 수 있는 건물의 개수가 1개 이상이라면
$i$번째 건물에서 거리가 가장 가까운 건물의 번호 중 작은 번호로 출력한다.
'''

import sys

input = sys.stdin.readline

N = int(input())
right_stack_list = []
left_stack_list = []
answer = [[0 for _ in range(3)] for _ in range(N + 1)]
input_list = [(i + 1, int(x)) for i, x in enumerate(input().split())]
for x in input_list:
    if len(right_stack_list) == 0 or right_stack_list[-1][-1][1] >= x[1]:
        right_stack_list.append([x])
    else:
        for stack in reversed(right_stack_list):
            if stack[-1][1] < x[1]:
                stack.append(x)
            else:
                break
for x in reversed(input_list):
    if len(left_stack_list) == 0 or left_stack_list[-1][-1][1] >= x[1]:
        left_stack_list.append([x])
    else:
        for stack in reversed(left_stack_list):
            if stack[-1][1] < x[1]:
                stack.append(x)
            else:
                break

for stack in right_stack_list:
    for i, x in enumerate(stack[:-1]):
        if answer[x[0]][1] == 0:
            answer[x[0]][0] += len(stack) - i - 1
            answer[x[0]][1] = stack[i + 1][0]

for stack in left_stack_list:
    for i, x in enumerate(stack[:-1]):
        if answer[x[0]][2] == 0:
            answer[x[0]][0] += len(stack) - i - 1
            answer[x[0]][2] = stack[i + 1][0]

for i, a in enumerate(answer[1:]):
    if a[0] == 0:
        print(a[0])
    else:
        if a[1] == 0:
            print(a[0], a[2], sep=' ')
        elif a[2] == 0:
            print(a[0], a[1], sep=' ')
        else:
            idx = i + 1
            closer = a[2] if idx - a[2] <= a[1] - idx else a[1]
            print(a[0], closer, sep=' ')
