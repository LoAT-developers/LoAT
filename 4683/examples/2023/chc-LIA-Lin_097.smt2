; ./prepared/tricera/sv-comp-2020/./mixed/s3_srvr_1.cil-1.c-1_000.smt2
(set-logic HORN)


(declare-fun |inv_main329| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main192| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main111| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main248| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main499| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main482| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main323| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main412| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main100| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main4| ( Int Int ) Bool)
(declare-fun |inv_main291| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main448| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main265| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        true
      )
      (inv_main4 B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main323 A1
             F1
             I2
             D2
             T1
             O
             J1
             D
             D1
             I
             G2
             U
             C2
             C
             J2
             A2
             J
             L
             K
             H2
             F
             E1
             S1
             H1
             A
             W
             N
             I1
             K1
             C1
             S
             T
             M
             R
             Z
             V
             B2
             Z1
             B1
             W1
             P
             H
             E2
             R1
             Q
             V1
             Y
             O1
             N1
             E
             Q1
             U1
             Y1
             P1
             G
             X1
             L1
             X
             F2
             M1
             G1
             B)
        (and (not (= K (- 1)))
     (<= 0 F2)
     (<= 0 B2)
     (<= 0 M1)
     (<= 0 L1)
     (<= 0 Z)
     (<= 0 X)
     (<= 0 V)
     (<= 0 B)
     (= H2 0))
      )
      (inv_main329 A1
             F1
             I2
             D2
             T1
             O
             J1
             D
             D1
             I
             G2
             U
             C2
             C
             J2
             A2
             J
             L
             K
             H2
             F
             E1
             S1
             H1
             A
             W
             N
             I1
             K1
             C1
             S
             T
             M
             R
             Z
             V
             B2
             Z1
             B1
             W1
             P
             H
             E2
             R1
             Q
             V1
             Y
             O1
             N1
             E
             Q1
             U1
             Y1
             P1
             G
             X1
             L1
             X
             F2
             M1
             G1
             B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main323 V
             S
             B
             E2
             X
             V1
             I1
             Y
             J2
             S1
             Z1
             A2
             I
             F
             D2
             G2
             I2
             C1
             P
             M
             X1
             B1
             N1
             G1
             G
             F2
             Q
             B2
             A1
             E1
             K
             U
             T
             D1
             J
             N
             P1
             O
             R1
             E
             J1
             U1
             A
             C2
             F1
             L
             H
             M1
             R
             Y1
             L1
             Q1
             W
             Z
             T1
             C
             H2
             H1
             O1
             K1
             W1
             D)
        (and (not (= P (- 1)))
     (not (= M 0))
     (<= 0 H2)
     (<= 0 P1)
     (<= 0 O1)
     (<= 0 K1)
     (<= 0 H1)
     (<= 0 N)
     (<= 0 J)
     (<= 0 D)
     (= P (- 4)))
      )
      (inv_main329 V
             S
             B
             E2
             X
             V1
             I1
             Y
             J2
             S1
             Z1
             A2
             I
             F
             D2
             G2
             I2
             C1
             P
             M
             X1
             B1
             N1
             G1
             G
             F2
             Q
             B2
             A1
             E1
             K
             U
             T
             D1
             J
             N
             P1
             O
             R1
             E
             J1
             U1
             A
             C2
             F1
             L
             H
             M1
             R
             Y1
             L1
             Q1
             W
             Z
             T1
             C
             H2
             H1
             O1
             K1
             W1
             D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main111 P
             H
             C1
             Y
             T1
             E
             U1
             O
             K
             N1
             A2
             J1
             O1
             R
             K2
             W
             J2
             I2
             E1
             H2
             F
             L1
             B2
             X
             L
             V
             T
             G
             D
             D2
             U
             I
             K1
             C
             F1
             P1
             S1
             B1
             A1
             Y1
             M
             Z1
             M1
             V1
             B
             A
             Z
             D1
             Q
             F2
             S
             R1
             G1
             C2
             W1
             J
             I1
             Q1
             N
             X1
             E2
             G2)
        (and (not (= E 12292))
     (not (= E 16384))
     (not (= E 8192))
     (not (= E 24576))
     (not (= E 8195))
     (not (= E 8480))
     (not (= E 8481))
     (= E 8482)
     (<= 0 G2)
     (<= 0 X1)
     (<= 0 S1)
     (<= 0 Q1)
     (<= 0 P1)
     (<= 0 I1)
     (<= 0 F1)
     (<= 0 N)
     (= H1 3))
      )
      (inv_main192 P
             H
             C1
             Y
             T1
             H1
             U1
             O
             K
             N1
             A2
             J1
             O1
             R
             K2
             W
             J2
             I2
             E1
             H2
             F
             L1
             B2
             X
             L
             V
             T
             G
             D
             D2
             U
             I
             K1
             C
             F1
             P1
             S1
             B1
             A1
             Y1
             M
             E
             M1
             V1
             B
             A
             Z
             D1
             Q
             F2
             S
             R1
             G1
             C2
             W1
             J
             I1
             Q1
             N
             X1
             E2
             G2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main111 F
             H
             T
             N
             O
             L2
             N2
             D1
             G1
             U
             A2
             M
             B2
             E1
             M2
             O1
             D2
             G2
             A
             B
             L1
             Y
             K2
             C2
             X
             I
             H1
             D
             P1
             S1
             H2
             V1
             Z
             F2
             R1
             W
             U1
             F1
             N1
             I2
             Q1
             P
             J2
             C
             J1
             Y1
             X1
             O2
             B1
             M1
             A1
             R
             E
             I1
             K
             T1
             C1
             E2
             Q
             V
             J
             W1)
        (and (not (= L2 16384))
     (not (= L2 8192))
     (not (= L2 24576))
     (not (= L2 8195))
     (= L2 8480)
     (= Z1 0)
     (= K1 0)
     (= S 8448)
     (= G 8482)
     (<= 0 E2)
     (<= 0 W1)
     (<= 0 U1)
     (<= 0 R1)
     (<= 0 C1)
     (<= 0 W)
     (<= 0 V)
     (<= 0 Q)
     (not (<= L 0))
     (not (= L2 12292)))
      )
      (inv_main192 F
             H
             T
             N
             O
             S
             N2
             D1
             G1
             U
             Z1
             M
             B2
             E1
             M2
             K1
             D2
             G2
             A
             B
             L1
             Y
             K2
             C2
             X
             I
             H1
             D
             P1
             S1
             G
             V1
             Z
             F2
             R1
             W
             U1
             F1
             N1
             L
             Q1
             L2
             J2
             C
             J1
             Y1
             X1
             O2
             B1
             M1
             A1
             R
             E
             I1
             K
             T1
             C1
             E2
             Q
             V
             J
             W1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main111 X1
             S
             E
             B1
             R
             Q
             B2
             C1
             O
             E2
             Y1
             P1
             J
             B
             K1
             I1
             C2
             O2
             D
             U1
             T1
             D1
             P
             R1
             G1
             N2
             L
             V
             U
             H
             A
             Z1
             C
             D2
             F2
             Z
             F
             E1
             L1
             G2
             N1
             H2
             F1
             M
             A2
             Q1
             S1
             V1
             W1
             N
             J2
             G
             K2
             I
             M2
             L2
             M1
             H1
             A1
             I2
             X
             J1)
        (and (= Y 0)
     (= W 0)
     (not (= Q 12292))
     (not (= Q 16384))
     (not (= Q 8192))
     (not (= Q 24576))
     (not (= Q 8195))
     (not (= Q 8480))
     (= Q 8481)
     (= K 8482)
     (<= 0 I2)
     (<= 0 F2)
     (<= 0 M1)
     (<= 0 J1)
     (<= 0 H1)
     (<= 0 A1)
     (<= 0 Z)
     (<= 0 F)
     (not (<= T 0))
     (= O1 8448))
      )
      (inv_main192 X1
             S
             E
             B1
             R
             O1
             B2
             C1
             O
             E2
             W
             P1
             J
             B
             K1
             Y
             C2
             O2
             D
             U1
             T1
             D1
             P
             R1
             G1
             N2
             L
             V
             U
             H
             K
             Z1
             C
             D2
             F2
             Z
             F
             E1
             L1
             T
             N1
             Q
             F1
             M
             A2
             Q1
             S1
             V1
             W1
             N
             J2
             G
             K2
             I
             M2
             L2
             M1
             H1
             A1
             I2
             X
             J1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main111 Q1
             A2
             Q
             X1
             K1
             H2
             V1
             R1
             J
             K
             C1
             L1
             H1
             K2
             U
             B1
             J2
             Z
             F
             G
             D2
             S
             T1
             D1
             B2
             F1
             A
             M
             I1
             D
             C2
             S1
             N
             X
             J1
             E
             I
             Z1
             N2
             O
             M1
             E2
             B
             G2
             H
             O1
             I2
             P1
             C
             L
             N1
             G1
             V
             W1
             Y
             R
             F2
             P
             W
             M2
             E1
             L2)
        (and (not (= H2 8465))
     (not (= H2 8466))
     (not (= H2 8496))
     (not (= H2 8497))
     (not (= H2 8512))
     (not (= H2 8513))
     (not (= H2 8528))
     (not (= H2 8529))
     (not (= H2 8544))
     (not (= H2 8545))
     (= H2 8560)
     (not (= H2 12292))
     (not (= H2 16384))
     (not (= H2 8192))
     (not (= H2 24576))
     (not (= H2 8195))
     (not (= H2 8480))
     (not (= H2 8481))
     (not (= H2 8482))
     (= Y1 8576)
     (= U1 8448)
     (= T 0)
     (<= 0 L2)
     (<= 0 F2)
     (<= 0 J1)
     (<= 0 W)
     (<= 0 P)
     (<= 0 I)
     (<= 0 E)
     (<= 0 M2)
     (not (<= A1 0))
     (not (= H2 8464)))
      )
      (inv_main192 Q1
             A2
             Q
             X1
             K1
             U1
             V1
             R1
             J
             K
             T
             L1
             H1
             K2
             U
             B1
             J2
             Z
             F
             G
             D2
             S
             T1
             D1
             B2
             F1
             A
             M
             I1
             D
             Y1
             S1
             N
             X
             J1
             E
             I
             Z1
             N2
             A1
             M1
             H2
             B
             G2
             H
             O1
             I2
             P1
             C
             L
             N1
             G1
             V
             W1
             Y
             R
             F2
             P
             W
             M2
             E1
             L2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main111 L1
             T
             G1
             U
             A2
             N1
             F
             S1
             J1
             K2
             U1
             X
             P1
             B
             N2
             C1
             M
             B1
             K1
             A1
             M1
             X1
             E2
             I1
             C2
             I2
             O1
             B2
             H
             T1
             Q
             C
             R
             V
             E
             Q1
             E1
             A
             M2
             L2
             S
             G
             F1
             J2
             Z
             Z1
             D2
             D1
             R1
             Y1
             O
             P
             F2
             Y
             L
             I
             K
             D
             W1
             W
             N
             H1)
        (and (= G2 8576)
     (= N1 8561)
     (not (= N1 8464))
     (not (= N1 8465))
     (not (= N1 8466))
     (not (= N1 8496))
     (not (= N1 8497))
     (not (= N1 8512))
     (not (= N1 8513))
     (not (= N1 8528))
     (not (= N1 8529))
     (not (= N1 8544))
     (not (= N1 8545))
     (not (= N1 8560))
     (not (= N1 12292))
     (not (= N1 16384))
     (not (= N1 8192))
     (not (= N1 24576))
     (not (= N1 8195))
     (not (= N1 8480))
     (not (= N1 8481))
     (not (= N1 8482))
     (= J 8448)
     (<= 0 D)
     (<= 0 W1)
     (<= 0 Q1)
     (<= 0 H1)
     (<= 0 E1)
     (<= 0 W)
     (<= 0 K)
     (<= 0 E)
     (not (<= V1 0))
     (= H2 0))
      )
      (inv_main192 L1
             T
             G1
             U
             A2
             J
             F
             S1
             J1
             K2
             H2
             X
             P1
             B
             N2
             C1
             M
             B1
             K1
             A1
             M1
             X1
             E2
             I1
             C2
             I2
             O1
             B2
             H
             T1
             G2
             C
             R
             V
             E
             Q1
             E1
             A
             M2
             V1
             S
             N1
             F1
             J2
             Z
             Z1
             D2
             D1
             R1
             Y1
             O
             P
             F2
             Y
             L
             I
             K
             D
             W1
             W
             N
             H1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main111 Z1
             E
             M1
             K
             B1
             M2
             F2
             D
             I
             F1
             N
             H2
             V1
             C2
             E2
             E1
             G2
             T1
             F
             D2
             K1
             Q1
             A1
             I1
             C1
             Y
             W1
             H1
             Y1
             K2
             H
             R
             L1
             A2
             J
             W
             S1
             O1
             S
             I2
             U
             P1
             C
             G1
             B2
             U1
             Z
             V
             J2
             T
             X
             G
             J1
             N1
             L2
             A
             B
             Q
             M
             X1
             D1
             O)
        (and (= L 8608)
     (not (= M2 8577))
     (= M2 8592)
     (not (= M2 8561))
     (not (= M2 8576))
     (not (= M2 8464))
     (not (= M2 8465))
     (not (= M2 8466))
     (not (= M2 8496))
     (not (= M2 8497))
     (not (= M2 8512))
     (not (= M2 8513))
     (not (= M2 8528))
     (not (= M2 8529))
     (not (= M2 8544))
     (not (= M2 8545))
     (not (= M2 8560))
     (not (= M2 8448))
     (not (= M2 12292))
     (not (= M2 16384))
     (not (= M2 8192))
     (not (= M2 24576))
     (not (= M2 8195))
     (not (= M2 8480))
     (not (= M2 8481))
     (not (= M2 8482))
     (<= 0 B)
     (<= 0 X1)
     (<= 0 S1)
     (<= 0 W)
     (<= 0 Q)
     (<= 0 O)
     (<= 0 M)
     (<= 0 J)
     (not (<= R1 0))
     (= P 0))
      )
      (inv_main192 Z1
             E
             M1
             K
             B1
             L
             F2
             D
             I
             F1
             P
             H2
             V1
             C2
             E2
             E1
             G2
             T1
             F
             D2
             K1
             Q1
             A1
             I1
             C1
             Y
             W1
             H1
             Y1
             K2
             H
             R
             L1
             A2
             J
             W
             S1
             O1
             S
             R1
             U
             M2
             C
             G1
             B2
             U1
             Z
             V
             J2
             T
             X
             G
             J1
             N1
             L2
             A
             B
             Q
             M
             X1
             D1
             O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main111 U1
             O1
             H1
             K2
             D
             G2
             Q
             Y1
             N
             M2
             V
             G1
             Y
             F
             C2
             J
             B1
             B
             D1
             F1
             P1
             R
             I2
             S1
             R1
             S
             P
             B2
             A2
             V1
             Q1
             M
             T1
             O
             N1
             E1
             H2
             Z1
             E
             D2
             L1
             X1
             H
             C1
             T
             K1
             U
             J2
             X
             L2
             K
             J1
             Z
             W
             I
             L
             M1
             A1
             C
             E2
             W1
             F2)
        (and (= G2 8593)
     (not (= G2 8577))
     (not (= G2 8592))
     (not (= G2 8561))
     (not (= G2 8576))
     (not (= G2 8464))
     (not (= G2 8465))
     (not (= G2 8466))
     (not (= G2 8496))
     (not (= G2 8497))
     (not (= G2 8512))
     (not (= G2 8513))
     (not (= G2 8528))
     (not (= G2 8529))
     (not (= G2 8544))
     (not (= G2 8545))
     (not (= G2 8560))
     (not (= G2 8448))
     (not (= G2 12292))
     (not (= G2 16384))
     (not (= G2 8192))
     (not (= G2 24576))
     (not (= G2 8195))
     (not (= G2 8480))
     (not (= G2 8481))
     (not (= G2 8482))
     (= I1 0)
     (<= 0 C)
     (<= 0 H2)
     (<= 0 F2)
     (<= 0 E2)
     (<= 0 N1)
     (<= 0 M1)
     (<= 0 E1)
     (<= 0 A1)
     (not (<= G 0))
     (= A 8608))
      )
      (inv_main192 U1
             O1
             H1
             K2
             D
             A
             Q
             Y1
             N
             M2
             I1
             G1
             Y
             F
             C2
             J
             B1
             B
             D1
             F1
             P1
             R
             I2
             S1
             R1
             S
             P
             B2
             A2
             V1
             Q1
             M
             T1
             O
             N1
             E1
             H2
             Z1
             E
             G
             L1
             G2
             H
             C1
             T
             K1
             U
             J2
             X
             L2
             K
             J1
             Z
             W
             I
             L
             M1
             A1
             C
             E2
             W1
             F2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main111 M2
             Z1
             P1
             X
             E1
             W
             L1
             O1
             N
             K1
             W1
             E2
             H2
             M
             J2
             I2
             U
             F1
             J1
             A1
             D1
             B
             Q
             Z
             B2
             J
             X1
             V1
             K2
             U1
             N1
             G2
             D2
             H
             M1
             E
             R1
             T
             S
             G
             C1
             I
             R
             F
             S1
             P
             Y1
             L
             I1
             B1
             T1
             K
             D
             A
             H1
             G1
             O
             C2
             F2
             C
             L2
             Y)
        (and (not (= W 8593))
     (= W 8608)
     (not (= W 8577))
     (not (= W 8592))
     (not (= W 8561))
     (not (= W 8576))
     (not (= W 8464))
     (not (= W 8465))
     (not (= W 8466))
     (not (= W 8496))
     (not (= W 8497))
     (not (= W 8512))
     (not (= W 8513))
     (not (= W 8528))
     (not (= W 8529))
     (not (= W 8544))
     (not (= W 8545))
     (not (= W 8560))
     (not (= W 8448))
     (not (= W 12292))
     (not (= W 16384))
     (not (= W 8192))
     (not (= W 24576))
     (not (= W 8195))
     (not (= W 8480))
     (not (= W 8481))
     (not (= W 8482))
     (= V 8640)
     (<= 0 C)
     (<= 0 F2)
     (<= 0 C2)
     (<= 0 R1)
     (<= 0 M1)
     (<= 0 Y)
     (<= 0 O)
     (<= 0 E)
     (not (<= Q1 0))
     (= A2 0))
      )
      (inv_main192 M2
             Z1
             P1
             X
             E1
             V
             L1
             O1
             N
             K1
             A2
             E2
             H2
             M
             J2
             I2
             U
             F1
             J1
             A1
             D1
             B
             Q
             Z
             B2
             J
             X1
             V1
             K2
             U1
             N1
             G2
             D2
             H
             M1
             E
             R1
             T
             S
             Q1
             C1
             W
             R
             F
             S1
             P
             Y1
             L
             I1
             B1
             T1
             K
             D
             A
             H1
             G1
             O
             C2
             F2
             C
             L2
             Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main111 D
             L
             B1
             Z1
             K1
             A2
             I2
             D2
             P1
             B
             I1
             M1
             H1
             W
             O
             K
             L1
             S1
             F
             G1
             C1
             A1
             N1
             Y1
             T1
             K2
             E1
             U1
             N
             V1
             D1
             B2
             Q
             P
             E2
             G
             I
             L2
             V
             Z
             Y
             J1
             J2
             H
             C
             F2
             Q1
             R1
             F1
             O1
             G2
             J
             X
             R
             S
             E
             U
             H2
             X1
             M
             M2
             T)
        (and (= A2 8609)
     (not (= A2 8593))
     (not (= A2 8608))
     (not (= A2 8577))
     (not (= A2 8592))
     (not (= A2 8561))
     (not (= A2 8576))
     (not (= A2 8464))
     (not (= A2 8465))
     (not (= A2 8466))
     (not (= A2 8496))
     (not (= A2 8497))
     (not (= A2 8512))
     (not (= A2 8513))
     (not (= A2 8528))
     (not (= A2 8529))
     (not (= A2 8544))
     (not (= A2 8545))
     (not (= A2 8560))
     (not (= A2 8448))
     (not (= A2 12292))
     (not (= A2 16384))
     (not (= A2 8192))
     (not (= A2 24576))
     (not (= A2 8195))
     (not (= A2 8480))
     (not (= A2 8481))
     (not (= A2 8482))
     (= W1 0)
     (<= 0 H2)
     (<= 0 E2)
     (<= 0 X1)
     (<= 0 U)
     (<= 0 T)
     (<= 0 M)
     (<= 0 I)
     (<= 0 G)
     (not (<= A 0))
     (= C2 8640))
      )
      (inv_main192 D
             L
             B1
             Z1
             K1
             C2
             I2
             D2
             P1
             B
             W1
             M1
             H1
             W
             O
             K
             L1
             S1
             F
             G1
             C1
             A1
             N1
             Y1
             T1
             K2
             E1
             U1
             N
             V1
             D1
             B2
             Q
             P
             E2
             G
             I
             L2
             V
             A
             Y
             A2
             J2
             H
             C
             F2
             Q1
             R1
             F1
             O1
             G2
             J
             X
             R
             S
             E
             U
             H2
             X1
             M
             M2
             T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main248 J1
             J2
             P2
             V1
             X1
             B2
             F
             N2
             C
             B
             I1
             L
             Y
             N1
             N
             X
             F2
             O
             K
             P
             K1
             A2
             B1
             R1
             D1
             C2
             P1
             S1
             G
             F1
             T
             H2
             J
             O2
             G1
             U1
             V
             A1
             E2
             C1
             Q
             E
             D
             T1
             D2
             W1
             H1
             H
             Z1
             U
             S
             Y1
             A
             W
             L2
             Z
             E1
             R
             L1
             Q1
             I2
             M1)
        (and (= L2 0)
     (= K2 0)
     (= G2 1)
     (= O1 8496)
     (= I 0)
     (<= 0 U1)
     (<= 0 Q1)
     (<= 0 M1)
     (<= 0 L1)
     (<= 0 G1)
     (<= 0 E1)
     (<= 0 V)
     (<= 0 R)
     (not (<= M 0))
     (= M2 1))
      )
      (inv_main192 J1
             J2
             P2
             V1
             X1
             O1
             F
             N2
             C
             B
             I
             L
             Y
             N1
             N
             K2
             F2
             O
             K
             P
             K1
             A2
             B1
             R1
             D1
             C2
             P1
             S1
             G
             F1
             T
             H2
             J
             O2
             G1
             U1
             V
             A1
             E2
             M
             Q
             E
             D
             G2
             D2
             W1
             H1
             H
             Z1
             U
             S
             Y1
             A
             W
             M2
             Z
             E1
             R
             L1
             Q1
             I2
             M1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main248 U
             W1
             R
             R1
             M1
             I1
             G1
             V1
             E
             G2
             T
             L1
             H2
             J2
             D2
             Y1
             I2
             F1
             I
             K1
             P1
             Z
             B1
             D1
             K2
             M
             J1
             B2
             C
             V
             A
             O2
             W
             G
             D
             T1
             L
             O
             C2
             K
             F
             X1
             S1
             Y
             E1
             Q
             Q1
             O1
             U1
             H1
             N
             H
             P
             X
             N2
             L2
             A2
             C1
             E2
             N1
             J
             F2)
        (and (= M2 1)
     (= Z1 0)
     (= S 0)
     (not (= N2 0))
     (<= 0 D)
     (<= 0 F2)
     (<= 0 E2)
     (<= 0 A2)
     (<= 0 T1)
     (<= 0 N1)
     (<= 0 C1)
     (<= 0 L)
     (not (<= A1 0))
     (= B 8496))
      )
      (inv_main192 U
             W1
             R
             R1
             M1
             B
             G1
             V1
             E
             G2
             Z1
             L1
             H2
             J2
             D2
             S
             I2
             F1
             I
             K1
             P1
             Z
             B1
             D1
             K2
             M
             J1
             B2
             C
             V
             A
             O2
             W
             G
             D
             T1
             L
             O
             C2
             A1
             F
             X1
             S1
             M2
             E1
             Q
             Q1
             O1
             U1
             H1
             N
             H
             P
             X
             N2
             L2
             A2
             C1
             E2
             N1
             J
             F2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main265 P1
             J2
             I
             O1
             G
             X1
             U1
             Q
             W1
             M1
             N
             T
             E
             Z1
             L
             J1
             Y1
             E2
             S
             L1
             T1
             N1
             V1
             W
             I2
             I1
             C1
             K2
             R
             L2
             Q1
             M
             V
             B2
             A2
             R1
             Y
             F1
             X
             C
             D
             J
             F2
             E1
             Z
             H2
             A1
             A
             P
             F
             U
             D2
             S1
             C2
             H1
             K
             G1
             B1
             G2
             H
             B
             O)
        (and (= D1 8656)
     (not (= T 0))
     (<= 0 G2)
     (<= 0 A2)
     (<= 0 R1)
     (<= 0 G1)
     (<= 0 B1)
     (<= 0 Y)
     (<= 0 O)
     (<= 0 H)
     (not (<= C 0))
     (= K1 0))
      )
      (inv_main192 P1
             J2
             I
             O1
             G
             D1
             U1
             Q
             W1
             M1
             K1
             T
             E
             Z1
             L
             J1
             Y1
             E2
             S
             L1
             T1
             N1
             V1
             W
             I2
             I1
             C1
             K2
             R
             L2
             Q1
             M
             V
             B2
             A2
             R1
             Y
             F1
             X
             C
             D
             J
             F2
             E1
             Z
             H2
             A1
             A
             P
             F
             U
             D2
             S1
             C2
             H1
             K
             G1
             B1
             G2
             H
             B
             O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main265 S
             P1
             U1
             L2
             E
             Y
             A2
             J2
             B1
             T1
             Q
             H1
             F2
             U
             Q1
             I2
             N
             S1
             F1
             D
             K2
             B2
             W1
             R
             D2
             E1
             F
             A1
             D1
             P
             H
             A
             R1
             E2
             T
             I1
             O1
             M1
             Y1
             L
             V1
             H2
             N1
             C
             C1
             W
             K
             J
             K1
             G1
             Z
             V
             X1
             J1
             X
             O
             G
             Z1
             M
             I
             G2
             B)
        (and (= L1 0)
     (= H1 0)
     (<= 0 B)
     (<= 0 Z1)
     (<= 0 O1)
     (<= 0 I1)
     (<= 0 T)
     (<= 0 M)
     (<= 0 I)
     (<= 0 G)
     (not (<= L 0))
     (= C2 8512))
      )
      (inv_main192 S
             P1
             U1
             L2
             E
             C2
             A2
             J2
             B1
             T1
             L1
             H1
             F2
             U
             Q1
             I2
             N
             S1
             F1
             D
             K2
             B2
             W1
             R
             D2
             E1
             F
             A1
             D1
             P
             H
             A
             R1
             E2
             T
             I1
             O1
             M1
             Y1
             L
             V1
             H2
             N1
             C
             C1
             W
             K
             J
             K1
             G1
             Z
             V
             X1
             J1
             X
             O
             G
             Z1
             M
             I
             G2
             B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main111 C1
             W1
             Z
             K1
             Q
             F1
             L1
             S1
             R1
             B2
             I1
             Y1
             N
             H
             J2
             C
             K2
             P
             N1
             G2
             B1
             H2
             M1
             D1
             T
             D2
             O
             G
             E2
             P1
             E
             J1
             X
             G1
             A2
             X1
             J
             A
             V1
             U1
             M
             V
             F
             D
             I
             C2
             Q1
             Z1
             R
             U
             S
             T1
             H1
             F2
             E1
             I2
             O1
             K
             B
             A1
             Y
             L)
        (and (not (= F1 8464))
     (not (= F1 8465))
     (not (= F1 8466))
     (not (= F1 8496))
     (not (= F1 8497))
     (not (= F1 8512))
     (not (= F1 8513))
     (not (= F1 8528))
     (not (= F1 8529))
     (not (= F1 8544))
     (not (= F1 8545))
     (not (= F1 8560))
     (= F1 8448)
     (not (= F1 12292))
     (not (= F1 16384))
     (not (= F1 8192))
     (not (= F1 24576))
     (not (= F1 8195))
     (not (= F1 8480))
     (not (= F1 8481))
     (not (= F1 8482))
     (not (<= 1 W))
     (<= 0 A2)
     (<= 0 X1)
     (<= 0 O1)
     (<= 0 A1)
     (<= 0 L)
     (<= 0 K)
     (<= 0 J)
     (<= 0 B)
     (not (= F1 8561))
     (= v_63 E))
      )
      (inv_main192 C1
             W1
             Z
             K1
             Q
             E
             L1
             S1
             R1
             B2
             I1
             Y1
             N
             H
             J2
             C
             K2
             P
             N1
             G2
             B1
             H2
             M1
             D1
             T
             D2
             O
             G
             E2
             P1
             v_63
             J1
             X
             G1
             A2
             X1
             J
             A
             W
             U1
             M
             F1
             F
             D
             I
             C2
             Q1
             Z1
             R
             U
             S
             T1
             H1
             F2
             E1
             I2
             O1
             K
             B
             A1
             Y
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main111 V
             G2
             E1
             I1
             N1
             G1
             K1
             E2
             R
             U1
             N
             F1
             J
             J2
             I
             S1
             C1
             O
             D
             K
             I2
             S
             D2
             M
             L2
             M1
             W1
             K2
             C
             A2
             L
             Y1
             D1
             X
             C2
             T
             O1
             E
             V1
             Q1
             F
             G
             B2
             P
             X1
             H2
             H
             W
             A
             R1
             B
             H1
             P1
             F2
             Z
             A1
             L1
             Q
             J1
             B1
             U
             Y)
        (and (not (= G1 8561))
     (not (= G1 8464))
     (not (= G1 8465))
     (not (= G1 8466))
     (not (= G1 8496))
     (not (= G1 8497))
     (not (= G1 8512))
     (not (= G1 8513))
     (not (= G1 8528))
     (not (= G1 8529))
     (not (= G1 8544))
     (not (= G1 8545))
     (not (= G1 8560))
     (= G1 8448)
     (not (= G1 12292))
     (not (= G1 16384))
     (not (= G1 8192))
     (not (= G1 24576))
     (not (= G1 8195))
     (not (= G1 8480))
     (not (= G1 8481))
     (not (= G1 8482))
     (<= 1 T1)
     (<= 0 C2)
     (<= 0 O1)
     (<= 0 L1)
     (<= 0 J1)
     (<= 0 B1)
     (<= 0 Y)
     (<= 0 T)
     (<= 0 Q)
     (not (<= H1 0))
     (= Z1 1)
     (= v_64 L)
     (= v_65 H1))
      )
      (inv_main192 V
             G2
             E1
             I1
             N1
             L
             K1
             E2
             R
             U1
             N
             F1
             Z1
             J2
             I
             S1
             C1
             O
             D
             K
             I2
             S
             D2
             M
             L2
             M1
             W1
             K2
             C
             A2
             v_64
             Y1
             D1
             X
             C2
             T
             O1
             E
             H1
             Q1
             F
             G1
             B2
             P
             X1
             H2
             H
             W
             A
             R1
             B
             v_65
             P1
             F2
             Z
             A1
             L1
             Q
             J1
             B1
             U
             Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main412 J1
             B2
             D1
             K2
             D
             K
             B1
             R
             P
             G
             H2
             I1
             Z
             O
             M
             Q1
             L1
             N1
             C
             U1
             L
             V
             A2
             T1
             Y1
             M1
             A1
             Z1
             E
             D2
             G1
             Y
             Q
             W1
             A
             E2
             N
             I2
             G2
             X1
             B
             W
             V1
             J2
             H
             S1
             C2
             P1
             C1
             H1
             K1
             I
             F2
             L2
             S
             F1
             J
             F
             E1
             O1
             X
             R1)
        (and (= U 0)
     (= T 3)
     (<= 0 A)
     (<= 0 E2)
     (<= 0 R1)
     (<= 0 O1)
     (<= 0 E1)
     (<= 0 N)
     (<= 0 J)
     (<= 0 F)
     (not (<= X1 0))
     (not (= I1 0)))
      )
      (inv_main192 J1
             B2
             D1
             K2
             D
             T
             B1
             R
             P
             G
             U
             I1
             Z
             O
             M
             Q1
             L1
             N1
             C
             U1
             L
             V
             A2
             T1
             Y1
             M1
             A1
             Z1
             E
             D2
             G1
             Y
             Q
             W1
             A
             E2
             N
             I2
             G2
             X1
             B
             W
             V1
             J2
             H
             S1
             C2
             P1
             C1
             H1
             K1
             I
             F2
             L2
             S
             F1
             J
             F
             E1
             O1
             X
             R1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main412 U
             H2
             Z
             W
             R
             V
             X1
             Y
             O
             Y1
             T1
             M1
             Z1
             J
             F
             D1
             A2
             B
             S1
             F1
             P
             G2
             J2
             T
             A
             J1
             L2
             L1
             M
             H1
             E
             K1
             V1
             I1
             D
             L
             R1
             Q
             H
             I
             D2
             G
             N
             G1
             F2
             C
             A1
             I2
             Q1
             W1
             K2
             U1
             E2
             C2
             X
             P1
             N1
             K
             S
             C1
             O1
             E1)
        (and (= M1 0)
     (= B1 8656)
     (<= 0 R1)
     (<= 0 N1)
     (<= 0 E1)
     (<= 0 C1)
     (<= 0 S)
     (<= 0 L)
     (<= 0 K)
     (<= 0 D)
     (not (<= I 0))
     (= B2 0))
      )
      (inv_main192 U
             H2
             Z
             W
             R
             B1
             X1
             Y
             O
             Y1
             B2
             M1
             Z1
             J
             F
             D1
             A2
             B
             S1
             F1
             P
             G2
             J2
             T
             A
             J1
             L2
             L1
             M
             H1
             E
             K1
             V1
             I1
             D
             L
             R1
             Q
             H
             I
             D2
             G
             N
             G1
             F2
             C
             A1
             I2
             Q1
             W1
             K2
             U1
             E2
             C2
             X
             P1
             N1
             K
             S
             C1
             O1
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main291 D2
             L1
             E
             F1
             D1
             J2
             U1
             A1
             G2
             U
             P
             I
             S
             E1
             M1
             H
             G1
             Y1
             X1
             Z1
             O1
             D
             L2
             A2
             K
             C
             F2
             R1
             Q
             V
             M2
             Z
             J
             T1
             M
             T
             Q1
             H1
             S1
             V1
             R
             J1
             N
             W1
             B
             E2
             K1
             C1
             A
             K2
             P1
             C2
             G
             X
             B1
             Y
             I2
             N1
             F
             L
             I1
             H2)
        (and (= R1 0)
     (= W 0)
     (= O 8544)
     (= M (- 30))
     (= M (- 1))
     (<= 0 I2)
     (<= 0 H2)
     (<= 0 Q1)
     (<= 0 N1)
     (<= 0 T)
     (<= 0 M)
     (<= 0 L)
     (<= 0 F)
     (= B2 1))
      )
      (inv_main192 D2
             L1
             E
             F1
             D1
             O
             U1
             A1
             G2
             U
             W
             I
             S
             E1
             M1
             H
             G1
             Y1
             X1
             Z1
             O1
             D
             L2
             A2
             K
             C
             F2
             R1
             Q
             V
             M2
             Z
             J
             T1
             M
             T
             Q1
             H1
             S1
             V1
             R
             J1
             B2
             W1
             B
             E2
             K1
             C1
             A
             K2
             P1
             C2
             G
             X
             B1
             Y
             I2
             N1
             F
             L
             I1
             H2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main291 P
             A1
             T1
             Z
             C2
             T
             B2
             E
             U
             H
             X1
             L2
             B
             G
             R1
             L
             Q1
             I1
             A2
             W1
             V1
             H2
             O
             S1
             O1
             F2
             I
             N
             I2
             G2
             J
             A
             D
             C
             S
             L1
             J1
             H1
             E2
             K
             K1
             X
             Z1
             E1
             G1
             Y
             M
             W
             M1
             M2
             Q
             P1
             R
             B1
             V
             F1
             U1
             D1
             F
             J2
             D2
             K2)
        (and (= Y1 0)
     (not (= V1 0))
     (= N1 8544)
     (= C1 1)
     (= S (- 30))
     (not (= S (- 1)))
     (= N 0)
     (<= 0 K2)
     (<= 0 J2)
     (<= 0 U1)
     (<= 0 L1)
     (<= 0 J1)
     (<= 0 D1)
     (<= 0 S)
     (<= 0 F)
     (= A (- 2))
     (= v_65 A))
      )
      (inv_main192 P
             A1
             T1
             Z
             C2
             N1
             B2
             E
             U
             H
             Y1
             L2
             B
             G
             R1
             L
             Q1
             I1
             A2
             W1
             V1
             H2
             O
             S1
             O1
             F2
             I
             N
             I2
             G2
             J
             A
             D
             C
             S
             L1
             J1
             H1
             E2
             K
             K1
             X
             C1
             E1
             G1
             Y
             M
             W
             M1
             M2
             Q
             P1
             R
             B1
             V
             F1
             U1
             D1
             v_65
             J2
             D2
             K2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main291 N
             R
             D
             Q1
             A2
             Z
             I2
             D1
             B
             N1
             E1
             V
             M1
             U
             X1
             A
             H
             Q
             P2
             F2
             M2
             J1
             S
             S1
             X
             K2
             R1
             G
             O
             T
             K1
             M
             J2
             C1
             W1
             L
             B1
             L2
             O1
             E
             F1
             I1
             D2
             J
             Y1
             O2
             K
             W
             Z1
             A1
             I
             H1
             G2
             B2
             Y
             N2
             F
             L1
             P
             P1
             H2
             C2)
        (and (not (= M2 0))
     (= E2 512)
     (= W1 (- 30))
     (not (= W1 (- 1)))
     (= V1 0)
     (= U1 8544)
     (= G1 1)
     (not (= M (- 2)))
     (not (= M (- 4)))
     (= G 0)
     (not (>= C 65))
     (<= 0 F)
     (<= 0 C2)
     (<= 0 W1)
     (<= 0 P1)
     (<= 0 L1)
     (<= 0 B1)
     (<= 0 P)
     (<= 0 L)
     (= (+ T1 (* (- 8) C)) 0)
     (= v_68 M)
     (= v_69 M))
      )
      (inv_main192 N
             R
             D
             Q1
             A2
             U1
             I2
             D1
             B
             N1
             V1
             V
             M1
             U
             X1
             A
             H
             Q
             P2
             F2
             M2
             J1
             S
             S1
             X
             K2
             R1
             G
             O
             T
             K1
             M
             J2
             C1
             W1
             L
             B1
             L2
             O1
             E
             F1
             I1
             G1
             J
             Y1
             O2
             K
             W
             Z1
             C
             E2
             H1
             G2
             B2
             Y
             N2
             F
             L1
             v_68
             v_69
             T1
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main291 C
             F2
             I2
             D1
             I1
             W1
             D2
             X
             L2
             L
             E1
             F
             J1
             Q
             O1
             A2
             J
             Z1
             B2
             P
             L1
             F1
             K
             K2
             P1
             O2
             B1
             J2
             T1
             M2
             S1
             R
             Z
             X1
             I
             E
             D
             C1
             O
             K1
             M
             U1
             H2
             Q1
             P2
             Y
             V1
             W
             G1
             G
             N1
             Y1
             B
             H1
             A
             N
             A1
             N2
             V
             S
             G2
             T)
        (and (= J2 0)
     (= E2 1024)
     (= R1 0)
     (= M1 8544)
     (not (= L1 0))
     (= U 1)
     (not (= R (- 2)))
     (= R (- 4))
     (= I (- 30))
     (not (= I (- 1)))
     (not (>= C2 129))
     (<= 0 E)
     (<= 0 D)
     (<= 0 N2)
     (<= 0 A1)
     (<= 0 V)
     (<= 0 T)
     (<= 0 S)
     (<= 0 I)
     (= (+ H (* (- 8) C2)) 0)
     (= v_68 R)
     (= v_69 R))
      )
      (inv_main192 C
             F2
             I2
             D1
             I1
             M1
             D2
             X
             L2
             L
             R1
             F
             J1
             Q
             O1
             A2
             J
             Z1
             B2
             P
             L1
             F1
             K
             K2
             P1
             O2
             B1
             J2
             T1
             M2
             S1
             R
             Z
             X1
             I
             E
             D
             C1
             O
             K1
             M
             U1
             U
             Q1
             P2
             Y
             V1
             W
             G1
             C2
             E2
             Y1
             B
             H1
             A
             N
             A1
             N2
             v_68
             v_69
             H
             T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main323 X
             X1
             S
             Y
             R1
             J1
             H
             M1
             W1
             M
             F2
             Q1
             V1
             B
             P
             Z1
             K
             C2
             E1
             Z
             R
             M2
             G2
             T1
             J
             K2
             L
             L1
             A2
             T
             E
             H1
             S1
             U1
             D1
             V
             I1
             G1
             E2
             Q
             A1
             O
             F1
             D2
             O1
             A
             Y1
             N1
             J2
             P1
             C
             N
             G
             I
             U
             C1
             F
             W
             B1
             D
             L2
             B2)
        (and (= H2 8560)
     (= K1 0)
     (not (= E1 (- 4)))
     (not (= E1 (- 1)))
     (not (= Z 0))
     (<= 0 B2)
     (<= 0 I1)
     (<= 0 D1)
     (<= 0 B1)
     (<= 0 W)
     (<= 0 V)
     (<= 0 F)
     (<= 0 D)
     (= I2 1))
      )
      (inv_main192 X
             X1
             S
             Y
             R1
             H2
             H
             M1
             W1
             M
             F2
             Q1
             V1
             B
             P
             Z1
             K
             C2
             E1
             Z
             R
             M2
             G2
             T1
             J
             K1
             L
             L1
             A2
             T
             E
             H1
             S1
             U1
             D1
             V
             I1
             G1
             E2
             Q
             A1
             O
             I2
             D2
             O1
             A
             Y1
             N1
             J2
             P1
             C
             N
             G
             I
             U
             C1
             F
             W
             B1
             D
             L2
             B2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main329 Q1
             Z
             L
             I
             X1
             J2
             M1
             U1
             G
             S1
             D2
             E2
             T1
             K2
             Z1
             A
             Y
             M2
             C1
             I1
             F2
             U
             I2
             T
             G1
             B1
             B2
             H
             G2
             J
             K
             Y1
             W1
             B
             E
             L1
             F
             Q
             F1
             E1
             A1
             W
             J1
             O
             C
             N1
             P
             D
             R1
             O1
             H2
             H1
             V
             L2
             S
             C2
             V1
             N
             R
             M
             K1
             A2)
        (and (= D1 1)
     (= C1 (- 2))
     (= X 8560)
     (not (= J (- 256)))
     (<= 0 A2)
     (<= 0 V1)
     (<= 0 L1)
     (<= 0 R)
     (<= 0 N)
     (<= 0 M)
     (<= 0 F)
     (<= 0 E)
     (= P1 0)
     (= v_65 J))
      )
      (inv_main192 Q1
             Z
             L
             I
             X1
             X
             M1
             U1
             G
             S1
             D2
             E2
             T1
             K2
             Z1
             A
             Y
             M2
             C1
             I1
             F2
             U
             I2
             T
             G1
             P1
             B2
             H
             G2
             J
             K
             Y1
             W1
             B
             E
             L1
             F
             Q
             F1
             E1
             A1
             W
             D1
             O
             C
             N1
             P
             D
             R1
             O1
             H2
             H1
             V
             L2
             S
             C2
             V1
             N
             R
             M
             K1
             v_65)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main323 D
             T1
             L
             Y1
             B1
             Q1
             J
             P
             Z
             S
             K2
             B
             H1
             A
             J1
             N
             I2
             R
             M1
             U
             D2
             F2
             E2
             A1
             X1
             J2
             Q
             C
             G
             X
             P1
             R1
             C2
             M
             G1
             W1
             Y
             F1
             V1
             K1
             M2
             A2
             O1
             I
             G2
             F
             Z1
             I1
             K
             U1
             L2
             C1
             E1
             D1
             H
             H2
             S1
             W
             E
             T
             N1
             O)
        (and (= M1 (- 1))
     (= L1 1)
     (= V 8560)
     (<= 0 W1)
     (<= 0 S1)
     (<= 0 G1)
     (<= 0 Y)
     (<= 0 W)
     (<= 0 T)
     (<= 0 O)
     (<= 0 E)
     (= B2 0))
      )
      (inv_main192 D
             T1
             L
             Y1
             B1
             V
             J
             P
             Z
             S
             K2
             B
             H1
             A
             J1
             N
             I2
             R
             M1
             U
             D2
             F2
             E2
             A1
             X1
             B2
             Q
             C
             G
             X
             P1
             R1
             C2
             M
             G1
             W1
             Y
             F1
             V1
             K1
             M2
             A2
             L1
             I
             G2
             F
             Z1
             I1
             K
             U1
             L2
             C1
             E1
             D1
             H
             H2
             S1
             W
             E
             T
             N1
             O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main329 G1
             U
             H2
             E2
             M1
             R
             V1
             A2
             V
             D2
             S
             C2
             Z
             O2
             J
             D1
             N2
             I
             E1
             C1
             Y
             F2
             A1
             F
             R1
             I1
             B2
             D
             E
             X
             C
             Z1
             B1
             G2
             F1
             N
             M
             K1
             O1
             S1
             G
             Y1
             M2
             T
             Q
             X1
             H
             W
             P
             A
             K2
             L2
             L
             L1
             O
             J2
             I2
             J1
             T1
             N1
             Q1
             W1)
        (and (= U1 0)
     (= P1 8576)
     (= X (- 256))
     (= K 8448)
     (<= 0 I2)
     (<= 0 W1)
     (<= 0 T1)
     (<= 0 N1)
     (<= 0 J1)
     (<= 0 F1)
     (<= 0 N)
     (<= 0 M)
     (not (<= H1 0))
     (= B 1)
     (= v_67 X))
      )
      (inv_main192 G1
             U
             H2
             E2
             M1
             K
             V1
             A2
             V
             D2
             U1
             C2
             Z
             O2
             J
             D1
             N2
             I
             E1
             C1
             Y
             F2
             A1
             F
             R1
             B
             B2
             D
             E
             X
             P1
             Z1
             B1
             G2
             F1
             N
             M
             K1
             O1
             H1
             G
             Y1
             M2
             T
             Q
             X1
             H
             W
             P
             A
             K2
             L2
             L
             L1
             O
             J2
             I2
             J1
             T1
             N1
             Q1
             v_67)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main329 K2
             V
             E2
             B
             Q1
             G2
             T1
             Y1
             J
             L1
             W1
             Y
             H
             D1
             A1
             D2
             F2
             L2
             I1
             G1
             Z
             B2
             G
             M1
             P1
             I2
             Z1
             O1
             A2
             J1
             U1
             O
             D
             H1
             M
             P
             W
             N1
             Q
             H2
             C1
             N
             K
             C2
             S
             E
             K1
             S1
             F
             A
             E1
             X1
             O2
             F1
             J2
             M2
             U
             V1
             N2
             T
             R1
             X)
        (and (not (= I1 (- 2)))
     (= B1 8448)
     (= R 0)
     (= L 1)
     (= I 8576)
     (<= 0 V1)
     (<= 0 X)
     (<= 0 W)
     (<= 0 U)
     (<= 0 T)
     (<= 0 P)
     (<= 0 M)
     (<= 0 N2)
     (not (<= C 0))
     (not (= J1 (- 256)))
     (= v_67 J1))
      )
      (inv_main192 K2
             V
             E2
             B
             Q1
             B1
             T1
             Y1
             J
             L1
             R
             Y
             H
             D1
             A1
             D2
             F2
             L2
             I1
             G1
             Z
             B2
             G
             M1
             P1
             L
             Z1
             O1
             A2
             J1
             I
             O
             D
             H1
             M
             P
             W
             N1
             Q
             C
             C1
             N
             K
             C2
             S
             E
             K1
             S1
             F
             A
             E1
             X1
             O2
             F1
             J2
             M2
             U
             V1
             N2
             T
             R1
             v_67)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main111 K
             E
             E2
             P1
             W
             T
             L1
             N1
             M1
             U
             C
             B1
             F2
             A1
             T1
             V1
             S1
             N
             J
             O1
             I2
             H1
             U1
             A
             Q1
             Y1
             M2
             F1
             A2
             R1
             D1
             B
             R
             J1
             V
             P
             I
             F
             G2
             I1
             W1
             M
             L2
             Z
             X1
             C2
             S
             K2
             D2
             C1
             Y
             Z1
             K1
             G
             G1
             H
             L
             Q
             X
             D
             B2
             J2)
        (and (not (= R1 (- 256)))
     (= E1 1)
     (not (= T 8464))
     (not (= T 8465))
     (not (= T 8466))
     (not (= T 8496))
     (not (= T 8497))
     (= T 8512)
     (not (= T 12292))
     (not (= T 16384))
     (not (= T 8192))
     (not (= T 24576))
     (not (= T 8195))
     (not (= T 8480))
     (not (= T 8481))
     (not (= T 8482))
     (= O 8528)
     (<= 0 J2)
     (<= 0 X)
     (<= 0 V)
     (<= 0 Q)
     (<= 0 P)
     (<= 0 L)
     (<= 0 I)
     (<= 0 D)
     (= H2 0)
     (= v_65 R1))
      )
      (inv_main192 K
             E
             E2
             P1
             W
             O
             L1
             N1
             M1
             U
             H2
             B1
             F2
             A1
             T1
             V1
             S1
             N
             J
             O1
             I2
             H1
             U1
             A
             Q1
             Y1
             M2
             F1
             A2
             R1
             D1
             B
             R
             J1
             V
             P
             I
             F
             G2
             I1
             W1
             T
             E1
             Z
             X1
             C2
             S
             K2
             D2
             C1
             Y
             Z1
             K1
             G
             G1
             H
             v_65
             Q
             X
             D
             B2
             J2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main111 S1
             U1
             T
             D
             L
             D1
             W
             B1
             J1
             I
             Q
             J
             K
             K1
             C2
             B2
             M2
             R
             V
             I1
             H2
             K2
             E1
             N1
             Z
             F2
             I2
             T1
             W1
             H1
             U
             L2
             E2
             Y1
             G2
             O1
             Q1
             C1
             G1
             E
             F
             R1
             H
             Z1
             P
             M
             A1
             V1
             F1
             A
             J2
             D2
             C
             P1
             G
             M1
             N
             S
             Y
             O
             L1
             X)
        (and (= X1 8528)
     (= H1 (- 256))
     (not (= D1 8464))
     (not (= D1 8465))
     (not (= D1 8466))
     (not (= D1 8496))
     (not (= D1 8497))
     (= D1 8512)
     (not (= D1 12292))
     (not (= D1 16384))
     (not (= D1 8192))
     (not (= D1 24576))
     (not (= D1 8195))
     (not (= D1 8480))
     (not (= D1 8481))
     (not (= D1 8482))
     (<= 0 G2)
     (<= 0 Q1)
     (<= 0 O1)
     (<= 0 Y)
     (<= 0 X)
     (<= 0 S)
     (<= 0 O)
     (<= 0 N)
     (not (<= A2 0))
     (= B 0)
     (= v_65 H1))
      )
      (inv_main192 S1
             U1
             T
             D
             L
             X1
             W
             B1
             J1
             I
             B
             J
             K
             K1
             C2
             B2
             M2
             R
             V
             I1
             H2
             K2
             E1
             N1
             Z
             F2
             I2
             T1
             W1
             H1
             U
             L2
             E2
             Y1
             G2
             O1
             Q1
             C1
             G1
             A2
             F
             D1
             H
             Z1
             P
             M
             A1
             V1
             F1
             A
             J2
             D2
             C
             P1
             G
             M1
             v_65
             S
             Y
             O
             L1
             X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main111 W
             Y1
             X1
             P
             G
             K
             T
             U
             D2
             I
             E1
             O1
             U1
             O
             W1
             M1
             G2
             S
             J2
             R1
             K2
             F2
             B2
             F1
             T1
             N
             S1
             B
             J1
             A1
             R
             J
             Y
             X
             C2
             K1
             D1
             Q
             A2
             B1
             E2
             I2
             I1
             F
             E
             M2
             C
             M
             G1
             Q1
             Z1
             L1
             D
             A
             P1
             H
             N1
             H1
             L
             L2
             Z
             V1)
        (and (= C1 1)
     (not (= A1 (- 256)))
     (= V 0)
     (not (= K 8464))
     (not (= K 8465))
     (not (= K 8466))
     (not (= K 8496))
     (not (= K 8497))
     (not (= K 8512))
     (= K 8513)
     (not (= K 12292))
     (not (= K 16384))
     (not (= K 8192))
     (not (= K 24576))
     (not (= K 8195))
     (not (= K 8480))
     (not (= K 8481))
     (not (= K 8482))
     (<= 0 C2)
     (<= 0 V1)
     (<= 0 N1)
     (<= 0 K1)
     (<= 0 H1)
     (<= 0 D1)
     (<= 0 L)
     (<= 0 L2)
     (= H2 8528)
     (= v_65 A1))
      )
      (inv_main192 W
             Y1
             X1
             P
             G
             H2
             T
             U
             D2
             I
             V
             O1
             U1
             O
             W1
             M1
             G2
             S
             J2
             R1
             K2
             F2
             B2
             F1
             T1
             N
             S1
             B
             J1
             A1
             R
             J
             Y
             X
             C2
             K1
             D1
             Q
             A2
             B1
             E2
             K
             C1
             F
             E
             M2
             C
             M
             G1
             Q1
             Z1
             L1
             D
             A
             P1
             H
             v_65
             H1
             L
             L2
             Z
             V1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main111 J2
             L2
             F
             I
             H
             E
             S
             E2
             S1
             K1
             Z1
             D2
             O1
             B
             W1
             A2
             Q
             J1
             W
             V
             B2
             X1
             O
             C2
             K
             F1
             D
             I1
             P
             P1
             U1
             L1
             X
             H1
             Q1
             N
             D1
             Y
             J
             T1
             E1
             C
             M
             Y1
             M2
             Z
             A1
             M1
             G2
             U
             K2
             R1
             L
             F2
             G
             G1
             A
             I2
             H2
             T
             B1
             R)
        (and (= N1 0)
     (= C1 8528)
     (not (= E 8464))
     (not (= E 8465))
     (not (= E 8466))
     (not (= E 8496))
     (not (= E 8497))
     (not (= E 8512))
     (= E 8513)
     (not (= E 12292))
     (not (= E 16384))
     (not (= E 8192))
     (not (= E 24576))
     (not (= E 8195))
     (not (= E 8480))
     (not (= E 8481))
     (not (= E 8482))
     (<= 0 A)
     (<= 0 I2)
     (<= 0 H2)
     (<= 0 Q1)
     (<= 0 D1)
     (<= 0 T)
     (<= 0 R)
     (<= 0 N)
     (not (<= V1 0))
     (= P1 (- 256))
     (= v_65 P1))
      )
      (inv_main192 J2
             L2
             F
             I
             H
             C1
             S
             E2
             S1
             K1
             N1
             D2
             O1
             B
             W1
             A2
             Q
             J1
             W
             V
             B2
             X1
             O
             C2
             K
             F1
             D
             I1
             P
             P1
             U1
             L1
             X
             H1
             Q1
             N
             D1
             Y
             J
             V1
             E1
             E
             M
             Y1
             M2
             Z
             A1
             M1
             G2
             U
             K2
             R1
             L
             F2
             G
             G1
             v_65
             I2
             H2
             T
             B1
             R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main111 E
             Z
             K2
             G2
             D2
             C1
             U
             R
             B1
             X1
             L2
             N
             F2
             C
             M1
             D
             J1
             Q1
             P1
             J2
             L
             B
             J
             L1
             T1
             B2
             T
             G1
             A
             V
             Y1
             A2
             A1
             V1
             E2
             I
             Y
             U1
             O1
             X
             M
             Q
             W1
             W
             H
             D1
             H2
             I1
             P
             C2
             I2
             R1
             H1
             K
             K1
             O
             F
             N1
             E1
             G
             S
             Z1)
        (and (= F1 2)
     (not (= C1 8561))
     (= C1 8576)
     (not (= C1 8464))
     (not (= C1 8465))
     (not (= C1 8466))
     (not (= C1 8496))
     (not (= C1 8497))
     (not (= C1 8512))
     (not (= C1 8513))
     (not (= C1 8528))
     (not (= C1 8529))
     (not (= C1 8544))
     (not (= C1 8545))
     (not (= C1 8560))
     (not (= C1 8448))
     (not (= C1 12292))
     (not (= C1 16384))
     (not (= C1 8192))
     (not (= C1 24576))
     (not (= C1 8195))
     (not (= C1 8480))
     (not (= C1 8481))
     (not (= C1 8482))
     (<= 0 E2)
     (<= 0 Z1)
     (<= 0 N1)
     (<= 0 E1)
     (<= 0 Y)
     (<= 0 I)
     (<= 0 G)
     (<= 0 F)
     (not (<= F1 0))
     (= S1 8466))
      )
      (inv_main192 E
             Z
             K2
             G2
             D2
             S1
             U
             R
             B1
             X1
             L2
             N
             F2
             C
             M1
             D
             J1
             Q1
             P1
             J2
             L
             B
             J
             L1
             T1
             B2
             T
             G1
             A
             V
             Y1
             A2
             A1
             V1
             E2
             I
             Y
             U1
             O1
             F1
             M
             C1
             W1
             W
             H
             D1
             H2
             I1
             P
             C2
             I2
             R1
             H1
             K
             K1
             O
             F
             N1
             E1
             G
             S
             Z1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main111 U1
             G
             F1
             G2
             X1
             U
             Q1
             C
             C1
             H1
             T1
             Y
             P
             A2
             K
             N1
             B1
             N
             Z
             E2
             M2
             O1
             E1
             B2
             Z1
             J2
             D
             L
             O
             F2
             L1
             F
             P1
             J
             Y1
             H
             R1
             K1
             M1
             N2
             G1
             H2
             E
             Q
             T
             S
             R
             W
             V
             I
             M
             L2
             D1
             W1
             J1
             V1
             S1
             A
             B
             I2
             X
             K2)
        (and (= C2 0)
     (not (= A1 2))
     (not (= U 8561))
     (= U 8576)
     (not (= U 8464))
     (not (= U 8465))
     (not (= U 8466))
     (not (= U 8496))
     (not (= U 8497))
     (not (= U 8512))
     (not (= U 8513))
     (not (= U 8528))
     (not (= U 8529))
     (not (= U 8544))
     (not (= U 8545))
     (not (= U 8560))
     (not (= U 8448))
     (not (= U 12292))
     (not (= U 16384))
     (not (= U 8192))
     (not (= U 24576))
     (not (= U 8195))
     (not (= U 8480))
     (not (= U 8481))
     (not (= U 8482))
     (<= 0 B)
     (<= 0 A)
     (<= 0 K2)
     (<= 0 I2)
     (<= 0 Y1)
     (<= 0 S1)
     (<= 0 R1)
     (<= 0 H)
     (not (<= I1 0))
     (not (<= A1 0))
     (= D2 8592))
      )
      (inv_main192 U1
             G
             F1
             G2
             X1
             D2
             Q1
             C
             C1
             H1
             C2
             Y
             P
             A2
             K
             N1
             B1
             N
             Z
             E2
             M2
             O1
             E1
             B2
             Z1
             J2
             D
             L
             O
             F2
             L1
             F
             P1
             J
             Y1
             H
             R1
             K1
             M1
             I1
             G1
             U
             E
             Q
             T
             S
             R
             W
             V
             I
             M
             L2
             D1
             W1
             J1
             V1
             S1
             A
             B
             I2
             X
             K2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main111 C
             N1
             I
             Y
             A
             U1
             I2
             Y1
             O1
             E2
             J2
             C2
             H2
             Q
             L2
             M1
             F1
             B2
             G1
             H
             W
             K
             J
             D1
             L1
             R
             F2
             E1
             W1
             K1
             J1
             T1
             Z
             P
             B1
             Q1
             D2
             P1
             M
             F
             K2
             S1
             R1
             B
             G2
             V
             H1
             O
             D
             T
             E
             A1
             N
             G
             C1
             Z1
             X
             I1
             S
             U
             L
             V1)
        (and (= X1 2)
     (= U1 8577)
     (not (= U1 8561))
     (not (= U1 8576))
     (not (= U1 8464))
     (not (= U1 8465))
     (not (= U1 8466))
     (not (= U1 8496))
     (not (= U1 8497))
     (not (= U1 8512))
     (not (= U1 8513))
     (not (= U1 8528))
     (not (= U1 8529))
     (not (= U1 8544))
     (not (= U1 8545))
     (not (= U1 8560))
     (not (= U1 8448))
     (not (= U1 12292))
     (not (= U1 16384))
     (not (= U1 8192))
     (not (= U1 24576))
     (not (= U1 8195))
     (not (= U1 8480))
     (not (= U1 8481))
     (not (= U1 8482))
     (<= 0 D2)
     (<= 0 V1)
     (<= 0 Q1)
     (<= 0 I1)
     (<= 0 B1)
     (<= 0 X)
     (<= 0 U)
     (<= 0 S)
     (not (<= X1 0))
     (= A2 8466))
      )
      (inv_main192 C
             N1
             I
             Y
             A
             A2
             I2
             Y1
             O1
             E2
             J2
             C2
             H2
             Q
             L2
             M1
             F1
             B2
             G1
             H
             W
             K
             J
             D1
             L1
             R
             F2
             E1
             W1
             K1
             J1
             T1
             Z
             P
             B1
             Q1
             D2
             P1
             M
             X1
             K2
             U1
             R1
             B
             G2
             V
             H1
             O
             D
             T
             E
             A1
             N
             G
             C1
             Z1
             X
             I1
             S
             U
             L
             V1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main111 J
             G2
             Z1
             D
             X
             K2
             U
             F2
             T1
             F
             N
             M
             Q
             L1
             I2
             M2
             X1
             N2
             T
             L
             S1
             V
             W1
             B
             G1
             U1
             C1
             B1
             P
             W
             S
             C
             J2
             J1
             A1
             O1
             R
             I1
             M1
             Z
             C2
             E
             A2
             B2
             D2
             N1
             R1
             O
             H2
             K
             G
             H1
             P1
             Y
             Q1
             D1
             V1
             E2
             I
             F1
             E1
             K1)
        (and (= K2 8577)
     (not (= K2 8561))
     (not (= K2 8576))
     (not (= K2 8464))
     (not (= K2 8465))
     (not (= K2 8466))
     (not (= K2 8496))
     (not (= K2 8497))
     (not (= K2 8512))
     (not (= K2 8513))
     (not (= K2 8528))
     (not (= K2 8529))
     (not (= K2 8544))
     (not (= K2 8545))
     (not (= K2 8560))
     (not (= K2 8448))
     (not (= K2 12292))
     (not (= K2 16384))
     (not (= K2 8192))
     (not (= K2 24576))
     (not (= K2 8195))
     (not (= K2 8480))
     (not (= K2 8481))
     (not (= K2 8482))
     (= Y1 8592)
     (= H 0)
     (<= 0 E2)
     (<= 0 V1)
     (<= 0 O1)
     (<= 0 K1)
     (<= 0 F1)
     (<= 0 A1)
     (<= 0 R)
     (<= 0 I)
     (not (<= A 0))
     (not (<= L2 0))
     (not (= L2 2)))
      )
      (inv_main192 J
             G2
             Z1
             D
             X
             Y1
             U
             F2
             T1
             F
             H
             M
             Q
             L1
             I2
             M2
             X1
             N2
             T
             L
             S1
             V
             W1
             B
             G1
             U1
             C1
             B1
             P
             W
             S
             C
             J2
             J1
             A1
             O1
             R
             I1
             M1
             A
             C2
             K2
             A2
             B2
             D2
             N1
             R1
             O
             H2
             K
             G
             H1
             P1
             Y
             Q1
             D1
             V1
             E2
             I
             F1
             E1
             K1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main111 J1
             H1
             X
             A
             C1
             G
             M2
             N1
             P1
             K
             F1
             G1
             B
             J
             L
             U
             R
             C2
             Q1
             A1
             V1
             A2
             K1
             W
             I
             O
             L1
             O1
             C
             D1
             L2
             D2
             F
             H2
             Z1
             P
             U1
             V
             T1
             W1
             Z
             P2
             E
             J2
             N2
             S1
             Y
             E2
             K2
             B2
             O2
             Q
             M
             G2
             B1
             R1
             H
             E1
             I2
             I1
             F2
             T)
        (and (= X1 3)
     (not (= M1 0))
     (= B1 2)
     (not (= S 0))
     (= N 8672)
     (not (= G 8641))
     (= G 8656)
     (not (= G 8609))
     (not (= G 8640))
     (not (= G 8593))
     (not (= G 8608))
     (not (= G 8577))
     (not (= G 8592))
     (not (= G 8561))
     (not (= G 8576))
     (not (= G 8464))
     (not (= G 8465))
     (not (= G 8466))
     (not (= G 8496))
     (not (= G 8497))
     (not (= G 8512))
     (not (= G 8513))
     (not (= G 8528))
     (not (= G 8529))
     (not (= G 8544))
     (not (= G 8545))
     (not (= G 8560))
     (not (= G 8448))
     (not (= G 12292))
     (not (= G 16384))
     (not (= G 8192))
     (not (= G 24576))
     (not (= G 8195))
     (not (= G 8480))
     (not (= G 8481))
     (not (= G 8482))
     (<= 0 I2)
     (<= 0 Z1)
     (<= 0 U1)
     (<= 0 I1)
     (<= 0 E1)
     (<= 0 T)
     (<= 0 P)
     (<= 0 H)
     (not (<= Y1 0))
     (= D 0)
     (= v_68 C))
      )
      (inv_main192 J1
             H1
             X
             A
             C1
             N
             M2
             N1
             P1
             K
             D
             G1
             B
             J
             L
             U
             R
             C2
             Q1
             A1
             V1
             A2
             K1
             W
             I
             O
             L1
             O1
             C
             D1
             L2
             D2
             v_68
             H2
             Z1
             P
             U1
             V
             T1
             Y1
             Z
             G
             E
             J2
             N2
             S1
             Y
             E2
             K2
             B2
             O2
             Q
             S
             M1
             X1
             R1
             H
             E1
             I2
             I1
             F2
             T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main111 B2
             K
             L1
             I
             A2
             W1
             I1
             T1
             H
             D1
             A1
             S1
             E2
             Q1
             K2
             Z1
             J1
             L
             G1
             T
             F
             Y
             C2
             U1
             U
             O2
             N
             O
             O1
             D
             H2
             E1
             A
             M1
             Q
             N1
             D2
             V
             J2
             L2
             F2
             X
             I2
             M
             G
             R
             W
             P1
             Y1
             V1
             C1
             M2
             H1
             B1
             G2
             S
             J
             Z
             E
             R1
             N2
             B)
        (and (not (= G2 2))
     (= X1 8672)
     (not (= W1 8641))
     (= W1 8656)
     (not (= W1 8609))
     (not (= W1 8640))
     (not (= W1 8593))
     (not (= W1 8608))
     (not (= W1 8577))
     (not (= W1 8592))
     (not (= W1 8561))
     (not (= W1 8576))
     (not (= W1 8464))
     (not (= W1 8465))
     (not (= W1 8466))
     (not (= W1 8496))
     (not (= W1 8497))
     (not (= W1 8512))
     (not (= W1 8513))
     (not (= W1 8528))
     (not (= W1 8529))
     (not (= W1 8544))
     (not (= W1 8545))
     (not (= W1 8560))
     (not (= W1 8448))
     (not (= W1 12292))
     (not (= W1 16384))
     (not (= W1 8192))
     (not (= W1 24576))
     (not (= W1 8195))
     (not (= W1 8480))
     (not (= W1 8481))
     (not (= W1 8482))
     (= F1 0)
     (not (= P 0))
     (<= 0 B)
     (<= 0 E)
     (<= 0 D2)
     (<= 0 R1)
     (<= 0 N1)
     (<= 0 Z)
     (<= 0 Q)
     (<= 0 J)
     (not (<= K1 0))
     (not (= C 0))
     (= v_67 O1))
      )
      (inv_main192 B2
             K
             L1
             I
             A2
             X1
             I1
             T1
             H
             D1
             F1
             S1
             E2
             Q1
             K2
             Z1
             J1
             L
             G1
             T
             F
             Y
             C2
             U1
             U
             O2
             N
             O
             O1
             D
             H2
             E1
             v_67
             M1
             Q
             N1
             D2
             V
             J2
             K1
             F2
             W1
             I2
             M
             G
             R
             W
             P1
             Y1
             V1
             C1
             M2
             C
             P
             G2
             S
             J
             Z
             E
             R1
             N2
             B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main111 O2
             L2
             U
             N2
             K
             W1
             B
             I1
             F2
             O
             H1
             X1
             M2
             N
             T
             E1
             M
             D1
             S1
             W
             J
             V1
             T1
             Z
             H2
             R1
             F
             Y1
             P2
             S
             R
             G2
             A1
             H
             V
             K1
             F1
             E2
             G1
             M1
             D2
             J1
             P
             P1
             C1
             C2
             B2
             Q1
             N1
             C
             A
             Z1
             I
             Q
             U1
             L
             L1
             I2
             E
             O1
             J2
             X)
        (and (= K2 3)
     (not (= A2 0))
     (= W1 8657)
     (not (= W1 8641))
     (not (= W1 8656))
     (not (= W1 8609))
     (not (= W1 8640))
     (not (= W1 8593))
     (not (= W1 8608))
     (not (= W1 8577))
     (not (= W1 8592))
     (not (= W1 8561))
     (not (= W1 8576))
     (not (= W1 8464))
     (not (= W1 8465))
     (not (= W1 8466))
     (not (= W1 8496))
     (not (= W1 8497))
     (not (= W1 8512))
     (not (= W1 8513))
     (not (= W1 8528))
     (not (= W1 8529))
     (not (= W1 8544))
     (not (= W1 8545))
     (not (= W1 8560))
     (not (= W1 8448))
     (not (= W1 12292))
     (not (= W1 16384))
     (not (= W1 8192))
     (not (= W1 24576))
     (not (= W1 8195))
     (not (= W1 8480))
     (not (= W1 8481))
     (not (= W1 8482))
     (= U1 2)
     (not (= B1 0))
     (= Y 0)
     (<= 0 E)
     (<= 0 I2)
     (<= 0 O1)
     (<= 0 L1)
     (<= 0 K1)
     (<= 0 F1)
     (<= 0 X)
     (<= 0 V)
     (not (<= G 0))
     (= D 8672)
     (= v_68 P2))
      )
      (inv_main192 O2
             L2
             U
             N2
             K
             D
             B
             I1
             F2
             O
             Y
             X1
             M2
             N
             T
             E1
             M
             D1
             S1
             W
             J
             V1
             T1
             Z
             H2
             R1
             F
             Y1
             P2
             S
             R
             G2
             v_68
             H
             V
             K1
             F1
             E2
             G1
             G
             D2
             W1
             P
             P1
             C1
             C2
             B2
             Q1
             N1
             C
             A
             Z1
             B1
             A2
             K2
             L
             L1
             I2
             E
             O1
             J2
             X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main111 Y
             X1
             O2
             G2
             T1
             D1
             R
             B
             E1
             X
             I
             C
             B2
             L2
             T
             U
             N
             A2
             H
             Z1
             H1
             H2
             P1
             J1
             D
             P
             F
             K1
             R1
             Q
             V
             S1
             G1
             I2
             G
             J2
             K2
             E
             F2
             B1
             W
             Y1
             E2
             M
             C1
             L1
             Z
             O
             W1
             Q1
             V1
             A1
             I1
             L
             F1
             K
             A
             C2
             N1
             N2
             M1
             J)
        (and (= D2 8672)
     (= O1 0)
     (not (= F1 2))
     (= D1 8657)
     (not (= D1 8641))
     (not (= D1 8656))
     (not (= D1 8609))
     (not (= D1 8640))
     (not (= D1 8593))
     (not (= D1 8608))
     (not (= D1 8577))
     (not (= D1 8592))
     (not (= D1 8561))
     (not (= D1 8576))
     (not (= D1 8464))
     (not (= D1 8465))
     (not (= D1 8466))
     (not (= D1 8496))
     (not (= D1 8497))
     (not (= D1 8512))
     (not (= D1 8513))
     (not (= D1 8528))
     (not (= D1 8529))
     (not (= D1 8544))
     (not (= D1 8545))
     (not (= D1 8560))
     (not (= D1 8448))
     (not (= D1 12292))
     (not (= D1 16384))
     (not (= D1 8192))
     (not (= D1 24576))
     (not (= D1 8195))
     (not (= D1 8480))
     (not (= D1 8481))
     (not (= D1 8482))
     (not (= S 0))
     (<= 0 A)
     (<= 0 K2)
     (<= 0 J2)
     (<= 0 C2)
     (<= 0 N1)
     (<= 0 J)
     (<= 0 G)
     (<= 0 N2)
     (not (<= U1 0))
     (not (= M2 0))
     (= v_67 R1))
      )
      (inv_main192 Y
             X1
             O2
             G2
             T1
             D2
             R
             B
             E1
             X
             O1
             C
             B2
             L2
             T
             U
             N
             A2
             H
             Z1
             H1
             H2
             P1
             J1
             D
             P
             F
             K1
             R1
             Q
             V
             S1
             v_67
             I2
             G
             J2
             K2
             E
             F2
             U1
             W
             D1
             E2
             M
             C1
             L1
             Z
             O
             W1
             Q1
             V1
             A1
             M2
             S
             F1
             K
             A
             C2
             N1
             N2
             M1
             J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main448 G
             O2
             T
             Y1
             H2
             Z
             A2
             C
             P
             O
             B
             J
             Y
             L1
             M
             E2
             X
             L2
             K1
             W
             V1
             H1
             V
             L
             U
             U1
             G1
             B1
             O1
             A
             D1
             N
             K2
             I
             T1
             R
             S
             I1
             N2
             E1
             Q
             R1
             D2
             W1
             Z1
             K
             G2
             H
             F
             B2
             C2
             N1
             A1
             S1
             D
             J1
             Q1
             J2
             F2
             I2
             E
             P1)
        (and (= M2 8640)
     (= X1 8448)
     (= M1 0)
     (= C1 5)
     (not (= J 0))
     (<= 0 J2)
     (<= 0 I2)
     (<= 0 F2)
     (<= 0 T1)
     (<= 0 Q1)
     (<= 0 P1)
     (<= 0 S)
     (<= 0 R)
     (not (<= F1 0))
     (= D 4))
      )
      (inv_main192 G
             O2
             T
             Y1
             H2
             X1
             A2
             C
             P
             O
             M1
             J
             Y
             L1
             M
             E2
             X
             L2
             K1
             W
             V1
             H1
             V
             L
             U
             U1
             G1
             B1
             O1
             A
             M2
             N
             K2
             I
             T1
             R
             S
             I1
             N2
             F1
             Q
             R1
             D2
             W1
             Z1
             K
             G2
             H
             F
             B2
             C2
             N1
             A1
             S1
             C1
             J1
             Q1
             J2
             F2
             I2
             E
             P1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main448 N1
             C
             Z
             S1
             A1
             O
             P
             I1
             I2
             R
             X
             F1
             C2
             M
             K1
             U1
             Q1
             G
             Z1
             B
             N
             K2
             G1
             T1
             V
             H1
             F2
             Q
             L1
             K
             R1
             Y1
             J2
             H2
             B2
             G2
             E
             E2
             J
             A2
             B1
             W1
             O2
             D
             P1
             N2
             L2
             O1
             X1
             T
             Y
             F
             H
             D2
             D1
             J1
             M2
             M1
             W
             C1
             L
             U)
        (and (= V1 8448)
     (= F1 0)
     (= E1 5)
     (= D1 4)
     (= S 0)
     (<= 0 E)
     (<= 0 M2)
     (<= 0 G2)
     (<= 0 B2)
     (<= 0 M1)
     (<= 0 C1)
     (<= 0 W)
     (<= 0 U)
     (not (<= I 0))
     (= A 3))
      )
      (inv_main192 N1
             C
             Z
             S1
             A1
             V1
             P
             I1
             I2
             R
             S
             F1
             C2
             M
             K1
             U1
             Q1
             G
             Z1
             B
             N
             K2
             G1
             T1
             V
             H1
             F2
             Q
             L1
             K
             A
             Y1
             J2
             H2
             B2
             G2
             E
             E2
             J
             I
             B1
             W1
             O2
             D
             P1
             N2
             L2
             O1
             X1
             T
             Y
             F
             H
             D2
             E1
             J1
             M2
             M1
             W
             C1
             L
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main448 O1
             Q
             J
             A1
             W1
             D
             C2
             H1
             S1
             I1
             I
             U1
             V1
             I2
             E
             D2
             F1
             Y
             X
             R
             C1
             Z
             F
             L
             N1
             L1
             J1
             E1
             H
             Q1
             P1
             O
             V
             K2
             T1
             Y1
             D1
             C
             F2
             M
             G1
             X1
             W
             L2
             N
             U
             A
             N2
             R1
             Z1
             P
             B2
             K1
             B
             M1
             J2
             K
             B1
             T
             G2
             A2
             S)
        (and (not (= U1 0))
     (not (= M1 3))
     (not (= M1 4))
     (= G 0)
     (= M2 8640)
     (<= 0 G2)
     (<= 0 Y1)
     (<= 0 T1)
     (<= 0 D1)
     (<= 0 B1)
     (<= 0 T)
     (<= 0 S)
     (<= 0 K)
     (not (<= H2 0))
     (= E2 8448))
      )
      (inv_main192 O1
             Q
             J
             A1
             W1
             E2
             C2
             H1
             S1
             I1
             G
             U1
             V1
             I2
             E
             D2
             F1
             Y
             X
             R
             C1
             Z
             F
             L
             N1
             L1
             J1
             E1
             H
             Q1
             M2
             O
             V
             K2
             T1
             Y1
             D1
             C
             F2
             H2
             G1
             X1
             W
             L2
             N
             U
             A
             N2
             R1
             Z1
             P
             B2
             K1
             B
             M1
             J2
             K
             B1
             T
             G2
             A2
             S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main448 R1
             N2
             E2
             L2
             O
             U
             D2
             D1
             X1
             B
             O1
             C
             S1
             B1
             T
             M
             I2
             G2
             Z
             W1
             U1
             G1
             Z1
             G
             L1
             N
             S
             M2
             K
             W
             C1
             J2
             P1
             A
             T1
             Y
             V1
             E
             H
             C2
             Y1
             V
             K2
             L
             P
             H2
             X
             F1
             N1
             I1
             J
             B2
             Q
             R
             M1
             A1
             J1
             E1
             F2
             Q1
             H1
             K1)
        (and (= A2 8448)
     (not (= M1 3))
     (not (= M1 4))
     (= I 3)
     (= F 0)
     (<= 0 F2)
     (<= 0 V1)
     (<= 0 T1)
     (<= 0 Q1)
     (<= 0 K1)
     (<= 0 J1)
     (<= 0 E1)
     (<= 0 Y)
     (not (<= D 0))
     (= C 0))
      )
      (inv_main192 R1
             N2
             E2
             L2
             O
             A2
             D2
             D1
             X1
             B
             F
             C
             S1
             B1
             T
             M
             I2
             G2
             Z
             W1
             U1
             G1
             Z1
             G
             L1
             N
             S
             M2
             K
             W
             I
             J2
             P1
             A
             T1
             Y
             V1
             E
             H
             D
             Y1
             V
             K2
             L
             P
             H2
             X
             F1
             N1
             I1
             J
             B2
             Q
             R
             M1
             A1
             J1
             E1
             F2
             Q1
             H1
             K1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main291 F1
             L1
             D1
             H1
             I2
             Q
             D
             J2
             X
             V
             J
             B1
             C2
             G1
             B
             C
             T1
             Y1
             S
             N
             O1
             S1
             D2
             A1
             I
             Z
             W1
             L2
             E2
             G
             A
             Z1
             T
             F
             E1
             M1
             A2
             K1
             P1
             E
             Y
             R1
             H
             K
             M2
             V1
             W
             M
             U
             L
             N1
             X1
             B2
             J1
             Q1
             P
             G2
             F2
             O
             I1
             R
             K2)
        (and (= C1 0)
     (not (= L2 0))
     (<= 0 K2)
     (<= 0 G2)
     (<= 0 F2)
     (<= 0 A2)
     (<= 0 M1)
     (<= 0 I1)
     (<= 0 E1)
     (<= 0 O)
     (not (<= H2 0))
     (= U1 8544))
      )
      (inv_main192 F1
             L1
             D1
             H1
             I2
             U1
             D
             J2
             X
             V
             C1
             B1
             C2
             G1
             B
             C
             T1
             Y1
             S
             N
             O1
             S1
             D2
             A1
             I
             Z
             W1
             L2
             E2
             G
             A
             Z1
             T
             F
             E1
             M1
             A2
             K1
             P1
             H2
             Y
             R1
             H
             K
             M2
             V1
             W
             M
             U
             L
             N1
             X1
             B2
             J1
             Q1
             P
             G2
             F2
             O
             I1
             R
             K2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main291 J2
             F1
             T1
             J
             R1
             V
             D1
             P1
             N
             I
             E2
             O1
             K1
             N1
             H2
             M
             M1
             F2
             L1
             W1
             C1
             Z
             Y
             M2
             G2
             B2
             X1
             Q
             P
             K
             H1
             J1
             B
             X
             C2
             V1
             K2
             L2
             A
             W
             G1
             S
             F
             S1
             D
             L
             Y1
             E1
             Q1
             U1
             O
             B1
             D2
             H
             I1
             R
             A2
             Z1
             G
             I2
             E
             U)
        (and (not (= C2 (- 30)))
     (= T 8544)
     (= Q 0)
     (<= 0 K2)
     (<= 0 I2)
     (<= 0 C2)
     (<= 0 A2)
     (<= 0 Z1)
     (<= 0 V1)
     (<= 0 U)
     (<= 0 G)
     (not (<= A1 0))
     (= C 0))
      )
      (inv_main192 J2
             F1
             T1
             J
             R1
             T
             D1
             P1
             N
             I
             C
             O1
             K1
             N1
             H2
             M
             M1
             F2
             L1
             W1
             C1
             Z
             Y
             M2
             G2
             B2
             X1
             Q
             P
             K
             H1
             J1
             B
             X
             C2
             V1
             K2
             L2
             A
             A1
             G1
             S
             F
             S1
             D
             L
             Y1
             E1
             Q1
             U1
             O
             B1
             D2
             H
             I1
             R
             A2
             Z1
             G
             I2
             E
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main291 F2
             A2
             Q
             Q1
             H
             J2
             T
             A
             D1
             K1
             C
             I2
             B2
             L2
             I1
             S
             G1
             M2
             N
             C1
             V1
             G2
             M1
             K
             Y1
             G
             H2
             X1
             D
             W1
             J1
             L
             I
             E2
             R1
             E1
             K2
             A1
             U1
             M
             V
             X
             D2
             Z1
             N1
             B1
             T1
             O
             P
             W
             O1
             L1
             Y
             F1
             P1
             B
             E
             H1
             C2
             R
             J
             S1)
        (and (= V1 0)
     (= R1 (- 30))
     (not (= R1 (- 1)))
     (= Z 0)
     (= F 8544)
     (<= 0 K2)
     (<= 0 C2)
     (<= 0 S1)
     (<= 0 R1)
     (<= 0 H1)
     (<= 0 E1)
     (<= 0 R)
     (<= 0 E)
     (not (<= U 0))
     (= X1 0))
      )
      (inv_main192 F2
             A2
             Q
             Q1
             H
             F
             T
             A
             D1
             K1
             Z
             I2
             B2
             L2
             I1
             S
             G1
             M2
             N
             C1
             V1
             G2
             M1
             K
             Y1
             G
             H2
             X1
             D
             W1
             J1
             L
             I
             E2
             R1
             E1
             K2
             A1
             U1
             U
             V
             X
             D2
             Z1
             N1
             B1
             T1
             O
             P
             W
             O1
             L1
             Y
             F1
             P1
             B
             E
             H1
             C2
             R
             J
             S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main291 M2
             R1
             P2
             Y
             N2
             S
             I
             O2
             B1
             F2
             K
             C
             M1
             M
             H2
             U
             D
             J
             X
             G2
             P1
             V1
             C2
             J2
             H1
             B
             D2
             Q
             U1
             O1
             S1
             V
             P
             L
             F
             H
             E
             Z
             L2
             J1
             Q1
             E1
             B2
             X1
             L1
             R
             K2
             I1
             C1
             A
             I2
             A2
             F1
             T
             W1
             Y1
             Z1
             E2
             G
             T1
             N1
             O)
        (and (= F (- 30))
     (not (= F (- 1)))
     (not (= P1 0))
     (= K1 512)
     (= D1 0)
     (= W 8544)
     (not (= V (- 2)))
     (not (= V (- 4)))
     (= Q 0)
     (>= N 65)
     (<= 0 E)
     (<= 0 F)
     (<= 0 E2)
     (<= 0 Z1)
     (<= 0 T1)
     (<= 0 O)
     (<= 0 H)
     (<= 0 G)
     (not (<= G1 0))
     (= (+ A1 (* (- 8) N)) 0)
     (= v_68 V)
     (= v_69 V))
      )
      (inv_main192 M2
             R1
             P2
             Y
             N2
             W
             I
             O2
             B1
             F2
             D1
             C
             M1
             M
             H2
             U
             D
             J
             X
             G2
             P1
             V1
             C2
             J2
             H1
             B
             D2
             Q
             U1
             O1
             S1
             V
             P
             L
             F
             H
             E
             Z
             L2
             G1
             Q1
             E1
             B2
             X1
             L1
             R
             K2
             I1
             C1
             N
             K1
             A2
             F1
             T
             W1
             Y1
             Z1
             E2
             v_68
             v_69
             A1
             O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main291 K
             N2
             K2
             G2
             O
             F2
             Q1
             H1
             E
             E2
             V1
             H2
             U1
             J
             O2
             M2
             Y
             F1
             S1
             T
             G
             A1
             G1
             J2
             L1
             C
             K1
             J1
             M
             I
             X1
             D2
             L
             B2
             C2
             R1
             T1
             U
             Z
             S
             H
             P1
             B
             Q
             A
             O1
             I2
             F
             X
             M1
             W1
             Y1
             P2
             A2
             C1
             B1
             L2
             W
             N
             V
             N1
             Z1)
        (and (= D 0)
     (not (= D2 (- 2)))
     (= D2 (- 4))
     (= C2 (- 30))
     (not (= C2 (- 1)))
     (= J1 0)
     (= I1 8544)
     (= R 1024)
     (not (= G 0))
     (>= E1 129)
     (<= 0 L2)
     (<= 0 C2)
     (<= 0 Z1)
     (<= 0 T1)
     (<= 0 R1)
     (<= 0 W)
     (<= 0 V)
     (<= 0 N)
     (not (<= P 0))
     (= (+ D1 (* (- 8) E1)) 0)
     (= v_68 D2)
     (= v_69 D2))
      )
      (inv_main192 K
             N2
             K2
             G2
             O
             I1
             Q1
             H1
             E
             E2
             D
             H2
             U1
             J
             O2
             M2
             Y
             F1
             S1
             T
             G
             A1
             G1
             J2
             L1
             C
             K1
             J1
             M
             I
             X1
             D2
             L
             B2
             C2
             R1
             T1
             U
             Z
             P
             H
             P1
             B
             Q
             A
             O1
             I2
             F
             X
             E1
             R
             Y1
             P2
             A2
             C1
             B1
             L2
             W
             v_68
             v_69
             D1
             Z1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main4 D2 P)
        (and (= W1 0)
     (not (= U1 0))
     (= N1 8464)
     (= M1 (- 1))
     (= I1 8464)
     (= N 0)
     (= D 0)
     (= A 1)
     (<= 0 R1)
     (<= 0 F1)
     (<= 0 E1)
     (<= 0 S)
     (<= 0 O)
     (<= 0 I)
     (<= 0 H)
     (= Z1 8464)
     (= v_62 G)
     (= v_63 U1))
      )
      (inv_main100 Z1
             P
             N1
             U1
             T1
             I1
             G1
             M
             E
             Q
             G2
             C
             D1
             A
             T
             V1
             K1
             H2
             K
             J
             B1
             Q1
             L
             C1
             I2
             B
             L1
             P1
             F2
             X
             U
             R
             A1
             J2
             O
             G
             v_62
             v_63
             J1
             M1
             E2
             S1
             N
             D
             O1
             V
             F
             C2
             A2
             W
             X1
             B2
             H1
             Z
             W1
             Y
             H
             R1
             I
             S
             Y1
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main4 H2 B2)
        (and (= W1 8464)
     (not (= T1 0))
     (= Q1 0)
     (= I1 0)
     (= E1 1)
     (= Z (- 1))
     (= N 8464)
     (= K 8464)
     (= D 0)
     (<= 0 A2)
     (<= 0 U1)
     (<= 0 D1)
     (<= 0 S)
     (<= 0 G)
     (<= 0 F)
     (<= 0 A)
     (= E2 0)
     (= v_62 L1)
     (= v_63 T1))
      )
      (inv_main100 N
             B2
             W1
             I1
             W
             K
             R1
             R
             F1
             S1
             M
             U
             G1
             E1
             J2
             Z1
             I2
             Y
             O
             Y1
             T
             T1
             X
             B1
             H
             A1
             Q
             P1
             H1
             B
             X1
             I
             L
             C
             U1
             L1
             v_62
             v_63
             F2
             Z
             E
             M1
             Q1
             D
             J
             G2
             V1
             K1
             O1
             P
             N1
             C2
             V
             D2
             E2
             J1
             D1
             G
             S
             A
             C1
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main4 I2 F1)
        (and (= D2 0)
     (= Z1 8464)
     (= W1 1)
     (= V1 0)
     (= L1 0)
     (= J1 0)
     (= C1 (- 1))
     (= Z 0)
     (= T 8464)
     (= B 8464)
     (<= 0 Y1)
     (<= 0 H1)
     (<= 0 G1)
     (<= 0 R)
     (<= 0 P)
     (<= 0 N)
     (<= 0 E)
     (= G2 0)
     (= v_63 E1))
      )
      (inv_main100 B
             F1
             Z1
             J1
             K2
             T
             V
             D1
             M1
             T1
             I
             E2
             A1
             W1
             H2
             R1
             O1
             X
             O
             B2
             J2
             G2
             B1
             C
             Q1
             H
             L
             F
             A2
             D
             A
             Y
             U
             I1
             H1
             E1
             v_63
             Z
             K
             C1
             U1
             S1
             V1
             D2
             X1
             C2
             N1
             M
             J
             S
             F2
             P1
             W
             K1
             L1
             Q
             G1
             R
             P
             E
             G
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main448 D1
             E2
             V
             K1
             D
             S1
             D2
             B1
             J2
             B
             H1
             I2
             Y
             W1
             I1
             E
             M
             X1
             O1
             F1
             U1
             X
             B2
             T1
             G
             I
             T
             L
             F2
             V1
             A2
             C
             H
             Y1
             L1
             O
             K
             Z
             U
             J
             M1
             N
             G2
             C2
             G1
             P
             Q1
             S
             C1
             J1
             A
             R1
             N1
             W
             F
             P1
             R
             Z1
             K2
             H2
             Q
             A1)
        (and (not (= F 4))
     (<= 0 H2)
     (<= 0 Z1)
     (<= 0 L1)
     (<= 0 A1)
     (<= 0 R)
     (<= 0 O)
     (<= 0 K)
     (<= 0 K2)
     (= F 3))
      )
      (inv_main499 D1
             E2
             V
             K1
             D
             S1
             D2
             B1
             J2
             B
             H1
             I2
             Y
             W1
             I1
             E
             M
             X1
             O1
             F1
             U1
             X
             B2
             T1
             G
             I
             T
             L
             F2
             V1
             A2
             C
             H
             Y1
             L1
             O
             K
             Z
             U
             E1
             M1
             N
             G2
             C2
             G1
             P
             Q1
             S
             C1
             J1
             A
             R1
             N1
             W
             F
             P1
             R
             Z1
             K2
             H2
             Q
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main111 R
             W1
             J
             Y
             K2
             G1
             E
             Z1
             G
             M
             C
             P1
             B
             L
             S1
             Y1
             P
             T1
             G2
             X1
             D2
             I
             C1
             T
             A2
             S
             X
             U
             A
             N1
             I2
             J1
             A1
             F1
             D1
             J2
             I1
             F
             K1
             L1
             Q
             D
             Q1
             C2
             B2
             V
             H1
             O1
             F2
             M1
             H
             E1
             W
             B1
             K
             Z
             O
             R1
             N
             E2
             H2
             V1)
        (and (not (= T1 (- 2097152)))
     (not (= G1 8464))
     (not (= G1 8465))
     (not (= G1 8466))
     (not (= G1 8496))
     (not (= G1 8497))
     (not (= G1 8512))
     (not (= G1 8513))
     (= G1 8528)
     (not (= G1 12292))
     (not (= G1 16384))
     (not (= G1 8192))
     (not (= G1 24576))
     (not (= G1 8195))
     (not (= G1 8480))
     (not (= G1 8481))
     (not (= G1 8482))
     (<= 0 E2)
     (<= 0 V1)
     (<= 0 R1)
     (<= 0 I1)
     (<= 0 D1)
     (<= 0 O)
     (<= 0 N)
     (<= 0 J2)
     (= U1 1)
     (= v_63 N1)
     (= v_64 G1)
     (= v_65 T1))
      )
      (inv_main291 R
             W1
             J
             Y
             K2
             G1
             E
             Z1
             G
             M
             C
             P1
             B
             L
             S1
             Y1
             P
             T1
             G2
             X1
             D2
             I
             C1
             T
             A2
             S
             X
             U1
             A
             N1
             I2
             J1
             A1
             F1
             v_63
             J2
             I1
             F
             K1
             L1
             Q
             v_64
             Q1
             C2
             B2
             V
             H1
             O1
             F2
             M1
             H
             E1
             W
             B1
             K
             Z
             O
             v_65
             N
             E2
             H2
             V1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main111 C2
             V
             A2
             H1
             G2
             F1
             N1
             I
             X
             F
             J
             M1
             U1
             F2
             L
             K2
             S
             P
             I2
             H2
             N
             B1
             H
             K
             T
             O
             L1
             Z1
             B2
             J1
             M
             G1
             R1
             X1
             E2
             J2
             I1
             U
             Q1
             Y
             Y1
             C
             O1
             E1
             W
             K1
             R
             G
             Q
             A
             D
             C1
             Z
             E
             T1
             P1
             A1
             D1
             V1
             D2
             W1
             B)
        (and (not (= F1 8464))
     (not (= F1 8465))
     (not (= F1 8466))
     (not (= F1 8496))
     (not (= F1 8497))
     (not (= F1 8512))
     (not (= F1 8513))
     (= F1 8528)
     (not (= F1 12292))
     (not (= F1 16384))
     (not (= F1 8192))
     (not (= F1 24576))
     (not (= F1 8195))
     (not (= F1 8480))
     (not (= F1 8481))
     (not (= F1 8482))
     (= P (- 2097152))
     (<= 0 E2)
     (<= 0 D2)
     (<= 0 V1)
     (<= 0 I1)
     (<= 0 D1)
     (<= 0 A1)
     (<= 0 B)
     (<= 0 J2)
     (= S1 0)
     (= v_63 J1)
     (= v_64 F1)
     (= v_65 P))
      )
      (inv_main291 C2
             V
             A2
             H1
             G2
             F1
             N1
             I
             X
             F
             J
             M1
             U1
             F2
             L
             K2
             S
             P
             I2
             H2
             N
             B1
             H
             K
             T
             O
             L1
             S1
             B2
             J1
             M
             G1
             R1
             X1
             v_63
             J2
             I1
             U
             Q1
             Y
             Y1
             v_64
             O1
             E1
             W
             K1
             R
             G
             Q
             A
             D
             C1
             Z
             E
             T1
             P1
             A1
             v_65
             V1
             D2
             W1
             B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main111 S
             A2
             A1
             Z
             H1
             B1
             H2
             I2
             Z1
             H
             M
             F2
             C2
             E2
             T
             G2
             G
             I1
             W1
             X
             D
             T1
             D2
             F1
             R
             K1
             B2
             E
             Q
             B
             Q1
             N
             R1
             V
             I
             P
             G1
             K
             N1
             L
             F
             L1
             V1
             O
             C1
             K2
             U
             E1
             J
             Y1
             O1
             C
             X1
             J2
             M1
             S1
             D1
             P1
             A
             Y
             W
             U1)
        (and (not (= I1 (- 2097152)))
     (not (= B1 8464))
     (not (= B1 8465))
     (not (= B1 8466))
     (not (= B1 8496))
     (not (= B1 8497))
     (not (= B1 8512))
     (not (= B1 8513))
     (not (= B1 8528))
     (= B1 8529)
     (not (= B1 12292))
     (not (= B1 16384))
     (not (= B1 8192))
     (not (= B1 24576))
     (not (= B1 8195))
     (not (= B1 8480))
     (not (= B1 8481))
     (not (= B1 8482))
     (<= 0 A)
     (<= 0 U1)
     (<= 0 P1)
     (<= 0 G1)
     (<= 0 D1)
     (<= 0 Y)
     (<= 0 P)
     (<= 0 I)
     (= J1 1)
     (= v_63 B)
     (= v_64 B1)
     (= v_65 I1))
      )
      (inv_main291 S
             A2
             A1
             Z
             H1
             B1
             H2
             I2
             Z1
             H
             M
             F2
             C2
             E2
             T
             G2
             G
             I1
             W1
             X
             D
             T1
             D2
             F1
             R
             K1
             B2
             J1
             Q
             B
             Q1
             N
             R1
             V
             v_63
             P
             G1
             K
             N1
             L
             F
             v_64
             V1
             O
             C1
             K2
             U
             E1
             J
             Y1
             O1
             C
             X1
             J2
             M1
             S1
             D1
             v_65
             A
             Y
             W
             U1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main111 J2
             C2
             Y
             C
             I
             E2
             P
             Q1
             J1
             F2
             D1
             L1
             X1
             Q
             W1
             M1
             T
             Z
             X
             N
             V
             S
             B2
             E
             U
             L
             V1
             D
             A2
             I2
             N1
             R
             T1
             J
             K1
             P1
             G1
             M
             C1
             H
             K2
             U1
             G2
             G
             R1
             O
             F
             Y1
             Z1
             H1
             W
             F1
             A
             B1
             S1
             I1
             B
             H2
             K
             A1
             D2
             E1)
        (and (not (= E2 8465))
     (not (= E2 8466))
     (not (= E2 8496))
     (not (= E2 8497))
     (not (= E2 8512))
     (not (= E2 8513))
     (not (= E2 8528))
     (= E2 8529)
     (not (= E2 12292))
     (not (= E2 16384))
     (not (= E2 8192))
     (not (= E2 24576))
     (not (= E2 8195))
     (not (= E2 8480))
     (not (= E2 8481))
     (not (= E2 8482))
     (= O1 0)
     (= Z (- 2097152))
     (<= 0 H2)
     (<= 0 P1)
     (<= 0 K1)
     (<= 0 G1)
     (<= 0 E1)
     (<= 0 A1)
     (<= 0 K)
     (<= 0 B)
     (not (= E2 8464))
     (= v_63 I2)
     (= v_64 E2)
     (= v_65 Z))
      )
      (inv_main291 J2
             C2
             Y
             C
             I
             E2
             P
             Q1
             J1
             F2
             D1
             L1
             X1
             Q
             W1
             M1
             T
             Z
             X
             N
             V
             S
             B2
             E
             U
             L
             V1
             O1
             A2
             I2
             N1
             R
             T1
             J
             v_63
             P1
             G1
             M
             C1
             H
             K2
             v_64
             G2
             G
             R1
             O
             F
             Y1
             Z1
             H1
             W
             F1
             A
             B1
             S1
             I1
             B
             v_65
             K
             A1
             D2
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main111 Q
             H2
             M
             N1
             K
             O1
             D2
             A2
             J1
             J2
             K1
             I1
             B2
             P1
             F1
             D
             Q1
             E
             B1
             G1
             B
             C
             I
             A1
             G2
             M1
             J
             F
             A
             Y
             G
             W
             F2
             U1
             V
             I2
             N
             E2
             T1
             S1
             R1
             U
             E1
             O
             S
             T
             L1
             L
             Z
             C2
             R
             H1
             Z1
             D1
             P
             X1
             H
             C1
             Y1
             V1
             X
             W1)
        (and (not (= O1 8465))
     (= O1 8466)
     (not (= O1 12292))
     (not (= O1 16384))
     (not (= O1 8192))
     (not (= O1 24576))
     (not (= O1 8195))
     (not (= O1 8480))
     (not (= O1 8481))
     (not (= O1 8482))
     (<= 0 Y1)
     (<= 0 W1)
     (<= 0 V1)
     (<= 0 C1)
     (<= 0 V)
     (<= 0 N)
     (<= 0 H)
     (<= 0 I2)
     (not (= O1 8464))
     (= v_62 O1))
      )
      (inv_main248 Q
             H2
             M
             N1
             K
             O1
             D2
             A2
             J1
             J2
             K1
             I1
             B2
             P1
             F1
             D
             Q1
             E
             B1
             G1
             B
             C
             I
             A1
             G2
             M1
             J
             F
             A
             Y
             G
             W
             F2
             U1
             V
             I2
             N
             E2
             T1
             S1
             R1
             v_62
             E1
             O
             S
             T
             L1
             L
             Z
             C2
             R
             H1
             Z1
             D1
             P
             X1
             H
             C1
             Y1
             V1
             X
             W1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main111 K
             Z
             D
             J
             W
             U1
             B
             Y1
             C
             E2
             G
             T1
             I
             C2
             F1
             P
             X
             F2
             V
             B2
             K1
             T
             N1
             S
             F
             A2
             O
             C1
             E
             J1
             N
             Z1
             G1
             H
             M1
             O1
             G2
             A
             I2
             R
             J2
             S1
             Q
             M
             L
             B1
             X1
             R1
             P1
             W1
             D2
             U
             L1
             A1
             E1
             I1
             V1
             H1
             D1
             Q1
             Y
             H2)
        (and (not (= U1 12292))
     (not (= U1 16384))
     (not (= U1 8192))
     (not (= U1 24576))
     (not (= U1 8195))
     (not (= U1 8480))
     (not (= U1 8481))
     (not (= U1 8482))
     (<= 0 H2)
     (<= 0 G2)
     (<= 0 V1)
     (<= 0 Q1)
     (<= 0 O1)
     (<= 0 M1)
     (<= 0 H1)
     (<= 0 D1)
     (= U1 8464)
     (= v_62 U1))
      )
      (inv_main248 K
             Z
             D
             J
             W
             U1
             B
             Y1
             C
             E2
             G
             T1
             I
             C2
             F1
             P
             X
             F2
             V
             B2
             K1
             T
             N1
             S
             F
             A2
             O
             C1
             E
             J1
             N
             Z1
             G1
             H
             M1
             O1
             G2
             A
             I2
             R
             J2
             v_62
             Q
             M
             L
             B1
             X1
             R1
             P1
             W1
             D2
             U
             L1
             A1
             E1
             I1
             V1
             H1
             D1
             Q1
             Y
             H2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main111 O1
             E
             C1
             Q
             G1
             I
             U
             K1
             A1
             V
             R1
             G2
             A
             P1
             P
             I1
             S1
             Y1
             Y
             B1
             H2
             G
             H
             O
             F
             I2
             M
             Z
             J1
             Z1
             M1
             D1
             X1
             N
             K
             E2
             A2
             L1
             S
             V1
             T1
             N1
             F1
             L
             B2
             E1
             J2
             W1
             J
             T
             B
             R
             Q1
             D
             X
             C2
             H1
             U1
             C
             W
             D2
             F2)
        (and (= I 8465)
     (not (= I 12292))
     (not (= I 16384))
     (not (= I 8192))
     (not (= I 24576))
     (not (= I 8195))
     (not (= I 8480))
     (not (= I 8481))
     (not (= I 8482))
     (<= 0 F2)
     (<= 0 E2)
     (<= 0 A2)
     (<= 0 U1)
     (<= 0 H1)
     (<= 0 W)
     (<= 0 K)
     (<= 0 C)
     (not (= I 8464))
     (= v_62 I))
      )
      (inv_main248 O1
             E
             C1
             Q
             G1
             I
             U
             K1
             A1
             V
             R1
             G2
             A
             P1
             P
             I1
             S1
             Y1
             Y
             B1
             H2
             G
             H
             O
             F
             I2
             M
             Z
             J1
             Z1
             M1
             D1
             X1
             N
             K
             E2
             A2
             L1
             S
             V1
             T1
             v_62
             F1
             L
             B2
             E1
             J2
             W1
             J
             T
             B
             R
             Q1
             D
             X
             C2
             H1
             U1
             C
             W
             D2
             F2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main192 F1
             G2
             L1
             V1
             M1
             E
             E1
             A
             J
             H1
             W1
             D1
             Q1
             J1
             N
             B1
             V
             I2
             D2
             G
             I
             C1
             O1
             I1
             H
             T1
             A2
             P1
             C
             Z1
             N1
             S
             K
             T
             E2
             Q
             C2
             Y
             A1
             H2
             X1
             R
             U
             Z
             G1
             M
             S1
             B
             U1
             Y1
             R1
             O
             F
             B2
             X
             W
             K1
             D
             F2
             L
             P
             J2)
        (and (= U 0)
     (= N 0)
     (<= 0 F2)
     (<= 0 E2)
     (<= 0 C2)
     (<= 0 K1)
     (<= 0 Q)
     (<= 0 L)
     (<= 0 D)
     (<= 0 J2)
     (= A2 0))
      )
      (inv_main482 F1
             G2
             L1
             V1
             M1
             E
             E1
             A
             J
             H1
             W1
             D1
             Q1
             J1
             N
             B1
             V
             I2
             D2
             G
             I
             C1
             O1
             I1
             H
             T1
             A2
             P1
             C
             Z1
             N1
             S
             K
             T
             E2
             Q
             C2
             Y
             A1
             H2
             X1
             R
             U
             Z
             G1
             M
             S1
             B
             U1
             Y1
             R1
             O
             F
             B2
             X
             W
             K1
             D
             F2
             L
             P
             J2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main192 D2
             E
             J2
             H2
             K
             T
             S
             J
             F2
             G
             O1
             Q
             Z
             M
             S1
             B2
             L1
             C
             Z1
             H1
             R1
             H
             Q1
             A2
             T1
             F1
             X1
             X
             F
             B
             I
             G1
             V1
             K1
             U1
             V
             B1
             P
             C2
             J1
             I1
             Y1
             W
             A1
             Y
             E2
             N1
             A
             L
             E1
             R
             K2
             O
             C1
             D
             M1
             P1
             G2
             U
             I2
             D1
             N)
        (and (not (= S1 0))
     (= W 0)
     (<= 0 I2)
     (<= 0 G2)
     (<= 0 U1)
     (<= 0 P1)
     (<= 0 B1)
     (<= 0 V)
     (<= 0 U)
     (<= 0 N)
     (not (<= W1 0))
     (= X1 0))
      )
      (inv_main482 D2
             E
             J2
             H2
             K
             T
             S
             J
             F2
             G
             O1
             Q
             Z
             M
             S1
             B2
             L1
             C
             Z1
             H1
             R1
             H
             Q1
             A2
             T1
             F1
             X1
             X
             F
             B
             I
             G1
             V1
             K1
             U1
             V
             B1
             P
             C2
             W1
             I1
             Y1
             W
             A1
             Y
             E2
             N1
             A
             L
             E1
             R
             K2
             O
             C1
             D
             M1
             P1
             G2
             U
             I2
             D1
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main111 Q
             G1
             L
             U
             L1
             E2
             F1
             E1
             B2
             X1
             Y1
             S1
             T
             K1
             X
             W
             B1
             N1
             C1
             M
             G
             S
             I2
             H2
             V
             D
             H
             G2
             Q1
             P1
             O
             C2
             A2
             V1
             K
             H1
             D1
             A1
             R
             T1
             J
             J1
             C
             F
             U1
             W1
             D2
             E
             I1
             J2
             B
             A
             Y
             M1
             Z
             N
             P
             I
             Z1
             R1
             F2
             O1)
        (and (= E2 8672)
     (not (= E2 8641))
     (not (= E2 8656))
     (not (= E2 8609))
     (not (= E2 8640))
     (not (= E2 8593))
     (not (= E2 8608))
     (not (= E2 8577))
     (not (= E2 8592))
     (not (= E2 8561))
     (not (= E2 8576))
     (not (= E2 8464))
     (not (= E2 8465))
     (not (= E2 8466))
     (not (= E2 8496))
     (not (= E2 8497))
     (not (= E2 8512))
     (not (= E2 8513))
     (not (= E2 8528))
     (not (= E2 8529))
     (not (= E2 8544))
     (not (= E2 8545))
     (not (= E2 8560))
     (not (= E2 8448))
     (not (= E2 12292))
     (not (= E2 16384))
     (not (= E2 8192))
     (not (= E2 24576))
     (not (= E2 8195))
     (not (= E2 8480))
     (not (= E2 8481))
     (not (= E2 8482))
     (<= 0 Z1)
     (<= 0 R1)
     (<= 0 O1)
     (<= 0 H1)
     (<= 0 D1)
     (<= 0 P)
     (<= 0 K)
     (<= 0 I)
     (not (= E2 8657))
     (= v_62 E2))
      )
      (inv_main448 Q
             G1
             L
             U
             L1
             E2
             F1
             E1
             B2
             X1
             Y1
             S1
             T
             K1
             X
             W
             B1
             N1
             C1
             M
             G
             S
             I2
             H2
             V
             D
             H
             G2
             Q1
             P1
             O
             C2
             A2
             V1
             K
             H1
             D1
             A1
             R
             T1
             J
             v_62
             C
             F
             U1
             W1
             D2
             E
             I1
             J2
             B
             A
             Y
             M1
             Z
             N
             P
             I
             Z1
             R1
             F2
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main111 A
             O1
             B
             Z
             Y1
             T
             G
             H
             P
             Z1
             F1
             B1
             C
             I1
             V
             B2
             I2
             Y
             H1
             L1
             T1
             E1
             Q
             G1
             M1
             M
             A1
             V1
             P1
             S
             J
             F2
             N
             F
             K1
             D1
             E
             X1
             S1
             H2
             J2
             A2
             G2
             L
             U
             D
             C2
             X
             W
             I
             J1
             D2
             R1
             Q1
             E2
             R
             O
             W1
             C1
             K
             N1
             U1)
        (and (not (= T 8657))
     (not (= T 8672))
     (not (= T 8641))
     (not (= T 8656))
     (not (= T 8609))
     (not (= T 8640))
     (not (= T 8593))
     (not (= T 8608))
     (not (= T 8577))
     (not (= T 8592))
     (not (= T 8561))
     (not (= T 8576))
     (not (= T 8464))
     (not (= T 8465))
     (not (= T 8466))
     (not (= T 8496))
     (not (= T 8497))
     (not (= T 8512))
     (not (= T 8513))
     (not (= T 8528))
     (not (= T 8529))
     (not (= T 8544))
     (not (= T 8545))
     (not (= T 8560))
     (not (= T 8448))
     (not (= T 12292))
     (not (= T 16384))
     (not (= T 8192))
     (not (= T 24576))
     (not (= T 8195))
     (not (= T 8480))
     (not (= T 8481))
     (not (= T 8482))
     (<= 0 W1)
     (<= 0 U1)
     (<= 0 K1)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 O)
     (<= 0 K)
     (<= 0 E)
     (= T 8673)
     (= v_62 T))
      )
      (inv_main448 A
             O1
             B
             Z
             Y1
             T
             G
             H
             P
             Z1
             F1
             B1
             C
             I1
             V
             B2
             I2
             Y
             H1
             L1
             T1
             E1
             Q
             G1
             M1
             M
             A1
             V1
             P1
             S
             J
             F2
             N
             F
             K1
             D1
             E
             X1
             S1
             H2
             J2
             v_62
             G2
             L
             U
             D
             C2
             X
             W
             I
             J1
             D2
             R1
             Q1
             E2
             R
             O
             W1
             C1
             K
             N1
             U1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main111 R
             A
             L2
             J2
             C2
             Y
             F1
             U
             J
             K
             P1
             Y1
             E
             I1
             Z1
             M
             Q1
             T1
             R1
             E1
             B2
             G1
             P
             D
             W
             V
             G
             K1
             A2
             O
             Q
             K2
             X1
             E2
             O1
             G2
             I2
             A1
             Z
             C
             D1
             I
             D2
             M1
             T
             B
             H2
             H1
             S
             F2
             J1
             V1
             L1
             S1
             F
             X
             U1
             N1
             W1
             C1
             N
             L)
        (and (not (= Y 8464))
     (not (= Y 8465))
     (not (= Y 8466))
     (= Y 8496)
     (not (= Y 12292))
     (not (= Y 16384))
     (not (= Y 8192))
     (not (= Y 24576))
     (not (= Y 8195))
     (not (= Y 8480))
     (not (= Y 8481))
     (not (= Y 8482))
     (= F 1)
     (<= 0 I2)
     (<= 0 G2)
     (<= 0 W1)
     (<= 0 U1)
     (<= 0 O1)
     (<= 0 N1)
     (<= 0 C1)
     (<= 0 L)
     (= B1 2)
     (= v_64 Y))
      )
      (inv_main265 R
             A
             L2
             J2
             C2
             Y
             F1
             U
             J
             K
             P1
             Y1
             E
             I1
             Z1
             M
             Q1
             T1
             R1
             E1
             B2
             G1
             P
             D
             W
             V
             G
             K1
             A2
             O
             Q
             K2
             X1
             E2
             O1
             G2
             I2
             A1
             Z
             H
             D1
             v_64
             D2
             M1
             T
             B
             H2
             H1
             S
             F2
             J1
             V1
             L1
             S1
             B1
             X
             U1
             N1
             W1
             C1
             N
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main111 Z1
             A2
             B2
             J2
             V1
             F1
             V
             C
             P1
             O
             I2
             J1
             G1
             B
             R
             J
             E2
             Q
             U1
             L
             A1
             Y
             G
             A
             O1
             W1
             F
             X
             H2
             M
             I
             M1
             T1
             Y1
             D1
             C2
             G2
             I1
             N
             C1
             R1
             H1
             N1
             X1
             W
             D2
             E1
             E
             B1
             S
             K1
             L1
             T
             K
             F2
             H
             K2
             D
             U
             Z
             P
             Q1)
        (and (not (= F1 8464))
     (not (= F1 8465))
     (not (= F1 8466))
     (= F1 8496)
     (not (= F1 12292))
     (not (= F1 16384))
     (not (= F1 8192))
     (not (= F1 24576))
     (not (= F1 8195))
     (not (= F1 8480))
     (not (= F1 8481))
     (not (= F1 8482))
     (<= 0 G2)
     (<= 0 C2)
     (<= 0 Q1)
     (<= 0 D1)
     (<= 0 Z)
     (<= 0 U)
     (<= 0 D)
     (<= 0 K2)
     (not (= F2 1))
     (= v_63 F1))
      )
      (inv_main265 Z1
             A2
             B2
             J2
             V1
             F1
             V
             C
             P1
             O
             I2
             J1
             G1
             B
             R
             J
             E2
             Q
             U1
             L
             A1
             Y
             G
             A
             O1
             W1
             F
             X
             H2
             M
             I
             M1
             T1
             Y1
             D1
             C2
             G2
             I1
             N
             S1
             R1
             v_63
             N1
             X1
             W
             D2
             E1
             E
             B1
             S
             K1
             L1
             T
             K
             F2
             H
             K2
             D
             U
             Z
             P
             Q1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main111 J2
             O1
             D2
             B1
             F2
             A1
             I1
             K1
             J
             O
             L2
             B
             U1
             R
             B2
             Q1
             D
             I2
             C2
             N1
             X
             E1
             W1
             K
             C1
             F1
             Y
             V
             A2
             F
             Z
             N
             L
             P1
             J1
             R1
             Y1
             U
             P
             S
             T
             A
             H1
             I
             G
             M
             K2
             S1
             E
             G1
             Z1
             X1
             H2
             W
             T1
             D1
             H
             C
             M1
             L1
             Q
             V1)
        (and (= T1 1)
     (not (= A1 8464))
     (not (= A1 8465))
     (not (= A1 8466))
     (not (= A1 8496))
     (= A1 8497)
     (not (= A1 12292))
     (not (= A1 16384))
     (not (= A1 8192))
     (not (= A1 24576))
     (not (= A1 8195))
     (not (= A1 8480))
     (not (= A1 8481))
     (not (= A1 8482))
     (<= 0 Y1)
     (<= 0 V1)
     (<= 0 R1)
     (<= 0 M1)
     (<= 0 L1)
     (<= 0 J1)
     (<= 0 H)
     (<= 0 C)
     (= G2 2)
     (= v_64 A1))
      )
      (inv_main265 J2
             O1
             D2
             B1
             F2
             A1
             I1
             K1
             J
             O
             L2
             B
             U1
             R
             B2
             Q1
             D
             I2
             C2
             N1
             X
             E1
             W1
             K
             C1
             F1
             Y
             V
             A2
             F
             Z
             N
             L
             P1
             J1
             R1
             Y1
             U
             P
             E2
             T
             v_64
             H1
             I
             G
             M
             K2
             S1
             E
             G1
             Z1
             X1
             H2
             W
             G2
             D1
             H
             C
             M1
             L1
             Q
             V1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main111 Z
             O
             C
             A2
             I
             M
             Q1
             J1
             B
             W1
             O1
             W
             Y1
             S
             U
             Z1
             I2
             G2
             L
             V
             H2
             K
             H1
             A1
             V1
             E
             H
             Q
             U1
             K2
             E2
             X1
             N1
             C2
             N
             F
             J2
             D1
             P1
             A
             E1
             P
             B2
             G
             C1
             L1
             B1
             G1
             F2
             K1
             D2
             T
             R
             R1
             S1
             J
             I1
             D
             T1
             X
             F1
             Y)
        (and (not (= M 8464))
     (not (= M 8465))
     (not (= M 8466))
     (not (= M 8496))
     (= M 8497)
     (not (= M 12292))
     (not (= M 16384))
     (not (= M 8192))
     (not (= M 24576))
     (not (= M 8195))
     (not (= M 8480))
     (not (= M 8481))
     (not (= M 8482))
     (<= 0 T1)
     (<= 0 I1)
     (<= 0 Y)
     (<= 0 X)
     (<= 0 N)
     (<= 0 F)
     (<= 0 D)
     (<= 0 J2)
     (not (= S1 1))
     (= v_63 M))
      )
      (inv_main265 Z
             O
             C
             A2
             I
             M
             Q1
             J1
             B
             W1
             O1
             W
             Y1
             S
             U
             Z1
             I2
             G2
             L
             V
             H2
             K
             H1
             A1
             V1
             E
             H
             Q
             U1
             K2
             E2
             X1
             N1
             C2
             N
             F
             J2
             D1
             P1
             M1
             E1
             v_63
             B2
             G
             C1
             L1
             B1
             G1
             F2
             K1
             D2
             T
             R
             R1
             S1
             J
             I1
             D
             T1
             X
             F1
             Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main111 G
             F
             W
             C1
             D2
             L1
             T
             K1
             O1
             C
             B1
             J1
             S1
             L
             E2
             X1
             D
             Z
             E
             E1
             C2
             I2
             H
             A
             V1
             H2
             X
             N
             G2
             Y
             A2
             P
             J
             R1
             L2
             V
             K2
             S
             I
             Z1
             N1
             Y1
             R
             W1
             A1
             J2
             M1
             O
             U1
             B
             F2
             I1
             H1
             D1
             P1
             Q
             U
             M
             G1
             K
             F1
             B2)
        (and (= P1 3)
     (not (= L1 8609))
     (= L1 8640)
     (not (= L1 8593))
     (not (= L1 8608))
     (not (= L1 8577))
     (not (= L1 8592))
     (not (= L1 8561))
     (not (= L1 8576))
     (not (= L1 8464))
     (not (= L1 8465))
     (not (= L1 8466))
     (not (= L1 8496))
     (not (= L1 8497))
     (not (= L1 8512))
     (not (= L1 8513))
     (not (= L1 8528))
     (not (= L1 8529))
     (not (= L1 8544))
     (not (= L1 8545))
     (not (= L1 8560))
     (not (= L1 8448))
     (not (= L1 12292))
     (not (= L1 16384))
     (not (= L1 8192))
     (not (= L1 24576))
     (not (= L1 8195))
     (not (= L1 8480))
     (not (= L1 8481))
     (not (= L1 8482))
     (<= 0 B2)
     (<= 0 G1)
     (<= 0 V)
     (<= 0 U)
     (<= 0 M)
     (<= 0 K)
     (<= 0 L2)
     (<= 0 K2)
     (= Q1 4)
     (= v_64 L1))
      )
      (inv_main412 G
             F
             W
             C1
             D2
             L1
             T
             K1
             O1
             C
             B1
             J1
             S1
             L
             E2
             X1
             D
             Z
             E
             E1
             C2
             I2
             H
             A
             V1
             H2
             X
             N
             G2
             Y
             A2
             P
             J
             R1
             L2
             V
             K2
             S
             I
             T1
             N1
             v_64
             R
             W1
             A1
             J2
             M1
             O
             U1
             B
             F2
             I1
             H1
             D1
             Q1
             Q
             U
             M
             G1
             K
             F1
             B2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main111 X
             F1
             P
             W1
             K1
             J2
             M1
             L
             O1
             P1
             Z
             D2
             H1
             J
             C1
             C2
             C
             S
             U
             I
             U1
             Q
             B
             O
             J1
             T1
             L1
             M
             Q1
             Y
             Z1
             V1
             H
             D
             F2
             W
             D1
             N
             B1
             A2
             R
             G1
             Y1
             K2
             H2
             E
             K
             I2
             G2
             I1
             F
             E2
             A1
             R1
             E1
             B2
             X1
             G
             V
             A
             N1
             T)
        (and (not (= J2 8609))
     (= J2 8640)
     (not (= J2 8593))
     (not (= J2 8608))
     (not (= J2 8577))
     (not (= J2 8592))
     (not (= J2 8561))
     (not (= J2 8576))
     (not (= J2 8464))
     (not (= J2 8465))
     (not (= J2 8466))
     (not (= J2 8496))
     (not (= J2 8497))
     (not (= J2 8512))
     (not (= J2 8513))
     (not (= J2 8528))
     (not (= J2 8529))
     (not (= J2 8544))
     (not (= J2 8545))
     (not (= J2 8560))
     (not (= J2 8448))
     (not (= J2 12292))
     (not (= J2 16384))
     (not (= J2 8192))
     (not (= J2 24576))
     (not (= J2 8195))
     (not (= J2 8480))
     (not (= J2 8481))
     (not (= J2 8482))
     (<= 0 A)
     (<= 0 F2)
     (<= 0 X1)
     (<= 0 D1)
     (<= 0 W)
     (<= 0 V)
     (<= 0 T)
     (<= 0 G)
     (not (= E1 3))
     (= v_63 J2))
      )
      (inv_main412 X
             F1
             P
             W1
             K1
             J2
             M1
             L
             O1
             P1
             Z
             D2
             H1
             J
             C1
             C2
             C
             S
             U
             I
             U1
             Q
             B
             O
             J1
             T1
             L1
             M
             Q1
             Y
             Z1
             V1
             H
             D
             F2
             W
             D1
             N
             B1
             S1
             R
             v_63
             Y1
             K2
             H2
             E
             K
             I2
             G2
             I1
             F
             E2
             A1
             R1
             E1
             B2
             X1
             G
             V
             A
             N1
             T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main111 Q
             P1
             W
             V1
             A
             K2
             T1
             Q1
             Z1
             C2
             F
             J
             O1
             L1
             I2
             E
             E2
             E1
             D
             S
             M
             B1
             G
             P
             W1
             U1
             B2
             S1
             D2
             A2
             N
             K1
             J2
             Y1
             L2
             I
             R1
             O
             K
             G1
             N1
             X1
             H2
             R
             Y
             F2
             C
             A1
             V
             G2
             Z
             B
             U
             H1
             L
             J1
             M1
             H
             I1
             C1
             T
             D1)
        (and (= L 3)
     (= K2 8641)
     (not (= K2 8609))
     (not (= K2 8640))
     (not (= K2 8593))
     (not (= K2 8608))
     (not (= K2 8577))
     (not (= K2 8592))
     (not (= K2 8561))
     (not (= K2 8576))
     (not (= K2 8464))
     (not (= K2 8465))
     (not (= K2 8466))
     (not (= K2 8496))
     (not (= K2 8497))
     (not (= K2 8512))
     (not (= K2 8513))
     (not (= K2 8528))
     (not (= K2 8529))
     (not (= K2 8544))
     (not (= K2 8545))
     (not (= K2 8560))
     (not (= K2 8448))
     (not (= K2 12292))
     (not (= K2 16384))
     (not (= K2 8192))
     (not (= K2 24576))
     (not (= K2 8195))
     (not (= K2 8480))
     (not (= K2 8481))
     (not (= K2 8482))
     (<= 0 R1)
     (<= 0 M1)
     (<= 0 I1)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 I)
     (<= 0 H)
     (<= 0 L2)
     (= X 4)
     (= v_64 K2))
      )
      (inv_main412 Q
             P1
             W
             V1
             A
             K2
             T1
             Q1
             Z1
             C2
             F
             J
             O1
             L1
             I2
             E
             E2
             E1
             D
             S
             M
             B1
             G
             P
             W1
             U1
             B2
             S1
             D2
             A2
             N
             K1
             J2
             Y1
             L2
             I
             R1
             O
             K
             F1
             N1
             v_64
             H2
             R
             Y
             F2
             C
             A1
             V
             G2
             Z
             B
             U
             H1
             X
             J1
             M1
             H
             I1
             C1
             T
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main111 K2
             F2
             C2
             Y
             J2
             J
             X1
             Q
             S
             H1
             B
             P1
             K1
             M1
             B1
             P
             M
             T1
             F1
             C1
             D
             B2
             H2
             E2
             W1
             E1
             H
             R1
             Z
             O
             Q1
             N
             G
             I
             W
             S1
             F
             O1
             K
             A2
             V1
             G1
             R
             X
             N1
             U1
             C
             L
             A1
             V
             U
             Y1
             J1
             I2
             A
             D1
             T
             G2
             Z1
             L1
             E
             D2)
        (and (= J 8641)
     (not (= J 8609))
     (not (= J 8640))
     (not (= J 8593))
     (not (= J 8608))
     (not (= J 8577))
     (not (= J 8592))
     (not (= J 8561))
     (not (= J 8576))
     (not (= J 8464))
     (not (= J 8465))
     (not (= J 8466))
     (not (= J 8496))
     (not (= J 8497))
     (not (= J 8512))
     (not (= J 8513))
     (not (= J 8528))
     (not (= J 8529))
     (not (= J 8544))
     (not (= J 8545))
     (not (= J 8560))
     (not (= J 8448))
     (not (= J 12292))
     (not (= J 16384))
     (not (= J 8192))
     (not (= J 24576))
     (not (= J 8195))
     (not (= J 8480))
     (not (= J 8481))
     (not (= J 8482))
     (<= 0 G2)
     (<= 0 D2)
     (<= 0 Z1)
     (<= 0 S1)
     (<= 0 L1)
     (<= 0 W)
     (<= 0 T)
     (<= 0 F)
     (not (= A 3))
     (= v_63 J))
      )
      (inv_main412 K2
             F2
             C2
             Y
             J2
             J
             X1
             Q
             S
             H1
             B
             P1
             K1
             M1
             B1
             P
             M
             T1
             F1
             C1
             D
             B2
             H2
             E2
             W1
             E1
             H
             R1
             Z
             O
             Q1
             N
             G
             I
             W
             S1
             F
             O1
             K
             I1
             V1
             v_63
             R
             X
             N1
             U1
             C
             L
             A1
             V
             U
             Y1
             J1
             I2
             A
             D1
             T
             G2
             Z1
             L1
             E
             D2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main192 D2
             N1
             F1
             B2
             X
             K2
             O
             J1
             U
             A2
             S
             Z1
             U1
             W1
             M1
             H
             Z
             E2
             L
             R
             V1
             N
             X1
             A
             O1
             I1
             Q1
             T1
             M
             W
             L1
             H1
             F
             R1
             H2
             C2
             I
             B1
             J
             G
             C
             E1
             Y
             A1
             E
             P1
             F2
             I2
             B
             V
             K1
             G1
             Y1
             T
             C1
             J2
             Q
             P
             S1
             D1
             K
             D)
        (and (not (= Q1 0))
     (<= 0 H2)
     (<= 0 C2)
     (<= 0 S1)
     (<= 0 D1)
     (<= 0 Q)
     (<= 0 P)
     (<= 0 I)
     (<= 0 D)
     (= G2 0))
      )
      (inv_main111 D2
             N1
             F1
             B2
             X
             K2
             O
             J1
             U
             A2
             S
             Z1
             U1
             W1
             M1
             H
             Z
             E2
             L
             R
             V1
             N
             X1
             A
             O1
             I1
             Q1
             T1
             M
             W
             L1
             H1
             F
             R1
             H2
             C2
             I
             B1
             J
             G
             C
             E1
             G2
             A1
             E
             P1
             F2
             I2
             B
             V
             K1
             G1
             Y1
             T
             C1
             J2
             Q
             P
             S1
             D1
             K
             D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main192 P1
             B1
             O
             W1
             R1
             J1
             C
             T1
             E
             S
             D
             V
             N
             V1
             I
             P
             L1
             I2
             J2
             Q1
             M
             W
             O1
             J
             B2
             N1
             H1
             H2
             S1
             Z
             A
             R
             U1
             G2
             H
             B
             M1
             F
             E2
             C1
             C2
             U
             D2
             Q
             E1
             Y1
             A2
             F1
             A1
             K1
             T
             X
             D1
             F2
             G1
             G
             K2
             L
             X1
             K
             I1
             Z1)
        (and (= H1 0)
     (= Y 0)
     (<= 0 Z1)
     (<= 0 X1)
     (<= 0 M1)
     (<= 0 L)
     (<= 0 K)
     (<= 0 H)
     (<= 0 B)
     (<= 0 K2)
     (not (= D2 0)))
      )
      (inv_main111 P1
             B1
             O
             W1
             R1
             J1
             C
             T1
             E
             S
             D
             V
             N
             V1
             I
             P
             L1
             I2
             J2
             Q1
             M
             W
             O1
             J
             B2
             N1
             H1
             H2
             S1
             Z
             A
             R
             U1
             G2
             H
             B
             M1
             F
             E2
             C1
             C2
             U
             Y
             Q
             E1
             Y1
             A2
             F1
             A1
             K1
             T
             X
             D1
             F2
             G1
             G
             K2
             L
             X1
             K
             I1
             Z1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main482 Y1
             U
             O
             C2
             P
             T
             J1
             I2
             M
             H
             G
             H1
             L
             D2
             M1
             S1
             W1
             B
             X1
             R
             K2
             G2
             I
             F2
             B2
             D
             E1
             V
             Y
             Z
             L1
             S
             K
             X
             R1
             Q1
             U1
             G1
             V1
             F
             A2
             D1
             N1
             P1
             A1
             A
             N
             C
             E2
             H2
             I1
             K1
             Z1
             W
             E
             O1
             C1
             B1
             J2
             J
             Q
             T1)
        (and (= F1 0)
     (<= 0 U1)
     (<= 0 T1)
     (<= 0 R1)
     (<= 0 Q1)
     (<= 0 C1)
     (<= 0 B1)
     (<= 0 J)
     (<= 0 J2)
     (= G1 0))
      )
      (inv_main111 Y1
             U
             O
             C2
             P
             T
             J1
             I2
             M
             H
             G
             H1
             L
             D2
             M1
             S1
             W1
             B
             X1
             R
             K2
             G2
             I
             F2
             B2
             D
             E1
             V
             Y
             Z
             L1
             S
             K
             X
             R1
             Q1
             U1
             G1
             V1
             F
             A2
             D1
             F1
             P1
             A1
             A
             N
             C
             E2
             H2
             I1
             K1
             Z1
             W
             E
             O1
             C1
             B1
             J2
             J
             Q
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main482 C2
             S
             A2
             F2
             I
             P
             K2
             V
             Q
             X1
             C1
             H
             L
             B
             V1
             E2
             K1
             R
             H1
             J2
             S1
             J1
             R1
             T1
             E
             H2
             I1
             O
             D
             L1
             G
             K
             D1
             Q1
             E1
             U
             O1
             A1
             W1
             T
             B2
             A
             U1
             F
             I2
             D2
             N
             X
             Z1
             J
             N1
             F1
             G1
             Y
             C
             P1
             Y1
             M
             W
             G2
             M1
             Z)
        (and (not (= A1 0))
     (= P A)
     (<= 0 G2)
     (<= 0 Y1)
     (<= 0 O1)
     (<= 0 E1)
     (<= 0 Z)
     (<= 0 W)
     (<= 0 U)
     (<= 0 M)
     (= B1 0))
      )
      (inv_main111 C2
             S
             A2
             F2
             I
             P
             K2
             V
             Q
             X1
             C1
             H
             L
             B
             V1
             E2
             K1
             R
             H1
             J2
             S1
             J1
             R1
             T1
             E
             H2
             I1
             O
             D
             L1
             G
             K
             D1
             Q1
             E1
             U
             O1
             A1
             W1
             T
             B2
             A
             B1
             F
             I2
             D2
             N
             X
             Z1
             J
             N1
             F1
             G1
             Y
             C
             P1
             Y1
             M
             W
             G2
             M1
             Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main482 G2
             Q1
             E
             Z1
             S
             T
             D
             Y1
             E1
             F2
             U1
             W
             R1
             I2
             V1
             T1
             C
             H
             J1
             F
             P1
             B1
             J
             S1
             H1
             D1
             V
             A2
             E2
             L1
             Q
             D2
             F1
             Y
             W1
             G1
             Z
             M1
             L
             C2
             O
             I
             P
             X1
             K1
             R
             J2
             K
             O1
             C1
             U
             K2
             M
             X
             B2
             A1
             N
             H2
             G
             N1
             I1
             B)
        (and (not (= M1 0))
     (not (= T I))
     (<= 0 H2)
     (<= 0 W1)
     (<= 0 N1)
     (<= 0 G1)
     (<= 0 Z)
     (<= 0 N)
     (<= 0 G)
     (<= 0 B)
     (= A 0)
     (= v_63 T))
      )
      (inv_main111 G2
             Q1
             E
             Z1
             S
             T
             D
             Y1
             E1
             F2
             U1
             W
             R1
             I2
             V1
             T1
             C
             H
             J1
             F
             P1
             B1
             J
             S1
             H1
             D1
             V
             A2
             E2
             L1
             Q
             D2
             F1
             Y
             W1
             G1
             Z
             M1
             L
             C2
             v_63
             I
             A
             X1
             K1
             R
             J2
             K
             O1
             C1
             U
             K2
             M
             X
             B2
             A1
             N
             H2
             G
             N1
             I1
             B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main100 E
             Y
             A2
             F1
             Y1
             F2
             M1
             G
             V1
             T1
             X
             A1
             C2
             J1
             G1
             J2
             H1
             A
             O
             V
             T
             W
             D2
             D
             G2
             B1
             X1
             M
             U1
             I
             F
             P
             P1
             Q1
             U
             Z
             K2
             E1
             L1
             H2
             D1
             B
             L
             Z1
             S1
             O1
             E2
             J
             B2
             I2
             R
             N1
             Q
             S
             W1
             K
             I1
             C
             N
             H
             C1
             K1)
        (and (= R1 (+ 1 Y1))
     (not (= H1 0))
     (<= 0 K1)
     (<= 0 I1)
     (<= 0 Z)
     (<= 0 U)
     (<= 0 N)
     (<= 0 H)
     (<= 0 C)
     (<= 0 K2)
     (= S1 (- 12288)))
      )
      (inv_main111 E
             Y
             A2
             F1
             R1
             F2
             M1
             G
             V1
             T1
             X
             A1
             C2
             J1
             G1
             J2
             H1
             A
             O
             V
             T
             W
             D2
             D
             G2
             B1
             X1
             M
             U1
             I
             F
             P
             P1
             Q1
             U
             Z
             K2
             E1
             L1
             H2
             D1
             B
             L
             Z1
             S1
             O1
             E2
             J
             B2
             I2
             R
             N1
             Q
             S
             W1
             K
             I1
             C
             N
             H
             C1
             K1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main100 V1
             U1
             Y1
             W1
             O
             S1
             A1
             T
             E1
             K
             G1
             B1
             P
             Q
             F1
             R
             Q1
             F2
             B2
             E2
             L
             K2
             J1
             M
             L1
             T1
             H1
             C
             D1
             R1
             G
             F
             X
             K1
             P1
             W
             J2
             G2
             Y
             M1
             E
             U
             I2
             C2
             O1
             H2
             I1
             N
             N1
             D2
             Z1
             X1
             A
             H
             J
             A2
             D
             B
             V
             C1
             S
             I)
        (and (not (= Q1 0))
     (not (= O1 (- 12288)))
     (= Z (+ 1 O))
     (<= 0 P1)
     (<= 0 C1)
     (<= 0 W)
     (<= 0 V)
     (<= 0 I)
     (<= 0 D)
     (<= 0 B)
     (<= 0 J2)
     (not (= H2 (- 16384))))
      )
      (inv_main111 V1
             U1
             Y1
             W1
             Z
             S1
             A1
             T
             E1
             K
             G1
             B1
             P
             Q
             F1
             R
             Q1
             F2
             B2
             E2
             L
             K2
             J1
             M
             L1
             T1
             H1
             C
             D1
             R1
             G
             F
             X
             K1
             P1
             W
             J2
             G2
             Y
             M1
             E
             U
             I2
             C2
             O1
             H2
             I1
             N
             N1
             D2
             Z1
             X1
             A
             H
             J
             A2
             D
             B
             V
             C1
             S
             I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main100 S
             E1
             K2
             U1
             J
             O1
             F2
             Y1
             L
             T1
             C
             H
             V
             W
             H1
             A1
             Z1
             Y
             J1
             J2
             Z
             R1
             D
             N
             K1
             N1
             G2
             F1
             V1
             S1
             B2
             E
             U
             R
             D1
             I2
             H2
             Q1
             G
             M
             Q
             X1
             B
             F
             I
             G1
             C2
             W1
             E2
             L1
             O
             M1
             P1
             T
             X
             A
             D2
             C1
             A2
             I1
             K
             P)
        (and (= G1 (- 16384))
     (= B1 (+ 1 J))
     (not (= I (- 12288)))
     (<= 0 I2)
     (<= 0 H2)
     (<= 0 D2)
     (<= 0 A2)
     (<= 0 I1)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 P)
     (not (= Z1 0)))
      )
      (inv_main111 S
             E1
             K2
             U1
             B1
             O1
             F2
             Y1
             L
             T1
             C
             H
             V
             W
             H1
             A1
             Z1
             Y
             J1
             J2
             Z
             R1
             D
             N
             K1
             N1
             G2
             F1
             V1
             S1
             B2
             E
             U
             R
             D1
             I2
             H2
             Q1
             G
             M
             Q
             X1
             B
             F
             I
             G1
             C2
             W1
             E2
             L1
             O
             M1
             P1
             T
             X
             A
             D2
             C1
             A2
             I1
             K
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main111 G
             P1
             I1
             T1
             Y
             P
             G2
             B1
             C2
             H2
             O
             F
             O1
             G1
             J1
             K
             A
             E1
             E2
             N
             X
             H
             M
             K1
             T
             R1
             L1
             Z1
             E
             A1
             F1
             Z
             N1
             S
             R
             B2
             J2
             H1
             D
             Y1
             C1
             X1
             M1
             D1
             Q
             A2
             V
             W
             C
             I2
             D2
             F2
             V1
             U1
             S1
             U
             B
             W1
             J
             I
             Q1
             L)
        (and (not (= P 8465))
     (not (= P 8466))
     (not (= P 8496))
     (not (= P 8497))
     (not (= P 8512))
     (not (= P 8513))
     (not (= P 8528))
     (not (= P 8529))
     (= P 8544)
     (not (= P 12292))
     (not (= P 16384))
     (not (= P 8192))
     (not (= P 24576))
     (not (= P 8195))
     (not (= P 8480))
     (not (= P 8481))
     (not (= P 8482))
     (<= 0 B2)
     (<= 0 W1)
     (<= 0 R)
     (<= 0 L)
     (<= 0 J)
     (<= 0 I)
     (<= 0 B)
     (<= 0 J2)
     (not (= P 8464))
     (= v_62 P))
      )
      (inv_main323 G
             P1
             I1
             T1
             Y
             P
             G2
             B1
             C2
             H2
             O
             F
             O1
             G1
             J1
             K
             A
             E1
             E2
             N
             X
             H
             M
             K1
             T
             R1
             L1
             Z1
             E
             A1
             F1
             Z
             N1
             S
             R
             B2
             J2
             H1
             D
             Y1
             C1
             v_62
             M1
             D1
             Q
             A2
             V
             W
             C
             I2
             D2
             F2
             V1
             U1
             S1
             U
             B
             W1
             J
             I
             Q1
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main111 V1
             M
             N1
             J
             K
             G2
             F2
             H
             W1
             L
             A
             E1
             O1
             D2
             A1
             D1
             H1
             B
             F
             M1
             O
             E
             R
             D
             T
             G1
             E2
             I
             C1
             N
             S1
             R1
             U
             W
             B1
             T1
             X1
             X
             A2
             J1
             Z
             Z1
             Y1
             Q
             Q1
             S
             C2
             Y
             J2
             I2
             V
             U1
             F1
             I1
             B2
             P1
             L1
             C
             K1
             H2
             G
             P)
        (and (not (= G2 8465))
     (not (= G2 8466))
     (not (= G2 8496))
     (not (= G2 8497))
     (not (= G2 8512))
     (not (= G2 8513))
     (not (= G2 8528))
     (not (= G2 8529))
     (not (= G2 8544))
     (= G2 8545)
     (not (= G2 12292))
     (not (= G2 16384))
     (not (= G2 8192))
     (not (= G2 24576))
     (not (= G2 8195))
     (not (= G2 8480))
     (not (= G2 8481))
     (not (= G2 8482))
     (<= 0 H2)
     (<= 0 X1)
     (<= 0 T1)
     (<= 0 L1)
     (<= 0 K1)
     (<= 0 B1)
     (<= 0 P)
     (<= 0 C)
     (not (= G2 8464))
     (= v_62 G2))
      )
      (inv_main323 V1
             M
             N1
             J
             K
             G2
             F2
             H
             W1
             L
             A
             E1
             O1
             D2
             A1
             D1
             H1
             B
             F
             M1
             O
             E
             R
             D
             T
             G1
             E2
             I
             C1
             N
             S1
             R1
             U
             W
             B1
             T1
             X1
             X
             A2
             J1
             Z
             v_62
             Y1
             Q
             Q1
             S
             C2
             Y
             J2
             I2
             V
             U1
             F1
             I1
             B2
             P1
             L1
             C
             K1
             H2
             G
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main499 E1
             Y
             O1
             U1
             F1
             M
             N1
             F2
             A
             L
             J1
             Q1
             R
             I
             P
             S
             A2
             O
             Q
             R1
             G2
             K
             C1
             T1
             K1
             G
             N
             G1
             U
             M1
             D2
             D
             X
             B
             E
             A1
             P1
             H2
             F
             C
             J2
             C2
             W1
             Z1
             J
             B2
             H
             B1
             T
             Y1
             W
             I2
             L1
             E2
             I1
             Z
             H1
             S1
             V
             X1
             V1
             D1)
        (and (<= 0 S1)
     (<= 0 P1)
     (<= 0 H1)
     (<= 0 D1)
     (<= 0 A1)
     (<= 0 V)
     (<= 0 E)
     (<= 0 X1))
      )
      false
    )
  )
)

(check-sat)
(exit)
