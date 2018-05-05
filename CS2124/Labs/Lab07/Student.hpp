//
//  Student.hpp
//  Lab7
//
//  Created by Taimur Ghani on 3/9/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "Course.hpp"
using namespace std;

namespace BrooklynPoly{
    class Course;

    class Student{
        friend ostream& operator<<(ostream& os, Student& stud);
    public:
        Student(const string& name);
        void addCourse(Course& course);
        string getName() const;
        vector<Course*> getCourses() const;
        void clearCourse(const string& courseName);
    private:
        string name;
        vector<Course*> courses;
    };
}

#endif /* Student_hpp */
