; ./tricera/sv-comp-2020/./mixed/functions_1-2.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main3| ( Int ) Bool)
(declare-fun |inv_main4| ( Int ) Bool)

(assert
  (forall ( (A Int) ) 
    (=>
      (and
        (= A 0)
      )
      (inv_main3 A)
    )
  )
)
(assert
  (forall ( (A Int) ) 
    (=>
      (and
        (inv_main3 A)
        (and (not (<= A 268435454)) (<= 0 A))
      )
      (inv_main4 A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv_main3 A)
        (and (<= 0 A) (<= A 268435454) (= B (+ 2 A)))
      )
      (inv_main3 B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv_main4 A)
        (and (= B 0)
     (<= (- 1) B)
     (<= 0 A)
     (<= B 1)
     (or (not (<= 1 B)) (<= 1 A))
     (or (not (<= B (- 1))) (<= A (- 1)))
     (= A (+ (* 2 C) B)))
      )
      false
    )
  )
)

(check-sat)
(exit)
