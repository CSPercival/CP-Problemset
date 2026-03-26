#!/bin/bash

g++ -O3 gen_1A_GRM.cpp -o gen
g++ -O3 brut_1A_GRM.cpp -o brut
g++ -O3 1A_GRM.cpp -o wzo

for i in {1..20000}; do
    echo -n "Test $i... " 
    ./gen > test_in
    ./brut < test_in > outB
    ./wzo < test_in > outW
    cmp outB outW || break

    echo "Accepted"
done