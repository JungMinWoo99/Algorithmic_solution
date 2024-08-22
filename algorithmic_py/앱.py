N, M = map(int, input().split())
m = list(map(int, input().split()))
c = list(map(int, input().split()))
C = N*100 + 1
for i in range(N):
    if c[i] == 0:
        M -= m[i]
        m[i] = 0
dp_arr = [[0 for _ in range(N)] for _ in range(C)]


def dp():
    for i in range(C):
        for j in range(N):
            if i - c[j] >= 0 and j - 1 >= 0:
                tem1 = dp_arr[i - c[j]][j - 1] + m[j]
                tem2 = dp_arr[i][j - 1]
                dp_arr[i][j] = tem1 if tem1 > tem2 else tem2
            elif j - 1 >= 0:
                dp_arr[i][j] = dp_arr[i][j - 1]
            elif i - c[j] >= 0:
                dp_arr[i][j] = m[j]

            if dp_arr[i][j] >= M:
                return i


print(dp())
