; ./prepared/hcai/./svcomp/O0/nec20_false-unreach-call_true-termination_000.smt2
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
  (forall ( (A Int) (B Int) (C Bool) (D Int) (E Int) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (main@entry B)
        (and (= K (ite C 0 1023))
     (or (not G) (not F) (= E 0))
     (or (not G) (not F) (= H D))
     (or (not G) (not F) (= I H))
     (or (not G) (not F) (= J E))
     (or (not F) (and G F))
     (= F true)
     (= A B))
      )
      (main@_bb I J K)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Int) (G Int) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) ) 
    (=>
      (and
        (main@_bb D C M)
        (and (or (not I) (not B) (not A))
     (or (not I) (not H) (= G E))
     (or (not I) (not H) (= J F))
     (or (not I) (not H) (= K J))
     (or (not I) (not H) (= L G))
     (or (not H) (and I H))
     (or (not I) (= E (+ 1 C)))
     (or (not I) (= F (+ 2 D)))
     (or (not I) (and I A))
     (= H true)
     (not (= (<= C M) B)))
      )
      (main@_bb K L M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Bool) (E Int) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) ) 
    (=>
      (and
        (main@_bb E A B)
        (let ((a!1 (or (not H) (not (= (<= 1025 E) F)))))
  (and (or (not C) D (not H))
       a!1
       (or (not H) (= J (ite F 1 0)))
       (or (not H) (and C H))
       (or (not I) (and I H))
       (or (not L) (= K (= J 0)))
       (or (not L) (and L I))
       (or (not M) (and M L))
       (or (not N) (and N M))
       (or (not O) (and O N))
       (or (not H) (not G))
       (or K (not L))
       (= O true)
       (not (= (<= A B) D))))
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
