/**
 * Copyright 2017 Christoffer Ackelman
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * WARNING! This file was generated, do not modify it directly!
 */

#ifndef TUPLES_H
#define TUPLES_H

namespace Tuples {

template<typename T1>
struct unary_tuple
{
  T1 first;
  unary_tuple() {}
  unary_tuple(const T1 &t1) : first(t1) {}
  unary_tuple(const unary_tuple<T1> &p) : first(p.first) {}
  unary_tuple<T1>& operator=(const unary_tuple<T1> &p) {
    first = p.first;
    return *this;
  }
  bool operator<(const unary_tuple<T1> &p) const {
    if(first < p.first) return true;
    return false;
  }
};

template<typename T1>
unary_tuple<T1> tuple(const T1 &t1)
{
  return unary_tuple<T1>(t1);
}

template<typename T1, typename T2>
struct binary_tuple
{
  T1 first;
  T2 second;
  binary_tuple() {}
  binary_tuple(const T1 &t1, const T2 &t2) : first(t1), second(t2) {}
  binary_tuple(const binary_tuple<T1, T2> &p) : first(p.first), second(p.second) {}
  binary_tuple<T1, T2>& operator=(const binary_tuple<T1, T2> &p) {
    first = p.first;
    second = p.second;
    return *this;
  }
  bool operator<(const binary_tuple<T1, T2> &p) const {
    if(first < p.first) return true;
    if(second < p.second) return true;
    return false;
  }
};

template<typename T1, typename T2>
binary_tuple<T1, T2> tuple(const T1 &t1, const T2 &t2)
{
  return binary_tuple<T1, T2>(t1, t2);
}

template<typename T1, typename T2, typename T3>
struct ternary_tuple
{
  T1 first;
  T2 second;
  T3 third;
  ternary_tuple() {}
  ternary_tuple(const T1 &t1, const T2 &t2, const T3 &t3) : first(t1), second(t2), third(t3) {}
  ternary_tuple(const ternary_tuple<T1, T2, T3> &p) : first(p.first), second(p.second), third(p.third) {}
  ternary_tuple<T1, T2, T3>& operator=(const ternary_tuple<T1, T2, T3> &p) {
    first = p.first;
    second = p.second;
    third = p.third;
    return *this;
  }
  bool operator<(const ternary_tuple<T1, T2, T3> &p) const {
    if(first < p.first) return true;
    if(second < p.second) return true;
    if(third < p.third) return true;
    return false;
  }
};

template<typename T1, typename T2, typename T3>
ternary_tuple<T1, T2, T3> tuple(const T1 &t1, const T2 &t2, const T3 &t3)
{
  return ternary_tuple<T1, T2, T3>(t1, t2, t3);
}

template<typename T1, typename T2, typename T3, typename T4>
struct quaternary_tuple
{
  T1 first;
  T2 second;
  T3 third;
  T4 fourth;
  quaternary_tuple() {}
  quaternary_tuple(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4) : first(t1), second(t2), third(t3), fourth(t4) {}
  quaternary_tuple(const quaternary_tuple<T1, T2, T3, T4> &p) : first(p.first), second(p.second), third(p.third), fourth(p.fourth) {}
  quaternary_tuple<T1, T2, T3, T4>& operator=(const quaternary_tuple<T1, T2, T3, T4> &p) {
    first = p.first;
    second = p.second;
    third = p.third;
    fourth = p.fourth;
    return *this;
  }
  bool operator<(const quaternary_tuple<T1, T2, T3, T4> &p) const {
    if(first < p.first) return true;
    if(second < p.second) return true;
    if(third < p.third) return true;
    if(fourth < p.fourth) return true;
    return false;
  }
};

template<typename T1, typename T2, typename T3, typename T4>
quaternary_tuple<T1, T2, T3, T4> tuple(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4)
{
  return quaternary_tuple<T1, T2, T3, T4>(t1, t2, t3, t4);
}

template<typename T1, typename T2, typename T3, typename T4, typename T5>
struct quinary_tuple
{
  T1 first;
  T2 second;
  T3 third;
  T4 fourth;
  T5 fifth;
  quinary_tuple() {}
  quinary_tuple(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4, const T5 &t5) : first(t1), second(t2), third(t3), fourth(t4), fifth(t5) {}
  quinary_tuple(const quinary_tuple<T1, T2, T3, T4, T5> &p) : first(p.first), second(p.second), third(p.third), fourth(p.fourth), fifth(p.fifth) {}
  quinary_tuple<T1, T2, T3, T4, T5>& operator=(const quinary_tuple<T1, T2, T3, T4, T5> &p) {
    first = p.first;
    second = p.second;
    third = p.third;
    fourth = p.fourth;
    fifth = p.fifth;
    return *this;
  }
  bool operator<(const quinary_tuple<T1, T2, T3, T4, T5> &p) const {
    if(first < p.first) return true;
    if(second < p.second) return true;
    if(third < p.third) return true;
    if(fourth < p.fourth) return true;
    if(fifth < p.fifth) return true;
    return false;
  }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5>
quinary_tuple<T1, T2, T3, T4, T5> tuple(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4, const T5 &t5)
{
  return quinary_tuple<T1, T2, T3, T4, T5>(t1, t2, t3, t4, t5);
}

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
struct senary_tuple
{
  T1 first;
  T2 second;
  T3 third;
  T4 fourth;
  T5 fifth;
  T6 sixth;
  senary_tuple() {}
  senary_tuple(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4, const T5 &t5, const T6 &t6) : first(t1), second(t2), third(t3), fourth(t4), fifth(t5), sixth(t6) {}
  senary_tuple(const senary_tuple<T1, T2, T3, T4, T5, T6> &p) : first(p.first), second(p.second), third(p.third), fourth(p.fourth), fifth(p.fifth), sixth(p.sixth) {}
  senary_tuple<T1, T2, T3, T4, T5, T6>& operator=(const senary_tuple<T1, T2, T3, T4, T5, T6> &p) {
    first = p.first;
    second = p.second;
    third = p.third;
    fourth = p.fourth;
    fifth = p.fifth;
    sixth = p.sixth;
    return *this;
  }
  bool operator<(const senary_tuple<T1, T2, T3, T4, T5, T6> &p) const {
    if(first < p.first) return true;
    if(second < p.second) return true;
    if(third < p.third) return true;
    if(fourth < p.fourth) return true;
    if(fifth < p.fifth) return true;
    if(sixth < p.sixth) return true;
    return false;
  }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
senary_tuple<T1, T2, T3, T4, T5, T6> tuple(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4, const T5 &t5, const T6 &t6)
{
  return senary_tuple<T1, T2, T3, T4, T5, T6>(t1, t2, t3, t4, t5, t6);
}

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
struct septenary_tuple
{
  T1 first;
  T2 second;
  T3 third;
  T4 fourth;
  T5 fifth;
  T6 sixth;
  T7 seventh;
  septenary_tuple() {}
  septenary_tuple(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4, const T5 &t5, const T6 &t6, const T7 &t7) : first(t1), second(t2), third(t3), fourth(t4), fifth(t5), sixth(t6), seventh(t7) {}
  septenary_tuple(const septenary_tuple<T1, T2, T3, T4, T5, T6, T7> &p) : first(p.first), second(p.second), third(p.third), fourth(p.fourth), fifth(p.fifth), sixth(p.sixth), seventh(p.seventh) {}
  septenary_tuple<T1, T2, T3, T4, T5, T6, T7>& operator=(const septenary_tuple<T1, T2, T3, T4, T5, T6, T7> &p) {
    first = p.first;
    second = p.second;
    third = p.third;
    fourth = p.fourth;
    fifth = p.fifth;
    sixth = p.sixth;
    seventh = p.seventh;
    return *this;
  }
  bool operator<(const septenary_tuple<T1, T2, T3, T4, T5, T6, T7> &p) const {
    if(first < p.first) return true;
    if(second < p.second) return true;
    if(third < p.third) return true;
    if(fourth < p.fourth) return true;
    if(fifth < p.fifth) return true;
    if(sixth < p.sixth) return true;
    if(seventh < p.seventh) return true;
    return false;
  }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
septenary_tuple<T1, T2, T3, T4, T5, T6, T7> tuple(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4, const T5 &t5, const T6 &t6, const T7 &t7)
{
  return septenary_tuple<T1, T2, T3, T4, T5, T6, T7>(t1, t2, t3, t4, t5, t6, t7);
}

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
struct octonary_tuple
{
  T1 first;
  T2 second;
  T3 third;
  T4 fourth;
  T5 fifth;
  T6 sixth;
  T7 seventh;
  T8 eighth;
  octonary_tuple() {}
  octonary_tuple(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4, const T5 &t5, const T6 &t6, const T7 &t7, const T8 &t8) : first(t1), second(t2), third(t3), fourth(t4), fifth(t5), sixth(t6), seventh(t7), eighth(t8) {}
  octonary_tuple(const octonary_tuple<T1, T2, T3, T4, T5, T6, T7, T8> &p) : first(p.first), second(p.second), third(p.third), fourth(p.fourth), fifth(p.fifth), sixth(p.sixth), seventh(p.seventh), eighth(p.eighth) {}
  octonary_tuple<T1, T2, T3, T4, T5, T6, T7, T8>& operator=(const octonary_tuple<T1, T2, T3, T4, T5, T6, T7, T8> &p) {
    first = p.first;
    second = p.second;
    third = p.third;
    fourth = p.fourth;
    fifth = p.fifth;
    sixth = p.sixth;
    seventh = p.seventh;
    eighth = p.eighth;
    return *this;
  }
  bool operator<(const octonary_tuple<T1, T2, T3, T4, T5, T6, T7, T8> &p) const {
    if(first < p.first) return true;
    if(second < p.second) return true;
    if(third < p.third) return true;
    if(fourth < p.fourth) return true;
    if(fifth < p.fifth) return true;
    if(sixth < p.sixth) return true;
    if(seventh < p.seventh) return true;
    if(eighth < p.eighth) return true;
    return false;
  }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
octonary_tuple<T1, T2, T3, T4, T5, T6, T7, T8> tuple(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4, const T5 &t5, const T6 &t6, const T7 &t7, const T8 &t8)
{
  return octonary_tuple<T1, T2, T3, T4, T5, T6, T7, T8>(t1, t2, t3, t4, t5, t6, t7, t8);
}

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
struct novenary_tuple
{
  T1 first;
  T2 second;
  T3 third;
  T4 fourth;
  T5 fifth;
  T6 sixth;
  T7 seventh;
  T8 eighth;
  T9 ninth;
  novenary_tuple() {}
  novenary_tuple(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4, const T5 &t5, const T6 &t6, const T7 &t7, const T8 &t8, const T9 &t9) : first(t1), second(t2), third(t3), fourth(t4), fifth(t5), sixth(t6), seventh(t7), eighth(t8), ninth(t9) {}
  novenary_tuple(const novenary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9> &p) : first(p.first), second(p.second), third(p.third), fourth(p.fourth), fifth(p.fifth), sixth(p.sixth), seventh(p.seventh), eighth(p.eighth), ninth(p.ninth) {}
  novenary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9>& operator=(const novenary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9> &p) {
    first = p.first;
    second = p.second;
    third = p.third;
    fourth = p.fourth;
    fifth = p.fifth;
    sixth = p.sixth;
    seventh = p.seventh;
    eighth = p.eighth;
    ninth = p.ninth;
    return *this;
  }
  bool operator<(const novenary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9> &p) const {
    if(first < p.first) return true;
    if(second < p.second) return true;
    if(third < p.third) return true;
    if(fourth < p.fourth) return true;
    if(fifth < p.fifth) return true;
    if(sixth < p.sixth) return true;
    if(seventh < p.seventh) return true;
    if(eighth < p.eighth) return true;
    if(ninth < p.ninth) return true;
    return false;
  }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
novenary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9> tuple(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4, const T5 &t5, const T6 &t6, const T7 &t7, const T8 &t8, const T9 &t9)
{
  return novenary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9>(t1, t2, t3, t4, t5, t6, t7, t8, t9);
}

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
struct denary_tuple
{
  T1 first;
  T2 second;
  T3 third;
  T4 fourth;
  T5 fifth;
  T6 sixth;
  T7 seventh;
  T8 eighth;
  T9 ninth;
  T10 tenth;
  denary_tuple() {}
  denary_tuple(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4, const T5 &t5, const T6 &t6, const T7 &t7, const T8 &t8, const T9 &t9, const T10 &t10) : first(t1), second(t2), third(t3), fourth(t4), fifth(t5), sixth(t6), seventh(t7), eighth(t8), ninth(t9), tenth(t10) {}
  denary_tuple(const denary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> &p) : first(p.first), second(p.second), third(p.third), fourth(p.fourth), fifth(p.fifth), sixth(p.sixth), seventh(p.seventh), eighth(p.eighth), ninth(p.ninth), tenth(p.tenth) {}
  denary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>& operator=(const denary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> &p) {
    first = p.first;
    second = p.second;
    third = p.third;
    fourth = p.fourth;
    fifth = p.fifth;
    sixth = p.sixth;
    seventh = p.seventh;
    eighth = p.eighth;
    ninth = p.ninth;
    tenth = p.tenth;
    return *this;
  }
  bool operator<(const denary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> &p) const {
    if(first < p.first) return true;
    if(second < p.second) return true;
    if(third < p.third) return true;
    if(fourth < p.fourth) return true;
    if(fifth < p.fifth) return true;
    if(sixth < p.sixth) return true;
    if(seventh < p.seventh) return true;
    if(eighth < p.eighth) return true;
    if(ninth < p.ninth) return true;
    if(tenth < p.tenth) return true;
    return false;
  }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
denary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> tuple(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4, const T5 &t5, const T6 &t6, const T7 &t7, const T8 &t8, const T9 &t9, const T10 &t10)
{
  return denary_tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10);
}

} //end of namespace

#endif