#!/bin/bash
for test in testdata/sat-flat125-301/*.cnf
do
  #echo $test
  ./a.out < $test
done

for test in testdata/sat-uniform-20-91/*.cnf
do
  #echo $test
  ./a.out < $test
done

for test in testdata/unsat-dimacs-dubois/*.cnf
do
  #echo $test
  ./a.out < $test
done

for test in testdata/unsat-uniform-50-218/*.cnf
do
  #echo $test
  ./a.out < $test
done
