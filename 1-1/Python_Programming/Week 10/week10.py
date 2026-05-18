## plus() ##
# 함수 선언
def plus(n1, n2):
    result = 0
    result = n1 + n2
    return result   # 결과 반환

# 전역변수 선언
hap = 0

# 메인 코드
hap = plus(100, 200)    # 함수 호출
print(f"100과 200의 plus() 함수 결과는 {hap}")
print("=======================")