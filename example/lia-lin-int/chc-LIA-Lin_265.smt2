; ./aeval/./multi-phase/s_split_05_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int ) Bool)
(declare-fun |fail| ( ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (not (<= 0 B)) (not (<= A 0)) (= C 1))
      )
      (inv A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv A B C)
        (and (= E (+ 2 B)) (= F (ite (>= B 0) (* 2 C) C)) (= D (+ 1 A)))
      )
      (inv D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv B A C)
        (and (<= C 1) (>= A B))
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
