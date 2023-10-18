; ./prepared/hcai/./svcomp/O0/trex01_true-unreach-call_true-termination_000.smt2
(set-logic HORN)


(declare-fun |main@_bb3| ( Int Int ) Bool)
(declare-fun |main@verifier.error.split| ( ) Bool)
(declare-fun |main@entry| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        true
      )
      (main@entry A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Bool) (Q Int) (R Int) (S Int) ) 
    (=>
      (and
        (main@entry N B)
        (and (or (not F) (not E) (not D))
     (or (not E) F (not H))
     (or (not P) (not O) (= Q 1))
     (or (not P) (not O) (= R Q))
     (or (not D) (and E D))
     (or (not D) (not C))
     (or (not H) (and H E))
     (or (not H) (not G))
     (or (not I) (and I D))
     (or (not J) (and J H))
     (or (not O) (and P O))
     (or (not P) (= K N))
     (or (not P) (= L N))
     (or (not P) (= M N))
     (or (not P) (and P (or J I)))
     (= O true)
     (= A B))
      )
      (main@_bb3 R S)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Bool) (F Bool) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main@_bb3 C I)
        (and (or (not F) (not E) (= G D))
     (or (not F) (not E) (= H G))
     (or (not F) B (not A))
     (or (not E) (and F E))
     (or (not F) (= D (* 2 C)))
     (or (not F) (and A F))
     (= E true)
     (not (= (<= I C) B)))
      )
      (main@_bb3 H I)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Int) (E Bool) (F Bool) (G Bool) (H Bool) (I Int) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) ) 
    (=>
      (and
        (main@_bb3 D A)
        (let ((a!1 (or (not G) (not (= (<= D 0) E)))))
  (and (or (not G) (not C) (not B))
       (or (not H) (and G H))
       (or (not L) (and K L))
       (or (not M) (and M L))
       (or (not N) (and N M))
       (or (not K) (= J (= I 0)))
       (or (not K) (and K H))
       (or (not K) J)
       a!1
       (or (not G) (= I (ite E 1 0)))
       (or (not G) (and G B))
       (or (not G) (not F))
       (= N true)
       (not (= (<= A D) C))))
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
