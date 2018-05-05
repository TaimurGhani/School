//
//  Course.cpp
//  Lab7
//
//  Created by Taimur Ghani on 3/9/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#include "Course.hpp"

namespace BrooklynPoly{
    Course::Course(const string& name) : name(name){}
    void Course::addStudent(Student& student){
        students.push_back(&student);
    }
    string Course::getName() const{
        return name;
    }
    void Course::clearStudents(){
        for (size_t i = 0; i < students.size(); i++){
            students.pop_back();
        }
    }

    ostream& operator<<(ostream& os, Course& c){
        os << c.name << ":" << endl;
        for (size_t i = 0; i <c.students.size(); i++){
            os << c.students[i]->getName() << endl;
        }
        os << endl;
        return os;
    }
}
