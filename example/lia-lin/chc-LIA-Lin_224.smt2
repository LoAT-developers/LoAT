; ./vmt/./ctigar/hsortprime.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (and (= E true) (not D) (not C) (not B) (not A) (not F))
      )
      (state F E D B A C G H I J K)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (state F E D B A C N P R T V)
        (let ((a!1 (not (<= (+ (* 2 R) (* (- 1) T)) 1)))
      (a!2 (not (<= (+ P (* (- 1) T)) (- 1))))
      (a!3 (or A
               C
               (not B)
               (not D)
               (not F)
               (not E)
               (<= (+ P (* (- 1) T)) (- 1))
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
                    (= V U))))
      (a!4 (not (<= (+ (* 2 R) (* (- 1) V)) 1)))
      (a!5 (and (not L)
                (not K)
                J
                I
                H
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
      (a!6 (or A
               C
               D
               (not B)
               (not F)
               (not E)
               (<= (+ (* 2 R) (* (- 1) V)) 1)
               (and (not L)
                    (not K)
                    J
                    I
                    (not H)
                    (not G)
                    (= N M)
                    (= P O)
                    (= R Q)
                    (= T S)
                    (= V U))))
      (a!7 (not (<= 0 (+ (* 2 R) (* (- 1) V)))))
      (a!8 (not (= (+ P (* (- 2) R)) 0)))
      (a!9 (or A
               C
               D
               F
               (not B)
               (not E)
               (<= 0 (+ (* 2 R) (* (- 1) V)))
               (and (not L)
                    (not K)
                    J
                    (not I)
                    (not H)
                    G
                    (= N M)
                    (= P O)
                    (= R Q)
                    (= T S)
                    (= V U))))
      (a!10 (or A
                B
                C
                (not D)
                (not F)
                (not E)
                (= (+ P (* (- 2) R)) 0)
                (and (not L)
                     (not K)
                     J
                     (not I)
                     (not H)
                     (not G)
                     (= N M)
                     (= P O)
                     (= R Q)
                     (= T S)
                     (= V U))))
      (a!11 (and L
                 (not K)
                 (not J)
                 (not I)
                 (not H)
                 (not G)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= (+ M (* (- 1) R)) (- 1))))
      (a!12 (and (not L)
                 K
                 (not J)
                 (not I)
                 (not H)
                 G
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= (+ M (* (- 1) P)) 1)))
      (a!13 (and (not L)
                 K
                 (not J)
                 (not I)
                 H
                 G
                 (= N M)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= (+ (* 2 P) (* (- 1) O)) (- 2))))
      (a!14 (and (not L)
                 K
                 J
                 (not I)
                 H
                 (not G)
                 (= N M)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= (+ (* 2 P) (* (- 1) O)) 0)))
      (a!15 (and L
                 (not K)
                 (not J)
                 (not I)
                 H
                 (not G)
                 (= N M)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= (+ O (* (- 2) R)) (- 2))))
      (a!16 (and L
                 (not K)
                 J
                 (not I)
                 (not H)
                 G
                 (= N M)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= (+ O (* (- 2) R)) 0)))
      (a!17 (and L
                 (not K)
                 (not J)
                 (not I)
                 (not H)
                 G
                 (= N M)
                 (= P O)
                 (= T S)
                 (= V U)
                 (= (+ R (* (- 1) Q)) 1)))
      (a!18 (and L
                 (not K)
                 (not J)
                 I
                 (not H)
                 G
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= V U)
                 (= (+ T (* (- 1) S)) 1)))
      (a!19 (and L
                 (not K)
                 J
                 I
                 (not H)
                 G
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)))
      (a!20 (and (not L)
                 (not K)
                 (not J)
                 (not I)
                 (not H)
                 (not G)
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U))))
(let ((a!21 (or A
                D
                (not C)
                (not B)
                (not F)
                (not E)
                (<= (+ (* 2 R) (* (- 1) T)) 1)
                a!19)))
  (and (or A
           D
           (not C)
           (not B)
           (not F)
           (not E)
           a!1
           (and L
                (not K)
                J
                I
                (not H)
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
       (or A
           C
           F
           (not B)
           (not D)
           (not E)
           (= W 0)
           (and L (not K) J (not I) H G (= N M) (= P O) (= R Q) (= T S) (= V U)))
       (or A
           B
           E
           (not C)
           (not D)
           (not F)
           (not (<= 3 T))
           (and L
                (not K)
                J
                (not I)
                (not H)
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
       (or A
           B
           E
           (not C)
           (not D)
           (not F)
           (<= 3 T)
           (and L (not K) (not J) I H G (= N M) (= P O) (= R Q) (= T S) (= V U)))
       (or A
           B
           D
           (not C)
           (not F)
           (not E)
           (not (<= R 1))
           (and L
                (not K)
                (not J)
                I
                H
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
       (or A
           B
           D
           (not C)
           (not F)
           (not E)
           (<= R 1)
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
                (= V U)))
       (or C
           D
           E
           (not A)
           (not B)
           (not F)
           (= W 0)
           (and L
                (not K)
                (not J)
                (not I)
                H
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
       (or C
           F
           (not A)
           (not B)
           (not D)
           (not E)
           (not (<= 2 T))
           (and (not L) K J I H G (= N M) (= P O) (= R Q) (= T S) (= V U)))
       (or C
           D
           (not A)
           (not B)
           (not F)
           (not E)
           (not (<= 2 R))
           (and (not L) K J I H (not G) (= N M) (= P O) (= R Q) (= T S) (= V U)))
       (or C
           F
           (not A)
           (not B)
           (not D)
           (not E)
           (<= 2 T)
           (and (not L) K J I (not H) G (= N M) (= P O) (= R Q) (= T S) (= V U)))
       (or C
           D
           (not A)
           (not B)
           (not F)
           (not E)
           (<= 2 R)
           (and (not L)
                K
                J
                I
                (not H)
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
       (or C
           D
           E
           (not A)
           (not B)
           (not F)
           (not (= W 0))
           (and (not L) K J (not I) H G (= N M) (= P O) (= R Q) (= T S) (= V U)))
       (or B
           C
           E
           F
           (not A)
           (not D)
           (= W 0)
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
                (= V U)))
       (or B
           C
           F
           (not A)
           (not D)
           (not E)
           (not (<= P T))
           (and (not L) K (not J) I H G (= N M) (= P O) (= R Q) (= T S) (= V U)))
       (or B
           C
           E
           F
           (not A)
           (not D)
           (not (= W 0))
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
                (= V U)))
       (or B
           C
           F
           (not A)
           (not D)
           (not E)
           (<= P T)
           (and (not L)
                K
                (not J)
                I
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
       (or A
           C
           E
           (not B)
           (not D)
           (not F)
           (= W 0)
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
                (= V U)))
       (or A
           C
           (not B)
           (not D)
           (not F)
           (not E)
           a!2
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
                (= V U)))
       a!3
       (or A
           C
           E
           (not B)
           (not D)
           (not F)
           (not (= W 0))
           (and (not L) (not K) J I H G (= N M) (= P O) (= R Q) (= T S) (= V U)))
       (or A C D (not B) (not F) (not E) a!4 a!5)
       (or A
           C
           F
           (not B)
           (not D)
           (not E)
           (not (= W 0))
           (and (not L)
                (not K)
                J
                I
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
       a!6
       (or A
           C
           D
           F
           (not B)
           (not E)
           a!7
           (and (not L)
                (not K)
                J
                (not I)
                H
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
       (or A
           B
           C
           (not D)
           (not F)
           (not E)
           a!8
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
                (= V U)))
       a!9
       a!10
       (or A
           B
           C
           F
           (not D)
           (not E)
           (not (= N R))
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
                (= V U)))
       (or A
           B
           C
           D
           (not F)
           (not E)
           (not (= T V))
           (and (not L)
                (not K)
                (not J)
                I
                H
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
       (or A
           B
           C
           F
           (not D)
           (not E)
           (= N R)
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
                (= V U)))
       (or A
           B
           C
           D
           (not F)
           (not E)
           (= T V)
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
                (= V U)))
       (or A
           B
           C
           D
           F
           (not E)
           (not (<= 2 V))
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
                (= V U)))
       (or A
           B
           C
           D
           F
           (not E)
           (<= 2 V)
           (and (not L)
                (not K)
                (not J)
                (not I)
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
       (or C (not A) (not B) (not D) (not F) (not E) a!11)
       (or B C D F (not A) (not E) a!12)
       (or B C D E (not A) (not F) a!13)
       (or C D E F (not A) (not B) a!14)
       (or A B D E F (not C) a!15)
       (or A D F (not C) (not B) (not E) a!16)
       (or A B D F (not C) (not E) a!17)
       (or A B F (not C) (not D) (not E) a!18)
       (or A
           E
           F
           (not C)
           (not B)
           (not D)
           (and L (not K) J I H (not G) (= N M) (= P O) (= R Q) (= T S) (= V U)))
       (or A E (not C) (not B) (not D) (not F) a!19)
       (or A
           D
           E
           (not C)
           (not B)
           (not F)
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
                (= V U)))
       (or A
           B
           D
           E
           (not C)
           (not F)
           (and (not L)
                K
                J
                (not I)
                H
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
       (or C
           D
           F
           (not A)
           (not B)
           (not E)
           (and (not L)
                K
                (not J)
                (not I)
                H
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
       (or B C D (not A) (not F) (not E) a!5)
       (or A B C D E F a!20)
       (or A B C D E (not F) a!20)
       (or A B C E F (not D) a!20)
       (or A B C E (not D) (not F) a!20)
       (or A B E F (not C) (not D) a!20)
       (or A B (not C) (not D) (not F) (not E) a!20)
       (or A C D E F (not B) a!20)
       (or A C D E (not B) (not F) a!20)
       (or A C E F (not B) (not D) a!20)
       (or A F (not C) (not B) (not D) (not E) a!20)
       (or B C D E F (not A) a!20)
       (or B C E (not A) (not D) (not F) a!20)
       (or C E F (not A) (not B) (not D) a!20)
       (or C E (not A) (not B) (not D) (not F) a!20)
       (or A
           D
           E
           F
           (not C)
           (not B)
           (and L
                (not K)
                J
                (not I)
                H
                (not G)
                (= M R)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
       (or B
           C
           (not A)
           (not D)
           (not F)
           (not E)
           (and (not L)
                K
                J
                (not I)
                (not H)
                (not G)
                (= M P)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)))
       a!21)))
      )
      (state G H I J K L M O Q S U)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (state F E D B A C G H I J K)
        (and (not E) (= D true) (= C true) (= B true) (not A) (= F true))
      )
      false
    )
  )
)

(check-sat)
(exit)
