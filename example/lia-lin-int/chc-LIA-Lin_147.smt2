; ./tricera/sv-comp-2020/./mixed/s3_clnt_4.cil-1.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main377| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main108| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main265| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main239| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main466| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main3| ( Int ) Bool)
(declare-fun |inv_main193| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main114| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main199| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main254| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main449| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) ) 
    (=>
      (and
        true
      )
      (inv_main3 A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) ) 
    (=>
      (and
        (inv_main114 J1
             V
             R
             D
             J2
             J
             A
             Q1
             O2
             I
             Z
             N2
             E2
             B1
             F
             E1
             M2
             S1
             Q
             U1
             X
             Q2
             L2
             D1
             H2
             W1
             D2
             A2
             M1
             N
             A1
             Y
             R1
             O
             L1
             B2
             F1
             L
             K
             K2
             G2
             C1
             X1
             O1
             G
             F2
             W
             P2
             E
             M
             U
             P
             B
             P1
             H1
             K1
             I2
             N1
             C2
             T1
             I1
             G1
             T
             S
             Y1)
        (and (not (= J2 16384))
     (not (= J2 4096))
     (not (= J2 20480))
     (not (= J2 4099))
     (not (= J2 4368))
     (not (= J2 4369))
     (not (= J2 4384))
     (not (= J2 4385))
     (not (= J2 4400))
     (not (= J2 4401))
     (not (= J2 4416))
     (not (= J2 4417))
     (not (= J2 4432))
     (not (= J2 4433))
     (not (= J2 4448))
     (not (= J2 4449))
     (not (= J2 4464))
     (not (= J2 4465))
     (not (= J2 4466))
     (not (= J2 4467))
     (not (= J2 4480))
     (not (= J2 4481))
     (= J2 4496)
     (= Z1 0)
     (= H 0)
     (= C 4512)
     (<= 0 B2)
     (<= 0 K1)
     (<= 0 F1)
     (not (<= V1 0))
     (not (= J2 12292)))
      )
      (inv_main193 J1
             V
             R
             D
             C
             J
             A
             Q1
             O2
             Z1
             Z
             N2
             E2
             B1
             F
             E1
             M2
             S1
             Q
             U1
             X
             Q2
             H
             D1
             H2
             W1
             D2
             A2
             M1
             N
             A1
             Y
             R1
             O
             L1
             B2
             F1
             L
             K
             V1
             G2
             J2
             X1
             O1
             G
             F2
             W
             P2
             E
             M
             U
             P
             B
             P1
             H1
             K1
             I2
             N1
             C2
             T1
             I1
             G1
             T
             S
             Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) ) 
    (=>
      (and
        (inv_main114 A
             I2
             D
             J
             Y1
             L
             B
             O1
             N
             A2
             H1
             I1
             G2
             Z1
             U1
             G1
             Q2
             D2
             J1
             X1
             B2
             V
             B1
             Q
             X
             S1
             F1
             P
             P1
             W1
             I
             O
             C2
             R
             E1
             G
             M
             P2
             D1
             U
             C
             H
             O2
             W
             R1
             L2
             M1
             K1
             K
             K2
             F
             C1
             E
             S
             T
             J2
             Q1
             Y
             A1
             N2
             Z
             F2
             L1
             N1
             T1)
        (and (= E2 0)
     (= Y1 4497)
     (not (= Y1 12292))
     (not (= Y1 16384))
     (not (= Y1 4096))
     (not (= Y1 20480))
     (not (= Y1 4099))
     (not (= Y1 4368))
     (not (= Y1 4369))
     (not (= Y1 4384))
     (not (= Y1 4385))
     (not (= Y1 4400))
     (not (= Y1 4401))
     (not (= Y1 4416))
     (not (= Y1 4417))
     (not (= Y1 4432))
     (not (= Y1 4433))
     (not (= Y1 4448))
     (not (= Y1 4449))
     (not (= Y1 4464))
     (not (= Y1 4465))
     (not (= Y1 4466))
     (not (= Y1 4467))
     (not (= Y1 4480))
     (not (= Y1 4481))
     (not (= Y1 4496))
     (= V1 4512)
     (<= 0 J2)
     (<= 0 M)
     (<= 0 G)
     (not (<= M2 0))
     (= H2 0))
      )
      (inv_main193 A
             I2
             D
             J
             V1
             L
             B
             O1
             N
             H2
             H1
             I1
             G2
             Z1
             U1
             G1
             Q2
             D2
             J1
             X1
             B2
             V
             E2
             Q
             X
             S1
             F1
             P
             P1
             W1
             I
             O
             C2
             R
             E1
             G
             M
             P2
             D1
             M2
             C
             Y1
             O2
             W
             R1
             L2
             M1
             K1
             K
             K2
             F
             C1
             E
             S
             T
             J2
             Q1
             Y
             A1
             N2
             Z
             F2
             L1
             N1
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main239 M2
             S
             G
             H2
             N
             C1
             M1
             J2
             I
             L2
             R
             B
             X1
             E2
             Z
             T
             Y1
             X
             Z1
             K1
             L1
             I1
             I2
             C
             D1
             Q
             F2
             J1
             E
             V
             G1
             T1
             P
             H
             D
             Q1
             K
             P1
             H1
             F1
             O2
             D2
             E1
             A
             R1
             B1
             S1
             W1
             M
             A1
             O
             N2
             A2
             G2
             N1
             W
             K2
             V1
             J
             U
             F
             O1
             B2
             L
             U1)
        (and (= Y 4384)
     (not (= R B))
     (<= 0 Q1)
     (<= 0 W)
     (<= 0 K)
     (not (<= F1 0))
     (= C2 0))
      )
      (inv_main193 M2
             S
             G
             H2
             Y
             C1
             M1
             J2
             I
             C2
             R
             B
             X1
             E2
             Z
             T
             Y1
             X
             Z1
             K1
             L1
             I1
             I2
             C
             D1
             Q
             F2
             J1
             E
             V
             G1
             T1
             P
             H
             D
             Q1
             K
             P1
             H1
             F1
             O2
             D2
             E1
             A
             R1
             B1
             S1
             W1
             M
             A1
             O
             N2
             A2
             G2
             N1
             W
             K2
             V1
             J
             U
             F
             O1
             B2
             L
             U1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main239 E
             H
             D1
             R1
             J
             M
             I
             I1
             P
             V
             J2
             L1
             Q1
             L
             N1
             H2
             U
             X
             C1
             X1
             P1
             H1
             M1
             Z
             K1
             T
             O1
             W1
             Z1
             F2
             L2
             D2
             C
             W
             A
             S
             G
             I2
             O
             U1
             A1
             D
             B
             E2
             K
             B2
             A2
             B1
             O2
             Y
             K2
             G1
             N
             F1
             Y1
             S1
             J1
             F
             N2
             R
             Q
             C2
             T1
             G2
             E1)
        (and (= J2 L1) (= V1 4384) (<= 0 S1) (<= 0 S) (<= 0 G) (not (<= U1 0)) (= M2 0))
      )
      (inv_main193 E
             H
             D1
             R1
             V1
             M
             I
             I1
             P
             M2
             J2
             L1
             Q1
             L
             N1
             H2
             U
             X
             C1
             X1
             P1
             H1
             M1
             Z
             K1
             T
             O1
             W1
             Z1
             F2
             L2
             D2
             C
             W
             A
             S
             G
             I2
             O
             U1
             A1
             D
             B
             E2
             K
             B2
             A2
             B1
             O2
             Y
             K2
             G1
             N
             F1
             Y1
             S1
             J1
             F
             N2
             R
             Q
             C2
             T1
             G2
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main254 I1
             F
             F2
             L2
             E
             O
             C1
             G1
             S
             C2
             E2
             I2
             I
             R
             U1
             Z1
             A1
             R1
             U
             V1
             H
             D
             P
             J1
             Y1
             X
             T
             Y
             D1
             Q1
             F1
             N1
             A2
             B1
             B
             X1
             W1
             K2
             N
             A
             V
             D2
             G
             Z
             E1
             M2
             W
             Q
             O2
             J2
             K
             H1
             S1
             T1
             B2
             M
             O1
             C
             K1
             P1
             L
             J
             G2
             H2
             M1)
        (and (= L1 4560)
     (not (= I 0))
     (<= 0 X1)
     (<= 0 W1)
     (<= 0 M)
     (not (<= A 0))
     (= N2 0))
      )
      (inv_main193 I1
             F
             F2
             L2
             L1
             O
             C1
             G1
             S
             N2
             E2
             I2
             I
             R
             U1
             Z1
             A1
             R1
             U
             V1
             H
             D
             P
             J1
             Y1
             X
             T
             Y
             D1
             Q1
             F1
             N1
             A2
             B1
             B
             X1
             W1
             K2
             N
             A
             V
             D2
             G
             Z
             E1
             M2
             W
             Q
             O2
             J2
             K
             H1
             S1
             T1
             B2
             M
             O1
             C
             K1
             P1
             L
             J
             G2
             H2
             M1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main254 D2
             T1
             S1
             A
             E
             P1
             L2
             U1
             I2
             H1
             I
             G1
             Y
             C2
             B
             K
             C
             O1
             H2
             G2
             K2
             Z1
             E2
             J
             C1
             H
             W
             R1
             B1
             L1
             T
             N1
             N2
             A1
             D1
             V
             E1
             F
             N
             U
             W1
             M
             I1
             Q1
             V1
             Y1
             Q
             F1
             G
             M2
             S
             J2
             Z
             F2
             P
             K1
             R
             L
             M1
             D
             A2
             B2
             O
             X1
             O2)
        (and (= Y 0) (= X 0) (<= 0 K1) (<= 0 E1) (<= 0 V) (not (<= U 0)) (= J1 4400))
      )
      (inv_main193 D2
             T1
             S1
             A
             J1
             P1
             L2
             U1
             I2
             X
             I
             G1
             Y
             C2
             B
             K
             C
             O1
             H2
             G2
             K2
             Z1
             E2
             J
             C1
             H
             W
             R1
             B1
             L1
             T
             N1
             N2
             A1
             D1
             V
             E1
             F
             N
             U
             W1
             M
             I1
             Q1
             V1
             Y1
             Q
             F1
             G
             M2
             S
             J2
             Z
             F2
             P
             K1
             R
             L
             M1
             D
             A2
             B2
             O
             X1
             O2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main265 G
             X
             A1
             M2
             W
             U1
             C
             Q
             H2
             O
             O2
             N2
             I
             S1
             B1
             W1
             K
             B2
             K1
             K2
             V1
             Z1
             N
             I1
             U
             T1
             N1
             H1
             J1
             E1
             L1
             R
             L2
             J
             F
             P2
             D2
             T
             D
             I2
             D1
             A
             V
             H
             Q1
             S
             C1
             M
             Y1
             E2
             B
             F2
             O1
             L
             X1
             E
             F1
             J2
             R1
             G1
             G2
             Z
             Y
             C2
             A2)
        (and (= M1 1)
     (not (= E1 (- 256)))
     (= P 4416)
     (<= 0 D2)
     (<= 0 E)
     (<= 0 P2)
     (= P1 0)
     (= v_68 E1))
      )
      (inv_main193 G
             X
             A1
             M2
             P
             U1
             C
             Q
             H2
             P1
             O2
             N2
             I
             S1
             B1
             W1
             K
             B2
             K1
             K2
             V1
             Z1
             N
             I1
             U
             T1
             N1
             H1
             J1
             E1
             L1
             R
             L2
             J
             F
             P2
             D2
             T
             D
             I2
             D1
             A
             M1
             H
             Q1
             S
             C1
             M
             Y1
             E2
             B
             F2
             O1
             L
             X1
             v_68
             F1
             J2
             R1
             G1
             G2
             Z
             Y
             C2
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main114 K2
             J2
             F2
             X
             A2
             M
             C2
             G2
             J
             G
             K1
             L1
             S
             J1
             O1
             B2
             D
             U1
             I2
             M2
             A1
             Q1
             E2
             S1
             Z
             I1
             L
             W1
             Y1
             F
             R1
             Q
             G1
             P1
             H
             F1
             H2
             B
             M1
             Y
             D2
             D1
             I
             E1
             O
             V1
             Z1
             R
             C
             P
             W
             U
             L2
             K
             E
             A
             H1
             V
             T1
             C1
             B1
             T
             X1
             N1
             N)
        (and (not (= A2 4528))
     (not (= A2 4529))
     (not (= A2 4561))
     (= A2 4352)
     (not (= A2 4560))
     (not (= A2 4497))
     (not (= A2 4512))
     (not (= A2 12292))
     (not (= A2 16384))
     (not (= A2 4096))
     (not (= A2 20480))
     (not (= A2 4099))
     (not (= A2 4368))
     (not (= A2 4369))
     (not (= A2 4384))
     (not (= A2 4385))
     (not (= A2 4400))
     (not (= A2 4401))
     (not (= A2 4416))
     (not (= A2 4417))
     (not (= A2 4432))
     (not (= A2 4433))
     (not (= A2 4448))
     (not (= A2 4449))
     (not (= A2 4464))
     (not (= A2 4465))
     (not (= A2 4466))
     (not (= A2 4467))
     (not (= A2 4480))
     (not (= A2 4481))
     (not (= A2 4496))
     (not (<= 1 B))
     (<= 0 H2)
     (<= 0 F1)
     (<= 0 A)
     (not (= A2 4513))
     (= v_65 R1)
     (= v_66 B))
      )
      (inv_main193 K2
             J2
             F2
             X
             R1
             M
             C2
             G2
             J
             G
             K1
             L1
             S
             J1
             O1
             B2
             D
             U1
             I2
             M2
             A1
             Q1
             E2
             S1
             Z
             I1
             L
             W1
             Y1
             F
             v_65
             Q
             G1
             P1
             H
             F1
             H2
             B
             M1
             Y
             D2
             A2
             I
             E1
             O
             V1
             Z1
             R
             C
             P
             W
             U
             L2
             K
             E
             A
             H1
             V
             T1
             C1
             B1
             v_66
             X1
             N1
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main114 D
             E
             R1
             B1
             Q1
             L2
             Q
             P
             K1
             F
             M2
             O1
             I1
             Z1
             Z
             X1
             H2
             L1
             O
             B2
             T
             H
             N2
             C
             V
             C1
             S
             L
             A1
             P1
             A2
             H1
             N1
             S1
             J1
             W
             U
             E1
             F1
             Y
             D2
             Y1
             K2
             G
             T1
             W1
             G1
             B
             C2
             I2
             A
             G2
             J
             D1
             E2
             M1
             X
             M
             V1
             K
             J2
             R
             U1
             F2
             N)
        (and (not (= Q1 4528))
     (not (= Q1 4529))
     (not (= Q1 4561))
     (= Q1 4352)
     (not (= Q1 4560))
     (not (= Q1 4497))
     (not (= Q1 4512))
     (not (= Q1 12292))
     (not (= Q1 16384))
     (not (= Q1 4096))
     (not (= Q1 20480))
     (not (= Q1 4099))
     (not (= Q1 4368))
     (not (= Q1 4369))
     (not (= Q1 4384))
     (not (= Q1 4385))
     (not (= Q1 4400))
     (not (= Q1 4401))
     (not (= Q1 4416))
     (not (= Q1 4417))
     (not (= Q1 4432))
     (not (= Q1 4433))
     (not (= Q1 4448))
     (not (= Q1 4449))
     (not (= Q1 4464))
     (not (= Q1 4465))
     (not (= Q1 4466))
     (not (= Q1 4467))
     (not (= Q1 4480))
     (not (= Q1 4481))
     (not (= Q1 4496))
     (= I 1)
     (<= 1 E1)
     (<= 0 M1)
     (<= 0 W)
     (<= 0 U)
     (not (<= J 0))
     (not (= Q1 4513))
     (= v_66 A2)
     (= v_67 J)
     (= v_68 J))
      )
      (inv_main193 D
             E
             R1
             B1
             A2
             L2
             Q
             P
             K1
             F
             M2
             O1
             I1
             I
             Z
             X1
             H2
             L1
             O
             B2
             T
             H
             N2
             C
             V
             C1
             S
             L
             A1
             P1
             v_66
             H1
             N1
             S1
             J1
             W
             U
             J
             F1
             Y
             D2
             Q1
             K2
             G
             T1
             W1
             G1
             B
             C2
             I2
             A
             G2
             v_67
             D1
             E2
             M1
             X
             M
             V1
             K
             J2
             E1
             v_68
             F2
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) ) 
    (=>
      (and
        (inv_main377 U
             F1
             P
             T1
             C1
             J2
             J
             F2
             V
             L2
             W1
             Z
             G
             B
             Y1
             S2
             C2
             Y
             J1
             U1
             M
             E2
             G1
             P2
             K1
             K
             O1
             N
             D
             D2
             F
             X1
             Q2
             P1
             N1
             X
             S
             S1
             I1
             R2
             D1
             A2
             I2
             M1
             M2
             R
             V1
             O2
             O
             L
             W
             Q1
             B2
             H1
             T
             E
             C
             Z1
             Q
             A1
             I
             H2
             B1
             G2
             E1)
        (and (= N2 (+ (- 5) P2))
     (= K2 4560)
     (= L1 0)
     (= H 4352)
     (= G 0)
     (<= 0 X)
     (<= 0 S)
     (<= 0 E)
     (not (<= R1 0))
     (= A (+ (- 5) P2)))
      )
      (inv_main193 U
             F1
             P
             T1
             H
             J2
             J
             F2
             V
             L1
             W1
             Z
             G
             B
             Y1
             S2
             C2
             Y
             J1
             U1
             M
             E2
             G1
             N2
             K1
             K
             O1
             N
             D
             D2
             K2
             X1
             Q2
             P1
             N1
             X
             S
             S1
             I1
             R1
             D1
             A2
             I2
             M1
             M2
             R
             V1
             O2
             O
             L
             W
             Q1
             B2
             H1
             T
             E
             P2
             A
             Q
             A1
             I
             H2
             B1
             G2
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) ) 
    (=>
      (and
        (inv_main377 I1
             C
             T
             K2
             G
             W1
             N2
             C1
             K1
             B
             I2
             Q
             S
             B1
             G2
             U
             O1
             V1
             Y
             F
             R2
             O
             Q1
             I
             L2
             L
             D
             G1
             N
             M1
             N1
             H
             P1
             J
             D2
             Y1
             H1
             X1
             D1
             A2
             J2
             F2
             F1
             L1
             S2
             T1
             R
             Q2
             S1
             Z
             M2
             V
             X
             W
             A1
             R1
             T2
             A
             H2
             J1
             E1
             M
             C2
             E2
             P2)
        (and (= B2 (+ (- 5) I))
     (= Z1 0)
     (= U1 (+ (- 5) I))
     (not (= S 0))
     (= P 4352)
     (= K 3)
     (= I 3)
     (<= 0 Y1)
     (<= 0 R1)
     (<= 0 H1)
     (not (<= E 0))
     (= O2 (+ (- 5) I)))
      )
      (inv_main193 I1
             C
             T
             K2
             P
             W1
             N2
             C1
             K1
             Z1
             I2
             Q
             S
             B1
             G2
             U
             O1
             V1
             Y
             F
             R2
             O
             Q1
             U1
             L2
             L
             D
             G1
             N
             M1
             K
             H
             P1
             J
             D2
             Y1
             H1
             X1
             D1
             E
             J2
             F2
             F1
             L1
             S2
             T1
             R
             Q2
             S1
             Z
             M2
             V
             X
             W
             A1
             R1
             I
             B2
             O2
             J1
             E1
             M
             C2
             E2
             P2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) ) 
    (=>
      (and
        (inv_main377 J1
             U1
             O2
             M1
             G
             E1
             A2
             E2
             N2
             I1
             E
             T2
             D2
             Q2
             W
             Y
             P2
             A1
             U2
             H1
             M2
             C
             T
             M
             B1
             V
             L
             Y1
             V2
             C2
             S
             R2
             C1
             B
             F
             X
             P
             K
             R1
             Z
             L2
             N1
             K2
             D
             N
             T1
             S1
             B2
             D1
             I2
             P1
             O
             G1
             Z1
             S2
             W1
             H
             J2
             W2
             K1
             U
             X1
             R
             F1
             I)
        (and (= (+ Q (* (- 4) M)) (- 20))
     (= A (+ (- 5) M))
     (= G2 3)
     (= F2 3)
     (not (= D2 0))
     (= V1 (+ (- 5) M))
     (= O1 0)
     (= L1 0)
     (not (= M 3))
     (= J (+ (- 5) M))
     (<= 0 W1)
     (<= 0 X)
     (<= 0 P)
     (not (<= Q1 0))
     (= (+ H2 (* (- 4) M)) (- 20)))
      )
      (inv_main193 J1
             U1
             O2
             M1
             F2
             E1
             A2
             E2
             N2
             L1
             E
             T2
             D2
             Q2
             W
             Y
             P2
             A1
             U2
             H1
             M2
             C
             T
             Q
             O1
             V
             L
             Y1
             V2
             C2
             G2
             R2
             C1
             B
             F
             X
             P
             K
             R1
             Q1
             L2
             N1
             K2
             D
             N
             T1
             S1
             B2
             D1
             I2
             P1
             O
             G1
             Z1
             S2
             W1
             M
             V1
             J
             A
             H2
             X1
             R
             F1
             I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 Q
             J1
             W
             X
             V1
             A2
             L
             H1
             X1
             N2
             N
             A
             H2
             F2
             G1
             A1
             J
             G
             E1
             B1
             Q1
             F1
             Y1
             M2
             K
             E2
             U1
             Z1
             N1
             P2
             K2
             C1
             M
             C2
             T
             D1
             B2
             C
             O
             S
             U
             S1
             L2
             I
             I1
             Y
             H
             Z
             D
             O2
             O1
             R
             F
             P
             M1
             J2
             T1
             B
             V
             E
             G2
             L1
             I2
             K1
             D2)
        (and (not (= V1 16384))
     (not (= V1 4096))
     (not (= V1 20480))
     (not (= V1 4099))
     (not (= V1 4368))
     (not (= V1 4369))
     (not (= V1 4384))
     (not (= V1 4385))
     (not (= V1 4400))
     (not (= V1 4401))
     (not (= V1 4416))
     (not (= V1 4417))
     (= V1 4432)
     (= R1 4448)
     (= P1 0)
     (not (= P 5))
     (<= 0 J2)
     (<= 0 B2)
     (<= 0 D1)
     (not (<= W1 0))
     (not (= V1 12292)))
      )
      (inv_main193 Q
             J1
             W
             X
             R1
             A2
             L
             H1
             X1
             P1
             N
             A
             H2
             F2
             G1
             A1
             J
             G
             E1
             B1
             Q1
             F1
             Y1
             M2
             K
             E2
             U1
             Z1
             N1
             P2
             K2
             C1
             M
             C2
             T
             D1
             B2
             C
             O
             W1
             U
             V1
             L2
             I
             I1
             Y
             H
             Z
             D
             O2
             O1
             R
             F
             P
             M1
             J2
             T1
             B
             V
             E
             G2
             L1
             I2
             K1
             D2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 O2
             M
             K1
             G2
             N
             B2
             C
             S
             S1
             A1
             Y1
             M1
             A2
             A
             B
             Z
             U
             L1
             F2
             D
             H2
             K2
             M2
             R
             J
             I1
             T1
             Q
             L2
             G
             R1
             W
             P
             E2
             O
             D2
             F1
             L
             H
             H1
             I
             Q1
             Y
             X
             V1
             I2
             C1
             F
             C2
             J1
             K
             X1
             N2
             O1
             P2
             P1
             E1
             G1
             W1
             N1
             Z1
             J2
             U1
             V
             E)
        (and (= D1 0)
     (= B1 4448)
     (not (= N 12292))
     (not (= N 16384))
     (not (= N 4096))
     (not (= N 20480))
     (not (= N 4099))
     (not (= N 4368))
     (not (= N 4369))
     (not (= N 4384))
     (not (= N 4385))
     (not (= N 4400))
     (not (= N 4401))
     (not (= N 4416))
     (not (= N 4417))
     (not (= N 4432))
     (= N 4433)
     (<= 0 D2)
     (<= 0 P1)
     (<= 0 F1)
     (not (<= T 0))
     (not (= O1 5)))
      )
      (inv_main193 O2
             M
             K1
             G2
             B1
             B2
             C
             S
             S1
             D1
             Y1
             M1
             A2
             A
             B
             Z
             U
             L1
             F2
             D
             H2
             K2
             M2
             R
             J
             I1
             T1
             Q
             L2
             G
             R1
             W
             P
             E2
             O
             D2
             F1
             L
             H
             T
             I
             N
             Y
             X
             V1
             I2
             C1
             F
             C2
             J1
             K
             X1
             N2
             O1
             P2
             P1
             E1
             G1
             W1
             N1
             Z1
             J2
             U1
             V
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 S1
             T
             N1
             D2
             E2
             S
             B1
             V
             E1
             P2
             G1
             O2
             I
             V1
             F2
             A1
             R
             N2
             E
             Y
             R1
             G2
             H
             I1
             Z
             D
             B
             B2
             A2
             X
             C
             C2
             C1
             D1
             H2
             U
             I2
             F
             K1
             P1
             F1
             M
             Z1
             Q
             L1
             X1
             G
             W
             O
             A
             L2
             M2
             K
             N
             P
             Y1
             M1
             L
             K2
             J2
             J1
             T1
             O1
             Q1
             W1)
        (and (not (= E2 16384))
     (not (= E2 4096))
     (not (= E2 20480))
     (not (= E2 4099))
     (not (= E2 4368))
     (not (= E2 4369))
     (not (= E2 4384))
     (not (= E2 4385))
     (not (= E2 4400))
     (not (= E2 4401))
     (not (= E2 4416))
     (not (= E2 4417))
     (not (= E2 4432))
     (not (= E2 4433))
     (= E2 4448)
     (= U1 0)
     (= J 4464)
     (not (= D 0))
     (<= 0 I2)
     (<= 0 Y1)
     (<= 0 U)
     (not (<= H1 0))
     (not (= E2 12292)))
      )
      (inv_main193 S1
             T
             N1
             D2
             J
             S
             B1
             V
             E1
             U1
             G1
             O2
             I
             V1
             F2
             A1
             R
             N2
             E
             Y
             R1
             G2
             H
             I1
             Z
             D
             B
             B2
             A2
             X
             C
             C2
             C1
             D1
             H2
             U
             I2
             F
             K1
             H1
             F1
             E2
             Z1
             Q
             L1
             X1
             G
             W
             O
             A
             L2
             M2
             K
             N
             P
             Y1
             M1
             L
             K2
             J2
             J1
             T1
             O1
             Q1
             W1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 L2
             F2
             C
             R1
             I1
             U1
             G1
             K
             J
             X1
             G2
             N
             Y
             M2
             D1
             A1
             L1
             Z
             Q1
             C2
             H
             M1
             I
             B2
             J2
             O
             A2
             E
             J1
             V1
             Z1
             O1
             E2
             H2
             N1
             S
             M
             Q
             D2
             I2
             C1
             V
             W
             F1
             F
             K1
             T1
             G
             B
             E1
             Y1
             P2
             B1
             H1
             A
             P1
             P
             N2
             U
             W1
             O2
             T
             S1
             X
             D)
        (and (not (= I1 16384))
     (not (= I1 4096))
     (not (= I1 20480))
     (not (= I1 4099))
     (not (= I1 4368))
     (not (= I1 4369))
     (not (= I1 4384))
     (not (= I1 4385))
     (not (= I1 4400))
     (not (= I1 4401))
     (not (= I1 4416))
     (not (= I1 4417))
     (not (= I1 4432))
     (not (= I1 4433))
     (= I1 4448)
     (= R 4480)
     (= O 0)
     (= L 0)
     (<= 0 P1)
     (<= 0 S)
     (<= 0 M)
     (not (<= K2 0))
     (not (= I1 12292)))
      )
      (inv_main193 L2
             F2
             C
             R1
             R
             U1
             G1
             K
             J
             L
             G2
             N
             Y
             M2
             D1
             A1
             L1
             Z
             Q1
             C2
             H
             M1
             I
             B2
             J2
             O
             A2
             E
             J1
             V1
             Z1
             O1
             E2
             H2
             N1
             S
             M
             Q
             D2
             K2
             C1
             I1
             W
             F1
             F
             K1
             T1
             G
             B
             E1
             Y1
             P2
             B1
             H1
             A
             P1
             P
             N2
             U
             W1
             O2
             T
             S1
             X
             D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 L2
             Z1
             C
             B1
             O2
             I2
             U
             J
             N
             O
             K1
             E
             S1
             B2
             O1
             X
             P1
             A
             W1
             T1
             C1
             X1
             D2
             V1
             B
             G1
             Q1
             Y1
             P2
             I1
             R1
             S
             V
             K
             H2
             F2
             J2
             L
             W
             U1
             L1
             H
             A2
             T
             N2
             G2
             D1
             Z
             C2
             N1
             P
             K2
             J1
             A1
             G
             Q
             I
             M
             R
             Y
             D
             E2
             M2
             H1
             M1)
        (and (not (= O2 16384))
     (not (= O2 4096))
     (not (= O2 20480))
     (not (= O2 4099))
     (not (= O2 4368))
     (not (= O2 4369))
     (not (= O2 4384))
     (not (= O2 4385))
     (not (= O2 4400))
     (not (= O2 4401))
     (not (= O2 4416))
     (not (= O2 4417))
     (not (= O2 4432))
     (not (= O2 4433))
     (not (= O2 4448))
     (= O2 4449)
     (not (= G1 0))
     (= F1 4464)
     (= E1 0)
     (<= 0 J2)
     (<= 0 F2)
     (<= 0 Q)
     (not (<= F 0))
     (not (= O2 12292)))
      )
      (inv_main193 L2
             Z1
             C
             B1
             F1
             I2
             U
             J
             N
             E1
             K1
             E
             S1
             B2
             O1
             X
             P1
             A
             W1
             T1
             C1
             X1
             D2
             V1
             B
             G1
             Q1
             Y1
             P2
             I1
             R1
             S
             V
             K
             H2
             F2
             J2
             L
             W
             F
             L1
             O2
             A2
             T
             N2
             G2
             D1
             Z
             C2
             N1
             P
             K2
             J1
             A1
             G
             Q
             I
             M
             R
             Y
             D
             E2
             M2
             H1
             M1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 O1
             E
             T
             Y
             R1
             Z1
             X
             R
             X1
             I2
             B1
             Q1
             S
             O2
             L
             M1
             S1
             G1
             N
             F2
             D
             K
             J1
             L2
             W
             W1
             L1
             J
             D1
             H2
             F1
             E2
             K1
             I
             F
             Y1
             V1
             K2
             I1
             N2
             P2
             C1
             O
             H1
             A
             M2
             G2
             C
             A2
             B
             T1
             H
             U1
             J2
             P
             U
             A1
             Q
             N1
             Z
             D2
             G
             B2
             E1
             C2)
        (and (not (= R1 12292))
     (not (= R1 16384))
     (not (= R1 4096))
     (not (= R1 20480))
     (not (= R1 4099))
     (not (= R1 4368))
     (not (= R1 4369))
     (not (= R1 4384))
     (not (= R1 4385))
     (not (= R1 4400))
     (not (= R1 4401))
     (not (= R1 4416))
     (not (= R1 4417))
     (not (= R1 4432))
     (not (= R1 4433))
     (not (= R1 4448))
     (= R1 4449)
     (= P1 4480)
     (= M 0)
     (<= 0 Y1)
     (<= 0 V1)
     (<= 0 U)
     (not (<= V 0))
     (= W1 0))
      )
      (inv_main193 O1
             E
             T
             Y
             P1
             Z1
             X
             R
             X1
             M
             B1
             Q1
             S
             O2
             L
             M1
             S1
             G1
             N
             F2
             D
             K
             J1
             L2
             W
             W1
             L1
             J
             D1
             H2
             F1
             E2
             K1
             I
             F
             Y1
             V1
             K2
             I1
             V
             P2
             R1
             O
             H1
             A
             M2
             G2
             C
             A2
             B
             T1
             H
             U1
             J2
             P
             U
             A1
             Q
             N1
             Z
             D2
             G
             B2
             E1
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 O1
             H2
             J
             K1
             P2
             S1
             E1
             K
             C
             Q
             G
             J1
             N
             B
             B1
             U1
             N2
             O
             S
             M
             R
             G1
             T
             R1
             Z
             N1
             L2
             K2
             I
             H
             L1
             D2
             Y1
             E
             I2
             M1
             H1
             B2
             M2
             W1
             T1
             Z1
             Q1
             D
             J2
             U
             D1
             L
             I1
             A
             F2
             E2
             X
             W
             O2
             A1
             V1
             P1
             Y
             P
             F
             X1
             C2
             G2
             A2)
        (and (= V 0)
     (not (= P2 12292))
     (not (= P2 16384))
     (not (= P2 4096))
     (not (= P2 20480))
     (not (= P2 4099))
     (not (= P2 4368))
     (not (= P2 4369))
     (not (= P2 4384))
     (not (= P2 4385))
     (not (= P2 4400))
     (not (= P2 4401))
     (not (= P2 4416))
     (not (= P2 4417))
     (not (= P2 4432))
     (not (= P2 4433))
     (not (= P2 4448))
     (not (= P2 4449))
     (not (= P2 4464))
     (not (= P2 4465))
     (not (= P2 4466))
     (= P2 4467)
     (<= 0 M1)
     (<= 0 H1)
     (<= 0 A1)
     (not (<= C1 0))
     (= F1 4480))
      )
      (inv_main193 O1
             H2
             J
             K1
             F1
             S1
             E1
             K
             C
             V
             G
             J1
             N
             B
             B1
             U1
             N2
             O
             S
             M
             R
             G1
             T
             R1
             Z
             N1
             L2
             K2
             I
             H
             L1
             D2
             Y1
             E
             I2
             M1
             H1
             B2
             M2
             C1
             T1
             P2
             Q1
             D
             J2
             U
             D1
             L
             I1
             A
             F2
             E2
             X
             W
             O2
             A1
             V1
             P1
             Y
             P
             F
             X1
             C2
             G2
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 K
             M
             Y1
             T1
             P1
             J2
             P2
             V
             L2
             L1
             A
             N2
             O1
             Z
             C
             R
             C1
             E2
             S1
             U
             H1
             M1
             W
             D
             F2
             N1
             O
             O2
             X
             W1
             F1
             B
             K2
             B1
             C2
             E1
             P
             I2
             H2
             H
             B2
             N
             V1
             R1
             J
             Q
             G
             K1
             A1
             I
             S
             Z1
             D1
             G2
             A2
             F
             I1
             Y
             D2
             E
             U1
             G1
             L
             X1
             M2)
        (and (not (= P1 12292))
     (not (= P1 16384))
     (not (= P1 4096))
     (not (= P1 20480))
     (not (= P1 4099))
     (not (= P1 4368))
     (not (= P1 4369))
     (not (= P1 4384))
     (not (= P1 4385))
     (not (= P1 4400))
     (not (= P1 4401))
     (not (= P1 4416))
     (not (= P1 4417))
     (not (= P1 4432))
     (not (= P1 4433))
     (not (= P1 4448))
     (not (= P1 4449))
     (not (= P1 4464))
     (not (= P1 4465))
     (= P1 4466)
     (= J1 4480)
     (<= 0 E1)
     (<= 0 P)
     (<= 0 F)
     (not (<= T 0))
     (= Q1 0))
      )
      (inv_main193 K
             M
             Y1
             T1
             J1
             J2
             P2
             V
             L2
             Q1
             A
             N2
             O1
             Z
             C
             R
             C1
             E2
             S1
             U
             H1
             M1
             W
             D
             F2
             N1
             O
             O2
             X
             W1
             F1
             B
             K2
             B1
             C2
             E1
             P
             I2
             H2
             T
             B2
             P1
             V1
             R1
             J
             Q
             G
             K1
             A1
             I
             S
             Z1
             D1
             G2
             A2
             F
             I1
             Y
             D2
             E
             U1
             G1
             L
             X1
             M2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 U
             N
             R
             G1
             K2
             F
             J2
             M1
             S1
             L2
             R1
             V1
             T
             D1
             C1
             A2
             D2
             G2
             B2
             C2
             W
             P2
             Z1
             B1
             Q1
             Y1
             A1
             E1
             P
             Z
             K
             I
             L1
             O
             J
             T1
             E2
             D
             O1
             O2
             I2
             X1
             E
             A
             B
             H2
             S
             M2
             Y
             H1
             J1
             H
             I1
             U1
             W1
             X
             N2
             F2
             M
             P1
             V
             G
             K1
             L
             C)
        (and (not (= K2 16384))
     (not (= K2 4096))
     (not (= K2 20480))
     (not (= K2 4099))
     (not (= K2 4368))
     (not (= K2 4369))
     (not (= K2 4384))
     (not (= K2 4385))
     (not (= K2 4400))
     (not (= K2 4401))
     (not (= K2 4416))
     (not (= K2 4417))
     (not (= K2 4432))
     (not (= K2 4433))
     (not (= K2 4448))
     (not (= K2 4449))
     (= K2 4464)
     (= F1 0)
     (= Q 4480)
     (<= 0 E2)
     (<= 0 T1)
     (<= 0 X)
     (not (<= N1 0))
     (not (= K2 12292)))
      )
      (inv_main193 U
             N
             R
             G1
             Q
             F
             J2
             M1
             S1
             F1
             R1
             V1
             T
             D1
             C1
             A2
             D2
             G2
             B2
             C2
             W
             P2
             Z1
             B1
             Q1
             Y1
             A1
             E1
             P
             Z
             K
             I
             L1
             O
             J
             T1
             E2
             D
             O1
             N1
             I2
             K2
             E
             A
             B
             H2
             S
             M2
             Y
             H1
             J1
             H
             I1
             U1
             W1
             X
             N2
             F2
             M
             P1
             V
             G
             K1
             L
             C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 L2
             D2
             M1
             H2
             G2
             A1
             G
             R1
             F2
             H1
             O
             B2
             O1
             D1
             U
             A
             E1
             E
             B
             I2
             I
             K1
             D
             T1
             K2
             F
             S
             V
             T
             Z1
             X
             R
             K
             N2
             Y1
             W
             U1
             M
             J2
             P
             S1
             P1
             B1
             Y
             L
             V1
             X1
             J1
             Q
             Q1
             C
             J
             I1
             Z
             A2
             G1
             N1
             P2
             W1
             C1
             O2
             L1
             E2
             C2
             F1)
        (and (not (= G2 12292))
     (not (= G2 16384))
     (not (= G2 4096))
     (not (= G2 20480))
     (not (= G2 4099))
     (not (= G2 4368))
     (not (= G2 4369))
     (not (= G2 4384))
     (not (= G2 4385))
     (not (= G2 4400))
     (not (= G2 4401))
     (not (= G2 4416))
     (not (= G2 4417))
     (not (= G2 4432))
     (not (= G2 4433))
     (not (= G2 4448))
     (not (= G2 4449))
     (not (= G2 4464))
     (= G2 4465)
     (= N 0)
     (<= 0 U1)
     (<= 0 G1)
     (<= 0 W)
     (not (<= H 0))
     (= M2 4480))
      )
      (inv_main193 L2
             D2
             M1
             H2
             M2
             A1
             G
             R1
             F2
             N
             O
             B2
             O1
             D1
             U
             A
             E1
             E
             B
             I2
             I
             K1
             D
             T1
             K2
             F
             S
             V
             T
             Z1
             X
             R
             K
             N2
             Y1
             W
             U1
             M
             J2
             H
             S1
             G2
             B1
             Y
             L
             V1
             X1
             J1
             Q
             Q1
             C
             J
             I1
             Z
             A2
             G1
             N1
             P2
             W1
             C1
             O2
             L1
             E2
             C2
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main114 I1
             A2
             E1
             E2
             C2
             Q1
             M
             I
             K2
             P1
             L1
             A1
             S1
             B2
             O1
             K1
             X
             H2
             V
             C1
             J
             W1
             J1
             H
             J2
             R
             D
             Y
             F1
             N
             E
             Q
             Z1
             U1
             O2
             N2
             L2
             V1
             M2
             R1
             P
             N1
             Z
             C
             X1
             M1
             H1
             G2
             F2
             W
             I2
             T1
             U
             O
             F
             B
             D1
             S
             L
             B1
             G1
             K
             P2
             Y1
             A)
        (and (not (= C2 12292))
     (not (= C2 16384))
     (not (= C2 4096))
     (not (= C2 20480))
     (not (= C2 4099))
     (not (= C2 4368))
     (not (= C2 4369))
     (not (= C2 4384))
     (not (= C2 4385))
     (not (= C2 4400))
     (not (= C2 4401))
     (not (= C2 4416))
     (not (= C2 4417))
     (not (= C2 4432))
     (not (= C2 4433))
     (not (= C2 4448))
     (not (= C2 4449))
     (not (= C2 4464))
     (not (= C2 4465))
     (not (= C2 4466))
     (not (= C2 4467))
     (= C2 4480)
     (= R 1)
     (= G 4496)
     (<= 0 N2)
     (<= 0 L2)
     (<= 0 B)
     (not (<= T 0))
     (= D2 0)
     (= v_68 N))
      )
      (inv_main193 I1
             A2
             E1
             E2
             G
             Q1
             M
             I
             K2
             D2
             L1
             A1
             S1
             B2
             O1
             K1
             X
             H2
             V
             C1
             J
             W1
             J1
             H
             J2
             R
             D
             Y
             F1
             N
             E
             Q
             Z1
             U1
             O2
             N2
             v_68
             V1
             M2
             T
             P
             C2
             Z
             C
             X1
             M1
             H1
             G2
             F2
             W
             I2
             T1
             U
             O
             F
             B
             D1
             S
             L
             B1
             G1
             K
             P2
             Y1
             A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main114 B1
             O
             E
             H2
             F2
             I2
             U
             B2
             J1
             K2
             J2
             A1
             Z1
             Y
             P
             R
             H1
             N2
             O2
             J
             F
             P2
             O1
             N
             V1
             L2
             K1
             H
             I
             G
             E2
             U1
             P1
             D
             M
             M1
             C
             Q
             A2
             E1
             V
             T1
             Z
             G1
             D2
             C1
             G2
             D1
             X1
             F1
             Q1
             S1
             L1
             Q2
             W1
             T
             A
             I1
             C2
             M2
             L
             W
             B
             N1
             K)
        (and (not (= F2 12292))
     (not (= F2 16384))
     (not (= F2 4096))
     (not (= F2 20480))
     (not (= F2 4099))
     (not (= F2 4368))
     (not (= F2 4369))
     (not (= F2 4384))
     (not (= F2 4385))
     (not (= F2 4400))
     (not (= F2 4401))
     (not (= F2 4416))
     (not (= F2 4417))
     (not (= F2 4432))
     (not (= F2 4433))
     (not (= F2 4448))
     (not (= F2 4449))
     (not (= F2 4464))
     (not (= F2 4465))
     (not (= F2 4466))
     (not (= F2 4467))
     (= F2 4480)
     (= Y1 0)
     (= R1 0)
     (= X 4512)
     (<= 0 M1)
     (<= 0 T)
     (<= 0 C)
     (not (<= S 0))
     (not (= L2 1))
     (= v_69 G))
      )
      (inv_main193 B1
             O
             E
             H2
             X
             I2
             U
             B2
             J1
             R1
             J2
             A1
             Z1
             Y
             P
             R
             H1
             N2
             O2
             J
             F
             P2
             Y1
             N
             V1
             L2
             K1
             H
             I
             G
             E2
             U1
             P1
             D
             M
             M1
             v_69
             Q
             A2
             S
             V
             F2
             Z
             G1
             D2
             C1
             G2
             D1
             X1
             F1
             Q1
             S1
             L1
             Q2
             W1
             T
             A
             I1
             C2
             M2
             L
             W
             B
             N1
             K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main114 J
             L1
             O1
             X1
             P1
             W1
             S
             B
             M2
             E2
             E1
             C
             P2
             D1
             N2
             K
             F
             B1
             V1
             I
             U1
             P
             C2
             Z1
             I2
             O2
             Y
             K1
             A1
             X
             Y1
             H
             M
             W
             E
             G2
             K2
             T1
             B2
             S1
             R1
             R
             G1
             J1
             T
             O
             H1
             Q
             F2
             H2
             J2
             D2
             F1
             Z
             C1
             N
             Q1
             V
             N1
             I1
             A
             L
             M1
             L2
             A2)
        (and (not (= P1 12292))
     (not (= P1 16384))
     (not (= P1 4096))
     (not (= P1 20480))
     (not (= P1 4099))
     (not (= P1 4368))
     (not (= P1 4369))
     (not (= P1 4384))
     (not (= P1 4385))
     (not (= P1 4400))
     (not (= P1 4401))
     (not (= P1 4416))
     (not (= P1 4417))
     (not (= P1 4432))
     (not (= P1 4433))
     (not (= P1 4448))
     (not (= P1 4449))
     (not (= P1 4464))
     (not (= P1 4465))
     (not (= P1 4466))
     (not (= P1 4467))
     (not (= P1 4480))
     (= P1 4481)
     (= U 0)
     (= G 4496)
     (<= 0 K2)
     (<= 0 G2)
     (<= 0 N)
     (not (<= D 0))
     (= O2 1)
     (= v_68 X))
      )
      (inv_main193 J
             L1
             O1
             X1
             G
             W1
             S
             B
             M2
             U
             E1
             C
             P2
             D1
             N2
             K
             F
             B1
             V1
             I
             U1
             P
             C2
             Z1
             I2
             O2
             Y
             K1
             A1
             X
             Y1
             H
             M
             W
             E
             G2
             v_68
             T1
             B2
             D
             R1
             P1
             G1
             J1
             T
             O
             H1
             Q
             F2
             H2
             J2
             D2
             F1
             Z
             C1
             N
             Q1
             V
             N1
             I1
             A
             L
             M1
             L2
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main114 A
             B
             J
             H2
             K2
             P
             L1
             E1
             Z
             W
             Q
             E
             S
             T
             I
             M2
             P1
             C2
             F1
             X1
             H
             A1
             N1
             W1
             Z1
             Y
             Y1
             L
             P2
             H1
             J1
             D1
             I2
             C
             K1
             D
             L2
             N
             C1
             S1
             M
             U1
             A2
             E2
             Q1
             V
             X
             B2
             I1
             M1
             O2
             O
             G
             Q2
             T1
             R
             G2
             N2
             R1
             D2
             F
             O1
             U
             G1
             K)
        (and (not (= K2 16384))
     (not (= K2 4096))
     (not (= K2 20480))
     (not (= K2 4099))
     (not (= K2 4368))
     (not (= K2 4369))
     (not (= K2 4384))
     (not (= K2 4385))
     (not (= K2 4400))
     (not (= K2 4401))
     (not (= K2 4416))
     (not (= K2 4417))
     (not (= K2 4432))
     (not (= K2 4433))
     (not (= K2 4448))
     (not (= K2 4449))
     (not (= K2 4464))
     (not (= K2 4465))
     (not (= K2 4466))
     (not (= K2 4467))
     (not (= K2 4480))
     (= K2 4481)
     (= F2 0)
     (= V1 4512)
     (= B1 0)
     (not (= Y 1))
     (<= 0 L2)
     (<= 0 R)
     (<= 0 D)
     (not (<= J2 0))
     (not (= K2 12292))
     (= v_69 H1))
      )
      (inv_main193 A
             B
             J
             H2
             V1
             P
             L1
             E1
             Z
             B1
             Q
             E
             S
             T
             I
             M2
             P1
             C2
             F1
             X1
             H
             A1
             F2
             W1
             Z1
             Y
             Y1
             L
             P2
             H1
             J1
             D1
             I2
             C
             K1
             D
             v_69
             N
             C1
             J2
             M
             K2
             A2
             E2
             Q1
             V
             X
             B2
             I1
             M1
             O2
             O
             G
             Q2
             T1
             R
             G2
             N2
             R1
             D2
             F
             O1
             U
             G1
             K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 E1
             F
             T
             C1
             L
             N1
             D2
             C2
             N2
             Z1
             S1
             V
             H2
             L1
             Y1
             G1
             U1
             P
             R
             P1
             J1
             A2
             C
             X1
             A
             G
             G2
             E
             D
             Y
             N
             K2
             V1
             O2
             U
             J
             W1
             A1
             S
             X
             I1
             J2
             K1
             O
             P2
             K
             Z
             E2
             F1
             B1
             Q
             M1
             I2
             B2
             Q1
             W
             T1
             I
             L2
             M
             H1
             B
             D1
             F2
             O1)
        (and (= R1 4512)
     (not (= L 4513))
     (not (= L 4528))
     (not (= L 4529))
     (= L 4560)
     (not (= L 4497))
     (not (= L 4512))
     (not (= L 12292))
     (not (= L 16384))
     (not (= L 4096))
     (not (= L 20480))
     (not (= L 4099))
     (not (= L 4368))
     (not (= L 4369))
     (not (= L 4384))
     (not (= L 4385))
     (not (= L 4400))
     (not (= L 4401))
     (not (= L 4416))
     (not (= L 4417))
     (not (= L 4432))
     (not (= L 4433))
     (not (= L 4448))
     (not (= L 4449))
     (not (= L 4464))
     (not (= L 4465))
     (not (= L 4466))
     (not (= L 4467))
     (not (= L 4480))
     (not (= L 4481))
     (not (= L 4496))
     (= H 0)
     (<= 0 W1)
     (<= 0 W)
     (<= 0 J)
     (not (<= M2 0))
     (not (= H2 0)))
      )
      (inv_main193 E1
             F
             T
             C1
             R1
             N1
             D2
             C2
             N2
             H
             S1
             V
             H2
             L1
             Y1
             G1
             U1
             P
             R
             P1
             J1
             A2
             C
             X1
             A
             G
             G2
             E
             D
             Y
             N
             K2
             V1
             O2
             U
             J
             W1
             A1
             S
             M2
             I1
             L
             K1
             O
             P2
             K
             Z
             E2
             F1
             B1
             Q
             M1
             I2
             B2
             Q1
             W
             T1
             I
             L2
             M
             H1
             B
             D1
             F2
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 Y
             J
             O
             J1
             C1
             S
             Y1
             F
             A
             F1
             I1
             E1
             E2
             D2
             T1
             N2
             N1
             A1
             L2
             L
             F2
             K1
             W1
             G1
             C2
             P1
             N
             J2
             M2
             U1
             M1
             H1
             B2
             B
             U
             O1
             Q1
             L1
             Z
             G2
             D
             Q
             S1
             M
             O2
             B1
             C
             T
             R1
             D1
             I
             V
             R
             Z1
             V1
             X
             E
             A2
             K2
             P2
             K
             W
             I2
             H2
             P)
        (and (not (= C1 4513))
     (not (= C1 4528))
     (not (= C1 4529))
     (= C1 4560)
     (not (= C1 4497))
     (not (= C1 4512))
     (not (= C1 12292))
     (not (= C1 16384))
     (not (= C1 4096))
     (not (= C1 20480))
     (not (= C1 4099))
     (not (= C1 4368))
     (not (= C1 4369))
     (not (= C1 4384))
     (not (= C1 4385))
     (not (= C1 4400))
     (not (= C1 4401))
     (not (= C1 4416))
     (not (= C1 4417))
     (not (= C1 4432))
     (not (= C1 4433))
     (not (= C1 4448))
     (not (= C1 4449))
     (not (= C1 4464))
     (not (= C1 4465))
     (not (= C1 4466))
     (not (= C1 4467))
     (not (= C1 4480))
     (not (= C1 4481))
     (not (= C1 4496))
     (= H 3)
     (= G 0)
     (<= 0 Q1)
     (<= 0 O1)
     (<= 0 X)
     (not (<= X1 0))
     (= E2 0))
      )
      (inv_main193 Y
             J
             O
             J1
             H
             S
             Y1
             F
             A
             G
             I1
             E1
             E2
             D2
             T1
             N2
             N1
             A1
             L2
             L
             F2
             K1
             W1
             G1
             C2
             P1
             N
             J2
             M2
             U1
             M1
             H1
             B2
             B
             U
             O1
             Q1
             L1
             Z
             X1
             D
             C1
             S1
             M
             O2
             B1
             C
             T
             R1
             D1
             I
             V
             R
             Z1
             V1
             X
             E
             A2
             K2
             P2
             K
             W
             I2
             H2
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 B1
             I2
             E
             D2
             J1
             Z1
             I1
             H2
             K2
             Y1
             L
             F
             G
             E1
             D
             M1
             J
             B2
             O2
             L1
             V1
             O
             S
             C1
             U1
             M2
             O1
             Y
             V
             J2
             R1
             P2
             M
             W
             T
             G1
             P
             R
             C
             I
             C2
             G2
             D1
             K
             E2
             S1
             X1
             N
             N2
             A2
             X
             N1
             P1
             Z
             F2
             T1
             A1
             B
             W1
             L2
             Q
             Q1
             H1
             H
             A)
        (and (not (= J1 4513))
     (not (= J1 4528))
     (not (= J1 4529))
     (= J1 4561)
     (not (= J1 4560))
     (not (= J1 4497))
     (not (= J1 4512))
     (not (= J1 12292))
     (not (= J1 16384))
     (not (= J1 4096))
     (not (= J1 20480))
     (not (= J1 4099))
     (not (= J1 4368))
     (not (= J1 4369))
     (not (= J1 4384))
     (not (= J1 4385))
     (not (= J1 4400))
     (not (= J1 4401))
     (not (= J1 4416))
     (not (= J1 4417))
     (not (= J1 4432))
     (not (= J1 4433))
     (not (= J1 4448))
     (not (= J1 4449))
     (not (= J1 4464))
     (not (= J1 4465))
     (not (= J1 4466))
     (not (= J1 4467))
     (not (= J1 4480))
     (not (= J1 4481))
     (not (= J1 4496))
     (= F1 0)
     (not (= G 0))
     (<= 0 T1)
     (<= 0 G1)
     (<= 0 P)
     (not (<= U 0))
     (= K1 4512))
      )
      (inv_main193 B1
             I2
             E
             D2
             K1
             Z1
             I1
             H2
             K2
             F1
             L
             F
             G
             E1
             D
             M1
             J
             B2
             O2
             L1
             V1
             O
             S
             C1
             U1
             M2
             O1
             Y
             V
             J2
             R1
             P2
             M
             W
             T
             G1
             P
             R
             C
             U
             C2
             J1
             D1
             K
             E2
             S1
             X1
             N
             N2
             A2
             X
             N1
             P1
             Z
             F2
             T1
             A1
             B
             W1
             L2
             Q
             Q1
             H1
             H
             A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 I2
             C
             X1
             P1
             L2
             H
             B2
             M2
             A
             F1
             P2
             I
             N2
             K
             Z
             O2
             H1
             W1
             Q1
             G
             D2
             F
             V1
             B
             X
             J1
             O
             G2
             A2
             K2
             R
             A1
             Q
             H2
             L1
             F2
             U1
             W
             J2
             Z1
             S
             E1
             N1
             N
             I1
             D1
             B1
             V
             M
             G1
             E
             D
             O1
             U
             T1
             P
             C1
             T
             J
             C2
             K1
             M1
             Y1
             L
             S1)
        (and (not (= L2 4513))
     (not (= L2 4528))
     (not (= L2 4529))
     (= L2 4561)
     (not (= L2 4560))
     (not (= L2 4497))
     (not (= L2 4512))
     (not (= L2 12292))
     (not (= L2 16384))
     (not (= L2 4096))
     (not (= L2 20480))
     (not (= L2 4099))
     (not (= L2 4368))
     (not (= L2 4369))
     (not (= L2 4384))
     (not (= L2 4385))
     (not (= L2 4400))
     (not (= L2 4401))
     (not (= L2 4416))
     (not (= L2 4417))
     (not (= L2 4432))
     (not (= L2 4433))
     (not (= L2 4448))
     (not (= L2 4449))
     (not (= L2 4464))
     (not (= L2 4465))
     (not (= L2 4466))
     (not (= L2 4467))
     (not (= L2 4480))
     (not (= L2 4481))
     (not (= L2 4496))
     (= R1 3)
     (= Y 0)
     (<= 0 F2)
     (<= 0 U1)
     (<= 0 P)
     (not (<= E2 0))
     (= N2 0))
      )
      (inv_main193 I2
             C
             X1
             P1
             R1
             H
             B2
             M2
             A
             Y
             P2
             I
             N2
             K
             Z
             O2
             H1
             W1
             Q1
             G
             D2
             F
             V1
             B
             X
             J1
             O
             G2
             A2
             K2
             R
             A1
             Q
             H2
             L1
             F2
             U1
             W
             J2
             E2
             S
             L2
             N1
             N
             I1
             D1
             B1
             V
             M
             G1
             E
             D
             O1
             U
             T1
             P
             C1
             T
             J
             C2
             K1
             M1
             Y1
             L
             S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) ) 
    (=>
      (and
        (inv_main199 V1
             R
             U1
             S2
             E
             I2
             K1
             J2
             M
             Q
             V
             Z1
             B
             M1
             E2
             T
             A
             D2
             N
             C1
             H
             P
             N2
             Q2
             J
             Z
             E1
             G1
             A1
             I1
             T1
             K2
             D
             Q1
             H1
             H2
             M2
             J1
             U
             W
             G
             I
             B2
             W1
             P2
             A2
             F1
             F
             P1
             C2
             X
             C
             S
             D1
             O2
             L
             G2
             Y
             X1
             N1
             K
             O
             R1
             O1
             L1)
        (and (= L2 (+ 1 C1))
     (= J2 (- 64512))
     (= F2 0)
     (not (= E2 0))
     (= Y1 (+ 65280 J2))
     (= S1 4096)
     (not (= P1 0))
     (= B1 0)
     (not (= U 0))
     (not (= F 0))
     (<= 0 M2)
     (<= 0 H2)
     (<= 0 L)
     (= R2 4368))
      )
      (inv_main193 V1
             R
             U1
             S2
             R2
             I2
             B1
             J2
             S1
             F2
             V
             Z1
             B
             M1
             E2
             T
             A
             D2
             N
             L2
             H
             P
             N2
             Q2
             J
             Z
             E1
             G1
             A1
             I1
             T1
             K2
             D
             Q1
             H1
             H2
             M2
             J1
             U
             W
             G
             I
             B2
             W1
             P2
             A2
             F1
             F
             P1
             C2
             X
             C
             S
             D1
             Y1
             L
             G2
             Y
             X1
             N1
             K
             O
             R1
             O1
             L1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (v_72 Int) ) 
    (=>
      (and
        (inv_main199 W
             R2
             D
             E2
             H
             S
             L1
             Z1
             N1
             T1
             P2
             V1
             V
             M2
             J
             F2
             W1
             C1
             K1
             H1
             O
             R1
             L2
             Q1
             Q
             T
             X1
             M
             T2
             N2
             S1
             I
             M1
             B1
             D1
             L
             Z
             A
             C2
             U
             B2
             I1
             Y1
             J2
             E
             J1
             O2
             P1
             O1
             K
             F
             G2
             I2
             B
             R
             N
             Q2
             A1
             E1
             X
             S2
             G1
             U1
             A2
             P)
        (and (not (= O2 0))
     (= K2 0)
     (= H2 4096)
     (= D2 (+ 65280 Z1))
     (not (= C2 0))
     (= Z1 (- 64512))
     (not (= P1 0))
     (not (= O1 0))
     (= F1 4368)
     (not (= Y 0))
     (= J 0)
     (= G 0)
     (<= 0 Z)
     (<= 0 N)
     (<= 0 L)
     (= C (+ 1 H1))
     (= v_72 Y))
      )
      (inv_main193 W
             R2
             D
             E2
             F1
             S
             K2
             Z1
             H2
             G
             P2
             V1
             V
             M2
             Y
             F2
             W1
             C1
             K1
             C
             O
             R1
             L2
             Q1
             Q
             T
             X1
             M
             T2
             N2
             S1
             I
             M1
             B1
             v_72
             L
             Z
             A
             C2
             U
             B2
             I1
             Y1
             J2
             E
             J1
             O2
             P1
             O1
             K
             F
             G2
             I2
             B
             D2
             N
             Q2
             A1
             E1
             X
             S2
             G1
             U1
             A2
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) ) 
    (=>
      (and
        (inv_main199 M
             S1
             F
             Z1
             I2
             P
             L1
             L2
             Z
             E
             U1
             M1
             C2
             C1
             M2
             L
             P2
             G2
             O1
             K2
             V1
             A2
             I1
             O2
             X
             R1
             F1
             N2
             Q1
             E2
             S
             A
             E1
             A1
             T1
             K1
             B2
             O
             S2
             W
             Y
             G
             P1
             F2
             D1
             H2
             J1
             D2
             J
             H1
             H
             G1
             X1
             J2
             R2
             Q2
             U
             N
             B
             R
             V
             T
             B1
             D
             Y1)
        (and (= L2 (- 64512))
     (not (= D2 0))
     (= W1 0)
     (= N1 0)
     (= Q (+ 65280 L2))
     (= K 4368)
     (not (= J 0))
     (= I (+ 1 K2))
     (= C 4096)
     (= S2 0)
     (<= 0 Q2)
     (<= 0 B2)
     (<= 0 K1)
     (not (= M2 0)))
      )
      (inv_main193 M
             S1
             F
             Z1
             K
             P
             N1
             L2
             C
             W1
             U1
             M1
             C2
             C1
             M2
             L
             P2
             G2
             O1
             I
             V1
             A2
             I1
             O2
             X
             R1
             F1
             N2
             Q1
             E2
             S
             A
             E1
             A1
             T1
             K1
             B2
             O
             S2
             W
             Y
             G
             P1
             F2
             D1
             H2
             J1
             D2
             J
             H1
             H
             G1
             X1
             J2
             Q
             Q2
             U
             N
             B
             R
             V
             T
             B1
             D
             Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (v_72 Int) ) 
    (=>
      (and
        (inv_main199 B
             E1
             H1
             M2
             C
             X1
             O2
             T2
             A1
             X
             J
             H2
             U1
             C1
             F2
             B1
             S2
             O1
             Q
             I2
             Y1
             Y
             Z1
             L2
             T
             M1
             R
             P1
             A2
             K2
             T1
             E2
             O
             V1
             S1
             S
             D2
             H
             N
             L1
             V
             E
             M
             B2
             Q1
             N2
             C2
             A
             P
             J1
             Z
             P2
             R1
             N1
             I
             I1
             L
             F
             U
             R2
             G1
             D
             G
             K
             W1)
        (and (= Q2 (+ 1 I2))
     (= J2 4096)
     (= G2 (+ 65280 T2))
     (= F2 0)
     (not (= C2 0))
     (= K1 0)
     (not (= F1 0))
     (= D1 0)
     (= W 4368)
     (not (= P 0))
     (= N 0)
     (= T2 (- 64512))
     (<= 0 D2)
     (<= 0 I1)
     (<= 0 S)
     (not (= A 0))
     (= v_72 F1))
      )
      (inv_main193 B
             E1
             H1
             M2
             W
             X1
             K1
             T2
             J2
             D1
             J
             H2
             U1
             C1
             F1
             B1
             S2
             O1
             Q
             Q2
             Y1
             Y
             Z1
             L2
             T
             M1
             R
             P1
             A2
             K2
             T1
             E2
             O
             V1
             v_72
             S
             D2
             H
             N
             L1
             V
             E
             M
             B2
             Q1
             N2
             C2
             A
             P
             J1
             Z
             P2
             R1
             N1
             G2
             I1
             L
             F
             U
             R2
             G1
             D
             G
             K
             W1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) ) 
    (=>
      (and
        (inv_main114 N
             H2
             K1
             M2
             X
             S1
             J
             V1
             P1
             C
             H1
             G2
             T1
             Z1
             N2
             E
             Y1
             A2
             B2
             L
             Q2
             C1
             L2
             F2
             G1
             K2
             B1
             I
             B
             O2
             K
             M
             M1
             A
             C2
             P
             G
             N1
             D2
             Q
             W1
             P2
             O
             J2
             W
             U
             I2
             A1
             E1
             E2
             F1
             D
             U1
             H
             Q1
             J1
             I1
             X1
             R
             T
             Y
             R1
             O1
             Z
             F)
        (and (= L1 4432)
     (not (= X 12292))
     (not (= X 16384))
     (not (= X 4096))
     (not (= X 20480))
     (not (= X 4099))
     (not (= X 4368))
     (not (= X 4369))
     (not (= X 4384))
     (not (= X 4385))
     (not (= X 4400))
     (not (= X 4401))
     (= X 4416)
     (= V 0)
     (= S 4)
     (= H 3)
     (<= 0 J1)
     (<= 0 P)
     (<= 0 G)
     (not (<= D1 0))
     (not (= E2 0)))
      )
      (inv_main193 N
             H2
             K1
             M2
             L1
             S1
             J
             V1
             P1
             V
             H1
             G2
             T1
             Z1
             N2
             E
             Y1
             A2
             B2
             L
             Q2
             C1
             L2
             F2
             G1
             K2
             B1
             I
             B
             O2
             K
             M
             M1
             A
             C2
             P
             G
             N1
             D2
             D1
             W1
             X
             O
             J2
             W
             U
             I2
             A1
             E1
             E2
             F1
             D
             U1
             S
             Q1
             J1
             I1
             X1
             R
             T
             Y
             R1
             O1
             Z
             F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 O
             N
             J
             Q
             I
             Y
             V1
             L1
             X1
             F
             A1
             K1
             X
             J2
             W
             H
             E2
             A2
             I2
             S
             B2
             P
             M1
             P2
             I1
             H2
             G
             F1
             M
             F2
             Q1
             W1
             D
             L
             K2
             R
             T
             Y1
             V
             E1
             O1
             K
             H1
             M2
             D2
             C2
             T1
             E
             B
             P1
             U1
             O2
             A
             Z
             N2
             J1
             C1
             C
             L2
             G2
             G1
             U
             D1
             R1
             B1)
        (and (not (= P1 0))
     (= N1 0)
     (not (= Z 3))
     (not (= I 12292))
     (not (= I 16384))
     (not (= I 4096))
     (not (= I 20480))
     (not (= I 4099))
     (not (= I 4368))
     (not (= I 4369))
     (not (= I 4384))
     (not (= I 4385))
     (not (= I 4400))
     (not (= I 4401))
     (= I 4416)
     (<= 0 J1)
     (<= 0 T)
     (<= 0 R)
     (not (<= S1 0))
     (= Z1 4432))
      )
      (inv_main193 O
             N
             J
             Q
             Z1
             Y
             V1
             L1
             X1
             N1
             A1
             K1
             X
             J2
             W
             H
             E2
             A2
             I2
             S
             B2
             P
             M1
             P2
             I1
             H2
             G
             F1
             M
             F2
             Q1
             W1
             D
             L
             K2
             R
             T
             Y1
             V
             S1
             O1
             I
             H1
             M2
             D2
             C2
             T1
             E
             B
             P1
             U1
             O2
             A
             Z
             N2
             J1
             C1
             C
             L2
             G2
             G1
             U
             D1
             R1
             B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) ) 
    (=>
      (and
        (inv_main114 L
             J
             R
             Y
             B
             S1
             J2
             T1
             V
             G
             K
             O
             L2
             W
             Q2
             Q1
             G1
             D1
             E1
             W1
             P2
             N
             H2
             Z1
             A2
             E
             P1
             O1
             D
             U
             K2
             M
             M2
             K1
             H
             Q
             S
             I1
             X1
             N2
             F2
             B2
             C1
             Y1
             P
             B1
             F
             I2
             G2
             X
             D2
             N1
             E2
             A1
             C2
             I
             Z
             L1
             U1
             V1
             O2
             J1
             C
             T
             F1)
        (and (= M1 0)
     (= A1 3)
     (not (= X 0))
     (not (= B 12292))
     (not (= B 16384))
     (not (= B 4096))
     (not (= B 20480))
     (not (= B 4099))
     (not (= B 4368))
     (not (= B 4369))
     (not (= B 4384))
     (not (= B 4385))
     (not (= B 4400))
     (not (= B 4401))
     (not (= B 4416))
     (= B 4417)
     (= A 4)
     (<= 0 S)
     (<= 0 Q)
     (<= 0 I)
     (not (<= H1 0))
     (= R1 4432))
      )
      (inv_main193 L
             J
             R
             Y
             R1
             S1
             J2
             T1
             V
             M1
             K
             O
             L2
             W
             Q2
             Q1
             G1
             D1
             E1
             W1
             P2
             N
             H2
             Z1
             A2
             E
             P1
             O1
             D
             U
             K2
             M
             M2
             K1
             H
             Q
             S
             I1
             X1
             H1
             F2
             B
             C1
             Y1
             P
             B1
             F
             I2
             G2
             X
             D2
             N1
             E2
             A
             C2
             I
             Z
             L1
             U1
             V1
             O2
             J1
             C
             T
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 S
             V
             Z
             M1
             Q1
             P2
             T
             J2
             H2
             W
             K1
             B2
             I2
             O2
             I1
             M2
             X1
             B
             P1
             J
             K
             C
             Z1
             L2
             E
             N2
             J1
             T1
             N
             V1
             D2
             D1
             M
             G2
             Q
             R
             Y1
             E1
             F2
             I
             A1
             S1
             O1
             R1
             Y
             O
             C2
             L
             H1
             C1
             U1
             D
             K2
             B1
             L1
             P
             G
             A2
             F
             N1
             G1
             H
             U
             A
             F1)
        (and (not (= Q1 12292))
     (not (= Q1 16384))
     (not (= Q1 4096))
     (not (= Q1 20480))
     (not (= Q1 4099))
     (not (= Q1 4368))
     (not (= Q1 4369))
     (not (= Q1 4384))
     (not (= Q1 4385))
     (not (= Q1 4400))
     (not (= Q1 4401))
     (not (= Q1 4416))
     (= Q1 4417)
     (not (= C1 0))
     (not (= B1 3))
     (= X 0)
     (<= 0 Y1)
     (<= 0 R)
     (<= 0 P)
     (not (<= E2 0))
     (= W1 4432))
      )
      (inv_main193 S
             V
             Z
             M1
             W1
             P2
             T
             J2
             H2
             X
             K1
             B2
             I2
             O2
             I1
             M2
             X1
             B
             P1
             J
             K
             C
             Z1
             L2
             E
             N2
             J1
             T1
             N
             V1
             D2
             D1
             M
             G2
             Q
             R
             Y1
             E1
             F2
             E2
             A1
             Q1
             O1
             R1
             Y
             O
             C2
             L
             H1
             C1
             U1
             D
             K2
             B1
             L1
             P
             G
             A2
             F
             N1
             G1
             H
             U
             A
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main114 B2
             D2
             Y1
             K1
             V
             I
             N1
             A1
             J2
             N2
             H2
             B
             R1
             Y
             K
             L2
             J
             S1
             P1
             M1
             I2
             P2
             D1
             A
             H
             F
             V1
             I1
             G1
             X
             W1
             X1
             Q1
             N
             T1
             A2
             D
             L1
             L
             H1
             B1
             U
             C2
             C1
             F1
             Z1
             G2
             O1
             M
             U1
             R
             F2
             Q2
             C
             J1
             T
             S
             E
             G
             Q
             Z
             P
             E2
             O2
             K2)
        (and (not (= F2 0))
     (= V1 0)
     (= W 0)
     (not (= V 4497))
     (= V 4512)
     (not (= V 12292))
     (not (= V 16384))
     (not (= V 4096))
     (not (= V 20480))
     (not (= V 4099))
     (not (= V 4368))
     (not (= V 4369))
     (not (= V 4384))
     (not (= V 4385))
     (not (= V 4400))
     (not (= V 4401))
     (not (= V 4416))
     (not (= V 4417))
     (not (= V 4432))
     (not (= V 4433))
     (not (= V 4448))
     (not (= V 4449))
     (not (= V 4464))
     (not (= V 4465))
     (not (= V 4466))
     (not (= V 4467))
     (not (= V 4480))
     (not (= V 4481))
     (not (= V 4496))
     (not (= R 0))
     (= O 0)
     (<= 0 A2)
     (<= 0 T)
     (<= 0 D)
     (not (<= E1 0))
     (= M2 4528)
     (= v_69 G1))
      )
      (inv_main193 B2
             D2
             Y1
             K1
             M2
             I
             N1
             A1
             J2
             O
             H2
             B
             R1
             Y
             K
             L2
             J
             S1
             P1
             M1
             I2
             P2
             D1
             A
             H
             F
             V1
             I1
             G1
             X
             W1
             X1
             v_69
             W
             T1
             A2
             D
             L1
             L
             E1
             B1
             V
             C2
             C1
             F1
             Z1
             G2
             O1
             M
             U1
             R
             F2
             Q2
             C
             J1
             T
             S
             E
             G
             Q
             Z
             P
             E2
             O2
             K2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main114 N1
             I
             E2
             Y1
             U
             C1
             J1
             M1
             F1
             O
             Z1
             A
             C
             J
             V
             J2
             S1
             K1
             A1
             G2
             L
             A2
             H1
             U1
             E
             B
             K2
             H2
             R1
             O2
             N
             Q
             Y
             R
             Z
             P2
             D2
             N2
             X1
             D
             L1
             Q1
             T1
             D1
             T
             V1
             S
             L2
             M2
             C2
             K
             I1
             G
             W1
             G1
             F
             B2
             B1
             F2
             X
             O1
             P1
             W
             M
             E1)
        (and (= I2 4528)
     (not (= I1 0))
     (not (= U 4497))
     (= U 4512)
     (not (= U 12292))
     (not (= U 16384))
     (not (= U 4096))
     (not (= U 20480))
     (not (= U 4099))
     (not (= U 4368))
     (not (= U 4369))
     (not (= U 4384))
     (not (= U 4385))
     (not (= U 4400))
     (not (= U 4401))
     (not (= U 4416))
     (not (= U 4417))
     (not (= U 4432))
     (not (= U 4433))
     (not (= U 4448))
     (not (= U 4449))
     (not (= U 4464))
     (not (= U 4465))
     (not (= U 4466))
     (not (= U 4467))
     (not (= U 4480))
     (not (= U 4481))
     (not (= U 4496))
     (not (= K 0))
     (= H 0)
     (<= 0 D2)
     (<= 0 F)
     (<= 0 P2)
     (not (<= P 0))
     (not (= K2 0))
     (= v_68 R1)
     (= v_69 Q))
      )
      (inv_main193 N1
             I
             E2
             Y1
             I2
             C1
             J1
             M1
             F1
             H
             Z1
             A
             C
             J
             V
             J2
             S1
             K1
             A1
             G2
             L
             A2
             H1
             U1
             E
             B
             K2
             H2
             R1
             O2
             N
             Q
             v_68
             v_69
             Z
             P2
             D2
             N2
             X1
             P
             L1
             U
             T1
             D1
             T
             V1
             S
             L2
             M2
             C2
             K
             I1
             G
             W1
             G1
             F
             B2
             B1
             F2
             X
             O1
             P1
             W
             M
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main114 Q
             J
             E2
             D2
             X1
             N2
             M1
             N1
             P2
             M
             C
             W
             B1
             G
             G1
             C2
             V
             J1
             Y
             P1
             T
             O2
             S1
             I1
             E
             Y1
             U
             K2
             H2
             C1
             Q1
             H1
             H
             F1
             Q2
             L2
             D
             V1
             X
             B
             F
             W1
             Z
             Z1
             A
             T1
             A2
             L
             A1
             G2
             M2
             B2
             O1
             R1
             E1
             P
             K1
             L1
             O
             N
             J2
             I
             R
             F2
             D1)
        (and (= I2 0)
     (not (= B2 0))
     (= X1 4513)
     (not (= X1 4497))
     (not (= X1 4512))
     (not (= X1 12292))
     (not (= X1 16384))
     (not (= X1 4096))
     (not (= X1 20480))
     (not (= X1 4099))
     (not (= X1 4368))
     (not (= X1 4369))
     (not (= X1 4384))
     (not (= X1 4385))
     (not (= X1 4400))
     (not (= X1 4401))
     (not (= X1 4416))
     (not (= X1 4417))
     (not (= X1 4432))
     (not (= X1 4433))
     (not (= X1 4448))
     (not (= X1 4449))
     (not (= X1 4464))
     (not (= X1 4465))
     (not (= X1 4466))
     (not (= X1 4467))
     (not (= X1 4480))
     (not (= X1 4481))
     (not (= X1 4496))
     (= U 0)
     (= S 4528)
     (= K 0)
     (<= 0 L2)
     (<= 0 P)
     (<= 0 D)
     (not (<= U1 0))
     (not (= M2 0))
     (= v_69 H2))
      )
      (inv_main193 Q
             J
             E2
             D2
             S
             N2
             M1
             N1
             P2
             I2
             C
             W
             B1
             G
             G1
             C2
             V
             J1
             Y
             P1
             T
             O2
             S1
             I1
             E
             Y1
             U
             K2
             H2
             C1
             Q1
             H1
             v_69
             K
             Q2
             L2
             D
             V1
             X
             U1
             F
             X1
             Z
             Z1
             A
             T1
             A2
             L
             A1
             G2
             M2
             B2
             O1
             R1
             E1
             P
             K1
             L1
             O
             N
             J2
             I
             R
             F2
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main114 H2
             I2
             B
             Z1
             K1
             A1
             D2
             G2
             H1
             Y
             I
             X1
             D1
             E
             R1
             N2
             P2
             B2
             M1
             M2
             D
             O2
             T1
             G
             U
             S
             J1
             C1
             A
             C
             C2
             F1
             P1
             A2
             F2
             Z
             N1
             O
             Q
             U1
             S1
             W
             G1
             L1
             T
             J
             Y1
             X
             E1
             K
             F
             E2
             Q1
             R
             P
             I1
             M
             V
             H
             N
             V1
             L2
             O1
             K2
             L)
        (and (not (= E2 0))
     (= K1 4513)
     (not (= K1 4497))
     (not (= K1 4512))
     (not (= K1 12292))
     (not (= K1 16384))
     (not (= K1 4096))
     (not (= K1 20480))
     (not (= K1 4099))
     (not (= K1 4368))
     (not (= K1 4369))
     (not (= K1 4384))
     (not (= K1 4385))
     (not (= K1 4400))
     (not (= K1 4401))
     (not (= K1 4416))
     (not (= K1 4417))
     (not (= K1 4432))
     (not (= K1 4433))
     (not (= K1 4448))
     (not (= K1 4449))
     (not (= K1 4464))
     (not (= K1 4465))
     (not (= K1 4466))
     (not (= K1 4467))
     (not (= K1 4480))
     (not (= K1 4481))
     (not (= K1 4496))
     (not (= J1 0))
     (= B1 4528)
     (not (= F 0))
     (<= 0 N1)
     (<= 0 I1)
     (<= 0 Z)
     (not (<= W1 0))
     (= J2 0)
     (= v_68 A)
     (= v_69 F1))
      )
      (inv_main193 H2
             I2
             B
             Z1
             B1
             A1
             D2
             G2
             H1
             J2
             I
             X1
             D1
             E
             R1
             N2
             P2
             B2
             M1
             M2
             D
             O2
             T1
             G
             U
             S
             J1
             C1
             A
             C
             C2
             F1
             v_68
             v_69
             F2
             Z
             N1
             O
             Q
             W1
             S1
             K1
             G1
             L1
             T
             J
             Y1
             X
             E1
             K
             F
             E2
             Q1
             R
             P
             I1
             M
             V
             H
             N
             V1
             L2
             O1
             K2
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main265 A1
             E
             Q2
             P2
             Q
             I
             J2
             C1
             H
             F1
             G
             Q1
             B1
             Z1
             S
             C2
             N
             V1
             O1
             A2
             E1
             U1
             R1
             Y1
             C
             M1
             A
             G1
             W1
             N1
             O
             L2
             J1
             X1
             S1
             K
             N2
             U
             E2
             I2
             T1
             H1
             O2
             M2
             W
             Z
             V
             F
             X
             H2
             D2
             P1
             M
             B
             R
             G2
             D1
             Y
             F2
             J
             K2
             K1
             B2
             L1
             P)
        (and (= I1 3)
     (= T 0)
     (= D 4416)
     (= B 2)
     (<= 0 N2)
     (<= 0 G2)
     (<= 0 K)
     (not (<= L 0))
     (= N1 (- 256))
     (= v_69 N1))
      )
      (inv_main193 A1
             E
             Q2
             P2
             D
             I
             J2
             C1
             H
             T
             G
             Q1
             B1
             Z1
             S
             C2
             N
             V1
             O1
             A2
             E1
             U1
             R1
             Y1
             C
             M1
             A
             G1
             W1
             N1
             O
             L2
             J1
             X1
             S1
             K
             N2
             U
             E2
             L
             T1
             H1
             O2
             M2
             W
             Z
             V
             F
             X
             H2
             D2
             P1
             M
             I1
             R
             v_69
             D1
             Y
             F2
             J
             K2
             K1
             B2
             L1
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main265 E1
             M2
             D1
             T
             S1
             P2
             N
             P1
             R
             O1
             J2
             C
             G1
             Y1
             B
             H2
             R1
             W1
             G
             B1
             F2
             M
             H
             A2
             Z
             V1
             S
             Q
             X
             X1
             O2
             U1
             W
             Q1
             J1
             N2
             V
             L2
             K2
             B2
             I1
             Y
             D
             I
             C1
             F1
             K
             M1
             N1
             H1
             G2
             F
             E2
             L
             O
             A1
             D2
             J
             I2
             P
             Q2
             K1
             C2
             E
             T1)
        (and (= L1 4416)
     (= U 5)
     (= L 4)
     (not (= L 2))
     (= A 0)
     (<= 0 N2)
     (<= 0 A1)
     (<= 0 V)
     (not (<= Z1 0))
     (= X1 (- 256))
     (= v_69 X1))
      )
      (inv_main193 E1
             M2
             D1
             T
             L1
             P2
             N
             P1
             R
             A
             J2
             C
             G1
             Y1
             B
             H2
             R1
             W1
             G
             B1
             F2
             M
             H
             A2
             Z
             V1
             S
             Q
             X
             X1
             O2
             U1
             W
             Q1
             J1
             N2
             V
             L2
             K2
             Z1
             I1
             Y
             D
             I
             C1
             F1
             K
             M1
             N1
             H1
             G2
             F
             E2
             U
             O
             v_69
             D2
             J
             I2
             P
             Q2
             K1
             C2
             E
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main265 W
             N2
             E1
             N1
             V1
             L2
             Q1
             A2
             G1
             X
             J1
             U
             B2
             F1
             Y1
             O1
             F
             J2
             C2
             Z
             W1
             S1
             H
             P
             A
             C
             K2
             V
             T1
             O2
             L
             Q
             T
             S
             C1
             E
             A1
             B1
             Y
             X1
             L1
             H2
             J
             B
             I2
             I
             G2
             D
             F2
             P1
             O
             N
             D1
             M1
             H1
             M
             R
             K
             E2
             M2
             R1
             G
             Z1
             P2
             I1)
        (and (= D2 4416)
     (not (= M1 4))
     (not (= M1 2))
     (= K1 0)
     (<= 0 A1)
     (<= 0 M)
     (<= 0 E)
     (not (<= U1 0))
     (= O2 (- 256))
     (= v_68 O2))
      )
      (inv_main193 W
             N2
             E1
             N1
             D2
             L2
             Q1
             A2
             G1
             K1
             J1
             U
             B2
             F1
             Y1
             O1
             F
             J2
             C2
             Z
             W1
             S1
             H
             P
             A
             C
             K2
             V
             T1
             O2
             L
             Q
             T
             S
             C1
             E
             A1
             B1
             Y
             U1
             L1
             H2
             J
             B
             I2
             I
             G2
             D
             F2
             P1
             O
             N
             D1
             M1
             H1
             v_68
             R
             K
             E2
             M2
             R1
             G
             Z1
             P2
             I1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 F1
             N1
             P
             Y
             R1
             C1
             R
             U
             U1
             N
             F2
             A2
             J2
             L
             L1
             E2
             S
             C2
             C
             G1
             Z
             Y1
             W1
             X1
             T
             O1
             E
             G
             V1
             L2
             D
             Q
             I2
             E1
             X
             I1
             J1
             G2
             T1
             O
             S1
             M2
             A
             D1
             B2
             M1
             M
             A1
             K1
             Z1
             B1
             H1
             H
             W
             D2
             I
             Q1
             H2
             K
             B
             J
             P1
             K2
             V
             F)
        (and (not (= R1 16384))
     (not (= R1 4096))
     (not (= R1 20480))
     (not (= R1 4099))
     (not (= R1 4368))
     (not (= R1 4369))
     (not (= R1 4384))
     (not (= R1 4385))
     (= R1 4400)
     (<= 0 J1)
     (<= 0 I1)
     (<= 0 I)
     (not (= R1 12292))
     (= v_65 R1))
      )
      (inv_main265 F1
             N1
             P
             Y
             R1
             C1
             R
             U
             U1
             N
             F2
             A2
             J2
             L
             L1
             E2
             S
             C2
             C
             G1
             Z
             Y1
             W1
             X1
             T
             O1
             E
             G
             V1
             L2
             D
             Q
             I2
             E1
             X
             I1
             J1
             G2
             T1
             O
             S1
             v_65
             A
             D1
             B2
             M1
             M
             A1
             K1
             Z1
             B1
             H1
             H
             W
             D2
             I
             Q1
             H2
             K
             B
             J
             P1
             K2
             V
             F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 O1
             C
             Q1
             A1
             K2
             D1
             Z1
             X1
             V1
             D2
             E
             B
             Y
             J2
             H2
             S
             H1
             I2
             M2
             M
             V
             P
             K1
             J
             T
             F1
             S1
             P1
             M1
             I
             G1
             N
             N1
             C2
             Q
             R1
             W
             O
             X
             U
             W1
             E2
             R
             F2
             T1
             A
             L
             F
             E1
             D
             L1
             G2
             K
             Y1
             Z
             B1
             C1
             J1
             U1
             A2
             H
             B2
             G
             I1
             L2)
        (and (not (= K2 16384))
     (not (= K2 4096))
     (not (= K2 20480))
     (not (= K2 4099))
     (not (= K2 4368))
     (not (= K2 4369))
     (not (= K2 4384))
     (not (= K2 4385))
     (not (= K2 4400))
     (= K2 4401)
     (<= 0 R1)
     (<= 0 B1)
     (<= 0 W)
     (not (= K2 12292))
     (= v_65 K2))
      )
      (inv_main265 O1
             C
             Q1
             A1
             K2
             D1
             Z1
             X1
             V1
             D2
             E
             B
             Y
             J2
             H2
             S
             H1
             I2
             M2
             M
             V
             P
             K1
             J
             T
             F1
             S1
             P1
             M1
             I
             G1
             N
             N1
             C2
             Q
             R1
             W
             O
             X
             U
             W1
             v_65
             R
             F2
             T1
             A
             L
             F
             E1
             D
             L1
             G2
             K
             Y1
             Z
             B1
             C1
             J1
             U1
             A2
             H
             B2
             G
             I1
             L2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main193 K2
             W
             F1
             T1
             C1
             D2
             L1
             E1
             F
             H1
             B1
             C
             L2
             J1
             C2
             A1
             Z
             Q
             I1
             W1
             R
             E
             P1
             A2
             I
             S1
             S
             N
             N1
             O1
             H2
             L
             T
             D
             M
             Y
             K1
             G2
             B
             V
             M1
             V1
             J
             K
             U1
             D1
             B2
             U
             G
             Z1
             F2
             X
             Y1
             R1
             P
             O
             J2
             M2
             G1
             I2
             H
             Q1
             A
             X1
             E2)
        (and (= N 0) (= J 0) (<= 0 K1) (<= 0 Y) (<= 0 O) (= A1 0))
      )
      (inv_main449 K2
             W
             F1
             T1
             C1
             D2
             L1
             E1
             F
             H1
             B1
             C
             L2
             J1
             C2
             A1
             Z
             Q
             I1
             W1
             R
             E
             P1
             A2
             I
             S1
             S
             N
             N1
             O1
             H2
             L
             T
             D
             M
             Y
             K1
             G2
             B
             V
             M1
             V1
             J
             K
             U1
             D1
             B2
             U
             G
             Z1
             F2
             X
             Y1
             R1
             P
             O
             J2
             M2
             G1
             I2
             H
             Q1
             A
             X1
             E2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main193 E1
             I
             G1
             Q
             O
             N2
             C
             L2
             G
             T
             A2
             J1
             Y1
             X
             E
             S
             U1
             F1
             K
             D
             H
             J
             M2
             X1
             A1
             P1
             D2
             U
             V
             O1
             S1
             K1
             V1
             H2
             M
             Y
             F2
             K2
             P
             T1
             W1
             L
             E2
             I2
             B2
             H1
             G2
             B
             N1
             I1
             L1
             Z1
             Q1
             M1
             B1
             F
             Z
             C1
             C2
             R1
             A
             N
             D1
             W
             J2)
        (and (= U 0) (not (= S 0)) (<= 0 F2) (<= 0 Y) (<= 0 F) (not (<= R 0)) (= E2 0))
      )
      (inv_main449 E1
             I
             G1
             Q
             O
             N2
             C
             L2
             G
             T
             A2
             J1
             Y1
             X
             E
             S
             U1
             F1
             K
             D
             H
             J
             M2
             X1
             A1
             P1
             D2
             U
             V
             O1
             S1
             K1
             V1
             H2
             M
             Y
             F2
             K2
             P
             R
             W1
             L
             E2
             I2
             B2
             H1
             G2
             B
             N1
             I1
             L1
             Z1
             Q1
             M1
             B1
             F
             Z
             C1
             C2
             R1
             A
             N
             D1
             W
             J2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main114 C
             Y1
             Q1
             K1
             Q
             F1
             M
             E2
             O1
             Y
             N1
             W
             I1
             B2
             T
             W1
             K
             N2
             B
             V1
             M2
             L2
             D1
             J1
             M1
             J
             P
             V
             C1
             D
             I2
             T1
             E1
             X1
             O
             S
             H2
             A2
             R1
             N
             H
             L1
             C2
             J2
             D2
             G
             S1
             X
             U1
             E
             F2
             A1
             Z
             G1
             G2
             K2
             I
             P1
             O2
             F
             A
             B1
             H1
             U
             R)
        (and (not (= Q 12292))
     (not (= Q 16384))
     (not (= Q 4096))
     (not (= Q 20480))
     (not (= Q 4099))
     (not (= Q 4368))
     (not (= Q 4369))
     (= Q 4384)
     (= L 2)
     (<= 0 K2)
     (<= 0 H2)
     (<= 0 S)
     (= G1 1)
     (= v_67 Q))
      )
      (inv_main254 C
             Y1
             Q1
             K1
             Q
             F1
             M
             E2
             O1
             Y
             N1
             W
             I1
             B2
             T
             W1
             K
             N2
             B
             V1
             M2
             L2
             D1
             J1
             M1
             J
             P
             V
             C1
             D
             I2
             T1
             E1
             X1
             O
             S
             H2
             A2
             R1
             Z1
             H
             v_67
             C2
             J2
             D2
             G
             S1
             X
             U1
             E
             F2
             A1
             Z
             L
             G2
             K2
             I
             P1
             O2
             F
             A
             B1
             H1
             U
             R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main114 C
             M1
             E2
             A2
             K
             Q1
             B2
             J
             S1
             I1
             R
             G2
             Z1
             E1
             L2
             P
             Y
             R1
             D
             D2
             W
             F1
             U1
             V
             E
             C2
             Q
             U
             N2
             O
             K1
             G
             D1
             M
             F2
             A
             M2
             C1
             A1
             Z
             P1
             K2
             I
             T
             T1
             B
             J2
             H1
             S
             H2
             J1
             W1
             L1
             F
             G1
             Y1
             O1
             I2
             X
             V1
             N1
             X1
             B1
             N
             L)
        (and (not (= K 16384))
     (not (= K 4096))
     (not (= K 20480))
     (not (= K 4099))
     (not (= K 4368))
     (not (= K 4369))
     (= K 4384)
     (not (= F 1))
     (<= 0 M2)
     (<= 0 Y1)
     (<= 0 A)
     (not (= K 12292))
     (= v_66 K))
      )
      (inv_main254 C
             M1
             E2
             A2
             K
             Q1
             B2
             J
             S1
             I1
             R
             G2
             Z1
             E1
             L2
             P
             Y
             R1
             D
             D2
             W
             F1
             U1
             V
             E
             C2
             Q
             U
             N2
             O
             K1
             G
             D1
             M
             F2
             A
             M2
             C1
             A1
             H
             P1
             v_66
             I
             T
             T1
             B
             J2
             H1
             S
             H2
             J1
             W1
             L1
             F
             G1
             Y1
             O1
             I2
             X
             V1
             N1
             X1
             B1
             N
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main114 I2
             E1
             B
             N2
             S1
             S
             K
             L1
             R1
             W
             B1
             K2
             Z1
             I1
             M2
             M1
             Y1
             Z
             G
             A
             R
             Q1
             A2
             P1
             L2
             N
             Y
             M
             I
             F
             X1
             C
             H1
             P
             F2
             L
             U1
             D1
             E2
             D2
             O
             X
             C2
             H2
             G1
             E
             C1
             T
             N1
             O1
             U
             W1
             J1
             K1
             F1
             G2
             H
             O2
             D
             V
             A1
             Q
             T1
             V1
             J2)
        (and (not (= S1 16384))
     (not (= S1 4096))
     (not (= S1 20480))
     (not (= S1 4099))
     (not (= S1 4368))
     (not (= S1 4369))
     (not (= S1 4384))
     (= S1 4385)
     (= K1 1)
     (= J 2)
     (<= 0 G2)
     (<= 0 U1)
     (<= 0 L)
     (not (= S1 12292))
     (= v_67 S1))
      )
      (inv_main254 I2
             E1
             B
             N2
             S1
             S
             K
             L1
             R1
             W
             B1
             K2
             Z1
             I1
             M2
             M1
             Y1
             Z
             G
             A
             R
             Q1
             A2
             P1
             L2
             N
             Y
             M
             I
             F
             X1
             C
             H1
             P
             F2
             L
             U1
             D1
             E2
             B2
             O
             v_67
             C2
             H2
             G1
             E
             C1
             T
             N1
             O1
             U
             W1
             J1
             J
             F1
             G2
             H
             O2
             D
             V
             A1
             Q
             T1
             V1
             J2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main114 E1
             L2
             W1
             K2
             Q1
             P
             J
             Y
             G
             E2
             Y1
             N
             K1
             F
             G1
             N2
             A2
             D2
             D1
             B
             T
             H2
             B1
             X
             A1
             M1
             T1
             C2
             M
             P1
             Q
             C1
             J1
             A
             R
             E
             D
             F1
             U
             L
             Z
             U1
             M2
             I1
             B2
             Z1
             J2
             I2
             K
             O
             H1
             I
             R1
             V
             C
             O1
             N1
             S
             X1
             G2
             V1
             S1
             W
             H
             F2)
        (and (not (= Q1 16384))
     (not (= Q1 4096))
     (not (= Q1 20480))
     (not (= Q1 4099))
     (not (= Q1 4368))
     (not (= Q1 4369))
     (not (= Q1 4384))
     (= Q1 4385)
     (not (= V 1))
     (<= 0 O1)
     (<= 0 E)
     (<= 0 D)
     (not (= Q1 12292))
     (= v_66 Q1))
      )
      (inv_main254 E1
             L2
             W1
             K2
             Q1
             P
             J
             Y
             G
             E2
             Y1
             N
             K1
             F
             G1
             N2
             A2
             D2
             D1
             B
             T
             H2
             B1
             X
             A1
             M1
             T1
             C2
             M
             P1
             Q
             C1
             J1
             A
             R
             E
             D
             F1
             U
             L1
             Z
             v_66
             M2
             I1
             B2
             Z1
             J2
             I2
             K
             O
             H1
             I
             R1
             V
             C
             O1
             N1
             S
             X1
             G2
             V1
             S1
             W
             H
             F2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 L1
             K2
             D
             A2
             E1
             M2
             D2
             O1
             U1
             Z1
             S
             D1
             I2
             G2
             W1
             T1
             L
             V
             P
             G
             R1
             C2
             F
             M1
             N
             Q1
             J
             B
             U
             B2
             I
             Y1
             M
             L2
             A
             N1
             J2
             C1
             B1
             X1
             H
             H2
             K1
             F2
             R
             O
             Z
             X
             Y
             T
             I1
             Q
             G1
             S1
             W
             J1
             A1
             P1
             V1
             E2
             F1
             E
             C
             K
             H1)
        (and (not (= E1 16384))
     (not (= E1 4096))
     (not (= E1 20480))
     (= E1 4099)
     (<= 0 J2)
     (<= 0 N1)
     (<= 0 J1)
     (not (= E1 12292))
     (= v_65 E1))
      )
      (inv_main199 L1
             K2
             D
             A2
             E1
             M2
             D2
             O1
             U1
             Z1
             S
             D1
             I2
             G2
             W1
             T1
             L
             V
             P
             G
             R1
             C2
             F
             M1
             N
             Q1
             J
             B
             U
             B2
             I
             Y1
             M
             L2
             A
             N1
             J2
             C1
             B1
             X1
             H
             v_65
             K1
             F2
             R
             O
             Z
             X
             Y
             T
             I1
             Q
             G1
             S1
             W
             J1
             A1
             P1
             V1
             E2
             F1
             E
             C
             K
             H1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 I1
             J2
             S
             I2
             K2
             X
             M2
             R
             L1
             Z1
             D2
             T1
             H2
             Q
             Y
             R1
             D1
             C1
             V
             P
             Z
             B1
             J1
             E1
             N
             W1
             G
             X1
             K1
             D
             U
             N1
             I
             A1
             E
             H1
             B
             J
             C2
             F2
             U1
             G2
             C
             F1
             Q1
             O
             E2
             A2
             F
             M
             A
             G1
             L
             H
             B2
             S1
             O1
             P1
             T
             V1
             W
             L2
             M1
             K
             Y1)
        (and (not (= K2 16384))
     (not (= K2 4096))
     (= K2 20480)
     (<= 0 S1)
     (<= 0 H1)
     (<= 0 B)
     (not (= K2 12292))
     (= v_65 K2))
      )
      (inv_main199 I1
             J2
             S
             I2
             K2
             X
             M2
             R
             L1
             Z1
             D2
             T1
             H2
             Q
             Y
             R1
             D1
             C1
             V
             P
             Z
             B1
             J1
             E1
             N
             W1
             G
             X1
             K1
             D
             U
             N1
             I
             A1
             E
             H1
             B
             J
             C2
             F2
             U1
             v_65
             C
             F1
             Q1
             O
             E2
             A2
             F
             M
             A
             G1
             L
             H
             B2
             S1
             O1
             P1
             T
             V1
             W
             L2
             M1
             K
             Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 O1
             Q
             A1
             Z1
             L
             O
             G1
             I2
             L2
             P1
             A2
             N1
             U1
             M
             C2
             X1
             G
             K
             U
             B1
             L1
             R1
             I
             F2
             J
             K2
             S1
             F1
             T1
             V
             I1
             B2
             J2
             V1
             Y1
             C1
             M1
             E1
             S
             E2
             A
             H2
             H
             D
             K1
             Q1
             C
             J1
             W
             N
             X
             Y
             F
             B
             W1
             H1
             E
             P
             M2
             R
             G2
             T
             D1
             D2
             Z)
        (and (not (= L 16384))
     (= L 4096)
     (<= 0 M1)
     (<= 0 H1)
     (<= 0 C1)
     (not (= L 12292))
     (= v_65 L))
      )
      (inv_main199 O1
             Q
             A1
             Z1
             L
             O
             G1
             I2
             L2
             P1
             A2
             N1
             U1
             M
             C2
             X1
             G
             K
             U
             B1
             L1
             R1
             I
             F2
             J
             K2
             S1
             F1
             T1
             V
             I1
             B2
             J2
             V1
             Y1
             C1
             M1
             E1
             S
             E2
             A
             v_65
             H
             D
             K1
             Q1
             C
             J1
             W
             N
             X
             Y
             F
             B
             W1
             H1
             E
             P
             M2
             R
             G2
             T
             D1
             D2
             Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 G1
             H
             Z1
             M
             U
             J2
             E1
             Y
             F2
             L1
             G
             C
             Y1
             S
             N1
             F1
             Z
             Q1
             R1
             C1
             B2
             K1
             F
             A2
             K2
             E
             W1
             X
             X1
             H2
             J1
             M1
             E2
             D
             Q
             U1
             G2
             A
             T1
             S1
             J
             W
             T
             H1
             B1
             M2
             D2
             P1
             I
             I2
             O1
             B
             O
             A1
             V1
             N
             R
             V
             L2
             I1
             K
             D1
             P
             C2
             L)
        (and (= U 16384) (<= 0 G2) (<= 0 U1) (<= 0 N) (not (= U 12292)) (= v_65 U))
      )
      (inv_main199 G1
             H
             Z1
             M
             U
             J2
             E1
             Y
             F2
             L1
             G
             C
             Y1
             S
             N1
             F1
             Z
             Q1
             R1
             C1
             B2
             K1
             F
             A2
             K2
             E
             W1
             X
             X1
             H2
             J1
             M1
             E2
             D
             Q
             U1
             G2
             A
             T1
             S1
             J
             v_65
             T
             H1
             B1
             M2
             D2
             P1
             I
             I2
             O1
             B
             O
             A1
             V1
             N
             R
             V
             L2
             I1
             K
             D1
             P
             C2
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 A
             E1
             W1
             G
             W
             F1
             Y1
             C2
             X
             F
             B2
             N1
             T1
             R
             S
             Q
             B1
             X1
             A1
             M1
             P
             H1
             J
             G1
             L1
             U
             E
             L2
             T
             I1
             P1
             J2
             C
             N
             A2
             K1
             R1
             Z
             K2
             O1
             N2
             U1
             D1
             S1
             H2
             O2
             M
             I
             J1
             L
             V1
             B
             M2
             I2
             Q1
             Y
             G2
             V
             Z1
             K
             E2
             P2
             O
             D
             F2)
        (and (= C1 4096)
     (= W 12292)
     (= H (+ 1 A1))
     (<= 0 R1)
     (<= 0 K1)
     (<= 0 Y)
     (= D2 1))
      )
      (inv_main199 A
             E1
             W1
             G
             C1
             D2
             Y1
             C2
             X
             F
             B2
             N1
             T1
             R
             S
             Q
             B1
             X1
             H
             M1
             P
             H1
             J
             G1
             L1
             U
             E
             L2
             T
             I1
             P1
             J2
             C
             N
             A2
             K1
             R1
             Z
             K2
             O1
             N2
             W
             D1
             S1
             H2
             O2
             M
             I
             J1
             L
             V1
             B
             M2
             I2
             Q1
             Y
             G2
             V
             Z1
             K
             E2
             P2
             O
             D
             F2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main3 S1)
        (and (= G2 0)
     (= Y1 12292)
     (= X1 1)
     (not (= M1 0))
     (= T 0)
     (= O 12292)
     (= G 12292)
     (= C (- 1))
     (<= 0 T1)
     (<= 0 O1)
     (<= 0 E1)
     (= L2 0)
     (= v_66 M1))
      )
      (inv_main108 Y1
             O
             M1
             G1
             G
             N2
             H1
             I
             D2
             U1
             Q
             P
             F2
             M
             X1
             V1
             C1
             K2
             I2
             H
             D
             L
             L1
             U
             H2
             N1
             J1
             K
             R
             J2
             A2
             C2
             X
             E
             F
             F1
             T1
             R1
             v_66
             C
             W
             Z1
             L2
             G2
             E2
             V
             B1
             Q1
             A1
             D1
             B
             Y
             K1
             T
             A
             O1
             S
             P1
             B2
             W1
             M2
             N
             I1
             Z
             J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main3 I1)
        (and (= G2 0)
     (= B2 12292)
     (= R1 0)
     (= G1 0)
     (not (= C1 0))
     (= P 12292)
     (= M 12292)
     (= J 1)
     (= H 0)
     (<= 0 K1)
     (<= 0 F1)
     (<= 0 I)
     (= J2 (- 1))
     (= v_66 C1))
      )
      (inv_main108 P
             M
             G1
             G
             B2
             N2
             J1
             W
             O1
             F2
             W1
             F
             E
             M2
             J
             Y
             S
             C1
             Q1
             T1
             P1
             V1
             O
             M1
             Z
             U1
             D
             L1
             E2
             B1
             N1
             X
             R
             B
             D1
             S1
             K1
             A2
             v_66
             J2
             I2
             C
             R1
             G2
             H1
             X1
             V
             A1
             K
             K2
             E1
             L
             L2
             H
             C2
             I
             Q
             A
             H2
             U
             D2
             T
             N
             Z1
             Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main3 J1)
        (and (= H2 0)
     (= C2 0)
     (= Q1 12292)
     (= M1 12292)
     (= W (- 1))
     (= J 0)
     (= G 12292)
     (= E 0)
     (= D 1)
     (= B 0)
     (<= 0 Y)
     (<= 0 N)
     (<= 0 M)
     (= L2 0))
      )
      (inv_main108 M1
             G
             J
             G2
             Q1
             Y1
             M2
             K2
             V
             J2
             I
             N1
             A1
             C
             D
             W1
             O2
             E
             F
             U
             N2
             D1
             I2
             A
             R1
             A2
             K1
             P1
             S1
             V1
             H
             G1
             O
             Z
             F2
             Z1
             M
             L1
             B
             W
             B2
             U1
             L2
             C2
             K
             X1
             Q
             E2
             T
             F1
             S
             E1
             D2
             H2
             T1
             Y
             C1
             I1
             L
             O1
             H1
             B1
             R
             X
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main108 K
             P
             Y1
             H1
             N2
             X
             C
             G2
             J
             J2
             V
             R1
             T
             D
             A1
             Q1
             T1
             L2
             D2
             C2
             O1
             W1
             C1
             X1
             P1
             A
             G1
             F1
             H
             R
             H2
             B2
             F
             M2
             E1
             U
             I2
             N
             B
             S
             K1
             G
             D1
             F2
             J1
             I1
             M
             Z1
             E
             I
             B1
             W
             V1
             K2
             U1
             E2
             S1
             L1
             L
             Q
             M1
             O
             A2
             Y
             Z)
        (and (= J1 (- 12288)) (<= 0 I2) (<= 0 E2) (<= 0 U) (= N1 (+ 1 H1)))
      )
      (inv_main114 K
             P
             Y1
             N1
             N2
             X
             C
             G2
             J
             J2
             V
             R1
             T
             D
             A1
             Q1
             T1
             L2
             D2
             C2
             O1
             W1
             C1
             X1
             P1
             A
             G1
             F1
             H
             R
             H2
             B2
             F
             M2
             E1
             U
             I2
             N
             B
             S
             K1
             G
             D1
             F2
             J1
             I1
             M
             Z1
             E
             I
             B1
             W
             V1
             K2
             U1
             E2
             S1
             L1
             L
             Q
             M1
             O
             A2
             Y
             Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main108 X1
             N
             S
             V
             D
             N2
             R1
             L2
             A
             U1
             Z1
             M1
             W
             D2
             G2
             K2
             I
             T
             H
             P1
             A1
             E1
             B1
             Q
             X
             U
             C
             D1
             Y1
             P
             I1
             J
             G
             V1
             I2
             L
             K1
             F2
             J2
             O
             E2
             S1
             M
             G1
             F
             W1
             C2
             R
             L1
             A2
             Z
             F1
             Y
             M2
             J1
             B
             E
             Q1
             K
             H1
             O1
             C1
             B2
             H2
             T1)
        (and (= N1 (+ 1 V))
     (not (= F (- 12288)))
     (<= 0 K1)
     (<= 0 L)
     (<= 0 B)
     (not (= W1 (- 16384))))
      )
      (inv_main114 X1
             N
             S
             N1
             D
             N2
             R1
             L2
             A
             U1
             Z1
             M1
             W
             D2
             G2
             K2
             I
             T
             H
             P1
             A1
             E1
             B1
             Q
             X
             U
             C
             D1
             Y1
             P
             I1
             J
             G
             V1
             I2
             L
             K1
             F2
             J2
             O
             E2
             S1
             M
             G1
             F
             W1
             C2
             R
             L1
             A2
             Z
             F1
             Y
             M2
             J1
             B
             E
             Q1
             K
             H1
             O1
             C1
             B2
             H2
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main108 L1
             C2
             C1
             O
             T1
             H
             R
             L2
             U1
             T
             Q
             E
             R1
             K1
             I1
             D
             K2
             D1
             G
             J1
             F2
             A
             B
             N2
             B1
             Z1
             F
             F1
             I
             K
             S
             V1
             N
             X
             L
             O1
             Y
             D2
             A1
             A2
             J
             W1
             E2
             B2
             X1
             I2
             P
             C
             J2
             U
             W
             M
             Q1
             G1
             G2
             S1
             H2
             M2
             N1
             E1
             Y1
             H1
             Z
             M1
             V)
        (and (not (= X1 (- 12288)))
     (= P1 (+ 1 O))
     (<= 0 S1)
     (<= 0 O1)
     (<= 0 Y)
     (= I2 (- 16384)))
      )
      (inv_main114 L1
             C2
             C1
             P1
             T1
             H
             R
             L2
             U1
             T
             Q
             E
             R1
             K1
             I1
             D
             K2
             D1
             G
             J1
             F2
             A
             B
             N2
             B1
             Z1
             F
             F1
             I
             K
             S
             V1
             N
             X
             L
             O1
             Y
             D2
             A1
             A2
             J
             W1
             E2
             B2
             X1
             I2
             P
             C
             J2
             U
             W
             M
             Q1
             G1
             G2
             S1
             H2
             M2
             N1
             E1
             Y1
             H1
             Z
             M1
             V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main193 R1
             G1
             B2
             Z1
             W
             L2
             G2
             J
             M
             L
             E1
             P
             C1
             O1
             F1
             O
             C2
             R
             K2
             E2
             E
             F
             W1
             J1
             V1
             A1
             L1
             I2
             F2
             C
             G
             K1
             Q
             Y1
             M2
             N
             A2
             T
             V
             X
             D
             Y
             N2
             N1
             I
             A
             X1
             P1
             D1
             M1
             Z
             I1
             B
             B1
             S1
             Q1
             H1
             U
             U1
             J2
             K
             H
             D2
             S
             H2)
        (and (= T1 0) (<= 0 A2) (<= 0 Q1) (<= 0 N) (not (= I2 0)))
      )
      (inv_main114 R1
             G1
             B2
             Z1
             W
             L2
             G2
             J
             M
             L
             E1
             P
             C1
             O1
             F1
             O
             C2
             R
             K2
             E2
             E
             F
             W1
             J1
             V1
             A1
             L1
             I2
             F2
             C
             G
             K1
             Q
             Y1
             M2
             N
             A2
             T
             V
             X
             D
             Y
             T1
             N1
             I
             A
             X1
             P1
             D1
             M1
             Z
             I1
             B
             B1
             S1
             Q1
             H1
             U
             U1
             J2
             K
             H
             D2
             S
             H2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main193 B
             L1
             N1
             L2
             Q
             O
             C2
             A1
             W1
             Q1
             B2
             J2
             M1
             L
             G1
             J1
             Z
             G
             R1
             O1
             F
             S1
             R
             Y
             I
             Y1
             U1
             E
             X1
             S
             I2
             X
             H
             G2
             U
             V1
             P1
             E1
             K
             D
             C1
             A2
             A
             N2
             N
             D2
             H2
             W
             V
             Z1
             D1
             T
             K2
             E2
             K1
             C
             H1
             F2
             F1
             P
             M
             T1
             J
             M2
             B1)
        (and (= E 0) (not (= A 0)) (<= 0 V1) (<= 0 P1) (<= 0 C) (= I1 0))
      )
      (inv_main114 B
             L1
             N1
             L2
             Q
             O
             C2
             A1
             W1
             Q1
             B2
             J2
             M1
             L
             G1
             J1
             Z
             G
             R1
             O1
             F
             S1
             R
             Y
             I
             Y1
             U1
             E
             X1
             S
             I2
             X
             H
             G2
             U
             V1
             P1
             E1
             K
             D
             C1
             A2
             I1
             N2
             N
             D2
             H2
             W
             V
             Z1
             D1
             T
             K2
             E2
             K1
             C
             H1
             F2
             F1
             P
             M
             T1
             J
             M2
             B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main449 K
             T
             K2
             B2
             I
             U1
             D
             P1
             A
             L
             E
             Y1
             L1
             B1
             M
             D2
             X1
             V
             Q
             I1
             S1
             C1
             G
             A1
             C
             T1
             H1
             F
             Y
             X
             B
             I2
             F2
             U
             H2
             S
             E1
             J2
             C2
             O
             E2
             Z1
             O1
             A2
             W1
             N
             J
             G2
             V1
             M1
             H
             K1
             R
             N2
             G1
             L2
             D1
             F1
             J1
             M2
             P
             R1
             W
             Z
             Q1)
        (and (= N1 0) (<= 0 L2) (<= 0 E1) (<= 0 S) (= C2 0))
      )
      (inv_main114 K
             T
             K2
             B2
             I
             U1
             D
             P1
             A
             L
             E
             Y1
             L1
             B1
             M
             D2
             X1
             V
             Q
             I1
             S1
             C1
             G
             A1
             C
             T1
             H1
             F
             Y
             X
             B
             I2
             F2
             U
             H2
             S
             E1
             J2
             C2
             O
             E2
             Z1
             N1
             A2
             W1
             N
             J
             G2
             V1
             M1
             H
             K1
             R
             N2
             G1
             L2
             D1
             F1
             J1
             M2
             P
             R1
             W
             Z
             Q1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main449 D
             E
             W1
             R
             L1
             X1
             U
             Z
             M
             H1
             A1
             P1
             M2
             F1
             P
             J
             A2
             S1
             K2
             N1
             B
             D2
             G2
             W
             H
             T
             F2
             J1
             L
             C2
             M1
             E1
             B1
             N
             K
             G
             X
             J2
             T1
             L2
             Y1
             U1
             V1
             C
             I2
             S
             K1
             Q1
             V
             C1
             A
             G1
             H2
             I1
             Z1
             B2
             O1
             F
             Q
             I
             N2
             E2
             O
             Y
             D1)
        (and (= R1 0) (= L1 U1) (<= 0 B2) (<= 0 X) (<= 0 G) (not (= T1 0)))
      )
      (inv_main114 D
             E
             W1
             R
             L1
             X1
             U
             Z
             M
             H1
             A1
             P1
             M2
             F1
             P
             J
             A2
             S1
             K2
             N1
             B
             D2
             G2
             W
             H
             T
             F2
             J1
             L
             C2
             M1
             E1
             B1
             N
             K
             G
             X
             J2
             T1
             L2
             Y1
             U1
             R1
             C
             I2
             S
             K1
             Q1
             V
             C1
             A
             G1
             H2
             I1
             Z1
             B2
             O1
             F
             Q
             I
             N2
             E2
             O
             Y
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main449 X
             D2
             V1
             N
             L
             D1
             C2
             F2
             E2
             V
             G1
             F
             H
             P1
             C
             M2
             E1
             Y
             A1
             S1
             Z
             N1
             K
             B2
             R1
             W1
             X1
             I2
             E
             Y1
             J2
             N2
             G
             M1
             H2
             J
             I1
             O1
             A2
             S
             C1
             A
             J1
             B
             U
             Q
             W
             L1
             B1
             T
             K2
             I
             P
             H1
             Z1
             U1
             M
             K1
             O
             L2
             D
             G2
             R
             Q1
             F1)
        (and (= T1 0)
     (not (= L A))
     (<= 0 U1)
     (<= 0 I1)
     (<= 0 J)
     (not (= A2 0))
     (= v_66 L))
      )
      (inv_main114 X
             D2
             V1
             N
             L
             D1
             C2
             F2
             E2
             V
             G1
             F
             H
             P1
             C
             M2
             E1
             Y
             A1
             S1
             Z
             N1
             K
             B2
             R1
             W1
             X1
             I2
             E
             Y1
             J2
             N2
             G
             M1
             H2
             J
             I1
             O1
             A2
             S
             v_66
             A
             T1
             B
             U
             Q
             W
             L1
             B1
             T
             K2
             I
             P
             H1
             Z1
             U1
             M
             K1
             O
             L2
             D
             G2
             R
             Q1
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 Y
             H2
             E1
             W1
             G1
             I1
             I
             U
             M2
             C2
             S1
             N
             C
             E2
             G
             D1
             B
             B2
             J2
             P
             P1
             A1
             Z1
             F2
             X
             N1
             V1
             X1
             U1
             M1
             T1
             F
             J
             I2
             E
             M
             F1
             A2
             D2
             C1
             J1
             D
             K2
             O1
             H
             L1
             Q
             Z
             H1
             L2
             G2
             T
             Y1
             O
             R
             K
             R1
             L
             K1
             B1
             Q1
             S
             W
             V
             A)
        (and (= G1 4528)
     (not (= G1 4497))
     (not (= G1 4512))
     (not (= G1 12292))
     (not (= G1 16384))
     (not (= G1 4096))
     (not (= G1 20480))
     (not (= G1 4099))
     (not (= G1 4368))
     (not (= G1 4369))
     (not (= G1 4384))
     (not (= G1 4385))
     (not (= G1 4400))
     (not (= G1 4401))
     (not (= G1 4416))
     (not (= G1 4417))
     (not (= G1 4432))
     (not (= G1 4433))
     (not (= G1 4448))
     (not (= G1 4449))
     (not (= G1 4464))
     (not (= G1 4465))
     (not (= G1 4466))
     (not (= G1 4467))
     (not (= G1 4480))
     (not (= G1 4481))
     (not (= G1 4496))
     (<= 0 F1)
     (<= 0 M)
     (<= 0 K)
     (not (= G1 4513))
     (= v_65 G1))
      )
      (inv_main377 Y
             H2
             E1
             W1
             G1
             I1
             I
             U
             M2
             C2
             S1
             N
             C
             E2
             G
             D1
             B
             B2
             J2
             P
             P1
             A1
             Z1
             F2
             X
             N1
             V1
             X1
             U1
             M1
             T1
             F
             J
             I2
             E
             M
             F1
             A2
             D2
             C1
             J1
             v_65
             K2
             O1
             H
             L1
             Q
             Z
             H1
             L2
             G2
             T
             Y1
             O
             R
             K
             R1
             L
             K1
             B1
             Q1
             S
             W
             V
             A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 L
             F1
             E
             A2
             H
             K
             B2
             B1
             T1
             M
             K2
             H2
             O1
             F2
             Y1
             X
             D
             G
             A
             S1
             E2
             L1
             J2
             R1
             C
             Z
             I
             R
             U1
             I1
             U
             X1
             M2
             W1
             J
             O
             G1
             E1
             J1
             Y
             A1
             N1
             G2
             T
             D2
             Z1
             D1
             F
             V1
             S
             I2
             M1
             C1
             Q1
             H1
             P
             P1
             B
             K1
             Q
             L2
             W
             C2
             N
             V)
        (and (not (= H 4528))
     (= H 4529)
     (not (= H 4497))
     (not (= H 4512))
     (not (= H 12292))
     (not (= H 16384))
     (not (= H 4096))
     (not (= H 20480))
     (not (= H 4099))
     (not (= H 4368))
     (not (= H 4369))
     (not (= H 4384))
     (not (= H 4385))
     (not (= H 4400))
     (not (= H 4401))
     (not (= H 4416))
     (not (= H 4417))
     (not (= H 4432))
     (not (= H 4433))
     (not (= H 4448))
     (not (= H 4449))
     (not (= H 4464))
     (not (= H 4465))
     (not (= H 4466))
     (not (= H 4467))
     (not (= H 4480))
     (not (= H 4481))
     (not (= H 4496))
     (<= 0 G1)
     (<= 0 P)
     (<= 0 O)
     (not (= H 4513))
     (= v_65 H))
      )
      (inv_main377 L
             F1
             E
             A2
             H
             K
             B2
             B1
             T1
             M
             K2
             H2
             O1
             F2
             Y1
             X
             D
             G
             A
             S1
             E2
             L1
             J2
             R1
             C
             Z
             I
             R
             U1
             I1
             U
             X1
             M2
             W1
             J
             O
             G1
             E1
             J1
             Y
             A1
             v_65
             G2
             T
             D2
             Z1
             D1
             F
             V1
             S
             I2
             M1
             C1
             Q1
             H1
             P
             P1
             B
             K1
             Q
             L2
             W
             C2
             N
             V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main114 I
             G1
             R1
             K1
             X1
             N1
             S1
             K
             T
             F
             M1
             G
             W
             V
             L2
             E2
             F1
             Q1
             L1
             A2
             D2
             U1
             Z
             K2
             E
             I2
             C2
             A1
             J1
             E1
             P1
             I1
             A
             H2
             R
             H
             L
             D
             B
             Q
             O1
             O
             B2
             T1
             Y
             N2
             J2
             W1
             P
             Z1
             M
             C
             O2
             P2
             S
             J
             D1
             G2
             Y1
             C1
             U
             M2
             N
             F2
             H1)
        (and (not (= X1 16384))
     (not (= X1 4096))
     (not (= X1 20480))
     (not (= X1 4099))
     (= X1 4368)
     (= V1 1)
     (= B1 0)
     (= P2 0)
     (<= 0 L)
     (<= 0 J)
     (<= 0 H)
     (not (= X1 12292))
     (= v_68 X1))
      )
      (inv_main239 I
             G1
             R1
             K1
             X1
             N1
             S1
             K
             T
             F
             M1
             G
             W
             V
             L2
             E2
             B1
             Q1
             L1
             A2
             D2
             U1
             Z
             K2
             E
             I2
             C2
             A1
             J1
             E1
             P1
             I1
             A
             H2
             R
             H
             L
             D
             B
             X
             O1
             v_68
             B2
             T1
             Y
             N2
             J2
             W1
             P
             Z1
             M
             C
             O2
             V1
             S
             J
             D1
             G2
             Y1
             C1
             U
             M2
             N
             F2
             H1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main114 K2
             F1
             A
             M
             C
             M1
             F
             B1
             X
             P1
             H2
             I2
             V1
             I1
             N
             A2
             K1
             E2
             C1
             U1
             R1
             E
             E1
             B2
             P
             S
             J2
             G1
             J1
             D1
             Y1
             Q
             W1
             G
             B
             L
             W
             K
             Z
             N1
             J
             X1
             V
             G2
             H1
             N2
             Y
             O2
             Z1
             S1
             I
             L2
             L1
             D
             U
             Q1
             D2
             H
             C2
             M2
             T
             O1
             R
             T1
             A1)
        (and (not (= D 0))
     (not (= C 12292))
     (not (= C 16384))
     (not (= C 4096))
     (not (= C 20480))
     (not (= C 4099))
     (= C 4368)
     (<= 0 Q1)
     (<= 0 W)
     (<= 0 L)
     (= O 0)
     (= v_67 C))
      )
      (inv_main239 K2
             F1
             A
             M
             C
             M1
             F
             B1
             X
             P1
             H2
             I2
             V1
             I1
             N
             A2
             O
             E2
             C1
             U1
             R1
             E
             E1
             B2
             P
             S
             J2
             G1
             J1
             D1
             Y1
             Q
             W1
             G
             B
             L
             W
             K
             Z
             F2
             J
             v_67
             V
             G2
             H1
             N2
             Y
             O2
             Z1
             S1
             I
             L2
             L1
             D
             U
             Q1
             D2
             H
             C2
             M2
             T
             O1
             R
             T1
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main114 Q
             R
             H1
             D
             B1
             V1
             F1
             U1
             P1
             J
             G
             K1
             L1
             X
             H
             N
             O2
             M
             A1
             S
             S1
             B2
             C
             Z
             J2
             V
             E
             K2
             O1
             W1
             E2
             T1
             A2
             U
             P
             Y1
             R1
             N2
             Y
             D1
             F
             B
             L
             L2
             E1
             I
             T
             G1
             F2
             X1
             I2
             M1
             O
             K
             I1
             H2
             D2
             Z1
             A
             W
             M2
             P2
             G2
             C1
             C2)
        (and (= N1 0)
     (not (= B1 12292))
     (not (= B1 16384))
     (not (= B1 4096))
     (not (= B1 20480))
     (not (= B1 4099))
     (not (= B1 4368))
     (= B1 4369)
     (= K 0)
     (<= 0 H2)
     (<= 0 Y1)
     (<= 0 R1)
     (= Q1 1)
     (= v_68 B1))
      )
      (inv_main239 Q
             R
             H1
             D
             B1
             V1
             F1
             U1
             P1
             J
             G
             K1
             L1
             X
             H
             N
             N1
             M
             A1
             S
             S1
             B2
             C
             Z
             J2
             V
             E
             K2
             O1
             W1
             E2
             T1
             A2
             U
             P
             Y1
             R1
             N2
             Y
             J1
             F
             v_68
             L
             L2
             E1
             I
             T
             G1
             F2
             X1
             I2
             M1
             O
             Q1
             I1
             H2
             D2
             Z1
             A
             W
             M2
             P2
             G2
             C1
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main114 Y
             D1
             Q
             I1
             O1
             S1
             P
             O2
             D2
             G1
             H
             R1
             W1
             U1
             L2
             Z
             H2
             M1
             L1
             U
             G
             N
             E
             B1
             A1
             H1
             C1
             L
             N1
             C2
             O
             Q1
             M2
             J2
             K1
             G2
             D
             F
             S
             A
             B2
             X1
             R
             W
             X
             C
             N2
             I2
             K2
             Y1
             E2
             Z1
             P1
             F1
             E1
             F2
             V
             B
             A2
             K
             J
             T1
             M
             V1
             T)
        (and (not (= O1 16384))
     (not (= O1 4096))
     (not (= O1 20480))
     (not (= O1 4099))
     (not (= O1 4368))
     (= O1 4369)
     (not (= F1 0))
     (= I 0)
     (<= 0 G2)
     (<= 0 F2)
     (<= 0 D)
     (not (= O1 12292))
     (= v_67 O1))
      )
      (inv_main239 Y
             D1
             Q
             I1
             O1
             S1
             P
             O2
             D2
             G1
             H
             R1
             W1
             U1
             L2
             Z
             I
             M1
             L1
             U
             G
             N
             E
             B1
             A1
             H1
             C1
             L
             N1
             C2
             O
             Q1
             M2
             J2
             K1
             G2
             D
             F
             S
             J1
             B2
             v_67
             R
             W
             X
             C
             N2
             I2
             K2
             Y1
             E2
             Z1
             P1
             F1
             E1
             F2
             V
             B
             A2
             K
             J
             T1
             M
             V1
             T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main114 D1
             N
             H1
             K1
             M1
             X1
             E2
             G2
             R
             M
             I1
             B1
             U1
             I2
             W1
             B
             V1
             J
             A
             I
             J2
             H2
             H
             W
             G
             Q1
             K
             C2
             G1
             K2
             A2
             E
             B2
             L
             Z1
             Y
             D
             T
             L1
             Q
             C
             M2
             N2
             Y1
             J1
             V
             U
             E1
             O1
             S
             T1
             R1
             X
             N1
             P1
             L2
             F
             O
             F2
             Z
             A1
             P
             S1
             F1
             C1)
        (and (not (= M1 12292))
     (not (= M1 16384))
     (not (= M1 4096))
     (not (= M1 20480))
     (not (= M1 4099))
     (not (= M1 4368))
     (not (= M1 4369))
     (not (= M1 4384))
     (not (= M1 4385))
     (not (= M1 4400))
     (not (= M1 4401))
     (not (= M1 4416))
     (not (= M1 4417))
     (= M1 4432)
     (<= 0 L2)
     (<= 0 Y)
     (<= 0 D)
     (= N1 5)
     (= v_66 M1))
      )
      (inv_main466 D1
             N
             H1
             K1
             M1
             X1
             E2
             G2
             R
             M
             I1
             B1
             U1
             I2
             W1
             B
             V1
             J
             A
             I
             J2
             H2
             H
             W
             G
             Q1
             K
             C2
             G1
             K2
             A2
             E
             B2
             L
             Z1
             Y
             D
             T
             L1
             D2
             C
             v_66
             N2
             Y1
             J1
             V
             U
             E1
             O1
             S
             T1
             R1
             X
             N1
             P1
             L2
             F
             O
             F2
             Z
             A1
             P
             S1
             F1
             C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main114 K
             G1
             R
             E2
             W
             E1
             G2
             D1
             Y1
             I2
             L1
             M2
             P1
             T1
             J1
             D
             F1
             O1
             H
             Q
             A1
             U
             V
             N
             O
             T
             D2
             L
             A
             W1
             C1
             R1
             C2
             J
             V1
             Y
             S
             I1
             M1
             U1
             S1
             F2
             N1
             I
             P
             B1
             X
             B2
             H2
             K2
             X1
             Z
             F
             M
             K1
             B
             L2
             Z1
             Q1
             E
             N2
             G
             C
             H1
             A2)
        (and (not (= W 16384))
     (not (= W 4096))
     (not (= W 20480))
     (not (= W 4099))
     (not (= W 4368))
     (not (= W 4369))
     (not (= W 4384))
     (not (= W 4385))
     (not (= W 4400))
     (not (= W 4401))
     (not (= W 4416))
     (not (= W 4417))
     (not (= W 4432))
     (= W 4433)
     (= M 5)
     (<= 0 Y)
     (<= 0 S)
     (<= 0 B)
     (not (= W 12292))
     (= v_66 W))
      )
      (inv_main466 K
             G1
             R
             E2
             W
             E1
             G2
             D1
             Y1
             I2
             L1
             M2
             P1
             T1
             J1
             D
             F1
             O1
             H
             Q
             A1
             U
             V
             N
             O
             T
             D2
             L
             A
             W1
             C1
             R1
             C2
             J
             V1
             Y
             S
             I1
             M1
             J2
             S1
             v_66
             N1
             I
             P
             B1
             X
             B2
             H2
             K2
             X1
             Z
             F
             M
             K1
             B
             L2
             Z1
             Q1
             E
             N2
             G
             C
             H1
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main466 W1
             C
             C2
             N1
             E
             A
             C1
             O1
             P1
             K1
             D1
             L2
             G1
             U
             J2
             G
             N
             Z
             O
             F2
             V
             W
             T
             U1
             Y1
             V1
             B
             M
             J1
             Q1
             Y
             I
             L
             M1
             H2
             A2
             R1
             F1
             H1
             Z1
             D
             K2
             I1
             F
             J
             E1
             S
             I2
             T1
             B1
             X
             K
             H
             G2
             L1
             E2
             Q
             D2
             A1
             B2
             M2
             X1
             P
             R
             S1)
        (and (<= 0 A2) (<= 0 R1) (<= 0 E2))
      )
      false
    )
  )
)

(check-sat)
(exit)
