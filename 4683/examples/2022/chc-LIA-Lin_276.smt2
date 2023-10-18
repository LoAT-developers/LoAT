; ./aeval/./multi-phase/s_split_20_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int ) Bool)
(declare-fun |fail| ( ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= B 0) (= C (- 1)) (= A 0))
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
        (let ((a!1 (= F (ite (= (mod B 2) 0) (+ 1 C) C))))
  (and (= E (+ (* (- 1) A) (* (- 1) B))) a!1 (= D (+ 1 B))))
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
        (and (= A 942573485) (not (= 0 (+ B C))))
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
