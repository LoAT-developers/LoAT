; ./sv-comp/./2015-05-26/LIA/Eldarica/linear-tree-like/rsolv.smt2-0003_000.smt2
(set-logic HORN)

(declare-fun |predh26_2| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (v_31 Int) ) 
    (=>
      (and
        (predh26_2 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 1 L) (= A (+ 1 L)) (= 0 v_31))
      )
      (predh35_1 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A v_31 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (v_16 Int) (v_17 Int) (v_18 Int) (v_19 Int) (v_20 Int) (v_21 Int) (v_22 Int) (v_23 Int) (v_24 Int) (v_25 Int) (v_26 Int) (v_27 Int) (v_28 Int) (v_29 Int) ) 
    (=>
      (and
        (and (<= 11 B)
     (= A (+ (- 1) B))
     (= v_16 G)
     (= v_17 B)
     (= v_18 F)
     (= v_19 E)
     (= v_20 D)
     (= v_21 C)
     (= 1 v_22)
     (= v_23 B)
     (= 1 v_24)
     (= v_25 B)
     (= 1 v_26)
     (= v_27 B)
     (= 1 v_28)
     (= v_29 B))
      )
      (predh26_2 G
           B
           F
           E
           P
           D
           C
           O
           N
           M
           L
           K
           J
           I
           H
           v_16
           v_17
           v_18
           v_19
           A
           v_20
           v_21
           v_22
           v_23
           v_24
           v_25
           v_26
           v_27
           v_28
           v_29)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (predh35_1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B A)
        (and (<= 0 (+ (* (- 1) J) C))
     (<= 0 (+ K (* (- 1) H)))
     (<= 0 (+ J (* (- 1) D)))
     (<= 0 (+ N (* (- 1) J)))
     (<= 1 (+ K (* (- 1) G))))
      )
      false
    )
  )
)

(check-sat)
(exit)
