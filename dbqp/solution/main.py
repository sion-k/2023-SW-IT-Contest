n, d = map(int, input().split())
s = list(input() for _ in range(n))

flip = {}

flip[('d', 1)] = flip[('d', 2)] = 'q'
flip[('d', 3)] = flip[('d', 4)] = 'b'
flip[('b', 1)] = flip[('b', 2)] = 'p'
flip[('b', 3)] = flip[('b', 4)] = 'd'
flip[('q', 1)] = flip[('q', 2)] = 'd'
flip[('q', 3)] = flip[('q', 4)] = 'p'
flip[('p', 1)] = flip[('p', 2)] = 'b'
flip[('p', 3)] = flip[('p', 4)] = 'q'

for i in range(n):
    t = []
    for x in s[i]:
        t.append(flip[(x, d)])

    print(''.join(t))
