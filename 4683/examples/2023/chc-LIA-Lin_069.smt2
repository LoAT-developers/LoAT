; ./prepared/eldarica-misc/./LIA/llreve/03_while_unsafe.c-1_000.smt2
(set-logic HORN)


(declare-fun |inv_main31| ( Int Int Int Int ) Bool)
(declare-fun |inv_main12| ( Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main3| ( Int Int ) Bool)
(declare-fun |inv_main26| ( Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        true
      )
      (inv_main3 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (inv_main26 G F D I K E H J)
        (and (= B (+ 5 H)) (= C (+ 1 E)) (<= 1 (+ I (* (- 1) E))) (= A (+ J H)))
      )
      (inv_main26 G F D I K C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) ) 
    (=>
      (and
        (inv_main12 G E F J H I D)
        (and (= B (+ (* 5 H) J))
     (= C (+ 1 H))
     (<= 1 (+ F (* (- 1) H)))
     (= A (+ D (* 5 H) J)))
      )
      (inv_main12 G E F J C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (v_2 Int) (v_3 Int) (v_4 Int) (v_5 Int) (v_6 Int) ) 
    (=>
      (and
        (inv_main3 B A)
        (and (= v_2 B) (= v_3 A) (= 0 v_4) (= 0 v_5) (= 0 v_6))
      )
      (inv_main12 B A v_2 v_3 v_4 v_5 v_6)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main26 D C A F H B E G)
        (not (<= 1 (+ F (* (- 1) B))))
      )
      (inv_main31 D C A G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (v_7 Int) (v_8 Int) (v_9 Int) (v_10 Int) (v_11 Int) ) 
    (=>
      (and
        (inv_main12 D B C G E F A)
        (let ((a!1 (not (<= 1 (+ C (* (- 1) E))))))
  (and a!1 (= v_7 D) (= v_8 B) (= 0 v_9) (= 0 v_10) (= 0 v_11)))
      )
      (inv_main26 D B A v_7 v_8 v_9 v_10 v_11)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv_main31 D B A C)
        (not (= A C))
      )
      false
    )
  )
)

(check-sat)
(exit)
