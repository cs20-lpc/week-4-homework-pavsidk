#include "Student.hpp"

Student::Student() {
    this->name = "";
    this->id = 0;
}   

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

LinkedList<Course>& Student::get_courses_enrolled() {
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

void Student::append_course_enrolled(const Course& new_course) {
    courses_enrolled.append(new_course);
}

void Student::print_student() {
    cout << endl;
}

int Student::search(LinkedList<Student> students_list, int id) {
    int length = students_list.getLength();
    int c_id = -1;

    for (int i = 0; i<length; i++) {
        c_id = students_list.getElement(i).get_id();
        if (c_id == id) {
            return i;
        }
    }
    return -1;
}