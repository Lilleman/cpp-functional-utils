/**
 * Copyright 2017 Christoffer Ackelman
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * WARNING! This file was generated, do not modify it directly!
 */

#ifndef FUNCTIONAL_HELPERS_H
#define FUNCTIONAL_HELPERS_H

namespace Functional {

template<typename Arg1, typename Result>
class binder1arg1st;

template<typename Arg1, typename Arg2, typename Result>
class binder2arg1st;

template<typename Arg1, typename Arg2, typename Arg3, typename Result>
class binder3arg1st;

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Result>
class binder4arg1st;

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Result>
class binder5arg1st;

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
class binder6arg1st;

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
class binder7arg1st;

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
class binder8arg1st;

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
class binder9arg1st;

template<typename Result>
class nullary_function
{
protected:
  Result (*_fun)();
public:
  nullary_function() {}
  nullary_function(Result (*func)()) : _fun(func) {}
  virtual Result operator()() const {
    return _fun();
  }
};

template<typename Result>
nullary_function<Result> ptr_fun(Result (*_fun)())
{
  return nullary_function<Result>(_fun);
}

template<typename Arg1, typename Result>
class unary_function
{
protected:
  Result (*_fun)(Arg1);
public:
  unary_function() {}
  unary_function(Result (*func)(Arg1)) : _fun(func) {}
  binder1arg1st<Arg1, Result> operator[](const Arg1 x) const {
    return bind1st(*this, x);
  }
  virtual Result operator()(Arg1 _a) const {
    return _fun(_a);
  }
};

template<typename Arg1, typename Result>
unary_function<Arg1, Result> ptr_fun(Result (*_fun)(Arg1))
{
  return unary_function<Arg1, Result>(_fun);
}

template<typename Arg1, typename Arg2, typename Result>
class binary_function
{
protected:
  Result (*_fun)(Arg1, Arg2);
public:
  binary_function() {}
  binary_function(Result (*func)(Arg1, Arg2)) : _fun(func) {}
  binder2arg1st<Arg1, Arg2, Result> operator[](const Arg1 x) const {
    return bind1st(*this, x);
  }
  virtual Result operator()(Arg1 _a, Arg2 _b) const {
    return _fun(_a, _b);
  }
};

template<typename Arg1, typename Arg2, typename Result>
binary_function<Arg1, Arg2, Result> ptr_fun(Result (*_fun)(Arg1, Arg2))
{
  return binary_function<Arg1, Arg2, Result>(_fun);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Result>
class ternary_function
{
protected:
  Result (*_fun)(Arg1, Arg2, Arg3);
public:
  ternary_function() {}
  ternary_function(Result (*func)(Arg1, Arg2, Arg3)) : _fun(func) {}
  binder3arg1st<Arg1, Arg2, Arg3, Result> operator[](const Arg1 x) const {
    return bind1st(*this, x);
  }
  virtual Result operator()(Arg1 _a, Arg2 _b, Arg3 _c) const {
    return _fun(_a, _b, _c);
  }
};

template<typename Arg1, typename Arg2, typename Arg3, typename Result>
ternary_function<Arg1, Arg2, Arg3, Result> ptr_fun(Result (*_fun)(Arg1, Arg2, Arg3))
{
  return ternary_function<Arg1, Arg2, Arg3, Result>(_fun);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Result>
class quaternary_function
{
protected:
  Result (*_fun)(Arg1, Arg2, Arg3, Arg4);
public:
  quaternary_function() {}
  quaternary_function(Result (*func)(Arg1, Arg2, Arg3, Arg4)) : _fun(func) {}
  binder4arg1st<Arg1, Arg2, Arg3, Arg4, Result> operator[](const Arg1 x) const {
    return bind1st(*this, x);
  }
  virtual Result operator()(Arg1 _a, Arg2 _b, Arg3 _c, Arg4 _d) const {
    return _fun(_a, _b, _c, _d);
  }
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Result>
quaternary_function<Arg1, Arg2, Arg3, Arg4, Result> ptr_fun(Result (*_fun)(Arg1, Arg2, Arg3, Arg4))
{
  return quaternary_function<Arg1, Arg2, Arg3, Arg4, Result>(_fun);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Result>
class quinary_function
{
protected:
  Result (*_fun)(Arg1, Arg2, Arg3, Arg4, Arg5);
public:
  quinary_function() {}
  quinary_function(Result (*func)(Arg1, Arg2, Arg3, Arg4, Arg5)) : _fun(func) {}
  binder5arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Result> operator[](const Arg1 x) const {
    return bind1st(*this, x);
  }
  virtual Result operator()(Arg1 _a, Arg2 _b, Arg3 _c, Arg4 _d, Arg5 _e) const {
    return _fun(_a, _b, _c, _d, _e);
  }
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Result>
quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> ptr_fun(Result (*_fun)(Arg1, Arg2, Arg3, Arg4, Arg5))
{
  return quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result>(_fun);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
class senary_function
{
protected:
  Result (*_fun)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6);
public:
  senary_function() {}
  senary_function(Result (*func)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)) : _fun(func) {}
  binder6arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> operator[](const Arg1 x) const {
    return bind1st(*this, x);
  }
  virtual Result operator()(Arg1 _a, Arg2 _b, Arg3 _c, Arg4 _d, Arg5 _e, Arg6 _f) const {
    return _fun(_a, _b, _c, _d, _e, _f);
  }
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> ptr_fun(Result (*_fun)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6))
{
  return senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result>(_fun);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
class septenary_function
{
protected:
  Result (*_fun)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7);
public:
  septenary_function() {}
  septenary_function(Result (*func)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)) : _fun(func) {}
  binder7arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> operator[](const Arg1 x) const {
    return bind1st(*this, x);
  }
  virtual Result operator()(Arg1 _a, Arg2 _b, Arg3 _c, Arg4 _d, Arg5 _e, Arg6 _f, Arg7 _g) const {
    return _fun(_a, _b, _c, _d, _e, _f, _g);
  }
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> ptr_fun(Result (*_fun)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7))
{
  return septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result>(_fun);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
class octonary_function
{
protected:
  Result (*_fun)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8);
public:
  octonary_function() {}
  octonary_function(Result (*func)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)) : _fun(func) {}
  binder8arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> operator[](const Arg1 x) const {
    return bind1st(*this, x);
  }
  virtual Result operator()(Arg1 _a, Arg2 _b, Arg3 _c, Arg4 _d, Arg5 _e, Arg6 _f, Arg7 _g, Arg8 _h) const {
    return _fun(_a, _b, _c, _d, _e, _f, _g, _h);
  }
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> ptr_fun(Result (*_fun)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8))
{
  return octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result>(_fun);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
class novenary_function
{
protected:
  Result (*_fun)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9);
public:
  novenary_function() {}
  novenary_function(Result (*func)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)) : _fun(func) {}
  binder9arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> operator[](const Arg1 x) const {
    return bind1st(*this, x);
  }
  virtual Result operator()(Arg1 _a, Arg2 _b, Arg3 _c, Arg4 _d, Arg5 _e, Arg6 _f, Arg7 _g, Arg8 _h, Arg9 _i) const {
    return _fun(_a, _b, _c, _d, _e, _f, _g, _h, _i);
  }
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> ptr_fun(Result (*_fun)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9))
{
  return novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result>(_fun);
}

template<typename Result, typename Class>
class mem_fun0_t : public unary_function<Class*, Result> {
public:
  mem_fun0_t(Result (Class::*func)()) : mf(func) {}
  Result operator()(Class* p) const {
    return (p->*mf)();
  }
private:
  Result (Class::*mf)();
};

template<typename Result, typename Class>
mem_fun0_t<Result, Class> mem_fun(Result (Class::*_fun)())
{
  return mem_fun0_t<Result, Class>(_fun);
}

template<typename Result, typename Class, typename Arg1>
class mem_fun1_t : public binary_function<Class*, Arg1, Result> {
public:
  mem_fun1_t(Result (Class::*func)(Arg1)) : mf(func) {}
  Result operator()(Class* p, Arg1 _a) const {
    return (p->*mf)(_a);
  }
private:
  Result (Class::*mf)(Arg1);
};

template<typename Result, typename Class, typename Arg1>
mem_fun1_t<Result, Class, Arg1> mem_fun(Result (Class::*_fun)(Arg1))
{
  return mem_fun1_t<Result, Class, Arg1>(_fun);
}

template<typename Result, typename Class, typename Arg1, typename Arg2>
class mem_fun2_t : public ternary_function<Class*, Arg1, Arg2, Result> {
public:
  mem_fun2_t(Result (Class::*func)(Arg1, Arg2)) : mf(func) {}
  Result operator()(Class* p, Arg1 _a, Arg2 _b) const {
    return (p->*mf)(_a, _b);
  }
private:
  Result (Class::*mf)(Arg1, Arg2);
};

template<typename Result, typename Class, typename Arg1, typename Arg2>
mem_fun2_t<Result, Class, Arg1, Arg2> mem_fun(Result (Class::*_fun)(Arg1, Arg2))
{
  return mem_fun2_t<Result, Class, Arg1, Arg2>(_fun);
}

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3>
class mem_fun3_t : public quaternary_function<Class*, Arg1, Arg2, Arg3, Result> {
public:
  mem_fun3_t(Result (Class::*func)(Arg1, Arg2, Arg3)) : mf(func) {}
  Result operator()(Class* p, Arg1 _a, Arg2 _b, Arg3 _c) const {
    return (p->*mf)(_a, _b, _c);
  }
private:
  Result (Class::*mf)(Arg1, Arg2, Arg3);
};

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3>
mem_fun3_t<Result, Class, Arg1, Arg2, Arg3> mem_fun(Result (Class::*_fun)(Arg1, Arg2, Arg3))
{
  return mem_fun3_t<Result, Class, Arg1, Arg2, Arg3>(_fun);
}

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class mem_fun4_t : public quinary_function<Class*, Arg1, Arg2, Arg3, Arg4, Result> {
public:
  mem_fun4_t(Result (Class::*func)(Arg1, Arg2, Arg3, Arg4)) : mf(func) {}
  Result operator()(Class* p, Arg1 _a, Arg2 _b, Arg3 _c, Arg4 _d) const {
    return (p->*mf)(_a, _b, _c, _d);
  }
private:
  Result (Class::*mf)(Arg1, Arg2, Arg3, Arg4);
};

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
mem_fun4_t<Result, Class, Arg1, Arg2, Arg3, Arg4> mem_fun(Result (Class::*_fun)(Arg1, Arg2, Arg3, Arg4))
{
  return mem_fun4_t<Result, Class, Arg1, Arg2, Arg3, Arg4>(_fun);
}

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class mem_fun5_t : public senary_function<Class*, Arg1, Arg2, Arg3, Arg4, Arg5, Result> {
public:
  mem_fun5_t(Result (Class::*func)(Arg1, Arg2, Arg3, Arg4, Arg5)) : mf(func) {}
  Result operator()(Class* p, Arg1 _a, Arg2 _b, Arg3 _c, Arg4 _d, Arg5 _e) const {
    return (p->*mf)(_a, _b, _c, _d, _e);
  }
private:
  Result (Class::*mf)(Arg1, Arg2, Arg3, Arg4, Arg5);
};

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
mem_fun5_t<Result, Class, Arg1, Arg2, Arg3, Arg4, Arg5> mem_fun(Result (Class::*_fun)(Arg1, Arg2, Arg3, Arg4, Arg5))
{
  return mem_fun5_t<Result, Class, Arg1, Arg2, Arg3, Arg4, Arg5>(_fun);
}

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
class mem_fun6_t : public septenary_function<Class*, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> {
public:
  mem_fun6_t(Result (Class::*func)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)) : mf(func) {}
  Result operator()(Class* p, Arg1 _a, Arg2 _b, Arg3 _c, Arg4 _d, Arg5 _e, Arg6 _f) const {
    return (p->*mf)(_a, _b, _c, _d, _e, _f);
  }
private:
  Result (Class::*mf)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6);
};

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
mem_fun6_t<Result, Class, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> mem_fun(Result (Class::*_fun)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6))
{
  return mem_fun6_t<Result, Class, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>(_fun);
}

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
class mem_fun7_t : public octonary_function<Class*, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> {
public:
  mem_fun7_t(Result (Class::*func)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)) : mf(func) {}
  Result operator()(Class* p, Arg1 _a, Arg2 _b, Arg3 _c, Arg4 _d, Arg5 _e, Arg6 _f, Arg7 _g) const {
    return (p->*mf)(_a, _b, _c, _d, _e, _f, _g);
  }
