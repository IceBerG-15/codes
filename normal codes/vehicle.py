class Vehicle:
    def __init__(self, name, mileage, capacity):
        self.name = name
        self.mileage = mileage
        self.capacity = capacity

    def fare(self):
        return self.capacity * 100

class Bus(Vehicle):
    def fare(self):
        return super().fare()+0.1*super().fare()

School_bus = Bus("School Volvo", 12, 50)

print(isinstance(School_bus,Vehicle))