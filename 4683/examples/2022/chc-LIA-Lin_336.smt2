; ./seahorn/./sv_comp_flat_small/termination-crafted-lit/AliasDarteFeautrierGonnord-SAS2010-rsd_true-termination.c.flat_000.smt2
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
  (forall ( (A Int) (B Int) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Bool) (I Int) (J Bool) (K Bool) (L Int) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (v_18 Int) (v_19 Int) ) 
    (=>
      (and
        (main_1 v_18 E F G)
        (let ((a!1 (or (not J) (not (= (<= I L) C)))))
  (and (= 0 v_18)
       (or (= B R) (not M) (not P))
       (or (= A Q) (not M) (not P))
       (or (= R L) (not M) (not P))
       (or (= Q L) (not M) (not P))
       (or D (not H) (not K))
       (or (not C) (not J) (not N))
       (or (not O) (and M P))
       (or (not M) (and J N))
       (or (not J) (= L (* 2 I)))
       a!1
       (or (not J) (and H K))
       (= O true)
       (not (= (<= I (- 1)) D))
       (= 1 v_19)))
      )
      (main_1 v_19 B A I)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Bool) (G Int) (H Bool) (I Bool) (J Int) (K Bool) (L Bool) (M Bool) (v_13 Int) (v_14 Int) ) 
    (=>
      (and
        (main_1 v_13 C D E)
        (let ((a!1 (or (not H) (not (= (<= G J) A)))))
  (and (= 0 v_13)
       (or (and H L) (and F M) (not K))
       (or A (not H) (not L))
       (or (not B) (not F) (not M))
       (or B (not I) (not F))
       (or (not H) (= J (* 2 G)))
       a!1
       (or (not H) (and F I))
       (= K true)
       (not (= (<= G (- 1)) B))
       (= 2 v_14)))
      )
      (main_1 v_14 C D G)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Int) (D Int) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Int) (M Int) (N Int) (O Int) (P Bool) (Q Bool) (v_17 Int) (v_18 Int) ) 
    (=>
      (and
        (main_1 v_17 H I J)
        (and (= 1 v_17)
     (= N (ite B D C))
     (= D (+ (- 1) I))
     (= O (ite B D I))
     (not (= (<= J N) E))
     (= B (= A 0))
     (or (not Q) (not K) (= M N))
     (or (not Q) (not K) (= L O))
     (or (not Q) (not K) (= G M))
     (or (not Q) (not K) (= F L))
     (or (not E) (not Q) (not K))
     (or (not P) (and Q K))
     (= P true)
     (= C (+ (- 1) H))
     (= 1 v_18))
      )
      (main_1 v_18 G F J)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Int) (D Int) (E Bool) (F Int) (G Int) (H Int) (I Bool) (J Bool) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (v_15 Int) (v_16 Int) ) 
    (=>
      (and
        (main_1 v_15 F G H)
        (and (= 1 v_15)
     (= L (ite B D G))
     (= D (+ (- 1) G))
     (= C (+ (- 1) F))
     (not (= (<= H K) E))
     (= B (= A 0))
     (or E (not N) (not I))
     (or (not M) (and N I))
     (or (not J) (and M O))
     (= J true)
     (= K (ite B D C))
     (= 2 v_16))
      )
      (main_1 v_16 F G H)
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
