V = 4

# ---------- Common Safe Function ----------
def is_safe(graph, color, v, c):
    for i in range(V):
        if graph[v][i] and color[i] == c:
            return False
    return True


# =====================================================
#                1. BACKTRACKING
# =====================================================

def graph_util(graph, m, color, v):

    if v == V:
        return True

    for c in range(1, m + 1):

        if is_safe(graph, color, v, c):

            color[v] = c

            if graph_util(graph, m, color, v + 1):
                return True

            # Backtrack
            color[v] = 0

    return False


def coloring(graph, m):

    color = [0] * V

    if not graph_util(graph, m, color, 0):
        print("No Solution")
        return False

    print("\nGraph Coloring using Backtracking:\n")

    for i in range(V):
        print("Vertex", i, "-->", color[i])

    return True


# =====================================================
#              2. BRANCH AND BOUND
# =====================================================

bestColors = V
bestAssignment = [0] * V


def branch_and_bound(graph, color, v, usedColors):

    global bestColors, bestAssignment

    # BOUND
    if usedColors >= bestColors:
        return

    # All vertices colored
    if v == V:

        bestColors = usedColors
        bestAssignment = color[:]

        return

    # Try assigning colors
    for c in range(1, usedColors + 2):

        if is_safe(graph, color, v, c):

            color[v] = c

            newUsedColors = max(usedColors, c)

            branch_and_bound(
                graph,
                color,
                v + 1,
                newUsedColors
            )

            # Backtrack
            color[v] = 0


# =====================================================
#                     MAIN
# =====================================================

graph = [
    [0, 1, 1, 1],
    [1, 0, 1, 0],
    [1, 1, 0, 1],
    [1, 0, 1, 0]
]

m = 3

# Backtracking
coloring(graph, m)

# Branch and Bound
color = [0] * V

branch_and_bound(graph, color, 0, 0)

print("\nGraph Coloring using Branch and Bound:\n")

print("Minimum colors needed:", bestColors)

for i in range(V):
    print("Vertex", i, "--> Color", bestAssignment[i])