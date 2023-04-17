; ./sv-comp/./2015-05-26/LIA/Eldarica/linear-tree-like/crank.smt2-b-0035_000.smt2
(set-logic HORN)

(declare-fun |predh52_5| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh10_18| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh30_13| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh45_11| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh55_4| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh10_10| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh57_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh30_8| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh6_19| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh41_7| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh10_14| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh22_16| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh18_17| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh45_6| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh25_15| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh30_9| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh41_12| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh52_2| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh45_3| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) ) 
    (=>
      (and
        (predh52_2 T S R Q P O N M L K J I H G F E D C B A)
        (and (<= 0 C) (<= 1 (+ F (* (- 1) C))))
      )
      (predh57_1 T S R Q P O N M L K J I H G F E D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) ) 
    (=>
      (and
        (predh45_3 T S R Q P O N M L K J I H G F E D C B A)
        (and (<= 0 (+ F (* (- 1) D))) (<= 0 D) (<= 1 (+ (* (- 1) F) E)))
      )
      (predh52_2 T S R Q P O N M L K J I H G F E D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (predh55_4 U T S R Q P O N M L K J I H G F E D C B)
        (= A (+ 1 G))
      )
      (predh45_3 U T S R Q P O N M L K J I H A F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) ) 
    (=>
      (and
        (predh52_5 T S R Q P O N M L K J I H G F E D C B A)
        (and (<= 0 C) (<= 0 (+ (* (- 1) F) C)))
      )
      (predh55_4 T S R Q P O N M L K J I H G F E D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) ) 
    (=>
      (and
        (predh45_6 T S R Q P O N M L K J I H G F E D C B A)
        (and (<= 0 (+ F (* (- 1) D))) (<= 0 D) (<= 1 (+ (* (- 1) F) E)))
      )
      (predh52_5 T S R Q P O N M L K J I H G F E D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (v_21 Int) ) 
    (=>
      (and
        (predh41_7 T S R Q P O N M L K J I H G F E D C B A)
        (and (= (- 1) (+ (* 2 U) (* (- 1) G) (* (- 1) E))) (= v_21 G))
      )
      (predh45_6 T S R Q P O N M L K J I H G v_21 E D C B U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) ) 
    (=>
      (and
        (predh30_8 T S R Q P O N M L K J I H G F E D C B A)
        (<= 1 (+ (* (- 1) J) E))
      )
      (predh41_7 T S R Q P O N M L K J I H G F E D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (predh30_9 U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ K (* (- 1) F))) (= A (+ 1 F)))
      )
      (predh30_8 U T S R Q P O N M L K J I H G A E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (predh10_10 U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 1 (+ K (* (- 1) H))) (= A (+ 1 H)))
      )
      (predh30_9 U T S R Q P O N M L K J I H G A E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (v_21 Int) ) 
    (=>
      (and
        (predh45_11 U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ G (* (- 1) F))) (= A (+ (* (- 1) H) F)) (= v_21 F))
      )
      (predh10_10 U T S R Q P O N M L K J I F G v_21 E D A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (v_21 Int) ) 
    (=>
      (and
        (predh41_12 T S R Q P O N M L K J I H G F E D C B A)
        (and (= (- 1) (+ (* 2 U) (* (- 1) G) (* (- 1) E))) (= v_21 G))
      )
      (predh45_11 T S R Q P O N M L K J I H G v_21 E D C B U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) ) 
    (=>
      (and
        (predh30_13 T S R Q P O N M L K J I H G F E D C B A)
        (<= 1 (+ (* (- 1) J) E))
      )
      (predh41_12 T S R Q P O N M L K J I H G F E D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (predh10_14 U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 1 (+ K (* (- 1) H))) (= A (+ 1 H)))
      )
      (predh30_13 U T S R Q P O N M L K J I H G A E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (predh25_15 U T S R Q P O N M L K J I H G F E D C B)
        (= A (+ 1 H))
      )
      (predh10_14 U T S R Q P O N M L K J I A G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) ) 
    (=>
      (and
        (predh22_16 T S R Q P O N M L K J I H G F E D C B A)
        (and (<= 0 C) (<= 0 (+ (* (- 1) G) C)))
      )
      (predh25_15 T S R Q P O N M L K J I H G F E D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) ) 
    (=>
      (and
        (predh18_17 T S R Q P O N M L K J I H G F E D C B A)
        (and (<= 0 D) (<= 0 (+ G (* (- 1) D))))
      )
      (predh22_16 T S R Q P O N M L K J I H G F E D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) ) 
    (=>
      (and
        (predh10_18 T S R Q P O N M L K J I H G F E D C B A)
        (<= 1 (+ J (* (- 1) G)))
      )
      (predh18_17 T S R Q P O N M L K J I H G F E D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) ) 
    (=>
      (and
        (predh6_19 T S R Q P O N M L K J I H G F E D C B A)
        true
      )
      (predh10_18 T S R Q P O N M L K J I H G F E D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (v_8 Int) (v_9 Int) (v_10 Int) (v_11 Int) (v_12 Int) (v_13 Int) (v_14 Int) (v_15 Int) (v_16 Int) (v_17 Int) (v_18 Int) (v_19 Int) ) 
    (=>
      (and
        (and (<= 0 C)
     (= 1 v_8)
     (= v_9 C)
     (= v_10 C)
     (= v_11 G)
     (= v_12 F)
     (= 1 v_13)
     (= v_14 E)
     (= v_15 D)
     (= 1 v_16)
     (= v_17 C)
     (= v_18 B)
     (= v_19 A))
      )
      (predh6_19 C
           G
           F
           H
           E
           D
           v_8
           v_9
           B
           A
           v_10
           v_11
           v_12
           v_13
           v_14
           v_15
           v_16
           v_17
           v_18
           v_19)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) ) 
    (=>
      (and
        (predh57_1 T S R Q P O N M L K J I H G F E D C B A)
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
