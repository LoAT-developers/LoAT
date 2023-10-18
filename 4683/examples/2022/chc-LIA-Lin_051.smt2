; ./aeval-unsafe/./unsafe/s_split_27_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= A 0) (>= B 0) (= C 0))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv E B D)
        (let ((a!1 (= A (ite (= B (div E 1000)) (+ 1 D) D))))
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
        (inv C B A)
        (let ((a!1 (not (<= C (+ 1000 (* 1000 B))))))
  (and a!1 (= A 1000)))
      )
      false
    )
  )
)

(check-sat)
(exit)
