; ./prepared/aeval-unsafe/./unsafe/s_split_24_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (or (= C 0) (= C 1)) (or (= B 0) (= B 1)) (= A 0))
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
        (let ((a!1 (= A (ite (= (mod F 2) (mod E 2)) (+ 1 D) D))))
  (and (= B (+ 3 E)) a!1 (= C (+ 2 F))))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv B C A)
        (and (not (<= B 400)) (>= A 100))
      )
      false
    )
  )
)

(check-sat)
(exit)
