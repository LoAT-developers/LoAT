; ./prepared/vmt/./conc/fib_bench_safe_v2_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Int) (E Int) (F Bool) (G Bool) (H Int) ) 
    (=>
      (and
        (and (= D 0)
     (= H 0)
     (= A 1)
     (or (not F) (not G))
     (or (not C) (not B))
     (not B)
     (not G)
     (not F)
     (not C)
     (= E 1))
      )
      (state G F C B E D A H)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Int) (E Int) (F Bool) (G Bool) (H Int) (I Int) (J Bool) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Int) ) 
    (=>
      (and
        (state Q P C B E D A R)
        (let ((a!1 (and F (= R I) (= (+ E A (* (- 1) H)) 0)))
      (a!2 (and O (not M) (= D L) (= E K)))
      (a!3 (and M (= D L) (= (+ E A (* (- 1) K)) 0)))
      (a!4 (and G (not F) (= A H) (= R I)))
      (a!5 (and (not G) (not F) (= A H) (= (+ R (* (- 1) I)) (- 1))))
      (a!6 (and (not O) (not M) (= E K) (= (+ D (* (- 1) L)) (- 1)))))
  (and (or P Q (<= 5 R) (not J) a!1)
       (or B C (not (<= 5 D)) (not N) a!2)
       (or B C (<= 5 D) (not N) a!3)
       (or Q (not P) (not J) a!4)
       (or B (not C) (not N) a!2)
       (or (not Q) (not J) a!5)
       (or (not B) (not N) a!6)
       (or (not P) (not Q))
       (or (not G) (not F))
       (or J (and (= A H) (= R I) (= P G) (= Q F)))
       (or N (and (= D L) (= E K) (= B M) (= C O)))
       (or (not N) (not J))
       (or (not O) (not M))
       (or (not B) (not C))
       (or P Q (not J) (not (<= 5 R)) a!4)))
      )
      (state F G O M K L H I)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Int) (E Int) (F Bool) (G Bool) (H Int) ) 
    (=>
      (and
        (state G F C B E D A H)
        (or (not (<= E 144)) (not (<= A 144)))
      )
      false
    )
  )
)

(check-sat)
(exit)
