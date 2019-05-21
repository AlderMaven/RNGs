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
	//generates a string of distinct length with only lowercase letters randomly chosen
	string generateLowerCase(int length){
	
		string returnString;
		char temp;
		RNG rando;
		
		std::ostringstream oss;
		
		
		for(int i = 0; i<length; i++){
			usleep(rando.fastRandNum(1000, 1001)); //Must be at or above 1000 to operate correctly in this implementation
			temp = (char) rando.fastRandNum(97,122); //Using ASCII characters to generate
			oss << temp;
			
		}
		returnString = oss.str();
		return returnString;
	}
	
	//generates a string of distinct length with only uppercase letters randomly chosen
	string generateUpperCase(int length){
		
		string returnString;
		char temp;
		RNG rando;
		
		std::ostringstream oss;
		
		for(int i = 0; i<length; i++){
			usleep(rando.fastRandNum(1000, 1001)); //Must be at or above 1000 to operate correctly in this implementation
			temp = (char) rando.fastRandNum(65,90); //Using ASCII characters to generate
			oss << temp; //using ostringstream to build string
		}
		returnString = oss.str(); //return using oss to produce string
		return returnString;
	}
	
	string simpleSpace(){
		RNG rando;
		int temp;
		std::ostringstream oss;
		temp = 32;
		
		oss << (char) temp;
		return oss.str();
	}
	
	public:
	//Fixed length with mix of upper and lower case characters
	string randString(int length){
		
		if(length<1){
			return NULL;
		}
		RNG rando;
		string returnString;
		std::ostringstream oss;
		
		for(int i = 0; i<length; i++){
			
			if(rando.fastRandNum(0,1)){ //select between genUpper and genLower to produce 1 character
				oss << generateLowerCase(1);
			}
			else{
				oss << generateUpperCase(1);
			}
		}
		returnString = oss.str();
		return returnString;
	}
	
	//For certain length but randomized characters
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
	
	//For string of length within range, composed of randomized characters
	string randString(int minLength, int maxLength, int caseFlag){
		
		//Handling of base cases
		if(minLength > maxLength || minLength < 1){
			return NULL;
		}
		else if(minLength == maxLength){
			return randString(minLength, caseFlag);
		}
		
		//Randomize length based on min and max
		RNG rando;
		int length = rando.fastRandNum(minLength, maxLength);
		
		switch(caseFlag){
			case 1: return randString(length); break; //Gives mix of upper and lower case
			case 2: return generateLowerCase(length); break;
			case 3: return generateUpperCase(length); break;
			default: return NULL; break; //error handling for invalid caseFlags
		}
		
	}
	
	//Generates a randomized string which may be seperated by single spaces
	string randSpacedString(int length){
		if(length<1){
			return NULL;
		}
		RNG rando;
		string returnString;
		int temp;
		bool spaceFlag = false; //Used to create monospacing
		std::ostringstream oss;
		
		
		for(int i = 0; i<length;i++){
			temp = rando.fastRandNum(0, 4); //For occurence rate of spaces, increase space rate by decreasing second number
			if(temp == 0 && spaceFlag){
				oss << simpleSpace();
				spaceFlag = false;
			}
			else{
				oss << randString(1);
				spaceFlag = true; //Set flag to enable spaces 
			}
		}
		returnString = oss.str(); //Create string from stream
		return returnString;
	}
	
	string randSentence(int minLength, int maxLength){
		return NULL;
	}
};



int main(){ //Used for simple test cases
	
	randStringGen rando;
	
	string printingString = (rando.randSpacedString(50));
	cout << printingString << endl;
	return 0;
}