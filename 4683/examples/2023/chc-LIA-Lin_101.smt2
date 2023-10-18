; ./prepared/tricera/sv-comp-2020/./mixed/diamond_1-2.c-1_000.smt2
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
     (= D 0))
      )
      (inv_main5 A C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv_main5 C A)
        (and (= B (+ 2 C))
     (= A (+ (* 2 E) D))
     (<= (- 1) D)
     (<= 0 C)
     (<= 0 A)
     (<= D 1)
     (<= C 98)
     (or (not (<= 1 D)) (<= 1 A))
     (or (not (<= D (- 1))) (<= A (- 1)))
     (not (= D 0)))
      )
      (inv_main5 B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv_main3 B)
        (and (<= 0 B) (<= 0 A))
      )
      (inv_main5 B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv_main5 A B)
        (and (<= 0 B) (not (<= A 98)) (<= 0 A))
      )
      (inv_main6 A B)
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
     (or (<= 1 B) (not (<= 1 C)))
     (or (not (<= E (- 1))) (<= A (- 1)))
     (or (<= B (- 1)) (not (<= C (- 1))))
     (= A (+ (* 2 F) E)))
      )
      false
    )
  )
)

(check-sat)
(exit)
