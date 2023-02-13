/*   Type:        ANTLR
 *   Title:       Grammar for C Integer Programs
 *   Description: A grammar definiton for C integer programs
 *   Project:     AProVE
 *   Authors:     Thomas Ströder
 *   Copyright:   Copyright (c) 2015
 *   Department:  RWTH Aachen / Templergraben 55 / D-52056 Aachen
 *
 * The following license text is based on the "BSD licence".
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

grammar CINT;

// parser rules

nondet : NONDETNAME OPENP CLOSEP;

// arithmetic expressions
num_expr: OPENP num_expr CLOSEP | MINUS num_expr | num_expr MULT num_expr | num_expr PLUS num_expr | num_expr MINUS num_expr | V | ZERO | POS | nondet;

// boolean expressions
bool_expr: OPENP bool_expr CLOSEP | NOT bool_expr | bool_expr AND bool_expr | bool_expr OR bool_expr | lit | FALSE | TRUE;
lit: num_expr relop num_expr;
relop: LT | LEQ | EQ | GT | GEQ | NEQ;

loop : WHILE OPENP bool_expr CLOSEP OPENC (instructions)? CLOSEC;

condition :
    IF
    OPENP bool_expr CLOSEP
    OPENC then CLOSEC
    (ELSE OPENC else CLOSEC)?;

then : instructions?;

else : instructions?;

assignment : V ASSIGN num_expr TERMINATOR;

instruction : loop | condition | assignment;

declaration : INT V (COMMA V)* TERMINATOR;

declarations : declaration+;

instructions : instruction+;

// the opening part of each program
// ("typedef enum {false,true} bool;extern int __VERIFIER_nondet_int(void);int main(){")
pre :
    TYPEDEF ENUM OPENC FALSE COMMA TRUE CLOSEC BOOL TERMINATOR
    EXTERN INT NONDETNAME OPENP VOID CLOSEP TERMINATOR
    INT MAIN OPENP CLOSEP OPENC;

// the closing part of each program ("return 0;}")
post : RETURN ZERO TERMINATOR CLOSEC;

main : pre declarations? instructions? post;


// lexer rules

INT : 'int';
IF : 'if';
WHILE : 'while';
ELSE : 'else';
TERMINATOR : ';';
OPENP : '(';
CLOSEP : ')';
OPENC : '{';
CLOSEC : '}';
MULT : '*';
MINUS : '-';
PLUS : '+';
LT	:	'<';
LEQ     :       '<=';
EQ      :       '==';
NEQ     :       '!=';
GEQ     :       '>=';
GT      :       '>' ;
ASSIGN : '=';
NONDETNAME : '__VERIFIER_nondet_int';
OR : '||';
AND : '&&';
NOT : '!';
TRUE : 'true';
FALSE : 'false';
TYPEDEF : 'typedef';
ENUM : 'enum';
COMMA : ',';
BOOL : 'bool';
EXTERN : 'extern';
VOID : 'void';
MAIN : 'main';
RETURN : 'return';
ZERO : '0';
POS : NONZERO DIGIT*;
fragment NONZERO : '1'..'9';
fragment DIGIT : ZERO | NONZERO;
V : CHAR ALPHANUM*;
fragment ALPHANUM : CHAR | DIGIT;
fragment CHAR : LOW | UP;
fragment LOW : 'a'..'z';
fragment UP: 'A'..'Z';
W : (' ' | '\n' | '\r' | '\t')+ -> skip;
BLOCKCOMMENT : '/*' (.)*? '*/' -> skip;
LINECOMMENT : '//' (~('\r'|'\n'))* -> skip;