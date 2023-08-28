n, d = map(int, input().split())
s = list(input() for _ in range(n))

flip = {}

flip[('d', 1)], flip[('d', 2)] = 'q', 'b'
flip[('b', 1)], flip[('b', 2)] = 'p', 'd'
flip[('q', 1)], flip[('q', 2)] = 'd', 'p'
flip[('p', 1)], flip[('p', 2)] = 'b', 'q'

for i in range(n):
    t = []
    for x in s[i]:
        t.append(flip[(x, d)])

    print(''.join(t))
