; ./aeval/./multi-phase/s_split_39_000.smt2
(set-logic HORN)

(declare-fun |fail| ( ) Bool)
(declare-fun |inv| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (= B 0) (= A 0))
      )
      (inv A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv A B)
        (let ((a!1 (= D (ite (<= B (* 5 A)) (+ 1 B) B)))
      (a!2 (= C (ite (<= B (* 5 A)) (div A 10) (+ 1 A)))))
  (and a!1 a!2))
      )
      (inv C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv B A)
        (and (<= A B) (not (<= A 50)))
      )
      fail
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        fail
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
