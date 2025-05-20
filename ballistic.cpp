/*
Name: Rayen Ben Ismail
Date: 2/20/2025
Description: This program is a ballistics calculator
file naming: ballistic.cpp
*/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "libs\iotools.h"
#include "libs\pagetools.h"
using namespace std;

IoTools Io;

// Class definitions
class Projectile {
    public:

        float x0;
        float y0; 

        float yFloor;
        float xWall;

        float crossSection;
        float fCoef;
        bool friction;

        bool initialized;

        Projectile(){
            initialized = false;
        }

    private:
        float xCoord(int time);

        float yCoord(int time);

};

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
            }
        }

    private:
        void page0(){
            cout<<"MAIN MENU"<<endl<<endl;
            cout<<"Data Entry         [1]"<<endl;
            cout<<"Trajectory Display [2]"<<endl;
            cout<<"Exit               [0]"<<endl;

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
            cout<<"DATA ENTRY"<<endl<<endl;
            system("pause"); // CONTINUE HERE
        }


};

// Function prototypes
void menuProcess(char input[500], short* menuState, bool* endFlag);

int main(){
    PageTools2 Display(5);

    bool endFlag;
    short menuState = 00; // 00 for menu, 1X for the first layer of pages, 2X for the second...

    do{

        Display.pageSelect(menuState);

        switch(menuState){
            case 0:
                menuProcess(Display.entry[0], &menuState, &endFlag);
                break;
            case 10:
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
    }
}