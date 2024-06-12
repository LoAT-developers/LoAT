; ./prepared/vmt/./ctigar/cars.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (and (= F true) (not E) (not D) (not C) (not B) (not A) (not G))
      )
      (state G F E D C B A H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (state G F E D C B A P R T V X Z B1)
        (let ((a!1 (and N
                M
                L
                K
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
      (a!2 (and N
                M
                L
                K
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
      (a!3 (and N
                M
                L
                K
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
      (a!5 (<= 0 (+ P R (* (- 2) V) (* 2 Z))))
      (a!6 (and N
                M
                L
                (not K)
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
      (a!7 (and N
                M
                L
                (not K)
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
      (a!8 (not (<= 75 (+ X (* 5 Z)))))
      (a!9 (not (<= (+ X (* (- 5) Z)) 75)))
      (a!10 (<= (+ P R (* (- 2) V) (* (- 2) Z)) 0))
      (a!11 (not (<= 0 (+ T (* (- 2) X) B1))))
      (a!12 (or A
                B
                (not C)
                (not D)
                (not E)
                (not G)
                (not F)
                (<= 0 (+ T (* (- 2) X) B1))
                (and N
                     (not M)
                     (not L)
                     (not K)
                     (not J)
                     (not I)
                     (not H)
                     (= P O)
                     (= R Q)
                     (= T S)
                     (= V U)
                     (= X W)
                     (= Z Y)
                     (= B1 A1))))
      (a!13 (not (<= (+ T (* (- 2) X) B1) 0)))
      (a!14 (or A
                B
                D
                (not C)
                (not E)
                (not G)
                (not F)
                (<= (+ T (* (- 2) X) B1) 0)
                (and (not N)
                     M
                     L
                     (not K)
                     (not J)
                     (not I)
                     (not H)
                     (= P O)
                     (= R Q)
                     (= T S)
                     (= V U)
                     (= X W)
                     (= Z Y)
                     (= B1 A1))))
      (a!15 (and (not N)
                 M
                 (not L)
                 (not K)
                 J
                 (not I)
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)))
      (a!16 (not (= (+ P R (* (- 2) V)) 0)))
      (a!17 (or A
                B
                C
                E
                F
                (not D)
                (not G)
                (= (+ P R (* (- 2) V)) 0)
                (and (not N)
                     (not M)
                     L
                     (not K)
                     J
                     I
                     (not H)
                     (= P O)
                     (= R Q)
                     (= T S)
                     (= V U)
                     (= X W)
                     (= Z Y)
                     (= B1 A1))))
      (a!18 (and (not N)
                 (not M)
                 (not L)
                 (not K)
                 J
                 (not I)
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)))
      (a!19 (and (not N)
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 I
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)))
      (a!20 (and (not N)
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 (not I)
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)))
      (a!22 (and N
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 I
                 (not H)
                 (= P O)
                 (= R Q)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ R T (* (- 1) S)) 0)))
      (a!23 (and (not N)
                 M
                 L
                 (not K)
                 (not J)
                 I
                 (not H)
                 (= P O)
                 (= R Q)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ R T (* (- 1) S)) 0)))
      (a!24 (and N
                 (not M)
                 (not L)
                 K
                 J
                 (not I)
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ V (* (- 1) U)) (- 1))))
      (a!25 (and (not N)
                 M
                 L
                 K
                 J
                 (not I)
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ V (* (- 1) U)) 1)))
      (a!26 (and N
                 (not M)
                 (not L)
                 K
                 (not J)
                 (not I)
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ V X (* (- 1) W)) 0)))
      (a!27 (and (not N)
                 M
                 L
                 K
                 (not J)
                 (not I)
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ V X (* (- 1) W)) 0)))
      (a!28 (and N
                 (not M)
                 (not L)
                 K
                 (not J)
                 I
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= B1 A1)
                 (= (+ Z (* (- 1) Y)) (- 1))))
      (a!29 (and (not N)
                 M
                 L
                 K
                 (not J)
                 I
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= B1 A1)
                 (= (+ Z (* (- 1) Y)) (- 1))))
      (a!30 (and N
                 (not M)
                 (not L)
                 (not K)
                 J
                 I
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= (+ P B1 (* (- 1) A1)) 0)))
      (a!31 (and (not N)
                 M
                 L
                 (not K)
                 J
                 I
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= (+ P B1 (* (- 1) A1)) 0)))
      (a!32 (and N
                 M
                 L
                 K
                 J
                 I
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)))
      (a!33 (and (not N)
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 (not I)
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1))))
(let ((a!4 (or A D E (not B) (not C) (not G) (not F) (<= 75 (+ X (* 5 Z))) a!3))
      (a!21 (or A
                C
                E
                (not B)
                (not D)
                (not G)
                (not F)
                (<= (+ X (* (- 5) Z)) 75)
                a!20)))
  (and (or A D E G (not B) (not C) (not F) (<= (- 6) V) a!1)
       (or A C (not B) (not D) (not E) (not G) (not F) (<= 0 P) a!2)
       a!4
       (or A D G (not B) (not C) (not E) (not F) a!5 a!6)
       (or A D (not B) (not C) (not E) (not G) (not F) (<= P R) a!7)
       (or A
           D
           (not B)
           (not C)
           (not E)
           (not G)
           (not F)
           (not (<= P R))
           (and N
                M
                L
                (not K)
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           D
           G
           (not B)
           (not C)
           (not E)
           (not F)
           (not a!5)
           (and N
                M
                (not L)
                K
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           D
           E
           (not B)
           (not C)
           (not G)
           (not F)
           a!8
           (and N
                M
                (not L)
                K
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           D
           E
           G
           (not B)
           (not C)
           (not F)
           (not (<= (- 6) V))
           (and N
                M
                (not L)
                (not K)
                (not J)
                I
                (not H)
                (= P O)
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
           (not G)
           (not F)
           (not (<= 0 P))
           (and N
                M
                (not L)
                (not K)
                (not J)
                (not I)
                (not H)
                (= P O)
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
           (not (<= V 6))
           (and N
                (not M)
                L
                K
                (not J)
                I
                (not H)
                (= P O)
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
           (not G)
           (not F)
           a!9
           (and N
                (not M)
                L
                K
                (not J)
                (not I)
                (not H)
                (= P O)
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
           (not a!10)
           (and N
                (not M)
                L
                (not K)
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           C
           D
           (not B)
           (not E)
           (not G)
           (not F)
           (not (<= R 5))
           (and N
                (not M)
                L
                (not K)
                (not J)
                (not I)
                (not H)
                (= P O)
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
           G
           (not C)
           (not F)
           (= C1 0)
           (and N
                (not M)
                (not L)
                K
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           (not C)
           (not D)
           (not E)
           (not G)
           (not F)
           a!11
           (and N
                (not M)
                (not L)
                (not K)
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       a!12
       (or A
           B
           D
           F
           (not C)
           (not E)
           (not G)
           (= C1 0)
           (and (not N)
                M
                L
                K
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           D
           (not C)
           (not E)
           (not G)
           (not F)
           a!13
           (and (not N)
                M
                L
                (not K)
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       a!14
       (or A
           B
           D
           F
           (not C)
           (not E)
           (not G)
           (not (= C1 0))
           (and (not N)
                M
                (not L)
                K
                J
                I
                (not H)
                (= P O)
                (= R Q)
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
           (<= V 5)
           (and (not N)
                M
                (not L)
                K
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
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
           (not (<= V 5))
           (and (not N)
                M
                (not L)
                K
                (not J)
                I
                (not H)
                (= P O)
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
           (not C)
           (not G)
           (not (<= (- 5) V))
           (and (not N)
                M
                (not L)
                K
                (not J)
                (not I)
                (not H)
                (= P O)
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
           (not C)
           (not G)
           (<= (- 5) V)
           (and (not N)
                M
                (not L)
                (not K)
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A B C (not D) (not E) (not G) (not F) (not (<= V 5)) a!15)
       (or A
           B
           D
           E
           G
           (not C)
           (not F)
           (not (= C1 0))
           (and (not N)
                M
                (not L)
                (not K)
                (not J)
                I
                (not H)
                (= P O)
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
           (not G)
           (not F)
           (<= V 5)
           (and (not N)
                M
                (not L)
                (not K)
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
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
           (not (<= (- 5) V))
           (and (not N)
                (not M)
                L
                K
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
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
           (<= (- 5) V)
           (and (not N)
                (not M)
                L
                K
                (not J)
                I
                (not H)
                (= P O)
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
           (not D)
           (not G)
           a!16
           (and (not N)
                (not M)
                L
                K
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       a!17
       (or A
           B
           C
           E
           F
           G
           (not D)
           (<= P R)
           (and (not N)
                (not M)
                L
                (not K)
                J
                (not I)
                (not H)
                (= P O)
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
           (not (<= P R))
           (and (not N)
                (not M)
                L
                (not K)
                (not J)
                I
                (not H)
                (= P O)
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
           (not E)
           (not G)
           (not (<= R 5))
           (and (not N)
                (not M)
                L
                (not K)
                (not J)
                (not I)
                (not H)
                (= P O)
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
           (not E)
           (not G)
           (<= R 5)
           (and (not N)
                (not M)
                (not L)
                K
                J
                I
                (not H)
                (= P O)
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
           (<= 0 P)
           (and (not N)
                (not M)
                (not L)
                K
                J
                (not I)
                (not H)
                (= P O)
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
           (not (<= 0 P))
           (and (not N)
                (not M)
                (not L)
                K
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A C E G (not B) (not D) (not F) a!10 a!18)
       (or A C D (not B) (not E) (not G) (not F) (<= R 5) a!19)
       a!21
       (or A C D E G (not B) (not F) a!22)
       (or A B E G (not C) (not D) (not F) a!23)
       (or A C D F G (not B) (not E) a!24)
       (or A B F G (not C) (not D) (not E) a!25)
       (or A C D E (not B) (not G) (not F) a!26)
       (or A B E (not C) (not D) (not G) (not F) a!27)
       (or A C D G (not B) (not E) (not F) a!28)
       (or A B G (not C) (not D) (not E) (not F) a!29)
       (or A C D E F (not B) (not G) a!30)
       (or A B E F (not C) (not D) (not G) a!31)
       (or A (not B) (not C) (not D) (not E) (not G) (not F) a!32)
       (or A G (not B) (not C) (not D) (not E) (not F) a!1)
       (or A F (not B) (not C) (not D) (not E) (not G) a!2)
       (or A F G (not B) (not C) (not D) (not E) a!3)
       (or A E (not B) (not C) (not D) (not G) (not F) a!6)
       (or A
           E
           F
           G
           (not B)
           (not C)
           (not D)
           (and N
                M
                L
                (not K)
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A E F (not B) (not C) (not D) (not G) a!7)
       (or A
           D
           F
           (not B)
           (not C)
           (not E)
           (not G)
           (and N
                M
                (not L)
                K
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           D
           F
           G
           (not B)
           (not C)
           (not E)
           (and N
                M
                (not L)
                K
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           D
           E
           F
           (not B)
           (not C)
           (not G)
           (and N
                M
                (not L)
                (not K)
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           D
           E
           F
           G
           (not B)
           (not C)
           (and N
                M
                (not L)
                (not K)
                J
                (not I)
                (not H)
                (= P O)
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
           (not G)
           (and N
                (not M)
                L
                K
                J
                I
                (not H)
                (= P O)
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
           (and N
                (not M)
                L
                K
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           C
           E
           F
           (not B)
           (not D)
           (not G)
           (and N
                (not M)
                L
                (not K)
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           C
           E
           F
           G
           (not B)
           (not D)
           (and N
                (not M)
                L
                (not K)
                J
                (not I)
                (not H)
                (= P O)
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
           (not B)
           (not E)
           (not G)
           (and (not N)
                M
                L
                K
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A B F (not C) (not D) (not E) (not G) a!15)
       (or B C D E G (not A) (not F) a!18)
       (or B C D E F (not A) (not G) a!19)
       (or B C D E F G (not A) a!20)
       (or A B C D E F G a!33)
       (or A B C D G (not E) (not F) a!33)
       (or A B C D (not E) (not G) (not F) a!33)
       (or A B C E G (not D) (not F) a!33)
       (or A B C E (not D) (not G) (not F) a!33)
       (or A B C F (not D) (not E) (not G) a!33)
       (or A B D E F G (not C) a!33)
       (or A B D E (not C) (not G) (not F) a!33)
       (or A B D G (not C) (not E) (not F) a!33)
       (or A B E F G (not C) (not D) a!33)
       (or A C D E F G (not B) a!33)
       (or A E G (not B) (not C) (not D) (not F) a!33)
       (or A
           B
           C
           D
           E
           G
           (not F)
           (and (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                I
                (not H)
                (= S 100)
                (= P O)
                (= R Q)
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
           (not G)
           (and (not N)
                (not M)
                (not L)
                (not K)
                J
                I
                (not H)
                (= W 75)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           C
           F
           G
           (not D)
           (not E)
           (and (not N)
                (not M)
                L
                K
                J
                (not I)
                (not H)
                (= Y 0)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= B1 A1)))
       (or A
           B
           C
           D
           E
           (not G)
           (not F)
           (and (not N)
                (not M)
                (not L)
                K
                (not J)
                (not I)
                (not H)
                (= A1 (- 50))
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)))
       (or A C G (not B) (not D) (not E) (not F) (<= V 6) a!32))))
      )
      (state I J K L M N H O Q S U W Y A1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (state G F E D C B A H I J K L M N)
        (or (and (not A) B C D (not E) (not F) G)
    (and (not A) B C D (not E) F G)
    (and (not A) B C D E (not F) (not G))
    (and (not A) B C D E (not F) G)
    (and (not A) B C D E F (not G))
    (and (not A) B C D E F G)
    (and A (not B) (not C) (not D) (not E) (not F) (not G))
    (and A (not B) (not C) (not D) (not E) (not F) G)
    (and A (not B) (not C) (not D) (not E) F (not G)))
      )
      false
    )
  )
)

(check-sat)
(exit)
