/*
FILE         : ultimateRadio.cpp
PROJECT      : The Pioneer Radio project
PROGRAMMER   : Valeriia Rait
FIRST VERSION: 29.07.2023
DESCRIPTION  : This file contains all the test harness of all written classes
*/

#include <iostream>
#include <cstring>
#include <new>

#include "PioneerCarRadio.h"
#include "PioneerAM.h"
#include "PioneerWorld.h"


AmFmRadio* createRadio(const char* argument);

int main(int argc, char* argv[]) {
    AmFmRadio* pRadio = NULL;

    try {
        pRadio = createRadio(argv[2]);
    }
    catch (invalid_argument& exception) {
        cout << "Error: " << exception.what() << endl;
        return -1; //error code
    }

    while (true) {
        cout << "Enter the the code of type of radio which you want to instantiate: ";
        char input;
        cin >> input;

        try {
            if (input == 'c') {
                
                pRadio = createRadio("-car");
                pRadio->HandleKeypresses();
                delete pRadio;
            }
            else if (input == 'a') {
                
                pRadio = createRadio("-am");
                pRadio->HandleKeypresses();
                delete pRadio;
            }
            else if (input == 'w') {
                
                pRadio = createRadio("-world");
                pRadio->HandleKeypresses();
                delete pRadio;
            }
            else if (input == 'x') {
                return 0;
            }
            else {
                continue;
            }
        }
        catch (invalid_argument& exception) {
            cout << "Error ocured: " << exception.what() << endl;
            return -1; //error code
        }
    }
    return 0;
}


//AmFmRadio* createRadio(const char* argument)
//RETURNS: AmFmRadio* -instance of radio
//PARAMETERS: const char* argument -passed argument from the command line
//DESCIPTION: this function based on passed to it argunment command line instantiate new radio object
AmFmRadio* createRadio(const char* argument) {
    if (strcmp(argument, "-car") == 0) {
        return new PioneerCarRadio();
    }
    else if (strcmp(argument, "-am") == 0) {
        return new PioneerAM();
    }
    else if (strcmp(argument, "-world") == 0) {
        return new PioneerWorld();
    }
    else {
        throw invalid_argument("The chosen radio type is invalid");
    }
}