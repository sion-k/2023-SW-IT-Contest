a, b = map(int, input().split())

if b + 1 <= a <= 2 * b:
    print('YES')

    ret = []
    while a != b + 1:
        ret.append("aba")
        a -= 2
        b -= 1

    ret.append("ab" * b + "a")

    print(len(ret))
    print('\n'.join(ret))
else:
    print('NO')
