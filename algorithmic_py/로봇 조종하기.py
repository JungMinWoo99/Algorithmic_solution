'''
문제
NASA에서는 화성 탐사를 위해 화성에 무선 조종 로봇을 보냈다. 실제 화성의 모습은 굉장히 복잡하지만, 로봇의 메모리가 얼마 안 되기 때문에 지형을 N×M 배열로 단순화 하여 생각하기로 한다.

지형의 고저차의 특성상, 로봇은 움직일 때 배열에서 왼쪽, 오른쪽, 아래쪽으로 이동할 수 있지만, 위쪽으로는 이동할 수 없다. 또한 한 번 탐사한 지역(배열에서 하나의 칸)은 탐사하지 않기로 한다.

각각의 지역은 탐사 가치가 있는데, 로봇을 배열의 왼쪽 위 (1, 1)에서 출발시켜 오른쪽 아래 (N, M)으로 보내려고 한다. 이때, 위의 조건을 만족하면서, 탐사한 지역들의 가치의 합이 최대가 되도록 하는 프로그램을 작성하시오.

입력
첫째 줄에 N, M(1≤N, M≤1,000)이 주어진다. 다음 N개의 줄에는 M개의 수로 배열이 주어진다. 배열의 각 수는 절댓값이 100을 넘지 않는 정수이다. 이 값은 그 지역의 가치를 나타낸다.

출력
첫째 줄에 최대 가치의 합을 출력한다.
'''

import sys

input = sys.stdin.readline

N, M = map(int, input().split())
input_arr = [[int(x) for x in input().split()] for _ in range(N)]
dp_arr = [[0 for _ in range(M)] for _ in range(N)]
dp_arr[0][0] = input_arr[0][0]
for i in range(1, M):
    dp_arr[0][i] = dp_arr[0][i - 1] + input_arr[0][i]
for i in range(1, N):
    right_dir = [0 for _ in range(M)]
    right_dir[0] = dp_arr[i - 1][0] + input_arr[i][0]
    for j in range(1, M):
        right_dir[j] = (dp_arr[i - 1][j] if dp_arr[i - 1][j] > right_dir[j - 1] else right_dir[j - 1]) + input_arr[i][j]
    left_dir = [0 for _ in range(M)]
    left_dir[M - 1] = dp_arr[i - 1][M - 1] + input_arr[i][M - 1]
    for j in range(M - 2, -1, -1):
        left_dir[j] = (dp_arr[i - 1][j] if dp_arr[i - 1][j] > left_dir[j + 1] else left_dir[j + 1]) + input_arr[i][j]
    for j in range(M):
        dp_arr[i][j] = right_dir[j] if right_dir[j] > left_dir[j] else left_dir[j]
print(dp_arr[N-1][M-1])