private:
  Result (Class::*mf)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7);
};

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
mem_fun7_t<Result, Class, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> mem_fun(Result (Class::*_fun)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7))
{
  return mem_fun7_t<Result, Class, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7>(_fun);
}

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8>
class mem_fun8_t : public novenary_function<Class*, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> {
public:
  mem_fun8_t(Result (Class::*func)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)) : mf(func) {}
  Result operator()(Class* p, Arg1 _a, Arg2 _b, Arg3 _c, Arg4 _d, Arg5 _e, Arg6 _f, Arg7 _g, Arg8 _h) const {
    return (p->*mf)(_a, _b, _c, _d, _e, _f, _g, _h);
  }
private:
  Result (Class::*mf)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8);
};

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8>
mem_fun8_t<Result, Class, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8> mem_fun(Result (Class::*_fun)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8))
{
  return mem_fun8_t<Result, Class, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8>(_fun);
}

template<typename Arg1, typename Result>
class binder1arg1st : public nullary_function<Result> {
public:
  binder1arg1st(const unary_function<Arg1, Result> &x, const Arg1 &y) : op(x), value(y) {}
  Result operator()() const {
    return op(value);
  }
protected:
  const unary_function<Arg1, Result> &op;
  Arg1 value;
};

template<typename Arg1, typename Result>
binder1arg1st<Arg1, Result> bind1st(const unary_function<Arg1, Result> &fn, const Arg1 &_a)
{
  return binder1arg1st<Arg1, Result>(fn, _a);
}

