#!/bin/bash

ME=`basename "$0"`

function help {
    echo "usage: ./$ME ({(dynamic|static) (release|debug)} | bundle)"
}

function print {
    echo
    echo "$ME: $1"
    echo
}

function check {
    EXIT_CODE=$?
    if [[ $EXIT_CODE -ne 0 ]]; then
        print "$1 failed, exit code $EXIT_CODE"
        exit $EXIT_CODE
    fi
}

BUILD=build/release
BIN=loat-static
BUNDLE=bin
TEMPLATE=bundle.template
OUT=loat.zip

if [[ ! -d $OUT ]]; then
    rm $OUT
fi

if [[ -d $BUNDLE ]]; then
    rm -r $BUNDLE
fi

print "creating bundle..."
cp -r $TEMPLATE $BUNDLE
cp $BUILD/$BIN $BUNDLE
zip -r $OUT $BUNDLE
check "creating bundle"

print "bundle created successfully"

rm -r $BUNDLE
