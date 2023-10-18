; ./prepared/hopv/./lia/termination/Ackermann00_000.smt2
(set-logic HORN)


(declare-fun |ack_1030$unknown:8| ( Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |fail$unknown:21| ( Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (|ack_1030$unknown:8| H G F E D C B A)
        (and (= I 1) (not (= 0 E)))
      )
      (|fail$unknown:21| I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (v_8 Int) (v_9 Int) (v_10 Int) ) 
    (=>
      (and
        (let ((a!1 (= (= 0 H) (and (not (= 0 F)) (not (= 0 G))))))
  (and (= (= 0 G) (<= A 0))
       (= (= 0 F) (<= B 0))
       (not (= 0 H))
       (= E 0)
       (= D 0)
       (= C 0)
       (not a!1)
       (= v_8 E)
       (= v_9 D)
       (= v_10 C)))
      )
      (|ack_1030$unknown:8| B E D C A v_8 v_9 v_10)
    )
  )
)
(assert
  (forall ( (A Int) ) 
    (=>
      (and
        (|fail$unknown:21| A)
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
