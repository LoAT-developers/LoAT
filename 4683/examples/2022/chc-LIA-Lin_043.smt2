; ./aeval-unsafe/./unsafe/s_split_45_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (= C 0)
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
        (let ((a!1 (= B (ite (>= E 765552) (ite (>= E 865552) F (+ 1 F)) 0)))
      (a!2 (= A (ite (>= E 663258) (ite (>= E 763258) D (+ 1 D)) 0))))
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
        (and (>= C 965552) (= B A))
      )
      false
    )
  )
)

(check-sat)
(exit)
