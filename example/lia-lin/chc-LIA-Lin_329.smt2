; ./seahorn/./sv_comp_flat_small/termination-crafted-lit/LeikeHeizmann-WST2014-Ex6_false-termination.c.flat_000.smt2
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
  (forall ( (A Int) (B Int) (C Bool) (D Bool) (E Bool) (F Int) (G Int) (H Bool) (I Int) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Int) (P Int) (v_16 Int) (v_17 Int) ) 
    (=>
      (and
        (main_1 v_16 F G)
        (and (= 0 v_16)
     (not (= (<= I 0) C))
     (= E (and C D))
     (or (= B P) (not K) (not N))
     (or (= A O) (not K) (not N))
     (or (= P I) (not K) (not N))
     (or (= O J) (not K) (not N))
     (or E (not H) (not L))
     (or (not M) (and K N))
     (or (not K) (and H L))
     (= M true)
     (not (= (<= J 0) D))
     (= 1 v_17))
      )
      (main_1 v_17 B A)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Bool) (G Int) (H Int) (I Bool) (J Bool) (v_10 Int) (v_11 Int) ) 
    (=>
      (and
        (main_1 v_10 D E)
        (and (= 0 v_10)
     (not (= (<= G 0) A))
     (= C (and B A))
     (or (not C) (not F) (not J))
     (or (not I) (and F J))
     (= I true)
     (not (= (<= H 0) B))
     (= 2 v_11))
      )
      (main_1 v_11 D E)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Int) (G Int) (H Bool) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (v_14 Int) (v_15 Int) ) 
    (=>
      (and
        (main_1 v_14 F G)
        (and (= 1 v_14)
     (= K (* 2 F))
     (not (= (<= F 0) A))
     (not (= (<= G 0) B))
     (= C (and A B))
     (or (not N) (not H) (= J K))
     (or (not N) (not H) (= I L))
     (or (not N) (not H) (= E J))
     (or (not N) (not H) (= D I))
     (or C (not N) (not H))
     (or (not M) (and N H))
     (= M true)
     (= L (* 3 G))
     (= 1 v_15))
      )
      (main_1 v_15 E D)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Bool) (G Bool) (H Int) (I Int) (J Bool) (K Bool) (L Bool) (v_12 Int) (v_13 Int) ) 
    (=>
      (and
        (main_1 v_12 D E)
        (and (= 1 v_12)
     (= I (* 3 E))
     (not (= (<= D 0) A))
     (not (= (<= E 0) B))
     (= C (and A B))
     (or (not C) (not K) (not F))
     (or (not J) (and K F))
     (or (not G) (and J L))
     (= G true)
     (= H (* 2 D))
     (= 2 v_13))
      )
      (main_1 v_13 D E)
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
