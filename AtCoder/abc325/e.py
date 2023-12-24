from queue import PriorityQueue

n, a, b, c = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
dist = [101010101010101010] * n

def dijkstra(s:int):
    pq = PriorityQueue()
    dist[s] = 0
    pq.put([0, s])
    
    while not pq.empty():
        p = pq.get()
        v = p[1]
        if dist[v] < p[0]:
            continue
        for to in range(n):
            if s==0 and dist[to] > dist[v] + graph[v][to]*a:
                dist[to] = dist[v] + graph[v][to]*a
                pq.put([dist[to], to])
            if s==n-1 and dist[to] > dist[v] + graph[v][to]*b + c:
                dist[to] = dist[v] + graph[v][to]*b + c
                pq.put([dist[to], to])

dijkstra(0)
dist_car = dist
dist = [101010101010101010] * n
dijkstra(n-1)

ans = 101010101010101010
for i in range(n):
    ans = min(ans, dist_car[i] + dist[i])
print(ans)