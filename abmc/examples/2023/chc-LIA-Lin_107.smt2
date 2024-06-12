; ./prepared/tricera/sv-comp-2020/./mixed/diamond_1-1.c-1_000.smt2
(set-logic HORN)


(declare-fun |inv_main5| ( Int Int ) Bool)
(declare-fun |inv_main3| ( Int ) Bool)
(declare-fun |inv_main6| ( Int Int ) Bool)

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
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv_main5 A C)
        (and (= C (+ (* 2 E) D))
     (= B (+ 2 A))
     (<= (- 1) D)
     (<= 0 C)
     (<= 0 A)
     (<= D 1)
     (<= A 98)
     (or (<= 1 C) (not (<= 1 D)))
     (or (not (<= D (- 1))) (<= C (- 1)))
     (= D 0))
      )
      (inv_main5 B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv_main5 B C)
        (and (= C (+ (* 2 E) D))
     (= A (+ 1 B))
     (<= (- 1) D)
     (<= 0 C)
     (<= 0 B)
     (<= D 1)
     (<= B 98)
     (or (<= 1 C) (not (<= 1 D)))
     (or (not (<= D (- 1))) (<= C (- 1)))
     (not (= D 0)))
      )
      (inv_main5 A C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv_main3 A)
        (and (<= 0 B) (<= 0 A))
      )
      (inv_main5 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv_main5 B A)
        (and (<= 0 B) (not (<= B 98)) (<= 0 A))
      )
      (inv_main6 B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main6 B A)
        (and (not (= C E))
     (= B (+ (* 2 D) C))
     (<= (- 1) E)
     (<= (- 1) C)
     (<= 0 A)
     (<= 0 B)
     (<= E 1)
     (<= C 1)
     (or (not (<= 1 E)) (<= 1 A))
     (or (not (<= 1 C)) (<= 1 B))
     (or (not (<= E (- 1))) (<= A (- 1)))
     (or (not (<= C (- 1))) (<= B (- 1)))
     (= A (+ (* 2 F) E)))
      )
      false
    )
  )
)

(check-sat)
(exit)
