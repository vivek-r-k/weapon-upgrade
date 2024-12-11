class DeliveryApp:
    # Constructor
    def __init__(self):
        self.customer = input("Customer name? \n")
        self.items = int(input("Number of items? \n"))
        self.price = int(input("Price? \n"))
        self.availability = input("Available? (yes/no) \n").lower() == 'yes'

    # Display method
    def display(self):
        print(f"Name: {self.customer}\n{self.items} items")
        print(f"Rs {self.price}")
        if self.availability:
            print("Product is available \n")
        else:
            print("Product not available \n")

# Inherited class from DeliveryApp
class Deliver(DeliveryApp):
    # Constructor
    def __init__(self):
        super().__init__()
        self.address = input("Enter the address? \n")
        self.distance = int(input("Enter the distance to reach the destination \n"))

    # Print method
    def print(self):
        self.display()
        print(f"{self.address}")
        print(f"{self.distance} kilometers")

    # Destructor
    def __del__(self):
        print("Can't be delivered \n")

# Multilevel inheritance from Deliver
class Rating(Deliver):
    # Constructor
    def __init__(self):
        super().__init__()
        self.numlogins = 0

    # Review method
    def review(self, l):
        self.numlogins = l
        self.numlogins = int(input("Enter the number of logins? \n"))

        try:
            self.customer_rating = int(input("What is the customer rating? \n"))
        except ValueError:
            print("Invalid Input: You can only input a numeric value for customer rating")
            exit(1)

        self.satisfactory = input("Was the experience satisfactory? (yes/no) \n").lower() == 'yes'
        self.app_name = input("App name? \n")

    # Show method
    def show(self):
        self.print()
        print(f"{self.numlogins} logins\n{self.customer_rating} rating")
        if self.satisfactory:
            print("Yes very satisfied!!! \n")
        else:
            print("Not satisfied!!! \n")

    # Destructor
    def __del__(self):
        print("No activity \n")

# Friend function equivalent in Python
def app_name_comments(r):
    print(f"The App name is: {r.app_name}\n")

# Abstract base class
from abc import ABC, abstractmethod

class LastPart(ABC):
    def __init__(self):
        self.instamart = False

    @abstractmethod
    def last(self):
        pass

# Inherited class from LastPart
class EndClass(LastPart):
    def last(self):
        if self.instamart:
            print("You cannot be a part of Swiggy Instamart \n")
        else:
            print("You can be a part of Swiggy Instamart \n")

# Main function equivalent in Python
def main():
    r = 0
    obj_1 = Rating()
    obj_1.review(r)
    obj_1.show()
    app_name_comments(obj_1)

    # Creating instance of EndClass through LastPart reference
    ptr = EndClass()
    ptr.last()

if __name__ == "__main__":
    main()
