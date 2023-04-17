; ./vmt/./ctigar/mergesort.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (and (= E true) (not D) (not C) (not B) (not A) (not F))
      )
      (state F E D B C A Q P O N M L K J I H G)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) ) 
    (=>
      (and
        (state F E D B C A H1 F1 D1 B1 Z X V T R P N)
        (let ((a!1 (or A
               B
               C
               E
               F
               (not D)
               (<= (+ F1 Z (* (- 1) T)) 0)
               (and L
                    (not K)
                    (not J)
                    I
                    H
                    G
                    (= N M)
                    (= P O)
                    (= R Q)
                    (= T S)
                    (= V U)
                    (= X W)
                    (= Z Y)
                    (= B1 A1)
                    (= D1 C1)
                    (= F1 E1)
                    (= H1 G1))))
      (a!2 (and L
                (not K)
                (not J)
                I
                H
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
      (a!3 (and (not L)
                K
                J
                I
                (not H)
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
      (a!4 (and (not L)
                (not K)
                J
                (not I)
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
      (a!5 (not (<= (+ F1 Z (* (- 1) T)) 0)))
      (a!6 (or A
               C
               (not B)
               (not D)
               (not F)
               (not E)
               (and (not (<= N X)) (not (<= R H1)))
               (and (not L)
                    K
                    (not J)
                    I
                    H
                    (not G)
                    (= N M)
                    (= P O)
                    (= R Q)
                    (= T S)
                    (= V U)
                    (= X W)
                    (= Z Y)
                    (= B1 A1)
                    (= D1 C1)
                    (= F1 E1)
                    (= H1 G1))))
      (a!7 (and (not L)
                (not K)
                J
                (not I)
                H
                G
                (= N M)
                (= P O)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= (+ F1 Z (* (- 1) Q)) 0)))
      (a!8 (and (not L)
                K
                J
                I
                H
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= (+ X (* (- 1) W)) (- 1))))
      (a!9 (and (not L)
                K
                (not J)
                I
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)
                (= (+ X (* (- 1) W)) (- 1))))
      (a!10 (and L
                 (not K)
                 (not J)
                 I
                 (not H)
                 G
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= (+ (* 2 F1) Z (* (- 1) Y)) 0)))
      (a!11 (and L
                 (not K)
                 (not J)
                 (not I)
                 H
                 G
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!12 (and (not L)
                 K
                 J
                 I
                 H
                 G
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!13 (and (not L)
                 K
                 J
                 (not I)
                 H
                 G
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!14 (and (not L)
                 K
                 (not J)
                 (not I)
                 H
                 G
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)
                 (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!15 (and (not L)
                 (not K)
                 (not J)
                 I
                 H
                 (not G)
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= F1 E1)
                 (= H1 G1)
                 (= (+ (* 2 F1) (* (- 1) C1) Z) 0)))
      (a!16 (and (not L)
                 (not K)
                 J
                 (not I)
                 (not H)
                 (not G)
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= F1 E1)
                 (= H1 G1)
                 (= (+ C1 (* (- 1) T)) 1)))
      (a!17 (and L
                 (not K)
                 J
                 (not I)
                 (not H)
                 (not G)
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= H1 G1)
                 (= (+ (* 2 F1) (* (- 1) E1)) 0)))
      (a!18 (and (not L)
                 K
                 J
                 (not I)
                 H
                 (not G)
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ H1 (* (- 1) G1)) (- 1))))
      (a!19 (and (not L)
                 K
                 (not J)
                 (not I)
                 H
                 (not G)
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ H1 (* (- 1) G1)) (- 1))))
      (a!20 (and (not L)
                 K
                 J
                 (not I)
                 (not H)
                 (not G)
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1)))
      (a!21 (and (not L)
                 (not K)
                 (not J)
                 (not I)
                 (not H)
                 (not G)
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= H1 G1))))
  (and (or A
           B
           C
           D
           E
           (not F)
           (not (<= T F1))
           (and L
                (not K)
                J
                (not I)
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       a!1
       (or A B E (not C) (not D) (not F) (<= B1 T) a!2)
       (or B
           C
           D
           F
           (not A)
           (not E)
           (not (<= N B1))
           (and L
                (not K)
                (not J)
                I
                (not H)
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or B
           C
           D
           F
           (not A)
           (not E)
           (<= N B1)
           (and L
                (not K)
                (not J)
                (not I)
                H
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A
           E
           F
           (not C)
           (not B)
           (not D)
           (not (<= N X))
           (and L
                (not K)
                (not J)
                (not I)
                (not H)
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A
           E
           F
           (not C)
           (not B)
           (not D)
           (<= N X)
           (and (not L)
                K
                J
                I
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A D E F (not C) (not B) (not (<= R H1)) a!3)
       (or A
           D
           E
           F
           (not C)
           (not B)
           (<= R H1)
           (and (not L)
                K
                J
                (not I)
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A
           B
           E
           (not C)
           (not D)
           (not F)
           (not (<= B1 T))
           (and (not L)
                K
                (not J)
                I
                H
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A
           B
           D
           E
           F
           (not C)
           (= I1 0)
           (and (not L)
                K
                (not J)
                I
                (not H)
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A
           B
           D
           E
           F
           (not C)
           (not (= I1 0))
           (and (not L)
                K
                (not J)
                (not I)
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A B C E (not D) (not F) (not (<= D1 T)) a!4)
       (or A
           B
           C
           E
           (not D)
           (not F)
           (<= D1 T)
           (and (not L)
                (not K)
                (not J)
                I
                H
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A
           B
           C
           E
           F
           (not D)
           a!5
           (and (not L)
                (not K)
                (not J)
                I
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A
           B
           C
           D
           E
           (not F)
           (<= T F1)
           (and (not L)
                (not K)
                (not J)
                (not I)
                H
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       a!6
       (or A
           C
           D
           (not B)
           (not F)
           (not E)
           (and (not L)
                (not K)
                J
                I
                (not H)
                (not G)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= D1 M)
                (= F1 E1)
                (= H1 G1)))
       (or A C D E (not B) (not F) a!7)
       (or A
           C
           D
           F
           (not B)
           (not E)
           (and (not L)
                (not K)
                J
                (not I)
                H
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= X W)
                (= Z Y)
                (= Z U)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A F (not C) (not B) (not D) (not E) a!8)
       (or A B E F (not C) (not D) a!9)
       (or B C E F (not A) (not D) a!10)
       (or B C D E (not A) (not F) a!11)
       (or A E (not C) (not B) (not D) (not F) a!12)
       (or A D E (not C) (not B) (not F) a!13)
       (or A B D E (not C) (not F) a!14)
       (or A B C F (not D) (not E) a!15)
       (or A B C (not D) (not F) (not E) a!16)
       (or B C (not A) (not D) (not F) (not E) a!17)
       (or A D F (not C) (not B) (not E) a!18)
       (or A B D F (not C) (not E) a!19)
       (or B C E (not A) (not D) (not F) a!2)
       (or B
           C
           D
           (not A)
           (not F)
           (not E)
           (and L
                (not K)
                (not J)
                (not I)
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A (not C) (not B) (not D) (not F) (not E) a!3)
       (or A B (not C) (not D) (not F) (not E) a!20)
       (or A D (not C) (not B) (not F) (not E) a!20)
       (or A
           B
           F
           (not C)
           (not D)
           (not E)
           (and (not L)
                K
                (not J)
                (not I)
                H
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A
           B
           D
           (not C)
           (not F)
           (not E)
           (and (not L)
                (not K)
                J
                I
                H
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A C D E F (not B) a!4)
       (or B
           C
           F
           (not A)
           (not D)
           (not E)
           (and (not L)
                (not K)
                (not J)
                I
                (not H)
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or C
           D
           E
           F
           (not A)
           (not B)
           (and (not L)
                (not K)
                (not J)
                (not I)
                H
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A B C D E F a!21)
       (or C D F (not A) (not B) (not E) a!21)
       (or A
           C
           F
           (not B)
           (not D)
           (not E)
           (and (not L)
                (not K)
                J
                I
                H
                (not G)
                (= W R)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A
           B
           C
           D
           (not F)
           (not E)
           (and (not L)
                (not K)
                (not J)
                I
                (not H)
                (not G)
                (= Y 1)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or B
           C
           D
           E
           F
           (not A)
           (and L
                (not K)
                (not J)
                (not I)
                (not H)
                G
                (= A1 V)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A
           C
           E
           (not B)
           (not D)
           (not F)
           (and (not L)
                (not K)
                J
                I
                H
                G
                (= A1 V)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))
       (or A
           B
           C
           D
           F
           (not E)
           (and (not L)
                (not K)
                (not J)
                (not I)
                H
                (not G)
                (= E1 1)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= H1 G1)))
       (or A
           C
           E
           F
           (not B)
           (not D)
           (and (not L)
                (not K)
                J
                I
                (not H)
                G
                (= G1 V)
                (= N M)
                (= P O)
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
           (not F)
           (not E)
           (<= R H1)
           (<= N X)
           (and (not L)
                K
                (not J)
                (not I)
                (not H)
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)
                (= H1 G1)))))
      )
      (state H G I J K L G1 E1 C1 A1 Y W U S Q O M)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (state F E D B C A Q P O N M L K J I H G)
        (and (not E) (= D true) (not C) (not B) (= A true) (= F true))
      )
      false
    )
  )
)

(check-sat)
(exit)
