//Created by Brandon Barnes
//Simple RNG based on time()
//Will return numbers in sequential order since rand is not being used
//Therefore this is easier to manipulate by an end user if they can determine their current count

#include <ctime>

using namespace std;

int randomNum(int min, int max){
	if(min < 0|| max<0 || min>max){ //Error cases
        return -1;
    }
    if(min == max){ //Quick return
        return min;
    }
	
    int result;
    int temp = max+1-min;
    result = (time(NULL)%(temp))+min; //Ensures [min,max]
	/*
	min as floor is from adding min and a possible modulus of 0
	max as ceiling is from min+max difference of max-min
	Since that difference is > 0, this gives a range that can be returned reliably in consistant time
	*/
    return result;
}	