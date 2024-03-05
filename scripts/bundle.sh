#!/bin/bash

# creates a StarExec-bundle with the binary from build/release

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
DIR=$(pwd)

cd $SCRIPT_DIR/..

ME=`basename "$0"`

function print {
    echo
    echo "$ME: $1"
    echo
}

function check {
    EXIT_CODE=$?
    if [[ $EXIT_CODE -ne 0 ]]; then
        print "$1 failed, exit code $EXIT_CODE"
        cd $DIR
        exit $EXIT_CODE
    fi
}

BUILD=./build/release
BIN=loat-static
BUNDLE=./bin
TEMPLATE=./bundle.template
OUT=./loat.zip

if [[ ! -d $OUT ]]; then
    rm $OUT
fi

if [[ -d $BUNDLE ]]; then
    rm -r $BUNDLE
fi

print "building LoAT..."
cd $BUILD
cmake -DCMAKE_BUILD_TYPE=Release ../..
make -j
cd $SCRIPT_DIR/..
check "building LoAT"
print "creating bundle..."
cp -r $TEMPLATE $BUNDLE
cp $BUILD/$BIN $BUNDLE
zip -r $OUT $BUNDLE
check "creating bundle"

print "bundle created successfully"

rm -r $BUNDLE

cd $DIR
