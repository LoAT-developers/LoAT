; ./prepared/aeval-unsafe/./unsafe/s_split_08_000.smt2
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
        (let ((a!1 (= A (ite (= (mod D 2) 0) (+ 1 C) C))))
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
        (and (= A 1351235) (= B 2702470))
      )
      false
    )
  )
)

(check-sat)
(exit)
