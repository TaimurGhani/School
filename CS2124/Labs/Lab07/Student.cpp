//
//  Student.cpp
//  Lab7
//
//  Created by Taimur Ghani on 3/9/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#include "Student.hpp"

namespace BrooklynPoly{
    Student::Student(const string& name) : name(name){}
    void Student::addCourse(Course& course){
        courses.push_back(&course);
    }
    string Student::getName() const{
        return name;
    }
    ostream& operator<<(ostream& os, Student& stud){
        os << stud.name << ":" << endl;
        for (size_t i = 0; i <stud.courses.size(); i++){
            os << stud.courses[i]->getName() << endl;
        }
        os << endl;
        return os;
    }
    void Student::clearCourse(const string& courseName){
        for (size_t i = 0; i < courses.size(); i++){
            if (courses[i]->getName() == courseName){
                courses[i] = courses[courses.size()-1];
                courses.pop_back();
            }
        }
    }
}
