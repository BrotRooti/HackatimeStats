//
// Created by Phillip on 17.06.2025.
//

#include <iostream>
#include <cstring>


using namespace std;

void printHelp() {
    cout << "This is a terminal program, which gets your stats from Hackatime and shows you some graphics/statistics." << endl;
    cout << "Usage: hackatime-stats [options]" << endl;
    cout << "Options:" << endl;
    cout << "  --help      Show this help message and exit" << endl;
    cout << "  --version   Show version information and exit" << endl;
}

void printVersion() {
    cout << "Hackatime Stats version 1.0" << endl;
    cout << "This program is a work in progress." << endl;
    cout << "Please check back later for more features." << endl;
}

void statsSystem() {
    cout << "Welcome to Hackatime Stats!" << endl;
    cout << "This program is designed to fetch and display your coding statistics from Hackatime." << endl;
    cout << "At the moment, it is a work in progress." << endl;
    cout << "Please check back later for more features." << endl;
}

int main( int argc, char *argv[]) {
    if (argc == 1) {
        statsSystem();
        return 0;
    }
    if (argc == 2) {
        if (strcmp(argv[1], "--help")==0) {
            printHelp();
            return 0;
        }
        if (strcmp(argv[1],"--version")==0) {
            cout << "Hackatime Stats version 1.0" << endl;
            return 0;
        }
        cout << "Unknown argument: " << argv[1] << endl;
        printHelp();
        return 1;
    }
    cout << "Too many arguments. Please use --help for more information." << endl;
    return 1;
}
