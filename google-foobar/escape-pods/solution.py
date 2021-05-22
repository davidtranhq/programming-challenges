# Edmonds-Karp maximum flow

# one past the maximum number of bunnies that could fit in a corridor
max_cap = 2000001

class Queue:
    def __init__(self, arr = None):
        self.arr = arr if arr else []

    def enqueue(self, x):
        self.arr.append(x)
    
    def dequeue(self):
        return self.arr.pop(0) if len(self.arr) != 0 else None

    def size(self):
        return len(self.arr)

class Vertex:
    def __init__(self, dist = None, pred = None):
        self.dist = dist
        self.pred = pred
        self.visited = False

class Edge:
    def __init__(self, capacity, flow = 0):
        self.cap = capacity
        self.flow = flow

def bfs(graph, src):
    '''Returns a list of edges corresponding to the path from src to the supersink'''
    verts = [Vertex() for row in graph]
    verts[src].dist = 0
    queue = Queue()
    queue.enqueue(src)
    while queue.size():
        u = queue.dequeue()
        for v in range(len(graph[u])):
            if graph[u][v] and not verts[v].visited:
                verts[v].dist = verts[u].dist + 1
                verts[v].pred = u
                verts[v].visited = True
                queue.enqueue(v)
    # traverse the predecessors of the supersink (last element) to build the list of edges
    path = []
    current = verts[-1]
    while current:
        path.insert(0, (current.pred, verts.index(current)))
        current = verts[current.pred] if current.pred else None
    # only return the list if a path exists to the supersink
    return path if path[0][0] == src else None

def to_ordinary(entrances, exits, graph):
    '''Convert a multiple-source and/or multiple-sink graph to ordinary single source/sink.'''
    # add supersource to graph
    supersource = [Edge(max_cap if room in entrances else 0, 0) for room in range(len(graph))]
    graph.insert(0, supersource)
    # adjust the adjacency matrix to accomdate two new nodes: supersource and supersink
    for room in graph:
        if graph.index(room)-1 in exits:
            room.append(Edge(max_cap, 0))
        else:
            room.append(Edge(0, 0))
        room.insert(0, Edge(0, 0))
    # add supersink to graph
    supersink = [Edge(0,0)] * len(graph)
    graph.append(supersink)
    return graph

def solution(entrances, exits, path):
    # initiailize graph and residual graphs
    graph = [[Edge(cap, 0) for cap in room] for room in path]
    to_ordinary(entrances, exits, graph)
    residual_caps = [[edge.cap for edge in room] for room in graph]
    augmenting_path = bfs(residual_caps, 0)
    while augmenting_path:
        min_residual_edge = min(augmenting_path, key=lambda c: residual_caps[c[0]][c[1]])
        min_residual = residual_caps[min_residual_edge[0]][min_residual_edge[1]]
        for u, v in augmenting_path:
            if graph[u][v].cap:
                graph[u][v].flow += min_residual
                residual_caps[u][v] -= min_residual
                residual_caps[v][u] += min_residual
            else:
                graph[v][u].flow -= min_residual
                residual_caps[u][v] += min_residual
        augmenting_path = bfs(residual_caps, 0)
    # maximum flow is the sum of the flows coming into the exit nodes
    # subtracting 1 from row.index(v) is necessary because the supersource shifted the nodes by 1
    return sum(v.flow for row in graph for v in row if row.index(v)-1 in exits)