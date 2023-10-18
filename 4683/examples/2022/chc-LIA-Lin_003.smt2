; ./extra-small-lia/./s_mutants_05_000.smt2
(set-logic HORN)

(declare-fun |itp| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (not (<= B A)) (= A 0))
      )
      (itp A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (itp A B)
        (and (= C (+ 1 A)) (= D (+ 2 B)))
      )
      (itp C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (itp A B)
        (and (not (<= A 1000)) (<= B 2000))
      )
      false
    )
  )
)

(check-sat)
(exit)
