a, b = map(int, input().split())

if a <= b:
    print(2 * min(a, b) - 1)
else:
    print(2 * min(a, b) + 1)
