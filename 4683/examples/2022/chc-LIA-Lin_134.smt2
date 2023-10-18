; ./tricera/sv-comp-2020/./mixed/nested_1-1.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main7| ( Int Int ) Bool)
(declare-fun |inv_main5| ( Int Int ) Bool)
(declare-fun |inv_main4| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (= A 0) (= B 0))
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
        (and (<= 0 A) (not (<= B 268435454)) (<= 0 B))
      )
      (inv_main5 B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv_main4 B A)
        (and (<= 0 A) (<= 0 B) (<= B 268435454) (= C 0))
      )
      (inv_main7 B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv_main7 B A)
        (and (<= 0 A) (<= 0 B) (<= A 9) (= C (+ 1 A)))
      )
      (inv_main7 B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv_main7 B C)
        (and (<= 0 C) (<= 0 B) (not (<= C 9)) (= A (+ 1 B)))
      )
      (inv_main4 A C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv_main5 B A)
        (and (= C 0)
     (<= (- 1) C)
     (<= 0 A)
     (<= 0 B)
     (<= C 1)
     (or (not (<= 1 C)) (<= 1 B))
     (or (not (<= C (- 1))) (<= B (- 1)))
     (= B (+ (* 2 D) C)))
      )
      false
    )
  )
)

(check-sat)
(exit)
