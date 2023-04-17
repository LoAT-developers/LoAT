; ./eldarica-misc/./LIA/llreve/nested-while_merged_safe.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main2| ( ) Bool)
(declare-fun |inv_main11| ( Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main16| ( Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main10| ( Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main6| ( Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main19| ( Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |CHC_COMP_FALSE| ( ) Bool)
(declare-fun |inv_main22| ( Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        true
      )
      inv_main2
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main10 B E F C H G D A)
        true
      )
      (inv_main11 B E F C H G D A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main16 B E F C H G D A)
        true
      )
      (inv_main22 B E F C H G D A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) ) 
    (=>
      (and
        (inv_main11 D G H E J I F C)
        (and (= B (+ 1 G)) (<= 1 (+ F (* (- 1) G))) (= A (+ 1 J)))
      )
      (inv_main11 D B H E A I F C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) ) 
    (=>
      (and
        (inv_main19 D G H E J I F C)
        (and (= B (+ 1 H)) (<= 1 (+ C (* (- 1) H))) (= A (+ 1 I)))
      )
      (inv_main19 D G B E J A F C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main11 B E F C H G D A)
        (let ((a!1 (not (<= 1 (+ E (* (- 1) D))))) (a!2 (not (<= 1 (+ D (* (- 1) E))))))
  (and a!1 a!2))
      )
      (inv_main6 B E F C H G D A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) ) 
    (=>
      (and
        (inv_main11 D G H E J I F C)
        (let ((a!1 (not (<= 1 (+ F (* (- 1) G))))))
  (and (= B (+ (- 1) J)) a!1 (<= 1 (+ G (* (- 1) F))) (= A (+ 1 F))))
      )
      (inv_main10 D G H E B I A C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main6 B E F C H G D A)
        (not (<= 1 (+ F (* (- 1) A))))
      )
      (inv_main16 B E F C H G D A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) ) 
    (=>
      (and
        (inv_main6 D G H E J I F C)
        (and (= B (+ (- 1) I)) (<= 1 (+ H (* (- 1) C))) (= A (+ 1 C)))
      )
      (inv_main19 D G H E J B F A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main19 B E F C H G D A)
        (let ((a!1 (not (<= 1 (+ F (* (- 1) A))))) (a!2 (not (<= 1 (+ A (* (- 1) F))))))
  (and a!1 a!2))
      )
      (inv_main16 B E F C H G D A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) ) 
    (=>
      (and
        (inv_main19 D G H E J I F C)
        (let ((a!1 (not (<= 1 (+ C (* (- 1) H))))))
  (and (= B (+ (- 1) I)) a!1 (<= 1 (+ H (* (- 1) C))) (= A (+ 1 C))))
      )
      (inv_main19 D G H E J B F A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (v_2 Int) (v_3 Int) (v_4 Int) (v_5 Int) (v_6 Int) (v_7 Int) ) 
    (=>
      (and
        inv_main2
        (and (not (<= 1 A)) (= v_2 A) (= v_3 A) (= v_4 B) (= v_5 B) (= 0 v_6) (= 0 v_7))
      )
      (inv_main6 A v_2 v_3 B v_4 v_5 v_6 v_7)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (v_3 Int) (v_4 Int) (v_5 Int) (v_6 Int) (v_7 Int) ) 
    (=>
      (and
        inv_main2
        (and (<= 1 C)
     (= A (+ (- 1) B))
     (= v_3 C)
     (= v_4 C)
     (= v_5 B)
     (= 1 v_6)
     (= 0 v_7))
      )
      (inv_main10 C v_3 v_4 B A v_5 v_6 v_7)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main10 B E F C H G D A)
        (not (<= 0 (+ E (* (- 1) D))))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main6 B E F C H G D A)
        (let ((a!1 (not (= H (+ C (* (- 1) B))))))
  (and (or (not (<= B 0)) (not (= H C))) (or (not (<= 1 B)) a!1)))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main16 B E F C H G D A)
        (let ((a!1 (not (= G (+ C (* (- 1) B))))))
  (and (or (not (<= B 0)) (not (= G C))) (or (not (<= 1 B)) a!1)))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main22 B E F C H G D A)
        (not (= E F))
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
