; ./eldarica-misc/./LIA/llreve/barthe_merged_unsafe.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main15| ( Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main6| ( Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        true
      )
      (inv_main6 G D F E A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (v_7 Int) (v_8 Int) (v_9 Int) (v_10 Int) (v_11 Int) ) 
    (=>
      (and
        (inv_main6 C E B G D F A)
        (and (<= 1 C) (= 0 v_7) (= v_8 E) (= v_9 E) (= v_10 E) (= v_11 E))
      )
      (inv_main15 C E v_7 v_8 v_9 v_10 v_11)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (v_11 Int) ) 
    (=>
      (and
        (inv_main15 G I F K H J E)
        (and (= B (+ 5 J (* 5 F) I))
     (= C (+ 5 (* 5 F) I))
     (= D (+ 1 F))
     (= F 10)
     (<= 2 (+ G (* (- 1) F)))
     (= A (+ 10 E))
     (= 10 v_11))
      )
      (inv_main15 G I D C v_11 B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (inv_main15 H J G L I K F)
        (and (= B (+ 5 K (* 5 G) J))
     (= C (+ 5 I))
     (= D (+ 5 (* 5 G) J))
     (= E (+ 1 G))
     (not (= G 10))
     (<= 2 (+ H (* (- 1) G)))
     (= A (+ 5 F I)))
      )
      (inv_main15 H J E D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv_main15 C E B G D F A)
        (not (= F A))
      )
      false
    )
  )
)

(check-sat)
(exit)
