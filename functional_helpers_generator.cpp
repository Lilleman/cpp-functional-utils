/**
 * Copyright 2017 Christoffer Ackelman
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

string getName(int arity) {
  string names[] = {"nullary", "unary", "binary", "ternary", "quaternary", "quinary", "senary", "septenary", "octonary", "novenary", "denary"};
  return names[arity];
}

char getLetter(int arity) {
  return 'a' + arity;
}

string getOrdinal(int num) {
  stringstream ss;
  string endings[] = {"st", "nd", "rd", "th", "th", "th", "th", "th", "th", "th", "th"};
  ss << num << endings[num - 1];
  return ss.str();
}

void genLicence(ofstream &file) {
  file << "/**\n";
  file << " * Copyright 2017 Christoffer Ackelman\n";
  file << " *\n";
  file << " * This Source Code Form is subject to the terms of the Mozilla Public\n";
  file << " * License, v. 2.0. If a copy of the MPL was not distributed with this\n";
  file << " * file, You can obtain one at http://mozilla.org/MPL/2.0/.\n";
  file << " *\n";
  file << " * WARNING! This file was generated, do not modify it directly!\n";
  file << " */\n\n";
}

void generateHeaders(ofstream &file, int arity) {
  stringstream buf;
  buf << "template<";
  for (int i = 0; i < arity; i++) {
    buf << "typename Arg" << (i + 1) << ", ";
  }
  buf << "typename Result>\n";

  buf << "class binder" << arity << "arg1st;\n\n";

  file << buf.str();
}

void genClass(ofstream &file, int arity) {
  stringstream buf;
  buf << "template<";
  for (int i = 0; i < arity; i++) {
    buf << "typename Arg" << (i + 1) << ", ";
  }
  buf << "typename Result>\n";

  buf << "class " << getName(arity) << "_function\n";

  buf << "{\n";

  buf << "protected:\n";

  buf << "  Result (*_fun)(";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ");\n";

  buf << "public:\n";

  buf << "  " << getName(arity) << "_function() {}\n";

  buf << "  " << getName(arity) << "_function(Result (*func)(";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ")) : _fun(func) {}\n";

  if (arity > 0) {
    buf << "  binder" << arity << "arg1st<";
    for (int i = 0; i < arity; i++) {
      buf << "Arg" << (i + 1) << ", ";
    }
    buf << "Result> operator[](const Arg1 x) const {\n";

    buf << "    return bind1st(*this, x);\n";

    buf << "  }\n";
  }

  buf << "  virtual Result operator()(";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1) << " _" << getLetter(i);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ") const {\n";

  buf << "    return _fun(";
  for (int i = 0; i < arity; i++) {
    buf << '_' << getLetter(i);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ");\n";

  buf << "  }\n";

  buf << "};\n\n";

  file << buf.str();
}

void genPtrFun(ofstream &file, int arity) {
  stringstream buf;
  buf << "template<";
  for (int i = 0; i < arity; i++) {
    buf << "typename Arg" << (i + 1) << ", ";
  }
  buf << "typename Result>\n";

  buf << getName(arity) << "_function<";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1) << ", ";
  }
  buf << "Result> ptr_fun(Result (*_fun)(";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << "))\n";

  buf << "{\n";

  buf << "  return " << getName(arity) << "_function<";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1) << ", ";
  }
  buf << "Result>(_fun);\n";

  buf << "}\n\n";

  file << buf.str();
}

