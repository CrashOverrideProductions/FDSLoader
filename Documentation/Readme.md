## Famicom Disk System Breakdown
### **Description**: Breakdown of the Communication between the FDS and Ram Adapter <img alt="" align="right" src="https://img.shields.io/badge/Status-Research%20Phase-informational?style=flat&logoColor=white&color=73398D" />


### To Do List
- [x] Define Cable Pinout
- [x] List Pin Logic States
- [ ] Define Rom Transfer Procedure

- [ ] List Items Here
- [ ] List Items Here
- [ ] List Items Here

## Cable Pinout
 --------==---------   <br/>
| 1  3  5  7  9  11 |  <br/>
| 2  4  6  8 10  12 | 


 Ram Adapter Cable View
 
 | Pin | I/O |        Signal        | Logic State|                                  Signal Description                                  																	                                      |
 |-----|-----|----------------------|------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------|
 |  1  |  O  | /WRITE               | LOGIC LOW  | While active, this signal indicated data on the "Write Data" pin is written to the Disk				                                  														|
 |  2  |  O  | +5V VCC              | +5V VCC    | +VE Power Supply                                                                   																		                                      |
 |  3  |  O  | /SCAN_MEDIA          | LOGIC LOW  | While inactive, this signal instructs the media pointer to (and stay) at the beginning of the media, When active media pointer is advanced at a constant rate|
 |  4  |  O  | GND                  | GND		     | -VE Power Supply																																		                                                                      		|
 |  5  |  O  | WRITE DATA           | LOGIC HIGH | Serial Data Written to the Disk, if /Write Low																												                                                        |
 |  6  |  I  | MOTOR_ON/BATT_GOOD   | LOGIC HIGH | When HIGH (From FDS) Shows FDS Motor/Batteries Good																										                                                    	|
 |  7  |  I  | /WRITEABLE_MEDIA     | LOGIC LOW  | While active, indicates to the Ram Adapter that the media is writable																					                                            	|
 |  8  |  I  | MOTOR_POWER          | UN-USED    | UN-USED																																					                                                                          	|
 |  9  |  I  | READ_DATA            | LOGIC LOW  | When "/Scan Media" is active data that is progressivly read off the Disk (via the Media Pointer) is expected to appear here					                				|
 | 10  |  I  | /MEDIA_SET           | LOGIC LOW  | When active, this signal indicates the presence of valid storage media																						                                            |
 | 11  |  I  | /READY               | LOGIC LOW  | The Falling Edge of this signal indicates to the Ram Adapter the Disk Drive has acknowledged the "/Scan Media" signal and the Disk Head is at the beginning of the track. While the signal remains active, this indicates that the Disk Head is advancing across the Disk surface, this signal goes inactive if the head advanced to the end of the disk ir the "/Scan Media" signal goes inactive| 
 | 12  |  O  | /STOP_MOTOR          | LOGIC LOW  | The Falling Edge of this signal instructs the drive to stot the current scan of the disk																		                                  |


## Cable Pin Logic States





<!-- Licencing Always at the Bottom -->
## Licencing <img alt="" align="right" src="https://img.shields.io/badge/Licence-CC--BY--NC--SA--4.0-informational?style=flat&logo=Creative%20Commons&logoColor=white&color=EF9421" />

**Creative Commons: Attribution - NonCommercial - ShareAlike 4.0 International (CC BY-NC-SA 4.0)**


**You are free to:**

&nbsp;&nbsp;&nbsp;&nbsp; **Share** — copy and redistribute the material in any medium or format

&nbsp;&nbsp;&nbsp;&nbsp; **Adapt** — remix, transform, and build upon the material 


**Under the following terms:**

&nbsp;&nbsp;&nbsp;&nbsp; **Attribution** — You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.

&nbsp;&nbsp;&nbsp;&nbsp; **NonCommercial** — You may not use the material for commercial purposes.

&nbsp;&nbsp;&nbsp;&nbsp; **ShareAlike** — If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.
