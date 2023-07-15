n = int(input())
s = list(input())

for i in range(n):
    if s[i] == 'R':
        s[i] = 0
    elif s[i] == 'G':
        s[i] = 1
    else:
        s[i] = 2


def change(i):
    for j in range(i - 1, i + 2):
        s[j] = (s[j] + 1) % 3


ret = 3 * n

for k in range(3):
    cnt = 0
    t = s[:]

    for i in range(1, n - 1):
        while s[i - 1] != k:
            change(i)
            cnt += 1

    if all(x == k for x in s):
        ret = min(ret, cnt)

    s = t

print(-1 if ret == 3 * n else ret)
