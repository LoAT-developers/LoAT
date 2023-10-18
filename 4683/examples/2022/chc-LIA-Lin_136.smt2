; ./tricera/sv-comp-2020/./mixed/s3_srvr_6.cil-2.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main519| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main454| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main271| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main389| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main254| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main333| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main435| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main300| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main4| ( Int Int ) Bool)
(declare-fun |inv_main282| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main339| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main321| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main536| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main106| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main484| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main198| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main432| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main117| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main481| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

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
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 Z1
             U1
             E2
             C2
             J2
             G2
             N1
             H2
             H
             P
             I
             X1
             Q1
             Y1
             C1
             E1
             V
             S1
             R1
             A
             F2
             I2
             N
             M
             O
             D2
             B
             M1
             F1
             B1
             Y
             D
             T
             P1
             F
             U
             V1
             O1
             J1
             W
             A2
             G1
             H1
             L1
             K2
             K1
             Z
             Q
             E
             S
             W1
             I1
             G
             A1
             R
             J
             T1
             L
             K
             B2
             D1
             C)
        (and (not (= G2 16384))
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
     (= G2 8528)
     (not (= S1 (- 2097152)))
     (= X 1)
     (<= 0 B2)
     (<= 0 V1)
     (<= 0 T1)
     (<= 0 U)
     (<= 0 L)
     (<= 0 K)
     (<= 0 F)
     (<= 0 C)
     (not (= G2 12292))
     (= v_63 B1)
     (= v_64 G2)
     (= v_65 S1))
      )
      (inv_main300 Z1
             U1
             E2
             C2
             J2
             G2
             N1
             H2
             H
             P
             I
             X1
             Q1
             Y1
             C1
             E1
             V
             S1
             R1
             A
             F2
             I2
             N
             M
             O
             D2
             B
             X
             F1
             B1
             Y
             D
             T
             P1
             v_63
             U
             V1
             O1
             J1
             W
             A2
             v_64
             H1
             L1
             K2
             K1
             Z
             Q
             E
             S
             W1
             I1
             G
             A1
             R
             J
             T1
             v_65
             K
             B2
             D1
             C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 T1
             R
             E
             X
             Q
             P
             X1
             Y
             N
             A2
             U1
             L1
             J
             B
             G1
             E1
             Y1
             K2
             D
             Q1
             P1
             Z
             O
             N1
             C1
             J2
             K
             U
             T
             H
             A
             V1
             C
             Z1
             B2
             H2
             F
             A1
             H1
             C2
             J1
             D2
             B1
             L
             W1
             M1
             O1
             R1
             S1
             M
             F2
             G
             G2
             I
             I2
             I1
             D1
             W
             E2
             V
             F1
             S)
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
     (not (= P 8496))
     (not (= P 8497))
     (not (= P 8512))
     (not (= P 8513))
     (= P 8528)
     (= K2 (- 2097152))
     (<= 0 H2)
     (<= 0 E2)
     (<= 0 B2)
     (<= 0 D1)
     (<= 0 W)
     (<= 0 V)
     (<= 0 S)
     (<= 0 F)
     (= K1 0)
     (= v_63 H)
     (= v_64 P)
     (= v_65 K2))
      )
      (inv_main300 T1
             R
             E
             X
             Q
             P
             X1
             Y
             N
             A2
             U1
             L1
             J
             B
             G1
             E1
             Y1
             K2
             D
             Q1
             P1
             Z
             O
             N1
             C1
             J2
             K
             K1
             T
             H
             A
             V1
             C
             Z1
             v_63
             H2
             F
             A1
             H1
             C2
             J1
             v_64
             B1
             L
             W1
             M1
             O1
             R1
             S1
             M
             F2
             G
             G2
             I
             I2
             I1
             D1
             v_65
             E2
             V
             F1
             S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 J1
             J
             Z
             S1
             Y1
             Q1
             K1
             D
             C1
             N
             L1
             E1
             H2
             U
             T
             M
             M1
             V1
             G
             A
             K2
             P
             A2
             P1
             G2
             D1
             I1
             R1
             T1
             H1
             G1
             A1
             Z1
             F1
             Y
             V
             F
             J2
             E2
             R
             W1
             K
             D2
             B1
             B
             I
             X1
             H
             U1
             N1
             F2
             O1
             C
             B2
             I2
             W
             O
             E
             S
             C2
             Q
             X)
        (and (= Q1 8529)
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
     (= L 1)
     (<= 0 C2)
     (<= 0 Y)
     (<= 0 X)
     (<= 0 V)
     (<= 0 S)
     (<= 0 O)
     (<= 0 F)
     (<= 0 E)
     (not (= V1 (- 2097152)))
     (= v_63 H1)
     (= v_64 Q1)
     (= v_65 V1))
      )
      (inv_main300 J1
             J
             Z
             S1
             Y1
             Q1
             K1
             D
             C1
             N
             L1
             E1
             H2
             U
             T
             M
             M1
             V1
             G
             A
             K2
             P
             A2
             P1
             G2
             D1
             I1
             L
             T1
             H1
             G1
             A1
             Z1
             F1
             v_63
             V
             F
             J2
             E2
             R
             W1
             v_64
             D2
             B1
             B
             I
             X1
             H
             U1
             N1
             F2
             O1
             C
             B2
             I2
             W
             O
             v_65
             S
             C2
             Q
             X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main117 A
             L1
             M
             V1
             K1
             N
             E2
             F2
             Q1
             M1
             B2
             L
             W
             G1
             J1
             R1
             G2
             K2
             Z1
             C
             E1
             E
             I2
             Q
             J2
             Y1
             B1
             O1
             S
             S1
             F
             B
             H
             D
             F1
             X1
             A1
             U1
             K
             U
             T1
             Z
             P
             V
             H2
             H1
             D1
             G
             C1
             R
             Y
             X
             W1
             I1
             J
             N1
             T
             A2
             O
             C2
             P1
             I)
        (and (= N 8529)
     (not (= N 12292))
     (not (= N 16384))
     (not (= N 8192))
     (not (= N 24576))
     (not (= N 8195))
     (not (= N 8480))
     (not (= N 8481))
     (not (= N 8482))
     (not (= N 8464))
     (not (= N 8465))
     (not (= N 8466))
     (not (= N 8496))
     (not (= N 8497))
     (not (= N 8512))
     (not (= N 8513))
     (not (= N 8528))
     (= K2 (- 2097152))
     (<= 0 C2)
     (<= 0 A2)
     (<= 0 X1)
     (<= 0 F1)
     (<= 0 A1)
     (<= 0 T)
     (<= 0 O)
     (<= 0 I)
     (= D2 0)
     (= v_63 S1)
     (= v_64 N)
     (= v_65 K2))
      )
      (inv_main300 A
             L1
             M
             V1
             K1
             N
             E2
             F2
             Q1
             M1
             B2
             L
             W
             G1
             J1
             R1
             G2
             K2
             Z1
             C
             E1
             E
             I2
             Q
             J2
             Y1
             B1
             D2
             S
             S1
             F
             B
             H
             D
             v_63
             X1
             A1
             U1
             K
             U
             T1
             v_64
             P
             V
             H2
             H1
             D1
             G
             C1
             R
             Y
             X
             W1
             I1
             J
             N1
             T
             v_65
             O
             C2
             P1
             I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main198 O1
             H1
             S
             V1
             H2
             U1
             M1
             B2
             H
             R
             G1
             Q
             Z
             D2
             T
             W
             J2
             F1
             I2
             S1
             W1
             J1
             K
             E1
             I1
             X
             Y1
             O
             A2
             Y
             L
             C2
             P1
             U
             N
             V
             E
             A
             A1
             P
             T1
             D1
             R1
             C
             Z1
             K2
             C1
             G
             J
             B
             L1
             N1
             F
             B1
             F2
             K1
             Q1
             I
             M
             E2
             D
             G2)
        (and (= X1 0)
     (<= 0 G2)
     (<= 0 E2)
     (<= 0 Q1)
     (<= 0 V)
     (<= 0 N)
     (<= 0 M)
     (<= 0 I)
     (<= 0 E)
     (not (= Y1 0)))
      )
      (inv_main117 O1
             H1
             S
             V1
             H2
             U1
             M1
             B2
             H
             R
             G1
             Q
             Z
             D2
             T
             W
             J2
             F1
             I2
             S1
             W1
             J1
             K
             E1
             I1
             X
             Y1
             O
             A2
             Y
             L
             C2
             P1
             U
             N
             V
             E
             A
             A1
             P
             T1
             D1
             X1
             C
             Z1
             K2
             C1
             G
             J
             B
             L1
             N1
             F
             B1
             F2
             K1
             Q1
             I
             M
             E2
             D
             G2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main198 V1
             A2
             K
             D
             I1
             X
             B1
             E
             J
             S
             T1
             L1
             R
             C2
             H1
             A
             E2
             M1
             Z1
             Q
             F
             H
             C1
             M
             Y1
             Q1
             C
             J2
             P1
             B2
             G1
             I2
             V
             P
             J1
             N1
             O
             T
             B
             D2
             Z
             O1
             U1
             F1
             X1
             E1
             I
             F2
             K2
             D1
             L
             G
             W1
             R1
             K1
             S1
             A1
             W
             G2
             U
             Y
             N)
        (and (not (= U1 0))
     (= C 0)
     (<= 0 G2)
     (<= 0 N1)
     (<= 0 J1)
     (<= 0 A1)
     (<= 0 W)
     (<= 0 U)
     (<= 0 O)
     (<= 0 N)
     (= H2 0))
      )
      (inv_main117 V1
             A2
             K
             D
             I1
             X
             B1
             E
             J
             S
             T1
             L1
             R
             C2
             H1
             A
             E2
             M1
             Z1
             Q
             F
             H
             C1
             M
             Y1
             Q1
             C
             J2
             P1
             B2
             G1
             I2
             V
             P
             J1
             N1
             O
             T
             B
             D2
             Z
             O1
             H2
             F1
             X1
             E1
             I
             F2
             K2
             D1
             L
             G
             W1
             R1
             K1
             S1
             A1
             W
             G2
             U
             Y
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main519 B2
             P1
             I1
             O1
             R1
             N1
             F
             D1
             I
             E1
             O
             E
             S
             B1
             R
             V1
             C
             K2
             D2
             J
             I2
             Y
             G
             S1
             J1
             C1
             F2
             A2
             B
             X1
             M
             Z
             W
             H1
             D
             M1
             T1
             X
             L
             Y1
             F1
             C2
             H2
             A
             W1
             Q1
             Z1
             A1
             E2
             U
             L1
             K1
             K
             U1
             H
             P
             T
             G1
             Q
             G2
             V
             J2)
        (and (= N 0)
     (<= 0 G2)
     (<= 0 T1)
     (<= 0 M1)
     (<= 0 G1)
     (<= 0 T)
     (<= 0 Q)
     (<= 0 D)
     (<= 0 J2)
     (= X 0))
      )
      (inv_main117 B2
             P1
             I1
             O1
             R1
             N1
             F
             D1
             I
             E1
             O
             E
             S
             B1
             R
             V1
             C
             K2
             D2
             J
             I2
             Y
             G
             S1
             J1
             C1
             F2
             A2
             B
             X1
             M
             Z
             W
             H1
             D
             M1
             T1
             X
             L
             Y1
             F1
             C2
             N
             A
             W1
             Q1
             Z1
             A1
             E2
             U
             L1
             K1
             K
             U1
             H
             P
             T
             G1
             Q
             G2
             V
             J2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main519 U
             A2
             D
             I
             J2
             X
             Z
             P
             P1
             I1
             F2
             Q
             Y
             B1
             S
             W1
             G2
             W
             H2
             K1
             U1
             N
             A
             K2
             T
             E
             Q1
             N1
             L1
             A1
             T1
             C1
             M1
             J1
             D1
             J
             O
             Z1
             H
             G
             E2
             I2
             H1
             M
             S1
             F1
             R1
             D2
             R
             G1
             L
             Y1
             C
             E1
             O1
             V1
             C2
             X1
             B
             V
             B2
             K)
        (and (= X I2)
     (= F 0)
     (<= 0 C2)
     (<= 0 X1)
     (<= 0 D1)
     (<= 0 V)
     (<= 0 O)
     (<= 0 K)
     (<= 0 J)
     (<= 0 B)
     (not (= Z1 0)))
      )
      (inv_main117 U
             A2
             D
             I
             J2
             X
             Z
             P
             P1
             I1
             F2
             Q
             Y
             B1
             S
             W1
             G2
             W
             H2
             K1
             U1
             N
             A
             K2
             T
             E
             Q1
             N1
             L1
             A1
             T1
             C1
             M1
             J1
             D1
             J
             O
             Z1
             H
             G
             E2
             I2
             F
             M
             S1
             F1
             R1
             D2
             R
             G1
             L
             Y1
             C
             E1
             O1
             V1
             C2
             X1
             B
             V
             B2
             K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main519 T
             I2
             D2
             A1
             F1
             U1
             G1
             A2
             D1
             A
             L
             E
             Y
             S
             G
             Y1
             S1
             Q1
             X
             I1
             K2
             K
             F
             O1
             G2
             C
             C1
             W
             V1
             M1
             X1
             R
             H2
             N1
             J
             L1
             Z1
             U
             W1
             T1
             O
             P
             N
             K1
             F2
             Q
             C2
             E1
             R1
             V
             H1
             J2
             P1
             Z
             J1
             E2
             B1
             H
             I
             D
             M
             B2)
        (and (not (= U 0))
     (= B 0)
     (<= 0 B2)
     (<= 0 Z1)
     (<= 0 L1)
     (<= 0 B1)
     (<= 0 J)
     (<= 0 I)
     (<= 0 H)
     (<= 0 D)
     (not (= U1 P))
     (= v_63 U1))
      )
      (inv_main117 T
             I2
             D2
             A1
             F1
             U1
             G1
             A2
             D1
             A
             L
             E
             Y
             S
             G
             Y1
             S1
             Q1
             X
             I1
             K2
             K
             F
             O1
             G2
             C
             C1
             W
             V1
             M1
             X1
             R
             H2
             N1
             J
             L1
             Z1
             U
             W1
             T1
             v_63
             P
             B
             K1
             F2
             Q
             C2
             E1
             R1
             V
             H1
             J2
             P1
             Z
             J1
             E2
             B1
             H
             I
             D
             M
             B2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main106 A1
             P
             E2
             V1
             G1
             N
             I1
             H1
             U
             K2
             B1
             E1
             H
             O
             I2
             L
             T
             M
             B
             J
             P1
             A
             Y
             Z
             S
             K1
             X1
             B2
             Y1
             U1
             R
             V
             Q
             M1
             Q1
             L1
             T1
             X
             C2
             J1
             F
             D1
             D
             F1
             A2
             W
             G2
             I
             H2
             D2
             F2
             S1
             W1
             R1
             C
             N1
             K
             E
             J2
             Z1
             G
             C1)
        (and (= O1 (+ 1 G1))
     (not (= T 0))
     (<= 0 Z1)
     (<= 0 T1)
     (<= 0 Q1)
     (<= 0 L1)
     (<= 0 C1)
     (<= 0 K)
     (<= 0 E)
     (<= 0 J2)
     (= A2 (- 12288)))
      )
      (inv_main117 A1
             P
             E2
             V1
             O1
             N
             I1
             H1
             U
             K2
             B1
             E1
             H
             O
             I2
             L
             T
             M
             B
             J
             P1
             A
             Y
             Z
             S
             K1
             X1
             B2
             Y1
             U1
             R
             V
             Q
             M1
             Q1
             L1
             T1
             X
             C2
             J1
             F
             D1
             D
             F1
             A2
             W
             G2
             I
             H2
             D2
             F2
             S1
             W1
             R1
             C
             N1
             K
             E
             J2
             Z1
             G
             C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main106 Q1
             P1
             H1
             L
             T
             A1
             E2
             V1
             S
             R1
             L1
             O
             H
             C1
             K1
             W1
             B2
             F1
             I1
             Z
             Z1
             D
             B1
             H2
             U1
             G2
             X
             K
             J2
             J1
             K2
             P
             R
             F2
             I2
             W
             F
             I
             V
             D2
             E1
             G
             Q
             N1
             M1
             Y
             B
             J
             N
             T1
             C
             A2
             U
             G1
             C2
             O1
             S1
             D1
             Y1
             E
             A
             X1)
        (and (not (= M1 (- 12288)))
     (not (= Y (- 16384)))
     (= M (+ 1 T))
     (<= 0 I2)
     (<= 0 Y1)
     (<= 0 X1)
     (<= 0 S1)
     (<= 0 D1)
     (<= 0 W)
     (<= 0 F)
     (<= 0 E)
     (not (= B2 0)))
      )
      (inv_main117 Q1
             P1
             H1
             L
             M
             A1
             E2
             V1
             S
             R1
             L1
             O
             H
             C1
             K1
             W1
             B2
             F1
             I1
             Z
             Z1
             D
             B1
             H2
             U1
             G2
             X
             K
             J2
             J1
             K2
             P
             R
             F2
             I2
             W
             F
             I
             V
             D2
             E1
             G
             Q
             N1
             M1
             Y
             B
             J
             N
             T1
             C
             A2
             U
             G1
             C2
             O1
             S1
             D1
             Y1
             E
             A
             X1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main106 I1
             C1
             Y
             B2
             G2
             C
             H2
             L
             R
             S1
             M1
             M
             A1
             I2
             N1
             B
             K
             R1
             H
             N
             W1
             X
             A
             W
             T1
             V1
             J2
             E
             J1
             Y1
             V
             G
             S
             F
             F2
             O1
             U
             I
             B1
             Q1
             A2
             K1
             C2
             J
             E2
             U1
             G1
             H1
             L1
             D2
             Q
             F1
             E1
             Z
             P
             P1
             K2
             O
             T
             D1
             X1
             D)
        (and (= Z1 (+ 1 G2))
     (= U1 (- 16384))
     (not (= K 0))
     (<= 0 F2)
     (<= 0 O1)
     (<= 0 D1)
     (<= 0 U)
     (<= 0 T)
     (<= 0 O)
     (<= 0 D)
     (<= 0 K2)
     (not (= E2 (- 12288))))
      )
      (inv_main117 I1
             C1
             Y
             B2
             Z1
             C
             H2
             L
             R
             S1
             M1
             M
             A1
             I2
             N1
             B
             K
             R1
             H
             N
             W1
             X
             A
             W
             T1
             V1
             J2
             E
             J1
             Y1
             V
             G
             S
             F
             F2
             O1
             U
             I
             B1
             Q1
             A2
             K1
             C2
             J
             E2
             U1
             G1
             H1
             L1
             D2
             Q
             F1
             E1
             Z
             P
             P1
             K2
             O
             T
             D1
             X1
             D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main481 V1
             A2
             K
             R
             J
             L
             U
             M1
             C1
             G2
             Y1
             P
             U1
             B
             D1
             I1
             B1
             L2
             F
             J1
             Y
             S
             S1
             N1
             L1
             O
             G
             X
             K1
             I2
             I
             G1
             H2
             X1
             D
             N
             E2
             E1
             W1
             M
             O1
             R1
             E
             D2
             P1
             J2
             C2
             Q
             Z
             H
             Q1
             F2
             T
             A1
             H1
             C
             K2
             V
             A
             F1
             Z1
             T1)
        (and (= H1 11)
     (<= 0 A)
     (<= 0 E2)
     (<= 0 T1)
     (<= 0 F1)
     (<= 0 V)
     (<= 0 N)
     (<= 0 D)
     (<= 0 K2)
     (= B2 12))
      )
      (inv_main484 V1
             A2
             K
             R
             J
             L
             U
             M1
             C1
             G2
             Y1
             P
             U1
             B
             D1
             I1
             B1
             L2
             F
             J1
             Y
             S
             S1
             N1
             L1
             O
             G
             X
             K1
             I2
             I
             G1
             H2
             X1
             D
             N
             E2
             E1
             W1
             W
             O1
             R1
             E
             D2
             P1
             J2
             C2
             Q
             Z
             H
             Q1
             F2
             T
             A1
             B2
             C
             K2
             V
             A
             F1
             Z1
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main481 G
             J2
             X1
             S
             E
             P1
             E1
             C1
             T1
             Y
             R1
             O
             L1
             C2
             C
             B
             W
             J1
             Q1
             N1
             H2
             A1
             B1
             B2
             F2
             P
             G2
             A
             H
             L
             I
             W1
             A2
             U
             K1
             D2
             M
             I1
             V1
             E2
             R
             X
             K
             G1
             Y1
             Z1
             S1
             O1
             H1
             F
             K2
             Z
             T
             V
             N
             D
             F1
             Q
             J
             L2
             M1
             D1)
        (and (= N 14)
     (not (= N 11))
     (<= 0 D2)
     (<= 0 K1)
     (<= 0 F1)
     (<= 0 D1)
     (<= 0 Q)
     (<= 0 M)
     (<= 0 J)
     (<= 0 L2)
     (= U1 15))
      )
      (inv_main484 G
             J2
             X1
             S
             E
             P1
             E1
             C1
             T1
             Y
             R1
             O
             L1
             C2
             C
             B
             W
             J1
             Q1
             N1
             H2
             A1
             B1
             B2
             F2
             P
             G2
             A
             H
             L
             I
             W1
             A2
             U
             K1
             D2
             M
             I1
             V1
             I2
             R
             X
             K
             G1
             Y1
             Z1
             S1
             O1
             H1
             F
             K2
             Z
             T
             V
             U1
             D
             F1
             Q
             J
             L2
             M1
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main481 F2
             L2
             W
             Y
             I1
             D
             D2
             Q
             K
             U
             X1
             M1
             A2
             T
             M
             B
             R1
             N1
             C2
             J1
             Q1
             C1
             N
             L1
             S
             J2
             R
             J
             V1
             C
             V
             I
             H1
             T1
             W1
             S1
             A1
             E
             B1
             P1
             G1
             Y1
             Z1
             H2
             Z
             F1
             O
             U1
             K2
             B2
             L
             O1
             F
             I2
             G2
             E2
             E1
             D1
             A
             P
             H
             G)
        (and (not (= G2 14))
     (not (= G2 11))
     (= K1 18)
     (<= 0 A)
     (<= 0 W1)
     (<= 0 S1)
     (<= 0 E1)
     (<= 0 D1)
     (<= 0 A1)
     (<= 0 P)
     (<= 0 G)
     (= G2 17))
      )
      (inv_main484 F2
             L2
             W
             Y
             I1
             D
             D2
             Q
             K
             U
             X1
             M1
             A2
             T
             M
             B
             R1
             N1
             C2
             J1
             Q1
             C1
             N
             L1
             S
             J2
             R
             J
             V1
             C
             V
             I
             H1
             T1
             W1
             S1
             A1
             E
             B1
             X
             G1
             Y1
             Z1
             H2
             Z
             F1
             O
             U1
             K2
             B2
             L
             O1
             F
             I2
             K1
             E2
             E1
             D1
             A
             P
             H
             G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main481 D
             J2
             A
             Q
             M
             F1
             I1
             B1
             A2
             F2
             W1
             Z1
             C1
             N
             S1
             R
             T
             W
             F
             C
             H
             X1
             C2
             G
             I2
             O1
             A1
             Y1
             S
             E1
             X
             L1
             Z
             U1
             H1
             N1
             D1
             U
             P1
             T1
             B2
             Y
             V1
             H2
             V
             L2
             G2
             J
             G1
             Q1
             J1
             K2
             P
             O
             E
             L
             I
             D2
             E2
             K1
             R1
             B)
        (and (= E 20)
     (not (= E 17))
     (not (= E 14))
     (not (= E 11))
     (<= 0 E2)
     (<= 0 D2)
     (<= 0 N1)
     (<= 0 K1)
     (<= 0 H1)
     (<= 0 D1)
     (<= 0 I)
     (<= 0 B)
     (= M1 21))
      )
      (inv_main484 D
             J2
             A
             Q
             M
             F1
             I1
             B1
             A2
             F2
             W1
             Z1
             C1
             N
             S1
             R
             T
             W
             F
             C
             H
             X1
             C2
             G
             I2
             O1
             A1
             Y1
             S
             E1
             X
             L1
             Z
             U1
             H1
             N1
             D1
             U
             P1
             K
             B2
             Y
             V1
             H2
             V
             L2
             G2
             J
             G1
             Q1
             J1
             K2
             P
             O
             M1
             L
             I
             D2
             E2
             K1
             R1
             B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main481 I
             U
             C1
             B
             O1
             C
             Y1
             N1
             Q1
             E
             L1
             A
             A1
             F1
             W
             Y
             K1
             A2
             E2
             J2
             D2
             V1
             K
             C2
             G2
             J
             J1
             S
             H
             H1
             V
             Z
             H2
             B1
             S1
             Q
             M
             N
             T
             Z1
             F
             G1
             E1
             P1
             M1
             U1
             P
             D1
             G
             I2
             R
             F2
             X
             R1
             B2
             L
             I1
             D
             W1
             X1
             O
             T1)
        (and (not (= B2 17))
     (not (= B2 14))
     (not (= B2 11))
     (<= 0 X1)
     (<= 0 W1)
     (<= 0 T1)
     (<= 0 S1)
     (<= 0 I1)
     (<= 0 Q)
     (<= 0 M)
     (<= 0 D)
     (not (= B2 20)))
      )
      (inv_main484 I
             U
             C1
             B
             O1
             C
             Y1
             N1
             Q1
             E
             L1
             A
             A1
             F1
             W
             Y
             K1
             A2
             E2
             J2
             D2
             V1
             K
             C2
             G2
             J
             J1
             S
             H
             H1
             V
             Z
             H2
             B1
             S1
             Q
             M
             N
             T
             K2
             F
             G1
             E1
             P1
             M1
             U1
             P
             D1
             G
             I2
             R
             F2
             X
             R1
             B2
             L
             I1
             D
             W1
             X1
             O
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 I1 O)
        (and (not (= S1 0))
     (= M1 1)
     (= A1 0)
     (= R (- 1))
     (= L 0)
     (= G 8464)
     (= A 8464)
     (= K2 8464)
     (<= 0 I2)
     (<= 0 F2)
     (<= 0 U1)
     (<= 0 T1)
     (<= 0 G1)
     (<= 0 D1)
     (<= 0 S)
     (<= 0 D)
     (= V1 0)
     (= v_63 H2)
     (= v_64 S1))
      )
      (inv_main106 A
             O
             K2
             S1
             Y
             G
             L1
             G2
             Z
             U
             C1
             N
             P
             M1
             Q1
             J
             O1
             B2
             X
             W
             Z1
             X1
             M
             E
             C
             K1
             V
             B
             A2
             B1
             F1
             Q
             I
             K
             S
             H2
             v_63
             v_64
             R1
             R
             H1
             C2
             A1
             L
             D2
             F
             J2
             Y1
             E2
             W1
             T
             J1
             P1
             H
             V1
             E1
             U1
             D
             D1
             F2
             N1
             G1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 I1 E1)
        (and (= Z1 8464)
     (= T1 0)
     (= K1 1)
     (= C1 0)
     (= B1 0)
     (not (= Z 0))
     (= Y 0)
     (= K 8464)
     (= I (- 1))
     (<= 0 Y1)
     (<= 0 U1)
     (<= 0 O1)
     (<= 0 N1)
     (<= 0 F1)
     (<= 0 D1)
     (<= 0 J)
     (<= 0 E)
     (= F2 8464)
     (= v_63 P1)
     (= v_64 Z))
      )
      (inv_main106 Z1
             E1
             K
             T1
             H2
             F2
             W
             N
             V
             V1
             D2
             A2
             R1
             K1
             Q
             Q1
             T
             A
             G1
             S
             S1
             Z
             X
             R
             W1
             H1
             M1
             F
             O
             M
             X1
             H
             P
             E2
             N1
             P1
             v_63
             v_64
             L
             I
             G
             B2
             Y
             C1
             L1
             I2
             G2
             C2
             C
             U
             D
             J2
             J1
             K2
             B1
             B
             Y1
             D1
             J
             F1
             A1
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 E H)
        (and (= Y1 0)
     (= S1 8464)
     (= Q1 8464)
     (= O1 (- 1))
     (= K1 1)
     (= X 0)
     (= M 0)
     (= I 0)
     (= B 0)
     (= K2 0)
     (<= 0 V1)
     (<= 0 C1)
     (<= 0 S)
     (<= 0 P)
     (<= 0 O)
     (<= 0 N)
     (<= 0 L)
     (<= 0 D)
     (= F2 8464)
     (= v_64 L1))
      )
      (inv_main106 S1
             H
             F2
             B
             B2
             Q1
             Z1
             B1
             F
             I1
             I2
             K
             J2
             K1
             T
             R
             X1
             L2
             D2
             M1
             Y
             I
             W1
             G
             H2
             V
             Q
             D1
             U1
             E2
             A
             J
             P1
             H1
             C1
             L1
             v_64
             M
             A1
             O1
             R1
             A2
             K2
             Y1
             E1
             J1
             G1
             C
             U
             C2
             N1
             F1
             Z
             G2
             X
             T1
             V1
             P
             D
             O
             W
             S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 S1
             U
             O
             X
             L
             R
             J1
             C1
             D1
             D
             J2
             V
             H
             B
             G1
             I1
             F1
             S
             P
             B2
             A
             G2
             K
             N1
             B1
             M1
             W
             L1
             K1
             E1
             T
             F2
             Q1
             A1
             Q
             V1
             J
             D2
             I
             R1
             X1
             E
             M
             U1
             F
             Y
             E2
             P1
             Z
             C
             C2
             W1
             Z1
             G
             O1
             A2
             T1
             N
             H2
             Y1
             H1
             I2)
        (and (not (= R 8545))
     (not (= R 8560))
     (not (= R 8561))
     (not (= R 8448))
     (not (= R 8576))
     (not (= R 8577))
     (not (= R 8592))
     (not (= R 8593))
     (not (= R 8608))
     (not (= R 8609))
     (not (= R 8640))
     (not (= R 8641))
     (= R 8656)
     (not (= R 8529))
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
     (<= 0 H2)
     (<= 0 Y1)
     (<= 0 V1)
     (<= 0 T1)
     (<= 0 Q)
     (<= 0 N)
     (<= 0 J)
     (<= 0 I2)
     (not (= R 8544))
     (= v_62 R))
      )
      (inv_main454 S1
             U
             O
             X
             L
             R
             J1
             C1
             D1
             D
             J2
             V
             H
             B
             G1
             I1
             F1
             S
             P
             B2
             A
             G2
             K
             N1
             B1
             M1
             W
             L1
             K1
             E1
             T
             F2
             Q1
             A1
             Q
             V1
             J
             D2
             I
             R1
             X1
             v_62
             M
             U1
             F
             Y
             E2
             P1
             Z
             C
             C2
             W1
             Z1
             G
             O1
             A2
             T1
             N
             H2
             Y1
             H1
             I2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 L
             W1
             D2
             K1
             U
             K
             Q1
             Z
             C1
             J2
             T
             I1
             Y
             Y1
             O
             H1
             C
             C2
             I2
             Z1
             J
             A2
             O1
             P
             I
             D
             G2
             X
             X1
             H
             R1
             G1
             Q
             F
             E
             W
             N1
             N
             R
             L1
             P1
             J1
             T1
             E1
             B1
             E2
             D1
             S
             H2
             A1
             G
             M1
             S1
             M
             F2
             U1
             B2
             F1
             B
             V
             V1
             A)
        (and (not (= K 8544))
     (not (= K 8545))
     (not (= K 8560))
     (not (= K 8561))
     (not (= K 8448))
     (not (= K 8576))
     (not (= K 8577))
     (not (= K 8592))
     (not (= K 8593))
     (not (= K 8608))
     (not (= K 8609))
     (not (= K 8640))
     (not (= K 8641))
     (not (= K 8656))
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
     (<= 0 B2)
     (<= 0 N1)
     (<= 0 F1)
     (<= 0 W)
     (<= 0 V)
     (<= 0 E)
     (<= 0 B)
     (<= 0 A)
     (= K 8657)
     (= v_62 K))
      )
      (inv_main454 L
             W1
             D2
             K1
             U
             K
             Q1
             Z
             C1
             J2
             T
             I1
             Y
             Y1
             O
             H1
             C
             C2
             I2
             Z1
             J
             A2
             O1
             P
             I
             D
             G2
             X
             X1
             H
             R1
             G1
             Q
             F
             E
             W
             N1
             N
             R
             L1
             P1
             v_62
             T1
             E1
             B1
             E2
             D1
             S
             H2
             A1
             G
             M1
             S1
             M
             F2
             U1
             B2
             F1
             B
             V
             V1
             A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main432 X1
             Q1
             S1
             C2
             R
             K
             L2
             A
             N1
             R1
             W
             F1
             M
             G1
             E1
             L
             Z
             Y1
             B
             K2
             D
             A2
             D1
             E
             W1
             V
             Y
             O
             Q
             V1
             H
             J1
             H2
             D2
             I
             H1
             U
             J2
             I1
             F
             B1
             F2
             P
             S
             G2
             P1
             X
             C
             B2
             K1
             M1
             T1
             U1
             T
             L1
             I2
             A1
             E2
             G
             O1
             C1
             J)
        (and (= N 10)
     (<= 0 E2)
     (<= 0 O1)
     (<= 0 H1)
     (<= 0 A1)
     (<= 0 U)
     (<= 0 J)
     (<= 0 I)
     (<= 0 G)
     (= L1 9))
      )
      (inv_main435 X1
             Q1
             S1
             C2
             R
             K
             L2
             A
             N1
             R1
             W
             F1
             M
             G1
             E1
             L
             Z
             Y1
             B
             K2
             D
             A2
             D1
             E
             W1
             V
             Y
             O
             Q
             V1
             H
             J1
             H2
             D2
             I
             H1
             U
             J2
             I1
             Z1
             B1
             F2
             P
             S
             G2
             P1
             X
             C
             B2
             K1
             M1
             T1
             U1
             T
             N
             I2
             A1
             E2
             G
             O1
             C1
             J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main432 J
             X
             C
             J1
             D
             H1
             P1
             N1
             D1
             Y1
             F2
             Z1
             L
             D2
             R1
             B
             I2
             K1
             L2
             G
             B2
             Q
             A2
             M1
             W1
             M
             I1
             F
             P
             V
             U
             W
             U1
             B1
             G1
             F1
             K
             Z
             V1
             K2
             X1
             O
             T
             T1
             N
             Y
             C1
             E
             H2
             A
             L1
             O1
             I
             S
             H
             R
             G2
             J2
             E2
             A1
             C2
             Q1)
        (and (not (= H 9))
     (= H 12)
     (<= 0 J2)
     (<= 0 G2)
     (<= 0 E2)
     (<= 0 Q1)
     (<= 0 G1)
     (<= 0 F1)
     (<= 0 A1)
     (<= 0 K)
     (= E1 13))
      )
      (inv_main435 J
             X
             C
             J1
             D
             H1
             P1
             N1
             D1
             Y1
             F2
             Z1
             L
             D2
             R1
             B
             I2
             K1
             L2
             G
             B2
             Q
             A2
             M1
             W1
             M
             I1
             F
             P
             V
             U
             W
             U1
             B1
             G1
             F1
             K
             Z
             V1
             S1
             X1
             O
             T
             T1
             N
             Y
             C1
             E
             H2
             A
             L1
             O1
             I
             S
             E1
             R
             G2
             J2
             E2
             A1
             C2
             Q1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main432 K1
             H1
             Z
             M1
             F1
             D2
             U1
             F
             A2
             A1
             N1
             L2
             T
             Q
             D1
             J2
             M
             S
             X
             R
             F2
             X1
             R1
             B2
             B
             J
             D
             W1
             L1
             L
             I
             K2
             C2
             P1
             W
             E2
             H2
             T1
             Y
             C
             O1
             O
             J1
             S1
             G1
             G
             N
             U
             H
             C1
             P
             Z1
             E
             E1
             A
             V
             V1
             G2
             I1
             K
             Q1
             I2)
        (and (= A 15)
     (not (= A 12))
     (= Y1 16)
     (<= 0 I2)
     (<= 0 H2)
     (<= 0 G2)
     (<= 0 E2)
     (<= 0 V1)
     (<= 0 I1)
     (<= 0 W)
     (<= 0 K)
     (not (= A 9)))
      )
      (inv_main435 K1
             H1
             Z
             M1
             F1
             D2
             U1
             F
             A2
             A1
             N1
             L2
             T
             Q
             D1
             J2
             M
             S
             X
             R
             F2
             X1
             R1
             B2
             B
             J
             D
             W1
             L1
             L
             I
             K2
             C2
             P1
             W
             E2
             H2
             T1
             Y
             B1
             O1
             O
             J1
             S1
             G1
             G
             N
             U
             H
             C1
             P
             Z1
             E
             E1
             Y1
             V
             V1
             G2
             I1
             K
             Q1
             I2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main432 J1
             X1
             D1
             H2
             T
             X
             D2
             U1
             B
             V1
             Z
             G1
             Z1
             S1
             K2
             O
             Q
             I1
             E1
             N1
             V
             R
             W1
             L
             E2
             C1
             O1
             M1
             J
             H1
             K
             U
             P
             J2
             A2
             A1
             D
             K1
             N
             E
             I
             C2
             I2
             W
             C
             H
             Q1
             L1
             M
             A
             B1
             B2
             T1
             P1
             G2
             Y1
             S
             F2
             G
             F1
             F
             R1)
        (and (= G2 18)
     (not (= G2 15))
     (not (= G2 12))
     (= Y 19)
     (<= 0 F2)
     (<= 0 A2)
     (<= 0 R1)
     (<= 0 F1)
     (<= 0 A1)
     (<= 0 S)
     (<= 0 G)
     (<= 0 D)
     (not (= G2 9)))
      )
      (inv_main435 J1
             X1
             D1
             H2
             T
             X
             D2
             U1
             B
             V1
             Z
             G1
             Z1
             S1
             K2
             O
             Q
             I1
             E1
             N1
             V
             R
             W1
             L
             E2
             C1
             O1
             M1
             J
             H1
             K
             U
             P
             J2
             A2
             A1
             D
             K1
             N
             L2
             I
             C2
             I2
             W
             C
             H
             Q1
             L1
             M
             A
             B1
             B2
             T1
             P1
             Y
             Y1
             S
             F2
             G
             F1
             F
             R1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main432 N
             F2
             X1
             P1
             Q
             C
             Y
             U1
             N1
             K
             T
             Z
             L1
             B
             J
             K2
             E1
             O1
             H1
             J2
             S
             R
             I1
             R1
             M
             I
             H2
             C1
             H
             Z1
             J1
             G2
             E
             D2
             S1
             P
             D
             F1
             G
             O
             M1
             K1
             V1
             Q1
             U
             L
             G1
             A
             B2
             A2
             X
             D1
             W
             B1
             I2
             F
             T1
             Y1
             E2
             W1
             A1
             V)
        (and (not (= I2 21))
     (not (= I2 18))
     (not (= I2 15))
     (not (= I2 12))
     (<= 0 E2)
     (<= 0 Y1)
     (<= 0 W1)
     (<= 0 T1)
     (<= 0 S1)
     (<= 0 V)
     (<= 0 P)
     (<= 0 D)
     (not (= I2 9)))
      )
      (inv_main435 N
             F2
             X1
             P1
             Q
             C
             Y
             U1
             N1
             K
             T
             Z
             L1
             B
             J
             K2
             E1
             O1
             H1
             J2
             S
             R
             I1
             R1
             M
             I
             H2
             C1
             H
             Z1
             J1
             G2
             E
             D2
             S1
             P
             D
             F1
             G
             C2
             M1
             K1
             V1
             Q1
             U
             L
             G1
             A
             B2
             A2
             X
             D1
             W
             B1
             I2
             F
             T1
             Y1
             E2
             W1
             A1
             V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main117 W1
             U
             B2
             R
             F1
             J2
             U1
             S1
             A1
             K2
             P1
             O1
             I1
             L1
             J1
             D1
             D2
             C
             G2
             B
             H
             K
             T
             A
             Z1
             E2
             K1
             W
             Y
             A2
             D
             V
             O
             T1
             X1
             V1
             F2
             H2
             M
             P
             C2
             M1
             B1
             S
             I2
             N
             C1
             N1
             J
             Q
             G
             H1
             Z
             R1
             L
             F
             G1
             X
             Y1
             E
             Q1
             E1)
        (and (not (= J2 12292))
     (not (= J2 16384))
     (not (= J2 8192))
     (not (= J2 24576))
     (not (= J2 8195))
     (not (= J2 8480))
     (not (= J2 8481))
     (= J2 8482)
     (<= 0 F2)
     (<= 0 Y1)
     (<= 0 X1)
     (<= 0 V1)
     (<= 0 G1)
     (<= 0 E1)
     (<= 0 X)
     (<= 0 E)
     (= I 3))
      )
      (inv_main198 W1
             U
             B2
             R
             F1
             I
             U1
             S1
             A1
             K2
             P1
             O1
             I1
             L1
             J1
             D1
             D2
             C
             G2
             B
             H
             K
             T
             A
             Z1
             E2
             K1
             W
             Y
             A2
             D
             V
             O
             T1
             X1
             V1
             F2
             H2
             M
             P
             C2
             J2
             B1
             S
             I2
             N
             C1
             N1
             J
             Q
             G
             H1
             Z
             R1
             L
             F
             G1
             X
             Y1
             E
             Q1
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main117 I
             N
             I1
             B2
             F2
             C1
             V
             O1
             J
             Z
             A2
             N1
             S
             O2
             T
             O
             L1
             Y1
             H
             W1
             M
             D2
             N2
             H2
             D
             F1
             B1
             X1
             P
             K2
             F
             A1
             Y
             M1
             K
             Q
             H1
             X
             K1
             S1
             C
             I2
             D1
             G
             C2
             P1
             G1
             R1
             E
             V1
             Q1
             A
             B
             J2
             L
             Z1
             E1
             J1
             U1
             T1
             W
             M2)
        (and (= G2 8448)
     (not (= C1 12292))
     (not (= C1 16384))
     (not (= C1 8192))
     (not (= C1 24576))
     (not (= C1 8195))
     (= C1 8480)
     (= U 8482)
     (= R 0)
     (<= 0 M2)
     (<= 0 U1)
     (<= 0 T1)
     (<= 0 J1)
     (<= 0 H1)
     (<= 0 E1)
     (<= 0 Q)
     (<= 0 K)
     (not (<= E2 0))
     (= L2 0))
      )
      (inv_main198 I
             N
             I1
             B2
             F2
             G2
             V
             O1
             J
             Z
             R
             N1
             S
             O2
             T
             L2
             L1
             Y1
             H
             W1
             M
             D2
             N2
             H2
             D
             F1
             B1
             X1
             P
             K2
             U
             A1
             Y
             M1
             K
             Q
             H1
             X
             K1
             E2
             C
             C1
             D1
             G
             C2
             P1
             G1
             R1
             E
             V1
             Q1
             A
             B
             J2
             L
             Z1
             E1
             J1
             U1
             T1
             W
             M2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main117 X
             J
             O1
             D
             M
             S
             B
             C
             P
             Z1
             L1
             L2
             A
             I2
             N
             E
             Y1
             I
             Q
             T1
             J2
             D2
             L
             U1
             S1
             P1
             Y
             B1
             H2
             R
             G1
             N1
             K2
             W1
             E2
             H1
             F
             A1
             D1
             H
             C2
             T
             V
             N2
             M2
             G2
             F2
             R1
             B2
             Z
             Q1
             U
             W
             C1
             O2
             M1
             G
             K1
             O
             E1
             A2
             F1)
        (and (= V1 0)
     (= I1 8482)
     (not (= S 12292))
     (not (= S 16384))
     (not (= S 8192))
     (not (= S 24576))
     (not (= S 8195))
     (not (= S 8480))
     (= S 8481)
     (= K 8448)
     (<= 0 E2)
     (<= 0 K1)
     (<= 0 H1)
     (<= 0 F1)
     (<= 0 E1)
     (<= 0 O)
     (<= 0 G)
     (<= 0 F)
     (not (<= J1 0))
     (= X1 0))
      )
      (inv_main198 X
             J
             O1
             D
             M
             K
             B
             C
             P
             Z1
             V1
             L2
             A
             I2
             N
             X1
             Y1
             I
             Q
             T1
             J2
             D2
             L
             U1
             S1
             P1
             Y
             B1
             H2
             R
             I1
             N1
             K2
             W1
             E2
             H1
             F
             A1
             D1
             J1
             C2
             S
             V
             N2
             M2
             G2
             F2
             R1
             B2
             Z
             Q1
             U
             W
             C1
             O2
             M1
             G
             K1
             O
             E1
             A2
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main117 W
             O
             L1
             M1
             J1
             U
             X1
             C2
             E
             H1
             E1
             T1
             J
             F2
             W1
             I
             R
             X
             P
             G2
             L2
             J2
             S
             B2
             I2
             K1
             R1
             S1
             U1
             G1
             P1
             E2
             I1
             V
             L
             Q
             Z
             M
             A2
             A
             N2
             F
             T
             D1
             Z1
             Y
             D2
             H2
             H
             C1
             A1
             O1
             K2
             V1
             F1
             Q1
             B
             K
             B1
             M2
             N
             G)
        (and (= N1 8576)
     (not (= U 8544))
     (not (= U 8545))
     (= U 8560)
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
     (= D 8448)
     (<= 0 B)
     (<= 0 B1)
     (<= 0 Z)
     (<= 0 Q)
     (<= 0 L)
     (<= 0 K)
     (<= 0 G)
     (<= 0 M2)
     (not (<= C 0))
     (= Y1 0))
      )
      (inv_main198 W
             O
             L1
             M1
             J1
             D
             X1
             C2
             E
             H1
             Y1
             T1
             J
             F2
             W1
             I
             R
             X
             P
             G2
             L2
             J2
             S
             B2
             I2
             K1
             R1
             S1
             U1
             G1
             N1
             E2
             I1
             V
             L
             Q
             Z
             M
             A2
             C
             N2
             U
             T
             D1
             Z1
             Y
             D2
             H2
             H
             C1
             A1
             O1
             K2
             V1
             F1
             Q1
             B
             K
             B1
             M2
             N
             G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main117 M1
             A2
             X1
             E1
             R
             S1
             K2
             H2
             J
             P
             G2
             W
             M2
             D1
             C
             O1
             M
             K
             I2
             Y
             T
             N2
             O
             N
             V1
             L2
             E
             Q
             F
             U1
             C2
             S
             F2
             U
             J2
             K1
             R1
             A
             X
             B
             L
             J1
             G
             H1
             H
             P1
             D
             G1
             B2
             I1
             W1
             A1
             Z
             V
             T1
             D2
             Z1
             C1
             E2
             N1
             B1
             I)
        (and (not (= S1 8545))
     (not (= S1 8560))
     (= S1 8561)
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
     (= Q1 8448)
     (= L1 0)
     (= F1 8576)
     (<= 0 J2)
     (<= 0 E2)
     (<= 0 Z1)
     (<= 0 R1)
     (<= 0 N1)
     (<= 0 K1)
     (<= 0 C1)
     (<= 0 I)
     (not (<= Y1 0))
     (not (= S1 8544)))
      )
      (inv_main198 M1
             A2
             X1
             E1
             R
             Q1
             K2
             H2
             J
             P
             L1
             W
             M2
             D1
             C
             O1
             M
             K
             I2
             Y
             T
             N2
             O
             N
             V1
             L2
             E
             Q
             F
             U1
             F1
             S
             F2
             U
             J2
             K1
             R1
             A
             X
             Y1
             L
             S1
             G
             H1
             H
             P1
             D
             G1
             B2
             I1
             W1
             A1
             Z
             V
             T1
             D2
             Z1
             C1
             E2
             N1
             B1
             I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main254 G2
             N1
             N2
             K2
             D1
             J1
             F2
             O
             C1
             F1
             O2
             B
             R
             O1
             H1
             P
             Q1
             S
             J2
             E2
             U
             V1
             M
             K
             M2
             F
             E1
             T1
             X1
             A1
             W
             I1
             P1
             C2
             L
             X
             B2
             G1
             S1
             Z
             J
             A2
             Q
             K1
             L1
             A
             Y1
             I
             E
             Y
             I2
             L2
             N
             C
             V
             B1
             H
             Z1
             R1
             G
             D2
             M1)
        (and (= H2 0)
     (= W1 0)
     (= U1 1)
     (= V 0)
     (= P2 1)
     (<= 0 B2)
     (<= 0 Z1)
     (<= 0 R1)
     (<= 0 M1)
     (<= 0 X)
     (<= 0 L)
     (<= 0 H)
     (<= 0 G)
     (not (<= T 0))
     (= D 8496))
      )
      (inv_main198 G2
             N1
             N2
             K2
             D1
             D
             F2
             O
             C1
             F1
             H2
             B
             R
             O1
             H1
             W1
             Q1
             S
             J2
             E2
             U
             V1
             M
             K
             M2
             F
             E1
             T1
             X1
             A1
             W
             I1
             P1
             C2
             L
             X
             B2
             G1
             S1
             T
             J
             A2
             Q
             P2
             L1
             A
             Y1
             I
             E
             Y
             I2
             L2
             N
             C
             U1
             B1
             H
             Z1
             R1
             G
             D2
             M1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main254 D
             O
             Y
             E2
             D2
             A2
             T1
             X
             E1
             L2
             R1
             R
             V
             P
             I
             H2
             P1
             Q
             Z1
             F1
             T
             C
             M2
             U1
             I2
             F
             U
             D1
             M1
             H1
             B2
             B
             H
             W
             N
             J
             Z
             G2
             J2
             L1
             J1
             N1
             L
             B1
             Y1
             X1
             A1
             K1
             F2
             O1
             K
             C1
             I1
             Q1
             G
             N2
             W1
             S
             G1
             K2
             E
             M)
        (and (= C2 8496)
     (= V1 0)
     (= S1 0)
     (not (= G 0))
     (<= 0 K2)
     (<= 0 W1)
     (<= 0 G1)
     (<= 0 Z)
     (<= 0 S)
     (<= 0 N)
     (<= 0 M)
     (<= 0 J)
     (not (<= O2 0))
     (= A 1))
      )
      (inv_main198 D
             O
             Y
             E2
             D2
             C2
             T1
             X
             E1
             L2
             S1
             R
             V
             P
             I
             V1
             P1
             Q
             Z1
             F1
             T
             C
             M2
             U1
             I2
             F
             U
             D1
             M1
             H1
             B2
             B
             H
             W
             N
             J
             Z
             G2
             J2
             O2
             J1
             N1
             L
             A
             Y1
             X1
             A1
             K1
             F2
             O1
             K
             C1
             I1
             Q1
             G
             N2
             W1
             S
             G1
             K2
             E
             M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main271 U
             E
             V
             R1
             W
             Q
             A
             I1
             O1
             K2
             M
             H2
             E1
             L1
             Y1
             N1
             L
             B1
             X1
             B2
             I
             E2
             B
             W1
             H1
             Z
             X
             N
             C
             T
             C2
             F2
             O
             J2
             S1
             M1
             G
             C1
             K
             S
             F1
             D2
             J
             F
             Z1
             K1
             Y
             V1
             J1
             I2
             A1
             G2
             Q1
             A2
             P
             D1
             D
             H
             G1
             T1
             R
             P1)
        (and (= U1 0)
     (= L2 8656)
     (<= 0 T1)
     (<= 0 S1)
     (<= 0 P1)
     (<= 0 M1)
     (<= 0 G1)
     (<= 0 H)
     (<= 0 G)
     (<= 0 D)
     (not (<= S 0))
     (not (= H2 0)))
      )
      (inv_main198 U
             E
             V
             R1
             W
             L2
             A
             I1
             O1
             K2
             U1
             H2
             E1
             L1
             Y1
             N1
             L
             B1
             X1
             B2
             I
             E2
             B
             W1
             H1
             Z
             X
             N
             C
             T
             C2
             F2
             O
             J2
             S1
             M1
             G
             C1
             K
             S
             F1
             D2
             J
             F
             Z1
             K1
             Y
             V1
             J1
             I2
             A1
             G2
             Q1
             A2
             P
             D1
             D
             H
             G1
             T1
             R
             P1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main271 I2
             K2
             J
             P
             X
             G2
             H1
             S1
             E
             L2
             B2
             M
             W1
             G
             Q1
             X1
             R1
             K1
             U1
             R
             V
             G1
             A1
             J1
             F1
             K
             H2
             B
             P1
             Q
             I1
             E2
             O
             Z
             Z1
             W
             C2
             A2
             O1
             N
             L1
             N1
             C
             B1
             J2
             V1
             T
             Y
             F
             H
             T1
             S
             A
             M1
             D
             D1
             L
             U
             I
             C1
             F2
             D2)
        (and (= E1 8512)
     (= M 0)
     (<= 0 D2)
     (<= 0 C2)
     (<= 0 Z1)
     (<= 0 C1)
     (<= 0 W)
     (<= 0 U)
     (<= 0 L)
     (<= 0 I)
     (not (<= N 0))
     (= Y1 0))
      )
      (inv_main198 I2
             K2
             J
             P
             X
             E1
             H1
             S1
             E
             L2
             Y1
             M
             W1
             G
             Q1
             X1
             R1
             K1
             U1
             R
             V
             G1
             A1
             J1
             F1
             K
             H2
             B
             P1
             Q
             I1
             E2
             O
             Z
             Z1
             W
             C2
             A2
             O1
             N
             L1
             N1
             C
             B1
             J2
             V1
             T
             Y
             F
             H
             T1
             S
             A
             M1
             D
             D1
             L
             U
             I
             C1
             F2
             D2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main282 O1
             Q
             J
             A1
             W1
             D
             B2
             H1
             S1
             I1
             I
             U1
             V1
             H2
             E
             C2
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
             J2
             T1
             I2
             D1
             C
             E2
             M
             G1
             X1
             W
             K2
             N
             U
             A
             M2
             R1
             Y1
             P
             A2
             K1
             B
             M1
             K
             B1
             T
             F2
             Z1
             S
             G2)
        (and (not (= Q1 (- 256)))
     (= G 0)
     (= L2 1)
     (<= 0 I2)
     (<= 0 G2)
     (<= 0 F2)
     (<= 0 Z1)
     (<= 0 T1)
     (<= 0 D1)
     (<= 0 B1)
     (<= 0 T)
     (= D2 8528)
     (= v_65 Q1))
      )
      (inv_main198 O1
             Q
             J
             A1
             W1
             D2
             B2
             H1
             S1
             I1
             G
             U1
             V1
             H2
             E
             C2
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
             J2
             T1
             I2
             D1
             C
             E2
             M
             G1
             X1
             L2
             K2
             N
             U
             A
             M2
             R1
             Y1
             P
             A2
             K1
             B
             M1
             K
             v_65
             T
             F2
             Z1
             S
             G2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main282 R1
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
        (and (= M1 2)
     (= W (- 256))
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
     (= A2 8528)
     (= v_66 W))
      )
      (inv_main198 R1
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
             C1
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
             I
             A1
             v_66
             E1
             F2
             Q1
             H1
             K1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main282 F1
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
        (and (not (= Q1 2))
     (= C1 0)
     (= G (- 256))
     (<= 0 K2)
     (<= 0 G2)
     (<= 0 F2)
     (<= 0 A2)
     (<= 0 M1)
     (<= 0 I1)
     (<= 0 E1)
     (<= 0 O)
     (not (<= H2 0))
     (= U1 8528)
     (= v_65 G))
      )
      (inv_main198 F1
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
             v_65
             F2
             O
             I1
             R
             K2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 U
             H2
             R1
             P1
             M1
             L
             B2
             P
             L1
             T
             K1
             E2
             C2
             I
             W
             U1
             G2
             B1
             H
             B
             J1
             A1
             D2
             X
             J2
             I1
             F1
             V1
             Z1
             H1
             J
             O
             N1
             G1
             Q1
             T1
             R
             V
             E1
             A
             A2
             E
             M
             I2
             D1
             G
             K
             W1
             C1
             O1
             S1
             N
             Z
             C
             Y
             Q
             Y1
             X1
             F
             F2
             D
             S)
        (and (not (= L 8545))
     (not (= L 8560))
     (not (= L 8561))
     (= L 8448)
     (not (= L 8529))
     (not (= L 12292))
     (not (= L 16384))
     (not (= L 8192))
     (not (= L 24576))
     (not (= L 8195))
     (not (= L 8480))
     (not (= L 8481))
     (not (= L 8482))
     (not (= L 8464))
     (not (= L 8465))
     (not (= L 8466))
     (not (= L 8496))
     (not (= L 8497))
     (not (= L 8512))
     (not (= L 8513))
     (not (= L 8528))
     (not (<= 1 E1))
     (<= 0 F2)
     (<= 0 Y1)
     (<= 0 X1)
     (<= 0 T1)
     (<= 0 Q1)
     (<= 0 S)
     (<= 0 R)
     (<= 0 F)
     (not (= L 8544))
     (= v_62 J))
      )
      (inv_main198 U
             H2
             R1
             P1
             M1
             J
             B2
             P
             L1
             T
             K1
             E2
             C2
             I
             W
             U1
             G2
             B1
             H
             B
             J1
             A1
             D2
             X
             J2
             I1
             F1
             V1
             Z1
             H1
             v_62
             O
             N1
             G1
             Q1
             T1
             R
             V
             E1
             A
             A2
             L
             M
             I2
             D1
             G
             K
             W1
             C1
             O1
             S1
             N
             Z
             C
             Y
             Q
             Y1
             X1
             F
             F2
             D
             S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main117 O1
             C1
             M1
             K1
             W1
             A
             H
             T1
             T
             I
             G2
             K
             J2
             H1
             E2
             U1
             W
             N1
             B1
             F2
             R1
             M
             S1
             D2
             F1
             C
             D
             L
             U
             Z1
             G
             K2
             I1
             J
             C2
             V1
             O
             P1
             X1
             R
             Z
             J1
             H2
             V
             B2
             I2
             Y1
             L1
             E1
             A1
             Q1
             P
             Q
             Y
             S
             N
             E
             D1
             B
             F
             G1
             A2)
        (and (not (= A 8544))
     (not (= A 8545))
     (not (= A 8560))
     (not (= A 8561))
     (= A 8448)
     (not (= A 8529))
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
     (<= 1 X1)
     (<= 0 C2)
     (<= 0 A2)
     (<= 0 V1)
     (<= 0 D1)
     (<= 0 O)
     (<= 0 F)
     (<= 0 E)
     (<= 0 B)
     (not (<= P 0))
     (= X 1)
     (= v_63 G)
     (= v_64 P))
      )
      (inv_main198 O1
             C1
             M1
             K1
             W1
             G
             H
             T1
             T
             I
             G2
             K
             X
             H1
             E2
             U1
             W
             N1
             B1
             F2
             R1
             M
             S1
             D2
             F1
             C
             D
             L
             U
             Z1
             v_63
             K2
             I1
             J
             C2
             V1
             O
             P1
             P
             R
             Z
             A
             H2
             V
             B2
             I2
             Y1
             L1
             E1
             A1
             Q1
             v_64
             Q
             Y
             S
             N
             E
             D1
             B
             F
             G1
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main389 Z
             S
             Q
             S1
             M1
             P1
             Y1
             A
             J2
             Z1
             D1
             C
             B
             E2
             H2
             K1
             U1
             D2
             P
             V
             K2
             E
             F1
             N1
             G2
             I2
             J
             H1
             Y
             K
             I
             M
             R1
             G
             N
             L1
             U
             Q1
             T1
             L
             E1
             C2
             O
             I1
             B2
             B1
             X1
             C1
             D
             O1
             G1
             T
             R
             X
             A2
             J1
             W
             F
             A1
             H
             V1
             W1)
        (and (= L 2)
     (<= 0 W1)
     (<= 0 L1)
     (<= 0 A1)
     (<= 0 W)
     (<= 0 U)
     (<= 0 N)
     (<= 0 H)
     (<= 0 F)
     (not (<= L 0))
     (= F2 8466))
      )
      (inv_main198 Z
             S
             Q
             S1
             M1
             F2
             Y1
             A
             J2
             Z1
             D1
             C
             B
             E2
             H2
             K1
             U1
             D2
             P
             V
             K2
             E
             F1
             N1
             G2
             I2
             J
             H1
             Y
             K
             I
             M
             R1
             G
             N
             L1
             U
             Q1
             T1
             L
             E1
             C2
             O
             I1
             B2
             B1
             X1
             C1
             D
             O1
             G1
             T
             R
             X
             A2
             J1
             W
             F
             A1
             H
             V1
             W1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main389 E1
             I1
             V
             Q
             X
             D
             F
             V1
             J
             L
             W
             H
             I2
             I
             A2
             U1
             O
             Y
             D2
             F1
             A1
             Z1
             H2
             S
             P
             M1
             E2
             G
             H1
             G2
             N
             N2
             P1
             R1
             M
             J1
             L1
             Z
             N1
             X1
             T
             K1
             W1
             J2
             K
             L2
             C2
             B2
             S1
             E
             B
             O1
             T1
             R
             D1
             C1
             C
             K2
             F2
             G1
             U
             B1)
        (and (= Y1 7)
     (not (= X1 2))
     (= D1 6)
     (= M2 8592)
     (<= 0 C)
     (<= 0 K2)
     (<= 0 F2)
     (<= 0 L1)
     (<= 0 J1)
     (<= 0 G1)
     (<= 0 B1)
     (<= 0 M)
     (not (<= X1 0))
     (not (<= Q1 0))
     (= A 0))
      )
      (inv_main198 E1
             I1
             V
             Q
             X
             M2
             F
             V1
             J
             L
             A
             H
             I2
             I
             A2
             U1
             O
             Y
             D2
             F1
             A1
             Z1
             H2
             S
             P
             M1
             E2
             G
             H1
             G2
             N
             N2
             P1
             R1
             M
             J1
             L1
             Z
             N1
             Q1
             T
             K1
             W1
             J2
             K
             L2
             C2
             B2
             S1
             E
             B
             O1
             T1
             R
             Y1
             C1
             C
             K2
             F2
             G1
             U
             B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main389 B2
             Q1
             B1
             O1
             L2
             N1
             Q
             T
             J1
             F2
             X
             D1
             F
             H2
             M
             G2
             H1
             M2
             I2
             N
             J2
             K
             T1
             J
             C1
             P1
             D
             C
             V
             X1
             W1
             D2
             M1
             S
             G
             L1
             U
             E1
             I
             R
             U1
             A
             F1
             G1
             L
             Y1
             P
             V1
             O
             A1
             E
             E2
             C2
             Z
             B
             A2
             H
             Y
             K1
             R1
             S1
             K2)
        (and (= Z1 0)
     (= W 8592)
     (not (= R 2))
     (<= 0 K2)
     (<= 0 R1)
     (<= 0 L1)
     (<= 0 K1)
     (<= 0 Y)
     (<= 0 U)
     (<= 0 H)
     (<= 0 G)
     (not (<= I1 0))
     (not (<= R 0))
     (not (= B 6)))
      )
      (inv_main198 B2
             Q1
             B1
             O1
             L2
             W
             Q
             T
             J1
             F2
             Z1
             D1
             F
             H2
             M
             G2
             H1
             M2
             I2
             N
             J2
             K
             T1
             J
             C1
             P1
             D
             C
             V
             X1
             W1
             D2
             M1
             S
             G
             L1
             U
             E1
             I
             I1
             U1
             A
             F1
             G1
             L
             Y1
             P
             V1
             O
             A1
             E
             E2
             C2
             Z
             B
             A2
             H
             Y
             K1
             R1
             S1
             K2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main435 Z
             L
             H
             C
             I1
             M
             O1
             W1
             A1
             T1
             D
             R
             I2
             J
             I
             J2
             P
             K
             F1
             H2
             D2
             U
             B1
             V1
             Y
             F2
             L2
             K2
             L1
             E1
             V
             X
             E
             F
             T
             H1
             S
             N1
             D1
             E2
             A
             S1
             A2
             C1
             C2
             P1
             B2
             G2
             Y1
             M1
             R1
             Q
             Q1
             U1
             X1
             Z1
             K1
             G1
             B
             J1
             O
             G)
        (and (not (= R 0))
     (= N 0)
     (<= 0 K1)
     (<= 0 J1)
     (<= 0 H1)
     (<= 0 G1)
     (<= 0 T)
     (<= 0 S)
     (<= 0 G)
     (<= 0 B)
     (not (<= E2 0))
     (= W 3))
      )
      (inv_main198 Z
             L
             H
             C
             I1
             W
             O1
             W1
             A1
             T1
             N
             R
             I2
             J
             I
             J2
             P
             K
             F1
             H2
             D2
             U
             B1
             V1
             Y
             F2
             L2
             K2
             L1
             E1
             V
             X
             E
             F
             T
             H1
             S
             N1
             D1
             E2
             A
             S1
             A2
             C1
             C2
             P1
             B2
             G2
             Y1
             M1
             R1
             Q
             Q1
             U1
             X1
             Z1
             K1
             G1
             B
             J1
             O
             G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main435 B2
             U1
             F
             K1
             B1
             C1
             C2
             M
             G
             J
             X1
             E
             L1
             G1
             A2
             Y
             K2
             Q1
             B
             K
             G2
             D1
             N
             D
             R1
             L2
             J1
             W1
             N1
             H2
             P1
             D2
             I2
             I1
             I
             E2
             S1
             T
             A1
             Q
             P
             X
             F1
             R
             T1
             M1
             O1
             O
             L
             V
             F2
             Z
             C
             H1
             S
             H
             E1
             W
             V1
             A
             J2
             Y1)
        (and (= U 0)
     (= E 0)
     (<= 0 A)
     (<= 0 E2)
     (<= 0 Y1)
     (<= 0 V1)
     (<= 0 S1)
     (<= 0 E1)
     (<= 0 W)
     (<= 0 I)
     (not (<= Q 0))
     (= Z1 8656))
      )
      (inv_main198 B2
             U1
             F
             K1
             B1
             Z1
             C2
             M
             G
             J
             U
             E
             L1
             G1
             A2
             Y
             K2
             Q1
             B
             K
             G2
             D1
             N
             D
             R1
             L2
             J1
             W1
             N1
             H2
             P1
             D2
             I2
             I1
             I
             E2
             S1
             T
             A1
             Q
             P
             X
             F1
             R
             T1
             M1
             O1
             O
             L
             V
             F2
             Z
             C
             H1
             S
             H
             E1
             W
             V1
             A
             J2
             Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main484 Y
             R1
             P
             W
             U1
             C2
             B2
             H
             A1
             S
             F
             L
             K2
             T1
             D1
             W1
             D2
             J1
             K
             B
             U
             M1
             I
             N1
             T
             C
             Y1
             X
             K1
             I1
             E2
             X1
             H2
             A2
             Z
             V1
             D
             M2
             E
             Z1
             F1
             G1
             G
             J2
             A
             L2
             I2
             M
             J
             G2
             H1
             V
             O
             O1
             Q
             B1
             E1
             S1
             F2
             L1
             N
             Q1)
        (and (= C1 8640)
     (= R 0)
     (not (= L 0))
     (<= 0 F2)
     (<= 0 V1)
     (<= 0 S1)
     (<= 0 Q1)
     (<= 0 L1)
     (<= 0 E1)
     (<= 0 Z)
     (<= 0 D)
     (not (<= Z1 0))
     (= P1 8448))
      )
      (inv_main198 Y
             R1
             P
             W
             U1
             P1
             B2
             H
             A1
             S
             R
             L
             K2
             T1
             D1
             W1
             D2
             J1
             K
             B
             U
             M1
             I
             N1
             T
             C
             Y1
             X
             K1
             I1
             C1
             X1
             H2
             A2
             Z
             V1
             D
             M2
             E
             Z1
             F1
             G1
             G
             J2
             A
             L2
             I2
             M
             J
             G2
             H1
             V
             O
             O1
             Q
             B1
             E1
             S1
             F2
             L1
             N
             Q1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main484 D1
             H
             L
             C1
             C2
             B2
             M2
             Q1
             A2
             A1
             S1
             U
             M
             V1
             K
             V
             S
             Y
             Z1
             X
             K1
             M1
             F2
             R
             Q
             D
             C
             J1
             F
             B
             T
             W1
             K2
             G2
             F1
             L1
             I2
             J2
             E2
             J
             G
             N
             G1
             Y1
             T1
             I1
             X1
             D2
             B1
             W
             H1
             R1
             H2
             E
             P
             A
             P1
             O1
             L2
             Z
             O
             U1)
        (and (= E1 3)
     (= U 0)
     (= I 0)
     (<= 0 I2)
     (<= 0 U1)
     (<= 0 P1)
     (<= 0 O1)
     (<= 0 L1)
     (<= 0 F1)
     (<= 0 Z)
     (<= 0 L2)
     (not (<= J 0))
     (= N1 8448))
      )
      (inv_main198 D1
             H
             L
             C1
             C2
             N1
             M2
             Q1
             A2
             A1
             I
             U
             M
             V1
             K
             V
             S
             Y
             Z1
             X
             K1
             M1
             F2
             R
             Q
             D
             C
             J1
             F
             B
             E1
             W1
             K2
             G2
             F1
             L1
             I2
             J2
             E2
             J
             G
             N
             G1
             Y1
             T1
             I1
             X1
             D2
             B1
             W
             H1
             R1
             H2
             E
             P
             A
             P1
             O1
             L2
             Z
             O
             U1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main300 R1
             C
             U
             N1
             L
             K2
             H2
             M1
             F
             M2
             I1
             H
             O1
             I2
             T
             S1
             Y
             J
             G1
             I
             E2
             S
             K
             N
             C1
             P
             K1
             M
             V1
             D2
             H1
             O
             B2
             B
             F1
             B1
             P1
             U1
             G2
             A2
             C2
             X
             J2
             Z1
             J1
             W
             E
             L1
             R
             G
             Q
             A
             D
             V
             Y1
             X1
             L2
             Q1
             A1
             E1
             W1
             F2)
        (and (= F1 (- 30))
     (= F1 (- 1))
     (= D1 8544)
     (= Z 0)
     (= M 0)
     (<= 0 F2)
     (<= 0 Q1)
     (<= 0 P1)
     (<= 0 F1)
     (<= 0 E1)
     (<= 0 B1)
     (<= 0 A1)
     (<= 0 L2)
     (= T1 1))
      )
      (inv_main198 R1
             C
             U
             N1
             L
             D1
             H2
             M1
             F
             M2
             Z
             H
             O1
             I2
             T
             S1
             Y
             J
             G1
             I
             E2
             S
             K
             N
             C1
             P
             K1
             M
             V1
             D2
             H1
             O
             B2
             B
             F1
             B1
             P1
             U1
             G2
             A2
             C2
             X
             T1
             Z1
             J1
             W
             E
             L1
             R
             G
             Q
             A
             D
             V
             Y1
             X1
             L2
             Q1
             A1
             E1
             W1
             F2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main300 S
             C2
             A1
             Z
             H1
             B1
             J2
             K2
             B2
             H
             M
             H2
             E2
             G2
             T
             I2
             G
             I1
             X1
             X
             D
             U1
             F2
             F1
             R
             K1
             D2
             E
             Q
             B
             R1
             N
             S1
             V
             I
             P
             G1
             K
             O1
             L
             F
             M1
             W1
             O
             C1
             M2
             U
             E1
             J
             A2
             P1
             C
             Z1
             L2
             N1
             T1
             D1
             Q1
             A
             Y
             W
             V1)
        (and (= L1 1)
     (= J1 8544)
     (= N (- 2))
     (= I (- 30))
     (not (= I (- 1)))
     (= E 0)
     (not (= D 0))
     (<= 0 A)
     (<= 0 V1)
     (<= 0 Q1)
     (<= 0 G1)
     (<= 0 D1)
     (<= 0 Y)
     (<= 0 P)
     (<= 0 I)
     (= Y1 0)
     (= v_65 N))
      )
      (inv_main198 S
             C2
             A1
             Z
             H1
             J1
             J2
             K2
             B2
             H
             Y1
             H2
             E2
             G2
             T
             I2
             G
             I1
             X1
             X
             D
             U1
             F2
             F1
             R
             K1
             D2
             E
             Q
             B
             R1
             N
             S1
             V
             I
             P
             G1
             K
             O1
             L
             F
             M1
             L1
             O
             C1
             M2
             U
             E1
             J
             A2
             P1
             C
             Z1
             L2
             N1
             T1
             D1
             Q1
             v_65
             Y
             W
             V1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main300 W
             D1
             O2
             F1
             R
             Y
             A2
             O
             X1
             K1
             B1
             C
             F2
             Q
             J
             I2
             T
             M
             J2
             H2
             E
             V
             M1
             E2
             Z1
             S
             Q1
             W1
             M2
             Y1
             D
             O1
             N1
             H
             E1
             B
             S1
             Z
             N2
             U
             I
             D2
             I1
             L1
             P
             B2
             C2
             J1
             X
             H1
             A
             P1
             L2
             F
             N
             K2
             L
             C1
             G2
             G1
             V1
             K)
        (and (= W1 0)
     (= U1 8544)
     (= T1 512)
     (not (= O1 (- 4)))
     (not (= O1 (- 2)))
     (= E1 (- 30))
     (not (= E1 (- 1)))
     (= A1 1)
     (= G 0)
     (not (= E 0))
     (not (>= H1 65))
     (<= 0 B)
     (<= 0 G2)
     (<= 0 S1)
     (<= 0 G1)
     (<= 0 E1)
     (<= 0 C1)
     (<= 0 L)
     (<= 0 K)
     (= (+ R1 (* (- 8) H1)) 0)
     (= v_67 O1)
     (= v_68 O1))
      )
      (inv_main198 W
             D1
             O2
             F1
             R
             U1
             A2
             O
             X1
             K1
             G
             C
             F2
             Q
             J
             I2
             T
             M
             J2
             H2
             E
             V
             M1
             E2
             Z1
             S
             Q1
             W1
             M2
             Y1
             D
             O1
             N1
             H
             E1
             B
             S1
             Z
             N2
             U
             I
             D2
             A1
             L1
             P
             B2
             C2
             J1
             X
             H1
             T1
             P1
             L2
             F
             N
             K2
             L
             C1
             v_67
             v_68
             R1
             K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main300 J
             F1
             X1
             S1
             G2
             P
             C1
             E1
             G1
             N2
             Y
             F
             K
             B
             I2
             W
             K1
             I
             U
             H1
             N1
             L
             P1
             T1
             W1
             H
             V1
             O2
             F2
             L1
             E
             L2
             O1
             A2
             C
             B1
             M
             Z1
             D1
             M2
             D
             R1
             V
             S
             H2
             M1
             E2
             Q1
             J1
             C2
             I1
             Z
             U1
             T
             Y1
             D2
             R
             B2
             K2
             Q
             N
             X)
        (and (= C (- 30))
     (not (= C (- 1)))
     (= L2 (- 4))
     (not (= L2 (- 2)))
     (= J2 0)
     (not (= N1 0))
     (= A1 1)
     (= O 8544)
     (= G 1024)
     (= O2 0)
     (not (>= C2 129))
     (<= 0 C)
     (<= 0 K2)
     (<= 0 B2)
     (<= 0 B1)
     (<= 0 X)
     (<= 0 R)
     (<= 0 Q)
     (<= 0 M)
     (= (+ A (* (- 8) C2)) 0)
     (= v_67 L2)
     (= v_68 L2))
      )
      (inv_main198 J
             F1
             X1
             S1
             G2
             O
             C1
             E1
             G1
             N2
             J2
             F
             K
             B
             I2
             W
             K1
             I
             U
             H1
             N1
             L
             P1
             T1
             W1
             H
             V1
             O2
             F2
             L1
             E
             L2
             O1
             A2
             C
             B1
             M
             Z1
             D1
             M2
             D
             R1
             A1
             S
             H2
             M1
             E2
             Q1
             J1
             C2
             G
             Z
             U1
             T
             Y1
             D2
             R
             B2
             v_67
             v_68
             A
             X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main321 G
             D2
             G1
             D1
             N
             R1
             E2
             K
             H2
             P1
             I1
             M
             U1
             Z1
             J1
             W1
             A
             O
             V1
             C1
             J2
             I
             A2
             C2
             E
             I2
             L2
             A1
             W
             Q
             T1
             C
             B1
             R
             S1
             L
             G2
             F
             H
             B2
             Y
             L1
             V
             O1
             M1
             B
             F1
             F2
             K2
             E1
             X
             Q1
             U
             Y1
             S
             D
             N1
             N2
             M2
             P
             J
             Z)
        (and (= H1 8544)
     (= T 0)
     (= S 3)
     (<= 0 G2)
     (<= 0 S1)
     (<= 0 N1)
     (<= 0 Z)
     (<= 0 P)
     (<= 0 L)
     (<= 0 N2)
     (<= 0 M2)
     (not (<= K1 0))
     (= X1 4))
      )
      (inv_main198 G
             D2
             G1
             D1
             N
             H1
             E2
             K
             H2
             P1
             T
             M
             U1
             Z1
             J1
             W1
             A
             O
             V1
             C1
             J2
             I
             A2
             C2
             E
             I2
             L2
             A1
             W
             Q
             T1
             C
             B1
             R
             S1
             L
             G2
             F
             H
             K1
             Y
             L1
             V
             O1
             M1
             B
             F1
             F2
             K2
             E1
             X
             Q1
             U
             Y1
             X1
             D
             N1
             N2
             M2
             P
             J
             Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main321 J2
             H
             T1
             L1
             E1
             U
             B1
             Y1
             P
             U1
             Z
             A2
             J1
             J
             P1
             B
             M1
             D1
             L
             W
             G1
             B2
             C1
             Q1
             O
             R1
             H1
             M2
             C2
             D2
             D
             E
             M
             F2
             V1
             V
             I2
             I1
             Z1
             A
             Y
             C
             N1
             T
             K
             S
             N
             X
             A1
             O1
             G2
             E2
             F1
             L2
             R
             X1
             S1
             W1
             H2
             G
             Q
             F)
        (and (= K1 0)
     (not (= R 3))
     (<= 0 I2)
     (<= 0 H2)
     (<= 0 W1)
     (<= 0 V1)
     (<= 0 S1)
     (<= 0 V)
     (<= 0 G)
     (<= 0 F)
     (not (<= I 0))
     (= K2 8544))
      )
      (inv_main198 J2
             H
             T1
             L1
             E1
             K2
             B1
             Y1
             P
             U1
             K1
             A2
             J1
             J
             P1
             B
             M1
             D1
             L
             W
             G1
             B2
             C1
             Q1
             O
             R1
             H1
             M2
             C2
             D2
             D
             E
             M
             F2
             V1
             V
             I2
             I1
             Z1
             I
             Y
             C
             N1
             T
             K
             S
             N
             X
             A1
             O1
             G2
             E2
             F1
             L2
             R
             X1
             S1
             W1
             H2
             G
             Q
             F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main333 P
             R
             B1
             H1
             D
             V
             Q
             C2
             E2
             K1
             I
             Y
             I2
             J2
             F
             E
             D2
             O
             N1
             N
             M1
             F2
             K
             P1
             A
             L2
             B
             X1
             D1
             M
             T1
             H2
             S1
             Y1
             M2
             T
             X
             J1
             V1
             C
             Q1
             G2
             U
             B2
             W1
             F1
             S
             W
             K2
             U1
             C1
             A2
             E1
             J
             L1
             H
             Z
             I1
             G
             O1
             L
             A1)
        (and (= R1 1)
     (not (= N1 (- 4)))
     (not (= N1 (- 1)))
     (= G1 0)
     (not (= N 0))
     (<= 0 O1)
     (<= 0 I1)
     (<= 0 A1)
     (<= 0 Z)
     (<= 0 X)
     (<= 0 T)
     (<= 0 G)
     (<= 0 M2)
     (= Z1 8560))
      )
      (inv_main198 P
             R
             B1
             H1
             D
             Z1
             Q
             C2
             E2
             K1
             I
             Y
             I2
             J2
             F
             E
             D2
             O
             N1
             N
             M1
             F2
             K
             P1
             A
             G1
             B
             X1
             D1
             M
             T1
             H2
             S1
             Y1
             M2
             T
             X
             J1
             V1
             C
             Q1
             G2
             R1
             B2
             W1
             F1
             S
             W
             K2
             U1
             C1
             A2
             E1
             J
             L1
             H
             Z
             I1
             G
             O1
             L
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main339 N
             C2
             G1
             H2
             D2
             T
             H1
             K2
             Y1
             K
             B2
             J
             F1
             D1
             C1
             Q
             Z1
             F
             J2
             Q1
             E1
             P
             F2
             X1
             P1
             I1
             K1
             B1
             G2
             A
             R
             S1
             V
             R1
             M1
             M
             J1
             A1
             O1
             D
             G
             T1
             L2
             E
             L1
             O
             L
             I
             W
             A2
             U
             N1
             C
             B
             S
             E2
             W1
             U1
             V1
             Z
             H
             I2)
        (and (= J2 (- 2))
     (= Y 1)
     (= X 8560)
     (= M2 0)
     (<= 0 I2)
     (<= 0 W1)
     (<= 0 V1)
     (<= 0 U1)
     (<= 0 M1)
     (<= 0 J1)
     (<= 0 Z)
     (<= 0 M)
     (not (= A (- 256)))
     (= v_65 A))
      )
      (inv_main198 N
             C2
             G1
             H2
             D2
             X
             H1
             K2
             Y1
             K
             B2
             J
             F1
             D1
             C1
             Q
             Z1
             F
             J2
             Q1
             E1
             P
             F2
             X1
             P1
             M2
             K1
             B1
             G2
             A
             R
             S1
             V
             R1
             M1
             M
             J1
             A1
             O1
             D
             G
             T1
             Y
             E
             L1
             O
             L
             I
             W
             A2
             U
             N1
             C
             B
             S
             E2
             W1
             U1
             V1
             Z
             H
             v_65)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main333 B1
             C
             E2
             A1
             J1
             L
             N1
             R
             A2
             L1
             X1
             E
             F2
             F1
             D2
             X
             C2
             Y1
             R1
             T1
             J
             S
             Y
             G2
             Z1
             H
             V
             Z
             I1
             D
             A
             M2
             N
             P
             S1
             L2
             K
             F
             I
             J2
             M
             U1
             G
             V1
             H1
             P1
             H2
             B
             I2
             Q1
             D1
             E1
             K1
             K2
             O1
             U
             W1
             M1
             Q
             G1
             B2
             C1)
        (and (= W 1)
     (= T 0)
     (= O 8560)
     (<= 0 W1)
     (<= 0 S1)
     (<= 0 M1)
     (<= 0 G1)
     (<= 0 C1)
     (<= 0 Q)
     (<= 0 K)
     (<= 0 L2)
     (= R1 (- 1)))
      )
      (inv_main198 B1
             C
             E2
             A1
             J1
             O
             N1
             R
             A2
             L1
             X1
             E
             F2
             F1
             D2
             X
             C2
             Y1
             R1
             T1
             J
             S
             Y
             G2
             Z1
             T
             V
             Z
             I1
             D
             A
             M2
             N
             P
             S1
             L2
             K
             F
             I
             J2
             M
             U1
             W
             V1
             H1
             P1
             H2
             B
             I2
             Q1
             D1
             E1
             K1
             K2
             O1
             U
             W1
             M1
             Q
             G1
             B2
             C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main339 P
             C1
             W1
             B
             T1
             H
             W
             E1
             Q1
             M2
             V
             R
             M1
             D2
             P1
             N
             Z1
             I
             D1
             Q
             I1
             M
             D
             K2
             C2
             F2
             R1
             E2
             S1
             B1
             B2
             N2
             S
             O
             G
             Y1
             F1
             J
             N1
             A2
             L
             U1
             P2
             A1
             C
             X1
             J2
             K1
             E
             Z
             T
             H2
             G2
             U
             I2
             Y
             J1
             H1
             F
             X
             A
             K)
        (and (= I2 4)
     (= V1 8576)
     (= L1 1)
     (= G1 5)
     (= B1 (- 256))
     (= O2 0)
     (<= 0 Y1)
     (<= 0 J1)
     (<= 0 H1)
     (<= 0 F1)
     (<= 0 X)
     (<= 0 K)
     (<= 0 G)
     (<= 0 F)
     (not (<= O1 0))
     (= L2 8448)
     (= v_68 B1))
      )
      (inv_main198 P
             C1
             W1
             B
             T1
             L2
             W
             E1
             Q1
             M2
             O2
             R
             M1
             D2
             P1
             N
             Z1
             I
             D1
             Q
             I1
             M
             D
             K2
             C2
             L1
             R1
             E2
             S1
             B1
             V1
             N2
             S
             O
             G
             Y1
             F1
             J
             N1
             O1
             L
             U1
             P2
             A1
             C
             X1
             J2
             K1
             E
             Z
             T
             H2
             G2
             U
             G1
             Y
             J1
             H1
             F
             X
             A
             v_68)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main339 N
             A1
             D1
             J1
             G2
             D2
             F1
             I2
             I
             E1
             L1
             V
             G
             U1
             I1
             C2
             K2
             E2
             S1
             M1
             C
             Y
             J2
             R1
             D
             O2
             Q1
             V1
             E
             X
             L
             R
             A2
             Y1
             Q
             T1
             H2
             G1
             O
             F2
             P1
             B2
             C1
             S
             W
             O1
             F
             M
             N1
             X1
             M2
             B
             L2
             A
             Z
             H
             B1
             Z1
             N2
             T
             U
             K)
        (and (= H1 1)
     (not (= Z 4))
     (= X (- 256))
     (= P 8448)
     (= J 0)
     (<= 0 H2)
     (<= 0 Z1)
     (<= 0 T1)
     (<= 0 B1)
     (<= 0 T)
     (<= 0 Q)
     (<= 0 K)
     (<= 0 N2)
     (not (<= K1 0))
     (= W1 8576)
     (= v_67 X))
      )
      (inv_main198 N
             A1
             D1
             J1
             G2
             P
             F1
             I2
             I
             E1
             J
             V
             G
             U1
             I1
             C2
             K2
             E2
             S1
             M1
             C
             Y
             J2
             R1
             D
             H1
             Q1
             V1
             E
             X
             W1
             R
             A2
             Y1
             Q
             T1
             H2
             G1
             O
             K1
             P1
             B2
             C1
             S
             W
             O1
             F
             M
             N1
             X1
             M2
             B
             L2
             A
             Z
             H
             B1
             Z1
             N2
             T
             U
             v_67)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main339 W
             C2
             V1
             X1
             S
             Y
             B
             H2
             C1
             O2
             I
             R1
             Q1
             J1
             P1
             T
             L
             T1
             D
             Z
             I2
             F1
             R
             G
             B1
             V
             A1
             K
             F2
             Y1
             W1
             L2
             O1
             G1
             U1
             K2
             I1
             Q
             J2
             E2
             N1
             N
             K1
             B2
             D2
             M2
             H1
             U
             P2
             M1
             N2
             Z1
             L1
             A
             J
             S1
             O
             H
             F
             X
             C
             A2)
        (and (= E 1)
     (= G2 8448)
     (not (= Y1 (- 256)))
     (= E1 8576)
     (= D1 5)
     (= P 0)
     (= J 4)
     (<= 0 K2)
     (<= 0 A2)
     (<= 0 U1)
     (<= 0 I1)
     (<= 0 X)
     (<= 0 O)
     (<= 0 H)
     (<= 0 F)
     (not (<= M 0))
     (not (= D (- 2)))
     (= v_68 Y1))
      )
      (inv_main198 W
             C2
             V1
             X1
             S
             G2
             B
             H2
             C1
             O2
             P
             R1
             Q1
             J1
             P1
             T
             L
             T1
             D
             Z
             I2
             F1
             R
             G
             B1
             E
             A1
             K
             F2
             Y1
             E1
             L2
             O1
             G1
             U1
             K2
             I1
             Q
             J2
             M
             N1
             N
             K1
             B2
             D2
             M2
             H1
             U
             P2
             M1
             N2
             Z1
             L1
             A
             D1
             S1
             O
             H
             F
             X
             C
             v_68)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main339 C
             B2
             E
             V1
             F
             P
             Z
             B
             H1
             C1
             F1
             K1
             T1
             W
             O
             J2
             I1
             P1
             W1
             L2
             D2
             E2
             I
             M2
             K2
             F2
             E1
             Q1
             D1
             D
             Q
             J
             A1
             A
             Y
             X
             L
             C2
             O2
             A2
             N
             V
             U
             S1
             T
             O1
             I2
             Y1
             G
             U1
             X1
             N2
             H2
             N1
             J1
             L1
             M
             R1
             Z1
             B1
             R
             G2)
        (and (not (= W1 (- 2)))
     (= M1 8576)
     (not (= J1 4))
     (= G1 1)
     (= S 0)
     (= K 8448)
     (<= 0 G2)
     (<= 0 Z1)
     (<= 0 R1)
     (<= 0 B1)
     (<= 0 Y)
     (<= 0 X)
     (<= 0 M)
     (<= 0 L)
     (not (<= H 0))
     (not (= D (- 256)))
     (= v_67 D))
      )
      (inv_main198 C
             B2
             E
             V1
             F
             K
             Z
             B
             H1
             C1
             S
             K1
             T1
             W
             O
             J2
             I1
             P1
             W1
             L2
             D2
             E2
             I
             M2
             K2
             G1
             E1
             Q1
             D1
             D
             M1
             J
             A1
             A
             Y
             X
             L
             C2
             O2
             H
             N
             V
             U
             S1
             T
             O1
             I2
             Y1
             G
             U1
             X1
             N2
             H2
             N1
             J1
             L1
             M
             R1
             Z1
             B1
             R
             v_67)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main117 N
             B1
             E1
             V1
             E2
             H2
             U
             L2
             D1
             K1
             S1
             H1
             Y
             R1
             M
             G
             K
             Y1
             F2
             W1
             X
             T
             I1
             W
             Q
             N2
             C
             D2
             P1
             A2
             F
             J
             A
             F1
             L1
             R
             V
             Q1
             O1
             G2
             K2
             C1
             O
             N1
             U1
             J2
             S
             A1
             B2
             Z
             P
             J1
             L
             I2
             H
             X1
             E
             T1
             D
             B
             C2
             I)
        (and (not (= H2 8545))
     (not (= H2 8560))
     (not (= H2 8561))
     (not (= H2 8448))
     (not (= H2 8576))
     (not (= H2 8577))
     (= H2 8592)
     (not (= H2 8529))
     (not (= H2 12292))
     (not (= H2 16384))
     (not (= H2 8192))
     (not (= H2 24576))
     (not (= H2 8195))
     (not (= H2 8480))
     (not (= H2 8481))
     (not (= H2 8482))
     (not (= H2 8464))
     (not (= H2 8465))
     (not (= H2 8466))
     (not (= H2 8496))
     (not (= H2 8497))
     (not (= H2 8512))
     (not (= H2 8513))
     (not (= H2 8528))
     (= Z1 0)
     (= M1 8)
     (= G1 8608)
     (= H 7)
     (<= 0 B)
     (<= 0 T1)
     (<= 0 L1)
     (<= 0 V)
     (<= 0 R)
     (<= 0 I)
     (<= 0 E)
     (<= 0 D)
     (not (<= M2 0))
     (not (= H2 8544)))
      )
      (inv_main198 N
             B1
             E1
             V1
             E2
             G1
             U
             L2
             D1
             K1
             Z1
             H1
             Y
             R1
             M
             G
             K
             Y1
             F2
             W1
             X
             T
             I1
             W
             Q
             N2
             C
             D2
             P1
             A2
             F
             J
             A
             F1
             L1
             R
             V
             Q1
             O1
             M2
             K2
             H2
             O
             N1
             U1
             J2
             S
             A1
             B2
             Z
             P
             J1
             L
             I2
             M1
             X1
             E
             T1
             D
             B
             C2
             I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 W
             V1
             D
             E
             F1
             J1
             Q
             I1
             B1
             A2
             M2
             T1
             S
             O
             U
             G2
             E2
             H2
             K
             E1
             B2
             G
             O1
             V
             B
             C1
             R
             P
             D2
             C
             W1
             Z
             A
             Q1
             I2
             F
             H1
             X
             L1
             U1
             N1
             T
             M1
             Y1
             R1
             A1
             C2
             K1
             N
             M
             I
             J
             F2
             X1
             J2
             H
             S1
             Y
             Z1
             L2
             L
             D1)
        (and (not (= J2 7))
     (= P1 0)
     (not (= J1 8544))
     (not (= J1 8545))
     (not (= J1 8560))
     (not (= J1 8561))
     (not (= J1 8448))
     (not (= J1 8576))
     (not (= J1 8577))
     (= J1 8592)
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
     (<= 0 I2)
     (<= 0 Z1)
     (<= 0 S1)
     (<= 0 H1)
     (<= 0 D1)
     (<= 0 Y)
     (<= 0 F)
     (<= 0 L2)
     (not (<= G1 0))
     (= K2 8608))
      )
      (inv_main198 W
             V1
             D
             E
             F1
             K2
             Q
             I1
             B1
             A2
             P1
             T1
             S
             O
             U
             G2
             E2
             H2
             K
             E1
             B2
             G
             O1
             V
             B
             C1
             R
             P
             D2
             C
             W1
             Z
             A
             Q1
             I2
             F
             H1
             X
             L1
             G1
             N1
             J1
             M1
             Y1
             R1
             A1
             C2
             K1
             N
             M
             I
             J
             F2
             X1
             J2
             H
             S1
             Y
             Z1
             L2
             L
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main117 M1
             K1
             M
             R
             O
             L1
             O1
             G2
             A1
             D
             L2
             X1
             C1
             U
             J
             V1
             F
             I
             T1
             A
             H1
             Y
             B1
             V
             Z
             Q
             W1
             E
             D2
             X
             P
             L
             H
             N2
             J2
             W
             C2
             K2
             G
             J1
             D1
             U1
             Q1
             I1
             Z1
             A2
             R1
             P1
             H2
             S
             C
             I2
             B2
             N
             T
             N1
             E2
             G1
             E1
             F1
             M2
             S1)
        (and (= F2 8)
     (= Y1 0)
     (not (= L1 8544))
     (not (= L1 8545))
     (not (= L1 8560))
     (not (= L1 8561))
     (not (= L1 8448))
     (not (= L1 8576))
     (not (= L1 8577))
     (not (= L1 8592))
     (= L1 8593)
     (not (= L1 8529))
     (not (= L1 12292))
     (not (= L1 16384))
     (not (= L1 8192))
     (not (= L1 24576))
     (not (= L1 8195))
     (not (= L1 8480))
     (not (= L1 8481))
     (not (= L1 8482))
     (not (= L1 8464))
     (not (= L1 8465))
     (not (= L1 8466))
     (not (= L1 8496))
     (not (= L1 8497))
     (not (= L1 8512))
     (not (= L1 8513))
     (not (= L1 8528))
     (= T 7)
     (<= 0 J2)
     (<= 0 E2)
     (<= 0 C2)
     (<= 0 S1)
     (<= 0 G1)
     (<= 0 F1)
     (<= 0 E1)
     (<= 0 W)
     (not (<= K 0))
     (= B 8608))
      )
      (inv_main198 M1
             K1
             M
             R
             O
             B
             O1
             G2
             A1
             D
             Y1
             X1
             C1
             U
             J
             V1
             F
             I
             T1
             A
             H1
             Y
             B1
             V
             Z
             Q
             W1
             E
             D2
             X
             P
             L
             H
             N2
             J2
             W
             C2
             K2
             G
             K
             D1
             L1
             Q1
             I1
             Z1
             A2
             R1
             P1
             H2
             S
             C
             I2
             B2
             N
             F2
             N1
             E2
             G1
             E1
             F1
             M2
             S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 C2
             T1
             T
             Z
             G2
             A2
             B2
             L2
             I1
             W1
             K
             A1
             L
             Z1
             R1
             D
             P1
             M2
             O1
             Q1
             F
             H2
             I
             N1
             B
             E
             E1
             S1
             F2
             Y1
             K2
             I2
             B1
             W
             V1
             X1
             N
             A
             Y
             J2
             H1
             O
             C1
             S
             H
             P
             G
             F1
             M
             J
             M1
             G1
             X
             U1
             E2
             L1
             K1
             U
             D1
             D2
             C
             V)
        (and (not (= A2 8544))
     (not (= A2 8545))
     (not (= A2 8560))
     (not (= A2 8561))
     (not (= A2 8448))
     (not (= A2 8576))
     (not (= A2 8577))
     (not (= A2 8592))
     (= A2 8593)
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
     (= J1 0)
     (= Q 8608)
     (<= 0 D2)
     (<= 0 X1)
     (<= 0 V1)
     (<= 0 K1)
     (<= 0 D1)
     (<= 0 V)
     (<= 0 U)
     (<= 0 N)
     (not (<= R 0))
     (not (= E2 7)))
      )
      (inv_main198 C2
             T1
             T
             Z
             G2
             Q
             B2
             L2
             I1
             W1
             J1
             A1
             L
             Z1
             R1
             D
             P1
             M2
             O1
             Q1
             F
             H2
             I
             N1
             B
             E
             E1
             S1
             F2
             Y1
             K2
             I2
             B1
             W
             V1
             X1
             N
             A
             Y
             R
             H1
             A2
             C1
             S
             H
             P
             G
             F1
             M
             J
             M1
             G1
             X
             U1
             E2
             L1
             K1
             U
             D1
             D2
             C
             V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main117 O
             V
             X1
             A
             L
             L1
             M1
             G2
             T
             G1
             U
             D2
             T1
             K1
             N1
             M
             K
             A2
             J
             E
             Q1
             N
             M2
             Y1
             C
             K2
             S1
             I2
             P
             X
             I
             F1
             G
             B2
             R1
             F
             E2
             U1
             F2
             N2
             W1
             C2
             H2
             P1
             Z
             Y
             A1
             B
             W
             J1
             H1
             C1
             B1
             O1
             E1
             J2
             V1
             L2
             Z1
             D
             Q
             I1)
        (and (not (= L1 8545))
     (not (= L1 8560))
     (not (= L1 8561))
     (not (= L1 8448))
     (not (= L1 8576))
     (not (= L1 8577))
     (not (= L1 8592))
     (not (= L1 8593))
     (= L1 8608)
     (not (= L1 8529))
     (not (= L1 12292))
     (not (= L1 16384))
     (not (= L1 8192))
     (not (= L1 24576))
     (not (= L1 8195))
     (not (= L1 8480))
     (not (= L1 8481))
     (not (= L1 8482))
     (not (= L1 8464))
     (not (= L1 8465))
     (not (= L1 8466))
     (not (= L1 8496))
     (not (= L1 8497))
     (not (= L1 8512))
     (not (= L1 8513))
     (not (= L1 8528))
     (= E1 8)
     (= S 0)
     (= R 9)
     (= H 8640)
     (<= 0 L2)
     (<= 0 E2)
     (<= 0 Z1)
     (<= 0 V1)
     (<= 0 R1)
     (<= 0 I1)
     (<= 0 F)
     (<= 0 D)
     (not (<= D1 0))
     (not (= L1 8544)))
      )
      (inv_main198 O
             V
             X1
             A
             L
             H
             M1
             G2
             T
             G1
             S
             D2
             T1
             K1
             N1
             M
             K
             A2
             J
             E
             Q1
             N
             M2
             Y1
             C
             K2
             S1
             I2
             P
             X
             I
             F1
             G
             B2
             R1
             F
             E2
             U1
             F2
             D1
             W1
             L1
             H2
             P1
             Z
             Y
             A1
             B
             W
             J1
             H1
             C1
             B1
             O1
             R
             J2
             V1
             L2
             Z1
             D
             Q
             I1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 W1
             X1
             A1
             A2
             M
             S1
             A
             O1
             D2
             C
             R
             G2
             T
             F
             J2
             U1
             X
             I2
             M1
             N1
             T1
             L
             B
             H
             R1
             C2
             Z
             D1
             S
             Z1
             Y1
             N
             Q1
             H2
             Q
             F2
             H1
             O
             V
             E2
             E
             Y
             C1
             B2
             U
             J
             K2
             F1
             K
             G1
             M2
             P1
             D
             B1
             E1
             G
             K1
             P
             I1
             J1
             L1
             L2)
        (and (not (= S1 8544))
     (not (= S1 8545))
     (not (= S1 8560))
     (not (= S1 8561))
     (not (= S1 8448))
     (not (= S1 8576))
     (not (= S1 8577))
     (not (= S1 8592))
     (not (= S1 8593))
     (= S1 8608)
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
     (not (= E1 8))
     (= W 8640)
     (<= 0 F2)
     (<= 0 K1)
     (<= 0 J1)
     (<= 0 I1)
     (<= 0 H1)
     (<= 0 Q)
     (<= 0 P)
     (<= 0 L2)
     (not (<= I 0))
     (= V1 0))
      )
      (inv_main198 W1
             X1
             A1
             A2
             M
             W
             A
             O1
             D2
             C
             V1
             G2
             T
             F
             J2
             U1
             X
             I2
             M1
             N1
             T1
             L
             B
             H
             R1
             C2
             Z
             D1
             S
             Z1
             Y1
             N
             Q1
             H2
             Q
             F2
             H1
             O
             V
             I
             E
             S1
             C1
             B2
             U
             J
             K2
             F1
             K
             G1
             M2
             P1
             D
             B1
             E1
             G
             K1
             P
             I1
             J1
             L1
             L2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main117 Q1
             K
             O1
             F
             H2
             D1
             H1
             E
             S1
             C2
             A1
             T1
             L
             V1
             K2
             L2
             B
             M1
             P1
             W
             B1
             O
             J
             M
             A2
             R1
             S
             X1
             L1
             R
             Z
             F1
             G
             N
             E1
             D
             K1
             X
             A
             T
             Q
             W1
             U1
             N1
             Y1
             E2
             V
             J1
             U
             G1
             I
             D2
             B2
             P
             M2
             C
             Y
             I1
             I2
             Z1
             C1
             G2)
        (and (= F2 8640)
     (not (= D1 8544))
     (not (= D1 8545))
     (not (= D1 8560))
     (not (= D1 8561))
     (not (= D1 8448))
     (not (= D1 8576))
     (not (= D1 8577))
     (not (= D1 8592))
     (not (= D1 8593))
     (not (= D1 8608))
     (= D1 8609)
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
     (= H 9)
     (= M2 8)
     (<= 0 I2)
     (<= 0 G2)
     (<= 0 Z1)
     (<= 0 K1)
     (<= 0 I1)
     (<= 0 E1)
     (<= 0 Y)
     (<= 0 D)
     (not (<= N2 0))
     (= J2 0))
      )
      (inv_main198 Q1
             K
             O1
             F
             H2
             F2
             H1
             E
             S1
             C2
             J2
             T1
             L
             V1
             K2
             L2
             B
             M1
             P1
             W
             B1
             O
             J
             M
             A2
             R1
             S
             X1
             L1
             R
             Z
             F1
             G
             N
             E1
             D
             K1
             X
             A
             N2
             Q
             D1
             U1
             N1
             Y1
             E2
             V
             J1
             U
             G1
             I
             D2
             B2
             P
             H
             C
             Y
             I1
             I2
             Z1
             C1
             G2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main117 U
             Z1
             I
             A2
             H2
             G2
             B2
             K2
             R
             F1
             S1
             W
             H1
             D2
             B
             M
             R1
             Q1
             K
             C
             P
             L1
             F
             G
             O1
             J
             X
             Y
             N
             L
             W1
             I1
             D1
             E2
             J2
             M1
             M2
             P1
             B1
             L2
             Q
             T
             H
             A
             T1
             J1
             N1
             S
             E1
             U1
             Z
             I2
             V
             Y1
             E
             A1
             C2
             O
             X1
             K1
             G1
             F2)
        (and (not (= G2 8545))
     (not (= G2 8560))
     (not (= G2 8561))
     (not (= G2 8448))
     (not (= G2 8576))
     (not (= G2 8577))
     (not (= G2 8592))
     (not (= G2 8593))
     (not (= G2 8608))
     (= G2 8609)
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
     (= C1 0)
     (not (= E 8))
     (= D 8640)
     (<= 0 J2)
     (<= 0 F2)
     (<= 0 C2)
     (<= 0 X1)
     (<= 0 M1)
     (<= 0 K1)
     (<= 0 O)
     (<= 0 M2)
     (not (<= V1 0))
     (not (= G2 8544)))
      )
      (inv_main198 U
             Z1
             I
             A2
             H2
             D
             B2
             K2
             R
             F1
             C1
             W
             H1
             D2
             B
             M
             R1
             Q1
             K
             C
             P
             L1
             F
             G
             O1
             J
             X
             Y
             N
             L
             W1
             I1
             D1
             E2
             J2
             M1
             M2
             P1
             B1
             V1
             Q
             G2
             H
             A
             T1
             J1
             N1
             S
             E1
             U1
             Z
             I2
             V
             Y1
             E
             A1
             C2
             O
             X1
             K1
             G1
             F2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main454 I
             R
             N2
             V
             Y
             N
             H1
             Q1
             C2
             I1
             J1
             K
             E
             T1
             D
             G2
             T
             B
             B2
             F2
             A2
             G1
             W1
             F1
             M
             O1
             X1
             E2
             L
             M1
             Z
             E1
             K2
             G
             J
             K1
             V1
             L2
             L1
             B1
             H2
             S1
             O
             P1
             N1
             F
             W
             I2
             U
             S
             Q
             D2
             R1
             A1
             C
             U1
             A
             H
             P
             D1
             Y1
             J2)
        (and (= Z1 0)
     (not (= R1 0))
     (not (= A1 0))
     (= X 11)
     (= M2 8672)
     (<= 0 A)
     (<= 0 J2)
     (<= 0 V1)
     (<= 0 K1)
     (<= 0 D1)
     (<= 0 P)
     (<= 0 J)
     (<= 0 H)
     (not (<= C1 0))
     (= C 10)
     (= v_66 L))
      )
      (inv_main198 I
             R
             N2
             V
             Y
             M2
             H1
             Q1
             C2
             I1
             Z1
             K
             E
             T1
             D
             G2
             T
             B
             B2
             F2
             A2
             G1
             W1
             F1
             M
             O1
             X1
             E2
             L
             M1
             Z
             E1
             v_66
             G
             J
             K1
             V1
             L2
             L1
             C1
             H2
             S1
             O
             P1
             N1
             F
             W
             I2
             U
             S
             Q
             D2
             R1
             A1
             X
             U1
             A
             H
             P
             D1
             Y1
             J2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main454 Z1
             C1
             F
             Q1
             G1
             F2
             K2
             V
             G2
             X
             X1
             H2
             L2
             F1
             V1
             A1
             N
             U1
             K
             O
             R1
             G
             W
             B2
             J2
             N2
             Y
             P1
             O1
             C2
             I1
             E1
             H1
             H
             A
             D1
             R
             A2
             W1
             P
             M2
             M1
             E2
             L
             K1
             I
             I2
             D
             S1
             Q
             B1
             J1
             T
             B
             Y1
             U
             Z
             D2
             S
             E
             M
             T1)
        (and (= C 14)
     (= Y1 13)
     (not (= Y1 10))
     (= L1 0)
     (not (= T 0))
     (= J 8672)
     (<= 0 A)
     (<= 0 D2)
     (<= 0 T1)
     (<= 0 D1)
     (<= 0 Z)
     (<= 0 S)
     (<= 0 R)
     (<= 0 E)
     (not (<= N1 0))
     (not (= B 0))
     (= v_66 O1))
      )
      (inv_main198 Z1
             C1
             F
             Q1
             G1
             J
             K2
             V
             G2
             X
             L1
             H2
             L2
             F1
             V1
             A1
             N
             U1
             K
             O
             R1
             G
             W
             B2
             J2
             N2
             Y
             P1
             O1
             C2
             I1
             E1
             v_66
             H
             A
             D1
             R
             A2
             W1
             N1
             M2
             M1
             E2
             L
             K1
             I
             I2
             D
             S1
             Q
             B1
             J1
             T
             B
             C
             U
             Z
             D2
             S
             E
             M
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main454 S1
             U
             L1
             L
             T
             G1
             R1
             E2
             W
             B2
             J1
             Q
             H1
             K1
             J2
             Z
             I1
             N1
             A
             L2
             X1
             U1
             D
             F2
             O
             Y
             C2
             V
             T1
             J
             G
             H2
             C1
             M
             P1
             X
             E1
             S
             C
             Z1
             M2
             O1
             A1
             K2
             D2
             G2
             B
             R
             D1
             Y1
             A2
             F1
             K
             E
             N
             N2
             W1
             H
             I
             F
             Q1
             P)
        (and (= V1 17)
     (= M1 0)
     (= N 16)
     (not (= N 13))
     (not (= N 10))
     (not (= K 0))
     (not (= E 0))
     (<= 0 W1)
     (<= 0 P1)
     (<= 0 E1)
     (<= 0 X)
     (<= 0 P)
     (<= 0 I)
     (<= 0 H)
     (<= 0 F)
     (not (<= B1 0))
     (= I2 8672)
     (= v_66 T1))
      )
      (inv_main198 S1
             U
             L1
             L
             T
             I2
             R1
             E2
             W
             B2
             M1
             Q
             H1
             K1
             J2
             Z
             I1
             N1
             A
             L2
             X1
             U1
             D
             F2
             O
             Y
             C2
             V
             T1
             J
             G
             H2
             v_66
             M
             P1
             X
             E1
             S
             C
             B1
             M2
             O1
             A1
             K2
             D2
             G2
             B
             R
             D1
             Y1
             A2
             F1
             K
             E
             V1
             N2
             W1
             H
             I
             F
             Q1
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main454 Y
             H
             X
             K1
             B1
             J1
             H1
             W
             A1
             X1
             Y1
             Q1
             F1
             A
             I1
             L
             S
             C
             Z
             U
             R1
             I
             S1
             D
             B2
             G2
             K
             N2
             D1
             N
             Z1
             Q
             F2
             V
             P
             A2
             C2
             D2
             T
             L2
             J
             B
             E
             E2
             T1
             W1
             F
             G1
             M1
             K2
             O1
             E1
             V1
             U1
             I2
             L1
             C1
             H2
             M2
             P1
             N1
             G)
        (and (not (= I2 16))
     (not (= I2 13))
     (not (= I2 10))
     (not (= V1 0))
     (not (= U1 0))
     (= R 20)
     (= O 8672)
     (= M 0)
     (<= 0 H2)
     (<= 0 C2)
     (<= 0 A2)
     (<= 0 P1)
     (<= 0 C1)
     (<= 0 P)
     (<= 0 G)
     (<= 0 M2)
     (not (<= J2 0))
     (= I2 19)
     (= v_66 D1))
      )
      (inv_main198 Y
             H
             X
             K1
             B1
             O
             H1
             W
             A1
             X1
             M
             Q1
             F1
             A
             I1
             L
             S
             C
             Z
             U
             R1
             I
             S1
             D
             B2
             G2
             K
             N2
             D1
             N
             Z1
             Q
             v_66
             V
             P
             A2
             C2
             D2
             T
             J2
             J
             B
             E
             E2
             T1
             W1
             F
             G1
             M1
             K2
             O1
             E1
             V1
             U1
             R
             L1
             C1
             H2
             M2
             P1
             N1
             G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main454 R1
             X
             J
             L
             W
             V
             G1
             Q1
             H2
             E1
             Z
             P1
             D1
             G2
             M
             A2
             L1
             J2
             D2
             F2
             M2
             G
             P
             W1
             Z1
             F1
             Y
             A1
             I1
             O
             S1
             L2
             K2
             C
             M1
             D
             E
             X1
             E2
             A
             T
             F
             N
             S
             H1
             U
             T1
             B2
             J1
             Y1
             I2
             I
             H
             C1
             U1
             R
             O1
             N1
             K
             K1
             Q
             C2)
        (and (not (= U1 19))
     (not (= U1 16))
     (not (= U1 13))
     (not (= U1 10))
     (not (= C1 0))
     (= B1 0)
     (not (= H 0))
     (<= 0 C2)
     (<= 0 O1)
     (<= 0 N1)
     (<= 0 M1)
     (<= 0 K1)
     (<= 0 K)
     (<= 0 E)
     (<= 0 D)
     (not (<= B 0))
     (= V1 8672)
     (= v_65 I1))
      )
      (inv_main198 R1
             X
             J
             L
             W
             V1
             G1
             Q1
             H2
             E1
             B1
             P1
             D1
             G2
             M
             A2
             L1
             J2
             D2
             F2
             M2
             G
             P
             W1
             Z1
             F1
             Y
             A1
             I1
             O
             S1
             L2
             v_65
             C
             M1
             D
             E
             X1
             E2
             B
             T
             F
             N
             S
             H1
             U
             T1
             B2
             J1
             Y1
             I2
             I
             H
             C1
             U1
             R
             O1
             N1
             K
             K1
             Q
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 X1
             C
             A1
             J1
             U1
             K
             X
             N
             U
             N1
             H1
             D2
             R1
             P
             Q
             E1
             M1
             L1
             F
             Z
             Z1
             Y
             T
             B2
             W1
             T1
             J2
             A2
             I1
             S
             I
             G
             V
             L
             V1
             M
             H2
             H
             A
             P1
             O
             E2
             Q1
             C2
             W
             G1
             Y1
             G2
             B
             J
             I2
             R
             O1
             K1
             D
             E
             D1
             S1
             C1
             B1
             F1
             F2)
        (and (not (= K 8657))
     (not (= K 8544))
     (not (= K 8545))
     (not (= K 8560))
     (not (= K 8561))
     (not (= K 8448))
     (not (= K 8576))
     (not (= K 8577))
     (not (= K 8592))
     (not (= K 8593))
     (not (= K 8608))
     (not (= K 8609))
     (not (= K 8640))
     (not (= K 8641))
     (not (= K 8656))
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
     (<= 0 H2)
     (<= 0 F2)
     (<= 0 V1)
     (<= 0 S1)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 B1)
     (<= 0 M)
     (= K 8672)
     (= v_62 K))
      )
      (inv_main481 X1
             C
             A1
             J1
             U1
             K
             X
             N
             U
             N1
             H1
             D2
             R1
             P
             Q
             E1
             M1
             L1
             F
             Z
             Z1
             Y
             T
             B2
             W1
             T1
             J2
             A2
             I1
             S
             I
             G
             V
             L
             V1
             M
             H2
             H
             A
             P1
             O
             v_62
             Q1
             C2
             W
             G1
             Y1
             G2
             B
             J
             I2
             R
             O1
             K1
             D
             E
             D1
             S1
             C1
             B1
             F1
             F2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 B2
             E1
             Q1
             K
             I2
             R
             O
             P
             D1
             O1
             T1
             B
             A
             N1
             C
             D2
             P1
             W
             A1
             D
             G
             S
             W1
             S1
             X1
             G1
             M
             I1
             H2
             V1
             R1
             U1
             J2
             C2
             L1
             I
             A2
             E2
             T
             H
             L
             Y1
             F2
             B1
             Z
             Q
             U
             C1
             V
             M1
             J1
             Y
             X
             K1
             F
             H1
             Z1
             F1
             G2
             E
             N
             J)
        (and (not (= R 8672))
     (not (= R 8657))
     (not (= R 8544))
     (not (= R 8545))
     (not (= R 8560))
     (not (= R 8561))
     (not (= R 8448))
     (not (= R 8576))
     (not (= R 8577))
     (not (= R 8592))
     (not (= R 8593))
     (not (= R 8608))
     (not (= R 8609))
     (not (= R 8640))
     (not (= R 8641))
     (not (= R 8656))
     (not (= R 8529))
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
     (<= 0 G2)
     (<= 0 A2)
     (<= 0 Z1)
     (<= 0 L1)
     (<= 0 F1)
     (<= 0 J)
     (<= 0 I)
     (<= 0 E)
     (= R 8673)
     (= v_62 R))
      )
      (inv_main481 B2
             E1
             Q1
             K
             I2
             R
             O
             P
             D1
             O1
             T1
             B
             A
             N1
             C
             D2
             P1
             W
             A1
             D
             G
             S
             W1
             S1
             X1
             G1
             M
             I1
             H2
             V1
             R1
             U1
             J2
             C2
             L1
             I
             A2
             E2
             T
             H
             L
             v_62
             F2
             B1
             Z
             Q
             U
             C1
             V
             M1
             J1
             Y
             X
             K1
             F
             H1
             Z1
             F1
             G2
             E
             N
             J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 E2
             N
             F
             B
             I1
             M1
             Y
             T
             U
             D1
             D
             G
             Z
             L
             C2
             M
             A2
             S
             R1
             V1
             I
             L1
             B2
             G1
             P
             K1
             R
             P1
             C1
             H2
             K
             V
             H
             O1
             W1
             I2
             A
             Z1
             J2
             F2
             T1
             X
             A1
             S1
             C
             G2
             H1
             J1
             X1
             E1
             B1
             U1
             Y1
             D2
             O
             J
             Q
             Q1
             E
             W
             F1
             N1)
        (and (not (= M1 8529))
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
     (<= 0 W1)
     (<= 0 Q1)
     (<= 0 N1)
     (<= 0 W)
     (<= 0 Q)
     (<= 0 E)
     (<= 0 A)
     (<= 0 I2)
     (= M1 8544)
     (= v_62 M1))
      )
      (inv_main333 E2
             N
             F
             B
             I1
             M1
             Y
             T
             U
             D1
             D
             G
             Z
             L
             C2
             M
             A2
             S
             R1
             V1
             I
             L1
             B2
             G1
             P
             K1
             R
             P1
             C1
             H2
             K
             V
             H
             O1
             W1
             I2
             A
             Z1
             J2
             F2
             T1
             v_62
             A1
             S1
             C
             G2
             H1
             J1
             X1
             E1
             B1
             U1
             Y1
             D2
             O
             J
             Q
             Q1
             E
             W
             F1
             N1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 K1
             C2
             X1
             J2
             C1
             Q
             G2
             D2
             P1
             W1
             L
             B
             K
             R
             E2
             I1
             T1
             D
             A
             V1
             E
             S1
             I
             U1
             H
             M1
             D1
             I2
             G
             O
             U
             J1
             P
             Z1
             T
             M
             X
             E1
             L1
             R1
             B2
             H2
             S
             A2
             N
             Y1
             J
             O1
             G1
             H1
             B1
             F1
             A1
             W
             F
             V
             F2
             N1
             Y
             C
             Q1
             Z)
        (and (= Q 8545)
     (not (= Q 8529))
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
     (<= 0 F2)
     (<= 0 N1)
     (<= 0 Z)
     (<= 0 Y)
     (<= 0 X)
     (<= 0 T)
     (<= 0 M)
     (<= 0 C)
     (not (= Q 8544))
     (= v_62 Q))
      )
      (inv_main333 K1
             C2
             X1
             J2
             C1
             Q
             G2
             D2
             P1
             W1
             L
             B
             K
             R
             E2
             I1
             T1
             D
             A
             V1
             E
             S1
             I
             U1
             H
             M1
             D1
             I2
             G
             O
             U
             J1
             P
             Z1
             T
             M
             X
             E1
             L1
             R1
             B2
             v_62
             S
             A2
             N
             Y1
             J
             O1
             G1
             H1
             B1
             F1
             A1
             W
             F
             V
             F2
             N1
             Y
             C
             Q1
             Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 O1
             X
             O
             T1
             H2
             I1
             Q1
             F
             I
             E1
             H
             Y1
             D2
             E
             S
             E2
             B1
             D1
             P
             T
             R1
             G1
             W
             J
             U1
             C2
             X1
             F1
             K1
             V
             Z1
             Q
             S1
             W1
             L
             N
             J1
             D
             F2
             C
             B2
             P1
             Z
             V1
             R
             K
             N1
             C1
             U
             J2
             M
             A
             A1
             I2
             L1
             G2
             G
             M1
             H1
             B
             A2
             Y)
        (and (not (= I1 8545))
     (not (= I1 8560))
     (not (= I1 8561))
     (not (= I1 8448))
     (not (= I1 8576))
     (not (= I1 8577))
     (not (= I1 8592))
     (not (= I1 8593))
     (not (= I1 8608))
     (not (= I1 8609))
     (= I1 8640)
     (not (= I1 8529))
     (not (= I1 12292))
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
     (not (= I1 8497))
     (not (= I1 8512))
     (not (= I1 8513))
     (not (= I1 8528))
     (<= 0 M1)
     (<= 0 J1)
     (<= 0 H1)
     (<= 0 Y)
     (<= 0 N)
     (<= 0 L)
     (<= 0 G)
     (<= 0 B)
     (not (= I1 8544))
     (= v_62 I1))
      )
      (inv_main432 O1
             X
             O
             T1
             H2
             I1
             Q1
             F
             I
             E1
             H
             Y1
             D2
             E
             S
             E2
             B1
             D1
             P
             T
             R1
             G1
             W
             J
             U1
             C2
             X1
             F1
             K1
             V
             Z1
             Q
             S1
             W1
             L
             N
             J1
             D
             F2
             C
             B2
             v_62
             Z
             V1
             R
             K
             N1
             C1
             U
             J2
             M
             A
             A1
             I2
             L1
             G2
             G
             M1
             H1
             B
             A2
             Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 G1
             S1
             U
             I1
             E1
             R1
             A
             O1
             L
             O
             L1
             X1
             A1
             X
             Z
             E2
             T
             B2
             U1
             I2
             W
             D
             F1
             F2
             C2
             T1
             M
             G
             P
             F
             W1
             I
             V
             D1
             C1
             K
             Y
             Y1
             G2
             E
             K1
             J2
             B
             Z1
             S
             D2
             J
             A2
             H2
             R
             M1
             Q
             Q1
             N1
             P1
             H1
             C
             N
             H
             B1
             J1
             V1)
        (and (not (= R1 8545))
     (not (= R1 8560))
     (not (= R1 8561))
     (not (= R1 8448))
     (not (= R1 8576))
     (not (= R1 8577))
     (not (= R1 8592))
     (not (= R1 8593))
     (not (= R1 8608))
     (not (= R1 8609))
     (not (= R1 8640))
     (= R1 8641)
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
     (<= 0 V1)
     (<= 0 C1)
     (<= 0 B1)
     (<= 0 Y)
     (<= 0 N)
     (<= 0 K)
     (<= 0 H)
     (<= 0 C)
     (not (= R1 8544))
     (= v_62 R1))
      )
      (inv_main432 G1
             S1
             U
             I1
             E1
             R1
             A
             O1
             L
             O
             L1
             X1
             A1
             X
             Z
             E2
             T
             B2
             U1
             I2
             W
             D
             F1
             F2
             C2
             T1
             M
             G
             P
             F
             W1
             I
             V
             D1
             C1
             K
             Y
             Y1
             G2
             E
             K1
             v_62
             B
             Z1
             S
             D2
             J
             A2
             H2
             R
             M1
             Q
             Q1
             N1
             P1
             H1
             C
             N
             H
             B1
             J1
             V1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main198 B1
             H1
             D
             C
             G1
             I1
             F1
             E1
             R
             A
             E
             F2
             U1
             O1
             D2
             I2
             Y1
             X1
             S
             Z1
             J2
             V1
             P1
             O
             Q
             D1
             T
             H
             A1
             V
             N
             C2
             M1
             H2
             K1
             J1
             T1
             Q1
             P
             B2
             A2
             R1
             W1
             Y
             N1
             I
             Z
             L
             C1
             J
             L1
             M
             F
             B
             G2
             E2
             W
             G
             K
             X
             U
             S1)
        (and (= W1 0)
     (= T 0)
     (<= 0 T1)
     (<= 0 S1)
     (<= 0 K1)
     (<= 0 J1)
     (<= 0 X)
     (<= 0 W)
     (<= 0 K)
     (<= 0 G)
     (= D2 0))
      )
      (inv_main519 B1
             H1
             D
             C
             G1
             I1
             F1
             E1
             R
             A
             E
             F2
             U1
             O1
             D2
             I2
             Y1
             X1
             S
             Z1
             J2
             V1
             P1
             O
             Q
             D1
             T
             H
             A1
             V
             N
             C2
             M1
             H2
             K1
             J1
             T1
             Q1
             P
             B2
             A2
             R1
             W1
             Y
             N1
             I
             Z
             L
             C1
             J
             L1
             M
             F
             B
             G2
             E2
             W
             G
             K
             X
             U
             S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main198 C2
             Z1
             Q
             X
             E1
             B1
             F2
             W1
             D1
             B2
             K2
             S
             N
             V
             K
             Y1
             U1
             D2
             P1
             H2
             C
             M1
             O1
             F
             Z
             H1
             F1
             A
             C1
             O
             V1
             A2
             T
             E2
             L
             Q1
             G1
             R1
             N1
             A1
             H
             T1
             L1
             R
             I2
             K1
             S1
             U
             D
             I
             B
             E
             I1
             M
             P
             J1
             J2
             Y
             G2
             X1
             G
             J)
        (and (= F1 0)
     (not (= K 0))
     (<= 0 G2)
     (<= 0 X1)
     (<= 0 Q1)
     (<= 0 G1)
     (<= 0 Y)
     (<= 0 L)
     (<= 0 J)
     (<= 0 J2)
     (not (<= W 0))
     (= L1 0))
      )
      (inv_main519 C2
             Z1
             Q
             X
             E1
             B1
             F2
             W1
             D1
             B2
             K2
             S
             N
             V
             K
             Y1
             U1
             D2
             P1
             H2
             C
             M1
             O1
             F
             Z
             H1
             F1
             A
             C1
             O
             V1
             A2
             T
             E2
             L
             Q1
             G1
             R1
             N1
             W
             H
             T1
             L1
             R
             I2
             K1
             S1
             U
             D
             I
             B
             E
             I1
             M
             P
             J1
             J2
             Y
             G2
             X1
             G
             J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 C2
             N
             U
             T1
             P1
             F2
             F1
             N1
             U1
             M
             A2
             K1
             B1
             P
             D
             O
             T
             X1
             G
             Q1
             S
             I1
             J
             E
             X
             W
             R1
             C1
             F
             I
             H1
             O1
             V
             H
             M1
             Q
             L1
             A1
             Y1
             B2
             L
             V1
             B
             Y
             K
             W1
             Z
             D1
             C
             Z1
             J2
             R
             D2
             G1
             A
             I2
             H2
             S1
             G2
             J1
             E2
             E1)
        (and (not (= F2 16384))
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
     (= F2 8512)
     (<= 0 H2)
     (<= 0 G2)
     (<= 0 S1)
     (<= 0 M1)
     (<= 0 L1)
     (<= 0 J1)
     (<= 0 E1)
     (<= 0 Q)
     (not (= F2 12292))
     (= v_62 F2))
      )
      (inv_main282 C2
             N
             U
             T1
             P1
             F2
             F1
             N1
             U1
             M
             A2
             K1
             B1
             P
             D
             O
             T
             X1
             G
             Q1
             S
             I1
             J
             E
             X
             W
             R1
             C1
             F
             I
             H1
             O1
             V
             H
             M1
             Q
             L1
             A1
             Y1
             B2
             L
             v_62
             B
             Y
             K
             W1
             Z
             D1
             C
             Z1
             J2
             R
             D2
             G1
             A
             I2
             H2
             S1
             G2
             J1
             E2
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 J1
             V1
             R1
             D2
             Y1
             P
             A2
             G1
             W1
             H
             E
             A1
             Q1
             X
             F1
             K1
             B
             I1
             I2
             E1
             Y
             C
             S
             H2
             P1
             D
             B2
             G2
             U1
             Z
             B1
             L
             C1
             A
             K
             H1
             C2
             O1
             J
             Q
             F2
             V
             T1
             L1
             U
             O
             G
             N1
             Z1
             D1
             T
             R
             E2
             M1
             F
             W
             J2
             N
             M
             X1
             S1
             I)
        (and (not (= P 16384))
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
     (= P 8513)
     (<= 0 C2)
     (<= 0 X1)
     (<= 0 H1)
     (<= 0 N)
     (<= 0 M)
     (<= 0 K)
     (<= 0 I)
     (<= 0 J2)
     (not (= P 12292))
     (= v_62 P))
      )
      (inv_main282 J1
             V1
             R1
             D2
             Y1
             P
             A2
             G1
             W1
             H
             E
             A1
             Q1
             X
             F1
             K1
             B
             I1
             I2
             E1
             Y
             C
             S
             H2
             P1
             D
             B2
             G2
             U1
             Z
             B1
             L
             C1
             A
             K
             H1
             C2
             O1
             J
             Q
             F2
             v_62
             T1
             L1
             U
             O
             G
             N1
             Z1
             D1
             T
             R
             E2
             M1
             F
             W
             J2
             N
             M
             X1
             S1
             I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main117 C2
             T
             H2
             F1
             A
             L
             A1
             Z
             E1
             D1
             F
             K
             X
             Y
             K1
             R1
             G1
             B1
             G
             A2
             Z1
             U1
             B
             Q1
             C1
             I2
             N1
             P1
             M1
             Y1
             X1
             S
             H1
             T1
             W
             I
             D2
             Q
             L2
             E2
             F2
             J
             O
             S1
             V1
             P
             M
             I1
             D
             J2
             G2
             L1
             H
             K2
             J1
             V
             N
             O1
             R
             B2
             U
             W1)
        (and (not (= L 8544))
     (not (= L 8545))
     (not (= L 8560))
     (not (= L 8561))
     (not (= L 8448))
     (= L 8576)
     (not (= L 8529))
     (not (= L 12292))
     (not (= L 16384))
     (not (= L 8192))
     (not (= L 24576))
     (not (= L 8195))
     (not (= L 8480))
     (not (= L 8481))
     (not (= L 8482))
     (not (= L 8464))
     (not (= L 8465))
     (not (= L 8466))
     (not (= L 8496))
     (not (= L 8497))
     (not (= L 8512))
     (not (= L 8513))
     (not (= L 8528))
     (= C 6)
     (<= 0 D2)
     (<= 0 B2)
     (<= 0 W1)
     (<= 0 O1)
     (<= 0 W)
     (<= 0 R)
     (<= 0 N)
     (<= 0 I)
     (= J1 5)
     (= v_64 L))
      )
      (inv_main389 C2
             T
             H2
             F1
             A
             L
             A1
             Z
             E1
             D1
             F
             K
             X
             Y
             K1
             R1
             G1
             B1
             G
             A2
             Z1
             U1
             B
             Q1
             C1
             I2
             N1
             P1
             M1
             Y1
             X1
             S
             H1
             T1
             W
             I
             D2
             Q
             L2
             E
             F2
             v_64
             O
             S1
             V1
             P
             M
             I1
             D
             J2
             G2
             L1
             H
             K2
             C
             V
             N
             O1
             R
             B2
             U
             W1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main117 O
             H2
             A2
             C1
             I2
             A1
             H
             Y
             T1
             P
             B2
             J
             F1
             R
             W1
             Z1
             V
             K
             C2
             U1
             S
             N
             D
             E2
             B1
             L1
             Q1
             R1
             M
             Y1
             M1
             C
             X1
             Z
             X
             G1
             H1
             N1
             A
             K2
             I
             P1
             F2
             O1
             I1
             D1
             V1
             U
             J2
             W
             Q
             J1
             D2
             S1
             G
             K1
             L
             B
             G2
             E1
             T
             E)
        (and (not (= A1 8545))
     (not (= A1 8560))
     (not (= A1 8561))
     (not (= A1 8448))
     (= A1 8576)
     (not (= A1 8529))
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
     (not (= G 5))
     (<= 0 G2)
     (<= 0 H1)
     (<= 0 G1)
     (<= 0 E1)
     (<= 0 X)
     (<= 0 L)
     (<= 0 E)
     (<= 0 B)
     (not (= A1 8544))
     (= v_63 A1))
      )
      (inv_main389 O
             H2
             A2
             C1
             I2
             A1
             H
             Y
             T1
             P
             B2
             J
             F1
             R
             W1
             Z1
             V
             K
             C2
             U1
             S
             N
             D
             E2
             B1
             L1
             Q1
             R1
             M
             Y1
             M1
             C
             X1
             Z
             X
             G1
             H1
             N1
             A
             F
             I
             v_63
             F2
             O1
             I1
             D1
             V1
             U
             J2
             W
             Q
             J1
             D2
             S1
             G
             K1
             L
             B
             G2
             E1
             T
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main117 S1
             Z
             F2
             G1
             J1
             D2
             X1
             Y
             I2
             R
             E1
             P1
             A
             R1
             G2
             F1
             C2
             W1
             O
             I
             T
             E2
             M
             N
             O1
             W
             H2
             L2
             B2
             K2
             V1
             J
             D
             Q
             M1
             U1
             N1
             F
             A1
             H
             Q1
             V
             K
             P
             X
             I1
             A2
             S
             C1
             Z1
             B1
             T1
             B
             U
             K1
             C
             J2
             Y1
             G
             L1
             L
             E)
        (and (not (= D2 8545))
     (not (= D2 8560))
     (not (= D2 8561))
     (not (= D2 8448))
     (not (= D2 8576))
     (= D2 8577)
     (not (= D2 8529))
     (not (= D2 12292))
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
     (not (= D2 8513))
     (not (= D2 8528))
     (= K1 5)
     (= D1 6)
     (<= 0 J2)
     (<= 0 Y1)
     (<= 0 U1)
     (<= 0 N1)
     (<= 0 M1)
     (<= 0 L1)
     (<= 0 G)
     (<= 0 E)
     (not (= D2 8544))
     (= v_64 D2))
      )
      (inv_main389 S1
             Z
             F2
             G1
             J1
             D2
             X1
             Y
             I2
             R
             E1
             P1
             A
             R1
             G2
             F1
             C2
             W1
             O
             I
             T
             E2
             M
             N
             O1
             W
             H2
             L2
             B2
             K2
             V1
             J
             D
             Q
             M1
             U1
             N1
             F
             A1
             H1
             Q1
             v_64
             K
             P
             X
             I1
             A2
             S
             C1
             Z1
             B1
             T1
             B
             U
             D1
             C
             J2
             Y1
             G
             L1
             L
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main117 B
             Q1
             Z1
             N1
             K2
             U
             R1
             Y
             F2
             K
             Y1
             R
             V1
             G
             V
             P1
             G2
             I
             U1
             L
             X
             S
             X1
             L1
             S1
             C
             O1
             D1
             F
             Q
             C1
             D2
             H1
             D
             I1
             J1
             W1
             E2
             J
             C2
             E
             F1
             T
             T1
             I2
             A2
             E1
             P
             A1
             G1
             W
             H
             Z
             J2
             A
             B2
             H2
             K1
             N
             M1
             O
             B1)
        (and (not (= U 8545))
     (not (= U 8560))
     (not (= U 8561))
     (not (= U 8448))
     (not (= U 8576))
     (= U 8577)
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
     (not (= A 5))
     (<= 0 H2)
     (<= 0 W1)
     (<= 0 M1)
     (<= 0 K1)
     (<= 0 J1)
     (<= 0 I1)
     (<= 0 B1)
     (<= 0 N)
     (not (= U 8544))
     (= v_63 U))
      )
      (inv_main389 B
             Q1
             Z1
             N1
             K2
             U
             R1
             Y
             F2
             K
             Y1
             R
             V1
             G
             V
             P1
             G2
             I
             U1
             L
             X
             S
             X1
             L1
             S1
             C
             O1
             D1
             F
             Q
             C1
             D2
             H1
             D
             I1
             J1
             W1
             E2
             J
             M
             E
             v_63
             T
             T1
             I2
             A2
             E1
             P
             A1
             G1
             W
             H
             Z
             J2
             A
             B2
             H2
             K1
             N
             M1
             O
             B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main333 S
             K
             W1
             Q1
             R1
             M
             U
             E
             G
             A1
             G2
             T
             X
             T1
             C2
             O1
             R
             X1
             Q
             W
             F2
             J
             C
             J1
             L1
             H1
             N
             F1
             Y
             I
             C1
             D1
             A2
             U1
             L
             Y1
             S1
             P1
             Z
             A
             E2
             Z1
             E1
             K1
             I2
             V
             J2
             O
             B1
             V1
             I1
             H2
             H
             D
             M1
             G1
             B2
             P
             B
             F
             D2
             N1)
        (and (not (= Q (- 1)))
     (<= 0 B2)
     (<= 0 Y1)
     (<= 0 S1)
     (<= 0 N1)
     (<= 0 P)
     (<= 0 L)
     (<= 0 F)
     (<= 0 B)
     (= W 0))
      )
      (inv_main339 S
             K
             W1
             Q1
             R1
             M
             U
             E
             G
             A1
             G2
             T
             X
             T1
             C2
             O1
             R
             X1
             Q
             W
             F2
             J
             C
             J1
             L1
             H1
             N
             F1
             Y
             I
             C1
             D1
             A2
             U1
             L
             Y1
             S1
             P1
             Z
             A
             E2
             Z1
             E1
             K1
             I2
             V
             J2
             O
             B1
             V1
             I1
             H2
             H
             D
             M1
             G1
             B2
             P
             B
             F
             D2
             N1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main333 P
             Z1
             M
             E
             Q
             H
             P1
             G1
             L1
             Y
             B2
             X1
             D1
             N1
             E2
             B1
             A2
             R
             O
             I1
             C
             F1
             L
             J2
             I
             U1
             H1
             T1
             J
             C2
             W1
             I2
             O1
             F
             X
             A
             K
             V
             S1
             K1
             S
             Z
             A1
             J1
             M1
             W
             D
             Q1
             V1
             G2
             H2
             E1
             F2
             U
             N
             D2
             G
             T
             Y1
             C1
             B
             R1)
        (and (= O (- 4))
     (not (= O (- 1)))
     (<= 0 Y1)
     (<= 0 R1)
     (<= 0 C1)
     (<= 0 X)
     (<= 0 T)
     (<= 0 K)
     (<= 0 G)
     (<= 0 A)
     (not (= I1 0)))
      )
      (inv_main339 P
             Z1
             M
             E
             Q
             H
             P1
             G1
             L1
             Y
             B2
             X1
             D1
             N1
             E2
             B1
             A2
             R
             O
             I1
             C
             F1
             L
             J2
             I
             U1
             H1
             T1
             J
             C2
             W1
             I2
             O1
             F
             X
             A
             K
             V
             S1
             K1
             S
             Z
             A1
             J1
             M1
             W
             D
             Q1
             V1
             G2
             H2
             E1
             F2
             U
             N
             D2
             G
             T
             Y1
             C1
             B
             R1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main117 K
             J1
             G
             B2
             L
             Q
             C
             W1
             V
             E2
             I2
             V1
             C1
             T1
             P
             A
             N
             Z
             L1
             O1
             W
             U1
             M1
             R1
             A1
             H2
             S1
             C2
             F1
             H
             I
             F
             Y1
             A2
             L2
             T
             R
             E
             S
             J
             K1
             Q1
             Z1
             D
             F2
             N1
             D2
             X
             M
             K2
             B
             Y
             J2
             H1
             I1
             X1
             P1
             E1
             G2
             G1
             D1
             U)
        (and (not (= Q 12292))
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
     (= Q 8496)
     (= O 2)
     (<= 0 G2)
     (<= 0 P1)
     (<= 0 G1)
     (<= 0 E1)
     (<= 0 U)
     (<= 0 T)
     (<= 0 R)
     (<= 0 L2)
     (= I1 1)
     (= v_64 Q))
      )
      (inv_main271 K
             J1
             G
             B2
             L
             Q
             C
             W1
             V
             E2
             I2
             V1
             C1
             T1
             P
             A
             N
             Z
             L1
             O1
             W
             U1
             M1
             R1
             A1
             H2
             S1
             C2
             F1
             H
             I
             F
             Y1
             A2
             L2
             T
             R
             E
             S
             B1
             K1
             v_64
             Z1
             D
             F2
             N1
             D2
             X
             M
             K2
             B
             Y
             J2
             H1
             O
             X1
             P1
             E1
             G2
             G1
             D1
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main117 S1
             F1
             W
             E1
             J2
             N1
             B2
             X1
             M
             X
             Q
             Y1
             E2
             H2
             C
             H
             K
             P1
             D1
             Y
             T1
             R1
             C1
             W1
             I1
             L
             U
             A1
             T
             J1
             C2
             J
             H1
             B
             Z
             O1
             I2
             E
             A2
             I
             S
             K1
             B1
             G
             N
             D2
             P
             Q1
             F
             G2
             M1
             L1
             F2
             Z1
             K2
             O
             V1
             A
             G1
             D
             U1
             V)
        (and (not (= N1 16384))
     (not (= N1 8192))
     (not (= N1 24576))
     (not (= N1 8195))
     (not (= N1 8480))
     (not (= N1 8481))
     (not (= N1 8482))
     (not (= N1 8464))
     (not (= N1 8465))
     (not (= N1 8466))
     (= N1 8496)
     (not (= K2 1))
     (<= 0 I2)
     (<= 0 V1)
     (<= 0 O1)
     (<= 0 G1)
     (<= 0 Z)
     (<= 0 V)
     (<= 0 D)
     (<= 0 A)
     (not (= N1 12292))
     (= v_63 N1))
      )
      (inv_main271 S1
             F1
             W
             E1
             J2
             N1
             B2
             X1
             M
             X
             Q
             Y1
             E2
             H2
             C
             H
             K
             P1
             D1
             Y
             T1
             R1
             C1
             W1
             I1
             L
             U
             A1
             T
             J1
             C2
             J
             H1
             B
             Z
             O1
             I2
             E
             A2
             R
             S
             v_63
             B1
             G
             N
             D2
             P
             Q1
             F
             G2
             M1
             L1
             F2
             Z1
             K2
             O
             V1
             A
             G1
             D
             U1
             V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main117 M1
             G1
             G2
             D2
             I1
             B2
             J2
             C1
             V
             A
             I
             G
             X
             F
             H
             C
             Q
             B1
             P
             E1
             L2
             S
             E
             E2
             J1
             N1
             F2
             O
             K1
             Y1
             K
             D1
             P1
             Z
             V1
             D
             I2
             L
             O1
             H1
             N
             J
             M
             B
             K2
             W1
             Y
             F1
             R
             C2
             T
             A2
             R1
             U
             H2
             X1
             U1
             T1
             Q1
             L1
             S1
             A1)
        (and (not (= B2 12292))
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
     (= B2 8497)
     (= Z1 2)
     (<= 0 I2)
     (<= 0 V1)
     (<= 0 U1)
     (<= 0 T1)
     (<= 0 Q1)
     (<= 0 L1)
     (<= 0 A1)
     (<= 0 D)
     (= H2 1)
     (= v_64 B2))
      )
      (inv_main271 M1
             G1
             G2
             D2
             I1
             B2
             J2
             C1
             V
             A
             I
             G
             X
             F
             H
             C
             Q
             B1
             P
             E1
             L2
             S
             E
             E2
             J1
             N1
             F2
             O
             K1
             Y1
             K
             D1
             P1
             Z
             V1
             D
             I2
             L
             O1
             W
             N
             v_64
             M
             B
             K2
             W1
             Y
             F1
             R
             C2
             T
             A2
             R1
             U
             Z1
             X1
             U1
             T1
             Q1
             L1
             S1
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main117 L1
             A2
             Z1
             Z
             Q1
             D1
             U
             F1
             C
             T1
             J2
             P
             W1
             K1
             N1
             R
             U1
             G
             G2
             S
             Y
             C2
             B1
             S1
             O1
             H1
             E1
             E2
             E
             D2
             F2
             M
             N
             M1
             J
             W
             X
             T
             B2
             D
             K2
             J1
             A1
             V
             B
             L
             H2
             R1
             K
             C1
             O
             Y1
             V1
             X1
             H
             A
             I
             P1
             G1
             I1
             F
             I2)
        (and (not (= D1 16384))
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
     (= D1 8497)
     (not (= H 1))
     (<= 0 I2)
     (<= 0 P1)
     (<= 0 I1)
     (<= 0 G1)
     (<= 0 X)
     (<= 0 W)
     (<= 0 J)
     (<= 0 I)
     (not (= D1 12292))
     (= v_63 D1))
      )
      (inv_main271 L1
             A2
             Z1
             Z
             Q1
             D1
             U
             F1
             C
             T1
             J2
             P
             W1
             K1
             N1
             R
             U1
             G
             G2
             S
             Y
             C2
             B1
             S1
             O1
             H1
             E1
             E2
             E
             D2
             F2
             M
             N
             M1
             J
             W
             X
             T
             B2
             Q
             K2
             v_63
             A1
             V
             B
             L
             H2
             R1
             K
             C1
             O
             Y1
             V1
             X1
             H
             A
             I
             P1
             G1
             I1
             F
             I2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main432 K1
             G
             B1
             I
             D2
             Q1
             H1
             W
             A
             I2
             P1
             T1
             S1
             Q
             V1
             G2
             F
             J
             B2
             K2
             N
             X1
             E2
             G1
             M1
             F2
             D1
             C1
             H
             J1
             X
             P
             L
             C2
             M
             R1
             O1
             E
             V
             C
             F1
             A2
             U1
             W1
             J2
             S
             L1
             T
             N1
             Z
             H2
             R
             U
             Z1
             O
             Y
             B
             D
             A1
             Y1
             I1
             E1)
        (and (= O 21)
     (not (= O 18))
     (not (= O 15))
     (not (= O 12))
     (<= 0 Y1)
     (<= 0 R1)
     (<= 0 O1)
     (<= 0 E1)
     (<= 0 A1)
     (<= 0 M)
     (<= 0 D)
     (<= 0 B)
     (not (= O 9)))
      )
      (inv_main536 K1
             G
             B1
             I
             D2
             Q1
             H1
             W
             A
             I2
             P1
             T1
             S1
             Q
             V1
             G2
             F
             J
             B2
             K2
             N
             X1
             E2
             G1
             M1
             F2
             D1
             C1
             H
             J1
             X
             P
             L
             C2
             M
             R1
             O1
             E
             V
             K
             F1
             A2
             U1
             W1
             J2
             S
             L1
             T
             N1
             Z
             H2
             R
             U
             Z1
             O
             Y
             B
             D
             A1
             Y1
             I1
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 C2
             Y1
             X1
             B2
             Y
             S
             G2
             M
             Q
             G1
             H
             F
             O1
             A1
             X
             F2
             N1
             D1
             W
             B1
             D2
             O
             I1
             K1
             J
             F1
             P1
             V
             P
             V1
             N
             A2
             Q1
             J2
             Z1
             E
             L1
             R1
             K
             U
             U1
             E1
             S1
             M1
             T
             H2
             J1
             D
             R
             Z
             B
             A
             I2
             L
             W1
             E2
             I
             T1
             C
             H1
             C1
             G)
        (and (not (= S 16384))
     (not (= S 8192))
     (not (= S 24576))
     (not (= S 8195))
     (not (= S 8480))
     (not (= S 8481))
     (not (= S 8482))
     (not (= S 8464))
     (not (= S 8465))
     (= S 8466)
     (<= 0 Z1)
     (<= 0 T1)
     (<= 0 L1)
     (<= 0 H1)
     (<= 0 I)
     (<= 0 G)
     (<= 0 E)
     (<= 0 C)
     (not (= S 12292))
     (= v_62 S))
      )
      (inv_main254 C2
             Y1
             X1
             B2
             Y
             S
             G2
             M
             Q
             G1
             H
             F
             O1
             A1
             X
             F2
             N1
             D1
             W
             B1
             D2
             O
             I1
             K1
             J
             F1
             P1
             V
             P
             V1
             N
             A2
             Q1
             J2
             Z1
             E
             L1
             R1
             K
             U
             U1
             v_62
             S1
             M1
             T
             H2
             J1
             D
             R
             Z
             B
             A
             I2
             L
             W1
             E2
             I
             T1
             C
             H1
             C1
             G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 T
             F
             D2
             S
             T1
             I
             D1
             Z
             C2
             H2
             R
             J2
             O1
             L
             E1
             B1
             H
             L1
             Y
             J1
             N1
             X1
             I2
             V1
             C
             I1
             C1
             Y1
             A
             R1
             P
             A2
             S1
             Q1
             G1
             H1
             K1
             Q
             D
             Z1
             O
             N
             A1
             F2
             X
             W
             B2
             M
             W1
             E2
             V
             J
             K
             E
             P1
             M1
             F1
             B
             G
             U1
             G2
             U)
        (and (not (= I 16384))
     (not (= I 8192))
     (not (= I 24576))
     (not (= I 8195))
     (not (= I 8480))
     (not (= I 8481))
     (not (= I 8482))
     (= I 8464)
     (<= 0 U1)
     (<= 0 K1)
     (<= 0 H1)
     (<= 0 G1)
     (<= 0 F1)
     (<= 0 U)
     (<= 0 G)
     (<= 0 B)
     (not (= I 12292))
     (= v_62 I))
      )
      (inv_main254 T
             F
             D2
             S
             T1
             I
             D1
             Z
             C2
             H2
             R
             J2
             O1
             L
             E1
             B1
             H
             L1
             Y
             J1
             N1
             X1
             I2
             V1
             C
             I1
             C1
             Y1
             A
             R1
             P
             A2
             S1
             Q1
             G1
             H1
             K1
             Q
             D
             Z1
             O
             v_62
             A1
             F2
             X
             W
             B2
             M
             W1
             E2
             V
             J
             K
             E
             P1
             M1
             F1
             B
             G
             U1
             G2
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main117 H
             N
             E
             W
             E1
             B1
             G
             P1
             X
             D
             C1
             T
             J2
             Z1
             A1
             S
             X1
             N1
             C
             F1
             C2
             Y1
             K
             J
             Y
             M
             Z
             V1
             I2
             D1
             R
             Q
             F
             B2
             U1
             H1
             R1
             F2
             I
             P
             V
             B
             L1
             J1
             D2
             E2
             O1
             A2
             L
             M1
             A
             W1
             G1
             T1
             G2
             K1
             U
             I1
             S1
             H2
             Q1
             O)
        (and (not (= B1 16384))
     (not (= B1 8192))
     (not (= B1 24576))
     (not (= B1 8195))
     (not (= B1 8480))
     (not (= B1 8481))
     (not (= B1 8482))
     (not (= B1 8464))
     (= B1 8465)
     (<= 0 H2)
     (<= 0 U1)
     (<= 0 S1)
     (<= 0 R1)
     (<= 0 I1)
     (<= 0 H1)
     (<= 0 U)
     (<= 0 O)
     (not (= B1 12292))
     (= v_62 B1))
      )
      (inv_main254 H
             N
             E
             W
             E1
             B1
             G
             P1
             X
             D
             C1
             T
             J2
             Z1
             A1
             S
             X1
             N1
             C
             F1
             C2
             Y1
             K
             J
             Y
             M
             Z
             V1
             I2
             D1
             R
             Q
             F
             B2
             U1
             H1
             R1
             F2
             I
             P
             V
             v_62
             L1
             J1
             D2
             E2
             O1
             A2
             L
             M1
             A
             W1
             G1
             T1
             G2
             K1
             U
             I1
             S1
             H2
             Q1
             O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main300 Z1
             K
             C
             J1
             V1
             A
             T
             P
             J2
             Y1
             U1
             D
             H2
             B2
             G1
             E
             R
             D2
             A1
             T1
             B
             F1
             H1
             U
             M
             Q
             G2
             C1
             C2
             O
             S1
             X
             L
             I1
             X1
             S
             K1
             F2
             J
             R1
             N1
             I
             E2
             E1
             P1
             M1
             I2
             W
             W1
             V
             L1
             Z
             G
             H
             O1
             Q1
             A2
             B1
             F
             D1
             Y
             N)
        (and (<= 0 A2)
     (<= 0 X1)
     (<= 0 K1)
     (<= 0 D1)
     (<= 0 B1)
     (<= 0 S)
     (<= 0 N)
     (<= 0 F)
     (not (= C1 0)))
      )
      (inv_main321 Z1
             K
             C
             J1
             V1
             A
             T
             P
             J2
             Y1
             U1
             D
             H2
             B2
             G1
             E
             R
             D2
             A1
             T1
             B
             F1
             H1
             U
             M
             Q
             G2
             C1
             C2
             O
             S1
             X
             L
             I1
             X1
             S
             K1
             F2
             J
             R1
             N1
             I
             E2
             E1
             P1
             M1
             I2
             W
             W1
             V
             L1
             Z
             G
             H
             O1
             Q1
             A2
             B1
             F
             D1
             Y
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main300 G2
             H
             H1
             B2
             K
             V
             L1
             C
             U
             I2
             D
             N
             M
             X1
             R1
             I
             G1
             A2
             Y
             H2
             T1
             D1
             J1
             J2
             U1
             Q
             Q1
             F2
             L
             O1
             T
             W1
             P1
             E2
             C1
             X
             Z1
             M1
             E1
             B
             A
             D2
             N1
             Z
             I1
             K1
             B1
             G
             S
             V1
             R
             E
             F
             A1
             P
             F1
             S1
             J
             C2
             W
             Y1
             O)
        (and (not (= C1 (- 30)))
     (<= 0 C2)
     (<= 0 Z1)
     (<= 0 S1)
     (<= 0 C1)
     (<= 0 X)
     (<= 0 W)
     (<= 0 O)
     (<= 0 J)
     (= F2 0))
      )
      (inv_main321 G2
             H
             H1
             B2
             K
             V
             L1
             C
             U
             I2
             D
             N
             M
             X1
             R1
             I
             G1
             A2
             Y
             H2
             T1
             D1
             J1
             J2
             U1
             Q
             Q1
             F2
             L
             O1
             T
             W1
             P1
             E2
             C1
             X
             Z1
             M1
             E1
             B
             A
             D2
             N1
             Z
             I1
             K1
             B1
             G
             S
             V1
             R
             E
             F
             A1
             P
             F1
             S1
             J
             C2
             W
             Y1
             O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main300 L1
             G
             U1
             F2
             B2
             D2
             W
             G1
             N1
             V
             U
             D1
             W1
             B1
             J2
             X
             Z1
             J1
             Q1
             R
             O
             X1
             F
             D
             H
             P
             C1
             Y
             A2
             J
             G2
             P1
             A1
             Q
             L
             R1
             Y1
             E2
             B
             O1
             F1
             I2
             M1
             K
             I
             M
             K1
             E
             T
             I1
             Z
             S
             S1
             H1
             A
             H2
             T1
             V1
             C2
             N
             E1
             C)
        (and (= O 0)
     (= L (- 30))
     (not (= L (- 1)))
     (<= 0 C2)
     (<= 0 Y1)
     (<= 0 V1)
     (<= 0 T1)
     (<= 0 R1)
     (<= 0 N)
     (<= 0 L)
     (<= 0 C)
     (= Y 0))
      )
      (inv_main321 L1
             G
             U1
             F2
             B2
             D2
             W
             G1
             N1
             V
             U
             D1
             W1
             B1
             J2
             X
             Z1
             J1
             Q1
             R
             O
             X1
             F
             D
             H
             P
             C1
             Y
             A2
             J
             G2
             P1
             A1
             Q
             L
             R1
             Y1
             E2
             B
             O1
             F1
             I2
             M1
             K
             I
             M
             K1
             E
             T
             I1
             Z
             S
             S1
             H1
             A
             H2
             T1
             V1
             C2
             N
             E1
             C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main300 Q
             K2
             O1
             T1
             Y
             I1
             Q1
             F2
             E1
             M1
             V
             H
             P
             R
             C1
             U
             E
             B
             U1
             Y1
             L
             G2
             W
             I2
             J1
             D1
             V1
             G
             T
             S
             Z1
             G1
             S1
             W1
             O
             M
             B2
             D
             E2
             K1
             F
             H2
             X1
             F1
             P1
             R1
             N
             L2
             A2
             B1
             D2
             C
             K
             Z
             L1
             I
             A
             X
             H1
             C2
             J
             A1)
        (and (= N1 512)
     (not (= G1 (- 4)))
     (not (= G1 (- 2)))
     (= O (- 30))
     (not (= O (- 1)))
     (not (= L 0))
     (= G 0)
     (>= B1 65)
     (<= 0 A)
     (<= 0 C2)
     (<= 0 B2)
     (<= 0 H1)
     (<= 0 A1)
     (<= 0 X)
     (<= 0 O)
     (<= 0 M)
     (= (+ J2 (* (- 8) B1)) 0)
     (= v_64 G1)
     (= v_65 G1))
      )
      (inv_main321 Q
             K2
             O1
             T1
             Y
             I1
             Q1
             F2
             E1
             M1
             V
             H
             P
             R
             C1
             U
             E
             B
             U1
             Y1
             L
             G2
             W
             I2
             J1
             D1
             V1
             G
             T
             S
             Z1
             G1
             S1
             W1
             O
             M
             B2
             D
             E2
             K1
             F
             H2
             X1
             F1
             P1
             R1
             N
             L2
             A2
             B1
             N1
             C
             K
             Z
             L1
             I
             A
             X
             v_64
             v_65
             J2
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main300 I2
             Q1
             L1
             E1
             X
             T
             M
             Z
             J1
             F2
             S1
             P
             I1
             O1
             M1
             G1
             X1
             Q
             B
             U
             T1
             A1
             J
             A2
             O
             G
             I
             L2
             C2
             W
             H2
             L
             D1
             W1
             S
             B2
             Y
             F
             D2
             G2
             V
             C
             Y1
             K
             V1
             R
             E
             F1
             K2
             N1
             D
             P1
             B1
             K1
             E2
             C1
             R1
             H1
             Z1
             H
             A
             N)
        (and (= U1 1024)
     (not (= T1 0))
     (= S (- 30))
     (not (= S (- 1)))
     (= L (- 4))
     (not (= L (- 2)))
     (= L2 0)
     (>= N1 129)
     (<= 0 B2)
     (<= 0 Z1)
     (<= 0 R1)
     (<= 0 H1)
     (<= 0 Y)
     (<= 0 S)
     (<= 0 N)
     (<= 0 H)
     (= (+ J2 (* (- 8) N1)) 0)
     (= v_64 L)
     (= v_65 L))
      )
      (inv_main321 I2
             Q1
             L1
             E1
             X
             T
             M
             Z
             J1
             F2
             S1
             P
             I1
             O1
             M1
             G1
             X1
             Q
             B
             U
             T1
             A1
             J
             A2
             O
             G
             I
             L2
             C2
             W
             H2
             L
             D1
             W1
             S
             B2
             Y
             F
             D2
             G2
             V
             C
             Y1
             K
             V1
             R
             E
             F1
             K2
             N1
             U1
             P1
             B1
             K1
             E2
             C1
             R1
             H1
             v_64
             v_65
             J2
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main536 X1
             R
             T
             L
             N1
             N
             Y1
             Z
             E2
             J1
             O
             Q1
             L1
             D1
             M1
             E
             V
             H2
             U1
             M
             A2
             P1
             H
             X
             G
             C
             T1
             P
             U
             I1
             F1
             D
             G2
             F
             Z1
             W1
             C2
             K
             B1
             Q
             K1
             H1
             B2
             W
             F2
             I2
             Y
             G1
             E1
             S
             C1
             J
             B
             D2
             R1
             I
             O1
             J2
             V1
             S1
             A
             A1)
        (and (<= 0 Z1)
     (<= 0 W1)
     (<= 0 V1)
     (<= 0 S1)
     (<= 0 O1)
     (<= 0 A1)
     (<= 0 J2)
     (<= 0 C2))
      )
      false
    )
  )
)

(check-sat)
(exit)
