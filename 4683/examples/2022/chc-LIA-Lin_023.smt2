; ./extra-small-lia/./gj2007_m_3_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int Int ) Bool)
(declare-fun |inv5| ( Int Int Int Int ) Bool)
(declare-fun |inv3| ( Int Int Int Int ) Bool)
(declare-fun |inv4| ( Int Int Int Int ) Bool)
(declare-fun |inv2| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= B D) (= A 0) (not (<= D 0)) (= C 0))
      )
      (inv A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv A C B G)
        (and (= E (ite (<= G B) (+ 1 C) C)) (= D (+ 1 A)) (not (<= G A)) (= F (+ 1 B)))
      )
      (inv D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv A B C D)
        (>= A D)
      )
      (inv2 A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv2 A C B G)
        (let ((a!1 (= E (ite (<= (* 2 G) B) (+ 1 C) C))))
  (and a!1 (= D (+ 1 A)) (not (<= (* 2 G) A)) (= F (+ 1 B))))
      )
      (inv2 D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv2 B C D E)
        (>= A (* 2 E))
      )
      (inv3 B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv3 A C B G)
        (let ((a!1 (= E (ite (<= (* 3 G) B) (+ 1 C) C))))
  (and a!1 (= D (+ 1 A)) (not (<= (* 3 G) A)) (= F (+ 1 B))))
      )
      (inv3 D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv3 B C D E)
        (>= A (* 3 E))
      )
      (inv4 B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv4 A C B G)
        (let ((a!1 (= E (ite (<= (* 4 G) B) (+ 1 C) C))))
  (and a!1 (= D (+ 1 A)) (not (<= (* 4 G) A)) (= F (+ 1 B))))
      )
      (inv4 D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv4 B C D E)
        (>= A (* 4 E))
      )
      (inv5 B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv5 A C B G)
        (let ((a!1 (= E (ite (<= (* 5 G) B) (+ 1 C) C))))
  (and a!1 (= D (+ 1 A)) (not (<= (* 5 G) A)) (= F (+ 1 B))))
      )
      (inv5 D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv5 B C A D)
        (and (>= B (* 5 D)) (not (= C D)))
      )
      false
    )
  )
)

(check-sat)
(exit)
