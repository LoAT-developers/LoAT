#!/bin/bash

for var in "$@"
do
    if [[ $var == --name ]]; then
        echo "LoAT"
        exit 0
    elif [[ $var == --category* ]]; then
        category=$( echo $var | cut -d "=" -f 2 )
    elif [[ $var == --timeout* ]]; then
        timeout=$( echo $var | cut -d "=" -f 2 )
        timeout=`expr $timeout - 3`
    else
        bench=$var
    fi
done
if [[ $category == Integer_Transition_Systems ]]; then
    loat_static --format its --mode termination --proof $bench
elif [[ $category == Complexity_ITS ]]; then
    res=`timeout $timeout loat_static --format koat --mode complexity --proof`
    echo "$res" | grep "WORST_CASE\|NO" | tac | head -n 1
else
    echo "unknown category $category"
fi
