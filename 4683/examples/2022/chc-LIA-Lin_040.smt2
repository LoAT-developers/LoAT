; ./aeval-unsafe/./unsafe/s_split_28_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= A 0) (>= B 100) (= C 0))
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
        (let ((a!1 (= A (ite (<= F (div E 50)) (+ 1 D) D))))
  (and (= B (+ (- 1) F)) a!1 (= C (+ 1 E))))
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
        (and (not (<= A 0)) (= B 0))
      )
      false
    )
  )
)

(check-sat)
(exit)
