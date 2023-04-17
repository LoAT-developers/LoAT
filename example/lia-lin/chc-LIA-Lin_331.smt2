; ./seahorn/./sv_comp_flat_small/termination-crafted-lit/ChenFlurMukhopadhyay-SAS2012-Ex2.12_false-termination.c.flat_000.smt2
(set-logic HORN)

(declare-fun |main_1| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (v_2 Int) ) 
    (=>
      (and
        (and true (= 0 v_2))
      )
      (main_1 v_2 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Int) (E Int) (F Bool) (G Int) (H Int) (I Bool) (J Bool) (K Bool) (L Bool) (M Int) (N Int) (v_14 Int) (v_15 Int) ) 
    (=>
      (and
        (main_1 v_14 D E)
        (and (= 0 v_14)
     (or (= B N) (not I) (not L))
     (or (= A M) (not I) (not L))
     (or (= N G) (not I) (not L))
     (or (= M H) (not I) (not L))
     (or C (not F) (not J))
     (or (not K) (and I L))
     (or (not I) (and F J))
     (= K true)
     (not (= (<= 5 G) C))
     (= 1 v_15))
      )
      (main_1 v_15 B A)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Bool) (G Bool) (v_7 Int) (v_8 Int) ) 
    (=>
      (and
        (main_1 v_7 B C)
        (and (= 0 v_7)
     (or (not A) (not D) (not G))
     (or (not F) (and D G))
     (= F true)
     (not (= (<= 5 E) A))
     (= 2 v_8))
      )
      (main_1 v_8 B C)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Int) (E Int) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Bool) (v_12 Int) (v_13 Int) ) 
    (=>
      (and
        (main_1 v_12 D E)
        (and (= 1 v_12)
     (= J (+ E D))
     (not (= (<= 5 I) A))
     (or (not F) (= H I) (not L))
     (or (not F) (= G J) (not L))
     (or (not F) (= C H) (not L))
     (or (not F) (= B G) (not L))
     (or A (not F) (not L))
     (or (not K) (and F L))
     (= K true)
     (= I (+ D (* (- 1) E)))
     (= 1 v_13))
      )
      (main_1 v_13 C B)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Bool) (F Int) (G Int) (H Bool) (I Bool) (J Bool) (v_10 Int) (v_11 Int) ) 
    (=>
      (and
        (main_1 v_10 B C)
        (and (= 1 v_10)
     (= F (+ B (* (- 1) C)))
     (not (= (<= 5 F) A))
     (or (not D) (not A) (not I))
     (or (not H) (and D I))
     (or (not E) (and H J))
     (= E true)
     (= G (+ C B))
     (= 2 v_11))
      )
      (main_1 v_11 B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (v_2 Int) ) 
    (=>
      (and
        (main_1 v_2 A B)
        (= 2 v_2)
      )
      false
    )
  )
)

(check-sat)
(exit)
