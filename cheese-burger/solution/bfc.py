a, b = map(int, input().split())

a -= 2
b -= 1
cnt = 3

while a and b:
    a -= 1
    b -= 1
    cnt += 2

print(cnt)
