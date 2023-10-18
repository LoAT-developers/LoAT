; ./prepared/seahorn/./sv_comp_flat_small/bitvector/jain_1_true-unreach-call.c.flat_000.smt2
(set-logic HORN)


(declare-fun |main_1| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (v_1 Int) ) 
    (=>
      (and
        (and true (= 0 v_1))
      )
      (main_1 v_1 A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Bool) (E Bool) (F Int) (v_6 Int) (v_7 Int) ) 
    (=>
      (and
        (main_1 v_6 B)
        (and (= 0 v_6)
     (or (= F 1) (not C) (not E))
     (or (not D) (and C E))
     (= D true)
     (or (= A F) (not C) (not E))
     (= 1 v_7))
      )
      (main_1 v_7 A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Bool) (E Int) (F Int) (G Bool) (H Int) (I Int) (J Bool) (K Bool) (v_11 Int) (v_12 Int) ) 
    (=>
      (and
        (main_1 v_11 F)
        (and (= 1 v_11)
     (not (= C D))
     (= I (+ B F))
     (= B (* 2 A))
     (or (= H I) (not G) (not K))
     (or (= E H) (not G) (not K))
     (or (not D) (not G) (not K))
     (or (not J) (and G K))
     (= J true)
     (not (= (= I 0) C))
     (= 1 v_12))
      )
      (main_1 v_12 E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Bool) (E Int) (F Bool) (G Int) (H Bool) (I Bool) (v_9 Int) (v_10 Int) ) 
    (=>
      (and
        (main_1 v_9 E)
        (and (= 1 v_9)
     (not (= C D))
     (= B (* 2 A))
     (= G (+ B E))
     (or D (not F) (not I))
     (or (not H) (and F I))
     (= H true)
     (not (= (= G 0) C))
     (= 2 v_10))
      )
      (main_1 v_10 E)
    )
  )
)
(assert
  (forall ( (A Int) (v_1 Int) ) 
    (=>
      (and
        (main_1 v_1 A)
        (= 2 v_1)
      )
      false
    )
  )
)

(check-sat)
(exit)
