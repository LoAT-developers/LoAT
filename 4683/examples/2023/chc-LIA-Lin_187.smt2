; ./prepared/vmt/./lustre/Gas_e7_435_e8_532_000.smt2
(set-logic HORN)


(declare-fun |state| ( Int Int Int Int Int Int Int Int Bool Bool Bool Bool Int Int Bool Bool Bool Bool Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Bool) (J Int) (K Bool) (L Int) (M Int) (N Int) (O Bool) (P Bool) (Q Int) (R Int) (S Bool) (T Bool) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (let ((a!1 (= A (and I (or (not K) (<= 300 G)))))
      (a!2 (or (not A) (<= N 600) (<= 0 (+ M (* (- 2) L))))))
  (and a!1
       (= T K)
       (= S (<= R 10))
       (= S I)
       (= X 0)
       (= X M)
       (= W 0)
       (= W L)
       (= V 0)
       (= V N)
       (= U 0)
       (= U G)
       (= Q 0)
       (= Q R)
       (not T)
       (= a!2 B)))
      )
      (state X M W L V N U G T K S I Q R A B O P C D E F H J)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Bool) (J Int) (K Bool) (L Bool) (M Int) (N Int) (O Int) (P Int) (Q Bool) (R Int) (S Int) (T Int) (U Int) (V Bool) (W Int) (X Int) (Y Int) (Z Bool) (A1 Bool) (B1 Bool) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Bool) (H1 Int) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Int) ) 
    (=>
      (and
        (state V1 N U1 M T1 O S1 G R1 L Q1 I O1 P1 A B Q V C D E F H J)
        (let ((a!1 (or (not A) (<= O 600) (<= 0 (+ N (* (- 2) M)))))
      (a!2 (= J1 (and I1 (or (not G1) (<= 300 H1)))))
      (a!3 (= A (and I (or (not L) (<= 300 G)))))
      (a!4 (or (not V) (= (+ P1 (* (- 1) U)) (- 1))))
      (a!5 (or (not V) (= (+ M (* (- 1) S)) (- 1))))
      (a!6 (or V (= (+ G (* (- 1) W)) (- 1))))
      (a!7 (or Q (= (+ O (* (- 1) P)) (- 1))))
      (a!8 (or Q (= (+ N (* (- 1) T)) (- 1))))
      (a!9 (or (not J1) (<= N1 600) (<= 0 (+ M1 (* (- 2) L1))))))
  (and (= a!1 B)
       (= R1 L)
       (= Q1 I)
       (= Z (and I (<= Y 10)))
       (= B1 (and (not Q) A1))
       (= G1 B1)
       (= I1 Z)
       a!2
       a!3
       (= V1 N)
       (= U1 M)
       (= T1 O)
       (= S1 G)
       (= O1 P1)
       (= X U)
       (= Y X)
       (= C1 W)
       (= D1 P)
       (= E1 R)
       (= F1 T)
       (= H1 C1)
       (= L1 E1)
       (= M1 F1)
       (= N1 D1)
       a!4
       a!5
       a!6
       (or V (= U 0))
       (or (not V) (= W 0))
       (or V (= M S))
       a!7
       a!8
       (or (not Q) (= P 0))
       (or (not Q) (= R 0))
       (or Q (= R S))
       (or (not Q) (= T 0))
       (= a!9 K1)))
      )
      (state F1 M1 E1 L1 D1 N1 C1 H1 B1 G1 Z I1 X Y J1 K1 A1 K U W P S R T)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Bool) (J Int) (K Bool) (L Int) (M Int) (N Int) (O Bool) (P Bool) (Q Int) (R Int) (S Bool) (T Bool) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (state X M W L V N U G T K S I Q R A B O P C D E F H J)
        (not B)
      )
      false
    )
  )
)

(check-sat)
(exit)
