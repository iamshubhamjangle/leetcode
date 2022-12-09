#include <bits/stdc++.h>
using namespace std;


class Person {
public:
    int age;

    Person(int age) {
        this->age = age;
    }

    void operator= (Person p) {
        cout << "Hello " << this->age << " " << p.age << endl;
    }
};

int main(){
    Person p1(10);
    Person p2(20);
    p1 = p2;
}