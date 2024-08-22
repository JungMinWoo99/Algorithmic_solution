from collections import deque
import sys
input = sys.stdin.readline

def list_intersection(lst1, lst2):
    # 리스트를 set으로 변환하여 교집합을 구함
    return list(set(lst1) & set(lst2))

N, M, L, K = map(int, input().split())

k_p_list = [[0, 0] for _ in range(K + 1)]
near_list = [[[], []] for _ in range(K + 1)]

for idx in range(1, K + 1):
    k_p_list[idx][0], k_p_list[idx][1] = map(int, input().split())

for i in range(1, K + 1):
    near_list[i][0].append(i)
    for j in range(i+1, K + 1):
        if abs(k_p_list[i][0] - k_p_list[j][0]) <= L and \
                abs(k_p_list[i][1] - k_p_list[j][1]) <= L:
            near_list[i][1].append(j)
copy = near_list.copy()
copy.sort(key=lambda x: len(x[1]), reverse=True)
loop_queue = deque(copy)
max_len = 0
while len(loop_queue) > 0:
    s = loop_queue.pop()
    if len(s[1]) == 0 and max_len < len(s[0]):
        max_len = len(s[0])
    elif len(s[1]) + len(s[0]) <= max_len:
        continue
    else:
        for n in s[1]:
            new_near = [s[0] + near_list[n][0], list_intersection(s[1], near_list[n][1])]
            loop_queue.append(new_near)

print(K - max_len)
