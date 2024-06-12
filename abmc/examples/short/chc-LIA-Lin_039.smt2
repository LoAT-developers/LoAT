; ./prepared/aeval-unsafe/./unsafe/s_split_42_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= B A) (= A 0) (= C 0))
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
        (and (= B (ite (>= F 1765) (+ 2 E) (+ 1 E)))
     (= A (ite (>= E 5765) (+ 3 D) (+ 2 D)))
     (= C (+ 1 F)))
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
        (and (not (<= A 27650)) (not (<= B 17650)))
      )
      false
    )
  )
)

(check-sat)
(exit)
