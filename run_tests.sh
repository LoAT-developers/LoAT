#!/bin/bash
repo=../chc-comp22-benchmarks
while read line; do
    if [ "$line" = "unsat" ] || [ "$line" = "sat" ] || [ "$line" == "unknown" ]; then
        expected=$line
    else
        if [[ $line =~ ^#.*$ ]]; then
            continue
        else
            if [[ $line =~ ^[0-9]+$ ]]; then
                ex=$line
                echo "running chc-${path}_$ex.smt2"
                actual=$(./build/static/release/loat-static --mode reachability --format horn --proof-level 0 --timeout 10 "$repo/$path/chc-${path}_$ex.smt2")
                if [ "$expected" = "$actual" ]; then
                    echo "test passed"
                else
                    echo "test failed -- expted $expected, got $actual"
                    exit 0
                fi
            else
                if [ "$line" = "LIA-Lin" ]; then
                    path=$line
                else
                    echo "failed to parse $line"
                    exit -1;
                fi
            fi
        fi
    fi
done < test_data.txt
