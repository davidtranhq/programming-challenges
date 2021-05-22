'''
Each vertex contains an element that describes it's position, shortest unbroken path d0,
shortest broken path d1, unbroken predecessor p0, and broken predecessor p1.

pseudo:
single-source initialize
intiailize source vertex (0,0) with shortest unbroken path of 1, broken path of 401,
    and no predecessors
fill priority queue Q
while Q
    pop u from priority queue
    for (u,v) in edges of graph
        if v is space
            if v.d0 > u.d0 + 1
                v.d0 = u.d0 + 1
                v.p0 = u
                re-add v to the queue; we might have gone through a broken path last time
            if v.d1 > u.d1 + 1
                v.d1 = u.d1 + 1
                v.p1 = u
                re-add v to the queue; we might have gone through an unbroken path last time
        if v is wall
            if v.d1 > u.d0 + 1
                v.d1 = u.d0 + 1
                v.p1 = u
    if u == end
        return min(u.dist)
'''
import math

# 401 is greater than the max distance that can exist (maze is 20x20)

class Vertex:
    def __init__(self, x, y, dist = None, pred = None):
        if not dist:
            dist = [401, 401]
        if not pred:
            pred = [None, None]
        self.x = x
        self.y = y
        self.dist = list(dist)
        self.pred = list(pred)

    def __lt__(self, other):
        return min(self.dist) < min(other.dist)

class PriorityQueue:
    def __init__(self, graph):
        # flatten the list (making a copy at the same time since we'll be modifying it)
        self.vertices = [vertex for row in graph for vertex in row]
    
    def push(self, x):
        self.vertices.append(x)

    def pop(self):
        # start with the first element being the smallest
        smallest = self.vertices[0]
        smallest_i = 0
        for i in range(1, len(self.vertices)):
            if self.vertices[i] < smallest:
                smallest = self.vertices[i]
                smallest_i = i
        self.vertices.pop(smallest_i)
        return smallest
    
    def size(self):
        return len(self.vertices)

def solution(maze):
    w = len(maze[0])
    h = len(maze)
    shortest = {}
    graph = [[Vertex(x, y) for x in range(w)] for y in range(h)]
    graph[0][0].dist = [1, 401]
    queue = PriorityQueue(graph)
    while queue.size():
        u = queue.pop()
        for x, y in [(u.x+1, u.y), (u.x-1, u.y), (u.x, u.y+1), (u.x, u.y-1)]:
            # make sure this adjacent vertex v doesn't extend beyond the boundaries of the maze
            if x >= 0 and x < w and y >= 0 and y < h:
                v = graph[y][x]        
                if maze[y][x]:
                    # v is a wall
                    if v.dist[1] > u.dist[0] + 1:
                        v.dist[1] = u.dist[0] + 1
                        v.pred[1] = (u.x, u.y)
                else:
                    # v is a space
                    if v.dist[0] > u.dist[0] + 1:
                        v.dist[0] = u.dist[0] + 1
                        v.pred[0] = (u.x, u.y)
                        queue.push(v)
                    if v.dist[1] > u.dist[1] + 1:
                        v.dist[1] = u.dist[1] + 1
                        v.pred[1] = (u.x, u.y)
                        queue.push(v)
        if u.x == w-1 and u.y == h-1:
            return min(u.dist)

