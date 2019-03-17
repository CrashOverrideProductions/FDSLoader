This file is for verifiying Famicom Disk System Rom files (.fds) are valid, 
Not for sharing Rom Files  


17/03/19
  at this point the plan is to if possible have an application to verifiy and fix rom files instead of utilising micro processor
  rescources to do this on the fly
  
  
  Disk Header File:
    All Disk Files (Roms) need to have a 16 byte header at the start of the file, most methods of backing up Game Disks or 
    Roms sourced from the internet (We do not condone piracy) have this header missing.
    
    First 64 Bytes of Valid File (Metroid (Rev1))
      46 44 53 1A 02 00 00 00 00 00 00 00 00 00 00 00   <--- This is the Header  
      01 2A 4E 49 4E 54 45 4E 44 4F 2D 48 56 43 2A 01 
      4D 45 54 20 01 00 00 00 00 0F FF FF FF FF FF 61 
      08 12 49 61 00 00 02 00 13 00 56 00 61 08 12 FF
      
      
