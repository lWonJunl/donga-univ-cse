dan = int(input())

for i in range(1, 10):
    for j in range(2, dan+1):
        print("%2d X %2d = %2d" % (j, i, j*i), end=' ')
    print()