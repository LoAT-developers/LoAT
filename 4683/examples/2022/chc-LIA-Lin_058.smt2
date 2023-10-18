; ./aeval-unsafe/./unsafe/s_split_46_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (= B 0)
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
        (let ((a!1 (= B (ite (<= 200 (div D 5)) (+ 5 D) (+ 1 D)))))
  (and (= A (ite (= D 1000) 0 C)) a!1))
      )
      (inv B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv B A)
        (and (>= B 2000) (= A 0))
      )
      false
    )
  )
)

(check-sat)
(exit)
