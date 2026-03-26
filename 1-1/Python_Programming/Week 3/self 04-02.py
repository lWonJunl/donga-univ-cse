inValue=0; count=0; result=0; i=0; # 변수 선언 및 초기화

# 필요한 입력 받기
inValue=int(input("시프트할 숫자는? "))
count=int(input("출력할 횟수는? "))

# 왼쪽 시프트 연산자 계산
for i in range(1, count+1):
    result = inValue << i
    print("%d << %d = %d" % (inValue, i, result))

# 오른쪽 시프트 연산자 계산
for i in range(1, count+1):
    result = inValue >> i
    print("%d >> %d = %d" % (inValue, i, result))