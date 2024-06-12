; ./prepared/llreve/./smt2/loop__loop_unswitching_000.smt2
(set-logic HORN)


(declare-fun |INV_MAIN_23| ( Int Int Int Int Int ) Bool)
(declare-fun |CHC_COMP_FALSE| ( ) Bool)
(declare-fun |INV_MAIN_42| ( Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (v_4 Int) (v_5 Int) ) 
    (=>
      (and
        (and (= A C) (<= A 0) (= B D) (= 0 v_4) (= 0 v_5))
      )
      (INV_MAIN_23 B v_4 D C v_5)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (v_4 Int) (v_5 Int) ) 
    (=>
      (and
        (and (= A C) (not (<= A 0)) (= B D) (= 0 v_4) (= 0 v_5))
      )
      (INV_MAIN_42 B v_4 D C v_5)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (INV_MAIN_23 E F G H I)
        (let ((a!1 (= A (+ I (ite (<= H 0) (- 1) 1)))))
  (and (= B (+ (- 1) G))
       (= C (+ (- 1) F))
       (= D (+ (- 1) E))
       (not (<= E 0))
       (not (<= G 0))
       a!1))
      )
      (INV_MAIN_23 D C B H A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (INV_MAIN_23 C D E F G)
        (and (= B (+ (- 1) C)) (not (<= C 0)) (<= E 0) (= A (+ (- 1) D)))
      )
      (INV_MAIN_23 B A E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (INV_MAIN_23 C D E F G)
        (let ((a!1 (= A (+ G (ite (<= F 0) (- 1) 1)))))
  (and (= B (+ (- 1) E)) (<= C 0) (not (<= E 0)) a!1))
      )
      (INV_MAIN_23 C D B F A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (INV_MAIN_42 E F G H I)
        (let ((a!1 (= A (+ I (ite (<= H 0) (- 1) 1)))))
  (and (= B (+ (- 1) G))
       (= C (+ 1 F))
       (= D (+ (- 1) E))
       (not (<= E 0))
       (not (<= G 0))
       a!1))
      )
      (INV_MAIN_42 D C B H A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (INV_MAIN_42 C D E F G)
        (and (= B (+ (- 1) C)) (not (<= C 0)) (<= E 0) (= A (+ 1 D)))
      )
      (INV_MAIN_42 B A E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (INV_MAIN_42 C D E F G)
        (let ((a!1 (= A (+ G (ite (<= F 0) (- 1) 1)))))
  (and (= B (+ (- 1) E)) (<= C 0) (not (<= E 0)) a!1))
      )
      (INV_MAIN_42 C D B F A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (INV_MAIN_23 A B C D E)
        (and (<= A 0) (<= C 0) (not (= B E)))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (INV_MAIN_42 A B C D E)
        (and (<= A 0) (<= C 0) (not (= B E)))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        CHC_COMP_FALSE
      )
      false
    )
  )
)

(check-sat)
(exit)
