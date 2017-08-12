#!/bin/bash

g++ generator_functional_helpers.cpp -o generator_functional_helpers
g++ generator_tuples.cpp -o generator_tuples
g++ generator_memoize.cpp -o generator_memoize
chmod +x generator_functional_helpers
chmod +x generator_tuples
chmod +x generator_memoize
./generator_functional_helpers 9
./generator_tuples 10
./generator_memoize 9