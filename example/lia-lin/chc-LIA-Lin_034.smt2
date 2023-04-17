; ./aeval-unsafe/./unsafe/s_split_34_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (= A 1) (= B 0))
      )
      (inv B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv D C)
        (let ((a!1 (ite (and (not (<= B (- 100))) (not (<= 100 B))) C (* (- 1) C))))
  (and (= A a!1) (= B (+ D C))))
      )
      (inv B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv A B)
        (and (<= A 100) (>= A (- 100)))
      )
      false
    )
  )
)

(check-sat)
(exit)
