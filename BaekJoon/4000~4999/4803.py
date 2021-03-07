import sys

case_num = 0
while(True):
    case_num += 1
    n_v, n_e = map(int, sys.stdin.readline().split())
    if(n_v == 0):
        break
    graph = [[] for _ in range(n_v+1)]

    for i in range(n_e):
        a,b = map(int, sys.stdin.readline().split())
        graph[a].append(b)

    parent = [-1 for _ in range(n_v+1)]
    is_tree = [True for _ in range(n_v+1)]

    def get_p(child):
        if parent[child] == -1:
            return child
        parent[child] = get_p(parent[child])
        return parent[child]

    for i in range(n_v+1):
        for node in graph[i]:
            p_a = get_p(i)
            p_b = get_p(node)
            p_a , p_b = max(p_a, p_b), min(p_a,p_b)
            
            if(p_a == p_b):
                is_tree[p_b] = False
            else:
                parent[p_a] = p_b

    trees = list()
    for i in range(1, n_v+1):
        head = get_p(i)
        if(is_tree[head] and head not in trees):
            trees.append(head)
    print("Case ",case_num,": ",sep="", end="")
    if(len(trees) == 1):
        print("There is one tree.")
    elif(len(trees) == 0):
        print("No trees.")
    else:
        print("A forest of",len(trees),"trees.")

