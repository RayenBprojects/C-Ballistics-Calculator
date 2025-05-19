#ifndef IOTOOLS_H //HEADER_FILE_IOTOOLS_H
#define IOTOOLS_H //HEADER_FILE_IOTOOLS_H

#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;


class IoTools{ // Common class for various projects
	
	public:
		
		void lineTool(int size, char lineChar = '-', bool returnLine = false);
		
		void barTool(float nominator = 0 , float denominator = 1 , int barLength = 100 , bool percentDisplay = true, bool returnLine = false);
		
		void promptTool(char prompt[500] , char result[500] , char error[500],bool doError = false, bool isNumber = false);


		void IoTools::lineTool(int size , char lineChar, bool returnLine){
			for (int i = 0 ; i < size ; i++){
				cout<<lineChar;
			}
			if (returnLine){
				cout<<endl;
			}
		}

		void IoTools::barTool(float nominator , float denominator , int barLength , bool percentDisplay , bool returnLine){
			float tempLengthFloat = (nominator/denominator)*((float)barLength);
			int tempLength = tempLengthFloat;
			if (tempLengthFloat - tempLength > 0.5){
				tempLength++;
			}
	
			cout<<'['; lineTool(tempLength, '|', false); lineTool(barLength - tempLength, '-', false) ; cout<<']';
	
			if (percentDisplay){
				float tempPercent = (nominator/denominator)*100;
				cout<<' '<<fixed<<setprecision(1)<<setw(5)<<tempPercent<<'%';
			}

			if (returnLine){
				cout<<endl;
			}
	} 

		void IoTools::promptTool(char prompt[500] , char result[500], char error[500], bool doError , bool isNumber){

			if (!doError){
				bool errorFlag;
				bool lengthFlag;
				do{
					errorFlag = false;
					lengthFlag = false;
			
					cout<<prompt;
					cin>>result;
			
					for (int i = 0 ; i < 500 ; i++){
						if (result[i] == '\0'){
							lengthFlag = true;
							break;
						}
				
						if (isNumber && (result[i] != '0') && (result[i] != '1') && (result[i] != '2') && (result[i] != '3') && (result[i] != '4') && (result[i] != '5') && (result[i] != '6') && (result[i] != '7') && (result[i] != '8') && (result[i] != '9')){
							errorFlag = true;
							break;
						}
					}
			
					if (!lengthFlag){
						errorFlag = true;
					}
			
					if (errorFlag){
						cout<<error;
				
						while(!kbhit()){}
						getch();
				
						cout<<"\x1b[2K"<<"\x1b[1F"<<"\x1b[2K";
				
					}
			
				} while(errorFlag);
			}
			else{
				cout<<error;
				getch();
				while(!kbhit){}
				getch;
				cout<<"\x1b[2K"<<"\x1b[1F"<<"\x1b[2K";
			}

		}
};











#endif