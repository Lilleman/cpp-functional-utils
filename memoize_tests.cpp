/**
 * Copyright 2017 Christoffer Ackelman
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <iostream>
#include <limits>
#include <map>
#include <vector>
#include "assert.h"
#include "math.h"
#include "stdlib.h"

#include "memoize.h"

using namespace std;
using namespace Memoize;

////////////////////
// Helpers
////////////////////
class MyClass
{
  public:
    bool isBiggerThan10(int a, int b) {
      if (a < 10) return false;
      if (b < 10) return false;
      return true;
    }
};

bool isBiggerThan10(int a, int b)
{
  if (a < 10) return false;
  if (b < 10) return false;
  return true;
}

////////////////////
// Tests
////////////////////

void testMemoize()
{
  binary_memoizer<bool, int, int> memoized = memoize(&isBiggerThan10);
  memoized(1, 2);
  memoized(2, 3);
  memoized(1, 2);
}

void testMemoizeMemberFunc()
{
  MyClass c;
  ternary_memoizer<bool, MyClass*, int, int> memoized = memoize(&MyClass::isBiggerThan10);
  memoized(&c, 1, 2);
  memoized(&c, 2, 3);
  memoized(&c, 1, 2);
}

int main()
{
  testMemoize();
  //testMemoizeMemberFunc();
}
