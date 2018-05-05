//
//  Course.hpp
//  Lab7
//
//  Created by Taimur Ghani on 3/9/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#ifndef Course_hpp
#define Course_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "Student.hpp"
using namespace std;

namespace BrooklynPoly{
    class Student;

    class Course{
        friend ostream& operator<<(ostream& os, Course& c);
    public:
        Course(const string& name);
        void addStudent(Student& student);
        string getName() const;
        void clearStudents();
    private:
        string name;
        vector<Student*> students;
    };
}
#endif /* Course_hpp */
