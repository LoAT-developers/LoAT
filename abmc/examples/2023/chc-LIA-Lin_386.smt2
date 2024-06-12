; ./prepared/sv-comp/./2015-05-26/LIA/Eldarica/linear-tree-like/rotation_vc.correct.3.nts.horn-0001_000.smt2
(set-logic HORN)


(declare-fun |predr17_2| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predr3_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predr12_3| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predr11_4| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (predr17_2 Z Y X W V U T S R Q P O N M L A K J I H G F E D)
        (and (= B (+ 1 G))
     (= C (+ 1 G))
     (<= 1 (+ (* (- 1) M) E))
     (<= 1 (+ L (* (- 1) G)))
     (= A (+ 1 G)))
      )
      (predr3_1 Z Y X W V U T S R Q P O N M L C K J I H B F E D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (v_26 Int) (v_27 Int) ) 
    (=>
      (and
        (predr12_3 Z Y X W V U T S R Q P O N H M L K B A J I v_26 G F)
        (and (= v_26 H)
     (= B (+ 1 I))
     (= C (+ 1 I))
     (= D (+ 1 I))
     (= E (+ 1 I))
     (<= 2 (+ L (* (- 1) I)))
     (<= 1 (+ J (* (- 1) I)))
     (= A (+ 1 I))
     (= v_27 G))
      )
      (predr17_2 Z Y X W V U T S R Q P O N H M L K E D J C G v_27 F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (v_25 Int) (v_26 Int) (v_27 Int) ) 
    (=>
      (and
        (predr11_4 Y X W V U T S R Q P O N M L K J I H G A F E v_25 D)
        (and (= v_25 E)
     (= B (+ 1 F))
     (= C (+ 1 F))
     (<= 2 (+ G (* (- 1) F)))
     (<= 2 (+ J (* (- 1) F)))
     (= A (+ 1 F))
     (= v_26 E)
     (= v_27 E))
      )
      (predr12_3 Y X W V U T S R Q P O N M E K J I H G C B v_26 v_27 D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (v_18 Int) (v_19 Int) (v_20 Int) (v_21 Int) (v_22 Int) (v_23 Int) ) 
    (=>
      (and
        (and (<= 2 (+ E (* (- 1) D)))
     (<= 2 D)
     (<= 0 (+ F (* (- 1) E)))
     (= A (+ 1 D))
     (= 0 v_18)
     (= v_19 E)
     (= 1 v_20)
     (= v_21 C)
     (= v_22 C)
     (= v_23 B))
      )
      (predr11_4 R Q P O N M L K J I H G v_18 C E F B v_19 A D v_20 v_21 v_22 v_23)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (predr3_1 X W V U T S R Q P O N M L K J I H G F E D C B A)
        (not (= 0 L))
      )
      false
    )
  )
)

(check-sat)
(exit)
