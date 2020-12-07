*
pin config:
stop motor    = f0 (input)  (active low)
media set     = f1 (output) (active low)
batt/motor on = f2 (output)
ready         = f3 (output) (active low)
read data     = f4 (output) (also tied to b5)
rw media      = f5 (output) (active low)
write         = f6 (input)
scan media    = f7 (input)  (active low)
write data    = d5 (input)  (active low)
*/

/*
Rate is the signal that represents the intervals at which data (bits) are 
transfered. A single data bit is transfered on every 0 to 1 (_-) transition 
of this signal. The RAM adaptor expects a transfer rate of 96.4kHz, although 
the tolerance it has for this rate is ñ10%. This tolerance is neccessary 
since, the disk drive can NOT turn the disk at a constant speed. Even though 
it may seem constant, there is a small varying degree in rotation speed, due 
to it's physical architecture.
16000000 / 96400 = 165.97510373443983402489626556017
16000000 / 166 = 96385.542168674698795180722891566
166 is close enough
166 / 2 = 83 for clock up -> down transitioning
*/*
pin config:
stop motor    = f0 (input)  (active low)
media set     = f1 (output) (active low)
batt/motor on = f2 (output)
ready         = f3 (output) (active low)
read data     = f4 (output) (also tied to b5)
rw media      = f5 (output) (active low)
write         = f6 (input)
scan media    = f7 (input)  (active low)
write data    = d5 (input)  (active low)
*/

/*
Rate is the signal that represents the intervals at which data (bits) are 
transfered. A single data bit is transfered on every 0 to 1 (_-) transition 
of this signal. The RAM adaptor expects a transfer rate of 96.4kHz, although 
the tolerance it has for this rate is ñ10%. This tolerance is neccessary 
since, the disk drive can NOT turn the disk at a constant speed. Even though 
it may seem constant, there is a small varying degree in rotation speed, due 
to it's physical architecture.
16000000 / 96400 = 165.97510373443983402489626556017
16000000 / 166 = 96385.542168674698795180722891566
166 is close enough
166 / 2 = 83 for clock up -> down transitioning
*/
