; ./prepared/vmt/./ctigar/barbrprime.c_000.smt2
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
      (a!2 (and (not P)
                O
                (not N)
                M
                L
                (not K)
                (not J)
                I
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= (+ R (* (- 1) Q)) (- 1))))
      (a!3 (and (not P)
                O
                (not N)
                (not M)
                (not L)
                K
                J
                I
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= (+ R (* (- 1) Q)) 1)))
      (a!4 (and (not P)
                (not O)
                N
                M
                (not L)
                (not K)
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
      (a!5 (and (not P)
                (not O)
                (not N)
                M
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
      (a!6 (and (not P)
                (not O)
                (not N)
                M
                (not L)
                (not K)
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
      (a!7 (and (not P)
                O
                (not N)
                (not M)
                L
                (not K)
                J
                (not I)
                (= R Q)
                (= T S)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= (+ V (* (- 1) U)) (- 1))))
      (a!8 (and (not P)
                O
                (not N)
                M
                (not L)
                (not K)
                J
                I
                (= R Q)
                (= T S)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= (+ V (* (- 1) U)) 1)))
      (a!9 (and (not P)
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
                (= D1 C1)
                (= F1 E1)
                (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!10 (and (not P)
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
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!11 (and (not P)
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
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!12 (and (not P)
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
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!13 (and (not P)
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
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ B1 (* (- 1) A1)) 1)))
      (a!14 (and (not P)
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
                 (= (+ F1 (* (- 1) E1)) (- 1))))
      (a!15 (and (not P)
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
                 (= (+ F1 (* (- 1) E1)) 1)))
      (a!16 (and (not P)
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
                 (= (+ F1 (* (- 1) E1)) 1)))
      (a!17 (and (not P)
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
                 (= (+ F1 (* (- 1) E1)) 1)))
      (a!18 (and (not P)
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
                 (= (+ F1 (* (- 1) E1)) 1)))
      (a!19 (and P
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
      (a!20 (and (not P)
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
  (and (or B C D E F G H (not A) (<= T 3) a!1)
       (or B
           C
           D
           E
           F
           G
           (not A)
           (not H)
           (not (<= F1 T))
           (and P
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
       (or B
           C
           D
           E
           F
           G
           H
           (not A)
           (not (<= T 3))
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
           (not (= G1 0))
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
           F
           H
           (not C)
           (not B)
           (not E)
           (not G)
           (<= T 2)
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
           G
           H
           (not C)
           (not D)
           (not E)
           (not F)
           (= G1 0)
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
           (not C)
           (not D)
           (not E)
           (not F)
           (not H)
           (not G)
           (not (<= T 1))
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
           E
           F
           H
           (not C)
           (not B)
           (not G)
           (<= 1 B1)
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
           (not C)
           (not D)
           (not E)
           (not F)
           (not H)
           (not G)
           (<= T 1)
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
           G
           H
           (not C)
           (not D)
           (not E)
           (not F)
           (not (= G1 0))
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
           E
           G
           H
           (not C)
           (not D)
           (not F)
           (= G1 0)
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
           E
           (not C)
           (not D)
           (not F)
           (not H)
           (not G)
           (not (<= T 0))
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
           E
           G
           H
           (not C)
           (not D)
           (not F)
           (not (= G1 0))
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
           D
           F
           G
           (not C)
           (not E)
           (not H)
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
           (not C)
           (not E)
           (not F)
           (not H)
           (not G)
           (not (<= 1 F1))
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
           F
           (not C)
           (not E)
           (not H)
           (not G)
           (<= 1 V)
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
           F
           G
           (not C)
           (not E)
           (not H)
           (not (= G1 0))
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
           G
           H
           (not C)
           (not F)
           (<= 1 R)
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
           (not (<= V 0))
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
           (<= V 0)
           (and (not P)
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
           (not (<= 1 F1))
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
           G
           (not B)
           (not D)
           (not F)
           (not H)
           (<= 1 X)
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
           (not B)
           (not E)
           (not F)
           (not H)
           (not G)
           (<= 1 R)
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
           D
           H
           (not B)
           (not E)
           (not F)
           (not G)
           (not (<= X 0))
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
           H
           (not B)
           (not E)
           (not F)
           (not G)
           (<= X 0)
           (and (not P)
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
           E
           H
           (not B)
           (not F)
           (not G)
           (<= 1 F1)
           (and (not P)
                (not O)
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
           D
           E
           F
           H
           (not B)
           (not G)
           (<= 1 Z)
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
           E
           H
           (not D)
           (not F)
           (not G)
           (= G1 0)
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
           C
           F
           G
           (not D)
           (not E)
           (not H)
           (<= 1 R)
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
           F
           G
           H
           (not D)
           (not E)
           (<= Z 0)
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
           (not D)
           (not F)
           (not H)
           (not (<= 0 Z))
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
           F
           G
           (not E)
           (not H)
           (= G1 0)
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
           (not E)
           (not F)
           (not H)
           (not G)
           (not (<= 1 R))
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
           D
           F
           (not E)
           (not H)
           (not G)
           (not (<= 0 D1))
           (and (not P)
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
           H
           (not E)
           (not G)
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
       (or A B F H (not C) (not D) (not E) (not G) a!2)
       (or A B D E G (not C) (not F) (not H) a!3)
       (or A C E F H (not B) (not D) (not G) a!4)
       (or A B C G H (not D) (not E) (not F) a!5)
       (or A B C E F H (not D) (not G) a!6)
       (or A B D F G H (not C) (not E) a!7)
       (or A B E F G (not C) (not D) (not H) a!8)
       (or A B D E (not C) (not F) (not H) (not G) a!9)
       (or A C E F G (not B) (not D) (not H) a!10)
       (or A B C H (not D) (not E) (not F) (not G) a!11)
       (or A B C E F G (not D) (not H) a!12)
       (or A D E F (not C) (not B) (not H) (not G) a!13)
       (or A D F (not C) (not B) (not E) (not H) (not G) a!14)
       (or A H (not C) (not B) (not D) (not E) (not F) (not G) a!15)
       (or A B E F H (not C) (not D) (not G) a!16)
       (or A C G H (not B) (not D) (not E) (not F) a!17)
       (or A C D E (not B) (not F) (not H) (not G) a!18)
       (or B C D E H (not A) (not F) (not G) a!19)
       (or B C D E G (not A) (not F) (not H) a!1)
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
           E
           G
           (not C)
           (not B)
           (not D)
           (not F)
           (not H)
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
           D
           H
           (not C)
           (not B)
           (not E)
           (not F)
           (not G)
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
           D
           E
           H
           (not C)
           (not B)
           (not F)
           (not G)
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
           F
           (not C)
           (not D)
           (not E)
           (not H)
           (not G)
           (and (not P)
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
           G
           (not B)
           (not D)
           (not E)
           (not F)
           (not H)
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
           E
           G
           H
           (not B)
           (not D)
           (not F)
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
           F
           H
           (not B)
           (not E)
           (not G)
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
           (not D)
           (not E)
           (not F)
           (not H)
           (not G)
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
       (or A B C D E F G H a!20)
       (or A B C D G H (not E) (not F) a!20)
       (or A B C D G (not E) (not F) (not H) a!20)
       (or A B C E F G H (not D) a!20)
       (or A B C E (not D) (not F) (not H) (not G) a!20)
       (or A B C F H (not D) (not E) (not G) a!20)
       (or A B C F (not D) (not E) (not H) (not G) a!20)
       (or A B D E F H (not C) (not G) a!20)
       (or A B D E F (not C) (not H) (not G) a!20)
       (or A B D E H (not C) (not F) (not G) a!20)
       (or A B D G H (not C) (not E) (not F) a!20)
       (or A B D G (not C) (not E) (not F) (not H) a!20)
       (or A B E F G H (not C) (not D) a!20)
       (or A B E G (not C) (not D) (not F) (not H) a!20)
       (or A B F G H (not C) (not D) (not E) a!20)
       (or A B G (not C) (not D) (not E) (not F) (not H) a!20)
       (or A C D E F G (not B) (not H) a!20)
       (or A C D E G H (not B) (not F) a!20)
       (or A C D E G (not B) (not F) (not H) a!20)
       (or A C D G H (not B) (not E) (not F) a!20)
       (or A C D G (not B) (not E) (not F) (not H) a!20)
       (or A C E F G H (not B) (not D) a!20)
       (or A C E (not B) (not D) (not F) (not H) (not G) a!20)
       (or A C F H (not B) (not D) (not E) (not G) a!20)
       (or A C F (not B) (not D) (not E) (not H) (not G) a!20)
       (or A D E F G H (not C) (not B) a!20)
       (or A D E F G (not C) (not B) (not H) a!20)
       (or A D F G H (not C) (not B) (not E) a!20)
       (or A D F G (not C) (not B) (not E) (not H) a!20)
       (or A E F G H (not C) (not B) (not D) a!20)
       (or A E F G (not C) (not B) (not D) (not H) a!20)
       (or A E G H (not C) (not B) (not D) (not F) a!20)
       (or A F G H (not C) (not B) (not D) (not E) a!20)
       (or A F G (not C) (not B) (not D) (not E) (not H) a!20)
       (or A G H (not C) (not B) (not D) (not E) (not F) a!20)
       (or B C D E G H (not A) (not F) a!20)
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
                (not K)
                (not J)
                I
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
                N
                (not M)
                L
                K
                J
                (not I)
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
                N
                (not M)
                (not L)
                K
                J
                (not I)
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
                (not N)
                M
                L
                (not K)
                J
                I
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
                M
                (not L)
                K
                (not J)
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
                (not M)
                L
                (not K)
                J
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
                (not M)
                L
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
                M
                (not L)
                K
                (not J)
                (not I)
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
                L
                K
                (not J)
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
           G
           (not D)
           (not E)
           (not F)
           (not H)
           (and (not P)
                (not O)
                (not N)
                M
                L
                K
                J
                I
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
                N
                (not M)
                L
                (not K)
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
           H
           (not F)
           (not G)
           (and (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                K
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
           F
           G
           (not H)
           (and (not P)
                (not O)
                (not N)
                (not M)
                (not L)
                (not K)
                J
                I
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
                (not N)
                M
                (not L)
                K
                (not J)
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
                (not L)
                K
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
                K
                (not J)
                (not I)
                (= E1 0)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)))
       (or B C D E F G (not A) (not H) (<= F1 T) a!19)))
      )
      (state I J K L M N O P Q S U W Y A1 C1 E1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) ) 
    (=>
      (and
        (state H G F E D B C A I J K L M N O P)
        (and (= F true) (not E) (not D) (not C) (not B) (= A true) (not (= H G)))
      )
      false
    )
  )
)

(check-sat)
(exit)
