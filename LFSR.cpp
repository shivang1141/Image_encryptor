#include <iostream>
#include <string>
#include <cmath>
#include "LFSR.hpp"

LFSR::LFSR(std::string seed, int t) {
  _seed = seed;
  tap = t;
}

LFSR::~LFSR() {
}

int LFSR::step() {
  int len = _seed.length();
  int bit = _seed[0] - '0';
  int T = _seed[len - tap - 1] - '0';
  if (bit == T)
    bit = 0;
  else
    bit = 1;
  for (int i = 0; i < len - 1; i++)
    _seed[i] = _seed[i + 1];
    _seed[len - 1] = bit + 48;

  return bit;
}

int LFSR::generate(int k) {
  int num = 0;

  for (int loop = k; loop > 0; loop--) {
    int b = step();
    if (b == 1)
      num = num + pow(2, loop - 1);
  }
  return num;
}

std::ostream& operator<< (std::ostream &out, LFSR &lfsr) {
  out << lfsr._seed;
  return out;
}
