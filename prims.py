import heapq

def prim(V, adj):

    visited = [False] * V

    pq = [(0, 0)]

    total_cost = 0

    print("Edges in MST:")

    while pq:

        weight, node = heapq.heappop(pq)

        if visited[node]:
            continue

        visited[node] = True

        total_cost += weight

        print(node, "->", weight)

        for neighbor, cost in adj[node]:

            if not visited[neighbor]:
                heapq.heappush(pq, (cost, neighbor))

    print("Total Cost =", total_cost)


V = int(input("Enter number of vertices: "))
E = int(input("Enter number of edges: "))

adj = [[] for _ in range(V)]

print("Enter edges (u v w):")

for _ in range(E):

    u, v, w = map(int, input().split())

    adj[u].append((v, w))
    adj[v].append((u, w))

prim(V, adj)