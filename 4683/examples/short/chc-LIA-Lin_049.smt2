; ./prepared/aeval-unsafe/./unsafe/s_split_43_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (= A 0) (= B 0))
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
        (let ((a!1 (= A (ite (>= D 50000000) (ite (>= D 100000000) C (+ 1 C)) 0))))
  (and a!1 (= B (+ 1 D))))
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
        (and (>= B 100000000) (= A 50000000))
      )
      false
    )
  )
)

(check-sat)
(exit)
