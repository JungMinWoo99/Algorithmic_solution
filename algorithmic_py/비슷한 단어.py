'''
문제
N개의 영단어들이 주어졌을 때, 가장 비슷한 두 단어를 구해내는 프로그램을 작성하시오.

두 단어의 비슷한 정도는 두 단어의 접두사의 길이로 측정한다. 접두사란 두 단어의 앞부분에서 공통적으로 나타나는 부분문자열을 말한다. 즉, 두 단어의 앞에서부터 M개의 글자들이 같으면서 M이 최대인 경우를 구하는 것이다. "AHEHHEH", "AHAHEH"의 접두사는 "AH"가 되고, "AB", "CD"의 접두사는 ""(길이가 0)이 된다.

접두사의 길이가 최대인 경우가 여러 개일 때에는 입력되는 순서대로 제일 앞쪽에 있는 단어를 답으로 한다. 즉, 답으로 S라는 문자열과 T라는 문자열을 출력한다고 했을 때, 우선 S가 입력되는 순서대로 제일 앞쪽에 있는 단어인 경우를 출력하고, 그런 경우도 여러 개 있을 때에는 그 중에서 T가 입력되는 순서대로 제일 앞쪽에 있는 단어인 경우를 출력한다.

입력
첫째 줄에 N(2 ≤ N ≤ 20,000)이 주어진다. 다음 N개의 줄에 알파벳 소문자로만 이루어진 길이 100자 이하의 서로 다른 영단어가 주어진다.

출력
첫째 줄에 S를, 둘째 줄에 T를 출력한다. 단, 이 두 단어는 서로 달라야 한다. 즉, 가장 비슷한 두 단어를 구할 때 같은 단어는 제외하는 것이다.
'''
import sys
input = sys.stdin.readline

N = int(input())
input_list = []

for i in range(N):
    input_str = input()[:-1]
    input_list.append((input_str, i))

input_list.sort(key=lambda x: x[0])
print(input_list)
answer1 = N + 1
answer2 = N + 1
max_idx = -1
for i in range(N-1):
    if len(input_list[i][0]) > max_idx and len(input_list[i + 1][0]) > max_idx and input_list[i][0][:max_idx + 1] == input_list[i + 1][0][:max_idx + 1]:
        S = input_list[i][1] if input_list[i][1] < input_list[i+1][1] else input_list[i+1][1]
        T = input_list[i][1] if input_list[i][1] > input_list[i+1][1] else input_list[i+1][1]
        if S < answer1:
            answer1 = S
            answer2 = T
        elif S == answer1 and T < answer2:
            answer1 = S
            answer2 = T
        elif len(input_list[i][0]) > max_idx + 1 and len(input_list[i + 1][0]) > max_idx + 1 and input_list[i][0][:max_idx + 2] == input_list[i + 1][0][:max_idx + 2]:
            answer1 = S
            answer2 = T
        while len(input_list[i][0]) > max_idx + 1 and len(input_list[i + 1][0]) > max_idx + 1 and input_list[i][0][:max_idx + 2] == input_list[i + 1][0][:max_idx + 2]:
            max_idx += 1

for i in input_list:
    if i[1] == answer1:
        S_str = i[0]
    elif i[1] == answer2:
        T_str = i[0]
print(S_str)
print(T_str)
