#pragma once
#include "Dataset.h"
#include "MatchingAlgorithm.h"


class Model{
    private: 
    vector<room> Rooms;
    CurrentReading current_Reading;
    dataset data;
    MatchingAlgorithm matcher;
    bool roomFound = false;

    public:
    void getData();
    void starReadingSignals();
    void findRoom();


    
};