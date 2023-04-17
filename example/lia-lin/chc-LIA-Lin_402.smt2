; ./seahorn/./sv_comp_flat_small/loop-acceleration/simple_false-unreach-call4.c.flat_000.smt2
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
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (v_6 Int) (v_7 Int) ) 
    (=>
      (and
        (main_1 v_6 A)
        (and (= 0 v_6)
     (or (= F E) (not B) (not D))
     (or (not C) (and B D))
     (= C true)
     (or (= E 268435441) (not B) (not D))
     (= 1 v_7))
      )
      (main_1 v_7 F)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Bool) (D Int) (E Int) (F Int) (G Bool) (H Bool) (v_8 Int) (v_9 Int) ) 
    (=>
      (and
        (main_1 v_8 B)
        (and (= 1 v_8)
     (= F (+ (- 2) B))
     (or (= E D) (not C) (not H))
     (or (= D F) (not C) (not H))
     (or A (not C) (not H))
     (or (not G) (and C H))
     (= G true)
     (not (= (<= B 1) A))
     (= 1 v_9))
      )
      (main_1 v_9 E)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Bool) (H Int) (I Bool) (J Bool) (K Int) (L Bool) (M Bool) (v_13 Int) (v_14 Int) ) 
    (=>
      (and
        (main_1 v_13 F)
        (and (= 1 v_13)
     (= H (+ (- 2) F))
     (or (not J) (not G) (= E F))
     (or (not J) (not G) (= K E))
     (or (not D) (not J) (not G))
     (or (not L) (and I M))
     (or (not I) (= B (= A 0)))
     (or (not I) (not (= B C)))
     (or (not I) (and J G))
     (or (not I) C)
     (= L true)
     (not (= (<= F 1) D))
     (= 2 v_14))
      )
      (main_1 v_14 F)
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
