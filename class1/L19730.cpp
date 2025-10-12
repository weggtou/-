#include <iostream>
#include <vector>
#include <bits/debugger.h>

using namespace std;
#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) {return *this;}
  void sp(const string& str = "") {}
} dout;
#define debug(x)

#endif
