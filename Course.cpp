// TODO:  Course class methods implementation here.

#include "Course.hpp"

int Course::get_location() const {
    return this->location;
}
string Course::get_name() const {
    return this->course_name;
}

//mutators
void Course::set_location(int location) {
    this->location = location;
}
void Course::set_course_name(string course_name) {
    this->course_name = course_name;
}