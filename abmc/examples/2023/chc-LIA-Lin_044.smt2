; ./prepared/aeval-unsafe/./unsafe/s_split_49_000.smt2
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
        (let ((a!1 (or (and (>= D 7500) (>= D 12500))
               (and (not (>= D 7500)) (not (>= D 2500))))))
  (and (= A (ite a!1 (+ (- 2) C) (+ 1 C))) (= B (+ 1 D))))
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
        (and (= A 0) (= B 15000))
      )
      false
    )
  )
)

(check-sat)
(exit)
