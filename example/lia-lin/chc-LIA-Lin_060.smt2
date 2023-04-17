; ./hcai/./svcomp/O0/count_up_down_false-unreach-call_true-termination_000.smt2
(set-logic HORN)

(declare-fun |main@entry| ( Int ) Bool)
(declare-fun |main@verifier.error.split| ( ) Bool)
(declare-fun |main@_bb| ( Int Int Int ) Bool)

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
  (forall ( (A Int) (B Int) (C Int) (D Bool) (E Bool) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main@entry B)
        (and (or (not E) (not D) (= C H))
     (or (not E) (not D) (= F 0))
     (or (not E) (not D) (= G F))
     (or (not E) (not D) (= I C))
     (or (not D) (and E D))
     (= D true)
     (= A B))
      )
      (main@_bb G H I)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Int) (G Int) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) ) 
    (=>
      (and
        (main@_bb D L C)
        (and (or (not I) (not B) (not A))
     (or (not I) (not H) (= G E))
     (or (not I) (not H) (= J F))
     (or (not I) (not H) (= K J))
     (or (not I) (not H) (= M G))
     (or (not H) (and I H))
     (or (not I) (= E (+ (- 1) C)))
     (or (not I) (= F (+ 1 D)))
     (or (not I) (and I A))
     (= H true)
     (= B (= C 0)))
      )
      (main@_bb K L M)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Int) (E Int) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) ) 
    (=>
      (and
        (main@_bb D E A)
        (let ((a!1 (or (not H) (not (= (= D E) F)))))
  (and (or C (not H) (not B))
       a!1
       (or (not H) (= J (ite F 1 0)))
       (or (not H) (and H B))
       (or (not H) (not G))
       (or (not I) (and I H))
       (or (not L) (= K (= J 0)))
       (or (not L) (and L I))
       (or (not M) (and M L))
       (or (not N) (and N M))
       (or (not O) (and O N))
       (or K (not L))
       (= O true)
       (= C (= A 0))))
      )
      main@verifier.error.split
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        main@verifier.error.split
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
