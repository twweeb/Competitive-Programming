#!/bin/bash

g++ -std=c++17 $1
if [ "$2" = "interactive" ]
then
    python interactive_runner.py python3 local_testing_tool.py $3 -- ./a.out
else
    ./a.out < test.in
fi

