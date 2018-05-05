//
//  Registrar.cpp
//  Lab7
//
//  Created by Taimur Ghani on 3/9/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#include "Registrar.hpp"
namespace BrooklynPoly{
    void Registrar::addCourse(const string& courseName){
        Course* newCourse = new Course(courseName);
        courses.push_back(newCourse);
    }
    void Registrar::addStudent(const string& studentName){
        Student* newStudent = new Student(studentName);
        students.push_back(newStudent);
    }
    void Registrar::enrollStudentInCourse(const string& studentName, const string& courseName){
        for (size_t i = 0; i < students.size(); i++){
            if (studentName == students[i]->getName()){
                for (size_t j = 0; j < courses.size(); j++){
                    if (courseName == courses[i]->getName()){
                        students[i]->addCourse(*courses[j]);
                        courses[j]->addStudent(*students[i]);
                    }
                }
            }
        }
    }
    
    void Registrar::cancelCourse(const string& courseName){
        for (size_t i = 0; i < students.size(); i++){
            for (size_t j = 0; j < students[i]->getCourses().size(); j++){
                if (students[i]->getCourses()[j]->getName() == courseName){
                    students[i]->clearCourse(courseName);
                }
            }
        }
        for (size_t i = 0; i < courses.size(); i++){
            if (courseName == courses[i]->getName()){
                courses[i]->clearStudents();
                courses[i] = courses[courses.size()-1];
                courses.pop_back();
            }
        }
    }
    ostream& operator<<(ostream& os, Registrar& r){
        for (size_t i = 0; i < r.students.size(); i++){
            os << *r.students[i];
        }
        for (size_t i = 0; i < r.courses.size(); i++){
            os << *r.courses[i];
        }
        return os;
    }
    
    void Registrar::purge(){
        while (students.size() > 0){
            delete students[students.size()-1];
            students[students.size()-1] = nullptr;
            students.pop_back();
            
        }
        while (courses.size() > 0){
            delete courses[courses.size()-1];
            courses[courses.size()-1] = nullptr;
            courses.pop_back();
            
        }
    }

}
