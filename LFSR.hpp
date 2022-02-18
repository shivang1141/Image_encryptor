#include <iostream>

class LFSR {
 public:
  LFSR(std::string seed, int tap);
  // constructor to create LFSR with the given initial seed and tap
  ~LFSR();
  int step();
  // simulate one step and return the new bit as 0 or 1
  int generate(int k);
  // simulate k steps and return k-bit integer

  friend std::ostream& operator<< (std::ostream &out, LFSR &lfsr);

 private:
  std::string _seed;
  int tap;
};

