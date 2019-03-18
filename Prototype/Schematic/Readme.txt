Prototype Schematic for FDS SD Loader
Eagle Schematic File and PDF included

Connects to P2 on the Ram Adapter PCB
    Header Part Number:    B12B-PH-KS (Digikey)
    Plug Part Number:      PHR-12 (Digikey)
    * Closest Match - Ram Adapter end may need locking tabs cut off from plug


17/03/19:
  Schematic is almost a copy of the QDC ATMega-164 schematic which appears to be based upon the FMD-POWER-05 PCB

  FDSLoadr does not use any inverters/gates, at this point im assuming that the program preformed any logic gate functions 
  and did not require the use of them, in this prototype the plan is to use logic gates to reduce processor load
  
      FDS Tech Brief Note - Data Transfer Protocol:
      ==============================================================================================================
      2 pieces of information (signals) must be sent: 
      
      - a signal that represents the rate at which the data is being sent 
      - the actual data 
      
      the FDS disk drive is sending it's data out via serial connection (1 wire, meaning 1 bit at a time).
      Data prerecorded on FDS disks have already had the 2 aformentioned signals "combined" using an XOR algorithm
      ==============================================================================================================

17/03/19: Continued
    Pin Signaling Basic Requirements-
       Pin           Name                       Function
       ----------------------------------------------------------------------------------------------------------------
        1   -   Ground:                 Connect to Arduino Ground
        2   -   Motor_Power:            Not Connected        
        3   -   Write_Data:             Serial Data Write to Disk
                                           - Serial Data                                           
        4   -   Read_Data:              Serial Data Read from Disk
                                           - Serial Data                                           
        5   -   /Write_Gate:            Unsure ATM
        6   -   /Scan_Media:            Instructs Storage Media to prepare for transfer
                                           - Pin Low = Prepare for Transfer | Pin High = No Transfer
        7   -   /Motor_Stop:            Stops Data Transfer
                                           - Pin Low = Stop Drive Motor | Pin High = Normal Position
        8   -   /Writable_Media:        Is the Media Writable?
                                           - Pin Low = Writable | Pin High = Read Only
        9   -   /Ready:                 Informs RAM Adapter that Media is Ready, Must be active during transfers
                                           - Pin Low = Ready | Pin High = Not Ready
        10  -   /Media_Set:             Sets the Media Present State
                                           - Pin Low = Media Present | Pin High = Media Not Present
        11  -   Motor_On/Batt_Good:     Connect to VCC via 4k7 Resistor
                                           - Pin Low = No Power to Disk Drive | Pin High = Disk Drive Power Good
        12  -   VCC:                    Connect to Arduino +5v
        
        
    Pin Signaling Ordering and Timing-
        Default Position - No Disc
               /Media_Set                    I      Set High
               /Writable_Media               I      Set High
               /Scan_Media                   O      Set High
               /Stop_Motor                   O      Set Low
               Motor_On/Batt_Good            I      Set High (Tie directly to VCC = Alway Good) 
               /Ready                        I      Set High
               /Write                        I      Set Low 
               /Scan_Media                   O      Set Low
               /Stop Motor                   O      Set High
               
        Load Data into RAM Adapter
               /Media_Set                    I      Set Low (Remains Set Throughout Transfer & for a short time after)
               /Writable_Media               I      Set Low (immediatley after /Media_Set (Can be tied to /Media_Set)
               /Scan_Media                   O      Set Low
               /Stop_Motor                   O      Set High
               Motor_On/Batt_Good            I      Set High (Tie directly to VCC = Alway Good) 
               /Ready                        I      Set Low ( Wait 0.15sec after previous / Remains active during transfer)
               /Write                        I      Set High (Sets data transfer direction to read)
               /Scan_Media                   O      Set High
                    OR                                  Terminates Data Transfer
               /Stop Motor                   O      Set Low
        
        Write Save Games to File
               /Media_Set                    I      Set Low (Remains Set Throughout Transfer & for a short time after)
               /Writable_Media               I      Set Low (immediatley after /Media_Set (Can be tied to /Media_Set)
               /Scan_Media                   O      Set ?
               /Stop_Motor                   O      Set ?
               Motor_On/Batt_Good            I      Set High (Tie directly to VCC = Alway Good) 
               /Ready                        I      Set Low ( Wait 0.15sec after previous / Remains active during transfer)
               /Write                        I      Set Low (Sets data transfer direction to read)
               /Scan_Media                   O      Set High
                    OR                                  Terminates Data Transfer
               /Stop Motor                   O      Set Low
               
      **** Not 100% Sure on the /Write, /Read, /Read_Gate setup yet......
