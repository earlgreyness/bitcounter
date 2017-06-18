# Description

The program calculates the amount of enabled bits in the input file, regarding it as raw binary data.

# Installation

    make counter

# Usage

    ./counter sample.bin

Output info on each byte:

    ./counter sample.bin --verbose

Use caching (no calculation with bitshifts):

    ./counter sample.bin --cached

You can combine both flags but the first parameter must always be the filename:

    ./counter sample.bin --cached --verbose

To compare performance of the two methods (cache/calculation), use large input files and don't use `--verbose`.


# Example

Command:

    ./counter sample.bin --cached --verbose

Output:

    01110001 : 4
    01110111 : 6
    01100101 : 4
    01110010 : 4
    01110100 : 4
    01111001 : 5
    00110001 : 3
    00001010 : 2
    Time elapsed: 6.7e-05 sec
    File size: 8B
    Bits (enabled/total): 32/64
