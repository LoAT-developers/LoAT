; ./hcai/./svcomp/O3/count_up_down_false-unreach-call_true-termination_000.smt2
(set-logic HORN)

(declare-fun |main@entry| ( Int ) Bool)
(declare-fun |main@orig.main.exit.split| ( ) Bool)
(declare-fun |main@.lr.ph| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) ) 
    (=>
      (and
        true
      )
      (main@entry A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Bool) (E Int) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (main@entry B)
        (and (= A B)
     (or (not G) (not D) (not C))
     (or (not G) (not F) (= E 0))
     (or (not G) (not F) (= H I))
     (or (not G) (not F) (= J H))
     (or (not G) (not F) (= K E))
     (or (not F) (and G F))
     (or (not G) (and G C))
     (= F true)
     (= D (= I 0)))
      )
      (main@.lr.ph I J K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) ) 
    (=>
      (and
        (main@entry B)
        (let ((a!1 (or (not K) (not (= (= F G) I)))))
  (and (= A B)
       (or (not D) (not K) (= E 0))
       (or (not D) (not K) (= F E))
       (or (not D) (not K) C)
       a!1
       (or (not K) (not (= I J)))
       (or (not K) (and D K))
       (or (not K) J)
       (or (not L) (and L K))
       (or (not K) (not H))
       (= L true)
       (= C (= G 0))))
      )
      main@orig.main.exit.split
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Int) (E Int) (F Int) (G Bool) (H Bool) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (main@.lr.ph J A B)
        (and (= D (+ 1 B))
     (= E (+ (- 1) A))
     (or (not H) (not G) (= F D))
     (or (not H) (not G) (= I E))
     (or (not H) (not G) (= K I))
     (or (not H) (not G) (= L F))
     (or (not H) (not G) (not C))
     (or (not G) (and H G))
     (= G true)
     (= C (= E 0)))
      )
      (main@.lr.ph J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Bool) (E Int) (F Bool) (G Int) (H Int) (I Bool) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) ) 
    (=>
      (and
        (main@.lr.ph L A B)
        (let ((a!1 (or (not P) (not (= (= K L) N)))))
  (and (= C (+ (- 1) A))
       (= E (+ 1 B))
       (or (not I) (not F) (= G E))
       (or (not I) (not F) (= H G))
       (or (not I) (not F) D)
       (or (not I) (not P) (= J H))
       (or (not I) (not P) (= K J))
       a!1
       (or (not P) (not (= N O)))
       (or (not P) (and I P))
       (or (not P) O)
       (or (not Q) (and Q P))
       (or (not I) (and I F))
       (or (not P) (not M))
       (= Q true)
       (= D (= C 0))))
      )
      main@orig.main.exit.split
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        main@orig.main.exit.split
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
