/**
 * Copyright 2017 Christoffer Ackelman
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <iostream>

#include <algorithm>
#include <map>
#include <numeric>
#include <sstream>
#include <string>

#include "functional_helpers.h"

namespace Functional
{

/**
 * Identity function that simply returns it's argument.
 */
template<typename T>
T id(const T t)
{
  return t;
}

/**
 * Takes two functions and returns a new function composed of the two functions.
 * If provided the functions f(x) and g(x),
 * the returned function y(x) will be equal to g(f(x))
 *
 * Usage:
 *   Compose<string, int, bool> isStringPrime = compose(to_int, is_prime);
 *   bool result = isStringPrime("5");
 */
template<typename A, typename B, typename C>
class Compose : std::unary_function<A, C>
{
    B(*f)(A);
    C(*g)(B);
  public:
    Compose(B(*f)(A), C(*g)(B)) : f(f), g(g) {}
    C operator()(A x) {
      return g(f(x));
    }
};

template<typename A, typename B, typename C>
Compose<A, B, C> compose(B(*f)(A), C(*g)(B))
{
  return Compose<A, B, C>(f, g);
}

/**
 * Flips the order of arguments for a functor taking two arguments.
 *
 * Usage:
 *   Flip<std::minus<int> > reverse_minus;
 *   assert(reverse_minus(a, b) == b - a);
 * or:
 *   assert(flip(std::minus<int>())(a, b) == b - a);
 */
template<typename Predicate>
class Flip : public std::binary_function<typename Predicate::first_argument_type, typename Predicate::second_argument_type, typename Predicate::result_type>
{
public:
  Flip() { pred = Predicate(); }
  typename Predicate::result_type operator()(const typename Predicate::first_argument_type &a, const typename Predicate::second_argument_type &b) const { return pred(b, a); }
protected:
  Predicate pred;
};

template<typename Predicate>
Flip<Predicate> flip(const Predicate &pred)
{ return Flip<Predicate>(); }

/**
 * Concatenetes two containers and stores the result in a new container.
 *
 * Usage:
 *   list3 = concat(list1, list2)
 */
template<typename Container>
Container concat(const Container &s1, const Container &s2)
{
  Container result;
  result.insert(result.end(), s1.begin(), s1.end());
  result.insert(result.end(), s2.begin(), s2.end());
  return result;
}

/**
 * Concatenes s2 to the end of s1.
 *
 * Usage:
 *   concat(list1, list2)
 */
template<typename Container>
void concat_mutable(Container &s1, const Container &s2)
{
  s1.insert(s1.end(), s2.begin(), s2.end());
}

/**
 * Tests whether all element in the container satisfy the provided predicate.
 *
 * Usage:
 *   if (every(list1, EVEN))
 */
template<typename Container, typename Functor>
bool every(Container &s, Functor f)
{
  typename Container::iterator it;
  for (it = s.begin(); it != s.end(); it++) {
    if (!f(*it)) {
      return false;
    }
  }
  return true;
}

/**
 * Returns all elements that satisfy the provided predicate.
 *
 * Usage:
 *   list2 = filter(list1, EVEN)
 */
template<typename Container, typename Functor>
Container filter(Container &s, Functor f)
{
  Container result;
  typename Container::iterator it;
  for (it = s.begin(); it != s.end(); it++) {
    if (f(*it)) {
      result.insert(result.end(), *it);
    }
  }
  return result;
}

/**
 * Returns an iterator to the first element in the container that satisfy the
 * provided predicate. Otherwise the last iterator is returned.
 *
 * Usage:
 *   iterator it = find(list, EVEN)
 */
template<typename Container, typename Functor>
typename Container::iterator find(Container &s, Functor f)
{
  return std::find_if(s.begin(), s.end(), f);
}

/**
 * Returns an iterator to the last element in the container that satisfy the
 * provided predicate. Otherwise the last iterator is returned.
 *
 * Usage:
 *   iterator it = find_last(list, EVEN)
 */
template<typename Container, typename Functor>
typename Container::reverse_iterator find_last(Container &s, Functor f)
{
  return std::find_if(s.rbegin(), s.rend(), f);
}

/**
 * Returns an iterator to the first element in the container, that is equal to
 * the provided element. Otherwise the last iterator is returned.
 *
 * Usage:
 *   iterator it = find_elem(list, 4)
 */
template<typename Container>
typename Container::iterator find_elem(Container &s, typename Container::const_reference elem)
{
  return std::find(s.begin(), s.end(), elem);
}

