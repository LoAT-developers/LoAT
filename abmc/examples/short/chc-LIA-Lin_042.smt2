; ./prepared/aeval-unsafe/./unsafe/s_split_41_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (= A 7500) (= B 0))
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
        (let ((a!1 (= B (ite (= 0 (mod D 2)) (+ 2 D) (+ 1 D)))))
  (and (= A (ite (>= D 5000) (+ 1 C) C)) a!1))
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
        (and (= A 10000) (= B 10000))
      )
      false
    )
  )
)

(check-sat)
(exit)
