; ./prepared/hcai/./svcomp/O3/id_o100_false-unreach-call_000.smt2
(set-logic HORN)


(declare-fun |main@entry| ( Int ) Bool)
(declare-fun |main@id.exit.split| ( ) Bool)
(declare-fun |main@tailrecurse.i| ( Int Int ) Bool)

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
  (forall ( (A Int) (B Int) (C Bool) (D Bool) (E Int) (F Int) (G Bool) (H Bool) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (main@entry B)
        (and (= A B)
     (or (not H) (not D) (not C))
     (or (not H) (not G) (= F E))
     (or (not H) (not G) (= I 0))
     (or (not H) (not G) (= J F))
     (or (not H) (not G) (= K I))
     (or (not G) (and H G))
     (or (not H) (and H C))
     (= G true)
     (= D (= E 0)))
      )
      (main@tailrecurse.i J K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Int) (E Int) (F Int) (G Bool) (H Bool) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (main@tailrecurse.i A B)
        (and (= D (+ (- 1) A))
     (= E (+ 1 B))
     (or (not H) (not G) (= F D))
     (or (not H) (not G) (= I E))
     (or (not H) (not G) (= J F))
     (or (not H) (not G) (= K I))
     (or (not H) (not G) (not C))
     (or (not G) (and H G))
     (= G true)
     (= C (= D 0)))
      )
      (main@tailrecurse.i J K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) ) 
    (=>
      (and
        (main@entry B)
        (and (= A B)
     (or (not H) (not E) (= G F))
     (or (not H) (not E) D)
     (or (not H) (not F) (not E))
     (or (not H) (and H E))
     (or (not H) G)
     (or (not I) (and I H))
     (= I true)
     (= D (= C 0)))
      )
      main@id.exit.split
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Bool) (E Int) (F Bool) (G Int) (H Int) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) ) 
    (=>
      (and
        (main@tailrecurse.i A B)
        (and (= C (+ (- 1) A))
     (= E (+ 1 B))
     (or (not J) (not F) (= G E))
     (or (not J) (not F) (= H G))
     (or (not J) (not F) D)
     (or (not M) (not J) (= L K))
     (or (not M) (not J) (= K I))
     (or (not J) (= I (= H 100)))
     (or (not J) (and J F))
     (or (not M) (and M J))
     (or (not M) L)
     (or (not N) (and N M))
     (= N true)
     (= D (= C 0)))
      )
      main@id.exit.split
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        main@id.exit.split
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
