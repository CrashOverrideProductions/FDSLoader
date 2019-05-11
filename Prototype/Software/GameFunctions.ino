void Game_ReadyToLoad(){
// Configure Pins
    pinMode(PIN_Write_Gate,       INPUT);
    pinMode(PIN_Scan_Media,       INPUT);
    pinMode(PIN_Write_Data,       INPUT);
    pinMode(PIN_Stop_Motor,       INPUT);

    pinMode(PIN_Motor_On,         OUTPUT);
    pinMode(PIN_Writeable_Media,  OUTPUT);
    pinMode(PIN_Read_Data,        OUTPUT);
    pinMode(PIN_Ready,            OUTPUT);
    pinMode(PIN_Media_Set,        OUTPUT);

    pinMode(PIN_Rate,             OUTPUT);
    pinMode(PIN_Data,             OUTPUT);

// Clear Previous Pin Configurations
    CLEAR_Writeable_Media();
    CLEAR_Ready();
    CLEAR_Media_Set();
    CLEAR_Motor_On();
  }

void Game_Load_Disk(){
  // Inserting Disk
    Serial.println("Inserting Disk");
    SET_Media_Set();

  // Check if RAM Adapter Wants Motor to Stop
    if (IS_Stop_Motor())  {
      Serial.println("RAM Adapter -> Stopping Drive Motor");
      CLEAR_Motor_On();
      return;
      }

  // Check if RAM Adapter Wants to Scan Disk
    if (IS_Scan_Media()){
      if (IS_Dont_Stop_Motor())
        Serial.println("RAM Adapter -> Wants Drive Motor to Run + Send Data");
      
      // Turn On Drive Motor
        SET_Motor_On();

      // Delay for 14354 Bit Transfers (0.15 Seconds)  
        delay(160);

      // Tell RAM Adapter "Data is Comming"
        SET_Ready();

        Game_Begin_Data_Transfer();
        delay(150);
      // Finish Transfer
        CLEAR_Ready();
        Serial.println("Finished Game Transfer");
        return;
      }  
    }

void Game_Begin_Data_Transfer(){
  Serial.println("Begin Data Transfer SD -> RAM Adapter");

  // Transfer Game from SD to RAM Adapter
      ReadSD();
    
 
  }

  void ReadSD() {
  int index = 0;
  Serial.println("Loading Metroid");
  File dataFile = SD.open("MET.FDS");
  //---------
  if (dataFile) {

    // read from the file until there's nothing else in it:
    while (dataFile.available()) {
      Serial1.write(dataFile.read());
    }
    // close the file:
    dataFile.close();
    Serial.println("Metroid Sent");
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error Opening Disk Image");
  }
}