void genMemFunClass(ofstream &file, int arity) {
  stringstream buf;
  buf << "template<typename Result, typename Class";
  for (int i = 0; i < arity; i++) {
    buf << ", typename Arg" << (i + 1);
  }
  buf << ">\n";

  buf << "class mem_fun" << arity << "_t : public " << getName(arity + 1) << "_function<Class*";
  for (int i = 0; i < arity; i++) {
    buf << ", Arg" << (i + 1);
  }
  buf << ", Result> {\n"; 

  buf << "public:\n";

  buf << "  mem_fun" << arity << "_t(Result (Class::*func)(";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ")) : mf(func) {}\n";

  buf << "  Result operator()(Class* p";
  for (int i = 0; i < arity; i++) {
    buf << ", Arg" << (i + 1) << " _" << getLetter(i);
  }
  buf << ") const {\n";

  buf << "    return (p->*mf)(";
  for (int i = 0; i < arity; i++) {
    buf << '_' << getLetter(i);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ");\n";

  buf << "  }\n";

  buf << "private:\n";

  buf << "  Result (Class::*mf)(";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ");\n";

  buf << "};\n\n";

  file << buf.str();
}

void genMemFun(ofstream &file, int arity) {
  stringstream buf;
  buf << "template<typename Result, typename Class";
  for (int i = 0; i < arity; i++) {
    buf << ", typename Arg" << (i + 1);
  }
  buf << ">\n";

  buf << "mem_fun" << arity << "_t<Result, Class";
  for (int i = 0; i < arity; i++) {
    buf << ", Arg" << (i + 1);
  }
  buf << "> mem_fun(Result (Class::*_fun)(";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << "))\n";

  buf << "{\n";

  buf << "  return mem_fun" << arity << "_t<Result, Class";
  for (int i = 0; i < arity; i++) {
    buf << ", Arg" << (i + 1);
  }
  buf << ">(_fun);\n";

  buf << "}\n\n";

  file << buf.str();
}

void genBinderClasses(ofstream &file, int arity, int bindArg) {
  stringstream buf;

  buf << "template<";
  for (int i = 0; i < arity; i++) {
    buf << "typename Arg" << (i + 1) << ", ";
  }
  buf << "typename Result>\n";

  buf << "class binder" << arity << "arg" << getOrdinal(bindArg) << " : public " << getName(arity - 1) << "_function<";
  for (int i = 0; i < arity; i++) {
    if (i != bindArg - 1) {
      buf << "Arg" << (i + 1);
      if (i < arity) {
        buf << ", ";
      }
    }
  }
  buf << "Result> {\n"; 

  buf << "public:\n";

  buf << "  binder" << arity << "arg" << getOrdinal(bindArg) << "(const " << getName(arity) << "_function<";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1) << ", ";
  }
  buf << "Result> &x, const Arg" << bindArg << " &y) : op(x), value(y) {}\n";

  if (arity > 1) {
    buf << "  binder" << (arity - 1) << "arg1st<";
    for (int i = 1; i < arity; i++) {
      buf << "Arg" << (i + 1) << ", ";
    }
    buf << "Result> operator[](const Arg2 x) const {\n";

    buf << "    return bind1st(*this, x);\n";

    buf << "  }\n";
  }

  buf << "  Result operator()(";
  for (int i = 0; i < arity; i++) {
    if (i != bindArg - 1) {
      if (i > 0 && !(i == 1 && bindArg == 1)) {
        buf << ", ";
      }
      buf << "const Arg" << (i + 1) << " _" << getLetter(i);
    }
  }
  buf << ") const {\n";

  buf << "    return op(";
  for (int i = 0; i < arity; i++) {
    if (i == bindArg - 1) {
      buf << "value";
    } else {
      buf << '_' << getLetter(i);
    }
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ");\n";

  buf << "  }\n";

  buf << "protected:\n";

  buf << "  const " << getName(arity) << "_function<";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1) << ", ";
  }
  buf << "Result> &op;\n";

  buf << "  Arg" << bindArg << " value;\n";

  buf << "};\n\n";

  file << buf.str();
}

void genBinders(ofstream &file, int arity, int bindArg) {
  stringstream buf;
  buf << "template<";
  for (int i = 0; i < arity; i++) {
    buf << "typename Arg" << (i + 1) << ", ";
  }
  buf << "typename Result>\n";

  buf << "binder" << arity << "arg" << getOrdinal(bindArg) << "<";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1) << ", ";
  }
  buf << "Result> bind" << getOrdinal(bindArg) << "(const " << getName(arity) << "_function<";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1) << ", ";
  }
  buf << "Result> &fn, const Arg" << bindArg << " &_" << getLetter(bindArg - 1) << ")\n";

  buf << "{\n";

  buf << "  return binder" << arity << "arg" << getOrdinal(bindArg) << "<";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1) << ", ";
  }
  buf << "Result>(fn, _" << getLetter(bindArg - 1) << ");\n";

  buf << "}\n\n";

  file << buf.str();
}

void genBindMember(ofstream &file, int arity) {
  stringstream buf;
  buf << "template<typename Result, typename Class";
  for (int i = 0; i < arity; i++) {
    buf << ", typename Arg" << (i + 1);
  }
  buf << ">\n";

  buf << "binder" << (arity + 1) << "arg1st<Class*";
  for (int i = 0; i < arity; i++) {
    buf << ", Arg" << (i + 1);
  }
  buf << ", Result> bindMemberFunc(Result (Class::*f)(";
  for (int i = 0; i < arity; i++) {
    buf << "Arg" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << "), Class *c)\n";

  buf << "{\n";

  buf << "  static mem_fun" << arity << "_t<Result, Class";
  for (int i = 0; i < arity; i++) {
    buf << ", Arg" << (i + 1);
  }
  buf << "> temp = mem_fun(f);\n";

  buf << "  return bind1st(temp, c);\n";

  buf << "}\n\n";

  file << buf.str();
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    cout << "Usage:\n";
    cout << "  ./functional_helpers_generator arity\n";
    cout << "where arity is a positive integer.\n";
    cout << "Example:\n";
    cout << "  ./functional_helpers_generator 4\n";
    exit(1);
  }

  int arity = atoi(argv[1]) + 1;
  
  ofstream file;
  file.open("functional_helpers.h", ofstream::out);

  genLicence(file);

  file << "#ifndef FUNCTIONAL_HELPERS_H\n";
  file << "#define FUNCTIONAL_HELPERS_H\n\n";

  file << "namespace Functional {\n\n";

  for (int i = 1; i < arity; i++) {
    generateHeaders(file, i);
  }

  for (int i = 0; i < arity; i++) {
    genClass(file, i);
    genPtrFun(file, i);
  }

  for (int i = 0; i < arity - 1; i++) {
    genMemFunClass(file, i);
    genMemFun(file, i);
  }

  for (int i = 1; i < arity; i++) {
    genBinderClasses(file, i, 1);
    genBinders(file, i, 1);
    
    for (int bindArg = 2; bindArg <= i; bindArg++) {
      genBinderClasses(file, i, bindArg);
      genBinders(file, i, bindArg);
    }
  }

  for (int i = 1; i < arity - 1; i++) {
    genBindMember(file, i);
  }

  file << "} //end of namespace\n\n";

  file << "#endif";
  
  file.close();
}
