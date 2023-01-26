#include "Controller.h"
#include <iostream>
using namespace std;

void Controller::viewMenu(){
    int choice = 0;
    do 
    {
        choice = view.showMenu();
        switch(choice){
        case 1:
            model.getData();
            break;
        case 2:
            model.findRoom();
            break;
        case 3:
            model.starReadingSignals();
            break;
        case 4:
            break;
        }
    
 


    }while (choice != 4);
 
    
}