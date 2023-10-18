; ./prepared/extra-small-lia/./const_mod_2_000.smt2
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
        (inv A)
        (= B (+ 23468 A))
      )
      (inv B)
    )
  )
)
(assert
  (forall ( (A Int) ) 
    (=>
      (and
        (inv A)
        (not (= (mod A 23468) 0))
      )
      false
    )
  )
)

(check-sat)
(exit)
