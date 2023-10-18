; ./prepared/vmt/./ctigar/nest-if8.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Bool) ) 
    (=>
      (and
        (and (= C true) (not B) (not A) (not J) (not D))
      )
      (state D C A B J I H G F E)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Bool) ) 
    (=>
      (and
        (state D C A B U S Q O M K)
        (let ((a!1 (not (<= (+ S M (* (- 1) K)) (- 5))))
      (a!2 (and I
                H
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
      (a!3 (or B
               C
               D
               (not U)
               (not A)
               (<= (+ S M (* (- 1) K)) (- 5))
               (and I
                    (not H)
                    G
                    (not F)
                    E
                    (= K J)
                    (= M L)
                    (= O N)
                    (= Q P)
                    (= S R))))
      (a!4 (and I (not H) (not G) F E (= K J) (= M L) (= O N) (= Q P) (= S R)))
      (a!5 (and I
                (not H)
                (not G)
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
      (a!6 (and I
                (not H)
                (not G)
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
      (a!7 (or A
               B
               D
               U
               (not C)
               (<= (+ S (* (- 1) Q)) 1)
               (and (not I)
                    (not H)
                    (not G)
                    F
                    E
                    (= K J)
                    (= M L)
                    (= O N)
                    (= Q P)
                    (= S R))))
      (a!8 (not (<= (+ S (* (- 1) Q)) 1)))
      (a!9 (and I
                H
                (not G)
                F
                (not E)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= (+ K (* (- 1) J)) (- 4))))
      (a!10 (and I
                 (not H)
                 G
                 F
                 E
                 (= K J)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= (+ M (* (- 1) L)) (- 2))))
      (a!11 (and (not I)
                 H
                 (not G)
                 F
                 E
                 (= K J)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= (+ M (* (- 1) L)) (- 1))))
      (a!12 (and I
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= Q P)
                 (= S R)
                 (= (+ O (* (- 1) N)) (- 1))))
      (a!13 (and (not I)
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= S R))))
  (and (or B
           C
           U
           (not A)
           (not D)
           (not (<= Q M))
           (and I H (not G) (not F) E (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or B C D (not U) (not A) a!1 a!2)
       a!3
       (or B
           U
           (not A)
           (not D)
           (not C)
           (= T 0)
           (and I
                (not H)
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A C D U (not B) (<= 0 M) a!4)
       (or C D U (not B) (not A) (not (<= M O)) a!5)
       (or D U (not B) (not A) (not C) (not (<= S O)) a!6)
       (or D
           U
           (not B)
           (not A)
           (not C)
           (<= S O)
           (and (not I) H G F (not E) (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or C
           D
           U
           (not B)
           (not A)
           (<= M O)
           (and (not I) H G (not F) E (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or A
           C
           D
           U
           (not B)
           (not (<= 0 M))
           (and (not I)
                H
                (not G)
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or B
           U
           (not A)
           (not D)
           (not C)
           (not (= T 0))
           (and (not I)
                H
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or B
           C
           U
           (not A)
           (not D)
           (<= Q M)
           (and (not I) (not H) G F E (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or B
           C
           D
           U
           (not A)
           (<= S K)
           (and (not I)
                (not H)
                G
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       a!7
       (or A
           B
           D
           U
           (not C)
           a!8
           (and (not I)
                (not H)
                (not G)
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A D (not U) (not B) (not C) a!9)
       (or B C (not U) (not A) (not D) a!10)
       (or A C U (not B) (not D) a!11)
       (or U (not B) (not A) (not D) (not C) a!12)
       (or A C D (not U) (not B) a!2)
       (or B
           D
           (not U)
           (not A)
           (not C)
           (and I (not H) G F (not E) (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or A B (not U) (not D) (not C) a!4)
       (or B (not U) (not A) (not D) (not C) a!5)
       (or A B D (not U) (not C) a!6)
       (or C
           U
           (not B)
           (not A)
           (not D)
           (and (not I) H G F E (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or A
           B
           C
           D
           (not U)
           (and (not I)
                H
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           D
           U
           (not B)
           (not C)
           (and (not I)
                H
                (not G)
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           B
           C
           (not U)
           (not D)
           (and (not I)
                (not H)
                G
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           C
           (not U)
           (not B)
           (not D)
           (and (not I)
                (not H)
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A B C D U a!13)
       (or A B C U (not D) a!13)
       (or A (not U) (not B) (not D) (not C) a!13)
       (or A
           B
           U
           (not D)
           (not C)
           (and (not I)
                (not H)
                G
                (not F)
                (not E)
                (= J 0)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or B
           D
           U
           (not A)
           (not C)
           (and (not I)
                (not H)
                G
                F
                (not E)
                (= L K)
                (= K J)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           U
           (not B)
           (not D)
           (not C)
           (and (not I)
                H
                G
                (not F)
                (not E)
                (= N 0)
                (= K J)
                (= M L)
                (= Q P)
                (= S R)))
       (or B
           C
           D
           U
           (not A)
           (not (<= S K))
           (and I H (not G) F E (= K J) (= M L) (= O N) (= Q P) (= S R)))))
      )
      (state F E G H I R P N L J)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Bool) ) 
    (=>
      (and
        (state D C A B J I H G F E)
        (and (not A)
     (= J true)
     (or (and (not B) C (not D)) (and (not B) C D) (and B (not C) (not D))))
      )
      false
    )
  )
)

(check-sat)
(exit)
