# Intro

Replacement of a PIC16C62B/72A microcontroller for a micro AVR (Arduino), on an Amazona 189D3632G006 electronic card. GE Easy washing machine, model TL10003PB0. The code provides full functionality on the washing machine with great similarity to the operation carried out with the original microcontroller.

# Contains

* Arduino microcontroller source code (sketch).

* Electronic information of the Amazon card.

* Test schematic for Proteus Design Suite.

# Requirements

Make the corresponding connections of the Arduino on the Amazona card, so that it directs the operations on the card.

# Recent changes

Updated Easy_GE_Mabe.ino version from 1.0.0 to 1.1.0.
Added Easy_GE_Mabe_debug.ino to debug from virtual terminal in Proteus.
Work bug when it started being full
Lid led turns off with precise time
