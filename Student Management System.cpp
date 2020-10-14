#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class unit;
class student
{
protected:
    string sname, course, department;
    int regno, year, sem;
public:
    void newStudent();
    void regStudent();
    friend void display(student stu, unit un);
};

class unit
{
protected:
    char uname[30][7], ucode[10][7], grade[7], remarks[10][7], sclass[25];
    float cat[7], project[7], attend[7], exam[7], total[7];
    double allsum, average;
public:
    void inputMarks();
    void getAverage();
    unit()
    {
        average=0;
    }
    friend void display(student stu, unit un);
};

void student::newStudent()
{
    cout<<"Enter student's name"<<endl;
    cin>>sname;
    cout<<"Enter student's registration number"<<endl;
    cin>>regno;
    cout<<"Enter student's course name"<<endl;
    cin>>course;
    cout<<"Enter student's department"<<endl;
    cin>>department;
}

void student::regStudent()
{
    cout<<"Enter academic year"<<endl;
    cin>>year;
    cout<<"Enter semester [1/2]"<<endl;
    cin>>sem;
}

int input, j;
void unit::inputMarks()
{
    cout<<"How many units?"<<endl;
    cin>>input;

    //restrict number of units
    while(input<3 || input>7)
    {
        cout<<"Invalid entry. You can input minimum of 3 and maximum of 7 units"<<endl;
        cout<<"How many units?"<<endl;
        cin>>input;
    }

    for(j=1; j<=input; j++)
    {
        cout<<"Enter unit "<<j<<" name"<<endl;
        cin>>uname[j];
        cout<<"Enter unit "<<j<<" code"<<endl;
        cin>>ucode[j];
        cout<<"Enter sitting CAT marks [out of 15]"<<endl;
        cin>>cat[j];
        //validate input
        while(cat[j]<0 || cat[j]>15)
        {
            cout<<"Invalid entry"<<endl;
            cout<<"Enter sitting CAT marks [out of 15]"<<endl;
            cin>>cat[j];
        }
        cout<<"Enter semester project marks [out of 20]"<<endl;
        cin>>project[j];
        //validate input
        while(project[j]<0 || project[j]>20)
        {
            cout<<"Invalid entry"<<endl;
            cout<<"Enter semester project marks [out of 20]"<<endl;
            cin>>project[j];
        }
        cout<<"Enter attendance marks [out of 5]"<<endl;
        cin>>attend[j];
        //validate input
        while(attend[j]<0 || attend[j]>5)
        {
            cout<<"Invalid entry"<<endl;
            cout<<"Enter attendance marks [out of 5]"<<endl;
            cin>>attend[j];
        }
        cout<<"Enter exam marks [out of 60]"<<endl;
        cin>>exam[j];
        //validate input
        while(exam[j]<0 || exam[j]>60)
        {
            cout<<"Invalid entry"<<endl;
            cout<<"Enter exam marks [out of 60]"<<endl;
            cin>>exam[j];
        }

        //obtain total score for a unit
        total[j]=cat[j]+attend[j]+project[j]+exam[j];

        //get grade and remarks
        if(total[j]>=70 && total[j]<=100)
        {
            grade[j]='A';
            strcpy(remarks[j],"Excellent");
        }
        else if(total[j]>=60 && total[j]<=69)
        {
            grade[j]='B';
            strcpy(remarks[j],"Good");
        }
        else if(total[j]>=50 && total[j]<=59)
        {
            grade[j]='C';
            strcpy(remarks[j],"Fair");
        }
        else if(total[j]>=40 && total[j]<=49)
        {
            grade[j]='D';
            strcpy(remarks[j],"Pass");
        }
        else if(total[j]>=0 && total[j]<=40)
        {
            grade[j]='F';
            strcpy(remarks[j],"Fail");
        }

        //obtain the total score for all units
        allsum+=total[j];
    }
}

void unit::getAverage()
{
    average=allsum/input; //input is number of units
    if (average>=70 && average<=100)
    {
        strcpy(sclass,"First Class");
    }
    else if (average>=60 && average<=69)
    {
        strcpy(sclass,"Second Class, Upper Division");
    }
    else if (average>=50 && average<=59)
    {
        strcpy(sclass,"Second Class, Lower Division");
    }
    else if (average>=40 && average<=49)
    {
        strcpy(sclass,"Pass");
    }
}

void display(student stu, unit un)
{
    cout<<"Student Transcript"<<endl;
    cout<<"Sunshine College International"<<endl;
    cout<<endl;
    cout<<"Registration Number\t"<<stu.regno<<endl;
    cout<<"Full Names\t\t"<<stu.sname<<endl;
    cout<<"Department\t\t"<<stu.department<<endl;
    cout<<"Academic year\t\tYear "<<stu.year<<endl;
    cout<<"Program\t\t"<<stu.course<<endl;
    cout<<endl;
    cout<<"Unit Code"<<setw(15)<<"Unit Name"<<setw(15)<<"CAT(x/15)"<<setw(15)<<"Attendance(x/5)"<<setw(15)<<"Project(x/20)"<<setw(15)<<"Exam(x/60)"<<setw(15)<<"Total(x/100)"<<setw(10)<<"Grade"<<setw(15)<<"Remarks"<<endl;
    for(j=1; j<=input; j++)
    {
    cout<<un.ucode[j]<<setw(15)<<un.uname[j]<<setw(15)<<un.cat[j]<<setw(15)<<un.attend[j]<<setw(15)<<un.project[j]<<setw(15)<<un.exam[j]<<setw(15)<<un.total[j]<<setw(10)<<un.grade[j]<<setw(15)<<un.remarks[j]<<endl;
    }
    cout<<"*****************************************************************************************************************************************"<<endl;
    cout<<"\tAverage Score\t"<<un.average<<"%\tClass\t"<<un.sclass<<endl;
    cout<<"*****************************************************************************************************************************************"<<endl;
}
int main()
{
    int choice;
    do
    {
    cout<<"******************************************************************************"<<endl;
    cout<<"\t\tWelcome to Sunshine our Academic Management System AMS)"<<endl;
    cout<<"\t\t\t1. Create new student"<<endl;
    cout<<"\t\t\t2. Register Student"<<endl;
    cout<<"\t\t\t3. Key in Student Marks"<<endl;
    cout<<"\t\t\t4. Print student Progressive"<<endl;
    cout<<"\t\t\t5. Exit"<<endl;
    cout<<"******************************************************************************"<<endl;
    cout<<"select one of the above options"<<endl;
    cin>>choice;

    while(choice<1 || choice>5)
    {
     cout<<"Invalid choice. Select a number between 1 and 5"<<endl;
     cin>>choice;
    }

    student s;
    unit u;
    switch(choice)
    {
    case 1:
        s.newStudent();
        break;
    case 2:
        s.regStudent();
        break;
    case 3:
        u.inputMarks();
        break;
    case 4:
        u.getAverage();
        display(s, u);
        break;
    case 5:
        break;
    }
    }while(choice!=5);
    return 0;
}
