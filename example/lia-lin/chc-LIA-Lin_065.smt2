; ./hcai/./svcomp/O3/sum01_bug02_false-unreach-call_true-termination_000.smt2
(set-logic HORN)

(declare-fun |main@.lr.ph| ( Int Int Int Int ) Bool)
(declare-fun |main@entry| ( Int ) Bool)
(declare-fun |main@orig.main.exit.split| ( ) Bool)

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
  (forall ( (A Int) (B Int) (C Bool) (D Bool) (E Int) (F Int) (G Bool) (H Bool) (I Int) (J Int) (K Int) (L Int) (M Int) ) 
    (=>
      (and
        (main@entry B)
        (and (= A B)
     (or (not H) (not D) (not C))
     (or (not H) (not G) (= E 0))
     (or (not H) (not G) (= F 1))
     (or (not H) (not G) (= I 10))
     (or (not H) (not G) (= K F))
     (or (not H) (not G) (= L I))
     (or (not H) (not G) (= M E))
     (or (not G) (and H G))
     (or (not H) (and H C))
     (= G true)
     (not (= (<= 1 J) D)))
      )
      (main@.lr.ph J K L M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) ) 
    (=>
      (and
        (main@entry B)
        (and (= A B)
     (or (not N) (not D) (= E 0))
     (or (not N) (not D) (= H E))
     (or (not N) (not D) C)
     (or (not N) (= L (or J I)))
     (or (not N) (not (= L M)))
     (or (not N) (= I (= H G)))
     (or (not N) (= J (= H 0)))
     (or (not N) (= G (* 2 F)))
     (or (not N) (and N D))
     (or (not N) (not K))
     (or (not N) M)
     (or (not O) (and O N))
     (= O true)
     (not (= (<= 1 F) C)))
      )
      main@orig.main.exit.split
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Int) (E Int) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Bool) (M Bool) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (main@.lr.ph O E D C)
        (and (not (= (<= O E) F))
     (= B (+ 2 C))
     (= H (+ 1 E))
     (= I (+ (- 1) D))
     (= G (ite A B C))
     (or (not M) (not L) (= J G))
     (or (not M) (not L) (= K H))
     (or (not M) (not L) (= N I))
     (or (not M) (not L) (= P K))
     (or (not M) (not L) (= Q N))
     (or (not M) (not L) (= R J))
     (or (not M) (not L) F)
     (or (not L) (and M L))
     (= L true)
     (not (= (<= D E) A)))
      )
      (main@.lr.ph O P Q R)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Bool) (I Int) (J Bool) (K Int) (L Int) (M Bool) (N Int) (O Int) (P Int) (Q Int) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) ) 
    (=>
      (and
        (main@.lr.ph O G E C)
        (and (not (= (<= O G) H))
     (= B (+ 2 C))
     (= D (+ (- 1) E))
     (= F (+ 1 G))
     (= I (ite A B C))
     (or (not M) (not J) (= K I))
     (or (not M) (not J) (= L K))
     (or (not M) (not J) (not H))
     (or (not W) (not M) (= N L))
     (or (not W) (not M) (= Q N))
     (or (not M) (and M J))
     (or (not W) (= U (or S R)))
     (or (not W) (not (= U V)))
     (or (not W) (= R (= Q P)))
     (or (not W) (= S (= Q 0)))
     (or (not W) (= P (* 2 O)))
     (or (not W) (and W M))
     (or (not W) (not T))
     (or (not W) V)
     (or (not X) (and X W))
     (= X true)
     (not (= (<= E G) A)))
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
