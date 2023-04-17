; ./aeval/./multi-phase/s_split_49_000.smt2
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
        (let ((a!1 (= D
              (ite (>= A 7500)
                   (ite (>= A 12500) (+ (- 2) B) (+ 1 B))
                   (ite (>= A 2500) (+ 1 B) (+ (- 2) B))))))
  (and a!1 (= C (+ 1 A))))
      )
      (inv C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv A B)
        (and (not (= B 0)) (= A 15000))
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
