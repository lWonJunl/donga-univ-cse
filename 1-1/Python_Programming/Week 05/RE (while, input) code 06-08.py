i = 1
dan = int(input())

while i<10:
    j = 2
    while j<=dan:
        print("%2d X %2d = %2d" % (j, i, j*i), end=' ')
        j += 1
    i += 1
    print()