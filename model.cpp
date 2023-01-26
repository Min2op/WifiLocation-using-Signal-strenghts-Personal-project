#include "Model.h"
#include <iostream>

using namespace std;

void Model::getData(){
    data.setDatafromFiles();
    Rooms = data.returnDataFromFiles();

}

void Model::starReadingSignals(){
    current_Reading = matcher.getRealtimeReading();
    

}

void Model::findRoom(){
    cout << "test" << endl;
    int threshhold;

        for(int i = 0; i < Rooms.size(); i++){
            for(int k = 0; k < current_Reading.current_MacID_Signalstrength.size(); k++){
                   for(int j = 0; j < Rooms[i].macID_SignalStrength.size(); j++){
                        if(current_Reading.current_MacID_Signalstrength[k].first == Rooms[i].macID_SignalStrength[j].first){
                            cout << "sniffing " << endl;
                            cout << "Current read mac address: " << current_Reading.current_MacID_Signalstrength[k].first << endl;
                            cout << "Mac address from historical data: " << Rooms[i].macID_SignalStrength[j].first << endl;
                            if(current_Reading.current_MacID_Signalstrength[k].second == Rooms[i].macID_SignalStrength[j].second){
                                ++threshhold;

                            }
                        }
                   
                   }
                    if(threshhold > 3){
                    cout << "Are you in the room? " << Rooms[i].roomNo << endl;
                    break;
                    }
                }
             
            }
            
        }
    