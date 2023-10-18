; ./prepared/tricera/sv-comp-2020/./mixed/s3_srvr_10.cil.c-1_000.smt2
(set-logic HORN)


(declare-fun |inv_main496| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main453| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main328| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main4| ( Int Int ) Bool)
(declare-fun |inv_main197| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main253| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main417| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main296| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main513| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main116| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main105| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main270| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main334| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main487| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

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
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main116 Y
             O
             F
             S
             D2
             E1
             I2
             G1
             B2
             S1
             H2
             L
             W1
             H
             G
             B
             D1
             P
             X
             K
             C2
             Q1
             A1
             E2
             R
             Y1
             K1
             N
             I
             U
             M
             F2
             G2
             A2
             D
             X1
             W
             V1
             R1
             K2
             O1
             Q
             F1
             Z
             T1
             P1
             L1
             E
             U1
             J1
             T
             M1
             C1
             Z1
             B1
             A
             I1
             J2
             H1
             J
             N1
             V)
        (and (not (= E1 16384))
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
     (not (= P (- 2097152)))
     (= C 1)
     (<= 0 X1)
     (<= 0 I1)
     (<= 0 H1)
     (<= 0 W)
     (<= 0 V)
     (<= 0 J)
     (<= 0 D)
     (<= 0 J2)
     (not (= E1 12292))
     (= v_63 U)
     (= v_64 E1)
     (= v_65 P))
      )
      (inv_main296 Y
             O
             F
             S
             D2
             E1
             I2
             G1
             B2
             S1
             H2
             L
             W1
             H
             G
             B
             D1
             P
             X
             K
             C2
             Q1
             A1
             E2
             R
             Y1
             K1
             C
             I
             U
             M
             F2
             G2
             A2
             v_63
             X1
             W
             V1
             R1
             K2
             O1
             v_64
             F1
             Z
             T1
             P1
             L1
             E
             U1
             J1
             T
             M1
             C1
             Z1
             B1
             A
             I1
             v_65
             H1
             J
             N1
             V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main116 C1
             K1
             H2
             U
             E2
             J1
             A1
             R
             L1
             X1
             F1
             D1
             T
             F2
             S
             Q
             P
             L
             B1
             K
             M1
             H1
             O
             O1
             W
             A2
             X
             I1
             F
             E1
             N1
             Z
             B2
             D
             S1
             G2
             D2
             K2
             B
             G1
             J2
             R1
             P1
             U1
             T1
             Y
             H
             N
             I2
             V
             W1
             I
             J
             E
             C
             V1
             A
             Q1
             G
             Y1
             C2
             M)
        (and (not (= J1 12292))
     (not (= J1 16384))
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
     (not (= J1 8497))
     (not (= J1 8512))
     (not (= J1 8513))
     (= J1 8528)
     (= L (- 2097152))
     (<= 0 G2)
     (<= 0 D2)
     (<= 0 Y1)
     (<= 0 S1)
     (<= 0 Q1)
     (<= 0 M)
     (<= 0 G)
     (<= 0 A)
     (= Z1 0)
     (= v_63 E1)
     (= v_64 J1)
     (= v_65 L))
      )
      (inv_main296 C1
             K1
             H2
             U
             E2
             J1
             A1
             R
             L1
             X1
             F1
             D1
             T
             F2
             S
             Q
             P
             L
             B1
             K
             M1
             H1
             O
             O1
             W
             A2
             X
             Z1
             F
             E1
             N1
             Z
             B2
             D
             v_63
             G2
             D2
             K2
             B
             G1
             J2
             v_64
             P1
             U1
             T1
             Y
             H
             N
             I2
             V
             W1
             I
             J
             E
             C
             V1
             A
             v_65
             G
             Y1
             C2
             M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main116 I
             X
             I1
             L
             W
             P
             F
             N1
             B
             G1
             T
             P1
             Q
             H
             B2
             M1
             A2
             S1
             F2
             N
             J2
             C2
             Y1
             Q1
             Z
             Y
             F1
             O1
             G
             V
             W1
             O
             R1
             M
             Z1
             H1
             J
             T1
             X1
             S
             B1
             I2
             V1
             K1
             C1
             R
             D2
             K
             D1
             E1
             K2
             A
             E
             A1
             J1
             G2
             U1
             U
             D
             L1
             E2
             C)
        (and (not (= S1 (- 2097152)))
     (= P 8529)
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
     (<= 0 Z1)
     (<= 0 U1)
     (<= 0 L1)
     (<= 0 H1)
     (<= 0 U)
     (<= 0 J)
     (<= 0 D)
     (<= 0 C)
     (= H2 1)
     (= v_63 V)
     (= v_64 P)
     (= v_65 S1))
      )
      (inv_main296 I
             X
             I1
             L
             W
             P
             F
             N1
             B
             G1
             T
             P1
             Q
             H
             B2
             M1
             A2
             S1
             F2
             N
             J2
             C2
             Y1
             Q1
             Z
             Y
             F1
             H2
             G
             V
             W1
             O
             R1
             M
             v_63
             H1
             J
             T1
             X1
             S
             B1
             v_64
             V1
             K1
             C1
             R
             D2
             K
             D1
             E1
             K2
             A
             E
             A1
             J1
             G2
             U1
             v_65
             D
             L1
             E2
             C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main116 O1
             M1
             Y
             U
             T1
             Q
             D
             T
             L
             B
             N1
             B1
             F2
             W
             G1
             J2
             D1
             E
             J
             S
             I
             S1
             I1
             H2
             A1
             E2
             H
             Z
             Z1
             C1
             D2
             P1
             X1
             C2
             K
             G2
             N
             V
             Y1
             H1
             X
             J1
             R
             K1
             A
             I2
             F1
             W1
             B2
             G
             F
             A2
             P
             Q1
             O
             M
             R1
             V1
             K2
             U1
             C
             L1)
        (and (= Q 8529)
     (not (= Q 12292))
     (not (= Q 16384))
     (not (= Q 8192))
     (not (= Q 24576))
     (not (= Q 8195))
     (not (= Q 8480))
     (not (= Q 8481))
     (not (= Q 8482))
     (not (= Q 8464))
     (not (= Q 8465))
     (not (= Q 8466))
     (not (= Q 8496))
     (not (= Q 8497))
     (not (= Q 8512))
     (not (= Q 8513))
     (not (= Q 8528))
     (= E (- 2097152))
     (<= 0 G2)
     (<= 0 V1)
     (<= 0 U1)
     (<= 0 R1)
     (<= 0 L1)
     (<= 0 N)
     (<= 0 K)
     (<= 0 K2)
     (= E1 0)
     (= v_63 C1)
     (= v_64 Q)
     (= v_65 E))
      )
      (inv_main296 O1
             M1
             Y
             U
             T1
             Q
             D
             T
             L
             B
             N1
             B1
             F2
             W
             G1
             J2
             D1
             E
             J
             S
             I
             S1
             I1
             H2
             A1
             E2
             H
             E1
             Z1
             C1
             D2
             P1
             X1
             C2
             v_63
             G2
             N
             V
             Y1
             H1
             X
             v_64
             R
             K1
             A
             I2
             F1
             W1
             B2
             G
             F
             A2
             P
             Q1
             O
             M
             R1
             v_65
             K2
             U1
             C
             L1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main116 G2
             T
             N
             I2
             L
             U1
             A
             K
             C1
             X1
             U
             M1
             H2
             Q
             D1
             Q1
             S1
             E2
             V1
             O
             F2
             Z1
             T1
             S
             I
             A1
             K1
             Y
             M
             K2
             F1
             G
             X
             D
             E1
             D2
             L1
             H
             R1
             E
             J
             V
             P1
             Y1
             J2
             H1
             J1
             C
             B2
             W1
             B
             R
             P
             A2
             I1
             F
             B1
             W
             N1
             G1
             L2
             Z)
        (and (not (= U1 16384))
     (not (= U1 8192))
     (not (= U1 24576))
     (not (= U1 8195))
     (not (= U1 8480))
     (not (= U1 8481))
     (not (= U1 8482))
     (not (= U1 8464))
     (not (= U1 8465))
     (not (= U1 8466))
     (= U1 8496)
     (= O1 2)
     (= I1 1)
     (<= 0 D2)
     (<= 0 N1)
     (<= 0 L1)
     (<= 0 G1)
     (<= 0 E1)
     (<= 0 B1)
     (<= 0 Z)
     (<= 0 W)
     (not (= U1 12292))
     (= v_64 U1))
      )
      (inv_main270 G2
             T
             N
             I2
             L
             U1
             A
             K
             C1
             X1
             U
             M1
             H2
             Q
             D1
             Q1
             S1
             E2
             V1
             O
             F2
             Z1
             T1
             S
             I
             A1
             K1
             Y
             M
             K2
             F1
             G
             X
             D
             E1
             D2
             L1
             H
             R1
             C2
             J
             v_64
             P1
             Y1
             J2
             H1
             J1
             C
             B2
             W1
             B
             R
             P
             A2
             O1
             F
             B1
             W
             N1
             G1
             L2
             Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main116 T1
             I
             K1
             L1
             I1
             P
             K2
             O1
             O
             M1
             V1
             F
             U1
             A
             K
             U
             J2
             X
             E
             G1
             C1
             R
             E1
             F1
             Y1
             E2
             D2
             Z
             D
             N1
             M
             H2
             W
             A1
             C
             V
             Q
             G2
             T
             A2
             H
             B2
             I2
             Q1
             L
             F2
             G
             C2
             J1
             S
             R1
             X1
             B1
             H1
             P1
             D1
             N
             W1
             S1
             J
             B
             Y)
        (and (not (= P 12292))
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
     (= P 8496)
     (<= 0 W1)
     (<= 0 S1)
     (<= 0 Y)
     (<= 0 V)
     (<= 0 Q)
     (<= 0 N)
     (<= 0 J)
     (<= 0 C)
     (not (= P1 1))
     (= v_63 P))
      )
      (inv_main270 T1
             I
             K1
             L1
             I1
             P
             K2
             O1
             O
             M1
             V1
             F
             U1
             A
             K
             U
             J2
             X
             E
             G1
             C1
             R
             E1
             F1
             Y1
             E2
             D2
             Z
             D
             N1
             M
             H2
             W
             A1
             C
             V
             Q
             G2
             T
             Z1
             H
             v_63
             I2
             Q1
             L
             F2
             G
             C2
             J1
             S
             R1
             X1
             B1
             H1
             P1
             D1
             N
             W1
             S1
             J
             B
             Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main116 B
             Q
             F
             H
             G1
             C2
             B2
             W
             N
             Y
             F2
             B1
             G2
             P1
             Y1
             R
             L
             X
             U
             K
             J1
             T1
             K2
             E
             V
             G
             H2
             A1
             A2
             C1
             J
             I1
             E1
             Q1
             V1
             N1
             S1
             L1
             P
             E2
             D1
             W1
             I2
             X1
             L2
             U1
             R1
             T
             F1
             Z
             M
             I
             M1
             A
             H1
             K1
             D
             O1
             Z1
             D2
             O
             C)
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
     (not (= C2 8496))
     (= C2 8497)
     (= H1 1)
     (= S 2)
     (<= 0 D2)
     (<= 0 Z1)
     (<= 0 V1)
     (<= 0 S1)
     (<= 0 O1)
     (<= 0 N1)
     (<= 0 D)
     (<= 0 C)
     (not (= C2 12292))
     (= v_64 C2))
      )
      (inv_main270 B
             Q
             F
             H
             G1
             C2
             B2
             W
             N
             Y
             F2
             B1
             G2
             P1
             Y1
             R
             L
             X
             U
             K
             J1
             T1
             K2
             E
             V
             G
             H2
             A1
             A2
             C1
             J
             I1
             E1
             Q1
             V1
             N1
             S1
             L1
             P
             J2
             D1
             v_64
             I2
             X1
             L2
             U1
             R1
             T
             F1
             Z
             M
             I
             M1
             A
             S
             K1
             D
             O1
             Z1
             D2
             O
             C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main116 M
             M1
             C
             K2
             B2
             I1
             X
             T
             E
             H2
             T1
             L
             A2
             H1
             W
             O
             Z
             R
             V
             G
             Y1
             P
             J1
             J2
             F
             U1
             I
             D2
             I2
             U
             D
             O1
             S
             F2
             A1
             S1
             K
             G2
             B1
             F1
             V1
             E1
             L1
             W1
             Z1
             H
             B
             C2
             A
             Y
             D1
             Q
             E2
             R1
             X1
             K1
             N1
             C1
             P1
             J
             G1
             Q1)
        (and (not (= I1 12292))
     (not (= I1 16384))
     (not (= I1 8192))
     (not (= I1 24576))
     (not (= I1 8195))
     (not (= I1 8480))
     (not (= I1 8481))
     (not (= I1 8482))
     (not (= I1 8464))
     (not (= I1 8465))
     (not (= I1 8466))
     (not (= I1 8496))
     (= I1 8497)
     (<= 0 S1)
     (<= 0 Q1)
     (<= 0 P1)
     (<= 0 N1)
     (<= 0 C1)
     (<= 0 A1)
     (<= 0 K)
     (<= 0 J)
     (not (= X1 1))
     (= v_63 I1))
      )
      (inv_main270 M
             M1
             C
             K2
             B2
             I1
             X
             T
             E
             H2
             T1
             L
             A2
             H1
             W
             O
             Z
             R
             V
             G
             Y1
             P
             J1
             J2
             F
             U1
             I
             D2
             I2
             U
             D
             O1
             S
             F2
             A1
             S1
             K
             G2
             B1
             N
             V1
             v_63
             L1
             W1
             Z1
             H
             B
             C2
             A
             Y
             D1
             Q
             E2
             R1
             X1
             K1
             N1
             C1
             P1
             J
             G1
             Q1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main116 Q
             A
             J
             U
             X1
             D
             K
             R1
             B
             Y
             I2
             V
             L
             G2
             H1
             D1
             M1
             M
             W
             C2
             L1
             I1
             Y1
             D2
             E
             Z
             G
             K1
             V1
             B2
             W1
             H2
             O1
             S
             I
             O
             R
             H
             A1
             C
             A2
             F2
             J1
             S1
             B1
             N
             Q1
             F
             G1
             E1
             U1
             T1
             J2
             E2
             P
             N1
             C1
             F1
             T
             P1
             X
             Z1)
        (and (not (= D 8529))
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
     (<= 0 Z1)
     (<= 0 P1)
     (<= 0 F1)
     (<= 0 C1)
     (<= 0 T)
     (<= 0 R)
     (<= 0 O)
     (<= 0 I)
     (= D 8544)
     (= v_62 D))
      )
      (inv_main328 Q
             A
             J
             U
             X1
             D
             K
             R1
             B
             Y
             I2
             V
             L
             G2
             H1
             D1
             M1
             M
             W
             C2
             L1
             I1
             Y1
             D2
             E
             Z
             G
             K1
             V1
             B2
             W1
             H2
             O1
             S
             I
             O
             R
             H
             A1
             C
             A2
             v_62
             J1
             S1
             B1
             N
             Q1
             F
             G1
             E1
             U1
             T1
             J2
             E2
             P
             N1
             C1
             F1
             T
             P1
             X
             Z1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main116 T
             C
             H1
             U1
             D2
             U
             D1
             X1
             A
             W1
             S1
             L1
             G1
             Y1
             O1
             I2
             H2
             R1
             H
             J
             Z1
             E1
             C2
             L
             E
             O
             B
             V1
             K1
             R
             A1
             P1
             J2
             X
             Z
             C1
             B1
             G2
             V
             J1
             F2
             S
             K
             N1
             T1
             N
             B2
             D
             M
             F1
             E2
             F
             Q
             I1
             I
             Q1
             Y
             P
             G
             W
             A2
             M1)
        (and (not (= U 8544))
     (not (= U 8529))
     (not (= U 12292))
     (not (= U 16384))
     (not (= U 8192))
     (not (= U 24576))
     (not (= U 8195))
     (not (= U 8480))
     (not (= U 8481))
     (not (= U 8482))
     (not (= U 8464))
     (not (= U 8465))
     (not (= U 8466))
     (not (= U 8496))
     (not (= U 8497))
     (not (= U 8512))
     (not (= U 8513))
     (not (= U 8528))
     (<= 0 M1)
     (<= 0 C1)
     (<= 0 B1)
     (<= 0 Z)
     (<= 0 Y)
     (<= 0 W)
     (<= 0 P)
     (<= 0 G)
     (= U 8545)
     (= v_62 U))
      )
      (inv_main328 T
             C
             H1
             U1
             D2
             U
             D1
             X1
             A
             W1
             S1
             L1
             G1
             Y1
             O1
             I2
             H2
             R1
             H
             J
             Z1
             E1
             C2
             L
             E
             O
             B
             V1
             K1
             R
             A1
             P1
             J2
             X
             Z
             C1
             B1
             G2
             V
             J1
             F2
             v_62
             K
             N1
             T1
             N
             B2
             D
             M
             F1
             E2
             F
             Q
             I1
             I
             Q1
             Y
             P
             G
             W
             A2
             M1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main197 Z1
             X
             K1
             C
             J
             C2
             F
             M
             W
             V
             A2
             U1
             Q
             A1
             E1
             Y
             T1
             E
             S
             G
             B
             R
             J1
             Y1
             I
             D2
             A
             O
             Q1
             I2
             P
             K
             H2
             G2
             N
             J2
             Z
             B1
             H
             S1
             U
             G1
             D
             M1
             P1
             I1
             L
             H1
             F1
             R1
             T
             C1
             E2
             L1
             D1
             F2
             V1
             N1
             X1
             W1
             O1
             B2)
        (and (= D 0)
     (= A 0)
     (<= 0 B2)
     (<= 0 X1)
     (<= 0 W1)
     (<= 0 V1)
     (<= 0 N1)
     (<= 0 Z)
     (<= 0 N)
     (<= 0 J2)
     (not (= G1 8464)))
      )
      (inv_main487 Z1
             X
             K1
             C
             J
             C2
             F
             M
             W
             V
             A2
             U1
             Q
             A1
             E1
             Y
             T1
             E
             S
             G
             B
             R
             J1
             Y1
             I
             D2
             A
             O
             Q1
             I2
             P
             K
             H2
             G2
             N
             J2
             Z
             B1
             H
             S1
             U
             G1
             D
             M1
             P1
             I1
             L
             H1
             F1
             R1
             T
             C1
             E2
             L1
             D1
             F2
             V1
             N1
             X1
             W1
             O1
             B2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main197 F2
             T
             L
             J1
             X
             V
             R
             G
             P1
             P
             K
             M1
             T1
             E2
             L1
             C1
             D1
             Y1
             G1
             F1
             I
             J
             D2
             E
             Q
             W
             G2
             F
             Q1
             N
             N1
             J2
             D
             B2
             W1
             O1
             V1
             O
             H
             K1
             C
             B
             B1
             Y
             I1
             E1
             A1
             C2
             I2
             H1
             A2
             U1
             A
             Z1
             R1
             Z
             H2
             M
             X1
             S1
             S
             U)
        (and (= B1 0)
     (not (= V 8496))
     (= B 8464)
     (<= 0 H2)
     (<= 0 X1)
     (<= 0 W1)
     (<= 0 V1)
     (<= 0 S1)
     (<= 0 O1)
     (<= 0 U)
     (<= 0 M)
     (= G2 0))
      )
      (inv_main487 F2
             T
             L
             J1
             X
             V
             R
             G
             P1
             P
             K
             M1
             T1
             E2
             L1
             C1
             D1
             Y1
             G1
             F1
             I
             J
             D2
             E
             Q
             W
             G2
             F
             Q1
             N
             N1
             J2
             D
             B2
             W1
             O1
             V1
             O
             H
             K1
             C
             B
             B1
             Y
             I1
             E1
             A1
             C2
             I2
             H1
             A2
             U1
             A
             Z1
             R1
             Z
             H2
             M
             X1
             S1
             S
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main197 Q1
             A2
             U
             C1
             R1
             X1
             U1
             B1
             N1
             P
             G2
             C
             D2
             K1
             G1
             L1
             S1
             E
             F1
             J1
             I
             D
             F
             I2
             B2
             P1
             A1
             T
             E1
             T1
             A
             S
             H2
             Z1
             D1
             W
             O1
             Z
             H1
             B
             J2
             G
             K
             I1
             X
             R
             Y1
             C2
             M1
             Q
             H
             J
             M
             W1
             O
             Y
             L
             N
             V1
             F2
             E2
             V)
        (and (= A1 0)
     (= Z 0)
     (= K 0)
     (= G 8464)
     (<= 0 F2)
     (<= 0 V1)
     (<= 0 O1)
     (<= 0 D1)
     (<= 0 W)
     (<= 0 V)
     (<= 0 N)
     (<= 0 L)
     (= X1 8496))
      )
      (inv_main487 Q1
             A2
             U
             C1
             R1
             X1
             U1
             B1
             N1
             P
             G2
             C
             D2
             K1
             G1
             L1
             S1
             E
             F1
             J1
             I
             D
             F
             I2
             B2
             P1
             A1
             T
             E1
             T1
             A
             S
             H2
             Z1
             D1
             W
             O1
             Z
             H1
             B
             J2
             G
             K
             I1
             X
             R
             Y1
             C2
             M1
             Q
             H
             J
             M
             W1
             O
             Y
             L
             N
             V1
             F2
             E2
             V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main197 G1
             E2
             F2
             B2
             Y1
             Q
             B1
             P1
             E1
             J
             F1
             R1
             Z
             H
             C
             M
             S
             G2
             W
             D1
             H1
             N1
             F
             X
             T1
             R
             E
             D2
             X1
             V1
             U1
             I1
             V
             P
             Z1
             J2
             G
             C2
             L1
             M1
             A2
             A1
             W1
             D
             H2
             C1
             I2
             T
             I
             O1
             O
             U
             Q1
             N
             K1
             A
             L
             B
             Y
             J1
             K
             S1)
        (and (= B2 0)
     (= W1 0)
     (= A1 8464)
     (= Q 8496)
     (= E 0)
     (<= 0 Z1)
     (<= 0 S1)
     (<= 0 J1)
     (<= 0 Y)
     (<= 0 L)
     (<= 0 G)
     (<= 0 B)
     (<= 0 J2)
     (not (= C2 0)))
      )
      (inv_main487 G1
             E2
             F2
             B2
             Y1
             Q
             B1
             P1
             E1
             J
             F1
             R1
             Z
             H
             C
             M
             S
             G2
             W
             D1
             H1
             N1
             F
             X
             T1
             R
             E
             D2
             X1
             V1
             U1
             I1
             V
             P
             Z1
             J2
             G
             C2
             L1
             M1
             A2
             A1
             W1
             D
             H2
             C1
             I2
             T
             I
             O1
             O
             U
             Q1
             N
             K1
             A
             L
             B
             Y
             J1
             K
             S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main116 G1
             A1
             T
             P
             C
             M
             H
             Y
             I2
             G2
             G
             Z1
             F2
             E
             C1
             N1
             X
             Z
             D2
             A
             O1
             Q1
             V
             K2
             O
             C2
             Y1
             W
             B1
             I1
             L
             S1
             V1
             L1
             D1
             J1
             T1
             H1
             J
             E2
             B2
             H2
             M1
             I
             W1
             F
             A2
             U
             J2
             D
             K
             S
             N
             K1
             R1
             X1
             P1
             F1
             E1
             R
             Q
             U1)
        (and (not (= M 16384))
     (not (= M 8192))
     (not (= M 24576))
     (not (= M 8195))
     (not (= M 8480))
     (not (= M 8481))
     (= M 8482)
     (= B 3)
     (<= 0 U1)
     (<= 0 T1)
     (<= 0 P1)
     (<= 0 J1)
     (<= 0 F1)
     (<= 0 E1)
     (<= 0 D1)
     (<= 0 R)
     (not (= M 12292)))
      )
      (inv_main197 G1
             A1
             T
             P
             C
             B
             H
             Y
             I2
             G2
             G
             Z1
             F2
             E
             C1
             N1
             X
             Z
             D2
             A
             O1
             Q1
             V
             K2
             O
             C2
             Y1
             W
             B1
             I1
             L
             S1
             V1
             L1
             D1
             J1
             T1
             H1
             J
             E2
             B2
             M
             M1
             I
             W1
             F
             A2
             U
             J2
             D
             K
             S
             N
             K1
             R1
             X1
             P1
             F1
             E1
             R
             Q
             U1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main116 G2
             X1
             T1
             J1
             W
             P
             F2
             S1
             B
             I
             G1
             W1
             D
             A2
             C2
             F1
             N
             J
             Q
             V1
             C
             O2
             H1
             V
             A
             U1
             Y
             R
             Z1
             Y1
             C1
             M
             P1
             E2
             K2
             E
             N2
             L1
             E1
             D1
             T
             S
             B2
             N1
             O
             I1
             M2
             H
             G
             X
             R1
             J2
             M1
             O1
             A1
             D2
             K
             U
             I2
             Q1
             Z
             B1)
        (and (= K1 8448)
     (not (= P 12292))
     (not (= P 16384))
     (not (= P 8192))
     (not (= P 24576))
     (not (= P 8195))
     (= P 8480)
     (= L 0)
     (= F 8482)
     (<= 0 K2)
     (<= 0 I2)
     (<= 0 Q1)
     (<= 0 B1)
     (<= 0 U)
     (<= 0 K)
     (<= 0 E)
     (<= 0 N2)
     (not (<= L2 0))
     (= H2 0))
      )
      (inv_main197 G2
             X1
             T1
             J1
             W
             K1
             F2
             S1
             B
             I
             L
             W1
             D
             A2
             C2
             H2
             N
             J
             Q
             V1
             C
             O2
             H1
             V
             A
             U1
             Y
             R
             Z1
             Y1
             F
             M
             P1
             E2
             K2
             E
             N2
             L1
             E1
             L2
             T
             P
             B2
             N1
             O
             I1
             M2
             H
             G
             X
             R1
             J2
             M1
             O1
             A1
             D2
             K
             U
             I2
             Q1
             Z
             B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main116 H1
             A2
             D2
             I1
             K1
             G2
             T
             C
             J1
             U1
             M1
             X
             I2
             B2
             R
             V
             S
             Z1
             G1
             F
             L
             O2
             N2
             Q1
             F1
             H
             J2
             D1
             Z
             C1
             F2
             M2
             Q
             U
             M
             Y
             I
             G
             H2
             E
             W1
             P
             L1
             O1
             O
             K2
             B
             E1
             E2
             R1
             A
             S1
             B1
             J
             K
             D
             P1
             C2
             V1
             N1
             W
             L2)
        (and (not (= G2 16384))
     (not (= G2 8192))
     (not (= G2 24576))
     (not (= G2 8195))
     (not (= G2 8480))
     (= G2 8481)
     (= Y1 0)
     (= T1 8448)
     (= A1 8482)
     (= N 0)
     (<= 0 L2)
     (<= 0 C2)
     (<= 0 V1)
     (<= 0 P1)
     (<= 0 N1)
     (<= 0 Y)
     (<= 0 M)
     (<= 0 I)
     (not (<= X1 0))
     (not (= G2 12292)))
      )
      (inv_main197 H1
             A2
             D2
             I1
             K1
             T1
             T
             C
             J1
             U1
             Y1
             X
             I2
             B2
             R
             N
             S
             Z1
             G1
             F
             L
             O2
             N2
             Q1
             F1
             H
             J2
             D1
             Z
             C1
             A1
             M2
             Q
             U
             M
             Y
             I
             G
             H2
             X1
             W1
             G2
             L1
             O1
             O
             K2
             B
             E1
             E2
             R1
             A
             S1
             B1
             J
             K
             D
             P1
             C2
             V1
             N1
             W
             L2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main116 O
             V
             T1
             G1
             V1
             N1
             H2
             Z
             U1
             B2
             O1
             Y
             Q1
             C1
             J2
             E2
             H
             P1
             L2
             X1
             G
             A1
             E
             I2
             S1
             D1
             M1
             J1
             L1
             M
             L
             W
             U
             S
             G2
             N
             X
             Q
             F1
             A
             E1
             C
             I
             A2
             J
             H1
             K1
             B
             D
             T
             D2
             K
             Z1
             P
             M2
             K2
             C2
             R
             F2
             W1
             R1
             I1)
        (and (= N1 8560)
     (not (= N1 8545))
     (not (= N1 8544))
     (not (= N1 8529))
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
     (= B1 0)
     (= N2 8576)
     (<= 0 G2)
     (<= 0 F2)
     (<= 0 C2)
     (<= 0 W1)
     (<= 0 I1)
     (<= 0 X)
     (<= 0 R)
     (<= 0 N)
     (not (<= F 0))
     (= Y1 8448))
      )
      (inv_main197 O
             V
             T1
             G1
             V1
             Y1
             H2
             Z
             U1
             B2
             B1
             Y
             Q1
             C1
             J2
             E2
             H
             P1
             L2
             X1
             G
             A1
             E
             I2
             S1
             D1
             M1
             J1
             L1
             M
             N2
             W
             U
             S
             G2
             N
             X
             Q
             F1
             F
             E1
             N1
             I
             A2
             J
             H1
             K1
             B
             D
             T
             D2
             K
             Z1
             P
             M2
             K2
             C2
             R
             F2
             W1
             R1
             I1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main116 B
             C1
             J
             V1
             S1
             Q1
             I
             Y1
             H1
             T
             U
             E2
             H
             E
             J1
             E1
             M
             Z1
             N1
             X
             F
             W1
             A
             V
             K2
             J2
             R
             O
             F2
             C2
             N
             U1
             K1
             L1
             G2
             D1
             A2
             P1
             M1
             T1
             H2
             B1
             Y
             L
             A1
             S
             G1
             I2
             G
             D2
             X1
             Z
             F1
             D
             C
             L2
             I1
             Q
             R1
             N2
             B2
             K)
        (and (not (= Q1 8560))
     (not (= Q1 8545))
     (not (= Q1 8544))
     (not (= Q1 8529))
     (not (= Q1 12292))
     (not (= Q1 16384))
     (not (= Q1 8192))
     (not (= Q1 24576))
     (not (= Q1 8195))
     (not (= Q1 8480))
     (not (= Q1 8481))
     (not (= Q1 8482))
     (not (= Q1 8464))
     (not (= Q1 8465))
     (not (= Q1 8466))
     (not (= Q1 8496))
     (not (= Q1 8497))
     (not (= Q1 8512))
     (not (= Q1 8513))
     (not (= Q1 8528))
     (= W 0)
     (= P 8576)
     (= M2 8448)
     (<= 0 G2)
     (<= 0 A2)
     (<= 0 R1)
     (<= 0 I1)
     (<= 0 D1)
     (<= 0 Q)
     (<= 0 K)
     (<= 0 N2)
     (not (<= O1 0))
     (= Q1 8561))
      )
      (inv_main197 B
             C1
             J
             V1
             S1
             M2
             I
             Y1
             H1
             T
             W
             E2
             H
             E
             J1
             E1
             M
             Z1
             N1
             X
             F
             W1
             A
             V
             K2
             J2
             R
             O
             F2
             C2
             P
             U1
             K1
             L1
             G2
             D1
             A2
             P1
             M1
             O1
             H2
             Q1
             Y
             L
             A1
             S
             G1
             I2
             G
             D2
             X1
             Z
             F1
             D
             C
             L2
             I1
             Q
             R1
             N2
             B2
             K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main116 E2
             J2
             X1
             L1
             H
             X
             G2
             B2
             K1
             H1
             W1
             A2
             J
             F2
             T
             G
             Z
             H2
             U
             I
             N
             Q1
             F
             B1
             T1
             V
             M1
             Z1
             A
             B
             D1
             P1
             Y
             L
             Y1
             M2
             I2
             J1
             V1
             L2
             O
             O1
             R
             E
             W
             D
             D2
             R1
             C1
             E1
             M
             S
             N1
             C
             Q
             C2
             K
             A1
             I1
             F1
             K2
             P)
        (and (= S1 8608)
     (not (= X 8577))
     (= X 8592)
     (not (= X 8561))
     (not (= X 8576))
     (not (= X 8560))
     (not (= X 8448))
     (not (= X 8545))
     (not (= X 8544))
     (not (= X 8529))
     (not (= X 12292))
     (not (= X 16384))
     (not (= X 8192))
     (not (= X 24576))
     (not (= X 8195))
     (not (= X 8480))
     (not (= X 8481))
     (not (= X 8482))
     (not (= X 8464))
     (not (= X 8465))
     (not (= X 8466))
     (not (= X 8496))
     (not (= X 8497))
     (not (= X 8512))
     (not (= X 8513))
     (not (= X 8528))
     (<= 0 I2)
     (<= 0 Y1)
     (<= 0 I1)
     (<= 0 F1)
     (<= 0 A1)
     (<= 0 P)
     (<= 0 K)
     (<= 0 M2)
     (not (<= G1 0))
     (= U1 0))
      )
      (inv_main197 E2
             J2
             X1
             L1
             H
             S1
             G2
             B2
             K1
             H1
             U1
             A2
             J
             F2
             T
             G
             Z
             H2
             U
             I
             N
             Q1
             F
             B1
             T1
             V
             M1
             Z1
             A
             B
             D1
             P1
             Y
             L
             Y1
             M2
             I2
             J1
             V1
             G1
             O
             X
             R
             E
             W
             D
             D2
             R1
             C1
             E1
             M
             S
             N1
             C
             Q
             C2
             K
             A1
             I1
             F1
             K2
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main116 Z1
             G1
             N1
             G
             D2
             H1
             F2
             R1
             C1
             S1
             Y1
             R
             K1
             L2
             B1
             S
             X1
             W1
             J1
             M
             L
             F
             A2
             C
             W
             Q1
             A1
             N
             T1
             H2
             Z
             I
             O1
             E
             F1
             Q
             L1
             D1
             Y
             X
             B2
             P
             M1
             E2
             B
             J
             K
             V
             C2
             O
             K2
             U
             A
             G2
             V1
             P1
             D
             J2
             T
             I2
             I1
             U1)
        (and (not (= H1 8577))
     (not (= H1 8592))
     (not (= H1 8561))
     (not (= H1 8576))
     (not (= H1 8560))
     (not (= H1 8448))
     (not (= H1 8545))
     (not (= H1 8544))
     (not (= H1 8529))
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
     (= H 0)
     (= M2 8608)
     (<= 0 J2)
     (<= 0 I2)
     (<= 0 U1)
     (<= 0 L1)
     (<= 0 F1)
     (<= 0 T)
     (<= 0 Q)
     (<= 0 D)
     (not (<= E1 0))
     (= H1 8593))
      )
      (inv_main197 Z1
             G1
             N1
             G
             D2
             M2
             F2
             R1
             C1
             S1
             H
             R
             K1
             L2
             B1
             S
             X1
             W1
             J1
             M
             L
             F
             A2
             C
             W
             Q1
             A1
             N
             T1
             H2
             Z
             I
             O1
             E
             F1
             Q
             L1
             D1
             Y
             E1
             B2
             H1
             M1
             E2
             B
             J
             K
             V
             C2
             O
             K2
             U
             A
             G2
             V1
             P1
             D
             J2
             T
             I2
             I1
             U1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main116 A1
             O
             A
             E2
             J2
             J1
             L2
             G2
             T1
             F2
             X
             K2
             V1
             C
             M1
             N
             U
             K1
             Z
             G
             Y1
             N1
             H
             P
             M
             M2
             S
             W
             R1
             Y
             C2
             I2
             P1
             F1
             G1
             H1
             F
             C1
             U1
             B1
             V
             Z1
             I1
             E
             R
             X1
             D2
             E1
             Q1
             D
             B2
             L
             H2
             S1
             K
             Q
             T
             I
             O1
             W1
             B
             A2)
        (and (not (= J1 8593))
     (= J1 8608)
     (not (= J1 8577))
     (not (= J1 8592))
     (not (= J1 8561))
     (not (= J1 8576))
     (not (= J1 8560))
     (not (= J1 8448))
     (not (= J1 8545))
     (not (= J1 8544))
     (not (= J1 8529))
     (not (= J1 12292))
     (not (= J1 16384))
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
     (not (= J1 8497))
     (not (= J1 8512))
     (not (= J1 8513))
     (not (= J1 8528))
     (= J 0)
     (<= 0 A2)
     (<= 0 W1)
     (<= 0 O1)
     (<= 0 H1)
     (<= 0 G1)
     (<= 0 T)
     (<= 0 I)
     (<= 0 F)
     (not (<= D1 0))
     (= L1 8640))
      )
      (inv_main197 A1
             O
             A
             E2
             J2
             L1
             L2
             G2
             T1
             F2
             J
             K2
             V1
             C
             M1
             N
             U
             K1
             Z
             G
             Y1
             N1
             H
             P
             M
             M2
             S
             W
             R1
             Y
             C2
             I2
             P1
             F1
             G1
             H1
             F
             C1
             U1
             D1
             V
             J1
             I1
             E
             R
             X1
             D2
             E1
             Q1
             D
             B2
             L
             H2
             S1
             K
             Q
             T
             I
             O1
             W1
             B
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main116 J2
             R
             O1
             D2
             U
             A2
             B
             T1
             A
             L2
             Y
             C
             N1
             H1
             I1
             I2
             Q
             K2
             V
             E
             W1
             F2
             M1
             J
             G1
             C2
             K1
             E1
             F
             T
             Z1
             L
             Z
             S
             X
             A1
             S1
             M2
             Y1
             G
             I
             C1
             F1
             E2
             J1
             H
             N
             P1
             U1
             G2
             R1
             L1
             M
             B2
             W
             D1
             B1
             K
             V1
             X1
             P
             D)
        (and (= A2 8609)
     (not (= A2 8593))
     (not (= A2 8608))
     (not (= A2 8577))
     (not (= A2 8592))
     (not (= A2 8561))
     (not (= A2 8576))
     (not (= A2 8560))
     (not (= A2 8448))
     (not (= A2 8545))
     (not (= A2 8544))
     (not (= A2 8529))
     (not (= A2 12292))
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
     (not (= A2 8512))
     (not (= A2 8513))
     (not (= A2 8528))
     (= Q1 8640)
     (<= 0 X1)
     (<= 0 V1)
     (<= 0 S1)
     (<= 0 B1)
     (<= 0 A1)
     (<= 0 X)
     (<= 0 K)
     (<= 0 D)
     (not (<= O 0))
     (= H2 0))
      )
      (inv_main197 J2
             R
             O1
             D2
             U
             Q1
             B
             T1
             A
             L2
             H2
             C
             N1
             H1
             I1
             I2
             Q
             K2
             V
             E
             W1
             F2
             M1
             J
             G1
             C2
             K1
             E1
             F
             T
             Z1
             L
             Z
             S
             X
             A1
             S1
             M2
             Y1
             O
             I
             A2
             F1
             E2
             J1
             H
             N
             P1
             U1
             G2
             R1
             L1
             M
             B2
             W
             D1
             B1
             K
             V1
             X1
             P
             D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main253 X1
             K1
             W
             I1
             P2
             B1
             P
             G
             L2
             F1
             S1
             D2
             F
             T
             D
             B
             T1
             H1
             A
             G1
             J
             Z1
             R1
             K2
             J2
             N1
             N
             C2
             W1
             M1
             P1
             C
             Y
             M
             I2
             E
             A2
             N2
             U
             K
             Q
             X
             E2
             O1
             F2
             E1
             D1
             G2
             R
             C1
             I
             S
             M2
             V
             Q1
             J1
             Z
             L
             A1
             B2
             V1
             L1)
        (and (= Y1 8496)
     (= U1 1)
     (= Q1 0)
     (= O 1)
     (= H 0)
     (<= 0 E)
     (<= 0 I2)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 L1)
     (<= 0 A1)
     (<= 0 Z)
     (<= 0 L)
     (not (<= O2 0))
     (= H2 0))
      )
      (inv_main197 X1
             K1
             W
             I1
             P2
             Y1
             P
             G
             L2
             F1
             H
             D2
             F
             T
             D
             H2
             T1
             H1
             A
             G1
             J
             Z1
             R1
             K2
             J2
             N1
             N
             C2
             W1
             M1
             P1
             C
             Y
             M
             I2
             E
             A2
             N2
             U
             O2
             Q
             X
             E2
             O
             F2
             E1
             D1
             G2
             R
             C1
             I
             S
             M2
             V
             U1
             J1
             Z
             L
             A1
             B2
             V1
             L1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main253 J1
             H
             O1
             A
             J
             K1
             M2
             V1
             D
             F2
             P1
             R1
             C
             A2
             Z1
             L
             Q
             S1
             S
             R
             F1
             Y1
             I1
             G1
             V
             U
             M1
             H2
             G
             L1
             L2
             J2
             O
             Y
             N1
             T1
             K
             E
             D1
             B2
             U1
             N
             P
             M
             Z
             B1
             Q1
             X
             K2
             W
             T
             E1
             O2
             C1
             H1
             A1
             B
             G2
             F
             E2
             X1
             N2)
        (and (= C2 8496)
     (= W1 0)
     (not (= H1 0))
     (= I 1)
     (<= 0 B)
     (<= 0 G2)
     (<= 0 E2)
     (<= 0 T1)
     (<= 0 N1)
     (<= 0 K)
     (<= 0 F)
     (<= 0 N2)
     (not (<= D2 0))
     (= I2 0))
      )
      (inv_main197 J1
             H
             O1
             A
             J
             C2
             M2
             V1
             D
             F2
             I2
             R1
             C
             A2
             Z1
             W1
             Q
             S1
             S
             R
             F1
             Y1
             I1
             G1
             V
             U
             M1
             H2
             G
             L1
             L2
             J2
             O
             Y
             N1
             T1
             K
             E
             D1
             D2
             U1
             N
             P
             I
             Z
             B1
             Q1
             X
             K2
             W
             T
             E1
             O2
             C1
             H1
             A1
             B
             G2
             F
             E2
             X1
             N2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main270 Q1
             G2
             V1
             S
             M1
             N
             N1
             R
             W
             F
             P1
             L2
             H1
             I
             C
             G1
             E1
             I2
             L
             P
             K
             J1
             Z
             X
             M
             V
             D2
             L1
             Y
             F1
             T1
             O1
             E
             Q
             W1
             J2
             A1
             Z1
             B
             H2
             I1
             J
             G
             H
             S1
             D
             E2
             Y1
             C2
             U
             U1
             A2
             B1
             D1
             O
             B2
             K1
             K2
             R1
             C1
             F2
             X1)
        (and (= T 0)
     (not (= L2 0))
     (<= 0 J2)
     (<= 0 X1)
     (<= 0 W1)
     (<= 0 R1)
     (<= 0 K1)
     (<= 0 C1)
     (<= 0 A1)
     (<= 0 K2)
     (not (<= H2 0))
     (= A 8656))
      )
      (inv_main197 Q1
             G2
             V1
             S
             M1
             A
             N1
             R
             W
             F
             T
             L2
             H1
             I
             C
             G1
             E1
             I2
             L
             P
             K
             J1
             Z
             X
             M
             V
             D2
             L1
             Y
             F1
             T1
             O1
             E
             Q
             W1
             J2
             A1
             Z1
             B
             H2
             I1
             J
             G
             H
             S1
             D
             E2
             Y1
             C2
             U
             U1
             A2
             B1
             D1
             O
             B2
             K1
             K2
             R1
             C1
             F2
             X1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main270 Q1
             I2
             B
             D
             Y
             O1
             I
             J2
             N
             X1
             H1
             C2
             H2
             Y1
             S1
             K1
             P
             T1
             D1
             V1
             J1
             V
             U
             L1
             Z1
             X
             L
             K2
             A1
             A2
             I1
             R
             E1
             S
             K
             W1
             T
             M1
             Q
             J
             B2
             F1
             F2
             M
             B1
             N1
             U1
             C1
             L2
             W
             E2
             C
             P1
             G
             R1
             A
             G2
             F
             O
             G1
             D2
             E)
        (and (= Z 8512)
     (= H 0)
     (<= 0 G2)
     (<= 0 W1)
     (<= 0 G1)
     (<= 0 T)
     (<= 0 O)
     (<= 0 K)
     (<= 0 F)
     (<= 0 E)
     (not (<= J 0))
     (= C2 0))
      )
      (inv_main197 Q1
             I2
             B
             D
             Y
             Z
             I
             J2
             N
             X1
             H
             C2
             H2
             Y1
             S1
             K1
             P
             T1
             D1
             V1
             J1
             V
             U
             L1
             Z1
             X
             L
             K2
             A1
             A2
             I1
             R
             E1
             S
             K
             W1
             T
             M1
             Q
             J
             B2
             F1
             F2
             M
             B1
             N1
             U1
             C1
             L2
             W
             E2
             C
             P1
             G
             R1
             A
             G2
             F
             O
             G1
             D2
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main116 D1
             K1
             A2
             H1
             O
             G2
             X
             P
             W
             T
             G
             U
             A
             T1
             K
             N1
             N
             M
             M1
             S
             D2
             E1
             Y1
             V
             K2
             H2
             B
             L1
             J2
             I
             O1
             J
             F2
             X1
             E
             Z1
             I1
             Y
             B1
             C1
             W1
             C2
             C
             D
             R1
             L
             G1
             Q
             V1
             B2
             U1
             A1
             Q1
             S1
             F
             J1
             E2
             I2
             R
             P1
             H
             Z)
        (and (not (= G2 8560))
     (= G2 8448)
     (not (= G2 8545))
     (not (= G2 8544))
     (not (= G2 8529))
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
     (not (<= 1 F1))
     (<= 0 I2)
     (<= 0 E2)
     (<= 0 Z1)
     (<= 0 P1)
     (<= 0 I1)
     (<= 0 Z)
     (<= 0 R)
     (<= 0 E)
     (not (= G2 8561))
     (= v_63 O1))
      )
      (inv_main197 D1
             K1
             A2
             H1
             O
             O1
             X
             P
             W
             T
             G
             U
             A
             T1
             K
             N1
             N
             M
             M1
             S
             D2
             E1
             Y1
             V
             K2
             H2
             B
             L1
             J2
             I
             v_63
             J
             F2
             X1
             E
             Z1
             I1
             Y
             F1
             C1
             W1
             G2
             C
             D
             R1
             L
             G1
             Q
             V1
             B2
             U1
             A1
             Q1
             S1
             F
             J1
             E2
             I2
             R
             P1
             H
             Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main116 R1
             A
             D2
             P
             M
             X
             U
             D1
             Y
             N
             V
             L
             F
             W
             J1
             K
             B2
             H1
             S
             O
             D
             I1
             P1
             E2
             F2
             N1
             A2
             L2
             V1
             B
             G1
             G
             T
             J2
             Q
             Q1
             G2
             J
             X1
             C2
             M1
             E
             C1
             H2
             K1
             I
             E1
             I2
             B1
             Y1
             K2
             L1
             R
             O1
             W1
             S1
             H
             A1
             Z
             U1
             C
             F1)
        (and (not (= X 8561))
     (not (= X 8560))
     (= X 8448)
     (not (= X 8545))
     (not (= X 8544))
     (not (= X 8529))
     (not (= X 12292))
     (not (= X 16384))
     (not (= X 8192))
     (not (= X 24576))
     (not (= X 8195))
     (not (= X 8480))
     (not (= X 8481))
     (not (= X 8482))
     (not (= X 8464))
     (not (= X 8465))
     (not (= X 8466))
     (not (= X 8496))
     (not (= X 8497))
     (not (= X 8512))
     (not (= X 8513))
     (not (= X 8528))
     (<= 1 Z1)
     (<= 0 G2)
     (<= 0 U1)
     (<= 0 Q1)
     (<= 0 F1)
     (<= 0 A1)
     (<= 0 Z)
     (<= 0 Q)
     (<= 0 H)
     (not (<= L1 0))
     (= T1 1)
     (= v_64 G1)
     (= v_65 L1))
      )
      (inv_main197 R1
             A
             D2
             P
             M
             G1
             U
             D1
             Y
             N
             V
             L
             T1
             W
             J1
             K
             B2
             H1
             S
             O
             D
             I1
             P1
             E2
             F2
             N1
             A2
             L2
             V1
             B
             v_64
             G
             T
             J2
             Q
             Q1
             G2
             J
             L1
             C2
             M1
             X
             C1
             H2
             K1
             I
             E1
             I2
             B1
             Y1
             K2
             v_65
             R
             O1
             W1
             S1
             H
             A1
             Z
             U1
             C
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main417 S1
             J
             N
             L
             V
             H2
             M
             Y
             J1
             K1
             K2
             U
             D
             N1
             V1
             Q
             G1
             K
             I1
             L1
             L2
             H1
             P1
             O1
             S
             W1
             F2
             D1
             H
             T
             J2
             E2
             B2
             A1
             G2
             I2
             W
             C
             C2
             B
             X1
             O
             I
             M1
             F1
             A2
             G
             Y1
             Z
             Z1
             P
             D2
             F
             R
             Q1
             E1
             A
             R1
             U1
             T1
             C1
             X)
        (and (not (= U 0))
     (= E 0)
     (<= 0 A)
     (<= 0 I2)
     (<= 0 G2)
     (<= 0 U1)
     (<= 0 T1)
     (<= 0 R1)
     (<= 0 X)
     (<= 0 W)
     (not (<= B 0))
     (= B1 3))
      )
      (inv_main197 S1
             J
             N
             L
             V
             B1
             M
             Y
             J1
             K1
             E
             U
             D
             N1
             V1
             Q
             G1
             K
             I1
             L1
             L2
             H1
             P1
             O1
             S
             W1
             F2
             D1
             H
             T
             J2
             E2
             B2
             A1
             G2
             I2
             W
             C
             C2
             B
             X1
             O
             I
             M1
             F1
             A2
             G
             Y1
             Z
             Z1
             P
             D2
             F
             R
             Q1
             E1
             A
             R1
             U1
             T1
             C1
             X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main417 U1
             L
             Q
             A1
             W1
             D
             G1
             C1
             N1
             V1
             T
             F1
             M1
             I
             A2
             B2
             K2
             K
             C
             I2
             E1
             S
             Y
             G2
             Q1
             L1
             W
             T1
             S1
             K1
             N
             O
             B
             M
             U
             P1
             J1
             E
             J
             Z1
             R
             O1
             G
             H1
             A
             Y1
             R1
             X
             P
             F
             C2
             F2
             J2
             Z
             H
             L2
             E2
             H2
             I1
             V
             B1
             X1)
        (and (= F1 0)
     (= D1 0)
     (<= 0 H2)
     (<= 0 E2)
     (<= 0 X1)
     (<= 0 P1)
     (<= 0 J1)
     (<= 0 I1)
     (<= 0 V)
     (<= 0 U)
     (not (<= Z1 0))
     (= D2 8656))
      )
      (inv_main197 U1
             L
             Q
             A1
             W1
             D2
             G1
             C1
             N1
             V1
             D1
             F1
             M1
             I
             A2
             B2
             K2
             K
             C
             I2
             E1
             S
             Y
             G2
             Q1
             L1
             W
             T1
             S1
             K1
             N
             O
             B
             M
             U
             P1
             J1
             E
             J
             Z1
             R
             O1
             G
             H1
             A
             Y1
             R1
             X
             P
             F
             C2
             F2
             J2
             Z
             H
             L2
             E2
             H2
             I1
             V
             B1
             X1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main296 L1
             E2
             F1
             K
             O1
             E
             C2
             J1
             C1
             H2
             J2
             R1
             I2
             I
             Z
             N1
             J
             M1
             V
             Z1
             A1
             R
             U
             S1
             B
             B1
             C
             M
             Y1
             L2
             M2
             D
             Q1
             F
             T
             X
             A
             Q
             V1
             P
             S
             I1
             N
             O
             D2
             E1
             W
             X1
             H
             K1
             D1
             A2
             G
             Y
             P1
             G2
             K2
             F2
             H1
             U1
             B2
             W1)
        (and (= G1 0)
     (= T (- 30))
     (= T (- 1))
     (= M 0)
     (= L 1)
     (<= 0 A)
     (<= 0 K2)
     (<= 0 F2)
     (<= 0 W1)
     (<= 0 U1)
     (<= 0 H1)
     (<= 0 X)
     (<= 0 T)
     (= T1 8544))
      )
      (inv_main197 L1
             E2
             F1
             K
             O1
             T1
             C2
             J1
             C1
             H2
             G1
             R1
             I2
             I
             Z
             N1
             J
             M1
             V
             Z1
             A1
             R
             U
             S1
             B
             B1
             C
             M
             Y1
             L2
             M2
             D
             Q1
             F
             T
             X
             A
             Q
             V1
             P
             S
             I1
             L
             O
             D2
             E1
             W
             X1
             H
             K1
             D1
             A2
             G
             Y
             P1
             G2
             K2
             F2
             H1
             U1
             B2
             W1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main296 E1
             G1
             A
             B2
             V
             S1
             W
             M1
             P1
             K
             K1
             X
             L
             D
             F2
             J2
             P
             T1
             C1
             T
             L1
             R1
             H1
             V1
             C
             B
             Z
             A1
             D1
             L2
             H2
             K2
             G2
             E2
             Z1
             U1
             E
             F
             J1
             Q1
             S
             O
             H
             I
             Y
             Q
             W1
             B1
             F1
             O1
             N1
             U
             M2
             G
             X1
             I2
             R
             C2
             Y1
             D2
             J
             N)
        (and (= A2 8544)
     (= Z1 (- 30))
     (not (= Z1 (- 1)))
     (not (= L1 0))
     (= I1 1)
     (= A1 0)
     (= M 0)
     (<= 0 D2)
     (<= 0 C2)
     (<= 0 Z1)
     (<= 0 Y1)
     (<= 0 U1)
     (<= 0 R)
     (<= 0 N)
     (<= 0 E)
     (= K2 (- 2))
     (= v_65 K2))
      )
      (inv_main197 E1
             G1
             A
             B2
             V
             A2
             W
             M1
             P1
             K
             M
             X
             L
             D
             F2
             J2
             P
             T1
             C1
             T
             L1
             R1
             H1
             V1
             C
             B
             Z
             A1
             D1
             L2
             H2
             K2
             G2
             E2
             Z1
             U1
             E
             F
             J1
             Q1
             S
             O
             I1
             I
             Y
             Q
             W1
             B1
             F1
             O1
             N1
             U
             M2
             G
             X1
             I2
             R
             C2
             v_65
             D2
             J
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main296 P2
             I2
             O2
             B1
             F
             N1
             A1
             N
             X1
             V1
             R1
             L2
             O
             A2
             Z
             S1
             C2
             Y1
             E
             K2
             U
             B2
             Q
             S
             G1
             Y
             J2
             M1
             X
             K
             D1
             I
             E2
             F2
             T
             W
             B
             H2
             G2
             D2
             Q1
             A
             T1
             D
             R
             V
             H1
             K1
             H
             I1
             P
             E1
             Z1
             M2
             M
             G
             L1
             L
             C
             O1
             U1
             J)
        (and (= N2 1)
     (= W1 512)
     (= M1 0)
     (= J1 0)
     (= F1 8544)
     (not (= U 0))
     (= T (- 30))
     (not (= T (- 1)))
     (not (= I (- 4)))
     (not (= I (- 2)))
     (not (>= P1 65))
     (<= 0 C)
     (<= 0 B)
     (<= 0 O1)
     (<= 0 L1)
     (<= 0 W)
     (<= 0 T)
     (<= 0 L)
     (<= 0 J)
     (= (+ C1 (* (- 8) P1)) 0)
     (= v_68 I)
     (= v_69 I))
      )
      (inv_main197 P2
             I2
             O2
             B1
             F
             F1
             A1
             N
             X1
             V1
             J1
             L2
             O
             A2
             Z
             S1
             C2
             Y1
             E
             K2
             U
             B2
             Q
             S
             G1
             Y
             J2
             M1
             X
             K
             D1
             I
             E2
             F2
             T
             W
             B
             H2
             G2
             D2
             Q1
             A
             N2
             D
             R
             V
             H1
             K1
             H
             P1
             W1
             E1
             Z1
             M2
             M
             G
             L1
             L
             v_68
             v_69
             C1
             J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main296 O1
             Y1
             S
             G1
             E1
             U1
             W1
             O2
             S1
             C2
             L2
             J1
             X
             D
             W
             G2
             B
             G
             F1
             H2
             K
             A
             P1
             R1
             I2
             B2
             H
             M
             V
             A1
             Y
             U
             H1
             X1
             M2
             P2
             P
             V1
             F
             J2
             R
             B1
             Z
             O
             A2
             T
             T1
             C
             L
             K1
             N2
             Q
             I
             L1
             E2
             Q1
             F2
             D2
             I1
             J
             C1
             Z1)
        (and (= E 8544)
     (= M2 (- 30))
     (not (= M2 (- 1)))
     (= N1 0)
     (= D1 1)
     (= U (- 4))
     (not (= U (- 2)))
     (= N 1024)
     (= M 0)
     (not (= K 0))
     (not (>= K2 129))
     (<= 0 M2)
     (<= 0 F2)
     (<= 0 D2)
     (<= 0 Z1)
     (<= 0 I1)
     (<= 0 P)
     (<= 0 J)
     (<= 0 P2)
     (= (+ M1 (* (- 8) K2)) 0)
     (= v_68 U)
     (= v_69 U))
      )
      (inv_main197 O1
             Y1
             S
             G1
             E1
             E
             W1
             O2
             S1
             C2
             N1
             J1
             X
             D
             W
             G2
             B
             G
             F1
             H2
             K
             A
             P1
             R1
             I2
             B2
             H
             M
             V
             A1
             Y
             U
             H1
             X1
             M2
             P2
             P
             V1
             F
             J2
             R
             B1
             D1
             O
             A2
             T
             T1
             C
             L
             K2
             N
             Q
             I
             L1
             E2
             Q1
             F2
             D2
             v_68
             v_69
             M1
             Z1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main328 Z
             T1
             R1
             M1
             L1
             H2
             G2
             W1
             X
             H
             H1
             K1
             Q
             Y1
             A1
             Z1
             S1
             G
             Y
             V
             T
             I
             B2
             G1
             O1
             B1
             W
             K
             L
             P
             E
             D
             Q1
             X1
             N1
             F1
             C
             I2
             E1
             E2
             D1
             L2
             J1
             O
             I1
             D2
             C2
             U
             F2
             P1
             S
             F
             A2
             C1
             J2
             J
             M2
             V1
             A
             R
             N
             K2)
        (and (= U1 8560)
     (not (= Y (- 4)))
     (not (= Y (- 1)))
     (not (= V 0))
     (= M 0)
     (<= 0 A)
     (<= 0 K2)
     (<= 0 V1)
     (<= 0 N1)
     (<= 0 F1)
     (<= 0 R)
     (<= 0 C)
     (<= 0 M2)
     (= B 1))
      )
      (inv_main197 Z
             T1
             R1
             M1
             L1
             U1
             G2
             W1
             X
             H
             H1
             K1
             Q
             Y1
             A1
             Z1
             S1
             G
             Y
             V
             T
             I
             B2
             G1
             O1
             M
             W
             K
             L
             P
             E
             D
             Q1
             X1
             N1
             F1
             C
             I2
             E1
             E2
             D1
             L2
             B
             O
             I1
             D2
             C2
             U
             F2
             P1
             S
             F
             A2
             C1
             J2
             J
             M2
             V1
             A
             R
             N
             K2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main334 Z
             S1
             N
             D
             D2
             C
             E2
             A2
             H1
             F1
             G2
             V1
             M1
             O
             Q
             N1
             F2
             W
             B2
             S
             J2
             I
             E
             L2
             K2
             T1
             I1
             R1
             M
             H
             F
             H2
             G
             M2
             B
             G1
             X
             L
             P
             C1
             T
             Y
             X1
             W1
             K1
             Z1
             A1
             C2
             B1
             U1
             D1
             O1
             Q1
             E1
             R
             Y1
             I2
             K
             U
             A
             L1
             J)
        (and (= P1 1)
     (= J1 8560)
     (= V 0)
     (not (= H (- 256)))
     (<= 0 A)
     (<= 0 B)
     (<= 0 I2)
     (<= 0 G1)
     (<= 0 X)
     (<= 0 U)
     (<= 0 K)
     (<= 0 J)
     (= B2 (- 2))
     (= v_65 H))
      )
      (inv_main197 Z
             S1
             N
             D
             D2
             J1
             E2
             A2
             H1
             F1
             G2
             V1
             M1
             O
             Q
             N1
             F2
             W
             B2
             S
             J2
             I
             E
             L2
             K2
             V
             I1
             R1
             M
             H
             F
             H2
             G
             M2
             B
             G1
             X
             L
             P
             C1
             T
             Y
             P1
             W1
             K1
             Z1
             A1
             C2
             B1
             U1
             D1
             O1
             Q1
             E1
             R
             Y1
             I2
             K
             U
             A
             L1
             v_65)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main328 H2
             J2
             D
             R1
             S1
             V1
             U1
             Y
             L
             H1
             M2
             O
             K2
             J
             I
             G
             O1
             L1
             R
             W
             Q1
             P1
             Z
             H
             C1
             B2
             X1
             L2
             T1
             A2
             F2
             B1
             V
             J1
             X
             W1
             M1
             I2
             Z1
             I1
             E
             F
             U
             Y1
             B
             D1
             Q
             D2
             G1
             S
             N
             E1
             P
             C
             M
             A1
             K
             N1
             T
             K1
             F1
             A)
        (and (= E2 0)
     (= C2 8560)
     (= R (- 1))
     (<= 0 A)
     (<= 0 W1)
     (<= 0 N1)
     (<= 0 M1)
     (<= 0 K1)
     (<= 0 X)
     (<= 0 T)
     (<= 0 K)
     (= G2 1))
      )
      (inv_main197 H2
             J2
             D
             R1
             S1
             C2
             U1
             Y
             L
             H1
             M2
             O
             K2
             J
             I
             G
             O1
             L1
             R
             W
             Q1
             P1
             Z
             H
             C1
             E2
             X1
             L2
             T1
             A2
             F2
             B1
             V
             J1
             X
             W1
             M1
             I2
             Z1
             I1
             E
             F
             G2
             Y1
             B
             D1
             Q
             D2
             G1
             S
             N
             E1
             P
             C
             M
             A1
             K
             N1
             T
             K1
             F1
             A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main334 B1
             P1
             G1
             A1
             W1
             X1
             L2
             V1
             L
             C1
             I
             B2
             G2
             E1
             P
             F1
             B
             S
             J1
             N2
             K2
             M
             A
             N
             S1
             J
             N1
             Y1
             H
             O
             T
             W
             Y
             G
             K
             E2
             C
             O1
             O2
             L1
             I2
             H2
             K1
             U
             J2
             D1
             F
             Z1
             U1
             E
             D2
             Q1
             V
             Z
             C2
             H1
             D
             R
             T1
             Q
             F2
             M2)
        (and (= M1 8576)
     (= I1 1)
     (= X 8448)
     (= O (- 256))
     (<= 0 C)
     (<= 0 D)
     (<= 0 M2)
     (<= 0 E2)
     (<= 0 T1)
     (<= 0 R)
     (<= 0 Q)
     (<= 0 K)
     (not (<= R1 0))
     (= A2 0)
     (= v_67 O))
      )
      (inv_main197 B1
             P1
             G1
             A1
             W1
             X
             L2
             V1
             L
             C1
             A2
             B2
             G2
             E1
             P
             F1
             B
             S
             J1
             N2
             K2
             M
             A
             N
             S1
             I1
             N1
             Y1
             H
             O
             M1
             W
             Y
             G
             K
             E2
             C
             O1
             O2
             R1
             I2
             H2
             K1
             U
             J2
             D1
             F
             Z1
             U1
             E
             D2
             Q1
             V
             Z
             C2
             H1
             D
             R
             T1
             Q
             F2
             v_67)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main334 Z1
             T1
             B
             Q
             Q1
             E
             R
             C
             I2
             Y
             Y1
             E1
             F1
             N1
             X
             H
             V
             I1
             E2
             V1
             T
             F
             B1
             U1
             H1
             F2
             L1
             K1
             C1
             W1
             X1
             S
             A
             J2
             D1
             K2
             C2
             N
             M1
             L2
             G2
             D
             O
             G1
             N2
             M
             M2
             A2
             U
             J1
             H2
             J
             P
             S1
             I
             L
             G
             P1
             A1
             B2
             O1
             W)
        (and (= D2 8576)
     (not (= W1 (- 256)))
     (= Z 1)
     (= K 0)
     (= O2 8448)
     (<= 0 K2)
     (<= 0 C2)
     (<= 0 B2)
     (<= 0 P1)
     (<= 0 D1)
     (<= 0 A1)
     (<= 0 W)
     (<= 0 G)
     (not (<= R1 0))
     (not (= E2 (- 2)))
     (= v_67 W1))
      )
      (inv_main197 Z1
             T1
             B
             Q
             Q1
             O2
             R
             C
             I2
             Y
             K
             E1
             F1
             N1
             X
             H
             V
             I1
             E2
             V1
             T
             F
             B1
             U1
             H1
             Z
             L1
             K1
             C1
             W1
             D2
             S
             A
             J2
             D1
             K2
             C2
             N
             M1
             R1
             G2
             D
             O
             G1
             N2
             M
             M2
             A2
             U
             J1
             H2
             J
             P
             S1
             I
             L
             G
             P1
             A1
             B2
             O1
             v_67)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main116 P
             F2
             M2
             T
             C2
             B1
             I
             O
             Q1
             L1
             V
             G1
             H2
             E1
             C
             Y1
             T1
             F1
             I2
             S1
             V1
             Q
             N1
             U
             G
             B2
             P1
             Z
             K2
             D1
             L
             A2
             Z1
             D
             H
             A1
             J1
             W1
             E2
             D2
             R
             C1
             K
             G2
             U1
             B
             I1
             X
             A
             F
             Y
             O1
             N
             X1
             S
             W
             M
             H1
             J2
             M1
             E
             R1)
        (and (not (= D1 (- 256)))
     (not (= B1 12292))
     (not (= B1 16384))
     (not (= B1 8192))
     (not (= B1 24576))
     (not (= B1 8195))
     (not (= B1 8480))
     (not (= B1 8481))
     (not (= B1 8482))
     (not (= B1 8464))
     (not (= B1 8465))
     (not (= B1 8466))
     (not (= B1 8496))
     (not (= B1 8497))
     (= B1 8512)
     (= J 0)
     (= L2 1)
     (<= 0 J2)
     (<= 0 R1)
     (<= 0 M1)
     (<= 0 J1)
     (<= 0 H1)
     (<= 0 A1)
     (<= 0 M)
     (<= 0 H)
     (= K1 8528)
     (= v_65 D1))
      )
      (inv_main197 P
             F2
             M2
             T
             C2
             K1
             I
             O
             Q1
             L1
             J
             G1
             H2
             E1
             C
             Y1
             T1
             F1
             I2
             S1
             V1
             Q
             N1
             U
             G
             B2
             P1
             Z
             K2
             D1
             L
             A2
             Z1
             D
             H
             A1
             J1
             W1
             E2
             D2
             R
             B1
             L2
             G2
             U1
             B
             I1
             X
             A
             F
             Y
             O1
             N
             X1
             S
             W
             v_65
             H1
             J2
             M1
             E
             R1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main116 L1
             M2
             B
             W
             B2
             X
             O
             D
             K2
             W1
             H1
             T
             O1
             M
             G2
             K1
             L
             A2
             I1
             Z1
             A
             A1
             C
             E1
             Y
             Q
             C2
             F
             L2
             P1
             J
             V1
             Y1
             D2
             X1
             D1
             Q1
             U1
             V
             R1
             J2
             I2
             Z
             G1
             T1
             N1
             P
             B1
             N
             M1
             H2
             F2
             H
             C1
             G
             E
             U
             S1
             F1
             K
             S
             R)
        (and (= P1 (- 256))
     (= J1 8528)
     (not (= X 12292))
     (not (= X 16384))
     (not (= X 8192))
     (not (= X 24576))
     (not (= X 8195))
     (not (= X 8480))
     (not (= X 8481))
     (not (= X 8482))
     (not (= X 8464))
     (not (= X 8465))
     (not (= X 8466))
     (not (= X 8496))
     (not (= X 8497))
     (= X 8512)
     (<= 0 X1)
     (<= 0 S1)
     (<= 0 Q1)
     (<= 0 F1)
     (<= 0 D1)
     (<= 0 U)
     (<= 0 R)
     (<= 0 K)
     (not (<= I 0))
     (= E2 0)
     (= v_65 P1))
      )
      (inv_main197 L1
             M2
             B
             W
             B2
             J1
             O
             D
             K2
             W1
             E2
             T
             O1
             M
             G2
             K1
             L
             A2
             I1
             Z1
             A
             A1
             C
             E1
             Y
             Q
             C2
             F
             L2
             P1
             J
             V1
             Y1
             D2
             X1
             D1
             Q1
             U1
             V
             I
             J2
             X
             Z
             G1
             T1
             N1
             P
             B1
             N
             M1
             H2
             F2
             H
             C1
             G
             E
             v_65
             S1
             F1
             K
             S
             R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main116 G
             D1
             Z
             F2
             G1
             U
             P
             L2
             H
             Y
             Q1
             R
             V1
             C
             B2
             T1
             Z1
             S
             F
             L1
             F1
             I1
             N1
             U1
             J
             E2
             M1
             A2
             M2
             E
             D
             S1
             K2
             E1
             O1
             A1
             B
             H1
             X
             Q
             M
             T
             R1
             C1
             W1
             K
             V
             O
             C2
             Y1
             L
             D2
             B1
             G2
             W
             I
             X1
             J1
             K1
             N
             H2
             P1)
        (and (= J2 1)
     (= I2 8528)
     (not (= U 12292))
     (not (= U 16384))
     (not (= U 8192))
     (not (= U 24576))
     (not (= U 8195))
     (not (= U 8480))
     (not (= U 8481))
     (not (= U 8482))
     (not (= U 8464))
     (not (= U 8465))
     (not (= U 8466))
     (not (= U 8496))
     (not (= U 8497))
     (not (= U 8512))
     (= U 8513)
     (not (= E (- 256)))
     (<= 0 B)
     (<= 0 X1)
     (<= 0 P1)
     (<= 0 O1)
     (<= 0 K1)
     (<= 0 J1)
     (<= 0 A1)
     (<= 0 N)
     (= A 0)
     (= v_65 E))
      )
      (inv_main197 G
             D1
             Z
             F2
             G1
             I2
             P
             L2
             H
             Y
             A
             R
             V1
             C
             B2
             T1
             Z1
             S
             F
             L1
             F1
             I1
             N1
             U1
             J
             E2
             M1
             A2
             M2
             E
             D
             S1
             K2
             E1
             O1
             A1
             B
             H1
             X
             Q
             M
             U
             J2
             C1
             W1
             K
             V
             O
             C2
             Y1
             L
             D2
             B1
             G2
             W
             I
             v_65
             J1
             K1
             N
             H2
             P1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main116 F2
             L2
             Z1
             J1
             E1
             W1
             H2
             F
             E2
             D2
             S
             N1
             L1
             U
             S1
             M2
             X
             E
             R
             B
             A2
             P1
             U1
             J
             P
             W
             Q
             O
             X1
             C2
             D1
             V
             T
             Q1
             B2
             L
             I
             H
             K2
             K
             A1
             I2
             O1
             G
             Z
             K1
             F1
             G2
             V1
             I1
             M1
             C
             T1
             B1
             M
             Y1
             H1
             J2
             N
             R1
             G1
             C1)
        (and (= C2 (- 256))
     (not (= W1 12292))
     (not (= W1 16384))
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
     (= W1 8513)
     (= D 0)
     (<= 0 J2)
     (<= 0 B2)
     (<= 0 R1)
     (<= 0 H1)
     (<= 0 C1)
     (<= 0 N)
     (<= 0 L)
     (<= 0 I)
     (not (<= Y 0))
     (= A 8528)
     (= v_65 C2))
      )
      (inv_main197 F2
             L2
             Z1
             J1
             E1
             A
             H2
             F
             E2
             D2
             D
             N1
             L1
             U
             S1
             M2
             X
             E
             R
             B
             A2
             P1
             U1
             J
             P
             W
             Q
             O
             X1
             C2
             D1
             V
             T
             Q1
             B2
             L
             I
             H
             K2
             Y
             A1
             W1
             O1
             G
             Z
             K1
             F1
             G2
             V1
             I1
             M1
             C
             T1
             B1
             M
             Y1
             v_65
             J2
             N
             R1
             G1
             C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main116 K1
             D
             V
             K2
             T
             D1
             T1
             Q
             I
             I1
             L1
             B1
             U
             C1
             X
             Y
             A2
             K
             F1
             F2
             B2
             O1
             H2
             M
             H
             A
             S1
             B
             Z
             I2
             W
             R1
             S
             E
             C
             J
             W1
             G1
             J2
             A1
             N
             R
             Y1
             V1
             G
             O
             D2
             C2
             L
             H1
             P
             L2
             E2
             J1
             E1
             Z1
             P1
             U1
             F
             X1
             M1
             G2)
        (and (= N1 8466)
     (not (= D1 8561))
     (= D1 8576)
     (not (= D1 8560))
     (not (= D1 8448))
     (not (= D1 8545))
     (not (= D1 8544))
     (not (= D1 8529))
     (not (= D1 12292))
     (not (= D1 16384))
     (not (= D1 8192))
     (not (= D1 24576))
     (not (= D1 8195))
     (not (= D1 8480))
     (not (= D1 8481))
     (not (= D1 8482))
     (not (= D1 8464))
     (not (= D1 8465))
     (not (= D1 8466))
     (not (= D1 8496))
     (not (= D1 8497))
     (not (= D1 8512))
     (not (= D1 8513))
     (not (= D1 8528))
     (<= 0 G2)
     (<= 0 X1)
     (<= 0 W1)
     (<= 0 U1)
     (<= 0 P1)
     (<= 0 J)
     (<= 0 F)
     (<= 0 C)
     (not (<= Q1 0))
     (= Q1 2))
      )
      (inv_main197 K1
             D
             V
             K2
             T
             N1
             T1
             Q
             I
             I1
             L1
             B1
             U
             C1
             X
             Y
             A2
             K
             F1
             F2
             B2
             O1
             H2
             M
             H
             A
             S1
             B
             Z
             I2
             W
             R1
             S
             E
             C
             J
             W1
             G1
             J2
             Q1
             N
             D1
             Y1
             V1
             G
             O
             D2
             C2
             L
             H1
             P
             L2
             E2
             J1
             E1
             Z1
             P1
             U1
             F
             X1
             M1
             G2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main116 K1
             X1
             H2
             A2
             A
             Y
             U
             O1
             O
             Q
             L2
             G
             C
             M2
             D2
             Y1
             L
             P
             W
             M1
             D
             C2
             I2
             G2
             C1
             S
             T1
             E2
             X
             Z
             I
             T
             N2
             V1
             B
             F
             F2
             D1
             K2
             L1
             F1
             B2
             P1
             K
             J1
             N
             Z1
             U1
             J
             J2
             H
             R
             B1
             Q1
             R1
             N1
             M
             H1
             I1
             A1
             S1
             E)
        (and (= E1 8592)
     (not (= Y 8561))
     (= Y 8576)
     (not (= Y 8560))
     (not (= Y 8448))
     (not (= Y 8545))
     (not (= Y 8544))
     (not (= Y 8529))
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
     (not (= Y 8496))
     (not (= Y 8497))
     (not (= Y 8512))
     (not (= Y 8513))
     (not (= Y 8528))
     (= V 0)
     (<= 0 B)
     (<= 0 F2)
     (<= 0 I1)
     (<= 0 H1)
     (<= 0 A1)
     (<= 0 M)
     (<= 0 F)
     (<= 0 E)
     (not (<= W1 0))
     (not (<= G1 0))
     (not (= G1 2)))
      )
      (inv_main197 K1
             X1
             H2
             A2
             A
             E1
             U
             O1
             O
             Q
             V
             G
             C
             M2
             D2
             Y1
             L
             P
             W
             M1
             D
             C2
             I2
             G2
             C1
             S
             T1
             E2
             X
             Z
             I
             T
             N2
             V1
             B
             F
             F2
             D1
             K2
             W1
             F1
             Y
             P1
             K
             J1
             N
             Z1
             U1
             J
             J2
             H
             R
             B1
             Q1
             R1
             N1
             M
             H1
             I1
             A1
             S1
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main116 M1
             T
             X
             X1
             G1
             Y1
             C
             E1
             U1
             D1
             O1
             K
             M
             Q
             H1
             L
             D2
             W1
             Q1
             H
             C1
             E2
             P
             I1
             A2
             U
             S
             J2
             I
             N
             E
             L1
             D
             Z
             H2
             K2
             C2
             L2
             P1
             G
             K1
             A1
             O
             F2
             F
             B
             J
             R1
             G2
             W
             R
             Z1
             Y
             N1
             B1
             T1
             S1
             B2
             F1
             A
             V
             I2)
        (and (not (= Y1 8561))
     (not (= Y1 8576))
     (not (= Y1 8560))
     (not (= Y1 8448))
     (not (= Y1 8545))
     (not (= Y1 8544))
     (not (= Y1 8529))
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
     (= V1 8466)
     (= J1 2)
     (<= 0 A)
     (<= 0 I2)
     (<= 0 H2)
     (<= 0 C2)
     (<= 0 B2)
     (<= 0 S1)
     (<= 0 F1)
     (<= 0 K2)
     (not (<= J1 0))
     (= Y1 8577))
      )
      (inv_main197 M1
             T
             X
             X1
             G1
             V1
             C
             E1
             U1
             D1
             O1
             K
             M
             Q
             H1
             L
             D2
             W1
             Q1
             H
             C1
             E2
             P
             I1
             A2
             U
             S
             J2
             I
             N
             E
             L1
             D
             Z
             H2
             K2
             C2
             L2
             P1
             J1
             K1
             Y1
             O
             F2
             F
             B
             J
             R1
             G2
             W
             R
             Z1
             Y
             N1
             B1
             T1
             S1
             B2
             F1
             A
             V
             I2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main116 M2
             E
             L1
             I2
             I1
             S1
             I
             D2
             V
             P
             A
             V1
             S
             X1
             K
             B1
             B
             C1
             R
             E1
             T
             N2
             C
             C2
             H
             K2
             W
             L2
             J1
             D1
             E2
             O
             M1
             H2
             G1
             G2
             X
             J
             G
             O1
             J2
             K1
             N1
             Z1
             Y
             W1
             Y1
             B2
             D
             R1
             H1
             N
             M
             F
             T1
             Z
             A2
             Q
             P1
             U
             Q1
             L)
        (and (= U1 0)
     (= S1 8577)
     (not (= S1 8561))
     (not (= S1 8576))
     (not (= S1 8560))
     (not (= S1 8448))
     (not (= S1 8545))
     (not (= S1 8544))
     (not (= S1 8529))
     (not (= S1 12292))
     (not (= S1 16384))
     (not (= S1 8192))
     (not (= S1 24576))
     (not (= S1 8195))
     (not (= S1 8480))
     (not (= S1 8481))
     (not (= S1 8482))
     (not (= S1 8464))
     (not (= S1 8465))
     (not (= S1 8466))
     (not (= S1 8496))
     (not (= S1 8497))
     (not (= S1 8512))
     (not (= S1 8513))
     (not (= S1 8528))
     (= A1 8592)
     (<= 0 G2)
     (<= 0 A2)
     (<= 0 P1)
     (<= 0 G1)
     (<= 0 X)
     (<= 0 U)
     (<= 0 Q)
     (<= 0 L)
     (not (<= F2 0))
     (not (<= F1 0))
     (not (= F2 2)))
      )
      (inv_main197 M2
             E
             L1
             I2
             I1
             A1
             I
             D2
             V
             P
             U1
             V1
             S
             X1
             K
             B1
             B
             C1
             R
             E1
             T
             N2
             C
             C2
             H
             K2
             W
             L2
             J1
             D1
             E2
             O
             M1
             H2
             G1
             G2
             X
             J
             G
             F1
             J2
             S1
             N1
             Z1
             Y
             W1
             Y1
             B2
             D
             R1
             H1
             N
             M
             F
             T1
             Z
             A2
             Q
             P1
             U
             Q1
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main116 I
             F1
             H2
             M
             E2
             K1
             G2
             O1
             I2
             E1
             L
             V1
             Q
             O2
             R1
             K2
             G
             S
             A
             P
             H
             Q1
             T
             B
             X1
             F2
             F
             U1
             X
             C2
             H1
             D1
             R
             J2
             C
             J
             W
             J1
             Z
             K
             N2
             I1
             A2
             B2
             N1
             P1
             Y
             D2
             V
             N
             U
             M1
             W1
             C1
             Y1
             A1
             Z1
             P2
             E
             T1
             L2
             L1)
        (and (= Y1 2)
     (not (= S1 0))
     (not (= K1 8641))
     (= K1 8656)
     (not (= K1 8609))
     (not (= K1 8640))
     (not (= K1 8593))
     (not (= K1 8608))
     (not (= K1 8577))
     (not (= K1 8592))
     (not (= K1 8561))
     (not (= K1 8576))
     (not (= K1 8560))
     (not (= K1 8448))
     (not (= K1 8545))
     (not (= K1 8544))
     (not (= K1 8529))
     (not (= K1 12292))
     (not (= K1 16384))
     (not (= K1 8192))
     (not (= K1 24576))
     (not (= K1 8195))
     (not (= K1 8480))
     (not (= K1 8481))
     (not (= K1 8482))
     (not (= K1 8464))
     (not (= K1 8465))
     (not (= K1 8466))
     (not (= K1 8496))
     (not (= K1 8497))
     (not (= K1 8512))
     (not (= K1 8513))
     (not (= K1 8528))
     (= G1 8672)
     (= B1 3)
     (= O 0)
     (<= 0 C)
     (<= 0 E)
     (<= 0 Z1)
     (<= 0 T1)
     (<= 0 L1)
     (<= 0 W)
     (<= 0 J)
     (<= 0 P2)
     (not (<= D 0))
     (not (= M2 0))
     (= v_68 X))
      )
      (inv_main197 I
             F1
             H2
             M
             E2
             G1
             G2
             O1
             I2
             E1
             O
             V1
             Q
             O2
             R1
             K2
             G
             S
             A
             P
             H
             Q1
             T
             B
             X1
             F2
             F
             U1
             X
             C2
             H1
             D1
             v_68
             J2
             C
             J
             W
             J1
             Z
             D
             N2
             K1
             A2
             B2
             N1
             P1
             Y
             D2
             V
             N
             U
             M1
             M2
             S1
             B1
             A1
             Z1
             P2
             E
             T1
             L2
             L1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main116 T1
             D
             M2
             K1
             J1
             G
             V
             A
             U1
             Y
             P
             V1
             E2
             H1
             N
             G2
             P1
             K2
             M1
             N1
             F1
             S1
             D2
             C
             O
             C2
             R1
             L2
             Q1
             B
             O1
             E
             X1
             J2
             F2
             Z1
             L1
             I1
             B2
             M
             Q
             O2
             W1
             G1
             T
             E1
             A1
             F
             Y1
             H
             R
             H2
             D1
             C1
             B1
             W
             S
             I2
             A2
             L
             Z
             U)
        (and (not (= K 0))
     (= J 0)
     (not (= I 0))
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
     (not (= G 8560))
     (not (= G 8448))
     (not (= G 8545))
     (not (= G 8544))
     (not (= G 8529))
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
     (= N2 8672)
     (<= 0 I2)
     (<= 0 F2)
     (<= 0 A2)
     (<= 0 Z1)
     (<= 0 L1)
     (<= 0 U)
     (<= 0 S)
     (<= 0 L)
     (not (<= X 0))
     (not (= B1 2))
     (= v_67 Q1))
      )
      (inv_main197 T1
             D
             M2
             K1
             J1
             N2
             V
             A
             U1
             Y
             J
             V1
             E2
             H1
             N
             G2
             P1
             K2
             M1
             N1
             F1
             S1
             D2
             C
             O
             C2
             R1
             L2
             Q1
             B
             O1
             E
             v_67
             J2
             F2
             Z1
             L1
             I1
             B2
             X
             Q
             G
             W1
             G1
             T
             E1
             A1
             F
             Y1
             H
             R
             H2
             K
             I
             B1
             W
             S
             I2
             A2
             L
             Z
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main116 P1
             J1
             Z1
             V1
             X
             B
             B2
             N1
             F
             R1
             E1
             C
             X1
             P
             K1
             M1
             O
             S
             N
             S1
             L2
             O1
             L1
             K2
             N2
             R
             Z
             D2
             D1
             J2
             F2
             J
             E2
             U1
             Y1
             L
             T1
             Y
             E
             W
             G
             D
             C2
             I2
             H
             A
             I1
             H2
             C1
             Q
             G2
             V
             A2
             U
             I
             F1
             W1
             M
             H1
             O2
             Q1
             M2)
        (and (not (= B 8641))
     (not (= B 8656))
     (not (= B 8609))
     (not (= B 8640))
     (not (= B 8593))
     (not (= B 8608))
     (not (= B 8577))
     (not (= B 8592))
     (not (= B 8561))
     (not (= B 8576))
     (not (= B 8560))
     (not (= B 8448))
     (not (= B 8545))
     (not (= B 8544))
     (not (= B 8529))
     (not (= B 12292))
     (not (= B 16384))
     (not (= B 8192))
     (not (= B 24576))
     (not (= B 8195))
     (not (= B 8480))
     (not (= B 8481))
     (not (= B 8482))
     (not (= B 8464))
     (not (= B 8465))
     (not (= B 8466))
     (not (= B 8496))
     (not (= B 8497))
     (not (= B 8512))
     (not (= B 8513))
     (not (= B 8528))
     (= G1 0)
     (not (= B1 0))
     (= A1 8672)
     (= K 3)
     (= I 2)
     (not (= P2 0))
     (<= 0 M2)
     (<= 0 Y1)
     (<= 0 W1)
     (<= 0 T1)
     (<= 0 H1)
     (<= 0 M)
     (<= 0 L)
     (<= 0 O2)
     (not (<= T 0))
     (= B 8657)
     (= v_68 D1))
      )
      (inv_main197 P1
             J1
             Z1
             V1
             X
             A1
             B2
             N1
             F
             R1
             G1
             C
             X1
             P
             K1
             M1
             O
             S
             N
             S1
             L2
             O1
             L1
             K2
             N2
             R
             Z
             D2
             D1
             J2
             F2
             J
             v_68
             U1
             Y1
             L
             T1
             Y
             E
             T
             G
             B
             C2
             I2
             H
             A
             I1
             H2
             C1
             Q
             G2
             V
             B1
             P2
             K
             F1
             W1
             M
             H1
             O2
             Q1
             M2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main116 U1
             C1
             Y1
             F2
             O1
             W
             N1
             T1
             U
             I1
             A2
             W1
             O
             H2
             E2
             V1
             H1
             R1
             Z
             I2
             B1
             C2
             L
             S1
             R
             Q1
             F1
             A1
             Y
             B2
             J
             N
             C
             V
             D
             P
             S
             O2
             M2
             M
             J2
             K
             G
             N2
             T
             K2
             D2
             E1
             E
             P1
             Q
             X1
             F
             Z1
             G1
             J1
             A
             H
             B
             M1
             I
             L2)
        (and (= K1 0)
     (not (= G1 2))
     (= D1 8672)
     (not (= X 0))
     (= W 8657)
     (not (= W 8641))
     (not (= W 8656))
     (not (= W 8609))
     (not (= W 8640))
     (not (= W 8593))
     (not (= W 8608))
     (not (= W 8577))
     (not (= W 8592))
     (not (= W 8561))
     (not (= W 8576))
     (not (= W 8560))
     (not (= W 8448))
     (not (= W 8545))
     (not (= W 8544))
     (not (= W 8529))
     (not (= W 12292))
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
     (<= 0 B)
     (<= 0 A)
     (<= 0 D)
     (<= 0 L2)
     (<= 0 M1)
     (<= 0 S)
     (<= 0 P)
     (<= 0 H)
     (not (<= L1 0))
     (not (= G2 0))
     (= v_67 Y))
      )
      (inv_main197 U1
             C1
             Y1
             F2
             O1
             D1
             N1
             T1
             U
             I1
             K1
             W1
             O
             H2
             E2
             V1
             H1
             R1
             Z
             I2
             B1
             C2
             L
             S1
             R
             Q1
             F1
             A1
             Y
             B2
             J
             N
             v_67
             V
             D
             P
             S
             O2
             M2
             L1
             J2
             W
             G
             N2
             T
             K2
             D2
             E1
             E
             P1
             Q
             X1
             G2
             X
             G1
             J1
             A
             H
             B
             M1
             I
             L2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main453 A
             C2
             M2
             M
             N1
             D2
             J2
             L1
             N
             O2
             T
             J1
             B
             I
             G1
             O
             D
             Y
             L2
             R1
             E1
             W
             T1
             S1
             U1
             B2
             W1
             H2
             S
             Z
             C1
             Z1
             L
             H1
             H
             F1
             C
             V1
             B1
             G
             X
             D1
             V
             J
             U
             Q
             M1
             P1
             P
             F
             A1
             K
             Y1
             F2
             O1
             A2
             G2
             Q1
             I1
             N2
             K1
             I2)
        (and (= X1 0)
     (= O1 4)
     (not (= J1 0))
     (= R 8448)
     (= E 8640)
     (<= 0 C)
     (<= 0 I2)
     (<= 0 G2)
     (<= 0 Q1)
     (<= 0 I1)
     (<= 0 F1)
     (<= 0 H)
     (<= 0 N2)
     (not (<= K2 0))
     (= E2 5))
      )
      (inv_main197 A
             C2
             M2
             M
             N1
             R
             J2
             L1
             N
             O2
             X1
             J1
             B
             I
             G1
             O
             D
             Y
             L2
             R1
             E1
             W
             T1
             S1
             U1
             B2
             W1
             H2
             S
             Z
             E
             Z1
             L
             H1
             H
             F1
             C
             V1
             B1
             K2
             X
             D1
             V
             J
             U
             Q
             M1
             P1
             P
             F
             A1
             K
             Y1
             F2
             E2
             A2
             G2
             Q1
             I1
             N2
             K1
             I2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main453 G1
             U
             B2
             I1
             D2
             A2
             R1
             W1
             F
             J
             P
             N
             F1
             Z
             O
             K2
             E
             W
             H1
             J2
             T1
             B
             I2
             Q1
             M2
             N1
             C1
             R
             A
             P1
             N2
             S1
             Q
             G2
             X
             L1
             E1
             C
             B1
             I
             M
             H
             F2
             X1
             K1
             T
             S
             H2
             G
             V
             E2
             D1
             V1
             M1
             L
             L2
             D
             O1
             Y1
             J1
             C2
             Z1)
        (and (= Y 3)
     (= N 0)
     (= L 4)
     (= K 5)
     (= O2 0)
     (<= 0 D)
     (<= 0 Z1)
     (<= 0 Y1)
     (<= 0 O1)
     (<= 0 L1)
     (<= 0 J1)
     (<= 0 E1)
     (<= 0 X)
     (not (<= A1 0))
     (= U1 8448))
      )
      (inv_main197 G1
             U
             B2
             I1
             D2
             U1
             R1
             W1
             F
             J
             O2
             N
             F1
             Z
             O
             K2
             E
             W
             H1
             J2
             T1
             B
             I2
             Q1
             M2
             N1
             C1
             R
             A
             P1
             Y
             S1
             Q
             G2
             X
             L1
             E1
             C
             B1
             A1
             M
             H
             F2
             X1
             K1
             T
             S
             H2
             G
             V
             E2
             D1
             V1
             M1
             K
             L2
             D
             O1
             Y1
             J1
             C2
             Z1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main453 K
             O
             C2
             G2
             Q1
             B1
             F1
             A
             Z1
             E2
             M
             J1
             V1
             M1
             V
             Q
             R1
             X
             I2
             Y1
             F
             I1
             E1
             W1
             D2
             N2
             H2
             X1
             N1
             A1
             U1
             W
             S1
             U
             B2
             D
             F2
             A2
             R
             J2
             G1
             T
             O1
             C1
             L
             J
             P
             E
             I
             K1
             M2
             D1
             K2
             Z
             Y
             G
             T1
             C
             S
             B
             H1
             P1)
        (and (not (= J1 0))
     (not (= Y 5))
     (not (= Y 4))
     (= N 8640)
     (= H 8448)
     (<= 0 B)
     (<= 0 C)
     (<= 0 F2)
     (<= 0 B2)
     (<= 0 T1)
     (<= 0 P1)
     (<= 0 S)
     (<= 0 D)
     (not (<= L2 0))
     (= L1 0))
      )
      (inv_main197 K
             O
             C2
             G2
             Q1
             H
             F1
             A
             Z1
             E2
             L1
             J1
             V1
             M1
             V
             Q
             R1
             X
             I2
             Y1
             F
             I1
             E1
             W1
             D2
             N2
             H2
             X1
             N1
             A1
             N
             W
             S1
             U
             B2
             D
             F2
             A2
             R
             L2
             G1
             T
             O1
             C1
             L
             J
             P
             E
             I
             K1
             M2
             D1
             K2
             Z
             Y
             G
             T1
             C
             S
             B
             H1
             P1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main453 M1
             L1
             E
             F1
             C
             I
             X
             P
             Z
             U1
             Y1
             N2
             K1
             B1
             M
             N
             S
             Z1
             Q
             H1
             U
             D
             G
             P1
             O
             W1
             T1
             C1
             A
             D1
             C2
             E1
             T
             L2
             K2
             B2
             A2
             M2
             V1
             B
             Y
             F
             J
             I1
             W
             A1
             I2
             N1
             G1
             H2
             R
             J2
             R1
             G2
             X1
             L
             E2
             J1
             O1
             K
             Q1
             D2)
        (and (not (= X1 5))
     (not (= X1 4))
     (= S1 0)
     (= V 3)
     (= N2 0)
     (<= 0 K2)
     (<= 0 E2)
     (<= 0 D2)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 O1)
     (<= 0 J1)
     (<= 0 K)
     (not (<= H 0))
     (= F2 8448))
      )
      (inv_main197 M1
             L1
             E
             F1
             C
             F2
             X
             P
             Z
             U1
             S1
             N2
             K1
             B1
             M
             N
             S
             Z1
             Q
             H1
             U
             D
             G
             P1
             O
             W1
             T1
             C1
             A
             D1
             V
             E1
             T
             L2
             K2
             B2
             A2
             M2
             V1
             H
             Y
             F
             J
             I1
             W
             A1
             I2
             N1
             G1
             H2
             R
             J2
             R1
             G2
             X1
             L
             E2
             J1
             O1
             K
             Q1
             D2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main296 L2
             A2
             R1
             T1
             J1
             J2
             G2
             N1
             V
             W
             A
             V1
             F1
             K1
             C
             J
             M2
             N
             Y
             G1
             Q
             D1
             O1
             I
             W1
             F2
             H
             B1
             I1
             M
             P
             U1
             K2
             G
             L1
             K
             E2
             S1
             Y1
             A1
             C1
             X
             F
             X1
             M1
             D
             T
             H1
             R
             E1
             B2
             O
             D2
             L
             Z
             B
             P1
             Z1
             E
             I2
             Q1
             S)
        (and (not (= B1 0))
     (= U 8544)
     (<= 0 I2)
     (<= 0 E2)
     (<= 0 Z1)
     (<= 0 P1)
     (<= 0 L1)
     (<= 0 S)
     (<= 0 K)
     (<= 0 E)
     (not (<= C2 0))
     (= H2 0))
      )
      (inv_main197 L2
             A2
             R1
             T1
             J1
             U
             G2
             N1
             V
             W
             H2
             V1
             F1
             K1
             C
             J
             M2
             N
             Y
             G1
             Q
             D1
             O1
             I
             W1
             F2
             H
             B1
             I1
             M
             P
             U1
             K2
             G
             L1
             K
             E2
             S1
             Y1
             C2
             C1
             X
             F
             X1
             M1
             D
             T
             H1
             R
             E1
             B2
             O
             D2
             L
             Z
             B
             P1
             Z1
             E
             I2
             Q1
             S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main296 H
             L
             D1
             I
             X1
             C
             U1
             R1
             L2
             D
             Z1
             M2
             W1
             Z
             O1
             N1
             D2
             W
             Y
             Q
             F2
             F1
             B
             S
             C1
             R
             V
             Q1
             T1
             P
             O
             K2
             P1
             H1
             G2
             J1
             E1
             J2
             A1
             N
             V1
             B1
             J
             A2
             L1
             G1
             E2
             F
             C2
             K1
             A
             U
             X
             M1
             T
             B2
             E
             S1
             Y1
             M
             I1
             H2)
        (and (= Q1 0)
     (= K 0)
     (= G 8544)
     (<= 0 H2)
     (<= 0 G2)
     (<= 0 Y1)
     (<= 0 S1)
     (<= 0 J1)
     (<= 0 E1)
     (<= 0 M)
     (<= 0 E)
     (not (<= I2 0))
     (not (= G2 (- 30))))
      )
      (inv_main197 H
             L
             D1
             I
             X1
             G
             U1
             R1
             L2
             D
             K
             M2
             W1
             Z
             O1
             N1
             D2
             W
             Y
             Q
             F2
             F1
             B
             S
             C1
             R
             V
             Q1
             T1
             P
             O
             K2
             P1
             H1
             G2
             J1
             E1
             J2
             A1
             I2
             V1
             B1
             J
             A2
             L1
             G1
             E2
             F
             C2
             K1
             A
             U
             X
             M1
             T
             B2
             E
             S1
             Y1
             M
             I1
             H2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main296 G1
             F
             Y
             V1
             C1
             E
             D1
             U
             X1
             S1
             I2
             K1
             A
             V
             Y1
             Q
             G2
             H
             E1
             R
             X
             P1
             L1
             Z1
             T1
             O
             P
             L
             C
             L2
             H2
             Q1
             N1
             A1
             I1
             K
             E2
             W
             U1
             T
             Z
             J
             S
             K2
             B
             I
             D2
             D
             C2
             M1
             N
             M
             B1
             F2
             J1
             B2
             J2
             O1
             G
             W1
             M2
             F1)
        (and (= I1 (- 30))
     (not (= I1 (- 1)))
     (= H1 0)
     (= X 0)
     (= L 0)
     (<= 0 J2)
     (<= 0 E2)
     (<= 0 W1)
     (<= 0 O1)
     (<= 0 I1)
     (<= 0 F1)
     (<= 0 K)
     (<= 0 G)
     (not (<= R1 0))
     (= A2 8544))
      )
      (inv_main197 G1
             F
             Y
             V1
             C1
             A2
             D1
             U
             X1
             S1
             H1
             K1
             A
             V
             Y1
             Q
             G2
             H
             E1
             R
             X
             P1
             L1
             Z1
             T1
             O
             P
             L
             C
             L2
             H2
             Q1
             N1
             A1
             I1
             K
             E2
             W
             U1
             R1
             Z
             J
             S
             K2
             B
             I
             D2
             D
             C2
             M1
             N
             M
             B1
             F2
             J1
             B2
             J2
             O1
             G
             W1
             M2
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main296 I1
             P2
             Q1
             P
             A1
             H1
             F1
             D
             X1
             S
             N
             M2
             Z1
             O1
             H2
             L2
             I2
             L
             U1
             R
             F2
             J1
             B1
             B2
             C
             T
             E
             Q
             A2
             Y1
             O2
             R1
             G
             X
             M1
             G2
             A
             W
             J2
             O
             W1
             D2
             U
             V1
             L1
             E2
             P1
             M
             D1
             N1
             C2
             E1
             K1
             G1
             F
             I
             T1
             K2
             K
             B
             J
             S1)
        (and (not (= F2 0))
     (not (= R1 (- 4)))
     (not (= R1 (- 2)))
     (= M1 (- 30))
     (not (= M1 (- 1)))
     (= Z 512)
     (= Y 0)
     (= Q 0)
     (= H 8544)
     (>= N2 65)
     (<= 0 A)
     (<= 0 B)
     (<= 0 K2)
     (<= 0 G2)
     (<= 0 T1)
     (<= 0 S1)
     (<= 0 M1)
     (<= 0 K)
     (not (<= V 0))
     (= (+ C1 (* (- 8) N2)) 0)
     (= v_68 R1)
     (= v_69 R1))
      )
      (inv_main197 I1
             P2
             Q1
             P
             A1
             H
             F1
             D
             X1
             S
             Y
             M2
             Z1
             O1
             H2
             L2
             I2
             L
             U1
             R
             F2
             J1
             B1
             B2
             C
             T
             E
             Q
             A2
             Y1
             O2
             R1
             G
             X
             M1
             G2
             A
             W
             J2
             V
             W1
             D2
             U
             V1
             L1
             E2
             P1
             M
             D1
             N2
             Z
             E1
             K1
             G1
             F
             I
             T1
             K2
             v_68
             v_69
             C1
             S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) (v_69 Int) ) 
    (=>
      (and
        (inv_main296 M
             T1
             P
             C1
             D2
             V1
             V
             N1
             S
             X1
             J1
             J2
             E1
             N2
             Q1
             M2
             O
             J
             C
             G1
             P2
             X
             B1
             T
             A1
             M1
             P1
             Z1
             I
             N
             F1
             S1
             C2
             B
             W
             I1
             F2
             Y
             E
             K2
             O1
             R1
             E2
             W1
             A
             F
             D1
             D
             L1
             I2
             K
             U
             R
             L
             Z
             U1
             A2
             H
             B2
             G
             H1
             O2)
        (and (= L2 0)
     (= H2 8544)
     (= Z1 0)
     (= S1 (- 4))
     (not (= S1 (- 2)))
     (= K1 1024)
     (= W (- 30))
     (not (= W (- 1)))
     (not (= P2 0))
     (>= Y1 129)
     (<= 0 F2)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 I1)
     (<= 0 W)
     (<= 0 H)
     (<= 0 G)
     (<= 0 O2)
     (not (<= Q 0))
     (= (+ G2 (* (- 8) Y1)) 0)
     (= v_68 S1)
     (= v_69 S1))
      )
      (inv_main197 M
             T1
             P
             C1
             D2
             H2
             V
             N1
             S
             X1
             L2
             J2
             E1
             N2
             Q1
             M2
             O
             J
             C
             G1
             P2
             X
             B1
             T
             A1
             M1
             P1
             Z1
             I
             N
             F1
             S1
             C2
             B
             W
             I1
             F2
             Y
             E
             Q
             O1
             R1
             E2
             W1
             A
             F
             D1
             D
             L1
             Y1
             K1
             U
             R
             L
             Z
             U1
             A2
             H
             v_68
             v_69
             G2
             O2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main453 J1
             C2
             J2
             Q1
             K1
             C
             T1
             Z
             X
             K
             B2
             E2
             P1
             J
             I1
             G1
             Q
             O1
             X1
             G
             A1
             K2
             D2
             U1
             H1
             R
             S
             D
             M
             O
             M1
             I2
             E1
             N1
             D1
             I
             F1
             H2
             W1
             F
             P
             V1
             L
             U
             T
             A2
             G2
             W
             Z1
             B1
             E
             Y
             C1
             H
             L1
             S1
             A
             Y1
             F2
             R1
             N
             B)
        (and (not (= L1 4))
     (<= 0 F2)
     (<= 0 Y1)
     (<= 0 R1)
     (<= 0 F1)
     (<= 0 D1)
     (<= 0 I)
     (<= 0 B)
     (<= 0 A)
     (= L1 5))
      )
      (inv_main513 J1
             C2
             J2
             Q1
             K1
             C
             T1
             Z
             X
             K
             B2
             E2
             P1
             J
             I1
             G1
             Q
             O1
             X1
             G
             A1
             K2
             D2
             U1
             H1
             R
             S
             D
             M
             O
             M1
             I2
             E1
             N1
             D1
             I
             F1
             H2
             W1
             V
             P
             V1
             L
             U
             T
             A2
             G2
             W
             Z1
             B1
             E
             Y
             C1
             H
             L1
             S1
             A
             Y1
             F2
             R1
             N
             B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main197 W1
             X
             B2
             E
             C1
             Q1
             W
             T
             H2
             N
             J2
             P
             Y
             S
             U1
             D2
             B1
             I2
             F
             R1
             D
             J
             R
             I
             H
             T1
             G1
             O1
             L1
             K1
             Z1
             U
             C
             L
             S1
             Y1
             K
             O
             P1
             A1
             G2
             A2
             F1
             G
             E2
             D1
             C2
             B
             J1
             E1
             H1
             V1
             M1
             X1
             I1
             N1
             A
             M
             Z
             V
             F2
             Q)
        (and (= Q1 8496)
     (= G1 0)
     (= F1 0)
     (not (= O 0))
     (not (= E 0))
     (<= 0 Y1)
     (<= 0 S1)
     (<= 0 Z)
     (<= 0 V)
     (<= 0 Q)
     (<= 0 M)
     (<= 0 K)
     (<= 0 A)
     (= A2 8464))
      )
      (inv_main513 W1
             X
             B2
             E
             C1
             Q1
             W
             T
             H2
             N
             J2
             P
             Y
             S
             U1
             D2
             B1
             I2
             F
             R1
             D
             J
             R
             I
             H
             T1
             G1
             O1
             L1
             K1
             Z1
             U
             C
             L
             S1
             Y1
             K
             O
             P1
             A1
             G2
             A2
             F1
             G
             E2
             D1
             C2
             B
             J1
             E1
             H1
             V1
             M1
             X1
             I1
             N1
             A
             M
             Z
             V
             F2
             Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main197 H
             B2
             D1
             T1
             I2
             V
             N1
             D
             V1
             L
             H1
             B
             X
             F1
             H2
             E2
             Y1
             S
             C1
             Q1
             N
             C
             S1
             L1
             J2
             B1
             J
             Z
             X1
             J1
             G1
             A1
             O
             U
             M
             C2
             K1
             R
             U1
             D2
             O1
             P
             K
             W1
             T
             I1
             Q
             F2
             A2
             G
             P1
             W
             R1
             Z1
             E1
             G2
             I
             M1
             K2
             F
             A
             Y)
        (and (= E 0)
     (<= 0 C2)
     (<= 0 M1)
     (<= 0 K1)
     (<= 0 Y)
     (<= 0 M)
     (<= 0 I)
     (<= 0 F)
     (<= 0 K2)
     (not (= J 0)))
      )
      (inv_main116 H
             B2
             D1
             T1
             I2
             V
             N1
             D
             V1
             L
             H1
             B
             X
             F1
             H2
             E2
             Y1
             S
             C1
             Q1
             N
             C
             S1
             L1
             J2
             B1
             J
             Z
             X1
             J1
             G1
             A1
             O
             U
             M
             C2
             K1
             R
             U1
             D2
             O1
             P
             E
             W1
             T
             I1
             Q
             F2
             A2
             G
             P1
             W
             R1
             Z1
             E1
             G2
             I
             M1
             K2
             F
             A
             Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main197 F2
             N
             D1
             C2
             Q1
             P
             Y
             E
             K1
             R
             D
             S
             A2
             H1
             C
             K2
             C1
             Q
             H
             B2
             L1
             J2
             B1
             O1
             E1
             Z1
             G1
             T1
             D2
             I1
             P1
             I2
             X
             U1
             O
             V1
             F1
             M1
             I
             F
             M
             Y1
             W
             W1
             A1
             R1
             K
             E2
             J
             H2
             A
             V
             S1
             L
             Z
             U
             T
             G
             J1
             X1
             N1
             G2)
        (and (not (= W 0))
     (= B 0)
     (<= 0 G2)
     (<= 0 X1)
     (<= 0 V1)
     (<= 0 J1)
     (<= 0 F1)
     (<= 0 T)
     (<= 0 O)
     (<= 0 G)
     (= G1 0))
      )
      (inv_main116 F2
             N
             D1
             C2
             Q1
             P
             Y
             E
             K1
             R
             D
             S
             A2
             H1
             C
             K2
             C1
             Q
             H
             B2
             L1
             J2
             B1
             O1
             E1
             Z1
             G1
             T1
             D2
             I1
             P1
             I2
             X
             U1
             O
             V1
             F1
             M1
             I
             F
             M
             Y1
             B
             W1
             A1
             R1
             K
             E2
             J
             H2
             A
             V
             S1
             L
             Z
             U
             T
             G
             J1
             X1
             N1
             G2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main496 E2
             K
             S
             D2
             Y1
             K1
             B
             Q
             F
             L
             W
             Z
             E
             Y
             M
             G2
             X1
             M1
             H
             V1
             I1
             A2
             P1
             Z1
             A1
             P
             I2
             R
             J1
             J2
             A
             U1
             D1
             G
             X
             H2
             S1
             K2
             O1
             R1
             O
             C
             U
             D
             I
             N
             T1
             N1
             L1
             H1
             F2
             W1
             T
             C1
             B2
             E1
             V
             C2
             F1
             Q1
             G1
             B1)
        (and (= K2 0)
     (<= 0 H2)
     (<= 0 C2)
     (<= 0 S1)
     (<= 0 Q1)
     (<= 0 F1)
     (<= 0 B1)
     (<= 0 X)
     (<= 0 V)
     (= J 0))
      )
      (inv_main116 E2
             K
             S
             D2
             Y1
             K1
             B
             Q
             F
             L
             W
             Z
             E
             Y
             M
             G2
             X1
             M1
             H
             V1
             I1
             A2
             P1
             Z1
             A1
             P
             I2
             R
             J1
             J2
             A
             U1
             D1
             G
             X
             H2
             S1
             K2
             O1
             R1
             O
             C
             J
             D
             I
             N
             T1
             N1
             L1
             H1
             F2
             W1
             T
             C1
             B2
             E1
             V
             C2
             F1
             Q1
             G1
             B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main496 W1
             S1
             Q1
             D
             J2
             M
             K
             I2
             A1
             E
             H1
             T
             Y1
             Z
             Q
             D2
             T1
             F1
             B1
             I1
             V
             I
             U
             E2
             L1
             C2
             K2
             K1
             B
             E1
             S
             H2
             X1
             G1
             O1
             F2
             L
             H
             B2
             G2
             R
             M1
             W
             C
             U1
             P
             A2
             J
             J1
             A
             Z1
             R1
             G
             C1
             V1
             D1
             F
             Y
             N
             N1
             P1
             O)
        (and (= M M1)
     (not (= H 0))
     (<= 0 F2)
     (<= 0 O1)
     (<= 0 N1)
     (<= 0 Y)
     (<= 0 O)
     (<= 0 N)
     (<= 0 L)
     (<= 0 F)
     (= X 0))
      )
      (inv_main116 W1
             S1
             Q1
             D
             J2
             M
             K
             I2
             A1
             E
             H1
             T
             Y1
             Z
             Q
             D2
             T1
             F1
             B1
             I1
             V
             I
             U
             E2
             L1
             C2
             K2
             K1
             B
             E1
             S
             H2
             X1
             G1
             O1
             F2
             L
             H
             B2
             G2
             R
             M1
             X
             C
             U1
             P
             A2
             J
             J1
             A
             Z1
             R1
             G
             C1
             V1
             D1
             F
             Y
             N
             N1
             P1
             O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main496 M1
             L1
             E
             Z
             A
             Q1
             M
             N1
             C2
             T1
             E2
             K1
             R1
             G2
             D1
             F
             O1
             A1
             K2
             U1
             B2
             C1
             P
             H
             D
             F1
             T
             J1
             U
             J
             X1
             W
             D2
             G
             P1
             K
             I1
             L
             E1
             Y
             X
             S
             I
             H1
             V
             O
             S1
             N
             B
             A2
             R
             I2
             Q
             W1
             F2
             J2
             V1
             C
             G1
             Z1
             Y1
             H2)
        (and (= B1 0)
     (not (= L 0))
     (<= 0 H2)
     (<= 0 Z1)
     (<= 0 V1)
     (<= 0 P1)
     (<= 0 I1)
     (<= 0 G1)
     (<= 0 K)
     (<= 0 C)
     (not (= Q1 S))
     (= v_63 Q1))
      )
      (inv_main116 M1
             L1
             E
             Z
             A
             Q1
             M
             N1
             C2
             T1
             E2
             K1
             R1
             G2
             D1
             F
             O1
             A1
             K2
             U1
             B2
             C1
             P
             H
             D
             F1
             T
             J1
             U
             J
             X1
             W
             D2
             G
             P1
             K
             I1
             L
             E1
             Y
             v_63
             S
             B1
             H1
             V
             O
             S1
             N
             B
             A2
             R
             I2
             Q
             W1
             F2
             J2
             V1
             C
             G1
             Z1
             Y1
             H2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main105 T1
             K
             O
             F
             Y1
             H2
             I2
             T
             Z1
             P
             C2
             I
             U1
             C
             N1
             G2
             Q1
             A
             Y
             S1
             R1
             S
             K2
             V1
             W
             G
             M
             B1
             E2
             B2
             C1
             I1
             Z
             V
             G1
             O1
             J1
             Q
             F1
             A2
             L
             N
             X
             U
             E1
             K1
             B
             D
             P1
             R
             X1
             J2
             E
             W1
             H
             M1
             D1
             H1
             F2
             L1
             D2
             J)
        (and (= E1 (- 12288))
     (= A1 (+ 1 Y1))
     (<= 0 F2)
     (<= 0 O1)
     (<= 0 L1)
     (<= 0 J1)
     (<= 0 H1)
     (<= 0 G1)
     (<= 0 D1)
     (<= 0 J)
     (not (= Q1 0)))
      )
      (inv_main116 T1
             K
             O
             F
             A1
             H2
             I2
             T
             Z1
             P
             C2
             I
             U1
             C
             N1
             G2
             Q1
             A
             Y
             S1
             R1
             S
             K2
             V1
             W
             G
             M
             B1
             E2
             B2
             C1
             I1
             Z
             V
             G1
             O1
             J1
             Q
             F1
             A2
             L
             N
             X
             U
             E1
             K1
             B
             D
             P1
             R
             X1
             J2
             E
             W1
             H
             M1
             D1
             H1
             F2
             L1
             D2
             J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main105 S
             J
             A2
             C2
             Z
             U1
             V1
             Y
             X
             R1
             C
             P
             M
             W
             G2
             G1
             S1
             O
             W1
             Q
             D1
             E
             N
             L
             K2
             I1
             Y1
             I
             A
             F2
             H1
             A1
             M1
             T1
             F
             E1
             K
             U
             B
             N1
             T
             J1
             B2
             D2
             G
             E2
             J2
             P1
             R
             O1
             Z1
             F1
             B1
             H
             K1
             I2
             Q1
             V
             X1
             D
             H2
             L1)
        (and (not (= S1 0))
     (= C1 (+ 1 Z))
     (not (= G (- 12288)))
     (<= 0 X1)
     (<= 0 Q1)
     (<= 0 L1)
     (<= 0 E1)
     (<= 0 V)
     (<= 0 K)
     (<= 0 F)
     (<= 0 D)
     (not (= E2 (- 16384))))
      )
      (inv_main116 S
             J
             A2
             C2
             C1
             U1
             V1
             Y
             X
             R1
             C
             P
             M
             W
             G2
             G1
             S1
             O
             W1
             Q
             D1
             E
             N
             L
             K2
             I1
             Y1
             I
             A
             F2
             H1
             A1
             M1
             T1
             F
             E1
             K
             U
             B
             N1
             T
             J1
             B2
             D2
             G
             E2
             J2
             P1
             R
             O1
             Z1
             F1
             B1
             H
             K1
             I2
             Q1
             V
             X1
             D
             H2
             L1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main105 Y
             M1
             I1
             B1
             I
             R1
             L
             D
             X1
             A2
             B2
             J1
             Q
             P
             I2
             L1
             A1
             W
             G1
             Z
             J
             V1
             V
             O
             R
             T1
             S1
             H1
             E
             H
             A
             D2
             Q1
             C1
             F
             J2
             O1
             G
             X
             U
             D1
             Y1
             N
             F1
             E2
             C
             F2
             Z1
             B
             W1
             C2
             U1
             N1
             S
             G2
             P1
             K
             T
             K2
             H2
             E1
             M)
        (and (= K1 (+ 1 I))
     (not (= A1 0))
     (= C (- 16384))
     (<= 0 H2)
     (<= 0 O1)
     (<= 0 T)
     (<= 0 M)
     (<= 0 K)
     (<= 0 F)
     (<= 0 K2)
     (<= 0 J2)
     (not (= E2 (- 12288))))
      )
      (inv_main116 Y
             M1
             I1
             B1
             K1
             R1
             L
             D
             X1
             A2
             B2
             J1
             Q
             P
             I2
             L1
             A1
             W
             G1
             Z
             J
             V1
             V
             O
             R
             T1
             S1
             H1
             E
             H
             A
             D2
             Q1
             C1
             F
             J2
             O1
             G
             X
             U
             D1
             Y1
             N
             F1
             E2
             C
             F2
             Z1
             B
             W1
             C2
             U1
             N1
             S
             G2
             P1
             K
             T
             K2
             H2
             E1
             M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main487 F
             S1
             I1
             K
             X1
             M1
             L
             O1
             O
             H1
             J2
             Z
             D2
             Z1
             C2
             U1
             E2
             E
             C1
             W1
             L1
             B
             A1
             I
             P1
             F2
             I2
             B1
             V1
             E1
             Q1
             H2
             D
             S
             Y
             U
             H
             T
             Y1
             N1
             G2
             R1
             N
             T1
             P
             F1
             M
             J
             K1
             G1
             X
             R
             J1
             G
             A
             D1
             A2
             C
             W
             Q
             B2
             V)
        (and (<= 0 A2)
     (<= 0 Y)
     (<= 0 W)
     (<= 0 V)
     (<= 0 U)
     (<= 0 Q)
     (<= 0 H)
     (<= 0 C)
     (= C2 0))
      )
      (inv_main496 F
             S1
             I1
             K
             X1
             M1
             L
             O1
             O
             H1
             J2
             Z
             D2
             Z1
             C2
             U1
             E2
             E
             C1
             W1
             L1
             B
             A1
             I
             P1
             F2
             I2
             B1
             V1
             E1
             Q1
             H2
             D
             S
             Y
             U
             H
             T
             Y1
             N1
             G2
             R1
             N
             T1
             P
             F1
             M
             J
             K1
             G1
             X
             R
             J1
             G
             A
             D1
             A2
             C
             W
             Q
             B2
             V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main487 N
             S
             U1
             A
             K
             I1
             J1
             D2
             Q
             D1
             R
             A2
             Q1
             H1
             K1
             L
             J
             X1
             I
             E
             N1
             M
             J2
             V1
             C
             H2
             P1
             F2
             O
             U
             H
             C1
             G
             Y1
             O1
             F
             B2
             R1
             C2
             K2
             T1
             Z1
             E2
             M1
             W
             V
             X
             B
             T
             G1
             E1
             Z
             Y
             L1
             B1
             G2
             S1
             I2
             W1
             D
             P
             F1)
        (and (<= 0 I2)
     (<= 0 B2)
     (<= 0 W1)
     (<= 0 S1)
     (<= 0 O1)
     (<= 0 F1)
     (<= 0 F)
     (<= 0 D)
     (not (<= A1 0))
     (not (= K1 0)))
      )
      (inv_main496 N
             S
             U1
             A
             K
             I1
             J1
             D2
             Q
             D1
             R
             A2
             Q1
             H1
             K1
             L
             J
             X1
             I
             E
             N1
             M
             J2
             V1
             C
             H2
             P1
             F2
             O
             U
             H
             C1
             G
             Y1
             O1
             F
             B2
             R1
             C2
             A1
             T1
             Z1
             E2
             M1
             W
             V
             X
             B
             T
             G1
             E1
             Z
             Y
             L1
             B1
             G2
             S1
             I2
             W1
             D
             P
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main116 D
             E1
             G2
             I2
             B
             R1
             Z1
             X1
             S1
             O1
             O
             Q1
             T
             F2
             G
             P1
             X
             E
             U1
             D1
             D2
             V1
             L
             Y
             T1
             A
             P
             Y1
             H2
             B2
             U
             V
             B1
             L2
             Q
             H
             C2
             I
             A1
             S
             A2
             N1
             C
             F1
             Z
             W1
             W
             C1
             J
             J2
             G1
             K
             H1
             I1
             M1
             N
             M
             E2
             F
             L1
             R
             J1)
        (and (= R1 8640)
     (not (= R1 8593))
     (not (= R1 8608))
     (not (= R1 8577))
     (not (= R1 8592))
     (not (= R1 8561))
     (not (= R1 8576))
     (not (= R1 8560))
     (not (= R1 8448))
     (not (= R1 8545))
     (not (= R1 8544))
     (not (= R1 8529))
     (not (= R1 12292))
     (not (= R1 16384))
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
     (= M1 3)
     (= K2 4)
     (<= 0 E2)
     (<= 0 C2)
     (<= 0 L1)
     (<= 0 J1)
     (<= 0 Q)
     (<= 0 M)
     (<= 0 H)
     (<= 0 F)
     (not (= R1 8609))
     (= v_64 R1))
      )
      (inv_main417 D
             E1
             G2
             I2
             B
             R1
             Z1
             X1
             S1
             O1
             O
             Q1
             T
             F2
             G
             P1
             X
             E
             U1
             D1
             D2
             V1
             L
             Y
             T1
             A
             P
             Y1
             H2
             B2
             U
             V
             B1
             L2
             Q
             H
             C2
             I
             A1
             K1
             A2
             v_64
             C
             F1
             Z
             W1
             W
             C1
             J
             J2
             G1
             K
             H1
             I1
             K2
             N
             M
             E2
             F
             L1
             R
             J1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main116 E1
             R1
             J2
             I
             B2
             G
             F2
             R
             I2
             H
             S1
             L
             U1
             H2
             N
             Y1
             S
             F
             W
             Q
             A
             P
             B1
             P1
             B
             A1
             K1
             D1
             F1
             K
             Q1
             L1
             Z
             C1
             M
             V1
             O1
             E2
             M1
             N1
             X
             C2
             G1
             K2
             T1
             J1
             J
             Z1
             O
             D2
             V
             I1
             U
             W1
             A2
             E
             T
             X1
             D
             C
             Y
             H1)
        (and (not (= G 8609))
     (= G 8640)
     (not (= G 8593))
     (not (= G 8608))
     (not (= G 8577))
     (not (= G 8592))
     (not (= G 8561))
     (not (= G 8576))
     (not (= G 8560))
     (not (= G 8448))
     (not (= G 8545))
     (not (= G 8544))
     (not (= G 8529))
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
     (<= 0 X1)
     (<= 0 V1)
     (<= 0 O1)
     (<= 0 H1)
     (<= 0 T)
     (<= 0 M)
     (<= 0 D)
     (<= 0 C)
     (not (= A2 3))
     (= v_63 G))
      )
      (inv_main417 E1
             R1
             J2
             I
             B2
             G
             F2
             R
             I2
             H
             S1
             L
             U1
             H2
             N
             Y1
             S
             F
             W
             Q
             A
             P
             B1
             P1
             B
             A1
             K1
             D1
             F1
             K
             Q1
             L1
             Z
             C1
             M
             V1
             O1
             E2
             M1
             G2
             X
             v_63
             G1
             K2
             T1
             J1
             J
             Z1
             O
             D2
             V
             I1
             U
             W1
             A2
             E
             T
             X1
             D
             C
             Y
             H1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main116 N1
             H2
             D1
             I1
             Q
             T1
             E
             I
             J2
             W
             L1
             O1
             V
             F
             U
             N
             A
             B
             X
             F1
             H
             I2
             K2
             R
             Z
             G2
             M1
             E1
             X1
             P1
             Y1
             C2
             O
             P
             E2
             B1
             M
             W1
             D
             D2
             R1
             C
             A1
             H1
             C1
             S
             G
             T
             L2
             V1
             Q1
             U1
             G1
             L
             B2
             K
             Z1
             S1
             A2
             F2
             J
             J1)
        (and (= T1 8641)
     (not (= T1 8609))
     (not (= T1 8640))
     (not (= T1 8593))
     (not (= T1 8608))
     (not (= T1 8577))
     (not (= T1 8592))
     (not (= T1 8561))
     (not (= T1 8576))
     (not (= T1 8560))
     (not (= T1 8448))
     (not (= T1 8545))
     (not (= T1 8544))
     (not (= T1 8529))
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
     (= K1 4)
     (<= 0 F2)
     (<= 0 E2)
     (<= 0 A2)
     (<= 0 Z1)
     (<= 0 S1)
     (<= 0 J1)
     (<= 0 B1)
     (<= 0 M)
     (= B2 3)
     (= v_64 T1))
      )
      (inv_main417 N1
             H2
             D1
             I1
             Q
             T1
             E
             I
             J2
             W
             L1
             O1
             V
             F
             U
             N
             A
             B
             X
             F1
             H
             I2
             K2
             R
             Z
             G2
             M1
             E1
             X1
             P1
             Y1
             C2
             O
             P
             E2
             B1
             M
             W1
             D
             Y
             R1
             v_64
             A1
             H1
             C1
             S
             G
             T
             L2
             V1
             Q1
             U1
             G1
             L
             K1
             K
             Z1
             S1
             A2
             F2
             J
             J1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main116 G
             E2
             C1
             Z1
             S
             M1
             M
             F
             C2
             Y
             F1
             I
             E
             G1
             A1
             E1
             J2
             W1
             X1
             L
             P1
             K2
             L1
             K
             F2
             J
             H1
             B
             X
             S1
             J1
             T
             O1
             A
             Y1
             R
             D2
             H
             B1
             C
             G2
             I2
             Q1
             P
             N
             A2
             B2
             O
             R1
             V1
             Q
             N1
             Z
             I1
             T1
             D1
             U1
             V
             H2
             U
             D
             W)
        (and (= M1 8641)
     (not (= M1 8609))
     (not (= M1 8640))
     (not (= M1 8593))
     (not (= M1 8608))
     (not (= M1 8577))
     (not (= M1 8592))
     (not (= M1 8561))
     (not (= M1 8576))
     (not (= M1 8560))
     (not (= M1 8448))
     (not (= M1 8545))
     (not (= M1 8544))
     (not (= M1 8529))
     (not (= M1 12292))
     (not (= M1 16384))
     (not (= M1 8192))
     (not (= M1 24576))
     (not (= M1 8195))
     (not (= M1 8480))
     (not (= M1 8481))
     (not (= M1 8482))
     (not (= M1 8464))
     (not (= M1 8465))
     (not (= M1 8466))
     (not (= M1 8496))
     (not (= M1 8497))
     (not (= M1 8512))
     (not (= M1 8513))
     (not (= M1 8528))
     (<= 0 H2)
     (<= 0 D2)
     (<= 0 Y1)
     (<= 0 U1)
     (<= 0 W)
     (<= 0 V)
     (<= 0 U)
     (<= 0 R)
     (not (= T1 3))
     (= v_63 M1))
      )
      (inv_main417 G
             E2
             C1
             Z1
             S
             M1
             M
             F
             C2
             Y
             F1
             I
             E
             G1
             A1
             E1
             J2
             W1
             X1
             L
             P1
             K2
             L1
             K
             F2
             J
             H1
             B
             X
             S1
             J1
             T
             O1
             A
             Y1
             R
             D2
             H
             B1
             K1
             G2
             v_63
             Q1
             P
             N
             A2
             B2
             O
             R1
             V1
             Q
             N1
             Z
             I1
             T1
             D1
             U1
             V
             H2
             U
             D
             W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main116 Z
             A2
             J
             A
             M
             Q1
             M1
             L
             E
             U1
             Y1
             X1
             W
             O1
             Y
             L1
             F1
             Z1
             K1
             V
             H2
             B
             E2
             I
             F
             B2
             V1
             J1
             W1
             N
             F2
             R
             H1
             O
             C
             G1
             J2
             T1
             S1
             A1
             B1
             G
             Q
             C1
             K
             X
             D1
             H
             N1
             D
             S
             P1
             G2
             T
             P
             E1
             U
             R1
             D2
             I1
             C2
             I2)
        (and (not (= Q1 16384))
     (not (= Q1 8192))
     (not (= Q1 24576))
     (not (= Q1 8195))
     (not (= Q1 8480))
     (not (= Q1 8481))
     (not (= Q1 8482))
     (not (= Q1 8464))
     (not (= Q1 8465))
     (= Q1 8466)
     (<= 0 D2)
     (<= 0 R1)
     (<= 0 I1)
     (<= 0 G1)
     (<= 0 U)
     (<= 0 C)
     (<= 0 J2)
     (<= 0 I2)
     (not (= Q1 12292))
     (= v_62 Q1))
      )
      (inv_main253 Z
             A2
             J
             A
             M
             Q1
             M1
             L
             E
             U1
             Y1
             X1
             W
             O1
             Y
             L1
             F1
             Z1
             K1
             V
             H2
             B
             E2
             I
             F
             B2
             V1
             J1
             W1
             N
             F2
             R
             H1
             O
             C
             G1
             J2
             T1
             S1
             A1
             B1
             v_62
             Q
             C1
             K
             X
             D1
             H
             N1
             D
             S
             P1
             G2
             T
             P
             E1
             U
             R1
             D2
             I1
             C2
             I2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main116 G
             F1
             L
             X
             P
             A
             J1
             I1
             P1
             D1
             X1
             G1
             V
             K
             K1
             Y
             S
             J
             E2
             R
             O
             I
             A1
             Y1
             B2
             N1
             F2
             N
             T1
             E
             D
             S1
             O1
             J2
             E1
             I2
             Q
             M
             C1
             D2
             W1
             M1
             R1
             U1
             T
             F
             A2
             U
             H1
             Z
             B1
             C2
             V1
             G2
             H
             C
             W
             Q1
             L1
             Z1
             H2
             B)
        (and (not (= A 16384))
     (not (= A 8192))
     (not (= A 24576))
     (not (= A 8195))
     (not (= A 8480))
     (not (= A 8481))
     (not (= A 8482))
     (= A 8464)
     (<= 0 Z1)
     (<= 0 Q1)
     (<= 0 L1)
     (<= 0 E1)
     (<= 0 W)
     (<= 0 Q)
     (<= 0 B)
     (<= 0 I2)
     (not (= A 12292))
     (= v_62 A))
      )
      (inv_main253 G
             F1
             L
             X
             P
             A
             J1
             I1
             P1
             D1
             X1
             G1
             V
             K
             K1
             Y
             S
             J
             E2
             R
             O
             I
             A1
             Y1
             B2
             N1
             F2
             N
             T1
             E
             D
             S1
             O1
             J2
             E1
             I2
             Q
             M
             C1
             D2
             W1
             v_62
             R1
             U1
             T
             F
             A2
             U
             H1
             Z
             B1
             C2
             V1
             G2
             H
             C
             W
             Q1
             L1
             Z1
             H2
             B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main116 W
             T1
             I2
             J2
             X1
             X
             B2
             J
             T
             L1
             F2
             Z1
             M1
             G2
             D
             P
             G1
             G
             E1
             V
             Q1
             L
             W1
             S1
             A2
             H1
             K1
             A
             M
             E2
             E
             D2
             B
             O1
             H
             C2
             O
             C1
             U1
             C
             N
             I
             H2
             B1
             Q
             Y1
             K
             N1
             D1
             V1
             R
             Z
             U
             F
             R1
             J1
             F1
             P1
             S
             Y
             I1
             A1)
        (and (not (= X 16384))
     (not (= X 8192))
     (not (= X 24576))
     (not (= X 8195))
     (not (= X 8480))
     (not (= X 8481))
     (not (= X 8482))
     (not (= X 8464))
     (= X 8465)
     (<= 0 C2)
     (<= 0 P1)
     (<= 0 F1)
     (<= 0 A1)
     (<= 0 Y)
     (<= 0 S)
     (<= 0 O)
     (<= 0 H)
     (not (= X 12292))
     (= v_62 X))
      )
      (inv_main253 W
             T1
             I2
             J2
             X1
             X
             B2
             J
             T
             L1
             F2
             Z1
             M1
             G2
             D
             P
             G1
             G
             E1
             V
             Q1
             L
             W1
             S1
             A2
             H1
             K1
             A
             M
             E2
             E
             D2
             B
             O1
             H
             C2
             O
             C1
             U1
             C
             N
             v_62
             H2
             B1
             Q
             Y1
             K
             N1
             D1
             V1
             R
             Z
             U
             F
             R1
             J1
             F1
             P1
             S
             Y
             I1
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main4 G F)
        (and (= M2 0)
     (= H2 8464)
     (= G2 0)
     (= B2 0)
     (= Y1 1)
     (= X1 (- 1))
     (= P1 0)
     (= J1 0)
     (not (= H1 0))
     (= A1 0)
     (= Z 0)
     (= U 0)
     (= S 0)
     (= R 8464)
     (= P 0)
     (= N2 8464)
     (<= 0 A)
     (<= 0 M2)
     (<= 0 I2)
     (<= 0 G2)
     (<= 0 E2)
     (<= 0 B2)
     (<= 0 T1)
     (<= 0 I1)
     (<= 0 E1)
     (<= 0 A1)
     (<= 0 P)
     (<= 0 E)
     (= C 0)
     (= v_67 U1)
     (= v_68 H1))
      )
      (inv_main105 N2
             F
             H2
             H1
             D2
             R
             W1
             F1
             V1
             M
             S1
             V
             J
             Y1
             F2
             T
             M1
             Z1
             B1
             W
             Q1
             A2
             O
             Y
             K2
             K
             J1
             B
             O1
             S
             J2
             C1
             O2
             D
             T1
             U1
             v_67
             v_68
             R1
             X1
             L1
             L2
             C
             P1
             D1
             H
             N1
             I
             K1
             Q
             X
             C2
             G1
             L
             U
             N
             M2
             A1
             G2
             P
             Z
             B2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main4 S V)
        (and (= U1 0)
     (= S1 0)
     (= O1 (- 1))
     (= N1 8464)
     (not (= M1 0))
     (= F1 8464)
     (= C1 0)
     (= Z 0)
     (= X 0)
     (= U 0)
     (= R 0)
     (= P 8464)
     (= M 0)
     (= L 0)
     (= H 1)
     (= O2 0)
     (= N2 0)
     (<= 0 S1)
     (<= 0 J1)
     (<= 0 I1)
     (<= 0 H1)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 A1)
     (<= 0 U)
     (<= 0 M)
     (<= 0 L)
     (<= 0 J)
     (<= 0 I)
     (= K2 0)
     (= v_67 A2)
     (= v_68 M1))
      )
      (inv_main105 N1
             V
             F1
             K2
             C
             P
             M2
             E1
             T1
             P1
             D2
             B1
             Y1
             H
             W1
             H2
             K1
             N
             L2
             F
             R1
             M1
             A
             F2
             Y
             D
             Z
             V1
             Q1
             U1
             G
             C2
             I2
             B
             I
             A2
             v_67
             v_68
             W
             O1
             Z1
             Q
             X
             R
             O
             K
             B2
             G1
             E
             X1
             T
             G2
             J2
             E2
             N2
             L1
             L
             S1
             C1
             U
             O2
             M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main4 Q1 Y)
        (and (= N2 0)
     (= M2 0)
     (= I2 0)
     (= G2 (- 1))
     (= X1 8464)
     (= V1 0)
     (= T1 0)
     (= R1 0)
     (= J1 0)
     (= C1 8464)
     (= B1 0)
     (= V 1)
     (= U 0)
     (= T 0)
     (= M 0)
     (= I 0)
     (= F 0)
     (= P2 8464)
     (<= 0 D)
     (<= 0 B)
     (<= 0 E)
     (<= 0 M2)
     (<= 0 V1)
     (<= 0 M1)
     (<= 0 I1)
     (<= 0 B1)
     (<= 0 T)
     (<= 0 R)
     (<= 0 N)
     (<= 0 K)
     (= E 0)
     (= v_68 G))
      )
      (inv_main105 P2
             Y
             C1
             F
             K2
             X1
             F2
             H
             H2
             J
             A
             K1
             F1
             V
             E1
             P
             C2
             H1
             O1
             A2
             U1
             J1
             D2
             E2
             X
             Y1
             T1
             L
             G1
             I2
             S
             P1
             B2
             L2
             I1
             G
             v_68
             M
             A1
             G2
             N1
             S1
             N2
             U
             L1
             W
             J2
             W1
             Q
             Z1
             O
             Z
             C
             O2
             R1
             D1
             T
             V1
             B1
             M2
             I
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main116 K
             F1
             J1
             C2
             X
             G2
             A1
             P1
             R1
             S
             Q1
             D1
             O1
             N
             O
             B1
             I1
             D
             I2
             X1
             G1
             C1
             T1
             Y
             M
             E
             B2
             P
             E1
             R
             U
             B
             I
             M1
             S1
             T
             F2
             C
             J
             H2
             N1
             F
             L1
             V
             L
             A2
             W1
             U1
             A
             W
             E2
             J2
             Z1
             K1
             V1
             Z
             Q
             H
             G
             H1
             D2
             Y1)
        (and (= G2 8672)
     (not (= G2 8641))
     (not (= G2 8656))
     (not (= G2 8609))
     (not (= G2 8640))
     (not (= G2 8593))
     (not (= G2 8608))
     (not (= G2 8577))
     (not (= G2 8592))
     (not (= G2 8561))
     (not (= G2 8576))
     (not (= G2 8560))
     (not (= G2 8448))
     (not (= G2 8545))
     (not (= G2 8544))
     (not (= G2 8529))
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
     (<= 0 F2)
     (<= 0 Y1)
     (<= 0 S1)
     (<= 0 H1)
     (<= 0 T)
     (<= 0 Q)
     (<= 0 H)
     (<= 0 G)
     (not (= G2 8657))
     (= v_62 G2))
      )
      (inv_main453 K
             F1
             J1
             C2
             X
             G2
             A1
             P1
             R1
             S
             Q1
             D1
             O1
             N
             O
             B1
             I1
             D
             I2
             X1
             G1
             C1
             T1
             Y
             M
             E
             B2
             P
             E1
             R
             U
             B
             I
             M1
             S1
             T
             F2
             C
             J
             H2
             N1
             v_62
             L1
             V
             L
             A2
             W1
             U1
             A
             W
             E2
             J2
             Z1
             K1
             V1
             Z
             Q
             H
             G
             H1
             D2
             Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main116 R1
             H1
             F
             F2
             B
             K
             N1
             A1
             H2
             A
             V
             W
             D
             Y
             U1
             J1
             M
             V1
             X1
             T1
             K1
             C
             I
             G1
             G
             S1
             U
             J2
             C2
             F1
             Z1
             G2
             O1
             I2
             L
             C1
             S
             D1
             A2
             Z
             R
             H
             E1
             P
             D2
             E2
             L1
             N
             M1
             P1
             B1
             Y1
             T
             W1
             E
             B2
             I1
             J
             O
             X
             Q
             Q1)
        (and (not (= K 8657))
     (not (= K 8672))
     (not (= K 8641))
     (not (= K 8656))
     (not (= K 8609))
     (not (= K 8640))
     (not (= K 8593))
     (not (= K 8608))
     (not (= K 8577))
     (not (= K 8592))
     (not (= K 8561))
     (not (= K 8576))
     (not (= K 8560))
     (not (= K 8448))
     (not (= K 8545))
     (not (= K 8544))
     (not (= K 8529))
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
     (<= 0 Q1)
     (<= 0 I1)
     (<= 0 C1)
     (<= 0 X)
     (<= 0 S)
     (<= 0 O)
     (<= 0 L)
     (<= 0 J)
     (= K 8673)
     (= v_62 K))
      )
      (inv_main453 R1
             H1
             F
             F2
             B
             K
             N1
             A1
             H2
             A
             V
             W
             D
             Y
             U1
             J1
             M
             V1
             X1
             T1
             K1
             C
             I
             G1
             G
             S1
             U
             J2
             C2
             F1
             Z1
             G2
             O1
             I2
             L
             C1
             S
             D1
             A2
             Z
             R
             v_62
             E1
             P
             D2
             E2
             L1
             N
             M1
             P1
             B1
             Y1
             T
             W1
             E
             B2
             I1
             J
             O
             X
             Q
             Q1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main328 W
             T1
             B1
             P
             F1
             E2
             O1
             N
             Z1
             C2
             D1
             S1
             E
             G2
             X
             H2
             H
             Q1
             L1
             O
             J1
             T
             G
             M
             I1
             Z
             A1
             M1
             Y
             K1
             Y1
             E1
             K
             C1
             D
             C
             Q
             H1
             F
             A
             X1
             N1
             J2
             R
             B2
             V
             B
             I2
             D2
             F2
             U1
             A2
             V1
             U
             G1
             W1
             J
             I
             P1
             L
             R1
             S)
        (and (= O 0)
     (<= 0 P1)
     (<= 0 S)
     (<= 0 Q)
     (<= 0 L)
     (<= 0 J)
     (<= 0 I)
     (<= 0 D)
     (<= 0 C)
     (not (= L1 (- 1))))
      )
      (inv_main334 W
             T1
             B1
             P
             F1
             E2
             O1
             N
             Z1
             C2
             D1
             S1
             E
             G2
             X
             H2
             H
             Q1
             L1
             O
             J1
             T
             G
             M
             I1
             Z
             A1
             M1
             Y
             K1
             Y1
             E1
             K
             C1
             D
             C
             Q
             H1
             F
             A
             X1
             N1
             J2
             R
             B2
             V
             B
             I2
             D2
             F2
             U1
             A2
             V1
             U
             G1
             W1
             J
             I
             P1
             L
             R1
             S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main328 O
             K1
             B1
             A
             D2
             F
             Q1
             O1
             A2
             W1
             B
             J
             F1
             F2
             K
             L
             E
             I1
             Y1
             G2
             D
             T
             G1
             R
             C1
             S1
             H
             W
             N
             E2
             I
             T1
             E1
             Q
             Z1
             N1
             R1
             P1
             V1
             J1
             L1
             M
             X1
             D1
             S
             A1
             J2
             I2
             X
             U1
             H1
             V
             U
             C2
             Z
             C
             M1
             H2
             G
             P
             B2
             Y)
        (and (= Y1 (- 4))
     (not (= Y1 (- 1)))
     (<= 0 H2)
     (<= 0 Z1)
     (<= 0 R1)
     (<= 0 N1)
     (<= 0 M1)
     (<= 0 Y)
     (<= 0 P)
     (<= 0 G)
     (not (= G2 0)))
      )
      (inv_main334 O
             K1
             B1
             A
             D2
             F
             Q1
             O1
             A2
             W1
             B
             J
             F1
             F2
             K
             L
             E
             I1
             Y1
             G2
             D
             T
             G1
             R
             C1
             S1
             H
             W
             N
             E2
             I
             T1
             E1
             Q
             Z1
             N1
             R1
             P1
             V1
             J1
             L1
             M
             X1
             D1
             S
             A1
             J2
             I2
             X
             U1
             H1
             V
             U
             C2
             Z
             C
             M1
             H2
             G
             P
             B2
             Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main513 G2
             E2
             J2
             I1
             I
             Q
             R
             Q1
             C2
             A
             O
             T1
             V
             M1
             E1
             L
             K
             G
             V1
             M
             S1
             J1
             P1
             B1
             P
             D
             F2
             Z
             L1
             N
             F1
             B2
             S
             Y1
             F
             G1
             J
             N1
             D1
             Z1
             C
             Y
             O1
             E
             A2
             A1
             T
             X1
             X
             I2
             K1
             D2
             U
             H
             H2
             R1
             W
             W1
             U1
             C1
             H1
             B)
        (and (<= 0 U1)
     (<= 0 G1)
     (<= 0 C1)
     (<= 0 W)
     (<= 0 J)
     (<= 0 F)
     (<= 0 B)
     (<= 0 W1))
      )
      false
    )
  )
)

(check-sat)
(exit)
