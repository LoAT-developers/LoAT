; ./aeval-unsafe/./unsafe/s_split_39_000.smt2
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
        (let ((a!1 (= A (ite (<= C (* 5 D)) (+ 1 C) C)))
      (a!2 (= B (ite (<= C (* 5 D)) (div D 10) (+ 1 D)))))
  (and a!1 a!2))
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
        (and (not (<= B A)) (not (<= B 50)))
      )
      false
    )
  )
)

(check-sat)
(exit)
