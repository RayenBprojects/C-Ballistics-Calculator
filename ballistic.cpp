/*
Name: Rayen Ben Ismail
Date: 2/20/2025
Description: This program is a ballistics calculator
file naming: ballistic.cpp
*/

/* PENDING TASKS
    GOAL: create version 1.0 (calculations without friction, wall, or angle)
    next up: redo unit display in the data page

    AFTER 1.0:
    Add rest of prompts in page20(), PageTools2 class
    Add Negative and float number functionality to iotools.h library (promptTool method)
*/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "libs\iotools.h"
IoTools Io;
#include "libs\pagetools.h"
using namespace std;

// Constants
const short entryAlloc = 6;

// Class definitions
class Projectile {
    public:

        float speed;
        float angle;
        float height;

        float xWall;
        float angleGround;

        float xSection; // as in cross section, unrelated to x
        float fCoef;
        
        bool aeroDelete;
        bool wallDelete;
        bool angleDelete;

        bool initialized;

        Projectile(){
            initialized = false;

            speed = 0;
            angle = 0;
            height = 0;

            xWall = 0;
            angleGround = 0;

            xSection = 0;
            fCoef = 0;

            aeroDelete = true;
            wallDelete = true;
            angleDelete = true;
        }

    private:
        float xCoord(int time);

        float yCoord(int time);

};
Projectile Ballistic;

class PageTools2 : public PageTools{
    public:
        PageTools2(int arraySize):PageTools(arraySize){}

        void pageSelect(short page){

            system("cls");
            for (int i = 0 ; i < entryNum ; i++){
                entry[i][0] = '\0';
            }

            switch (page){
                case 0:
                    page0();
                    break;
                case 10:
                    page10();
                    break;
                case 11:
                    page11();
                    break;
                
            }
        }

    private:
        void page0(){
            cout<<"MAIN MENU"<<endl<<endl;
            cout<<"Settings                    [1]"<<endl;
            cout<<"Data entry                  [2]"<<endl;
            if (Ballistic.initialized){
                cout<<"Trajectory Display          [-]"<<endl;
            }
            else{
                cout<<"Trajectory Display (NO DATA)[-]"<<endl;
            }
            cout<<"Exit                        [0]"<<endl;

            int falseFlag;
            do{
                falseFlag = false;

                char prompt[500] = "-->";
                char error[500] = "Please choose a presented number";
                Io.promptTool(prompt, entry[0], error, false, true);

                if (atoi(entry[0]) > 2){
                    falseFlag = true;
                    Io.promptTool(prompt, entry[0], error, true, true);
                }
            } while (falseFlag);
        }

        void page10(){
            bool falseFlag;
            char prompt[3][500] = {
                "Ignore air friction [Y/N] : ",
                "Remove wall         [Y/N] : ",
                "Angled ground       [Y/N] : "
            };
            char error[500] = "Please enter 'Y' or 'N'";

            cout<<"Settings"<<endl<<endl;

            for(int i = 0 ; i < 3 ; i++){
                cout<<prompt[i]<<endl<<endl;
            }
            for (int i = 0 ; i < 6 ; i++){
                cout<<"\x1b[A";
            }

            
            for (int i = 0 ; i < 3 ; i++){
                do{
                    falseFlag = false;
                    Io.promptTool(prompt[i],entry[i],error,false,false);
                    if (( tolower(entry[i][0]) != 'n' && tolower(entry[i][0]) != 'y') || ( entry[i][1] != '\0' ) ){
                        falseFlag = true;
                        Io.promptTool(prompt[i],entry[i],error,true,false);
                    }
                }while (falseFlag);
                cout<<endl;
            }
        }

        void page11(){
            bool falseFlag;
            short lineCount = 6;
            char prompt[7][500] = { "Launch velocity     (m/s): ",
                                    "Launch angle    (degrees): ",
                                    "Launch height         (m): ",
                                    "Aero cross section  (m^2): ",
                                    "Aero friction coef       : ",
                                    "Distance from wall    (m): ",
                                    "Ground Angle    (degrees): "};

            char error[500] = "Please enter valid data";
            
            cout<<"DATA ENTRY"<<endl<<endl;

            for(int i = 0 ; i < 3 ; i++){
                cout<<prompt[i]<<endl<<endl;
            }
            if(!Ballistic.aeroDelete){
                for (int i = 3 ; i < 5 ; i++){
                    cout<<prompt[i]<<endl<<endl;
                }
                lineCount += 4;
            }
            if(!Ballistic.wallDelete){
                cout<<prompt[5]<<endl<<endl;
                lineCount += 2;
            }
            if(!Ballistic.angleDelete){
                cout<<prompt[6]<<endl;
                lineCount += 1;
            }
            for (int i = 0 ; i < lineCount ; i++){
                cout<<"\x1b[A";
            }

            for(int i = 0 ; i < 3 ; i++){
                do{
                    falseFlag =false;
                    Io.promptTool(prompt[i], entry[i], error, false, true);
                } while(falseFlag);
                cout<<endl;
            }
        }
};

// Function prototypes
void menuProcess(char input[500], short* menuState, bool* endFlag);
void settingProcess(short* menuState, char* entry[entryAlloc]);
void dataProcess(short* menuState, char* entry[entryAlloc]);

int main(){
    PageTools2 Display(entryAlloc);

    bool endFlag;
    short menuState = 00;
    /* PAGE INDEX - Wanted to make nested pages but it would've just been bad ui
    * 0 for menu
    * 10 for settings page
    * 11 for data entry page
    * 12 for trajectory display page
    */


    do{

        Display.pageSelect(menuState);

        switch(menuState){
            case 0:
                menuProcess(Display.entry[0], &menuState, &endFlag);
                break;
            case 10:
                settingProcess(&menuState, Display.entry);
                break;
            case 11:
                dataProcess(&menuState, Display.entry);
                break;
        }

    }while(endFlag == false);

    return 0;
}

void menuProcess(char input[500], short* menuState, bool* endFlag){
    switch (atoi(input)){
        case 0:
            *endFlag = true;
            break;
        case 1:
            *menuState = 10;
            break;
        case 2:
            *menuState = 11;
            break;
        case 3:
            *menuState = 12;
            break;
    }
}

void settingProcess(short* menuState, char* entry[entryAlloc]){

    bool choice[3]; // 0 for aerodelete, 1 for walldelete, 2 for angledelete

    for (int i = 0; i < 3; i++){
        switch (tolower(entry[i][0])){
            case 121: // ASCII for 'y'
                choice[i] = true;
                break;
            case 110: // ASCII for 'n'
                choice[i] = false;
                break;
        }
    }

    Ballistic.aeroDelete = choice[0];
    Ballistic.wallDelete = choice[1];
    Ballistic.angleDelete = choice[2];

    *menuState = 0;

}

void dataProcess(short* menuState, char* entry[entryAlloc]){
    Ballistic.initialized = true;

    Ballistic.speed = atoi(entry[0]);
    Ballistic.angle = atoi(entry[1]);
    Ballistic.height = atoi(entry[2]);

    *menuState = 0;
}