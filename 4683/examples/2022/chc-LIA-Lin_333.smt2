; ./seahorn/./sv_comp_flat_small/ldv-linux-3.4-simple/32_1_cilled_true-unreach-call_ok_nondet_linux-3.4-32_1-drivers--net--phy--vitesse.ko-ldv_main0_sequence_infinite_withcheck_stateful.cil.out.c.flat_000.smt2
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
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Int) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (v_18 Int) (v_19 Int) ) 
    (=>
      (and
        (main_1 v_18)
        (let ((a!1 (or (not H) (not (= (<= 0 J) D)))))
  (and (= 0 v_18)
       (or (not N) (not K) C)
       (or (not B) (not P) (not M))
       (or (not F) (not I) (not G))
       (or (not D) (not L) (not H))
       (or (not O) (and M P))
       (or (not K) (= C (= J 0)))
       (or (not K) (and L H))
       a!1
       (or (not H) (and G I))
       (or (not Q) (and R O))
       (or (not M) (= B (= A 0)))
       (or (not M) (and N K))
       (= Q true)
       (not (= (<= 0 E) F))
       (= 1 v_19)))
      )
      (main_1 v_19)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Int) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (v_25 Int) (v_26 Int) ) 
    (=>
      (and
        (main_1 v_25)
        (let ((a!1 (or (not H) (not (= (<= 0 J) D)))))
  (and (= 0 v_25)
       (or (and K U) (and Q V) (and T O) (and W G) (not S))
       (or D (not H) (not R))
       (or (not D) (not L) (not H))
       (or (not I) (not F) (not G))
       (or F (not G) (not W))
       (or (not P) (not M) B)
       (or (not K) (not C) (not U))
       (or (not K) C (not N))
       (or (not M) (= B (= A 0)))
       (or (not M) (and K N))
       (or (not O) (and P M))
       a!1
       (or (not H) (and I G))
       (or (not X) (and S Y))
       (or (not Q) (and H R))
       (or (not K) (= C (= J 0)))
       (or (not K) (and H L))
       (= X true)
       (not S)
       (not (= (<= 0 E) F))
       (= 2 v_26)))
      )
      (main_1 v_26)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Bool) (v_5 Int) (v_6 Int) ) 
    (=>
      (and
        (main_1 v_5)
        (and (= 1 v_5)
     (or (not E) (not C) (not B))
     (or (not D) (and E C))
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
     (or B (not C) (not J))
     (or (not D) (and K I))
     (or (not I) (and C J))
     (or (not G) (and E H))
     (or (not E) (and F D))
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
