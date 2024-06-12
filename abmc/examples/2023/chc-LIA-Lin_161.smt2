; ./prepared/vmt/./lustre/SYNAPSE_all_e8_251_e3_1472_000.smt2
(set-logic HORN)


(declare-fun |state| ( Int Int Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Int Int Int Int Bool Bool Int Int Bool Int Bool Bool Int ) Bool)

(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Int) (P Bool) (Q Bool) (R Int) (S Int) (T Int) (U Int) (V Int) (W Bool) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) ) 
    (=>
      (and
        (let ((a!1 (and S1
                (or (not (<= 1 S)) (not (<= 1 R)))
                (not (<= 2 R))
                (= (+ B1 (* (- 1) R) (* (- 1) S) (* (- 1) T)) 0))))
  (and (not (= (and N1 J1) M))
       (= W Q)
       (= N (and M (<= 0 G)))
       (= N W)
       (= X T)
       (= U R)
       (= H G)
       (= H J)
       (= I X)
       (= J V)
       (= J I)
       (= K 0)
       (= K Z)
       (= L 0)
       (= L U)
       (= O G)
       (= O B1)
       (= Z S)
       (or (not A) (= B 0))
       (or (not J1) (= A1 K1))
       (or (= A1 P1) J1)
       (or (not J1) (= G1 E))
       (or (= G1 M1) J1)
       (or (not J1) (= I1 C))
       (or (= I1 R1) J1)
       (or (not C1) (= H1 B))
       (or (not C1) (= F1 E1))
       (or (not C1) (= Y D1))
       (or (= A1 Y) C1)
       (or (= G1 F1) C1)
       (or (= I1 H1) C1)
       (or (not F) (= Q1 1))
       (or (not F) (= L1 0))
       (or (not D) (= C 1))
       (or (not D) (= E 0))
       (or (not N1) (= R1 Q1))
       (or (not N1) (= P1 O1))
       (or (not N1) (= M1 L1))
       (= S1 true)
       (= (or (not Q) a!1) P)))
      )
      (state O
       B1
       N
       W
       N1
       J1
       C1
       M
       H
       J
       L
       U
       K
       Z
       I
       X
       I1
       R1
       C
       G1
       M1
       E
       A1
       K1
       P1
       H1
       B
       F1
       E1
       Y
       D1
       Q
       V
       R
       S
       T
       S1
       P
       G
       L1
       F
       Q1
       D
       A
       O1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Int) (P Bool) (Q Bool) (R Int) (S Int) (T Int) (U Int) (V Int) (W Bool) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Bool) (K1 Int) (L1 Int) (M1 Bool) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Bool) (W1 Int) (X1 Bool) (Y1 Int) (Z1 Bool) (A2 Bool) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Bool) (O2 Bool) (P2 Int) (Q2 Bool) (R2 Bool) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Bool) (Z2 Int) (A3 Bool) (B3 Int) (C3 Int) (D3 Bool) (E3 Int) (F3 Int) (G3 Bool) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Bool) ) 
    (=>
      (and
        (state O
       B1
       N
       W
       G3
       J1
       C1
       M
       H
       J
       L
       U
       K
       Z
       I
       X
       I1
       K3
       C
       G1
       F3
       E
       A1
       K1
       I3
       H1
       B
       F1
       E1
       Y
       D1
       Q
       V
       R
       S
       T
       L3
       P
       G
       E3
       F
       J3
       D
       A
       H3)
        (let ((a!1 (and V1
                (or (not (<= 1 U1)) (not (<= 1 T1)))
                (not (<= 2 U1))
                (= (+ S2 (* (- 1) U1) (* (- 1) T1) (* (- 1) S1)) 0)))
      (a!2 (and L3
                (or (not (<= 1 R)) (not (<= 1 S)))
                (not (<= 2 R))
                (= (+ B1 (* (- 1) R) (* (- 1) S) (* (- 1) T)) 0)))
      (a!3 (= V1 (= (+ R S T (* (- 1) U1) (* (- 1) T1) (* (- 1) S1)) 0)))
      (a!4 (or (not X1) (= (+ U (* (- 1) X) W1) (- 1))))
      (a!5 (or (not X1) (= (+ Z (* (- 1) B2)) (- 1))))
      (a!6 (or (not Z1) (= (+ U Z X (* (- 1) Y1)) 1)))
      (a!7 (or (not A2) (= (+ U Z X (* (- 1) N1)) 1))))
  (and (= (<= 1 X) X1)
       (= (<= 1 X) A2)
       (= (or (not R2) a!1) Q2)
       (= (or (not Q) a!2) P)
       (not (= (and D3 M1) N2))
       (not (= (and J1 G3) M))
       a!3
       (= O2 (and W N2 (<= 0 M2)))
       (= Y2 O2)
       (= Y2 R2)
       (= W Q)
       (= N W)
       (= H2 G2)
       (= J2 I2)
       (= L2 K2)
       (= S2 P2)
       (= T2 S1)
       (= T2 H2)
       (= U2 T1)
       (= U2 J2)
       (= V2 U1)
       (= V2 L2)
       (= X2 F2)
       (= X2 W2)
       (= B1 P2)
       (= Z S)
       (= X T)
       (= U R)
       (= O B1)
       (= L U)
       (= K Z)
       (= J F2)
       (= J V)
       (= I X)
       (= H J)
       (or (not M1) (= L1 N1))
       (or (not M1) (= P1 O1))
       (or (not M1) (= R1 Q1))
       (or M1 (= Z P1))
       (or M1 (= X L1))
       (or M1 (= U R1))
       a!4
       a!5
       (or (not X1) (= E2 0))
       (or X1 (= Z B2))
       (or X1 (= X W1))
       (or X1 (= U E2))
       a!6
       (or (not Z1) (= C2 0))
       (or (not Z1) (= D2 1))
       (or Z1 (= Z C2))
       (or Z1 (= X Y1))
       (or Z1 (= U D2))
       a!7
       (or (not A2) (= O1 0))
       (or (not A2) (= Q1 1))
       (or A2 (= Z O1))
       (or A2 (= X N1))
       (or A2 (= U Q1))
       (or (not A3) (= W1 G2))
       (or (not A3) (= I2 B2))
       (or (not A3) (= K2 E2))
       (or A3 (= Z2 G2))
       (or A3 (= B3 I2))
       (or A3 (= C3 K2))
       (or D3 (= P1 B3))
       (or D3 (= R1 C3))
       (or (not D3) (= Y1 Z2))
       (or D3 (= Z2 L1))
       (or (not D3) (= B3 C2))
       (or (not D3) (= C3 D2))
       (or J1 (= I1 K3))
       (or (not J1) (= I1 C))
       (or J1 (= G1 F3))
       (or (not J1) (= G1 E))
       (or J1 (= A1 I3))
       (or (not J1) (= A1 K1))
       (or C1 (= I1 H1))
       (or (not C1) (= H1 B))
       (or C1 (= G1 F1))
       (or (not C1) (= F1 E1))
       (or C1 (= A1 Y))
       (or (not C1) (= Y D1))
       (= (<= 1 Z) Z1)))
      )
      (state P2
       S2
       O2
       Y2
       M1
       D3
       A3
       N2
       F2
       X2
       L2
       V2
       J2
       U2
       H2
       T2
       C3
       R1
       D2
       B3
       P1
       C2
       Z2
       Y1
       L1
       K2
       E2
       I2
       B2
       G2
       W1
       R2
       W2
       U1
       T1
       S1
       V1
       Q2
       M2
       O1
       A2
       Q1
       Z1
       X1
       N1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Int) (P Bool) (Q Bool) (R Int) (S Int) (T Int) (U Int) (V Int) (W Bool) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) ) 
    (=>
      (and
        (state O
       B1
       N
       W
       N1
       J1
       C1
       M
       H
       J
       L
       U
       K
       Z
       I
       X
       I1
       R1
       C
       G1
       M1
       E
       A1
       K1
       P1
       H1
       B
       F1
       E1
       Y
       D1
       Q
       V
       R
       S
       T
       S1
       P
       G
       L1
       F
       Q1
       D
       A
       O1)
        (not P)
      )
      false
    )
  )
)

(check-sat)
(exit)
