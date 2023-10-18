; ./aeval/./multi-phase/s_split_10_000.smt2
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
        (= B (ite (<= 200 (div A 5)) (+ 5 A) (+ 1 A)))
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
        (and (>= A 2000) (not (= (mod A 5) 0)))
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
