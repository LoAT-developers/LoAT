; ./seahorn/./sv_comp_flat_small/loops/for_bounded_loop1_false-unreach-call_true-termination.c.flat_000.smt2
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
  (forall ( (A Int) (B Int) (C Bool) (D Int) (E Int) (F Int) (G Int) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Int) (N Int) (O Int) (P Int) (Q Int) (v_17 Int) (v_18 Int) ) 
    (=>
      (and
        (main_1 v_17 D E F G)
        (and (= 0 v_17)
     (or (= M 0) (not I) (not L))
     (or (= A N) (not I) (not L))
     (or (= Q O) (not I) (not L))
     (or (= P M) (not I) (not L))
     (or (= O 0) (not I) (not L))
     (or (= N 0) (not I) (not L))
     (or C (not H) (not J))
     (or (not K) (and I L))
     (or (not I) (and H J))
     (= K true)
     (= C true)
     (not (= (<= B 0) C))
     (= 1 v_18))
      )
      (main_1 v_18 B P A Q)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Bool) (D Int) (E Int) (F Int) (G Int) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (v_14 Int) (v_15 Int) ) 
    (=>
      (and
        (main_1 v_14 D E F G)
        (and (= 0 v_14)
     (or (= L K) (not H) (not J))
     (or K (not H) (not J))
     (or (not C) (not H) (not J))
     (or (not M) (and I N))
     (or (not I) (not (= L A)))
     (or (not I) (and H J))
     (or (not I) A)
     (= M true)
     (= C true)
     (not (= (<= B 0) C))
     (= 2 v_15))
      )
      (main_1 v_15 B E F G)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Bool) (T Bool) (U Int) (V Int) (W Int) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (v_27 Int) (v_28 Int) ) 
    (=>
      (and
        (main_1 v_27 I J K L)
        (let ((a!1 (or (not X) (not (= (<= I W) A))))
      (a!2 (or (not S) (= B (+ L (* (- 1) J)))))
      (a!3 (or (not S) (not (= (= V 0) D))))
      (a!4 (or (not S) (not (= (= U 0) C)))))
  (and (= 1 v_27)
       (not (= F G))
       (or (= H O) (not X) (not A1))
       (or (= R P) (not X) (not A1))
       (or (= Q N) (not X) (not A1))
       (or (= P V) (not X) (not A1))
       (or (= O W) (not X) (not A1))
       (or (= N U) (not X) (not A1))
       (or A (not X) (not A1))
       (or (not E) (not S) (not Y))
       (or (not G) (not T) (not M))
       (or (not Z) (and X A1))
       a!1
       (or (not X) (and S Y))
       (or (not S) (= V (+ U B)))
       a!2
       (or (not S) (= W (+ 1 K)))
       a!3
       a!4
       (or (not S) (not (= D E)))
       (or (not S) (and M T))
       (or (not S) C)
       (= Z true)
       (= F (= L J))
       (= 1 v_28)))
      )
      (main_1 v_28 I Q H R)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Int) (W Int) (X Int) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Int) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (v_35 Int) (v_36 Int) ) 
    (=>
      (and
        (main_1 v_35 J K L M)
        (let ((a!1 (or (not Y) (not (= (<= J X) B))))
      (a!2 (or (not T) (= D (+ M (* (- 1) K)))))
      (a!3 (or (not T) (not (= (= W 0) F))))
      (a!4 (or (not T) (not (= (= V 0) E)))))
  (and (= 1 v_35)
       (not (= H I))
       (or (not R) (and F1 I1) (and O S))
       (or I (not H1) (not N))
       (or G (not G1) (not T))
       (or (not F1) (and H1 N) (and G1 T))
       (or (not B1) (not Y) (= C C1))
       (or (not B1) (not Y) (= C1 W))
       (or (not B) (not B1) (not Y))
       (or (= Q P) (not A1) (not E1))
       (or (= P D1) (not A1) (not E1))
       (or (not G) (not Z) (not T))
       (or (not I) (not U) (not N))
       a!1
       (or (not Y) (and Z T))
       a!2
       (or (not T) (= X (+ 1 L)))
       (or (not T) (= W (+ V D)))
       a!3
       a!4
       (or (not T) (not (= F G)))
       (or (not T) (and U N))
       (or E (not T))
       (or (not O) (not (= Q A)))
       (or (not O) (and A1 E1))
       (or (not O) A)
       (or (not A1) (= D1 (= C 0)))
       (or (not A1) (and B1 Y))
       (= R true)
       (= H (= M K))
       (= 2 v_36)))
      )
      (main_1 v_36 J K L M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (v_4 Int) ) 
    (=>
      (and
        (main_1 v_4 A B C D)
        (= 2 v_4)
      )
      false
    )
  )
)

(check-sat)
(exit)
