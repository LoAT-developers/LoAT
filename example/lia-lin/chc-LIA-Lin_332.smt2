; ./seahorn/./sv_comp_flat_small/array-examples/standard_vararg_true-unreach-call_ground.c.flat_000.smt2
(set-logic HORN)

(declare-fun |main_1| ( Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (v_4 Int) ) 
    (=>
      (and
        (and true (= 0 v_4))
      )
      (main_1 v_4 A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Bool) (G Int) (H Bool) (I Bool) (J Int) (K Int) (v_11 Int) (v_12 Int) ) 
    (=>
      (and
        (main_1 v_11 B C D E)
        (and (= 0 v_11)
     (or (= K J) (not F) (not I))
     (or (= J 0) (not F) (not I))
     (or (not H) (and F I))
     (= H true)
     (= A G)
     (= 1 v_12))
      )
      (main_1 v_12 B C G K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Int) (E Int) (F Int) (G Int) (H Bool) (I Int) (J Int) (K Int) (L Bool) (M Bool) (v_13 Int) (v_14 Int) ) 
    (=>
      (and
        (main_1 v_13 D E F G)
        (and (= 1 v_13)
     (= A (+ F (* 4 G)))
     (= K (+ 1 G))
     (or (= I K) (not H) (not M))
     (or (= J I) (not H) (not M))
     (or C (not H) (not M))
     (or (not L) (and H M))
     (= L true)
     (not (= (<= B (- 1)) C))
     (= 1 v_14))
      )
      (main_1 v_14 D E F J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Bool) (K Int) (L Bool) (M Bool) (N Int) (O Bool) (P Bool) (Q Int) (v_17 Int) (v_18 Int) ) 
    (=>
      (and
        (main_1 v_17 F G H I)
        (and (= 1 v_17)
     (= B (+ H (* 4 I)))
     (= K (+ 1 I))
     (or (= E I) (not J) (not M))
     (or (= N E) (not J) (not M))
     (or (not D) (not J) (not M))
     (or (= A Q) (not L) (not P))
     (or (= Q 0) (not L) (not P))
     (or (not O) (and L P))
     (or (not L) (and J M))
     (= O true)
     (not (= (<= C (- 1)) D))
     (= 2 v_18))
      )
      (main_1 v_18 A N H I)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Int) (M Int) (N Bool) (O Bool) (v_15 Int) (v_16 Int) ) 
    (=>
      (and
        (main_1 v_15 G H I J)
        (and (= 2 v_15)
     (not (= (<= H G) A))
     (not (= D E))
     (= B (+ I (* 4 G)))
     (= M (+ 1 G))
     (or (not O) (not K) (= F L))
     (or (not O) (not K) (= L M))
     (or (not E) (not O) (not K))
     (or (not N) (and O K))
     (= A true)
     (= N true)
     (not (= (<= C (- 1)) D))
     (= 2 v_16))
      )
      (main_1 v_16 F H I J)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Bool) (K Int) (L Bool) (M Bool) (v_13 Int) (v_14 Int) ) 
    (=>
      (and
        (main_1 v_13 F G H I)
        (and (= 2 v_13)
     (not (= (<= C (- 1)) D))
     (not (= D E))
     (= B (+ H (* 4 F)))
     (= K (+ 1 F))
     (or E (not J) (not M))
     (or (not L) (and J M))
     (= A true)
     (= L true)
     (not (= (<= G F) A))
     (= 3 v_14))
      )
      (main_1 v_14 F G H I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (v_4 Int) ) 
    (=>
      (and
        (main_1 v_4 A B C D)
        (= 3 v_4)
      )
      false
    )
  )
)

(check-sat)
(exit)
