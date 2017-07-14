/**
 * Copyright 2017 Christoffer Ackelman
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "Functional.h"
#include <iostream>
#include <limits>
#include <map>
#include <vector>
#include "assert.h"
#include "math.h"
#include "stdlib.h"

using namespace std;
using namespace Functional;

template<class A>
void printList(std::vector<A>& list)
{
  std::cout << "[" << Functional::join(list, ", ") << "]\n";
}

////////////////////
// Helpers
////////////////////

bool equal(float a, float b) {
  return fabs(a - b) < std::numeric_limits<float>::epsilon();
}

bool equal(double a, double b) {
  return fabs(a - b) < std::numeric_limits<float>::epsilon();
}

class MyClass
{
  public:
    template<class T>
    bool isBiggerThan10(T a) {
      return (a + i) >= 10;
    }
    template<class T>
    bool isSmallerThan10(T a) {
      return (a + i) <= 10;
    }
    int i;
    bool everyBiggerThan10(std::vector<int> list) {
      return every(list, bindMemberFunc(&MyClass::isBiggerThan10<int>, this));
    }
};

bool isBiggerThan10(int a)
{
  return a >= 10;
}

bool isPrime(int a)
{
  int start = 2;
  while (start <= sqrt(a)) {
    if (a % start++ < 1) {
      return false;
    }
  }
  return a > 1;
}

bool isEven(int a, int b, int c)
{
  if (a % 2 == 1)
    return false;
  if (b % 2 == 1)
    return false;
  if (c % 2 == 1)
    return false;

  return true;
}

std::pair<int, int> reformatMap(std::map<std::string, int> map)
{
  std::pair<int, int> res;
  res.first = map["key"];
  res.second = map["value"];
  return res;
}

int returnInt(std::string str)
{
  return atoi(str.c_str());
}

////////////////////
// Tests
////////////////////

void testBind()
{
  ternary_function<int, int, int, bool> isEven0 = ptr_fun(isEven);
  binder3arg1st<int, int, int, bool> isEven1 = isEven0[2];
  binder2arg1st<int, int, bool> isEven2 = isEven1[2];

  binder1arg1st<int, bool> isEven9 = isEven2[5];
  assert(isEven9() == false);

  binder1arg1st<int, bool> isEven92 = isEven2[6];
  assert(isEven92() == true);

  cout << "Function 'bind'\t\t\tpassed the tests.\n";
}

void testCompose()
{
  Compose<string, int, bool> function = compose(returnInt, isPrime);
  assert(function("4") == false);
  assert(function("5") == true);

  cout << "Function 'compose'\t\tpassed the tests.\n";
}

void testEvery()
{
  std::vector<int> list;
  list.push_back(12);
  list.push_back(5);
  list.push_back(8);
  list.push_back(130);
  list.push_back(44);
  bool res = every(list, isBiggerThan10);
  assert(res == false);

  list[1] = 54;
  list[2] = 18;
  res = every(list, isBiggerThan10);
  assert(res);

  cout << "Function 'every'\t\tpassed the tests.\n";
}

void testFilter()
{
  std::vector<int> list;
  list.push_back(12);
  list.push_back(5);
  list.push_back(8);
  list.push_back(130);
  list.push_back(44);
  std::vector<int> filtered = filter(list, isBiggerThan10);
  // filtered is [12, 130, 44]
  assert(filtered.size() == 3);
  assert(filtered[0] == 12);
  assert(filtered[1] == 130);
  assert(filtered[2] == 44);

  cout << "Function 'filter'\t\tpassed the tests.\n";
}

void testFindIncludes()
{
  std::vector<int> list;
  list.push_back(4);
  list.push_back(6);
  list.push_back(8);
  list.push_back(12);
  std::vector<int>::iterator res = Functional::find(list, isPrime);
  bool res2 = includes(list, isPrime);
  assert(res == list.end());  // No prime found, should return end iterator
  assert(res2 == false);

  list[1] = 5;
  res = Functional::find(list, isPrime);
  res2 = includes(list, isPrime);
  assert(*res == 5);  // Should find 5, and return an iterator to it
  assert(res2);

  list[1] = 6;
  std::vector<int>::reverse_iterator res3 = Functional::find_last(list, isPrime);
  assert(res3 == list.rend());

  list[3] = 5;
  res3 = Functional::find_last(list, isPrime);
  assert(*res3 == 5);
  assert(list.rend() - res3 == 4);

  cout << "Function 'find'\t\t\tpassed the tests.\n";
  cout << "Function 'find_last'\t\tpassed the tests.\n";
  cout << "Function 'includes'\t\tpassed the tests.\n";
}

void testFindIncludesElem()
{
  std::vector<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  std::vector<int>::iterator res = find_elem(list, 2);
  bool res2 = includes_elem(list, 2);
  assert(*res == 2);  // Should return an iterator to the element 2
  assert(res2);

  res = find_elem(list, 5);
  res2 = includes_elem(list, 5);
  assert(res == list.end());  // 4 not found, should return end iterator
  assert(res2 == false);

  list[3] = 2;
  std::vector<int>::reverse_iterator res3 = Functional::find_last_elem(list, 2);
  assert(*res3 == 2);
  assert(list.rend() - res3 == 4);

  res3 = Functional::find_last_elem(list, 0);
  assert(res3 == list.rend());  // 0 not found, should return end iterator

  cout << "Function 'find_elem'\t\tpassed the tests.\n";
  cout << "Function 'find_last_elem'\tpassed the tests.\n";
  cout << "Function 'includes_elem'\tpassed the tests.\n";
}

void testFlip()
{
  Flip<std::minus<int> > reverse_minus;
  assert(std::minus<int>()(2, 5) == 2 - 5);
  assert(reverse_minus(2, 5) == 5 - 2);
  assert(flip(std::minus<int>())(2, 5) == 5 - 2);

  cout << "Function 'flip'\t\t\tpassed the tests.\n";
}

void testJoin()
{
  std::vector<std::string> list;
  list.push_back("Wind");
  list.push_back("Rain");
  list.push_back("Fire");
  std::string str = join(list, ", ");
  assert(str == "Wind, Rain, Fire");

  str = join(list, " + ");
  assert(str == "Wind + Rain + Fire");

  str = join(list, "");
  assert(str == "WindRainFire");

  cout << "Function 'join'\t\t\tpassed the tests.\n";
}

void testMap()
{
  std::vector<int> numbers;
  numbers.push_back(1);
  numbers.push_back(4);
  numbers.push_back(9);
  std::vector<double> roots;
  Functional::map(roots, numbers, sqrt);
  // roots is now [1, 2, 3], numbers is still [1, 4, 9]
  assert(equal(roots[0], 1.0));
  assert(equal(roots[1], 2.0));
  assert(equal(roots[2], 3.0));



  std::map<std::string, int> map1;
  map1["key"] = 1;
  map1["value"] = 10;
  std::map<std::string, int> map2;
  map2["key"] = 2;
  map2["value"] = 20;
  std::map<std::string, int> map3;
  map3["key"] = 3;
  map3["value"] = 30;
  std::vector<std::map<std::string, int> > list3;
  list3.push_back(map1);
  list3.push_back(map2);
  list3.push_back(map3);

  std::vector<std::pair<int, int> > result3;
  Functional::map(result3, list3, reformatMap);
  std::map<int, int> result4(result3.begin(), result3.end());
  // result4 is now {1:10, 2:20, 3:30}
  // list3 is still [{key:1, value:10}, {key:2, value:20}, {key:3, value: 30}]
  assert(result4.size() == 3);
  assert(result4.find(1)->second == 10);
  assert(result4.find(2)->second == 20);
  assert(result4.find(3)->second == 30);



  std::vector<std::string> list2;
  list2.push_back("1");
  list2.push_back("2");
  list2.push_back("3");
  std::vector<int> result2;
  Functional::map(result2, list2, returnInt);
  // result2 is now [1, 2, 3], list2 is still ["1", "2", "3"]
  assert(result2[0] == 1);
  assert(result2[1] == 2);
  assert(result2[2] == 3);

  cout << "Function 'map'\t\t\tpassed the tests.\n";
}

void testReduce()
{
  std::vector<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);

  int res = reduce(list, 0, std::minus<int>()); // Argument 2 is the accumulator value
  assert(res == -10);
  res = reduce_right(list, 0, std::minus<int>()); // Argument 2 is the accumulator value
  assert(res == -2);
  list.insert(list.begin(), 0);
  res = reduce1(list, std::minus<int>()); // reduce1 has no acumulator
  assert(res == -10);
  res = reduce_right1(list, std::minus<int>()); // reduce_right1 has no acumulator
  assert(res == -2);

  std::vector<int> l1;
  l1.push_back(0);
  l1.push_back(1);
  std::vector<int> l2;
  l2.push_back(2);
  l2.push_back(3);
  std::vector<int> l3;
  l3.push_back(4);
  l3.push_back(5);
  std::vector<std::vector<int> > list2;
  list2.push_back(l1);
  list2.push_back(l2);
  list2.push_back(l3);
  // list2 is [[0, 1], [2, 3], [4, 5]]
  std::vector<int> flattened;
  flattened = reduce(list2, flattened, concat<std::vector<int> >);
  // flattened is [0, 1, 2, 3, 4, 5]
  assert(flattened[0] == 0);
  assert(flattened[1] == 1);
  assert(flattened[2] == 2);
  assert(flattened[3] == 3);
  assert(flattened[4] == 4);
  assert(flattened[5] == 5);

  cout << "Function 'reduce'\t\tpassed the tests.\n";
  cout << "Function 'reduce1'\t\tpassed the tests.\n";
  cout << "Function 'reduce_right'\t\tpassed the tests.\n";
  cout << "Function 'reduce_right1'\tpassed the tests.\n";
}

void testReverse()
{
  std::vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);

  std::vector<int> reversed = reverse(nums);
  assert(reversed[0] == 3);
  assert(reversed[1] == 2);
  assert(reversed[2] == 1);
  assert(nums[0] == 1);
  assert(nums[1] == 2);
  assert(nums[2] == 3);

  reverse_mutable(nums);
  assert(nums[0] == 3);
  assert(nums[1] == 2);
  assert(nums[2] == 1);

  cout << "Function 'reverse'\t\tpassed the tests.\n";
  cout << "Function 'reverse_mutable'\tpassed the tests.\n";
}

void testSlice()
{
  std::vector<std::string> fruits;
  fruits.push_back("Banana");
  fruits.push_back("Orange");
  fruits.push_back("Lemon");
  fruits.push_back("Apple");
  fruits.push_back("Mango");
  std::vector<std::string> citrus = slice(fruits, 1, 3);
  // fruits contains ["Banana", "Orange", "Lemon", "Apple", "Mango"]
  // citrus contains ["Orange", "Lemon"]
  assert(citrus[0] == "Orange");
  assert(citrus[1] == "Lemon");

  cout << "Function 'slice'\t\tpassed the tests.\n";
}

void testSome()
{
  std::vector<int> list;
  list.push_back(2);
  list.push_back(5);
  list.push_back(8);
  list.push_back(1);
  list.push_back(4);
  bool res = some(list, isBiggerThan10);
  assert(res == false);

  list[0] = 12;
  res = some(list, isBiggerThan10);
  assert(res);

  cout << "Function 'some'\t\t\tpassed the tests.\n";
}

void testConcat()
{
  std::vector<int> l1;
  l1.push_back(1);
  l1.push_back(2);
  l1.push_back(3);

  std::vector<int> l2;
  l2.push_back(4);
  l2.push_back(5);
  l2.push_back(6);

  // Test version 1: immutable
  std::vector<int> res = concat(l1, l2);
  assert(l1.size() == 3);
  assert(l2.size() == 3);
  assert(res.size() == 6);
  assert(res[0] == 1);
  assert(res[1] == 2);
  assert(res[2] == 3);
  assert(res[3] == 4);
  assert(res[4] == 5);
  assert(res[5] == 6);

  // Test version 2: mutable
  concat_mutable(l1, l2);
  assert(l2.size() == 3);
  assert(l1.size() == 6);
  assert(l1[0] == 1);
  assert(l1[1] == 2);
  assert(l1[2] == 3);
  assert(l1[3] == 4);
  assert(l1[4] == 5);
  assert(l1[5] == 6);

  cout << "Function 'concat'\t\tpassed the tests.\n";
  cout << "Function 'concat_mutable'\tpassed the tests.\n";
}

void testFlatten()
{
  std::vector<int> l1;
  l1.push_back(0);
  l1.push_back(1);
  std::vector<int> l2;
  l2.push_back(2);
  l2.push_back(3);
  std::vector<int> l3;
  l3.push_back(4);
  l3.push_back(5);
  std::vector<std::vector<int> > list2;
  list2.push_back(l1);
  list2.push_back(l2);
  list2.push_back(l3);
  // list2 is [[0, 1], [2, 3], [4, 5]]
  std::vector<int> flattened = flatten(list2);
  // flattened is [0, 1, 2, 3, 4, 5]
  assert(flattened[0] == 0);
  assert(flattened[1] == 1);
  assert(flattened[2] == 2);
  assert(flattened[3] == 3);
  assert(flattened[4] == 4);
  assert(flattened[5] == 5);

  cout << "Function 'flatten'\t\tpassed the tests.\n";
}

void testPop()
{
  std::vector<std::string> list;
  list.push_back("angel");
  list.push_back("clown");
  list.push_back("mandarin");
  list.push_back("sturgeon");

  std::string removed = pop(list);
  // list is now ["angel", "clown", "mandarin"]
  assert(removed == "sturgeon");
  assert(list.size() == 3);
  assert(list[0] == "angel");
  assert(list[1] == "clown");
  assert(list[2] == "mandarin");

  cout << "Function 'pop'\t\t\tpassed the tests.\n";
}

void testPush()
{
  std::vector<std::string> list;
  list.push_back("soccer");
  list.push_back("baseball");

  unsigned int len = push(list, std::string("football"));
  assert(list.size() == len);
  assert(len == 3);
  len = push(list, std::string("swimming"));
  // list is now ["soccer", "baseball", "football", "swimming"]
  assert(list.size() == len);
  assert(len == 4);
  assert(list[0] == "soccer");
  assert(list[1] == "baseball");
  assert(list[2] == "football");
  assert(list[3] == "swimming");

  cout << "Function 'push'\t\t\tpassed the tests.\n";
}

void testShift()
{
  std::vector<std::string> fish;
  fish.push_back("angel");
  fish.push_back("clown");
  fish.push_back("mandarin");
  fish.push_back("surgeon");

  std::string removed = shift(fish);
  // fish is now ["clown", "mandarin", "surgeon"]
  assert(removed == "angel");
  assert(fish.size() == 3);
  assert(fish[0] == "clown");
  assert(fish[1] == "mandarin");
  assert(fish[2] == "surgeon");

  cout << "Function 'shift'\t\tpassed the tests.\n";
}

void testSplice()
{
  std::vector<std::string> list;
  list.push_back("angel");
  list.push_back("clown");
  list.push_back("mandarin");
  list.push_back("surgeon");

  std::vector<std::string> removed;
  std::vector<std::string> addL;

  addL.push_back("drum");
  removed = splice(list, 2, 0, addL);
  // list is now    ["angel", "clown", "drum", "mandarin", "surgeon"]
  // removed is now []
  assert(list.size() == 5);
  assert(list[0] == "angel");
  assert(list[1] == "clown");
  assert(list[2] == "drum");
  assert(list[3] == "mandarin");
  assert(list[4] == "surgeon");
  assert(removed.size() == 0);

  addL.clear();
  removed = splice(list, 3, 1, addL);
  // list is now    ["angel", "clown", "drum", "surgeon"]
  // removed is now ["mandarin"]
  assert(list.size() == 4);
  assert(list[0] == "angel");
  assert(list[1] == "clown");
  assert(list[2] == "drum");
  assert(list[3] == "surgeon");
  assert(removed.size() == 1);
  assert(removed[0] == "mandarin");

  addL.push_back("trumpet");
  removed = splice(list, 2, 1, addL);
  // list is now ["angel", "clown", "trumpet", "surgeon"]
  // removed is now ["drum"]
  assert(list.size() == 4);
  assert(list[0] == "angel");
  assert(list[1] == "clown");
  assert(list[2] == "trumpet");
  assert(list[3] == "surgeon");
  assert(removed.size() == 1);
  assert(removed[0] == "drum");

  addL.clear();
  addL.push_back("parrot");
  addL.push_back("anemone");
  addL.push_back("blue");
  removed = splice(list, 0, 2, addL);
  // list is now ["parrot", "anemone", "blue", "trumpet", "surgeon"]
  // removed is now ["angel", "clown"]
  assert(list.size() == 5);
  assert(list[0] == "parrot");
  assert(list[1] == "anemone");
  assert(list[2] == "blue");
  assert(list[3] == "trumpet");
  assert(list[4] == "surgeon");
  assert(removed.size() == 2);
  assert(removed[0] == "angel");
  assert(removed[1] == "clown");

  addL.clear();
  removed = splice(list, 3, 2000, addL);
  // list is now ["parrot", "anemone", "blue"]
  // removed is now ["trumpet", "surgeon"]
  assert(list.size() == 3);
  assert(list[0] == "parrot");
  assert(list[1] == "anemone");
  assert(list[2] == "blue");
  assert(removed.size() == 2);
  assert(removed[0] == "trumpet");
  assert(removed[1] == "surgeon");

  cout << "Function 'splice'\t\tpassed the tests.\n";
}

void testUnshift()
{
  std::vector<int> list;
  list.push_back(1);
  list.push_back(2);

  unsigned int len = unshift(list, 0);
  // list is now [0, 1, 2]
  assert(list.size() == len);
  assert(len == 3);

  len = unshift(list, -1);
  // list is now [-1, 0, 1, 2]
  assert(list.size() == len);
  assert(len == 4);

  len = unshift(list, -2);
  // list is now [-2, -1, 0, 1, 2]
  assert(list.size() == len);
  assert(len == 5);
  assert(list[0] == -2);
  assert(list[1] == -1);
  assert(list[2] == 0);
  assert(list[3] == 1);
  assert(list[4] == 2);

  cout << "Function 'unshift'\t\tpassed the tests.\n";
}

void testUnzip()
{
  std::map<std::string, int> map1;
  map1.insert(std::pair<std::string, int>("a", 3));
  map1.insert(std::pair<std::string, int>("b", 4));
  map1.insert(std::pair<std::string, int>("c", 5));

  std::pair<std::vector<std::string>, std::vector<int> > result = Functional::unzip<std::vector>(map1);
  assert(result.first[1] == "b");
  assert(result.second[1] == 4);

  cout << "Function 'unzip'\t\tpassed the tests.\n";
}

void testZip()
{
  std::vector<std::string> keys;
  keys.push_back("a");
  keys.push_back("b");
  keys.push_back("c");

  std::vector<int> values;
  values.push_back(3);
  values.push_back(4);
  values.push_back(5);

  std::map<std::string, int> result = Functional::zip(keys, values);
  assert(result["a"] == 3);
  assert(result["b"] == 4);
  assert(result["c"] == 5);

  cout << "Function 'zip'\t\t\tpassed the tests.\n";
}

void testBindMemberFunc()
{
  std::vector<int> list;
  list.push_back(12);
  list.push_back(5);
  list.push_back(8);
  bool res = every(list, isBiggerThan10);
  assert(res == false);

  MyClass instance;
  instance.i = 0;

  Functional::binder2arg1st<MyClass*, int, bool> isBgThan10 = bindMemberFunc(&MyClass::isBiggerThan10<int>, &instance);
  Functional::binder2arg1st<MyClass*, int, bool> isSmThan10 = bindMemberFunc(&MyClass::isSmallerThan10<int>, &instance);

  assert(isBgThan10(5) == false);

  res = every(list, isBgThan10);
  assert(res == false);

  instance.i = 5;
  res = every(list, isBgThan10);
  assert(res == true);

  res = instance.everyBiggerThan10(list);
  assert(res == true);

  cout << "Function 'bindMemberFunc'\tpassed the tests.\n";
}

int main()
{
  testBind();
  testCompose();
  testConcat();
  testEvery();
  testFilter();
  testFindIncludes();
  testFindIncludesElem();
  testFlatten();
  testFlip();
  testJoin();
  testMap();
  testPop();
  testPush();
  testReduce();
  testReverse();
  testShift();
  testSlice();
  testSome();
  testSplice();
  testUnshift();
  testUnzip();
  testZip();

  testBindMemberFunc();
}
