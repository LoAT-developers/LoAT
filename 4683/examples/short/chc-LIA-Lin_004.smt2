; ./prepared/extra-small-lia/./s_multipl_13_000.smt2
(set-logic HORN)


(declare-fun |POST1| ( Int Int Int ) Bool)
(declare-fun |PRE| ( Int Int Int Int ) Bool)
(declare-fun |POST2| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (v_1 Int) (v_2 Int) (v_3 Int) ) 
    (=>
      (and
        (and (>= A 0) (= v_1 A) (= 0 v_2) (= 0 v_3))
      )
      (PRE A v_1 v_2 v_3)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (PRE A E B C)
        (let ((a!1 (or (and (= G C) (= F (+ 1 B))) (and (= G (+ 1 C)) (= F B)))))
  (and (not (= A 0)) a!1 (= D (+ (- 1) A))))
      )
      (PRE D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (PRE A B C D)
        (= A 0)
      )
      (POST1 B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (POST1 B A E)
        (and (= C (+ (- 1) B)) (not (= A 0)) (= D (+ (- 1) A)))
      )
      (POST1 C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (POST1 A B C)
        (= B 0)
      )
      (POST2 A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (POST2 B D A)
        (and (not (= A 0)) (= E (+ (- 1) A)) (= C (+ (- 1) B)))
      )
      (POST2 C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (POST2 C A B)
        (and (not (= C 0)) (= B 0))
      )
      false
    )
  )
)

(check-sat)
(exit)
