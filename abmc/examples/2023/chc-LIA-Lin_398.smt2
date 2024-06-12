; ./prepared/sv-comp/./2015-05-26/LIA/Eldarica/linear-tree-like/binarysearch.nts.horn-0000_000.smt2
(set-logic HORN)


(declare-fun |predr0_2| ( Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predr4_1| ( Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (v_10 Int) ) 
    (=>
      (and
        (predr0_2 J I H G F E D C B A)
        (and (<= 1 (+ E (* (- 1) C))) (= 1 v_10))
      )
      (predr4_1 I J H v_10 E C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (v_7 Int) (v_8 Int) (v_9 Int) ) 
    (=>
      (and
        (and (<= 0 E) (<= 0 C) (= v_7 E) (= v_8 D) (= v_9 C))
      )
      (predr0_2 E D C G F v_7 v_8 v_9 B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (predr4_1 F E D C B A)
        (and (<= 0 D) (<= 0 E) (not (= 1 C)))
      )
      false
    )
  )
)

(check-sat)
(exit)
