; ./llreve/./smt2/loop__break_single_000.smt2
(set-logic HORN)

(declare-fun |INV_MAIN_42| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (v_2 Int) (v_3 Int) ) 
    (=>
      (and
        (and (= A B) (= 0 v_2) (= 0 v_3))
      )
      (INV_MAIN_42 v_2 A v_3 B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (INV_MAIN_42 C D E F)
        (and (= B (+ 1 C))
     (not (= C D))
     (not (= E F))
     (<= C 10)
     (<= E 10)
     (= A (+ 1 E)))
      )
      (INV_MAIN_42 B D A F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (INV_MAIN_42 B C D E)
        (and (not (= B C)) (<= B 10) (or (not (<= D 10)) (= D E)) (= A (+ 1 B)))
      )
      (INV_MAIN_42 A C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (INV_MAIN_42 B C D E)
        (and (not (= D E)) (<= D 10) (or (not (<= B 10)) (= B C)) (= A (+ 1 D)))
      )
      (INV_MAIN_42 B C A E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (INV_MAIN_42 A B C D)
        (and (or (not (<= A 10)) (= A B)) (or (not (<= C 10)) (= C D)) (not (= A C)))
      )
      false
    )
  )
)

(check-sat)
(exit)
