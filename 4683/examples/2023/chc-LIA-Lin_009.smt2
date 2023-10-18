; ./prepared/extra-small-lia/./gj2007_m_1_000.smt2
(set-logic HORN)


(declare-fun |inv5| ( Int Int Int ) Bool)
(declare-fun |inv3| ( Int Int Int ) Bool)
(declare-fun |inv| ( Int Int Int ) Bool)
(declare-fun |inv4| ( Int Int Int ) Bool)
(declare-fun |inv2| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= A 0) (not (<= C 0)) (= B C))
      )
      (inv A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv A B E)
        (and (= C (+ 1 A)) (not (<= E A)) (= D (ite (<= E A) (+ 1 B) B)))
      )
      (inv C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv A B C)
        (>= A C)
      )
      (inv2 A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv2 A B E)
        (and (= C (+ 1 A)) (not (<= (* 2 E) A)) (= D (ite (<= E A) (+ 1 B) B)))
      )
      (inv2 C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv2 B C D)
        (>= A (* 2 D))
      )
      (inv3 B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv3 A B E)
        (and (= C (+ 1 A)) (not (<= (* 3 E) A)) (= D (ite (<= E A) (+ 1 B) B)))
      )
      (inv3 C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv3 B C D)
        (>= A (* 3 D))
      )
      (inv4 B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv4 A B E)
        (and (= C (+ 1 A)) (not (<= (* 4 E) A)) (= D (ite (<= E A) (+ 1 B) B)))
      )
      (inv4 C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv4 B C D)
        (>= A (* 4 D))
      )
      (inv5 B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv5 A B E)
        (and (= C (+ 1 A)) (not (<= (* 5 E) A)) (= D (ite (<= E A) (+ 1 B) B)))
      )
      (inv5 C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv5 A B C)
        (and (>= A (* 5 C)) (not (= B (* 5 C))))
      )
      false
    )
  )
)

(check-sat)
(exit)
