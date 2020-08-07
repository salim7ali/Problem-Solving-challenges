# Impementing below undirected graph as adjacency list by creating a class
# NOTE: is_directed and all_edges can be modified if directed graph is required or edges need to be changed respectively
# A-------C\
# |       | \
# |       |  E
# |       | /
# B-------D/

class Graph:
    def __init__(self, Nodes, is_directed = False):
        self.nodes = Nodes
        self.adj_list = {}

        for node in self.nodes:
            self.adj_list[node] = []

    def print_adj_list(self):
        for node in self.nodes:
            print(node, "->", self.adj_list[node])

    def add_edge(self, u, v):
        self.adj_list[u].append(v)
        if is_directed == False:
            self.adj_list[v].append(u)

nodes = ['A', 'B', 'C', 'D', 'E']
all_edges = [('A', 'B'), ('A', 'C'), ('B', 'D'), ('C', 'D'), ('C', 'E'), ('D', 'E')]
is_directed = False

graph = Graph(nodes, is_directed)
print('Before:')
graph.print_adj_list()

for u, v in all_edges:
    graph.add_edge(u, v)

print('After:')
graph.print_adj_list()