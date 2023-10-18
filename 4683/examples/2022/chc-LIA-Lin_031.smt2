; ./aeval-unsafe/./unsafe/s_split_33_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= B 0) (= A 0) (= C 0))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv F E D)
        (let ((a!1 (= A (ite (= (div D 100) (div C 100)) D (+ 100 D)))))
  (and (= B (mod (+ 1 E) 100)) a!1 (= C (+ 1 F))))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv C A B)
        (= C (+ B A))
      )
      false
    )
  )
)

(check-sat)
(exit)
