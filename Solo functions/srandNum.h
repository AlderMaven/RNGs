//Created by Brandon Barnes
//Version of RNG utilizing rand and srand, little less predictable for user
//Result will increase monotonically until loop around
//However the spacing between numbers on repeated calls is not directly consistent to system time 

#include<iostream>
#include<ctime>
#include<stdlib.h>

using namespace std;

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