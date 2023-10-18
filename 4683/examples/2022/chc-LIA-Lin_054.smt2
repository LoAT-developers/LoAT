; ./aeval-unsafe/./unsafe/s_split_11_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (not (<= B C)) (or (= A 0) (= A 1)) (not (<= 0 C)))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv E D A)
        (let ((a!1 (= B (ite (= (mod E 2) A) (+ 2 D) D))))
  (and (= C (+ 1 E)) a!1))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv B A C)
        (and (not (<= A 54932)) (not (<= B 54932)))
      )
      false
    )
  )
)

(check-sat)
(exit)
