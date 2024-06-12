; ./prepared/seahorn/./sv_comp_flat_small/float-benchs/zonotope_3.c.flat_000.smt2
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
     (or (= F 1) (not E) (not C))
     (or (not D) (and C E))
     (= D true)
     (or (= A F) (not E) (not C))
     (= 1 v_7))
      )
      (main_1 v_7 A)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Bool) (G Int) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Int) (Q Bool) (R Bool) (v_18 Int) (v_19 Int) ) 
    (=>
      (and
        (main_1 v_18 E)
        (let ((a!1 (or (not K) (not (= (<= 100001 P) A)))))
  (and (= 1 v_18)
       (or (= G P) (not K) (not R))
       (or (= D G) (not K) (not R))
       (or (= N J) (not H) (not L))
       (or (= C N) (not H) (not L))
       (or (= C O) (not F) (not M))
       (or B (not F) (not M))
       (or (not B) (not F) (not I))
       (or A (not K) (not R))
       (or (not O) (not F) (not M))
       a!1
       (or (not K) (= P (+ 1 E)))
       (or (not H) (and F I))
       (or C (not K))
       (or (not Q) (and K R))
       (= Q true)
       (or (and H L) (and F M) (not K))
       (= 1 v_19)))
      )
      (main_1 v_19 D)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (v_29 Int) (v_30 Int) ) 
    (=>
      (and
        (main_1 v_29 G)
        (let ((a!1 (or (not L) (not (= (<= 100001 Q) D)))))
  (and (= 1 v_29)
       (or (not Y) (not R) (= C A1))
       (or B (not R) (not Y))
       (or (and T X) (not W) (and Y R))
       (or (not B) (not R) (not U))
       (or (= C Z) (not X) (not T))
       (or (= Z V) (not X) (not T))
       (or (not N) (not H) (= F P))
       (or (not P) (not N) (not H))
       (or E (not N) (not H))
       (or (not M) (not I) (= O K))
       (or (not M) (not I) (= F O))
       (or (not L) (and N H) (and M I))
       (or (not D) (not S) (not L))
       (or (not A1) (not Y) (not R))
       (or (not R) (and L S))
       (or (not I) (and H J))
       (or (not W) (not (= C A)))
       (or (not W) A)
       (or (not T) (and U R))
       a!1
       (or (not L) (= Q (+ 1 G)))
       (or (not L) F)
       (or (not B1) (and W C1))
       (= B1 true)
       (or (not E) (not H) (not J))
       (= 2 v_30)))
      )
      (main_1 v_30 G)
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
