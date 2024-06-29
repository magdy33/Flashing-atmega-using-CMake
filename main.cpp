#define F_CPU 1000000UL 

#include"LED.hpp"





int main(){

    LED ledblink;
    while(1){
        ledblink.LED_TOGGLE();
    }
    return 0;
}



