; ./prepared/aeval-unsafe/./unsafe/s_split_20_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= B 0) (= A (- 1)) (= C 0))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv E F D)
        (let ((a!1 (= A (ite (= (mod E 2) 0) (+ 1 D) D))))
  (and (= B (+ (* (- 1) F) (* (- 1) E))) a!1 (= C (+ 1 E))))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv C B A)
        (and (= C 942573485) (= 0 (+ B A)))
      )
      false
    )
  )
)

(check-sat)
(exit)
