#include "View.h"
#include <iostream>
using namespace std;

int View::showMenu(){
    int choice = 0;
    do
    {
        
        cout << "***************************" << endl;
        cout << " Welcome To the Main Menu " << endl;
        cout << "***************************" << endl;
        cout << "1. Load Room Data from Files " << endl;
        cout << "2. Check Amount of Room Data " << endl;
        cout << "3. Start matching Algorithm  " << endl;
        cout << "4. Exit the programme        " << endl;
        
        cin >> choice;
        return choice;     
    }while (choice != 4);
   
   
}