/**
 * Returns an iterator to the last element in the container, that is equal to
 * the provided element. Otherwise the last iterator is returned.
 *
 * Usage:
 *   iterator it = find_last_elem(list, 4)
 */
template<typename Container>
typename Container::reverse_iterator find_last_elem(Container &s, typename Container::const_reference elem)
{
  return std::find(s.rbegin(), s.rend(), elem);
}

/**
 * Executes the provided function on each element in the container.
 *
 * Usage:
 *   for_each(list, print_element)
 */
template<typename Container, typename Functor>
void for_each(Container &s, Functor f)
{
  typename Container::iterator it;
  for (it = s.begin(); it != s.end(); it++) {
    f(*it);
  }
}

/**
 * Determines whether the container contains an element that satisfies the
 * provided predicate.
 *
 * Usage:
 *   if (includes(list, EVEN))
 */
template<typename Container, typename Fun>
bool includes(Container &s, Fun f)
{
  return Functional::find(s, f) != s.end();
}

/**
 * Determines whether the container contains the provided element.
 *
 * Usage:
 *   if (includes_elem(list, 4))
 */
template<typename Container>
bool includes_elem(Container &s, typename Container::const_reference elem)
{
  return find_elem(s, elem) != s.end();
}

/**
 * Joins all elements of the container into a string where the elements are
 * separated by the provided separator.
 *
 * Usage:
 *   cout << join(list)
 */
template<typename Container>
std::string join(Container &s, std::string sep)
{
  typename Container::iterator it;
  std::ostringstream ss;
  for (it = s.begin(); it != s.end(); it++) {
    ss << *it;
    if (it != s.end() - 1) {
      ss << sep;
    }
  }
  return ss.str();
}

/**
 * Executes the provided function once for each element in the container.
 *
 * Usage:
 *   vector<int> result;
 *   map(result, listOfStrings, convertStringToInt)
 */
template<typename TargetContainer, typename SourceContainer, typename Functor>
TargetContainer& map(TargetContainer &t, SourceContainer &s, Functor f)
{
  std::transform(s.begin(), s.end(), std::inserter<TargetContainer>(t, t.end()), f);
  return t;
}

/**
 * Removes the last element from a vector and returns that element.
 *
 * Usage:
 *   last_element = pop(list)
 */
template<typename Container>
typename Container::value_type pop(Container &s)
{
  typename Container::value_type result = s.back();
  s.pop_back();
  return result;
}

/**
 * Adds one element to the end of the vector and returns the new length of the vector.
 *
 * Usage:
 *   int new_size = push(list, element);
 */
template<typename Container>
int push(Container &s, typename Container::value_type elem)
{
  s.push_back(elem);
  return s.size();
}

/**
 * Applies the provided function against a provided accumulator and each value
 * in the provided container (from left to right) reducing it to a single value.
 *
 * Usage:
 *   int sum = reduce(listWithInts, 0, addTwoInts)
 */
template<typename Container, typename Functor>
typename Container::value_type reduce(Container &s, typename Container::const_reference acc, Functor f)
{
  return std::accumulate(s.begin(), s.end(), acc, f);
}

/**
 * Applies the provided function against a provided accumulator and each value
 * in the provided container (from right to left) reducing it to a single value.
 *
 * Usage:
 *   int sum = reduce_right(listWithInts, 0, addTwoInts)
 */
template<typename Container, typename Functor>
typename Container::value_type reduce_right(Container &s, typename Container::const_reference acc, Functor f)
{
  return std::accumulate(s.rbegin(), s.rend(), acc, flip(f));
}

/**
 * Flattens a vector of vectors into a single vector.
 * [[1, 2], [3, 4]] -> [1, 2, 3, 4]
 *
 * Usage:
 *   vector<int> flattened = flatten(vector<vector<int>>)
 */
template<typename Container>
typename Container::value_type flatten(Container &s)
{
  typename Container::value_type flattened;
  return reduce(s, flattened, concat<typename Container::value_type>);
}

/**
 * Same as reduce, but without an accumulator.
 * Uses the first value in the container as accumulator instead.
 *
 * Usage:
 *   int sum = reduce1(listWithInts, addTwoInts)
 */
template<typename Container, typename Functor>
typename Container::value_type reduce1(Container &s, Functor f)
{
  typename Container::value_type acc = *(s.begin());
  return std::accumulate(++s.begin(), s.end(), acc, f);
}

