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

nondet : NONDETNAME W* OPENP W* CLOSEP;

num_atom : ZERO | POS | nondet | V | OPENP W* bool_expr W* CLOSEP;

mult_expr : num_atom (W* MULT W* num_atom)*;

pm_mult_expr: W* (PLUS | MINUS) W* mult_expr;

num_expr : mult_expr pm_mult_expr* | MINUS W* mult_expr pm_mult_expr*;

bool_atom : TRUE | FALSE | num_expr (W* BO W* num_expr)?;

and_expr : bool_atom (W* AND W* bool_atom)*;

bool_expr : and_expr (W* OR W* and_expr)* | NOT W* bool_atom;

loop : WHILE W* OPENP W* bool_expr W* CLOSEP W* OPENC W* (instructions W*)? CLOSEC;

condition :
    IF
    W*
    OPENP W* bool_expr W* CLOSEP
    W*
    OPENC W* (instructions W*)? CLOSEC
    (W* ELSE W* OPENC W* (instructions W*)? CLOSEC)?;

assignment : V W* ASSIGN W* num_expr W* TERMINATOR;

instruction : loop | condition | assignment;

declaration : INT W+ V (W* COMMA W* V)* W* TERMINATOR;

declarations : declaration (W* declarations)?;

instructions : instruction (W* instructions)?;

// the opening part of each program
// ("typedef enum {false,true} bool;extern int __VERIFIER_nondet_int(void);int main(){")
pre :
    W*
    TYPEDEF W+ ENUM W* OPENC W* FALSE W* COMMA W* TRUE W* CLOSEC W* BOOL W* TERMINATOR
    W*
    EXTERN W+ INT W+ NONDETNAME W* OPENP W* VOID W* CLOSEP W* TERMINATOR
    W*
    INT W+ MAIN W* OPENP W* CLOSEP W* OPENC;

// the closing part of each program ("return 0;}")
post : RETURN W+ ZERO W* TERMINATOR W* CLOSEC W*;

main : pre (W* declarations)? (W* instructions)? W* post;


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
BO : '<=' | '>=' | '<' | '>' | '==' | '!=';
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
W : ' ' | '\n' | '\r' | '\t';
BLOCKCOMMENT : '/*' (.)*? '*/' -> skip;
LINECOMMENT : '//' (~('\r'|'\n'))* -> skip;
