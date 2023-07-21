def source_removal(matrix):
    # matrix is the adjacency matrix of the graph
    # returns a list of the nodes in topolog
    # order, or None if the graph has a cycle
    n = len(matrix)
    # indegree[i] is the number of incoming edges to i
    indegree = [0] * n
    for i in range(n):
        for j in range(n):
            indegree[j] += matrix[i][j]
    # nodes with no incoming edges
    sources = [i for i in range(n) if indegree[i] == 0]
    # list of nodes in topological order
    top_order = []
    while sources:
        # remove a node n with no incoming edges
        n = sources.pop()
        top_order.append(n)
        # remove edges (n, v) from the graph
        for v in range(n):
            if matrix[n][v]:
                indegree[v] -= 1
                if indegree[v] == 0:
                    sources.append(v)
    if len(top_order) == n:
        return top_order
    else:
        return None
    




def main():
    matrix = [
        [0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 1, 1, 0]]

    ls = source_removal(matrix)

    print(ls)


if __name__ == "__main__":
    main()
