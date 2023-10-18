; ./prepared/aeval-unsafe/./unsafe/s_split_31_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= A 0) (not (<= B 53736239)) (= C 0))
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
        (let ((a!1 (ite (or (not (<= B E)) (= 0 (mod E 2))) (+ 1 D) (+ (- 1) D))))
  (and (= C (+ 1 E)) (= A a!1)))
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
        (and (not (<= C B)) (>= A 0))
      )
      false
    )
  )
)

(check-sat)
(exit)
