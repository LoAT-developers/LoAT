; ./prepared/hcai/./svcomp/O3/EvenOdd01_true-unreach-call_true-no-overflow_true-termination_000.smt2
(set-logic HORN)


(declare-fun |main@entry| ( ) Bool)
(declare-fun |main@isOdd.exit.split| ( ) Bool)
(declare-fun |main@tailrecurse.i| ( Int Int ) Bool)

(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        true
      )
      main@entry
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        main@entry
        (and (or (not C) (not B) (= D E))
     (or (not C) (not B) (= F D))
     (or (not B) (and C B))
     (not A)
     (= B true)
     (not (= (<= 0 E) A)))
      )
      (main@tailrecurse.i E F)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Int) (J Bool) (K Int) (L Bool) (M Bool) (N Int) (O Int) (P Int) ) 
    (=>
      (and
        (main@tailrecurse.i O I)
        (and (or (not C) B (not A))
     (or (not E) (not D) (not C))
     (or (not F) (not B) (not A))
     (or (not H) (not G) (not F))
     (or (not M) (and G F) (and D C))
     (or (not M) (not L) (= N K))
     (or (not M) (not L) (= P N))
     (or (not M) (not L) (not J))
     (or (not C) (= E (= I 0)))
     (or (not C) (and C A))
     (or (not D) C)
     (or (not F) (= H (= I 1)))
     (or (not F) (and F A))
     (or (not G) F)
     (or (not L) (and M L))
     (or (not M) (= K (+ (- 2) I)))
     (or (not M) (= J (= I 2)))
     (= L true)
     (not (= (<= 1 I) B)))
      )
      (main@tailrecurse.i O P)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Int) (M Bool) (N Bool) (O Int) (P Bool) (Q Bool) (R Int) (S Int) (T Int) (U Int) (V Bool) (W Bool) (X Bool) ) 
    (=>
      (and
        (main@tailrecurse.i S F)
        (and (or (not W) (and P Q) (and N M) (and K J))
     (or (not J) (and P D) (and M C))
     (or (not K) (not J) (= L 0))
     (or (not K) (not J) (= T L))
     (or (not K) (not J) G)
     (or (not M) B (not A))
     (or (not M) (not H) (not C))
     (or (not N) (not M) (= O 0))
     (or (not N) (not M) (= T O))
     (or (not N) (not M) H)
     (or (not P) (not B) (not A))
     (or (not P) (not Q) (= R 1))
     (or (not P) (not Q) (= T R))
     (or (not P) (not I) (not D))
     (or (not P) I (not Q))
     (or (not W) (= U (mod S 2)))
     (or (not W) (= V (= T U)))
     (or (not W) (not V))
     (or (not X) (and X W))
     (or (not J) (= E (+ (- 2) F)))
     (or (not J) (= G (= F 2)))
     (or (not K) J)
     (or (not M) (= H (= F 0)))
     (or (not M) (and M A))
     (or M (not C))
     (or (not N) M)
     (or (not P) (= I (= F 1)))
     (or (not P) (and P A))
     (or P (not D))
     (or P (not Q))
     (= X true)
     (not (= (<= 1 F) B)))
      )
      main@isOdd.exit.split
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        main@isOdd.exit.split
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
