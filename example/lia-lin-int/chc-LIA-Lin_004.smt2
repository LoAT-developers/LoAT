; ./extra-small-lia/./s_multipl_11_000.smt2
(set-logic HORN)

(declare-fun |LOOPZ| ( Int Int Int ) Bool)
(declare-fun |LOOPY| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (not (<= B A))
      )
      (LOOPY A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (LOOPY A B)
        (and (= C (+ 1000 A)) (not (<= B A)) (= D B))
      )
      (LOOPY C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (v_2 Int) ) 
    (=>
      (and
        (LOOPY A B)
        (and (<= B A) (= 0 v_2))
      )
      (LOOPZ v_2 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (LOOPZ A B C)
        (and (= F (+ 2 C)) (= E B) (not (<= B C)) (= D (+ 1 A)))
      )
      (LOOPZ D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (LOOPZ C A B)
        (and (not (<= C 500)) (<= A B))
      )
      false
    )
  )
)

(check-sat)
(exit)
