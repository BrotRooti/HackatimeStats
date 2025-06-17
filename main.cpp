//
// Created by Phillip on 17.06.2025.
//

#include <iostream>
#include <cstring>
#include <fstream>
#include <format>


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

void printUnknownArgument(const char *arg) {
    cout << "Unknown argument: " << arg << endl;
    cout << "Use --help to see available options." << endl;
}

string getAPIKey() {
    char * userpath = getenv("USERPROFILE");
    string path;
    if (userpath != nullptr)
        path = std::string(userpath) + "\\.wakatime.cfg";
    else
        std::cout << "No user path";

    fstream file(path,ios::in);
    if (!file.is_open()) {
        cout <<  format("Could not open the configuration file. Please ensure it exists at {}", path) << endl;
        return "-1";
    }
    cout << "Reading configuration file from: " << path << endl;
    for (string line; getline(file, line); ) {
        if (line.find("api_key") != string::npos) {
            size_t pos = line.find("=");
            if (pos != string::npos) {
                string api_key = line.substr(pos + 1);
                return api_key;
            }
        }
    }

    return "-1";
}

void statsSystem() {
    cout << "Welcome to Hackatime Stats!" << endl;
    cout << "This program is designed to fetch and display your coding statistics from Hackatime." << endl;
    cout << "At the moment, it is a work in progress." << endl;
    cout << "\n\n\n\n";


    const string api_key = getAPIKey();
    if (api_key == "-1") {
        cout << "Exiting due to missing API key." << endl;
        return;
    }
    cout << "Your API key is: " << api_key << endl;

}

int main(const int argc, char *argv[]) {
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
        printUnknownArgument(argv[1]);
        return 1;
    }
    cout << "Too many arguments. Please use --help for more information." << endl;
    return 1;
}