template<typename Arg1, typename Arg2, typename Result>
class binder2arg1st : public unary_function<Arg2, Result> {
public:
  binder2arg1st(const binary_function<Arg1, Arg2, Result> &x, const Arg1 &y) : op(x), value(y) {}
  binder1arg1st<Arg2, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg2 _b) const {
    return op(value, _b);
  }
protected:
  const binary_function<Arg1, Arg2, Result> &op;
  Arg1 value;
};

template<typename Arg1, typename Arg2, typename Result>
binder2arg1st<Arg1, Arg2, Result> bind1st(const binary_function<Arg1, Arg2, Result> &fn, const Arg1 &_a)
{
  return binder2arg1st<Arg1, Arg2, Result>(fn, _a);
}

template<typename Arg1, typename Arg2, typename Result>
class binder2arg2nd : public unary_function<Arg1, Result> {
public:
  binder2arg2nd(const binary_function<Arg1, Arg2, Result> &x, const Arg2 &y) : op(x), value(y) {}
  binder1arg1st<Arg2, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a) const {
    return op(_a, value);
  }
protected:
  const binary_function<Arg1, Arg2, Result> &op;
  Arg2 value;
};

template<typename Arg1, typename Arg2, typename Result>
binder2arg2nd<Arg1, Arg2, Result> bind2nd(const binary_function<Arg1, Arg2, Result> &fn, const Arg2 &_b)
{
  return binder2arg2nd<Arg1, Arg2, Result>(fn, _b);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Result>
class binder3arg1st : public binary_function<Arg2, Arg3, Result> {
public:
  binder3arg1st(const ternary_function<Arg1, Arg2, Arg3, Result> &x, const Arg1 &y) : op(x), value(y) {}
  binder2arg1st<Arg2, Arg3, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg2 _b, const Arg3 _c) const {
    return op(value, _b, _c);
  }
protected:
  const ternary_function<Arg1, Arg2, Arg3, Result> &op;
  Arg1 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Result>
binder3arg1st<Arg1, Arg2, Arg3, Result> bind1st(const ternary_function<Arg1, Arg2, Arg3, Result> &fn, const Arg1 &_a)
{
  return binder3arg1st<Arg1, Arg2, Arg3, Result>(fn, _a);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Result>
class binder3arg2nd : public binary_function<Arg1, Arg3, Result> {
public:
  binder3arg2nd(const ternary_function<Arg1, Arg2, Arg3, Result> &x, const Arg2 &y) : op(x), value(y) {}
  binder2arg1st<Arg2, Arg3, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg3 _c) const {
    return op(_a, value, _c);
  }
protected:
  const ternary_function<Arg1, Arg2, Arg3, Result> &op;
  Arg2 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Result>
binder3arg2nd<Arg1, Arg2, Arg3, Result> bind2nd(const ternary_function<Arg1, Arg2, Arg3, Result> &fn, const Arg2 &_b)
{
  return binder3arg2nd<Arg1, Arg2, Arg3, Result>(fn, _b);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Result>
class binder3arg3rd : public binary_function<Arg1, Arg2, Result> {
public:
  binder3arg3rd(const ternary_function<Arg1, Arg2, Arg3, Result> &x, const Arg3 &y) : op(x), value(y) {}
  binder2arg1st<Arg2, Arg3, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b) const {
    return op(_a, _b, value);
  }
protected:
  const ternary_function<Arg1, Arg2, Arg3, Result> &op;
  Arg3 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Result>
binder3arg3rd<Arg1, Arg2, Arg3, Result> bind3rd(const ternary_function<Arg1, Arg2, Arg3, Result> &fn, const Arg3 &_c)
{
  return binder3arg3rd<Arg1, Arg2, Arg3, Result>(fn, _c);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Result>
class binder4arg1st : public ternary_function<Arg2, Arg3, Arg4, Result> {
public:
  binder4arg1st(const quaternary_function<Arg1, Arg2, Arg3, Arg4, Result> &x, const Arg1 &y) : op(x), value(y) {}
  binder3arg1st<Arg2, Arg3, Arg4, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg2 _b, const Arg3 _c, const Arg4 _d) const {
    return op(value, _b, _c, _d);
  }
protected:
  const quaternary_function<Arg1, Arg2, Arg3, Arg4, Result> &op;
  Arg1 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Result>
binder4arg1st<Arg1, Arg2, Arg3, Arg4, Result> bind1st(const quaternary_function<Arg1, Arg2, Arg3, Arg4, Result> &fn, const Arg1 &_a)
{
  return binder4arg1st<Arg1, Arg2, Arg3, Arg4, Result>(fn, _a);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Result>
class binder4arg2nd : public ternary_function<Arg1, Arg3, Arg4, Result> {
public:
  binder4arg2nd(const quaternary_function<Arg1, Arg2, Arg3, Arg4, Result> &x, const Arg2 &y) : op(x), value(y) {}
  binder3arg1st<Arg2, Arg3, Arg4, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg3 _c, const Arg4 _d) const {
    return op(_a, value, _c, _d);
  }
protected:
  const quaternary_function<Arg1, Arg2, Arg3, Arg4, Result> &op;
  Arg2 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Result>
binder4arg2nd<Arg1, Arg2, Arg3, Arg4, Result> bind2nd(const quaternary_function<Arg1, Arg2, Arg3, Arg4, Result> &fn, const Arg2 &_b)
{
  return binder4arg2nd<Arg1, Arg2, Arg3, Arg4, Result>(fn, _b);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Result>
class binder4arg3rd : public ternary_function<Arg1, Arg2, Arg4, Result> {
public:
  binder4arg3rd(const quaternary_function<Arg1, Arg2, Arg3, Arg4, Result> &x, const Arg3 &y) : op(x), value(y) {}
  binder3arg1st<Arg2, Arg3, Arg4, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg4 _d) const {
    return op(_a, _b, value, _d);
  }
protected:
  const quaternary_function<Arg1, Arg2, Arg3, Arg4, Result> &op;
  Arg3 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Result>
binder4arg3rd<Arg1, Arg2, Arg3, Arg4, Result> bind3rd(const quaternary_function<Arg1, Arg2, Arg3, Arg4, Result> &fn, const Arg3 &_c)
{
  return binder4arg3rd<Arg1, Arg2, Arg3, Arg4, Result>(fn, _c);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Result>
class binder4arg4th : public ternary_function<Arg1, Arg2, Arg3, Result> {
public:
  binder4arg4th(const quaternary_function<Arg1, Arg2, Arg3, Arg4, Result> &x, const Arg4 &y) : op(x), value(y) {}
  binder3arg1st<Arg2, Arg3, Arg4, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c) const {
    return op(_a, _b, _c, value);
  }
protected:
  const quaternary_function<Arg1, Arg2, Arg3, Arg4, Result> &op;
  Arg4 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Result>
binder4arg4th<Arg1, Arg2, Arg3, Arg4, Result> bind4th(const quaternary_function<Arg1, Arg2, Arg3, Arg4, Result> &fn, const Arg4 &_d)
{
  return binder4arg4th<Arg1, Arg2, Arg3, Arg4, Result>(fn, _d);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Result>
class binder5arg1st : public quaternary_function<Arg2, Arg3, Arg4, Arg5, Result> {
public:
  binder5arg1st(const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &x, const Arg1 &y) : op(x), value(y) {}
  binder4arg1st<Arg2, Arg3, Arg4, Arg5, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e) const {
    return op(value, _b, _c, _d, _e);
  }
protected:
  const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &op;
  Arg1 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Result>
binder5arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Result> bind1st(const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &fn, const Arg1 &_a)
{
  return binder5arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Result>(fn, _a);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Result>
class binder5arg2nd : public quaternary_function<Arg1, Arg3, Arg4, Arg5, Result> {
public:
  binder5arg2nd(const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &x, const Arg2 &y) : op(x), value(y) {}
  binder4arg1st<Arg2, Arg3, Arg4, Arg5, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg3 _c, const Arg4 _d, const Arg5 _e) const {
    return op(_a, value, _c, _d, _e);
  }
protected:
  const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &op;
  Arg2 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Result>
binder5arg2nd<Arg1, Arg2, Arg3, Arg4, Arg5, Result> bind2nd(const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &fn, const Arg2 &_b)
{
  return binder5arg2nd<Arg1, Arg2, Arg3, Arg4, Arg5, Result>(fn, _b);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Result>
class binder5arg3rd : public quaternary_function<Arg1, Arg2, Arg4, Arg5, Result> {
public:
  binder5arg3rd(const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &x, const Arg3 &y) : op(x), value(y) {}
  binder4arg1st<Arg2, Arg3, Arg4, Arg5, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg4 _d, const Arg5 _e) const {
    return op(_a, _b, value, _d, _e);
  }
protected:
  const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &op;
  Arg3 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Result>
binder5arg3rd<Arg1, Arg2, Arg3, Arg4, Arg5, Result> bind3rd(const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &fn, const Arg3 &_c)
{
  return binder5arg3rd<Arg1, Arg2, Arg3, Arg4, Arg5, Result>(fn, _c);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Result>
class binder5arg4th : public quaternary_function<Arg1, Arg2, Arg3, Arg5, Result> {
public:
  binder5arg4th(const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &x, const Arg4 &y) : op(x), value(y) {}
  binder4arg1st<Arg2, Arg3, Arg4, Arg5, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg5 _e) const {
    return op(_a, _b, _c, value, _e);
  }
protected:
  const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &op;
  Arg4 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Result>
binder5arg4th<Arg1, Arg2, Arg3, Arg4, Arg5, Result> bind4th(const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &fn, const Arg4 &_d)
{
  return binder5arg4th<Arg1, Arg2, Arg3, Arg4, Arg5, Result>(fn, _d);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Result>
class binder5arg5th : public quaternary_function<Arg1, Arg2, Arg3, Arg4, Result> {
public:
  binder5arg5th(const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &x, const Arg5 &y) : op(x), value(y) {}
  binder4arg1st<Arg2, Arg3, Arg4, Arg5, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d) const {
    return op(_a, _b, _c, _d, value);
  }
protected:
  const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &op;
  Arg5 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Result>
binder5arg5th<Arg1, Arg2, Arg3, Arg4, Arg5, Result> bind5th(const quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> &fn, const Arg5 &_e)
{
  return binder5arg5th<Arg1, Arg2, Arg3, Arg4, Arg5, Result>(fn, _e);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
class binder6arg1st : public quinary_function<Arg2, Arg3, Arg4, Arg5, Arg6, Result> {
public:
  binder6arg1st(const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &x, const Arg1 &y) : op(x), value(y) {}
  binder5arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg6 _f) const {
    return op(value, _b, _c, _d, _e, _f);
  }
protected:
  const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &op;
  Arg1 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
binder6arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> bind1st(const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &fn, const Arg1 &_a)
{
  return binder6arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result>(fn, _a);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
class binder6arg2nd : public quinary_function<Arg1, Arg3, Arg4, Arg5, Arg6, Result> {
public:
  binder6arg2nd(const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &x, const Arg2 &y) : op(x), value(y) {}
  binder5arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg6 _f) const {
    return op(_a, value, _c, _d, _e, _f);
  }
protected:
  const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &op;
  Arg2 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
binder6arg2nd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> bind2nd(const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &fn, const Arg2 &_b)
{
  return binder6arg2nd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result>(fn, _b);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
class binder6arg3rd : public quinary_function<Arg1, Arg2, Arg4, Arg5, Arg6, Result> {
public:
  binder6arg3rd(const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &x, const Arg3 &y) : op(x), value(y) {}
  binder5arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg4 _d, const Arg5 _e, const Arg6 _f) const {
    return op(_a, _b, value, _d, _e, _f);
  }
protected:
  const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &op;
  Arg3 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
binder6arg3rd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> bind3rd(const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &fn, const Arg3 &_c)
{
  return binder6arg3rd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result>(fn, _c);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
class binder6arg4th : public quinary_function<Arg1, Arg2, Arg3, Arg5, Arg6, Result> {
public:
  binder6arg4th(const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &x, const Arg4 &y) : op(x), value(y) {}
  binder5arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg5 _e, const Arg6 _f) const {
    return op(_a, _b, _c, value, _e, _f);
  }
protected:
  const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &op;
  Arg4 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
binder6arg4th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> bind4th(const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &fn, const Arg4 &_d)
{
  return binder6arg4th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result>(fn, _d);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
class binder6arg5th : public quinary_function<Arg1, Arg2, Arg3, Arg4, Arg6, Result> {
public:
  binder6arg5th(const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &x, const Arg5 &y) : op(x), value(y) {}
  binder5arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg6 _f) const {
    return op(_a, _b, _c, _d, value, _f);
  }
protected:
  const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &op;
  Arg5 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
binder6arg5th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> bind5th(const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &fn, const Arg5 &_e)
{
  return binder6arg5th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result>(fn, _e);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
class binder6arg6th : public quinary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Result> {
public:
  binder6arg6th(const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &x, const Arg6 &y) : op(x), value(y) {}
  binder5arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e) const {
    return op(_a, _b, _c, _d, _e, value);
  }
protected:
  const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &op;
  Arg6 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Result>
binder6arg6th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> bind6th(const senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> &fn, const Arg6 &_f)
{
  return binder6arg6th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result>(fn, _f);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
class binder7arg1st : public senary_function<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> {
public:
  binder7arg1st(const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &x, const Arg1 &y) : op(x), value(y) {}
  binder6arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg6 _f, const Arg7 _g) const {
    return op(value, _b, _c, _d, _e, _f, _g);
  }
protected:
  const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &op;
  Arg1 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
binder7arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> bind1st(const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &fn, const Arg1 &_a)
{
  return binder7arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result>(fn, _a);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
class binder7arg2nd : public senary_function<Arg1, Arg3, Arg4, Arg5, Arg6, Arg7, Result> {
public:
  binder7arg2nd(const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &x, const Arg2 &y) : op(x), value(y) {}
  binder6arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg6 _f, const Arg7 _g) const {
    return op(_a, value, _c, _d, _e, _f, _g);
  }
protected:
  const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &op;
  Arg2 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
binder7arg2nd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> bind2nd(const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &fn, const Arg2 &_b)
{
  return binder7arg2nd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result>(fn, _b);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
class binder7arg3rd : public senary_function<Arg1, Arg2, Arg4, Arg5, Arg6, Arg7, Result> {
public:
  binder7arg3rd(const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &x, const Arg3 &y) : op(x), value(y) {}
  binder6arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg4 _d, const Arg5 _e, const Arg6 _f, const Arg7 _g) const {
    return op(_a, _b, value, _d, _e, _f, _g);
  }
protected:
  const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &op;
  Arg3 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
binder7arg3rd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> bind3rd(const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &fn, const Arg3 &_c)
{
  return binder7arg3rd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result>(fn, _c);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
class binder7arg4th : public senary_function<Arg1, Arg2, Arg3, Arg5, Arg6, Arg7, Result> {
public:
  binder7arg4th(const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &x, const Arg4 &y) : op(x), value(y) {}
  binder6arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg5 _e, const Arg6 _f, const Arg7 _g) const {
    return op(_a, _b, _c, value, _e, _f, _g);
  }
protected:
  const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &op;
  Arg4 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
binder7arg4th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> bind4th(const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &fn, const Arg4 &_d)
{
  return binder7arg4th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result>(fn, _d);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
class binder7arg5th : public senary_function<Arg1, Arg2, Arg3, Arg4, Arg6, Arg7, Result> {
public:
  binder7arg5th(const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &x, const Arg5 &y) : op(x), value(y) {}
  binder6arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg6 _f, const Arg7 _g) const {
    return op(_a, _b, _c, _d, value, _f, _g);
  }
protected:
  const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &op;
  Arg5 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
binder7arg5th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> bind5th(const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &fn, const Arg5 &_e)
{
  return binder7arg5th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result>(fn, _e);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
class binder7arg6th : public senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg7, Result> {
public:
  binder7arg6th(const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &x, const Arg6 &y) : op(x), value(y) {}
  binder6arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg7 _g) const {
    return op(_a, _b, _c, _d, _e, value, _g);
  }
protected:
  const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &op;
  Arg6 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
binder7arg6th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> bind6th(const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &fn, const Arg6 &_f)
{
  return binder7arg6th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result>(fn, _f);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
class binder7arg7th : public senary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> {
public:
  binder7arg7th(const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &x, const Arg7 &y) : op(x), value(y) {}
  binder6arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg6 _f) const {
    return op(_a, _b, _c, _d, _e, _f, value);
  }
protected:
  const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &op;
  Arg7 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Result>
binder7arg7th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> bind7th(const septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> &fn, const Arg7 &_g)
{
  return binder7arg7th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result>(fn, _g);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
class binder8arg1st : public septenary_function<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> {
public:
  binder8arg1st(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &x, const Arg1 &y) : op(x), value(y) {}
  binder7arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg6 _f, const Arg7 _g, const Arg8 _h) const {
    return op(value, _b, _c, _d, _e, _f, _g, _h);
  }
protected:
  const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &op;
  Arg1 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
binder8arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> bind1st(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &fn, const Arg1 &_a)
{
  return binder8arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result>(fn, _a);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
class binder8arg2nd : public septenary_function<Arg1, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> {
public:
  binder8arg2nd(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &x, const Arg2 &y) : op(x), value(y) {}
  binder7arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg6 _f, const Arg7 _g, const Arg8 _h) const {
    return op(_a, value, _c, _d, _e, _f, _g, _h);
  }
protected:
  const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &op;
  Arg2 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
binder8arg2nd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> bind2nd(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &fn, const Arg2 &_b)
{
  return binder8arg2nd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result>(fn, _b);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
class binder8arg3rd : public septenary_function<Arg1, Arg2, Arg4, Arg5, Arg6, Arg7, Arg8, Result> {
public:
  binder8arg3rd(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &x, const Arg3 &y) : op(x), value(y) {}
  binder7arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg4 _d, const Arg5 _e, const Arg6 _f, const Arg7 _g, const Arg8 _h) const {
    return op(_a, _b, value, _d, _e, _f, _g, _h);
  }
protected:
  const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &op;
  Arg3 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
binder8arg3rd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> bind3rd(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &fn, const Arg3 &_c)
{
  return binder8arg3rd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result>(fn, _c);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
class binder8arg4th : public septenary_function<Arg1, Arg2, Arg3, Arg5, Arg6, Arg7, Arg8, Result> {
public:
  binder8arg4th(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &x, const Arg4 &y) : op(x), value(y) {}
  binder7arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg5 _e, const Arg6 _f, const Arg7 _g, const Arg8 _h) const {
    return op(_a, _b, _c, value, _e, _f, _g, _h);
  }
protected:
  const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &op;
  Arg4 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
binder8arg4th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> bind4th(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &fn, const Arg4 &_d)
{
  return binder8arg4th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result>(fn, _d);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
class binder8arg5th : public septenary_function<Arg1, Arg2, Arg3, Arg4, Arg6, Arg7, Arg8, Result> {
public:
  binder8arg5th(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &x, const Arg5 &y) : op(x), value(y) {}
  binder7arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg6 _f, const Arg7 _g, const Arg8 _h) const {
    return op(_a, _b, _c, _d, value, _f, _g, _h);
  }
protected:
  const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &op;
  Arg5 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
binder8arg5th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> bind5th(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &fn, const Arg5 &_e)
{
  return binder8arg5th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result>(fn, _e);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
class binder8arg6th : public septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg7, Arg8, Result> {
public:
  binder8arg6th(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &x, const Arg6 &y) : op(x), value(y) {}
  binder7arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg7 _g, const Arg8 _h) const {
    return op(_a, _b, _c, _d, _e, value, _g, _h);
  }
protected:
  const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &op;
  Arg6 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
binder8arg6th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> bind6th(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &fn, const Arg6 &_f)
{
  return binder8arg6th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result>(fn, _f);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
class binder8arg7th : public septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg8, Result> {
public:
  binder8arg7th(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &x, const Arg7 &y) : op(x), value(y) {}
  binder7arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg6 _f, const Arg8 _h) const {
    return op(_a, _b, _c, _d, _e, _f, value, _h);
  }
protected:
  const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &op;
  Arg7 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
binder8arg7th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> bind7th(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &fn, const Arg7 &_g)
{
  return binder8arg7th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result>(fn, _g);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
class binder8arg8th : public septenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> {
public:
  binder8arg8th(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &x, const Arg8 &y) : op(x), value(y) {}
  binder7arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg6 _f, const Arg7 _g) const {
    return op(_a, _b, _c, _d, _e, _f, _g, value);
  }
protected:
  const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &op;
  Arg8 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Result>
binder8arg8th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> bind8th(const octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> &fn, const Arg8 &_h)
{
  return binder8arg8th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result>(fn, _h);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
class binder9arg1st : public octonary_function<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> {
public:
  binder9arg1st(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &x, const Arg1 &y) : op(x), value(y) {}
  binder8arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg6 _f, const Arg7 _g, const Arg8 _h, const Arg9 _i) const {
    return op(value, _b, _c, _d, _e, _f, _g, _h, _i);
  }
protected:
  const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &op;
  Arg1 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
binder9arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> bind1st(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &fn, const Arg1 &_a)
{
  return binder9arg1st<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result>(fn, _a);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
class binder9arg2nd : public octonary_function<Arg1, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> {
public:
  binder9arg2nd(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &x, const Arg2 &y) : op(x), value(y) {}
  binder8arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg6 _f, const Arg7 _g, const Arg8 _h, const Arg9 _i) const {
    return op(_a, value, _c, _d, _e, _f, _g, _h, _i);
  }
protected:
  const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &op;
  Arg2 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
binder9arg2nd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> bind2nd(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &fn, const Arg2 &_b)
{
  return binder9arg2nd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result>(fn, _b);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
class binder9arg3rd : public octonary_function<Arg1, Arg2, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> {
public:
  binder9arg3rd(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &x, const Arg3 &y) : op(x), value(y) {}
  binder8arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg4 _d, const Arg5 _e, const Arg6 _f, const Arg7 _g, const Arg8 _h, const Arg9 _i) const {
    return op(_a, _b, value, _d, _e, _f, _g, _h, _i);
  }
protected:
  const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &op;
  Arg3 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
binder9arg3rd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> bind3rd(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &fn, const Arg3 &_c)
{
  return binder9arg3rd<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result>(fn, _c);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
class binder9arg4th : public octonary_function<Arg1, Arg2, Arg3, Arg5, Arg6, Arg7, Arg8, Arg9, Result> {
public:
  binder9arg4th(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &x, const Arg4 &y) : op(x), value(y) {}
  binder8arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg5 _e, const Arg6 _f, const Arg7 _g, const Arg8 _h, const Arg9 _i) const {
    return op(_a, _b, _c, value, _e, _f, _g, _h, _i);
  }
protected:
  const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &op;
  Arg4 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
binder9arg4th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> bind4th(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &fn, const Arg4 &_d)
{
  return binder9arg4th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result>(fn, _d);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
class binder9arg5th : public octonary_function<Arg1, Arg2, Arg3, Arg4, Arg6, Arg7, Arg8, Arg9, Result> {
public:
  binder9arg5th(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &x, const Arg5 &y) : op(x), value(y) {}
  binder8arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg6 _f, const Arg7 _g, const Arg8 _h, const Arg9 _i) const {
    return op(_a, _b, _c, _d, value, _f, _g, _h, _i);
  }
protected:
  const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &op;
  Arg5 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
binder9arg5th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> bind5th(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &fn, const Arg5 &_e)
{
  return binder9arg5th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result>(fn, _e);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
class binder9arg6th : public octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg7, Arg8, Arg9, Result> {
public:
  binder9arg6th(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &x, const Arg6 &y) : op(x), value(y) {}
  binder8arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg7 _g, const Arg8 _h, const Arg9 _i) const {
    return op(_a, _b, _c, _d, _e, value, _g, _h, _i);
  }
protected:
  const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &op;
  Arg6 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
binder9arg6th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> bind6th(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &fn, const Arg6 &_f)
{
  return binder9arg6th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result>(fn, _f);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
class binder9arg7th : public octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg8, Arg9, Result> {
public:
  binder9arg7th(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &x, const Arg7 &y) : op(x), value(y) {}
  binder8arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg6 _f, const Arg8 _h, const Arg9 _i) const {
    return op(_a, _b, _c, _d, _e, _f, value, _h, _i);
  }
protected:
  const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &op;
  Arg7 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
binder9arg7th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> bind7th(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &fn, const Arg7 &_g)
{
  return binder9arg7th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result>(fn, _g);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
class binder9arg8th : public octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg9, Result> {
public:
  binder9arg8th(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &x, const Arg8 &y) : op(x), value(y) {}
  binder8arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg6 _f, const Arg7 _g, const Arg9 _i) const {
    return op(_a, _b, _c, _d, _e, _f, _g, value, _i);
  }
protected:
  const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &op;
  Arg8 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
binder9arg8th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> bind8th(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &fn, const Arg8 &_h)
{
  return binder9arg8th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result>(fn, _h);
}

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
class binder9arg9th : public octonary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> {
public:
  binder9arg9th(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &x, const Arg9 &y) : op(x), value(y) {}
  binder8arg1st<Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> operator[](const Arg2 x) const {
    return bind1st(*this, x);
  }
  Result operator()(const Arg1 _a, const Arg2 _b, const Arg3 _c, const Arg4 _d, const Arg5 _e, const Arg6 _f, const Arg7 _g, const Arg8 _h) const {
    return op(_a, _b, _c, _d, _e, _f, _g, _h, value);
  }
protected:
  const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &op;
  Arg9 value;
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Result>
binder9arg9th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> bind9th(const novenary_function<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result> &fn, const Arg9 &_i)
{
  return binder9arg9th<Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Result>(fn, _i);
}

template<typename Result, typename Class, typename Arg1>
binder2arg1st<Class*, Arg1, Result> bindMemberFunc(Result (Class::*f)(Arg1), Class *c)
{
  static mem_fun1_t<Result, Class, Arg1> temp = mem_fun(f);
  return bind1st(temp, c);
}

template<typename Result, typename Class, typename Arg1, typename Arg2>
binder3arg1st<Class*, Arg1, Arg2, Result> bindMemberFunc(Result (Class::*f)(Arg1, Arg2), Class *c)
{
  static mem_fun2_t<Result, Class, Arg1, Arg2> temp = mem_fun(f);
  return bind1st(temp, c);
}

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3>
binder4arg1st<Class*, Arg1, Arg2, Arg3, Result> bindMemberFunc(Result (Class::*f)(Arg1, Arg2, Arg3), Class *c)
{
  static mem_fun3_t<Result, Class, Arg1, Arg2, Arg3> temp = mem_fun(f);
  return bind1st(temp, c);
}

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
binder5arg1st<Class*, Arg1, Arg2, Arg3, Arg4, Result> bindMemberFunc(Result (Class::*f)(Arg1, Arg2, Arg3, Arg4), Class *c)
{
  static mem_fun4_t<Result, Class, Arg1, Arg2, Arg3, Arg4> temp = mem_fun(f);
  return bind1st(temp, c);
}

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
binder6arg1st<Class*, Arg1, Arg2, Arg3, Arg4, Arg5, Result> bindMemberFunc(Result (Class::*f)(Arg1, Arg2, Arg3, Arg4, Arg5), Class *c)
{
  static mem_fun5_t<Result, Class, Arg1, Arg2, Arg3, Arg4, Arg5> temp = mem_fun(f);
  return bind1st(temp, c);
}

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
binder7arg1st<Class*, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Result> bindMemberFunc(Result (Class::*f)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6), Class *c)
{
  static mem_fun6_t<Result, Class, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> temp = mem_fun(f);
  return bind1st(temp, c);
}

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
binder8arg1st<Class*, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Result> bindMemberFunc(Result (Class::*f)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7), Class *c)
{
  static mem_fun7_t<Result, Class, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> temp = mem_fun(f);
  return bind1st(temp, c);
}

template<typename Result, typename Class, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8>
binder9arg1st<Class*, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Result> bindMemberFunc(Result (Class::*f)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8), Class *c)
{
  static mem_fun8_t<Result, Class, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8> temp = mem_fun(f);
  return bind1st(temp, c);
}

} //end of namespace

#endif