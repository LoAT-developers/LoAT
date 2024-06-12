; ./prepared/tricera/sv-comp-2020/./mixed/simple_3-2.c-1_000.smt2
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
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv_main5 A B)
        (let ((a!1 (not (<= 1 (+ B (* (- 1) A))))))
  (and (<= 0 A) a!1))
      )
      (inv_main6 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv_main5 C B)
        (and (<= 1 (+ B (* (- 1) C))) (<= 0 C) (= A (+ 2 C)))
      )
      (inv_main5 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv_main3 B)
        (<= 0 B)
      )
      (inv_main5 B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv_main6 B A)
        (and (not (= C 0))
     (<= (- 1) C)
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
