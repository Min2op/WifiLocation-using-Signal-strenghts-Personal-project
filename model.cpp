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
                                    ++Rooms[i].guessScore;
                            }
                            else if((current_Reading.current_MacID_Signalstrength[k].second - Rooms[i].macID_SignalStrength[j].second <= 3) && 
                                    (current_Reading.current_MacID_Signalstrength[k].second - Rooms[i].macID_SignalStrength[j].second >= -3)){
                                    ++Rooms[i].guessScore;
                            }
                       
                        }
                   
                   }
                  
                }
             
            }
            tester();
        }

void Model::tester(){
    string king;
    int biggest = 0;
    for(int i=0; i < Rooms.size(); i++){
        if(Rooms[i].guessScore > biggest){
           biggest =  Rooms[i].guessScore;
           king = Rooms[i].roomNo; 
           cout <<  biggest << endl;
        }
    }

    cout << "We guess that you are in the room " << king << " with the score " << biggest << endl;

}