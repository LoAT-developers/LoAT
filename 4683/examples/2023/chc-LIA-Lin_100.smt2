; ./prepared/tricera/sv-comp-2020/./mixed/s3_srvr_14.cil.c-1_000.smt2
(set-logic HORN)


(declare-fun |inv_main327| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main254| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main457| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main333| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main499| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main198| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main516| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main454| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main411| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main271| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main414| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main429| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main490| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main117| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main297| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main4| ( Int Int ) Bool)
(declare-fun |inv_main106| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        true
      )
      (inv_main4 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 K1
             H2
             R
             G2
             E2
             A
             Z
             J1
             W
             H1
             C
             Z1
             B1
             Y1
             L
             C2
             N1
             X1
             V1
             J
             C1
             Q1
             T1
             I
             G1
             E1
             J2
             F
             K
             A2
             N
             X
             U
             A1
             E
             S
             W1
             F1
             Y
             U1
             L1
             B2
             O
             D1
             P1
             D
             H
             D2
             Q
             P
             G
             M
             I1
             T
             M1
             F2
             S1
             O1
             V
             I2
             B
             R1)
        (and (not (= A 16384))
     (not (= A 8192))
     (not (= A 24576))
     (not (= A 8195))
     (not (= A 8480))
     (not (= A 8481))
     (not (= A 8482))
     (not (= A 8464))
     (not (= A 8465))
     (not (= A 8466))
     (not (= A 8496))
     (not (= A 8497))
     (not (= A 8512))
     (not (= A 8513))
     (not (= A 8528))
     (not (= A 8529))
     (= A 8544)
     (<= 0 W1)
     (<= 0 S1)
     (<= 0 R1)
     (<= 0 O1)
     (<= 0 V)
     (<= 0 S)
     (<= 0 E)
     (<= 0 I2)
     (not (= A 12292))
     (= v_62 A))
      )
      (inv_main327 K1
             H2
             R
             G2
             E2
             A
             Z
             J1
             W
             H1
             C
             Z1
             B1
             Y1
             L
             C2
             N1
             X1
             V1
             J
             C1
             Q1
             T1
             I
             G1
             E1
             J2
             F
             K
             A2
             N
             X
             U
             A1
             E
             S
             W1
             F1
             Y
             U1
             L1
             v_62
             O
             D1
             P1
             D
             H
             D2
             Q
             P
             G
             M
             I1
             T
             M1
             F2
             S1
             O1
             V
             I2
             B
             R1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 Q
             U1
             A
             J
             U
             W
             K
             Y1
             M
             G2
             L
             R
             D1
             T1
             Z1
             X1
             O1
             B2
             J2
             Y
             E1
             G1
             Z
             V
             Q1
             C
             E2
             H
             S
             M1
             I1
             N1
             H1
             F
             X
             I2
             C1
             B
             P
             F2
             A1
             N
             O
             A2
             H2
             V1
             I
             L1
             S1
             P1
             D2
             F1
             D
             C2
             R1
             T
             E
             K1
             B1
             G
             J1
             W1)
        (and (not (= W 12292))
     (not (= W 16384))
     (not (= W 8192))
     (not (= W 24576))
     (not (= W 8195))
     (not (= W 8480))
     (not (= W 8481))
     (not (= W 8482))
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
     (<= 0 W1)
     (<= 0 K1)
     (<= 0 C1)
     (<= 0 B1)
     (<= 0 X)
     (<= 0 G)
     (<= 0 E)
     (<= 0 I2)
     (= W 8545)
     (= v_62 W))
      )
      (inv_main327 Q
             U1
             A
             J
             U
             W
             K
             Y1
             M
             G2
             L
             R
             D1
             T1
             Z1
             X1
             O1
             B2
             J2
             Y
             E1
             G1
             Z
             V
             Q1
             C
             E2
             H
             S
             M1
             I1
             N1
             H1
             F
             X
             I2
             C1
             B
             P
             F2
             A1
             v_62
             O
             A2
             H2
             V1
             I
             L1
             S1
             P1
             D2
             F1
             D
             C2
             R1
             T
             E
             K1
             B1
             G
             J1
             W1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main198 X
             F1
             K1
             E2
             S
             S1
             V
             B2
             Y
             Y1
             C1
             F
             Q
             L1
             J1
             C2
             N1
             D2
             Q1
             I1
             U
             M
             A2
             E
             R
             E1
             I
             D
             N
             Z1
             Z
             F2
             H1
             J
             G1
             A1
             K
             R1
             T1
             K2
             X1
             B1
             O1
             G
             M1
             W
             C
             U1
             W1
             J2
             H
             I2
             O
             L
             G2
             T
             B
             P1
             H2
             P
             A
             D1)
        (and (not (= I 0))
     (<= 0 H2)
     (<= 0 P1)
     (<= 0 G1)
     (<= 0 D1)
     (<= 0 A1)
     (<= 0 P)
     (<= 0 K)
     (<= 0 B)
     (= V1 0))
      )
      (inv_main117 X
             F1
             K1
             E2
             S
             S1
             V
             B2
             Y
             Y1
             C1
             F
             Q
             L1
             J1
             C2
             N1
             D2
             Q1
             I1
             U
             M
             A2
             E
             R
             E1
             I
             D
             N
             Z1
             Z
             F2
             H1
             J
             G1
             A1
             K
             R1
             T1
             K2
             X1
             B1
             V1
             G
             M1
             W
             C
             U1
             W1
             J2
             H
             I2
             O
             L
             G2
             T
             B
             P1
             H2
             P
             A
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main198 H
             Q
             D1
             V
             I1
             K1
             F
             Y
             L
             Q1
             J
             F2
             D2
             W
             E
             N
             J1
             O
             K2
             E2
             M1
             P1
             C2
             R1
             K
             M
             C1
             Z
             X
             H1
             J2
             I2
             Y1
             X1
             B2
             G
             A2
             C
             S
             T1
             D
             G2
             S1
             P
             F1
             U1
             T
             O1
             L1
             W1
             H2
             E1
             V1
             Z1
             R
             A
             I
             U
             B1
             B
             N1
             G1)
        (and (= C1 0)
     (= A1 0)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 G1)
     (<= 0 B1)
     (<= 0 U)
     (<= 0 I)
     (<= 0 G)
     (<= 0 B)
     (not (= S1 0)))
      )
      (inv_main117 H
             Q
             D1
             V
             I1
             K1
             F
             Y
             L
             Q1
             J
             F2
             D2
             W
             E
             N
             J1
             O
             K2
             E2
             M1
             P1
             C2
             R1
             K
             M
             C1
             Z
             X
             H1
             J2
             I2
             Y1
             X1
             B2
             G
             A2
             C
             S
             T1
             D
             G2
             A1
             P
             F1
             U1
             T
             O1
             L1
             W1
             H2
             E1
             V1
             Z1
             R
             A
             I
             U
             B1
             B
             N1
             G1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main499 E2
             H1
             G2
             T1
             P
             A
             X1
             F1
             M
             F2
             A1
             E
             A2
             K1
             S1
             Z
             K
             W
             D1
             U
             B2
             L
             H2
             Y1
             R1
             N1
             B1
             V
             O
             G
             P1
             R
             O1
             S
             N
             L1
             I2
             I
             J
             D
             H
             K2
             X
             E1
             T
             Q1
             G1
             Z1
             D2
             J2
             C1
             W1
             Y
             J1
             U1
             I1
             M1
             V1
             F
             C2
             C
             Q)
        (and (= B 0)
     (<= 0 I2)
     (<= 0 C2)
     (<= 0 V1)
     (<= 0 M1)
     (<= 0 L1)
     (<= 0 Q)
     (<= 0 N)
     (<= 0 F)
     (= I 0))
      )
      (inv_main117 E2
             H1
             G2
             T1
             P
             A
             X1
             F1
             M
             F2
             A1
             E
             A2
             K1
             S1
             Z
             K
             W
             D1
             U
             B2
             L
             H2
             Y1
             R1
             N1
             B1
             V
             O
             G
             P1
             R
             O1
             S
             N
             L1
             I2
             I
             J
             D
             H
             K2
             B
             E1
             T
             Q1
             G1
             Z1
             D2
             J2
             C1
             W1
             Y
             J1
             U1
             I1
             M1
             V1
             F
             C2
             C
             Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main499 F1
             R
             N
             Y
             D2
             T1
             H
             K
             N1
             K2
             U1
             V1
             E2
             O1
             W
             M
             E1
             J
             Z1
             D1
             B1
             E
             U
             Z
             O
             G
             D
             Q
             H2
             V
             A
             G2
             W1
             I1
             X
             R1
             I
             Y1
             H1
             J2
             T
             M1
             G1
             P1
             P
             X1
             C2
             L1
             S1
             J1
             C1
             A1
             A2
             I2
             L
             C
             S
             K1
             F2
             F
             B
             Q1)
        (and (not (= Y1 0))
     (= T1 M1)
     (<= 0 F2)
     (<= 0 R1)
     (<= 0 Q1)
     (<= 0 K1)
     (<= 0 X)
     (<= 0 S)
     (<= 0 I)
     (<= 0 F)
     (= B2 0))
      )
      (inv_main117 F1
             R
             N
             Y
             D2
             T1
             H
             K
             N1
             K2
             U1
             V1
             E2
             O1
             W
             M
             E1
             J
             Z1
             D1
             B1
             E
             U
             Z
             O
             G
             D
             Q
             H2
             V
             A
             G2
             W1
             I1
             X
             R1
             I
             Y1
             H1
             J2
             T
             M1
             B2
             P1
             P
             X1
             C2
             L1
             S1
             J1
             C1
             A1
             A2
             I2
             L
             C
             S
             K1
             F2
             F
             B
             Q1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main499 D1
             F1
             X1
             N1
             Z1
             V1
             U
             I1
             E
             G2
             Y
             G
             T
             T1
             R1
             F2
             K2
             H2
             C
             A
             E1
             I
             P1
             M
             D
             V
             C1
             H
             K
             P
             R
             J1
             W
             S
             H1
             B1
             A1
             I2
             M1
             C2
             F
             B2
             J
             L
             K1
             B
             E2
             U1
             Z
             L1
             Q
             Q1
             O1
             G1
             Y1
             N
             A2
             O
             D2
             S1
             W1
             X)
        (and (not (= V1 B2))
     (= J2 0)
     (<= 0 D2)
     (<= 0 A2)
     (<= 0 S1)
     (<= 0 H1)
     (<= 0 B1)
     (<= 0 A1)
     (<= 0 X)
     (<= 0 O)
     (not (= I2 0))
     (= v_63 V1))
      )
      (inv_main117 D1
             F1
             X1
             N1
             Z1
             V1
             U
             I1
             E
             G2
             Y
             G
             T
             T1
             R1
             F2
             K2
             H2
             C
             A
             E1
             I
             P1
             M
             D
             V
             C1
             H
             K
             P
             R
             J1
             W
             S
             H1
             B1
             A1
             I2
             M1
             C2
             v_63
             B2
             J2
             L
             K1
             B
             E2
             U1
             Z
             L1
             Q
             Q1
             O1
             G1
             Y1
             N
             A2
             O
             D2
             S1
             W1
             X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main106 U1
             W
             V1
             Q1
             E2
             D2
             N1
             G
             D1
             E
             Z
             X1
             F2
             U
             I
             Y1
             G1
             V
             H2
             R
             L
             C2
             O
             K2
             F1
             A1
             A
             M1
             I2
             L1
             C1
             M
             K1
             S
             T1
             B2
             K
             Z1
             A2
             W1
             P
             O1
             S1
             N
             H
             P1
             H1
             T
             J
             J2
             X
             I1
             D
             R1
             B1
             J1
             C
             G2
             F
             Y
             Q
             B)
        (and (= E1 (+ 1 E2))
     (= H (- 12288))
     (<= 0 G2)
     (<= 0 B2)
     (<= 0 T1)
     (<= 0 Y)
     (<= 0 K)
     (<= 0 F)
     (<= 0 C)
     (<= 0 B)
     (not (= G1 0)))
      )
      (inv_main117 U1
             W
             V1
             Q1
             E1
             D2
             N1
             G
             D1
             E
             Z
             X1
             F2
             U
             I
             Y1
             G1
             V
             H2
             R
             L
             C2
             O
             K2
             F1
             A1
             A
             M1
             I2
             L1
             C1
             M
             K1
             S
             T1
             B2
             K
             Z1
             A2
             W1
             P
             O1
             S1
             N
             H
             P1
             H1
             T
             J
             J2
             X
             I1
             D
             R1
             B1
             J1
             C
             G2
             F
             Y
             Q
             B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main106 V1
             P
             K2
             H
             V
             R
             Q1
             A1
             L
             D2
             X1
             O
             S
             P1
             J1
             E
             N1
             B
             O1
             F
             A2
             D1
             K1
             G2
             B1
             W1
             K
             C
             J
             E1
             R1
             I1
             Z1
             H1
             E2
             Y1
             A
             F2
             M1
             U1
             S1
             Q
             I2
             I
             N
             G
             Y
             B2
             X
             U
             W
             D
             F1
             H2
             L1
             T
             J2
             C2
             G1
             C1
             M
             T1)
        (and (= Z (+ 1 V))
     (not (= N (- 12288)))
     (not (= G (- 16384)))
     (<= 0 A)
     (<= 0 E2)
     (<= 0 C2)
     (<= 0 Y1)
     (<= 0 T1)
     (<= 0 G1)
     (<= 0 C1)
     (<= 0 J2)
     (not (= N1 0)))
      )
      (inv_main117 V1
             P
             K2
             H
             Z
             R
             Q1
             A1
             L
             D2
             X1
             O
             S
             P1
             J1
             E
             N1
             B
             O1
             F
             A2
             D1
             K1
             G2
             B1
             W1
             K
             C
             J
             E1
             R1
             I1
             Z1
             H1
             E2
             Y1
             A
             F2
             M1
             U1
             S1
             Q
             I2
             I
             N
             G
             Y
             B2
             X
             U
             W
             D
             F1
             H2
             L1
             T
             J2
             C2
             G1
             C1
             M
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main106 V
             F
             B1
             M1
             G
             Y
             H
             K
             M
             T1
             F1
             B
             D
             H2
             A2
             W1
             W
             J
             K2
             C2
             U1
             D2
             I
             O
             A1
             Q
             L1
             F2
             E2
             O1
             Z
             N1
             S
             C1
             J2
             T
             E
             G2
             B2
             V1
             L
             I2
             P1
             Q1
             C
             E1
             X
             P
             I1
             R1
             D1
             A
             Z1
             H1
             R
             X1
             S1
             K1
             N
             J1
             G1
             Y1)
        (and (not (= W 0))
     (= U (+ 1 G))
     (not (= C (- 12288)))
     (<= 0 Y1)
     (<= 0 S1)
     (<= 0 K1)
     (<= 0 J1)
     (<= 0 T)
     (<= 0 N)
     (<= 0 E)
     (<= 0 J2)
     (= E1 (- 16384)))
      )
      (inv_main117 V
             F
             B1
             M1
             U
             Y
             H
             K
             M
             T1
             F1
             B
             D
             H2
             A2
             W1
             W
             J
             K2
             C2
             U1
             D2
             I
             O
             A1
             Q
             L1
             F2
             E2
             O1
             Z
             N1
             S
             C1
             J2
             T
             E
             G2
             B2
             V1
             L
             I2
             P1
             Q1
             C
             E1
             X
             P
             I1
             R1
             D1
             A
             Z1
             H1
             R
             X1
             S1
             K1
             N
             J1
             G1
             Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main411 M
             J1
             L
             S1
             Q1
             Q
             J2
             F
             A1
             T1
             E
             C
             G
             I
             H1
             C1
             A2
             C2
             B
             P1
             X
             I1
             K2
             P
             B1
             G1
             H2
             W1
             D
             Z
             K1
             R1
             D2
             T
             X1
             F1
             I2
             W
             E2
             U
             G2
             Y
             O
             K
             M1
             N
             E1
             N1
             J
             H
             O1
             B2
             S
             Y1
             A
             U1
             V
             R
             Z1
             F2
             D1
             V1)
        (and (not (= A 7))
     (= A 10)
     (<= 0 I2)
     (<= 0 F2)
     (<= 0 Z1)
     (<= 0 X1)
     (<= 0 V1)
     (<= 0 F1)
     (<= 0 V)
     (<= 0 R)
     (not (= A 4)))
      )
      (inv_main516 M
             J1
             L
             S1
             Q1
             Q
             J2
             F
             A1
             T1
             E
             C
             G
             I
             H1
             C1
             A2
             C2
             B
             P1
             X
             I1
             K2
             P
             B1
             G1
             H2
             W1
             D
             Z
             K1
             R1
             D2
             T
             X1
             F1
             I2
             W
             E2
             L1
             G2
             Y
             O
             K
             M1
             N
             E1
             N1
             J
             H
             O1
             B2
             S
             Y1
             A
             U1
             V
             R
             Z1
             F2
             D1
             V1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main198 K1
             E1
             B
             U
             G1
             I1
             X
             H2
             G
             W1
             O1
             N1
             H
             H1
             L1
             Y1
             R
             U1
             V1
             T
             D2
             D
             B2
             G2
             A2
             C
             F1
             C1
             R1
             C2
             K
             Z1
             Z
             J2
             Y
             M1
             V
             A
             M
             S1
             J1
             Q1
             F2
             P
             Q
             L
             W
             D1
             X1
             A1
             I
             E2
             I2
             S
             J
             O
             P1
             T1
             B1
             N
             E
             F)
        (and (= Q1 8496)
     (not (= I1 8656))
     (= F1 0)
     (not (= Q (- 12288)))
     (not (= L (- 16384)))
     (<= 0 T1)
     (<= 0 P1)
     (<= 0 M1)
     (<= 0 B1)
     (<= 0 Y)
     (<= 0 V)
     (<= 0 N)
     (<= 0 F)
     (= F2 0))
      )
      (inv_main516 K1
             E1
             B
             U
             G1
             I1
             X
             H2
             G
             W1
             O1
             N1
             H
             H1
             L1
             Y1
             R
             U1
             V1
             T
             D2
             D
             B2
             G2
             A2
             C
             F1
             C1
             R1
             C2
             K
             Z1
             Z
             J2
             Y
             M1
             V
             A
             M
             S1
             J1
             Q1
             F2
             P
             Q
             L
             W
             D1
             X1
             A1
             I
             E2
             I2
             S
             J
             O
             P1
             T1
             B1
             N
             E
             F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 Q1
             A
             B1
             R
             C1
             R1
             J2
             T
             X1
             G1
             O1
             E2
             O
             M1
             G
             V
             J1
             J
             H
             A2
             F1
             F
             Z1
             N
             X
             W
             D
             E
             Y1
             K
             C
             B
             F2
             H1
             Z
             Y
             U1
             W1
             L
             T1
             M
             S
             Q
             N1
             L1
             G2
             D2
             I2
             K1
             H2
             S1
             U
             V1
             I
             C2
             P1
             K2
             D1
             P
             B2
             A1
             E1)
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
     (= R1 8528)
     (= I1 1)
     (not (= J (- 2097152)))
     (<= 0 B2)
     (<= 0 U1)
     (<= 0 E1)
     (<= 0 D1)
     (<= 0 Z)
     (<= 0 Y)
     (<= 0 P)
     (<= 0 K2)
     (not (= R1 12292))
     (= v_63 K)
     (= v_64 R1)
     (= v_65 J))
      )
      (inv_main297 Q1
             A
             B1
             R
             C1
             R1
             J2
             T
             X1
             G1
             O1
             E2
             O
             M1
             G
             V
             J1
             J
             H
             A2
             F1
             F
             Z1
             N
             X
             W
             D
             I1
             Y1
             K
             C
             B
             F2
             H1
             v_63
             Y
             U1
             W1
             L
             T1
             M
             v_64
             Q
             N1
             L1
             G2
             D2
             I2
             K1
             H2
             S1
             U
             V1
             I
             C2
             P1
             K2
             v_65
             P
             B2
             A1
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 H2
             N1
             V
             E2
             F1
             W1
             K2
             D2
             E1
             L
             C
             G1
             A
             M
             U
             R1
             C1
             W
             V1
             E
             B2
             L1
             G2
             M1
             Q1
             J1
             X1
             I1
             Z1
             X
             K1
             T1
             I
             F
             F2
             J
             P1
             A2
             A1
             D1
             O1
             S
             Y
             K
             S1
             O
             H
             R
             B
             Y1
             T
             J2
             U1
             H1
             D
             C2
             B1
             I2
             G
             P
             Z
             Q)
        (and (not (= W1 16384))
     (not (= W1 8192))
     (not (= W1 24576))
     (not (= W1 8195))
     (not (= W1 8480))
     (not (= W1 8481))
     (not (= W1 8482))
     (not (= W1 8464))
     (not (= W1 8465))
     (not (= W1 8466))
     (not (= W1 8496))
     (not (= W1 8497))
     (not (= W1 8512))
     (not (= W1 8513))
     (= W1 8528)
     (= W (- 2097152))
     (= N 0)
     (<= 0 I2)
     (<= 0 F2)
     (<= 0 P1)
     (<= 0 B1)
     (<= 0 Q)
     (<= 0 P)
     (<= 0 J)
     (<= 0 G)
     (not (= W1 12292))
     (= v_63 X)
     (= v_64 W1)
     (= v_65 W))
      )
      (inv_main297 H2
             N1
             V
             E2
             F1
             W1
             K2
             D2
             E1
             L
             C
             G1
             A
             M
             U
             R1
             C1
             W
             V1
             E
             B2
             L1
             G2
             M1
             Q1
             J1
             X1
             N
             Z1
             X
             K1
             T1
             I
             F
             v_63
             J
             P1
             A2
             A1
             D1
             O1
             v_64
             Y
             K
             S1
             O
             H
             R
             B
             Y1
             T
             J2
             U1
             H1
             D
             C2
             B1
             v_65
             G
             P
             Z
             Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 S1
             B2
             D
             M
             Y1
             R
             E
             K1
             J
             V1
             D2
             O1
             Q
             T1
             G
             M1
             N1
             H1
             E2
             W1
             V
             I2
             S
             U1
             K
             L
             P
             U
             K2
             B1
             J2
             Q1
             I1
             D1
             W
             F1
             Y
             I
             P1
             X1
             C
             H2
             X
             Z1
             G2
             A
             O
             F
             T
             C2
             R1
             C1
             J1
             Z
             E1
             A1
             F2
             H
             B
             N
             G1
             A2)
        (and (not (= H1 (- 2097152)))
     (not (= R 12292))
     (not (= R 16384))
     (not (= R 8192))
     (not (= R 24576))
     (not (= R 8195))
     (not (= R 8480))
     (not (= R 8481))
     (not (= R 8482))
     (not (= R 8464))
     (not (= R 8465))
     (not (= R 8466))
     (not (= R 8496))
     (not (= R 8497))
     (not (= R 8512))
     (not (= R 8513))
     (not (= R 8528))
     (= R 8529)
     (<= 0 F2)
     (<= 0 A2)
     (<= 0 F1)
     (<= 0 Y)
     (<= 0 W)
     (<= 0 N)
     (<= 0 H)
     (<= 0 B)
     (= L1 1)
     (= v_63 B1)
     (= v_64 R)
     (= v_65 H1))
      )
      (inv_main297 S1
             B2
             D
             M
             Y1
             R
             E
             K1
             J
             V1
             D2
             O1
             Q
             T1
             G
             M1
             N1
             H1
             E2
             W1
             V
             I2
             S
             U1
             K
             L
             P
             L1
             K2
             B1
             J2
             Q1
             I1
             D1
             v_63
             F1
             Y
             I
             P1
             X1
             C
             v_64
             X
             Z1
             G2
             A
             O
             F
             T
             C2
             R1
             C1
             J1
             Z
             E1
             A1
             F2
             v_65
             B
             N
             G1
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 N
             C1
             T
             U
             K2
             T1
             R1
             Q1
             M1
             F1
             Z1
             E
             E1
             Q
             H1
             Y
             J2
             E2
             B1
             I2
             A2
             R
             P1
             C2
             V1
             D1
             A1
             H2
             A
             H
             F
             P
             D
             L1
             U1
             O
             O1
             C
             L
             S
             X1
             N1
             G2
             S1
             J1
             K
             J
             I1
             G1
             Z
             W
             W1
             B2
             V
             D2
             G
             Y1
             M
             I
             F2
             B
             X)
        (and (not (= T1 12292))
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
     (= T1 8529)
     (= K1 0)
     (<= 0 F2)
     (<= 0 Y1)
     (<= 0 U1)
     (<= 0 O1)
     (<= 0 X)
     (<= 0 O)
     (<= 0 M)
     (<= 0 I)
     (= E2 (- 2097152))
     (= v_63 H)
     (= v_64 T1)
     (= v_65 E2))
      )
      (inv_main297 N
             C1
             T
             U
             K2
             T1
             R1
             Q1
             M1
             F1
             Z1
             E
             E1
             Q
             H1
             Y
             J2
             E2
             B1
             I2
             A2
             R
             P1
             C2
             V1
             D1
             A1
             K1
             A
             H
             F
             P
             D
             L1
             v_63
             O
             O1
             C
             L
             S
             X1
             v_64
             G2
             S1
             J1
             K
             J
             I1
             G1
             Z
             W
             W1
             B2
             V
             D2
             G
             Y1
             v_65
             I
             F2
             B
             X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 Q W1)
        (and (= C2 8464)
     (= Z1 1)
     (= T1 0)
     (= Q1 8464)
     (not (= K1 0))
     (= H1 0)
     (= U (- 1))
     (= S 0)
     (= R 0)
     (<= 0 X1)
     (<= 0 P1)
     (<= 0 O1)
     (<= 0 A1)
     (<= 0 L)
     (<= 0 K)
     (<= 0 J)
     (<= 0 C)
     (= G2 8464)
     (= v_63 I1)
     (= v_64 K1))
      )
      (inv_main106 G2
             W1
             C2
             K1
             L1
             Q1
             S1
             B2
             P
             G
             H
             N
             X
             Z1
             D2
             R1
             E2
             W
             F1
             G1
             A
             D
             Z
             A2
             M
             F2
             R
             E1
             V1
             U1
             B
             C1
             N1
             J1
             P1
             I1
             v_63
             v_64
             K2
             U
             E
             V
             S
             T1
             B1
             H2
             D1
             T
             M1
             J2
             I
             Y1
             O
             F
             H1
             I2
             O1
             K
             C
             A1
             Y
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 W1 O1)
        (and (= G2 8464)
     (= E2 8464)
     (= R1 (- 1))
     (= P1 0)
     (= I1 0)
     (= H1 0)
     (= W 1)
     (not (= P 0))
     (= H 8464)
     (= B 0)
     (<= 0 F2)
     (<= 0 Z1)
     (<= 0 L1)
     (<= 0 J1)
     (<= 0 E1)
     (<= 0 Z)
     (<= 0 T)
     (<= 0 Q)
     (= A 0)
     (= v_63 N)
     (= v_64 P))
      )
      (inv_main106 E2
             O1
             G2
             I1
             K1
             H
             D2
             U1
             O
             A2
             K2
             J
             D1
             W
             M1
             R
             C
             T1
             Y
             X
             E
             P
             C1
             B2
             F
             K
             A
             G1
             V1
             Q1
             S1
             V
             D
             Y1
             Z1
             N
             v_63
             v_64
             B1
             R1
             L
             G
             B
             H1
             H2
             S
             M
             J2
             C2
             I
             X1
             F1
             N1
             I2
             P1
             A1
             L1
             Q
             J1
             E1
             U
             Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 Z A2)
        (and (= G2 0)
     (= B2 8464)
     (= R1 8464)
     (= O1 1)
     (= J1 (- 1))
     (= I1 0)
     (= B1 0)
     (= T 0)
     (= I 0)
     (= L2 8464)
     (= K2 0)
     (<= 0 D2)
     (<= 0 C2)
     (<= 0 E1)
     (<= 0 D1)
     (<= 0 W)
     (<= 0 N)
     (<= 0 J)
     (<= 0 G)
     (= J2 0)
     (= v_64 H2))
      )
      (inv_main106 L2
             A2
             R1
             J2
             A1
             B2
             R
             F
             M1
             U1
             Y1
             Y
             Q
             O1
             L1
             P
             E
             Q1
             S
             V1
             I2
             K2
             C1
             A
             B
             T1
             B1
             K
             F2
             W1
             P1
             H1
             C
             X
             C2
             H2
             v_64
             I1
             K1
             J1
             F1
             V
             I
             G2
             L
             U
             S1
             X1
             Z1
             M
             H
             G1
             D
             O
             T
             E2
             E1
             J
             G
             D1
             N1
             W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main454 I1
             D
             N1
             G1
             F
             X1
             C1
             G2
             Y1
             S1
             P
             L1
             W1
             B1
             J
             O
             C
             A2
             K
             X
             I
             J1
             M1
             D1
             F2
             H1
             O1
             Z
             K2
             Q
             I2
             P1
             V
             A
             E2
             T1
             Q1
             U1
             L
             N
             H
             D2
             H2
             A1
             B2
             F1
             W
             R1
             U
             E1
             G
             K1
             V1
             L2
             Z1
             E
             M
             Y
             J2
             T
             R
             C2)
        (and (= Z1 3)
     (<= 0 J2)
     (<= 0 E2)
     (<= 0 C2)
     (<= 0 T1)
     (<= 0 Q1)
     (<= 0 Y)
     (<= 0 T)
     (<= 0 M)
     (= B 4))
      )
      (inv_main457 I1
             D
             N1
             G1
             F
             X1
             C1
             G2
             Y1
             S1
             P
             L1
             W1
             B1
             J
             O
             C
             A2
             K
             X
             I
             J1
             M1
             D1
             F2
             H1
             O1
             Z
             K2
             Q
             I2
             P1
             V
             A
             E2
             T1
             Q1
             U1
             L
             S
             H
             D2
             H2
             A1
             B2
             F1
             W
             R1
             U
             E1
             G
             K1
             V1
             L2
             B
             E
             M
             Y
             J2
             T
             R
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main454 C1
             W1
             T
             H2
             J
             L1
             R1
             S
             Z1
             S1
             Q1
             T1
             B
             O
             L2
             K1
             Z
             X
             Y
             K
             G2
             P
             Q
             W
             I
             F2
             B2
             G1
             F
             V1
             J2
             D2
             D
             C
             U1
             J1
             D1
             K2
             E2
             R
             F1
             L
             I1
             C2
             E1
             H1
             X1
             O1
             G
             A
             Y1
             M1
             I2
             N
             B1
             N1
             M
             A2
             H
             U
             A1
             E)
        (and (= B1 6)
     (not (= B1 3))
     (<= 0 A2)
     (<= 0 U1)
     (<= 0 J1)
     (<= 0 D1)
     (<= 0 U)
     (<= 0 M)
     (<= 0 H)
     (<= 0 E)
     (= P1 7))
      )
      (inv_main457 C1
             W1
             T
             H2
             J
             L1
             R1
             S
             Z1
             S1
             Q1
             T1
             B
             O
             L2
             K1
             Z
             X
             Y
             K
             G2
             P
             Q
             W
             I
             F2
             B2
             G1
             F
             V1
             J2
             D2
             D
             C
             U1
             J1
             D1
             K2
             E2
             V
             F1
             L
             I1
             C2
             E1
             H1
             X1
             O1
             G
             A
             Y1
             M1
             I2
             N
             P1
             N1
             M
             A2
             H
             U
             A1
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main454 N
             D1
             Z1
             G1
             W
             J
             C2
             W1
             H1
             S1
             X1
             X
             K
             J2
             E2
             Y1
             G
             V1
             U1
             M
             B1
             F1
             A1
             E1
             O1
             I2
             C1
             G2
             B2
             L2
             R1
             M1
             L
             T
             U
             B
             Q1
             O
             S
             Q
             C
             H2
             A
             J1
             I
             Y
             H
             Z
             D
             K2
             N1
             R
             F
             I1
             P
             V
             E
             D2
             L1
             F2
             K1
             A2)
        (and (= P 9)
     (not (= P 6))
     (not (= P 3))
     (<= 0 B)
     (<= 0 F2)
     (<= 0 D2)
     (<= 0 A2)
     (<= 0 Q1)
     (<= 0 L1)
     (<= 0 U)
     (<= 0 E)
     (= P1 10))
      )
      (inv_main457 N
             D1
             Z1
             G1
             W
             J
             C2
             W1
             H1
             S1
             X1
             X
             K
             J2
             E2
             Y1
             G
             V1
             U1
             M
             B1
             F1
             A1
             E1
             O1
             I2
             C1
             G2
             B2
             L2
             R1
             M1
             L
             T
             U
             B
             Q1
             O
             S
             T1
             C
             H2
             A
             J1
             I
             Y
             H
             Z
             D
             K2
             N1
             R
             F
             I1
             P1
             V
             E
             D2
             L1
             F2
             K1
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main454 I
             R
             K1
             Z
             D2
             P
             G1
             G
             A2
             C
             C2
             B2
             Y
             W1
             G2
             N1
             K
             B
             O
             V
             E1
             J2
             D
             U1
             H1
             X1
             F1
             H2
             A
             J
             Q
             I2
             P1
             U
             N
             R1
             O1
             E
             L
             C1
             H
             M
             T
             S
             I1
             M1
             Z1
             W
             S1
             E2
             A1
             F
             Y1
             X
             Q1
             K2
             L1
             B1
             D1
             T1
             J1
             V1)
        (and (not (= Q1 6))
     (not (= Q1 3))
     (<= 0 V1)
     (<= 0 T1)
     (<= 0 R1)
     (<= 0 O1)
     (<= 0 L1)
     (<= 0 D1)
     (<= 0 B1)
     (<= 0 N)
     (not (= Q1 9)))
      )
      (inv_main457 I
             R
             K1
             Z
             D2
             P
             G1
             G
             A2
             C
             C2
             B2
             Y
             W1
             G2
             N1
             K
             B
             O
             V
             E1
             J2
             D
             U1
             H1
             X1
             F1
             H2
             A
             J
             Q
             I2
             P1
             U
             N
             R1
             O1
             E
             L
             F2
             H
             M
             T
             S
             I1
             M1
             Z1
             W
             S1
             E2
             A1
             F
             Y1
             X
             Q1
             K2
             L1
             B1
             D1
             T1
             J1
             V1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 D1
             X
             F1
             C1
             P1
             C
             B2
             R1
             A
             V1
             T
             L1
             N1
             J2
             E
             E1
             K
             D
             R
             U
             C2
             G1
             B1
             O
             E2
             W
             I2
             N
             H
             J1
             A2
             Y1
             F
             J
             Q1
             H1
             W1
             H2
             M1
             S1
             K1
             B
             X1
             F2
             Y
             M
             Z1
             A1
             Q
             G2
             U1
             I
             P
             Z
             I1
             G
             O1
             D2
             S
             V
             L
             T1)
        (and (not (= C 8561))
     (not (= C 8448))
     (not (= C 8576))
     (not (= C 8577))
     (not (= C 8592))
     (not (= C 8593))
     (not (= C 8608))
     (not (= C 8609))
     (= C 8640)
     (not (= C 8545))
     (not (= C 12292))
     (not (= C 16384))
     (not (= C 8192))
     (not (= C 24576))
     (not (= C 8195))
     (not (= C 8480))
     (not (= C 8481))
     (not (= C 8482))
     (not (= C 8464))
     (not (= C 8465))
     (not (= C 8466))
     (not (= C 8496))
     (not (= C 8497))
     (not (= C 8512))
     (not (= C 8513))
     (not (= C 8528))
     (not (= C 8529))
     (not (= C 8544))
     (<= 0 D2)
     (<= 0 W1)
     (<= 0 T1)
     (<= 0 Q1)
     (<= 0 O1)
     (<= 0 H1)
     (<= 0 V)
     (<= 0 S)
     (not (= C 8560))
     (= v_62 C))
      )
      (inv_main411 D1
             X
             F1
             C1
             P1
             C
             B2
             R1
             A
             V1
             T
             L1
             N1
             J2
             E
             E1
             K
             D
             R
             U
             C2
             G1
             B1
             O
             E2
             W
             I2
             N
             H
             J1
             A2
             Y1
             F
             J
             Q1
             H1
             W1
             H2
             M1
             S1
             K1
             v_62
             X1
             F2
             Y
             M
             Z1
             A1
             Q
             G2
             U1
             I
             P
             Z
             I1
             G
             O1
             D2
             S
             V
             L
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 P1
             D1
             B
             Y1
             V1
             O1
             P
             U
             G
             M1
             X
             G1
             E2
             K
             B1
             Z
             H2
             B2
             F2
             C
             Q
             L1
             D2
             T
             D
             Z1
             F
             W
             V
             F1
             J1
             U1
             K1
             J
             I1
             N
             M
             I
             G2
             R
             O
             T1
             C2
             Q1
             N1
             H1
             R1
             E
             A1
             W1
             A2
             E1
             C1
             S1
             J2
             Y
             X1
             H
             S
             L
             A
             I2)
        (and (not (= O1 8560))
     (not (= O1 8561))
     (not (= O1 8448))
     (not (= O1 8576))
     (not (= O1 8577))
     (not (= O1 8592))
     (not (= O1 8593))
     (not (= O1 8608))
     (not (= O1 8609))
     (not (= O1 8640))
     (not (= O1 8545))
     (not (= O1 12292))
     (not (= O1 16384))
     (not (= O1 8192))
     (not (= O1 24576))
     (not (= O1 8195))
     (not (= O1 8480))
     (not (= O1 8481))
     (not (= O1 8482))
     (not (= O1 8464))
     (not (= O1 8465))
     (not (= O1 8466))
     (not (= O1 8496))
     (not (= O1 8497))
     (not (= O1 8512))
     (not (= O1 8513))
     (not (= O1 8528))
     (not (= O1 8529))
     (not (= O1 8544))
     (<= 0 X1)
     (<= 0 I1)
     (<= 0 S)
     (<= 0 N)
     (<= 0 M)
     (<= 0 L)
     (<= 0 H)
     (<= 0 I2)
     (= O1 8641)
     (= v_62 O1))
      )
      (inv_main411 P1
             D1
             B
             Y1
             V1
             O1
             P
             U
             G
             M1
             X
             G1
             E2
             K
             B1
             Z
             H2
             B2
             F2
             C
             Q
             L1
             D2
             T
             D
             Z1
             F
             W
             V
             F1
             J1
             U1
             K1
             J
             I1
             N
             M
             I
             G2
             R
             O
             v_62
             C2
             Q1
             N1
             H1
             R1
             E
             A1
             W1
             A2
             E1
             C1
             S1
             J2
             Y
             X1
             H
             S
             L
             A
             I2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main117 M
             F2
             E1
             J1
             I2
             G1
             C1
             A
             D1
             Z
             H
             D2
             Y
             N1
             E
             V1
             I
             E2
             R1
             X1
             V
             L
             B1
             P
             X
             Z1
             H2
             K1
             G2
             O
             U1
             L1
             S1
             W1
             B2
             J
             S
             G
             A1
             R
             K2
             O1
             D
             B
             A2
             C
             T1
             H1
             J2
             I1
             P1
             W
             Q1
             C2
             M1
             K
             N
             U
             T
             Q
             F1
             F)
        (and (not (= G1 12292))
     (not (= G1 16384))
     (not (= G1 8192))
     (not (= G1 24576))
     (not (= G1 8195))
     (not (= G1 8480))
     (not (= G1 8481))
     (= G1 8482)
     (<= 0 B2)
     (<= 0 U)
     (<= 0 T)
     (<= 0 S)
     (<= 0 Q)
     (<= 0 N)
     (<= 0 J)
     (<= 0 F)
     (= Y1 3))
      )
      (inv_main198 M
             F2
             E1
             J1
             I2
             Y1
             C1
             A
             D1
             Z
             H
             D2
             Y
             N1
             E
             V1
             I
             E2
             R1
             X1
             V
             L
             B1
             P
             X
             Z1
             H2
             K1
             G2
             O
             U1
             L1
             S1
             W1
             B2
             J
             S
             G
             A1
             R
             K2
             G1
             D
             B
             A2
             C
             T1
             H1
             J2
             I1
             P1
             W
             Q1
             C2
             M1
             K
             N
             U
             T
             Q
             F1
             F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main117 T
             X
             G2
             Y
             L1
             F1
             W1
             H2
             H
             B2
             E
             K
             X1
             Y1
             Z
             A1
             L2
             D1
             F
             O1
             P1
             N1
             Q
             M1
             J
             R
             S1
             M2
             F2
             G1
             C
             D
             J2
             E2
             J1
             W
             O
             V
             Z1
             Q1
             B1
             K1
             B
             N2
             P
             D2
             U1
             K2
             H1
             S
             I2
             T1
             C1
             G
             I
             U
             M
             R1
             O2
             N
             L
             A)
        (and (= A2 0)
     (= I1 0)
     (not (= F1 12292))
     (not (= F1 16384))
     (not (= F1 8192))
     (not (= F1 24576))
     (not (= F1 8195))
     (= F1 8480)
     (= E1 8482)
     (<= 0 A)
     (<= 0 R1)
     (<= 0 J1)
     (<= 0 W)
     (<= 0 O)
     (<= 0 N)
     (<= 0 M)
     (<= 0 O2)
     (not (<= V1 0))
     (= C2 8448))
      )
      (inv_main198 T
             X
             G2
             Y
             L1
             C2
             W1
             H2
             H
             B2
             I1
             K
             X1
             Y1
             Z
             A2
             L2
             D1
             F
             O1
             P1
             N1
             Q
             M1
             J
             R
             S1
             M2
             F2
             G1
             E1
             D
             J2
             E2
             J1
             W
             O
             V
             Z1
             V1
             B1
             F1
             B
             N2
             P
             D2
             U1
             K2
             H1
             S
             I2
             T1
             C1
             G
             I
             U
             M
             R1
             O2
             N
             L
             A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main117 D
             Q
             C
             B1
             U1
             G
             E2
             A2
             I1
             S
             F
             B2
             M2
             T
             D1
             S1
             P1
             H2
             P
             D2
             I
             R1
             A
             K1
             N
             G2
             L2
             J1
             G1
             K2
             O2
             Z
             F2
             A1
             J2
             J
             Z1
             V1
             E
             W1
             C2
             V
             X
             F1
             O1
             E1
             U
             Y1
             B
             Y
             C1
             X1
             Q1
             M
             O
             W
             H1
             K
             N1
             M1
             T1
             R)
        (and (= L 8448)
     (= H 0)
     (not (= G 12292))
     (not (= G 16384))
     (not (= G 8192))
     (not (= G 24576))
     (not (= G 8195))
     (not (= G 8480))
     (= G 8481)
     (= N2 0)
     (<= 0 J2)
     (<= 0 Z1)
     (<= 0 N1)
     (<= 0 M1)
     (<= 0 H1)
     (<= 0 R)
     (<= 0 K)
     (<= 0 J)
     (not (<= L1 0))
     (= I2 8482))
      )
      (inv_main198 D
             Q
             C
             B1
             U1
             L
             E2
             A2
             I1
             S
             H
             B2
             M2
             T
             D1
             N2
             P1
             H2
             P
             D2
             I
             R1
             A
             K1
             N
             G2
             L2
             J1
             G1
             K2
             I2
             Z
             F2
             A1
             J2
             J
             Z1
             V1
             E
             L1
             C2
             G
             X
             F1
             O1
             E1
             U
             Y1
             B
             Y
             C1
             X1
             Q1
             M
             O
             W
             H1
             K
             N1
             M1
             T1
             R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main117 G1
             Q
             G
             B1
             H1
             K
             R1
             P
             U
             B
             H
             I
             L
             B2
             V1
             J
             A
             D1
             A2
             F2
             I2
             H2
             T
             V
             C1
             T1
             E2
             M
             J2
             D2
             Z1
             R
             Y1
             O1
             K2
             I1
             E1
             X1
             A1
             O
             S
             P1
             L1
             K1
             N1
             U1
             D
             J1
             G2
             Z
             W
             C2
             E
             Q1
             F1
             L2
             Y
             W1
             F
             N2
             M2
             C)
        (and (= M1 8448)
     (= X 0)
     (= K 8560)
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
     (<= 0 K2)
     (<= 0 W1)
     (<= 0 I1)
     (<= 0 E1)
     (<= 0 Y)
     (<= 0 F)
     (<= 0 N2)
     (not (<= N 0))
     (= S1 8576))
      )
      (inv_main198 G1
             Q
             G
             B1
             H1
             M1
             R1
             P
             U
             B
             X
             I
             L
             B2
             V1
             J
             A
             D1
             A2
             F2
             I2
             H2
             T
             V
             C1
             T1
             E2
             M
             J2
             D2
             S1
             R
             Y1
             O1
             K2
             I1
             E1
             X1
             A1
             N
             S
             K
             L1
             K1
             N1
             U1
             D
             J1
             G2
             Z
             W
             C2
             E
             Q1
             F1
             L2
             Y
             W1
             F
             N2
             M2
             C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main117 G
             A2
             L
             X
             T1
             D
             N
             L1
             P1
             N2
             D2
             S1
             W
             M2
             J1
             F2
             M1
             N1
             T
             C2
             D1
             H
             F1
             R
             Z1
             F
             Q1
             J
             I1
             C
             K1
             K
             O
             V
             G1
             M
             A
             I2
             I
             P
             U1
             B2
             E2
             W1
             U
             S
             E1
             Q
             A1
             K2
             E
             Z
             X1
             Y1
             H2
             B
             H1
             J2
             L2
             G2
             C1
             B1)
        (and (= D 8561)
     (not (= D 8545))
     (not (= D 12292))
     (not (= D 16384))
     (not (= D 8192))
     (not (= D 24576))
     (not (= D 8195))
     (not (= D 8480))
     (not (= D 8481))
     (not (= D 8482))
     (not (= D 8464))
     (not (= D 8465))
     (not (= D 8466))
     (not (= D 8496))
     (not (= D 8497))
     (not (= D 8512))
     (not (= D 8513))
     (not (= D 8528))
     (not (= D 8529))
     (not (= D 8544))
     (= V1 8576)
     (= O1 8448)
     (= Y 0)
     (<= 0 A)
     (<= 0 L2)
     (<= 0 J2)
     (<= 0 G2)
     (<= 0 H1)
     (<= 0 G1)
     (<= 0 B1)
     (<= 0 M)
     (not (<= R1 0))
     (not (= D 8560)))
      )
      (inv_main198 G
             A2
             L
             X
             T1
             O1
             N
             L1
             P1
             N2
             Y
             S1
             W
             M2
             J1
             F2
             M1
             N1
             T
             C2
             D1
             H
             F1
             R
             Z1
             F
             Q1
             J
             I1
             C
             V1
             K
             O
             V
             G1
             M
             A
             I2
             I
             R1
             U1
             D
             E2
             W1
             U
             S
             E1
             Q
             A1
             K2
             E
             Z
             X1
             Y1
             H2
             B
             H1
             J2
             L2
             G2
             C1
             B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 C
             E2
             U1
             D1
             R
             T1
             M1
             U
             O
             Q1
             F1
             I1
             V1
             Y1
             H
             A2
             G2
             M2
             M
             F2
             T
             K2
             L1
             Y
             G1
             A1
             C1
             J
             L2
             B2
             Z1
             K1
             X1
             I2
             G
             Q
             F
             S1
             R1
             A
             W1
             N
             J2
             P1
             J1
             L
             B
             N1
             D2
             H1
             S
             E1
             X
             D
             C2
             W
             V
             I
             K
             B1
             H2
             O1)
        (and (not (= T1 8561))
     (not (= T1 8448))
     (not (= T1 8576))
     (not (= T1 8577))
     (= T1 8592)
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
     (= Z 8608)
     (= E 0)
     (<= 0 O1)
     (<= 0 B1)
     (<= 0 V)
     (<= 0 Q)
     (<= 0 K)
     (<= 0 I)
     (<= 0 G)
     (<= 0 F)
     (not (<= P 0))
     (not (= T1 8560)))
      )
      (inv_main198 C
             E2
             U1
             D1
             R
             Z
             M1
             U
             O
             Q1
             E
             I1
             V1
             Y1
             H
             A2
             G2
             M2
             M
             F2
             T
             K2
             L1
             Y
             G1
             A1
             C1
             J
             L2
             B2
             Z1
             K1
             X1
             I2
             G
             Q
             F
             S1
             R1
             P
             W1
             T1
             J2
             P1
             J1
             L
             B
             N1
             D2
             H1
             S
             E1
             X
             D
             C2
             W
             V
             I
             K
             B1
             H2
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 J1
             I1
             D2
             I
             B
             K2
             M
             B2
             H2
             I2
             L2
             O1
             C
             C1
             P
             Q
             U
             F
             A2
             Z
             W
             L
             D1
             U1
             Y1
             G1
             J
             M2
             X
             E1
             L1
             K
             A
             H
             C2
             G2
             S1
             J2
             Z1
             Y
             P1
             V1
             R
             A1
             M1
             F1
             X1
             B1
             G
             K1
             T1
             E2
             H1
             F2
             E
             R1
             D
             S
             W1
             O
             N
             V)
        (and (not (= K2 8561))
     (not (= K2 8448))
     (not (= K2 8576))
     (not (= K2 8577))
     (not (= K2 8592))
     (= K2 8593)
     (not (= K2 8545))
     (not (= K2 12292))
     (not (= K2 16384))
     (not (= K2 8192))
     (not (= K2 24576))
     (not (= K2 8195))
     (not (= K2 8480))
     (not (= K2 8481))
     (not (= K2 8482))
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
     (= Q1 0)
     (= N1 8608)
     (<= 0 G2)
     (<= 0 C2)
     (<= 0 W1)
     (<= 0 S1)
     (<= 0 V)
     (<= 0 S)
     (<= 0 O)
     (<= 0 D)
     (not (<= T 0))
     (not (= K2 8560)))
      )
      (inv_main198 J1
             I1
             D2
             I
             B
             N1
             M
             B2
             H2
             I2
             Q1
             O1
             C
             C1
             P
             Q
             U
             F
             A2
             Z
             W
             L
             D1
             U1
             Y1
             G1
             J
             M2
             X
             E1
             L1
             K
             A
             H
             C2
             G2
             S1
             J2
             Z1
             T
             P1
             K2
             R
             A1
             M1
             F1
             X1
             B1
             G
             K1
             T1
             E2
             H1
             F2
             E
             R1
             D
             S
             W1
             O
             N
             V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 I
             W
             U1
             A2
             C2
             M
             P1
             L
             O
             S
             D2
             J1
             J
             A1
             L1
             O1
             G1
             Z
             M2
             D
             F1
             M1
             R1
             K2
             B
             Z1
             Y1
             H2
             S1
             A
             H1
             U
             Y
             F
             Q1
             N1
             C
             E1
             X1
             G2
             D1
             N
             V1
             R
             P
             B1
             F2
             I2
             K
             L2
             J2
             G
             Q
             C1
             V
             W1
             K1
             E2
             H
             X
             I1
             T)
        (and (= T1 8640)
     (not (= M 8560))
     (not (= M 8561))
     (not (= M 8448))
     (not (= M 8576))
     (not (= M 8577))
     (not (= M 8592))
     (not (= M 8593))
     (= M 8608)
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
     (<= 0 C)
     (<= 0 E2)
     (<= 0 Q1)
     (<= 0 N1)
     (<= 0 K1)
     (<= 0 X)
     (<= 0 T)
     (<= 0 H)
     (not (<= E 0))
     (= B2 0))
      )
      (inv_main198 I
             W
             U1
             A2
             C2
             T1
             P1
             L
             O
             S
             B2
             J1
             J
             A1
             L1
             O1
             G1
             Z
             M2
             D
             F1
             M1
             R1
             K2
             B
             Z1
             Y1
             H2
             S1
             A
             H1
             U
             Y
             F
             Q1
             N1
             C
             E1
             X1
             E
             D1
             M
             V1
             R
             P
             B1
             F2
             I2
             K
             L2
             J2
             G
             Q
             C1
             V
             W1
             K1
             E2
             H
             X
             I1
             T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 F1
             C
             F2
             X
             E2
             A
             Z1
             L1
             M2
             H
             Z
             C1
             T1
             H2
             N1
             D1
             G2
             A1
             G1
             H1
             I1
             D2
             X1
             V
             U
             V1
             Y
             G
             K1
             U1
             A2
             S
             P
             J
             K
             I
             Q
             J1
             S1
             F
             R
             B
             B2
             W1
             C2
             L2
             M1
             P1
             O1
             D
             B1
             W
             E
             E1
             M
             O
             J2
             I2
             T
             R1
             Y1
             N)
        (and (not (= A 8561))
     (not (= A 8448))
     (not (= A 8576))
     (not (= A 8577))
     (not (= A 8592))
     (not (= A 8593))
     (not (= A 8608))
     (= A 8609)
     (not (= A 8545))
     (not (= A 12292))
     (not (= A 16384))
     (not (= A 8192))
     (not (= A 24576))
     (not (= A 8195))
     (not (= A 8480))
     (not (= A 8481))
     (not (= A 8482))
     (not (= A 8464))
     (not (= A 8465))
     (not (= A 8466))
     (not (= A 8496))
     (not (= A 8497))
     (not (= A 8512))
     (not (= A 8513))
     (not (= A 8528))
     (not (= A 8529))
     (not (= A 8544))
     (= Q1 0)
     (= L 8640)
     (<= 0 J2)
     (<= 0 I2)
     (<= 0 R1)
     (<= 0 T)
     (<= 0 Q)
     (<= 0 N)
     (<= 0 K)
     (<= 0 I)
     (not (<= K2 0))
     (not (= A 8560)))
      )
      (inv_main198 F1
             C
             F2
             X
             E2
             L
             Z1
             L1
             M2
             H
             Q1
             C1
             T1
             H2
             N1
             D1
             G2
             A1
             G1
             H1
             I1
             D2
             X1
             V
             U
             V1
             Y
             G
             K1
             U1
             A2
             S
             P
             J
             K
             I
             Q
             J1
             S1
             K2
             R
             A
             B2
             W1
             C2
             L2
             M1
             P1
             O1
             D
             B1
             W
             E
             E1
             M
             O
             J2
             I2
             T
             R1
             Y1
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main254 T1
             Z1
             W1
             O2
             S1
             L1
             N2
             G2
             H
             J2
             M
             E2
             W
             R1
             D
             Q
             G
             B2
             O1
             C1
             C
             A1
             N
             H2
             L2
             I1
             K
             B1
             K2
             O
             P2
             I
             F1
             D1
             M1
             Y
             F
             S
             B
             A
             K1
             X
             U1
             V1
             F2
             L
             V
             D2
             C2
             T
             X1
             Y1
             U
             M2
             I2
             E1
             Q1
             P
             N1
             A2
             R
             H1)
        (and (= I2 0)
     (= P1 0)
     (= J1 1)
     (= Z 8496)
     (= J 0)
     (<= 0 F)
     (<= 0 A2)
     (<= 0 Q1)
     (<= 0 N1)
     (<= 0 M1)
     (<= 0 H1)
     (<= 0 Y)
     (<= 0 P)
     (not (<= G1 0))
     (= E 1))
      )
      (inv_main198 T1
             Z1
             W1
             O2
             S1
             Z
             N2
             G2
             H
             J2
             J
             E2
             W
             R1
             D
             P1
             G
             B2
             O1
             C1
             C
             A1
             N
             H2
             L2
             I1
             K
             B1
             K2
             O
             P2
             I
             F1
             D1
             M1
             Y
             F
             S
             B
             G1
             K1
             X
             U1
             E
             F2
             L
             V
             D2
             C2
             T
             X1
             Y1
             U
             M2
             J1
             E1
             Q1
             P
             N1
             A2
             R
             H1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main254 G1
             B
             F1
             E
             D2
             V
             D
             T
             H
             S
             C1
             A2
             E1
             O1
             I2
             J
             Q1
             G
             I
             D1
             K2
             X1
             N1
             N
             H1
             T1
             A1
             F
             P
             M
             O2
             P1
             S1
             K1
             R
             H2
             J1
             O
             Z1
             C2
             E2
             V1
             B2
             U1
             W1
             U
             R1
             M1
             K
             A
             Y
             B1
             W
             M2
             F2
             X
             I1
             Z
             L
             L1
             J2
             G2)
        (and (= L2 0)
     (not (= F2 0))
     (= Y1 1)
     (= Q 0)
     (<= 0 H2)
     (<= 0 G2)
     (<= 0 L1)
     (<= 0 J1)
     (<= 0 I1)
     (<= 0 Z)
     (<= 0 R)
     (<= 0 L)
     (not (<= N2 0))
     (= C 8496))
      )
      (inv_main198 G1
             B
             F1
             E
             D2
             C
             D
             T
             H
             S
             L2
             A2
             E1
             O1
             I2
             Q
             Q1
             G
             I
             D1
             K2
             X1
             N1
             N
             H1
             T1
             A1
             F
             P
             M
             O2
             P1
             S1
             K1
             R
             H2
             J1
             O
             Z1
             N2
             E2
             V1
             B2
             Y1
             W1
             U
             R1
             M1
             K
             A
             Y
             B1
             W
             M2
             F2
             X
             I1
             Z
             L
             L1
             J2
             G2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main271 P
             L
             B
             E1
             V
             X1
             G
             P1
             M1
             U
             T
             O1
             H2
             K
             L2
             K2
             R1
             D1
             I1
             M
             Y
             I2
             L1
             S
             G2
             E2
             H
             B2
             C
             C2
             C1
             Z
             S1
             H1
             A
             O
             V1
             D
             W1
             A1
             U1
             B1
             G1
             A2
             W
             F
             D2
             J1
             N1
             Z1
             I
             T1
             F2
             Q
             Q1
             E
             X
             J
             Y1
             F1
             N
             J2)
        (and (= K1 0)
     (= R 8656)
     (<= 0 A)
     (<= 0 J2)
     (<= 0 Y1)
     (<= 0 V1)
     (<= 0 F1)
     (<= 0 X)
     (<= 0 O)
     (<= 0 J)
     (not (<= A1 0))
     (not (= O1 0)))
      )
      (inv_main198 P
             L
             B
             E1
             V
             R
             G
             P1
             M1
             U
             K1
             O1
             H2
             K
             L2
             K2
             R1
             D1
             I1
             M
             Y
             I2
             L1
             S
             G2
             E2
             H
             B2
             C
             C2
             C1
             Z
             S1
             H1
             A
             O
             V1
             D
             W1
             A1
             U1
             B1
             G1
             A2
             W
             F
             D2
             J1
             N1
             Z1
             I
             T1
             F2
             Q
             Q1
             E
             X
             J
             Y1
             F1
             N
             J2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main271 Y
             M1
             Z1
             P
             G2
             B1
             B2
             C1
             M
             A1
             R
             W1
             Q
             Z
             J1
             H1
             D1
             X1
             U
             N
             I
             L
             C
             S1
             W
             C2
             K
             L1
             G1
             A
             I2
             H2
             A2
             G
             K2
             E2
             D
             F
             O1
             U1
             J2
             E
             F1
             P1
             Q1
             F2
             J
             Y1
             T
             N1
             E1
             H
             O
             X
             T1
             B
             R1
             S
             V
             V1
             D2
             L2)
        (and (= K1 8512)
     (= I1 0)
     (<= 0 E2)
     (<= 0 V1)
     (<= 0 R1)
     (<= 0 V)
     (<= 0 S)
     (<= 0 D)
     (<= 0 L2)
     (<= 0 K2)
     (not (<= U1 0))
     (= W1 0))
      )
      (inv_main198 Y
             M1
             Z1
             P
             G2
             K1
             B2
             C1
             M
             A1
             I1
             W1
             Q
             Z
             J1
             H1
             D1
             X1
             U
             N
             I
             L
             C
             S1
             W
             C2
             K
             L1
             G1
             A
             I2
             H2
             A2
             G
             K2
             E2
             D
             F
             O1
             U1
             J2
             E
             F1
             P1
             Q1
             F2
             J
             Y1
             T
             N1
             E1
             H
             O
             X
             T1
             B
             R1
             S
             V
             V1
             D2
             L2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 B
             W1
             Z
             W
             H2
             Z1
             B1
             B2
             T1
             Q1
             F1
             J
             P1
             X
             F2
             I
             J2
             C2
             G2
             U1
             O1
             X1
             J1
             P
             A2
             D1
             E
             K
             H1
             L1
             A
             D
             S1
             N1
             O
             I1
             K1
             T
             H
             R
             L
             F
             C1
             V1
             V
             Q
             I2
             Y
             M1
             Y1
             D2
             R1
             N
             C
             U
             A1
             E1
             S
             M
             E2
             G
             G1)
        (and (not (= Z1 8561))
     (= Z1 8448)
     (not (= Z1 8545))
     (not (= Z1 12292))
     (not (= Z1 16384))
     (not (= Z1 8192))
     (not (= Z1 24576))
     (not (= Z1 8195))
     (not (= Z1 8480))
     (not (= Z1 8481))
     (not (= Z1 8482))
     (not (= Z1 8464))
     (not (= Z1 8465))
     (not (= Z1 8466))
     (not (= Z1 8496))
     (not (= Z1 8497))
     (not (= Z1 8512))
     (not (= Z1 8513))
     (not (= Z1 8528))
     (not (= Z1 8529))
     (not (= Z1 8544))
     (not (<= 1 H))
     (<= 0 E2)
     (<= 0 K1)
     (<= 0 I1)
     (<= 0 G1)
     (<= 0 E1)
     (<= 0 S)
     (<= 0 O)
     (<= 0 M)
     (not (= Z1 8560))
     (= v_62 A))
      )
      (inv_main198 B
             W1
             Z
             W
             H2
             A
             B1
             B2
             T1
             Q1
             F1
             J
             P1
             X
             F2
             I
             J2
             C2
             G2
             U1
             O1
             X1
             J1
             P
             A2
             D1
             E
             K
             H1
             L1
             v_62
             D
             S1
             N1
             O
             I1
             K1
             T
             H
             R
             L
             Z1
             C1
             V1
             V
             Q
             I2
             Y
             M1
             Y1
             D2
             R1
             N
             C
             U
             A1
             E1
             S
             M
             E2
             G
             G1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main117 A
             R1
             A1
             S
             A2
             H1
             H
             T1
             S1
             I1
             C
             M
             P
             Z1
             G1
             K
             R
             P1
             Y
             O1
             T
             G2
             N1
             Z
             D1
             D2
             K2
             E2
             C2
             M1
             Q
             O
             G
             N
             Y1
             L
             V1
             V
             W
             X1
             I2
             J1
             F
             B
             U1
             J
             B2
             D
             F1
             F2
             L1
             K1
             I
             E1
             W1
             H2
             X
             B1
             U
             J2
             C1
             Q1)
        (and (not (= H1 8561))
     (= H1 8448)
     (not (= H1 8545))
     (not (= H1 12292))
     (not (= H1 16384))
     (not (= H1 8192))
     (not (= H1 24576))
     (not (= H1 8195))
     (not (= H1 8480))
     (not (= H1 8481))
     (not (= H1 8482))
     (not (= H1 8464))
     (not (= H1 8465))
     (not (= H1 8466))
     (not (= H1 8496))
     (not (= H1 8497))
     (not (= H1 8512))
     (not (= H1 8513))
     (not (= H1 8528))
     (not (= H1 8529))
     (not (= H1 8544))
     (= E 1)
     (<= 1 W)
     (<= 0 Y1)
     (<= 0 V1)
     (<= 0 Q1)
     (<= 0 B1)
     (<= 0 X)
     (<= 0 U)
     (<= 0 L)
     (<= 0 J2)
     (not (<= K1 0))
     (not (= H1 8560))
     (= v_63 Q)
     (= v_64 K1))
      )
      (inv_main198 A
             R1
             A1
             S
             A2
             Q
             H
             T1
             S1
             I1
             C
             M
             E
             Z1
             G1
             K
             R
             P1
             Y
             O1
             T
             G2
             N1
             Z
             D1
             D2
             K2
             E2
             C2
             M1
             v_63
             O
             G
             N
             Y1
             L
             V1
             V
             K1
             X1
             I2
             H1
             F
             B
             U1
             J
             B2
             D
             F1
             F2
             L1
             v_64
             I
             E1
             W1
             H2
             X
             B1
             U
             J2
             C1
             Q1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main414 F
             G2
             C
             J
             S
             H2
             B2
             M
             U1
             J1
             W1
             L
             G1
             M1
             V
             T
             O1
             Q1
             I1
             C1
             A2
             L1
             R1
             L2
             K1
             N1
             F2
             G
             I
             P1
             E
             T1
             Y
             J2
             O
             Y1
             N
             Q
             P
             X
             R
             A
             B1
             K
             E1
             W
             I2
             Z1
             U
             E2
             F1
             H1
             H
             Z
             K2
             C2
             A1
             D2
             X1
             D
             B
             S1)
        (and (= D1 3)
     (not (= L 0))
     (<= 0 D2)
     (<= 0 Y1)
     (<= 0 X1)
     (<= 0 S1)
     (<= 0 A1)
     (<= 0 O)
     (<= 0 N)
     (<= 0 D)
     (not (<= X 0))
     (= V1 0))
      )
      (inv_main198 F
             G2
             C
             J
             S
             D1
             B2
             M
             U1
             J1
             V1
             L
             G1
             M1
             V
             T
             O1
             Q1
             I1
             C1
             A2
             L1
             R1
             L2
             K1
             N1
             F2
             G
             I
             P1
             E
             T1
             Y
             J2
             O
             Y1
             N
             Q
             P
             X
             R
             A
             B1
             K
             E1
             W
             I2
             Z1
             U
             E2
             F1
             H1
             H
             Z
             K2
             C2
             A1
             D2
             X1
             D
             B
             S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main414 L
             S
             T1
             M1
             D1
             I2
             A1
             Q
             W
             H1
             N
             W1
             U
             P1
             K
             S1
             D
             B2
             E2
             Y
             T
             K2
             F
             C1
             C
             E
             F2
             X
             J1
             J
             N1
             A
             X1
             P
             I
             B1
             Y1
             K1
             G
             I1
             V
             Z
             V1
             B
             H2
             Z1
             G2
             R
             D2
             Q1
             O1
             J2
             O
             L1
             U1
             C2
             G1
             A2
             M
             F1
             H
             E1)
        (and (= R1 8656)
     (= L2 0)
     (<= 0 A2)
     (<= 0 Y1)
     (<= 0 G1)
     (<= 0 F1)
     (<= 0 E1)
     (<= 0 B1)
     (<= 0 M)
     (<= 0 I)
     (not (<= I1 0))
     (= W1 0))
      )
      (inv_main198 L
             S
             T1
             M1
             D1
             R1
             A1
             Q
             W
             H1
             L2
             W1
             U
             P1
             K
             S1
             D
             B2
             E2
             Y
             T
             K2
             F
             C1
             C
             E
             F2
             X
             J1
             J
             N1
             A
             X1
             P
             I
             B1
             Y1
             K1
             G
             I1
             V
             Z
             V1
             B
             H2
             Z1
             G2
             R
             D2
             Q1
             O1
             J2
             O
             L1
             U1
             C2
             G1
             A2
             M
             F1
             H
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main457 P
             O1
             K
             Q
             Q1
             B1
             M1
             P1
             Y
             S1
             U
             C1
             W
             R
             F1
             N
             E1
             K1
             L
             O
             D2
             V
             L1
             K2
             C2
             H
             Z1
             G
             Z
             W1
             X1
             I
             H1
             G2
             D1
             B
             F
             V1
             I2
             J1
             S
             M2
             U1
             A
             F2
             H2
             E
             N1
             R1
             E2
             A1
             Y1
             B2
             G1
             I1
             T
             L2
             A2
             J
             D
             M
             T1)
        (and (= J2 0)
     (not (= C1 0))
     (= X 8640)
     (<= 0 B)
     (<= 0 A2)
     (<= 0 T1)
     (<= 0 D1)
     (<= 0 J)
     (<= 0 F)
     (<= 0 D)
     (<= 0 L2)
     (not (<= J1 0))
     (= C 8448))
      )
      (inv_main198 P
             O1
             K
             Q
             Q1
             C
             M1
             P1
             Y
             S1
             J2
             C1
             W
             R
             F1
             N
             E1
             K1
             L
             O
             D2
             V
             L1
             K2
             C2
             H
             Z1
             G
             Z
             W1
             X
             I
             H1
             G2
             D1
             B
             F
             V1
             I2
             J1
             S
             M2
             U1
             A
             F2
             H2
             E
             N1
             R1
             E2
             A1
             Y1
             B2
             G1
             I1
             T
             L2
             A2
             J
             D
             M
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main457 H2
             O
             M2
             K2
             P
             P1
             A
             G2
             N
             X1
             H1
             S
             B2
             N1
             R1
             W
             C1
             J2
             J1
             M
             G1
             C2
             V1
             K1
             C
             L1
             S1
             D1
             Y
             Q1
             I1
             F1
             X
             W1
             K
             I
             V
             F2
             T
             R
             I2
             Z1
             E1
             L
             E2
             H
             A1
             Q
             J
             Z
             D
             B1
             D2
             A2
             U1
             G
             E
             F
             T1
             B
             Y1
             U)
        (and (= M1 0)
     (= S 0)
     (= L2 3)
     (<= 0 B)
     (<= 0 T1)
     (<= 0 V)
     (<= 0 U)
     (<= 0 K)
     (<= 0 I)
     (<= 0 F)
     (<= 0 E)
     (not (<= R 0))
     (= O1 8448))
      )
      (inv_main198 H2
             O
             M2
             K2
             P
             O1
             A
             G2
             N
             X1
             M1
             S
             B2
             N1
             R1
             W
             C1
             J2
             J1
             M
             G1
             C2
             V1
             K1
             C
             L1
             S1
             D1
             Y
             Q1
             L2
             F1
             X
             W1
             K
             I
             V
             F2
             T
             R
             I2
             Z1
             E1
             L
             E2
             H
             A1
             Q
             J
             Z
             D
             B1
             D2
             A2
             U1
             G
             E
             F
             T1
             B
             Y1
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main297 V
             J
             U1
             A
             H2
             Y1
             E2
             B1
             F2
             I
             K1
             Q1
             X
             X1
             L1
             G
             G2
             H
             S
             Y
             C2
             B2
             B
             O1
             E
             J1
             D
             T
             T1
             L2
             I1
             W1
             D1
             P
             H1
             D2
             K
             A2
             F1
             O
             G1
             J2
             C1
             N
             Z
             L
             A1
             K2
             N1
             I2
             W
             R
             M2
             V1
             C
             Q
             Z1
             M
             R1
             M1
             E1
             P1)
        (and (= H1 (- 30))
     (= H1 (- 1))
     (= U 1)
     (= T 0)
     (= F 8544)
     (<= 0 D2)
     (<= 0 Z1)
     (<= 0 R1)
     (<= 0 P1)
     (<= 0 M1)
     (<= 0 H1)
     (<= 0 M)
     (<= 0 K)
     (= S1 0))
      )
      (inv_main198 V
             J
             U1
             A
             H2
             F
             E2
             B1
             F2
             I
             S1
             Q1
             X
             X1
             L1
             G
             G2
             H
             S
             Y
             C2
             B2
             B
             O1
             E
             J1
             D
             T
             T1
             L2
             I1
             W1
             D1
             P
             H1
             D2
             K
             A2
             F1
             O
             G1
             J2
             U
             N
             Z
             L
             A1
             K2
             N1
             I2
             W
             R
             M2
             V1
             C
             Q
             Z1
             M
             R1
             M1
             E1
             P1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main297 Q
             B1
             J1
             A1
             D2
             H1
             C2
             G1
             R
             G2
             L1
             H2
             K1
             B2
             K
             A
             E1
             Q1
             D1
             V
             Z1
             U
             C1
             V1
             S
             D
             F
             T1
             P1
             H
             A2
             P
             J
             O1
             I1
             F2
             Y1
             I2
             Y
             U1
             E
             W
             E2
             L2
             F1
             T
             N1
             C
             M
             B
             S1
             N
             M2
             L
             K2
             X1
             W1
             I
             G
             X
             M1
             O)
        (and (not (= Z1 0))
     (= T1 0)
     (= R1 0)
     (= I1 (- 30))
     (not (= I1 (- 1)))
     (= Z 1)
     (= P (- 2))
     (<= 0 F2)
     (<= 0 Y1)
     (<= 0 W1)
     (<= 0 I1)
     (<= 0 X)
     (<= 0 O)
     (<= 0 I)
     (<= 0 G)
     (= J2 8544)
     (= v_65 P))
      )
      (inv_main198 Q
             B1
             J1
             A1
             D2
             J2
             C2
             G1
             R
             G2
             R1
             H2
             K1
             B2
             K
             A
             E1
             Q1
             D1
             V
             Z1
             U
             C1
             V1
             S
             D
             F
             T1
             P1
             H
             A2
             P
             J
             O1
             I1
             F2
             Y1
             I2
             Y
             U1
             E
             W
             Z
             L2
             F1
             T
             N1
             C
             M
             B
             S1
             N
             M2
             L
             K2
             X1
             W1
             I
             v_65
             X
             M1
             O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main297 U1
             L
             C2
             J
             S
             O
             Z
             E
             F2
             X1
             F
             P1
             Q1
             B2
             K
             W
             L1
             U
             K2
             N
             E2
             H2
             O1
             Y1
             I1
             A
             T
             P
             I2
             R
             D1
             T1
             G
             R1
             N1
             A1
             M1
             C1
             H
             D2
             M
             C
             Y
             V
             V1
             X
             F1
             B1
             S1
             Z1
             K1
             G1
             O2
             D
             I
             Q
             N2
             M2
             W1
             B
             J2
             L2)
        (and (= G2 1)
     (not (= E2 0))
     (= A2 0)
     (not (= T1 (- 4)))
     (not (= T1 (- 2)))
     (= N1 (- 30))
     (not (= N1 (- 1)))
     (= J1 512)
     (= H1 8544)
     (= P 0)
     (not (>= Z1 65))
     (<= 0 B)
     (<= 0 M2)
     (<= 0 L2)
     (<= 0 W1)
     (<= 0 N1)
     (<= 0 M1)
     (<= 0 A1)
     (<= 0 N2)
     (= (+ E1 (* (- 8) Z1)) 0)
     (= v_67 T1)
     (= v_68 T1))
      )
      (inv_main198 U1
             L
             C2
             J
             S
             H1
             Z
             E
             F2
             X1
             A2
             P1
             Q1
             B2
             K
             W
             L1
             U
             K2
             N
             E2
             H2
             O1
             Y1
             I1
             A
             T
             P
             I2
             R
             D1
             T1
             G
             R1
             N1
             A1
             M1
             C1
             H
             D2
             M
             C
             G2
             V
             V1
             X
             F1
             B1
             S1
             Z1
             J1
             G1
             O2
             D
             I
             Q
             N2
             M2
             v_67
             v_68
             E1
             L2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main297 O
             Y1
             U1
             F1
             C1
             S
             N1
             D
             R
             P1
             I2
             Z1
             R1
             W1
             V
             G2
             K
             N
             Q1
             X
             U
             K2
             B2
             B1
             B
             Q
             Y
             G1
             E2
             L2
             P
             O2
             D2
             H1
             T1
             V1
             M
             Z
             L1
             O1
             J1
             E1
             H
             S1
             T
             F
             F2
             K1
             N2
             C
             M1
             A2
             I1
             X1
             E
             L
             M2
             J
             A1
             D1
             I
             A)
        (and (= H2 8544)
     (= C2 0)
     (= T1 (- 30))
     (not (= T1 (- 1)))
     (= G1 0)
     (= W 1)
     (not (= U 0))
     (= G 1024)
     (= O2 (- 4))
     (not (= O2 (- 2)))
     (not (>= C 129))
     (<= 0 A)
     (<= 0 M2)
     (<= 0 V1)
     (<= 0 T1)
     (<= 0 D1)
     (<= 0 A1)
     (<= 0 M)
     (<= 0 J)
     (= (+ J2 (* (- 8) C)) 0)
     (= v_67 O2)
     (= v_68 O2))
      )
      (inv_main198 O
             Y1
             U1
             F1
             C1
             H2
             N1
             D
             R
             P1
             C2
             Z1
             R1
             W1
             V
             G2
             K
             N
             Q1
             X
             U
             K2
             B2
             B1
             B
             Q
             Y
             G1
             E2
             L2
             P
             O2
             D2
             H1
             T1
             V1
             M
             Z
             L1
             O1
             J1
             E1
             W
             S1
             T
             F
             F2
             K1
             N2
             C
             G
             A2
             I1
             X1
             E
             L
             M2
             J
             v_67
             v_68
             J2
             A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main327 K1
             X1
             K2
             L2
             P1
             W
             W1
             G1
             L
             U
             T
             S1
             H2
             E1
             A
             O1
             C1
             S
             F2
             M1
             R
             R1
             N1
             Z
             H1
             I2
             E2
             K
             A2
             J1
             I
             M
             V
             U1
             G2
             F
             F1
             C
             P
             C2
             Q
             D2
             Y
             Q1
             V1
             B1
             N
             E
             H
             Y1
             D
             X
             B
             M2
             G
             Z1
             B2
             A1
             O
             D1
             J
             I1)
        (and (not (= F2 (- 4)))
     (not (= F2 (- 1)))
     (= T1 0)
     (not (= M1 0))
     (= L1 8560)
     (<= 0 G2)
     (<= 0 B2)
     (<= 0 I1)
     (<= 0 F1)
     (<= 0 D1)
     (<= 0 A1)
     (<= 0 O)
     (<= 0 F)
     (= J2 1))
      )
      (inv_main198 K1
             X1
             K2
             L2
             P1
             L1
             W1
             G1
             L
             U
             T
             S1
             H2
             E1
             A
             O1
             C1
             S
             F2
             M1
             R
             R1
             N1
             Z
             H1
             T1
             E2
             K
             A2
             J1
             I
             M
             V
             U1
             G2
             F
             F1
             C
             P
             C2
             Q
             D2
             J2
             Q1
             V1
             B1
             N
             E
             H
             Y1
             D
             X
             B
             M2
             G
             Z1
             B2
             A1
             O
             D1
             J
             I1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main333 H1
             L2
             G1
             U
             M1
             J
             H2
             N1
             N
             W
             S1
             M2
             A
             X
             T1
             M
             O1
             V1
             F
             F2
             G2
             L1
             T
             I
             D1
             Q1
             I2
             X1
             W1
             Y
             D2
             O
             Q
             G
             U1
             V
             J1
             P1
             C1
             S
             C2
             E
             B
             C
             B1
             D
             K1
             L
             R1
             K
             E2
             A1
             F1
             K2
             J2
             R
             B2
             Z
             A2
             Z1
             E1
             P)
        (and (= I1 0)
     (not (= Y (- 256)))
     (= H 8560)
     (= F (- 2))
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 Z1)
     (<= 0 U1)
     (<= 0 J1)
     (<= 0 Z)
     (<= 0 V)
     (<= 0 P)
     (= Y1 1)
     (= v_65 Y))
      )
      (inv_main198 H1
             L2
             G1
             U
             M1
             H
             H2
             N1
             N
             W
             S1
             M2
             A
             X
             T1
             M
             O1
             V1
             F
             F2
             G2
             L1
             T
             I
             D1
             I1
             I2
             X1
             W1
             Y
             D2
             O
             Q
             G
             U1
             V
             J1
             P1
             C1
             S
             C2
             E
             Y1
             C
             B1
             D
             K1
             L
             R1
             K
             E2
             A1
             F1
             K2
             J2
             R
             B2
             Z
             A2
             Z1
             E1
             v_65)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main327 M
             F2
             V
             A
             U1
             M1
             B2
             A1
             B1
             Y
             E1
             K1
             D1
             G1
             Z1
             A2
             M2
             R1
             E2
             H
             D
             F1
             X
             C1
             Y1
             P
             S1
             Q
             U
             N
             K
             I1
             L
             C
             F
             J
             H1
             L1
             O
             G
             O1
             N1
             G2
             S
             R
             P1
             D2
             Q1
             W
             T
             B
             V1
             C2
             H2
             T1
             X1
             K2
             L2
             J1
             E
             J2
             Z)
        (and (= E2 (- 1))
     (= W1 1)
     (= I 8560)
     (<= 0 K2)
     (<= 0 J1)
     (<= 0 H1)
     (<= 0 Z)
     (<= 0 J)
     (<= 0 F)
     (<= 0 E)
     (<= 0 L2)
     (= I2 0))
      )
      (inv_main198 M
             F2
             V
             A
             U1
             I
             B2
             A1
             B1
             Y
             E1
             K1
             D1
             G1
             Z1
             A2
             M2
             R1
             E2
             H
             D
             F1
             X
             C1
             Y1
             I2
             S1
             Q
             U
             N
             K
             I1
             L
             C
             F
             J
             H1
             L1
             O
             G
             O1
             N1
             W1
             S
             R
             P1
             D2
             Q1
             W
             T
             B
             V1
             C2
             H2
             T1
             X1
             K2
             L2
             J1
             E
             J2
             Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main333 B
             D1
             P
             H1
             H2
             B2
             N
             U
             C
             N1
             K
             E1
             A1
             V1
             L
             F2
             W1
             G
             J
             W
             I1
             T1
             J2
             J1
             A
             M1
             V
             X
             M2
             I
             L2
             F1
             E
             Z
             C1
             S
             Q
             N2
             X1
             L1
             H
             G1
             R
             O2
             C2
             E2
             T
             K2
             P1
             Z1
             D
             S1
             U1
             M
             A2
             D2
             Y
             F
             R1
             Y1
             Q1
             K1)
        (and (= G2 1)
     (= O1 0)
     (= O 8448)
     (= I (- 256))
     (<= 0 Y1)
     (<= 0 R1)
     (<= 0 K1)
     (<= 0 C1)
     (<= 0 Y)
     (<= 0 S)
     (<= 0 Q)
     (<= 0 F)
     (not (<= B1 0))
     (= I2 8576)
     (= v_67 I))
      )
      (inv_main198 B
             D1
             P
             H1
             H2
             O
             N
             U
             C
             N1
             O1
             E1
             A1
             V1
             L
             F2
             W1
             G
             J
             W
             I1
             T1
             J2
             J1
             A
             G2
             V
             X
             M2
             I
             I2
             F1
             E
             Z
             C1
             S
             Q
             N2
             X1
             B1
             H
             G1
             R
             O2
             C2
             E2
             T
             K2
             P1
             Z1
             D
             S1
             U1
             M
             A2
             D2
             Y
             F
             R1
             Y1
             Q1
             v_67)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main333 A2
             W
             T
             P
             M2
             Q1
             U1
             E1
             F
             L1
             V
             W1
             V1
             O
             R
             O1
             J
             T1
             G2
             M
             B1
             B2
             Z1
             X1
             X
             Q
             L2
             K
             S1
             D
             A1
             C
             I1
             F2
             G1
             U
             A
             H2
             R1
             N2
             B
             N1
             E2
             J1
             Y
             L
             G
             C2
             K2
             F1
             E
             P1
             O2
             H
             I
             M1
             J2
             D2
             H1
             I2
             Y1
             D1)
        (and (not (= G2 (- 2)))
     (= K1 0)
     (= C1 1)
     (= Z 8448)
     (= S 8576)
     (<= 0 A)
     (<= 0 J2)
     (<= 0 I2)
     (<= 0 D2)
     (<= 0 H1)
     (<= 0 G1)
     (<= 0 D1)
     (<= 0 U)
     (not (<= N 0))
     (not (= D (- 256)))
     (= v_67 D))
      )
      (inv_main198 A2
             W
             T
             P
             M2
             Z
             U1
             E1
             F
             L1
             K1
             W1
             V1
             O
             R
             O1
             J
             T1
             G2
             M
             B1
             B2
             Z1
             X1
             X
             C1
             L2
             K
             S1
             D
             S
             C
             I1
             F2
             G1
             U
             A
             H2
             R1
             N
             B
             N1
             E2
             J1
             Y
             L
             G
             C2
             K2
             F1
             E
             P1
             O2
             H
             I
             M1
             J2
             D2
             H1
             I2
             Y1
             v_67)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 U1
             E1
             S1
             K2
             M2
             J
             X
             E2
             B2
             D2
             K
             Q1
             T
             R
             D
             G2
             Y
             O1
             E
             B
             J2
             G1
             O
             H
             A
             S
             V
             I
             G
             H1
             W1
             R1
             F
             A1
             M1
             Z
             N
             P1
             L1
             F1
             Y1
             M
             N1
             Z1
             A2
             C2
             P
             X1
             F2
             U
             C
             Q
             V1
             K1
             I2
             L2
             C1
             J1
             D1
             T1
             W
             I1)
        (and (not (= H1 (- 256)))
     (= B1 0)
     (= L 1)
     (not (= J 12292))
     (not (= J 16384))
     (not (= J 8192))
     (not (= J 24576))
     (not (= J 8195))
     (not (= J 8480))
     (not (= J 8481))
     (not (= J 8482))
     (not (= J 8464))
     (not (= J 8465))
     (not (= J 8466))
     (not (= J 8496))
     (not (= J 8497))
     (= J 8512)
     (<= 0 T1)
     (<= 0 M1)
     (<= 0 J1)
     (<= 0 I1)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 Z)
     (<= 0 N)
     (= H2 8528)
     (= v_65 H1))
      )
      (inv_main198 U1
             E1
             S1
             K2
             M2
             H2
             X
             E2
             B2
             D2
             B1
             Q1
             T
             R
             D
             G2
             Y
             O1
             E
             B
             J2
             G1
             O
             H
             A
             S
             V
             I
             G
             H1
             W1
             R1
             F
             A1
             M1
             Z
             N
             P1
             L1
             F1
             Y1
             J
             L
             Z1
             A2
             C2
             P
             X1
             F2
             U
             C
             Q
             V1
             K1
             I2
             L2
             v_65
             J1
             D1
             T1
             W
             I1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 M
             I1
             B
             K2
             V1
             B2
             E
             A
             Z
             N1
             N
             Q1
             O
             F
             X1
             C1
             M1
             G
             L
             J1
             K
             B1
             Q
             I
             W1
             J2
             R
             A2
             F1
             R1
             U1
             P
             L2
             E2
             X
             T
             A1
             H1
             I2
             W
             F2
             Z1
             L1
             Y1
             H
             V
             Y
             E1
             O1
             C2
             D
             D2
             C
             U
             G2
             S
             T1
             P1
             K1
             S1
             H2
             J)
        (and (not (= B2 16384))
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
     (= B2 8512)
     (= R1 (- 256))
     (= D1 8528)
     (= M2 0)
     (<= 0 T1)
     (<= 0 S1)
     (<= 0 P1)
     (<= 0 K1)
     (<= 0 A1)
     (<= 0 X)
     (<= 0 T)
     (<= 0 J)
     (not (<= G1 0))
     (not (= B2 12292))
     (= v_65 R1))
      )
      (inv_main198 M
             I1
             B
             K2
             V1
             D1
             E
             A
             Z
             N1
             M2
             Q1
             O
             F
             X1
             C1
             M1
             G
             L
             J1
             K
             B1
             Q
             I
             W1
             J2
             R
             A2
             F1
             R1
             U1
             P
             L2
             E2
             X
             T
             A1
             H1
             I2
             G1
             F2
             B2
             L1
             Y1
             H
             V
             Y
             E1
             O1
             C2
             D
             D2
             C
             U
             G2
             S
             v_65
             P1
             K1
             S1
             H2
             J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 B1
             J1
             P
             K1
             E1
             D2
             N
             D
             K
             R1
             Q1
             I
             O1
             H
             V
             P1
             N1
             F1
             A
             C2
             H2
             A2
             H1
             C1
             L2
             Y1
             S1
             V1
             L1
             G1
             K2
             Z1
             S
             F
             M2
             W1
             E
             I2
             T
             A1
             X
             D1
             G
             L
             G2
             U
             R
             F2
             J2
             I1
             E2
             M
             T1
             J
             M1
             Q
             Z
             C
             Y
             U1
             O
             W)
        (and (not (= D2 12292))
     (not (= D2 16384))
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
     (not (= D2 8497))
     (not (= D2 8512))
     (= D2 8513)
     (= B2 1)
     (= X1 0)
     (not (= G1 (- 256)))
     (<= 0 C)
     (<= 0 W1)
     (<= 0 U1)
     (<= 0 Z)
     (<= 0 Y)
     (<= 0 W)
     (<= 0 E)
     (<= 0 M2)
     (= B 8528)
     (= v_65 G1))
      )
      (inv_main198 B1
             J1
             P
             K1
             E1
             B
             N
             D
             K
             R1
             X1
             I
             O1
             H
             V
             P1
             N1
             F1
             A
             C2
             H2
             A2
             H1
             C1
             L2
             Y1
             S1
             V1
             L1
             G1
             K2
             Z1
             S
             F
             M2
             W1
             E
             I2
             T
             A1
             X
             D2
             B2
             L
             G2
             U
             R
             F2
             J2
             I1
             E2
             M
             T1
             J
             M1
             Q
             v_65
             C
             Y
             U1
             O
             W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 J1
             X
             L1
             T1
             R1
             X1
             J2
             J
             U
             I1
             L
             V1
             P1
             R
             C2
             K
             F2
             O
             D2
             Y
             K1
             E2
             I
             M1
             S1
             T
             H1
             C
             D
             G1
             G
             A1
             Z1
             P
             Q
             U1
             H2
             Y1
             L2
             W1
             B1
             B2
             H
             F
             A2
             E
             Z
             D1
             G2
             O1
             B
             M
             F1
             C1
             E1
             N
             A
             W
             N1
             Q1
             I2
             V)
        (and (not (= X1 16384))
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
     (= X1 8513)
     (= G1 (- 256))
     (= S 8528)
     (= M2 0)
     (<= 0 A)
     (<= 0 H2)
     (<= 0 U1)
     (<= 0 Q1)
     (<= 0 N1)
     (<= 0 W)
     (<= 0 V)
     (<= 0 Q)
     (not (<= K2 0))
     (not (= X1 12292))
     (= v_65 G1))
      )
      (inv_main198 J1
             X
             L1
             T1
             R1
             S
             J2
             J
             U
             I1
             M2
             V1
             P1
             R
             C2
             K
             F2
             O
             D2
             Y
             K1
             E2
             I
             M1
             S1
             T
             H1
             C
             D
             G1
             G
             A1
             Z1
             P
             Q
             U1
             H2
             Y1
             L2
             K2
             B1
             X1
             H
             F
             A2
             E
             Z
             D1
             G2
             O1
             B
             M
             F1
             C1
             E1
             N
             v_65
             W
             N1
             Q1
             I2
             V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main117 Q
             I1
             L
             V
             N1
             G2
             H1
             G1
             D2
             Z1
             A2
             U1
             U
             M1
             Y
             X
             C1
             P1
             D1
             M
             G
             T
             K2
             J2
             W
             D
             H
             I2
             S1
             R1
             O
             E2
             C2
             X1
             K
             R
             F1
             B1
             S
             V1
             J
             L1
             C
             F
             W1
             Y1
             F2
             E
             K1
             L2
             B
             A
             Z
             O1
             A1
             J1
             N
             P
             I
             B2
             T1
             H2)
        (and (not (= G2 8561))
     (not (= G2 8448))
     (= G2 8576)
     (not (= G2 8545))
     (not (= G2 12292))
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
     (= Q1 2)
     (= E1 8466)
     (<= 0 H2)
     (<= 0 B2)
     (<= 0 F1)
     (<= 0 R)
     (<= 0 P)
     (<= 0 N)
     (<= 0 K)
     (<= 0 I)
     (not (<= Q1 0))
     (not (= G2 8560)))
      )
      (inv_main198 Q
             I1
             L
             V
             N1
             E1
             H1
             G1
             D2
             Z1
             A2
             U1
             U
             M1
             Y
             X
             C1
             P1
             D1
             M
             G
             T
             K2
             J2
             W
             D
             H
             I2
             S1
             R1
             O
             E2
             C2
             X1
             K
             R
             F1
             B1
             S
             Q1
             J
             G2
             C
             F
             W1
             Y1
             F2
             E
             K1
             L2
             B
             A
             Z
             O1
             A1
             J1
             N
             P
             I
             B2
             T1
             H2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main117 E1
             D
             T1
             G
             F1
             P
             M
             D2
             F
             J2
             C
             I1
             I2
             Y
             Z
             H1
             G1
             P1
             C2
             A2
             M1
             Q
             Z1
             V
             C1
             T
             N
             L1
             J
             W1
             H
             B1
             S
             B
             L2
             R
             S1
             K1
             M2
             U1
             A
             U
             O1
             N2
             E2
             X
             I
             J1
             G2
             R1
             K2
             D1
             B2
             W
             L
             O
             X1
             A1
             K
             N1
             V1
             H2)
        (and (= Q1 8592)
     (not (= P 8560))
     (not (= P 8561))
     (not (= P 8448))
     (= P 8576)
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
     (not (= E 2))
     (<= 0 L2)
     (<= 0 H2)
     (<= 0 X1)
     (<= 0 S1)
     (<= 0 N1)
     (<= 0 A1)
     (<= 0 R)
     (<= 0 K)
     (not (<= Y1 0))
     (not (<= E 0))
     (= F2 0))
      )
      (inv_main198 E1
             D
             T1
             G
             F1
             Q1
             M
             D2
             F
             J2
             F2
             I1
             I2
             Y
             Z
             H1
             G1
             P1
             C2
             A2
             M1
             Q
             Z1
             V
             C1
             T
             N
             L1
             J
             W1
             H
             B1
             S
             B
             L2
             R
             S1
             K1
             M2
             Y1
             A
             P
             O1
             N2
             E2
             X
             I
             J1
             G2
             R1
             K2
             D1
             B2
             W
             L
             O
             X1
             A1
             K
             N1
             V1
             H2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main117 Z
             J1
             U
             G
             U1
             K
             K2
             M
             W
             H2
             Z1
             H1
             T
             Y
             Q1
             E2
             S
             R
             A
             L
             Y1
             X1
             K1
             C2
             I2
             I
             P
             A1
             M1
             W1
             G1
             X
             S1
             F1
             R1
             E1
             G2
             B1
             I1
             F
             A2
             B
             T1
             D
             V
             L1
             V1
             N1
             D1
             B2
             E
             L2
             C
             F2
             P1
             Q
             O
             J
             H
             D2
             C1
             O1)
        (and (= N 8466)
     (not (= K 8560))
     (not (= K 8561))
     (not (= K 8448))
     (not (= K 8576))
     (= K 8577)
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
     (<= 0 G2)
     (<= 0 D2)
     (<= 0 R1)
     (<= 0 O1)
     (<= 0 E1)
     (<= 0 O)
     (<= 0 J)
     (<= 0 H)
     (not (<= J2 0))
     (= J2 2))
      )
      (inv_main198 Z
             J1
             U
             G
             U1
             N
             K2
             M
             W
             H2
             Z1
             H1
             T
             Y
             Q1
             E2
             S
             R
             A
             L
             Y1
             X1
             K1
             C2
             I2
             I
             P
             A1
             M1
             W1
             G1
             X
             S1
             F1
             R1
             E1
             G2
             B1
             I1
             J2
             A2
             K
             T1
             D
             V
             L1
             V1
             N1
             D1
             B2
             E
             L2
             C
             F2
             P1
             Q
             O
             J
             H
             D2
             C1
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main117 G
             B1
             I2
             A2
             G1
             K2
             M
             Y1
             K
             F2
             O1
             R
             F
             L2
             U
             J1
             Q
             H
             W
             R1
             K1
             Z1
             M2
             N2
             B
             X
             F1
             O
             D
             L
             J
             X1
             S1
             N
             A1
             Z
             E
             C1
             A
             Q1
             Y
             E1
             H2
             E2
             S
             N1
             T
             W1
             H1
             I
             C
             P1
             M1
             L1
             U1
             P
             T1
             V1
             J2
             D2
             I1
             G2)
        (and (not (= K2 8561))
     (not (= K2 8448))
     (not (= K2 8576))
     (= K2 8577)
     (not (= K2 8545))
     (not (= K2 12292))
     (not (= K2 16384))
     (not (= K2 8192))
     (not (= K2 24576))
     (not (= K2 8195))
     (not (= K2 8480))
     (not (= K2 8481))
     (not (= K2 8482))
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
     (not (= C2 2))
     (= B2 0)
     (= V 8592)
     (<= 0 J2)
     (<= 0 G2)
     (<= 0 D2)
     (<= 0 V1)
     (<= 0 T1)
     (<= 0 A1)
     (<= 0 Z)
     (<= 0 E)
     (not (<= C2 0))
     (not (<= D1 0))
     (not (= K2 8560)))
      )
      (inv_main198 G
             B1
             I2
             A2
             G1
             V
             M
             Y1
             K
             F2
             B2
             R
             F
             L2
             U
             J1
             Q
             H
             W
             R1
             K1
             Z1
             M2
             N2
             B
             X
             F1
             O
             D
             L
             J
             X1
             S1
             N
             A1
             Z
             E
             C1
             A
             D1
             Y
             K2
             H2
             E2
             S
             N1
             T
             W1
             H1
             I
             C
             P1
             M1
             L1
             U1
             P
             T1
             V1
             J2
             D2
             I1
             G2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main297 B
             A2
             G1
             O
             D2
             F
             A1
             L1
             L2
             X
             B1
             H1
             N1
             E
             W1
             Q1
             G2
             W
             M
             Z1
             D1
             R
             J2
             M2
             K1
             L
             C2
             I
             P1
             C1
             P
             T1
             A
             K2
             K
             F2
             J1
             C
             X1
             B2
             E1
             D
             U1
             Y
             Y1
             H2
             J
             N
             I1
             H
             R1
             U
             F1
             I2
             S
             V1
             S1
             V
             G
             E2
             M1
             T)
        (and (= Z 8544)
     (not (= I 0))
     (<= 0 F2)
     (<= 0 E2)
     (<= 0 S1)
     (<= 0 J1)
     (<= 0 V)
     (<= 0 T)
     (<= 0 K)
     (<= 0 G)
     (not (<= Q 0))
     (= O1 0))
      )
      (inv_main198 B
             A2
             G1
             O
             D2
             Z
             A1
             L1
             L2
             X
             O1
             H1
             N1
             E
             W1
             Q1
             G2
             W
             M
             Z1
             D1
             R
             J2
             M2
             K1
             L
             C2
             I
             P1
             C1
             P
             T1
             A
             K2
             K
             F2
             J1
             C
             X1
             Q
             E1
             D
             U1
             Y
             Y1
             H2
             J
             N
             I1
             H
             R1
             U
             F1
             I2
             S
             V1
             S1
             V
             G
             E2
             M1
             T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main297 G
             R
             A1
             M2
             X1
             Q1
             N
             M
             H1
             L1
             F
             T1
             N1
             G2
             D
             C1
             B2
             J1
             B1
             L
             P
             M1
             Y1
             P1
             I2
             U
             B
             D2
             A2
             W1
             I
             J
             L2
             K2
             U1
             S1
             F2
             J2
             S
             V
             I1
             K1
             H2
             H
             O
             W
             Y
             T
             G1
             Q
             E1
             C2
             Z1
             X
             Z
             E2
             D1
             E
             C
             K
             F1
             O1)
        (and (= V1 0)
     (not (= U1 (- 30)))
     (= R1 8544)
     (<= 0 C)
     (<= 0 F2)
     (<= 0 U1)
     (<= 0 S1)
     (<= 0 O1)
     (<= 0 D1)
     (<= 0 K)
     (<= 0 E)
     (not (<= A 0))
     (= D2 0))
      )
      (inv_main198 G
             R
             A1
             M2
             X1
             R1
             N
             M
             H1
             L1
             V1
             T1
             N1
             G2
             D
             C1
             B2
             J1
             B1
             L
             P
             M1
             Y1
             P1
             I2
             U
             B
             D2
             A2
             W1
             I
             J
             L2
             K2
             U1
             S1
             F2
             J2
             S
             A
             I1
             K1
             H2
             H
             O
             W
             Y
             T
             G1
             Q
             E1
             C2
             Z1
             X
             Z
             E2
             D1
             E
             C
             K
             F1
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main297 R
             S1
             K
             Z
             A2
             O1
             P
             J
             C
             T
             M1
             A1
             X1
             S
             U
             K2
             D1
             H1
             U1
             G1
             X
             B1
             I2
             T1
             J2
             N1
             Y1
             M2
             E
             Q1
             W
             H
             C1
             H2
             F2
             V
             I1
             B
             D2
             E1
             L1
             K1
             G2
             V1
             Q
             B2
             G
             O
             A
             J1
             N
             R1
             F1
             E2
             C2
             W1
             Y
             L2
             P1
             M
             Z1
             I)
        (and (not (= F2 (- 1)))
     (= X 0)
     (= L 0)
     (= D 8544)
     (= M2 0)
     (<= 0 F2)
     (<= 0 P1)
     (<= 0 I1)
     (<= 0 Y)
     (<= 0 V)
     (<= 0 M)
     (<= 0 I)
     (<= 0 L2)
     (not (<= F 0))
     (= F2 (- 30)))
      )
      (inv_main198 R
             S1
             K
             Z
             A2
             D
             P
             J
             C
             T
             L
             A1
             X1
             S
             U
             K2
             D1
             H1
             U1
             G1
             X
             B1
             I2
             T1
             J2
             N1
             Y1
             M2
             E
             Q1
             W
             H
             C1
             H2
             F2
             V
             I1
             B
             D2
             F
             L1
             K1
             G2
             V1
             Q
             B2
             G
             O
             A
             J1
             N
             R1
             F1
             E2
             C2
             W1
             Y
             L2
             P1
             M
             Z1
             I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main297 C1
             P1
             F1
             Q
             O1
             N2
             K
             L2
             G
             K2
             J
             D2
             M2
             N
             B1
             M
             R1
             G2
             N1
             F
             V
             L1
             Z1
             X1
             V1
             U1
             G1
             H1
             W
             C2
             I1
             S1
             W1
             R
             F2
             O2
             D
             M1
             B2
             L
             K1
             D1
             I2
             A
             Q1
             J1
             X
             P
             Y
             Z
             E
             A2
             H
             C
             T
             S
             H2
             U
             E1
             E2
             A1
             B)
        (and (= J2 512)
     (= F2 (- 30))
     (not (= F2 (- 1)))
     (not (= S1 (- 4)))
     (not (= S1 (- 2)))
     (= H1 0)
     (not (= V 0))
     (= O 0)
     (= I 8544)
     (>= Z 65)
     (<= 0 B)
     (<= 0 D)
     (<= 0 H2)
     (<= 0 F2)
     (<= 0 E2)
     (<= 0 E1)
     (<= 0 U)
     (<= 0 O2)
     (not (<= Y1 0))
     (= (+ T1 (* (- 8) Z)) 0)
     (= v_67 S1)
     (= v_68 S1))
      )
      (inv_main198 C1
             P1
             F1
             Q
             O1
             I
             K
             L2
             G
             K2
             O
             D2
             M2
             N
             B1
             M
             R1
             G2
             N1
             F
             V
             L1
             Z1
             X1
             V1
             U1
             G1
             H1
             W
             C2
             I1
             S1
             W1
             R
             F2
             O2
             D
             M1
             B2
             Y1
             K1
             D1
             I2
             A
             Q1
             J1
             X
             P
             Y
             Z
             J2
             A2
             H
             C
             T
             S
             H2
             U
             v_67
             v_68
             T1
             B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main297 R1
             E2
             G1
             F
             R
             C
             E
             X
             U1
             T
             A2
             L2
             J2
             M2
             K1
             W
             B2
             X1
             U
             G2
             F1
             Y1
             M1
             M
             Z1
             V1
             F2
             D
             L1
             V
             E1
             J1
             S
             J
             G
             K
             N2
             A
             A1
             I1
             Q1
             Z
             H1
             S1
             O1
             K2
             N1
             B
             N
             P1
             D1
             I2
             B1
             I
             H2
             C1
             P
             D2
             L
             Y
             O
             T1)
        (and (= D 0)
     (= C2 1024)
     (= W1 8544)
     (= J1 (- 4))
     (not (= J1 (- 2)))
     (not (= F1 0))
     (= Q 0)
     (= G (- 30))
     (not (= G (- 1)))
     (>= P1 129)
     (<= 0 D2)
     (<= 0 T1)
     (<= 0 Y)
     (<= 0 P)
     (<= 0 L)
     (<= 0 K)
     (<= 0 G)
     (<= 0 N2)
     (not (<= H 0))
     (= (+ O2 (* (- 8) P1)) 0)
     (= v_67 J1)
     (= v_68 J1))
      )
      (inv_main198 R1
             E2
             G1
             F
             R
             W1
             E
             X
             U1
             T
             Q
             L2
             J2
             M2
             K1
             W
             B2
             X1
             U
             G2
             F1
             Y1
             M1
             M
             Z1
             V1
             F2
             D
             L1
             V
             E1
             J1
             S
             J
             G
             K
             N2
             A
             A1
             H
             Q1
             Z
             H1
             S1
             O1
             K2
             N1
             B
             N
             P1
             C2
             I2
             B1
             I
             H2
             C1
             P
             D2
             v_67
             v_68
             O2
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main429 Q
             K1
             Y1
             I1
             N1
             V1
             J1
             X
             G2
             L1
             U
             K
             I2
             V
             R
             E1
             U1
             F
             T1
             P1
             H
             X1
             G1
             S
             G
             R1
             A1
             W
             K2
             D
             N
             Z1
             D2
             Q1
             O1
             O
             J
             B
             Z
             P
             H1
             M
             N2
             B2
             L
             C
             L2
             D1
             E2
             I
             A
             B1
             T
             W1
             Y
             E
             F2
             H2
             A2
             J2
             F1
             S1)
        (and (not (= W1 0))
     (= M1 3)
     (= C1 8672)
     (= Y 2)
     (not (= T 0))
     (<= 0 J2)
     (<= 0 H2)
     (<= 0 F2)
     (<= 0 A2)
     (<= 0 S1)
     (<= 0 O1)
     (<= 0 O)
     (<= 0 J)
     (not (<= M2 0))
     (= C2 0)
     (= v_66 K2))
      )
      (inv_main198 Q
             K1
             Y1
             I1
             N1
             C1
             J1
             X
             G2
             L1
             C2
             K
             I2
             V
             R
             E1
             U1
             F
             T1
             P1
             H
             X1
             G1
             S
             G
             R1
             A1
             W
             K2
             D
             N
             Z1
             v_66
             Q1
             O1
             O
             J
             B
             Z
             M2
             H1
             M
             N2
             B2
             L
             C
             L2
             D1
             E2
             I
             A
             B1
             T
             W1
             M1
             E
             F2
             H2
             A2
             J2
             F1
             S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main429 V
             X1
             L
             I1
             J1
             H1
             Q
             N1
             E1
             X
             R
             M1
             G
             J
             O1
             A2
             D1
             E2
             E
             U
             Q1
             A1
             Y
             F1
             B
             T1
             N2
             N
             W
             S1
             U1
             R1
             G2
             M
             S
             M2
             G1
             P1
             B2
             D2
             J2
             Y1
             C2
             L1
             P
             W1
             C
             L2
             F2
             T
             Z1
             F
             B1
             H
             D
             O
             K1
             Z
             K
             V1
             K2
             I2)
        (and (= D 5)
     (not (= D 2))
     (= H2 0)
     (= C1 6)
     (not (= B1 0))
     (not (= H 0))
     (<= 0 I2)
     (<= 0 V1)
     (<= 0 K1)
     (<= 0 G1)
     (<= 0 Z)
     (<= 0 S)
     (<= 0 K)
     (<= 0 M2)
     (not (<= I 0))
     (= A 8672)
     (= v_66 W))
      )
      (inv_main198 V
             X1
             L
             I1
             J1
             A
             Q
             N1
             E1
             X
             H2
             M1
             G
             J
             O1
             A2
             D1
             E2
             E
             U
             Q1
             A1
             Y
             F1
             B
             T1
             N2
             N
             W
             S1
             U1
             R1
             v_66
             M
             S
             M2
             G1
             P1
             B2
             I
             J2
             Y1
             C2
             L1
             P
             W1
             C
             L2
             F2
             T
             Z1
             F
             B1
             H
             C1
             O
             K1
             Z
             K
             V1
             K2
             I2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main429 Z1
             O
             L1
             E
             U1
             H1
             G
             N
             Q
             P
             Y1
             L2
             A1
             T
             E1
             N1
             S
             F
             A
             M1
             X
             I
             K
             K2
             B1
             J1
             N2
             M2
             I2
             G1
             G2
             C2
             W
             X1
             F2
             E2
             D1
             W1
             U
             F1
             Z
             B
             O1
             C
             L
             H
             J2
             S1
             H2
             D
             T1
             C1
             I1
             D2
             P1
             R
             M
             B2
             A2
             V
             Y
             R1)
        (and (= Q1 9)
     (not (= P1 5))
     (not (= P1 2))
     (= P1 8)
     (= K1 8672)
     (not (= I1 0))
     (= J 0)
     (<= 0 F2)
     (<= 0 E2)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 R1)
     (<= 0 D1)
     (<= 0 V)
     (<= 0 M)
     (not (<= V1 0))
     (not (= D2 0))
     (= v_66 I2))
      )
      (inv_main198 Z1
             O
             L1
             E
             U1
             K1
             G
             N
             Q
             P
             J
             L2
             A1
             T
             E1
             N1
             S
             F
             A
             M1
             X
             I
             K
             K2
             B1
             J1
             N2
             M2
             I2
             G1
             G2
             C2
             v_66
             X1
             F2
             E2
             D1
             W1
             U
             V1
             Z
             B
             O1
             C
             L
             H
             J2
             S1
             H2
             D
             T1
             C1
             I1
             D2
             Q1
             R
             M
             B2
             A2
             V
             Y
             R1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main429 U1
             J1
             M1
             E2
             W1
             K2
             K1
             G2
             M2
             N
             J
             B2
             D2
             I2
             I
             H
             P
             Y
             X
             A
             C2
             T
             A1
             D1
             R
             L
             V1
             E
             Z1
             F1
             H2
             I1
             O1
             B1
             P1
             E1
             M
             X1
             C1
             K
             S1
             Q1
             U
             H1
             G
             D
             B
             V
             J2
             Y1
             F2
             R1
             A2
             L1
             L2
             Z
             Q
             W
             O
             T1
             C
             F)
        (and (= N1 8672)
     (not (= L1 0))
     (= G1 0)
     (not (= L2 5))
     (not (= L2 2))
     (not (= L2 8))
     (<= 0 T1)
     (<= 0 P1)
     (<= 0 E1)
     (<= 0 W)
     (<= 0 Q)
     (<= 0 O)
     (<= 0 M)
     (<= 0 F)
     (not (<= S 0))
     (not (= A2 0))
     (= v_65 Z1))
      )
      (inv_main198 U1
             J1
             M1
             E2
             W1
             N1
             K1
             G2
             M2
             N
             G1
             B2
             D2
             I2
             I
             H
             P
             Y
             X
             A
             C2
             T
             A1
             D1
             R
             L
             V1
             E
             Z1
             F1
             H2
             I1
             v_65
             B1
             P1
             E1
             M
             X1
             C1
             S
             S1
             Q1
             U
             H1
             G
             D
             B
             V
             J2
             Y1
             F2
             R1
             A2
             L1
             L2
             Z
             Q
             W
             O
             T1
             C
             F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 H2
             B2
             K1
             F2
             A1
             J2
             C1
             C
             Q1
             J
             D
             V1
             U1
             X
             H1
             R1
             Z1
             O1
             C2
             I2
             T1
             A2
             T
             N1
             P1
             A
             D2
             F1
             H
             G1
             Y1
             R
             F
             B
             N
             L
             U
             P
             K
             V
             S
             G
             E1
             E2
             J1
             M
             W1
             E
             I
             B1
             W
             S1
             M1
             I1
             D1
             Q
             L1
             O
             X1
             Y
             Z
             G2)
        (and (not (= J2 8560))
     (not (= J2 8561))
     (not (= J2 8448))
     (not (= J2 8576))
     (not (= J2 8577))
     (not (= J2 8592))
     (not (= J2 8593))
     (not (= J2 8608))
     (not (= J2 8609))
     (not (= J2 8640))
     (= J2 8656)
     (not (= J2 8545))
     (not (= J2 12292))
     (not (= J2 16384))
     (not (= J2 8192))
     (not (= J2 24576))
     (not (= J2 8195))
     (not (= J2 8480))
     (not (= J2 8481))
     (not (= J2 8482))
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
     (<= 0 G2)
     (<= 0 X1)
     (<= 0 L1)
     (<= 0 Y)
     (<= 0 U)
     (<= 0 O)
     (<= 0 N)
     (<= 0 L)
     (not (= J2 8641))
     (= v_62 J2))
      )
      (inv_main429 H2
             B2
             K1
             F2
             A1
             J2
             C1
             C
             Q1
             J
             D
             V1
             U1
             X
             H1
             R1
             Z1
             O1
             C2
             I2
             T1
             A2
             T
             N1
             P1
             A
             D2
             F1
             H
             G1
             Y1
             R
             F
             B
             N
             L
             U
             P
             K
             V
             S
             v_62
             E1
             E2
             J1
             M
             W1
             E
             I
             B1
             W
             S1
             M1
             I1
             D1
             Q
             L1
             O
             X1
             Y
             Z
             G2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 B2
             J1
             E2
             W
             G2
             N1
             C2
             C
             I
             H
             S
             Y
             J2
             V
             G
             B1
             O
             Q1
             R1
             F1
             T1
             V1
             C1
             T
             L1
             Z1
             U1
             P
             Z
             Q
             U
             X
             J
             D2
             F2
             G1
             H2
             P1
             H1
             A2
             N
             A
             D
             I2
             M
             L
             D1
             F
             S1
             Y1
             R
             I1
             W1
             O1
             X1
             B
             E
             M1
             K
             E1
             K1
             A1)
        (and (not (= N1 8641))
     (not (= N1 8560))
     (not (= N1 8561))
     (not (= N1 8448))
     (not (= N1 8576))
     (not (= N1 8577))
     (not (= N1 8592))
     (not (= N1 8593))
     (not (= N1 8608))
     (not (= N1 8609))
     (not (= N1 8640))
     (not (= N1 8656))
     (not (= N1 8545))
     (not (= N1 12292))
     (not (= N1 16384))
     (not (= N1 8192))
     (not (= N1 24576))
     (not (= N1 8195))
     (not (= N1 8480))
     (not (= N1 8481))
     (not (= N1 8482))
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
     (<= 0 H2)
     (<= 0 F2)
     (<= 0 M1)
     (<= 0 G1)
     (<= 0 E1)
     (<= 0 A1)
     (<= 0 K)
     (<= 0 E)
     (= N1 8657)
     (= v_62 N1))
      )
      (inv_main429 B2
             J1
             E2
             W
             G2
             N1
             C2
             C
             I
             H
             S
             Y
             J2
             V
             G
             B1
             O
             Q1
             R1
             F1
             T1
             V1
             C1
             T
             L1
             Z1
             U1
             P
             Z
             Q
             U
             X
             J
             D2
             F2
             G1
             H2
             P1
             H1
             A2
             N
             v_62
             D
             I2
             M
             L
             D1
             F
             S1
             Y1
             R
             I1
             W1
             O1
             X1
             B
             E
             M1
             K
             E1
             K1
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main411 B2
             R1
             N1
             G
             A
             T1
             P1
             Y1
             Q
             R
             D
             I1
             Z
             E2
             A1
             F
             V
             N
             D1
             K
             J
             C2
             P
             Z1
             K1
             H1
             Y
             L2
             S
             J1
             B
             H
             I
             X1
             T
             E1
             I2
             G1
             L
             X
             F1
             U
             M
             W
             S1
             E
             D2
             U1
             M1
             A2
             W1
             H2
             O
             J2
             B1
             O1
             C1
             V1
             F2
             Q1
             G2
             K2)
        (and (= C 5)
     (<= 0 I2)
     (<= 0 F2)
     (<= 0 V1)
     (<= 0 Q1)
     (<= 0 E1)
     (<= 0 C1)
     (<= 0 T)
     (<= 0 K2)
     (= B1 4))
      )
      (inv_main414 B2
             R1
             N1
             G
             A
             T1
             P1
             Y1
             Q
             R
             D
             I1
             Z
             E2
             A1
             F
             V
             N
             D1
             K
             J
             C2
             P
             Z1
             K1
             H1
             Y
             L2
             S
             J1
             B
             H
             I
             X1
             T
             E1
             I2
             G1
             L
             L1
             F1
             U
             M
             W
             S1
             E
             D2
             U1
             M1
             A2
             W1
             H2
             O
             J2
             C
             O1
             C1
             V1
             F2
             Q1
             G2
             K2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main411 K2
             V1
             G
             B2
             T
             B
             D
             U1
             F
             M1
             H2
             E1
             D1
             E
             Q1
             C2
             X
             P
             L1
             B1
             G1
             Y1
             Z
             C
             V
             W1
             O1
             T1
             X1
             K
             I2
             F1
             K1
             S1
             A2
             J2
             S
             G2
             E2
             C1
             U
             D2
             F2
             J
             Z1
             M
             I
             R
             L2
             A1
             O
             N1
             H
             Y
             W
             N
             Q
             L
             J1
             I1
             R1
             P1)
        (and (not (= W 4))
     (= W 7)
     (<= 0 J2)
     (<= 0 A2)
     (<= 0 P1)
     (<= 0 J1)
     (<= 0 I1)
     (<= 0 S)
     (<= 0 Q)
     (<= 0 L)
     (= A 8))
      )
      (inv_main414 K2
             V1
             G
             B2
             T
             B
             D
             U1
             F
             M1
             H2
             E1
             D1
             E
             Q1
             C2
             X
             P
             L1
             B1
             G1
             Y1
             Z
             C
             V
             W1
             O1
             T1
             X1
             K
             I2
             F1
             K1
             S1
             A2
             J2
             S
             G2
             E2
             H1
             U
             D2
             F2
             J
             Z1
             M
             I
             R
             L2
             A1
             O
             N1
             H
             Y
             A
             N
             Q
             L
             J1
             I1
             R1
             P1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main411 X
             C2
             O
             B2
             B
             Z1
             R1
             L
             U1
             Y1
             N1
             D
             F
             G
             Z
             U
             D2
             Q1
             R
             I
             S
             K
             Y
             H1
             P1
             E1
             O1
             N
             J1
             K1
             C1
             I2
             Q
             D1
             M
             X1
             E
             E2
             J
             K2
             T1
             G2
             T
             B1
             H
             V
             P
             W1
             W
             H2
             A
             A2
             V1
             F2
             C
             M1
             G1
             L1
             A1
             I1
             J2
             S1)
        (and (not (= C 7))
     (not (= C 10))
     (<= 0 X1)
     (<= 0 S1)
     (<= 0 L1)
     (<= 0 I1)
     (<= 0 G1)
     (<= 0 A1)
     (<= 0 M)
     (<= 0 E)
     (not (= C 4)))
      )
      (inv_main414 X
             C2
             O
             B2
             B
             Z1
             R1
             L
             U1
             Y1
             N1
             D
             F
             G
             Z
             U
             D2
             Q1
             R
             I
             S
             K
             Y
             H1
             P1
             E1
             O1
             N
             J1
             K1
             C1
             I2
             Q
             D1
             M
             X1
             E
             E2
             J
             F1
             T1
             G2
             T
             B1
             H
             V
             P
             W1
             W
             H2
             A
             A2
             V1
             F2
             C
             M1
             G1
             L1
             A1
             I1
             J2
             S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main327 Q
             I1
             G2
             A2
             F1
             C1
             I
             F2
             B1
             G
             O
             S
             V
             E2
             X1
             S1
             P1
             E
             C
             K
             W
             A1
             B2
             O1
             I2
             J1
             L1
             V1
             D1
             Q1
             Y1
             R
             L
             C2
             E1
             J2
             Y
             X
             K1
             H2
             G1
             Z
             R1
             H1
             D2
             F
             D
             Z1
             T
             U1
             H
             A
             M1
             B
             M
             J
             T1
             W1
             P
             N
             N1
             U)
        (and (not (= C (- 1)))
     (<= 0 W1)
     (<= 0 T1)
     (<= 0 E1)
     (<= 0 Y)
     (<= 0 U)
     (<= 0 P)
     (<= 0 N)
     (<= 0 J2)
     (= K 0))
      )
      (inv_main333 Q
             I1
             G2
             A2
             F1
             C1
             I
             F2
             B1
             G
             O
             S
             V
             E2
             X1
             S1
             P1
             E
             C
             K
             W
             A1
             B2
             O1
             I2
             J1
             L1
             V1
             D1
             Q1
             Y1
             R
             L
             C2
             E1
             J2
             Y
             X
             K1
             H2
             G1
             Z
             R1
             H1
             D2
             F
             D
             Z1
             T
             U1
             H
             A
             M1
             B
             M
             J
             T1
             W1
             P
             N
             N1
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main327 K1
             T
             I1
             H
             E1
             P1
             U
             A
             Q1
             N
             C
             A1
             F2
             O1
             V
             O
             D
             R1
             D1
             I2
             Q
             F
             K
             J2
             A2
             H2
             Y1
             G2
             B
             L1
             H1
             W
             G
             U1
             Y
             X1
             E
             J1
             S1
             T1
             N1
             D2
             C1
             L
             R
             W1
             C2
             B1
             G1
             F1
             P
             X
             J
             I
             E2
             M1
             Z1
             Z
             B2
             V1
             S
             M)
        (and (not (= D1 (- 1)))
     (not (= I2 0))
     (<= 0 B2)
     (<= 0 Z1)
     (<= 0 X1)
     (<= 0 V1)
     (<= 0 Z)
     (<= 0 Y)
     (<= 0 M)
     (<= 0 E)
     (= D1 (- 4)))
      )
      (inv_main333 K1
             T
             I1
             H
             E1
             P1
             U
             A
             Q1
             N
             C
             A1
             F2
             O1
             V
             O
             D
             R1
             D1
             I2
             Q
             F
             K
             J2
             A2
             H2
             Y1
             G2
             B
             L1
             H1
             W
             G
             U1
             Y
             X1
             E
             J1
             S1
             T1
             N1
             D2
             C1
             L
             R
             W1
             C2
             B1
             G1
             F1
             P
             X
             J
             I
             E2
             M1
             Z1
             Z
             B2
             V1
             S
             M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main490 E
             M
             Y
             H
             R1
             X
             G2
             A2
             Z1
             D2
             C1
             T
             I2
             Y1
             B2
             A
             Q1
             V
             H2
             V1
             F
             H1
             W
             C
             U
             T1
             O
             L1
             N1
             F2
             I1
             G
             X1
             U1
             C2
             P1
             M1
             P
             S1
             A1
             N
             W1
             F1
             E1
             Q
             S
             O1
             B
             E2
             G1
             R
             D
             L
             B1
             K
             I
             J2
             J
             K1
             J1
             D1
             Z)
        (and (<= 0 C2)
     (<= 0 P1)
     (<= 0 M1)
     (<= 0 K1)
     (<= 0 J1)
     (<= 0 Z)
     (<= 0 J)
     (<= 0 J2)
     (= B2 0))
      )
      (inv_main499 E
             M
             Y
             H
             R1
             X
             G2
             A2
             Z1
             D2
             C1
             T
             I2
             Y1
             B2
             A
             Q1
             V
             H2
             V1
             F
             H1
             W
             C
             U
             T1
             O
             L1
             N1
             F2
             I1
             G
             X1
             U1
             C2
             P1
             M1
             P
             S1
             A1
             N
             W1
             F1
             E1
             Q
             S
             O1
             B
             E2
             G1
             R
             D
             L
             B1
             K
             I
             J2
             J
             K1
             J1
             D1
             Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main490 F
             T1
             H2
             S1
             O1
             B1
             A
             L1
             E
             B2
             M
             A1
             J2
             J1
             K2
             P1
             R1
             Z1
             T
             M1
             E2
             I2
             U
             E1
             C2
             D1
             X1
             G2
             J
             G1
             F2
             R
             O
             V1
             X
             Q
             G
             W
             N1
             W1
             V
             H
             Y1
             B
             K
             S
             H1
             C1
             K1
             P
             Z
             D
             A2
             U1
             L
             D2
             Y
             Q1
             N
             I1
             C
             F1)
        (and (<= 0 Q1)
     (<= 0 I1)
     (<= 0 F1)
     (<= 0 Y)
     (<= 0 X)
     (<= 0 Q)
     (<= 0 N)
     (<= 0 G)
     (not (<= I 0))
     (not (= K2 0)))
      )
      (inv_main499 F
             T1
             H2
             S1
             O1
             B1
             A
             L1
             E
             B2
             M
             A1
             J2
             J1
             K2
             P1
             R1
             Z1
             T
             M1
             E2
             I2
             U
             E1
             C2
             D1
             X1
             G2
             J
             G1
             F2
             R
             O
             V1
             X
             Q
             G
             W
             N1
             I
             V
             H
             Y1
             B
             K
             S
             H1
             C1
             K1
             P
             Z
             D
             A2
             U1
             L
             D2
             Y
             Q1
             N
             I1
             C
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main198 C
             H
             M
             L
             I
             T1
             Z1
             B
             L1
             X1
             D2
             K
             W1
             G2
             M1
             E2
             W
             K1
             U1
             A2
             V
             C1
             X
             J1
             V1
             J2
             R
             S
             P1
             S1
             Y1
             N
             I2
             U
             F2
             E
             H2
             R1
             O1
             Q1
             B1
             I1
             G
             E1
             O
             Y
             Z
             Q
             N1
             D1
             A1
             B2
             H1
             C2
             D
             A
             T
             F
             G1
             P
             J
             F1)
        (and (= O (- 12288))
     (= G 0)
     (<= 0 H2)
     (<= 0 F2)
     (<= 0 G1)
     (<= 0 F1)
     (<= 0 T)
     (<= 0 P)
     (<= 0 F)
     (<= 0 E)
     (= R 0))
      )
      (inv_main490 C
             H
             M
             L
             I
             T1
             Z1
             B
             L1
             X1
             D2
             K
             W1
             G2
             M1
             E2
             W
             K1
             U1
             A2
             V
             C1
             X
             J1
             V1
             J2
             R
             S
             P1
             S1
             Y1
             N
             I2
             U
             F2
             E
             H2
             R1
             O1
             Q1
             B1
             I1
             G
             E1
             O
             Y
             Z
             Q
             N1
             D1
             A1
             B2
             H1
             C2
             D
             A
             T
             F
             G1
             P
             J
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main198 F1
             O1
             C
             H2
             E1
             I1
             X1
             J2
             C1
             W
             I
             N1
             A2
             N
             X
             W1
             T1
             Z1
             V
             Z
             P
             U1
             J
             E2
             K
             Y1
             B2
             A1
             O
             L1
             S
             S1
             I2
             M
             F2
             V1
             Q1
             L
             R1
             J1
             D
             U
             M1
             C2
             Y
             A
             D2
             P1
             H1
             E
             G2
             F
             B
             D1
             G1
             K1
             Q
             H
             G
             T
             R
             B1)
        (and (= M1 0)
     (= I1 8656)
     (not (= Y (- 12288)))
     (<= 0 F2)
     (<= 0 V1)
     (<= 0 Q1)
     (<= 0 B1)
     (<= 0 T)
     (<= 0 Q)
     (<= 0 H)
     (<= 0 G)
     (= B2 0))
      )
      (inv_main490 F1
             O1
             C
             H2
             E1
             I1
             X1
             J2
             C1
             W
             I
             N1
             A2
             N
             X
             W1
             T1
             Z1
             V
             Z
             P
             U1
             J
             E2
             K
             Y1
             B2
             A1
             O
             L1
             S
             S1
             I2
             M
             F2
             V1
             Q1
             L
             R1
             J1
             D
             U
             M1
             C2
             Y
             A
             D2
             P1
             H1
             E
             G2
             F
             B
             D1
             G1
             K1
             Q
             H
             G
             T
             R
             B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main198 X
             X1
             I1
             K
             R
             K1
             A
             T
             E
             D2
             P
             Q1
             C2
             J
             C1
             J2
             B
             T1
             V
             B1
             M1
             B2
             G2
             N
             H1
             N1
             G
             D1
             A1
             E2
             Y1
             H
             V1
             G1
             L1
             F1
             U
             S1
             Q
             D
             M
             Z
             L
             F
             F2
             U1
             W
             C
             P1
             A2
             S
             Z1
             Y
             I2
             O1
             W1
             H2
             I
             R1
             J1
             E1
             O)
        (and (= U1 (- 16384))
     (not (= K1 8656))
     (= L 0)
     (= G 0)
     (<= 0 H2)
     (<= 0 R1)
     (<= 0 L1)
     (<= 0 J1)
     (<= 0 F1)
     (<= 0 U)
     (<= 0 O)
     (<= 0 I)
     (not (= F2 (- 12288))))
      )
      (inv_main490 X
             X1
             I1
             K
             R
             K1
             A
             T
             E
             D2
             P
             Q1
             C2
             J
             C1
             J2
             B
             T1
             V
             B1
             M1
             B2
             G2
             N
             H1
             N1
             G
             D1
             A1
             E2
             Y1
             H
             V1
             G1
             L1
             F1
             U
             S1
             Q
             D
             M
             Z
             L
             F
             F2
             U1
             W
             C
             P1
             A2
             S
             Z1
             Y
             I2
             O1
             W1
             H2
             I
             R1
             J1
             E1
             O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main198 C2
             J
             E1
             J2
             J1
             O1
             X1
             L
             G1
             M1
             S
             G2
             U1
             T
             B2
             E
             V
             T1
             I2
             N
             O
             U
             L1
             G
             D1
             H1
             M
             A1
             P1
             I
             X
             B
             K1
             C
             Y1
             A2
             F
             Q1
             B1
             Y
             V1
             Z1
             H2
             D
             C1
             F2
             S1
             Z
             W
             K
             H
             N1
             I1
             R
             F1
             A
             W1
             P
             Q
             R1
             D2
             E2)
        (and (not (= F2 (- 16384)))
     (not (= Z1 8496))
     (not (= O1 8656))
     (not (= C1 (- 12288)))
     (= M 0)
     (<= 0 E2)
     (<= 0 A2)
     (<= 0 Y1)
     (<= 0 W1)
     (<= 0 R1)
     (<= 0 Q)
     (<= 0 P)
     (<= 0 F)
     (= H2 0))
      )
      (inv_main490 C2
             J
             E1
             J2
             J1
             O1
             X1
             L
             G1
             M1
             S
             G2
             U1
             T
             B2
             E
             V
             T1
             I2
             N
             O
             U
             L1
             G
             D1
             H1
             M
             A1
             P1
             I
             X
             B
             K1
             C
             Y1
             A2
             F
             Q1
             B1
             Y
             V1
             Z1
             H2
             D
             C1
             F2
             S1
             Z
             W
             K
             H
             N1
             I1
             R
             F1
             A
             W1
             P
             Q
             R1
             D2
             E2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 B1
             D2
             J2
             Z
             U1
             H1
             A1
             E
             H2
             L
             M1
             G2
             R1
             X1
             S
             G
             W1
             K1
             I2
             C
             P
             S1
             T1
             E1
             B
             G1
             O1
             T
             V1
             M
             J1
             F2
             I
             D1
             C2
             A2
             C1
             X
             N
             F1
             B2
             E2
             Q1
             U
             W
             H
             V
             Q
             O
             N1
             J
             Y1
             Z1
             A
             R
             P1
             D
             I1
             F
             Y
             L1
             K)
        (and (= H1 8672)
     (not (= H1 8641))
     (not (= H1 8560))
     (not (= H1 8561))
     (not (= H1 8448))
     (not (= H1 8576))
     (not (= H1 8577))
     (not (= H1 8592))
     (not (= H1 8593))
     (not (= H1 8608))
     (not (= H1 8609))
     (not (= H1 8640))
     (not (= H1 8656))
     (not (= H1 8545))
     (not (= H1 12292))
     (not (= H1 16384))
     (not (= H1 8192))
     (not (= H1 24576))
     (not (= H1 8195))
     (not (= H1 8480))
     (not (= H1 8481))
     (not (= H1 8482))
     (not (= H1 8464))
     (not (= H1 8465))
     (not (= H1 8466))
     (not (= H1 8496))
     (not (= H1 8497))
     (not (= H1 8512))
     (not (= H1 8513))
     (not (= H1 8528))
     (not (= H1 8529))
     (not (= H1 8544))
     (<= 0 C2)
     (<= 0 A2)
     (<= 0 I1)
     (<= 0 C1)
     (<= 0 Y)
     (<= 0 K)
     (<= 0 F)
     (<= 0 D)
     (not (= H1 8657))
     (= v_62 H1))
      )
      (inv_main454 B1
             D2
             J2
             Z
             U1
             H1
             A1
             E
             H2
             L
             M1
             G2
             R1
             X1
             S
             G
             W1
             K1
             I2
             C
             P
             S1
             T1
             E1
             B
             G1
             O1
             T
             V1
             M
             J1
             F2
             I
             D1
             C2
             A2
             C1
             X
             N
             F1
             B2
             v_62
             Q1
             U
             W
             H
             V
             Q
             O
             N1
             J
             Y1
             Z1
             A
             R
             P1
             D
             I1
             F
             Y
             L1
             K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 J
             W1
             D2
             G2
             T
             F2
             X1
             D
             I2
             K1
             K
             S1
             Y1
             Q
             Z
             V
             Q1
             C
             X
             J2
             L
             I1
             P1
             T1
             E1
             O1
             C1
             F1
             R
             H1
             A2
             P
             C2
             R1
             G1
             E2
             Z1
             U1
             D1
             A1
             B2
             N
             O
             U
             E
             A
             N1
             L1
             V1
             I
             H2
             G
             S
             B
             M1
             Y
             W
             J1
             H
             B1
             M
             F)
        (and (not (= F2 8657))
     (not (= F2 8672))
     (not (= F2 8641))
     (not (= F2 8560))
     (not (= F2 8561))
     (not (= F2 8448))
     (not (= F2 8576))
     (not (= F2 8577))
     (not (= F2 8592))
     (not (= F2 8593))
     (not (= F2 8608))
     (not (= F2 8609))
     (not (= F2 8640))
     (not (= F2 8656))
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
     (<= 0 E2)
     (<= 0 Z1)
     (<= 0 J1)
     (<= 0 G1)
     (<= 0 B1)
     (<= 0 W)
     (<= 0 H)
     (<= 0 F)
     (= F2 8673)
     (= v_62 F2))
      )
      (inv_main454 J
             W1
             D2
             G2
             T
             F2
             X1
             D
             I2
             K1
             K
             S1
             Y1
             Q
             Z
             V
             Q1
             C
             X
             J2
             L
             I1
             P1
             T1
             E1
             O1
             C1
             F1
             R
             H1
             A2
             P
             C2
             R1
             G1
             E2
             Z1
             U1
             D1
             A1
             B2
             v_62
             O
             U
             E
             A
             N1
             L1
             V1
             I
             H2
             G
             S
             B
             M1
             Y
             W
             J1
             H
             B1
             M
             F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main117 H
             R1
             A2
             F
             L
             I
             S1
             C1
             I1
             S
             V1
             K1
             D2
             K2
             E1
             G2
             Y
             V
             K
             N
             A1
             B2
             B1
             J2
             G1
             U1
             N1
             Z1
             U
             J
             E
             L1
             T
             F2
             H1
             J1
             Q
             W
             C
             T1
             Q1
             W1
             O
             D
             G
             P1
             M
             M1
             H2
             R
             E2
             L2
             C2
             D1
             Y1
             A
             X
             B
             I2
             O1
             P
             F1)
        (and (= X1 2)
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
     (= I 8496)
     (<= 0 B)
     (<= 0 I2)
     (<= 0 O1)
     (<= 0 J1)
     (<= 0 H1)
     (<= 0 F1)
     (<= 0 X)
     (<= 0 Q)
     (= Y1 1)
     (= v_64 I))
      )
      (inv_main271 H
             R1
             A2
             F
             L
             I
             S1
             C1
             I1
             S
             V1
             K1
             D2
             K2
             E1
             G2
             Y
             V
             K
             N
             A1
             B2
             B1
             J2
             G1
             U1
             N1
             Z1
             U
             J
             E
             L1
             T
             F2
             H1
             J1
             Q
             W
             C
             Z
             Q1
             v_64
             O
             D
             G
             P1
             M
             M1
             H2
             R
             E2
             L2
             C2
             D1
             X1
             A
             X
             B
             I2
             O1
             P
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main117 C2
             F
             E1
             M
             G1
             K1
             P
             F2
             D
             N1
             S
             Q
             V
             H1
             V1
             H
             A2
             E2
             K
             N
             R1
             T1
             D2
             Z
             L1
             Y1
             I
             I2
             J2
             R
             M1
             T
             P1
             Y
             W
             J1
             X
             L
             Q1
             U
             H2
             D1
             G2
             A1
             G
             C1
             S1
             W1
             Z1
             B1
             J
             A
             K2
             E
             I1
             B2
             X1
             U1
             F1
             C
             O1
             O)
        (and (not (= K1 16384))
     (not (= K1 8192))
     (not (= K1 24576))
     (not (= K1 8195))
     (not (= K1 8480))
     (not (= K1 8481))
     (not (= K1 8482))
     (not (= K1 8464))
     (not (= K1 8465))
     (not (= K1 8466))
     (= K1 8496)
     (not (= I1 1))
     (<= 0 X1)
     (<= 0 U1)
     (<= 0 J1)
     (<= 0 F1)
     (<= 0 X)
     (<= 0 W)
     (<= 0 O)
     (<= 0 C)
     (not (= K1 12292))
     (= v_63 K1))
      )
      (inv_main271 C2
             F
             E1
             M
             G1
             K1
             P
             F2
             D
             N1
             S
             Q
             V
             H1
             V1
             H
             A2
             E2
             K
             N
             R1
             T1
             D2
             Z
             L1
             Y1
             I
             I2
             J2
             R
             M1
             T
             P1
             Y
             W
             J1
             X
             L
             Q1
             B
             H2
             v_63
             G2
             A1
             G
             C1
             S1
             W1
             Z1
             B1
             J
             A
             K2
             E
             I1
             B2
             X1
             U1
             F1
             C
             O1
             O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main117 A
             G
             C
             Q
             Y
             W1
             H2
             W
             D2
             E
             T1
             A2
             E1
             C2
             U1
             F2
             Z1
             N1
             I2
             G1
             K1
             O1
             Y1
             P1
             X
             J2
             U
             L2
             F1
             B1
             V1
             Q1
             T
             A1
             F
             O
             M
             S
             I1
             K
             C1
             L1
             J
             B2
             H1
             P
             H
             N
             E2
             M1
             R1
             D1
             I
             J1
             K2
             V
             R
             L
             G2
             Z
             B
             X1)
        (and (not (= W1 16384))
     (not (= W1 8192))
     (not (= W1 24576))
     (not (= W1 8195))
     (not (= W1 8480))
     (not (= W1 8481))
     (not (= W1 8482))
     (not (= W1 8464))
     (not (= W1 8465))
     (not (= W1 8466))
     (not (= W1 8496))
     (= W1 8497)
     (= S1 2)
     (= K2 1)
     (<= 0 G2)
     (<= 0 X1)
     (<= 0 Z)
     (<= 0 R)
     (<= 0 O)
     (<= 0 M)
     (<= 0 L)
     (<= 0 F)
     (not (= W1 12292))
     (= v_64 W1))
      )
      (inv_main271 A
             G
             C
             Q
             Y
             W1
             H2
             W
             D2
             E
             T1
             A2
             E1
             C2
             U1
             F2
             Z1
             N1
             I2
             G1
             K1
             O1
             Y1
             P1
             X
             J2
             U
             L2
             F1
             B1
             V1
             Q1
             T
             A1
             F
             O
             M
             S
             I1
             D
             C1
             v_64
             J
             B2
             H1
             P
             H
             N
             E2
             M1
             R1
             D1
             I
             J1
             S1
             V
             R
             L
             G2
             Z
             B
             X1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main117 I2
             E1
             S1
             M
             P
             J1
             U
             Z
             K1
             C2
             I
             Z1
             Y
             H2
             D1
             B1
             R1
             L1
             J2
             C
             E2
             K2
             G
             X
             D
             W
             A1
             V1
             T
             Y1
             Q
             G1
             Q1
             P1
             B
             X1
             R
             C1
             W1
             H
             V
             N1
             O
             T1
             N
             E
             G2
             U1
             B2
             I1
             F
             L
             F2
             A
             F1
             S
             A2
             K
             M1
             J
             D2
             O1)
        (and (not (= J1 16384))
     (not (= J1 8192))
     (not (= J1 24576))
     (not (= J1 8195))
     (not (= J1 8480))
     (not (= J1 8481))
     (not (= J1 8482))
     (not (= J1 8464))
     (not (= J1 8465))
     (not (= J1 8466))
     (not (= J1 8496))
     (= J1 8497)
     (not (= F1 1))
     (<= 0 A2)
     (<= 0 X1)
     (<= 0 O1)
     (<= 0 M1)
     (<= 0 R)
     (<= 0 K)
     (<= 0 J)
     (<= 0 B)
     (not (= J1 12292))
     (= v_63 J1))
      )
      (inv_main271 I2
             E1
             S1
             M
             P
             J1
             U
             Z
             K1
             C2
             I
             Z1
             Y
             H2
             D1
             B1
             R1
             L1
             J2
             C
             E2
             K2
             G
             X
             D
             W
             A1
             V1
             T
             Y1
             Q
             G1
             Q1
             P1
             B
             X1
             R
             C1
             W1
             H1
             V
             v_63
             O
             T1
             N
             E
             G2
             U1
             B2
             I1
             F
             L
             F2
             A
             F1
             S
             A2
             K
             M1
             J
             D2
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 G
             C2
             Z1
             S
             N1
             X
             F2
             Y
             B2
             Y1
             T1
             L
             D1
             J
             F1
             H
             D2
             T
             G1
             V
             O
             A1
             W
             L1
             B1
             U1
             C1
             M
             P1
             I2
             A2
             H2
             E1
             J2
             Q1
             C
             E
             J1
             S1
             D
             I
             B
             Q
             F
             M1
             V1
             O1
             I1
             X1
             K
             E2
             Z
             A
             K1
             N
             G2
             U
             P
             H1
             R1
             W1
             R)
        (and (not (= X 16384))
     (not (= X 8192))
     (not (= X 24576))
     (not (= X 8195))
     (not (= X 8480))
     (not (= X 8481))
     (not (= X 8482))
     (not (= X 8464))
     (not (= X 8465))
     (= X 8466)
     (<= 0 R1)
     (<= 0 Q1)
     (<= 0 H1)
     (<= 0 U)
     (<= 0 R)
     (<= 0 P)
     (<= 0 E)
     (<= 0 C)
     (not (= X 12292))
     (= v_62 X))
      )
      (inv_main254 G
             C2
             Z1
             S
             N1
             X
             F2
             Y
             B2
             Y1
             T1
             L
             D1
             J
             F1
             H
             D2
             T
             G1
             V
             O
             A1
             W
             L1
             B1
             U1
             C1
             M
             P1
             I2
             A2
             H2
             E1
             J2
             Q1
             C
             E
             J1
             S1
             D
             I
             v_62
             Q
             F
             M1
             V1
             O1
             I1
             X1
             K
             E2
             Z
             A
             K1
             N
             G2
             U
             P
             H1
             R1
             W1
             R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 F1
             B
             G2
             M
             T1
             J
             H
             I1
             G
             A
             W
             D1
             C2
             G1
             D2
             I2
             K1
             L1
             Z1
             R1
             I
             J1
             E
             N
             N1
             W1
             J2
             Q
             L
             D
             B1
             H2
             A2
             V1
             A1
             Y
             V
             U1
             C1
             P1
             B2
             Y1
             T
             X1
             M1
             F
             S
             E1
             O
             U
             R
             O1
             H1
             P
             Z
             X
             F2
             K
             Q1
             S1
             C
             E2)
        (and (not (= J 16384))
     (not (= J 8192))
     (not (= J 24576))
     (not (= J 8195))
     (not (= J 8480))
     (not (= J 8481))
     (not (= J 8482))
     (= J 8464)
     (<= 0 F2)
     (<= 0 E2)
     (<= 0 S1)
     (<= 0 Q1)
     (<= 0 A1)
     (<= 0 Y)
     (<= 0 V)
     (<= 0 K)
     (not (= J 12292))
     (= v_62 J))
      )
      (inv_main254 F1
             B
             G2
             M
             T1
             J
             H
             I1
             G
             A
             W
             D1
             C2
             G1
             D2
             I2
             K1
             L1
             Z1
             R1
             I
             J1
             E
             N
             N1
             W1
             J2
             Q
             L
             D
             B1
             H2
             A2
             V1
             A1
             Y
             V
             U1
             C1
             P1
             B2
             v_62
             T
             X1
             M1
             F
             S
             E1
             O
             U
             R
             O1
             H1
             P
             Z
             X
             F2
             K
             Q1
             S1
             C
             E2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 I
             C1
             A2
             G
             X
             D2
             K1
             T1
             Q1
             R
             L
             H1
             V
             U
             N1
             D1
             I2
             W
             W1
             G2
             B2
             U1
             B1
             G1
             R1
             J
             B
             P1
             Y1
             Q
             T
             L1
             E2
             N
             O1
             M
             F1
             C
             Y
             S1
             O
             F2
             E1
             M1
             S
             I1
             Z1
             D
             F
             E
             J2
             J1
             P
             Z
             V1
             X1
             A
             A1
             H2
             H
             K
             C2)
        (and (not (= D2 16384))
     (not (= D2 8192))
     (not (= D2 24576))
     (not (= D2 8195))
     (not (= D2 8480))
     (not (= D2 8481))
     (not (= D2 8482))
     (not (= D2 8464))
     (= D2 8465)
     (<= 0 H2)
     (<= 0 C2)
     (<= 0 O1)
     (<= 0 F1)
     (<= 0 A1)
     (<= 0 M)
     (<= 0 H)
     (<= 0 A)
     (not (= D2 12292))
     (= v_62 D2))
      )
      (inv_main254 I
             C1
             A2
             G
             X
             D2
             K1
             T1
             Q1
             R
             L
             H1
             V
             U
             N1
             D1
             I2
             W
             W1
             G2
             B2
             U1
             B1
             G1
             R1
             J
             B
             P1
             Y1
             Q
             T
             L1
             E2
             N
             O1
             M
             F1
             C
             Y
             S1
             O
             v_62
             E1
             M1
             S
             I1
             Z1
             D
             F
             E
             J2
             J1
             P
             Z
             V1
             X1
             A
             A1
             H2
             H
             K
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main516 F2
             F1
             S1
             A
             N1
             C1
             K1
             B1
             R1
             I2
             D2
             Y1
             Z1
             V
             X1
             D
             H1
             Z
             Q
             J2
             H
             J
             B2
             K
             Q1
             P1
             M1
             C2
             X
             E2
             I1
             J1
             O
             W1
             G2
             L
             B
             N
             D1
             G1
             E
             V1
             R
             A2
             I
             U
             S
             H2
             C
             G
             F
             W
             Y
             U1
             T
             M
             P
             A1
             T1
             O1
             E1
             L1)
        (and (<= 0 T1)
     (<= 0 O1)
     (<= 0 L1)
     (<= 0 A1)
     (<= 0 P)
     (<= 0 L)
     (<= 0 B)
     (<= 0 G2))
      )
      false
    )
  )
)

(check-sat)
(exit)
