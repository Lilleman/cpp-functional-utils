/**
 * Copyright 2017 Christoffer Ackelman
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * WARNING! This file was generated, do not modify it directly!
 */

#ifndef MEMOIZE_H
#define MEMOIZE_H

#include <iostream>
#include <map>
#include "functional_helpers.h"
#include "tuples.h"

namespace Memoize {

template<typename Result, typename T1>
class unary_memoizer
{
public:
  std::map<Tuples::unary_tuple<T1>, Result> memo;
  Functional::unary_function<T1, Result> _fun;
  unary_memoizer() {}
  unary_memoizer(Functional::unary_function<T1, Result> &f) : _fun(f) {}
  virtual Result operator()(T1 _a) {
    Tuples::unary_tuple<T1> tup = Tuples::tuple(_a);
    typename std::map<Tuples::unary_tuple<T1>, Result>::const_iterator found = memo.find(tup);
    if (found != memo.end()) {
#ifdef DEBUG
      std::cout << "Found!\n";
#endif
      return found->second;
    }
#ifdef DEBUG
    std::cout << "Not found!\n";
#endif
    Result res = _fun(_a);
    memo[tup] = res;
    return res;
  }
};

template<typename Result, typename T1>
unary_memoizer<Result, T1> memoize(Functional::unary_function<T1, Result> f)
{
  return unary_memoizer<Result, T1>(f);
}

template<typename Result, typename T1>
unary_memoizer<Result, T1> memoize(Result (*f)(T1))
{
  return memoize(Functional::ptr_fun(f));
}

template<typename Result, typename Class>
unary_memoizer<Result, Class*> memoize(Result (Class::*f)())
{
  return memoize(Functional::mem_fun(f));
}

template<typename Result, typename T1, typename T2>
class binary_memoizer
{
public:
  std::map<Tuples::binary_tuple<T1, T2>, Result> memo;
  Functional::binary_function<T1, T2, Result> _fun;
  binary_memoizer() {}
  binary_memoizer(Functional::binary_function<T1, T2, Result> &f) : _fun(f) {}
  virtual Result operator()(T1 _a, T2 _b) {
    Tuples::binary_tuple<T1, T2> tup = Tuples::tuple(_a, _b);
    typename std::map<Tuples::binary_tuple<T1, T2>, Result>::const_iterator found = memo.find(tup);
    if (found != memo.end()) {
#ifdef DEBUG
      std::cout << "Found!\n";
#endif
      return found->second;
    }
#ifdef DEBUG
    std::cout << "Not found!\n";
#endif
    Result res = _fun(_a, _b);
    memo[tup] = res;
    return res;
  }
};

template<typename Result, typename T1, typename T2>
binary_memoizer<Result, T1, T2> memoize(Functional::binary_function<T1, T2, Result> f)
{
  return binary_memoizer<Result, T1, T2>(f);
}

template<typename Result, typename T1, typename T2>
binary_memoizer<Result, T1, T2> memoize(Result (*f)(T1, T2))
{
  return memoize(Functional::ptr_fun(f));
}

template<typename Result, typename Class, typename T1>
binary_memoizer<Result, Class*, T1> memoize(Result (Class::*f)(T1))
{
  return memoize(Functional::mem_fun(f));
}

template<typename Result, typename T1, typename T2, typename T3>
class ternary_memoizer
{
public:
  std::map<Tuples::ternary_tuple<T1, T2, T3>, Result> memo;
  Functional::ternary_function<T1, T2, T3, Result> _fun;
  ternary_memoizer() {}
  ternary_memoizer(Functional::ternary_function<T1, T2, T3, Result> &f) : _fun(f) {}
  virtual Result operator()(T1 _a, T2 _b, T3 _c) {
    Tuples::ternary_tuple<T1, T2, T3> tup = Tuples::tuple(_a, _b, _c);
    typename std::map<Tuples::ternary_tuple<T1, T2, T3>, Result>::const_iterator found = memo.find(tup);
    if (found != memo.end()) {
#ifdef DEBUG
      std::cout << "Found!\n";
#endif
      return found->second;
    }
#ifdef DEBUG
    std::cout << "Not found!\n";
#endif
    Result res = _fun(_a, _b, _c);
    memo[tup] = res;
    return res;
  }
};

template<typename Result, typename T1, typename T2, typename T3>
ternary_memoizer<Result, T1, T2, T3> memoize(Functional::ternary_function<T1, T2, T3, Result> f)
{
  return ternary_memoizer<Result, T1, T2, T3>(f);
}

template<typename Result, typename T1, typename T2, typename T3>
ternary_memoizer<Result, T1, T2, T3> memoize(Result (*f)(T1, T2, T3))
{
  return memoize(Functional::ptr_fun(f));
}

template<typename Result, typename Class, typename T1, typename T2>
ternary_memoizer<Result, Class*, T1, T2> memoize(Result (Class::*f)(T1, T2))
{
  return memoize(Functional::mem_fun(f));
}

template<typename Result, typename T1, typename T2, typename T3, typename T4>
class quaternary_memoizer
{
public:
  std::map<Tuples::quaternary_tuple<T1, T2, T3, T4>, Result> memo;
  Functional::quaternary_function<T1, T2, T3, T4, Result> _fun;
  quaternary_memoizer() {}
  quaternary_memoizer(Functional::quaternary_function<T1, T2, T3, T4, Result> &f) : _fun(f) {}
  virtual Result operator()(T1 _a, T2 _b, T3 _c, T4 _d) {
    Tuples::quaternary_tuple<T1, T2, T3, T4> tup = Tuples::tuple(_a, _b, _c, _d);
    typename std::map<Tuples::quaternary_tuple<T1, T2, T3, T4>, Result>::const_iterator found = memo.find(tup);
    if (found != memo.end()) {
#ifdef DEBUG
      std::cout << "Found!\n";
#endif
      return found->second;
    }
#ifdef DEBUG
    std::cout << "Not found!\n";
#endif
    Result res = _fun(_a, _b, _c, _d);
    memo[tup] = res;
    return res;
  }
};

template<typename Result, typename T1, typename T2, typename T3, typename T4>
quaternary_memoizer<Result, T1, T2, T3, T4> memoize(Functional::quaternary_function<T1, T2, T3, T4, Result> f)
{
  return quaternary_memoizer<Result, T1, T2, T3, T4>(f);
}

template<typename Result, typename T1, typename T2, typename T3, typename T4>
quaternary_memoizer<Result, T1, T2, T3, T4> memoize(Result (*f)(T1, T2, T3, T4))
{
  return memoize(Functional::ptr_fun(f));
}

template<typename Result, typename Class, typename T1, typename T2, typename T3>
quaternary_memoizer<Result, Class*, T1, T2, T3> memoize(Result (Class::*f)(T1, T2, T3))
{
  return memoize(Functional::mem_fun(f));
}

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5>
class quinary_memoizer
{
public:
  std::map<Tuples::quinary_tuple<T1, T2, T3, T4, T5>, Result> memo;
  Functional::quinary_function<T1, T2, T3, T4, T5, Result> _fun;
  quinary_memoizer() {}
  quinary_memoizer(Functional::quinary_function<T1, T2, T3, T4, T5, Result> &f) : _fun(f) {}
  virtual Result operator()(T1 _a, T2 _b, T3 _c, T4 _d, T5 _e) {
    Tuples::quinary_tuple<T1, T2, T3, T4, T5> tup = Tuples::tuple(_a, _b, _c, _d, _e);
    typename std::map<Tuples::quinary_tuple<T1, T2, T3, T4, T5>, Result>::const_iterator found = memo.find(tup);
    if (found != memo.end()) {
#ifdef DEBUG
      std::cout << "Found!\n";
#endif
      return found->second;
    }
#ifdef DEBUG
    std::cout << "Not found!\n";
#endif
    Result res = _fun(_a, _b, _c, _d, _e);
    memo[tup] = res;
    return res;
  }
};

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5>
quinary_memoizer<Result, T1, T2, T3, T4, T5> memoize(Functional::quinary_function<T1, T2, T3, T4, T5, Result> f)
{
  return quinary_memoizer<Result, T1, T2, T3, T4, T5>(f);
}

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5>
quinary_memoizer<Result, T1, T2, T3, T4, T5> memoize(Result (*f)(T1, T2, T3, T4, T5))
{
  return memoize(Functional::ptr_fun(f));
}

template<typename Result, typename Class, typename T1, typename T2, typename T3, typename T4>
quinary_memoizer<Result, Class*, T1, T2, T3, T4> memoize(Result (Class::*f)(T1, T2, T3, T4))
{
  return memoize(Functional::mem_fun(f));
}

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class senary_memoizer
{
public:
  std::map<Tuples::senary_tuple<T1, T2, T3, T4, T5, T6>, Result> memo;
  Functional::senary_function<T1, T2, T3, T4, T5, T6, Result> _fun;
  senary_memoizer() {}
  senary_memoizer(Functional::senary_function<T1, T2, T3, T4, T5, T6, Result> &f) : _fun(f) {}
  virtual Result operator()(T1 _a, T2 _b, T3 _c, T4 _d, T5 _e, T6 _f) {
    Tuples::senary_tuple<T1, T2, T3, T4, T5, T6> tup = Tuples::tuple(_a, _b, _c, _d, _e, _f);
    typename std::map<Tuples::senary_tuple<T1, T2, T3, T4, T5, T6>, Result>::const_iterator found = memo.find(tup);
    if (found != memo.end()) {
#ifdef DEBUG
      std::cout << "Found!\n";
#endif
      return found->second;
    }
#ifdef DEBUG
    std::cout << "Not found!\n";
#endif
    Result res = _fun(_a, _b, _c, _d, _e, _f);
    memo[tup] = res;
    return res;
  }
};

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
senary_memoizer<Result, T1, T2, T3, T4, T5, T6> memoize(Functional::senary_function<T1, T2, T3, T4, T5, T6, Result> f)
{
  return senary_memoizer<Result, T1, T2, T3, T4, T5, T6>(f);
}

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
senary_memoizer<Result, T1, T2, T3, T4, T5, T6> memoize(Result (*f)(T1, T2, T3, T4, T5, T6))
{
  return memoize(Functional::ptr_fun(f));
}

template<typename Result, typename Class, typename T1, typename T2, typename T3, typename T4, typename T5>
senary_memoizer<Result, Class*, T1, T2, T3, T4, T5> memoize(Result (Class::*f)(T1, T2, T3, T4, T5))
{
  return memoize(Functional::mem_fun(f));
}

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
class septenary_memoizer
{
public:
  std::map<Tuples::septenary_tuple<T1, T2, T3, T4, T5, T6, T7>, Result> memo;
  Functional::septenary_function<T1, T2, T3, T4, T5, T6, T7, Result> _fun;
  septenary_memoizer() {}
  septenary_memoizer(Functional::septenary_function<T1, T2, T3, T4, T5, T6, T7, Result> &f) : _fun(f) {}
  virtual Result operator()(T1 _a, T2 _b, T3 _c, T4 _d, T5 _e, T6 _f, T7 _g) {
    Tuples::septenary_tuple<T1, T2, T3, T4, T5, T6, T7> tup = Tuples::tuple(_a, _b, _c, _d, _e, _f, _g);
    typename std::map<Tuples::septenary_tuple<T1, T2, T3, T4, T5, T6, T7>, Result>::const_iterator found = memo.find(tup);
    if (found != memo.end()) {
#ifdef DEBUG
      std::cout << "Found!\n";
#endif
      return found->second;
    }
#ifdef DEBUG
    std::cout << "Not found!\n";
#endif
    Result res = _fun(_a, _b, _c, _d, _e, _f, _g);
    memo[tup] = res;
    return res;
  }
};

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
septenary_memoizer<Result, T1, T2, T3, T4, T5, T6, T7> memoize(Functional::septenary_function<T1, T2, T3, T4, T5, T6, T7, Result> f)
{
  return septenary_memoizer<Result, T1, T2, T3, T4, T5, T6, T7>(f);
}

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
septenary_memoizer<Result, T1, T2, T3, T4, T5, T6, T7> memoize(Result (*f)(T1, T2, T3, T4, T5, T6, T7))
{
  return memoize(Functional::ptr_fun(f));
}

template<typename Result, typename Class, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
septenary_memoizer<Result, Class*, T1, T2, T3, T4, T5, T6> memoize(Result (Class::*f)(T1, T2, T3, T4, T5, T6))
{
  return memoize(Functional::mem_fun(f));
}

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
class octonary_memoizer
{
public:
  std::map<Tuples::octonary_tuple<T1, T2, T3, T4, T5, T6, T7, T8>, Result> memo;
  Functional::octonary_function<T1, T2, T3, T4, T5, T6, T7, T8, Result> _fun;
  octonary_memoizer() {}
  octonary_memoizer(Functional::octonary_function<T1, T2, T3, T4, T5, T6, T7, T8, Result> &f) : _fun(f) {}
  virtual Result operator()(T1 _a, T2 _b, T3 _c, T4 _d, T5 _e, T6 _f, T7 _g, T8 _h) {
    Tuples::octonary_tuple<T1, T2, T3, T4, T5, T6, T7, T8> tup = Tuples::tuple(_a, _b, _c, _d, _e, _f, _g, _h);
    typename std::map<Tuples::octonary_tuple<T1, T2, T3, T4, T5, T6, T7, T8>, Result>::const_iterator found = memo.find(tup);
    if (found != memo.end()) {
#ifdef DEBUG
      std::cout << "Found!\n";
#endif
      return found->second;
    }
#ifdef DEBUG
    std::cout << "Not found!\n";
#endif
    Result res = _fun(_a, _b, _c, _d, _e, _f, _g, _h);
    memo[tup] = res;
    return res;
  }
};

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
octonary_memoizer<Result, T1, T2, T3, T4, T5, T6, T7, T8> memoize(Functional::octonary_function<T1, T2, T3, T4, T5, T6, T7, T8, Result> f)
{
  return octonary_memoizer<Result, T1, T2, T3, T4, T5, T6, T7, T8>(f);
}

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
octonary_memoizer<Result, T1, T2, T3, T4, T5, T6, T7, T8> memoize(Result (*f)(T1, T2, T3, T4, T5, T6, T7, T8))
{
  return memoize(Functional::ptr_fun(f));
}

template<typename Result, typename Class, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
octonary_memoizer<Result, Class*, T1, T2, T3, T4, T5, T6, T7> memoize(Result (Class::*f)(T1, T2, T3, T4, T5, T6, T7))
{
  return memoize(Functional::mem_fun(f));
}

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
class novenary_memoizer
{
public:
  std::map<Tuples::novenary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9>, Result> memo;
  Functional::novenary_function<T1, T2, T3, T4, T5, T6, T7, T8, T9, Result> _fun;
  novenary_memoizer() {}
  novenary_memoizer(Functional::novenary_function<T1, T2, T3, T4, T5, T6, T7, T8, T9, Result> &f) : _fun(f) {}
  virtual Result operator()(T1 _a, T2 _b, T3 _c, T4 _d, T5 _e, T6 _f, T7 _g, T8 _h, T9 _i) {
    Tuples::novenary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9> tup = Tuples::tuple(_a, _b, _c, _d, _e, _f, _g, _h, _i);
    typename std::map<Tuples::novenary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9>, Result>::const_iterator found = memo.find(tup);
    if (found != memo.end()) {
#ifdef DEBUG
      std::cout << "Found!\n";
#endif
      return found->second;
    }
#ifdef DEBUG
    std::cout << "Not found!\n";
#endif
    Result res = _fun(_a, _b, _c, _d, _e, _f, _g, _h, _i);
    memo[tup] = res;
    return res;
  }
};

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
novenary_memoizer<Result, T1, T2, T3, T4, T5, T6, T7, T8, T9> memoize(Functional::novenary_function<T1, T2, T3, T4, T5, T6, T7, T8, T9, Result> f)
{
  return novenary_memoizer<Result, T1, T2, T3, T4, T5, T6, T7, T8, T9>(f);
}

template<typename Result, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
novenary_memoizer<Result, T1, T2, T3, T4, T5, T6, T7, T8, T9> memoize(Result (*f)(T1, T2, T3, T4, T5, T6, T7, T8, T9))
{
  return memoize(Functional::ptr_fun(f));
}

template<typename Result, typename Class, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
novenary_memoizer<Result, Class*, T1, T2, T3, T4, T5, T6, T7, T8> memoize(Result (Class::*f)(T1, T2, T3, T4, T5, T6, T7, T8))
{
  return memoize(Functional::mem_fun(f));
}

} //end of namespace

#endif