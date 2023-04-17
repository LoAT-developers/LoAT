; ./jayhorn/./sv-comp-2020/jpf-regression/ExMIT_true/smt-output-with-inlining/jayhorn-tmp2_0_000.smt2
(set-logic HORN)

(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block9_5| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block9_6| ( Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |Assert #1: Main.java, line 36| ( ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block15_2| ( Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block15| ( Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block15_1| ( Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block9| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block13| ( Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |CHC_COMP_FALSE| ( ) Bool)
(declare-fun |Assert #2: Main.java, line 32| ( ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block13_1| ( Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block17| ( Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block9_2| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block9_4| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block9_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |Assert #0: Main.java, line 31| ( ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block9_8| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block18| ( Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block18_1| ( Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block9_7| ( Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block9_3| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block13_2| ( Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block9_9| ( Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_pre| ( Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (v_18 Int) (v_19 Int) (v_20 Int) (v_21 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_pre| P N K D G)
        (and (= v_18 P) (= v_19 N) (= v_20 K) (= v_21 D))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block9|
  P
  N
  K
  D
  G
  J
  A
  M
  R
  O
  E
  v_18
  v_19
  v_20
  v_21
  H
  B
  L
  I
  F
  C
  Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (v_19 Int) (v_20 Int) (v_21 Int) (v_22 Int) (v_23 Int) (v_24 Int) (v_25 Int) (v_26 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block9|
  M
  F
  Q
  B
  N
  A
  G
  D
  O
  C
  L
  v_19
  v_20
  v_21
  v_22
  S
  P
  J
  E
  I
  K
  R)
        (and (= v_19 M)
     (= v_20 F)
     (= v_21 Q)
     (= v_22 B)
     (= H 1)
     (= v_23 M)
     (= v_24 F)
     (= v_25 Q)
     (= v_26 B))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block9_1|
  M
  F
  Q
  B
  N
  A
  G
  D
  O
  v_23
  v_24
  v_25
  v_26
  S
  P
  J
  H
  E
  I
  K
  R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (v_17 Int) (v_18 Int) (v_19 Int) (v_20 Int) (v_21 Int) (v_22 Int) (v_23 Int) (v_24 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block9_1|
  P
  H
  L
  K
  E
  G
  J
  N
  O
  v_17
  v_18
  v_19
  v_20
  I
  F
  B
  D
  Q
  C
  M
  A)
        (and (= v_17 P)
     (= v_18 H)
     (= v_19 L)
     (= v_20 K)
     (= H 137)
     (<= 0 K)
     (= P 1)
     (= v_21 P)
     (= v_22 H)
     (= v_23 L)
     (= v_24 K))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block9_2|
  P
  H
  L
  K
  E
  G
  J
  N
  O
  v_21
  v_22
  v_23
  v_24
  F
  B
  D
  Q
  C
  M
  A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (v_19 Int) (v_20 Int) (v_21 Int) (v_22 Int) (v_23 Int) (v_24 Int) (v_25 Int) (v_26 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block9_2|
  C
  K
  S
  J
  A
  R
  Q
  B
  L
  v_19
  v_20
  v_21
  v_22
  E
  M
  I
  G
  O
  D
  P)
        (and (= v_19 C)
     (= v_20 K)
     (= v_21 S)
     (= v_22 J)
     (= H 0)
     (= F 0)
     (= N 0)
     (= v_23 C)
     (= v_24 K)
     (= v_25 S)
     (= v_26 J))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block9_3|
  C
  K
  S
  J
  A
  R
  Q
  B
  L
  N
  F
  H
  v_23
  v_24
  v_25
  v_26
  E
  M
  I
  G
  O
  D
  P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (v_19 Int) (v_20 Int) (v_21 Int) (v_22 Int) (v_23 Int) (v_24 Int) (v_25 Int) (v_26 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block9_3|
  E
  I
  R
  F
  P
  N
  B
  J
  Q
  L
  H
  M
  v_19
  v_20
  v_21
  v_22
  S
  C
  O
  D
  K
  A
  G)
        (and (= v_19 E)
     (= v_20 I)
     (= v_21 R)
     (= v_22 F)
     (= v_23 E)
     (= v_24 I)
     (= v_25 R)
     (= v_26 F))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block9_4|
  E
  I
  R
  F
  P
  Q
  L
  H
  M
  v_23
  v_24
  v_25
  v_26
  S
  C
  O
  D
  K
  A
  G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (v_16 Int) (v_17 Int) (v_18 Int) (v_19 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block9_4|
  N
  H
  G
  A
  D
  L
  F
  M
  C
  v_16
  v_17
  v_18
  v_19
  B
  I
  E
  K
  O
  J
  P)
        (and (= v_16 N) (= v_17 H) (= v_18 G) (= v_19 A))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block9_5|
  N
  H
  G
  A
  D
  L
  F
  M
  C
  B
  I
  E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block9_5|
  C
  M
  F
  H
  G
  I
  D
  E
  J
  L
  B
  K)
        true
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block9_6|
  C
  M
  F
  H
  G
  I
  D
  E
  J
  A
  L
  B
  K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block9_6|
  J
  L
  E
  D
  C
  F
  H
  B
  G
  I
  M
  A
  K)
        (and (<= I 2147483647) (<= (- 2147483648) I))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block9_7|
  J
  L
  E
  D
  C
  F
  H
  B
  G
  I
  M
  A
  K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block9_7|
  M
  K
  J
  B
  H
  N
  A
  C
  L
  D
  I
  E
  G)
        (= F 0)
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block9_8|
  M
  K
  J
  B
  H
  N
  F
  A
  C
  L
  D
  I
  E
  G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block9_8|
  C
  I
  B
  A
  M
  K
  D
  H
  N
  E
  L
  J
  F
  G)
        true
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block9_9|
  C
  I
  B
  A
  M
  K
  H
  N
  E
  L
  J
  F
  G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block9_8|
  L
  F
  I
  C
  D
  H
  K
  B
  N
  G
  E
  M
  J
  A)
        (not (= K 0))
      )
      |Assert #0: Main.java, line 31|
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block9_9|
  G
  J
  I
  D
  B
  K
  F
  E
  H
  C
  M
  L
  A)
        (= C 1)
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block13| G J I D B K C M L A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block13| B F J I A E D H G C)
        (= K 1)
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block13_1| B F J I A E D K C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block13_1| G A C J E F H B I)
        (= (+ D (* (- 2) B)) 0)
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block13_2| G A C J E F H D I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block13_2| H F G E D C B A I)
        (not (= A 10))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block17| H F G E D C B A I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block13_2| G I A C B F D H E)
        (= H 10)
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block18| G I A C B F D H E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block17| F B C I H E G A D)
        true
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block15| F B C I H E G D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block18| G H E I B C F D A)
        true
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block18_1| G H E I B C F A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block18| C F A I H D G E B)
        true
      )
      |Assert #1: Main.java, line 36|
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block18_1| B G C H F E D A)
        true
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block15| B G C H F E D A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block15| K I J B C D E G)
        (and (= F 0) (= A 0) (= H 0))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block15_1| K I J B C A F H E G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block15_1| H G F K I D A B E J)
        (= C 0)
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block15_2| H G F K I C D A B E J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block15_2| C B J K E F H D I G A)
        (not (= F 0))
      )
      |Assert #2: Main.java, line 32|
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        true
      )
      (|<Main: void main(JayArray_java_lang_String)>_pre| D A B E C)
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        |Assert #0: Main.java, line 31|
        true
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        |Assert #1: Main.java, line 36|
        true
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        |Assert #2: Main.java, line 32|
        true
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        CHC_COMP_FALSE
      )
      false
    )
  )
)

(check-sat)
(exit)
