; ./eldarica-misc/./LIA/llreve/nested-while_unsafe.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main15| ( Int Int Int Int Int ) Bool)
(declare-fun |inv_main37| ( Int Int Int Int ) Bool)
(declare-fun |inv_main3| ( Int Int ) Bool)
(declare-fun |inv_main32| ( Int Int Int Int Int Int ) Bool)

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
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (inv_main32 C D E I G H)
        (and (= B (+ 1 I)) (not (= F 0)) (<= 1 (+ H (* (- 1) I))) (= A (+ 2 G)))
      )
      (inv_main32 C D E B A H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) ) 
    (=>
      (and
        (inv_main32 C D E J G H)
        (let ((a!1 (not (<= 1 (+ H (* (- 1) J))))))
  (and (= B (+ (- 2) G))
       (not (= I 0))
       (<= 1 (+ J (* (- 1) H)))
       (or a!1 (= F 0))
       (= A (+ 1 H))))
      )
      (inv_main32 C D E J B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main15 C E D F G)
        (and (= B (+ 1 D)) (not (= H 0)) (<= 1 (+ G (* (- 1) D))) (= A (+ 1 F)))
      )
      (inv_main15 C E B A G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (inv_main15 C E D F G)
        (let ((a!1 (not (<= 1 (+ G (* (- 1) D))))))
  (and (= B (+ (- 1) F))
       (not (= I 0))
       (<= 1 (+ D (* (- 1) G)))
       (or a!1 (= H 0))
       (= A (+ 1 G))))
      )
      (inv_main15 C E D B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (v_4 Int) (v_5 Int) ) 
    (=>
      (and
        (inv_main3 B C)
        (and (not (= D 0)) (<= 1 B) (= A (+ (- 1) C)) (= v_4 B) (= 1 v_5))
      )
      (inv_main15 B C v_4 A v_5)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main32 A B C H F G)
        (let ((a!1 (not (<= 1 (+ H (* (- 1) G))))) (a!2 (not (<= 1 (+ G (* (- 1) H))))))
  (and (or a!1 (= E 0)) (or a!2 (= D 0))))
      )
      (inv_main37 A B C F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (v_9 Int) (v_10 Int) ) 
    (=>
      (and
        (inv_main15 B D C E G)
        (let ((a!1 (not (<= 1 (+ G (* (- 1) C))))) (a!2 (not (<= 1 (+ C (* (- 1) G))))))
  (and (not (= I 0))
       (<= 1 B)
       (or a!1 (= H 0))
       (or a!2 (= F 0))
       (= A (+ (- 2) D))
       (= v_9 B)
       (= 1 v_10)))
      )
      (inv_main32 B D E v_9 A v_10)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (v_8 Int) ) 
    (=>
      (and
        (inv_main15 A C B D F)
        (let ((a!1 (not (<= 1 (+ B (* (- 1) F))))) (a!2 (not (<= 1 (+ F (* (- 1) B))))))
  (and (or a!1 (= E 0)) (or (not (<= 1 A)) (= H 0)) (or a!2 (= G 0)) (= v_8 C)))
      )
      (inv_main37 A C D v_8)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (v_5 Int) (v_6 Int) (v_7 Int) ) 
    (=>
      (and
        (inv_main3 B C)
        (and (not (= E 0))
     (<= 1 B)
     (or (not (<= 1 B)) (= D 0))
     (= A (+ (- 2) C))
     (= v_5 C)
     (= v_6 B)
     (= 1 v_7))
      )
      (inv_main32 B C v_5 v_6 A v_7)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (v_4 Int) (v_5 Int) ) 
    (=>
      (and
        (inv_main3 A B)
        (and (or (not (<= 1 A)) (= D 0))
     (or (not (<= 1 A)) (= C 0))
     (= v_4 B)
     (= v_5 B))
      )
      (inv_main37 A B v_4 v_5)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv_main37 A B C D)
        (not (= C D))
      )
      false
    )
  )
)

(check-sat)
(exit)
