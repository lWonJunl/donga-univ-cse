import random as rd
answer, tryNum = 0, 0

quiz = rd.randint(1,100)

while True:
    answer = int(input("숫자를 입력하시오. : "))
    tryNum += 1
    if answer==quiz:
        print("축하합니다. 총 시도횟수 = %d" % tryNum)
        break
    elif answer>quiz:
        print("높음!")
    else:
        print("낮음!")