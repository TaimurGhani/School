//
//  main.cpp
//  MultipleInheritance
//
//  Created by Taimur Ghani on 4/4/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//


#include <iostream>
#include <vector>

using namespace std;

class Instrument{
public:
    Instrument(){}
    virtual void makeSound() const = 0;
	virtual void play() const = 0;
};

void Instrument::makeSound() const {
    cout << "To make a sound... ";
}

class Percusion : public Instrument{
public:
    Percusion(){}
    void makeSound() const {
        Instrument::makeSound();
        cout << "hit me!" << endl;
    }
};

class Brass : public Instrument{
public:
    Brass(int size) : size(size){}
    void makeSound() const{
        Instrument::makeSound();
        cout << "blow on a mouthpiece of size " << size << endl;;
    }
protected:
    int size;
    
};

class String : public Instrument{
public:
    String(int pitch) : pitch(pitch){}
    void makeSound() const{
        Instrument::makeSound();
        cout << "bow a string of pitch " << pitch << endl;;
    }
protected:
    int pitch;
    
};

class Drum : public Percusion{
public:
	void play() const{
		cout << "Boom" << endl;
	}
};

class Cymbal : public Percusion{
public:
	void play() const{
		cout << "Crash" << endl;
	}
};

class Trombone : public Brass{
public:
    Trombone(int size) : Brass(size) {}
	void play() const{
		cout << "Blat" << endl;
	}
};

class Trumpet : public Brass{
public:
    Trumpet(int size) : Brass(size) {}
	void play() const{
		cout << "Toot" << endl;
	}
};

class Violin : public String{
public:
    Violin(int size) : String(size) {}
	void play() const{
		cout << "Screech" << endl;
	}
};

class Cello : public String{
public:
    Cello(int size) : String(size) {}
	void play() const{
		cout << "Squawk" << endl;
	}
};

class Musician {
public:
    Musician() : instr(nullptr) {}
    
    void acceptInstr(Instrument* instPtr) { instr = instPtr; }
    
    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }
	
	void play(){
		if (instr != nullptr){
			instr->play();
		}
		else{
			cout << "Musician has no instrument!" << endl;
		}
	}
    
    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << "have no instr\n";
    }
    
private:
    Instrument* instr;
};

class MILL{
public:
    MILL(){}
    
    void receiveInstr(Instrument& inst){
        inst.makeSound();
        bool flag = false;
        for (size_t i = 0; i < instruments.size(); i++){
            if (instruments[i] == nullptr){
                instruments[i] = &inst;
                flag = true;
            }
        }
        if (!flag){
            instruments.push_back(&inst);
        }
    };
    
    void dailyTestPlay(){
        for (size_t i = 0; i < instruments.size(); i++){
            if (instruments[i] != nullptr){
                instruments[i] -> makeSound();
            }
        }
    }
    
    Instrument* loanOut(){
        for (size_t i = 0; i < instruments.size(); i++){
            if (instruments[i] != nullptr){
                Instrument* inst = instruments[i];
                instruments[i] = nullptr;
                return inst;
            }
        }
        return nullptr;
    }
private:
    vector<Instrument*> instruments;
};

class Orch{
public:
	Orch(){}
	void addPlayer(Musician& musician){
		if (musicians.size() > 25) {
			cout << "Orchestra already has 25 people!" << endl;
		}
		else{
			musicians.push_back(&musician);
		}
	}
	
	void play(){
		for (size_t i = 0; i < musicians.size(); i++){
			musicians[i]->play();
		}
	}
private:
	vector<Musician*> musicians;
};

// PART ONE
int main() {
    
    cout << "Define some instruments ----------------------------------------\n";
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12) ;
    Violin violin(567) ;
    // // use the debugger to look at the mill
    cout << "Define the MILL ------------------------------------------------\n";
    MILL mill;
    
    cout << "Put the instruments into the MILL ------------------------------\n";
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
    
    cout << "Daily test -----------------------------------------------------\n";
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
    
    cout << "Define some Musicians-------------------------------------------\n";
    Musician harpo;
    Musician groucho;
    
     cout << "TESTING: groucho.acceptInstr(mill.loanOut());-----------------------\n";
     groucho.testPlay();
     cout << endl;
     groucho.acceptInstr(mill.loanOut());
     cout << endl;
     groucho.testPlay();
     cout << endl;
     cout << "dailyTestPlay()" << endl;
     mill.dailyTestPlay();
    
	 cout << endl << endl;
    
     groucho.testPlay();
     cout << endl;
     mill.receiveInstr(*groucho.giveBackInstr());
     harpo.acceptInstr(mill.loanOut());
     groucho.acceptInstr(mill.loanOut());
     cout << endl;
     groucho.testPlay();
     cout << endl;
     harpo.testPlay();
     cout << endl;
     cout << "dailyTestPlay()" << endl;
     mill.dailyTestPlay();
	
     cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ----------\n";
	
     // fifth
     mill.receiveInstr(*groucho.giveBackInstr());
     cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
     mill.receiveInstr(*harpo.giveBackInstr());
	
	
     cout << endl;
     cout << "dailyTestPlay()" << endl;
     mill.dailyTestPlay();
     cout << endl;
	
     cout << endl;
	
	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;

	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(mill.loanOut());
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();


}


