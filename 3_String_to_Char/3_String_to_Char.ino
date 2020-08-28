#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW 

#define MAX_DEVICES 8
#define CS_PIN      27
#define CLK_PIN     26
#define DATA_PIN    25

MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES); // Software spi

char displayBuffer[12];

String city_str = "istanbul";  // string data

char city_chr[] = "istanbul";  // array char data

void setup(){
	
 P.begin();
 
}

void loop(){
  
 if(P.displayAnimate()){
	 
   city_str.toCharArray(displayBuffer, city_str.length() + 1 );
   P.displayText(displayBuffer, PA_CENTER, 25, 100, PA_PRINT, PA_NO_EFFECT);

 }
  
}
