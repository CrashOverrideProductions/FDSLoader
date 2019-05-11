/*    Project:          Famicom Disk System Drive Emulator
 *    Author:           Justin Bland - www.crashchips.com.au
 *    Date:             10/05/2019
 *    Status:           In Development
 *    
 *    Licence:          Creative Commons 
 *                      Attribution-NonCommercial-ShareAlike 3.0 Australia 
 *                      (CC BY-NC-SA 3.0 AU) 
 *    
 *    Arduino:          Arduno Mega 2560
 *    SD Shield:        WeeMo D1 (i think, Will Change)
 *    LCD Shield:       None Yet
 *    
 *    Purpose:          This project is to provide a method of reliably playing legally Archived
 *                      (Backup)/ HomeBrew Famicom Disk System Games without relying on the FDS Drive
 *                      or Disks for Game Play, This project  is not intended for use with illegal
 *                      Game Roms sourced from the internet, etc.
 *                      Please only use Game Roms from Games that you own / have the rights.
 */

#include <SPI.h>
#include <SD.h>

// Define Variables for the SD Card
    Sd2Card card;
    SdVolume volume;
    SdFile root;
    const int chipSelect = 53;


// Define Arduino to RAM Adapter Pinout Variables
    #define PIN_Scan_Media          31
    #define PIN_Write_Data          18 // Serial_1 TX
    #define PIN_Motor_On            41
    #define PIN_Writeable_Media     35
    #define PIN_Read_Data           19 // Serial_1 RX
    #define PIN_Media_Set           39
    #define PIN_Ready               37
    #define PIN_Stop_Motor          33
    #define PIN_Write_Gate          40
    #define PIN_Rate                44  // NOT SET YET
    #define PIN_Data                45  // NOT SET YET


// Define Arduino to RAM Adapter Pin Settings
  // Set Pins
    #define SET_Ready()             (pinMode(PIN_Ready,            HIGH))
    #define SET_Media_Set()         (pinMode(PIN_Media_Set,        HIGH))
    #define SET_Writeable_Media()   (pinMode(PIN_Writeable_Media,  HIGH))
    #define SET_Motor_On()          (pinMode(PIN_Motor_On,         HIGH))

  // Un-Set Pins
    #define CLEAR_Ready()           (pinMode(PIN_Ready,            LOW))
    #define CLEAR_Media_Set()       (pinMode(PIN_Media_Set,        LOW))
    #define CLEAR_Writeable_Media() (pinMode(PIN_Writeable_Media,  LOW))
    #define CLEAR_Motor_On()        (pinMode(PIN_Motor_On,         LOW))

  // Get RAM Adapter Status
    #define IS_Scan_Media()         (digitalRead(PIN_Scan_Media) == false)
    #define IS_Stop_Motor()         (digitalRead(PIN_Stop_Motor) == false)
    #define IS_Dont_Stop_Motor()    (digitalRead(PIN_Stop_Motor) == true)
    #define IS_Read_Disk_Mode()     (digitalRead(PIN_Write_Gate)== true)

// Define Serial Transfer Rates
  // Serial Monitoring Port (Serial 0)
    #define Serial_0_Rate          115200

  // Serial Data Port (Serial 1)
    #define Serial_1_Rate           100000
    #define FDS_KHZ                 (FPBA_HZ / 2 / Serial_1_Rate) // More Research On this One



void setup() {

// Start Serial Monitoring Port
  Serial.begin(Serial_0_Rate);

// Start Serial Game Data Port
  Serial1.begin(96400);

// Initalize SD Card
  InitSDCard();

}


void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("");
  Game_ReadyToLoad();
  delay(4000);
  Game_Load_Disk();
  delay(6000);
}
