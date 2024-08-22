import sys
input = sys.stdin.readline

tree = [[] for _ in range(9)]
for idx, node in enumerate(tree):
    i = idx + 1
    if i != 1:
        for before in tree[idx-1]:
            node.append([before[0] + i, before[1] + '+' + str(i), "+", i])
            node.append([before[0] - i, before[1] + '-' + str(i), "-", i])
            if before[2] == "+":
                node.append([before[0] + before[3] * 9 + i, before[1] + ' ' + str(i), "+", before[3]*10+i])
            else:
                node.append([before[0] - before[3] * 9 - i, before[1] + ' ' + str(i), "-", before[3]*10+i])
    else:
        node.append([i, str(i), "+", i])

N = int(input())
for x in range(N):
    i = int(input())
    answer = []
    for node in tree[i-1]:
        if node[0] == 0:
            answer.append(node[1])
    answer.sort()
    for line in answer:
        print(line)
    print()
