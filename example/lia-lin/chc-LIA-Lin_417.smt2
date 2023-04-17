; ./sv-comp/./2015-05-26/LIA/Eldarica/linear-tree-like/inf8.correct.nts.horn-0003_000.smt2
(set-logic HORN)

(declare-fun |predr18_2| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predr14_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (v_30 Int) ) 
    (=>
      (and
        (predr18_2 Z Y X W V U T S R Q P O N M L K J I H G F E D C B A)
        (and (<= H 0) (= 1 v_30))
      )
      (predr14_1 Z Y X W V U T S R Q P O N D1 C1 B1 A1 I H G F E D C v_30 A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (v_20 Int) (v_21 Int) (v_22 Int) (v_23 Int) (v_24 Int) (v_25 Int) ) 
    (=>
      (and
        (and (not (= 0 C))
     (not (= 0 B))
     (= 0 v_20)
     (= 0 v_21)
     (= 0 v_22)
     (= v_23 A)
     (= 0 v_24)
     (= 0 v_25))
      )
      (predr18_2 A
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
           v_20
           v_21
           D
           v_22
           C
           B
           v_23
           v_24
           v_25)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (predr14_1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B A)
        (and (<= A 0) (<= F 0) (<= I 0) (<= 1 H))
      )
      false
    )
  )
)

(check-sat)
(exit)
