; ./prepared/aeval-unsafe/./unsafe/s_split_12_000.smt2
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
        (let ((a!1 (= B (ite (= (mod E 2) 0) (+ 1 F) F)))
      (a!2 (= A (ite (= (mod E 2) 0) D (+ 1 D)))))
  (and a!1 a!2 (= C (+ 1 E))))
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
        (and (= B A) (= C 1342342))
      )
      false
    )
  )
)

(check-sat)
(exit)
