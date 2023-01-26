#include "Dataset.h"
#include <fstream>
#include <filesystem>
#include <iostream>

void dataset::setDatafromFiles(){
    string lineHolder, readMacAdress, readSignalStrength;
    ifstream reader;
    auto fileReader = filesystem::directory_iterator("/home/alex/Documents/Personal project/CalibratedRooms/");       
    for(auto& entry : fileReader){
        room* holderObject = new room();
        filesystem::path F = entry;
        cout << F.filename() << endl;
        reader.open(F, ios::in);
        
        while(!reader.eof()){
            reader >> readMacAdress;
            reader >> readSignalStrength;
            holderObject->macID_SignalStrength.push_back(make_pair(readMacAdress, stoi(readSignalStrength)));

        }
        holderObject->roomNo = F.filename();
        holderObject->macID_SignalStrength.pop_back();
        Rooms.push_back(*holderObject);
        delete holderObject;
        
        reader.close();
        reader.clear();

        
    }

    for(int i = 0; i < Rooms.size(); i++){
            cout << Rooms[i].roomNo << endl;
            for(int k = 0; k < Rooms[i].macID_SignalStrength.size(); k++){
                cout << Rooms[i].macID_SignalStrength[k].first << endl;
                cout << Rooms[i].macID_SignalStrength[k].second << endl;
            }
        }

}

vector<room> dataset::returnDataFromFiles(){
    return Rooms;
}