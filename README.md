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
