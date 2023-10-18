; ./vmt/./ctigar/barbr.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) ) 
    (=>
      (and
        (and (= G true) (not F) (not E) (not D) (not C) (not B) (not A) (not H))
      )
      (state H G F E D B C A I J K L M N O P)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) ) 
    (=>
      (and
        (state H G F E D B C A R T V X Z B1 D1 F1)
        (let ((a!1 (and P
                (not O)
                N
                M
                L
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!2 (and P
                (not O)
                N
                M
                L
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!3 (and P
                (not O)
                N
                M
                (not L)
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!4 (and P
                (not O)
                N
                M
                (not L)
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!5 (and P
                (not O)
                (not N)
                (not M)
                L
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!6 (and P
                (not O)
                (not N)
                (not M)
                L
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!7 (and P
                (not O)
                (not N)
                (not M)
                L
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!8 (and P
                (not O)
                (not N)
                (not M)
                L
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!9 (and P
                (not O)
                (not N)
                (not M)
                (not L)
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!10 (and P
                 (not O)
                 (not N)
                 (not M)
                 (not L)
                 K
                 (not J)
                 I
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)))
      (a!11 (and P
                 (not O)
                 (not N)
                 (not M)
                 (not L)
                 (not K)
                 J
                 I
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)))
      (a!12 (and P
                 (not O)
                 (not N)
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 I
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)))
      (a!13 (and (not P)
                 O
                 N
                 M
                 (not L)
                 K
                 (not J)
                 (not I)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ R (* (- 1) Q)) (- 1))))
      (a!14 (and (not P)
                 O
                 (not N)
                 (not M)
                 L
                 K
                 J
                 (not I)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ R (* (- 1) Q)) 1)))
      (a!15 (and (not P)
                 (not O)
                 N
                 M
                 L
                 (not K)
                 J
                 (not I)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ R (* (- 1) Q)) 1)))
      (a!16 (and (not P)
                 (not O)
                 N
                 (not M)
                 (not L)
                 K
                 (not J)
                 I
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ R (* (- 1) Q)) 1)))
      (a!17 (and (not P)
                 (not O)
                 N
                 (not M)
                 (not L)
                 K
                 (not J)
                 (not I)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ R (* (- 1) Q)) 1)))
      (a!18 (and (not P)
                 O
                 (not N)
                 M
                 L
                 (not K)
                 (not J)
                 (not I)
                 (= R Q)
                 (= T S)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ V (* (- 1) U)) (- 1))))
      (a!19 (and (not P)
                 O
                 N
                 (not M)
                 L
                 K
                 (not J)
                 (not I)
                 (= R Q)
                 (= T S)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ V (* (- 1) U)) 1)))
      (a!20 (and (not P)
                 O
                 (not N)
                 M
                 (not L)
                 (not K)
                 (not J)
                 (not I)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!21 (and (not P)
                 (not O)
                 N
                 M
                 (not L)
                 K
                 J
                 (not I)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!22 (and (not P)
                 (not O)
                 N
                 (not M)
                 L
                 K
                 (not J)
                 I
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!23 (and (not P)
                 (not O)
                 N
                 (not M)
                 L
                 K
                 (not J)
                 (not I)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!24 (and (not P)
                 O
                 (not N)
                 (not M)
                 (not L)
                 (not K)
                 J
                 I
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ B1 (* (- 1) A1)) 1)))
      (a!25 (and (not P)
                 O
                 (not N)
                 M
                 (not L)
                 (not K)
                 J
                 I
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= (+ F1 (* (- 1) E1)) (- 1))))
      (a!26 (and (not P)
                 O
                 N
                 M
                 (not L)
                 K
                 J
                 I
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= (+ F1 (* (- 1) E1)) 1)))
      (a!27 (and (not P)
                 O
                 N
                 (not M)
                 (not L)
                 K
                 (not J)
                 (not I)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= (+ F1 (* (- 1) E1)) 1)))
      (a!28 (and (not P)
                 (not O)
                 N
                 M
                 L
                 (not K)
                 J
                 I
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= (+ F1 (* (- 1) E1)) 1)))
      (a!29 (and (not P)
                 (not O)
                 (not N)
                 M
                 (not L)
                 (not K)
                 (not J)
                 I
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= (+ F1 (* (- 1) E1)) 1)))
      (a!30 (and P
                 (not O)
                 N
                 M
                 L
                 K
                 J
                 (not I)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)))
      (a!31 (and (not P)
                 (not O)
                 (not N)
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 (not I)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1))))
  (and (or B C F G H (not A) (not D) (not E) (<= 0 R) a!1)
       (or B C E G H (not A) (not D) (not F) (<= 0 F1) a!2)
       (or B
           C
           F
           G
           H
           (not A)
           (not D)
           (not E)
           (not (<= 0 R))
           (and P
                (not O)
                N
                M
                L
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B C E F G (not A) (not D) (not H) (<= 0 D1) a!3)
       (or B C E G (not A) (not D) (not F) (not H) (<= 0 B1) a!4)
       (or B
           C
           E
           G
           (not A)
           (not D)
           (not F)
           (not H)
           (not (<= 0 B1))
           (and P
                (not O)
                N
                (not M)
                L
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           E
           F
           G
           (not A)
           (not D)
           (not H)
           (not (<= 0 D1))
           (and P
                (not O)
                N
                (not M)
                L
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           E
           G
           H
           (not A)
           (not D)
           (not F)
           (not (<= 0 F1))
           (and P
                (not O)
                N
                (not M)
                L
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           E
           F
           G
           H
           (not A)
           (not D)
           (not (<= 0 Z))
           (and P
                (not O)
                N
                (not M)
                L
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           D
           G
           (not A)
           (not E)
           (not F)
           (not H)
           (not (<= 0 X))
           (and P
                (not O)
                (not N)
                M
                L
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           D
           F
           G
           (not A)
           (not E)
           (not H)
           (not (<= T 3))
           (and P
                (not O)
                (not N)
                M
                L
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           D
           G
           H
           (not A)
           (not E)
           (not F)
           (not (<= 0 V))
           (and P
                (not O)
                (not N)
                M
                L
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           D
           F
           G
           H
           (not A)
           (not E)
           (not (<= V 1))
           (and P
                (not O)
                (not N)
                M
                L
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B C D E F G H (not A) (<= F1 T) a!5)
       (or B
           C
           D
           E
           G
           (not A)
           (not F)
           (not H)
           (not (<= X 1))
           (and P
                (not O)
                (not N)
                (not M)
                L
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B C D F G H (not A) (not E) (<= V 1) a!6)
       (or B
           C
           D
           E
           F
           G
           (not A)
           (not H)
           (not (<= D1 1))
           (and P
                (not O)
                (not N)
                (not M)
                L
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B C D E G H (not A) (not F) (<= Z 1) a!7)
       (or B
           C
           D
           E
           G
           H
           (not A)
           (not F)
           (not (<= Z 1))
           (and P
                (not O)
                (not N)
                (not M)
                L
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B C D G H (not A) (not E) (not F) (<= 0 V) a!8)
       (or B
           C
           D
           E
           F
           G
           H
           (not A)
           (not (<= F1 T))
           (and P
                (not O)
                (not N)
                (not M)
                L
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B C D E F G (not A) (not H) (<= D1 1) a!9)
       (or B C D F G (not A) (not E) (not H) (<= T 3) a!10)
       (or B C D E G (not A) (not F) (not H) (<= X 1) a!11)
       (or B C D G (not A) (not E) (not F) (not H) (<= 0 X) a!12)
       (or A
           B
           C
           D
           F
           H
           (not E)
           (not G)
           (= G1 0)
           (and P
                (not O)
                (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           H
           (not C)
           (not D)
           (not E)
           (not F)
           (not G)
           (not (<= 1 T))
           (and (not P)
                O
                N
                M
                L
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           F
           H
           (not C)
           (not B)
           (not D)
           (not E)
           (not G)
           (not (<= D1 1))
           (and (not P)
                O
                N
                M
                L
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           F
           (not C)
           (not B)
           (not D)
           (not E)
           (not H)
           (not G)
           (not (<= 1 F1))
           (and (not P)
                O
                N
                M
                L
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           G
           H
           (not C)
           (not D)
           (not E)
           (not F)
           (not (= G1 0))
           (and (not P)
                O
                N
                M
                L
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           E
           (not C)
           (not B)
           (not D)
           (not F)
           (not H)
           (not G)
           (not (<= 1 D1))
           (and (not P)
                O
                N
                M
                L
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           E
           (not C)
           (not D)
           (not F)
           (not H)
           (not G)
           (not (<= T 0))
           (and (not P)
                O
                N
                M
                L
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           H
           (not C)
           (not D)
           (not E)
           (not F)
           (not G)
           (<= 1 T)
           (and (not P)
                O
                N
                M
                (not L)
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           F
           H
           (not C)
           (not B)
           (not D)
           (not E)
           (not G)
           (<= D1 1)
           (and (not P)
                O
                N
                M
                (not L)
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           F
           (not C)
           (not B)
           (not D)
           (not E)
           (not H)
           (not G)
           (<= 1 F1)
           (and (not P)
                O
                N
                M
                (not L)
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           E
           G
           H
           (not C)
           (not D)
           (not F)
           (= G1 0)
           (and (not P)
                O
                N
                M
                (not L)
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           E
           (not C)
           (not B)
           (not D)
           (not F)
           (not H)
           (not G)
           (<= 1 D1)
           (and (not P)
                O
                N
                M
                (not L)
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           E
           (not C)
           (not D)
           (not F)
           (not H)
           (not G)
           (<= T 0)
           (and (not P)
                O
                N
                M
                (not L)
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           G
           (not C)
           (not B)
           (not E)
           (not F)
           (not H)
           (= G1 0)
           (and (not P)
                O
                N
                (not M)
                L
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           E
           H
           (not C)
           (not D)
           (not F)
           (not G)
           (not (<= 0 T))
           (and (not P)
                O
                N
                (not M)
                L
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           E
           F
           H
           (not C)
           (not B)
           (not D)
           (not G)
           (not (<= T 3))
           (and (not P)
                O
                N
                (not M)
                L
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           E
           F
           (not C)
           (not B)
           (not D)
           (not H)
           (not G)
           (not (= F1 0))
           (and (not P)
                O
                N
                (not M)
                L
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           E
           G
           H
           (not C)
           (not D)
           (not F)
           (not (= G1 0))
           (and (not P)
                O
                N
                (not M)
                L
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           (not C)
           (not B)
           (not E)
           (not F)
           (not H)
           (not G)
           (not (<= 3 T))
           (and (not P)
                O
                N
                (not M)
                L
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           (not C)
           (not E)
           (not F)
           (not H)
           (not G)
           (not (<= 1 F1))
           (and (not P)
                O
                N
                (not M)
                L
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           E
           H
           (not C)
           (not D)
           (not F)
           (not G)
           (<= 0 T)
           (and (not P)
                O
                N
                (not M)
                (not L)
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           E
           F
           H
           (not C)
           (not B)
           (not D)
           (not G)
           (<= T 3)
           (and (not P)
                O
                N
                (not M)
                (not L)
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           E
           F
           (not C)
           (not B)
           (not D)
           (not H)
           (not G)
           (= F1 0)
           (and (not P)
                O
                N
                (not M)
                (not L)
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           F
           G
           (not C)
           (not E)
           (not H)
           (= G1 0)
           (and (not P)
                O
                N
                (not M)
                (not L)
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           (not C)
           (not B)
           (not E)
           (not F)
           (not H)
           (not G)
           (<= 3 T)
           (and (not P)
                O
                N
                (not M)
                (not L)
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           (not C)
           (not E)
           (not F)
           (not H)
           (not G)
           (<= 1 F1)
           (and (not P)
                O
                N
                (not M)
                (not L)
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           G
           (not C)
           (not B)
           (not E)
           (not F)
           (not H)
           (not (= G1 0))
           (and (not P)
                O
                (not N)
                M
                L
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           H
           (not C)
           (not E)
           (not F)
           (not G)
           (not (<= V 1))
           (and (not P)
                O
                (not N)
                M
                L
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           F
           H
           (not C)
           (not B)
           (not E)
           (not G)
           (not (<= T 2))
           (and (not P)
                O
                (not N)
                M
                L
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           F
           G
           (not C)
           (not E)
           (not H)
           (not (= G1 0))
           (and (not P)
                O
                (not N)
                M
                L
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           F
           (not C)
           (not E)
           (not H)
           (not G)
           (not (<= 1 V))
           (and (not P)
                O
                (not N)
                M
                L
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           E
           (not C)
           (not B)
           (not F)
           (not H)
           (not G)
           (not (<= 2 T))
           (and (not P)
                O
                (not N)
                M
                L
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           E
           G
           (not C)
           (not B)
           (not F)
           (not H)
           (= G1 0)
           (and (not P)
                O
                (not N)
                M
                (not L)
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           H
           (not C)
           (not E)
           (not F)
           (not G)
           (<= V 1)
           (and (not P)
                O
                (not N)
                M
                (not L)
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           F
           H
           (not C)
           (not B)
           (not E)
           (not G)
           (<= T 2)
           (and (not P)
                O
                (not N)
                M
                (not L)
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           (not B)
           (not D)
           (not E)
           (not F)
           (not H)
           (not G)
           (= G1 0)
           (and (not P)
                O
                (not N)
                M
                (not L)
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           F
           (not C)
           (not E)
           (not H)
           (not G)
           (<= 1 V)
           (and (not P)
                O
                (not N)
                M
                (not L)
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           E
           (not C)
           (not B)
           (not F)
           (not H)
           (not G)
           (<= 2 T)
           (and (not P)
                O
                (not N)
                M
                (not L)
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           E
           G
           (not C)
           (not B)
           (not F)
           (not H)
           (not (= G1 0))
           (and (not P)
                O
                (not N)
                (not M)
                L
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           E
           F
           H
           (not C)
           (not B)
           (not G)
           (not (<= 1 B1))
           (and (not P)
                O
                (not N)
                (not M)
                L
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           E
           F
           G
           (not C)
           (not H)
           (<= V 0)
           (and (not P)
                O
                (not N)
                (not M)
                L
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           E
           G
           H
           (not C)
           (not F)
           (<= 1 R)
           (and (not P)
                O
                (not N)
                (not M)
                L
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           (not C)
           (not D)
           (not E)
           (not F)
           (not H)
           (not G)
           (not (<= T 1))
           (and (not P)
                O
                (not N)
                (not M)
                L
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           E
           F
           G
           H
           (not C)
           (<= 0 V)
           (and (not P)
                O
                (not N)
                (not M)
                L
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           G
           H
           (not C)
           (not D)
           (not E)
           (not F)
           (= G1 0)
           (and (not P)
                O
                (not N)
                (not M)
                (not L)
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           E
           G
           H
           (not C)
           (not F)
           (not (<= 1 R))
           (and (not P)
                O
                (not N)
                (not M)
                (not L)
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           E
           F
           H
           (not C)
           (not B)
           (not G)
           (<= 1 B1)
           (and (not P)
                O
                (not N)
                (not M)
                (not L)
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           E
           F
           G
           H
           (not C)
           (not (<= 0 V))
           (and (not P)
                O
                (not N)
                (not M)
                (not L)
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           E
           F
           G
           (not C)
           (not H)
           (not (<= V 0))
           (and (not P)
                O
                (not N)
                (not M)
                (not L)
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           (not C)
           (not D)
           (not E)
           (not F)
           (not H)
           (not G)
           (<= T 1)
           (and (not P)
                O
                (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           (not B)
           (not D)
           (not E)
           (not F)
           (not H)
           (not G)
           (not (= G1 0))
           (and (not P)
                O
                (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           E
           H
           (not B)
           (not D)
           (not F)
           (not G)
           (= G1 0)
           (and (not P)
                (not O)
                N
                M
                L
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           F
           G
           (not B)
           (not D)
           (not E)
           (not H)
           (<= 1 F1)
           (and (not P)
                (not O)
                N
                M
                L
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           F
           G
           (not D)
           (not E)
           (not H)
           (<= 1 R)
           (and (not P)
                (not O)
                N
                M
                L
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           F
           G
           H
           (not B)
           (not D)
           (not E)
           (<= X 1)
           (and (not P)
                (not O)
                N
                M
                L
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           F
           G
           H
           (not D)
           (not E)
           (<= Z 0)
           (and (not P)
                (not O)
                N
                M
                L
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           F
           G
           H
           (not B)
           (not D)
           (not E)
           (not (<= X 1))
           (and (not P)
                (not O)
                N
                M
                (not L)
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           F
           G
           H
           (not D)
           (not E)
           (not (<= Z 0))
           (and (not P)
                (not O)
                N
                M
                (not L)
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           F
           G
           (not B)
           (not D)
           (not E)
           (not H)
           (not (<= 1 F1))
           (and (not P)
                (not O)
                N
                M
                (not L)
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           F
           G
           (not D)
           (not E)
           (not H)
           (not (<= 1 R))
           (and (not P)
                (not O)
                N
                M
                (not L)
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           E
           G
           (not B)
           (not D)
           (not F)
           (not H)
           (not (<= 1 X))
           (and (not P)
                (not O)
                N
                M
                (not L)
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           E
           G
           (not D)
           (not F)
           (not H)
           (not (<= 0 Z))
           (and (not P)
                (not O)
                N
                M
                (not L)
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           E
           G
           (not B)
           (not D)
           (not F)
           (not H)
           (<= 1 X)
           (and (not P)
                (not O)
                N
                (not M)
                L
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           E
           G
           (not D)
           (not F)
           (not H)
           (<= 0 Z)
           (and (not P)
                (not O)
                N
                (not M)
                L
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           F
           G
           (not B)
           (not E)
           (not H)
           (= G1 0)
           (and (not P)
                (not O)
                N
                (not M)
                L
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           F
           G
           (not E)
           (not H)
           (= G1 0)
           (and (not P)
                (not O)
                N
                (not M)
                L
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           (not B)
           (not E)
           (not F)
           (not H)
           (not G)
           (not (<= 1 R))
           (and (not P)
                (not O)
                N
                (not M)
                L
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           (not E)
           (not F)
           (not H)
           (not G)
           (not (<= 1 R))
           (and (not P)
                (not O)
                N
                (not M)
                L
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           E
           H
           (not B)
           (not D)
           (not F)
           (not G)
           (not (= G1 0))
           (and (not P)
                (not O)
                N
                (not M)
                (not L)
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           E
           H
           (not D)
           (not F)
           (not G)
           (not (= G1 0))
           (and (not P)
                (not O)
                N
                (not M)
                (not L)
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           (not B)
           (not E)
           (not F)
           (not H)
           (not G)
           (<= 1 R)
           (and (not P)
                (not O)
                N
                (not M)
                (not L)
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           (not E)
           (not F)
           (not H)
           (not G)
           (<= 1 R)
           (and (not P)
                (not O)
                N
                (not M)
                (not L)
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           H
           (not B)
           (not E)
           (not F)
           (not G)
           (not (<= X 0))
           (and (not P)
                (not O)
                (not N)
                M
                L
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           H
           (not E)
           (not F)
           (not G)
           (not (<= D1 0))
           (and (not P)
                (not O)
                (not N)
                M
                L
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           F
           G
           (not B)
           (not E)
           (not H)
           (not (= G1 0))
           (and (not P)
                (not O)
                (not N)
                M
                L
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           F
           G
           (not E)
           (not H)
           (not (= G1 0))
           (and (not P)
                (not O)
                (not N)
                M
                L
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           F
           (not B)
           (not E)
           (not H)
           (not G)
           (not (<= 0 X))
           (and (not P)
                (not O)
                (not N)
                M
                L
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           F
           (not E)
           (not H)
           (not G)
           (not (<= 0 D1))
           (and (not P)
                (not O)
                (not N)
                M
                L
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           H
           (not B)
           (not E)
           (not F)
           (not G)
           (<= X 0)
           (and (not P)
                (not O)
                (not N)
                M
                (not L)
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           H
           (not E)
           (not F)
           (not G)
           (<= D1 0)
           (and (not P)
                (not O)
                (not N)
                M
                (not L)
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           E
           F
           G
           H
           (not B)
           (= G1 0)
           (and (not P)
                (not O)
                (not N)
                M
                (not L)
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           F
           H
           (not E)
           (not G)
           (not (= G1 0))
           (and (not P)
                (not O)
                (not N)
                M
                (not L)
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           F
           (not B)
           (not E)
           (not H)
           (not G)
           (<= 0 X)
           (and (not P)
                (not O)
                (not N)
                M
                (not L)
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           F
           (not E)
           (not H)
           (not G)
           (<= 0 D1)
           (and (not P)
                (not O)
                (not N)
                M
                (not L)
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           E
           H
           (not B)
           (not F)
           (not G)
           (not (<= 1 F1))
           (and (not P)
                (not O)
                (not N)
                (not M)
                L
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           E
           F
           H
           (not B)
           (not G)
           (not (<= 1 Z))
           (and (not P)
                (not O)
                (not N)
                (not M)
                L
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           E
           F
           (not B)
           (not H)
           (not G)
           (not (<= Z 1))
           (and (not P)
                (not O)
                (not N)
                (not M)
                L
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           E
           F
           G
           H
           (not B)
           (not (= G1 0))
           (and (not P)
                (not O)
                (not N)
                (not M)
                L
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           E
           H
           (not B)
           (not F)
           (not G)
           (<= 1 F1)
           (and (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           E
           F
           H
           (not B)
           (not G)
           (<= 1 Z)
           (and (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           E
           F
           (not B)
           (not H)
           (not G)
           (<= Z 1)
           (and (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           E
           H
           (not D)
           (not F)
           (not G)
           (= G1 0)
           (and (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A B F H (not C) (not D) (not E) (not G) a!13)
       (or A B D E G (not C) (not F) (not H) a!14)
       (or A B C G H (not D) (not E) (not F) a!15)
       (or A C E F H (not B) (not D) (not G) a!16)
       (or A B C E F H (not D) (not G) a!17)
       (or A B D F G H (not C) (not E) a!18)
       (or A B E F G (not C) (not D) (not H) a!19)
       (or A B D E (not C) (not F) (not H) (not G) a!20)
       (or A B C H (not D) (not E) (not F) (not G) a!21)
       (or A C E F G (not B) (not D) (not H) a!22)
       (or A B C E F G (not D) (not H) a!23)
       (or A D E F (not C) (not B) (not H) (not G) a!24)
       (or A D F (not C) (not B) (not E) (not H) (not G) a!25)
       (or A H (not C) (not B) (not D) (not E) (not F) (not G) a!26)
       (or A B E F H (not C) (not D) (not G) a!27)
       (or A C G H (not B) (not D) (not E) (not F) a!28)
       (or A C D E (not B) (not F) (not H) (not G) a!29)
       (or B C (not A) (not D) (not E) (not F) (not H) (not G) a!30)
       (or B C F (not A) (not D) (not E) (not H) (not G) a!1)
       (or B C H (not A) (not D) (not E) (not F) (not G) a!2)
       (or B C G (not A) (not D) (not E) (not F) (not H) a!3)
       (or B
           C
           F
           H
           (not A)
           (not D)
           (not E)
           (not G)
           (and P
                (not O)
                N
                M
                (not L)
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B C G H (not A) (not D) (not E) (not F) a!4)
       (or B
           C
           E
           (not A)
           (not D)
           (not F)
           (not H)
           (not G)
           (and P
                (not O)
                N
                M
                (not L)
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           E
           H
           (not A)
           (not D)
           (not F)
           (not G)
           (and P
                (not O)
                N
                (not M)
                (not L)
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           E
           F
           H
           (not A)
           (not D)
           (not G)
           (and P
                (not O)
                N
                (not M)
                (not L)
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           E
           F
           (not A)
           (not D)
           (not H)
           (not G)
           (and P
                (not O)
                N
                (not M)
                (not L)
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           D
           (not A)
           (not E)
           (not F)
           (not H)
           (not G)
           (and P
                (not O)
                N
                (not M)
                (not L)
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           D
           H
           (not A)
           (not E)
           (not F)
           (not G)
           (and P
                (not O)
                (not N)
                M
                (not L)
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           D
           F
           H
           (not A)
           (not E)
           (not G)
           (and P
                (not O)
                (not N)
                M
                (not L)
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           D
           F
           (not A)
           (not E)
           (not H)
           (not G)
           (and P
                (not O)
                (not N)
                M
                (not L)
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           D
           E
           (not A)
           (not F)
           (not H)
           (not G)
           (and P
                (not O)
                (not N)
                M
                (not L)
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or C D E (not A) (not B) (not F) (not H) (not G) a!5)
       (or C D E F (not A) (not B) (not H) (not G) a!6)
       (or C D E H (not A) (not B) (not F) (not G) a!7)
       (or C D E F H (not A) (not B) (not G) a!8)
       (or C D E G (not A) (not B) (not F) (not H) a!9)
       (or B
           C
           D
           E
           H
           (not A)
           (not F)
           (not G)
           (and P
                (not O)
                (not N)
                (not M)
                (not L)
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or C D E F G (not A) (not B) (not H) a!10)
       (or B
           C
           D
           E
           F
           H
           (not A)
           (not G)
           (and P
                (not O)
                (not N)
                (not M)
                (not L)
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or C D E G H (not A) (not B) (not F) a!11)
       (or B
           C
           D
           E
           F
           (not A)
           (not H)
           (not G)
           (and P
                (not O)
                (not N)
                (not M)
                (not L)
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or C D E F G H (not A) (not B) a!12)
       (or A
           D
           E
           H
           (not C)
           (not B)
           (not F)
           (not G)
           (and (not P)
                O
                N
                M
                L
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           F
           (not C)
           (not D)
           (not E)
           (not H)
           (not G)
           (and (not P)
                O
                N
                (not M)
                L
                K
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           (not C)
           (not B)
           (not D)
           (not E)
           (not F)
           (not H)
           (not G)
           (and (not P)
                O
                N
                (not M)
                (not L)
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           E
           G
           (not C)
           (not B)
           (not D)
           (not F)
           (not H)
           (and (not P)
                O
                (not N)
                M
                L
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           E
           F
           (not C)
           (not D)
           (not H)
           (not G)
           (and (not P)
                O
                (not N)
                M
                L
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           H
           (not C)
           (not B)
           (not E)
           (not F)
           (not G)
           (and (not P)
                O
                (not N)
                (not M)
                L
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           F
           H
           (not B)
           (not E)
           (not G)
           (and (not P)
                (not O)
                N
                M
                L
                K
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           F
           H
           (not C)
           (not E)
           (not G)
           (and (not P)
                (not O)
                N
                M
                (not L)
                K
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           G
           (not B)
           (not D)
           (not E)
           (not F)
           (not H)
           (and (not P)
                (not O)
                N
                (not M)
                (not L)
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           (not D)
           (not E)
           (not F)
           (not H)
           (not G)
           (and (not P)
                (not O)
                N
                (not M)
                (not L)
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           E
           G
           H
           (not B)
           (not D)
           (not F)
           (and (not P)
                (not O)
                (not N)
                M
                L
                (not K)
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           E
           G
           H
           (not D)
           (not F)
           (and (not P)
                (not O)
                (not N)
                M
                L
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A B C D E F G H a!31)
       (or A B C D G H (not E) (not F) a!31)
       (or A B C D G (not E) (not F) (not H) a!31)
       (or A B C E F G H (not D) a!31)
       (or A B C E (not D) (not F) (not H) (not G) a!31)
       (or A B C F H (not D) (not E) (not G) a!31)
       (or A B C F (not D) (not E) (not H) (not G) a!31)
       (or A B D E F H (not C) (not G) a!31)
       (or A B D E F (not C) (not H) (not G) a!31)
       (or A B D E H (not C) (not F) (not G) a!31)
       (or A B D G H (not C) (not E) (not F) a!31)
       (or A B D G (not C) (not E) (not F) (not H) a!31)
       (or A B E F G H (not C) (not D) a!31)
       (or A B E G (not C) (not D) (not F) (not H) a!31)
       (or A B F G H (not C) (not D) (not E) a!31)
       (or A B G (not C) (not D) (not E) (not F) (not H) a!31)
       (or A C D E F G (not B) (not H) a!31)
       (or A C D E G H (not B) (not F) a!31)
       (or A C D E G (not B) (not F) (not H) a!31)
       (or A C D G H (not B) (not E) (not F) a!31)
       (or A C D G (not B) (not E) (not F) (not H) a!31)
       (or A C E F G H (not B) (not D) a!31)
       (or A C E (not B) (not D) (not F) (not H) (not G) a!31)
       (or A C F H (not B) (not D) (not E) (not G) a!31)
       (or A C F (not B) (not D) (not E) (not H) (not G) a!31)
       (or A D E F G H (not C) (not B) a!31)
       (or A D E F G (not C) (not B) (not H) a!31)
       (or A D F G H (not C) (not B) (not E) a!31)
       (or A D F G (not C) (not B) (not E) (not H) a!31)
       (or A E F G H (not C) (not B) (not D) a!31)
       (or A E F G (not C) (not B) (not D) (not H) a!31)
       (or A E G H (not C) (not B) (not D) (not F) a!31)
       (or A F G H (not C) (not B) (not D) (not E) a!31)
       (or A F G (not C) (not B) (not D) (not E) (not H) a!31)
       (or A G H (not C) (not B) (not D) (not E) (not F) a!31)
       (or B C F G (not A) (not D) (not E) (not H) a!31)
       (or A
           B
           C
           D
           E
           F
           H
           (not G)
           (and (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                K
                (not J)
                (not I)
                (= Q 0)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           G
           H
           (not C)
           (not B)
           (not E)
           (not F)
           (and (not P)
                O
                (not N)
                M
                L
                (not K)
                J
                I
                (= S 3)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           E
           G
           H
           (not C)
           (not B)
           (not F)
           (and (not P)
                O
                (not N)
                (not M)
                L
                (not K)
                J
                I
                (= S 2)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           F
           G
           (not C)
           (not D)
           (not E)
           (not H)
           (and (not P)
                O
                N
                M
                L
                K
                (not J)
                (not I)
                (= S 1)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           E
           H
           (not C)
           (not B)
           (not D)
           (not F)
           (not G)
           (and (not P)
                O
                N
                (not M)
                (not L)
                K
                J
                I
                (= S 0)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           F
           G
           H
           (not E)
           (and (not P)
                (not O)
                (not N)
                M
                L
                (not K)
                (not J)
                (not I)
                (= S 0)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           E
           (not F)
           (not H)
           (not G)
           (and (not P)
                (not O)
                (not N)
                M
                (not L)
                (not K)
                (not J)
                (not I)
                (= U 0)
                (= R Q)
                (= T S)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           E
           F
           (not B)
           (not D)
           (not H)
           (not G)
           (and (not P)
                (not O)
                N
                (not M)
                (not L)
                (not K)
                J
                I
                (= W 1)
                (= R Q)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           H
           (not B)
           (not D)
           (not E)
           (not F)
           (not G)
           (and (not P)
                (not O)
                N
                M
                (not L)
                K
                J
                I
                (= W 0)
                (= R Q)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           E
           G
           (not F)
           (not H)
           (and (not P)
                (not O)
                (not N)
                (not M)
                L
                K
                J
                (not I)
                (= W 0)
                (= R Q)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           G
           (not D)
           (not E)
           (not F)
           (not H)
           (and (not P)
                (not O)
                N
                M
                L
                K
                J
                (not I)
                (= Y 1)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           F
           G
           H
           (not B)
           (not E)
           (and (not P)
                (not O)
                (not N)
                M
                L
                (not K)
                (not J)
                I
                (= Y 0)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           E
           H
           (not F)
           (not G)
           (and (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                K
                J
                (not I)
                (= Y 0)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           E
           F
           G
           (not H)
           (and (not P)
                (not O)
                (not N)
                (not M)
                L
                K
                (not J)
                (not I)
                (= A1 0)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           E
           F
           (not D)
           (not H)
           (not G)
           (and (not P)
                (not O)
                N
                (not M)
                (not L)
                (not K)
                J
                (not I)
                (= C1 1)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= F1 E1)))
       (or A
           G
           (not C)
           (not B)
           (not D)
           (not E)
           (not F)
           (not H)
           (and (not P)
                O
                N
                M
                L
                K
                J
                I
                (= C1 0)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= F1 E1)))
       (or A
           B
           C
           D
           E
           G
           H
           (not F)
           (and (not P)
                (not O)
                (not N)
                (not M)
                L
                (not K)
                J
                (not I)
                (= C1 0)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= F1 E1)))
       (or A
           B
           C
           D
           E
           F
           (not H)
           (not G)
           (and (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                (not K)
                J
                (not I)
                (= E1 0)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)))
       (or B C E F G H (not A) (not D) (<= 0 Z) a!30)))
      )
      (state K L J M N I O P Q S U W Y A1 C1 E1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) ) 
    (=>
      (and
        (state H G F E D B C A I J K L M N O P)
        (or (and A (not B) (not C) D E (not F) G H)
    (and A (not B) (not C) D E F (not G) (not H))
    (and A (not B) (not C) D E F (not G) H)
    (and A (not B) (not C) D E F G (not H))
    (and A (not B) (not C) D E F G H)
    (and A B (not C) (not D) (not E) (not F) (not G) (not H))
    (and A B (not C) (not D) (not E) (not F) (not G) H)
    (and A B (not C) (not D) (not E) (not F) G (not H))
    (and A B (not C) (not D) (not E) (not F) G H)
    (and A B (not C) (not D) (not E) F (not G) (not H))
    (and A B (not C) (not D) (not E) F (not G) H)
    (and A B (not C) (not D) (not E) F G (not H))
    (and A B (not C) (not D) (not E) F G H))
      )
      false
    )
  )
)

(check-sat)
(exit)
