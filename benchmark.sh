#!/bin/bash

modes=("stl" "qsort" "merge" "quick")
sizes=(10 100 1000 10000 100000 1000000 10000000)

run_benchmark(){
    mode=$1
    size=$2
    /usr/bin/time -f "%e %M" ./volsort -m $mode input_$size.txt > /dev/null
}

for mode in "${modes[@]}"; do
    for size in "${sizes[@]}"; do
        echo -n "| $mode | $size | "
        result=$(run_benchmark $mode $size)
        echo "$result |"
    done >> README.md
done