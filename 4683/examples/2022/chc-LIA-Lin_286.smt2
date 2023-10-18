; ./aeval/./multi-phase/s_split_09_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int ) Bool)
(declare-fun |fail| ( ) Bool)

(assert
  (forall ( (A Int) ) 
    (=>
      (and
        (= A 0)
      )
      (inv A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv A)
        (= B (ite (= A 9998) 1 (+ 2 A)))
      )
      (inv B)
    )
  )
)
(assert
  (forall ( (A Int) ) 
    (=>
      (and
        (inv A)
        (and (not (<= A 9996)) (= 0 (mod A 4)))
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
