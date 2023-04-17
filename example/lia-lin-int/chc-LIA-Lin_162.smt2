; ./tricera/sv-comp-2020/./mixed/s3_srvr_4.cil.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main327| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main254| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main333| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main422| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main494| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main198| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main271| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main117| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main445| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main297| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main477| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main4| ( Int Int ) Bool)
(declare-fun |inv_main106| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

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
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 U1
             D1
             P1
             S1
             S
             R1
             A1
             C2
             E2
             Q1
             K1
             F2
             E1
             J1
             R
             X
             G
             T1
             N1
             C
             B
             B2
             F1
             A
             C1
             A2
             N
             L
             V
             K
             V1
             Z
             I1
             J2
             G1
             W
             L1
             Y
             O1
             X1
             J
             Z1
             I
             E
             Y1
             G2
             I2
             O
             Q
             P
             H1
             W1
             H2
             B1
             M1
             D
             H
             D2
             U
             T
             F
             M)
        (and (not (= R1 16384))
     (not (= R1 8192))
     (not (= R1 24576))
     (not (= R1 8195))
     (not (= R1 8480))
     (not (= R1 8481))
     (not (= R1 8482))
     (not (= R1 8464))
     (not (= R1 8465))
     (not (= R1 8466))
     (not (= R1 8496))
     (not (= R1 8497))
     (not (= R1 8512))
     (not (= R1 8513))
     (not (= R1 8528))
     (not (= R1 8529))
     (= R1 8544)
     (<= 0 D2)
     (<= 0 L1)
     (<= 0 G1)
     (<= 0 W)
     (<= 0 U)
     (<= 0 T)
     (<= 0 M)
     (<= 0 H)
     (not (= R1 12292))
     (= v_62 R1))
      )
      (inv_main327 U1
             D1
             P1
             S1
             S
             R1
             A1
             C2
             E2
             Q1
             K1
             F2
             E1
             J1
             R
             X
             G
             T1
             N1
             C
             B
             B2
             F1
             A
             C1
             A2
             N
             L
             V
             K
             V1
             Z
             I1
             J2
             G1
             W
             L1
             Y
             O1
             X1
             J
             v_62
             I
             E
             Y1
             G2
             I2
             O
             Q
             P
             H1
             W1
             H2
             B1
             M1
             D
             H
             D2
             U
             T
             F
             M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 H2
             G1
             N1
             L1
             U
             G2
             E
             C2
             I
             X1
             L
             J2
             Y1
             T
             U1
             M
             J
             P
             W
             D1
             R1
             G
             W1
             I1
             E1
             J1
             Z
             S
             F
             F2
             H1
             Q
             O
             X
             I2
             D2
             F1
             R
             A
             B1
             N
             A2
             C
             B
             B2
             V1
             O1
             V
             M1
             Y
             K
             C1
             K1
             T1
             D
             Z1
             H
             P1
             S1
             Q1
             E2
             A1)
        (and (not (= G2 12292))
     (not (= G2 16384))
     (not (= G2 8192))
     (not (= G2 24576))
     (not (= G2 8195))
     (not (= G2 8480))
     (not (= G2 8481))
     (not (= G2 8482))
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
     (<= 0 D2)
     (<= 0 S1)
     (<= 0 Q1)
     (<= 0 P1)
     (<= 0 F1)
     (<= 0 A1)
     (<= 0 H)
     (<= 0 I2)
     (= G2 8545)
     (= v_62 G2))
      )
      (inv_main327 H2
             G1
             N1
             L1
             U
             G2
             E
             C2
             I
             X1
             L
             J2
             Y1
             T
             U1
             M
             J
             P
             W
             D1
             R1
             G
             W1
             I1
             E1
             J1
             Z
             S
             F
             F2
             H1
             Q
             O
             X
             I2
             D2
             F1
             R
             A
             B1
             N
             v_62
             C
             B
             B2
             V1
             O1
             V
             M1
             Y
             K
             C1
             K1
             T1
             D
             Z1
             H
             P1
             S1
             Q1
             E2
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main198 I1
             Y1
             L
             I
             V1
             A1
             P1
             G
             J2
             I2
             N1
             V
             M
             L1
             E
             O
             T
             R1
             J1
             C2
             X1
             D
             A2
             R
             G1
             B2
             Z
             K
             F
             K1
             Y
             E2
             Q
             U1
             X
             U
             B1
             H
             C
             O1
             E1
             C1
             F1
             A
             D2
             M1
             Q1
             K2
             N
             S1
             F2
             Z1
             S
             P
             W
             D1
             B
             T1
             W1
             H2
             J
             G2)
        (and (not (= Z 0))
     (<= 0 H2)
     (<= 0 G2)
     (<= 0 W1)
     (<= 0 T1)
     (<= 0 B1)
     (<= 0 X)
     (<= 0 U)
     (<= 0 B)
     (= H1 0))
      )
      (inv_main117 I1
             Y1
             L
             I
             V1
             A1
             P1
             G
             J2
             I2
             N1
             V
             M
             L1
             E
             O
             T
             R1
             J1
             C2
             X1
             D
             A2
             R
             G1
             B2
             Z
             K
             F
             K1
             Y
             E2
             Q
             U1
             X
             U
             B1
             H
             C
             O1
             E1
             C1
             H1
             A
             D2
             M1
             Q1
             K2
             N
             S1
             F2
             Z1
             S
             P
             W
             D1
             B
             T1
             W1
             H2
             J
             G2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main198 Q
             O1
             K1
             E2
             C
             N
             K
             W1
             N1
             P
             B2
             J
             R1
             I
             G
             L1
             T1
             Y1
             F
             A2
             R
             H
             M
             D1
             G2
             H2
             I1
             Z
             S1
             O
             Q1
             D
             V
             B1
             U1
             C2
             F1
             J1
             D2
             B
             E
             U
             A1
             H1
             T
             A
             F2
             C1
             L
             W
             K2
             I2
             G1
             Y
             X1
             V1
             X
             P1
             M1
             Z1
             J2
             E1)
        (and (not (= A1 0))
     (= S 0)
     (<= 0 C2)
     (<= 0 Z1)
     (<= 0 U1)
     (<= 0 P1)
     (<= 0 M1)
     (<= 0 F1)
     (<= 0 E1)
     (<= 0 X)
     (= I1 0))
      )
      (inv_main117 Q
             O1
             K1
             E2
             C
             N
             K
             W1
             N1
             P
             B2
             J
             R1
             I
             G
             L1
             T1
             Y1
             F
             A2
             R
             H
             M
             D1
             G2
             H2
             I1
             Z
             S1
             O
             Q1
             D
             V
             B1
             U1
             C2
             F1
             J1
             D2
             B
             E
             U
             S
             H1
             T
             A
             F2
             C1
             L
             W
             K2
             I2
             G1
             Y
             X1
             V1
             X
             P1
             M1
             Z1
             J2
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main477 R1
             Y1
             A1
             H1
             I2
             G2
             F
             I
             B
             F2
             D1
             K1
             P
             G1
             Z
             H
             M
             C1
             Y
             E2
             L1
             Z1
             X
             Q1
             O
             W
             P1
             V1
             V
             C2
             B1
             W1
             K
             A
             M1
             J1
             L
             S1
             G
             C
             H2
             S
             E
             D
             E1
             U1
             J2
             A2
             O1
             I1
             N1
             J
             T
             N
             R
             T1
             F1
             B2
             D2
             K2
             U
             X1)
        (and (= Q 0)
     (<= 0 D2)
     (<= 0 B2)
     (<= 0 X1)
     (<= 0 M1)
     (<= 0 J1)
     (<= 0 F1)
     (<= 0 L)
     (<= 0 K2)
     (= S1 0))
      )
      (inv_main117 R1
             Y1
             A1
             H1
             I2
             G2
             F
             I
             B
             F2
             D1
             K1
             P
             G1
             Z
             H
             M
             C1
             Y
             E2
             L1
             Z1
             X
             Q1
             O
             W
             P1
             V1
             V
             C2
             B1
             W1
             K
             A
             M1
             J1
             L
             S1
             G
             C
             H2
             S
             Q
             D
             E1
             U1
             J2
             A2
             O1
             I1
             N1
             J
             T
             N
             R
             T1
             F1
             B2
             D2
             K2
             U
             X1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main477 V
             U
             Z1
             C1
             A2
             J
             H
             S
             P
             I1
             D1
             L1
             C
             K2
             E
             T
             V1
             L
             O
             R
             Q
             J2
             F1
             K
             U1
             N1
             R1
             X
             P1
             X1
             M1
             F
             I2
             F2
             N
             H2
             H1
             Z
             Q1
             T1
             C2
             G
             B1
             M
             A
             S1
             G2
             B
             D
             I
             Y1
             Y
             E1
             E2
             B2
             W1
             D2
             J1
             O1
             G1
             A1
             W)
        (and (not (= Z 0))
     (= J G)
     (<= 0 H2)
     (<= 0 D2)
     (<= 0 O1)
     (<= 0 J1)
     (<= 0 H1)
     (<= 0 G1)
     (<= 0 W)
     (<= 0 N)
     (= K1 0))
      )
      (inv_main117 V
             U
             Z1
             C1
             A2
             J
             H
             S
             P
             I1
             D1
             L1
             C
             K2
             E
             T
             V1
             L
             O
             R
             Q
             J2
             F1
             K
             U1
             N1
             R1
             X
             P1
             X1
             M1
             F
             I2
             F2
             N
             H2
             H1
             Z
             Q1
             T1
             C2
             G
             K1
             M
             A
             S1
             G2
             B
             D
             I
             Y1
             Y
             E1
             E2
             B2
             W1
             D2
             J1
             O1
             G1
             A1
             W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main477 B
             G1
             C
             S1
             W1
             J2
             C2
             J1
             A1
             L
             K
             Z1
             D1
             E1
             O
             Y
             Z
             K2
             I1
             G2
             S
             Y1
             P1
             M
             U1
             N
             T
             X
             I
             E2
             M1
             V1
             U
             F2
             H2
             K1
             G
             A2
             W
             Q
             F
             H1
             A
             F1
             P
             D2
             E
             I2
             B1
             O1
             L1
             J
             V
             X1
             Q1
             D
             B2
             T1
             C1
             N1
             R
             R1)
        (and (= H 0)
     (not (= J2 H1))
     (<= 0 H2)
     (<= 0 B2)
     (<= 0 T1)
     (<= 0 R1)
     (<= 0 N1)
     (<= 0 K1)
     (<= 0 C1)
     (<= 0 G)
     (not (= A2 0))
     (= v_63 J2))
      )
      (inv_main117 B
             G1
             C
             S1
             W1
             J2
             C2
             J1
             A1
             L
             K
             Z1
             D1
             E1
             O
             Y
             Z
             K2
             I1
             G2
             S
             Y1
             P1
             M
             U1
             N
             T
             X
             I
             E2
             M1
             V1
             U
             F2
             H2
             K1
             G
             A2
             W
             Q
             v_63
             H1
             H
             F1
             P
             D2
             E
             I2
             B1
             O1
             L1
             J
             V
             X1
             Q1
             D
             B2
             T1
             C1
             N1
             R
             R1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main106 V1
             A2
             I2
             W1
             U1
             K
             B1
             R1
             S1
             H1
             B2
             M1
             Y
             N1
             T1
             X1
             K1
             G2
             C1
             S
             G1
             F2
             E2
             I
             J2
             J1
             Q1
             Y1
             I1
             V
             H
             O
             B
             A1
             C2
             O1
             X
             Z1
             Z
             M
             F1
             D
             J
             T
             F
             R
             D2
             P1
             L
             H2
             Q
             A
             P
             E
             C
             L1
             D1
             U
             G
             K2
             W
             E1)
        (and (= N (+ 1 U1))
     (= F (- 12288))
     (<= 0 C2)
     (<= 0 O1)
     (<= 0 E1)
     (<= 0 D1)
     (<= 0 X)
     (<= 0 U)
     (<= 0 G)
     (<= 0 K2)
     (not (= K1 0)))
      )
      (inv_main117 V1
             A2
             I2
             W1
             N
             K
             B1
             R1
             S1
             H1
             B2
             M1
             Y
             N1
             T1
             X1
             K1
             G2
             C1
             S
             G1
             F2
             E2
             I
             J2
             J1
             Q1
             Y1
             I1
             V
             H
             O
             B
             A1
             C2
             O1
             X
             Z1
             Z
             M
             F1
             D
             J
             T
             F
             R
             D2
             P1
             L
             H2
             Q
             A
             P
             E
             C
             L1
             D1
             U
             G
             K2
             W
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main106 X1
             T
             R1
             Z
             U1
             D2
             B2
             I
             C1
             N1
             T1
             Z1
             D1
             A1
             M
             Q
             S
             P
             O1
             C
             F1
             F2
             I2
             Q1
             E1
             L
             G2
             G1
             Y1
             G
             M1
             A
             K
             Y
             K1
             J2
             J
             W
             J1
             H1
             O
             E2
             L1
             W1
             A2
             B1
             S1
             K2
             N
             P1
             H2
             D
             F
             V1
             I1
             H
             X
             C2
             V
             R
             U
             E)
        (and (not (= B1 (- 16384)))
     (not (= S 0))
     (= B (+ 1 U1))
     (<= 0 C2)
     (<= 0 K1)
     (<= 0 X)
     (<= 0 V)
     (<= 0 R)
     (<= 0 J)
     (<= 0 E)
     (<= 0 J2)
     (not (= A2 (- 12288))))
      )
      (inv_main117 X1
             T
             R1
             Z
             B
             D2
             B2
             I
             C1
             N1
             T1
             Z1
             D1
             A1
             M
             Q
             S
             P
             O1
             C
             F1
             F2
             I2
             Q1
             E1
             L
             G2
             G1
             Y1
             G
             M1
             A
             K
             Y
             K1
             J2
             J
             W
             J1
             H1
             O
             E2
             L1
             W1
             A2
             B1
             S1
             K2
             N
             P1
             H2
             D
             F
             V1
             I1
             H
             X
             C2
             V
             R
             U
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main106 Y1
             G
             Y
             V
             E2
             J1
             Z
             F
             D1
             E
             B2
             G2
             R
             M
             Z1
             H
             P1
             M1
             T1
             C2
             B
             U
             L
             X
             K
             G1
             U1
             I
             K2
             D
             S1
             K1
             J2
             N
             S
             C1
             X1
             I1
             F2
             H1
             A2
             H2
             O1
             W1
             D2
             F1
             Q
             V1
             A
             B1
             P
             A1
             I2
             R1
             Q1
             W
             O
             J
             E1
             L1
             T
             C)
        (and (not (= P1 0))
     (= N1 (+ 1 E2))
     (= F1 (- 16384))
     (<= 0 X1)
     (<= 0 L1)
     (<= 0 E1)
     (<= 0 C1)
     (<= 0 S)
     (<= 0 O)
     (<= 0 J)
     (<= 0 C)
     (not (= D2 (- 12288))))
      )
      (inv_main117 Y1
             G
             Y
             V
             N1
             J1
             Z
             F
             D1
             E
             B2
             G2
             R
             M
             Z1
             H
             P1
             M1
             T1
             C2
             B
             U
             L
             X
             K
             G1
             U1
             I
             K2
             D
             S1
             K1
             J2
             N
             S
             C1
             X1
             I1
             F2
             H1
             A2
             H2
             O1
             W1
             D2
             F1
             Q
             V1
             A
             B1
             P
             A1
             I2
             R1
             Q1
             W
             O
             J
             E1
             L1
             T
             C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 G
             Z
             R1
             M1
             V1
             U1
             E
             X
             L
             B2
             F2
             N
             C2
             S
             N1
             C
             K
             H2
             E2
             J
             J2
             A
             Y
             Q
             B
             D2
             I1
             Q1
             L1
             H1
             U
             P1
             X1
             R
             W1
             A1
             I2
             O1
             P
             F
             B1
             E1
             G1
             O
             T
             J1
             Z1
             Y1
             I
             G2
             S1
             W
             F1
             A2
             T1
             K1
             M
             V
             C1
             H
             D
             D1)
        (and (not (= U1 8561))
     (not (= U1 8448))
     (not (= U1 8576))
     (not (= U1 8577))
     (not (= U1 8592))
     (not (= U1 8593))
     (not (= U1 8608))
     (not (= U1 8609))
     (not (= U1 8640))
     (not (= U1 8641))
     (not (= U1 8656))
     (not (= U1 8657))
     (= U1 8672)
     (not (= U1 8545))
     (not (= U1 12292))
     (not (= U1 16384))
     (not (= U1 8192))
     (not (= U1 24576))
     (not (= U1 8195))
     (not (= U1 8480))
     (not (= U1 8481))
     (not (= U1 8482))
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
     (<= 0 W1)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 A1)
     (<= 0 V)
     (<= 0 M)
     (<= 0 H)
     (<= 0 I2)
     (not (= U1 8560))
     (= v_62 U1))
      )
      (inv_main445 G
             Z
             R1
             M1
             V1
             U1
             E
             X
             L
             B2
             F2
             N
             C2
             S
             N1
             C
             K
             H2
             E2
             J
             J2
             A
             Y
             Q
             B
             D2
             I1
             Q1
             L1
             H1
             U
             P1
             X1
             R
             W1
             A1
             I2
             O1
             P
             F
             B1
             v_62
             G1
             O
             T
             J1
             Z1
             Y1
             I
             G2
             S1
             W
             F1
             A2
             T1
             K1
             M
             V
             C1
             H
             D
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 I1
             F2
             J2
             S1
             U1
             Y1
             F
             H2
             C
             B
             H1
             K
             X
             M1
             M
             W
             C2
             N
             J
             O
             J1
             X1
             A1
             O1
             C1
             Z1
             N1
             P1
             G
             E1
             S
             D2
             I
             I2
             F1
             Y
             U
             Z
             B2
             B1
             P
             E
             D
             R1
             A2
             T1
             G1
             H
             W1
             T
             R
             V1
             A
             V
             G2
             D1
             Q
             K1
             Q1
             E2
             L1
             L)
        (and (not (= Y1 8560))
     (not (= Y1 8561))
     (not (= Y1 8448))
     (not (= Y1 8576))
     (not (= Y1 8577))
     (not (= Y1 8592))
     (not (= Y1 8593))
     (not (= Y1 8608))
     (not (= Y1 8609))
     (not (= Y1 8640))
     (not (= Y1 8641))
     (not (= Y1 8656))
     (not (= Y1 8657))
     (not (= Y1 8672))
     (not (= Y1 8545))
     (not (= Y1 12292))
     (not (= Y1 16384))
     (not (= Y1 8192))
     (not (= Y1 24576))
     (not (= Y1 8195))
     (not (= Y1 8480))
     (not (= Y1 8481))
     (not (= Y1 8482))
     (not (= Y1 8464))
     (not (= Y1 8465))
     (not (= Y1 8466))
     (not (= Y1 8496))
     (not (= Y1 8497))
     (not (= Y1 8512))
     (not (= Y1 8513))
     (not (= Y1 8528))
     (not (= Y1 8529))
     (not (= Y1 8544))
     (<= 0 E2)
     (<= 0 Q1)
     (<= 0 K1)
     (<= 0 F1)
     (<= 0 Y)
     (<= 0 U)
     (<= 0 Q)
     (<= 0 L)
     (= Y1 8673)
     (= v_62 Y1))
      )
      (inv_main445 I1
             F2
             J2
             S1
             U1
             Y1
             F
             H2
             C
             B
             H1
             K
             X
             M1
             M
             W
             C2
             N
             J
             O
             J1
             X1
             A1
             O1
             C1
             Z1
             N1
             P1
             G
             E1
             S
             D2
             I
             I2
             F1
             Y
             U
             Z
             B2
             B1
             P
             v_62
             D
             R1
             A2
             T1
             G1
             H
             W1
             T
             R
             V1
             A
             V
             G2
             D1
             Q
             K1
             Q1
             E2
             L1
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 U
             A2
             Z1
             Z
             V
             E1
             X1
             B
             S
             V1
             X
             K1
             H1
             F2
             D2
             A
             O
             G1
             Q1
             R
             D
             E
             Q
             W1
             I
             M1
             B2
             K
             E2
             C1
             B1
             P
             K2
             Y1
             W
             P1
             D1
             J1
             F
             L
             J2
             T1
             F1
             H
             G
             N1
             S1
             J
             R1
             A1
             T
             N
             L1
             C
             Y
             M
             G2
             C2
             I2
             O1
             H2
             U1)
        (and (not (= G1 (- 2097152)))
     (not (= E1 12292))
     (not (= E1 16384))
     (not (= E1 8192))
     (not (= E1 24576))
     (not (= E1 8195))
     (not (= E1 8480))
     (not (= E1 8481))
     (not (= E1 8482))
     (not (= E1 8464))
     (not (= E1 8465))
     (not (= E1 8466))
     (not (= E1 8496))
     (not (= E1 8497))
     (not (= E1 8512))
     (not (= E1 8513))
     (= E1 8528)
     (<= 0 I2)
     (<= 0 G2)
     (<= 0 C2)
     (<= 0 U1)
     (<= 0 P1)
     (<= 0 O1)
     (<= 0 D1)
     (<= 0 W)
     (= I1 1)
     (= v_63 C1)
     (= v_64 E1)
     (= v_65 G1))
      )
      (inv_main297 U
             A2
             Z1
             Z
             V
             E1
             X1
             B
             S
             V1
             X
             K1
             H1
             F2
             D2
             A
             O
             G1
             Q1
             R
             D
             E
             Q
             W1
             I
             M1
             B2
             I1
             E2
             C1
             B1
             P
             K2
             Y1
             v_63
             P1
             D1
             J1
             F
             L
             J2
             v_64
             F1
             H
             G
             N1
             S1
             J
             R1
             A1
             T
             N
             L1
             C
             Y
             M
             G2
             v_65
             I2
             O1
             H2
             U1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 I1
             K1
             C1
             Y1
             O1
             O
             X
             D2
             D1
             K2
             M1
             C
             V1
             T1
             Y
             T
             B2
             H2
             Q1
             H1
             F1
             E1
             D
             I
             A2
             M
             P
             U1
             V
             N1
             Z1
             F
             E
             R1
             F2
             P1
             W
             K
             B
             R
             G
             S
             I2
             G1
             J1
             L1
             U
             W1
             E2
             J
             Z
             G2
             A1
             X1
             J2
             B1
             L
             H
             N
             A
             S1
             Q)
        (and (= C2 0)
     (not (= O 12292))
     (not (= O 16384))
     (not (= O 8192))
     (not (= O 24576))
     (not (= O 8195))
     (not (= O 8480))
     (not (= O 8481))
     (not (= O 8482))
     (not (= O 8464))
     (not (= O 8465))
     (not (= O 8466))
     (not (= O 8496))
     (not (= O 8497))
     (not (= O 8512))
     (not (= O 8513))
     (= O 8528)
     (<= 0 A)
     (<= 0 F2)
     (<= 0 P1)
     (<= 0 W)
     (<= 0 Q)
     (<= 0 N)
     (<= 0 L)
     (<= 0 H)
     (= H2 (- 2097152))
     (= v_63 N1)
     (= v_64 O)
     (= v_65 H2))
      )
      (inv_main297 I1
             K1
             C1
             Y1
             O1
             O
             X
             D2
             D1
             K2
             M1
             C
             V1
             T1
             Y
             T
             B2
             H2
             Q1
             H1
             F1
             E1
             D
             I
             A2
             M
             P
             C2
             V
             N1
             Z1
             F
             E
             R1
             v_63
             P1
             W
             K
             B
             R
             G
             v_64
             I2
             G1
             J1
             L1
             U
             W1
             E2
             J
             Z
             G2
             A1
             X1
             J2
             B1
             L
             v_65
             N
             A
             S1
             Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 C
             Q1
             I
             U
             L
             F1
             Z1
             Y1
             J
             A
             J2
             W1
             A2
             N
             U1
             E1
             Z
             T
             Q
             C2
             B2
             K1
             V
             B
             S1
             V1
             W
             S
             O1
             G
             K2
             H1
             P1
             I1
             X1
             E2
             I2
             J1
             K
             F2
             M
             A1
             H
             P
             F
             Y
             R1
             G1
             C1
             L1
             G2
             N1
             M1
             H2
             B1
             X
             D
             O
             E
             R
             D2
             T1)
        (and (not (= F1 16384))
     (not (= F1 8192))
     (not (= F1 24576))
     (not (= F1 8195))
     (not (= F1 8480))
     (not (= F1 8481))
     (not (= F1 8482))
     (not (= F1 8464))
     (not (= F1 8465))
     (not (= F1 8466))
     (not (= F1 8496))
     (not (= F1 8497))
     (not (= F1 8512))
     (not (= F1 8513))
     (not (= F1 8528))
     (= F1 8529)
     (= D1 1)
     (not (= T (- 2097152)))
     (<= 0 I2)
     (<= 0 E2)
     (<= 0 X1)
     (<= 0 T1)
     (<= 0 R)
     (<= 0 O)
     (<= 0 E)
     (<= 0 D)
     (not (= F1 12292))
     (= v_63 G)
     (= v_64 F1)
     (= v_65 T))
      )
      (inv_main297 C
             Q1
             I
             U
             L
             F1
             Z1
             Y1
             J
             A
             J2
             W1
             A2
             N
             U1
             E1
             Z
             T
             Q
             C2
             B2
             K1
             V
             B
             S1
             V1
             W
             D1
             O1
             G
             K2
             H1
             P1
             I1
             v_63
             E2
             I2
             J1
             K
             F2
             M
             v_64
             H
             P
             F
             Y
             R1
             G1
             C1
             L1
             G2
             N1
             M1
             H2
             B1
             X
             D
             v_65
             E
             R
             D2
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 Y
             H
             I2
             Y1
             L
             M
             K2
             G
             M1
             E2
             D1
             C2
             H2
             X1
             Z
             P
             K
             C1
             F2
             P1
             U
             G1
             D
             I1
             A
             E1
             O
             O1
             S
             J2
             A2
             R1
             J1
             B2
             S1
             L1
             N
             N1
             C
             A1
             J
             E
             T1
             Z1
             V1
             G2
             B
             F1
             D2
             Q1
             U1
             F
             T
             V
             W1
             X
             R
             Q
             K1
             H1
             B1
             W)
        (and (not (= M 12292))
     (not (= M 16384))
     (not (= M 8192))
     (not (= M 24576))
     (not (= M 8195))
     (not (= M 8480))
     (not (= M 8481))
     (not (= M 8482))
     (not (= M 8464))
     (not (= M 8465))
     (not (= M 8466))
     (not (= M 8496))
     (not (= M 8497))
     (not (= M 8512))
     (not (= M 8513))
     (not (= M 8528))
     (= M 8529)
     (= I 0)
     (<= 0 S1)
     (<= 0 L1)
     (<= 0 K1)
     (<= 0 H1)
     (<= 0 W)
     (<= 0 R)
     (<= 0 Q)
     (<= 0 N)
     (= C1 (- 2097152))
     (= v_63 J2)
     (= v_64 M)
     (= v_65 C1))
      )
      (inv_main297 Y
             H
             I2
             Y1
             L
             M
             K2
             G
             M1
             E2
             D1
             C2
             H2
             X1
             Z
             P
             K
             C1
             F2
             P1
             U
             G1
             D
             I1
             A
             E1
             O
             I
             S
             J2
             A2
             R1
             J1
             B2
             v_63
             L1
             N
             N1
             C
             A1
             J
             v_64
             T1
             Z1
             V1
             G2
             B
             F1
             D2
             Q1
             U1
             F
             T
             V
             W1
             X
             R
             v_65
             K1
             H1
             B1
             W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main445 Z
             F2
             L1
             Q1
             X1
             M1
             H2
             N
             B2
             A
             C1
             D
             M
             W
             D2
             H
             U1
             T
             Z1
             O
             Y
             X
             E1
             C
             Q
             K2
             I1
             I2
             E2
             F1
             N1
             G
             K1
             H1
             R
             T1
             J2
             U
             D1
             V
             J1
             Y1
             L
             A1
             B1
             S1
             G1
             V1
             B
             S
             C2
             E
             O1
             I
             R1
             F
             G2
             A2
             P1
             W1
             J
             P)
        (and (<= 0 G2)
     (<= 0 A2)
     (<= 0 W1)
     (<= 0 T1)
     (<= 0 P1)
     (<= 0 R)
     (<= 0 P)
     (<= 0 J2)
     (= R1 4))
      )
      (inv_main494 Z
             F2
             L1
             Q1
             X1
             M1
             H2
             N
             B2
             A
             C1
             D
             M
             W
             D2
             H
             U1
             T
             Z1
             O
             Y
             X
             E1
             C
             Q
             K2
             I1
             I2
             E2
             F1
             N1
             G
             K1
             H1
             R
             T1
             J2
             U
             D1
             K
             J1
             Y1
             L
             A1
             B1
             S1
             G1
             V1
             B
             S
             C2
             E
             O1
             I
             R1
             F
             G2
             A2
             P1
             W1
             J
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 P S)
        (and (= S1 0)
     (= N1 8464)
     (= V 0)
     (= Q (- 1))
     (= O 0)
     (= L 8464)
     (= I 8464)
     (= E 1)
     (<= 0 H2)
     (<= 0 F2)
     (<= 0 E2)
     (<= 0 U1)
     (<= 0 G1)
     (<= 0 A1)
     (<= 0 R)
     (<= 0 K)
     (not (= V1 0))
     (= v_63 J1)
     (= v_64 V1))
      )
      (inv_main106 N1
             S
             L
             V1
             M
             I
             B1
             X
             U
             Z
             G2
             R1
             L1
             E
             W1
             F1
             Y1
             B
             I1
             P1
             B2
             C2
             E1
             J
             H
             Y
             D1
             G
             M1
             W
             K1
             O1
             A2
             N
             G1
             J1
             v_63
             v_64
             K2
             Q
             F
             X1
             S1
             V
             T
             T1
             I2
             J2
             C1
             C
             Q1
             D
             D2
             H1
             O
             Z1
             F2
             H2
             K
             A1
             A
             U1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 Z N1)
        (and (= T1 (- 1))
     (= G1 8464)
     (= E1 8464)
     (= Y 8464)
     (not (= X 0))
     (= P 0)
     (= O 0)
     (= J 0)
     (= I 0)
     (<= 0 E2)
     (<= 0 D2)
     (<= 0 Y1)
     (<= 0 W1)
     (<= 0 S1)
     (<= 0 B1)
     (<= 0 F)
     (<= 0 J2)
     (= A2 1)
     (= v_63 V)
     (= v_64 X))
      )
      (inv_main106 G1
             N1
             E1
             I
             C2
             Y
             V1
             N
             Q
             D
             K
             H2
             Z1
             A2
             U
             J1
             I2
             U1
             G
             G2
             W
             X
             M
             R1
             P1
             B
             L
             L1
             T
             D1
             B2
             Q1
             M1
             A
             F
             V
             v_63
             v_64
             S
             T1
             O1
             K2
             P
             O
             F1
             A1
             K1
             R
             I1
             C1
             X1
             C
             F2
             H
             J
             E
             J2
             Y1
             E2
             W1
             H1
             S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 A1 N1)
        (and (= C2 0)
     (= W1 8464)
     (= U1 (- 1))
     (= G1 0)
     (= Z 0)
     (= S 0)
     (= P 0)
     (= M 0)
     (= I 8464)
     (= G 8464)
     (<= 0 B)
     (<= 0 I2)
     (<= 0 G2)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 J1)
     (<= 0 H1)
     (<= 0 W)
     (= F2 1)
     (= v_64 S1))
      )
      (inv_main106 I
             N1
             W1
             P
             Z1
             G
             B1
             C
             D1
             T
             C1
             L1
             N
             F2
             D
             V
             X1
             Q1
             A
             M1
             H2
             Z
             Y1
             R
             U
             R1
             E2
             Q
             K1
             F
             V1
             L
             O
             J
             G2
             S1
             v_64
             S
             H
             U1
             I1
             L2
             C2
             M
             F1
             D2
             Y
             P1
             E1
             T1
             X
             E
             K
             O1
             G1
             J2
             I2
             A2
             B
             W
             K2
             H1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 H1
             N1
             M1
             Q
             Y1
             B2
             N
             S
             I2
             R1
             O
             F1
             E
             C
             L
             W1
             F2
             K
             G
             H2
             G1
             Z1
             P
             Q1
             M
             W
             D2
             U
             Z
             K1
             V
             Y
             A1
             U1
             B
             B1
             J2
             J1
             D
             C2
             R
             I1
             A2
             E2
             X
             V1
             I
             J
             X1
             F
             O1
             P1
             D1
             G2
             A
             S1
             C1
             T
             E1
             T1
             L1
             H)
        (and (not (= B2 8561))
     (not (= B2 8448))
     (not (= B2 8576))
     (not (= B2 8577))
     (not (= B2 8592))
     (not (= B2 8593))
     (not (= B2 8608))
     (not (= B2 8609))
     (not (= B2 8640))
     (not (= B2 8641))
     (= B2 8656)
     (not (= B2 8545))
     (not (= B2 12292))
     (not (= B2 16384))
     (not (= B2 8192))
     (not (= B2 24576))
     (not (= B2 8195))
     (not (= B2 8480))
     (not (= B2 8481))
     (not (= B2 8482))
     (not (= B2 8464))
     (not (= B2 8465))
     (not (= B2 8466))
     (not (= B2 8496))
     (not (= B2 8497))
     (not (= B2 8512))
     (not (= B2 8513))
     (not (= B2 8528))
     (not (= B2 8529))
     (not (= B2 8544))
     (<= 0 T1)
     (<= 0 E1)
     (<= 0 C1)
     (<= 0 B1)
     (<= 0 T)
     (<= 0 H)
     (<= 0 B)
     (<= 0 J2)
     (not (= B2 8560))
     (= v_62 B2))
      )
      (inv_main422 H1
             N1
             M1
             Q
             Y1
             B2
             N
             S
             I2
             R1
             O
             F1
             E
             C
             L
             W1
             F2
             K
             G
             H2
             G1
             Z1
             P
             Q1
             M
             W
             D2
             U
             Z
             K1
             V
             Y
             A1
             U1
             B
             B1
             J2
             J1
             D
             C2
             R
             v_62
             A2
             E2
             X
             V1
             I
             J
             X1
             F
             O1
             P1
             D1
             G2
             A
             S1
             C1
             T
             E1
             T1
             L1
             H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 L1
             F2
             W
             T
             G
             X1
             I
             D2
             B
             A2
             Q
             U
             A1
             K1
             Q1
             Y
             Z
             O
             G1
             B2
             D1
             S1
             C2
             J1
             W1
             J
             H1
             F
             M
             G2
             V1
             E1
             Z1
             E
             L
             C
             A
             J2
             R1
             I2
             U1
             Y1
             X
             P1
             K
             F1
             E2
             H
             O1
             V
             M1
             R
             D
             S
             C1
             H2
             T1
             I1
             N
             N1
             B1
             P)
        (and (not (= X1 8561))
     (not (= X1 8448))
     (not (= X1 8576))
     (not (= X1 8577))
     (not (= X1 8592))
     (not (= X1 8593))
     (not (= X1 8608))
     (not (= X1 8609))
     (not (= X1 8640))
     (not (= X1 8641))
     (not (= X1 8656))
     (= X1 8657)
     (not (= X1 8545))
     (not (= X1 12292))
     (not (= X1 16384))
     (not (= X1 8192))
     (not (= X1 24576))
     (not (= X1 8195))
     (not (= X1 8480))
     (not (= X1 8481))
     (not (= X1 8482))
     (not (= X1 8464))
     (not (= X1 8465))
     (not (= X1 8466))
     (not (= X1 8496))
     (not (= X1 8497))
     (not (= X1 8512))
     (not (= X1 8513))
     (not (= X1 8528))
     (not (= X1 8529))
     (not (= X1 8544))
     (<= 0 T1)
     (<= 0 N1)
     (<= 0 I1)
     (<= 0 P)
     (<= 0 N)
     (<= 0 L)
     (<= 0 C)
     (<= 0 A)
     (not (= X1 8560))
     (= v_62 X1))
      )
      (inv_main422 L1
             F2
             W
             T
             G
             X1
             I
             D2
             B
             A2
             Q
             U
             A1
             K1
             Q1
             Y
             Z
             O
             G1
             B2
             D1
             S1
             C2
             J1
             W1
             J
             H1
             F
             M
             G2
             V1
             E1
             Z1
             E
             L
             C
             A
             J2
             R1
             I2
             U1
             v_62
             X
             P1
             K
             F1
             E2
             H
             O1
             V
             M1
             R
             D
             S
             C1
             H2
             T1
             I1
             N
             N1
             B1
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main117 G
             A2
             B2
             H2
             J2
             K2
             J1
             D
             B
             U
             S1
             J
             U1
             D1
             G1
             A1
             Q1
             M1
             D2
             R1
             F2
             T
             X1
             Y
             N
             B1
             G2
             Z
             K
             E1
             P
             E2
             L1
             W1
             W
             I
             F
             Q
             V1
             F1
             C
             X
             N1
             P1
             I1
             I2
             O
             T1
             E
             V
             C1
             A
             Z1
             C2
             K1
             Y1
             M
             H
             O1
             L
             H1
             R)
        (and (not (= K2 12292))
     (not (= K2 16384))
     (not (= K2 8192))
     (not (= K2 24576))
     (not (= K2 8195))
     (not (= K2 8480))
     (not (= K2 8481))
     (= K2 8482)
     (<= 0 O1)
     (<= 0 W)
     (<= 0 R)
     (<= 0 M)
     (<= 0 L)
     (<= 0 I)
     (<= 0 H)
     (<= 0 F)
     (= S 3))
      )
      (inv_main198 G
             A2
             B2
             H2
             J2
             S
             J1
             D
             B
             U
             S1
             J
             U1
             D1
             G1
             A1
             Q1
             M1
             D2
             R1
             F2
             T
             X1
             Y
             N
             B1
             G2
             Z
             K
             E1
             P
             E2
             L1
             W1
             W
             I
             F
             Q
             V1
             F1
             C
             K2
             N1
             P1
             I1
             I2
             O
             T1
             E
             V
             C1
             A
             Z1
             C2
             K1
             Y1
             M
             H
             O1
             L
             H1
             R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main117 I
             O1
             L
             N1
             B
             S
             V
             X1
             A2
             B2
             K2
             U1
             L2
             R
             J
             G1
             Y
             T1
             H2
             M
             N
             A
             K
             M2
             N2
             U
             J1
             M1
             R1
             D
             G2
             X
             Z1
             W
             T
             E
             L1
             O2
             H1
             Y1
             Q
             W1
             B1
             D2
             G
             Z
             P1
             C
             I1
             S1
             Q1
             J2
             H
             A1
             F1
             F2
             F
             C2
             C1
             D1
             E1
             P)
        (and (= V1 0)
     (= K1 8482)
     (not (= S 12292))
     (not (= S 16384))
     (not (= S 8192))
     (not (= S 24576))
     (not (= S 8195))
     (= S 8480)
     (= O 0)
     (<= 0 E)
     (<= 0 C2)
     (<= 0 L1)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 T)
     (<= 0 P)
     (<= 0 F)
     (not (<= I2 0))
     (= E2 8448))
      )
      (inv_main198 I
             O1
             L
             N1
             B
             E2
             V
             X1
             A2
             B2
             V1
             U1
             L2
             R
             J
             O
             Y
             T1
             H2
             M
             N
             A
             K
             M2
             N2
             U
             J1
             M1
             R1
             D
             K1
             X
             Z1
             W
             T
             E
             L1
             O2
             H1
             I2
             Q
             S
             B1
             D2
             G
             Z
             P1
             C
             I1
             S1
             Q1
             J2
             H
             A1
             F1
             F2
             F
             C2
             C1
             D1
             E1
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main117 N1
             Y1
             V
             J
             N
             M1
             Q
             J2
             M2
             P
             M
             S
             B1
             W
             A1
             L2
             X1
             X
             V1
             A2
             H
             B
             O2
             E1
             C2
             F
             I
             C1
             I2
             K1
             O1
             N2
             Z
             K
             U
             Z1
             T1
             L
             F1
             G
             R
             A
             L1
             O
             W1
             Y
             S1
             D1
             D
             Q1
             T
             K2
             B2
             H1
             I1
             E2
             R1
             D2
             E
             G1
             G2
             H2)
        (and (= F2 8448)
     (= U1 0)
     (not (= M1 12292))
     (not (= M1 16384))
     (not (= M1 8192))
     (not (= M1 24576))
     (not (= M1 8195))
     (not (= M1 8480))
     (= M1 8481)
     (= J1 8482)
     (<= 0 E)
     (<= 0 H2)
     (<= 0 D2)
     (<= 0 Z1)
     (<= 0 T1)
     (<= 0 R1)
     (<= 0 G1)
     (<= 0 U)
     (not (<= P1 0))
     (= C 0))
      )
      (inv_main198 N1
             Y1
             V
             J
             N
             F2
             Q
             J2
             M2
             P
             C
             S
             B1
             W
             A1
             U1
             X1
             X
             V1
             A2
             H
             B
             O2
             E1
             C2
             F
             I
             C1
             I2
             K1
             J1
             N2
             Z
             K
             U
             Z1
             T1
             L
             F1
             P1
             R
             M1
             L1
             O
             W1
             Y
             S1
             D1
             D
             Q1
             T
             K2
             B2
             H1
             I1
             E2
             R1
             D2
             E
             G1
             G2
             H2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main117 L2
             B2
             A
             N1
             O1
             T1
             A1
             E2
             H2
             K2
             Q
             M1
             J1
             J
             J2
             C
             F2
             K
             G2
             F1
             H1
             C1
             T
             A2
             P1
             Z
             Y1
             R
             Z1
             X1
             D1
             E
             D
             M2
             W1
             N2
             E1
             N
             D2
             Y
             I
             B1
             L1
             L
             F
             B
             I1
             O
             X
             P
             G
             C2
             V1
             H
             Q1
             K1
             R1
             W
             S1
             U1
             V
             U)
        (and (= T1 8560)
     (not (= T1 8545))
     (not (= T1 12292))
     (not (= T1 16384))
     (not (= T1 8192))
     (not (= T1 24576))
     (not (= T1 8195))
     (not (= T1 8480))
     (not (= T1 8481))
     (not (= T1 8482))
     (not (= T1 8464))
     (not (= T1 8465))
     (not (= T1 8466))
     (not (= T1 8496))
     (not (= T1 8497))
     (not (= T1 8512))
     (not (= T1 8513))
     (not (= T1 8528))
     (not (= T1 8529))
     (not (= T1 8544))
     (= G1 0)
     (= S 8576)
     (<= 0 W1)
     (<= 0 U1)
     (<= 0 S1)
     (<= 0 R1)
     (<= 0 E1)
     (<= 0 W)
     (<= 0 U)
     (<= 0 N2)
     (not (<= M 0))
     (= I2 8448))
      )
      (inv_main198 L2
             B2
             A
             N1
             O1
             I2
             A1
             E2
             H2
             K2
             G1
             M1
             J1
             J
             J2
             C
             F2
             K
             G2
             F1
             H1
             C1
             T
             A2
             P1
             Z
             Y1
             R
             Z1
             X1
             S
             E
             D
             M2
             W1
             N2
             E1
             N
             D2
             M
             I
             T1
             L1
             L
             F
             B
             I1
             O
             X
             P
             G
             C2
             V1
             H
             Q1
             K1
             R1
             W
             S1
             U1
             V
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main117 U1
             G
             T1
             P1
             H
             N2
             A
             G2
             Y1
             L2
             L
             O1
             B2
             J1
             D
             M2
             D1
             A1
             I1
             W
             C
             J2
             V1
             D2
             E
             S1
             H2
             K2
             Y
             F
             E2
             R
             E1
             J
             P
             I2
             Q1
             M1
             M
             X
             L1
             C2
             F2
             K1
             Q
             H1
             V
             T
             X1
             O
             N1
             K
             C1
             N
             G1
             R1
             Z
             A2
             F1
             Z1
             B1
             I)
        (and (= W1 0)
     (= S 8448)
     (not (= N2 8560))
     (= N2 8561)
     (not (= N2 8545))
     (not (= N2 12292))
     (not (= N2 16384))
     (not (= N2 8192))
     (not (= N2 24576))
     (not (= N2 8195))
     (not (= N2 8480))
     (not (= N2 8481))
     (not (= N2 8482))
     (not (= N2 8464))
     (not (= N2 8465))
     (not (= N2 8466))
     (not (= N2 8496))
     (not (= N2 8497))
     (not (= N2 8512))
     (not (= N2 8513))
     (not (= N2 8528))
     (not (= N2 8529))
     (not (= N2 8544))
     (<= 0 I2)
     (<= 0 A2)
     (<= 0 Z1)
     (<= 0 Q1)
     (<= 0 F1)
     (<= 0 Z)
     (<= 0 P)
     (<= 0 I)
     (not (<= U 0))
     (= B 8576))
      )
      (inv_main198 U1
             G
             T1
             P1
             H
             S
             A
             G2
             Y1
             L2
             W1
             O1
             B2
             J1
             D
             M2
             D1
             A1
             I1
             W
             C
             J2
             V1
             D2
             E
             S1
             H2
             K2
             Y
             F
             B
             R
             E1
             J
             P
             I2
             Q1
             M1
             M
             U
             L1
             N2
             F2
             K1
             Q
             H1
             V
             T
             X1
             O
             N1
             K
             C1
             N
             G1
             R1
             Z
             A2
             F1
             Z1
             B1
             I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 N1
             K
             L2
             G2
             A
             B2
             C1
             M
             N
             Y1
             X
             G1
             U1
             F2
             P
             S
             Z1
             V
             D2
             H2
             J1
             F
             A1
             I2
             U
             I
             R1
             D1
             H1
             A2
             H
             B1
             S1
             Z
             M2
             T
             E2
             X1
             O
             F1
             D
             W1
             Q
             E
             L
             V1
             W
             L1
             P1
             E1
             R
             M1
             Q1
             B
             K2
             Y
             O1
             K1
             J
             G
             J2
             C2)
        (and (not (= B2 8560))
     (not (= B2 8561))
     (not (= B2 8448))
     (not (= B2 8576))
     (not (= B2 8577))
     (= B2 8592)
     (not (= B2 8545))
     (not (= B2 12292))
     (not (= B2 16384))
     (not (= B2 8192))
     (not (= B2 24576))
     (not (= B2 8195))
     (not (= B2 8480))
     (not (= B2 8481))
     (not (= B2 8482))
     (not (= B2 8464))
     (not (= B2 8465))
     (not (= B2 8466))
     (not (= B2 8496))
     (not (= B2 8497))
     (not (= B2 8512))
     (not (= B2 8513))
     (not (= B2 8528))
     (not (= B2 8529))
     (not (= B2 8544))
     (= T1 8608)
     (<= 0 E2)
     (<= 0 C2)
     (<= 0 O1)
     (<= 0 K1)
     (<= 0 T)
     (<= 0 J)
     (<= 0 G)
     (<= 0 M2)
     (not (<= I1 0))
     (= C 0))
      )
      (inv_main198 N1
             K
             L2
             G2
             A
             T1
             C1
             M
             N
             Y1
             C
             G1
             U1
             F2
             P
             S
             Z1
             V
             D2
             H2
             J1
             F
             A1
             I2
             U
             I
             R1
             D1
             H1
             A2
             H
             B1
             S1
             Z
             M2
             T
             E2
             X1
             O
             I1
             D
             B2
             Q
             E
             L
             V1
             W
             L1
             P1
             E1
             R
             M1
             Q1
             B
             K2
             Y
             O1
             K1
             J
             G
             J2
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 H2
             A2
             K2
             K1
             G
             K
             Q
             M1
             P1
             D
             H
             P
             D1
             C1
             I
             G1
             V
             X1
             I1
             F
             I2
             U1
             T1
             L
             E1
             H1
             C2
             N
             S1
             W
             L2
             R1
             U
             B
             G2
             L1
             O
             F1
             B1
             Q1
             A1
             J1
             J
             J2
             F2
             M2
             S
             N1
             D2
             Z1
             A
             Y1
             T
             E
             M
             E2
             Z
             X
             B2
             C
             O1
             Y)
        (and (= R 0)
     (not (= K 8560))
     (not (= K 8561))
     (not (= K 8448))
     (not (= K 8576))
     (not (= K 8577))
     (not (= K 8592))
     (= K 8593)
     (not (= K 8545))
     (not (= K 12292))
     (not (= K 16384))
     (not (= K 8192))
     (not (= K 24576))
     (not (= K 8195))
     (not (= K 8480))
     (not (= K 8481))
     (not (= K 8482))
     (not (= K 8464))
     (not (= K 8465))
     (not (= K 8466))
     (not (= K 8496))
     (not (= K 8497))
     (not (= K 8512))
     (not (= K 8513))
     (not (= K 8528))
     (not (= K 8529))
     (not (= K 8544))
     (<= 0 C)
     (<= 0 G2)
     (<= 0 B2)
     (<= 0 L1)
     (<= 0 Z)
     (<= 0 Y)
     (<= 0 X)
     (<= 0 O)
     (not (<= V1 0))
     (= W1 8608))
      )
      (inv_main198 H2
             A2
             K2
             K1
             G
             W1
             Q
             M1
             P1
             D
             R
             P
             D1
             C1
             I
             G1
             V
             X1
             I1
             F
             I2
             U1
             T1
             L
             E1
             H1
             C2
             N
             S1
             W
             L2
             R1
             U
             B
             G2
             L1
             O
             F1
             B1
             V1
             A1
             K
             J
             J2
             F2
             M2
             S
             N1
             D2
             Z1
             A
             Y1
             T
             E
             M
             E2
             Z
             X
             B2
             C
             O1
             Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 N
             W1
             H
             B
             A
             L2
             K2
             K1
             Z1
             J1
             R
             R1
             F1
             F2
             U1
             Z
             C2
             Y
             B2
             T1
             H2
             Q1
             E
             M1
             S1
             I1
             X1
             D1
             G
             P
             C1
             G1
             M2
             O
             J
             E1
             T
             X
             G2
             L1
             B1
             I
             A1
             V
             E2
             P1
             O1
             K
             M
             J2
             L
             D
             D2
             A2
             V1
             Q
             W
             I2
             F
             U
             Y1
             N1)
        (and (= H1 8640)
     (not (= L2 8560))
     (not (= L2 8561))
     (not (= L2 8448))
     (not (= L2 8576))
     (not (= L2 8577))
     (not (= L2 8592))
     (not (= L2 8593))
     (= L2 8608)
     (not (= L2 8545))
     (not (= L2 12292))
     (not (= L2 16384))
     (not (= L2 8192))
     (not (= L2 24576))
     (not (= L2 8195))
     (not (= L2 8480))
     (not (= L2 8481))
     (not (= L2 8482))
     (not (= L2 8464))
     (not (= L2 8465))
     (not (= L2 8466))
     (not (= L2 8496))
     (not (= L2 8497))
     (not (= L2 8512))
     (not (= L2 8513))
     (not (= L2 8528))
     (not (= L2 8529))
     (not (= L2 8544))
     (<= 0 I2)
     (<= 0 N1)
     (<= 0 E1)
     (<= 0 W)
     (<= 0 U)
     (<= 0 T)
     (<= 0 J)
     (<= 0 F)
     (not (<= S 0))
     (= C 0))
      )
      (inv_main198 N
             W1
             H
             B
             A
             H1
             K2
             K1
             Z1
             J1
             C
             R1
             F1
             F2
             U1
             Z
             C2
             Y
             B2
             T1
             H2
             Q1
             E
             M1
             S1
             I1
             X1
             D1
             G
             P
             C1
             G1
             M2
             O
             J
             E1
             T
             X
             G2
             S
             B1
             L2
             A1
             V
             E2
             P1
             O1
             K
             M
             J2
             L
             D
             D2
             A2
             V1
             Q
             W
             I2
             F
             U
             Y1
             N1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 W
             B
             V
             O1
             C1
             A1
             N
             O
             P1
             M
             Z
             Z1
             Y1
             X
             S1
             K1
             G
             V1
             J1
             E
             K
             L2
             C2
             F1
             D2
             I1
             H1
             K2
             R
             C
             J
             R1
             H
             G2
             X1
             I
             B2
             U1
             Q
             Y
             T
             M2
             L
             F
             D1
             J2
             I2
             A2
             H2
             S
             W1
             T1
             N1
             P
             D
             A
             M1
             E2
             L1
             U
             G1
             B1)
        (and (= Q1 8640)
     (not (= A1 8560))
     (not (= A1 8561))
     (not (= A1 8448))
     (not (= A1 8576))
     (not (= A1 8577))
     (not (= A1 8592))
     (not (= A1 8593))
     (not (= A1 8608))
     (= A1 8609)
     (not (= A1 8545))
     (not (= A1 12292))
     (not (= A1 16384))
     (not (= A1 8192))
     (not (= A1 24576))
     (not (= A1 8195))
     (not (= A1 8480))
     (not (= A1 8481))
     (not (= A1 8482))
     (not (= A1 8464))
     (not (= A1 8465))
     (not (= A1 8466))
     (not (= A1 8496))
     (not (= A1 8497))
     (not (= A1 8512))
     (not (= A1 8513))
     (not (= A1 8528))
     (not (= A1 8529))
     (not (= A1 8544))
     (<= 0 E2)
     (<= 0 B2)
     (<= 0 X1)
     (<= 0 M1)
     (<= 0 L1)
     (<= 0 B1)
     (<= 0 U)
     (<= 0 I)
     (not (<= E1 0))
     (= F2 0))
      )
      (inv_main198 W
             B
             V
             O1
             C1
             Q1
             N
             O
             P1
             M
             F2
             Z1
             Y1
             X
             S1
             K1
             G
             V1
             J1
             E
             K
             L2
             C2
             F1
             D2
             I1
             H1
             K2
             R
             C
             J
             R1
             H
             G2
             X1
             I
             B2
             U1
             Q
             E1
             T
             A1
             L
             F
             D1
             J2
             I2
             A2
             H2
             S
             W1
             T1
             N1
             P
             D
             A
             M1
             E2
             L1
             U
             G1
             B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main254 C1
             S1
             V1
             I1
             W1
             E2
             V
             S
             A2
             G2
             K
             F
             M1
             Q
             W
             P
             Z1
             D
             J2
             G1
             I2
             X1
             U
             N2
             Y
             L2
             F2
             H1
             A
             F1
             O
             B
             M
             R1
             K1
             K2
             T
             I
             D2
             U1
             M2
             E
             E1
             P2
             R
             H2
             O1
             Y1
             J
             L1
             X
             B1
             L
             B2
             T1
             N1
             Q1
             P1
             H
             D1
             A1
             G)
        (and (= C2 8496)
     (= T1 0)
     (= J1 0)
     (= Z 1)
     (= O2 0)
     (<= 0 K2)
     (<= 0 Q1)
     (<= 0 P1)
     (<= 0 K1)
     (<= 0 D1)
     (<= 0 T)
     (<= 0 H)
     (<= 0 G)
     (not (<= N 0))
     (= C 1))
      )
      (inv_main198 C1
             S1
             V1
             I1
             W1
             C2
             V
             S
             A2
             G2
             O2
             F
             M1
             Q
             W
             J1
             Z1
             D
             J2
             G1
             I2
             X1
             U
             N2
             Y
             L2
             F2
             H1
             A
             F1
             O
             B
             M
             R1
             K1
             K2
             T
             I
             D2
             N
             M2
             E
             E1
             Z
             R
             H2
             O1
             Y1
             J
             L1
             X
             B1
             L
             B2
             C
             N1
             Q1
             P1
             H
             D1
             A1
             G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main254 S
             E2
             F2
             K
             J1
             H1
             C
             O1
             N
             L1
             G2
             C1
             H2
             K1
             X1
             B2
             M1
             N1
             M2
             Y
             Y1
             V1
             G1
             X
             N2
             Z
             E
             C2
             D1
             Z1
             S1
             D
             W
             H
             I
             I2
             B1
             K2
             V
             P
             G
             T1
             F
             R
             Q1
             U1
             J
             L2
             O
             I1
             B
             F1
             J2
             U
             E1
             L
             M
             R1
             A
             Q
             A2
             W1)
        (and (= P1 8496)
     (not (= E1 0))
     (= T 1)
     (= O2 0)
     (<= 0 A)
     (<= 0 I2)
     (<= 0 W1)
     (<= 0 R1)
     (<= 0 B1)
     (<= 0 Q)
     (<= 0 M)
     (<= 0 I)
     (not (<= A1 0))
     (= D2 0))
      )
      (inv_main198 S
             E2
             F2
             K
             J1
             P1
             C
             O1
             N
             L1
             O2
             C1
             H2
             K1
             X1
             D2
             M1
             N1
             M2
             Y
             Y1
             V1
             G1
             X
             N2
             Z
             E
             C2
             D1
             Z1
             S1
             D
             W
             H
             I
             I2
             B1
             K2
             V
             A1
             G
             T1
             F
             T
             Q1
             U1
             J
             L2
             O
             I1
             B
             F1
             J2
             U
             E1
             L
             M
             R1
             A
             Q
             A2
             W1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main271 T1
             F2
             G1
             D2
             X
             J
             D
             G2
             D1
             Y
             M
             C
             P1
             H2
             G
             L2
             U1
             A2
             C2
             N
             K1
             I1
             R1
             B
             A
             K2
             U
             H1
             O1
             J2
             X1
             L
             I
             L1
             E1
             S
             J1
             W1
             B1
             R
             E2
             P
             A1
             Q
             M1
             S1
             V
             F
             V1
             B2
             I2
             K
             T
             H
             O
             E
             Q1
             F1
             Z
             W
             C1
             N1)
        (and (= Y1 0)
     (not (= C 0))
     (<= 0 Q1)
     (<= 0 N1)
     (<= 0 J1)
     (<= 0 F1)
     (<= 0 E1)
     (<= 0 Z)
     (<= 0 W)
     (<= 0 S)
     (not (<= R 0))
     (= Z1 8656))
      )
      (inv_main198 T1
             F2
             G1
             D2
             X
             Z1
             D
             G2
             D1
             Y
             Y1
             C
             P1
             H2
             G
             L2
             U1
             A2
             C2
             N
             K1
             I1
             R1
             B
             A
             K2
             U
             H1
             O1
             J2
             X1
             L
             I
             L1
             E1
             S
             J1
             W1
             B1
             R
             E2
             P
             A1
             Q
             M1
             S1
             V
             F
             V1
             B2
             I2
             K
             T
             H
             O
             E
             Q1
             F1
             Z
             W
             C1
             N1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main271 K2
             P1
             X
             D1
             B2
             P
             U1
             B
             L2
             M1
             I2
             V1
             E1
             N1
             C2
             Q1
             D2
             M
             L
             B1
             H1
             N
             R
             R1
             C1
             L1
             K1
             Z
             G2
             A2
             C
             X1
             F
             F2
             K
             S
             T
             V
             H2
             E2
             I1
             D
             Y
             G1
             A1
             U
             Q
             I
             G
             Z1
             S1
             F1
             A
             H
             J1
             W1
             Y1
             O
             W
             J
             O1
             E)
        (and (= V1 0)
     (= T1 8512)
     (<= 0 Y1)
     (<= 0 W)
     (<= 0 T)
     (<= 0 S)
     (<= 0 O)
     (<= 0 K)
     (<= 0 J)
     (<= 0 E)
     (not (<= E2 0))
     (= J2 0))
      )
      (inv_main198 K2
             P1
             X
             D1
             B2
             T1
             U1
             B
             L2
             M1
             J2
             V1
             E1
             N1
             C2
             Q1
             D2
             M
             L
             B1
             H1
             N
             R
             R1
             C1
             L1
             K1
             Z
             G2
             A2
             C
             X1
             F
             F2
             K
             S
             T
             V
             H2
             E2
             I1
             D
             Y
             G1
             A1
             U
             Q
             I
             G
             Z1
             S1
             F1
             A
             H
             J1
             W1
             Y1
             O
             W
             J
             O1
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 J1
             A2
             Q
             V1
             U1
             F2
             S1
             L
             B1
             C2
             R
             C
             G2
             C1
             D
             H1
             N
             A1
             E
             I
             I2
             R1
             Z1
             K1
             F
             U
             X
             G1
             E2
             J2
             P1
             M1
             V
             D2
             H
             P
             J
             O
             K
             X1
             Z
             E1
             B2
             Y1
             Q1
             M
             H2
             W1
             W
             L1
             N1
             I1
             D1
             T1
             B
             O1
             F1
             G
             A
             T
             Y
             S)
        (and (not (= F2 8561))
     (= F2 8448)
     (not (= F2 8545))
     (not (= F2 12292))
     (not (= F2 16384))
     (not (= F2 8192))
     (not (= F2 24576))
     (not (= F2 8195))
     (not (= F2 8480))
     (not (= F2 8481))
     (not (= F2 8482))
     (not (= F2 8464))
     (not (= F2 8465))
     (not (= F2 8466))
     (not (= F2 8496))
     (not (= F2 8497))
     (not (= F2 8512))
     (not (= F2 8513))
     (not (= F2 8528))
     (not (= F2 8529))
     (not (= F2 8544))
     (not (<= 1 K))
     (<= 0 F1)
     (<= 0 T)
     (<= 0 S)
     (<= 0 P)
     (<= 0 J)
     (<= 0 H)
     (<= 0 G)
     (<= 0 A)
     (not (= F2 8560))
     (= v_62 P1))
      )
      (inv_main198 J1
             A2
             Q
             V1
             U1
             P1
             S1
             L
             B1
             C2
             R
             C
             G2
             C1
             D
             H1
             N
             A1
             E
             I
             I2
             R1
             Z1
             K1
             F
             U
             X
             G1
             E2
             J2
             v_62
             M1
             V
             D2
             H
             P
             J
             O
             K
             X1
             Z
             F2
             B2
             Y1
             Q1
             M
             H2
             W1
             W
             L1
             N1
             I1
             D1
             T1
             B
             O1
             F1
             G
             A
             T
             Y
             S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main117 Q
             H2
             T
             J2
             Y1
             B2
             S1
             F2
             C2
             W1
             L1
             M1
             C1
             I2
             D
             P
             U
             W
             O
             X
             U1
             D2
             E
             K2
             R1
             F
             G1
             V1
             I
             V
             C
             Q1
             M
             J
             I1
             O1
             A
             N1
             B
             P1
             E2
             G2
             E1
             A2
             G
             B1
             Z1
             L
             F1
             A1
             Y
             S
             K
             K1
             T1
             N
             Z
             R
             H
             X1
             H1
             J1)
        (and (not (= B2 8561))
     (= B2 8448)
     (not (= B2 8545))
     (not (= B2 12292))
     (not (= B2 16384))
     (not (= B2 8192))
     (not (= B2 24576))
     (not (= B2 8195))
     (not (= B2 8480))
     (not (= B2 8481))
     (not (= B2 8482))
     (not (= B2 8464))
     (not (= B2 8465))
     (not (= B2 8466))
     (not (= B2 8496))
     (not (= B2 8497))
     (not (= B2 8512))
     (not (= B2 8513))
     (not (= B2 8528))
     (not (= B2 8529))
     (not (= B2 8544))
     (= D1 1)
     (<= 1 B)
     (<= 0 A)
     (<= 0 X1)
     (<= 0 O1)
     (<= 0 J1)
     (<= 0 I1)
     (<= 0 Z)
     (<= 0 R)
     (<= 0 H)
     (not (<= S 0))
     (not (= B2 8560))
     (= v_63 C)
     (= v_64 S))
      )
      (inv_main198 Q
             H2
             T
             J2
             Y1
             C
             S1
             F2
             C2
             W1
             L1
             M1
             D1
             I2
             D
             P
             U
             W
             O
             X
             U1
             D2
             E
             K2
             R1
             F
             G1
             V1
             I
             V
             v_63
             Q1
             M
             J
             I1
             O1
             A
             N1
             S
             P1
             E2
             B2
             E1
             A2
             G
             B1
             Z1
             L
             F1
             A1
             Y
             v_64
             K
             K1
             T1
             N
             Z
             R
             H
             X1
             H1
             J1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main445 U
             A
             Q1
             R
             B1
             D1
             T
             M2
             F1
             H2
             G
             B2
             N2
             O
             V
             H1
             S
             B
             T1
             A1
             I2
             F
             S1
             I1
             W
             R1
             J2
             K
             C2
             F2
             L1
             Q
             Y
             M1
             N1
             J
             P1
             L
             C1
             G1
             K1
             C
             J1
             P
             D
             G2
             Y1
             A2
             I
             E2
             U1
             L2
             Z1
             N
             W1
             H
             V1
             X1
             Z
             K2
             M
             D2)
        (and (not (= W1 4))
     (= O1 8640)
     (= E1 8448)
     (= E 0)
     (<= 0 K2)
     (<= 0 D2)
     (<= 0 X1)
     (<= 0 V1)
     (<= 0 P1)
     (<= 0 N1)
     (<= 0 Z)
     (<= 0 J)
     (not (<= X 0))
     (not (= B2 0)))
      )
      (inv_main198 U
             A
             Q1
             R
             B1
             E1
             T
             M2
             F1
             H2
             E
             B2
             N2
             O
             V
             H1
             S
             B
             T1
             A1
             I2
             F
             S1
             I1
             W
             R1
             J2
             K
             C2
             F2
             O1
             Q
             Y
             M1
             N1
             J
             P1
             L
             C1
             X
             K1
             C
             J1
             P
             D
             G2
             Y1
             A2
             I
             E2
             U1
             L2
             Z1
             N
             W1
             H
             V1
             X1
             Z
             K2
             M
             D2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main445 Q1
             F
             Z
             A
             Y1
             G2
             I2
             G
             Q
             M
             T
             X
             F1
             R
             K2
             F2
             X1
             A1
             L1
             P
             L
             W
             Z1
             B
             B1
             M1
             B2
             D
             H1
             C2
             S
             K
             O1
             N
             D1
             A2
             T1
             J
             M2
             E1
             U
             H2
             N2
             J2
             N1
             I1
             J1
             Y
             S1
             E
             K1
             V1
             R1
             I
             W1
             V
             C
             O
             L2
             C1
             P1
             D2)
        (and (= U1 8448)
     (= G1 0)
     (= X 0)
     (= H 3)
     (<= 0 C)
     (<= 0 L2)
     (<= 0 D2)
     (<= 0 A2)
     (<= 0 T1)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 O)
     (not (<= E2 0))
     (not (= W1 4)))
      )
      (inv_main198 Q1
             F
             Z
             A
             Y1
             U1
             I2
             G
             Q
             M
             G1
             X
             F1
             R
             K2
             F2
             X1
             A1
             L1
             P
             L
             W
             Z1
             B
             B1
             M1
             B2
             D
             H1
             C2
             H
             K
             O1
             N
             D1
             A2
             T1
             J
             M2
             E2
             U
             H2
             N2
             J2
             N1
             I1
             J1
             Y
             S1
             E
             K1
             V1
             R1
             I
             W1
             V
             C
             O
             L2
             C1
             P1
             D2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main297 K2
             V
             Z1
             A2
             P1
             Q1
             L1
             G1
             I
             H
             M2
             G
             W
             M1
             Y
             U1
             S
             S1
             F2
             K
             N
             D
             R
             Q
             U
             M
             B2
             R1
             T
             N1
             W1
             L
             O1
             C2
             F
             D2
             D1
             B1
             T1
             L2
             B
             Z
             O
             E2
             I2
             K1
             V1
             C1
             A
             P
             H2
             F1
             A1
             J1
             Y1
             C
             E1
             G2
             I1
             H1
             J
             E)
        (and (= X1 1)
     (= R1 0)
     (= X 8544)
     (= F (- 30))
     (= F (- 1))
     (<= 0 G2)
     (<= 0 D2)
     (<= 0 I1)
     (<= 0 H1)
     (<= 0 E1)
     (<= 0 D1)
     (<= 0 F)
     (<= 0 E)
     (= J2 0))
      )
      (inv_main198 K2
             V
             Z1
             A2
             P1
             X
             L1
             G1
             I
             H
             J2
             G
             W
             M1
             Y
             U1
             S
             S1
             F2
             K
             N
             D
             R
             Q
             U
             M
             B2
             R1
             T
             N1
             W1
             L
             O1
             C2
             F
             D2
             D1
             B1
             T1
             L2
             B
             Z
             X1
             E2
             I2
             K1
             V1
             C1
             A
             P
             H2
             F1
             A1
             J1
             Y1
             C
             E1
             G2
             I1
             H1
             J
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main297 N1
             L2
             G1
             M2
             T
             R1
             G
             F
             Q
             H2
             C
             D
             X1
             E1
             M
             K
             B
             L
             X
             A
             U1
             J
             K1
             V
             H
             D1
             C2
             U
             Q1
             O
             B1
             S1
             M1
             I1
             I
             Y
             T1
             B2
             V1
             P
             F1
             Z
             Y1
             N
             H1
             W
             W1
             A1
             Z1
             S
             K2
             O1
             A2
             G2
             E2
             I2
             L1
             P1
             E
             J1
             D2
             C1)
        (and (= F2 1)
     (not (= U1 0))
     (= S1 (- 2))
     (= U 0)
     (= R 0)
     (= I (- 30))
     (not (= I (- 1)))
     (<= 0 T1)
     (<= 0 P1)
     (<= 0 L1)
     (<= 0 J1)
     (<= 0 C1)
     (<= 0 Y)
     (<= 0 I)
     (<= 0 E)
     (= J2 8544)
     (= v_65 S1))
      )
      (inv_main198 N1
             L2
             G1
             M2
             T
             J2
             G
             F
             Q
             H2
             R
             D
             X1
             E1
             M
             K
             B
             L
             X
             A
             U1
             J
             K1
             V
             H
             D1
             C2
             U
             Q1
             O
             B1
             S1
             M1
             I1
             I
             Y
             T1
             B2
             V1
             P
             F1
             Z
             F2
             N
             H1
             W
             W1
             A1
             Z1
             S
             K2
             O1
             A2
             G2
             E2
             I2
             L1
             P1
             v_65
             J1
             D2
             C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main297 A
             U1
             M
             M2
             V
             B2
             E1
             Y
             H1
             G
             M1
             E2
             S1
             D2
             D1
             Z1
             K
             B1
             R1
             Y1
             C1
             S
             P
             K2
             J1
             Q
             W
             F
             R
             N1
             K1
             U
             H
             C2
             W1
             L1
             A1
             J
             H2
             X1
             I1
             N
             O
             C
             L
             V1
             O2
             E
             Q1
             G2
             F1
             I2
             D
             X
             N2
             G1
             J2
             I
             P1
             L2
             B
             T)
        (and (= F2 1)
     (= W1 (- 30))
     (not (= W1 (- 1)))
     (= T1 0)
     (= O1 8544)
     (not (= C1 0))
     (= Z 512)
     (not (= U (- 4)))
     (not (= U (- 2)))
     (= F 0)
     (not (>= G2 65))
     (<= 0 L2)
     (<= 0 J2)
     (<= 0 W1)
     (<= 0 P1)
     (<= 0 L1)
     (<= 0 A1)
     (<= 0 T)
     (<= 0 I)
     (= (+ A2 (* (- 8) G2)) 0)
     (= v_67 U)
     (= v_68 U))
      )
      (inv_main198 A
             U1
             M
             M2
             V
             O1
             E1
             Y
             H1
             G
             T1
             E2
             S1
             D2
             D1
             Z1
             K
             B1
             R1
             Y1
             C1
             S
             P
             K2
             J1
             Q
             W
             F
             R
             N1
             K1
             U
             H
             C2
             W1
             L1
             A1
             J
             H2
             X1
             I1
             N
             F2
             C
             L
             V1
             O2
             E
             Q1
             G2
             Z
             I2
             D
             X
             N2
             G1
             J2
             I
             v_67
             v_68
             A2
             T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main297 L
             O
             V1
             W1
             D
             H2
             Q
             R1
             X
             Z
             T
             M1
             O1
             S1
             D2
             F1
             K2
             M2
             N
             T1
             U
             S
             I1
             I2
             D1
             J1
             Y
             K1
             A
             C2
             N1
             L2
             H1
             B
             X1
             J2
             L1
             Z1
             M
             O2
             G2
             Y1
             Q1
             V
             G1
             W
             P
             F2
             B2
             J
             B1
             R
             K
             A2
             U1
             C
             N2
             E1
             I
             H
             F
             G)
        (and (= E 0)
     (= L2 (- 4))
     (not (= L2 (- 2)))
     (= E2 1024)
     (= X1 (- 30))
     (not (= X1 (- 1)))
     (= K1 0)
     (= C1 1)
     (= A1 8544)
     (not (= U 0))
     (not (>= J 129))
     (<= 0 J2)
     (<= 0 X1)
     (<= 0 L1)
     (<= 0 E1)
     (<= 0 I)
     (<= 0 H)
     (<= 0 G)
     (<= 0 N2)
     (= (+ P1 (* (- 8) J)) 0)
     (= v_67 L2)
     (= v_68 L2))
      )
      (inv_main198 L
             O
             V1
             W1
             D
             A1
             Q
             R1
             X
             Z
             E
             M1
             O1
             S1
             D2
             F1
             K2
             M2
             N
             T1
             U
             S
             I1
             I2
             D1
             J1
             Y
             K1
             A
             C2
             N1
             L2
             H1
             B
             X1
             J2
             L1
             Z1
             M
             O2
             G2
             Y1
             C1
             V
             G1
             W
             P
             F2
             B2
             J
             E2
             R
             K
             A2
             U1
             C
             N2
             E1
             v_67
             v_68
             P1
             G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main327 F1
             J2
             A2
             Q1
             L1
             X
             W1
             D
             I
             G
             A
             B
             D2
             G2
             E
             C1
             P
             K1
             X1
             A1
             U
             F2
             O1
             B2
             Z1
             H
             L2
             I1
             W
             S1
             V1
             J1
             T
             P1
             N
             E1
             B1
             C
             H1
             G1
             T1
             E2
             S
             O
             K
             Y
             U1
             L
             Z
             K2
             N1
             I2
             V
             J
             D1
             H2
             C2
             R
             Y1
             M
             R1
             M1)
        (and (not (= X1 (- 1)))
     (not (= A1 0))
     (= Q 8560)
     (= F 1)
     (= M2 0)
     (<= 0 C2)
     (<= 0 Y1)
     (<= 0 M1)
     (<= 0 E1)
     (<= 0 B1)
     (<= 0 R)
     (<= 0 N)
     (<= 0 M)
     (not (= X1 (- 4))))
      )
      (inv_main198 F1
             J2
             A2
             Q1
             L1
             Q
             W1
             D
             I
             G
             A
             B
             D2
             G2
             E
             C1
             P
             K1
             X1
             A1
             U
             F2
             O1
             B2
             Z1
             M2
             L2
             I1
             W
             S1
             V1
             J1
             T
             P1
             N
             E1
             B1
             C
             H1
             G1
             T1
             E2
             F
             O
             K
             Y
             U1
             L
             Z
             K2
             N1
             I2
             V
             J
             D1
             H2
             C2
             R
             Y1
             M
             R1
             M1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main333 Y
             W
             I2
             H2
             K
             V
             B2
             F
             G2
             A
             A1
             D1
             C2
             D2
             S
             J
             U1
             L1
             H1
             G1
             Q
             E1
             V1
             Z1
             U
             Q1
             H
             A2
             K1
             P1
             P
             D
             S1
             O
             L2
             T1
             F2
             K2
             I1
             E
             J1
             R
             C1
             O1
             Y1
             F1
             L
             T
             N1
             C
             M
             B
             R1
             B1
             M1
             Z
             E2
             X1
             W1
             I
             G
             X)
        (and (not (= P1 (- 256)))
     (= H1 (- 2))
     (= N 8560)
     (= M2 0)
     (<= 0 F2)
     (<= 0 E2)
     (<= 0 X1)
     (<= 0 W1)
     (<= 0 T1)
     (<= 0 X)
     (<= 0 I)
     (<= 0 L2)
     (= J2 1)
     (= v_65 P1))
      )
      (inv_main198 Y
             W
             I2
             H2
             K
             N
             B2
             F
             G2
             A
             A1
             D1
             C2
             D2
             S
             J
             U1
             L1
             H1
             G1
             Q
             E1
             V1
             Z1
             U
             M2
             H
             A2
             K1
             P1
             P
             D
             S1
             O
             L2
             T1
             F2
             K2
             I1
             E
             J1
             R
             J2
             O1
             Y1
             F1
             L
             T
             N1
             C
             M
             B
             R1
             B1
             M1
             Z
             E2
             X1
             W1
             I
             G
             v_65)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main327 H
             C
             D1
             P1
             K
             N
             A2
             U
             X1
             X
             J
             O1
             A1
             T
             J1
             G
             E2
             F
             O
             E
             U1
             L1
             Y1
             D2
             F2
             V
             R
             E1
             Q1
             G2
             T1
             A
             P
             K2
             W
             H1
             Z
             I
             N1
             M
             B2
             C2
             I2
             R1
             M1
             V1
             D
             Y
             F1
             C1
             S1
             Z1
             K1
             L
             H2
             S
             B1
             Q
             M2
             L2
             W1
             B)
        (and (= I1 1)
     (= G1 8560)
     (= O (- 1))
     (<= 0 B)
     (<= 0 H1)
     (<= 0 B1)
     (<= 0 Z)
     (<= 0 W)
     (<= 0 Q)
     (<= 0 M2)
     (<= 0 L2)
     (= J2 0))
      )
      (inv_main198 H
             C
             D1
             P1
             K
             G1
             A2
             U
             X1
             X
             J
             O1
             A1
             T
             J1
             G
             E2
             F
             O
             E
             U1
             L1
             Y1
             D2
             F2
             J2
             R
             E1
             Q1
             G2
             T1
             A
             P
             K2
             W
             H1
             Z
             I
             N1
             M
             B2
             C2
             I1
             R1
             M1
             V1
             D
             Y
             F1
             C1
             S1
             Z1
             K1
             L
             H2
             S
             B1
             Q
             M2
             L2
             W1
             B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main333 H1
             G
             F1
             U
             B2
             C2
             D1
             O
             R
             V
             A1
             B
             H2
             Z1
             Z
             D
             K1
             W1
             F2
             E1
             O1
             N
             J2
             J
             T
             M1
             O2
             L2
             M
             P
             D2
             R1
             W
             H
             X
             I2
             Q
             A
             U1
             T1
             S1
             Q1
             N1
             E
             C1
             Y1
             S
             X1
             F
             E2
             I1
             N2
             C
             L
             B1
             K2
             P1
             J1
             V1
             K
             M2
             I)
        (and (= A2 0)
     (= L1 8448)
     (= G1 1)
     (= P (- 256))
     (<= 0 I2)
     (<= 0 V1)
     (<= 0 P1)
     (<= 0 J1)
     (<= 0 X)
     (<= 0 Q)
     (<= 0 K)
     (<= 0 I)
     (not (<= Y 0))
     (= G2 8576)
     (= v_67 P))
      )
      (inv_main198 H1
             G
             F1
             U
             B2
             L1
             D1
             O
             R
             V
             A2
             B
             H2
             Z1
             Z
             D
             K1
             W1
             F2
             E1
             O1
             N
             J2
             J
             T
             G1
             O2
             L2
             M
             P
             G2
             R1
             W
             H
             X
             I2
             Q
             A
             U1
             Y
             S1
             Q1
             N1
             E
             C1
             Y1
             S
             X1
             F
             E2
             I1
             N2
             C
             L
             B1
             K2
             P1
             J1
             V1
             K
             M2
             v_67)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main333 R
             Z
             V1
             A
             Q1
             X
             N2
             I
             W
             O1
             R1
             J1
             U
             U1
             A1
             I1
             Q
             G1
             P1
             L
             E2
             M1
             T1
             D1
             S
             Y1
             M
             L1
             T
             L2
             C2
             K2
             G2
             K
             C
             B2
             J
             K1
             M2
             J2
             S1
             I2
             V
             G
             F2
             X1
             W1
             O2
             C1
             O
             E
             H
             Z1
             H1
             F1
             E1
             N
             H2
             F
             A2
             D2
             B1)
        (and (= D 8448)
     (not (= L2 (- 256)))
     (not (= P1 (- 2)))
     (= N1 8576)
     (= Y 0)
     (<= 0 C)
     (<= 0 H2)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 B1)
     (<= 0 N)
     (<= 0 J)
     (<= 0 F)
     (not (<= P 0))
     (= B 1)
     (= v_67 L2))
      )
      (inv_main198 R
             Z
             V1
             A
             Q1
             D
             N2
             I
             W
             O1
             Y
             J1
             U
             U1
             A1
             I1
             Q
             G1
             P1
             L
             E2
             M1
             T1
             D1
             S
             B
             M
             L1
             T
             L2
             N1
             K2
             G2
             K
             C
             B2
             J
             K1
             M2
             P
             S1
             I2
             V
             G
             F2
             X1
             W1
             O2
             C1
             O
             E
             H
             Z1
             H1
             F1
             E1
             N
             H2
             F
             A2
             D2
             v_67)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 C1
             G
             P1
             M2
             T1
             E2
             X
             H2
             W
             M
             U
             T
             G2
             L1
             D1
             Q
             S
             S1
             J
             M1
             H1
             O1
             I
             F2
             K1
             V1
             Y
             C2
             A
             W1
             O
             Q1
             X1
             P
             C
             N1
             B
             I2
             U1
             B2
             G1
             N
             F
             E
             I1
             B1
             J2
             D
             J1
             L
             R1
             K
             D2
             L2
             F1
             K2
             V
             R
             A2
             A1
             Z1
             Y1)
        (and (not (= E2 16384))
     (not (= E2 8192))
     (not (= E2 24576))
     (not (= E2 8195))
     (not (= E2 8480))
     (not (= E2 8481))
     (not (= E2 8482))
     (not (= E2 8464))
     (not (= E2 8465))
     (not (= E2 8466))
     (not (= E2 8496))
     (not (= E2 8497))
     (= E2 8512)
     (not (= W1 (- 256)))
     (= E1 0)
     (= Z 8528)
     (= H 1)
     (<= 0 B)
     (<= 0 C)
     (<= 0 A2)
     (<= 0 Y1)
     (<= 0 N1)
     (<= 0 A1)
     (<= 0 V)
     (<= 0 R)
     (not (= E2 12292))
     (= v_65 W1))
      )
      (inv_main198 C1
             G
             P1
             M2
             T1
             Z
             X
             H2
             W
             M
             E1
             T
             G2
             L1
             D1
             Q
             S
             S1
             J
             M1
             H1
             O1
             I
             F2
             K1
             V1
             Y
             C2
             A
             W1
             O
             Q1
             X1
             P
             C
             N1
             B
             I2
             U1
             B2
             G1
             E2
             H
             E
             I1
             B1
             J2
             D
             J1
             L
             R1
             K
             D2
             L2
             F1
             K2
             v_65
             R
             A2
             A1
             Z1
             Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 H
             H1
             S
             V1
             K1
             A2
             E1
             Q
             G2
             M1
             G1
             Z1
             S1
             A
             Y
             G
             M
             B2
             X
             L
             M2
             D
             Y1
             F1
             C1
             D1
             K
             T1
             P
             I1
             N
             U
             A1
             U1
             V
             P1
             N1
             C
             O1
             O
             F
             H2
             B1
             L1
             F2
             I2
             Q1
             E2
             R1
             W
             T
             B
             W1
             R
             Z
             C2
             J
             X1
             K2
             L2
             J1
             E)
        (and (not (= A2 12292))
     (not (= A2 16384))
     (not (= A2 8192))
     (not (= A2 24576))
     (not (= A2 8195))
     (not (= A2 8480))
     (not (= A2 8481))
     (not (= A2 8482))
     (not (= A2 8464))
     (not (= A2 8465))
     (not (= A2 8466))
     (not (= A2 8496))
     (not (= A2 8497))
     (= A2 8512)
     (= I1 (- 256))
     (= I 0)
     (<= 0 K2)
     (<= 0 X1)
     (<= 0 P1)
     (<= 0 N1)
     (<= 0 V)
     (<= 0 J)
     (<= 0 E)
     (<= 0 L2)
     (not (<= J2 0))
     (= D2 8528)
     (= v_65 I1))
      )
      (inv_main198 H
             H1
             S
             V1
             K1
             D2
             E1
             Q
             G2
             M1
             I
             Z1
             S1
             A
             Y
             G
             M
             B2
             X
             L
             M2
             D
             Y1
             F1
             C1
             D1
             K
             T1
             P
             I1
             N
             U
             A1
             U1
             V
             P1
             N1
             C
             O1
             J2
             F
             A2
             B1
             L1
             F2
             I2
             Q1
             E2
             R1
             W
             T
             B
             W1
             R
             Z
             C2
             v_65
             X1
             K2
             L2
             J1
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 H
             R
             Y
             L
             G2
             E
             G1
             J2
             A2
             V
             F2
             A
             K
             D1
             I1
             T
             W1
             U1
             E2
             W
             M1
             B
             S1
             V1
             H1
             N
             E1
             I
             G
             L1
             K2
             Z
             U
             J1
             L2
             I2
             C
             A1
             O
             B1
             M2
             J
             K1
             Z1
             F1
             C1
             B2
             M
             D2
             S
             H2
             O1
             Y1
             P
             P1
             N1
             Q
             C2
             X
             F
             R1
             X1)
        (and (= Q1 0)
     (not (= L1 (- 256)))
     (not (= E 12292))
     (not (= E 16384))
     (not (= E 8192))
     (not (= E 24576))
     (not (= E 8195))
     (not (= E 8480))
     (not (= E 8481))
     (not (= E 8482))
     (not (= E 8464))
     (not (= E 8465))
     (not (= E 8466))
     (not (= E 8496))
     (not (= E 8497))
     (not (= E 8512))
     (= E 8513)
     (= D 8528)
     (<= 0 C)
     (<= 0 I2)
     (<= 0 C2)
     (<= 0 X1)
     (<= 0 X)
     (<= 0 Q)
     (<= 0 F)
     (<= 0 L2)
     (= T1 1)
     (= v_65 L1))
      )
      (inv_main198 H
             R
             Y
             L
             G2
             D
             G1
             J2
             A2
             V
             Q1
             A
             K
             D1
             I1
             T
             W1
             U1
             E2
             W
             M1
             B
             S1
             V1
             H1
             N
             E1
             I
             G
             L1
             K2
             Z
             U
             J1
             L2
             I2
             C
             A1
             O
             B1
             M2
             E
             T1
             Z1
             F1
             C1
             B2
             M
             D2
             S
             H2
             O1
             Y1
             P
             P1
             N1
             v_65
             C2
             X
             F
             R1
             X1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 E1
             F
             I
             W1
             X
             C1
             L2
             D
             M1
             G1
             T1
             U1
             P
             S
             Y1
             K
             B
             Q
             M
             K2
             P1
             M2
             A1
             X1
             J
             W
             O1
             C
             R1
             S1
             R
             Q1
             Z
             V1
             C2
             N
             D2
             B1
             H1
             T
             E2
             I1
             N1
             O
             B2
             A
             V
             Y
             H
             L
             G
             Z1
             J2
             L1
             F2
             K1
             H2
             I2
             U
             J1
             G2
             A2)
        (and (= D1 8528)
     (not (= C1 12292))
     (not (= C1 16384))
     (not (= C1 8192))
     (not (= C1 24576))
     (not (= C1 8195))
     (not (= C1 8480))
     (not (= C1 8481))
     (not (= C1 8482))
     (not (= C1 8464))
     (not (= C1 8465))
     (not (= C1 8466))
     (not (= C1 8496))
     (not (= C1 8497))
     (not (= C1 8512))
     (= C1 8513)
     (= E 0)
     (<= 0 I2)
     (<= 0 H2)
     (<= 0 D2)
     (<= 0 C2)
     (<= 0 A2)
     (<= 0 J1)
     (<= 0 U)
     (<= 0 N)
     (not (<= F1 0))
     (= S1 (- 256))
     (= v_65 S1))
      )
      (inv_main198 E1
             F
             I
             W1
             X
             D1
             L2
             D
             M1
             G1
             E
             U1
             P
             S
             Y1
             K
             B
             Q
             M
             K2
             P1
             M2
             A1
             X1
             J
             W
             O1
             C
             R1
             S1
             R
             Q1
             Z
             V1
             C2
             N
             D2
             B1
             H1
             F1
             E2
             C1
             N1
             O
             B2
             A
             V
             Y
             H
             L
             G
             Z1
             J2
             L1
             F2
             K1
             v_65
             I2
             U
             J1
             G2
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main117 R1
             D
             F1
             A
             G
             I
             O1
             Q1
             B
             D2
             C
             C1
             I2
             M
             H2
             R
             K1
             K2
             F
             V1
             X1
             J1
             U
             B1
             T1
             O
             P
             E
             J
             M1
             Q
             T
             D1
             Y
             G2
             U1
             C2
             S1
             N1
             Y1
             W
             H
             F2
             S
             A2
             L
             K
             A1
             Z1
             H1
             B2
             N
             W1
             L1
             G1
             L2
             E1
             P1
             I1
             Z
             V
             J2)
        (and (= X 2)
     (not (= I 8560))
     (not (= I 8561))
     (not (= I 8448))
     (= I 8576)
     (not (= I 8545))
     (not (= I 12292))
     (not (= I 16384))
     (not (= I 8192))
     (not (= I 24576))
     (not (= I 8195))
     (not (= I 8480))
     (not (= I 8481))
     (not (= I 8482))
     (not (= I 8464))
     (not (= I 8465))
     (not (= I 8466))
     (not (= I 8496))
     (not (= I 8497))
     (not (= I 8512))
     (not (= I 8513))
     (not (= I 8528))
     (not (= I 8529))
     (not (= I 8544))
     (<= 0 J2)
     (<= 0 G2)
     (<= 0 C2)
     (<= 0 U1)
     (<= 0 P1)
     (<= 0 I1)
     (<= 0 E1)
     (<= 0 Z)
     (not (<= X 0))
     (= E2 8466))
      )
      (inv_main198 R1
             D
             F1
             A
             G
             E2
             O1
             Q1
             B
             D2
             C
             C1
             I2
             M
             H2
             R
             K1
             K2
             F
             V1
             X1
             J1
             U
             B1
             T1
             O
             P
             E
             J
             M1
             Q
             T
             D1
             Y
             G2
             U1
             C2
             S1
             N1
             X
             W
             I
             F2
             S
             A2
             L
             K
             A1
             Z1
             H1
             B2
             N
             W1
             L1
             G1
             L2
             E1
             P1
             I1
             Z
             V
             J2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main117 B2
             P1
             N
             K
             E1
             T
             A2
             H1
             N2
             D2
             S
             M
             Y1
             Z1
             O1
             X1
             C
             S1
             A
             U1
             A1
             G2
             O
             K2
             Z
             M2
             Q
             J2
             E
             D
             G
             P
             R
             M1
             I1
             L
             E2
             W1
             F2
             J1
             H2
             F1
             L1
             I2
             J
             N1
             C2
             D1
             K1
             H
             X
             Y
             C1
             B1
             R1
             B
             I
             T1
             L2
             U
             F
             W)
        (and (= G1 8592)
     (not (= V 2))
     (not (= T 8560))
     (not (= T 8561))
     (not (= T 8448))
     (= T 8576)
     (not (= T 8545))
     (not (= T 12292))
     (not (= T 16384))
     (not (= T 8192))
     (not (= T 24576))
     (not (= T 8195))
     (not (= T 8480))
     (not (= T 8481))
     (not (= T 8482))
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
     (<= 0 L2)
     (<= 0 E2)
     (<= 0 T1)
     (<= 0 I1)
     (<= 0 W)
     (<= 0 U)
     (<= 0 L)
     (<= 0 I)
     (not (<= V1 0))
     (not (<= V 0))
     (= Q1 0))
      )
      (inv_main198 B2
             P1
             N
             K
             E1
             G1
             A2
             H1
             N2
             D2
             Q1
             M
             Y1
             Z1
             O1
             X1
             C
             S1
             A
             U1
             A1
             G2
             O
             K2
             Z
             M2
             Q
             J2
             E
             D
             G
             P
             R
             M1
             I1
             L
             E2
             W1
             F2
             V1
             H2
             T
             L1
             I2
             J
             N1
             C2
             D1
             K1
             H
             X
             Y
             C1
             B1
             R1
             B
             I
             T1
             L2
             U
             F
             W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main117 P
             A
             W
             J2
             C1
             U1
             J
             Z1
             B2
             C
             V
             A2
             K1
             I1
             F2
             S1
             L2
             E1
             S
             I2
             X
             T
             O1
             A1
             B1
             I
             W1
             L1
             Q1
             F1
             N1
             N
             G1
             Y
             M1
             X1
             R1
             T1
             G2
             M
             E
             C2
             P1
             O
             L
             D1
             D
             J1
             E2
             K
             U
             R
             D2
             F
             B
             H
             Y1
             G
             H1
             K2
             V1
             Q)
        (and (not (= U1 8560))
     (not (= U1 8561))
     (not (= U1 8448))
     (not (= U1 8576))
     (= U1 8577)
     (not (= U1 8545))
     (not (= U1 12292))
     (not (= U1 16384))
     (not (= U1 8192))
     (not (= U1 24576))
     (not (= U1 8195))
     (not (= U1 8480))
     (not (= U1 8481))
     (not (= U1 8482))
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
     (= Z 2)
     (<= 0 Y1)
     (<= 0 X1)
     (<= 0 R1)
     (<= 0 M1)
     (<= 0 H1)
     (<= 0 Q)
     (<= 0 G)
     (<= 0 K2)
     (not (<= Z 0))
     (= H2 8466))
      )
      (inv_main198 P
             A
             W
             J2
             C1
             H2
             J
             Z1
             B2
             C
             V
             A2
             K1
             I1
             F2
             S1
             L2
             E1
             S
             I2
             X
             T
             O1
             A1
             B1
             I
             W1
             L1
             Q1
             F1
             N1
             N
             G1
             Y
             M1
             X1
             R1
             T1
             G2
             Z
             E
             U1
             P1
             O
             L
             D1
             D
             J1
             E2
             K
             U
             R
             D2
             F
             B
             H
             Y1
             G
             H1
             K2
             V1
             Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main117 F
             G1
             U
             L1
             F2
             F1
             C2
             D
             Y1
             C
             J
             J1
             P1
             R1
             E2
             G
             K1
             U1
             K
             E1
             Q
             A1
             H1
             N2
             V1
             Q1
             N1
             S
             R
             K2
             O
             M
             Z
             M1
             M2
             I1
             W1
             O1
             P
             X1
             D1
             L
             X
             J2
             D2
             H
             B2
             I2
             W
             A2
             B1
             E
             Y
             T
             V
             L2
             I
             T1
             A
             Z1
             H2
             S1)
        (and (not (= F1 8560))
     (not (= F1 8561))
     (not (= F1 8448))
     (not (= F1 8576))
     (= F1 8577)
     (not (= F1 8545))
     (not (= F1 12292))
     (not (= F1 16384))
     (not (= F1 8192))
     (not (= F1 24576))
     (not (= F1 8195))
     (not (= F1 8480))
     (not (= F1 8481))
     (not (= F1 8482))
     (not (= F1 8464))
     (not (= F1 8465))
     (not (= F1 8466))
     (not (= F1 8496))
     (not (= F1 8497))
     (not (= F1 8512))
     (not (= F1 8513))
     (not (= F1 8528))
     (not (= F1 8529))
     (not (= F1 8544))
     (= C1 8592)
     (not (= N 2))
     (<= 0 A)
     (<= 0 Z1)
     (<= 0 W1)
     (<= 0 T1)
     (<= 0 S1)
     (<= 0 I1)
     (<= 0 I)
     (<= 0 M2)
     (not (<= B 0))
     (not (<= N 0))
     (= G2 0))
      )
      (inv_main198 F
             G1
             U
             L1
             F2
             C1
             C2
             D
             Y1
             C
             G2
             J1
             P1
             R1
             E2
             G
             K1
             U1
             K
             E1
             Q
             A1
             H1
             N2
             V1
             Q1
             N1
             S
             R
             K2
             O
             M
             Z
             M1
             M2
             I1
             W1
             O1
             P
             B
             D1
             F1
             X
             J2
             D2
             H
             B2
             I2
             W
             A2
             B1
             E
             Y
             T
             V
             L2
             I
             T1
             A
             Z1
             H2
             S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 E
             A2
             J2
             M2
             T
             G
             Z
             T1
             D2
             K2
             L2
             F
             N1
             X
             D1
             O
             K
             V1
             G1
             S1
             J
             I
             Q
             S
             W1
             V
             U
             C
             M1
             H1
             Q1
             B2
             F2
             H
             R1
             P1
             H2
             C2
             Y1
             C1
             B1
             Y
             L
             U1
             E1
             B
             L1
             F1
             I1
             X1
             O1
             Z1
             G2
             E2
             P
             A
             N
             A1
             W
             I2
             R
             J1)
        (and (not (= G 8560))
     (not (= G 8561))
     (not (= G 8448))
     (not (= G 8576))
     (not (= G 8577))
     (not (= G 8592))
     (not (= G 8593))
     (not (= G 8608))
     (not (= G 8609))
     (= G 8640)
     (not (= G 8545))
     (not (= G 12292))
     (not (= G 16384))
     (not (= G 8192))
     (not (= G 24576))
     (not (= G 8195))
     (not (= G 8480))
     (not (= G 8481))
     (not (= G 8482))
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
     (not (= F 0))
     (= D 3)
     (<= 0 I2)
     (<= 0 H2)
     (<= 0 R1)
     (<= 0 P1)
     (<= 0 J1)
     (<= 0 A1)
     (<= 0 W)
     (<= 0 N)
     (not (<= M 0))
     (= K1 0))
      )
      (inv_main198 E
             A2
             J2
             M2
             T
             D
             Z
             T1
             D2
             K2
             K1
             F
             N1
             X
             D1
             O
             K
             V1
             G1
             S1
             J
             I
             Q
             S
             W1
             V
             U
             C
             M1
             H1
             Q1
             B2
             F2
             H
             R1
             P1
             H2
             C2
             Y1
             M
             B1
             G
             L
             U1
             E1
             B
             L1
             F1
             I1
             X1
             O1
             Z1
             G2
             E2
             P
             A
             N
             A1
             W
             I2
             R
             J1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 L2
             I2
             H
             X
             S
             P
             C1
             L
             V
             O1
             A2
             P1
             I1
             E1
             J1
             J
             U1
             L1
             D2
             X1
             J2
             B
             H1
             K2
             V1
             I
             H2
             U
             B1
             O
             S1
             D
             D1
             Q1
             Z1
             M2
             R
             W1
             C
             N1
             N
             K1
             B2
             G2
             C2
             R1
             W
             T1
             E
             E2
             Z
             Y
             K
             G
             M
             F
             A
             A1
             G1
             T
             Q
             Y1)
        (and (= P1 0)
     (= M1 8656)
     (not (= P 8560))
     (not (= P 8561))
     (not (= P 8448))
     (not (= P 8576))
     (not (= P 8577))
     (not (= P 8592))
     (not (= P 8593))
     (not (= P 8608))
     (not (= P 8609))
     (= P 8640)
     (not (= P 8545))
     (not (= P 12292))
     (not (= P 16384))
     (not (= P 8192))
     (not (= P 24576))
     (not (= P 8195))
     (not (= P 8480))
     (not (= P 8481))
     (not (= P 8482))
     (not (= P 8464))
     (not (= P 8465))
     (not (= P 8466))
     (not (= P 8496))
     (not (= P 8497))
     (not (= P 8512))
     (not (= P 8513))
     (not (= P 8528))
     (not (= P 8529))
     (not (= P 8544))
     (<= 0 A)
     (<= 0 Z1)
     (<= 0 Y1)
     (<= 0 G1)
     (<= 0 A1)
     (<= 0 T)
     (<= 0 R)
     (<= 0 M2)
     (not (<= F1 0))
     (= F2 0))
      )
      (inv_main198 L2
             I2
             H
             X
             S
             M1
             C1
             L
             V
             O1
             F2
             P1
             I1
             E1
             J1
             J
             U1
             L1
             D2
             X1
             J2
             B
             H1
             K2
             V1
             I
             H2
             U
             B1
             O
             S1
             D
             D1
             Q1
             Z1
             M2
             R
             W1
             C
             F1
             N
             P
             B2
             G2
             C2
             R1
             W
             T1
             E
             E2
             Z
             Y
             K
             G
             M
             F
             A
             A1
             G1
             T
             Q
             Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 C
             J2
             M1
             D2
             Z1
             M
             Q1
             K1
             S1
             Y
             I1
             A2
             U1
             K2
             P
             E1
             R
             F1
             K
             Y1
             R1
             C2
             W
             G1
             D
             E
             Q
             G
             V
             M2
             O
             B2
             U
             F
             L2
             O1
             I
             F2
             D1
             Z
             P1
             E2
             J
             A1
             A
             T1
             B
             I2
             H1
             S
             G2
             J1
             W1
             T
             H
             H2
             X
             V1
             N1
             X1
             C1
             N)
        (and (= L1 3)
     (= B1 0)
     (not (= M 8560))
     (not (= M 8561))
     (not (= M 8448))
     (not (= M 8576))
     (not (= M 8577))
     (not (= M 8592))
     (not (= M 8593))
     (not (= M 8608))
     (not (= M 8609))
     (not (= M 8640))
     (= M 8641)
     (not (= M 8545))
     (not (= M 12292))
     (not (= M 16384))
     (not (= M 8192))
     (not (= M 24576))
     (not (= M 8195))
     (not (= M 8480))
     (not (= M 8481))
     (not (= M 8482))
     (not (= M 8464))
     (not (= M 8465))
     (not (= M 8466))
     (not (= M 8496))
     (not (= M 8497))
     (not (= M 8512))
     (not (= M 8513))
     (not (= M 8528))
     (not (= M 8529))
     (not (= M 8544))
     (<= 0 X1)
     (<= 0 V1)
     (<= 0 O1)
     (<= 0 N1)
     (<= 0 X)
     (<= 0 N)
     (<= 0 I)
     (<= 0 L2)
     (not (<= L 0))
     (not (= A2 0)))
      )
      (inv_main198 C
             J2
             M1
             D2
             Z1
             L1
             Q1
             K1
             S1
             Y
             B1
             A2
             U1
             K2
             P
             E1
             R
             F1
             K
             Y1
             R1
             C2
             W
             G1
             D
             E
             Q
             G
             V
             M2
             O
             B2
             U
             F
             L2
             O1
             I
             F2
             D1
             L
             P1
             M
             J
             A1
             A
             T1
             B
             I2
             H1
             S
             G2
             J1
             W1
             T
             H
             H2
             X
             V1
             N1
             X1
             C1
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 B2
             C2
             D2
             L2
             X1
             F1
             V
             C
             Q1
             O
             K2
             K1
             G1
             B
             R
             J
             G2
             Q
             W1
             L
             A1
             Y
             G
             A
             P1
             Y1
             F
             X
             J2
             M
             I
             N1
             V1
             A2
             D1
             E2
             I2
             J1
             N
             C1
             S1
             I1
             O1
             Z1
             W
             F2
             E1
             E
             B1
             S
             L1
             M1
             T
             K
             H2
             H
             M2
             D
             U
             Z
             P
             R1)
        (and (= K1 0)
     (= H1 0)
     (not (= F1 8560))
     (not (= F1 8561))
     (not (= F1 8448))
     (not (= F1 8576))
     (not (= F1 8577))
     (not (= F1 8592))
     (not (= F1 8593))
     (not (= F1 8608))
     (not (= F1 8609))
     (not (= F1 8640))
     (= F1 8641)
     (not (= F1 8545))
     (not (= F1 12292))
     (not (= F1 16384))
     (not (= F1 8192))
     (not (= F1 24576))
     (not (= F1 8195))
     (not (= F1 8480))
     (not (= F1 8481))
     (not (= F1 8482))
     (not (= F1 8464))
     (not (= F1 8465))
     (not (= F1 8466))
     (not (= F1 8496))
     (not (= F1 8497))
     (not (= F1 8512))
     (not (= F1 8513))
     (not (= F1 8528))
     (not (= F1 8529))
     (not (= F1 8544))
     (<= 0 I2)
     (<= 0 E2)
     (<= 0 R1)
     (<= 0 D1)
     (<= 0 Z)
     (<= 0 U)
     (<= 0 D)
     (<= 0 M2)
     (not (<= U1 0))
     (= T1 8656))
      )
      (inv_main198 B2
             C2
             D2
             L2
             X1
             T1
             V
             C
             Q1
             O
             H1
             K1
             G1
             B
             R
             J
             G2
             Q
             W1
             L
             A1
             Y
             G
             A
             P1
             Y1
             F
             X
             J2
             M
             I
             N1
             V1
             A2
             D1
             E2
             I2
             J1
             N
             U1
             S1
             F1
             O1
             Z1
             W
             F2
             E1
             E
             B1
             S
             L1
             M1
             T
             K
             H2
             H
             M2
             D
             U
             Z
             P
             R1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main422 A1
             Z
             W
             N2
             U
             D2
             W1
             R1
             A
             K
             K2
             E1
             E2
             L1
             H2
             R
             G1
             H1
             K1
             D1
             M
             F1
             B
             Y1
             C2
             Q
             N1
             N
             F
             B1
             Y
             C1
             T1
             J
             S
             H
             G
             F2
             L2
             D
             V
             Q1
             A2
             M1
             O
             U1
             E
             J1
             B2
             Z1
             J2
             I2
             L
             M2
             X
             C
             P1
             O1
             T
             X1
             G2
             V1)
        (and (= X 2)
     (= P 8672)
     (not (= L 0))
     (= I 3)
     (not (= M2 0))
     (<= 0 X1)
     (<= 0 V1)
     (<= 0 P1)
     (<= 0 O1)
     (<= 0 T)
     (<= 0 S)
     (<= 0 H)
     (<= 0 G)
     (not (<= S1 0))
     (= I1 0)
     (= v_66 F))
      )
      (inv_main198 A1
             Z
             W
             N2
             U
             P
             W1
             R1
             A
             K
             I1
             E1
             E2
             L1
             H2
             R
             G1
             H1
             K1
             D1
             M
             F1
             B
             Y1
             C2
             Q
             N1
             N
             F
             B1
             Y
             C1
             v_66
             J
             S
             H
             G
             F2
             L2
             S1
             V
             Q1
             A2
             M1
             O
             U1
             E
             J1
             B2
             Z1
             J2
             I2
             L
             M2
             I
             C
             P1
             O1
             T
             X1
             G2
             V1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main422 C1
             D1
             A
             J2
             T1
             E2
             X1
             J
             L
             M
             D
             R1
             N2
             B2
             P
             B
             Y1
             A2
             M2
             I
             L1
             S
             D2
             V
             G
             H2
             U
             C2
             F
             M1
             Q1
             N
             Z1
             K
             B1
             W1
             O1
             H1
             K2
             H
             L2
             U1
             E1
             S1
             K1
             N1
             G2
             R
             O
             Z
             X
             Y
             T
             I2
             C
             W
             J1
             A1
             P1
             V1
             F2
             G1)
        (and (= C 3)
     (not (= I2 0))
     (= I1 8672)
     (= F1 4)
     (not (= T 0))
     (= Q 0)
     (<= 0 W1)
     (<= 0 V1)
     (<= 0 P1)
     (<= 0 O1)
     (<= 0 J1)
     (<= 0 G1)
     (<= 0 B1)
     (<= 0 A1)
     (not (<= E 0))
     (not (= C 2))
     (= v_66 F))
      )
      (inv_main198 C1
             D1
             A
             J2
             T1
             I1
             X1
             J
             L
             M
             Q
             R1
             N2
             B2
             P
             B
             Y1
             A2
             M2
             I
             L1
             S
             D2
             V
             G
             H2
             U
             C2
             F
             M1
             Q1
             N
             v_66
             K
             B1
             W1
             O1
             H1
             K2
             E
             L2
             U1
             E1
             S1
             K1
             N1
             G2
             R
             O
             Z
             X
             Y
             T
             I2
             F1
             W
             J1
             A1
             P1
             V1
             F2
             G1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main422 F2
             C
             D2
             I2
             J2
             I
             Z1
             N1
             K2
             B1
             Y
             R1
             Q
             S
             Z
             M2
             I1
             X
             D1
             X1
             C2
             C1
             V
             P
             A1
             J1
             D
             G
             N
             W1
             K1
             E1
             U
             Y1
             H2
             B2
             T1
             H
             U1
             J
             B
             R
             L1
             E
             G2
             F1
             Q1
             O
             E2
             A2
             F
             M
             A
             H1
             K
             S1
             O1
             P1
             T
             V1
             W
             L2)
        (and (not (= H1 0))
     (= G1 8672)
     (= L 0)
     (not (= K 2))
     (not (= K 3))
     (<= 0 H2)
     (<= 0 B2)
     (<= 0 V1)
     (<= 0 T1)
     (<= 0 P1)
     (<= 0 O1)
     (<= 0 T)
     (<= 0 L2)
     (not (<= M1 0))
     (not (= A 0))
     (= v_65 N))
      )
      (inv_main198 F2
             C
             D2
             I2
             J2
             G1
             Z1
             N1
             K2
             B1
             L
             R1
             Q
             S
             Z
             M2
             I1
             X
             D1
             X1
             C2
             C1
             V
             P
             A1
             J1
             D
             G
             N
             W1
             K1
             E1
             v_65
             Y1
             H2
             B2
             T1
             H
             U1
             M1
             B
             R
             L1
             E
             G2
             F1
             Q1
             O
             E2
             A2
             F
             M
             A
             H1
             K
             S1
             O1
             P1
             T
             V1
             W
             L2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main297 F2
             H
             S
             Z1
             U1
             J2
             P1
             C2
             L
             V1
             B2
             X1
             M
             A1
             L1
             G1
             O1
             O
             G
             F1
             A2
             K
             U
             B1
             R1
             I
             V
             S1
             J
             L2
             T1
             E2
             I1
             Z
             Q
             W1
             N1
             B
             A
             E1
             M1
             I2
             K2
             Y1
             H2
             D
             K1
             Q1
             C
             J1
             W
             N
             X
             C1
             D2
             H1
             F
             P
             M2
             R
             G2
             T)
        (and (= Y 8544)
     (= E 0)
     (<= 0 W1)
     (<= 0 N1)
     (<= 0 T)
     (<= 0 R)
     (<= 0 Q)
     (<= 0 P)
     (<= 0 F)
     (<= 0 M2)
     (not (<= D1 0))
     (not (= S1 0)))
      )
      (inv_main198 F2
             H
             S
             Z1
             U1
             Y
             P1
             C2
             L
             V1
             E
             X1
             M
             A1
             L1
             G1
             O1
             O
             G
             F1
             A2
             K
             U
             B1
             R1
             I
             V
             S1
             J
             L2
             T1
             E2
             I1
             Z
             Q
             W1
             N1
             B
             A
             D1
             M1
             I2
             K2
             Y1
             H2
             D
             K1
             Q1
             C
             J1
             W
             N
             X
             C1
             D2
             H1
             F
             P
             M2
             R
             G2
             T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main297 S1
             U
             T1
             M
             Y1
             E2
             L1
             M1
             T
             D
             N1
             F1
             S
             Z1
             B2
             E1
             G1
             J2
             Z
             X
             G
             Q1
             R1
             C1
             K1
             F
             H2
             W1
             K2
             E
             X1
             A2
             J1
             L
             H
             V1
             C
             A1
             J
             A
             G2
             Y
             F2
             Q
             W
             H1
             B1
             M2
             D2
             P1
             I
             I2
             O1
             U1
             C2
             O
             R
             V
             L2
             I1
             K
             D1)
        (and (= W1 0)
     (= N 0)
     (not (= H (- 30)))
     (<= 0 C)
     (<= 0 V1)
     (<= 0 I1)
     (<= 0 D1)
     (<= 0 V)
     (<= 0 R)
     (<= 0 H)
     (<= 0 L2)
     (not (<= P 0))
     (= B 8544))
      )
      (inv_main198 S1
             U
             T1
             M
             Y1
             B
             L1
             M1
             T
             D
             N
             F1
             S
             Z1
             B2
             E1
             G1
             J2
             Z
             X
             G
             Q1
             R1
             C1
             K1
             F
             H2
             W1
             K2
             E
             X1
             A2
             J1
             L
             H
             V1
             C
             A1
             J
             P
             G2
             Y
             F2
             Q
             W
             H1
             B1
             M2
             D2
             P1
             I
             I2
             O1
             U1
             C2
             O
             R
             V
             L2
             I1
             K
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main297 M1
             B1
             H2
             G
             R1
             C
             F
             G2
             W
             M
             R
             P
             Q
             U1
             O
             W1
             A
             D1
             A1
             I2
             Z1
             V1
             Z
             L1
             F1
             I
             G1
             E
             J1
             T
             S
             E1
             N1
             D2
             C1
             O1
             K1
             F2
             K2
             Y
             P1
             A2
             V
             Y1
             S1
             Q1
             E2
             L2
             L
             H
             H1
             K
             T1
             I1
             D
             X
             C2
             U
             X1
             J
             B2
             M2)
        (and (= J2 0)
     (= Z1 0)
     (= C1 (- 30))
     (not (= C1 (- 1)))
     (= E 0)
     (<= 0 C2)
     (<= 0 X1)
     (<= 0 O1)
     (<= 0 K1)
     (<= 0 C1)
     (<= 0 U)
     (<= 0 J)
     (<= 0 M2)
     (not (<= N 0))
     (= B 8544))
      )
      (inv_main198 M1
             B1
             H2
             G
             R1
             B
             F
             G2
             W
             M
             J2
             P
             Q
             U1
             O
             W1
             A
             D1
             A1
             I2
             Z1
             V1
             Z
             L1
             F1
             I
             G1
             E
             J1
             T
             S
             E1
             N1
             D2
             C1
             O1
             K1
             F2
             K2
             N
             P1
             A2
             V
             Y1
             S1
             Q1
             E2
             L2
             L
             H
             H1
             K
             T1
             I1
             D
             X
             C2
             U
             X1
             J
             B2
             M2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main297 D
             U
             K
             B1
             V
             S1
             D1
             H2
             O2
             T1
             A1
             G2
             Y
             R1
             D2
             W
             N
             B
             V1
             U1
             O1
             J1
             K2
             J
             S
             M1
             R
             Q
             L1
             G1
             I
             H1
             F
             O
             W1
             Q1
             I2
             I1
             J2
             H
             L2
             K1
             M
             Z
             B2
             X
             E
             C1
             F2
             A2
             E1
             Z1
             P
             F1
             N2
             E2
             L
             A
             N1
             T
             P1
             C2)
        (and (= C 512)
     (= Y1 0)
     (= W1 (- 30))
     (not (= W1 (- 1)))
     (not (= O1 0))
     (not (= H1 (- 4)))
     (not (= H1 (- 2)))
     (= Q 0)
     (= G 8544)
     (>= A2 65)
     (<= 0 A)
     (<= 0 I2)
     (<= 0 C2)
     (<= 0 W1)
     (<= 0 Q1)
     (<= 0 N1)
     (<= 0 T)
     (<= 0 L)
     (not (<= X1 0))
     (= (+ M2 (* (- 8) A2)) 0)
     (= v_67 H1)
     (= v_68 H1))
      )
      (inv_main198 D
             U
             K
             B1
             V
             G
             D1
             H2
             O2
             T1
             Y1
             G2
             Y
             R1
             D2
             W
             N
             B
             V1
             U1
             O1
             J1
             K2
             J
             S
             M1
             R
             Q
             L1
             G1
             I
             H1
             F
             O
             W1
             Q1
             I2
             I1
             J2
             X1
             L2
             K1
             M
             Z
             B2
             X
             E
             C1
             F2
             A2
             C
             Z1
             P
             F1
             N2
             E2
             L
             A
             v_67
             v_68
             M2
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main297 V1
             N1
             Y
             A1
             V
             I1
             E1
             D1
             N2
             G2
             L2
             X1
             G1
             J
             J1
             A2
             U1
             K
             O2
             J2
             D
             L1
             X
             E2
             C1
             M2
             H
             G
             S1
             W
             W1
             F
             K1
             N
             B1
             F2
             M1
             B2
             T1
             P1
             Q1
             Z
             O
             Z1
             H1
             B
             S
             O1
             C
             F1
             P
             L
             Y1
             R
             T
             M
             C2
             E
             Q
             A
             I2
             U)
        (and (not (= D 0))
     (= K2 0)
     (= R1 1024)
     (= B1 (- 30))
     (not (= B1 (- 1)))
     (= I 8544)
     (= G 0)
     (= F (- 4))
     (not (= F (- 2)))
     (>= F1 129)
     (<= 0 A)
     (<= 0 E)
     (<= 0 F2)
     (<= 0 C2)
     (<= 0 M1)
     (<= 0 B1)
     (<= 0 U)
     (<= 0 Q)
     (not (<= D2 0))
     (= (+ H2 (* (- 8) F1)) 0)
     (= v_67 F)
     (= v_68 F))
      )
      (inv_main198 V1
             N1
             Y
             A1
             V
             I
             E1
             D1
             N2
             G2
             K2
             X1
             G1
             J
             J1
             A2
             U1
             K
             O2
             J2
             D
             L1
             X
             E2
             C1
             M2
             H
             G
             S1
             W
             W1
             F
             K1
             N
             B1
             F2
             M1
             B2
             T1
             D2
             Q1
             Z
             O
             Z1
             H1
             B
             S
             O1
             C
             F1
             R1
             L
             Y1
             R
             T
             M
             C2
             E
             v_67
             v_68
             H2
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main327 C1
             G
             U1
             B2
             P
             H1
             R
             D2
             D
             F2
             E1
             V1
             I
             T
             J
             K1
             Y1
             B1
             W1
             Z1
             I1
             O1
             D1
             Q1
             T1
             A2
             L1
             Y
             X1
             G2
             H
             C2
             L
             Q
             C
             B
             A
             V
             S
             I2
             E
             P1
             E2
             O
             H2
             X
             J2
             U
             S1
             M
             J1
             F
             N1
             N
             A1
             R1
             W
             Z
             G1
             K
             M1
             F1)
        (and (not (= W1 (- 1)))
     (<= 0 G1)
     (<= 0 F1)
     (<= 0 Z)
     (<= 0 W)
     (<= 0 K)
     (<= 0 C)
     (<= 0 B)
     (<= 0 A)
     (= Z1 0))
      )
      (inv_main333 C1
             G
             U1
             B2
             P
             H1
             R
             D2
             D
             F2
             E1
             V1
             I
             T
             J
             K1
             Y1
             B1
             W1
             Z1
             I1
             O1
             D1
             Q1
             T1
             A2
             L1
             Y
             X1
             G2
             H
             C2
             L
             Q
             C
             B
             A
             V
             S
             I2
             E
             P1
             E2
             O
             H2
             X
             J2
             U
             S1
             M
             J1
             F
             N1
             N
             A1
             R1
             W
             Z
             G1
             K
             M1
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main327 G2
             F
             I1
             H2
             U
             I
             X1
             A1
             V1
             Q
             Q1
             K
             L1
             W1
             R
             A
             C1
             J1
             E1
             R1
             C
             O
             M
             E2
             G1
             S
             V
             E
             F1
             Z
             F2
             S1
             K1
             H1
             N
             G
             D
             L
             X
             Y
             T1
             D1
             D2
             P
             I2
             J2
             J
             B2
             M1
             B1
             H
             T
             Z1
             O1
             N1
             B
             W
             C2
             U1
             A2
             P1
             Y1)
        (and (= E1 (- 4))
     (not (= E1 (- 1)))
     (<= 0 C2)
     (<= 0 A2)
     (<= 0 Y1)
     (<= 0 U1)
     (<= 0 W)
     (<= 0 N)
     (<= 0 G)
     (<= 0 D)
     (not (= R1 0)))
      )
      (inv_main333 G2
             F
             I1
             H2
             U
             I
             X1
             A1
             V1
             Q
             Q1
             K
             L1
             W1
             R
             A
             C1
             J1
             E1
             R1
             C
             O
             M
             E2
             G1
             S
             V
             E
             F1
             Z
             F2
             S1
             K1
             H1
             N
             G
             D
             L
             X
             Y
             T1
             D1
             D2
             P
             I2
             J2
             J
             B2
             M1
             B1
             H
             T
             Z1
             O1
             N1
             B
             W
             C2
             U1
             A2
             P1
             Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main198 X
             F1
             A
             W
             G1
             T
             T1
             D1
             H2
             Q1
             R1
             N
             F
             L1
             I1
             E
             B2
             H1
             E2
             M1
             W1
             S
             U1
             O
             D2
             R
             U
             Y
             H
             A2
             L
             J2
             J
             Z
             O1
             S1
             J1
             V1
             K1
             Z1
             X1
             V
             C
             M
             Y1
             B
             I
             I2
             Q
             N1
             P
             C1
             P1
             G2
             C2
             B1
             A1
             E1
             F2
             D
             K
             G)
        (and (= U 0)
     (= C 0)
     (<= 0 F2)
     (<= 0 S1)
     (<= 0 O1)
     (<= 0 J1)
     (<= 0 E1)
     (<= 0 A1)
     (<= 0 G)
     (<= 0 D)
     (= I1 0))
      )
      (inv_main477 X
             F1
             A
             W
             G1
             T
             T1
             D1
             H2
             Q1
             R1
             N
             F
             L1
             I1
             E
             B2
             H1
             E2
             M1
             W1
             S
             U1
             O
             D2
             R
             U
             Y
             H
             A2
             L
             J2
             J
             Z
             O1
             S1
             J1
             V1
             K1
             Z1
             X1
             V
             C
             M
             Y1
             B
             I
             I2
             Q
             N1
             P
             C1
             P1
             G2
             C2
             B1
             A1
             E1
             F2
             D
             K
             G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main198 T1
             V
             H
             X
             P
             F2
             H2
             S
             F1
             Z1
             H1
             U1
             W1
             A
             O1
             E1
             Y1
             V1
             B2
             B1
             X1
             C
             K
             B
             I2
             S1
             D
             D2
             M
             Q
             J2
             I1
             N1
             L1
             A2
             G1
             R
             L
             G
             T
             P1
             K1
             A1
             U
             D1
             M1
             J1
             Z
             Y
             K2
             I
             O
             R1
             W
             Q1
             G2
             E
             N
             J
             F
             C2
             E2)
        (and (= A1 0)
     (= D 0)
     (<= 0 E2)
     (<= 0 A2)
     (<= 0 G1)
     (<= 0 R)
     (<= 0 N)
     (<= 0 J)
     (<= 0 F)
     (<= 0 E)
     (not (<= C1 0))
     (not (= O1 0)))
      )
      (inv_main477 T1
             V
             H
             X
             P
             F2
             H2
             S
             F1
             Z1
             H1
             U1
             W1
             A
             O1
             E1
             Y1
             V1
             B2
             B1
             X1
             C
             K
             B
             I2
             S1
             D
             D2
             M
             Q
             J2
             I1
             N1
             L1
             A2
             G1
             R
             L
             G
             C1
             P1
             K1
             A1
             U
             D1
             M1
             J1
             Z
             Y
             K2
             I
             O
             R1
             W
             Q1
             G2
             E
             N
             J
             F
             C2
             E2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main117 P
             M1
             G2
             Z
             S
             Y
             V
             E1
             E
             A
             D1
             X
             L
             L1
             D
             A1
             D2
             J2
             N
             U
             E2
             H
             K
             K1
             C
             R
             M
             O1
             R1
             I
             X1
             T
             T1
             V1
             C2
             F
             J1
             L2
             N1
             I1
             J
             I2
             F2
             H2
             Z1
             B1
             W1
             A2
             Q
             C1
             K2
             S1
             H1
             G1
             Y1
             W
             F1
             P1
             O
             Q1
             B2
             U1)
        (and (= Y1 1)
     (not (= Y 12292))
     (not (= Y 16384))
     (not (= Y 8192))
     (not (= Y 24576))
     (not (= Y 8195))
     (not (= Y 8480))
     (not (= Y 8481))
     (not (= Y 8482))
     (not (= Y 8464))
     (not (= Y 8465))
     (not (= Y 8466))
     (= Y 8496)
     (<= 0 C2)
     (<= 0 U1)
     (<= 0 Q1)
     (<= 0 P1)
     (<= 0 J1)
     (<= 0 F1)
     (<= 0 O)
     (<= 0 F)
     (= B 2)
     (= v_64 Y))
      )
      (inv_main271 P
             M1
             G2
             Z
             S
             Y
             V
             E1
             E
             A
             D1
             X
             L
             L1
             D
             A1
             D2
             J2
             N
             U
             E2
             H
             K
             K1
             C
             R
             M
             O1
             R1
             I
             X1
             T
             T1
             V1
             C2
             F
             J1
             L2
             N1
             G
             J
             v_64
             F2
             H2
             Z1
             B1
             W1
             A2
             Q
             C1
             K2
             S1
             H1
             G1
             B
             W
             F1
             P1
             O
             Q1
             B2
             U1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main117 F2
             G1
             E
             H
             L1
             C2
             V
             N1
             X1
             O
             P
             M
             J2
             I1
             D
             X
             C
             C1
             W
             I2
             B1
             K2
             G2
             S
             L
             E2
             W1
             B
             Q
             H1
             R
             V1
             T
             R1
             Q1
             S1
             F1
             J1
             I
             J
             U1
             M1
             K
             P1
             A1
             Z
             N
             H2
             F
             Y1
             O1
             A
             D2
             E1
             K1
             Y
             G
             Z1
             D1
             A2
             T1
             U)
        (and (not (= C2 16384))
     (not (= C2 8192))
     (not (= C2 24576))
     (not (= C2 8195))
     (not (= C2 8480))
     (not (= C2 8481))
     (not (= C2 8482))
     (not (= C2 8464))
     (not (= C2 8465))
     (not (= C2 8466))
     (= C2 8496)
     (not (= K1 1))
     (<= 0 A2)
     (<= 0 Z1)
     (<= 0 S1)
     (<= 0 Q1)
     (<= 0 F1)
     (<= 0 D1)
     (<= 0 U)
     (<= 0 G)
     (not (= C2 12292))
     (= v_63 C2))
      )
      (inv_main271 F2
             G1
             E
             H
             L1
             C2
             V
             N1
             X1
             O
             P
             M
             J2
             I1
             D
             X
             C
             C1
             W
             I2
             B1
             K2
             G2
             S
             L
             E2
             W1
             B
             Q
             H1
             R
             V1
             T
             R1
             Q1
             S1
             F1
             J1
             I
             B2
             U1
             v_63
             K
             P1
             A1
             Z
             N
             H2
             F
             Y1
             O1
             A
             D2
             E1
             K1
             Y
             G
             Z1
             D1
             A2
             T1
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main117 C2
             O
             K1
             R
             O1
             S
             B2
             A1
             R1
             K2
             D2
             F2
             F
             W
             G2
             Y
             J2
             J1
             M
             N1
             X1
             E
             G1
             G
             U1
             W1
             Q
             I
             U
             M1
             I1
             H2
             T1
             S1
             J
             Z
             L2
             C1
             X
             T
             Y1
             V
             F1
             V1
             A
             K
             E1
             B
             N
             H
             D1
             H1
             Q1
             B1
             D
             P1
             A2
             C
             Z1
             P
             L
             E2)
        (and (not (= S 12292))
     (not (= S 16384))
     (not (= S 8192))
     (not (= S 24576))
     (not (= S 8195))
     (not (= S 8480))
     (not (= S 8481))
     (not (= S 8482))
     (not (= S 8464))
     (not (= S 8465))
     (not (= S 8466))
     (not (= S 8496))
     (= S 8497)
     (= D 1)
     (<= 0 E2)
     (<= 0 A2)
     (<= 0 Z1)
     (<= 0 Z)
     (<= 0 P)
     (<= 0 J)
     (<= 0 C)
     (<= 0 L2)
     (= L1 2)
     (= v_64 S))
      )
      (inv_main271 C2
             O
             K1
             R
             O1
             S
             B2
             A1
             R1
             K2
             D2
             F2
             F
             W
             G2
             Y
             J2
             J1
             M
             N1
             X1
             E
             G1
             G
             U1
             W1
             Q
             I
             U
             M1
             I1
             H2
             T1
             S1
             J
             Z
             L2
             C1
             X
             I2
             Y1
             v_64
             F1
             V1
             A
             K
             E1
             B
             N
             H
             D1
             H1
             Q1
             B1
             L1
             P1
             A2
             C
             Z1
             P
             L
             E2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main117 K1
             R1
             C2
             W1
             F
             D2
             Q1
             B1
             I2
             J
             H
             I
             J2
             M
             P
             P1
             Z
             W
             B2
             S
             M1
             A
             U1
             A2
             E1
             E2
             B
             K2
             T1
             V1
             K
             O
             S1
             X
             I1
             H1
             Q
             D
             X1
             G1
             D1
             O1
             R
             F2
             A1
             G
             C
             Y
             C1
             V
             N
             L
             N1
             H2
             T
             Y1
             Z1
             U
             F1
             L1
             G2
             E)
        (and (not (= D2 16384))
     (not (= D2 8192))
     (not (= D2 24576))
     (not (= D2 8195))
     (not (= D2 8480))
     (not (= D2 8481))
     (not (= D2 8482))
     (not (= D2 8464))
     (not (= D2 8465))
     (not (= D2 8466))
     (not (= D2 8496))
     (= D2 8497)
     (not (= T 1))
     (<= 0 Z1)
     (<= 0 L1)
     (<= 0 I1)
     (<= 0 H1)
     (<= 0 F1)
     (<= 0 U)
     (<= 0 Q)
     (<= 0 E)
     (not (= D2 12292))
     (= v_63 D2))
      )
      (inv_main271 K1
             R1
             C2
             W1
             F
             D2
             Q1
             B1
             I2
             J
             H
             I
             J2
             M
             P
             P1
             Z
             W
             B2
             S
             M1
             A
             U1
             A2
             E1
             E2
             B
             K2
             T1
             V1
             K
             O
             S1
             X
             I1
             H1
             Q
             D
             X1
             J1
             D1
             v_63
             R
             F2
             A1
             G
             C
             Y
             C1
             V
             N
             L
             N1
             H2
             T
             Y1
             Z1
             U
             F1
             L1
             G2
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 S1
             H2
             G1
             E
             N1
             F2
             Q
             I2
             I1
             E1
             B
             D
             B2
             D1
             X
             F
             N
             S
             M
             K1
             B1
             V
             P1
             C2
             L
             P
             G2
             R
             O1
             X1
             Z
             G
             Q1
             H
             F1
             D2
             T1
             A
             W
             K
             A1
             W1
             A2
             I
             U
             J2
             Z1
             C1
             V1
             J1
             J
             O
             Y
             E2
             M1
             Y1
             U1
             L1
             C
             T
             H1
             R1)
        (and (not (= F2 16384))
     (not (= F2 8192))
     (not (= F2 24576))
     (not (= F2 8195))
     (not (= F2 8480))
     (not (= F2 8481))
     (not (= F2 8482))
     (not (= F2 8464))
     (not (= F2 8465))
     (= F2 8466)
     (<= 0 D2)
     (<= 0 U1)
     (<= 0 T1)
     (<= 0 R1)
     (<= 0 L1)
     (<= 0 F1)
     (<= 0 T)
     (<= 0 C)
     (not (= F2 12292))
     (= v_62 F2))
      )
      (inv_main254 S1
             H2
             G1
             E
             N1
             F2
             Q
             I2
             I1
             E1
             B
             D
             B2
             D1
             X
             F
             N
             S
             M
             K1
             B1
             V
             P1
             C2
             L
             P
             G2
             R
             O1
             X1
             Z
             G
             Q1
             H
             F1
             D2
             T1
             A
             W
             K
             A1
             v_62
             A2
             I
             U
             J2
             Z1
             C1
             V1
             J1
             J
             O
             Y
             E2
             M1
             Y1
             U1
             L1
             C
             T
             H1
             R1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 M
             L1
             P
             R1
             E
             U
             F1
             Y1
             W1
             H1
             G2
             V1
             W
             C2
             M1
             K
             U1
             A2
             D2
             E1
             Y
             B
             X
             F2
             Z
             J2
             N
             A
             B1
             T1
             I1
             N1
             H2
             B2
             J1
             S
             Q
             A1
             G1
             J
             C
             K1
             E2
             Q1
             O1
             Z1
             V
             D
             X1
             I
             H
             S1
             L
             C1
             T
             P1
             F
             I2
             D1
             R
             G
             O)
        (and (not (= U 16384))
     (not (= U 8192))
     (not (= U 24576))
     (not (= U 8195))
     (not (= U 8480))
     (not (= U 8481))
     (not (= U 8482))
     (= U 8464)
     (<= 0 J1)
     (<= 0 D1)
     (<= 0 S)
     (<= 0 R)
     (<= 0 Q)
     (<= 0 O)
     (<= 0 F)
     (<= 0 I2)
     (not (= U 12292))
     (= v_62 U))
      )
      (inv_main254 M
             L1
             P
             R1
             E
             U
             F1
             Y1
             W1
             H1
             G2
             V1
             W
             C2
             M1
             K
             U1
             A2
             D2
             E1
             Y
             B
             X
             F2
             Z
             J2
             N
             A
             B1
             T1
             I1
             N1
             H2
             B2
             J1
             S
             Q
             A1
             G1
             J
             C
             v_62
             E2
             Q1
             O1
             Z1
             V
             D
             X1
             I
             H
             S1
             L
             C1
             T
             P1
             F
             I2
             D1
             R
             G
             O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 F
             C2
             G
             Y
             D
             O
             K1
             L1
             T
             T1
             D1
             Q1
             Z
             X
             P1
             O1
             W
             Y1
             A2
             J2
             S1
             E1
             C1
             N
             F2
             N1
             D2
             B2
             L
             M
             G2
             J
             X1
             E
             I1
             R1
             I2
             A
             K
             H1
             S
             C
             U
             V
             E2
             Z1
             V1
             M1
             H
             J1
             H2
             I
             Q
             U1
             W1
             R
             F1
             B1
             G1
             P
             A1
             B)
        (and (not (= O 16384))
     (not (= O 8192))
     (not (= O 24576))
     (not (= O 8195))
     (not (= O 8480))
     (not (= O 8481))
     (not (= O 8482))
     (not (= O 8464))
     (= O 8465)
     (<= 0 R1)
     (<= 0 I1)
     (<= 0 G1)
     (<= 0 F1)
     (<= 0 B1)
     (<= 0 P)
     (<= 0 B)
     (<= 0 I2)
     (not (= O 12292))
     (= v_62 O))
      )
      (inv_main254 F
             C2
             G
             Y
             D
             O
             K1
             L1
             T
             T1
             D1
             Q1
             Z
             X
             P1
             O1
             W
             Y1
             A2
             J2
             S1
             E1
             C1
             N
             F2
             N1
             D2
             B2
             L
             M
             G2
             J
             X1
             E
             I1
             R1
             I2
             A
             K
             H1
             S
             v_62
             U
             V
             E2
             Z1
             V1
             M1
             H
             J1
             H2
             I
             Q
             U1
             W1
             R
             F1
             B1
             G1
             P
             A1
             B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main494 G1
             W
             D
             T1
             F1
             S1
             F2
             Z1
             D2
             K1
             U1
             I1
             F
             L
             R1
             K
             I
             G
             P
             Y1
             H
             E2
             B
             A
             G2
             U
             E
             X1
             N1
             H2
             J
             E1
             B2
             W1
             C
             C2
             I2
             J1
             O
             B1
             R
             J2
             Z
             M
             V1
             T
             S
             C1
             M1
             Q
             Q1
             O1
             V
             H1
             L1
             X
             Y
             N
             P1
             D1
             A1
             A2)
        (and (<= 0 A2)
     (<= 0 P1)
     (<= 0 D1)
     (<= 0 Y)
     (<= 0 N)
     (<= 0 C)
     (<= 0 I2)
     (<= 0 C2))
      )
      false
    )
  )
)

(check-sat)
(exit)
