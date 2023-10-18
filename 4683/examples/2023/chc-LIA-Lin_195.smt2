; ./prepared/vmt/./conc/fib_bench_safe_v1_000.smt2
(set-logic HORN)


(declare-fun |state| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= D 1) (= B 1) (= C 0) (= A 0))
      )
      (state D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Bool) (H Int) (I Int) (J Bool) ) 
    (=>
      (and
        (state D C B A)
        (let ((a!1 (and (= (+ C (* (- 1) H)) (- 1)) (= (+ D B (* (- 1) I)) 0)))
      (a!2 (and (= (+ A (* (- 1) E)) (- 1)) (= (+ D B (* (- 1) F)) 0))))
  (and (or (not (<= 5 A)) (not G) (and (= A E) (= B F)))
       (or (<= 5 C) (not J) a!1)
       (or (not J) (not (<= 5 C)) (and (= C H) (= D I)))
       (or G (and (= A E) (= B F)))
       (or J (and (= C H) (= D I)))
       (or (not J) (not G))
       (or (<= 5 A) (not G) a!2)))
      )
      (state I H F E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (state D C B A)
        (or (not (<= D 144)) (not (<= B 144)))
      )
      false
    )
  )
)

(check-sat)
(exit)
