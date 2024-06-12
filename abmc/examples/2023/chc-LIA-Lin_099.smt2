; ./prepared/tricera/sv-comp-2020/./mixed/s3_clnt_2.cil-1.c-1_000.smt2
(set-logic HORN)


(declare-fun |inv_main377| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main108| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main239| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main466| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main3| ( Int ) Bool)
(declare-fun |inv_main256| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main193| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main267| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main114| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main199| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main235| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
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
        (inv_main114 R
             X1
             M
             P2
             Y1
             C2
             K
             P1
             A
             B1
             C1
             L
             S1
             B
             T
             Q1
             X
             E2
             G1
             I
             W
             J2
             N
             F
             D
             G
             F2
             K1
             Y
             K2
             V1
             A1
             B2
             V
             P
             N2
             U1
             J1
             O
             H
             N1
             I2
             L2
             O1
             M2
             W1
             Z
             Z1
             M1
             E
             D2
             S
             O2
             D1
             T1
             Q2
             H1
             U
             G2
             E1
             I1
             H2
             L1
             A2
             R1)
        (and (not (= Y1 16384))
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
     (= Y1 4496)
     (= Q 0)
     (= J 0)
     (= C 4512)
     (<= 0 N2)
     (<= 0 U1)
     (<= 0 Q2)
     (not (<= F1 0))
     (not (= Y1 12292)))
      )
      (inv_main193 R
             X1
             M
             P2
             C
             C2
             K
             P1
             A
             J
             C1
             L
             S1
             B
             T
             Q1
             X
             E2
             G1
             I
             W
             J2
             Q
             F
             D
             G
             F2
             K1
             Y
             K2
             V1
             A1
             B2
             V
             P
             N2
             U1
             J1
             O
             F1
             N1
             Y1
             L2
             O1
             M2
             W1
             Z
             Z1
             M1
             E
             D2
             S
             O2
             D1
             T1
             Q2
             H1
             U
             G2
             E1
             I1
             H2
             L1
             A2
             R1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) ) 
    (=>
      (and
        (inv_main114 I2
             V1
             L1
             Y
             S
             H2
             X1
             D2
             B
             I1
             O
             U
             Y1
             K
             C2
             E2
             J
             C
             A
             Q2
             J1
             X
             E
             B2
             W1
             N
             A1
             R1
             A2
             E1
             U1
             T
             H1
             Q
             N1
             P
             M2
             G1
             P1
             F1
             V
             Z1
             P2
             Q1
             K1
             O2
             I
             H
             Z
             T1
             L2
             O1
             M1
             G2
             R
             D
             F
             F2
             L
             W
             K2
             S1
             B1
             D1
             N2)
        (and (= S 4497)
     (not (= S 12292))
     (not (= S 16384))
     (not (= S 4096))
     (not (= S 20480))
     (not (= S 4099))
     (not (= S 4368))
     (not (= S 4369))
     (not (= S 4384))
     (not (= S 4385))
     (not (= S 4400))
     (not (= S 4401))
     (not (= S 4416))
     (not (= S 4417))
     (not (= S 4432))
     (not (= S 4433))
     (not (= S 4448))
     (not (= S 4449))
     (not (= S 4464))
     (not (= S 4465))
     (not (= S 4466))
     (not (= S 4467))
     (not (= S 4480))
     (not (= S 4481))
     (not (= S 4496))
     (= M 4512)
     (= G 0)
     (<= 0 M2)
     (<= 0 P)
     (<= 0 D)
     (not (<= C1 0))
     (= J2 0))
      )
      (inv_main193 I2
             V1
             L1
             Y
             M
             H2
             X1
             D2
             B
             J2
             O
             U
             Y1
             K
             C2
             E2
             J
             C
             A
             Q2
             J1
             X
             G
             B2
             W1
             N
             A1
             R1
             A2
             E1
             U1
             T
             H1
             Q
             N1
             P
             M2
             G1
             P1
             C1
             V
             S
             P2
             Q1
             K1
             O2
             I
             H
             Z
             T1
             L2
             O1
             M1
             G2
             R
             D
             F
             F2
             L
             W
             K2
             S1
             B1
             D1
             N2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main239 S
             M
             B2
             I1
             K1
             Z1
             V
             R
             M1
             T
             L
             I
             J1
             I2
             L1
             X
             G1
             O2
             N2
             Q1
             Q
             F1
             H
             M2
             Z
             C1
             D1
             F
             F2
             J2
             P
             C
             G2
             U1
             O1
             J
             W1
             E
             D2
             H1
             H2
             O
             A2
             K2
             B
             E1
             E2
             R1
             A
             S1
             B1
             T1
             Y1
             G
             Y
             D
             P1
             C2
             V1
             N1
             W
             L2
             X1
             K
             U)
        (and (= N 4384)
     (not (= L I))
     (<= 0 W1)
     (<= 0 J)
     (<= 0 D)
     (not (<= H1 0))
     (= A1 0))
      )
      (inv_main193 S
             M
             B2
             I1
             N
             Z1
             V
             R
             M1
             A1
             L
             I
             J1
             I2
             L1
             X
             G1
             O2
             N2
             Q1
             Q
             F1
             H
             M2
             Z
             C1
             D1
             F
             F2
             J2
             P
             C
             G2
             U1
             O1
             J
             W1
             E
             D2
             H1
             H2
             O
             A2
             K2
             B
             E1
             E2
             R1
             A
             S1
             B1
             T1
             Y1
             G
             Y
             D
             P1
             C2
             V1
             N1
             W
             L2
             X1
             K
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main239 H
             H2
             D1
             H1
             V1
             R1
             F2
             C
             I
             I2
             G
             Y
             W1
             Q1
             P1
             X
             M2
             B1
             E
             K2
             J2
             U1
             E1
             W
             N1
             M
             K1
             Y1
             L
             M1
             V
             A1
             O1
             C2
             B2
             P
             G1
             A
             T1
             O
             F1
             J
             U
             I1
             L1
             B
             D
             T
             E2
             K
             A2
             Z1
             C1
             Q
             N
             L2
             D2
             R
             G2
             X1
             S1
             J1
             F
             N2
             S)
        (and (= G Y) (= O2 4384) (<= 0 L2) (<= 0 G1) (<= 0 P) (not (<= O 0)) (= Z 0))
      )
      (inv_main193 H
             H2
             D1
             H1
             O2
             R1
             F2
             C
             I
             Z
             G
             Y
             W1
             Q1
             P1
             X
             M2
             B1
             E
             K2
             J2
             U1
             E1
             W
             N1
             M
             K1
             Y1
             L
             M1
             V
             A1
             O1
             C2
             B2
             P
             G1
             A
             T1
             O
             F1
             J
             U
             I1
             L1
             B
             D
             T
             E2
             K
             A2
             Z1
             C1
             Q
             N
             L2
             D2
             R
             G2
             X1
             S1
             J1
             F
             N2
             S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main256 F
             G2
             U
             E
             Y
             I
             P1
             Z1
             C1
             Y1
             V1
             B1
             U1
             K2
             H
             R1
             G1
             V
             I1
             J2
             D2
             A
             E2
             B2
             T1
             N
             X1
             D1
             R
             O
             X
             J1
             T
             M1
             J
             S
             L1
             B
             F2
             M
             S1
             D
             A1
             F1
             H2
             G
             C2
             W1
             Z
             E1
             M2
             W
             P
             L
             L2
             H1
             Q
             Q1
             N2
             A2
             K
             N1
             C
             K1
             O1)
        (and (not (= U1 0))
     (= O2 4560)
     (<= 0 L1)
     (<= 0 H1)
     (<= 0 S)
     (not (<= M 0))
     (= I2 0))
      )
      (inv_main193 F
             G2
             U
             E
             O2
             I
             P1
             Z1
             C1
             I2
             V1
             B1
             U1
             K2
             H
             R1
             G1
             V
             I1
             J2
             D2
             A
             E2
             B2
             T1
             N
             X1
             D1
             R
             O
             X
             J1
             T
             M1
             J
             S
             L1
             B
             F2
             M
             S1
             D
             A1
             F1
             H2
             G
             C2
             W1
             Z
             E1
             M2
             W
             P
             L
             L2
             H1
             Q
             Q1
             N2
             A2
             K
             N1
             C
             K1
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main256 T1
             Y1
             I2
             Z1
             R1
             X
             K1
             M2
             K2
             K
             D1
             Y
             H2
             A
             J2
             O1
             T
             W1
             D2
             F
             I
             V
             S1
             G1
             B
             P1
             A1
             Z
             C2
             E2
             H
             J
             W
             N1
             B2
             G2
             O2
             B1
             P
             O
             F2
             E
             C
             U1
             F1
             H1
             N
             U
             Q1
             V1
             X1
             R
             E1
             A2
             L
             C1
             M1
             I1
             N2
             Q
             J1
             S
             M
             L1
             D)
        (and (= H2 0) (= G 4400) (<= 0 G2) (<= 0 C1) (<= 0 O2) (not (<= O 0)) (= L2 0))
      )
      (inv_main193 T1
             Y1
             I2
             Z1
             G
             X
             K1
             M2
             K2
             L2
             D1
             Y
             H2
             A
             J2
             O1
             T
             W1
             D2
             F
             I
             V
             S1
             G1
             B
             P1
             A1
             Z
             C2
             E2
             H
             J
             W
             N1
             B2
             G2
             O2
             B1
             P
             O
             F2
             E
             C
             U1
             F1
             H1
             N
             U
             Q1
             V1
             X1
             R
             E1
             A2
             L
             C1
             M1
             I1
             N2
             Q
             J1
             S
             M
             L1
             D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main267 X
             C2
             M1
             Z1
             I1
             I
             E1
             K2
             C
             V1
             D2
             J
             J2
             L2
             U1
             B2
             N1
             D1
             G
             S
             O2
             H2
             A1
             O
             B1
             T1
             T
             L1
             R1
             N
             S1
             J1
             O1
             Q
             Z
             G2
             A2
             F
             Y
             D
             M
             W
             K
             P
             N2
             V
             P2
             A
             H
             P1
             R
             C1
             L
             F2
             U
             M2
             K1
             X1
             H1
             W1
             E
             F1
             I2
             Q1
             G1)
        (and (= Y1 4416)
     (not (= N 256))
     (= B 1)
     (<= 0 M2)
     (<= 0 G2)
     (<= 0 A2)
     (= E2 0)
     (= v_68 N))
      )
      (inv_main193 X
             C2
             M1
             Z1
             Y1
             I
             E1
             K2
             C
             E2
             D2
             J
             J2
             L2
             U1
             B2
             N1
             D1
             G
             S
             O2
             H2
             A1
             O
             B1
             T1
             T
             L1
             R1
             N
             S1
             J1
             O1
             Q
             Z
             G2
             A2
             F
             Y
             D
             M
             W
             B
             P
             N2
             V
             P2
             A
             H
             P1
             R
             C1
             L
             F2
             U
             v_68
             K1
             X1
             H1
             W1
             E
             F1
             I2
             Q1
             G1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main267 N2
             O
             B1
             M2
             H2
             Y
             N
             T1
             J1
             T
             I2
             D
             U1
             K2
             G2
             A
             A2
             B
             O1
             Z
             Y1
             P2
             S1
             M
             G
             N1
             W1
             F
             J2
             A1
             C2
             M1
             R
             V1
             B2
             L2
             L
             Q1
             R1
             O2
             H
             K
             F2
             P1
             I
             E1
             H1
             G1
             P
             Z1
             E2
             S
             C
             V
             D2
             I1
             J
             K1
             F1
             E
             Q2
             L1
             W
             X1
             D1)
        (and (= X 0)
     (= V 2)
     (= U 3)
     (= Q 4416)
     (<= 0 L2)
     (<= 0 I1)
     (<= 0 L)
     (not (<= C1 0))
     (= A1 256)
     (= v_69 A1))
      )
      (inv_main193 N2
             O
             B1
             M2
             Q
             Y
             N
             T1
             J1
             X
             I2
             D
             U1
             K2
             G2
             A
             A2
             B
             O1
             Z
             Y1
             P2
             S1
             M
             G
             N1
             W1
             F
             J2
             A1
             C2
             M1
             R
             V1
             B2
             L2
             L
             Q1
             R1
             C1
             H
             K
             F2
             P1
             I
             E1
             H1
             G1
             P
             Z1
             E2
             S
             C
             U
             D2
             v_69
             J
             K1
             F1
             E
             Q2
             L1
             W
             X1
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main267 D
             E
             S1
             C1
             R1
             M2
             R
             Q
             L1
             F
             N2
             P1
             J1
             A2
             A1
             Y1
             I2
             M1
             P
             C2
             U
             H
             O2
             C
             W
             D1
             T
             L
             B1
             Q1
             B2
             I1
             O1
             T1
             K1
             X
             V
             F1
             G1
             Z
             E2
             Z1
             L2
             G
             U1
             X1
             H1
             B
             D2
             J2
             A
             H2
             J
             E1
             P2
             F2
             N1
             Y
             M
             W1
             K
             K2
             S
             V1
             G2)
        (and (not (= E1 2))
     (= O 0)
     (= I 4416)
     (<= 0 F2)
     (<= 0 X)
     (<= 0 V)
     (not (<= N 0))
     (= Q1 256)
     (= v_68 Q1))
      )
      (inv_main193 D
             E
             S1
             C1
             I
             M2
             R
             Q
             L1
             O
             N2
             P1
             J1
             A2
             A1
             Y1
             I2
             M1
             P
             C2
             U
             H
             O2
             C
             W
             D1
             T
             L
             B1
             Q1
             B2
             I1
             O1
             T1
             K1
             X
             V
             F1
             G1
             N
             E2
             Z1
             L2
             G
             U1
             X1
             H1
             B
             D2
             J2
             A
             H2
             J
             E1
             P2
             v_68
             N1
             Y
             M
             W1
             K
             K2
             S
             V1
             G2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main114 R
             C1
             N
             P1
             Z
             F2
             H
             B2
             S
             G2
             S1
             W
             F
             A
             U1
             M2
             Y1
             V
             G1
             Q1
             K
             A2
             D1
             J2
             H1
             I
             K1
             L
             C
             Z1
             E
             T1
             K2
             L1
             J1
             U
             Q
             O1
             F1
             L2
             A1
             W1
             E2
             I1
             H2
             P
             R1
             I2
             M
             J
             T
             M1
             X1
             E1
             D
             B
             V1
             O
             X
             G
             D2
             Y
             C2
             B1
             N1)
        (and (not (= Z 4528))
     (not (= Z 4529))
     (not (= Z 4561))
     (= Z 4352)
     (not (= Z 4560))
     (not (= Z 4497))
     (not (= Z 4512))
     (not (= Z 12292))
     (not (= Z 16384))
     (not (= Z 4096))
     (not (= Z 20480))
     (not (= Z 4099))
     (not (= Z 4368))
     (not (= Z 4369))
     (not (= Z 4384))
     (not (= Z 4385))
     (not (= Z 4400))
     (not (= Z 4401))
     (not (= Z 4416))
     (not (= Z 4417))
     (not (= Z 4432))
     (not (= Z 4433))
     (not (= Z 4448))
     (not (= Z 4449))
     (not (= Z 4464))
     (not (= Z 4465))
     (not (= Z 4466))
     (not (= Z 4467))
     (not (= Z 4480))
     (not (= Z 4481))
     (not (= Z 4496))
     (not (<= 1 O1))
     (<= 0 U)
     (<= 0 Q)
     (<= 0 B)
     (not (= Z 4513))
     (= v_65 E)
     (= v_66 O1))
      )
      (inv_main193 R
             C1
             N
             P1
             E
             F2
             H
             B2
             S
             G2
             S1
             W
             F
             A
             U1
             M2
             Y1
             V
             G1
             Q1
             K
             A2
             D1
             J2
             H1
             I
             K1
             L
             C
             Z1
             v_65
             T1
             K2
             L1
             J1
             U
             Q
             O1
             F1
             L2
             A1
             Z
             E2
             I1
             H2
             P
             R1
             I2
             M
             J
             T
             M1
             X1
             E1
             D
             B
             V1
             O
             X
             G
             D2
             v_66
             C2
             B1
             N1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main114 A1
             Y1
             P
             H
             L1
             U
             O
             I2
             E1
             L2
             E
             N1
             R1
             S
             W
             C2
             K
             G1
             V1
             E2
             F1
             T1
             G2
             A2
             T
             C
             O1
             M
             S1
             Y
             J
             H2
             K1
             F
             N
             I
             J2
             V
             W1
             X1
             G
             M1
             L
             I1
             Z
             Q
             C1
             Z1
             U1
             J1
             M2
             Q1
             R
             B1
             D
             D1
             F2
             D2
             A
             X
             P1
             N2
             B
             B2
             H1)
        (and (not (= L1 4513))
     (not (= L1 4528))
     (not (= L1 4529))
     (not (= L1 4561))
     (= L1 4352)
     (not (= L1 4560))
     (not (= L1 4497))
     (not (= L1 4512))
     (not (= L1 12292))
     (not (= L1 16384))
     (not (= L1 4096))
     (not (= L1 20480))
     (not (= L1 4099))
     (not (= L1 4368))
     (not (= L1 4369))
     (not (= L1 4384))
     (not (= L1 4385))
     (not (= L1 4400))
     (not (= L1 4401))
     (not (= L1 4416))
     (not (= L1 4417))
     (not (= L1 4432))
     (not (= L1 4433))
     (not (= L1 4448))
     (not (= L1 4449))
     (not (= L1 4464))
     (not (= L1 4465))
     (not (= L1 4466))
     (not (= L1 4467))
     (not (= L1 4480))
     (not (= L1 4481))
     (not (= L1 4496))
     (<= 1 V)
     (<= 0 J2)
     (<= 0 D1)
     (<= 0 I)
     (not (<= R 0))
     (= K2 1)
     (= v_66 J)
     (= v_67 R)
     (= v_68 R))
      )
      (inv_main193 A1
             Y1
             P
             H
             J
             U
             O
             I2
             E1
             L2
             E
             N1
             R1
             K2
             W
             C2
             K
             G1
             V1
             E2
             F1
             T1
             G2
             A2
             T
             C
             O1
             M
             S1
             Y
             v_66
             H2
             K1
             F
             N
             I
             J2
             R
             W1
             X1
             G
             L1
             L
             I1
             Z
             Q
             C1
             Z1
             U1
             J1
             M2
             Q1
             v_67
             B1
             D
             D1
             F2
             D2
             A
             X
             P1
             V
             v_68
             B2
             H1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) ) 
    (=>
      (and
        (inv_main377 I1
             S2
             A1
             I
             U
             B1
             K2
             A2
             R2
             D
             H
             K
             F2
             G1
             H1
             O
             J
             N1
             M1
             X1
             R1
             F
             B
             G2
             Q2
             Z
             I2
             E1
             B2
             K1
             F1
             W
             S
             C1
             G
             V1
             J1
             T1
             E2
             Q
             T
             R
             L2
             W1
             D1
             A
             J2
             E
             H2
             C2
             P2
             D2
             L1
             S1
             Q1
             X
             N2
             P
             V
             N
             Y1
             U1
             L
             Z1
             O2)
        (and (= P1 4560)
     (= O1 (+ 5 G2))
     (= Y 4352)
     (= M (+ 5 G2))
     (= C 0)
     (<= 0 V1)
     (<= 0 J1)
     (<= 0 X)
     (not (<= M2 0))
     (= F2 0))
      )
      (inv_main193 I1
             S2
             A1
             I
             Y
             B1
             K2
             A2
             R2
             C
             H
             K
             F2
             G1
             H1
             O
             J
             N1
             M1
             X1
             R1
             F
             B
             M
             Q2
             Z
             I2
             E1
             B2
             K1
             P1
             W
             S
             C1
             G
             V1
             J1
             T1
             E2
             M2
             T
             R
             L2
             W1
             D1
             A
             J2
             E
             H2
             C2
             P2
             D2
             L1
             S1
             Q1
             X
             G2
             O1
             V
             N
             Y1
             U1
             L
             Z1
             O2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) ) 
    (=>
      (and
        (inv_main377 E
             P1
             L1
             N
             K2
             D
             V
             I
             Z1
             T
             L2
             S2
             S
             Q
             H2
             P
             F2
             N1
             I2
             O2
             Y1
             M1
             O
             F
             M
             Z
             Q1
             X
             D1
             C1
             M2
             Y
             F1
             R2
             A
             T2
             N2
             C
             D2
             U
             T1
             O1
             J2
             U1
             A1
             P2
             E2
             K
             L
             G2
             H
             W1
             X1
             J
             V1
             E1
             C2
             K1
             R
             G1
             A2
             H1
             W
             J1
             B2)
        (and (= Q2 (+ 5 F))
     (= R1 3)
     (= I1 4352)
     (= B1 (+ 5 F))
     (not (= S 0))
     (= G (+ 5 F))
     (= F (- 3))
     (<= 0 N2)
     (<= 0 E1)
     (<= 0 T2)
     (not (<= S1 0))
     (= B 0))
      )
      (inv_main193 E
             P1
             L1
             N
             I1
             D
             V
             I
             Z1
             B
             L2
             S2
             S
             Q
             H2
             P
             F2
             N1
             I2
             O2
             Y1
             M1
             O
             Q2
             M
             Z
             Q1
             X
             D1
             C1
             R1
             Y
             F1
             R2
             A
             T2
             N2
             C
             D2
             S1
             T1
             O1
             J2
             U1
             A1
             P2
             E2
             K
             L
             G2
             H
             W1
             X1
             J
             V1
             E1
             F
             B1
             G
             G1
             A2
             H1
             W
             J1
             B2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) ) 
    (=>
      (and
        (inv_main377 Y
             D2
             L1
             N
             M1
             P1
             A
             H
             S2
             F2
             F
             Z1
             J
             E
             U2
             H1
             U
             W
             I
             S1
             O
             S
             R2
             O2
             M2
             E1
             O1
             I2
             H2
             N2
             D1
             B
             T2
             K
             G1
             T
             R1
             Q2
             K1
             A2
             G2
             V1
             Z
             C
             R
             L2
             X
             Q
             X1
             V
             Q1
             C1
             U1
             T1
             W1
             I1
             P
             J1
             D
             W2
             Y1
             A1
             M
             E2
             B2)
        (and (not (= O2 (- 3)))
     (= K2 3)
     (= J2 (+ 5 O2))
     (= C2 (+ 9 O2))
     (= N1 (+ 5 O2))
     (= F1 3)
     (= B1 0)
     (= L (+ 9 O2))
     (not (= J 0))
     (= G (+ 5 O2))
     (<= 0 R1)
     (<= 0 I1)
     (<= 0 T)
     (not (<= V2 0))
     (= P2 0))
      )
      (inv_main193 Y
             D2
             L1
             N
             K2
             P1
             A
             H
             S2
             B1
             F
             Z1
             J
             E
             U2
             H1
             U
             W
             I
             S1
             O
             S
             R2
             C2
             P2
             E1
             O1
             I2
             H2
             N2
             F1
             B
             T2
             K
             G1
             T
             R1
             Q2
             K1
             V2
             G2
             V1
             Z
             C
             R
             L2
             X
             Q
             X1
             V
             Q1
             C1
             U1
             T1
             W1
             I1
             O2
             G
             J2
             N1
             L
             A1
             M
             E2
             B2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 J2
             H1
             R1
             E
             B1
             D2
             B
             D1
             C1
             I
             F1
             P
             G2
             N1
             A1
             X
             B2
             F
             G1
             P1
             P2
             T1
             F2
             Q
             O2
             V1
             I1
             V
             H
             Y
             A2
             D
             C2
             C
             Q1
             T
             L
             K1
             W1
             R
             H2
             E1
             E2
             N2
             Z1
             K
             S
             O
             L1
             X1
             G
             U
             M
             O1
             S1
             I2
             W
             Z
             N
             Y1
             M1
             J
             M2
             K2
             J1)
        (and (not (= O1 4))
     (not (= B1 12292))
     (not (= B1 16384))
     (not (= B1 4096))
     (not (= B1 20480))
     (not (= B1 4099))
     (not (= B1 4368))
     (not (= B1 4369))
     (not (= B1 4384))
     (not (= B1 4385))
     (not (= B1 4400))
     (not (= B1 4401))
     (not (= B1 4416))
     (not (= B1 4417))
     (= B1 4432)
     (= A 4448)
     (<= 0 I2)
     (<= 0 T)
     (<= 0 L)
     (not (<= U1 0))
     (= L2 0))
      )
      (inv_main193 J2
             H1
             R1
             E
             A
             D2
             B
             D1
             C1
             L2
             F1
             P
             G2
             N1
             A1
             X
             B2
             F
             G1
             P1
             P2
             T1
             F2
             Q
             O2
             V1
             I1
             V
             H
             Y
             A2
             D
             C2
             C
             Q1
             T
             L
             K1
             W1
             U1
             H2
             B1
             E2
             N2
             Z1
             K
             S
             O
             L1
             X1
             G
             U
             M
             O1
             S1
             I2
             W
             Z
             N
             Y1
             M1
             J
             M2
             K2
             J1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 N
             L2
             H
             P1
             F1
             Q1
             A2
             H2
             E2
             Y
             B1
             K1
             L1
             C
             A1
             C2
             E
             R
             G2
             I2
             Z
             K2
             C1
             T1
             W1
             M2
             B2
             U1
             I
             J2
             I1
             P
             N1
             Z1
             X
             M
             G1
             D2
             D
             F2
             M1
             J
             H1
             O
             W
             V
             S
             E1
             F
             J1
             S1
             G
             B
             R1
             P2
             L
             K
             X1
             A
             O1
             Q
             N2
             U
             V1
             O2)
        (and (not (= R1 4))
     (not (= F1 12292))
     (not (= F1 16384))
     (not (= F1 4096))
     (not (= F1 20480))
     (not (= F1 4099))
     (not (= F1 4368))
     (not (= F1 4369))
     (not (= F1 4384))
     (not (= F1 4385))
     (not (= F1 4400))
     (not (= F1 4401))
     (not (= F1 4416))
     (not (= F1 4417))
     (not (= F1 4432))
     (= F1 4433)
     (= D1 4448)
     (<= 0 G1)
     (<= 0 M)
     (<= 0 L)
     (not (<= T 0))
     (= Y1 0))
      )
      (inv_main193 N
             L2
             H
             P1
             D1
             Q1
             A2
             H2
             E2
             Y1
             B1
             K1
             L1
             C
             A1
             C2
             E
             R
             G2
             I2
             Z
             K2
             C1
             T1
             W1
             M2
             B2
             U1
             I
             J2
             I1
             P
             N1
             Z1
             X
             M
             G1
             D2
             D
             T
             M1
             F1
             H1
             O
             W
             V
             S
             E1
             F
             J1
             S1
             G
             B
             R1
             P2
             L
             K
             X1
             A
             O1
             Q
             N2
             U
             V1
             O2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 J2
             F
             F1
             W1
             W
             E1
             Q1
             L
             X
             S1
             L1
             P1
             X1
             C
             Z
             T1
             Y1
             M
             K1
             V1
             L2
             K2
             O1
             I2
             Q
             B2
             U1
             I1
             D2
             B
             P2
             H1
             U
             R1
             J1
             K
             D1
             Y
             M1
             Z1
             H2
             P
             O2
             E
             A2
             H
             F2
             V
             N2
             G2
             G1
             C1
             C2
             A
             M2
             B1
             O
             J
             G
             S
             I
             N
             T
             A1
             D)
        (and (= N1 4464)
     (not (= W 12292))
     (not (= W 16384))
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
     (not (= W 4433))
     (= W 4448)
     (= R 0)
     (<= 0 D1)
     (<= 0 B1)
     (<= 0 K)
     (not (<= E2 0))
     (not (= B2 0)))
      )
      (inv_main193 J2
             F
             F1
             W1
             N1
             E1
             Q1
             L
             X
             R
             L1
             P1
             X1
             C
             Z
             T1
             Y1
             M
             K1
             V1
             L2
             K2
             O1
             I2
             Q
             B2
             U1
             I1
             D2
             B
             P2
             H1
             U
             R1
             J1
             K
             D1
             Y
             M1
             E2
             H2
             W
             O2
             E
             A2
             H
             F2
             V
             N2
             G2
             G1
             C1
             C2
             A
             M2
             B1
             O
             J
             G
             S
             I
             N
             T
             A1
             D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 U1
             T
             D
             L
             V
             W
             J1
             K
             I1
             Q
             P2
             S1
             J
             R
             K1
             E2
             I
             J2
             Z
             M2
             E1
             O1
             H
             Y1
             H2
             N2
             K2
             G2
             H1
             U
             B1
             V1
             D2
             D1
             C1
             P
             I2
             G1
             B2
             E
             F
             W1
             R1
             Q1
             M
             A1
             X1
             F1
             A
             L2
             F2
             C
             Z1
             A2
             O2
             P1
             N1
             M1
             N
             S
             Y
             O
             L1
             X
             C2)
        (and (= T1 0)
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
     (= V 4448)
     (= B 4480)
     (<= 0 I2)
     (<= 0 P1)
     (<= 0 P)
     (not (<= G 0))
     (= N2 0))
      )
      (inv_main193 U1
             T
             D
             L
             B
             W
             J1
             K
             I1
             T1
             P2
             S1
             J
             R
             K1
             E2
             I
             J2
             Z
             M2
             E1
             O1
             H
             Y1
             H2
             N2
             K2
             G2
             H1
             U
             B1
             V1
             D2
             D1
             C1
             P
             I2
             G1
             B2
             G
             F
             V
             R1
             Q1
             M
             A1
             X1
             F1
             A
             L2
             F2
             C
             Z1
             A2
             O2
             P1
             N1
             M1
             N
             S
             Y
             O
             L1
             X
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 G1
             C1
             T
             U
             E1
             K1
             L2
             E
             Z1
             P
             V1
             A
             F1
             K
             U1
             O
             K2
             C2
             G
             X1
             Q
             P1
             B1
             T1
             S
             B
             S1
             I
             V
             Z
             J
             N1
             E2
             L1
             I2
             M
             X
             M2
             B2
             H2
             G2
             C
             P2
             I1
             R1
             A2
             M1
             D
             J2
             W
             D1
             N
             H1
             D2
             H
             O1
             J1
             L
             O2
             A1
             W1
             Q1
             Y
             R
             F)
        (and (= F2 0)
     (not (= E1 12292))
     (not (= E1 16384))
     (not (= E1 4096))
     (not (= E1 20480))
     (not (= E1 4099))
     (not (= E1 4368))
     (not (= E1 4369))
     (not (= E1 4384))
     (not (= E1 4385))
     (not (= E1 4400))
     (not (= E1 4401))
     (not (= E1 4416))
     (not (= E1 4417))
     (not (= E1 4432))
     (not (= E1 4433))
     (not (= E1 4448))
     (= E1 4449)
     (not (= B 0))
     (<= 0 O1)
     (<= 0 X)
     (<= 0 M)
     (not (<= Y1 0))
     (= N2 4464))
      )
      (inv_main193 G1
             C1
             T
             U
             N2
             K1
             L2
             E
             Z1
             F2
             V1
             A
             F1
             K
             U1
             O
             K2
             C2
             G
             X1
             Q
             P1
             B1
             T1
             S
             B
             S1
             I
             V
             Z
             J
             N1
             E2
             L1
             I2
             M
             X
             M2
             B2
             Y1
             G2
             E1
             P2
             I1
             R1
             A2
             M1
             D
             J2
             W
             D1
             N
             H1
             D2
             H
             O1
             J1
             L
             O2
             A1
             W1
             Q1
             Y
             R
             F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 P
             T
             J1
             S1
             P2
             T1
             O
             D1
             K2
             P1
             A2
             E1
             N1
             Y1
             R
             V
             O2
             H2
             A
             H
             D2
             K
             C
             I2
             M1
             B1
             D
             W1
             Y
             E2
             Z
             O1
             B
             H1
             X1
             X
             F2
             G2
             M2
             M
             B2
             J2
             Q1
             N2
             V1
             N
             G1
             R1
             J
             Q
             G
             L1
             C1
             L
             L2
             W
             F1
             U
             Z1
             F
             K1
             A1
             C2
             E
             U1)
        (and (= S 0)
     (= I 4480)
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
     (= P2 4449)
     (<= 0 F2)
     (<= 0 X)
     (<= 0 W)
     (not (<= I1 0))
     (= B1 0))
      )
      (inv_main193 P
             T
             J1
             S1
             I
             T1
             O
             D1
             K2
             S
             A2
             E1
             N1
             Y1
             R
             V
             O2
             H2
             A
             H
             D2
             K
             C
             I2
             M1
             B1
             D
             W1
             Y
             E2
             Z
             O1
             B
             H1
             X1
             X
             F2
             G2
             M2
             I1
             B2
             P2
             Q1
             N2
             V1
             N
             G1
             R1
             J
             Q
             G
             L1
             C1
             L
             L2
             W
             F1
             U
             Z1
             F
             K1
             A1
             C2
             E
             U1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 E2
             L1
             U
             B2
             J2
             E1
             Y
             N
             I1
             R
             I2
             D2
             P2
             P
             Z1
             C2
             C1
             D
             P1
             O2
             G2
             S
             B1
             F
             L2
             A1
             Z
             X
             Y1
             O1
             O
             X1
             H
             J
             K
             J1
             T1
             M1
             C
             M
             I
             Q1
             K2
             S1
             E
             W1
             R1
             A
             B
             H2
             Q
             M2
             W
             H1
             A2
             D1
             K1
             V1
             U1
             V
             N2
             F2
             L
             N1
             T)
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
     (= J2 4467)
     (= G1 0)
     (= F1 4480)
     (<= 0 T1)
     (<= 0 J1)
     (<= 0 D1)
     (not (<= G 0))
     (not (= J2 12292)))
      )
      (inv_main193 E2
             L1
             U
             B2
             F1
             E1
             Y
             N
             I1
             G1
             I2
             D2
             P2
             P
             Z1
             C2
             C1
             D
             P1
             O2
             G2
             S
             B1
             F
             L2
             A1
             Z
             X
             Y1
             O1
             O
             X1
             H
             J
             K
             J1
             T1
             M1
             C
             G
             I
             J2
             K2
             S1
             E
             W1
             R1
             A
             B
             H2
             Q
             M2
             W
             H1
             A2
             D1
             K1
             V1
             U1
             V
             N2
             F2
             L
             N1
             T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 V1
             I
             J
             B
             G
             I2
             S
             N2
             K
             P1
             T1
             E1
             L1
             N1
             A
             J2
             V
             M
             N
             O
             E
             M2
             U
             A1
             I1
             D1
             U1
             A2
             D
             L2
             T
             F
             R
             X
             D2
             S1
             Z
             K2
             F1
             E2
             Z1
             G2
             H2
             C2
             B1
             Q1
             W
             Y
             L
             W1
             Y1
             J1
             Q
             F2
             H
             K1
             P
             G1
             B2
             H1
             O1
             P2
             X1
             C1
             O2)
        (and (not (= G 12292))
     (not (= G 16384))
     (not (= G 4096))
     (not (= G 20480))
     (not (= G 4099))
     (not (= G 4368))
     (not (= G 4369))
     (not (= G 4384))
     (not (= G 4385))
     (not (= G 4400))
     (not (= G 4401))
     (not (= G 4416))
     (not (= G 4417))
     (not (= G 4432))
     (not (= G 4433))
     (not (= G 4448))
     (not (= G 4449))
     (not (= G 4464))
     (not (= G 4465))
     (= G 4466)
     (= C 0)
     (<= 0 S1)
     (<= 0 K1)
     (<= 0 Z)
     (not (<= M1 0))
     (= R1 4480))
      )
      (inv_main193 V1
             I
             J
             B
             R1
             I2
             S
             N2
             K
             C
             T1
             E1
             L1
             N1
             A
             J2
             V
             M
             N
             O
             E
             M2
             U
             A1
             I1
             D1
             U1
             A2
             D
             L2
             T
             F
             R
             X
             D2
             S1
             Z
             K2
             F1
             M1
             Z1
             G
             H2
             C2
             B1
             Q1
             W
             Y
             L
             W1
             Y1
             J1
             Q
             F2
             H
             K1
             P
             G1
             B2
             H1
             O1
             P2
             X1
             C1
             O2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 K2
             U
             I
             V
             N
             D2
             D
             U1
             Z1
             T1
             Q
             X
             W1
             F1
             L1
             D1
             Y
             V1
             M1
             S1
             G2
             J1
             P1
             R1
             Q1
             B2
             H
             O
             K1
             I2
             G1
             S
             R
             E
             A2
             G
             P
             L2
             A
             Y1
             N2
             J2
             C2
             B1
             Z
             O1
             M2
             C
             X1
             N1
             I1
             F2
             E2
             P2
             J
             A1
             O2
             M
             F
             B
             E1
             T
             L
             C1
             H1)
        (and (= W 4480)
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
     (not (= N 4433))
     (not (= N 4448))
     (not (= N 4449))
     (= N 4464)
     (<= 0 A1)
     (<= 0 P)
     (<= 0 G)
     (not (<= K 0))
     (= H2 0))
      )
      (inv_main193 K2
             U
             I
             V
             W
             D2
             D
             U1
             Z1
             H2
             Q
             X
             W1
             F1
             L1
             D1
             Y
             V1
             M1
             S1
             G2
             J1
             P1
             R1
             Q1
             B2
             H
             O
             K1
             I2
             G1
             S
             R
             E
             A2
             G
             P
             L2
             A
             K
             N2
             N
             C2
             B1
             Z
             O1
             M2
             C
             X1
             N1
             I1
             F2
             E2
             P2
             J
             A1
             O2
             M
             F
             B
             E1
             T
             L
             C1
             H1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 C
             T
             F
             N2
             V
             G2
             L1
             D
             Q1
             X1
             W
             I1
             O2
             E
             S
             K
             H
             R
             I2
             F1
             M2
             C1
             Q
             H2
             J2
             Y
             P
             G
             P1
             U1
             J
             K2
             T1
             D2
             N1
             Z1
             P2
             Y1
             M
             O
             N
             K1
             E2
             A1
             Z
             S1
             M1
             H1
             C2
             D1
             F2
             E1
             W1
             B
             O1
             B1
             I
             B2
             V1
             U
             A
             J1
             A2
             L2
             L)
        (and (= G1 4480)
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
     (= V 4465)
     (<= 0 Z1)
     (<= 0 B1)
     (<= 0 P2)
     (not (<= X 0))
     (= R1 0))
      )
      (inv_main193 C
             T
             F
             N2
             G1
             G2
             L1
             D
             Q1
             R1
             W
             I1
             O2
             E
             S
             K
             H
             R
             I2
             F1
             M2
             C1
             Q
             H2
             J2
             Y
             P
             G
             P1
             U1
             J
             K2
             T1
             D2
             N1
             Z1
             P2
             Y1
             M
             X
             N
             V
             E2
             A1
             Z
             S1
             M1
             H1
             C2
             D1
             F2
             E1
             W1
             B
             O1
             B1
             I
             B2
             V1
             U
             A
             J1
             A2
             L2
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main114 J1
             C2
             U1
             O
             I1
             P2
             V
             L
             R
             J
             K2
             U
             I
             W1
             T1
             A1
             Z1
             Q1
             H
             S1
             D1
             R1
             M1
             F2
             N2
             V1
             J2
             Z
             C1
             E2
             O2
             B2
             W
             G
             K1
             M2
             D
             E
             L2
             D2
             X
             O1
             F
             B
             C
             E1
             Q
             H2
             H1
             S
             N
             F1
             P
             M
             Y1
             N1
             Y
             X1
             A2
             B1
             K
             P1
             T
             L1
             G1)
        (and (= G2 4496)
     (= V1 1)
     (not (= I1 12292))
     (not (= I1 16384))
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
     (not (= I1 4448))
     (not (= I1 4449))
     (not (= I1 4464))
     (not (= I1 4465))
     (not (= I1 4466))
     (not (= I1 4467))
     (= I1 4480)
     (<= 0 M2)
     (<= 0 N1)
     (<= 0 D)
     (not (<= A 0))
     (= I2 0)
     (= v_68 E2))
      )
      (inv_main193 J1
             C2
             U1
             O
             G2
             P2
             V
             L
             R
             I2
             K2
             U
             I
             W1
             T1
             A1
             Z1
             Q1
             H
             S1
             D1
             R1
             M1
             F2
             N2
             V1
             J2
             Z
             C1
             E2
             O2
             B2
             W
             G
             K1
             M2
             v_68
             E
             L2
             A
             X
             I1
             F
             B
             C
             E1
             Q
             H2
             H1
             S
             N
             F1
             P
             M
             Y1
             N1
             Y
             X1
             A2
             B1
             K
             P1
             T
             L1
             G1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main114 B
             L
             E1
             A1
             K
             S
             G1
             H2
             L1
             L2
             K2
             C
             W1
             G2
             I
             B2
             J1
             M
             A
             N
             P
             S1
             J
             W
             H
             O
             Y1
             P2
             T
             N1
             Y
             V1
             X1
             C1
             U
             Z
             I2
             K1
             F1
             B1
             Q2
             J2
             P1
             D1
             F
             Z1
             U1
             E
             D2
             Q1
             V
             X
             A2
             O1
             N2
             E2
             H1
             D
             R
             T1
             Q
             F2
             M2
             R1
             C2)
        (and (= M1 0)
     (= I1 4512)
     (not (= O 1))
     (not (= K 12292))
     (not (= K 16384))
     (not (= K 4096))
     (not (= K 20480))
     (not (= K 4099))
     (not (= K 4368))
     (not (= K 4369))
     (not (= K 4384))
     (not (= K 4385))
     (not (= K 4400))
     (not (= K 4401))
     (not (= K 4416))
     (not (= K 4417))
     (not (= K 4432))
     (not (= K 4433))
     (not (= K 4448))
     (not (= K 4449))
     (not (= K 4464))
     (not (= K 4465))
     (not (= K 4466))
     (not (= K 4467))
     (= K 4480)
     (<= 0 I2)
     (<= 0 E2)
     (<= 0 Z)
     (not (<= G 0))
     (= O2 0)
     (= v_69 N1))
      )
      (inv_main193 B
             L
             E1
             A1
             I1
             S
             G1
             H2
             L1
             M1
             K2
             C
             W1
             G2
             I
             B2
             J1
             M
             A
             N
             P
             S1
             O2
             W
             H
             O
             Y1
             P2
             T
             N1
             Y
             V1
             X1
             C1
             U
             Z
             v_69
             K1
             F1
             G
             Q2
             K
             P1
             D1
             F
             Z1
             U1
             E
             D2
             Q1
             V
             X
             A2
             O1
             N2
             E2
             H1
             D
             R
             T1
             Q
             F2
             M2
             R1
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main114 F
             O1
             R
             A2
             E
             H2
             Y
             V1
             E2
             H1
             W1
             O2
             P1
             D1
             K1
             Q
             O
             J1
             F1
             B1
             S1
             X
             T
             Z1
             Y1
             N1
             A
             D
             M1
             C
             H
             X1
             G2
             K2
             E1
             N2
             M2
             V
             I2
             S
             B2
             M
             U1
             C2
             U
             L1
             J2
             J
             P
             P2
             K
             Z
             F2
             B
             L
             G
             R1
             A1
             D2
             Q1
             W
             T1
             I
             L2
             N)
        (and (= G1 4496)
     (= C1 0)
     (not (= E 12292))
     (not (= E 16384))
     (not (= E 4096))
     (not (= E 20480))
     (not (= E 4099))
     (not (= E 4368))
     (not (= E 4369))
     (not (= E 4384))
     (not (= E 4385))
     (not (= E 4400))
     (not (= E 4401))
     (not (= E 4416))
     (not (= E 4417))
     (not (= E 4432))
     (not (= E 4433))
     (not (= E 4448))
     (not (= E 4449))
     (not (= E 4464))
     (not (= E 4465))
     (not (= E 4466))
     (not (= E 4467))
     (not (= E 4480))
     (= E 4481)
     (<= 0 N2)
     (<= 0 M2)
     (<= 0 G)
     (not (<= I1 0))
     (= N1 1)
     (= v_68 C))
      )
      (inv_main193 F
             O1
             R
             A2
             G1
             H2
             Y
             V1
             E2
             C1
             W1
             O2
             P1
             D1
             K1
             Q
             O
             J1
             F1
             B1
             S1
             X
             T
             Z1
             Y1
             N1
             A
             D
             M1
             C
             H
             X1
             G2
             K2
             E1
             N2
             v_68
             V
             I2
             I1
             B2
             E
             U1
             C2
             U
             L1
             J2
             J
             P
             P2
             K
             Z
             F2
             B
             L
             G
             R1
             A1
             D2
             Q1
             W
             T1
             I
             L2
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main114 I
             S
             L2
             I1
             J2
             E2
             U1
             C2
             Y1
             O2
             Q1
             B
             K
             H1
             F2
             Y
             M1
             D
             W
             J1
             G1
             G2
             N
             D1
             T1
             R
             B2
             M2
             D2
             W1
             O1
             E1
             M
             F1
             I2
             A
             X1
             T
             H2
             X
             Z1
             A1
             L1
             G
             C1
             S1
             P
             N1
             L
             P2
             Z
             C
             Q
             U
             O
             K1
             N2
             P1
             F
             V1
             V
             E
             A2
             K2
             Q2)
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
     (= J2 4481)
     (= R1 4512)
     (= B1 0)
     (not (= R 1))
     (= H 0)
     (<= 0 X1)
     (<= 0 K1)
     (<= 0 A)
     (not (<= J 0))
     (not (= J2 12292))
     (= v_69 W1))
      )
      (inv_main193 I
             S
             L2
             I1
             R1
             E2
             U1
             C2
             Y1
             B1
             Q1
             B
             K
             H1
             F2
             Y
             M1
             D
             W
             J1
             G1
             G2
             H
             D1
             T1
             R
             B2
             M2
             D2
             W1
             O1
             E1
             M
             F1
             I2
             A
             v_69
             T
             H2
             J
             Z1
             J2
             L1
             G
             C1
             S1
             P
             N1
             L
             P2
             Z
             C
             Q
             U
             O
             K1
             N2
             P1
             F
             V1
             V
             E
             A2
             K2
             Q2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 S
             Z
             V1
             O2
             M1
             D2
             P1
             A1
             O
             H
             C2
             L
             Q
             E
             O1
             N1
             C1
             V
             N
             K
             B2
             F1
             D
             Z1
             Y1
             I1
             G1
             K2
             W
             U1
             Y
             M2
             P2
             R1
             J
             H2
             D1
             C
             A
             I2
             X
             J2
             L1
             G
             H1
             G2
             J1
             M
             E2
             S1
             X1
             P
             N2
             K1
             U
             R
             I
             F
             F2
             T1
             E1
             B
             W1
             L2
             T)
        (and (not (= M1 4513))
     (not (= M1 4528))
     (not (= M1 4529))
     (= M1 4560)
     (not (= M1 4497))
     (not (= M1 4512))
     (not (= M1 12292))
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
     (not (= M1 4432))
     (not (= M1 4433))
     (not (= M1 4448))
     (not (= M1 4449))
     (not (= M1 4464))
     (not (= M1 4465))
     (not (= M1 4466))
     (not (= M1 4467))
     (not (= M1 4480))
     (not (= M1 4481))
     (not (= M1 4496))
     (= B1 0)
     (not (= Q 0))
     (<= 0 H2)
     (<= 0 D1)
     (<= 0 R)
     (not (<= Q1 0))
     (= A2 4512))
      )
      (inv_main193 S
             Z
             V1
             O2
             A2
             D2
             P1
             A1
             O
             B1
             C2
             L
             Q
             E
             O1
             N1
             C1
             V
             N
             K
             B2
             F1
             D
             Z1
             Y1
             I1
             G1
             K2
             W
             U1
             Y
             M2
             P2
             R1
             J
             H2
             D1
             C
             A
             Q1
             X
             M1
             L1
             G
             H1
             G2
             J1
             M
             E2
             S1
             X1
             P
             N2
             K1
             U
             R
             I
             F
             F2
             T1
             E1
             B
             W1
             L2
             T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 U1
             F2
             D2
             R1
             B2
             Q1
             N
             H2
             P
             N2
             R
             G1
             E
             X1
             O2
             F
             G2
             V
             P2
             Z1
             W1
             I2
             X
             G
             D1
             J
             C
             K2
             V1
             W
             A2
             J1
             Y
             Q
             K
             M2
             U
             J2
             S1
             B
             M1
             A
             L2
             H
             P1
             C1
             E2
             M
             H1
             B1
             Z
             T
             L
             Y1
             K1
             N1
             I1
             E1
             T1
             O
             A1
             S
             I
             C2
             L1)
        (and (not (= B2 4528))
     (not (= B2 4529))
     (= B2 4560)
     (not (= B2 4497))
     (not (= B2 4512))
     (not (= B2 12292))
     (not (= B2 16384))
     (not (= B2 4096))
     (not (= B2 20480))
     (not (= B2 4099))
     (not (= B2 4368))
     (not (= B2 4369))
     (not (= B2 4384))
     (not (= B2 4385))
     (not (= B2 4400))
     (not (= B2 4401))
     (not (= B2 4416))
     (not (= B2 4417))
     (not (= B2 4432))
     (not (= B2 4433))
     (not (= B2 4448))
     (not (= B2 4449))
     (not (= B2 4464))
     (not (= B2 4465))
     (not (= B2 4466))
     (not (= B2 4467))
     (not (= B2 4480))
     (not (= B2 4481))
     (not (= B2 4496))
     (= F1 3)
     (= E 0)
     (= D 0)
     (<= 0 M2)
     (<= 0 N1)
     (<= 0 U)
     (not (<= O1 0))
     (not (= B2 4513)))
      )
      (inv_main193 U1
             F2
             D2
             R1
             F1
             Q1
             N
             H2
             P
             D
             R
             G1
             E
             X1
             O2
             F
             G2
             V
             P2
             Z1
             W1
             I2
             X
             G
             D1
             J
             C
             K2
             V1
             W
             A2
             J1
             Y
             Q
             K
             M2
             U
             J2
             S1
             O1
             M1
             B2
             L2
             H
             P1
             C1
             E2
             M
             H1
             B1
             Z
             T
             L
             Y1
             K1
             N1
             I1
             E1
             T1
             O
             A1
             S
             I
             C2
             L1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 H
             D1
             T
             G
             D
             T1
             J2
             A
             Q1
             P2
             J1
             E
             O
             E2
             B
             R
             K1
             W
             D2
             U1
             C1
             V
             S
             M1
             H2
             L2
             Z
             E1
             K
             O2
             I1
             B1
             S1
             G1
             O1
             Z1
             H1
             Q
             L1
             K2
             U
             I2
             N
             B2
             J
             G2
             V1
             N2
             A2
             F1
             F
             P1
             C2
             R1
             I
             W1
             Y1
             A1
             M2
             M
             F2
             Y
             X1
             N1
             L)
        (and (not (= O 0))
     (not (= D 4513))
     (not (= D 4528))
     (not (= D 4529))
     (= D 4561)
     (not (= D 4560))
     (not (= D 4497))
     (not (= D 4512))
     (not (= D 12292))
     (not (= D 16384))
     (not (= D 4096))
     (not (= D 20480))
     (not (= D 4099))
     (not (= D 4368))
     (not (= D 4369))
     (not (= D 4384))
     (not (= D 4385))
     (not (= D 4400))
     (not (= D 4401))
     (not (= D 4416))
     (not (= D 4417))
     (not (= D 4432))
     (not (= D 4433))
     (not (= D 4448))
     (not (= D 4449))
     (not (= D 4464))
     (not (= D 4465))
     (not (= D 4466))
     (not (= D 4467))
     (not (= D 4480))
     (not (= D 4481))
     (not (= D 4496))
     (= C 0)
     (<= 0 Z1)
     (<= 0 W1)
     (<= 0 H1)
     (not (<= P 0))
     (= X 4512))
      )
      (inv_main193 H
             D1
             T
             G
             X
             T1
             J2
             A
             Q1
             C
             J1
             E
             O
             E2
             B
             R
             K1
             W
             D2
             U1
             C1
             V
             S
             M1
             H2
             L2
             Z
             E1
             K
             O2
             I1
             B1
             S1
             G1
             O1
             Z1
             H1
             Q
             L1
             P
             U
             D
             N
             B2
             J
             G2
             V1
             N2
             A2
             F1
             F
             P1
             C2
             R1
             I
             W1
             Y1
             A1
             M2
             M
             F2
             Y
             X1
             N1
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 A1
             R1
             E1
             Z
             F
             K
             Q
             I
             O1
             H1
             A2
             I1
             K2
             C2
             N1
             T
             U1
             M2
             A
             W
             R
             Z1
             S
             C
             B2
             G
             H2
             M1
             P1
             P
             M
             G2
             P2
             I2
             O2
             T1
             Y1
             V
             D1
             B
             L
             Y
             J1
             E
             K1
             W1
             S1
             V1
             F1
             H
             F2
             D
             G1
             U
             O
             N2
             B1
             Q1
             D2
             E2
             X1
             N
             J
             L2
             X)
        (and (= J2 3)
     (= L1 0)
     (not (= F 4513))
     (not (= F 4528))
     (not (= F 4529))
     (= F 4561)
     (not (= F 4560))
     (not (= F 4497))
     (not (= F 4512))
     (not (= F 12292))
     (not (= F 16384))
     (not (= F 4096))
     (not (= F 20480))
     (not (= F 4099))
     (not (= F 4368))
     (not (= F 4369))
     (not (= F 4384))
     (not (= F 4385))
     (not (= F 4400))
     (not (= F 4401))
     (not (= F 4416))
     (not (= F 4417))
     (not (= F 4432))
     (not (= F 4433))
     (not (= F 4448))
     (not (= F 4449))
     (not (= F 4464))
     (not (= F 4465))
     (not (= F 4466))
     (not (= F 4467))
     (not (= F 4480))
     (not (= F 4481))
     (not (= F 4496))
     (<= 0 N2)
     (<= 0 Y1)
     (<= 0 T1)
     (not (<= C1 0))
     (= K2 0))
      )
      (inv_main193 A1
             R1
             E1
             Z
             J2
             K
             Q
             I
             O1
             L1
             A2
             I1
             K2
             C2
             N1
             T
             U1
             M2
             A
             W
             R
             Z1
             S
             C
             B2
             G
             H2
             M1
             P1
             P
             M
             G2
             P2
             I2
             O2
             T1
             Y1
             V
             D1
             C1
             L
             F
             J1
             E
             K1
             W1
             S1
             V1
             F1
             H
             F2
             D
             G1
             U
             O
             N2
             B1
             Q1
             D2
             E2
             X1
             N
             J
             L2
             X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) ) 
    (=>
      (and
        (inv_main199 Z
             N
             U
             M
             O1
             C2
             A1
             A2
             N1
             R1
             G
             E1
             X
             I2
             L
             W1
             O2
             T1
             S2
             H2
             P1
             Q1
             V1
             S1
             K1
             K
             H
             O
             Y1
             U1
             F
             M2
             F1
             V
             Q2
             N2
             C
             T
             S
             R
             Q
             P
             A
             I1
             C1
             Y
             P2
             G2
             W
             L2
             J1
             L1
             I
             R2
             M1
             J
             D
             F2
             J2
             D1
             K2
             E2
             E
             B
             X1)
        (and (= D2 0)
     (= B2 0)
     (= A2 66048)
     (= Z1 (+ (- 65280) A2))
     (= H1 4368)
     (= G1 (+ 1 H2))
     (= B1 4096)
     (not (= W 0))
     (not (= S 0))
     (not (= L 0))
     (<= 0 N2)
     (<= 0 J)
     (<= 0 C)
     (not (= G2 0)))
      )
      (inv_main193 Z
             N
             U
             M
             H1
             C2
             B2
             A2
             B1
             D2
             G
             E1
             X
             I2
             L
             W1
             O2
             T1
             S2
             G1
             P1
             Q1
             V1
             S1
             K1
             K
             H
             O
             Y1
             U1
             F
             M2
             F1
             V
             Q2
             N2
             C
             T
             S
             R
             Q
             P
             A
             I1
             C1
             Y
             P2
             G2
             W
             L2
             J1
             L1
             I
             R2
             Z1
             J
             D
             F2
             J2
             D1
             K2
             E2
             E
             B
             X1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (v_72 Int) ) 
    (=>
      (and
        (inv_main199 N
             Y
             N1
             I
             P1
             R1
             F1
             O2
             E2
             M
             B2
             V
             Z
             L2
             B
             H2
             N2
             I1
             R
             Q1
             G1
             U1
             C1
             C2
             U
             E1
             L1
             A2
             Y1
             M2
             B1
             J2
             D2
             X
             O
             S1
             R2
             E
             G
             H
             H1
             V1
             I2
             Q2
             S
             Z1
             S2
             D
             D1
             T2
             K2
             Q
             F
             M1
             P
             K1
             L
             J1
             X1
             T
             O1
             C
             W1
             K
             A1)
        (and (= B 0)
     (not (= S2 0))
     (= P2 0)
     (= O2 66048)
     (= G2 (+ 1 Q1))
     (= F2 0)
     (= T1 4096)
     (not (= D1 0))
     (= W 4368)
     (not (= J 0))
     (not (= G 0))
     (not (= D 0))
     (<= 0 R2)
     (<= 0 S1)
     (<= 0 K1)
     (= A (+ (- 65280) O2))
     (= v_72 J))
      )
      (inv_main193 N
             Y
             N1
             I
             W
             R1
             F2
             O2
             T1
             P2
             B2
             V
             Z
             L2
             J
             H2
             N2
             I1
             R
             G2
             G1
             U1
             C1
             C2
             U
             E1
             L1
             A2
             Y1
             M2
             B1
             J2
             D2
             X
             v_72
             S1
             R2
             E
             G
             H
             H1
             V1
             I2
             Q2
             S
             Z1
             S2
             D
             D1
             T2
             K2
             Q
             F
             M1
             A
             K1
             L
             J1
             X1
             T
             O1
             C
             W1
             K
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) ) 
    (=>
      (and
        (inv_main199 P1
             W1
             M1
             V1
             D2
             F1
             S1
             B
             J2
             N
             A1
             P2
             F
             Z1
             Q
             F2
             E1
             E
             B2
             D1
             C2
             G
             L
             A2
             C1
             S2
             M2
             C
             D
             T1
             N2
             K1
             Y1
             L2
             J1
             K
             S
             Y
             G1
             R1
             T
             M
             B1
             H
             I
             L1
             A
             X1
             X
             O1
             U1
             E2
             P
             Q1
             J
             H1
             W
             O2
             N1
             R
             I1
             K2
             Z
             R2
             I2)
        (and (= Q2 4368)
     (= H2 4096)
     (= G2 (+ (- 65280) B))
     (not (= X1 0))
     (= G1 0)
     (not (= X 0))
     (= V 0)
     (= U (+ 1 D1))
     (not (= Q 0))
     (= O 0)
     (<= 0 H1)
     (<= 0 S)
     (<= 0 K)
     (= B 66048))
      )
      (inv_main193 P1
             W1
             M1
             V1
             Q2
             F1
             O
             B
             H2
             V
             A1
             P2
             F
             Z1
             Q
             F2
             E1
             E
             B2
             U
             C2
             G
             L
             A2
             C1
             S2
             M2
             C
             D
             T1
             N2
             K1
             Y1
             L2
             J1
             K
             S
             Y
             G1
             R1
             T
             M
             B1
             H
             I
             L1
             A
             X1
             X
             O1
             U1
             E2
             P
             Q1
             G2
             H1
             W
             O2
             N1
             R
             I1
             K2
             Z
             R2
             I2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (v_72 Int) ) 
    (=>
      (and
        (inv_main199 X1
             M1
             D1
             O
             J2
             P
             N1
             A2
             I
             U
             C1
             U1
             J1
             O2
             E2
             D2
             N
             P2
             V
             X
             S1
             M
             F2
             Z
             H
             R
             F
             R1
             J
             Y
             N2
             A1
             T2
             L2
             Q2
             C
             W
             V1
             K2
             H1
             G1
             Z1
             K1
             L
             I2
             G
             C2
             Q1
             P1
             L1
             K
             T
             R2
             B
             B1
             F1
             M2
             I1
             E
             B2
             W1
             S
             Q
             S2
             O1)
        (and (= K2 0)
     (= H2 4368)
     (= G2 0)
     (= E2 0)
     (not (= C2 0))
     (= A2 66048)
     (= Y1 4096)
     (= T1 (+ (- 65280) A2))
     (not (= Q1 0))
     (not (= P1 0))
     (not (= E1 0))
     (= D 0)
     (<= 0 C)
     (<= 0 F1)
     (<= 0 W)
     (= A (+ 1 X))
     (= v_72 E1))
      )
      (inv_main193 X1
             M1
             D1
             O
             H2
             P
             G2
             A2
             Y1
             D
             C1
             U1
             J1
             O2
             E1
             D2
             N
             P2
             V
             A
             S1
             M
             F2
             Z
             H
             R
             F
             R1
             J
             Y
             N2
             A1
             T2
             L2
             v_72
             C
             W
             V1
             K2
             H1
             G1
             Z1
             K1
             L
             I2
             G
             C2
             Q1
             P1
             L1
             K
             T
             R2
             B
             T1
             F1
             M2
             I1
             E
             B2
             W1
             S
             Q
             S2
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) ) 
    (=>
      (and
        (inv_main114 J
             F1
             E1
             N
             O1
             L2
             U
             M2
             J2
             P1
             S
             K1
             V1
             Y
             P2
             D1
             K2
             E2
             L
             I1
             K
             N2
             R
             G
             Q2
             R1
             A2
             D
             W
             G2
             E
             Z1
             N1
             O
             C
             V
             H1
             H
             T
             X1
             C1
             B
             G1
             S1
             M
             B1
             B2
             Q
             Y1
             P
             A1
             F
             H2
             J1
             Q1
             I2
             A
             W1
             M1
             D2
             I
             Z
             L1
             T1
             U1)
        (and (= C2 4)
     (not (= O1 12292))
     (not (= O1 16384))
     (not (= O1 4096))
     (not (= O1 20480))
     (not (= O1 4099))
     (not (= O1 4368))
     (not (= O1 4369))
     (not (= O1 4384))
     (not (= O1 4385))
     (not (= O1 4400))
     (not (= O1 4401))
     (= O1 4416)
     (= J1 3)
     (= X 0)
     (not (= P 0))
     (<= 0 I2)
     (<= 0 H1)
     (<= 0 V)
     (not (<= O2 0))
     (= F2 4432))
      )
      (inv_main193 J
             F1
             E1
             N
             F2
             L2
             U
             M2
             J2
             X
             S
             K1
             V1
             Y
             P2
             D1
             K2
             E2
             L
             I1
             K
             N2
             R
             G
             Q2
             R1
             A2
             D
             W
             G2
             E
             Z1
             N1
             O
             C
             V
             H1
             H
             T
             O2
             C1
             O1
             G1
             S1
             M
             B1
             B2
             Q
             Y1
             P
             A1
             F
             H2
             C2
             Q1
             I2
             A
             W1
             M1
             D2
             I
             Z
             L1
             T1
             U1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 V
             F1
             R1
             D
             V1
             J2
             W1
             M
             T
             M2
             Y1
             I2
             J
             O1
             K
             C
             E2
             Z
             S
             D1
             L1
             I
             Y
             W
             H1
             P2
             E
             N
             O2
             Z1
             N2
             L2
             I1
             C1
             U
             H2
             G2
             Q
             A
             F2
             B1
             S1
             X1
             K2
             B2
             Q1
             U1
             R
             T1
             X
             O
             D2
             L
             H
             K1
             C2
             N1
             J1
             B
             M1
             P
             G
             A2
             F
             P1)
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
     (= V1 4416)
     (= G1 4432)
     (= A1 0)
     (not (= X 0))
     (not (= H 3))
     (<= 0 H2)
     (<= 0 G2)
     (<= 0 C2)
     (not (<= E1 0))
     (not (= V1 12292)))
      )
      (inv_main193 V
             F1
             R1
             D
             G1
             J2
             W1
             M
             T
             A1
             Y1
             I2
             J
             O1
             K
             C
             E2
             Z
             S
             D1
             L1
             I
             Y
             W
             H1
             P2
             E
             N
             O2
             Z1
             N2
             L2
             I1
             C1
             U
             H2
             G2
             Q
             A
             E1
             B1
             V1
             X1
             K2
             B2
             Q1
             U1
             R
             T1
             X
             O
             D2
             L
             H
             K1
             C2
             N1
             J1
             B
             M1
             P
             G
             A2
             F
             P1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) ) 
    (=>
      (and
        (inv_main114 F2
             L2
             P1
             Q2
             I1
             R1
             X
             Q1
             N1
             M2
             E
             O
             M1
             K1
             J2
             S1
             W1
             B1
             C2
             L1
             I2
             H1
             Z1
             N2
             L
             J
             I
             G1
             Y
             D1
             G
             B
             V1
             X1
             G2
             K2
             E1
             T1
             P2
             M
             D
             W
             K
             A1
             C
             E2
             V
             B2
             C1
             F1
             A2
             H2
             O1
             R
             Y1
             A
             O2
             D2
             T
             J1
             U
             S
             F
             H
             Q)
        (and (not (= I1 12292))
     (not (= I1 16384))
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
     (= I1 4417)
     (not (= F1 0))
     (= R 3)
     (= P 4)
     (= N 4432)
     (<= 0 K2)
     (<= 0 E1)
     (<= 0 A)
     (not (<= Z 0))
     (= U1 0))
      )
      (inv_main193 F2
             L2
             P1
             Q2
             N
             R1
             X
             Q1
             N1
             U1
             E
             O
             M1
             K1
             J2
             S1
             W1
             B1
             C2
             L1
             I2
             H1
             Z1
             N2
             L
             J
             I
             G1
             Y
             D1
             G
             B
             V1
             X1
             G2
             K2
             E1
             T1
             P2
             Z
             D
             I1
             K
             A1
             C
             E2
             V
             B2
             C1
             F1
             A2
             H2
             O1
             P
             Y1
             A
             O2
             D2
             T
             J1
             U
             S
             F
             H
             Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 G
             E1
             Y
             Y1
             G2
             C
             N2
             W
             H1
             H2
             D2
             O
             F2
             W1
             I
             I1
             L
             J1
             L1
             M2
             X1
             D
             C2
             K
             T
             B1
             E
             P1
             H
             G1
             B
             S1
             I2
             N
             U
             D1
             M
             X
             J
             V1
             U1
             S
             Q1
             K1
             A
             R1
             O1
             O2
             C1
             Q
             T1
             P
             J2
             N1
             B2
             P2
             K2
             R
             A1
             F1
             F
             Z1
             Z
             E2
             V)
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
     (= G2 4417)
     (= A2 0)
     (not (= N1 3))
     (not (= Q 0))
     (<= 0 D1)
     (<= 0 M)
     (<= 0 P2)
     (not (<= M1 0))
     (= L2 4432))
      )
      (inv_main193 G
             E1
             Y
             Y1
             L2
             C
             N2
             W
             H1
             A2
             D2
             O
             F2
             W1
             I
             I1
             L
             J1
             L1
             M2
             X1
             D
             C2
             K
             T
             B1
             E
             P1
             H
             G1
             B
             S1
             I2
             N
             U
             D1
             M
             X
             J
             M1
             U1
             G2
             Q1
             K1
             A
             R1
             O1
             O2
             C1
             Q
             T1
             P
             J2
             N1
             B2
             P2
             K2
             R
             A1
             F1
             F
             Z1
             Z
             E2
             V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main114 M
             E1
             Z
             O2
             K2
             C1
             D1
             I
             O1
             F2
             D
             G1
             Q1
             E2
             U
             L1
             R1
             F
             S
             W1
             C
             B
             D2
             O
             I1
             N2
             E
             I2
             H
             T1
             Z1
             K1
             V
             J1
             T
             P2
             V1
             Q2
             G2
             Y
             S1
             Y1
             X
             P1
             W
             A1
             X1
             L2
             A2
             A
             U1
             B2
             N
             K
             L
             H1
             G
             H2
             J
             F1
             R
             M1
             N1
             Q
             P)
        (and (not (= K2 4497))
     (= K2 4512)
     (not (= K2 12292))
     (not (= K2 16384))
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
     (not (= K2 4481))
     (not (= K2 4496))
     (= C2 0)
     (not (= B2 0))
     (not (= U1 0))
     (= B1 4528)
     (= E 0)
     (<= 0 P2)
     (<= 0 V1)
     (<= 0 H1)
     (not (<= J2 0))
     (= M2 0)
     (= v_69 H))
      )
      (inv_main193 M
             E1
             Z
             O2
             B1
             C1
             D1
             I
             O1
             C2
             D
             G1
             Q1
             E2
             U
             L1
             R1
             F
             S
             W1
             C
             B
             D2
             O
             I1
             N2
             E
             I2
             H
             T1
             Z1
             K1
             v_69
             M2
             T
             P2
             V1
             Q2
             G2
             J2
             S1
             K2
             X
             P1
             W
             A1
             X1
             L2
             A2
             A
             U1
             B2
             N
             K
             L
             H1
             G
             H2
             J
             F1
             R
             M1
             N1
             Q
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main114 I2
             K
             M1
             O2
             B1
             C1
             C
             P1
             D2
             N2
             N1
             Z1
             M2
             Y1
             E
             B2
             C2
             R1
             H2
             N
             H
             T1
             B
             Y
             Q1
             A1
             U
             P2
             D
             S1
             R
             F
             K1
             F1
             O1
             H1
             W1
             F2
             K2
             P
             Q
             J1
             A
             E2
             V1
             G1
             W
             Z
             L1
             S
             I
             X1
             X
             L2
             G2
             A2
             E1
             J2
             V
             O
             I1
             L
             T
             G
             M)
        (and (= D1 4528)
     (not (= B1 4497))
     (= B1 4512)
     (not (= B1 12292))
     (not (= B1 16384))
     (not (= B1 4096))
     (not (= B1 20480))
     (not (= B1 4099))
     (not (= B1 4368))
     (not (= B1 4369))
     (not (= B1 4384))
     (not (= B1 4385))
     (not (= B1 4400))
     (not (= B1 4401))
     (not (= B1 4416))
     (not (= B1 4417))
     (not (= B1 4432))
     (not (= B1 4433))
     (not (= B1 4448))
     (not (= B1 4449))
     (not (= B1 4464))
     (not (= B1 4465))
     (not (= B1 4466))
     (not (= B1 4467))
     (not (= B1 4480))
     (not (= B1 4481))
     (not (= B1 4496))
     (not (= U 0))
     (= J 0)
     (not (= I 0))
     (<= 0 A2)
     (<= 0 W1)
     (<= 0 H1)
     (not (<= U1 0))
     (not (= X1 0))
     (= v_68 D)
     (= v_69 F))
      )
      (inv_main193 I2
             K
             M1
             O2
             D1
             C1
             C
             P1
             D2
             J
             N1
             Z1
             M2
             Y1
             E
             B2
             C2
             R1
             H2
             N
             H
             T1
             B
             Y
             Q1
             A1
             U
             P2
             D
             S1
             R
             F
             v_68
             v_69
             O1
             H1
             W1
             F2
             K2
             U1
             Q
             B1
             A
             E2
             V1
             G1
             W
             Z
             L1
             S
             I
             X1
             X
             L2
             G2
             A2
             E1
             J2
             V
             O
             I1
             L
             T
             G
             M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main114 E
             P
             N1
             T1
             G1
             A1
             M1
             I1
             J2
             B2
             N2
             W1
             Z1
             P2
             E1
             U1
             N
             R1
             Z
             T
             G
             I2
             Q2
             F1
             S
             I
             C
             V1
             Y1
             P1
             L1
             X1
             A
             L2
             D2
             H
             L
             Q1
             K1
             C2
             B
             O
             M
             B1
             O1
             O2
             H1
             K
             M2
             V
             Y
             U
             F
             J1
             D
             S1
             D1
             Q
             F2
             R
             G2
             C1
             X
             E2
             J)
        (and (= A2 0)
     (= G1 4513)
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
     (not (= Y 0))
     (= W 4528)
     (not (= U 0))
     (= C 0)
     (<= 0 S1)
     (<= 0 L)
     (<= 0 H)
     (not (<= K2 0))
     (= H2 0)
     (= v_69 Y1))
      )
      (inv_main193 E
             P
             N1
             T1
             W
             A1
             M1
             I1
             J2
             H2
             N2
             W1
             Z1
             P2
             E1
             U1
             N
             R1
             Z
             T
             G
             I2
             Q2
             F1
             S
             I
             C
             V1
             Y1
             P1
             L1
             X1
             v_69
             A2
             D2
             H
             L
             Q1
             K1
             K2
             B
             G1
             M
             B1
             O1
             O2
             H1
             K
             M2
             V
             Y
             U
             F
             J1
             D
             S1
             D1
             Q
             F2
             R
             G2
             C1
             X
             E2
             J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main114 L2
             V1
             F
             M
             R
             H1
             Y1
             W
             N
             G2
             V
             S1
             B1
             U
             F2
             X1
             N2
             J1
             F1
             M2
             I2
             C2
             E1
             Q1
             A
             O2
             Z
             X
             Z1
             G
             W1
             B2
             T
             U1
             D2
             S
             A2
             L1
             E
             J2
             L
             T1
             R1
             P1
             B
             C
             Y
             K2
             H
             D1
             G1
             K
             N1
             M1
             K1
             I
             D
             Q
             C1
             O
             A1
             E2
             J
             H2
             P)
        (and (= I1 0)
     (not (= G1 0))
     (not (= Z 0))
     (= R 4513)
     (not (= R 4497))
     (not (= R 4512))
     (not (= R 12292))
     (not (= R 16384))
     (not (= R 4096))
     (not (= R 20480))
     (not (= R 4099))
     (not (= R 4368))
     (not (= R 4369))
     (not (= R 4384))
     (not (= R 4385))
     (not (= R 4400))
     (not (= R 4401))
     (not (= R 4416))
     (not (= R 4417))
     (not (= R 4432))
     (not (= R 4433))
     (not (= R 4448))
     (not (= R 4449))
     (not (= R 4464))
     (not (= R 4465))
     (not (= R 4466))
     (not (= R 4467))
     (not (= R 4480))
     (not (= R 4481))
     (not (= R 4496))
     (not (= K 0))
     (<= 0 A2)
     (<= 0 S)
     (<= 0 I)
     (not (<= P2 0))
     (= O1 4528)
     (= v_68 Z1)
     (= v_69 B2))
      )
      (inv_main193 L2
             V1
             F
             M
             O1
             H1
             Y1
             W
             N
             I1
             V
             S1
             B1
             U
             F2
             X1
             N2
             J1
             F1
             M2
             I2
             C2
             E1
             Q1
             A
             O2
             Z
             X
             Z1
             G
             W1
             B2
             v_68
             v_69
             D2
             S
             A2
             L1
             E
             P2
             L
             R
             R1
             P1
             B
             C
             Y
             K2
             H
             D1
             G1
             K
             N1
             M1
             K1
             I
             D
             Q
             C1
             O
             A1
             E2
             J
             H2
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 B1
             X1
             Y
             F2
             P
             T1
             D
             V
             M
             A2
             X
             N1
             I1
             M1
             P1
             U
             I2
             K2
             A1
             Z
             U1
             J1
             Z1
             D1
             L1
             W1
             E1
             O
             W
             H2
             A
             I
             Q1
             L2
             O1
             F
             M2
             R1
             G
             K1
             H1
             R
             S
             S1
             F1
             Y1
             T
             K
             C2
             E
             C
             E2
             J
             J2
             G2
             H
             D2
             V1
             B
             C1
             G1
             N
             Q
             L
             B2)
        (and (not (= P 16384))
     (not (= P 4096))
     (not (= P 20480))
     (= P 4099)
     (<= 0 H)
     (<= 0 F)
     (<= 0 M2)
     (not (= P 12292))
     (= v_65 P))
      )
      (inv_main199 B1
             X1
             Y
             F2
             P
             T1
             D
             V
             M
             A2
             X
             N1
             I1
             M1
             P1
             U
             I2
             K2
             A1
             Z
             U1
             J1
             Z1
             D1
             L1
             W1
             E1
             O
             W
             H2
             A
             I
             Q1
             L2
             O1
             F
             M2
             R1
             G
             K1
             H1
             v_65
             S
             S1
             F1
             Y1
             T
             K
             C2
             E
             C
             E2
             J
             J2
             G2
             H
             D2
             V1
             B
             C1
             G1
             N
             Q
             L
             B2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 G
             C
             F2
             H1
             L2
             X1
             U
             R
             F
             I1
             Y
             E
             P
             B
             C2
             G2
             U1
             X
             K1
             T1
             S1
             M1
             B1
             J2
             E2
             A1
             O
             V1
             Q
             L1
             M
             C1
             W1
             N1
             H2
             I2
             L
             K2
             N
             W
             O1
             S
             J
             G1
             T
             Q1
             R1
             V
             Y1
             A
             M2
             J1
             E1
             P1
             D2
             D
             A2
             F1
             I
             H
             Z
             Z1
             D1
             B2
             K)
        (and (not (= L2 16384))
     (not (= L2 4096))
     (= L2 20480)
     (<= 0 I2)
     (<= 0 L)
     (<= 0 D)
     (not (= L2 12292))
     (= v_65 L2))
      )
      (inv_main199 G
             C
             F2
             H1
             L2
             X1
             U
             R
             F
             I1
             Y
             E
             P
             B
             C2
             G2
             U1
             X
             K1
             T1
             S1
             M1
             B1
             J2
             E2
             A1
             O
             V1
             Q
             L1
             M
             C1
             W1
             N1
             H2
             I2
             L
             K2
             N
             W
             O1
             v_65
             J
             G1
             T
             Q1
             R1
             V
             Y1
             A
             M2
             J1
             E1
             P1
             D2
             D
             A2
             F1
             I
             H
             Z
             Z1
             D1
             B2
             K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 M2
             B2
             C
             M1
             F
             L
             Q
             I
             R1
             H
             X1
             E1
             R
             L2
             I2
             K
             K1
             M
             T
             U
             V1
             B
             S
             V
             O
             X
             E2
             I1
             O1
             H2
             K2
             C1
             G
             D1
             H1
             L1
             E
             D
             T1
             G1
             C2
             A2
             N1
             D2
             F1
             J2
             U1
             W1
             A
             N
             F2
             P1
             G2
             A1
             Z1
             S1
             P
             Z
             Q1
             Y1
             B1
             J1
             J
             W
             Y)
        (and (not (= F 16384))
     (= F 4096)
     (<= 0 S1)
     (<= 0 L1)
     (<= 0 E)
     (not (= F 12292))
     (= v_65 F))
      )
      (inv_main199 M2
             B2
             C
             M1
             F
             L
             Q
             I
             R1
             H
             X1
             E1
             R
             L2
             I2
             K
             K1
             M
             T
             U
             V1
             B
             S
             V
             O
             X
             E2
             I1
             O1
             H2
             K2
             C1
             G
             D1
             H1
             L1
             E
             D
             T1
             G1
             C2
             v_65
             N1
             D2
             F1
             J2
             U1
             W1
             A
             N
             F2
             P1
             G2
             A1
             Z1
             S1
             P
             Z
             Q1
             Y1
             B1
             J1
             J
             W
             Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 E2
             J2
             D1
             I2
             T1
             J
             M
             P
             W
             Z1
             V1
             G2
             Y
             K1
             U
             F2
             R1
             Q
             N1
             D
             P1
             Z
             V
             L2
             C1
             X1
             J1
             S1
             H1
             D2
             M1
             C2
             B2
             W1
             M2
             X
             L
             B
             I1
             A2
             U1
             O1
             R
             G
             B1
             E1
             K
             G1
             F
             N
             Y1
             A1
             O
             H2
             Q1
             A
             I
             E
             F1
             C
             L1
             K2
             H
             T
             S)
        (and (= T1 16384) (<= 0 X) (<= 0 L) (<= 0 A) (not (= T1 12292)) (= v_65 T1))
      )
      (inv_main199 E2
             J2
             D1
             I2
             T1
             J
             M
             P
             W
             Z1
             V1
             G2
             Y
             K1
             U
             F2
             R1
             Q
             N1
             D
             P1
             Z
             V
             L2
             C1
             X1
             J1
             S1
             H1
             D2
             M1
             C2
             B2
             W1
             M2
             X
             L
             B
             I1
             A2
             U1
             v_65
             R
             G
             B1
             E1
             K
             G1
             F
             N
             Y1
             A1
             O
             H2
             Q1
             A
             I
             E
             F1
             C
             L1
             K2
             H
             T
             S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main114 L2
             Q1
             G1
             S1
             V
             C
             P2
             G2
             O1
             H1
             R
             L1
             M2
             K
             A2
             X1
             P1
             N1
             I
             M
             I2
             P
             J
             S
             H
             Z1
             D
             X
             Q
             I1
             O2
             T
             C1
             W1
             E1
             B
             A
             F1
             F2
             W
             N
             U
             R1
             V1
             J2
             T1
             O
             F
             N2
             K1
             H2
             L
             Z
             B1
             U1
             M1
             C2
             Y
             G
             B2
             E2
             A1
             Y1
             D1
             E)
        (and (= D2 1)
     (= J1 (+ 1 I))
     (= V 12292)
     (<= 0 M1)
     (<= 0 B)
     (<= 0 A)
     (= K2 4096))
      )
      (inv_main199 L2
             Q1
             G1
             S1
             K2
             D2
             P2
             G2
             O1
             H1
             R
             L1
             M2
             K
             A2
             X1
             P1
             N1
             J1
             M
             I2
             P
             J
             S
             H
             Z1
             D
             X
             Q
             I1
             O2
             T
             C1
             W1
             E1
             B
             A
             F1
             F2
             W
             N
             V
             R1
             V1
             J2
             T1
             O
             F
             N2
             K1
             H2
             L
             Z
             B1
             U1
             M1
             C2
             Y
             G
             B2
             E2
             A1
             Y1
             D1
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main3 J1)
        (and (= H2 0)
     (= C2 12292)
     (= B2 0)
     (= A2 12292)
     (= I1 1)
     (= V 12292)
     (= R (- 1))
     (= H 0)
     (<= 0 M1)
     (<= 0 B1)
     (<= 0 F)
     (not (= K2 0))
     (= v_66 K2))
      )
      (inv_main108 C2
             V
             K2
             U1
             A2
             J
             U
             F1
             K
             G1
             H1
             P1
             S
             Y
             I1
             N2
             W1
             E
             A
             X
             D1
             T
             D
             R1
             O
             Q
             X1
             C1
             N
             Q1
             G2
             V1
             L
             A1
             W
             L2
             B1
             Z
             v_66
             R
             Z1
             P
             H2
             B2
             F2
             G
             Y1
             M
             C
             L1
             M2
             T1
             B
             H
             I2
             F
             O1
             E1
             K1
             D2
             S1
             E2
             J2
             I
             N1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main3 W1)
        (and (= I2 12292)
     (= F2 0)
     (= V1 0)
     (= U1 12292)
     (not (= B1 0))
     (= W 0)
     (= K 12292)
     (= J 1)
     (= A 0)
     (<= 0 J1)
     (<= 0 O)
     (<= 0 L)
     (= K2 (- 1))
     (= v_66 B1))
      )
      (inv_main108 U1
             K
             F2
             Z
             I2
             Y
             L1
             R
             N
             E
             D2
             C2
             G2
             E2
             J
             J2
             G1
             B1
             X1
             O1
             Z1
             E1
             N2
             S
             Q
             P
             M
             I
             F
             H2
             H
             D1
             X
             B2
             L2
             D
             J1
             H1
             v_66
             K2
             S1
             A1
             A
             W
             N1
             M2
             R1
             F1
             C1
             C
             T
             T1
             I1
             V1
             M1
             O
             Q1
             B
             Y1
             V
             U
             G
             K1
             A2
             P1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main3 Y1)
        (and (= F2 0)
     (= C2 1)
     (= P1 12292)
     (= L1 12292)
     (= E1 0)
     (= V 0)
     (= L (- 1))
     (= H 0)
     (= F 0)
     (= C 0)
     (<= 0 L2)
     (<= 0 Q1)
     (<= 0 U)
     (= J2 12292))
      )
      (inv_main108 P1
             L1
             C
             S
             J2
             N1
             V1
             M1
             P
             K2
             X1
             N2
             B
             N
             C2
             O2
             F1
             F
             T
             Z
             R
             R1
             J
             W
             G
             U1
             I2
             A2
             K1
             D2
             D
             B2
             M
             K
             M2
             E
             U
             G1
             V
             L
             Q
             W1
             F2
             E1
             C1
             S1
             O
             B1
             Z1
             H2
             A1
             Y
             O1
             H
             A
             L2
             H1
             X
             G2
             I1
             T1
             J1
             D1
             E2
             I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main108 M1
             Y1
             A2
             F1
             T1
             J2
             B1
             D1
             V1
             B
             V
             Q
             K
             E1
             F2
             H1
             L
             R
             D
             U
             A1
             L2
             T
             L1
             N2
             K2
             G2
             C1
             Z1
             I1
             F
             N
             X
             N1
             E2
             K1
             U1
             I
             I2
             H2
             W
             J
             D2
             A
             C2
             S1
             G
             Y
             M
             M2
             X1
             E
             J1
             S
             Z
             O
             P1
             Q1
             P
             W1
             G1
             H
             C
             R1
             O1)
        (and (= B2 (+ 1 F1)) (<= 0 U1) (<= 0 K1) (<= 0 O) (= C2 12288))
      )
      (inv_main114 M1
             Y1
             A2
             B2
             T1
             J2
             B1
             D1
             V1
             B
             V
             Q
             K
             E1
             F2
             H1
             L
             R
             D
             U
             A1
             L2
             T
             L1
             N2
             K2
             G2
             C1
             Z1
             I1
             F
             N
             X
             N1
             E2
             K1
             U1
             I
             I2
             H2
             W
             J
             D2
             A
             C2
             S1
             G
             Y
             M
             M2
             X1
             E
             J1
             S
             Z
             O
             P1
             Q1
             P
             W1
             G1
             H
             C
             R1
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main108 Q1
             D1
             W
             U
             M
             S
             J1
             L
             W1
             A2
             A
             B
             H1
             O1
             I
             V1
             Z1
             Z
             K
             K2
             A1
             I2
             P1
             Y1
             H2
             E
             N2
             Q
             U1
             X1
             H
             F2
             N1
             V
             S1
             M2
             G
             N
             D2
             E1
             C
             P
             C2
             O
             C1
             R1
             L1
             B1
             G1
             G2
             K1
             E2
             T
             M1
             B2
             L2
             J2
             F
             J
             I1
             D
             T1
             X
             F1
             Y)
        (and (not (= C1 12288))
     (= R (+ 1 U))
     (<= 0 M2)
     (<= 0 L2)
     (<= 0 G)
     (not (= R1 16384)))
      )
      (inv_main114 Q1
             D1
             W
             R
             M
             S
             J1
             L
             W1
             A2
             A
             B
             H1
             O1
             I
             V1
             Z1
             Z
             K
             K2
             A1
             I2
             P1
             Y1
             H2
             E
             N2
             Q
             U1
             X1
             H
             F2
             N1
             V
             S1
             M2
             G
             N
             D2
             E1
             C
             P
             C2
             O
             C1
             R1
             L1
             B1
             G1
             G2
             K1
             E2
             T
             M1
             B2
             L2
             J2
             F
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
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main108 D
             N2
             M
             D1
             P1
             A1
             Y1
             Z1
             T
             U
             E2
             M2
             D2
             T1
             C1
             K1
             E
             K2
             H
             A
             G2
             W1
             J2
             Q
             I2
             Z
             O
             F1
             B2
             Y
             K
             L1
             M1
             C
             X1
             E1
             O1
             A2
             X
             G
             I
             B1
             F
             L2
             N1
             P
             V1
             B
             H2
             J1
             I1
             S1
             L
             S
             W
             R
             V
             N
             H1
             J
             G1
             C2
             U1
             Q1
             R1)
        (and (not (= N1 12288))
     (= P 16384)
     (<= 0 O1)
     (<= 0 E1)
     (<= 0 R)
     (= F2 (+ 1 D1)))
      )
      (inv_main114 D
             N2
             M
             F2
             P1
             A1
             Y1
             Z1
             T
             U
             E2
             M2
             D2
             T1
             C1
             K1
             E
             K2
             H
             A
             G2
             W1
             J2
             Q
             I2
             Z
             O
             F1
             B2
             Y
             K
             L1
             M1
             C
             X1
             E1
             O1
             A2
             X
             G
             I
             B1
             F
             L2
             N1
             P
             V1
             B
             H2
             J1
             I1
             S1
             L
             S
             W
             R
             V
             N
             H1
             J
             G1
             C2
             U1
             Q1
             R1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main193 S
             C1
             Q1
             A1
             I1
             X1
             T1
             H1
             E1
             K1
             Q
             K2
             L
             U1
             U
             A2
             D2
             N1
             G2
             B
             M1
             D1
             Z1
             C2
             Z
             O1
             J
             M2
             O
             N
             F2
             K
             W
             S1
             I2
             M
             E2
             C
             T
             Y1
             Y
             G
             V1
             L2
             J2
             L1
             H
             H2
             B1
             E
             J1
             P1
             D
             R
             B2
             I
             X
             A
             R1
             V
             W1
             G1
             F
             P
             N2)
        (and (= F1 0) (<= 0 E2) (<= 0 M) (<= 0 I) (not (= M2 0)))
      )
      (inv_main114 S
             C1
             Q1
             A1
             I1
             X1
             T1
             H1
             E1
             K1
             Q
             K2
             L
             U1
             U
             A2
             D2
             N1
             G2
             B
             M1
             D1
             Z1
             C2
             Z
             O1
             J
             M2
             O
             N
             F2
             K
             W
             S1
             I2
             M
             E2
             C
             T
             Y1
             Y
             G
             F1
             L2
             J2
             L1
             H
             H2
             B1
             E
             J1
             P1
             D
             R
             B2
             I
             X
             A
             R1
             V
             W1
             G1
             F
             P
             N2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main193 G
             F2
             T1
             O1
             X
             A2
             J2
             G2
             H1
             I1
             I2
             C
             E1
             M
             D2
             S1
             N1
             I
             J1
             A
             F
             U1
             B2
             M1
             Q1
             K2
             L2
             Z1
             R
             E
             D
             C2
             Y1
             P1
             G1
             H2
             L
             P
             O
             V1
             A1
             U
             Z
             Y
             B
             T
             W
             W1
             K1
             D1
             N2
             E2
             R1
             J
             B1
             V
             C1
             F1
             K
             X1
             N
             Q
             S
             M2
             L1)
        (and (not (= Z 0)) (= H 0) (<= 0 H2) (<= 0 V) (<= 0 L) (= Z1 0))
      )
      (inv_main114 G
             F2
             T1
             O1
             X
             A2
             J2
             G2
             H1
             I1
             I2
             C
             E1
             M
             D2
             S1
             N1
             I
             J1
             A
             F
             U1
             B2
             M1
             Q1
             K2
             L2
             Z1
             R
             E
             D
             C2
             Y1
             P1
             G1
             H2
             L
             P
             O
             V1
             A1
             U
             H
             Y
             B
             T
             W
             W1
             K1
             D1
             N2
             E2
             R1
             J
             B1
             V
             C1
             F1
             K
             X1
             N
             Q
             S
             M2
             L1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main449 R1
             F2
             R
             A1
             X1
             G
             E
             N
             C
             T1
             L2
             B1
             G1
             V1
             Q
             N1
             K2
             Z
             A2
             O1
             W1
             B
             S
             E1
             F
             P
             F1
             H1
             J
             K1
             T
             U
             I2
             P1
             O
             B2
             H2
             J2
             D
             D1
             Z1
             X
             W
             M1
             C1
             U1
             J1
             S1
             G2
             M2
             M
             I
             I1
             N2
             E2
             L1
             A
             H
             Q1
             Y
             D2
             V
             Y1
             L
             C2)
        (and (= D 0) (<= 0 H2) (<= 0 B2) (<= 0 L1) (= K 0))
      )
      (inv_main114 R1
             F2
             R
             A1
             X1
             G
             E
             N
             C
             T1
             L2
             B1
             G1
             V1
             Q
             N1
             K2
             Z
             A2
             O1
             W1
             B
             S
             E1
             F
             P
             F1
             H1
             J
             K1
             T
             U
             I2
             P1
             O
             B2
             H2
             J2
             D
             D1
             Z1
             X
             K
             M1
             C1
             U1
             J1
             S1
             G2
             M2
             M
             I
             I1
             N2
             E2
             L1
             A
             H
             Q1
             Y
             D2
             V
             Y1
             L
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main449 I2
             I1
             F2
             C2
             R1
             Q1
             G2
             U1
             S1
             A1
             G
             N2
             J2
             Z
             U
             R
             V
             D
             H1
             M
             J
             N1
             C1
             X
             B
             L1
             F1
             P
             K1
             G1
             Q
             H
             F
             T1
             L2
             H2
             Y
             V1
             N
             K2
             I
             J1
             L
             T
             A2
             E1
             W
             E
             B1
             E2
             Y1
             D1
             X1
             W1
             Z1
             C
             M2
             P1
             D2
             K
             A
             M1
             S
             O1
             B2)
        (and (= O 0) (not (= N 0)) (<= 0 H2) (<= 0 Y) (<= 0 C) (= R1 J1))
      )
      (inv_main114 I2
             I1
             F2
             C2
             R1
             Q1
             G2
             U1
             S1
             A1
             G
             N2
             J2
             Z
             U
             R
             V
             D
             H1
             M
             J
             N1
             C1
             X
             B
             L1
             F1
             P
             K1
             G1
             Q
             H
             F
             T1
             L2
             H2
             Y
             V1
             N
             K2
             I
             J1
             O
             T
             A2
             E1
             W
             E
             B1
             E2
             Y1
             D1
             X1
             W1
             Z1
             C
             M2
             P1
             D2
             K
             A
             M1
             S
             O1
             B2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main449 R1
             O
             K1
             Y
             A2
             B1
             H
             G2
             J1
             W
             U1
             N2
             D1
             K
             Y1
             E2
             I2
             Q1
             E
             W1
             M1
             V1
             K2
             L
             F1
             H1
             G
             I
             L2
             S1
             X1
             X
             E1
             L1
             D2
             A1
             B2
             Z
             U
             C1
             Z1
             P
             M2
             N1
             O1
             I1
             T
             B
             S
             P1
             D
             G1
             Q
             V
             J
             T1
             C
             J2
             F2
             N
             C2
             F
             R
             A
             H2)
        (and (not (= U 0))
     (= M 0)
     (<= 0 B2)
     (<= 0 T1)
     (<= 0 A1)
     (not (= A2 P))
     (= v_66 A2))
      )
      (inv_main114 R1
             O
             K1
             Y
             A2
             B1
             H
             G2
             J1
             W
             U1
             N2
             D1
             K
             Y1
             E2
             I2
             Q1
             E
             W1
             M1
             V1
             K2
             L
             F1
             H1
             G
             I
             L2
             S1
             X1
             X
             E1
             L1
             D2
             A1
             B2
             Z
             U
             C1
             v_66
             P
             M
             N1
             O1
             I1
             T
             B
             S
             P1
             D
             G1
             Q
             V
             J
             T1
             C
             J2
             F2
             N
             C2
             F
             R
             A
             H2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main114 U
             W
             X1
             K
             I1
             T
             G2
             Y1
             I2
             E2
             N2
             D
             F1
             E1
             Q
             V1
             L1
             D1
             P1
             B2
             S1
             J1
             S
             I
             C1
             D2
             K2
             Z
             A2
             F2
             M1
             H
             M
             C2
             B1
             A
             R
             C
             P
             E
             W1
             Q1
             H2
             G
             M2
             O
             Y
             O2
             V
             U1
             N
             K1
             F
             H1
             Z1
             J
             L2
             R1
             J2
             B
             T1
             X
             A1
             G1
             L)
        (and (not (= I1 12292))
     (not (= I1 16384))
     (not (= I1 4096))
     (not (= I1 20480))
     (not (= I1 4099))
     (not (= I1 4368))
     (not (= I1 4369))
     (= I1 4384)
     (= H1 1)
     (<= 0 R)
     (<= 0 J)
     (<= 0 A)
     (= O1 2)
     (= v_67 I1))
      )
      (inv_main256 U
             W
             X1
             K
             I1
             T
             G2
             Y1
             I2
             E2
             N2
             D
             F1
             E1
             Q
             V1
             L1
             D1
             P1
             B2
             S1
             J1
             S
             I
             C1
             D2
             K2
             Z
             A2
             F2
             M1
             H
             M
             C2
             B1
             A
             R
             C
             P
             N1
             W1
             v_67
             H2
             G
             M2
             O
             Y
             O2
             V
             U1
             N
             K1
             F
             O1
             Z1
             J
             L2
             R1
             J2
             B
             T1
             X
             A1
             G1
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main114 P
             Y
             B2
             T1
             E1
             T
             R
             F
             D
             O1
             I2
             M2
             A2
             G1
             M1
             L2
             H2
             J1
             K
             N
             V
             S
             V1
             J2
             A1
             W
             N1
             I
             E
             B1
             A
             U1
             F1
             Z1
             O
             J
             Z
             D1
             X1
             C
             K2
             N2
             R1
             F2
             P1
             C1
             H
             U
             D2
             I1
             H1
             M
             W1
             L1
             G
             B
             X
             G2
             Y1
             E2
             S1
             C2
             Q1
             K1
             L)
        (and (not (= E1 12292))
     (not (= E1 16384))
     (not (= E1 4096))
     (not (= E1 20480))
     (not (= E1 4099))
     (not (= E1 4368))
     (not (= E1 4369))
     (= E1 4384)
     (<= 0 Z)
     (<= 0 J)
     (<= 0 B)
     (not (= L1 1))
     (= v_66 E1))
      )
      (inv_main256 P
             Y
             B2
             T1
             E1
             T
             R
             F
             D
             O1
             I2
             M2
             A2
             G1
             M1
             L2
             H2
             J1
             K
             N
             V
             S
             V1
             J2
             A1
             W
             N1
             I
             E
             B1
             A
             U1
             F1
             Z1
             O
             J
             Z
             D1
             X1
             Q
             K2
             v_66
             R1
             F2
             P1
             C1
             H
             U
             D2
             I1
             H1
             M
             W1
             L1
             G
             B
             X
             G2
             Y1
             E2
             S1
             C2
             Q1
             K1
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main114 P
             I2
             I
             G1
             F1
             Y
             R
             H
             S1
             L2
             L1
             W1
             Q1
             X
             B1
             V
             J1
             F2
             Y1
             G2
             B2
             Q
             U
             V1
             H2
             O2
             A1
             Z1
             E2
             C1
             W
             S
             C
             L
             E1
             A
             U1
             J2
             C2
             K2
             N2
             D
             J
             M2
             O1
             O
             T1
             N
             H1
             G
             X1
             D2
             T
             P1
             F
             K
             D1
             Z
             A2
             M1
             K1
             B
             E
             R1
             M)
        (and (= N1 2)
     (not (= F1 12292))
     (not (= F1 16384))
     (not (= F1 4096))
     (not (= F1 20480))
     (not (= F1 4099))
     (not (= F1 4368))
     (not (= F1 4369))
     (not (= F1 4384))
     (= F1 4385)
     (<= 0 U1)
     (<= 0 K)
     (<= 0 A)
     (= P1 1)
     (= v_67 F1))
      )
      (inv_main256 P
             I2
             I
             G1
             F1
             Y
             R
             H
             S1
             L2
             L1
             W1
             Q1
             X
             B1
             V
             J1
             F2
             Y1
             G2
             B2
             Q
             U
             V1
             H2
             O2
             A1
             Z1
             E2
             C1
             W
             S
             C
             L
             E1
             A
             U1
             J2
             C2
             I1
             N2
             v_67
             J
             M2
             O1
             O
             T1
             N
             H1
             G
             X1
             D2
             T
             N1
             F
             K
             D1
             Z
             A2
             M1
             K1
             B
             E
             R1
             M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main114 V
             T
             F2
             G
             Q
             N
             F
             U
             M
             P1
             J
             K2
             A
             Z
             D
             I1
             D1
             C2
             P
             Z1
             A1
             K1
             H1
             H
             S
             J1
             N2
             K
             B
             Y
             I
             Y1
             T1
             R
             W
             L2
             F1
             X
             N1
             B2
             L
             S1
             R1
             E
             D2
             U1
             M1
             A2
             W1
             I2
             O
             C
             J2
             G1
             E2
             E1
             O1
             C1
             V1
             G2
             Q1
             H2
             M2
             L1
             B1)
        (and (not (= Q 12292))
     (not (= Q 16384))
     (not (= Q 4096))
     (not (= Q 20480))
     (not (= Q 4099))
     (not (= Q 4368))
     (not (= Q 4369))
     (not (= Q 4384))
     (= Q 4385)
     (<= 0 L2)
     (<= 0 F1)
     (<= 0 E1)
     (not (= G1 1))
     (= v_66 Q))
      )
      (inv_main256 V
             T
             F2
             G
             Q
             N
             F
             U
             M
             P1
             J
             K2
             A
             Z
             D
             I1
             D1
             C2
             P
             Z1
             A1
             K1
             H1
             H
             S
             J1
             N2
             K
             B
             Y
             I
             Y1
             T1
             R
             W
             L2
             F1
             X
             N1
             X1
             L
             v_66
             R1
             E
             D2
             U1
             M1
             A2
             W1
             I2
             O
             C
             J2
             G1
             E2
             E1
             O1
             C1
             V1
             G2
             Q1
             H2
             M2
             L1
             B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 G1
             U
             J2
             E
             H2
             D1
             B
             T
             F2
             P
             A2
             X1
             D2
             Y1
             D
             S
             F
             C
             R1
             V
             E1
             Z
             Z1
             K
             F1
             K2
             V1
             E2
             O1
             U1
             B1
             K1
             M1
             L1
             G
             M
             G2
             L2
             C2
             X
             C1
             Y
             B2
             I
             R
             M2
             A1
             O
             N1
             H
             A
             W1
             P1
             J
             N
             Q
             L
             J1
             I1
             S1
             Q1
             H1
             W
             T1
             I2)
        (and (not (= H2 16384))
     (not (= H2 4096))
     (not (= H2 20480))
     (not (= H2 4099))
     (not (= H2 4368))
     (not (= H2 4369))
     (not (= H2 4384))
     (not (= H2 4385))
     (= H2 4400)
     (<= 0 G2)
     (<= 0 Q)
     (<= 0 M)
     (not (= H2 12292))
     (= v_65 H2))
      )
      (inv_main267 G1
             U
             J2
             E
             H2
             D1
             B
             T
             F2
             P
             A2
             X1
             D2
             Y1
             D
             S
             F
             C
             R1
             V
             E1
             Z
             Z1
             K
             F1
             K2
             V1
             E2
             O1
             U1
             B1
             K1
             M1
             L1
             G
             M
             G2
             L2
             C2
             X
             C1
             v_65
             B2
             I
             R
             M2
             A1
             O
             N1
             H
             A
             W1
             P1
             J
             N
             Q
             L
             J1
             I1
             S1
             Q1
             H1
             W
             T1
             I2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 K
             J
             R1
             N1
             H2
             F1
             Y1
             B2
             F
             E
             I1
             H
             G
             K1
             Q1
             A2
             V
             P1
             D
             Z
             B
             A1
             J2
             D1
             L1
             O1
             R
             X1
             O
             L
             U
             I
             S
             U1
             M
             Q
             L2
             D2
             T1
             T
             Y
             W
             F2
             W1
             X
             I2
             A
             Z1
             V1
             M2
             N
             C2
             G2
             P
             H1
             M1
             B1
             J1
             K2
             S1
             G1
             C
             E1
             E2
             C1)
        (and (not (= H2 16384))
     (not (= H2 4096))
     (not (= H2 20480))
     (not (= H2 4099))
     (not (= H2 4368))
     (not (= H2 4369))
     (not (= H2 4384))
     (not (= H2 4385))
     (not (= H2 4400))
     (= H2 4401)
     (<= 0 L2)
     (<= 0 M1)
     (<= 0 Q)
     (not (= H2 12292))
     (= v_65 H2))
      )
      (inv_main267 K
             J
             R1
             N1
             H2
             F1
             Y1
             B2
             F
             E
             I1
             H
             G
             K1
             Q1
             A2
             V
             P1
             D
             Z
             B
             A1
             J2
             D1
             L1
             O1
             R
             X1
             O
             L
             U
             I
             S
             U1
             M
             Q
             L2
             D2
             T1
             T
             Y
             v_65
             F2
             W1
             X
             I2
             A
             Z1
             V1
             M2
             N
             C2
             G2
             P
             H1
             M1
             B1
             J1
             K2
             S1
             G1
             C
             E1
             E2
             C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 F2
             R1
             K1
             W
             H2
             S1
             T1
             F
             B
             R
             B2
             D
             E
             C2
             E1
             I
             J1
             T
             I2
             G1
             O
             E2
             M1
             J2
             A2
             K
             D1
             C1
             J
             U1
             C
             G
             A1
             Z
             M2
             W1
             X
             Q1
             Q
             L2
             B1
             U
             D2
             H
             A
             O1
             X1
             N1
             Y1
             S
             Z1
             V1
             L
             L1
             P
             N
             P1
             V
             M
             G2
             Y
             I1
             K2
             F1
             H1)
        (and (= H2 4528)
     (not (= H2 4497))
     (not (= H2 4512))
     (not (= H2 12292))
     (not (= H2 16384))
     (not (= H2 4096))
     (not (= H2 20480))
     (not (= H2 4099))
     (not (= H2 4368))
     (not (= H2 4369))
     (not (= H2 4384))
     (not (= H2 4385))
     (not (= H2 4400))
     (not (= H2 4401))
     (not (= H2 4416))
     (not (= H2 4417))
     (not (= H2 4432))
     (not (= H2 4433))
     (not (= H2 4448))
     (not (= H2 4449))
     (not (= H2 4464))
     (not (= H2 4465))
     (not (= H2 4466))
     (not (= H2 4467))
     (not (= H2 4480))
     (not (= H2 4481))
     (not (= H2 4496))
     (<= 0 W1)
     (<= 0 X)
     (<= 0 N)
     (not (= H2 4513))
     (= v_65 H2))
      )
      (inv_main377 F2
             R1
             K1
             W
             H2
             S1
             T1
             F
             B
             R
             B2
             D
             E
             C2
             E1
             I
             J1
             T
             I2
             G1
             O
             E2
             M1
             J2
             A2
             K
             D1
             C1
             J
             U1
             C
             G
             A1
             Z
             M2
             W1
             X
             Q1
             Q
             L2
             B1
             v_65
             D2
             H
             A
             O1
             X1
             N1
             Y1
             S
             Z1
             V1
             L
             L1
             P
             N
             P1
             V
             M
             G2
             Y
             I1
             K2
             F1
             H1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 G1
             M2
             P1
             Z
             E2
             J2
             V
             J1
             D1
             C2
             J
             H1
             C
             A
             K1
             K2
             B2
             R1
             W1
             D
             I2
             W
             I
             R
             L2
             U1
             V1
             G
             Q
             F1
             F2
             E1
             U
             K
             T
             M
             D2
             X
             H
             C1
             N
             A1
             S
             Y1
             I1
             L
             Y
             O1
             T1
             S1
             F
             B
             H2
             E
             P
             G2
             A2
             N1
             O
             L1
             B1
             Q1
             X1
             Z1
             M1)
        (and (not (= E2 4528))
     (= E2 4529)
     (not (= E2 4497))
     (not (= E2 4512))
     (not (= E2 12292))
     (not (= E2 16384))
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
     (not (= E2 4448))
     (not (= E2 4449))
     (not (= E2 4464))
     (not (= E2 4465))
     (not (= E2 4466))
     (not (= E2 4467))
     (not (= E2 4480))
     (not (= E2 4481))
     (not (= E2 4496))
     (<= 0 G2)
     (<= 0 D2)
     (<= 0 M)
     (not (= E2 4513))
     (= v_65 E2))
      )
      (inv_main377 G1
             M2
             P1
             Z
             E2
             J2
             V
             J1
             D1
             C2
             J
             H1
             C
             A
             K1
             K2
             B2
             R1
             W1
             D
             I2
             W
             I
             R
             L2
             U1
             V1
             G
             Q
             F1
             F2
             E1
             U
             K
             T
             M
             D2
             X
             H
             C1
             N
             v_65
             S
             Y1
             I1
             L
             Y
             O1
             T1
             S1
             F
             B
             H2
             E
             P
             G2
             A2
             N1
             O
             L1
             B1
             Q1
             X1
             Z1
             M1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main193 C1
             K2
             D1
             U
             W1
             K1
             Q1
             M2
             U1
             P1
             E1
             J2
             S
             Y
             W
             L1
             F
             G2
             F1
             Z1
             Z
             C2
             X
             I
             L2
             O
             T
             K
             S1
             D
             N1
             A1
             A2
             T1
             I1
             H
             E
             R
             Q
             O1
             F2
             B2
             H2
             J1
             B1
             M
             D2
             E2
             G
             H1
             B
             J
             C
             N
             L
             M1
             V1
             P
             V
             A
             G1
             I2
             X1
             Y1
             R1)
        (and (= L1 0) (= K 0) (<= 0 M1) (<= 0 H) (<= 0 E) (= H2 0))
      )
      (inv_main449 C1
             K2
             D1
             U
             W1
             K1
             Q1
             M2
             U1
             P1
             E1
             J2
             S
             Y
             W
             L1
             F
             G2
             F1
             Z1
             Z
             C2
             X
             I
             L2
             O
             T
             K
             S1
             D
             N1
             A1
             A2
             T1
             I1
             H
             E
             R
             Q
             O1
             F2
             B2
             H2
             J1
             B1
             M
             D2
             E2
             G
             H1
             B
             J
             C
             N
             L
             M1
             V1
             P
             V
             A
             G1
             I2
             X1
             Y1
             R1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main193 A
             E1
             V1
             B1
             O1
             D1
             A1
             F
             Z1
             P
             O
             Y1
             F1
             L2
             D2
             C2
             X1
             E
             I1
             G2
             M1
             I2
             S1
             C
             G1
             W1
             E2
             B2
             H1
             G
             F2
             K1
             H2
             P1
             N
             I
             T1
             Z
             N1
             X
             T
             H
             A2
             J2
             B
             J1
             N2
             W
             M
             M2
             D
             L
             Q1
             U1
             V
             R
             Y
             L1
             C1
             U
             K2
             K
             Q
             R1
             S)
        (and (= B2 0)
     (= A2 0)
     (<= 0 T1)
     (<= 0 R)
     (<= 0 I)
     (not (<= J 0))
     (not (= C2 0)))
      )
      (inv_main449 A
             E1
             V1
             B1
             O1
             D1
             A1
             F
             Z1
             P
             O
             Y1
             F1
             L2
             D2
             C2
             X1
             E
             I1
             G2
             M1
             I2
             S1
             C
             G1
             W1
             E2
             B2
             H1
             G
             F2
             K1
             H2
             P1
             N
             I
             T1
             Z
             N1
             J
             T
             H
             A2
             J2
             B
             J1
             N2
             W
             M
             M2
             D
             L
             Q1
             U1
             V
             R
             Y
             L1
             C1
             U
             K2
             K
             Q
             R1
             S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main235 T1
             N2
             F
             M2
             I
             A
             U1
             W
             Z1
             O1
             J
             T
             L
             G2
             V1
             A1
             L1
             M1
             C1
             H1
             G1
             I1
             Z
             C2
             Q1
             E
             K
             D
             A2
             M
             L2
             H2
             B1
             X1
             N1
             Y1
             Y
             O
             S
             X
             F2
             P2
             D2
             C
             G
             W1
             E1
             K2
             I2
             P1
             P
             U
             E2
             B
             H
             K1
             N
             V
             D1
             O2
             J2
             Q
             S1
             J1
             R)
        (and (= F1 1) (= B 0) (<= 0 Y1) (<= 0 K1) (<= 0 Y) (= B2 0))
      )
      (inv_main239 T1
             N2
             F
             M2
             I
             A
             U1
             W
             Z1
             O1
             J
             T
             L
             G2
             V1
             A1
             B2
             M1
             C1
             H1
             G1
             I1
             Z
             C2
             Q1
             E
             K
             D
             A2
             M
             L2
             H2
             B1
             X1
             N1
             Y1
             Y
             O
             S
             R1
             F2
             P2
             D2
             C
             G
             W1
             E1
             K2
             I2
             P1
             P
             U
             E2
             F1
             H
             K1
             N
             V
             D1
             O2
             J2
             Q
             S1
             J1
             R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main235 B
             E2
             U1
             Z1
             O1
             D2
             L1
             S1
             A1
             C2
             F1
             A
             P1
             V
             K1
             J1
             I1
             L
             Q
             N1
             I
             C
             H1
             L2
             R1
             E
             Z
             I2
             M1
             U
             K2
             D
             E1
             B2
             O2
             W1
             G1
             P2
             M
             P
             X
             D1
             H2
             S
             K
             G
             A2
             N
             H
             T1
             Y
             N2
             J2
             T
             F
             G2
             W
             M2
             X1
             Q1
             R
             J
             C1
             F2
             Y1)
        (and (= T 4) (not (= T 0)) (= O 5) (<= 0 G2) (<= 0 W1) (<= 0 G1) (= V1 0))
      )
      (inv_main239 B
             E2
             U1
             Z1
             O1
             D2
             L1
             S1
             A1
             C2
             F1
             A
             P1
             V
             K1
             J1
             V1
             L
             Q
             N1
             I
             C
             H1
             L2
             R1
             E
             Z
             I2
             M1
             U
             K2
             D
             E1
             B2
             O2
             W1
             G1
             P2
             M
             B1
             X
             D1
             H2
             S
             K
             G
             A2
             N
             H
             T1
             Y
             N2
             J2
             O
             F
             G2
             W
             M2
             X1
             Q1
             R
             J
             C1
             F2
             Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main235 Z
             S1
             F
             T1
             Z1
             A2
             K1
             G
             H1
             R1
             G1
             W1
             E2
             V1
             C1
             H2
             Q
             W
             N1
             M
             K2
             L
             N
             O
             A
             P1
             E1
             S
             M1
             J1
             B2
             P
             D1
             J2
             O1
             D
             B1
             E
             R
             C
             G2
             L1
             H
             X
             A1
             I2
             V
             Y1
             K
             F2
             I1
             M2
             Y
             U
             X1
             J
             B
             N2
             F1
             U1
             T
             Q1
             D2
             I
             C2)
        (and (not (= U 0)) (= O2 0) (<= 0 B1) (<= 0 J) (<= 0 D) (not (= U 4)))
      )
      (inv_main239 Z
             S1
             F
             T1
             Z1
             A2
             K1
             G
             H1
             R1
             G1
             W1
             E2
             V1
             C1
             H2
             O2
             W
             N1
             M
             K2
             L
             N
             O
             A
             P1
             E1
             S
             M1
             J1
             B2
             P
             D1
             J2
             O1
             D
             B1
             E
             R
             L2
             G2
             L1
             H
             X
             A1
             I2
             V
             Y1
             K
             F2
             I1
             M2
             Y
             U
             X1
             J
             B
             N2
             F1
             U1
             T
             Q1
             D2
             I
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main114 Z
             D1
             A2
             T
             D2
             P
             O1
             H1
             H2
             R1
             S
             Z1
             N
             N1
             B1
             G
             S1
             Q1
             E1
             F
             R
             M2
             D
             H
             I1
             K
             C
             W
             U1
             Y
             A1
             G2
             V1
             E
             A
             C1
             C2
             M
             E2
             Q
             K1
             L2
             V
             P1
             T1
             M1
             L
             B
             X1
             I2
             F1
             J
             U
             J2
             W1
             L1
             I
             K2
             G1
             O
             J1
             F2
             B2
             Y1
             N2)
        (and (not (= D2 12292))
     (not (= D2 16384))
     (not (= D2 4096))
     (not (= D2 20480))
     (not (= D2 4099))
     (not (= D2 4368))
     (not (= D2 4369))
     (not (= D2 4384))
     (not (= D2 4385))
     (not (= D2 4400))
     (not (= D2 4401))
     (not (= D2 4416))
     (not (= D2 4417))
     (= D2 4432)
     (<= 0 C2)
     (<= 0 L1)
     (<= 0 C1)
     (= J2 4)
     (= v_66 D2))
      )
      (inv_main466 Z
             D1
             A2
             T
             D2
             P
             O1
             H1
             H2
             R1
             S
             Z1
             N
             N1
             B1
             G
             S1
             Q1
             E1
             F
             R
             M2
             D
             H
             I1
             K
             C
             W
             U1
             Y
             A1
             G2
             V1
             E
             A
             C1
             C2
             M
             E2
             X
             K1
             v_66
             V
             P1
             T1
             M1
             L
             B
             X1
             I2
             F1
             J
             U
             J2
             W1
             L1
             I
             K2
             G1
             O
             J1
             F2
             B2
             Y1
             N2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main114 E1
             W1
             N1
             G
             B1
             L1
             A1
             M
             S1
             L
             K1
             J
             X
             F
             T
             A
             E2
             R
             D2
             C1
             E
             C
             Y
             H1
             Y1
             O
             U1
             Z
             L2
             F1
             D
             V1
             G1
             P1
             I
             I2
             K
             S
             H
             J1
             X1
             M2
             N
             H2
             Q1
             C2
             N2
             T1
             Q
             Z1
             G2
             V
             W
             B2
             I1
             J2
             A2
             K2
             M1
             P
             O1
             R1
             D1
             F2
             U)
        (and (not (= B1 12292))
     (not (= B1 16384))
     (not (= B1 4096))
     (not (= B1 20480))
     (not (= B1 4099))
     (not (= B1 4368))
     (not (= B1 4369))
     (not (= B1 4384))
     (not (= B1 4385))
     (not (= B1 4400))
     (not (= B1 4401))
     (not (= B1 4416))
     (not (= B1 4417))
     (not (= B1 4432))
     (= B1 4433)
     (<= 0 J2)
     (<= 0 I2)
     (<= 0 K)
     (= B2 4)
     (= v_66 B1))
      )
      (inv_main466 E1
             W1
             N1
             G
             B1
             L1
             A1
             M
             S1
             L
             K1
             J
             X
             F
             T
             A
             E2
             R
             D2
             C1
             E
             C
             Y
             H1
             Y1
             O
             U1
             Z
             L2
             F1
             D
             V1
             G1
             P1
             I
             I2
             K
             S
             H
             B
             X1
             v_66
             N
             H2
             Q1
             C2
             N2
             T1
             Q
             Z1
             G2
             V
             W
             B2
             I1
             J2
             A2
             K2
             M1
             P
             O1
             R1
             D1
             F2
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 A1
             X
             B1
             S
             E1
             K
             J
             M
             I2
             L
             B2
             G
             U
             E2
             F1
             E
             M1
             J1
             P
             V1
             F
             H1
             A
             B
             H2
             O1
             S1
             G2
             G1
             D1
             T1
             O
             I
             V
             Q
             A2
             Y
             N1
             C2
             C1
             R
             Z1
             X1
             Y1
             N
             R1
             I1
             T
             D2
             Z
             M2
             L2
             W
             H
             C
             K2
             W1
             F2
             P1
             U1
             Q1
             L1
             D
             K1
             J2)
        (and (not (= E1 16384))
     (not (= E1 4096))
     (not (= E1 20480))
     (not (= E1 4099))
     (= E1 4368)
     (<= 0 K2)
     (<= 0 A2)
     (<= 0 Y)
     (not (= E1 12292))
     (= v_65 E1))
      )
      (inv_main235 A1
             X
             B1
             S
             E1
             K
             J
             M
             I2
             L
             B2
             G
             U
             E2
             F1
             E
             M1
             J1
             P
             V1
             F
             H1
             A
             B
             H2
             O1
             S1
             G2
             G1
             D1
             T1
             O
             I
             V
             Q
             A2
             Y
             N1
             C2
             C1
             R
             v_65
             X1
             Y1
             N
             R1
             I1
             T
             D2
             Z
             M2
             L2
             W
             H
             C
             K2
             W1
             F2
             P1
             U1
             Q1
             L1
             D
             K1
             J2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main114 E1
             O1
             V1
             F1
             Q
             N1
             S1
             X1
             A
             J1
             B2
             E2
             R1
             O
             I
             P
             L
             J2
             K1
             K
             C1
             U1
             R
             U
             G
             D
             N
             Y
             M1
             D2
             I2
             G1
             S
             M
             K2
             J
             E
             F
             A2
             C
             M2
             X
             Q1
             H2
             C2
             H
             B1
             T
             Z1
             W
             L2
             L1
             G2
             B
             F2
             P1
             A1
             Z
             H1
             T1
             V
             Y1
             W1
             D1
             I1)
        (and (not (= Q 16384))
     (not (= Q 4096))
     (not (= Q 20480))
     (not (= Q 4099))
     (not (= Q 4368))
     (= Q 4369)
     (<= 0 P1)
     (<= 0 J)
     (<= 0 E)
     (not (= Q 12292))
     (= v_65 Q))
      )
      (inv_main235 E1
             O1
             V1
             F1
             Q
             N1
             S1
             X1
             A
             J1
             B2
             E2
             R1
             O
             I
             P
             L
             J2
             K1
             K
             C1
             U1
             R
             U
             G
             D
             N
             Y
             M1
             D2
             I2
             G1
             S
             M
             K2
             J
             E
             F
             A2
             C
             M2
             v_65
             Q1
             H2
             C2
             H
             B1
             T
             Z1
             W
             L2
             L1
             G2
             B
             F2
             P1
             A1
             Z
             H1
             T1
             V
             Y1
             W1
             D1
             I1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main466 O
             E2
             Z1
             F1
             V1
             A1
             S
             P1
             I1
             D1
             R
             B
             E
             D2
             W1
             Q1
             T1
             R1
             G1
             F2
             C
             G2
             V
             T
             N
             H
             B2
             M2
             E1
             M1
             J1
             J2
             Q
             Y1
             C2
             L
             B1
             A
             P
             X1
             A2
             Z
             I
             C1
             J
             L1
             M
             F
             O1
             N1
             L2
             H1
             K2
             K1
             W
             G
             K
             Y
             U
             U1
             H2
             I2
             S1
             X
             D)
        (and (<= 0 L) (<= 0 G) (<= 0 B1))
      )
      false
    )
  )
)

(check-sat)
(exit)
