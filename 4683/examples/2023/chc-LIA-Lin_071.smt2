; ./prepared/eldarica-misc/./LIA/llreve/barthe_safe.c-1_000.smt2
(set-logic HORN)


(declare-fun |inv_main29| ( Int Int Int Int ) Bool)
(declare-fun |inv_main22| ( Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main3| ( Int Int ) Bool)
(declare-fun |inv_main9| ( Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        true
      )
      (inv_main3 B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (inv_main22 J H F L K I E G)
        (and (= B (+ 5 E))
     (= C (+ 1 I))
     (not (= D 0))
     (<= 1 (+ L (* (- 1) I)))
     (= A (+ G E)))
      )
      (inv_main22 J H F L K C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (inv_main9 K H F G J E D)
        (and (= B (+ (* 5 J) G))
     (= C (+ 1 J))
     (not (= I 0))
     (<= 1 (+ F (* (- 1) J)))
     (= A (+ D (* 5 J) G)))
      )
      (inv_main9 K H F G C B A)
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
      (inv_main9 B A v_2 v_3 v_4 v_5 v_6)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (inv_main22 G D B I H E A C)
        (let ((a!1 (not (<= 1 (+ I (* (- 1) E))))))
  (or a!1 (= F 0)))
      )
      (inv_main29 G D B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (v_8 Int) (v_9 Int) (v_10 Int) (v_11 Int) (v_12 Int) ) 
    (=>
      (and
        (inv_main9 H E C D G B A)
        (let ((a!1 (not (<= 1 (+ C (* (- 1) G))))))
  (and (or a!1 (= F 0)) (= v_8 H) (= v_9 E) (= 0 v_10) (= v_11 E) (= 0 v_12)))
      )
      (inv_main22 H E A v_8 v_9 v_10 v_11 v_12)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv_main29 D C B A)
        (not (= B A))
      )
      false
    )
  )
)

(check-sat)
(exit)
