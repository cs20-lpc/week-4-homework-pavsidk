// TODO:  Student class methods implementation here.
#include "Student.hpp"

Student::Student(int id, string name, double gpa) {
    this->id = id;
    this->name = name;
    this->gpa = gpa;
}

int Student::get_id() const {
    return this->id;
}

string Student::get_name() const {
    return this->name;
}
double Student::get_gpa() const {
    return this->gpa;
}

LinkedList<Course> Student::get_courses_enrolled() const {
    return this->courses_enrolled;
}

void Student::set_id(int id) {
    this->id = id;
}
void Student::set_name(string name) {
    this->name = name;
}

void Student::set_gpa(double gpa) {
    this->gpa = gpa;
}

void Student::append_courses_enrolled(Course new_course) {
    this->courses_enrolled.append(new_course);
}