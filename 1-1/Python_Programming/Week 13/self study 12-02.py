class Car:
    speed = 0
    def method(self): 
        print("슈퍼 클래스", end='')

class Sedan(Car): 
    def method(self):
        print("서브 클래스", end='')

class Truck(Car):
    speed = 50
    color = "검정"

myCar = Car()
mySedan = Sedan()
myTruck = Truck()

myCar.method()

print()
mySedan.method()

print()
myTruck.method()

print()
print("myCar 속도 : %d" % myCar.speed)
print("mySedan 속도 : %d" % mySedan.speed)
print("myTruck 속도 : %d" % myTruck.speed, myTruck.color)