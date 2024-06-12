; ./prepared/sv-comp/./2015-05-26/LIA/Eldarica/linear-tree-like/bubblesort.error.nts.horn-0000_000.smt2
(set-logic HORN)


(declare-fun |predr12_2| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predr15_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (v_23 Int) (v_24 Int) ) 
    (=>
      (and
        (predr12_2 W V U T S R Q P O N M L K J I H G F E D C B A v_23)
        (and (= 1 v_23) (= 1 v_24))
      )
      (predr15_1 W V U T S R Q P O N M L K J I H G F E D C B A v_24)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (v_13 Int) (v_14 Int) (v_15 Int) (v_16 Int) (v_17 Int) (v_18 Int) (v_19 Int) (v_20 Int) (v_21 Int) (v_22 Int) (v_23 Int) ) 
    (=>
      (and
        (and (<= 1 B)
     (= A (+ 1 B))
     (= 1 v_13)
     (= v_14 K)
     (= v_15 J)
     (= v_16 I)
     (= v_17 H)
     (= v_18 G)
     (= v_19 F)
     (= v_20 E)
     (= v_21 D)
     (= v_22 C)
     (= 1 v_23))
      )
      (predr12_2 M
           K
           J
           I
           H
           G
           F
           E
           D
           C
           L
           A
           v_13
           v_14
           v_15
           v_16
           v_17
           v_18
           v_19
           v_20
           v_21
           v_22
           B
           v_23)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (predr15_1 X W V U T S R Q P O N M L K J I H G F E D C A B)
        (= A 2)
      )
      false
    )
  )
)

(check-sat)
(exit)
