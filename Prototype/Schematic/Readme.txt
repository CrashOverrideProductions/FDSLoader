Prototype Schematic for FDS SD Loader
Eagle Schematic File and PDF included


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
