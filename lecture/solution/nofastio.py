n, m = map(int, input().split())
r = [0] * (n + 1)

for i in range(m):
    k, s, e = map(int, input().split())

    if r[k] <= s:
        r[k] = e
        print('YES')
    else:
        print('NO')
