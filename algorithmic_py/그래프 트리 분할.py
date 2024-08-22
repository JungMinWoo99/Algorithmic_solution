import sys
input = sys.stdin.readline

N, M = map(int, input().split())

E = [[] for _ in range(N+1)]
for i in range(M):
    u, v = map(int, input().split())
    E[u].append([v, i+1])
    E[v].append([u, i+1])

graph_group = [False for _ in range(N+1)]
graph_group[0] = True
graph_num = 0
answer = []
for v in range(N+1):
    if graph_group[v] is False:
        graph_num += 1
        graph_group[v] = True

        graph_v = [v]
        graph_e = []
        search_stack = [v]

        def search_child_node(p_node):
            for edge in E[p_node]:
                if graph_group[edge[0]] is False:
                    graph_group[edge[0]] = True
                    graph_v.append(edge[0])
                    graph_e.append(edge[1])
                    search_stack.append(edge[0])

        while len(search_stack) > 0:
            next_v = search_stack.pop()
            search_child_node(next_v)

        answer.append([graph_v, graph_e])
        if graph_num > 2:
            break

if graph_num > 2:
    print(-1)
elif graph_num == 1 and len(answer[0][0]) == 1:
    print(-1)
else:
    if graph_num == 1:
        v = answer[0][0].pop()
        e = answer[0][1].pop()
        answer.append([[v], [], [v]])
    graph_size = [len(graph[0]) for graph in answer]
    if graph_size[0] == graph_size[1]:
        print(-1)
    else:
        print(*graph_size)
        for graph in answer:
            print(*graph[0])
            print(*graph[1])
