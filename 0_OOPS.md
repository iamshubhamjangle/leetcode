# OOPS in c++
Code Reference `0_OOPS.cpp`

### Class
- A class is like a blueprint for an object.
- It is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class.

### Object
- Object is an instance of a class.
- When class is instantiated memory is allocated to object.

### Access Modifiers
_By default all variables are private in c++_
- Public : Can be accessed by other classes and methods.
- Private : Can only be accessed by member functions scope within the class.
- Protected : Scope can be extended to child class, without exposing to public.

### Constructor
- Constructs the data members (properties) of a class.
	- It has no return type
	- Same names as of class
	- Should be public in most of cases
- Invoked when a instance of a class is created.
- If a parent class has build new/overwritten default constructor. Child class needs to be decalred with a constructor


## Pillars
### 1. Encapsulation
- Encapsulate all the properties of class using private keyword.
- Expose methods (getters/setter) to modify the values.
```cpp
class Car: AbstractCar {
protected:
	string name;		// if child class has to access properties of parent without making it public.
private: 
	string color;
	int year;
```

### 2. Abstraction
- Uses Abstract class in c++, Interface in java.
- An abstract class is a class that is designed to be specifically used as a base class. 
- An abstract class contains at least one pure virtual function. You declare a pure virtual function by using a pure specifier ( = 0 ) in member function.
```cpp
class AbstractCar {
	virtual void start() = 0;		// every car should have start
};
```

### 3. Inheritance
- The derived class inherits the features from the base class.
- This includes access to all public properties/methods.
- Protected properties can be accessed by child class.
- Inheritance should be public, if we want to access parent method from child object.
```cpp
class Electric: public Car {}
```

### 4. Polymorphism
- Single methods can have many forms. Parent function can be overwritten in base class.
- Parent class can hold the reference to child class. If we want to call overwritten method virtual keyword should be mentioned in parent class method.
```cpp
class Car: AbstractCar {
	virtual void fuel() { }
}

class Electric: public Car {
	void fuel() { }
};

main() {
	Electric ev("Tesla", "Texas", 2025, 100);
	Car* c = &ev;		// Parent can hold reference to child.
	c -> fuel();		// And call child's method if virtual keyword present in parent method
}
```