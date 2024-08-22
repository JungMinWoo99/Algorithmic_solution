'''
문제
길이가 N인 수열이 주어질 때, 수열에서 연속한 1개 이상의 수를 뽑았을 때 같은 수가 여러 번 등장하지 않는 경우의 수를 구하는 프로그램을 작성하여라.

입력
첫 번째 줄에는 수열의 길이 N이 주어진다. (1 ≤ N ≤ 100,000)

두 번째 줄에는 수열을 나타내는 N개의 정수가 주어진다. 수열에 나타나는 수는 모두 1 이상 100,000 이하이다.

출력
조건을 만족하는 경우의 수를 출력한다.
'''
import sys

input = sys.stdin.readline

N = int(input())
seq = list(map(int, input().split()))

start = 0
end = 0
num_bag = set()
num_bag.add(seq[start])
answer = 0


def cal_case_num(n):
    return (n + 1) * n // 2


while True:
    while end < N - 1 and not num_bag.__contains__(seq[end + 1]):
        num_bag.add(seq[end + 1])
        end = end + 1
    answer += cal_case_num(end - start + 1)
    num_bag.remove(seq[start])
    if end != N-1:
        start = start + 1
        answer -= cal_case_num(end - start + 1)
    else:
        break

print(answer)
