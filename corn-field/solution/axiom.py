import heapq

dy, dx = [-1, 1, 0, 0], [0, 0, -1, 1]


def in_range(y, x):
    return 0 <= y < n and 0 <= x < m


n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]

pq = []
for y in range(n):
    for x in range(m):
        if y == 0 or y == n - 1 or x == 0 or x == m - 1:
            heapq.heappush(pq, (-a[y][x], y, x))
            a[y][x] = 0

k = int(input())
for i in range(k):
    h, y, x = heapq.heappop(pq)
    print(y + 1, x + 1)

    for d in range(4):
        ny, nx = y + dy[d], x + dx[d]
        if in_range(ny, nx) and a[ny][nx]:
            heapq.heappush(pq, (-a[ny][nx], ny, nx))
            a[ny][nx] = 0
