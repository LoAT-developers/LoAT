; ./prepared/tricera/sv-comp-2020/./mixed/const_1-2.c-1_000.smt2
(set-logic HORN)


(declare-fun |inv_main5| ( Int Int ) Bool)
(declare-fun |inv_main4| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (= A 1) (= B 0))
      )
      (inv_main4 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv_main4 B A)
        (and (<= 0 A) (not (<= A 1023)) (<= 0 B))
      )
      (inv_main5 B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv_main4 D A)
        (and (= C (+ 1 A)) (<= 0 A) (<= 0 D) (<= A 1023) (= B 0))
      )
      (inv_main4 B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv_main5 B A)
        (and (<= 0 B) (<= 0 A) (not (= B 1)))
      )
      false
    )
  )
)

(check-sat)
(exit)
