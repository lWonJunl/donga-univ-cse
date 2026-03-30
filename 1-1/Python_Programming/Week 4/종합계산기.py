# 변수 선언
select, answer, numStr, num1, num2 = 0, 0, "", 0, 0

# 계산 종류 선택
select = int(input("1. 입력한 수식 계산 2. 두 수 사이의 합계 : "))

# 입력한 수식 계산
if select == 1: 
    numStr = input("수식을 입력하세요 : ")
    answer = eval(numStr)
    print(" %s 결과는 %5.1f 입니다." % (numStr, answer))

# 두 수 사이의 합계
elif select == 2:
    num1 = int(input("첫 번째 수를 입력하세요 : "))
    num2 = int(input("두 번째 수를 입력하세요 : "))
    for i in range(num1, num2 + 1):
        answer += i
    print("%d+...+%d는 %d입니다." % (num1, num2, answer))

# 압력한 값이 1, 2가 아닐 때
else:
    print("1 또는 2만 입력하세요.")