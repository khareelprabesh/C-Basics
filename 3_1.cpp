#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    Student * what;
};

void display1 (Student obj) {
    cout << "Name: " << obj.name << ", Age: " << obj.age << endl;
}

void display2 (Student * obj) {
    cout << "Name: " << obj->name << ", Age: " << obj->age << endl;
}

int main() {
    Student st1, st2, *st3;
    st3 = new Student;
    st3->name = "Charlie";
    st3->age = 21;
    st3->what = &st1;
    st1.name = "Alice";
    st1.age = 20;
    st1.what = &st2;
    st2.name = "Bob";
    st2.age = 22;
    st2.what = nullptr;
    display1(st1);
    display1(st2);
    display2(st3);
}

