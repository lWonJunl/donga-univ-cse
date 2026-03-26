a = int(input("년도를 입력하세요 : "))

if (a % 4 == 0) and ((a % 100 != 0) or a % 400 == 0) :
    print("윤년이 맞습니다.")
else :
    print("윤년이 아닙니다.")