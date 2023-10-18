; ./prepared/vmt/./ctigar/seq-len.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) ) 
    (=>
      (and
        (and (= D true) (not C) (not B) (not A) (not K) (not E))
      )
      (state E D C A B K J I H G F)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Bool) ) 
    (=>
      (and
        (state E D C A B V U S Q O M)
        (let ((a!1 (and K
                (not J)
                (not I)
                (not H)
                (not G)
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
      (a!2 (and (not K)
                J
                I
                H
                G
                F
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!3 (and (not K)
                J
                I
                (not H)
                (not G)
                (not F)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!4 (and (not K)
                J
                (not I)
                (not H)
                G
                F
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!5 (and (not K)
                (not J)
                I
                H
                G
                (not F)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!6 (and (not K)
                (not J)
                I
                (not H)
                (not G)
                F
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!7 (and (not K)
                (not J)
                (not I)
                H
                (not G)
                (not F)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!8 (and (not K)
                (not J)
                I
                H
                G
                F
                (= M L)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!9 (and (not K)
                (not J)
                I
                (not H)
                G
                (not F)
                (= M L)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!10 (and (not K)
                 (not J)
                 (not I)
                 H
                 (not G)
                 F
                 (= M L)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= (+ O (* (- 1) N)) (- 1))))
      (a!11 (and K
                 (not J)
                 (not I)
                 (not H)
                 (not G)
                 (not F)
                 (= M L)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= (+ O (* (- 1) N)) 1)))
      (a!12 (and (not K)
                 J
                 I
                 (not H)
                 (not G)
                 F
                 (= M L)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= (+ O (* (- 1) N)) 1)))
      (a!13 (and (not K)
                 J
                 (not I)
                 H
                 (not G)
                 (not F)
                 (= M L)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= (+ O (* (- 1) N)) 1)))
      (a!14 (and (not K)
                 (not J)
                 (not I)
                 (not H)
                 (not G)
                 (not F)
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T))))
  (and (or D E V (not B) (not A) (not C) (not (<= O 0)) a!1)
       (or D
           E
           V
           (not B)
           (not A)
           (not C)
           (<= O 0)
           (and (not K) J I H (not G) F (= M L) (= O N) (= Q P) (= S R) (= U T)))
       (or C
           V
           (not B)
           (not A)
           (not E)
           (not D)
           (<= Q M)
           (and (not K)
                J
                I
                H
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           D
           V
           (not B)
           (not C)
           (not E)
           (not (<= S M))
           (and (not K)
                J
                I
                (not H)
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           D
           V
           (not B)
           (not C)
           (not E)
           (<= S M)
           (and (not K) J (not I) H G F (= M L) (= O N) (= Q P) (= S R) (= U T)))
       (or A
           C
           E
           V
           (not B)
           (not D)
           (not (<= U M))
           (and (not K)
                J
                (not I)
                H
                (not G)
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           C
           E
           V
           (not B)
           (not D)
           (<= U M)
           (and (not K)
                J
                (not I)
                (not H)
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or B
           D
           E
           V
           (not A)
           (not C)
           (not (<= U M))
           (and (not K)
                J
                (not I)
                (not H)
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or B
           D
           E
           V
           (not A)
           (not C)
           (<= U M)
           (and (not K)
                (not J)
                I
                H
                (not G)
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           B
           V
           (not C)
           (not E)
           (not D)
           (not (<= S M))
           (and (not K)
                (not J)
                I
                (not H)
                G
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           B
           V
           (not C)
           (not E)
           (not D)
           (<= S M)
           (and (not K)
                (not J)
                I
                (not H)
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           B
           C
           D
           V
           (not E)
           (not (<= Q M))
           (and (not K)
                (not J)
                (not I)
                H
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           B
           C
           D
           V
           (not E)
           (<= Q M)
           (and (not K)
                (not J)
                (not I)
                (not H)
                G
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or D V (not B) (not A) (not C) (not E) a!2)
       (or A V (not B) (not C) (not E) (not D) a!3)
       (or A C D V (not B) (not E) a!4)
       (or B E V (not A) (not C) (not D) a!5)
       (or B C D E V (not A) a!6)
       (or A B C V (not E) (not D) a!7)
       (or B D V (not A) (not C) (not E) a!8)
       (or B C E V (not A) (not D) a!9)
       (or A B D E V (not C) a!10)
       (or V (not B) (not A) (not C) (not E) (not D) a!11)
       (or C D E V (not B) (not A) a!12)
       (or A C V (not B) (not E) (not D) a!13)
       (or A B C E (not V) (not D) a!1)
       (or E
           V
           (not B)
           (not A)
           (not C)
           (not D)
           (and (not K) J I H G (not F) (= M L) (= O N) (= Q P) (= S R) (= U T)))
       (or A
           B
           C
           D
           E
           (not V)
           (and (not K) J I (not H) G F (= M L) (= O N) (= Q P) (= S R) (= U T)))
       (or C
           E
           V
           (not B)
           (not A)
           (not D)
           (and (not K)
                J
                (not I)
                H
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           D
           E
           V
           (not B)
           (not C)
           (and (not K)
                J
                (not I)
                (not H)
                (not G)
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or B
           V
           (not A)
           (not C)
           (not E)
           (not D)
           (and (not K)
                (not J)
                I
                H
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or B
           C
           D
           V
           (not A)
           (not E)
           (and (not K)
                (not J)
                (not I)
                H
                G
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           B
           E
           V
           (not C)
           (not D)
           (and (not K)
                (not J)
                (not I)
                (not H)
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A B C D E V a!14)
       (or A B C D (not V) (not E) a!14)
       (or C
           D
           V
           (not B)
           (not A)
           (not E)
           (and (not K) J I (not H) G F (= L 0) (= O N) (= Q P) (= S R) (= U T)))
       (or A
           E
           V
           (not B)
           (not C)
           (not D)
           (and (not K)
                J
                (not I)
                H
                G
                (not F)
                (= L 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           C
           D
           E
           V
           (not B)
           (and (not K)
                J
                (not I)
                (not H)
                (not G)
                F
                (= L 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or B
           C
           V
           (not A)
           (not E)
           (not D)
           (and (not K)
                (not J)
                I
                H
                (not G)
                (not F)
                (= L 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           B
           D
           V
           (not C)
           (not E)
           (and (not K)
                (not J)
                (not I)
                H
                G
                F
                (= L 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           B
           C
           E
           V
           (not D)
           (and (not K)
                (not J)
                (not I)
                (not H)
                G
                (not F)
                (= N 0)
                (= L 0)
                (= Q P)
                (= S R)
                (= U T)))
       (or C
           V
           (not B)
           (not A)
           (not E)
           (not D)
           (not (<= Q M))
           (and K
                (not J)
                (not I)
                (not H)
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))))
      )
      (state G F H I J K T R P N L)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) ) 
    (=>
      (and
        (state E D C A B K J I H G F)
        (and (= D true) (not C) (not B) (not A) (= K true) (not E))
      )
      false
    )
  )
)

(check-sat)
(exit)
