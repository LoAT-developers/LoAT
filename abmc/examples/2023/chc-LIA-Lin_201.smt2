; ./prepared/vmt/./lustre/PRODUCER_CONSUMER_vt_e2_1352_000.smt2
(set-logic HORN)


(declare-fun |state| ( Int Int Int Int Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Int Int Int Int Int Bool Int Int Int Int Int Int Int Bool Bool Bool ) Bool)

(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (P Int) (Q Int) (R Int) (S Bool) (T Bool) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Bool) (E1 Bool) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Int) ) 
    (=>
      (and
        (let ((a!1 (or (not T) (<= (- 1) (+ W (* (- 1) V) (* (- 1) U)))))
      (a!2 (= (and D1 E1 (not (<= F1 0))) T))
      (a!3 (= N (or (and (not B) (not L1) (not Q1)) M)))
      (a!4 (not (= (or (and B Q1) (and B L1) (and L1 Q1)) M))))
  (and (not (= (or B L1 Q1) O))
       (= a!1 S)
       a!2
       (= O E1)
       a!3
       (= N D1)
       (= R Q)
       (= R W)
       (= P I)
       (= P F1)
       (= G Q)
       (= G F)
       (= F Y)
       (= H 0)
       (= H A1)
       (= J I)
       (= J G)
       (= K 0)
       (= K B1)
       (= L 0)
       (= L C1)
       (= Y X)
       (= A1 Z)
       (= B1 U)
       (= C1 V)
       (or Q1 (= H1 G1))
       (or (not Q1) (= P1 O1))
       (or (not Q1) (= G1 I1))
       (or (not L1) (= N1 M1))
       (or B (= H1 J1))
       (or (not B) (= H1 K1))
       (or (not B) (= A R1))
       a!4))
      )
      (state R
       W
       P
       F1
       O
       E1
       N
       D1
       B
       Q1
       L1
       M
       L
       C1
       K
       B1
       J
       G
       H
       A1
       F
       Y
       H1
       K1
       J1
       G1
       I1
       T
       V
       U
       Q
       Z
       X
       S
       I
       A
       R1
       P1
       O1
       N1
       M1
       C
       D
       E)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Bool) (F1 Bool) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Int) (P1 Int) (Q1 Bool) (R1 Int) (S1 Int) (T1 Bool) (U1 Int) (V1 Bool) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Int) (A2 Bool) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Bool) (I2 Bool) (J2 Bool) (K2 Int) (L2 Int) (M2 Bool) (N2 Bool) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Bool) (B3 Int) (C3 Int) (D3 Bool) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Bool) (J3 Int) ) 
    (=>
      (and
        (state S
       X
       Q
       G1
       P
       F1
       O
       E1
       B
       I3
       D3
       N
       M
       D1
       L
       C1
       K
       H
       I
       B1
       G
       Z
       I1
       L1
       K1
       H1
       J1
       U
       W
       V
       R
       A1
       Y
       T
       J
       A
       J3
       H3
       G3
       F3
       E3
       C
       D
       E)
        (let ((a!1 (not (= (or (and T1 Q1) (and T1 N1) (and Q1 N1)) H2)))
      (a!2 (not (= (or (and B D3) (and B I3) (and D3 I3)) N)))
      (a!3 (or (not N2) (<= (- 1) (+ Q2 (* (- 1) P2) (* (- 1) O2)))))
      (a!4 (or (not U) (<= (- 1) (+ X (* (- 1) W) (* (- 1) V)))))
      (a!5 (= (and A3 Z2 (not (<= B3 0))) N2))
      (a!6 (= (and E1 F1 (not (<= G1 0))) U))
      (a!7 (and E1 (or H2 (and (not T1) (not Q1) (not N1)))))
      (a!8 (or (not V1) (= (+ B1 (* (- 1) W1)) (- 1))))
      (a!9 (or (not V1) (= (+ Z (* (- 1) R1)) 1)))
      (a!10 (or (not Y1) (= (+ C1 (* (- 1) U1)) (- 1))))
      (a!11 (or (not Y1) (= (+ B1 (* (- 1) X1)) 1)))
      (a!12 (or (not A2) (= (+ D1 (* (- 1) O1)) (- 1))))
      (a!13 (or (not A2) (= (+ B1 (* (- 1) Z1)) 1))))
  (and (= (<= 1 B1) A2)
       (= (<= 1 Z) V1)
       a!1
       a!2
       (= a!3 M2)
       (= a!4 T)
       a!5
       a!6
       (= I2 a!7)
       (= Z2 I2)
       (= A3 J2)
       (= F1 J2)
       (= P F1)
       (= O E1)
       (= B2 P1)
       (= D2 C2)
       (= F2 S1)
       (= G2 M1)
       (= Q2 L2)
       (= S2 B2)
       (= S2 R2)
       (= U2 D2)
       (= U2 T2)
       (= W2 E2)
       (= W2 V2)
       (= X2 F2)
       (= X2 O2)
       (= Y2 G2)
       (= Y2 P2)
       (= B3 K2)
       (= G1 K2)
       (= D1 W)
       (= C1 V)
       (= B1 A1)
       (= Z Y)
       (= X L2)
       (= S X)
       (= Q G1)
       (= M D1)
       (= L C1)
       (= K H)
       (= I B1)
       (= H E2)
       (= H R)
       (= G Z)
       (or I3 (= I1 H1))
       (or (not I3) (= H1 J1))
       (or (not N1) (= M1 O1))
       (or N1 (= D1 M1))
       (or (not Q1) (= P1 R1))
       (or (not Q1) (= W1 C2))
       (or Q1 (= Z P1))
       (or Q1 (= C3 C2))
       (or (not T1) (= S1 U1))
       (or (not T1) (= X1 C3))
       (or T1 (= C1 S1))
       (or T1 (= C3 Z1))
       a!8
       a!9
       (or V1 (= B1 W1))
       (or V1 (= Z R1))
       a!10
       a!11
       (or Y1 (= C1 U1))
       (or Y1 (= B1 X1))
       a!12
       a!13
       (or A2 (= D1 O1))
       (or A2 (= B1 Z1))
       (or (not B) (= I1 L1))
       (or B (= I1 K1))
       (= (<= 1 B1) Y1)))
      )
      (state L2
       Q2
       K2
       B3
       J2
       A3
       I2
       Z2
       T1
       Q1
       N1
       H2
       G2
       Y2
       F2
       X2
       E2
       W2
       D2
       U2
       B2
       S2
       C3
       X1
       Z1
       C2
       W1
       N2
       P2
       O2
       V2
       T2
       R2
       M2
       F
       S1
       U1
       P1
       R1
       M1
       O1
       V1
       Y1
       A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (P Int) (Q Int) (R Int) (S Bool) (T Bool) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Bool) (E1 Bool) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Int) ) 
    (=>
      (and
        (state R
       W
       P
       F1
       O
       E1
       N
       D1
       B
       Q1
       L1
       M
       L
       C1
       K
       B1
       J
       G
       H
       A1
       F
       Y
       H1
       K1
       J1
       G1
       I1
       T
       V
       U
       Q
       Z
       X
       S
       I
       A
       R1
       P1
       O1
       N1
       M1
       C
       D
       E)
        (not S)
      )
      false
    )
  )
)

(check-sat)
(exit)
