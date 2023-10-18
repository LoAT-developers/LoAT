; ./prepared/aeval-unsafe/./unsafe/s_split_10_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int ) Bool)

(assert
  (forall ( (A Int) ) 
    (=>
      (and
        (= A 0)
      )
      (inv A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv B)
        (= A (ite (<= 200 (div B 5)) (+ 5 B) (+ 1 B)))
      )
      (inv A)
    )
  )
)
(assert
  (forall ( (A Int) ) 
    (=>
      (and
        (inv A)
        (and (>= A 2000) (= (mod A 5) 0))
      )
      false
    )
  )
)

(check-sat)
(exit)
