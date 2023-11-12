#!/bin/bash

set -e

# Switch working directory to the folder, where this script is laying around.
# That way all paths are guaranteed to be relative to the script locaiton.
pushd $(dirname ${BASH_SOURCE[0]})

cmake -S . -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo
# cmake --build build
pushd build
make -j4
popd

# TODO: debug 335 (seg fault)
# TODO: debug 034 (seg fault)

# # gdb --args \
# ./build/loat-static \
#   --mode reachability \
#   --format horn \
#   --proof-level 0 \
#   --log \
#   "../chc-comp22-benchmarks/LIA/chc-LIA_069.smt2"

# popd
# exit

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
    file="../chc-comp22-benchmarks/${benchmark}/chc-${benchmark}_${idx}.smt2"

    if true; then
    # if [[ "$z3_result" != "sat" ]] && [[ "$z3_result" != "timeout" ]]; then
    # if [[ "$z3_result" == "unsat" ]]; then
    # if [[ "$adcl_result" == "unsat" ]]; then
      set +e
      result=$(timeout 5 ./build/loat-static --mode reachability --format horn --proof-level 0 "$file")
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
    #   printf "$idx $prev_result \n"
    fi

  fi
done < "./benchmarks/${benchmark}.txt"

# "undo" pushd
popd
