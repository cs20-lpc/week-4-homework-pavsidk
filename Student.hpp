#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include "LinkedList.hpp"
#include "Course.hpp"
using std::string;


class Student {
    private:
        int id;
        string name;
        double gpa;
        LinkedList<Course> courses_enrolled; 
    public:
        Student();
        Student(int id, string name, double gpa);

        //accessors
        int get_id() const;
        string get_name() const;
        double get_gpa() const;
        LinkedList<Course>& get_courses_enrolled();
        
        //mutators
        void set_id(int id);
        void set_name(string name);
        void set_gpa(double gpa);
        void append_course_enrolled(const Course& new_course);

        void print_student();

        int search(LinkedList<Student>, int);
};

#endif