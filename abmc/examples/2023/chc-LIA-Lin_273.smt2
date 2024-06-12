; ./prepared/llreve/./smt2/clausified/loop__bug15_000.smt2
(set-logic HORN)


(declare-fun |INV_MAIN_42| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= B 1) (= A 1) (= C D))
      )
      (INV_MAIN_42 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (INV_MAIN_42 C D)
        (and (= (* 2 C) (+ (- 4) A)) (<= D 2) (<= C 2) (= (* 2 D) (+ (- 4) B)))
      )
      (INV_MAIN_42 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (INV_MAIN_42 C B)
        (and (<= C 2) (not (<= B 2)) (= (* 2 C) (+ (- 4) A)))
      )
      (INV_MAIN_42 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (INV_MAIN_42 A C)
        (and (<= C 2) (not (<= A 2)) (= (* 2 C) (+ (- 4) B)))
      )
      (INV_MAIN_42 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (INV_MAIN_42 A B)
        (let ((a!1 (not (= (+ (* 4 A) (* (- 4) B)) 0))))
  (and (not (<= B 2)) (not (<= A 2)) a!1))
      )
      false
    )
  )
)

(check-sat)
(exit)
