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

void genClass(ofstream &file, int arity) {
  stringstream buf;
  buf << "template<";
  for (int i = 0; i < arity; i++) {
    buf << "typename T" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ">\n";

  buf << "struct " << getName(arity) << "_tuple\n";

  buf << "{\n";

  for (int i = 0; i < arity; i++) {
    buf << "  T" << (i + 1) << " " << getOrdinal(i + 1) << ";\n";
  }

  buf << "  " << getName(arity) << "_tuple() {}\n";

  // Normal constructor
  buf << "  " << getName(arity) << "_tuple(";
  for (int i = 0; i < arity; i++) {
    buf << "const T" << (i + 1) << " &t" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ") : ";
  for (int i = 0; i < arity; i++) {
    buf << getOrdinal(i + 1) << "(t" << (i + 1) << ")";
    if (i < arity - 1)
      buf << ", ";
  }
  buf << " {}\n";

  // Copy constructor
  buf << "  " << getName(arity) << "_tuple(const " << getName(arity) << "_tuple<";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << "> &p) : ";
  for (int i = 0; i < arity; i++) {
    buf << getOrdinal(i + 1) << "(p." << getOrdinal(i + 1) << ")";
    if (i < arity - 1)
      buf << ", ";
  }
  buf << " {}\n";

  // assignment operator (copy)
  buf << "  " << getName(arity) << "_tuple<";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ">& operator=(const " << getName(arity) << "_tuple<";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << "> &p) {\n";
  for (int i = 0; i < arity; i++) {
    buf << "    " << getOrdinal(i + 1) << " = p." << getOrdinal(i + 1) << ";\n";
  }
  buf << "    return *this;\n";
  buf << "  }\n";

  // less than operator
  buf << "  bool operator<(const " << getName(arity) << "_tuple<";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << "> &p) const {\n";
  for (int i = 0; i < arity; i++) {
    buf << "    if(" << getOrdinal(i + 1) << " < p." << getOrdinal(i + 1) << ") return true;\n";
  }
  buf << "    return false;\n";
  buf << "  }\n";

  buf << "};\n\n";

  file << buf.str();
}

void genPtrFun(ofstream &file, int arity) {
  stringstream buf;
  buf << "template<";
  for (int i = 0; i < arity; i++) {
    buf << "typename T" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ">\n";

  buf << getName(arity) << "_tuple<";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << "> tuple(";
  for (int i = 0; i < arity; i++) {
    buf << "const T" << (i + 1) << " &t" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ")\n";

  buf << "{\n";

  buf << "  return " << getName(arity) << "_tuple<";
  for (int i = 0; i < arity; i++) {
    buf << "T" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ">(";
  for (int i = 0; i < arity; i++) {
    buf << "t" << (i + 1);
    if (i < arity - 1)
      buf << ", ";
  }
  buf << ");\n";

  buf << "}\n\n";

  file << buf.str();
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    cout << "Usage:\n";
    cout << "  ./generator_tuples arity\n";
    cout << "where arity is a positive integer.\n";
    cout << "Example:\n";
    cout << "  ./generator_tuples 4\n";
    exit(1);
  }

  int arity = atoi(argv[1]) + 1;
  
  ofstream file;
  file.open("tuples.h", ofstream::out);

  genLicence(file);

  file << "#ifndef TUPLES_H\n";
  file << "#define TUPLES_H\n\n";

  file << "namespace Tuples {\n\n";

  for (int i = 1; i < arity; i++) {
    genClass(file, i);
    genPtrFun(file, i);
  }

  file << "} //end of namespace\n\n";

  file << "#endif";
  
  file.close();
}
