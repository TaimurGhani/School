/*
    rec04.cpp
    Taimur Ghani
    16 September 2018
    This is the code for lab 4 in which
    we follow a set of tasks to practice
    how to use pointers
*/

#include <iostream>
#include <vector>
using namespace std;

//Struct for Task 16
struct Complex {
    double real;
    double img;
};

//Class for Task 17
class PlainOldClass {
public:
    PlainOldClass() : x(-72) {}
    int getX() const { return x; }
    void setX( int x )  { this->x = x; }
private:
    int x;
};

int main(int argc, const char * argv[]) {
    //Task 2
    int x;
    x = 10;
    cout << "x = " << x << endl;
    
    //Task 8
    int* p;
    p = &x;
    cout << "p = " << p << endl;
    
    //Task 9
    //p = 0x0012fed4;
    
    //Task 10
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p contains " << *p << endl;
    
    //Task 11
    *p = -2763;
    cout << "p points to where " << *p << " is      stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "x now contains " << x << endl;
    
    //Task 12
    int y(13);
    cout << "y contains " << y << endl;
    p = &y;
    cout << "p now points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    *p = 980;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "y now contains " << y << endl;

    //Task 13
    int* q;
    q = p;
    cout << "q points to where " << *q << " is stored\n";
    cout << "*q contains " << *q << endl;
    
    //Task 14
    double d(33.44);
    double* pD(&d);
    *pD = *p;
    *pD = 73.2343;
    *p  = *pD;
    *q  = *p;
    //pD  = p;
    //p   = pD;
    
    //Task 15
    int joe( 24 );
    const int sal( 19 );
    int* pI;
    pI = &joe;
    *pI = 234;
    //pI = &sal; assigning a const int* to an int*
    *pI = 7623;
    
    const int* pcI;
    pcI = &joe;
    //*pcI = 234; can't change *pcI because it is const
    pcI = &sal;
    //*pcI = 7623; can't change *pcI because it is const
    
    //int* const cpI; CANNOT INTITIALIZE int* const implicitly
    int* const cpI(&joe);
    //int* const cpI(&sal); CANNOT DECLARE AGAIN
    //cpI = &joe; CPI IS CONST --> CANT CHANGE REFERENCE
    *cpI = 234;
    //cpI = &sal; CPI IS CONST --> CANT CHANGE REFERENCE
    *cpI = 7623;
    
    //const int* const cpcI; CANNOT INTITIALIZE  const int*  implicitly
    const int* const cpcI(&joe);
    //const int* const cpcI(&sal); CANNOT DECLARE AGAIN
    //cpcI = &joe; CANNOT CHANGE ADRESS THAT PONITER HOLDS
    //*cpcI = 234; CANNOT CHANGE THE VALUE AT THE ADDRESS
    //cpcI = &sal; CANNOT CHANGE ADRESS THAT POINTER HOLDS
    //*cpcI = 7623; CANNOT CHANGE THE VALUE AT THE ADDRESS
    
    //Task 16
    Complex c = {11.23,45.67};
    Complex* pC(&c);
    //cout << "real: " << *pC.real << "\nimaginary: " << *pC.img << endl;
    //cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img << endl;
    cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;
    
    //Task 17
    PlainOldClass poc;
    PlainOldClass* ppoc( &poc );
    cout << ppoc->getX() << endl;
    ppoc->setX( 2837 );
    cout << ppoc->getX() << endl;
    
    //Task 18
    //Top of file where PlainOldClass code is
    
    //Task 19
    int* pDyn = new int(3); // p points to an int initialized to 3 on the heap
    *pDyn = 17;
    cout << "The " << *pDyn << " is stored at address " << pDyn << " which is in the heap\n";
    
    //Task 20
    cout << pDyn << endl;
    delete pDyn;
    cout << pDyn << endl;
    cout << "The 17 might STILL be stored at address " << pDyn<< " even though we deleted pDyn\n";
    cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";
    
    //Task 21
    pDyn = nullptr;
    double* pDouble( nullptr );
    
    //Task 22
    //cout << "Can we dereference nullptr?  " << *pDyn << endl;
    //cout << "Can we dereference nullptr?  " << *pDouble << endl;
    
    //Task 24
    double* pTest = new double( 12 );
    delete pTest;
    pTest = nullptr;
    delete pTest; // safe
    
    //Task 25
    short* pShrt = new short( 5 );
    delete pShrt;
    //delete pShrt;
    
    //Task 26
    long jumper( 12238743 );
    //delete jumper;
    long* ptrTolong( &jumper );
    //delete ptrTolong;
    Complex cmplx;
    //delete cmplx;
    
    //Task 27
    vector<Complex*> complV; // can hold pointers to Complex objects
    Complex* tmpPCmplx;      // space for a Complex pointer
    for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
        tmpPCmplx = new Complex; // create a new Complex object on the heap
        tmpPCmplx->real = ndx;   // set real and img to be the
        tmpPCmplx->img  = ndx;   // value of the current ndx
        complV.push_back( tmpPCmplx ); // store the ADDRESS of the object in a vector or pointer to Complex
    }
    // display the objects using the pointers stored in the vector
    for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
        cout << complV[ ndx ]->real << endl;
        cout << complV[ ndx ]->img  << endl;
    }
    // release the heap space pointed at by the pointers in the vector
    for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
        delete complV[ ndx ];
    }
    // clear the vector
    complV.clear();
    
    //Task 28
    class Colour {
    public:
        Colour( const string& name, unsigned r, unsigned g, unsigned b )
        : name(name), r(r), g(g), b(b) {}
        void display() const {
            cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
        }
    private:
        string   name;    // what we call this colour
        unsigned r, g, b; // red/green/blue values for displaying
    };
    
    vector< Colour* > colours;
    string inputName;
    unsigned inputR, inputG, inputB;
    
    // fill vector with Colours from the file
    // this could be from an actual file but here we are using the keyboard instead of a file (so we don't have to create an actual file)
     // do you remember the keystroke combination to indicate "end of file" at the keyboard?
     // somehow the while's test has to fail - from keyboard input
     while ( cin >> inputName >> inputR >> inputG >> inputB ) {
         colours.push_back( new Colour(inputName, inputR, inputG, inputB) );
     }
     
     // display all the Colours in the vector:
     for ( size_t ndx = 0; ndx < colours.size(); ++ndx ) {
         colours[ndx]->display();
         cout << endl;
     }
    
    //Task 29
    class SpeakerSystem {
    public:
        void vibrateSpeakerCones( unsigned signal ) const {
            
            cout << "Playing: " << signal << "Hz sound..." << endl;
            cout << "Buzz, buzzy, buzzer, bzap!!!\n";
        }
    };
    
    class Amplifier {
    public:
        void attachSpeakers( const SpeakerSystem& spkrs )
        {
            if( attachedSpeakers )
                cout << "already have speakers attached!\n";
            else
                attachedSpeakers = &spkrs;
        }
        void detachSpeakers()
        { attachedSpeakers = nullptr; }
        // should there be an "error" message if not attached?
        void playMusic( ) const {
            if( attachedSpeakers )
                attachedSpeakers -> vibrateSpeakerCones( 440 );
            else
                cout << "No speakers attached\n";
        }
    private:
        const SpeakerSystem* attachedSpeakers = nullptr;
    };
    
    SpeakerSystem ss;
    Amplifier amp;
    amp.attachSpeakers(ss);
    amp.playMusic();
    amp.detachSpeakers();
    amp.playMusic();
    
    //Task 30
    class Person {
    public:
        Person( const string& name ) : name(name), roomie(nullptr){}
        void movesInWith( Person& newRoomate ) {
            if (roomie == nullptr && newRoomate.roomie == nullptr){
                roomie = &newRoomate;        // now I have a new roomie
                newRoomate.roomie = this;    // and now they do too
            }
            else{
                cout << "Cannot move. Already have a roomate.";
            }
        }
        string getName() const { return name; }
        // Don't need to use getName() below, just there for you to use in debugging.
        string getRoomiesName() const { return roomie->getName(); }
    private:
        Person* roomie;
        string name;
    };
    
    // write code to model two people in this world
    Person joeBob("Joe Bob"), billyJane("Billy Jane"), taimurGhani("Taimur Ghani");
    // now model these two becoming roommates
    joeBob.movesInWith( billyJane );
    // did this work out?
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << &billyJane << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
    cout << &joeBob << endl;
    joeBob.movesInWith(taimurGhani);
    
}

