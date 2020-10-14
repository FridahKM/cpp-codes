#include <iostream>
#include <string.h>

using namespace std;

class movie
{
private:
    string name[], starring[], released[], genre[], rating[];
    float price[], cost;
public:
    movie()
    {
        cost=0;
    }
    void newMovie();
    void findMovie();
    void display();
    int terminate();
};

int j, n;
void movie::newMovie()
{
    cout<<"How many movies?"<<endl;
    cin>>n;
    for(j=1; j<=n; j++)
    {
        cout<<"Enter movie "<<j<<" name"<<endl;
        cin>>name[j];
        cout<<"Enter movie "<<j<<" price"<<endl;
        cin>>price[j];
        cout<<"Enter movie "<<j<<" rating"<<endl;
        cin>>rating[j];
        cout<<"Enter starring actor"<<endl;
        cin>>starring[j];
        cout<<"Enter release date"<<endl;
        cin>>released[j];
        cout<<"Enter movie genre"<<endl;
        cin>>genre[j];
    }
}

bool available;
void movie::findMovie()
{
    char again='y';
    do
    {
    STRING mname, mrate;
    float mmin, mmax;
    cout<<"Enter movie name"<<endl;
    cin>>mname;
    cout<<"Enter the minimum price"<<endl;
    cin>>mmin;
    cout<<"Enter the maximum price"<<endl;
    cin>>mmax;
    cout<<"Enter movie rating"<<endl;
    cin>>mrate;

    //search for input data in existing data
    for(j=1; j<=n; j++)
    {
        if(strcmp(mname,name[j])==0 && mmin<=price[j] && mmax>=price[j] && strcmp(mrate,rating[j])==0)
        {
         available=true;
        }
        else
        {
         available=false;
        }
    }

    cout<<"Do you want to search another movie? [y/n]"<<endl;
    cin>>again;
    }while(again=='Y' || again=='y');
}


void movie::display()
{
 if(available==true)
 {

     cout<<"_____________________________________________________________________________________"<<endl;
     cout<<"\t\t\tMOVIES"<<endl;
     cout<<"_____________________________________________________________________________________"<<endl;
     cout<<"#\t\tMovie name\t\t Genre\t\tRating\t\tRelease year\tPrice"<<endl;
     for(j=1; j<=n; j++)
     {
        cout<<j<<"\t\t"<<name[j]<<"\t\t"<<genre[j]<<"\t\t"<<rating[j]<<"\t\t"<<released[j]<<"\t\t"<<price[j]<<endl;
     }
     cout<<"_____________________________________________________________________________________"<<endl;
     cout<<"_____________________________________________________________________________________"<<endl;

 }
 else if(available==false)
 {
     cout<<"There is no movie found from your search"<<endl;
 }
}

int movie::terminate()
{
    return 0;
}
int main()
{
    int choice;
    do
    {
        cout<<"*********************************************************************************"<<endl;
        cout<<"\t\tMovie Search"<<endl;
        cout<<"\t\t1. Add New Movie"<<endl;
        cout<<"\t\t2. Find Movie"<<endl;
        cout<<"\t\t3. Display Movies"<<endl;
        cout<<"\t\t4. Exit"<<endl;
        cout<<"*********************************************************************************"<<endl;
        cout<<"Select one of the above options"<<endl;
        cin>>choice;

        movie m;
        switch(choice)
        {
        case 1:
            m.newMovie();
            break;
        case 2:
            m.findMovie();
            break;
        case 3:
            m.display();
            break;
        case 4:
            m.terminate();
            break;
        }
    }while(choice!=4);

    return 0;
}
