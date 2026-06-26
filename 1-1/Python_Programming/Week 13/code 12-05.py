# class 선언 #
class Car:
    color = ""
    speed = 0
    year = 0
    company = ""
    count = 0

    def __init__(self):
        self.speed = 0
        self.year = 0
        Car.company = "Ferrari"
        Car.count += 1

# 변수 선언 #
myCar1, myCar2, myCar3 = None, None, None

# 메인 #
myCar1 = Car()
myCar1.speed = 30
myCar1.year = 2016
print("myCar1는 %d년에 %s에서 생생되었으며, 현재 속도는 %dkm/h, 생산된 자동차는 총 %d대 입니다." % (myCar1.year, myCar1.company, myCar1.speed, myCar1.count))

myCar2 = Car()
myCar2.speed = 60
myCar2.year = 2022
print("myCar2는 %d년에 %s에서 생생되었으며, 현재 속도는 %dkm/h, 생산된 자동차는 총 %d대 입니다." % (myCar2.year, myCar2.company, myCar2.speed, myCar2.count))

myCar3 = Car()
myCar3.speed = 100
myCar3.year = 2011
print("myCar3는 %d년에 %s에서 생생되었으며, 현재 속도는 %dkm/h, 생산된 자동차는 총 %d대 입니다." % (myCar3.year, myCar3.company, myCar3.speed, myCar3.count))