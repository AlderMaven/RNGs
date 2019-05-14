//Created by Brandon Barnes
//Simple class to contain RNG functions
#include<ctime>
#include<stdlib.h>

class RNG{
    int srandNum(int min, int max){
        if(min < 0|| max<0 || min>max){ //Error cases
            return -1;
        }
        if(min == max){ //Quick return
            return min;
        }
    
        int temp = max+1-min; //is equivalent to difference between min and max + 1
    
        srand(time(NULL)); //seeds rand, necessary to have differences between seperate executions

        return (rand()%temp)+min; //will get [0, temp-1] from modulo, therefore returns [min, max] since temp = difference max and min+1
    
	}
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
	    //min as floor is from adding min and a possible modulus of 0
	    //max as ceiling is from min+max difference of max-min
	    //Since that difference is > 0, this gives a range that can be returned reliably in consistant time
	
	    return result;
    }	
};