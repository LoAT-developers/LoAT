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

function build {
    mkdir -p build/$1/$2
    cd build/$1/$2
    print "configuring build..."
    cmake ../../../ -DSTATIC=$3 -DCMAKE_BUILD_TYPE=$4
    check "configuration"
    print "building LoAT..."
    make -j
    check "build"
    print "done"
}

function default_build {
    build "static" "release" 1 Release
}

function bundle {
    BUILD=build/static/release
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

    print "building LoAT..."
    ./compile_static_binary
    check "build"

    print "creating bundle..."
    cp -r $TEMPLATE $BUNDLE
    cp $BUILD/$BIN $BUNDLE
    zip -r $OUT $BUNDLE
    check "creating bundle"

    print "bundle created successfully"

    rm -r $BUNDLE
}

case $1,$2 in
    "","" | "static","" | "static","release")
        default_build
        ;;
    "static","debug")
        build "static" "debug" 1 Debug
        ;;
    "dynamic","" | "dynamic","release")
        build "dynamic" "release" 0 Release
        ;;
    "dynamic","debug")
        build "dynamic" "debug" 0 Debug
        ;;
    "bundle","")
        bundle
        ;;
    *)
        help
        ;;
esac
