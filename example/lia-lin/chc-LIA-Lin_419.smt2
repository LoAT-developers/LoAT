; ./sv-comp/./2015-05-26/LIA/Eldarica/linear-tree-like/four1.smt2-0002_000.smt2
(set-logic HORN)

(declare-fun |predh103_3| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh7_5| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh112_2| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh88_4| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh122_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) ) 
    (=>
      (and
        (predh112_2 O1
            N1
            M1
            L1
            K1
            J1
            I1
            H1
            G1
            F1
            E1
            D1
            C1
            B1
            A1
            Z
            Y
            X
            W
            V
            U
            T
            S
            R
            Q
            P
            O
            N
            M
            L
            K
            J
            I
            H
            G
            F
            E
            D
            C
            B)
        (and (<= 2 (+ (* (- 1) Q) (* (- 1) M) C))
     (<= 0 (+ R (* (- 1) M)))
     (<= 0 C)
     (= A (+ Q M)))
      )
      (predh122_1 O1
            N1
            M1
            L1
            K1
            J1
            I1
            H1
            G1
            F1
            E1
            D1
            C1
            B1
            A1
            Z
            Y
            X
            W
            V
            U
            T
            S
            R
            Q
            P
            A
            N
            M
            L
            K
            J
            I
            H
            G
            F
            E
            D
            C
            B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (v_40 Int) ) 
    (=>
      (and
        (predh103_3 N1
            M1
            L1
            K1
            J1
            I1
            H1
            G1
            F1
            E1
            D1
            C1
            B1
            A1
            Z
            Y
            X
            W
            V
            U
            T
            S
            R
            Q
            P
            O
            N
            M
            L
            K
            J
            I
            H
            G
            F
            E
            D
            C
            B
            A)
        (and (<= 1 (+ P (* (- 1) O))) (= v_40 O))
      )
      (predh112_2 N1
            M1
            L1
            K1
            J1
            I1
            H1
            G1
            F1
            E1
            D1
            C1
            B1
            A1
            Z
            Y
            X
            W
            V
            U
            T
            S
            R
            Q
            P
            O
            N
            M
            v_40
            K
            J
            I
            H
            G
            F
            E
            D
            C
            B
            A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (v_43 Int) (v_44 Int) (v_45 Int) ) 
    (=>
      (and
        (predh88_4 N1
           M1
           L1
           K1
           J1
           I1
           H1
           G1
           F1
           E1
           D1
           C1
           B1
           A1
           Z
           Y
           X
           W
           V
           U
           T
           S
           R
           Q
           P
           O
           N
           M
           L
           K
           J
           I
           H
           G
           F
           E
           D
           C
           B
           A)
        (and (<= 1 (+ Q (* (- 1) P))) (= 1 v_43) (= 1 v_44) (= 0 v_45))
      )
      (predh103_3 N1
            M1
            L1
            K1
            J1
            I1
            H1
            G1
            F1
            E1
            D1
            C1
            B1
            A1
            Z
            Y
            X
            W
            V
            U
            T
            S
            R
            Q
            P
            v_43
            N
            Q1
            L
            K
            v_44
            P1
            H
            v_45
            O1
            E
            D
            C
            B
            A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) ) 
    (=>
      (and
        (predh7_5 O1
          N1
          M1
          L1
          K1
          J1
          I1
          H1
          G1
          F1
          E1
          D1
          C1
          B1
          A1
          Z
          Y
          X
          W
          V
          U
          T
          S
          R
          Q
          P
          O
          N
          M
          L
          K
          J
          I
          H
          G
          F
          E
          D
          C
          B)
        (and (<= 0 (+ (* (- 1) R) M)) (= A 2))
      )
      (predh88_4 O1
           N1
           M1
           L1
           K1
           J1
           I1
           H1
           G1
           F1
           E1
           D1
           C1
           B1
           A1
           Z
           Y
           X
           W
           V
           U
           T
           S
           R
           A
           P
           O
           N
           M
           L
           K
           J
           I
           H
           G
           F
           E
           D
           C
           B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (v_21 Int) (v_22 Int) (v_23 Int) (v_24 Int) (v_25 Int) (v_26 Int) (v_27 Int) (v_28 Int) (v_29 Int) (v_30 Int) (v_31 Int) (v_32 Int) (v_33 Int) (v_34 Int) (v_35 Int) (v_36 Int) (v_37 Int) (v_38 Int) (v_39 Int) ) 
    (=>
      (and
        (and (<= 2 O)
     (= v_21 P)
     (= v_22 O)
     (= v_23 N)
     (= v_24 M)
     (= v_25 L)
     (= 1 v_26)
     (= v_27 K)
     (= 1 v_28)
     (= v_29 J)
     (= v_30 I)
     (= v_31 H)
     (= v_32 G)
     (= v_33 F)
     (= v_34 E)
     (= v_35 D)
     (= v_36 C)
     (= v_37 B)
     (= 1 v_38)
     (= v_39 A))
      )
      (predh7_5 P
          O
          N
          U
          M
          L
          T
          K
          S
          J
          I
          H
          G
          F
          E
          D
          C
          B
          R
          Q
          v_21
          v_22
          v_23
          A
          v_24
          v_25
          v_26
          v_27
          v_28
          v_29
          v_30
          v_31
          v_32
          v_33
          v_34
          v_35
          v_36
          v_37
          v_38
          v_39)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) ) 
    (=>
      (and
        (predh122_1 N1
            M1
            L1
            K1
            J1
            I1
            H1
            G1
            F1
            E1
            D1
            C1
            B1
            A1
            Z
            Y
            X
            W
            V
            U
            T
            S
            R
            Q
            P
            O
            N
            M
            L
            K
            J
            I
            H
            G
            F
            E
            D
            C
            B
            A)
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
