; ./extra-small-lia/./s_mutants_21_000.smt2
(set-logic HORN)

(declare-fun |itp| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= C 0) (= B 0) (not (<= 10 A)) (not (<= A 0)) (= D (* 10 A)))
      )
      (itp B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (itp A B C)
        (let ((a!1 (or (and (= D (+ 1 A)) (= E (+ (- 1) B)))
               (and (= D (+ (- 1) A)) (= E (+ 1 B))))))
  (and a!1 (= F (+ C D E))))
      )
      (itp D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (itp A B C)
        (= C 78)
      )
      false
    )
  )
)

(check-sat)
(exit)
