//
//  main.cpp
//  Lab7
//
//  Created by Taimur Ghani on 3/9/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

//#include "Registrar.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include "Registrar.hpp"
using namespace std;
using namespace BrooklynPoly;



int main() {
    ifstream ifs("transactions.txt");
    if (!ifs){
        cerr << "Did not open";
        exit(1);
    }
    Registrar registrar;
    //string command;
    
   /* while (ifs >> command){
        if (command == "PrintReport"){
            cout << registrar << endl;
        }
        else if (command == "AddCourse"){
            string course;
            ifs >> course;
            registrar.addCourse(course);
        }
        else if (command == "AddStudent"){
            string stud;
            ifs >> stud;
            registrar.addStudent(stud);
        }
        else if (command == "EnrollStudentInCourse"){
            string stud;
            string course;
            ifs >> stud >> course;
            registrar.enrollStudentInCourse(stud, course);
        }
        else if (command == "CancelCourse"){
            string course;
            ifs >> course;
            registrar.cancelCourse(course);
        }
        else{
            registrar.purge();
        }
    }*/
    cout << "No courses or students added yet\n";
    cout << registrar << endl;  // or registrar.printReport()
    
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    cout << registrar << endl;  // or registrar.printReport()
    
    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    cout << registrar << endl;  // or registrar.printReport()
    
    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    cout << registrar << endl;  // or registrar.printReport()
    
    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    cout << registrar << endl;  // or registrar.printReport()
    
    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout <<  "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    cout << registrar << endl;  // or registrar.printReport()
    
    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    cout << registrar << endl;  // or registrar.printReport()
    
    /*
     // [OPTIONAL - do later if time]
     cout << "ChangeStudentName FritzTheCat MightyMouse\n";
     registrar.changeStudentName("FritzTheCat", "MightyMouse");
     cout << registrar << endl;  // or registrar.printReport()
     
     cout << "DropStudentFromCourse MightyMouse CS101.001\n";
     registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
     cout << registrar << endl;  // or registrar.printReport()
     
     cout << "RemoveStudent FritzTheCat\n";
     registrar.removeStudent("FritzTheCat");
     cout << registrar << endl;  // or registrar.printReport()
     */
    
    cout << "Purge for start of next semester\n";
    registrar.purge();
    cout << registrar << endl;  // or registrar.printReport()
}
