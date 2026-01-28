; ./aeval-unsafe/./unsafe/s_split_01_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int ) Bool)

(assert
  (forall ( (X Int) (Y Int) ) 
    (=>
      (and
        (and (<= X 0) (<= Y 0))
      )
      (inv X Y)
    )
  )
)

(assert
  (forall ( (X Int) (Y Int) (XX Int) (YY Int) ) 
    (=>
      (and
        (inv X Y)
        (or (and (< X 100) (= XX (+ X 1)) (= YY Y)) (and (= X 100) (= XX 0) (= YY (+ Y 1))))
      )
      (inv XX YY)
    )
  )
)

(assert
  (forall ( (X Int) (Y Int) ) 
    (=>
      (and
        (inv X Y)
        (and (>= Y 100))
      )
      false
    )
  )
)

(check-sat)
(exit)
