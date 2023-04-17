; ./hopv/./lia/mochi/array_init_000.smt2
(set-logic HORN)

(declare-fun |init$unknown:4| ( Int Int Int Int ) Bool)
(declare-fun |init$unknown:6| ( Int Int Int Int ) Bool)
(declare-fun |update$unknown:15| ( Int Int Int Int ) Bool)
(declare-fun |mk_array$unknown:9| ( Int Int Int ) Bool)
(declare-fun |update$unknown:12| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (|update$unknown:15| A E D B)
        (and (= 0 G) (= F (+ 1 B)) (= D 1) (not (= (= 0 G) (>= B C))))
      )
      (|init$unknown:4| A E C F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (|init$unknown:4| B A D C)
        (and (not (= 0 E)) (not (= (= 0 E) (>= C D))))
      )
      (|init$unknown:6| B A D C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (|init$unknown:4| A D C B)
        (and (= 0 F) (= E 1) (not (= (= 0 F) (>= B C))))
      )
      (|update$unknown:12| A D B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (|init$unknown:6| B A D F)
        (and (= 0 G) (= F (+ 1 C)) (= E 1) (not (= (= 0 G) (>= C D))))
      )
      (|init$unknown:6| B A D C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (|mk_array$unknown:9| A C B)
        (= D 0)
      )
      (|init$unknown:4| A C B D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (let ((a!1 (= (= 0 F) (and (not (= 0 D)) (not (= 0 E))))))
  (and (not (= (= 0 D) (<= 0 C)))
       (not a!1)
       (not (= 0 F))
       (= A 0)
       (= (= 0 E) (<= B C))))
      )
      (|mk_array$unknown:9| A C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (let ((a!1 (= (= 0 F) (and (not (= 0 D)) (not (= 0 E))))))
  (and (not (= (= 0 D) (<= 0 C)))
       (not a!1)
       (= 0 F)
       (= A (- 1))
       (= (= 0 E) (<= B C))))
      )
      (|mk_array$unknown:9| A C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (|update$unknown:12| F D B)
        (and (= 0 E) (= A F) (not (= (= 0 E) (= D B))))
      )
      (|update$unknown:15| A D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (and (not (= 0 E)) (= A C) (not (= (= 0 E) (= D B))))
      )
      (|update$unknown:15| A D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (|init$unknown:6| F B A H)
        (let ((a!1 (= (= 0 E) (and (not (= 0 D)) (not (= 0 C))))))
  (and (not (= (= 0 G) (>= F 1)))
       (not a!1)
       (= (= 0 D) (<= A B))
       (= 0 G)
       (not (= 0 E))
       (= H 0)
       (not (= (= 0 C) (<= 0 B)))))
      )
      false
    )
  )
)

(check-sat)
(exit)
