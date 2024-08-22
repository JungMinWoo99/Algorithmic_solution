import math

N, M = map(int, input().split())
H = list(map(int, input().split()))
H.sort(reverse=True)

h_arr = []
before_h = 0
for h in H:
    if h == 0:
        break
    if before_h == h:
        h_arr[len(h_arr)-1][1] += 1
    else:
        h_arr.append([h, 1])
        before_h = h

h_arr.append([0, 0])

search_arr = [[0, 0, 0]]
before_h = h_arr[0][0]
before_num = h_arr[0][1]
for idx, h in enumerate(h_arr):
    if before_h != h[0]:
        cut_len = search_arr[idx-1][0]+(before_h - h[0])*(search_arr[idx-1][1] + before_num)
        cut_num = search_arr[idx-1][1] + before_num
        search_arr.append([cut_len, cut_num, h[0]])
        before_h, before_num = h

search_arr.reverse()

while len(search_arr) != 1:
    mid = math.floor(len(search_arr)/2)
    if search_arr[mid][0] < M:
        search_arr = search_arr[:mid]
    else:
        search_arr = search_arr[mid:]

if search_arr[0][0] > M:
    rest = search_arr[0][0] - M
    search_arr[0][2] += rest // search_arr[0][1]

print(search_arr[0][2])
