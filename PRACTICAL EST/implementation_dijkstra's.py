import heapq

class Solution:
    def dijkstra(self, V, edges, src):
        adj = [[] for _ in range(V)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))

        dist = [float('inf')] * V
        dist[src] = 0

        pq = [(0, src)]

        while pq:
            d, u = heapq.heappop(pq)

            if d > dist[u]:
                continue

            for v, w in adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    heapq.heappush(pq, (dist[v], v))

        return dist
