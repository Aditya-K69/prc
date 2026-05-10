parent = {}

# Find Function
def find(node):

    if parent[node] == node:
        return node

    return find(parent[node])


# Union Function
def union(u, v):

    root_u = find(u)
    root_v = find(v)

    parent[root_u] = root_v


# Kruskal Algorithm
def kruskal(V, edges):

    edges.sort(key=lambda x: x[2])

    for i in range(V):
        parent[i] = i

    total_cost = 0

    print("Edges in MST:")

    for u, v, w in edges:

        if find(u) != find(v):

            union(u, v)

            print(u, "-", v, "=", w)

            total_cost += w

    print("Total Cost =", total_cost)


V = int(input("Enter number of vertices: "))
E = int(input("Enter number of edges: "))

edges = []

print("Enter edges (u v w):")

for _ in range(E):

    u, v, w = map(int, input().split())

    edges.append((u, v, w))

kruskal(V, edges)