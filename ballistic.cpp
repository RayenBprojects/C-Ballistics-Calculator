/*
Name: Rayen Ben Ismail
Date: 2/20/2025
Description: This program is a ballistics calculator
file naming: ballistic.cpp
*/

#include <iostream>
#include <conio.h>
#include "libs\iotools.h"
#include "libs\pagetools.h"
using namespace std;

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
            }
        }

    private:
        void page0(){
            cout<<"MAIN MENU"<<endl<<endl;
            cout<<"Data Entry [1]"<<endl;
            cout<<"Exit       [0]"<<endl;

        }


};


int main(){
    PageTools2 Display(5);

    bool endFlag;
    short menuState = 0;

    do{

        Display.pageSelect(0);

        fflush(stdin);
        while(!kbhit){}
        getch();
        endFlag = true;

    }while(endFlag == false);

    return 0;
}


