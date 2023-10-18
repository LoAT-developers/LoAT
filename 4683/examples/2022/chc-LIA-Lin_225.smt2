; ./vmt/./ctigar/svd.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) ) 
    (=>
      (and
        (and (= H true) (not G) (not F) (not E) (not D) (not C) (not B) (not A) (not I))
      )
      (state I H G F E D B C A S R Q P O N M L K J)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) ) 
    (=>
      (and
        (state I H G F E D B C A L1 J1 H1 F1 D1 B1 Z X V T)
        (let ((a!1 (and R
                (not Q)
                P
                O
                N
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
      (a!2 (and R
                (not Q)
                P
                O
                N
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
      (a!3 (and R
                (not Q)
                P
                O
                N
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
      (a!4 (and R
                (not Q)
                P
                O
                N
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
      (a!5 (and R
                (not Q)
                P
                O
                N
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
      (a!6 (and R
                (not Q)
                P
                O
                (not N)
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
      (a!7 (and R
                (not Q)
                P
                O
                (not N)
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
      (a!8 (and R
                (not Q)
                P
                O
                (not N)
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
      (a!9 (and R
                (not Q)
                P
                O
                (not N)
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
      (a!10 (and R
                 (not Q)
                 P
                 O
                 (not N)
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!11 (and R
                 (not Q)
                 P
                 (not O)
                 N
                 M
                 L
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!12 (and R
                 (not Q)
                 P
                 (not O)
                 N
                 M
                 (not L)
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!13 (and R
                 (not Q)
                 P
                 (not O)
                 N
                 M
                 (not L)
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!14 (and R
                 (not Q)
                 P
                 (not O)
                 N
                 M
                 (not L)
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!15 (and R
                 (not Q)
                 P
                 (not O)
                 N
                 M
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!16 (and R
                 (not Q)
                 P
                 (not O)
                 N
                 (not M)
                 L
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!17 (and R
                 (not Q)
                 P
                 (not O)
                 (not N)
                 (not M)
                 L
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!18 (and R
                 (not Q)
                 P
                 (not O)
                 (not N)
                 (not M)
                 L
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!19 (and R
                 (not Q)
                 P
                 (not O)
                 (not N)
                 (not M)
                 L
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!20 (and R
                 (not Q)
                 P
                 (not O)
                 (not N)
                 (not M)
                 (not L)
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!21 (and R
                 (not Q)
                 (not P)
                 O
                 N
                 (not M)
                 L
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!22 (and R
                 (not Q)
                 (not P)
                 O
                 N
                 (not M)
                 (not L)
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!23 (and R
                 (not Q)
                 (not P)
                 O
                 N
                 (not M)
                 (not L)
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!24 (and R
                 (not Q)
                 (not P)
                 O
                 N
                 (not M)
                 (not L)
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!25 (and R
                 (not Q)
                 (not P)
                 O
                 N
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!26 (and R
                 (not Q)
                 (not P)
                 O
                 (not N)
                 M
                 L
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!27 (and R
                 (not Q)
                 (not P)
                 (not O)
                 N
                 M
                 (not L)
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!28 (and R
                 (not Q)
                 (not P)
                 (not O)
                 N
                 M
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!29 (and R
                 (not Q)
                 (not P)
                 (not O)
                 N
                 (not M)
                 L
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!30 (and R
                 (not Q)
                 (not P)
                 (not O)
                 N
                 (not M)
                 L
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!31 (and R
                 (not Q)
                 (not P)
                 (not O)
                 N
                 (not M)
                 L
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!32 (and R
                 (not Q)
                 (not P)
                 (not O)
                 N
                 (not M)
                 L
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!33 (and R
                 (not Q)
                 (not P)
                 (not O)
                 N
                 (not M)
                 (not L)
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!34 (and R
                 (not Q)
                 (not P)
                 (not O)
                 N
                 (not M)
                 (not L)
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!35 (and R
                 (not Q)
                 (not P)
                 (not O)
                 N
                 (not M)
                 (not L)
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!36 (and R
                 (not Q)
                 (not P)
                 (not O)
                 N
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!37 (and R
                 (not Q)
                 (not P)
                 (not O)
                 (not N)
                 M
                 L
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!38 (and R
                 (not Q)
                 (not P)
                 (not O)
                 (not N)
                 M
                 L
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!39 (and R
                 (not Q)
                 (not P)
                 (not O)
                 (not N)
                 M
                 L
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!40 (and R
                 (not Q)
                 (not P)
                 (not O)
                 (not N)
                 M
                 L
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!41 (and R
                 (not Q)
                 (not P)
                 (not O)
                 (not N)
                 M
                 (not L)
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!42 (and R
                 (not Q)
                 (not P)
                 (not O)
                 (not N)
                 M
                 (not L)
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!43 (and R
                 (not Q)
                 (not P)
                 (not O)
                 (not N)
                 M
                 (not L)
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!44 (and R
                 (not Q)
                 (not P)
                 (not O)
                 (not N)
                 M
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!45 (and R
                 (not Q)
                 (not P)
                 (not O)
                 (not N)
                 (not M)
                 L
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!46 (and R
                 (not Q)
                 (not P)
                 (not O)
                 (not N)
                 (not M)
                 (not L)
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!47 (and R
                 (not Q)
                 (not P)
                 (not O)
                 (not N)
                 (not M)
                 (not L)
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!48 (and R
                 (not Q)
                 (not P)
                 (not O)
                 (not N)
                 (not M)
                 (not L)
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!49 (and R
                 (not Q)
                 (not P)
                 (not O)
                 (not N)
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!50 (and (not R)
                 Q
                 P
                 O
                 N
                 (not M)
                 (not L)
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!51 (and (not R)
                 Q
                 P
                 O
                 N
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!52 (and (not R)
                 Q
                 P
                 O
                 (not N)
                 M
                 L
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!53 (and (not R)
                 Q
                 P
                 O
                 (not N)
                 M
                 L
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!54 (and (not R)
                 Q
                 P
                 O
                 (not N)
                 (not M)
                 (not L)
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!55 (and (not R)
                 Q
                 P
                 O
                 (not N)
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!56 (and (not R)
                 Q
                 P
                 (not O)
                 N
                 M
                 L
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!57 (and (not R)
                 Q
                 P
                 (not O)
                 N
                 M
                 L
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!58 (and (not R)
                 Q
                 P
                 (not O)
                 N
                 M
                 L
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!59 (and (not R)
                 Q
                 P
                 (not O)
                 N
                 M
                 L
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!60 (and (not R)
                 Q
                 P
                 (not O)
                 (not N)
                 M
                 (not L)
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!61 (and (not R)
                 Q
                 P
                 (not O)
                 (not N)
                 M
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!62 (and (not R)
                 Q
                 P
                 (not O)
                 (not N)
                 (not M)
                 L
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!63 (and (not R)
                 Q
                 P
                 (not O)
                 (not N)
                 (not M)
                 L
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!64 (and (not R)
                 Q
                 (not P)
                 O
                 (not N)
                 M
                 (not L)
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!65 (and (not R)
                 Q
                 (not P)
                 O
                 (not N)
                 M
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!66 (and (not R)
                 Q
                 (not P)
                 O
                 (not N)
                 (not M)
                 L
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!67 (and (not R)
                 Q
                 (not P)
                 O
                 (not N)
                 (not M)
                 L
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!68 (and (not R)
                 Q
                 (not P)
                 O
                 (not N)
                 (not M)
                 L
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!69 (and (not R)
                 Q
                 (not P)
                 O
                 (not N)
                 (not M)
                 L
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!70 (and (not R)
                 Q
                 (not P)
                 O
                 (not N)
                 (not M)
                 (not L)
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!71 (and (not R)
                 Q
                 (not P)
                 O
                 (not N)
                 (not M)
                 (not L)
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!72 (and (not R)
                 Q
                 (not P)
                 (not O)
                 (not N)
                 M
                 L
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!73 (and (not R)
                 Q
                 (not P)
                 (not O)
                 (not N)
                 M
                 (not L)
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!74 (and (not R)
                 Q
                 (not P)
                 (not O)
                 (not N)
                 M
                 (not L)
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!75 (and (not R)
                 Q
                 (not P)
                 (not O)
                 (not N)
                 M
                 (not L)
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!76 (and (not R)
                 (not Q)
                 P
                 O
                 N
                 M
                 L
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!77 (and (not R)
                 (not Q)
                 P
                 O
                 N
                 M
                 (not L)
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!78 (and (not R)
                 (not Q)
                 P
                 O
                 N
                 M
                 (not L)
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!79 (and (not R)
                 (not Q)
                 P
                 O
                 N
                 M
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!80 (and (not R)
                 (not Q)
                 P
                 O
                 N
                 (not M)
                 L
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!81 (and (not R)
                 (not Q)
                 P
                 O
                 N
                 (not M)
                 L
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!82 (and (not R)
                 (not Q)
                 P
                 O
                 (not N)
                 (not M)
                 L
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!83 (and (not R)
                 (not Q)
                 P
                 O
                 (not N)
                 (not M)
                 L
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!84 (and (not R)
                 (not Q)
                 P
                 O
                 (not N)
                 (not M)
                 L
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!85 (and (not R)
                 (not Q)
                 P
                 O
                 (not N)
                 (not M)
                 L
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!86 (and (not R)
                 (not Q)
                 P
                 O
                 (not N)
                 (not M)
                 (not L)
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!87 (and (not R)
                 (not Q)
                 P
                 O
                 (not N)
                 (not M)
                 (not L)
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!88 (and (not R)
                 (not Q)
                 P
                 (not O)
                 N
                 (not M)
                 (not L)
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!89 (and (not R)
                 (not Q)
                 P
                 (not O)
                 N
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!90 (and (not R)
                 (not Q)
                 P
                 (not O)
                 (not N)
                 M
                 L
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!91 (and (not R)
                 (not Q)
                 P
                 (not O)
                 (not N)
                 M
                 L
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!92 (and (not R)
                 (not Q)
                 P
                 (not O)
                 (not N)
                 M
                 L
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!93 (and (not R)
                 (not Q)
                 P
                 (not O)
                 (not N)
                 M
                 L
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!94 (and (not R)
                 (not Q)
                 (not P)
                 O
                 (not N)
                 M
                 (not L)
                 (not K)
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!95 (and (not R)
                 (not Q)
                 (not P)
                 O
                 (not N)
                 M
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!96 (and (not R)
                 (not Q)
                 (not P)
                 O
                 (not N)
                 (not M)
                 L
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!97 (and (not R)
                 (not Q)
                 (not P)
                 O
                 (not N)
                 (not M)
                 L
                 K
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!98 (and (not R)
                 (not Q)
                 (not P)
                 (not O)
                 N
                 M
                 (not L)
                 (not K)
                 (not J)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!99 (and (not R)
                 (not Q)
                 (not P)
                 (not O)
                 N
                 (not M)
                 L
                 K
                 J
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= J1 I1)
                 (= L1 K1)))
      (a!100 (and (not R)
                  (not Q)
                  (not P)
                  (not O)
                  N
                  (not M)
                  L
                  K
                  (not J)
                  (= T S)
                  (= V U)
                  (= X W)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)))
      (a!101 (and (not R)
                  (not Q)
                  (not P)
                  (not O)
                  N
                  (not M)
                  L
                  (not K)
                  J
                  (= T S)
                  (= V U)
                  (= X W)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)))
      (a!102 (and R
                  (not Q)
                  (not P)
                  (not O)
                  (not N)
                  (not M)
                  L
                  K
                  (not J)
                  (= T S)
                  (= V U)
                  (= X W)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)))
      (a!104 (and R
                  (not Q)
                  (not P)
                  (not O)
                  (not N)
                  (not M)
                  L
                  K
                  J
                  (= V U)
                  (= X W)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ T (* (- 1) S)) (- 1))))
      (a!105 (and R
                  (not Q)
                  P
                  O
                  N
                  M
                  (not L)
                  K
                  (not J)
                  (= V U)
                  (= X W)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ T (* (- 1) S)) 1)))
      (a!106 (and R
                  (not Q)
                  P
                  O
                  (not N)
                  M
                  (not L)
                  K
                  J
                  (= T S)
                  (= X W)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ V (* (- 1) U)) (- 1))))
      (a!107 (and R
                  (not Q)
                  P
                  (not O)
                  N
                  M
                  L
                  K
                  (not J)
                  (= T S)
                  (= X W)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ V (* (- 1) U)) (- 1))))
      (a!108 (and R
                  (not Q)
                  (not P)
                  O
                  (not N)
                  M
                  L
                  K
                  (not J)
                  (= T S)
                  (= X W)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ V (* (- 1) U)) (- 1))))
      (a!109 (and (not R)
                  Q
                  P
                  O
                  N
                  (not M)
                  (not L)
                  K
                  J
                  (= T S)
                  (= X W)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ V (* (- 1) U)) (- 1))))
      (a!110 (and (not R)
                  (not Q)
                  P
                  O
                  (not N)
                  M
                  (not L)
                  (not K)
                  J
                  (= T S)
                  (= X W)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ V (* (- 1) U)) (- 1))))
      (a!111 (and R
                  (not Q)
                  P
                  (not O)
                  N
                  (not M)
                  L
                  K
                  (not J)
                  (= T S)
                  (= V U)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ X (* (- 1) W)) (- 1))))
      (a!112 (and R
                  (not Q)
                  P
                  (not O)
                  (not N)
                  (not M)
                  (not L)
                  K
                  (not J)
                  (= T S)
                  (= V U)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ X (* (- 1) W)) (- 1))))
      (a!113 (and (not R)
                  Q
                  P
                  O
                  N
                  M
                  L
                  K
                  J
                  (= T S)
                  (= V U)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ X (* (- 1) W)) (- 1))))
      (a!114 (and (not R)
                  Q
                  P
                  O
                  (not N)
                  M
                  L
                  (not K)
                  J
                  (= T S)
                  (= V U)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ X (* (- 1) W)) (- 1))))
      (a!115 (and (not R)
                  Q
                  P
                  (not O)
                  N
                  M
                  (not L)
                  K
                  J
                  (= T S)
                  (= V U)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ X (* (- 1) W)) (- 1))))
      (a!116 (and (not R)
                  Q
                  P
                  (not O)
                  (not N)
                  (not M)
                  L
                  (not K)
                  J
                  (= T S)
                  (= V U)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ X (* (- 1) W)) (- 1))))
      (a!117 (and (not R)
                  Q
                  (not P)
                  O
                  (not N)
                  (not M)
                  (not L)
                  (not K)
                  J
                  (= T S)
                  (= V U)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ X (* (- 1) W)) (- 1))))
      (a!118 (and (not R)
                  Q
                  (not P)
                  (not O)
                  (not N)
                  M
                  (not L)
                  (not K)
                  (not J)
                  (= T S)
                  (= V U)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ X (* (- 1) W)) (- 1))))
      (a!119 (and (not R)
                  (not Q)
                  P
                  O
                  N
                  (not M)
                  L
                  (not K)
                  J
                  (= T S)
                  (= V U)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ X (* (- 1) W)) (- 1))))
      (a!120 (and (not R)
                  (not Q)
                  P
                  O
                  (not N)
                  (not M)
                  (not L)
                  (not K)
                  J
                  (= T S)
                  (= V U)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ X (* (- 1) W)) (- 1))))
      (a!121 (and (not R)
                  (not Q)
                  P
                  (not O)
                  (not N)
                  M
                  (not L)
                  K
                  J
                  (= T S)
                  (= V U)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ X (* (- 1) W)) (- 1))))
      (a!122 (and (not R)
                  (not Q)
                  (not P)
                  O
                  (not N)
                  (not M)
                  L
                  (not K)
                  J
                  (= T S)
                  (= V U)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ X (* (- 1) W)) (- 1))))
      (a!123 (and (not R)
                  (not Q)
                  (not P)
                  (not O)
                  N
                  (not M)
                  L
                  (not K)
                  (not J)
                  (= T S)
                  (= V U)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ X (* (- 1) W)) (- 1))))
      (a!124 (and R
                  (not Q)
                  (not P)
                  (not O)
                  N
                  M
                  L
                  (not K)
                  J
                  (= T S)
                  (= V U)
                  (= X W)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ Y (* (- 1) T)) 1)))
      (a!125 (and (not R)
                  (not Q)
                  (not P)
                  (not O)
                  (not N)
                  (not M)
                  L
                  (not K)
                  (not J)
                  (= T S)
                  (= V U)
                  (= X W)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1)
                  (= (+ Y (* (- 1) T)) 1)))
      (a!126 (and (not R)
                  (not Q)
                  (not P)
                  (not O)
                  (not N)
                  (not M)
                  (not L)
                  (not K)
                  (not J)
                  (= T S)
                  (= V U)
                  (= X W)
                  (= Z Y)
                  (= B1 A1)
                  (= D1 C1)
                  (= F1 E1)
                  (= H1 G1)
                  (= J1 I1)
                  (= L1 K1))))
(let ((a!103 (or A
                 C
                 H
                 I
                 (not B)
                 (not D)
                 (not E)
                 (not F)
                 (not G)
                 (and (<= T J1) (not (= F1 T)))
                 a!102)))
  (and (or B
           C
           D
           G
           (not A)
           (not E)
           (not F)
           (not I)
           (not H)
           (<= 1 T)
           (and R
                (not Q)
                P
                O
                N
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C F G I (not A) (not B) (not D) (not E) (not H) (<= 1 T) a!1)
       (or C F G (not A) (not B) (not D) (not E) (not I) (not H) (<= T F1) a!2)
       (or C F I (not A) (not B) (not D) (not E) (not G) (not H) (<= 1 T) a!3)
       (or C
           F
           (not A)
           (not B)
           (not D)
           (not E)
           (not G)
           (not I)
           (not H)
           (<= T F1)
           a!4)
       (or C
           F
           (not A)
           (not B)
           (not D)
           (not E)
           (not G)
           (not I)
           (not H)
           (not (<= T F1))
           (and R
                (not Q)
                P
                O
                N
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           F
           I
           (not A)
           (not B)
           (not D)
           (not E)
           (not G)
           (not H)
           (not (<= 1 T))
           (and R
                (not Q)
                P
                O
                N
                (not M)
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           F
           G
           (not A)
           (not B)
           (not D)
           (not E)
           (not I)
           (not H)
           (not (<= T F1))
           (and R
                (not Q)
                P
                O
                N
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           F
           G
           I
           (not A)
           (not B)
           (not D)
           (not E)
           (not H)
           (not (<= 1 T))
           (and R
                (not Q)
                P
                O
                N
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B C D I (not A) (not E) (not F) (not G) (not H) (not (<= F1 T)) a!5)
       (or C
           E
           F
           G
           I
           (not A)
           (not B)
           (not D)
           (not H)
           (<= V F1)
           (and R
                (not Q)
                P
                O
                N
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C E F G H (not A) (not B) (not D) (not I) (<= 1 V) a!6)
       (or C E F H I (not A) (not B) (not D) (not G) (<= V F1) a!7)
       (or C E F H (not A) (not B) (not D) (not G) (not I) (<= 1 T) a!8)
       (or C E G H I (not A) (not B) (not D) (not F) (<= T F1) a!9)
       (or C
           E
           G
           H
           I
           (not A)
           (not B)
           (not D)
           (not F)
           (not (<= T F1))
           (and R
                (not Q)
                P
                O
                (not N)
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           E
           F
           H
           (not A)
           (not B)
           (not D)
           (not G)
           (not I)
           (not (<= 1 T))
           (and R
                (not Q)
                P
                O
                (not N)
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           E
           F
           H
           I
           (not A)
           (not B)
           (not D)
           (not G)
           (not (<= V F1))
           (and R
                (not Q)
                P
                O
                (not N)
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           E
           F
           G
           H
           (not A)
           (not B)
           (not D)
           (not I)
           (not (<= 1 V))
           (and R
                (not Q)
                P
                O
                (not N)
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           E
           F
           G
           I
           (not A)
           (not B)
           (not D)
           (not H)
           (not (<= V F1))
           (and R
                (not Q)
                P
                O
                (not N)
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B C D H (not A) (not E) (not F) (not G) (not I) (= M1 0) a!10)
       (or B
           C
           F
           H
           (not A)
           (not D)
           (not E)
           (not G)
           (not I)
           (<= V F1)
           (and R
                (not Q)
                P
                (not O)
                N
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           E
           G
           H
           I
           (not A)
           (not B)
           (not F)
           (<= X F1)
           (and R
                (not Q)
                P
                (not O)
                N
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C D E G I (not A) (not B) (not F) (not H) (<= 1 X) a!11)
       (or C D E G (not A) (not B) (not F) (not I) (not H) (<= X F1) a!12)
       (or C D E I (not A) (not B) (not F) (not G) (not H) (<= 1 V) a!13)
       (or C D E (not A) (not B) (not F) (not G) (not I) (not H) (<= V F1) a!14)
       (or C D F G I (not A) (not B) (not E) (not H) (<= 1 T) a!15)
       (or C D F G (not A) (not B) (not E) (not I) (not H) (<= T F1) a!16)
       (or C
           D
           F
           G
           (not A)
           (not B)
           (not E)
           (not I)
           (not H)
           (not (<= T F1))
           (and R
                (not Q)
                P
                (not O)
                N
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           F
           G
           I
           (not A)
           (not B)
           (not E)
           (not H)
           (not (<= 1 T))
           (and R
                (not Q)
                P
                (not O)
                N
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           E
           (not A)
           (not B)
           (not F)
           (not G)
           (not I)
           (not H)
           (not (<= V F1))
           (and R
                (not Q)
                P
                (not O)
                N
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           E
           I
           (not A)
           (not B)
           (not F)
           (not G)
           (not H)
           (not (<= 1 V))
           (and R
                (not Q)
                P
                (not O)
                (not N)
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           E
           G
           (not A)
           (not B)
           (not F)
           (not I)
           (not H)
           (not (<= X F1))
           (and R
                (not Q)
                P
                (not O)
                (not N)
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           E
           G
           I
           (not A)
           (not B)
           (not F)
           (not H)
           (not (<= 1 X))
           (and R
                (not Q)
                P
                (not O)
                (not N)
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           E
           G
           H
           I
           (not A)
           (not B)
           (not F)
           (not (<= X F1))
           (and R
                (not Q)
                P
                (not O)
                (not N)
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           G
           H
           I
           (not A)
           (not D)
           (not E)
           (not F)
           (<= X F1)
           (and R
                (not Q)
                P
                (not O)
                (not N)
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B C G I (not A) (not D) (not E) (not F) (not H) (<= 1 X) a!17)
       (or B C G (not A) (not D) (not E) (not F) (not I) (not H) (<= X F1) a!18)
       (or B C I (not A) (not D) (not E) (not F) (not G) (not H) (<= 1 V) a!19)
       (or B
           C
           (not A)
           (not D)
           (not E)
           (not F)
           (not G)
           (not I)
           (not H)
           (<= V F1)
           a!20)
       (or B
           C
           (not A)
           (not D)
           (not E)
           (not F)
           (not G)
           (not I)
           (not H)
           (not (<= V F1))
           (and R
                (not Q)
                P
                (not O)
                (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           I
           (not A)
           (not D)
           (not E)
           (not F)
           (not G)
           (not H)
           (not (<= 1 V))
           (and R
                (not Q)
                (not P)
                O
                N
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           G
           (not A)
           (not D)
           (not E)
           (not F)
           (not I)
           (not H)
           (not (<= X F1))
           (and R
                (not Q)
                (not P)
                O
                N
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           G
           I
           (not A)
           (not D)
           (not E)
           (not F)
           (not H)
           (not (<= 1 X))
           (and R
                (not Q)
                (not P)
                O
                N
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           G
           H
           I
           (not A)
           (not D)
           (not E)
           (not F)
           (not (<= X F1))
           (and R
                (not Q)
                (not P)
                O
                N
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           F
           H
           (not A)
           (not D)
           (not E)
           (not G)
           (not I)
           (not (<= V F1))
           (and R
                (not Q)
                (not P)
                O
                N
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           E
           F
           G
           H
           I
           (not A)
           (not D)
           (<= V F1)
           (and R
                (not Q)
                (not P)
                O
                N
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B C E F G I (not A) (not D) (not H) (<= 1 V) a!21)
       (or B C E F G (not A) (not D) (not I) (not H) (<= V F1) a!22)
       (or B C E F I (not A) (not D) (not G) (not H) (<= 1 T) a!23)
       (or B C E F (not A) (not D) (not G) (not I) (not H) (<= T F1) a!24)
       (or B C E G I (not A) (not D) (not F) (not H) (<= 1 Z) a!25)
       (or B C E G (not A) (not D) (not F) (not I) (not H) (<= Z F1) a!26)
       (or B
           C
           E
           G
           (not A)
           (not D)
           (not F)
           (not I)
           (not H)
           (not (<= Z F1))
           (and R
                (not Q)
                (not P)
                O
                (not N)
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           E
           G
           I
           (not A)
           (not D)
           (not F)
           (not H)
           (not (<= 1 Z))
           (and R
                (not Q)
                (not P)
                O
                (not N)
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           E
           F
           (not A)
           (not D)
           (not G)
           (not I)
           (not H)
           (not (<= T F1))
           (and R
                (not Q)
                (not P)
                O
                (not N)
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           E
           F
           I
           (not A)
           (not D)
           (not G)
           (not H)
           (not (<= 1 T))
           (and R
                (not Q)
                (not P)
                O
                (not N)
                (not M)
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           E
           F
           G
           (not A)
           (not D)
           (not I)
           (not H)
           (not (<= V F1))
           (and R
                (not Q)
                (not P)
                O
                (not N)
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           E
           F
           G
           I
           (not A)
           (not D)
           (not H)
           (not (<= 1 V))
           (and R
                (not Q)
                (not P)
                O
                (not N)
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           E
           F
           G
           H
           I
           (not A)
           (not D)
           (not (<= V F1))
           (and R
                (not Q)
                (not P)
                O
                (not N)
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           D
           H
           (not A)
           (not E)
           (not F)
           (not G)
           (not I)
           (not (= M1 0))
           (and R
                (not Q)
                (not P)
                (not O)
                N
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           D
           I
           (not A)
           (not E)
           (not F)
           (not G)
           (not H)
           (<= F1 T)
           (and R
                (not Q)
                (not P)
                (not O)
                N
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           D
           G
           (not A)
           (not E)
           (not F)
           (not I)
           (not H)
           (not (<= 1 T))
           (and R
                (not Q)
                (not P)
                (not O)
                N
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           F
           G
           H
           (not I)
           (<= T F1)
           (and R
                (not Q)
                (not P)
                (not O)
                N
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A B C D E F H I (not G) (<= 1 T) a!27)
       (or A B C D E F H (not G) (not I) (<= T F1) a!28)
       (or A B C E G H (not D) (not F) (not I) (<= 1 T) a!29)
       (or A B C E H I (not D) (not F) (not G) (<= T J1) a!30)
       (or A B C E H (not D) (not F) (not G) (not I) (<= 1 T) a!31)
       (or A B C F G H I (not D) (not E) (<= T F1) a!32)
       (or A B C F G H (not D) (not E) (not I) (<= 1 T) a!33)
       (or A B C F H I (not D) (not E) (not G) (<= T J1) a!34)
       (or A B C F H (not D) (not E) (not G) (not I) (<= 1 T) a!35)
       (or A B C G H I (not D) (not E) (not F) (<= T F1) a!36)
       (or A B E G H (not C) (not D) (not F) (not I) (<= 1 T) a!37)
       (or A B E H I (not C) (not D) (not F) (not G) (<= T J1) a!38)
       (or A B E H (not C) (not D) (not F) (not G) (not I) (<= 1 Z) a!39)
       (or A B F G H I (not C) (not D) (not E) (<= Z F1) a!40)
       (or A B F G H (not C) (not D) (not E) (not I) (<= 1 T) a!41)
       (or A B F H I (not C) (not D) (not E) (not G) (<= T J1) a!42)
       (or A B F H (not C) (not D) (not E) (not G) (not I) (<= 1 Z) a!43)
       (or A B G H I (not C) (not D) (not E) (not F) (<= Z F1) a!44)
       (or A B D E I (not C) (not F) (not G) (not H) (= M1 0) a!45)
       (or A
           F
           I
           (not C)
           (not B)
           (not D)
           (not E)
           (not G)
           (not H)
           (<= X F1)
           (and R
                (not Q)
                (not P)
                (not O)
                (not N)
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A F H (not C) (not B) (not D) (not E) (not G) (not I) (<= 1 T) a!46)
       (or A G H I (not C) (not B) (not D) (not E) (not F) (<= T J1) a!47)
       (or A G H (not C) (not B) (not D) (not E) (not F) (not I) (<= 1 X) a!48)
       (or A H I (not C) (not B) (not D) (not E) (not F) (not G) (<= X F1) a!49)
       (or A
           H
           I
           (not C)
           (not B)
           (not D)
           (not E)
           (not F)
           (not G)
           (not (<= X F1))
           (and (not R)
                Q
                P
                O
                N
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           G
           H
           (not C)
           (not B)
           (not D)
           (not E)
           (not F)
           (not I)
           (not (<= 1 X))
           (and (not R)
                Q
                P
                O
                N
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           G
           H
           I
           (not C)
           (not B)
           (not D)
           (not E)
           (not F)
           (not (<= T J1))
           (and (not R)
                Q
                P
                O
                N
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           F
           H
           (not C)
           (not B)
           (not D)
           (not E)
           (not G)
           (not I)
           (not (<= 1 T))
           (and (not R)
                Q
                P
                O
                N
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           F
           I
           (not C)
           (not B)
           (not D)
           (not E)
           (not G)
           (not H)
           (not (<= X F1))
           (and (not R)
                Q
                P
                O
                N
                (not M)
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           E
           G
           (not C)
           (not B)
           (not F)
           (not I)
           (not H)
           (<= V J1)
           (and (not R)
                Q
                P
                O
                N
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           E
           F
           G
           (not C)
           (not B)
           (not D)
           (not I)
           (not H)
           (<= X F1)
           (and (not R)
                Q
                P
                O
                N
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A E F H I (not C) (not B) (not D) (not G) (<= 1 V) a!50)
       (or A E F H (not C) (not B) (not D) (not G) (not I) (<= V J1) a!51)
       (or A E G H I (not C) (not B) (not D) (not F) (<= 1 X) a!52)
       (or A E G H (not C) (not B) (not D) (not F) (not I) (<= X F1) a!53)
       (or A
           E
           G
           H
           (not C)
           (not B)
           (not D)
           (not F)
           (not I)
           (not (<= X F1))
           (and (not R)
                Q
                P
                O
                (not N)
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           E
           G
           H
           I
           (not C)
           (not B)
           (not D)
           (not F)
           (not (<= 1 X))
           (and (not R)
                Q
                P
                O
                (not N)
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           E
           F
           H
           (not C)
           (not B)
           (not D)
           (not G)
           (not I)
           (not (<= V J1))
           (and (not R)
                Q
                P
                O
                (not N)
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           E
           F
           H
           I
           (not C)
           (not B)
           (not D)
           (not G)
           (not (<= 1 V))
           (and (not R)
                Q
                P
                O
                (not N)
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           E
           F
           G
           (not C)
           (not B)
           (not D)
           (not I)
           (not H)
           (not (<= X F1))
           (and (not R)
                Q
                P
                O
                (not N)
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           E
           I
           (not C)
           (not B)
           (not F)
           (not G)
           (not H)
           (<= X F1)
           (and (not R)
                Q
                P
                O
                (not N)
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A D E H (not C) (not B) (not F) (not G) (not I) (<= 1 V) a!54)
       (or A D F G H I (not C) (not B) (not E) (<= V J1) a!55)
       (or A D F G H (not C) (not B) (not E) (not I) (<= 1 T) a!56)
       (or A D F H I (not C) (not B) (not E) (not G) (<= T J1) a!57)
       (or A D F H (not C) (not B) (not E) (not G) (not I) (<= 1 X) a!58)
       (or A D G H I (not C) (not B) (not E) (not F) (<= X F1) a!59)
       (or A
           D
           G
           H
           I
           (not C)
           (not B)
           (not E)
           (not F)
           (not (<= X F1))
           (and (not R)
                Q
                P
                (not O)
                N
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           F
           H
           (not C)
           (not B)
           (not E)
           (not G)
           (not I)
           (not (<= 1 X))
           (and (not R)
                Q
                P
                (not O)
                N
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           F
           H
           I
           (not C)
           (not B)
           (not E)
           (not G)
           (not (<= T J1))
           (and (not R)
                Q
                P
                (not O)
                N
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           F
           G
           H
           (not C)
           (not B)
           (not E)
           (not I)
           (not (<= 1 T))
           (and (not R)
                Q
                P
                (not O)
                N
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           F
           G
           H
           I
           (not C)
           (not B)
           (not E)
           (not (<= V J1))
           (and (not R)
                Q
                P
                (not O)
                N
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           E
           H
           (not C)
           (not B)
           (not F)
           (not G)
           (not I)
           (not (<= 1 V))
           (and (not R)
                Q
                P
                (not O)
                (not N)
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           E
           I
           (not C)
           (not B)
           (not F)
           (not G)
           (not H)
           (not (<= X F1))
           (and (not R)
                Q
                P
                (not O)
                (not N)
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           E
           G
           (not C)
           (not B)
           (not F)
           (not I)
           (not H)
           (not (<= V J1))
           (and (not R)
                Q
                P
                (not O)
                (not N)
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           G
           (not C)
           (not D)
           (not E)
           (not F)
           (not I)
           (not H)
           (<= X F1)
           (and (not R)
                Q
                P
                (not O)
                (not N)
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A B H I (not C) (not D) (not E) (not F) (not G) (<= 1 T) a!60)
       (or A B H (not C) (not D) (not E) (not F) (not G) (not I) (<= T J1) a!61)
       (or A D E F G H I (not C) (not B) (<= 1 X) a!62)
       (or A D E F G H (not C) (not B) (not I) (<= X F1) a!63)
       (or A
           D
           E
           F
           G
           H
           (not C)
           (not B)
           (not I)
           (not (<= X F1))
           (and (not R)
                Q
                P
                (not O)
                (not N)
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           E
           F
           G
           H
           I
           (not C)
           (not B)
           (not (<= 1 X))
           (and (not R)
                Q
                P
                (not O)
                (not N)
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           H
           (not C)
           (not D)
           (not E)
           (not F)
           (not G)
           (not I)
           (not (<= T J1))
           (and (not R)
                Q
                (not P)
                O
                N
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           H
           I
           (not C)
           (not D)
           (not E)
           (not F)
           (not G)
           (not (<= 1 T))
           (and (not R)
                Q
                (not P)
                O
                N
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           G
           (not C)
           (not D)
           (not E)
           (not F)
           (not I)
           (not H)
           (not (<= X F1))
           (and (not R)
                Q
                (not P)
                O
                N
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           G
           H
           I
           (not C)
           (not D)
           (not E)
           (not F)
           (not (<= Z F1))
           (and (not R)
                Q
                (not P)
                O
                N
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           F
           H
           (not C)
           (not D)
           (not E)
           (not G)
           (not I)
           (not (<= 1 Z))
           (and (not R)
                Q
                (not P)
                O
                N
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           F
           H
           I
           (not C)
           (not D)
           (not E)
           (not G)
           (not (<= T J1))
           (and (not R)
                Q
                (not P)
                O
                N
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           F
           G
           H
           (not C)
           (not D)
           (not E)
           (not I)
           (not (<= 1 T))
           (and (not R)
                Q
                (not P)
                O
                N
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           F
           G
           H
           I
           (not C)
           (not D)
           (not E)
           (not (<= Z F1))
           (and (not R)
                Q
                (not P)
                O
                N
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           E
           H
           (not C)
           (not D)
           (not F)
           (not G)
           (not I)
           (not (<= 1 Z))
           (and (not R)
                Q
                (not P)
                O
                (not N)
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           E
           H
           I
           (not C)
           (not D)
           (not F)
           (not G)
           (not (<= T J1))
           (and (not R)
                Q
                (not P)
                O
                (not N)
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           E
           G
           H
           (not C)
           (not D)
           (not F)
           (not I)
           (not (<= 1 T))
           (and (not R)
                Q
                (not P)
                O
                (not N)
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           E
           (not C)
           (not F)
           (not G)
           (not I)
           (not H)
           (<= X F1)
           (and (not R)
                Q
                (not P)
                O
                (not N)
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A B D F G H I (not C) (not E) (<= 1 T) a!64)
       (or A B D F G H (not C) (not E) (not I) (<= T J1) a!65)
       (or A B D F H I (not C) (not E) (not G) (<= 1 X) a!66)
       (or A B D F H (not C) (not E) (not G) (not I) (<= X F1) a!67)
       (or A B D G H I (not C) (not E) (not F) (<= 1 T) a!68)
       (or A B D G H (not C) (not E) (not F) (not I) (<= T J1) a!69)
       (or A B D H I (not C) (not E) (not F) (not G) (<= 1 X) a!70)
       (or A B D H (not C) (not E) (not F) (not G) (not I) (<= X F1) a!71)
       (or A
           B
           D
           H
           (not C)
           (not E)
           (not F)
           (not G)
           (not I)
           (not (<= X F1))
           (and (not R)
                Q
                (not P)
                (not O)
                N
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           H
           I
           (not C)
           (not E)
           (not F)
           (not G)
           (not (<= 1 X))
           (and (not R)
                Q
                (not P)
                (not O)
                N
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           G
           H
           (not C)
           (not E)
           (not F)
           (not I)
           (not (<= T J1))
           (and (not R)
                Q
                (not P)
                (not O)
                N
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           G
           H
           I
           (not C)
           (not E)
           (not F)
           (not (<= 1 T))
           (and (not R)
                Q
                (not P)
                (not O)
                N
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           F
           H
           (not C)
           (not E)
           (not G)
           (not I)
           (not (<= X F1))
           (and (not R)
                Q
                (not P)
                (not O)
                N
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           F
           H
           I
           (not C)
           (not E)
           (not G)
           (not (<= 1 X))
           (and (not R)
                Q
                (not P)
                (not O)
                N
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           F
           G
           H
           (not C)
           (not E)
           (not I)
           (not (<= T J1))
           (and (not R)
                Q
                (not P)
                (not O)
                N
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           F
           G
           H
           I
           (not C)
           (not E)
           (not (<= 1 T))
           (and (not R)
                Q
                (not P)
                (not O)
                N
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           E
           (not C)
           (not F)
           (not G)
           (not I)
           (not H)
           (not (<= X F1))
           (and (not R)
                Q
                (not P)
                (not O)
                N
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           E
           I
           (not C)
           (not F)
           (not G)
           (not H)
           (not (= M1 0))
           (and (not R)
                Q
                (not P)
                (not O)
                (not N)
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           H
           (not B)
           (not D)
           (not E)
           (not F)
           (not G)
           (not I)
           (<= X F1)
           (and (not R)
                Q
                (not P)
                (not O)
                (not N)
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           (not B)
           (not D)
           (not E)
           (not F)
           (not G)
           (not I)
           (not H)
           (<= 1 T)
           a!72)
       (or A B D E F G I (not C) (not H) (<= T J1) a!73)
       (or A B D E F G (not C) (not I) (not H) (<= 1 X) a!74)
       (or A B D E F I (not C) (not G) (not H) (<= X F1) a!75)
       (or A
           B
           D
           E
           F
           I
           (not C)
           (not G)
           (not H)
           (not (<= X F1))
           (and (not R)
                Q
                (not P)
                (not O)
                (not N)
                (not M)
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           E
           F
           G
           (not C)
           (not I)
           (not H)
           (not (<= 1 X))
           (and (not R)
                Q
                (not P)
                (not O)
                (not N)
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           E
           F
           G
           I
           (not C)
           (not H)
           (not (<= T J1))
           (and (not R)
                Q
                (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           (not B)
           (not D)
           (not E)
           (not F)
           (not G)
           (not I)
           (not H)
           (not (<= 1 T))
           (and (not R)
                Q
                (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           H
           (not B)
           (not D)
           (not E)
           (not F)
           (not G)
           (not I)
           (not (<= X F1))
           (and (not R)
                (not Q)
                P
                O
                N
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A B C D E G H I (not F) (<= T J1) a!76)
       (or A B C D G I (not E) (not F) (not H) (= M1 0) a!77)
       (or A
           C
           E
           G
           (not B)
           (not D)
           (not F)
           (not I)
           (not H)
           (<= X J1)
           (and (not R)
                (not Q)
                P
                O
                N
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A C E H I (not B) (not D) (not F) (not G) (<= 1 X) a!78)
       (or A C E H (not B) (not D) (not F) (not G) (not I) (<= X J1) a!79)
       (or A C F G H I (not B) (not D) (not E) (<= 1 T) a!80)
       (or A C F G H (not B) (not D) (not E) (not I) (<= T F1) a!81)
       (or A
           C
           F
           G
           H
           (not B)
           (not D)
           (not E)
           (not I)
           (not (<= T F1))
           (and (not R)
                (not Q)
                P
                O
                N
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           F
           G
           H
           I
           (not B)
           (not D)
           (not E)
           (not (<= 1 T))
           (and (not R)
                (not Q)
                P
                O
                N
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           E
           H
           (not B)
           (not D)
           (not F)
           (not G)
           (not I)
           (not (<= X J1))
           (and (not R)
                (not Q)
                P
                O
                (not N)
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           E
           H
           I
           (not B)
           (not D)
           (not F)
           (not G)
           (not (<= 1 X))
           (and (not R)
                (not Q)
                P
                O
                (not N)
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           E
           G
           (not B)
           (not D)
           (not F)
           (not I)
           (not H)
           (not (<= X J1))
           (and (not R)
                (not Q)
                P
                O
                (not N)
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           G
           (not D)
           (not E)
           (not F)
           (not I)
           (not H)
           (<= V F1)
           (and (not R)
                (not Q)
                P
                O
                (not N)
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           F
           G
           (not B)
           (not E)
           (not I)
           (not H)
           (<= X J1)
           (and (not R)
                (not Q)
                P
                O
                (not N)
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A C D F H I (not B) (not E) (not G) (<= 1 X) a!82)
       (or A C D F H (not B) (not E) (not G) (not I) (<= X J1) a!83)
       (or A C D G H I (not B) (not E) (not F) (<= 1 T) a!84)
       (or A C D G H (not B) (not E) (not F) (not I) (<= T F1) a!85)
       (or A C D H I (not B) (not E) (not F) (not G) (<= 1 V) a!86)
       (or A C D H (not B) (not E) (not F) (not G) (not I) (<= V F1) a!87)
       (or A
           C
           D
           H
           (not B)
           (not E)
           (not F)
           (not G)
           (not I)
           (not (<= V F1))
           (and (not R)
                (not Q)
                P
                (not O)
                N
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           H
           I
           (not B)
           (not E)
           (not F)
           (not G)
           (not (<= 1 V))
           (and (not R)
                (not Q)
                P
                (not O)
                N
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           G
           H
           (not B)
           (not E)
           (not F)
           (not I)
           (not (<= T F1))
           (and (not R)
                (not Q)
                P
                (not O)
                N
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           G
           H
           I
           (not B)
           (not E)
           (not F)
           (not (<= 1 T))
           (and (not R)
                (not Q)
                P
                (not O)
                N
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           F
           H
           (not B)
           (not E)
           (not G)
           (not I)
           (not (<= X J1))
           (and (not R)
                (not Q)
                P
                (not O)
                N
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           F
           H
           I
           (not B)
           (not E)
           (not G)
           (not (<= 1 X))
           (and (not R)
                (not Q)
                P
                (not O)
                N
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           F
           G
           (not B)
           (not E)
           (not I)
           (not H)
           (not (<= X J1))
           (and (not R)
                (not Q)
                P
                (not O)
                N
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           I
           (not D)
           (not E)
           (not F)
           (not G)
           (not H)
           (<= X J1)
           (and (not R)
                (not Q)
                P
                (not O)
                N
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A B C H (not D) (not E) (not F) (not G) (not I) (<= 1 X) a!88)
       (or A C D E F G H I (not B) (<= X J1) a!89)
       (or A C D E F G H (not B) (not I) (<= 1 T) a!90)
       (or A C D E F H I (not B) (not G) (<= T F1) a!91)
       (or A C D E F H (not B) (not G) (not I) (<= 1 V) a!92)
       (or A C D E G H I (not B) (not F) (<= V F1) a!93)
       (or A
           C
           D
           E
           G
           H
           I
           (not B)
           (not F)
           (not (<= V F1))
           (and (not R)
                (not Q)
                P
                (not O)
                (not N)
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           E
           F
           H
           (not B)
           (not G)
           (not I)
           (not (<= 1 V))
           (and (not R)
                (not Q)
                P
                (not O)
                (not N)
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           E
           F
           H
           I
           (not B)
           (not G)
           (not (<= T F1))
           (and (not R)
                (not Q)
                P
                (not O)
                (not N)
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           E
           F
           G
           H
           (not B)
           (not I)
           (not (<= 1 T))
           (and (not R)
                (not Q)
                P
                (not O)
                (not N)
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           E
           F
           G
           H
           I
           (not B)
           (not (<= X J1))
           (and (not R)
                (not Q)
                P
                (not O)
                (not N)
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           H
           (not D)
           (not E)
           (not F)
           (not G)
           (not I)
           (not (<= 1 X))
           (and (not R)
                (not Q)
                (not P)
                O
                N
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           I
           (not D)
           (not E)
           (not F)
           (not G)
           (not H)
           (not (<= X J1))
           (and (not R)
                (not Q)
                (not P)
                O
                N
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           G
           (not D)
           (not E)
           (not F)
           (not I)
           (not H)
           (not (<= V F1))
           (and (not R)
                (not Q)
                (not P)
                O
                N
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           G
           H
           I
           (not D)
           (not E)
           (not F)
           (not (<= T F1))
           (and (not R)
                (not Q)
                (not P)
                O
                N
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           F
           H
           (not D)
           (not E)
           (not G)
           (not I)
           (not (<= 1 T))
           (and (not R)
                (not Q)
                (not P)
                O
                N
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           F
           H
           I
           (not D)
           (not E)
           (not G)
           (not (<= T J1))
           (and (not R)
                (not Q)
                (not P)
                O
                N
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           F
           G
           H
           (not D)
           (not E)
           (not I)
           (not (<= 1 T))
           (and (not R)
                (not Q)
                (not P)
                O
                N
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           F
           G
           H
           I
           (not D)
           (not E)
           (not (<= T F1))
           (and (not R)
                (not Q)
                (not P)
                O
                N
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           E
           H
           (not D)
           (not F)
           (not G)
           (not I)
           (not (<= 1 T))
           (and (not R)
                (not Q)
                (not P)
                O
                (not N)
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           E
           H
           I
           (not D)
           (not F)
           (not G)
           (not (<= T J1))
           (and (not R)
                (not Q)
                (not P)
                O
                (not N)
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           E
           G
           H
           (not D)
           (not F)
           (not I)
           (not (<= 1 T))
           (and (not R)
                (not Q)
                (not P)
                O
                (not N)
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           G
           (not E)
           (not F)
           (not I)
           (not H)
           (<= X J1)
           (and (not R)
                (not Q)
                (not P)
                O
                (not N)
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A B C D H I (not E) (not F) (not G) (<= 1 X) a!94)
       (or A B C D H (not E) (not F) (not G) (not I) (<= X J1) a!95)
       (or A B C E F G H I (not D) (<= 1 T) a!96)
       (or A B C E F G H (not D) (not I) (<= T F1) a!97)
       (or A
           B
           C
           E
           F
           G
           H
           (not D)
           (not I)
           (not (<= T F1))
           (and (not R)
                (not Q)
                (not P)
                O
                (not N)
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           E
           F
           G
           H
           I
           (not D)
           (not (<= 1 T))
           (and (not R)
                (not Q)
                (not P)
                O
                (not N)
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           H
           (not E)
           (not F)
           (not G)
           (not I)
           (not (<= X J1))
           (and (not R)
                (not Q)
                (not P)
                (not O)
                N
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           H
           I
           (not E)
           (not F)
           (not G)
           (not (<= 1 X))
           (and (not R)
                (not Q)
                (not P)
                (not O)
                N
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           G
           (not E)
           (not F)
           (not I)
           (not H)
           (not (<= X J1))
           (and (not R)
                (not Q)
                (not P)
                (not O)
                N
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           G
           I
           (not E)
           (not F)
           (not H)
           (not (= M1 0))
           (and (not R)
                (not Q)
                (not P)
                (not O)
                N
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           G
           H
           (not F)
           (not I)
           (<= X J1)
           (and (not R)
                (not Q)
                (not P)
                (not O)
                N
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A B C D E G (not F) (not I) (not H) (<= 1 X) a!98)
       (or A B C D E I (not F) (not G) (not H) (<= X J1) a!99)
       (or A B C D E (not F) (not G) (not I) (not H) (<= 1 T) a!100)
       (or A B C D F G I (not E) (not H) (<= T F1) a!101)
       (or A
           B
           C
           D
           F
           G
           I
           (not E)
           (not H)
           (not (<= T F1))
           (and (not R)
                (not Q)
                (not P)
                (not O)
                N
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           (not F)
           (not G)
           (not I)
           (not H)
           (not (<= 1 T))
           (and (not R)
                (not Q)
                (not P)
                (not O)
                N
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           I
           (not F)
           (not G)
           (not H)
           (not (<= X J1))
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           G
           (not F)
           (not I)
           (not H)
           (not (<= 1 X))
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           G
           H
           (not F)
           (not I)
           (not (<= X J1))
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           G
           H
           I
           (not F)
           (not (<= T J1))
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           F
           H
           (not G)
           (not I)
           (not (<= T F1))
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           F
           H
           I
           (not G)
           (not (<= 1 T))
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           F
           G
           H
           (not I)
           (not (<= T F1))
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       a!103
       (or B C D E F H (not A) (not G) (not I) a!104)
       (or C G I (not A) (not B) (not D) (not E) (not F) (not H) a!105)
       (or B
           C
           D
           G
           H
           (not A)
           (not E)
           (not F)
           (not I)
           (and R
                (not Q)
                (not P)
                (not O)
                N
                M
                (not L)
                K
                J
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= F1 S)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           F
           G
           I
           (not H)
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                K
                (not J)
                (= S 1)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C E G H (not A) (not B) (not D) (not F) (not I) a!106)
       (or C D I (not A) (not B) (not E) (not F) (not G) (not H) a!107)
       (or B C E I (not A) (not D) (not F) (not G) (not H) a!108)
       (or A F G H (not C) (not B) (not D) (not E) (not I) a!109)
       (or A C E G H I (not B) (not D) (not F) a!110)
       (or C
           E
           F
           G
           H
           I
           (not A)
           (not B)
           (not D)
           (and R
                (not Q)
                P
                O
                (not N)
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= X W)
                (= Z Y)
                (= Z U)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           F
           I
           (not A)
           (not D)
           (not E)
           (not G)
           (not H)
           (and R
                (not Q)
                (not P)
                O
                N
                (not M)
                L
                K
                (not J)
                (= T S)
                (= X W)
                (= Z Y)
                (= Z U)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           D
           (not A)
           (not E)
           (not F)
           (not G)
           (not I)
           (not H)
           (and R
                (not Q)
                (not P)
                O
                (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= X W)
                (= Z Y)
                (= Z U)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           E
           G
           H
           (not C)
           (not B)
           (not F)
           (not I)
           (and (not R)
                Q
                P
                (not O)
                (not N)
                M
                (not L)
                K
                J
                (= T S)
                (= X W)
                (= Z Y)
                (= Z U)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           G
           H
           (not D)
           (not E)
           (not F)
           (not I)
           (and (not R)
                (not Q)
                (not P)
                O
                N
                M
                (not L)
                K
                J
                (= T S)
                (= X W)
                (= Z Y)
                (= Z U)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C D F I (not A) (not B) (not E) (not G) (not H) a!111)
       (or C D E F G I (not A) (not B) (not H) a!112)
       (or A H (not C) (not B) (not D) (not E) (not F) (not G) (not I) a!113)
       (or A E H I (not C) (not B) (not D) (not F) (not G) a!114)
       (or A D G H (not C) (not B) (not E) (not F) (not I) a!115)
       (or A D E F H I (not C) (not B) (not G) a!116)
       (or A B E F G H I (not C) (not D) a!117)
       (or A B D E F (not C) (not G) (not I) (not H) a!118)
       (or A C F H I (not B) (not D) (not E) (not G) a!119)
       (or A C E F G H I (not B) (not D) a!120)
       (or A C D E G H (not B) (not F) (not I) a!121)
       (or A B C E F H I (not D) (not G) a!122)
       (or A B C D F G (not E) (not I) (not H) a!123)
       (or C
           D
           E
           F
           (not A)
           (not B)
           (not G)
           (not I)
           (not H)
           (and R
                (not Q)
                P
                (not O)
                (not N)
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= Z Y)
                (= Z W)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           F
           (not A)
           (not D)
           (not E)
           (not G)
           (not I)
           (not H)
           (and R
                (not Q)
                (not P)
                O
                N
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= Z Y)
                (= Z W)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           F
           H
           I
           (not C)
           (not B)
           (not D)
           (not E)
           (not G)
           (and (not R)
                Q
                P
                O
                N
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= Z Y)
                (= Z W)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           E
           F
           G
           H
           (not C)
           (not B)
           (not D)
           (not I)
           (and (not R)
                Q
                P
                O
                (not N)
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= Z Y)
                (= Z W)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           E
           H
           I
           (not C)
           (not B)
           (not F)
           (not G)
           (and (not R)
                Q
                P
                (not O)
                (not N)
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= Z Y)
                (= Z W)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           G
           H
           (not C)
           (not D)
           (not E)
           (not F)
           (not I)
           (and (not R)
                Q
                (not P)
                O
                N
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= Z Y)
                (= Z W)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           E
           H
           (not C)
           (not F)
           (not G)
           (not I)
           (and (not R)
                Q
                (not P)
                (not O)
                (not N)
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= Z Y)
                (= Z W)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           I
           (not B)
           (not D)
           (not E)
           (not F)
           (not G)
           (not H)
           (and (not R)
                (not Q)
                P
                O
                N
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= Z Y)
                (= Z W)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B C D H I (not A) (not E) (not F) (not G) a!124)
       (or A B C D E F G (not I) (not H) a!125)
       (or C H (not A) (not B) (not D) (not E) (not F) (not G) (not I) a!1)
       (or C I (not A) (not B) (not D) (not E) (not F) (not G) (not H) a!2)
       (or C H I (not A) (not B) (not D) (not E) (not F) (not G) a!3)
       (or C G (not A) (not B) (not D) (not E) (not F) (not I) (not H) a!4)
       (or C
           G
           H
           I
           (not A)
           (not B)
           (not D)
           (not E)
           (not F)
           (and R
                (not Q)
                P
                O
                N
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           F
           H
           (not A)
           (not B)
           (not D)
           (not E)
           (not G)
           (not I)
           (and R
                (not Q)
                P
                O
                N
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           F
           H
           I
           (not A)
           (not B)
           (not D)
           (not E)
           (not G)
           (and R
                (not Q)
                P
                O
                N
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           F
           G
           H
           (not A)
           (not B)
           (not D)
           (not E)
           (not I)
           (and R
                (not Q)
                P
                O
                N
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C F G H I (not A) (not B) (not D) (not E) a!5)
       (or C E (not A) (not B) (not D) (not F) (not G) (not I) (not H) a!6)
       (or C E H (not A) (not B) (not D) (not F) (not G) (not I) a!7)
       (or C E I (not A) (not B) (not D) (not F) (not G) (not H) a!8)
       (or C E H I (not A) (not B) (not D) (not F) (not G) a!9)
       (or C
           E
           G
           I
           (not A)
           (not B)
           (not D)
           (not F)
           (not H)
           (and R
                (not Q)
                P
                O
                (not N)
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           E
           F
           (not A)
           (not B)
           (not D)
           (not G)
           (not I)
           (not H)
           (and R
                (not Q)
                P
                O
                (not N)
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           E
           F
           I
           (not A)
           (not B)
           (not D)
           (not G)
           (not H)
           (and R
                (not Q)
                P
                O
                (not N)
                (not M)
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           E
           F
           G
           (not A)
           (not B)
           (not D)
           (not I)
           (not H)
           (and R
                (not Q)
                P
                O
                (not N)
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           E
           G
           (not A)
           (not B)
           (not D)
           (not F)
           (not I)
           (not H)
           (and R
                (not Q)
                P
                O
                (not N)
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C D (not A) (not B) (not E) (not F) (not G) (not I) (not H) a!10)
       (or C D H I (not A) (not B) (not E) (not F) (not G) a!11)
       (or C D G (not A) (not B) (not E) (not F) (not I) (not H) a!12)
       (or C D G H (not A) (not B) (not E) (not F) (not I) a!13)
       (or C D G I (not A) (not B) (not E) (not F) (not H) a!14)
       (or C D G H I (not A) (not B) (not E) (not F) a!15)
       (or C D F (not A) (not B) (not E) (not G) (not I) (not H) a!16)
       (or C
           D
           F
           H
           I
           (not A)
           (not B)
           (not E)
           (not G)
           (and R
                (not Q)
                P
                (not O)
                N
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           F
           G
           H
           (not A)
           (not B)
           (not E)
           (not I)
           (and R
                (not Q)
                P
                (not O)
                N
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           F
           G
           H
           I
           (not A)
           (not B)
           (not E)
           (and R
                (not Q)
                P
                (not O)
                N
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           E
           H
           (not A)
           (not B)
           (not F)
           (not G)
           (not I)
           (and R
                (not Q)
                P
                (not O)
                (not N)
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           E
           H
           I
           (not A)
           (not B)
           (not F)
           (not G)
           (and R
                (not Q)
                P
                (not O)
                (not N)
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           E
           G
           H
           (not A)
           (not B)
           (not F)
           (not I)
           (and R
                (not Q)
                P
                (not O)
                (not N)
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           F
           H
           (not A)
           (not B)
           (not E)
           (not G)
           (not I)
           (and R
                (not Q)
                P
                (not O)
                (not N)
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C D E F H (not A) (not B) (not G) (not I) a!17)
       (or C D E F I (not A) (not B) (not G) (not H) a!18)
       (or C D E F H I (not A) (not B) (not G) a!19)
       (or C D E F G (not A) (not B) (not I) (not H) a!20)
       (or C
           D
           E
           F
           G
           H
           I
           (not A)
           (not B)
           (and R
                (not Q)
                P
                (not O)
                (not N)
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           H
           (not A)
           (not D)
           (not E)
           (not F)
           (not G)
           (not I)
           (and R
                (not Q)
                (not P)
                O
                N
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           H
           I
           (not A)
           (not D)
           (not E)
           (not F)
           (not G)
           (and R
                (not Q)
                (not P)
                O
                N
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           G
           H
           (not A)
           (not D)
           (not E)
           (not F)
           (not I)
           (and R
                (not Q)
                (not P)
                O
                N
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           E
           F
           G
           H
           (not A)
           (not B)
           (not I)
           (and R
                (not Q)
                (not P)
                O
                N
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           D
           H
           (not A)
           (not B)
           (not E)
           (not F)
           (not G)
           (not I)
           (and R
                (not Q)
                (not P)
                O
                N
                (not M)
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B C F H I (not A) (not D) (not E) (not G) a!21)
       (or B C F G (not A) (not D) (not E) (not I) (not H) a!22)
       (or B C F G H (not A) (not D) (not E) (not I) a!23)
       (or B C F G I (not A) (not D) (not E) (not H) a!24)
       (or B C F G H I (not A) (not D) (not E) a!25)
       (or B C E (not A) (not D) (not F) (not G) (not I) (not H) a!26)
       (or B
           C
           E
           H
           I
           (not A)
           (not D)
           (not F)
           (not G)
           (and R
                (not Q)
                (not P)
                O
                (not N)
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           E
           G
           H
           (not A)
           (not D)
           (not F)
           (not I)
           (and R
                (not Q)
                (not P)
                O
                (not N)
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           E
           G
           H
           I
           (not A)
           (not D)
           (not F)
           (and R
                (not Q)
                (not P)
                O
                (not N)
                M
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           E
           F
           H
           (not A)
           (not D)
           (not G)
           (not I)
           (and R
                (not Q)
                (not P)
                O
                (not N)
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           E
           F
           H
           I
           (not A)
           (not D)
           (not G)
           (and R
                (not Q)
                (not P)
                O
                (not N)
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           E
           F
           G
           H
           (not A)
           (not D)
           (not I)
           (and R
                (not Q)
                (not P)
                O
                (not N)
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           E
           H
           (not A)
           (not D)
           (not F)
           (not G)
           (not I)
           (and R
                (not Q)
                (not P)
                O
                (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or C
           G
           H
           (not A)
           (not B)
           (not D)
           (not E)
           (not F)
           (not I)
           (and R
                (not Q)
                (not P)
                (not O)
                N
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B C D G I (not A) (not E) (not F) (not H) a!27)
       (or B C D G H I (not A) (not E) (not F) a!28)
       (or B C D F (not A) (not E) (not G) (not I) (not H) a!29)
       (or B C D F H (not A) (not E) (not G) (not I) a!30)
       (or B C D F I (not A) (not E) (not G) (not H) a!31)
       (or B C D F H I (not A) (not E) (not G) a!32)
       (or B C D F G (not A) (not E) (not I) (not H) a!33)
       (or B C D F G H (not A) (not E) (not I) a!34)
       (or B C D F G I (not A) (not E) (not H) a!35)
       (or B C D F G H I (not A) (not E) a!36)
       (or B C D E (not A) (not F) (not G) (not I) (not H) a!37)
       (or B C D E H (not A) (not F) (not G) (not I) a!38)
       (or B C D E I (not A) (not F) (not G) (not H) a!39)
       (or B C D E H I (not A) (not F) (not G) a!40)
       (or B C D E G (not A) (not F) (not I) (not H) a!41)
       (or B C D E G H (not A) (not F) (not I) a!42)
       (or B C D E G I (not A) (not F) (not H) a!43)
       (or B C D E G H I (not A) (not F) a!44)
       (or B C D E F I (not A) (not G) (not H) a!102)
       (or B C D E F H I (not A) (not G) a!45)
       (or B C D E F G (not A) (not I) (not H) a!46)
       (or B C D E F G H (not A) (not I) a!47)
       (or B C D E F G I (not A) (not H) a!48)
       (or B C D E F G H I (not A) a!49)
       (or A
           I
           (not C)
           (not B)
           (not D)
           (not E)
           (not F)
           (not G)
           (not H)
           (and (not R)
                Q
                P
                O
                N
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           G
           (not C)
           (not B)
           (not D)
           (not E)
           (not F)
           (not I)
           (not H)
           (and (not R)
                Q
                P
                O
                N
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           G
           I
           (not C)
           (not B)
           (not D)
           (not E)
           (not F)
           (not H)
           (and (not R)
                Q
                P
                O
                N
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           F
           (not C)
           (not B)
           (not D)
           (not E)
           (not G)
           (not I)
           (not H)
           (and (not R)
                Q
                P
                O
                N
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           (not C)
           (not B)
           (not D)
           (not E)
           (not F)
           (not G)
           (not I)
           (not H)
           (and (not R)
                Q
                P
                O
                N
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A F G I (not C) (not B) (not D) (not E) (not H) a!50)
       (or A F G H I (not C) (not B) (not D) (not E) a!51)
       (or A E (not C) (not B) (not D) (not F) (not G) (not I) (not H) a!52)
       (or A E H (not C) (not B) (not D) (not F) (not G) (not I) a!53)
       (or A
           E
           G
           (not C)
           (not B)
           (not D)
           (not F)
           (not I)
           (not H)
           (and (not R)
                Q
                P
                O
                (not N)
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           E
           G
           I
           (not C)
           (not B)
           (not D)
           (not F)
           (not H)
           (and (not R)
                Q
                P
                O
                (not N)
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           E
           F
           (not C)
           (not B)
           (not D)
           (not G)
           (not I)
           (not H)
           (and (not R)
                Q
                P
                O
                (not N)
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           E
           F
           I
           (not C)
           (not B)
           (not D)
           (not G)
           (not H)
           (and (not R)
                Q
                P
                O
                (not N)
                (not M)
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           E
           I
           (not C)
           (not B)
           (not D)
           (not F)
           (not G)
           (not H)
           (and (not R)
                Q
                P
                O
                (not N)
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A E F G I (not C) (not B) (not D) (not H) a!54)
       (or A E F G H I (not C) (not B) (not D) a!55)
       (or A D (not C) (not B) (not E) (not F) (not G) (not I) (not H) a!56)
       (or A D H (not C) (not B) (not E) (not F) (not G) (not I) a!57)
       (or A D I (not C) (not B) (not E) (not F) (not G) (not H) a!58)
       (or A D H I (not C) (not B) (not E) (not F) (not G) a!59)
       (or A
           D
           G
           I
           (not C)
           (not B)
           (not E)
           (not F)
           (not H)
           (and (not R)
                Q
                P
                (not O)
                N
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           F
           (not C)
           (not B)
           (not E)
           (not G)
           (not I)
           (not H)
           (and (not R)
                Q
                P
                (not O)
                N
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           F
           I
           (not C)
           (not B)
           (not E)
           (not G)
           (not H)
           (and (not R)
                Q
                P
                (not O)
                N
                (not M)
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           F
           G
           (not C)
           (not B)
           (not E)
           (not I)
           (not H)
           (and (not R)
                Q
                P
                (not O)
                N
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           F
           G
           I
           (not C)
           (not B)
           (not E)
           (not H)
           (and (not R)
                Q
                P
                (not O)
                N
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           E
           (not C)
           (not B)
           (not F)
           (not G)
           (not I)
           (not H)
           (and (not R)
                Q
                P
                (not O)
                N
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           G
           (not C)
           (not B)
           (not E)
           (not F)
           (not I)
           (not H)
           (and (not R)
                Q
                P
                (not O)
                (not N)
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           F
           G
           (not C)
           (not B)
           (not D)
           (not E)
           (not I)
           (not H)
           (and (not R)
                Q
                P
                (not O)
                (not N)
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A D E G I (not C) (not B) (not F) (not H) a!60)
       (or A D E G H I (not C) (not B) (not F) a!61)
       (or A D E F (not C) (not B) (not G) (not I) (not H) a!62)
       (or A D E F H (not C) (not B) (not G) (not I) a!63)
       (or A
           D
           E
           F
           G
           (not C)
           (not B)
           (not I)
           (not H)
           (and (not R)
                Q
                P
                (not O)
                (not N)
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           E
           F
           G
           I
           (not C)
           (not B)
           (not H)
           (and (not R)
                Q
                P
                (not O)
                (not N)
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           (not C)
           (not D)
           (not E)
           (not F)
           (not G)
           (not I)
           (not H)
           (and (not R)
                Q
                P
                (not O)
                (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           I
           (not C)
           (not D)
           (not E)
           (not F)
           (not G)
           (not H)
           (and (not R)
                Q
                (not P)
                O
                N
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           D
           E
           F
           I
           (not C)
           (not B)
           (not G)
           (not H)
           (and (not R)
                Q
                (not P)
                O
                N
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           G
           I
           (not C)
           (not D)
           (not E)
           (not F)
           (not H)
           (and (not R)
                Q
                (not P)
                O
                N
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           F
           (not C)
           (not D)
           (not E)
           (not G)
           (not I)
           (not H)
           (and (not R)
                Q
                (not P)
                O
                N
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           F
           I
           (not C)
           (not D)
           (not E)
           (not G)
           (not H)
           (and (not R)
                Q
                (not P)
                O
                N
                (not M)
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           F
           G
           (not C)
           (not D)
           (not E)
           (not I)
           (not H)
           (and (not R)
                Q
                (not P)
                O
                N
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           F
           G
           I
           (not C)
           (not D)
           (not E)
           (not H)
           (and (not R)
                Q
                (not P)
                O
                N
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           E
           (not C)
           (not D)
           (not F)
           (not G)
           (not I)
           (not H)
           (and (not R)
                Q
                (not P)
                O
                N
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           E
           I
           (not C)
           (not D)
           (not F)
           (not G)
           (not H)
           (and (not R)
                Q
                (not P)
                O
                (not N)
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           E
           G
           (not C)
           (not D)
           (not F)
           (not I)
           (not H)
           (and (not R)
                Q
                (not P)
                O
                (not N)
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A B E G I (not C) (not D) (not F) (not H) a!64)
       (or A B E G H I (not C) (not D) (not F) a!65)
       (or A B E F (not C) (not D) (not G) (not I) (not H) a!66)
       (or A B E F H (not C) (not D) (not G) (not I) a!67)
       (or A B E F I (not C) (not D) (not G) (not H) a!68)
       (or A B E F H I (not C) (not D) (not G) a!69)
       (or A B E F G (not C) (not D) (not I) (not H) a!70)
       (or A B E F G H (not C) (not D) (not I) a!71)
       (or A
           B
           D
           (not C)
           (not E)
           (not F)
           (not G)
           (not I)
           (not H)
           (and (not R)
                Q
                (not P)
                O
                (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           I
           (not C)
           (not E)
           (not F)
           (not G)
           (not H)
           (and (not R)
                Q
                (not P)
                (not O)
                N
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           G
           (not C)
           (not E)
           (not F)
           (not I)
           (not H)
           (and (not R)
                Q
                (not P)
                (not O)
                N
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           G
           I
           (not C)
           (not E)
           (not F)
           (not H)
           (and (not R)
                Q
                (not P)
                (not O)
                N
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           F
           (not C)
           (not E)
           (not G)
           (not I)
           (not H)
           (and (not R)
                Q
                (not P)
                (not O)
                N
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           F
           I
           (not C)
           (not E)
           (not G)
           (not H)
           (and (not R)
                Q
                (not P)
                (not O)
                N
                (not M)
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           F
           G
           (not C)
           (not E)
           (not I)
           (not H)
           (and (not R)
                Q
                (not P)
                (not O)
                N
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           F
           G
           I
           (not C)
           (not E)
           (not H)
           (and (not R)
                Q
                (not P)
                (not O)
                N
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           E
           F
           G
           I
           (not C)
           (not D)
           (not H)
           (and (not R)
                Q
                (not P)
                (not O)
                (not N)
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A B D E H I (not C) (not F) (not G) a!72)
       (or A B D E G (not C) (not F) (not I) (not H) a!73)
       (or A B D E G H (not C) (not F) (not I) a!74)
       (or A B D E G I (not C) (not F) (not H) a!75)
       (or A
           B
           D
           E
           F
           H
           (not C)
           (not G)
           (not I)
           (and (not R)
                Q
                (not P)
                (not O)
                (not N)
                (not M)
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           E
           F
           H
           I
           (not C)
           (not G)
           (and (not R)
                Q
                (not P)
                (not O)
                (not N)
                (not M)
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           E
           F
           G
           H
           (not C)
           (not I)
           (and (not R)
                Q
                (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           E
           F
           G
           H
           I
           (not C)
           (and (not R)
                Q
                (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           D
           E
           G
           H
           I
           (not C)
           (not F)
           (and (not R)
                (not Q)
                P
                O
                N
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A C G (not B) (not D) (not E) (not F) (not I) (not H) a!76)
       (or A C G H (not B) (not D) (not E) (not F) (not I) a!77)
       (or A C G I (not B) (not D) (not E) (not F) (not H) a!78)
       (or A C G H I (not B) (not D) (not E) (not F) a!79)
       (or A C F (not B) (not D) (not E) (not G) (not I) (not H) a!80)
       (or A C F H (not B) (not D) (not E) (not G) (not I) a!81)
       (or A
           C
           F
           G
           (not B)
           (not D)
           (not E)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                P
                O
                N
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           F
           G
           I
           (not B)
           (not D)
           (not E)
           (not H)
           (and (not R)
                (not Q)
                P
                O
                N
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           E
           (not B)
           (not D)
           (not F)
           (not G)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                P
                O
                N
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           E
           I
           (not B)
           (not D)
           (not F)
           (not G)
           (not H)
           (and (not R)
                (not Q)
                P
                O
                (not N)
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           F
           I
           (not B)
           (not D)
           (not E)
           (not G)
           (not H)
           (and (not R)
                (not Q)
                P
                O
                (not N)
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A C E F (not B) (not D) (not G) (not I) (not H) a!82)
       (or A C E F H (not B) (not D) (not G) (not I) a!83)
       (or A C E F I (not B) (not D) (not G) (not H) a!84)
       (or A C E F H I (not B) (not D) (not G) a!85)
       (or A C E F G (not B) (not D) (not I) (not H) a!86)
       (or A C E F G H (not B) (not D) (not I) a!87)
       (or A
           C
           D
           (not B)
           (not E)
           (not F)
           (not G)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                P
                O
                (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           I
           (not B)
           (not E)
           (not F)
           (not G)
           (not H)
           (and (not R)
                (not Q)
                P
                (not O)
                N
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           G
           (not B)
           (not E)
           (not F)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                P
                (not O)
                N
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           G
           I
           (not B)
           (not E)
           (not F)
           (not H)
           (and (not R)
                (not Q)
                P
                (not O)
                N
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           F
           (not B)
           (not E)
           (not G)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                P
                (not O)
                N
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           F
           I
           (not B)
           (not E)
           (not G)
           (not H)
           (and (not R)
                (not Q)
                P
                (not O)
                N
                (not M)
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           E
           F
           G
           I
           (not B)
           (not D)
           (not H)
           (and (not R)
                (not Q)
                P
                (not O)
                N
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A C D F G I (not B) (not E) (not H) a!88)
       (or A C D F G H I (not B) (not E) a!89)
       (or A C D E (not B) (not F) (not G) (not I) (not H) a!90)
       (or A C D E H (not B) (not F) (not G) (not I) a!91)
       (or A C D E I (not B) (not F) (not G) (not H) a!92)
       (or A C D E H I (not B) (not F) (not G) a!93)
       (or A
           C
           D
           E
           G
           I
           (not B)
           (not F)
           (not H)
           (and (not R)
                (not Q)
                P
                (not O)
                (not N)
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           E
           F
           (not B)
           (not G)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                P
                (not O)
                (not N)
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           E
           F
           I
           (not B)
           (not G)
           (not H)
           (and (not R)
                (not Q)
                P
                (not O)
                (not N)
                (not M)
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           E
           F
           G
           (not B)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                P
                (not O)
                (not N)
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           E
           F
           G
           I
           (not B)
           (not H)
           (and (not R)
                (not Q)
                P
                (not O)
                (not N)
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           (not D)
           (not E)
           (not F)
           (not G)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                P
                (not O)
                (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           E
           G
           (not B)
           (not F)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                O
                N
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           E
           G
           I
           (not B)
           (not D)
           (not F)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                O
                N
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           G
           I
           (not D)
           (not E)
           (not F)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                O
                N
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           F
           (not D)
           (not E)
           (not G)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                O
                N
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           F
           I
           (not D)
           (not E)
           (not G)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                O
                N
                (not M)
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           F
           G
           (not D)
           (not E)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                O
                N
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           F
           G
           I
           (not D)
           (not E)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                O
                N
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           E
           (not D)
           (not F)
           (not G)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                O
                N
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           E
           I
           (not D)
           (not F)
           (not G)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                O
                (not N)
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           E
           G
           (not D)
           (not F)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                O
                (not N)
                M
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A B C E G I (not D) (not F) (not H) a!94)
       (or A B C E G H I (not D) (not F) a!95)
       (or A B C E F (not D) (not G) (not I) (not H) a!96)
       (or A B C E F H (not D) (not G) (not I) a!97)
       (or A
           B
           C
           E
           F
           G
           (not D)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                O
                (not N)
                (not M)
                L
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           E
           F
           G
           I
           (not D)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                O
                (not N)
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           (not E)
           (not F)
           (not G)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                O
                (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           I
           (not E)
           (not F)
           (not G)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                (not O)
                N
                M
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           E
           F
           I
           (not D)
           (not G)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                (not O)
                N
                M
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A B C D G H I (not E) (not F) a!98)
       (or A B C D F (not E) (not G) (not I) (not H) a!99)
       (or A B C D F H (not E) (not G) (not I) a!100)
       (or A B C D F I (not E) (not G) (not H) a!101)
       (or A
           B
           C
           D
           F
           G
           H
           (not E)
           (not I)
           (and (not R)
                (not Q)
                (not P)
                (not O)
                N
                (not M)
                (not L)
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           F
           G
           H
           I
           (not E)
           (and (not R)
                (not Q)
                (not P)
                (not O)
                N
                (not M)
                (not L)
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           H
           (not F)
           (not G)
           (not I)
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                M
                L
                K
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           H
           I
           (not F)
           (not G)
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           F
           H
           I
           (not E)
           (not G)
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                M
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           F
           (not G)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                M
                (not L)
                (not K)
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           F
           I
           (not G)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                (not M)
                L
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or B
           C
           D
           E
           F
           (not A)
           (not G)
           (not I)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                K
                (not J)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A B C D E F G H I a!126)
       (or C
           (not A)
           (not B)
           (not D)
           (not E)
           (not F)
           (not G)
           (not I)
           (not H)
           a!126)
       (or A
           C
           E
           G
           H
           (not B)
           (not D)
           (not F)
           (not I)
           (and (not R)
                (not Q)
                P
                O
                (not N)
                M
                (not L)
                K
                J
                (= W T)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           D
           F
           G
           H
           (not B)
           (not E)
           (not I)
           (and (not R)
                (not Q)
                P
                (not O)
                N
                (not M)
                (not L)
                K
                J
                (= W T)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           H
           I
           (not D)
           (not E)
           (not F)
           (not G)
           (and (not R)
                (not Q)
                (not P)
                O
                N
                M
                L
                (not K)
                J
                (= W T)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           G
           H
           (not E)
           (not F)
           (not I)
           (and (not R)
                (not Q)
                (not P)
                (not O)
                N
                M
                (not L)
                K
                J
                (= W T)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           B
           C
           D
           E
           G
           I
           (not F)
           (not H)
           (and (not R)
                (not Q)
                (not P)
                (not O)
                (not N)
                M
                (not L)
                K
                (not J)
                (= W T)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1)))
       (or A
           C
           H
           I
           (not B)
           (not D)
           (not E)
           (not F)
           (not G)
           (not (<= T J1))
           (= F1 T)
           (and (not R)
                (not Q)
                P
                O
                N
                M
                L
                (not K)
                J
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= J1 I1)
                (= L1 K1))))))
      )
      (state K J L M N O P Q R K1 I1 G1 E1 C1 A1 Y W U S)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) ) 
    (=>
      (and
        (state I H G F E D B C A S R Q P O N M L K J)
        (or (and (not A) (not B) (not C) (not D) E (not F) G (not H) I)
    (and (not A) (not B) (not C) (not D) E (not F) G H (not I))
    (and (not A) (not B) (not C) (not D) E (not F) G H I)
    (and (not A) (not B) (not C) (not D) E F (not G) (not H) (not I))
    (and (not A) (not B) (not C) D (not E) (not F) G (not H) I)
    (and (not A) (not B) (not C) D (not E) (not F) G H I)
    (and (not A) (not B) (not C) D (not E) F (not G) (not H) (not I))
    (and (not A) (not B) (not C) D (not E) F (not G) H (not I))
    (and (not A) (not B) C (not D) (not E) F (not G) (not H) I)
    (and (not A) (not B) C (not D) (not E) F (not G) H (not I))
    (and (not A) (not B) C (not D) (not E) F (not G) H I)
    (and (not A) (not B) C (not D) (not E) F G (not H) (not I))
    (and (not A) (not B) C D (not E) (not F) (not G) (not H) I)
    (and (not A) (not B) C D (not E) (not F) (not G) H I)
    (and (not A) (not B) C D (not E) (not F) G (not H) (not I))
    (and (not A) (not B) C D (not E) (not F) G (not H) I)
    (and (not A) (not B) C D (not E) (not F) G H (not I))
    (and (not A) (not B) C D (not E) (not F) G H I)
    (and (not A) (not B) C D (not E) F (not G) (not H) (not I))
    (and (not A) (not B) C D (not E) F (not G) H (not I))
    (and (not A) B (not C) (not D) (not E) F G (not H) (not I))
    (and (not A) B (not C) (not D) (not E) F G (not H) I)
    (and (not A) B (not C) (not D) (not E) F G H (not I))
    (and (not A) B (not C) (not D) (not E) F G H I)
    (and (not A) B (not C) (not D) E (not F) (not G) (not H) (not I))
    (and (not A) B (not C) (not D) E (not F) (not G) H (not I))
    (and (not A) B (not C) D (not E) (not F) (not G) (not H) I)
    (and (not A) B (not C) D (not E) (not F) (not G) H I)
    (and (not A) B (not C) D (not E) (not F) G (not H) (not I))
    (and (not A) B (not C) D (not E) (not F) G (not H) I)
    (and (not A) B (not C) D (not E) (not F) G H (not I))
    (and (not A) B (not C) D (not E) (not F) G H I)
    (and (not A) B (not C) D E (not F) G (not H) I)
    (and (not A) B (not C) D E (not F) G H I)
    (and (not A) B (not C) D E F (not G) (not H) (not I))
    (and (not A) B (not C) D E F (not G) H (not I))
    (and (not A) B C (not D) (not E) (not F) G (not H) I)
    (and (not A) B C (not D) (not E) (not F) G H I)
    (and (not A) B C (not D) (not E) F (not G) (not H) (not I))
    (and (not A) B C (not D) (not E) F (not G) H (not I))
    (and (not A) B C (not D) E F G (not H) (not I))
    (and (not A) B C (not D) E F G (not H) I)
    (and (not A) B C (not D) E F G H (not I))
    (and (not A) B C (not D) E F G H I)
    (and (not A) B C D (not E) (not F) (not G) (not H) (not I))
    (and (not A) B C D (not E) (not F) (not G) H (not I))
    (and (not A) B C D (not E) F G (not H) I)
    (and (not A) B C D (not E) F G H I)
    (and (not A) B C D E (not F) (not G) (not H) (not I))
    (and (not A) B C D E (not F) (not G) H (not I))
    (and A (not B) (not C) (not D) (not E) (not F) (not G) (not H) (not I))
    (and A (not B) (not C) (not D) (not E) (not F) (not G) (not H) I)
    (and A (not B) (not C) (not D) (not E) (not F) (not G) H (not I))
    (and A (not B) (not C) (not D) (not E) (not F) (not G) H I)
    (and A (not B) (not C) (not D) (not E) F (not G) (not H) (not I))
    (and A (not B) (not C) (not D) (not E) F (not G) (not H) I)
    (and A (not B) (not C) (not D) (not E) F (not G) H (not I))
    (and A (not B) (not C) (not D) (not E) F (not G) H I)
    (and A (not B) (not C) (not D) (not E) F G (not H) (not I))
    (and A (not B) (not C) (not D) (not E) F G (not H) I)
    (and A (not B) (not C) (not D) (not E) F G H (not I))
    (and A (not B) (not C) (not D) (not E) F G H I)
    (and A (not B) (not C) (not D) E (not F) (not G) (not H) (not I))
    (and A (not B) (not C) (not D) E (not F) (not G) (not H) I)
    (and A (not B) (not C) (not D) E (not F) (not G) H (not I))
    (and A (not B) (not C) (not D) E (not F) (not G) H I)
    (and A (not B) (not C) (not D) E (not F) G (not H) (not I))
    (and A (not B) (not C) (not D) E (not F) G (not H) I)
    (and A (not B) (not C) (not D) E (not F) G H (not I))
    (and A (not B) (not C) (not D) E (not F) G H I)
    (and A (not B) (not C) (not D) E F (not G) (not H) (not I))
    (and A (not B) (not C) (not D) E F (not G) H (not I))
    (and A (not B) (not C) D (not E) F G H I)
    (and A (not B) (not C) D E (not F) (not G) (not H) (not I))
    (and A (not B) (not C) D E (not F) (not G) (not H) I)
    (and A (not B) (not C) D E (not F) (not G) H (not I))
    (and A (not B) (not C) D E (not F) (not G) H I)
    (and A (not B) (not C) D E (not F) G (not H) (not I))
    (and A B (not C) (not D) (not E) (not F) (not G) H I)
    (and A B (not C) (not D) (not E) (not F) G (not H) (not I))
    (and A B (not C) (not D) (not E) (not F) G (not H) I)
    (and A B (not C) (not D) (not E) (not F) G H (not I))
    (and A B (not C) (not D) E (not F) G H I)
    (and A B (not C) (not D) E F (not G) (not H) (not I))
    (and A B (not C) (not D) E F (not G) (not H) I)
    (and A B (not C) (not D) E F (not G) H (not I))
    (and A B (not C) (not D) E F (not G) H I)
    (and A B (not C) (not D) E F G (not H) (not I))
    (and A B (not C) D (not E) F G (not H) (not I))
    (and A B (not C) D (not E) F G (not H) I)
    (and A B (not C) D (not E) F G H (not I))
    (and A B (not C) D (not E) F G H I)
    (and A B (not C) D E F (not G) H I)
    (and A B (not C) D E F G (not H) (not I))
    (and A B (not C) D E F G (not H) I)
    (and A B (not C) D E F G H (not I)))
      )
      false
    )
  )
)

(check-sat)
(exit)
