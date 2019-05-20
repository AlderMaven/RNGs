//Created by Brandon Barnes
//Randomized string generators

#include <iostream>
#include <RNG.h> //Must include RNG.h from repository
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <unistd.h>

using namespace std;

class randStringGen{
	string generateLowerCase(int length){
	
		string returnString;
		char temp;
		RNG rando;
		
		std::ostringstream oss;
		
		
		for(int i = 0; i<length+1; i++){
		
			temp = (char) rando.fastRandNum(97,122);
			oss << temp;
			usleep(rando.fastRandNum(650, 900));
		}
		returnString = oss.str();
		return returnString;
	}

	string generateUpperCase(int length){
		
		string returnString;
		char temp;
		RNG rando;
		
		std::ostringstream oss;
		
		for(int i = 0; i<length+1; i++){
			temp = (char) rando.fastRandNum(65,90);
			oss << temp;
			usleep(rando.fastRandNum(65, 90));
		}
		returnString = oss.str();
		return returnString;
	}
	
	public:
	string randString(int length){
		
		if(length<1){
			return NULL;
		}
		RNG rando;
		string returnString;
		
		for(int i = 0; i<length+1; i++){
			
			if(rando.fastRandNum(0,1)){
				returnString = returnString + generateLowerCase(1);
			}
			else{
				returnString = returnString + generateUpperCase(1);
			}
		}
		return returnString;
	}
	
	
	string randString(int length, int caseFlag){
		if(length<1){
			return NULL;
		}
		switch(caseFlag){
			case 1: return randString(length);
			case 2: return generateLowerCase(length);
			case 3: return generateUpperCase(length);
			default: return NULL;
		}
	}
	string randString(int minLength, int maxLength, int caseFlag){
		
		if(minLength == maxLength){
			return randString(minLength, caseFlag);
		}
		else if(minLength > maxLength){
			return NULL;
		}
		
		RNG rando;
		int length = rando.fastRandNum(minLength, maxLength);
		
		switch(caseFlag){
			case 1: return randString(length); break;
			case 2: return generateLowerCase(length); break;
			case 3: return generateUpperCase(length); break;
			default: return NULL; break;
		}
		
	}
};



int main(){
	
	randStringGen rando;
	
	string printingString = (rando.randString(2,4,2));
	cout << printingString << endl;
	return 0;
}