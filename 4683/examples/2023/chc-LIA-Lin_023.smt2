; ./prepared/aeval-unsafe/./unsafe/s_split_05_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (not (<= 0 B)) (not (<= C 0)) (= A 1))
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
        (and (= B (+ 2 E)) (= A (ite (>= E 0) (* 2 D) D)) (= C (+ 1 F)))
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
        (and (not (<= A 1)) (>= C B))
      )
      false
    )
  )
)

(check-sat)
(exit)
