; ./prepared/aeval-unsafe/./unsafe/s_split_54_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= B 8000) (= A 0) (= C 0))
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
        (and (= B (ite (>= E 8000) (+ 1 F) (+ (- 1) F)))
     (= A (ite (<= 8000 E) (+ (- 1) D) (+ 1 D)))
     (= C (+ 1 E)))
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
        (and (= B 8000) (= A 0) (= C 16000))
      )
      false
    )
  )
)

(check-sat)
(exit)
