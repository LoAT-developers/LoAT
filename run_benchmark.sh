#!/bin/bash

set -e

# Switch working directory to the folder, where this script is laying around.
# That way all paths are guaranteed to be relative to the script locaiton.
pushd $(dirname ${BASH_SOURCE[0]})

cmake -S . -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo
pushd build
make -j4
popd

# DEBUG: non-deterministic unsat/unknown for 133,139

# gdb --args \
time ./build/loat-static \
   --mode reachability \
   --format horn \
   --proof-level 0 \
   --log \
   "../chc-comp22-benchmarks/LIA/chc-LIA_130.smt2"
   # "../chc-comp23-benchmarks/test.smt2"
   # "../chc-comp23-benchmarks/LIA-nonlin/chc-LIA_004.smt2"

popd
exit

# CHECK: 073 () / 119 () / 126 () / 130 (1m13s) / 351 (2m50s)

##########################################################################

benchmark="LIA"

printf "### %-7s %-7s %-7s \n" "Z3" "ADCL" "now"

while IFS= read -r line
do
  if [[ $line =~ ^#.*$ ]] || [[ "$line" = "" ]]; then
    # skip comments and empty lines
    continue
  else
    read idx z3_result adcl_result <<< "$line"
    # file="../chc-comp23-benchmarks/${benchmark}-nonlin/chc-${benchmark}_${idx}.smt2"
    file="../chc-comp22-benchmarks/${benchmark}/chc-${benchmark}_${idx}.smt2"

    # if true; then
    # if [[ "$z3_result" == "unsat" ]] && [[ "$adcl_result" == "timeout" ]]; then
    # if [[ "$z3_result" != "sat" ]] && [[ "$z3_result" != "timeout" ]]; then
    # if [[ "$z3_result" != "sat" ]]; then
    # if [[ "$adcl_result" == "unknown" ]]; then
    if [[ "$adcl_result" == "unsat" ]]; then
      set +e
      result=$(timeout 20 ./build/loat-static --mode reachability --format horn --proof-level 0 "$file")
      # result=$(timeout 5 z3 "$file")
      exit_status=$?
      set -e

      if [ $exit_status -eq 0 ]; then
        result=$(echo "$result" | head -n 1)
        # result="$result"
      elif [ $exit_status -eq 124 ]; then
        result="timeout"
      else
        result="error"
      fi

      printf "$idx %-7s %-7s %-7s \n" $z3_result $adcl_result $result

    # else
    #   # if we skip an instance nevertheless include it in the output
    #   # so the log can easily be copied and saved as a whole
    #   printf "$idx %-7s %-7s %-7s \n" $z3_result $adcl_result $adcl_result
    fi

  fi
# done < "./benchmarks/comp23-${benchmark}-nonlin.txt"
done < "./benchmarks/${benchmark}.txt"

# "undo" pushd
popd
