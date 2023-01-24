#!/bin/bash
repo=../chc-comp22-benchmarks

while read line; do
    if [ "$line" = "unsat" ] || [ "$line" = "sat" ] || [ "$line" == "unknown" ]; then
        # line contains the expected result for the following benchmarks
        expected=$line
    else
        if [[ $line =~ ^#.*$ ]] || [ "$line" = "" ] ; then
            # skip comments and empty lines
            continue
        else
            if [[ $line =~ ^[0-9]+$ ]]; then
                # line contains the number of the next benchmark -- run it
                ex=$line
                echo "running chc-${path}_$ex.smt2 with LoAT"
                start=`date +%s%3N`
                actual=$(timeout 10m ./build/static/release/loat-static --mode satisfiability --format horn --proof-level 0 "$repo/$path/chc-${path}_$ex.smt2" | head -n 1)
                end=`date +%s%3N`
                runtime=$((end-start))
                if [ "$expected" = "$actual" ]; then
                    echo "test passed in ${runtime}ms"
                else
                    echo "test failed after ${runtime}ms -- expected $expected, got $actual"
                    # exit 0
                fi
                
                echo "running chc-${path}_$ex.smt2 with z3"
                start=`date +%s%3N`
                actual=$(timeout 10m z3 "$repo/$path/chc-${path}_$ex.smt2" | head -n 1)
                end=`date +%s%3N`
                runtime=$((end-start))
                if [ "$expected" = "$actual" ]; then
                    echo "test passed in ${runtime}ms"
                else
                    echo "test failed after ${runtime}ms -- expected $expected, got $actual"
                    # exit 0
                fi
                
            else
                if [ "$line" = "LIA-Lin" ]; then
                    # line contains the folder of the following benchmarks
                    path=$line
                else
                    echo "failed to parse $line"
                    exit -1;
                fi
            fi
        fi
    fi
done < test_data_sat_comparison.txt


