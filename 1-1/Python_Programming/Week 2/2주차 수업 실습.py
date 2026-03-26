#서식을 이용한 출력
print("%d / %d = %5.1f" % (100, 200, 0.5))
print("%d" % 123)
print("%5d" % 123)
print("%05d" % 123)
print("---------------------")

#format() 함수를 이용한 출력
print("{2:d} {1:d} {0:d}".format(100,200,300))
print("---------------------")

#이스케이프 문자
print("줄 바꿈 \n연습")
print("탭키 \t연습")
print("글자가 \"강조\"되는 효과1")
print("글자가 *강조*되는 효과2")
print("\\\\\\ 역슬래시 세 게 출력")
print("\\n \\t \" \\ 를 그대로 출력")
print("---------------------")

#코드 정지
#import os
# os.system("Pause")

#변수의 사용
myVer = 100
type(myVer)
myVer = 100.0
type(myVer)
