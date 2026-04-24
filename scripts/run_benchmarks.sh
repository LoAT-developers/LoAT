#!/bin/bash

# first and only argument: args for the solver
export args=$1

# function to run a single benchmark
function benchmark() {
    filename=$1
    printf "running ${filename} ..."
    start=`date +%s.%N`

    set +e
    output=$(timeout ${TIMEOUT} solver ${args} "${filename}")

    exit_status=$?
    set -e

    end=`date +%s.%N`
    runtime=$( echo "1000 * ($end - $start)" | bc -l )
    runtime=$( printf %.0f $runtime )

    if [[ $exit_status -eq 0 || $exit_status -eq 124 ]]; then
        if [[ $exit_status -eq 0 ]]; then
            result="unknown"
        else
            result="timeout"
        fi
        for res in $output; do
            if [[ $res == *sat || $res == YES || $res == NO || $res == WORST_CASE* ]]; then
                result=$res
            fi
        done
    else
        result="error"
    fi

    printf "${result} after ${runtime}ms\n"

    echo -e "{\"name\": \"$filename\", \"result\": \"$result\", \"runtime\": \"$runtime\"}" >> ${filename}.json
}

# make 'benchmark' available for 'parallel'
export -f benchmark

# permissions are not preserved for artifacts:
chmod +x /usr/local/bin/solver

cd benchmarks
bench=()
if [[ ${BENCHMARKS} =~ tpdb-ari-* ]]; then
    readarray -d '' bench < <(find * -name "*.ari" -print0)
else
    readarray -d '' bench < <(find * -name "*.smt2" -print0)
fi

# sort the array of benchmarks
IFS=$'\n' sorted=($(sort <<<"${bench[*]}"))
unset IFS

my_bench=()
i=$CI_INDEX
while [[ $i -lt ${#sorted[@]} ]]; do
    my_bench+=(${sorted[i]})
    i=$(( i+CI_TOTAL ))
done

if [[ 0 -eq $CI_INDEX ]]; then
    echo $VERSION > solver.version
fi

# execute benchmarks in parallel
parallel benchmark ::: ${my_bench[@]}
