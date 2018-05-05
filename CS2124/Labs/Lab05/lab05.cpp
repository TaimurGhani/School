/*
    rec05.cpp
    Taimur Ghani
    23 February 2018
*/

#include <iostream>
#include <vector>
using namespace std;

class Section{
    
     friend ostream& operator<<(ostream& os, const Section& sec) {
         os << "Section: " << sec.classSec << ", ";
         os << sec.time;
         os << ", Students:";
         if ((sec.students).size() == 0){
             os << " None" << endl;
         }
         else{
             os << endl;
             for (const Student* stud : sec.students){
                 os << *stud;
             }
         }
         return os;
     }
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TimeSlot{
        
        friend ostream& operator<<(ostream& os, const TimeSlot& ts) {
            string m;
            int a;
            if (ts.time <13){
                m = "am";
                a = ts.time;
            }
            else {m = "pm"; a = ts.time-12;}
            return (os << "Time slot: [Day: "<<ts.day<<" Start time: "<<a<<m<<"]");
        }
        
    public:
        TimeSlot(const string& day, const int time) : day(day), time(time) {}
        void display() const {
            /*string m;
            int a;
            if (time <13){
                m = "am";
                a = time;
            }
            else {m = "pm"; a = time-12;}
            cout << "Time slot: [Day: "<<day<<" Start time: "<<a<<m<<"]";*/
            cout << *this;
        }
    private:
        string day;
        int time;
    };

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class Student{
        
        friend ostream& operator<<(ostream& os, const Student& stud) {
            os << "Name: " << stud.name <<", Grades: ";
            for (const int& grade : stud.grades){
                os << grade << " ";
            }
            os << endl;
            return os;
        }
        
    public:
        Student(const string& name) : name(name) {}
        
        void display() const {
            cout << *this;
        }
        
        string getName() const{
            return name;
        }
        void changeGrade(const int newGrade, const int week){
            grades[week-1] = newGrade;
        }
        
    private:
        string name;
        vector<int> grades = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    };
   
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
public:
    Section(const string& classSec, const string& day, const int hour) : classSec(classSec), time(day,hour){}
    Section(const Section& sec) : classSec(sec.classSec), time(sec.time){
        // make deep copy of students
        for (size_t i = 0; i < students.size(); i++){
            Student* tempstud = new Student(*students[i]);
            students.push_back(tempstud);
        }
    }
    ~Section(){
        cout << "Section " << classSec << " is being deleted" << endl;
        for (Student *stud : students){
            cout << "Deleting " << stud -> getName() << endl;
            delete stud;
        }
        
    }
    void addStudent(const string& studentName){
        Student *newStudent = new Student(studentName);
        students.push_back(newStudent);
    }
    
    void display() const{
        /*cout << "Section: " << classSec << ", ";
        time.display();
        cout << ", Students" << endl;
        for (const Student* stud : students){
            stud -> display();
        }*/
        cout << *this;
    }
    
    void addGrades(const string& studentName, const int newGrade, const int week){
        for (Student* stud : students){
            if (stud -> getName() == studentName){
                stud -> changeGrade(newGrade, week);
            }
        }
    }
private:
    vector<Student*> students;
    TimeSlot time;
    string classSec;
    
};


class LabWorker{
    
    friend ostream& operator<<(ostream& os, const LabWorker& lw) {
        if (!lw.labSec){
            os << lw.name << " does not have a section" << endl;
        }
        else{
            os << *lw.labSec;
        }
        return os;
    }
    
public:
    LabWorker(const string& name) : name(name){}
    
    void addSection(Section& theSection){
        labSec = &theSection;
    }
    
    void display() const{
        /*if (!labSec){
            cout << name << " does not have a section" << endl;
        }
        else{
            labSec -> display();
        }*/
        cout << *this;
    }
    
    void addGrade(const string& studentName, const int newGrade, const int week){
        labSec -> addGrades(studentName, newGrade, week);
    }
private:
    Section *labSec;
    string name;
    
};


// Test code
void doNothing(Section sec) { sec.display(); }

int main() {
    
    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2;
    //secA2.display();
    
    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2;
    //secA2.display();
    
    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    cout << moe;
    //moe.display();
    
    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    cout << moe;
    //moe.display();
    
    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    cout << jane;
    //jane.display();
    
    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    cout << moe;
    //moe.display();
    
    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    cout << moe;
    //moe.display();
    
    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all those students (or rather their records?)\n";
    
    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, then make sure the following call works\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";
    
} // main
