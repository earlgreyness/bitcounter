#include <iostream>
#include <fstream>
#include <bitset>
#include <cassert>
#include <ctime>
#include "string.h"

const int BYTE = 8;  // Amount of bits in a byte.

int* getCache();

int countBits(int byte, bool useCache, int *cache) {
    if (useCache) {
        return cache[byte];
    }
    int count = 0;
    for (int i = 0; i < BYTE; i++) {
        count += (byte >> i) & 1;
    }
    return count;
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cout << "Please provide source file name" << std::endl;
        return 1;
    }

    bool useCache = false;
    bool verbose = false;

    for (int i = 2; i < argc; i++) {
        if (!strcmp(argv[i], "--cached")) {
            useCache = true;
        }
        if (!strcmp(argv[i], "--verbose")) {
            verbose = true;
        }
    }

    int* cache = getCache();

    std::ifstream source;
    source.open(argv[1], std::ios::binary);

    int total = 0;
    int enabled = 0;

    clock_t begin = std::clock();

    int byte = source.get();

    while (source.good()) {
        int bits = countBits(byte, useCache, cache);
        assert(bits <= BYTE);
        if (verbose) {
            std::bitset<BYTE> bset = std::bitset<BYTE>(byte);
            std::cout << bset.to_string() << " : "<< bits << std::endl;
        }
        enabled += bits;
        total += BYTE;

        byte = source.get();
    }

    double elapsed = double(std::clock() - begin) / CLOCKS_PER_SEC;

    std::cout << "Time elapsed: " << elapsed << " sec" << std::endl;
    std::cout << "File size: " << total / BYTE << "B" << std::endl;
    std::cout << "Bits (enabled/total): " << enabled << "/" << total << std::endl;

    delete cache;
    source.close();
    return 0;
}

