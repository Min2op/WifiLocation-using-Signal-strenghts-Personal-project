#include "Controller.h";
#include <iostream>
using namespace std;

void Controller::viewMenu(){
    int choice = view.showMenu();
    switch(choice){
        case 1:
            cout << "hello" << endl;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }


}