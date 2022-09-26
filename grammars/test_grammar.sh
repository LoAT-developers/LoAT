# usage: test_grammar.sh $GRAMMAR_NAME $START_RULE $TEST_FILE
javac -cp ../deps/antlr-4.11.1-complete.jar:$CLASSPATH *.java
/usr/share/antlr4/grun $@
