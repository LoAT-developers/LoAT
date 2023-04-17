; ./hcai/./arrays_orig/array_fill2_abstracted_000.smt2
(set-logic HORN)

(declare-fun |loopi| ( Int Int Int Int Int Int ) Bool)
(declare-fun |init| ( Int Int Int Int Int ) Bool)
(declare-fun |write| ( Int Int Int Int Int Int Int ) Bool)
(declare-fun |end| ( Int Int Int Int Int ) Bool)
(declare-fun |loopj| ( Int Int Int Int Int Int Int ) Bool)
(declare-fun |incrj| ( Int Int Int Int Int Int Int ) Bool)
(declare-fun |incri| ( Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (and (<= 0 C) (not (<= B D)) (not (<= A C)) (<= 0 D))
      )
      (init A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (v_5 Int) ) 
    (=>
      (and
        (init A B C D E)
        (= 0 v_5)
      )
      (loopi A B v_5 C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (v_6 Int) ) 
    (=>
      (and
        (loopi A B C D E F)
        (and (not (<= A C)) (= 0 v_6))
      )
      (loopj A B C v_6 D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (loopi A B C D E F)
        (>= C A)
      )
      (end A B D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (loopj A B C D E F G)
        (not (<= B D))
      )
      (write A B C D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (loopj A B C D E F G)
        (>= D B)
      )
      (incri A B C E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (write A B C D E F G)
        (or (not (= C E)) (not (= D F)))
      )
      (incrj A B C D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (v_5 Int) (v_6 Int) (v_7 Int) (v_8 Int) (v_9 Int) ) 
    (=>
      (and
        (write A B C D v_5 v_6 E)
        (and (= v_5 C) (= v_6 D) (= v_7 C) (= v_8 D) (= 42 v_9))
      )
      (incrj A B C D v_7 v_8 v_9)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (incrj B C D E F G H)
        (= A (+ 1 E))
      )
      (loopj B C D A F G H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (incri B C D E F G)
        (= A (+ 1 D))
      )
      (loopi B C A E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (end A B C D E)
        (not (= E 42))
      )
      false
    )
  )
)

(check-sat)
(exit)
