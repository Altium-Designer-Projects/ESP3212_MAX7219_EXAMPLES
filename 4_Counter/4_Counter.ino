#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW 

#define MAX_DEVICES 8
#define CS_PIN      27
#define CLK_PIN     26
#define DATA_PIN    25

MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES); // Software spi

char displayBuffer[12] = " ";

word counter = 0;
byte i = 0;

void setup(){
 
 P.begin();
 P.setIntensity(6); 

}

void loop(){
  
 if(P.displayAnimate()){
   // sprintf(displayBuffer, "%s", "29.08.2019" ); 
    
   //sprintf(displayBuffer, "%d", counter );   
    
   sprintf(displayBuffer, "%04d", counter );  
   
   P.displayText( displayBuffer , PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);

   counter++;
   delay(1000);

 }

}
