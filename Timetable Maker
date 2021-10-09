#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
//declare classes
class lecturer{
    private:
        string lecname[100];
    public:
        void addlecturer();
};

class hall{
    private:
        string hallname[100];
        int capacity[100];
    public:
        void addhall();
};

class unit{
    private:
        string uname[250];
        string ucode[250];
        int regstud[250];
    public:
        void addunits();
};

//functions for adding items
void lecturer::addlecturer(){
    int lecs;
    cout << "How many lecturers?" <<endl;
    cin>>lecs;

    for(int i=1; i<=lecs; i++){
        cout << "Enter lecturer's "<<i<<" name."<<endl;
        cin>>lecname[i];
    }
}

void hall::addhall(){
    int no;
    cout << "How many lecture halls?" <<endl;
    cin>>no;

    for(int j=1; j<=no; j++){
        cout << "Enter hall's "<<j<<" name."<<endl;
        cin>>hallname[j];
        cout << "Enter hall's "<<j<<" capacity."<<endl;
        cin>>capacity[j];
    }
}

void unit::addunits(){
    int un;
    cout << "How many units?" <<endl;
    cin>>un;

    for(int k=1; k<=un; k++){
        cout << "Enter unit's "<<k<<" name."<<endl;
        cin>>uname[k];
        cout << "Enter unit's "<<k<<" code."<<endl;
        cin>>ucode[k];
        cout << "Enter unit's "<<k<<" number of registered students."<<endl;
        cin>>regstud[k];
    }
}

//method for exiting program
int endprogram(){
    return 0;
}

int main()
{
    int option;
    do{
       cout << "----------------------------------------------------------------------------------" << endl;
       cout << "WELCOME TO THE TIMETABLE AUTOMATION SYSTEM" << endl;
       cout << "1. Add units." << endl;
       cout << "2. Add lecturers." << endl;
       cout << "3. Add lecture halls." << endl;
       cout << "4. Create the timetable." << endl;
       cout << "5. Exit." << endl;
       cout << "----------------------------------------------------------------------------------" << endl;
       cout << "Select one of the above options." << endl;
       cin>>option;

       while(option<1 || option>5){
        cout << "Invalid choice. Select one of the above options." << endl;
        cin>>option;
       }

       //create objects
       unit U;
       lecturer L;
       hall H;

       switch (option){

       case 1:
           U.addunits();
           break;
       case 2:
           L.addlecturer();
           break;
       case 3:
           H.addhall();
           break;
       case 4:
           break;
       case 5:
           endprogram();
           break;

       }

    }while(option!=5);

    return 0;
}
