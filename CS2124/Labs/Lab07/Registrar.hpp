//
//  Registrar.hpp
//  Lab7
//
//  Created by Taimur Ghani on 3/9/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#ifndef Registrar_hpp
#define Registrar_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"


using namespace std;

namespace BrooklynPoly{
    class Registrar{
        friend ostream& operator<<(ostream& os, Registrar& r);
    public:
        void addCourse(const string& courseName);
        void addStudent(const string& studentName);
        void enrollStudentInCourse(const string& studentName, const string& courseName);
        void cancelCourse(const string& courseName);
        void purge();
    private:
        vector<Student*> students;
        vector<Course*> courses;
    };
}
#endif /* Registrar_hpp */
