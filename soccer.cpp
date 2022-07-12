#include <iostream>
#include <fstream>
#include <iomanip>
#include<stdlib.h>

using namespace std;

const int WIDTH = 35;

void printTeamRoaster(string soccerTeam[][3]);

int getGoals(string soccerTeam[][3]);

string getStars(string soccerTeam[][3]);

int main() {
    string fileName;
    char number;
    fstream myFile;
    string soccerTeam[11][3];


    cout << "Soccer team goals..." << endl;
    while (true) {
        cout << endl;
        cout << "Choose one of the following options" << endl;
        cout << "1. Load team's information." << endl;
        cout << "2. Display team's roaster." << endl;
        cout << "3. Display team's goals" << endl;
        cout << "4. Display team's star(s)." << endl;
        cout << "5. Quit." << endl;


        cin >> number;
        switch (number) {
            case '1':
                cout << "\nEnter the Name of the File" << endl;

                cin >> fileName;


                myFile.open(fileName, ios::in);
                if (myFile) {
                    while (!myFile.eof()) {
                        for (int i = 0; i < 11; i++) {
                            for (int j = 0; j < 3; j++) {


                                //myFile.ignore();
                                getline(myFile, soccerTeam[i][j]);
                            }
                        }

                    }
                } else {
                    cout << " Fatal Error ... Could not open file " << fileName << "." << endl;

                }

                break;


            case '2':

                printTeamRoaster(soccerTeam);

                break;

            case '3':

                cout << " Total Goals Scored : " << getGoals(soccerTeam) << endl;


                break;

            case '4':
                getStars(soccerTeam);
                break;


            case '5':

                exit(0);

            default:
                cout << "Unknown option. Try again..." << endl;


        }

    }


}

void printTeamRoaster(string soccerTeam[][3]) {
    cout << "\nTeam roaster ..." << endl << endl

         << setw(20) << left << "Player Name"
         << setw(10) << left << "Number"
         << setw(5) << left << "Goals" << endl;

    for (int i = 0; i < WIDTH; i++)
        cout << '-';
    cout << endl;

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 3; j++) {

        }
        cout << setw(20) << left << soccerTeam[i][0]
             << setw(10) << left << soccerTeam[i][1]
             << setw(5) << left << soccerTeam[i][2] << endl;
    }
}

int getGoals(string soccerTeam[][3]) {
    int goals = 0;
    for (int i = 0; i < 11; i++) {
        goals += atoi(soccerTeam[i][2].c_str());
    }
    return goals;
}

string getStars(string soccerTeam[][3]) {
    string goalStar;
    int maxGoals = 0;
    for (int i = 0; i < 11; i++) {

        int currentGoals = atoi(soccerTeam[i][2].c_str());
        if (currentGoals > maxGoals) {

            maxGoals = currentGoals;

        }

    }
    for (int i = 0; i < 11; i++) {
        if (atoi(soccerTeam[i][2].c_str()) == maxGoals) {
            cout << soccerTeam[i][0] << " " << maxGoals << endl;
        }
    }
}