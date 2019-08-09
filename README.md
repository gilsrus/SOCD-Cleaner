#SOCD Cleaner (Mode Changer VER)

_________________________________


### PinNo (for Arduino pro micro)
D2 - UP button IN
D3 - DOWN button IN
D4 - LEFT button IN
D5 - RIGHT button IN

D6 - UP OUT
D7 - DOWN OUT
D8 - LEFT OUT
D9 - RIGHT OUT

GND - Ground PIN

D10(jump to gnd) - Mode 1 (SOCD cleaner MODE)
D14(jump to gnd) - Mode 2 (LAST command MODE)
not Jump anything or (D10Jump & D14Jump) - Mode 0 (RAWoutput MODE)
_______________________________

### Mode 

##### - Mode 0 (RAW output Mode)
not Jump anything or (D10Jump & D14Jump)

Up + Down -> Up + DOWN
LEFT + RIGHT -> LEFT + RIGHT

##### - MOde 1 (SOCD cleaner MODE)

Connect D10 pin to Gnd pin

Up + Down -> UP
LEFT + RIGHT -> Neutral (no output)

##### - MOde 2 (LAST Command MODE)

Connect D14 pin to Gnd pin

Last command OUTPUT

Up + DOWN -> DOWN
DOWN + UP -> UP
LEFT + RIGHT -> RIGHT
RIGHT + LEFT -> LEFT

____________________________________________



