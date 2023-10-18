; ./seahorn/./sv_comp_flat_small/loop-new/count_by_k_true-unreach-call.c.flat_000.smt2
(set-logic HORN)

(declare-fun |main_1| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (v_3 Int) ) 
    (=>
      (and
        (and true (= 0 v_3))
      )
      (main_1 v_3 A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Int) (D Int) (E Int) (F Bool) (G Int) (H Bool) (I Bool) (J Int) (K Int) (v_11 Int) (v_12 Int) ) 
    (=>
      (and
        (main_1 v_11 C D E)
        (and (= 0 v_11)
     (not (= (<= 11 A) B))
     (or (= K J) (not F) (not I))
     (or (= J 0) (not F) (not I))
     (or (not H) (and F I))
     (= H true)
     (= B true)
     (= G (* 1000000 A))
     (= 1 v_12))
      )
      (main_1 v_12 G K A)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Int) (E Bool) (F Int) (G Int) (H Int) (I Bool) (J Bool) (v_10 Int) (v_11 Int) ) 
    (=>
      (and
        (main_1 v_10 B C D)
        (and (= 1 v_10)
     (not (= (<= B C) A))
     (or (= G F) (not E) (not J))
     (or (= F H) (not E) (not J))
     (or A (not E) (not J))
     (or (not I) (and E J))
     (= I true)
     (= H (+ C D))
     (= 1 v_11))
      )
      (main_1 v_11 B G D)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Int) (G Int) (H Bool) (I Int) (J Bool) (K Bool) (L Int) (M Bool) (N Bool) (v_14 Int) (v_15 Int) ) 
    (=>
      (and
        (main_1 v_14 E F G)
        (and (= 1 v_14)
     (not (= (<= E F) C))
     (or (not K) (not H) (= D L))
     (or (not K) (not H) (= L F))
     (or (not C) (not K) (not H))
     (or (not J) (= A (= D E)))
     (or (not J) (not (= A B)))
     (or (not J) (and K H))
     (or B (not J))
     (or (not M) (and N J))
     (= M true)
     (= I (+ F G))
     (= 2 v_15))
      )
      (main_1 v_15 E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (v_3 Int) ) 
    (=>
      (and
        (main_1 v_3 A B C)
        (= 2 v_3)
      )
      false
    )
  )
)

(check-sat)
(exit)
