; ./seahorn/./sv_comp_flat_small/ldv-linux-3.4-simple/32_1_cilled_true-unreach-call_ok_nondet_linux-3.4-32_1-drivers--w1--slaves--w1_smem.ko-ldv_main0_sequence_infinite_withcheck_stateful.cil.out.c.flat_000.smt2
(set-logic HORN)

(declare-fun |main_1| ( Int ) Bool)

(assert
  (forall ( (v_0 Int) ) 
    (=>
      (and
        (and true (= 0 v_0))
      )
      (main_1 v_0)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Int) (D Bool) (E Int) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (v_15 Int) (v_16 Int) ) 
    (=>
      (and
        (main_1 v_15)
        (and (= 0 v_15)
     (or F (not G) (not I))
     (or D (not H) (not K))
     (or (not B) (not J) (not M))
     (or (not N) (and L O))
     (or (not L) (and J M))
     (or (not J) (= B (= A 0)))
     (or (not J) (and H K))
     (or (not H) (= D (= C 0)))
     (or (not H) (and G I))
     (= N true)
     (= F (= E 0))
     (= 1 v_16))
      )
      (main_1 v_16)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Int) (D Bool) (E Int) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (v_21 Int) (v_22 Int) ) 
    (=>
      (and
        (main_1 v_21)
        (and (= 0 v_21)
     (or (and N Q) (and L R) (not P) (and S G))
     (or F (not G) (not I))
     (or (not F) (not S) (not G))
     (or B (not O) (not J))
     (or (not H) D (not K))
     (or (not H) (not D) (not M))
     (or (not T) (and P U))
     (or (not N) (and J O))
     (or (not L) (and H M))
     (or (not J) (= B (= A 0)))
     (or (not J) (and H K))
     (or (not H) (= D (= C 0)))
     (or (not H) (and G I))
     (= T true)
     (not P)
     (= F (= E 0))
     (= 2 v_22))
      )
      (main_1 v_22)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Bool) (v_5 Int) (v_6 Int) ) 
    (=>
      (and
        (main_1 v_5)
        (and (= 1 v_5)
     (or (not B) (not C) (not E))
     (or (not D) (and C E))
     (= D true)
     (= B (= A 0))
     (= 1 v_6))
      )
      (main_1 v_6)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (v_11 Int) (v_12 Int) ) 
    (=>
      (and
        (main_1 v_11)
        (and (= 1 v_11)
     (or B (not J) (not C))
     (or (not I) (and C J))
     (or (not G) (and E H))
     (or (not E) (and D F))
     (or (not D) (and I K))
     (= G true)
     (not E)
     (= B (= A 0))
     (= 2 v_12))
      )
      (main_1 v_12)
    )
  )
)
(assert
  (forall ( (v_0 Int) ) 
    (=>
      (and
        (main_1 v_0)
        (= 2 v_0)
      )
      false
    )
  )
)

(check-sat)
(exit)
