; ./prepared/tricera/sv-comp-2020/./mixed/id_build.i.v+lhb-reducer.c-1_000.smt2
(set-logic HORN)


(declare-fun |inv_main32| ( Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main29| ( Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |CHC_COMP_FALSE| ( ) Bool)
(declare-fun |inv_main40| ( Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main5| ( Int Int Int Int Int ) Bool)
(declare-fun |inv_main21| ( Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (and (= D 0) (= E 0))
      )
      (inv_main5 E D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) ) 
    (=>
      (and
        (inv_main32 A E F G J D H L B C M)
        (and (= I 0) (<= 2 (+ J (* (- 1) D))) (not (<= H 7)) (= K (+ 1 D)))
      )
      (inv_main32 A E F G J K I L B C M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (v_34 Int) ) 
    (=>
      (and
        (inv_main32 Z O U F1 R W C1 F C G H)
        (let ((a!1 (not (<= 1 (+ R (* (- 1) W)))))
      (a!2 (and (<= 1 (+ R (* (- 1) W))) (= H1 1)))
      (a!3 (or (and (<= 0 J) (= E 1)) (and (not (<= 0 J)) (= E 0)))))
  (and (= S (+ 1 Q))
       (= Q T)
       (= P H)
       (= N K)
       (= M Y)
       (= L F1)
       (= K Z)
       (= J W)
       (= I C)
       (not (= E 0))
       (= D D1)
       (= B J)
       (= A F)
       (= B1 G)
       (= A1 I)
       (= Y O)
       (= X A)
       (= V G1)
       (not (= H1 0))
       (= G1 U)
       (= E1 L)
       (= D1 R)
       (<= C1 7)
       (or (and a!1 (= H1 0)) a!2)
       a!3
       (= T C1)
       (= v_34 E)))
      )
      (inv_main32 N M V E1 D B S X A1 E v_34)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (v_25 Int) ) 
    (=>
      (and
        (inv_main5 K X J D Y)
        (let ((a!1 (or (and (<= 1 T) (= A 1)) (and (not (<= 1 T)) (= A 0))))
      (a!2 (or (and (<= 0 H) (= Q 1)) (and (not (<= 0 H)) (= Q 0)))))
  (and (= I X)
       (= H 0)
       (= G (+ 1 O))
       (= F I)
       (= E A)
       (= C R)
       (= B W)
       (not (= A 0))
       (= S D)
       (= R T)
       (not (= Q 0))
       (= P H)
       (= O N)
       (= N 0)
       (= M A)
       (= W K)
       (= V U)
       (= U J)
       (<= 1 T)
       a!1
       a!2
       (= L S)
       (= v_25 Q)))
      )
      (inv_main32 B F V L C P G E M Q v_25)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (v_14 Int) ) 
    (=>
      (and
        (inv_main5 H K A J L)
        (let ((a!1 (or (and (<= 1 B) (= D 1)) (and (not (<= 1 B)) (= D 0)))))
  (and (= G 0)
       (= F A)
       (= E H)
       (= D 0)
       (= C B)
       (= N J)
       (= M K)
       (<= 1 B)
       a!1
       (= I 0)
       (= v_14 D)))
      )
      (inv_main21 E M F N C I G D v_14)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (v_23 Int) ) 
    (=>
      (and
        (inv_main32 R W K F P Q S I L T U)
        (let ((a!1 (and (<= 1 (+ P (* (- 1) Q))) (= O 1)))
      (a!2 (not (<= 1 (+ P (* (- 1) Q))))))
  (and (= H L)
       (= G P)
       (= E I)
       (= D W)
       (= C F)
       (= B U)
       (= A T)
       (= O 0)
       (= N S)
       (= M K)
       (= V Q)
       (<= S 7)
       (or a!1 (and a!2 (= O 0)))
       (= J R)
       (= v_23 O)))
      )
      (inv_main40 J D M C G V N E H A B O v_23)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (v_33 Int) ) 
    (=>
      (and
        (inv_main32 H J C D1 Q E B N O I Y)
        (let ((a!1 (and (<= 1 (+ Q (* (- 1) E))) (= S 1)))
      (a!2 (not (<= 1 (+ Q (* (- 1) E)))))
      (a!3 (or (and (<= 0 R) (= M 1)) (and (not (<= 0 R)) (= M 0)))))
  (and (not (= S 0))
       (= R E)
       (= P N)
       (= M 0)
       (= L F1)
       (= K J)
       (= G O)
       (= F I)
       (= D C)
       (= A T)
       (= B1 B)
       (= A1 P)
       (= Z G)
       (= X B1)
       (= W Y)
       (= V G1)
       (= U K)
       (= G1 Q)
       (= F1 H)
       (= E1 D)
       (= C1 R)
       (<= B 7)
       (or a!1 (and a!2 (= S 0)))
       a!3
       (= T D1)
       (= v_33 M)))
      )
      (inv_main29 L U E1 A V C1 X A1 Z M v_33)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (v_24 Int) ) 
    (=>
      (and
        (inv_main5 M S J T P)
        (let ((a!1 (or (and (<= 1 Q) (= C 1)) (and (not (<= 1 Q)) (= C 0))))
      (a!2 (or (and (<= 0 K) (= B 1)) (and (not (<= 0 K)) (= B 0)))))
  (and (= I A)
       (= H K)
       (= G 0)
       (= F O)
       (= E L)
       (= D C)
       (not (= C 0))
       (= B 0)
       (= A J)
       (= R C)
       (= O S)
       (= N G)
       (= L M)
       (= X Q)
       (= W T)
       (= V W)
       (= U X)
       (<= 1 Q)
       a!1
       a!2
       (= K 0)
       (= v_24 B)))
      )
      (inv_main29 E F I V U H N D R B v_24)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (inv_main21 G I B D F E A H C)
        true
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (inv_main29 F E A I C B H D K J G)
        true
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) ) 
    (=>
      (and
        (inv_main40 D B C J G I M F E K H A L)
        true
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        CHC_COMP_FALSE
      )
      false
    )
  )
)

(check-sat)
(exit)
