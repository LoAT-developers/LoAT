; ./aeval-unsafe/./unsafe/s_split_29_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= C 0) (= B 0) (= A 0) (= D 0))
      )
      (inv D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv F G H E)
        (let ((a!1 (ite (<= (+ G (* (- 10) F)) 0) H (+ 1 H)))
      (a!2 (ite (<= (+ G (* (- 10) F)) 0) (+ 1 E) E)))
  (and (= C (+ G F)) (= B a!1) (= A a!2) (= D (+ 1 F))))
      )
      (inv D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv C D B A)
        (and (not (<= B A)) (not (<= C 100)))
      )
      false
    )
  )
)

(check-sat)
(exit)
