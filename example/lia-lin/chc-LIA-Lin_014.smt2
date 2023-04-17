; ./extra-small-lia/./s_multipl_18_000.smt2
(set-logic HORN)

(declare-fun |PRE| ( Int Int Int ) Bool)
(declare-fun |POST| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (v_1 Int) (v_2 Int) ) 
    (=>
      (and
        (and true (= 0 v_1) (= 0 v_2))
      )
      (PRE v_1 v_2 A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (PRE B A E)
        (let ((a!1 (and (not (<= 0 A)) (= C (+ B E)) (= D (+ A (* (- 1) E)))))
      (a!2 (and (>= A 0) (= C (+ B (* (- 1) E))) (= D (+ A E)))))
  (or a!1 a!2))
      )
      (PRE C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (PRE B C A)
        (and (not (<= C B)) (= D (* (- 1) A)))
      )
      (POST B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (POST A B E)
        (let ((a!1 (and (not (<= 0 B)) (= C (+ B (* (- 1) E))) (= D (+ A E))))
      (a!2 (and (>= B 0) (= C (+ B E)) (= D (+ A (* (- 1) E))))))
  (and (or a!1 a!2) (not (= A B))))
      )
      (POST C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (POST C B A)
        (and (= C B) (not (= C 0)))
      )
      false
    )
  )
)

(check-sat)
(exit)
