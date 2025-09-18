#include "LinkedList.hpp"
#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
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
  int position;
  string name;
  double gpa;
  Course cc;
  LinkedList<Student> students_list; 
  string new_course;
  int new_course_location;

  do {
    cout << "Enter choice: " << endl;
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "Enter ID: " << endl;
        cin >> id;
        cout << "Enter Name: " << endl;
        cin.ignore();
        getline(std::cin, name);
        cout << "Enter GPA: " << endl;
        cin >> gpa;
        students_list.append(Student(id, name, gpa));
        break;

      case 2:
        cout << "Enter ID to delete: " << endl;
        cin >> id;
        position = students_list.getIndexByID(id);
        students_list.remove(position);
        cout <<  "Deleted student with ID " << id << endl;
        break;

      case 3:
        cout << "Enter ID to search: " << endl;
        cin >> id;
        try {
          position = students_list.getIndexByID(id);
          Student searched = students_list.getElement(position);
          cout << "Found: " << searched.get_id() << " " << searched.get_name() << " " << searched.get_gpa() << endl; 
          cout << "Courses: " << searched.get_courses_enrolled();
        }
        catch (string& e) {
          cerr << e << endl;
        }
        break;

      case 4:
        cout << "Students in List: " << endl;
        cout << endl;
        break;

      case 5:
        cout << "Total students: " << students_list.getLength() << endl;
        break;

      case 6:
        cout << "Enter ID: " << endl;
        cin >> id;
        try {
          position = students_list.getIndexByID(id);
          Student searched = students_list.getElement(position);
          cout << "Enter Course Name:" << endl;
          cin.ignore();
          getline(std::cin, new_course);
          cc.set_course_name(new_course);
          cout << "Enter location:" << endl;
          cin >> new_course_location;
          cc.set_location(new_course_location);
          searched.append_course_enrolled(cc);
        }
        catch (string& e) {
          cerr << e << endl;
        }
        break;

      default:
        break;

    }
  } while (choice !=7);

}
