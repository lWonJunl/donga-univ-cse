# 함수 선언
def cal(n1, n2, op):
    ans = 0
    ans = eval("%d %s %d" % (n1, op, n2))
    return ans

# 전역변수 선언
num1, num2 = 0, 0
result = 0

# 메인 코드
num1 = int(input("숫자1 입력: "))
num2 = int(input("숫자2 입력: "))
op = input("연산자 입력: ")

result = cal(num1, num2, op)
print('결과 출력 : ', result)