#include "LinkedList.hpp"
#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
#include <limits>

// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.

using namespace std;

int main()
{
  // TO DO: Insert your code to display a menu for user to select to add/delete/view Student and course information.
  cout << "1. Insert Student" << endl;
  cout << "2. Delete Student" << endl;
  cout << "3. Search Student" << endl;
  cout << "4. Display All" << endl;
  cout << "5. Count Students" << endl;
  cout << "6. Add a course" << endl;
  cout << "7. Exit" << endl;
  int choice;
  int id;
  int position =-1;
  string name;
  double gpa;
  Course cc;
  LinkedList<Student> students_list; 
  string new_course;
  int new_course_location;
  Student test;
  int length;
  int length_courses;

  do {
    cout << "Enter choice: " << endl;
    cin >> choice;
    if (0 >= choice || choice > 7) {
      cout << "Please enter an available choice. " << endl;
    }
    switch (choice) {
      case 1:
        cout << "Enter ID: " << endl;
        cin >> id;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter Name: " << endl;
        getline(std::cin, name);
        cout << "Enter GPA: " << endl;
        cin >> gpa;
        students_list.append(Student(id, name, gpa));
        cout << endl;
        break;

      case 2:
        if (students_list.getLength() == 0) {
          cout << "There are no students in the list." << endl;
        }
        else {
          position = -1;
          while (position == -1) {
            cout << "Enter ID to delete: " << endl;
            cin >> id;
            position = test.search(students_list, id);
            if (position == -1) {cout<< "Please enter a valid ID. " << endl;}
          }
          try {
            students_list.remove(position);
            cout << "Deleted student with ID " << id << endl;
          }
          catch (string& e) {
            cerr << e << endl;
          }
        }
        cout << endl;
        break;

      case 3:
        if (students_list.getLength() == 0) {
          cout << "There are no students in the list." << endl;
        }
        else {
          position = -1;
          while (position == -1) {
            cout << "Enter ID to search: " << endl;
            cin >> id;
            position = test.search(students_list, id);
            if (position == -1) {cout<< "Please enter a valid ID. " << endl;}
          }
          cout << "Found: " << students_list.getElement(position).get_id() <<  " " << students_list.getElement(position).get_name() <<  " " << students_list.getElement(position).get_gpa() << endl;
          cout << "Courses: "; //add courses
          length_courses = students_list.getElement(position).get_courses_enrolled().getLength();
          for (int i=0; i<length_courses; i++) {
            cout << students_list.getElement(position).get_courses_enrolled().getElement(i).get_name() << " " << students_list.getElement(position).get_courses_enrolled().getElement(i).get_location() << endl;
          }
        }
        cout << endl;
        break;

      case 4:
        if (students_list.getLength() == 0) {
            cout << "There are no students in the list." << endl;
          }
        else {
          cout << "Students in List: " << endl;
          length = students_list.getLength();
          for (int i=0; i<length; i++) {
            cout << students_list.getElement(i).get_id() <<  " " << students_list.getElement(i).get_name() <<  " " << students_list.getElement(i).get_gpa() << " ";
            length_courses = students_list.getElement(i).get_courses_enrolled().getLength();
            for (int j=0; j<length_courses; j++) {
              cout << students_list.getElement(i).get_courses_enrolled().getElement(j).get_name() << " " << students_list.getElement(i).get_courses_enrolled().getElement(j).get_location() << " ";
            }
            cout << endl;
          }
          //add courses
          cout << endl;
        }
        break;

      case 5:
        cout << "Total students: " << students_list.getLength() << endl;
        cout << endl;
        break;

      case 6:
        if (students_list.getLength() == 0) {
          cout << "Please insert a student before adding a course." << endl;
        }
        else {
          position = -1;
          while (position == -1) {
            cout << "Enter ID: " << endl;
            cin >> id;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            position = test.search(students_list, id);
            if (position == -1) {cout<< "Please enter a valid ID. " << endl;}
          }
          cout << "Enter Course Name: " << endl;
          getline(std::cin, new_course);
          cout << "Enter location: " << endl;
          cin >> new_course_location;
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          students_list.getElement(position).append_course_enrolled(Course(new_course, new_course_location));
        }
        cout << endl;
        break;

      default:
        break;

    }
  } while (choice !=7);

}