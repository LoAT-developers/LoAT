; ./prepared/vmt/./ctigar/svd4.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (and (= G true) (not F) (not E) (not D) (not C) (not B) (not A) (not H))
      )
      (state H G F E D B A C I J K L M N)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (state H G F E D B A C R T V X Z B1)
        (let ((a!1 (and P
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
                (= B1 A1)))
      (a!2 (and P
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
                (= B1 A1)))
      (a!3 (and P
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
                (= B1 A1)))
      (a!4 (and P
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
                (= B1 A1)))
      (a!5 (and P
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
                (= B1 A1)))
      (a!6 (and P
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
                (= B1 A1)))
      (a!7 (and (not P)
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
                (= B1 A1)))
      (a!8 (and (not P)
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
                (= B1 A1)))
      (a!9 (and (not P)
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
                (= B1 A1)))
      (a!10 (and (not P)
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
                 (= B1 A1)))
      (a!11 (and (not P)
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
                 (= B1 A1)))
      (a!12 (and (not P)
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
                 (= B1 A1)))
      (a!13 (and (not P)
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
                 (= B1 A1)))
      (a!14 (and (not P)
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
                 (= B1 A1)))
      (a!15 (and (not P)
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
                 (= B1 A1)))
      (a!16 (and (not P)
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
                 (= B1 A1)))
      (a!17 (and (not P)
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
                 (= B1 A1)))
      (a!18 (and (not P)
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
                 (= B1 A1)))
      (a!19 (and (not P)
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
                 (= B1 A1)))
      (a!20 (and (not P)
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
                 (= B1 A1)))
      (a!21 (and (not P)
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
                 (= B1 A1)))
      (a!22 (and (not P)
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
                 (= B1 A1)))
      (a!23 (and (not P)
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
                 (= B1 A1)))
      (a!24 (and (not P)
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
                 (= B1 A1)))
      (a!25 (and (not P)
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
                 (= B1 A1)))
      (a!26 (and (not P)
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
                 (= B1 A1)))
      (a!27 (and (not P)
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
                 (= B1 A1)))
      (a!28 (and (not P)
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
                 (= B1 A1)))
      (a!29 (and (not P)
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
                 (= B1 A1)))
      (a!30 (and (not P)
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
                 (= B1 A1)))
      (a!31 (and (not P)
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
                 (= B1 A1)))
      (a!32 (and (not P)
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
                 (= B1 A1)))
      (a!33 (and (not P)
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
                 (= B1 A1)))
      (a!34 (and (not P)
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
                 (= B1 A1)))
      (a!35 (and (not P)
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
                 (= B1 A1)))
      (a!36 (and (not P)
                 O
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
                 (= (+ R (* (- 1) Q)) 1)))
      (a!37 (and P
                 (not O)
                 (not N)
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 I
                 (= R Q)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ T (* (- 1) S)) (- 1))))
      (a!38 (and (not P)
                 O
                 N
                 (not M)
                 (not L)
                 (not K)
                 J
                 I
                 (= R Q)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ T (* (- 1) S)) (- 1))))
      (a!39 (and (not P)
                 O
                 (not N)
                 M
                 (not L)
                 (not K)
                 J
                 I
                 (= R Q)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ T (* (- 1) S)) (- 1))))
      (a!40 (and (not P)
                 (not O)
                 (not N)
                 M
                 (not L)
                 K
                 J
                 (not I)
                 (= R Q)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ T (* (- 1) S)) (- 1))))
      (a!41 (and (not P)
                 O
                 (not N)
                 (not M)
                 L
                 (not K)
                 J
                 I
                 (= R Q)
                 (= T S)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ V (* (- 1) U)) (- 1))))
      (a!42 (and (not P)
                 (not O)
                 N
                 (not M)
                 L
                 K
                 (not J)
                 I
                 (= R Q)
                 (= T S)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ V (* (- 1) U)) (- 1))))
      (a!43 (and (not P)
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
                 (= Z Y)
                 (= B1 A1)
                 (= (+ R (* (- 1) W)) (- 1))))
      (a!44 (and (not P)
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
                 (= B1 A1)))
      (a!45 (and (not P)
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
                 (= B1 A1))))
  (and (or A
           B
           C
           D
           E
           H
           (not F)
           (not G)
           (<= 1 R)
           (and P
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
                (= B1 A1)))
       (or A B C D E (not F) (not H) (not G) (<= 1 R) a!1)
       (or A B C D F H (not E) (not G) (<= R Z) a!2)
       (or C
           E
           (not A)
           (not B)
           (not D)
           (not F)
           (not H)
           (not G)
           (<= T B1)
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
                (= B1 A1)))
       (or C F G H (not A) (not B) (not D) (not E) (<= 1 T) a!3)
       (or C F G (not A) (not B) (not D) (not E) (not H) (<= T B1) a!4)
       (or C G H (not A) (not B) (not D) (not E) (not F) (<= 1 R) a!5)
       (or C G (not A) (not B) (not D) (not E) (not F) (not H) (<= R Z) a!6)
       (or C
           G
           (not A)
           (not B)
           (not D)
           (not E)
           (not F)
           (not H)
           (not (<= R Z))
           (and (not P)
                O
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
                (= B1 A1)))
       (or C
           G
           H
           (not A)
           (not B)
           (not D)
           (not E)
           (not F)
           (not (<= 1 R))
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
                (= B1 A1)))
       (or C
           F
           G
           (not A)
           (not B)
           (not D)
           (not E)
           (not H)
           (not (<= T B1))
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
                (= B1 A1)))
       (or C
           F
           G
           H
           (not A)
           (not B)
           (not D)
           (not E)
           (not (<= 1 T))
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
                (= B1 A1)))
       (or C
           E
           (not A)
           (not B)
           (not D)
           (not F)
           (not H)
           (not G)
           (not (<= T B1))
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
                (= B1 A1)))
       (or A
           B
           C
           F
           (not D)
           (not E)
           (not H)
           (not G)
           (= C1 0)
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
                (= B1 A1)))
       (or C D F G H (not A) (not B) (not E) (<= 1 R) a!7)
       (or C D F G (not A) (not B) (not E) (not H) (<= R B1) a!8)
       (or C D G H (not A) (not B) (not E) (not F) (<= 1 R) a!9)
       (or C D G (not A) (not B) (not E) (not F) (not H) (<= R Z) a!10)
       (or C
           D
           G
           (not A)
           (not B)
           (not E)
           (not F)
           (not H)
           (not (<= R Z))
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
                (= B1 A1)))
       (or C
           D
           G
           H
           (not A)
           (not B)
           (not E)
           (not F)
           (not (<= 1 R))
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
                (= B1 A1)))
       (or C
           D
           F
           G
           (not A)
           (not B)
           (not E)
           (not H)
           (not (<= R B1))
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
                (= B1 A1)))
       (or C
           D
           F
           G
           H
           (not A)
           (not B)
           (not E)
           (not (<= 1 R))
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
                (= B1 A1)))
       (or B C F H (not A) (not D) (not E) (not G) (<= T B1) a!11)
       (or B C F G (not A) (not D) (not E) (not H) (<= 1 T) a!12)
       (or B C G H (not A) (not D) (not E) (not F) (<= T B1) a!13)
       (or B C G (not A) (not D) (not E) (not F) (not H) (<= 1 R) a!14)
       (or C D E F G H (not A) (not B) (<= R Z) a!15)
       (or C
           D
           E
           F
           G
           H
           (not A)
           (not B)
           (not (<= R Z))
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
                (= B1 A1)))
       (or B
           C
           G
           (not A)
           (not D)
           (not E)
           (not F)
           (not H)
           (not (<= 1 R))
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
                (= B1 A1)))
       (or B
           C
           G
           H
           (not A)
           (not D)
           (not E)
           (not F)
           (not (<= T B1))
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
                (= B1 A1)))
       (or B
           C
           F
           G
           (not A)
           (not D)
           (not E)
           (not H)
           (not (<= 1 T))
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
                (= B1 A1)))
       (or B
           C
           F
           H
           (not A)
           (not D)
           (not E)
           (not G)
           (not (<= T B1))
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
                (= B1 A1)))
       (or A
           B
           C
           H
           (not D)
           (not E)
           (not F)
           (not G)
           (<= T Z)
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
                (= B1 A1)))
       (or A C E G H (not B) (not D) (not F) (<= 1 R) a!16)
       (or A C E G (not B) (not D) (not F) (not H) (<= R B1) a!17)
       (or A C F G H (not B) (not D) (not E) (<= 1 R) a!18)
       (or A C F G (not B) (not D) (not E) (not H) (<= R Z) a!19)
       (or A
           C
           H
           (not B)
           (not D)
           (not E)
           (not F)
           (not G)
           (<= V B1)
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
                (= B1 A1)))
       (or A C G (not B) (not D) (not E) (not F) (not H) (<= 1 V) a!20)
       (or B C D E F G H (not A) (<= V B1) a!21)
       (or B C D E F G (not A) (not H) (<= 1 T) a!22)
       (or B C D E G H (not A) (not F) (<= T Z) a!23)
       (or B C D E G (not A) (not F) (not H) (<= 1 R) a!24)
       (or B C D F G H (not A) (not E) (<= R Z) a!25)
       (or B
           C
           D
           F
           G
           H
           (not A)
           (not E)
           (not (<= R Z))
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
                (= B1 A1)))
       (or B
           C
           D
           E
           G
           (not A)
           (not F)
           (not H)
           (not (<= 1 R))
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
                (= B1 A1)))
       (or B
           C
           D
           E
           G
           H
           (not A)
           (not F)
           (not (<= T Z))
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
                (= B1 A1)))
       (or B
           C
           D
           E
           F
           G
           (not A)
           (not H)
           (not (<= 1 T))
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
                (= B1 A1)))
       (or B
           C
           D
           E
           F
           G
           H
           (not A)
           (not (<= V B1))
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
                (= B1 A1)))
       (or A
           C
           G
           (not B)
           (not D)
           (not E)
           (not F)
           (not H)
           (not (<= 1 V))
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
                (= B1 A1)))
       (or A
           C
           H
           (not B)
           (not D)
           (not E)
           (not F)
           (not G)
           (not (<= V B1))
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
                (= B1 A1)))
       (or A
           C
           F
           G
           (not B)
           (not D)
           (not E)
           (not H)
           (not (<= R Z))
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
                (= B1 A1)))
       (or A
           C
           F
           G
           H
           (not B)
           (not D)
           (not E)
           (not (<= 1 R))
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
                (= B1 A1)))
       (or A
           C
           E
           G
           (not B)
           (not D)
           (not F)
           (not H)
           (not (<= R B1))
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
                (= B1 A1)))
       (or A
           C
           E
           G
           H
           (not B)
           (not D)
           (not F)
           (not (<= 1 R))
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
                (= B1 A1)))
       (or A
           B
           C
           (not D)
           (not E)
           (not F)
           (not H)
           (not G)
           (<= V B1)
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
                (= B1 A1)))
       (or A C D E F G H (not B) (<= 1 V) a!26)
       (or A C D E F G (not B) (not H) (<= V B1) a!27)
       (or A C D E G H (not B) (not F) (<= 1 R) a!28)
       (or A C D E G (not B) (not F) (not H) (<= R Z) a!29)
       (or A C D F G H (not B) (not E) (<= 1 T) a!30)
       (or A C D F G (not B) (not E) (not H) (<= T Z) a!31)
       (or A
           C
           D
           F
           G
           (not B)
           (not E)
           (not H)
           (not (<= T Z))
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
                (= B1 A1)))
       (or A
           C
           D
           F
           G
           H
           (not B)
           (not E)
           (not (<= 1 T))
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
                (= B1 A1)))
       (or A
           C
           D
           E
           G
           (not B)
           (not F)
           (not H)
           (not (<= R Z))
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
                (= B1 A1)))
       (or A
           C
           D
           E
           G
           H
           (not B)
           (not F)
           (not (<= 1 R))
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
                (= B1 A1)))
       (or A
           C
           D
           E
           F
           G
           (not B)
           (not H)
           (not (<= V B1))
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
                (= B1 A1)))
       (or A
           C
           D
           E
           F
           G
           H
           (not B)
           (not (<= 1 V))
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
                (= B1 A1)))
       (or A
           B
           C
           (not D)
           (not E)
           (not F)
           (not H)
           (not G)
           (not (<= V B1))
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
                (= B1 A1)))
       (or A
           B
           C
           H
           (not D)
           (not E)
           (not F)
           (not G)
           (not (<= T Z))
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
                (= B1 A1)))
       (or A
           B
           C
           F
           (not D)
           (not E)
           (not H)
           (not G)
           (not (= C1 0))
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
                (= B1 A1)))
       (or A
           B
           C
           D
           G
           H
           (not E)
           (not F)
           (<= T Z)
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
                (= B1 A1)))
       (or A B C D H (not E) (not F) (not G) (<= 1 R) a!32)
       (or A B C D (not E) (not F) (not H) (not G) (<= R B1) a!33)
       (or A B C E F H (not D) (not G) (<= 1 T) a!34)
       (or A B C E F (not D) (not H) (not G) (<= T Z) a!35)
       (or A
           B
           C
           E
           F
           (not D)
           (not H)
           (not G)
           (not (<= T Z))
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
                (= B1 A1)))
       (or A
           B
           C
           E
           F
           H
           (not D)
           (not G)
           (not (<= 1 T))
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
                (= B1 A1)))
       (or A
           B
           C
           D
           (not E)
           (not F)
           (not H)
           (not G)
           (not (<= R B1))
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
                (= B1 A1)))
       (or A
           B
           C
           D
           H
           (not E)
           (not F)
           (not G)
           (not (<= 1 R))
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
                (= B1 A1)))
       (or A
           B
           C
           D
           G
           H
           (not E)
           (not F)
           (not (<= T Z))
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
                (= B1 A1)))
       (or A
           B
           C
           D
           F
           H
           (not E)
           (not G)
           (not (<= R Z))
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
                (= B1 A1)))
       (or A
           B
           C
           D
           E
           (not F)
           (not H)
           (not G)
           (not (<= 1 R))
           (and (not P)
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
                (= B1 A1)))
       (or A
           B
           C
           D
           E
           H
           (not F)
           (not G)
           (not (<= 1 R))
           (and (not P)
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
                (= B1 A1)))
       (or A
           B
           C
           D
           E
           F
           (not H)
           (not G)
           (not (<= B1 Z))
           (and (not P)
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
                (= B1 A1)))
       (or A
           B
           C
           D
           E
           F
           H
           (not G)
           (<= Z B1)
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
                (= B1 A1)))
       (or A
           B
           C
           D
           E
           F
           H
           (not G)
           (not (<= Z B1))
           (and (not P)
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
                (= B1 A1)))
       (or C E F G H (not A) (not B) (not D) a!36)
       (or A B D E F G H (not C) a!37)
       (or C D E F G (not A) (not B) (not H) a!38)
       (or B C E F G (not A) (not D) (not H) a!39)
       (or A B C E H (not D) (not F) (not G) a!40)
       (or B C D F G (not A) (not E) (not H) a!41)
       (or A C D G H (not B) (not E) (not F) a!42)
       (or A B C D E G (not F) (not H) a!43)
       (or A B D F G H (not C) (not E) a!1)
       (or A B D E (not C) (not F) (not H) (not G) a!2)
       (or A B D E H (not C) (not F) (not G) a!3)
       (or A B D E G H (not C) (not F) a!4)
       (or A B D E F (not C) (not H) (not G) a!5)
       (or A B D E F G (not C) (not H) a!6)
       (or C
           (not A)
           (not B)
           (not D)
           (not E)
           (not F)
           (not H)
           (not G)
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
                (= B1 A1)))
       (or C
           H
           (not A)
           (not B)
           (not D)
           (not E)
           (not F)
           (not G)
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
                (= B1 A1)))
       (or C
           F
           (not A)
           (not B)
           (not D)
           (not E)
           (not H)
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
                (= B1 A1)))
       (or C
           F
           H
           (not A)
           (not B)
           (not D)
           (not E)
           (not G)
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
                (= B1 A1)))
       (or A
           B
           D
           E
           F
           H
           (not C)
           (not G)
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
                (= B1 A1)))
       (or C E H (not A) (not B) (not D) (not F) (not G) a!7)
       (or C E G H (not A) (not B) (not D) (not F) a!8)
       (or C E F (not A) (not B) (not D) (not H) (not G) a!9)
       (or C E F G (not A) (not B) (not D) (not H) a!10)
       (or C
           D
           (not A)
           (not B)
           (not E)
           (not F)
           (not H)
           (not G)
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
                (= B1 A1)))
       (or C
           D
           H
           (not A)
           (not B)
           (not E)
           (not F)
           (not G)
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
                (= B1 A1)))
       (or C
           D
           F
           (not A)
           (not B)
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
                (= B1 A1)))
       (or C
           D
           F
           H
           (not A)
           (not B)
           (not E)
           (not G)
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
                (= B1 A1)))
       (or A B D E G (not C) (not F) (not H) a!11)
       (or C D E (not A) (not B) (not F) (not H) (not G) a!12)
       (or C D E G (not A) (not B) (not F) (not H) a!13)
       (or C D E H (not A) (not B) (not F) (not G) a!14)
       (or C D E G H (not A) (not B) (not F) a!15)
       (or C
           D
           E
           F
           H
           (not A)
           (not B)
           (not G)
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
                (= B1 A1)))
       (or B
           C
           (not A)
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
                (not K)
                (not J)
                (not I)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or B
           C
           H
           (not A)
           (not D)
           (not E)
           (not F)
           (not G)
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
                (= B1 A1)))
       (or B
           C
           F
           (not A)
           (not D)
           (not E)
           (not H)
           (not G)
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
                (= B1 A1)))
       (or C
           D
           E
           F
           (not A)
           (not B)
           (not H)
           (not G)
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
                (= B1 A1)))
       (or B C E (not A) (not D) (not F) (not H) (not G) a!16)
       (or B C E G (not A) (not D) (not F) (not H) a!17)
       (or B C E H (not A) (not D) (not F) (not G) a!18)
       (or B C E G H (not A) (not D) (not F) a!19)
       (or B C E F H (not A) (not D) (not G) a!20)
       (or B C E F G H (not A) (not D) a!21)
       (or B C D (not A) (not E) (not F) (not H) (not G) a!22)
       (or B C D G (not A) (not E) (not F) (not H) a!23)
       (or B C D H (not A) (not E) (not F) (not G) a!24)
       (or B C D G H (not A) (not E) (not F) a!25)
       (or B
           C
           D
           F
           H
           (not A)
           (not E)
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
                (= B1 A1)))
       (or B
           C
           D
           E
           (not A)
           (not F)
           (not H)
           (not G)
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
                (= B1 A1)))
       (or B
           C
           D
           E
           H
           (not A)
           (not F)
           (not G)
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
                (= B1 A1)))
       (or B
           C
           D
           E
           F
           (not A)
           (not H)
           (not G)
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
                (= B1 A1)))
       (or B
           C
           D
           E
           F
           H
           (not A)
           (not G)
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
                (= B1 A1)))
       (or A
           C
           (not B)
           (not D)
           (not E)
           (not F)
           (not H)
           (not G)
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
                (= B1 A1)))
       (or B
           C
           D
           F
           (not A)
           (not E)
           (not H)
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
                (= B1 A1)))
       (or A
           C
           F
           (not B)
           (not D)
           (not E)
           (not H)
           (not G)
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
                (= B1 A1)))
       (or A
           C
           F
           H
           (not B)
           (not D)
           (not E)
           (not G)
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
                (= B1 A1)))
       (or A
           C
           E
           (not B)
           (not D)
           (not F)
           (not H)
           (not G)
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
                (= B1 A1)))
       (or A
           C
           E
           H
           (not B)
           (not D)
           (not F)
           (not G)
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
                (= B1 A1)))
       (or A C E F (not B) (not D) (not H) (not G) a!26)
       (or A C E F G (not B) (not D) (not H) a!27)
       (or A C E F H (not B) (not D) (not G) a!28)
       (or A C E F G H (not B) (not D) a!29)
       (or A C D (not B) (not E) (not F) (not H) (not G) a!30)
       (or A C D G (not B) (not E) (not F) (not H) a!31)
       (or A
           C
           D
           F
           (not B)
           (not E)
           (not H)
           (not G)
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
                (= B1 A1)))
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
                (= B1 A1)))
       (or A
           C
           D
           E
           (not B)
           (not F)
           (not H)
           (not G)
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
                (= B1 A1)))
       (or A
           C
           D
           E
           H
           (not B)
           (not F)
           (not G)
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
                (= B1 A1)))
       (or A
           C
           D
           E
           F
           (not B)
           (not H)
           (not G)
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
                (= B1 A1)))
       (or A
           C
           D
           E
           F
           H
           (not B)
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
                (= B1 A1)))
       (or A
           C
           D
           H
           (not B)
           (not E)
           (not F)
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
                (= B1 A1)))
       (or B
           C
           E
           F
           (not A)
           (not D)
           (not H)
           (not G)
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
                (= B1 A1)))
       (or A B C F G (not D) (not E) (not H) a!32)
       (or A B C F H (not D) (not E) (not G) a!33)
       (or A B C F G H (not D) (not E) a!34)
       (or A B C E (not D) (not F) (not H) (not G) a!35)
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
                (not L)
                K
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           C
           E
           F
           G
           (not D)
           (not H)
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
                (= B1 A1)))
       (or A
           B
           C
           E
           F
           G
           H
           (not D)
           (and (not P)
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
                (= B1 A1)))
       (or A
           B
           C
           D
           G
           (not E)
           (not F)
           (not H)
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
                (= B1 A1)))
       (or A
           B
           C
           E
           G
           (not D)
           (not F)
           (not H)
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
                (= B1 A1)))
       (or A
           B
           C
           D
           F
           G
           (not E)
           (not H)
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
                (= B1 A1)))
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
                (not J)
                I
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A B D F (not C) (not E) (not H) (not G) a!44)
       (or C E F H (not A) (not B) (not D) (not G) a!44)
       (or A B C D E F G H a!45)
       (or A B C D E F G (not H) a!45)
       (or A B D F H (not C) (not E) (not G) a!45)
       (or C
           E
           G
           (not A)
           (not B)
           (not D)
           (not F)
           (not H)
           (and (not P)
                O
                N
                M
                (not L)
                K
                J
                I
                (= R S)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or B
           C
           F
           G
           H
           (not A)
           (not D)
           (not E)
           (and (not P)
                O
                (not N)
                M
                L
                (not K)
                (not J)
                I
                (= R S)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           C
           G
           H
           (not B)
           (not D)
           (not E)
           (not F)
           (and (not P)
                (not O)
                N
                M
                L
                K
                (not J)
                I
                (= R U)
                (= R Q)
                (= T S)
                (= X W)
                (= Z Y)
                (= B1 A1)))
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
                (not J)
                I
                (= Q B1)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           D
           F
           G
           (not C)
           (not E)
           (not H)
           (and P
                (not O)
                (not N)
                (not M)
                L
                (not K)
                J
                I
                (= Q Z)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           C
           G
           H
           (not D)
           (not E)
           (not F)
           (and (not P)
                (not O)
                (not N)
                M
                L
                K
                (not J)
                I
                (= S X)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           C
           D
           F
           (not E)
           (not H)
           (not G)
           (and (not P)
                (not O)
                (not N)
                (not M)
                L
                K
                (not J)
                (not I)
                (= S X)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
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
                (= U X)
                (= R Q)
                (= T S)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           C
           D
           E
           F
           (not H)
           (not G)
           (<= B1 Z)
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
                (= B1 A1)))))
      )
      (state J I K L M N O P Q S U W Y A1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (state H G F E D B A C I J K L M N)
        (or (and (not A) (not B) (not C) D (not E) F G H)
    (and (not A) (not B) (not C) D E (not F) (not G) (not H))
    (and (not A) (not B) (not C) D E (not F) (not G) H)
    (and (not A) (not B) (not C) D E (not F) G (not H))
    (and (not A) (not B) C (not D) (not E) (not F) (not G) H)
    (and (not A) (not B) C (not D) (not E) (not F) G H)
    (and (not A) (not B) C (not D) (not E) F (not G) (not H))
    (and (not A) (not B) C (not D) (not E) F G (not H))
    (and (not A) (not B) C (not D) (not E) F G H)
    (and (not A) (not B) C (not D) E (not F) (not G) (not H))
    (and (not A) B (not C) (not D) E F (not G) H)
    (and (not A) B (not C) (not D) E F G H)
    (and (not A) B (not C) D (not E) (not F) (not G) (not H))
    (and (not A) B (not C) D (not E) (not F) (not G) H)
    (and (not A) B (not C) D (not E) (not F) G (not H))
    (and (not A) B (not C) D (not E) (not F) G H)
    (and A (not B) (not C) (not D) E F (not G) (not H))
    (and A (not B) (not C) (not D) E F (not G) H)
    (and A (not B) (not C) (not D) E F G (not H))
    (and A (not B) (not C) (not D) E F G H)
    (and A (not B) (not C) D (not E) (not F) (not G) (not H))
    (and A (not B) (not C) D (not E) (not F) G (not H))
    (and A (not B) (not C) D (not E) F (not G) (not H))
    (and A (not B) (not C) D (not E) F (not G) H)
    (and A (not B) (not C) D (not E) F G (not H))
    (and A (not B) (not C) D (not E) F G H)
    (and A B (not C) (not D) (not E) F (not G) (not H))
    (and A B (not C) (not D) (not E) F (not G) H)
    (and A B (not C) (not D) (not E) F G (not H))
    (and A B (not C) (not D) (not E) F G H)
    (and A B (not C) D (not E) (not F) (not G) H)
    (and A B (not C) D (not E) (not F) G H)
    (and A B (not C) D (not E) F (not G) (not H))
    (and A B (not C) D (not E) F G (not H)))
      )
      false
    )
  )
)

(check-sat)
(exit)
