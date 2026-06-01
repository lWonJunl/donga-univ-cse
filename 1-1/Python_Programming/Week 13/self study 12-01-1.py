# class 생성 #
class Car:
    color = " "
    speed = 0

    def __init__(self, value1, value2):
        self.color = value1
        self.speed = value2

    def upSpeed(self, value):
        if value > 150:
            self.speed += 150
        else:
            self.speed += value
        
    def downSpeed(self, value):
        self.speed -= value

# 메인 #
myCar1 = Car("빨강", 0)   
myCar2 = Car("파랑", 0) 
myCar3 = Car("파랑", 0) 


myCar1.upSpeed(30)
print("myCar1의 색상은 %s이며, 현재 속도는 %dkm/h입니다." % (myCar1.color, myCar1.speed))

myCar2.upSpeed(60)
print("myCar2의 색상은 %s이며, 현재 속도는 %dkm/h입니다." % (myCar2.color, myCar2.speed))

myCar3.upSpeed(200)
print("myCar3의 색상은 %s이며, 현재 속도는 %dkm/h입니다." % (myCar3.color, myCar3.speed))