// TODO:  Course class definitins go here.

#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
using std::string;

class Course {
    private:
        string course_name;
        int location;
    public:
        //accessors
        int get_location() const;
        string get_name() const;
        
        //mutators
        void set_location(int location);
        void set_course_name(string course_name);
};

#endif