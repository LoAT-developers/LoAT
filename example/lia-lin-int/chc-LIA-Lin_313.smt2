; ./jayhorn/./sv-comp-2020/jbmc-regression/synchronized/smt-output-with-inlining/jayhorn-tmp2_0_000.smt2
(set-logic HORN)

(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block10_2| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |Assert #0: Main.java, line 14| ( ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block10_3| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block10_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block10| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_pre| ( Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (v_13 Int) (v_14 Int) (v_15 Int) (v_16 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_pre| C K J E G)
        (and (= v_13 C) (= v_14 K) (= v_15 J) (= v_16 E))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block10|
  C
  K
  J
  E
  G
  D
  L
  B
  v_13
  v_14
  v_15
  v_16
  I
  H
  A
  F
  M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (v_14 Int) (v_15 Int) (v_16 Int) (v_17 Int) (v_18 Int) (v_19 Int) (v_20 Int) (v_21 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block10|
  C
  N
  D
  M
  G
  I
  A
  E
  v_14
  v_15
  v_16
  v_17
  H
  L
  F
  J
  B)
        (and (= v_14 C)
     (= v_15 N)
     (= v_16 D)
     (= v_17 M)
     (= K 1)
     (= v_18 C)
     (= v_19 N)
     (= v_20 D)
     (= v_21 M))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block10_1|
  C
  N
  D
  M
  G
  I
  A
  E
  v_18
  v_19
  v_20
  v_21
  H
  K
  L
  F
  J
  B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (v_14 Int) (v_15 Int) (v_16 Int) (v_17 Int) (v_18 Int) (v_19 Int) (v_20 Int) (v_21 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block10_1|
  L
  B
  F
  K
  E
  A
  N
  M
  v_14
  v_15
  v_16
  v_17
  G
  I
  J
  D
  C
  H)
        (and (= v_14 L)
     (= v_15 B)
     (= v_16 F)
     (= v_17 K)
     (= B 137)
     (<= 0 K)
     (= L 1)
     (= v_18 L)
     (= v_19 B)
     (= v_20 F)
     (= v_21 K))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block10_2|
  L
  B
  F
  K
  E
  A
  N
  M
  v_18
  v_19
  v_20
  v_21
  I
  J
  D
  C
  H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (v_16 Int) (v_17 Int) (v_18 Int) (v_19 Int) (v_20 Int) (v_21 Int) (v_22 Int) (v_23 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block10_2|
  C
  P
  E
  D
  H
  O
  J
  G
  v_16
  v_17
  v_18
  v_19
  K
  B
  N
  F
  I)
        (and (= v_16 C)
     (= v_17 P)
     (= v_18 E)
     (= v_19 D)
     (= M 0)
     (= L 0)
     (= A 0)
     (= v_20 C)
     (= v_21 P)
     (= v_22 E)
     (= v_23 D))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block10_3|
  C
  P
  E
  D
  H
  O
  J
  G
  L
  M
  A
  v_20
  v_21
  v_22
  v_23
  K
  B
  N
  F
  I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (v_16 Int) (v_17 Int) (v_18 Int) (v_19 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block10_3|
  D
  M
  E
  I
  F
  P
  G
  B
  K
  H
  N
  v_16
  v_17
  v_18
  v_19
  C
  J
  A
  O
  L)
        (and (= v_16 D) (= v_17 M) (= v_18 E) (= v_19 I))
      )
      |Assert #0: Main.java, line 14|
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        true
      )
      (|<Main: void main(JayArray_java_lang_String)>_pre| C B A E D)
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        |Assert #0: Main.java, line 14|
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
