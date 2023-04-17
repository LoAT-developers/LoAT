; ./jayhorn/./sv-comp-2020/jbmc-regression/StringValueOf06/smt-output-with-inlining/jayhorn-tmp_1_000.smt2
(set-logic HORN)

(declare-fun |Assert #0: Main.java, line 13| ( ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block11_2| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_pre| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block11_6| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block11_4| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block11_7| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block11_5| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block11_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block11_3| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |<Main: void main(JayArray_java_lang_String)>_Block11| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (v_40 Int) (v_41 Int) (v_42 Int) (v_43 Int) (v_44 Int) (v_45 Int) (v_46 Int) (v_47 Int) (v_48 Int) (v_49 Int) (v_50 Int) (v_51 Int) (v_52 Int) (v_53 Int) (v_54 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_pre|
  N
  U
  I
  C
  F1
  M1
  B
  B1
  K
  V
  E
  O
  E1
  J1
  N1
  A1)
        (and (= v_40 N)
     (= v_41 U)
     (= v_42 I)
     (= v_43 C)
     (= v_44 M1)
     (= v_45 B)
     (= v_46 B1)
     (= v_47 K)
     (= v_48 V)
     (= v_49 E)
     (= v_50 O)
     (= v_51 E1)
     (= v_52 J1)
     (= v_53 N1)
     (= v_54 A1))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block11|
  N
  U
  I
  C
  F1
  M1
  B
  B1
  K
  V
  E
  O
  E1
  J1
  N1
  A1
  M
  F
  L1
  K1
  W
  G
  T
  X
  D1
  G1
  v_40
  v_41
  v_42
  v_43
  D
  J
  P
  S
  C1
  I1
  Z
  H1
  L
  R
  H
  Q
  A
  Y
  v_44
  v_45
  v_46
  v_47
  v_48
  v_49
  v_50
  v_51
  v_52
  v_53
  v_54)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (v_52 Int) (v_53 Int) (v_54 Int) (v_55 Int) (v_56 Int) (v_57 Int) (v_58 Int) (v_59 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block11|
  Q
  T
  U1
  L1
  J1
  T1
  U
  M1
  J
  P
  I1
  V
  L
  I
  O1
  B1
  W1
  Y1
  R
  G1
  F
  N1
  E1
  S1
  M
  C1
  v_52
  v_53
  v_54
  v_55
  K1
  E
  F1
  O
  N
  Z
  B
  X1
  W
  Y
  D
  Q1
  P1
  Z1
  A1
  X
  G
  V1
  K
  D1
  R1
  C
  H1
  H
  A)
        (and (= v_52 Q)
     (= v_53 T)
     (= v_54 U1)
     (= v_55 L1)
     (= S 1)
     (= v_56 Q)
     (= v_57 T)
     (= v_58 U1)
     (= v_59 L1))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block11_1|
  Q
  T
  U1
  L1
  J1
  T1
  U
  M1
  J
  P
  I1
  V
  L
  I
  O1
  B1
  W1
  Y1
  R
  v_56
  v_57
  v_58
  v_59
  K1
  E
  F1
  N
  S
  D
  Q1
  P1
  Z1
  A1
  X
  G
  V1
  K
  D1
  R1
  C
  H1
  H
  A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (v_39 Int) (v_40 Int) (v_41 Int) (v_42 Int) (v_43 Int) (v_44 Int) (v_45 Int) (v_46 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block11_1|
  L
  E
  M
  G1
  P
  V
  K
  U
  Q
  H
  C
  G
  K1
  D
  T
  C1
  S
  F1
  I
  v_39
  v_40
  v_41
  v_42
  D1
  X
  F
  R
  H1
  J
  A
  J1
  A1
  I1
  M1
  O
  W
  Z
  B1
  B
  L1
  Y
  E1
  N)
        (and (= v_39 L)
     (= v_40 E)
     (= v_41 M)
     (= v_42 G1)
     (= E 137)
     (<= 0 G1)
     (= L 1)
     (= v_43 L)
     (= v_44 E)
     (= v_45 M)
     (= v_46 G1))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block11_2|
  L
  E
  M
  G1
  P
  V
  K
  U
  Q
  H
  C
  G
  K1
  D
  T
  C1
  S
  F1
  I
  v_43
  v_44
  v_45
  v_46
  D1
  X
  F
  H1
  J
  A
  J1
  A1
  I1
  M1
  O
  W
  Z
  B1
  B
  L1
  Y
  E1
  N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (v_40 Int) (v_41 Int) (v_42 Int) (v_43 Int) (v_44 Int) (v_45 Int) (v_46 Int) (v_47 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block11_2|
  X
  H
  G
  G1
  A
  D1
  P
  O
  N
  K1
  M
  D
  M1
  R
  I
  C1
  L
  B1
  J
  v_40
  v_41
  v_42
  v_43
  Z
  N1
  E
  E1
  T
  V
  K
  A1
  F1
  Q
  L1
  B
  S
  F
  C
  W
  U
  Y
  J1)
        (and (= v_40 X)
     (= v_41 H)
     (= v_42 G)
     (= v_43 G1)
     (= H1 1)
     (= v_44 X)
     (= v_45 H)
     (= v_46 G)
     (= v_47 G1))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block11_3|
  X
  H
  G
  G1
  A
  D1
  P
  O
  N
  K1
  M
  D
  M1
  R
  I
  C1
  v_44
  v_45
  v_46
  v_47
  Z
  N1
  E
  E1
  T
  V
  K
  A1
  I1
  H1
  L1
  B
  S
  F
  C
  W
  U
  Y
  J1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (v_35 Int) (v_36 Int) (v_37 Int) (v_38 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block11_3|
  E1
  I1
  G1
  C1
  K
  T
  A
  F
  D1
  G
  E
  F1
  S
  W
  P
  N
  v_35
  v_36
  v_37
  v_38
  U
  I
  Z
  D
  J
  H1
  M
  O
  A1
  X
  V
  Q
  L
  B1
  B
  C
  Y
  R
  H)
        (and (= v_35 E1) (= v_36 I1) (= v_37 G1) (= v_38 C1) (= E1 1))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block11_4|
  E1
  I1
  G1
  C1
  K
  T
  A
  F
  D1
  G
  E
  F1
  S
  W
  P
  N
  U
  I
  Z
  D
  A1
  X
  H1
  M
  O
  B1
  B
  C
  Y
  R
  H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block11_4|
  B
  E
  Q
  S
  F1
  E1
  V
  U
  F
  C1
  J
  Y
  N
  I
  D1
  W
  H
  X
  C
  M
  B1
  D
  A1
  Z
  G
  T
  O
  L
  R
  A
  K)
        true
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block11_5|
  B
  E
  Q
  S
  F1
  E1
  V
  U
  F
  C1
  J
  Y
  N
  I
  D1
  W
  H
  X
  C
  P
  M
  B1
  D
  A1
  Z
  G
  T
  O
  L
  R
  A
  K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block11_5|
  C
  V
  Y
  G
  J
  N
  C1
  L
  Q
  U
  I
  T
  W
  F1
  B
  H
  M
  B1
  X
  D1
  F
  E1
  K
  Z
  D
  E
  R
  P
  S
  A1
  O
  A)
        (and (<= D1 2147483647) (<= (- 2147483648) D1))
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block11_6|
  C
  V
  Y
  G
  J
  N
  C1
  L
  Q
  U
  I
  T
  W
  F1
  B
  H
  M
  B1
  X
  D1
  F
  E1
  K
  Z
  D
  E
  R
  P
  S
  A1
  O
  A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block11_6|
  O
  D1
  B1
  V
  T
  H
  G1
  K
  C
  L
  A1
  Q
  C1
  P
  F
  S
  Z
  U
  Y
  G
  E
  J
  I
  E1
  D
  A
  X
  W
  R
  M
  N
  B)
        (= F1 0)
      )
      (|<Main: void main(JayArray_java_lang_String)>_Block11_7|
  O
  D1
  B1
  V
  T
  H
  G1
  K
  C
  L
  A1
  Q
  C1
  P
  F
  S
  F1
  Z
  U
  Y
  G
  E
  J
  I
  E1
  D
  A
  X
  W
  R
  M
  N
  B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) ) 
    (=>
      (and
        (|<Main: void main(JayArray_java_lang_String)>_Block11_7|
  Z
  T
  G
  C
  M
  D
  A
  B1
  F
  N
  E
  J
  I
  R
  G1
  F1
  X
  U
  A1
  E1
  Y
  Q
  D1
  V
  B
  L
  P
  H
  W
  C1
  S
  K
  O)
        (not (= X 0))
      )
      |Assert #0: Main.java, line 13|
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) ) 
    (=>
      (and
        true
      )
      (|<Main: void main(JayArray_java_lang_String)>_pre|
  K
  P
  E
  B
  J
  I
  N
  O
  C
  A
  G
  M
  D
  H
  L
  F)
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        |Assert #0: Main.java, line 13|
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
