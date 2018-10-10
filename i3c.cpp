#include "pi2c.h"
#include <wiringPi.h>
#include <iostream>
#include <curses.h>
#include <stdio.h>

int main(){
    wiringPiSetup();
    Pi2c arduino(7); //Create a new object "arduino" using address "0x07"
    char receive[16];
    int temp[32000];
    int dato[1];
    unsigned int cont = 0;
    int contador[32000];
    int i = 0;
    FILE *datos;

    datos = fopen("temp.txt","w");
    
    
while(1){   
 
    //Receive from the Arduino and put the contents into the "receive" char array
    arduino.i2cRead(receive,16);
    dato[0] = receive[0];
    temp[cont] = dato[0];
    contador[cont] = cont;
    std::cout << "temp: " << dato[0] << std::endl;
    printf("%d - ", cont);
     //Send an 16 bit integer
    arduino.i2cWriteArduinoInt(4356); 
       delay(10);
	cont++;
    if(cont == 32000){
    for(i=0;i<32000;i++){
	fprintf(datos,"%d - %d\n",contador[i],temp[i]);
		     }
	fclose(datos);
	printf("fin del programa");
	return 1;
		  }
}
    return 0;
}
