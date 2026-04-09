import random as rd

while True:
    try:
        num1 = rd.randint(1,100)
        num2 = rd.randint(1,100)

        ans = int(input("%d + %d = " % (num1, num2)))

        if num1+num2==ans:
            print("잘했어요!")
        else:
            print("정답은 %d 입니다. 다음번에는 더 잘할 수 있죠?" % (num1+num2))

    except KeyboardInterrupt:
        break

    