int* getCache() {
    int *cache = new int[256];
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 1;
    cache[3] = 2;
    cache[4] = 1;
    cache[5] = 2;
    cache[6] = 2;
    cache[7] = 3;
    cache[8] = 1;
    cache[9] = 2;
    cache[10] = 2;
    cache[11] = 3;
    cache[12] = 2;
    cache[13] = 3;
    cache[14] = 3;
    cache[15] = 4;
    cache[16] = 1;
    cache[17] = 2;
    cache[18] = 2;
    cache[19] = 3;
    cache[20] = 2;
    cache[21] = 3;
    cache[22] = 3;
    cache[23] = 4;
    cache[24] = 2;
    cache[25] = 3;
    cache[26] = 3;
    cache[27] = 4;
    cache[28] = 3;
    cache[29] = 4;
    cache[30] = 4;
    cache[31] = 5;
    cache[32] = 1;
    cache[33] = 2;
    cache[34] = 2;
    cache[35] = 3;
    cache[36] = 2;
    cache[37] = 3;
    cache[38] = 3;
    cache[39] = 4;
    cache[40] = 2;
    cache[41] = 3;
    cache[42] = 3;
    cache[43] = 4;
    cache[44] = 3;
    cache[45] = 4;
    cache[46] = 4;
    cache[47] = 5;
    cache[48] = 2;
    cache[49] = 3;
    cache[50] = 3;
    cache[51] = 4;
    cache[52] = 3;
    cache[53] = 4;
    cache[54] = 4;
    cache[55] = 5;
    cache[56] = 3;
    cache[57] = 4;
    cache[58] = 4;
    cache[59] = 5;
    cache[60] = 4;
    cache[61] = 5;
    cache[62] = 5;
    cache[63] = 6;
    cache[64] = 1;
    cache[65] = 2;
    cache[66] = 2;
    cache[67] = 3;
    cache[68] = 2;
    cache[69] = 3;
    cache[70] = 3;
    cache[71] = 4;
    cache[72] = 2;
    cache[73] = 3;
    cache[74] = 3;
    cache[75] = 4;
    cache[76] = 3;
    cache[77] = 4;
    cache[78] = 4;
    cache[79] = 5;
    cache[80] = 2;
    cache[81] = 3;
    cache[82] = 3;
    cache[83] = 4;
    cache[84] = 3;
    cache[85] = 4;
    cache[86] = 4;
    cache[87] = 5;
    cache[88] = 3;
    cache[89] = 4;
    cache[90] = 4;
    cache[91] = 5;
    cache[92] = 4;
    cache[93] = 5;
    cache[94] = 5;
    cache[95] = 6;
    cache[96] = 2;
    cache[97] = 3;
    cache[98] = 3;
    cache[99] = 4;
    cache[100] = 3;
    cache[101] = 4;
    cache[102] = 4;
    cache[103] = 5;
    cache[104] = 3;
    cache[105] = 4;
    cache[106] = 4;
    cache[107] = 5;
    cache[108] = 4;
    cache[109] = 5;
    cache[110] = 5;
    cache[111] = 6;
    cache[112] = 3;
    cache[113] = 4;
    cache[114] = 4;
    cache[115] = 5;
    cache[116] = 4;
    cache[117] = 5;
    cache[118] = 5;
    cache[119] = 6;
    cache[120] = 4;
    cache[121] = 5;
    cache[122] = 5;
    cache[123] = 6;
    cache[124] = 5;
    cache[125] = 6;
    cache[126] = 6;
    cache[127] = 7;
    cache[128] = 1;
    cache[129] = 2;
    cache[130] = 2;
    cache[131] = 3;
    cache[132] = 2;
    cache[133] = 3;
    cache[134] = 3;
    cache[135] = 4;
    cache[136] = 2;
    cache[137] = 3;
    cache[138] = 3;
    cache[139] = 4;
    cache[140] = 3;
    cache[141] = 4;
    cache[142] = 4;
    cache[143] = 5;
    cache[144] = 2;
    cache[145] = 3;
    cache[146] = 3;
    cache[147] = 4;
    cache[148] = 3;
    cache[149] = 4;
    cache[150] = 4;
    cache[151] = 5;
    cache[152] = 3;
    cache[153] = 4;
    cache[154] = 4;
    cache[155] = 5;
    cache[156] = 4;
    cache[157] = 5;
    cache[158] = 5;
    cache[159] = 6;
    cache[160] = 2;
    cache[161] = 3;
    cache[162] = 3;
    cache[163] = 4;
    cache[164] = 3;
    cache[165] = 4;
    cache[166] = 4;
    cache[167] = 5;
    cache[168] = 3;
    cache[169] = 4;
    cache[170] = 4;
    cache[171] = 5;
    cache[172] = 4;
    cache[173] = 5;
    cache[174] = 5;
    cache[175] = 6;
    cache[176] = 3;
    cache[177] = 4;
    cache[178] = 4;
    cache[179] = 5;
    cache[180] = 4;
    cache[181] = 5;
    cache[182] = 5;
    cache[183] = 6;
    cache[184] = 4;
    cache[185] = 5;
    cache[186] = 5;
    cache[187] = 6;
    cache[188] = 5;
    cache[189] = 6;
    cache[190] = 6;
    cache[191] = 7;
    cache[192] = 2;
    cache[193] = 3;
    cache[194] = 3;
    cache[195] = 4;
    cache[196] = 3;
    cache[197] = 4;
    cache[198] = 4;
    cache[199] = 5;
    cache[200] = 3;
    cache[201] = 4;
    cache[202] = 4;
    cache[203] = 5;
    cache[204] = 4;
    cache[205] = 5;
    cache[206] = 5;
    cache[207] = 6;
    cache[208] = 3;
    cache[209] = 4;
    cache[210] = 4;
    cache[211] = 5;
    cache[212] = 4;
    cache[213] = 5;
    cache[214] = 5;
    cache[215] = 6;
    cache[216] = 4;
    cache[217] = 5;
    cache[218] = 5;
    cache[219] = 6;
    cache[220] = 5;
    cache[221] = 6;
    cache[222] = 6;
    cache[223] = 7;
    cache[224] = 3;
    cache[225] = 4;
    cache[226] = 4;
    cache[227] = 5;
    cache[228] = 4;
    cache[229] = 5;
    cache[230] = 5;
    cache[231] = 6;
    cache[232] = 4;
    cache[233] = 5;
    cache[234] = 5;
    cache[235] = 6;
    cache[236] = 5;
    cache[237] = 6;
    cache[238] = 6;
    cache[239] = 7;
    cache[240] = 4;
    cache[241] = 5;
    cache[242] = 5;
    cache[243] = 6;
    cache[244] = 5;
    cache[245] = 6;
    cache[246] = 6;
    cache[247] = 7;
    cache[248] = 5;
    cache[249] = 6;
    cache[250] = 6;
    cache[251] = 7;
    cache[252] = 6;
    cache[253] = 7;
    cache[254] = 7;
    cache[255] = 8;
    return cache;
}
