; ./prepared/sv-comp/./2015-05-26/LIA/Eldarica/linear-tree-like/qrsolv.smt2-0002_000.smt2
(set-logic HORN)


(declare-fun |predh5_2| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh14_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (v_34 Int) (v_35 Int) ) 
    (=>
      (and
        (predh5_2 H1
          G1
          F1
          E1
          D1
          C1
          B1
          A1
          Z
          Y
          X
          W
          V
          U
          T
          S
          R
          Q
          P
          O
          N
          M
          L
          K
          J
          I
          H
          G
          F
          E
          D
          C
          B
          A)
        (and (<= 1 (+ P (* (- 1) K))) (= v_34 K) (= 0 v_35))
      )
      (predh14_1 H1
           G1
           F1
           E1
           D1
           C1
           B1
           A1
           Z
           Y
           X
           W
           V
           U
           T
           S
           R
           Q
           P
           O
           N
           M
           K
           v_34
           v_35
           I
           H
           G
           F
           E
           D
           C
           B
           A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (v_17 Int) (v_18 Int) (v_19 Int) (v_20 Int) (v_21 Int) (v_22 Int) (v_23 Int) (v_24 Int) (v_25 Int) (v_26 Int) (v_27 Int) (v_28 Int) (v_29 Int) (v_30 Int) (v_31 Int) (v_32 Int) (v_33 Int) ) 
    (=>
      (and
        (and true
     (= v_17 H)
     (= v_18 A)
     (= v_19 G)
     (= v_20 F)
     (= v_21 E)
     (= v_22 D)
     (= 1 v_23)
     (= v_24 C)
     (= v_25 B)
     (= 1 v_26)
     (= v_27 A)
     (= 1 v_28)
     (= v_29 A)
     (= 1 v_30)
     (= v_31 A)
     (= 1 v_32)
     (= v_33 A))
      )
      (predh5_2 H
          A
          G
          F
          E
          D
          Q
          C
          B
          P
          O
          N
          M
          L
          K
          J
          I
          v_17
          v_18
          v_19
          v_20
          v_21
          v_22
          v_23
          v_24
          v_25
          v_26
          v_27
          v_28
          v_29
          v_30
          v_31
          v_32
          v_33)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) ) 
    (=>
      (and
        (predh14_1 H1
           G1
           F1
           E1
           D1
           C1
           B1
           A1
           Z
           Y
           X
           W
           V
           U
           T
           S
           R
           Q
           P
           O
           N
           M
           L
           K
           J
           I
           H
           G
           F
           E
           D
           C
           B
           A)
        (and (<= 0 (+ (* (- 1) L) C))
     (<= 0 (+ L (* (- 1) D)))
     (<= 0 (+ P (* (- 1) L)))
     (<= 1 (+ (* (- 1) L) H)))
      )
      false
    )
  )
)

(check-sat)
(exit)
