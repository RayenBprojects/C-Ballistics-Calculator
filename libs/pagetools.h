/* TASKS:

Needs an exit route when allocation keeps failing

*/


#ifndef PAGETOOLS_H //HEADER_FILE_IOTOOLS_H
#define PAGETOOLS_H //HEADER_FILE_IOTOOLS_H

#include <iostream>

class PageTools{

    public:

        char** entry;

        PageTools(int arraySize){

            bool allocFlag = true;

            entryNum = arraySize;

            do{
                char** tempPointer = new char*[arraySize];

                if (tempPointer == NULL){
                    allocFlag = false;
                }
                else{
                   allocFlag = true;
                   entry=tempPointer;
               }
            } while (!allocFlag);
            
            for (int i = 0 ; i < arraySize ; i++){
                do{
                    char* tempPointer2 = new char[100];

                    if (tempPointer2 == NULL){
                        allocFlag = false;
                    }
                    else{
                        allocFlag = true;
                        entry[i]=tempPointer2;
                    }
                } while (allocFlag == false);
            }
        }

        ~PageTools(){
            delete[] entry;
        }

    protected:
        int entryNum;
        virtual void pageSelect(short page) = 0;

};


#endif