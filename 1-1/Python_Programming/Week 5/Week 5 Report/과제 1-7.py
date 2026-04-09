i = 1
dan = int(input("원하는 단은? : "))

while i<10:
    print("%d X %d = %d" % (dan, i, dan*i), end=' ')
    i += 1
    print()