/**
 * Same as reduce_right, but without an accumulator.
 * Uses the first value in the container as accumulator instead.
 *
 * Usage:
 *   int sum = reduce_right1(listWithInts, addTwoInts)
 */
template<typename Container, typename Functor>
typename Container::value_type reduce_right1(Container &s, Functor f)
{
  typename Container::value_type acc = *(s.rbegin());
  return std::accumulate(++s.rbegin(), s.rend(), acc, f);
}

/**
 * Reverses the order of all elements in the provided container, returning a
 * new container with all elements in reverse order.
 *
 * Usage:
 *   reversed_list = reverse(list);
 */
template<typename Container>
Container reverse(Container &s)
{
  return Container(s.rbegin(), s.rend());
}

/**
 * Reverses the order of all elements in the provided container.
 *
 * Usage:
 *   reverse(list);
 */
template<typename Container>
void reverse_mutable(Container &s)
{
  return std::reverse(s.begin(), s.end());
}

/**
 * Removed the first element from a vector and returns that element.
 *
 * Usage:
 *   int first_element = shift(list)
 */
template<typename Container>
typename Container::value_type shift(Container &s)
{
  typename Container::value_type result = s.front();
  s.erase(s.begin());
  return result;
}

/**
 * Creates a shallow copy of the specified range.
 *
 * Usage:
 *   list_with_first_three_elements = shift(list, 0, 3)
 */
template<typename Container>
Container slice(Container &s, int begin, int end)
{
  typename Container::iterator begin1 = min(s.begin() + begin, s.end());
  typename Container::iterator end1 = min(s.begin() + end, s.end());

  return Container(begin1, end1);
}

/**
 * Tests whether some element in the container satisfy the provided predicate.
 *
 * Usage:
 *   if (some(list, EVEN))
 */
template<typename Container, typename Functor>
bool some(Container &s, Functor f)
{
  typename Container::iterator it;
  for (it = s.begin(); it != s.end(); it++) {
    if (f(*it)) {
      return true;
    }
  }
  return false;
}

/**
 * First removes deleteCount elements from the vector, beginning at index start.
 * Then adds all elements from addList to the vector, beginning at index start.
 *
 * Usage:
 *   list_with_removed_elements = splice(list, 2, 1, list_with_elements_to_add)
 */
template<typename Container>
Container splice(Container &s, int start, int deleteCount, Container &addList)
{
  typename Container::iterator begin = min(s.begin() + start, s.end());
  typename Container::iterator end = min(s.begin() + start + deleteCount, s.end());

  Container removed(begin, end);
  s.erase(begin, end);
  s.insert(begin, addList.begin(), addList.end());
  return removed;
}

/**
 * Adds one element to the beginning of a vector and returns the new length of the vector.
 *
 * Usage:
 *   int new_size = unshift(list, element)
 */
template<typename Container>
int unshift(Container &s, typename Container::value_type elem)
{
  s.insert(s.begin(), elem);
  return s.size();
}

/**
 * Splits a map into one container with all keys and one container with all values.
 *
 *
 * Usage:
 *   pair<vector<string>, vector<int>> pairs = unzip<vector>(mapWithStringToIntPairs)
 */
template<template <typename, typename> class TargetContainer, typename A, typename B>
std::pair<TargetContainer<A, std::allocator<A> >, TargetContainer<B, std::allocator<B> > > unzip(std::map<A, B> map)
{
  std::pair<TargetContainer<A, std::allocator<A> >, TargetContainer<B, std::allocator<B> > > result;
  for (typename std::map<A, B>::iterator it = map.begin(); it != map.end(); it++) {
    result.first.push_back(it->first);
    result.second.push_back(it->second);
  }
  return result;
}

/**
 * Creates a map from one container with all keys and one container with all values.
 *
 * Usage:
 *   map<string, int> mapWithStringToIntPairs = zip(listWithStrings, listWithInts)
 */
template<template <typename, typename> class SourceContainer, typename A, typename B>
std::map<A, B> zip(SourceContainer<A, std::allocator<A> > keys, SourceContainer<B, std::allocator<B> > values)
{
  std::map<A, B> result;
  typename SourceContainer<A, std::allocator<A> >::iterator it;
  typename SourceContainer<B, std::allocator<B> >::iterator it2;
  for (it = keys.begin(), it2 = values.begin(); it != keys.end() && it2 != values.end(); it++, it2++) {
    result.insert(std::pair<A, B>(*it, *it2));
  }
  return result;
}

} // End of namespace Functional
