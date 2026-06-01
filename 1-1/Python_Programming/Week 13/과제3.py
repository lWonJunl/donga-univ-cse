# class 선언 #
class SuperClass:
    def method(self):
        raise NotImplementedError

class SubClass1(SuperClass):
    def method(self):
        print("SubClassf1에서 method() 오버라이딩함")

class SubClass2(SuperClass):
    pass

# 메인 #
sub1 = SubClass1()
sub2 = SubClass2()

sub1.method()
sub2.method()
