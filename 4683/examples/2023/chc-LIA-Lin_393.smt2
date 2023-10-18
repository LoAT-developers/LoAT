; ./prepared/sv-comp/./2015-05-26/LIA/Eldarica/linear-tree-like/lop.smt2-0006_000.smt2
(set-logic HORN)


(declare-fun |predh14_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh5_2| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) ) 
    (=>
      (and
        (predh5_2 K1
          J1
          I1
          H1
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
          B)
        (and (<= 1 (+ Q (* (- 1) G))) (= A 2))
      )
      (predh14_1 K1
           J1
           I1
           H1
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
           A
           G
           F
           E
           D
           C
           B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (v_21 Int) (v_22 Int) (v_23 Int) (v_24 Int) (v_25 Int) (v_26 Int) (v_27 Int) (v_28 Int) (v_29 Int) (v_30 Int) (v_31 Int) (v_32 Int) (v_33 Int) (v_34 Int) (v_35 Int) ) 
    (=>
      (and
        (and (= A 2)
     (= v_21 J)
     (= v_22 I)
     (= v_23 H)
     (= 1 v_24)
     (= v_25 H)
     (= 1 v_26)
     (= v_27 H)
     (= 1 v_28)
     (= v_29 H)
     (= 1 v_30)
     (= v_31 H)
     (= v_32 G)
     (= v_33 D)
     (= v_34 C)
     (= v_35 B))
      )
      (predh5_2 J
          I
          H
          U
          T
          S
          R
          Q
          P
          O
          N
          G
          M
          L
          K
          D
          C
          B
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
          A
          F
          E
          v_33
          v_34
          v_35)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) ) 
    (=>
      (and
        (predh14_1 J1
           I1
           H1
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
        (and (<= 1 (+ (* (- 1) K) G))
     (<= 1 (+ H (* (- 1) F)))
     (<= 1 (+ J (* (- 1) G)))
     (<= 1 (+ M (* (- 1) F)))
     (<= 1 (+ P (* (- 1) G)))
     (<= 0 (+ (* (- 1) O) G))
     (<= 0 (+ N (* (- 1) G)))
     (<= 1 (+ (* (- 1) I) F)))
      )
      false
    )
  )
)

(check-sat)
(exit)
