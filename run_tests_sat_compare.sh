#!/bin/bash

resultsLoATRt="resultsLoATRt.txt"
resultsz3Rt="resultsz3Rt.txt"
echo "Test Results in ms:" > $resultsLoATRt
echo "Test Results in ms:" > $resultsz3Rt
resultsLoATOut="resultsLoATOut.txt"
resultsz3Out="resultsz3Out.txt"
echo "Test Results Output:" > $resultsLoATOut
echo "Test Results Output:" > $resultsz3Out

repo=../chc-comp22-benchmarks

while read line; do
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
                echo $runtime >> $resultsLoATRt
                echo $actual >> $resultsLoATOut
                echo "Result after ${runtime}ms: $actual"

                echo "running chc-${path}_$ex.smt2 with z3"
                start=`date +%s%3N`
                actual=$(timeout 10m z3 "$repo/$path/chc-${path}_$ex.smt2" | head -n 1)
                end=`date +%s%3N`
                runtime=$((end-start))
                echo $runtime >> $resultsz3Rt
                echo $actual >> $resultsz3Out
		echo "Result after ${runtime}ms: $actual"
                
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
done < test_data_sat_compare.txt


