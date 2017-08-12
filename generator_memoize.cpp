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
  string endings[] = {"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth"};
  return endings[num - 1];
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

void genHelper(ofstream &file, int arity) {
  stringstream buf;
  buf << "template<typename Result";
  for (int i = 0; i < arity; i++) {
    buf << ", typename T" << (i + 1);
  }
  buf << ">\n";

  buf << "class " << getName(arity) << "_memoizer\n";

  buf << "{\n";
  buf << "public:\n";

  buf << "  std::map<Tuples::" << getName(arity) << "_tuple<";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ">, Result> memo;\n";

  buf << "  Functional::" << getName(arity) << "_function<";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1) << ", ";
  }
  buf << "Result> _fun;\n";

  buf << "  " << getName(arity) << "_memoizer() {}\n";

  // Normal constructor
  buf << "  " << getName(arity) << "_memoizer(Functional::" << getName(arity) << "_function<";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1) << ", ";
  }
  buf << "Result> &f";
  buf << ") : _fun(f) {}\n";

  buf << "  virtual Result operator()(";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1) << " _" << getLetter(i);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ") {\n";

  buf << "    Tuples::" << getName(arity) << "_tuple<";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << "> tup = Tuples::tuple(";
  for (int i = 0; i < arity; i++) {
    buf << "_" << getLetter(i);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ");\n";

  buf << "    typename std::map<Tuples::" << getName(arity) << "_tuple<";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ">, Result>::const_iterator found = memo.find(tup);\n";

  buf << "    if (found != memo.end()) {\n";
  buf << "#ifdef DEBUG\n      std::cout << \"Found!\\n\";\n#endif\n";
  buf << "      return found->second;\n    }\n";

  buf << "#ifdef DEBUG\n    std::cout << \"Not found!\\n\";\n#endif\n";
  buf << "    Result res = _fun(";
  for (int i = 0; i < arity; i++) {
    buf << "_" << getLetter(i);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ");\n";

  buf << "    memo[tup] = res;\n";

  buf << "    return res;\n";

  buf << "  }\n";

  buf << "};\n\n";

  file << buf.str();
}

void genFunc(ofstream &file, int arity) {
  stringstream buf;
  buf << "template<typename Result";
  for (int i = 0; i < arity; i++) {
    buf << ", typename T" << (i + 1);
  }
  buf << ">\n";

  buf << getName(arity) << "_memoizer<Result";
  for (int i = 0; i < arity; i++) {
    buf << ", T" << (i + 1);
  }
  buf << "> memoize(Functional::" << getName(arity) << "_function<";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1) << ", ";
  }
  buf << "Result> f)\n";

  buf << "{\n";

  buf << "  return " << getName(arity) << "_memoizer<Result";
  for (int i = 0; i < arity; i++) {
    buf << ", T" << (i + 1);
  }
  buf << ">(f);\n";

  buf << "}\n\n";

  file << buf.str();
}

void genFunc2(ofstream &file, int arity) {
  stringstream buf;
  buf << "template<typename Result";
  for (int i = 0; i < arity; i++) {
    buf << ", typename T" << (i + 1);
  }
  buf << ">\n";

  buf << getName(arity) << "_memoizer<Result";
  for (int i = 0; i < arity; i++) {
    buf << ", T" << (i + 1);
  }
  buf << "> memoize(Result (*f)(";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << "))\n";

  buf << "{\n";

  buf << "  return memoize(Functional::ptr_fun(f));\n";

  buf << "}\n\n";

  file << buf.str();
}

void genFunc3(ofstream &file, int arity) {
  stringstream buf;
  buf << "template<typename Result, typename Class";
  for (int i = 0; i < arity; i++) {
    buf << ", typename T" << (i + 1);
  }
  buf << ">\n";

  buf << getName(arity + 1) << "_memoizer<Result, Class*";
  for (int i = 0; i < arity; i++) {
    buf << ", T" << (i + 1);
  }
  buf << "> memoize(Result (Class::*f)(";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << "))\n";

  buf << "{\n";

  buf << "  return memoize(Functional::mem_fun(f));\n";

  buf << "}\n\n";

  file << buf.str();
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    cout << "Usage:\n";
    cout << "  ./generator_memoize arity\n";
    cout << "where arity is a positive integer.\n";
    cout << "Example:\n";
    cout << "  ./generator_memoize 4\n";
    exit(1);
  }

  int arity = atoi(argv[1]) + 1;
  
  ofstream file;
  file.open("memoize.h", ofstream::out);

  genLicence(file);

  file << "#ifndef MEMOIZE_H\n";
  file << "#define MEMOIZE_H\n\n";

  file << "#include <iostream>\n";
  file << "#include <map>\n";
  file << "#include \"functional_helpers.h\"\n";
  file << "#include \"tuples.h\"\n\n";

  file << "namespace Memoize {\n\n";

  for (int i = 1; i < arity; i++) {
    genHelper(file, i);
    genFunc(file, i);
    genFunc2(file, i);
    genFunc3(file, i - 1);
  }

  file << "} //end of namespace\n\n";

  file << "#endif";
  
  file.close();
}
