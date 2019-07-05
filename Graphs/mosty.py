end = None  # bo tak lubię

# graf nieskierowany dany jako listy sąsiadów
g = {0: [1, 2],
     1: [0, 2, 4],
     2: [0, 1],
     3: [4, 5],
     4: [1, 3, 5],
     5: [3, 4, 6],
     6: [5, 7],
     7: [6]
     }


# zwraca wierzchołki grafu g
def vert(g):
    for v in g.keys():
        yield v


end


# zwraca sąsiadów wierzchołka v w grafie g
def adj(g, v):
    for w in g[v]:
        yield w


end


def dfs_visit(g, u):
    global time, color, d, low, parent

    color[u] = 1
    time += 1
    d[u] = time
    for v in adj(g, u):
        if color[v] == 0:
            parent[v] = u
            dfs_visit(g, v)
        end
    end

    # po przetworzeniu wierzchołka u oblicz low[u]
    low[u] = d[u]
    for v in adj(g, u):   # dla wszystkich sąsiadów wierzchołka u
        if parent[u] != v:   # z pominięciem jego rodzica
            if parent[v] == u:
                # jeżeli jest synem w drzewie rozpinającym
                low[u] = min(low[u], low[v])
            else:
                # jeżeli jest sąsiadem po krawędzi zwrotnej
                low[u] = min(low[u], d[v])
        end
    end


end


def dfs(g):
    global time, color, d, low, parent

    d = {}
    low = {}
    color = {}
    parent = {}

    for u in vert(g):
        color[u] = 0
        parent[u] = -1
    end
    time = 0
    for u in vert(g):
        if color[u] == 0:
            dfs_visit(g, u)
    end


end

dfs(g)

# przeglądniety graf
print("   v    d  low  par   adj")
for u in vert(g):
    print("{:4d} {:4d} {:4d} {:4d}   {}".format(
        u, d[u], low[u], parent[u], g[u]))
print()

# znalezione mosty
for u in vert(g):
    if d[u] == low[u] and parent[u] != -1:
        print("most:", parent[u], u)
    end
end
print()

# znalezione punkty artykulacji
for u in vert(g):
    if parent[u] != -1:  # pomiń korzeń (należy rozpatrzyć osobno!)
        for v in adj(g, u):
            if parent[v] == u and low[v] >= d[u]:
                print("punkt:", u)
                break
            end
        end
    else:  # teraz korzeń
        ls = 0  # liczba synów korzenia
        for v in adj(g, u):
            if parent[v] == u:
                ls += 1
        end
        if ls > 1:
            print("punkt artykulacji:", u)
        end
end
