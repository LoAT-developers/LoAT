; ./aeval/./multi-phase/s_split_40_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int ) Bool)
(declare-fun |fail| ( ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= B 0) (= C 0) (= A 0))
      )
      (inv A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv B A C)
        (let ((a!1 (or (not (<= B 100)) (not (<= 5 (mod B 10))))))
  (and (= E (ite a!1 (+ 1 A) A)) (= F (ite a!1 C (+ 1 C))) (= D (+ 1 B))))
      )
      (inv D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv A B C)
        (and (<= B C) (not (<= A 100)))
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
