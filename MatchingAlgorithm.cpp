#include "MatchingAlgorithm.h"
#include <string>
#include <unistd.h>
#include <fstream>
#include <string>
#include <iostream>


using namespace std;



CurrentReading MatchingAlgorithm::getRealtimeReading(){
    CurrentReading incomingReading;
    string mac;
    int signalStrength;

    string command = "sudo iwlist wlo1 scan | grep -e Address -e level > currentReading.txt";
    system(command.c_str());    
    ifstream iFile;
    iFile.open("/home/alex/Documents/Personal project/build/currentReading.txt", ios::in);   

    string holder;
    while(iFile >> holder){
                
                if(holder == "Address:"){
                    iFile >> mac;
                }
                else if (holder == "Signal")
                {
                    iFile >> holder;
                    holder = holder.substr(6,3);
                    signalStrength = stoi(holder);
                    incomingReading.current_MacID_Signalstrength.push_back(make_pair(mac,signalStrength));
                    incoming_Readings.push_back(incomingReading);
                }    

    }

    for(int i = 0; i < incoming_Readings.size(); i++){
        for(int k = 0; k < incoming_Readings[i].current_MacID_Signalstrength.size(); k++){
            cout << incoming_Readings[i].current_MacID_Signalstrength[k].first << endl;
            cout << incoming_Readings[i].current_MacID_Signalstrength[k].second << endl;
        }
    }

    return incomingReading;
}