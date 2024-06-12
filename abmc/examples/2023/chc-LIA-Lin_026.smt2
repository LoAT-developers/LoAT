; ./prepared/aeval-unsafe/./unsafe/s_split_40_000.smt2
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
        (inv E F D)
        (let ((a!1 (or (not (<= E 100)) (not (<= 5 (mod E 10))))))
  (and (= B (ite a!1 (+ 1 F) F)) (= A (ite a!1 D (+ 1 D))) (= C (+ 1 E))))
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
        (and (not (<= B A)) (not (<= C 100)))
      )
      false
    )
  )
)

(check-sat)
(exit)
