; ./aeval/./multi-phase/s_split_29_000.smt2
(set-logic HORN)

(declare-fun |fail| ( ) Bool)
(declare-fun |inv| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= B 0) (= C 0) (= D 0) (= A 0))
      )
      (inv A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv C B A D)
        (let ((a!1 (ite (<= (+ B (* (- 10) C)) 0) A (+ 1 A)))
      (a!2 (ite (<= (+ B (* (- 10) C)) 0) (+ 1 D) D)))
  (and (= F (+ B C)) (= G a!1) (= H a!2) (= E (+ 1 C))))
      )
      (inv E F G H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv B A C D)
        (and (<= C D) (not (<= B 100)))
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
