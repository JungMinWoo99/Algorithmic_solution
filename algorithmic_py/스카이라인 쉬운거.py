'''
문제
도시에서 태양이 질 때에 보이는 건물들의 윤곽을 스카이라인이라고 한다. 스카이라인만을 보고서 도시에 세워진 건물이 몇 채인지 알아 낼 수 있을까? 건물은 모두 직사각형 모양으로 밋밋하게 생겼다고 가정한다.

정확히 건물이 몇 개 있는지 알아내는 것은 대부분의 경우에 불가능하고, 건물이 최소한 몇 채 인지 알아내는 것은 가능해 보인다. 이를 알아내는 프로그램을 작성해 보자.

입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 50,000) 다음 n개의 줄에는 왼쪽부터 스카이라인을 보아 갈 때 스카이라인의 고도가 바뀌는 지점의 좌표 x와 y가 주어진다. (1 ≤ x ≤ 1,000,000. 0 ≤ y ≤ 500,000) 첫 번째 지점의 x좌표는 항상 1이다.

출력
첫 줄에 최소 건물 개수를 출력한다.
'''
import sys
input = sys.stdin.readline

n = int(input())

answer = 0
stack = []
for _ in range(n):
    _, x = map(int, input().split())
    while len(stack) != 0 and x < stack[-1]:
        stack.pop()
        answer += 1
    if len(stack) == 0 or x > stack[-1]:
        if x != 0:
            stack.append(x)
answer += len(stack)
print(answer)
