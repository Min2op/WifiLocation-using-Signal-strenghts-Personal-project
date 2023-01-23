#include "Model.h"

void Model::getData(){
    data.setDatafromFiles();
    Rooms = data.returnDataFromFiles();

}

