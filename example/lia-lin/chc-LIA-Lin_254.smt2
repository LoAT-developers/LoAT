; ./vmt/./ctigar/apache-get-tag.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Bool) (G Bool) (H Bool) (I Bool) ) 
    (=>
      (and
        (and (= B true) (not A) (not I) (not H) (not G) (not F) (not C))
      )
      (state C B A I H F G E D)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Int) (L Int) (M Int) (N Int) (O Int) (P Bool) (Q Bool) (R Bool) (S Bool) ) 
    (=>
      (and
        (state C B A S R P Q N L)
        (let ((a!1 (and J (not I) (not H) G (not F) E (not D) (= L K) (= N M)))
      (a!2 (and J (not I) (not H) G (not F) (not E) D (= L K) (= N M)))
      (a!3 (and J (not I) (not H) (not G) (not F) E (not D) (= L K) (= N M)))
      (a!4 (and J (not I) (not H) (not G) (not F) (not E) D (= L K) (= N M)))
      (a!5 (and (not J) I H G F E D (= L K) (= N M)))
      (a!6 (and (not J) I H G F E (not D) (= L K) (= N M)))
      (a!7 (and (not J) I H (not G) F E (not D) (= L K) (= N M)))
      (a!8 (and (not J) I H (not G) F (not E) D (= L K) (= N M)))
      (a!9 (and (not J) I H (not G) F (not E) (not D) (= L K) (= N M)))
      (a!10 (and (not J) I H (not G) (not F) E D (= L K) (= N M)))
      (a!11 (and (not J) I (not H) G F (not E) D (= L K) (= N M)))
      (a!12 (and (not J) I (not H) G (not F) E D (= L K) (= N M)))
      (a!13 (and (not J) I (not H) G (not F) E (not D) (= L K) (= N M)))
      (a!14 (and (not J) (not I) H G F (not E) (not D) (= L K) (= N M)))
      (a!15 (and (not J) (not I) H G (not F) E D (= L K) (= N M)))
      (a!16 (and (not J) (not I) (not H) G F (not E) (not D) (= L K) (= N M)))
      (a!17 (and (not J) (not I) (not H) G (not F) E D (= L K) (= N M)))
      (a!18 (and J
                 (not I)
                 (not H)
                 G
                 (not F)
                 (not E)
                 (not D)
                 (= N M)
                 (= (+ L (* (- 1) K)) (- 1))))
      (a!19 (and (not J)
                 I
                 H
                 (not G)
                 (not F)
                 E
                 (not D)
                 (= N M)
                 (= (+ L (* (- 1) K)) (- 1))))
      (a!20 (and (not J)
                 I
                 (not H)
                 (not G)
                 F
                 (not E)
                 (not D)
                 (= N M)
                 (= (+ L (* (- 1) K)) (- 1))))
      (a!21 (and (not J)
                 (not I)
                 H
                 (not G)
                 F
                 (not E)
                 (not D)
                 (= N M)
                 (= (+ L (* (- 1) K)) (- 1))))
      (a!22 (and (not J)
                 (not I)
                 (not H)
                 (not G)
                 F
                 (not E)
                 (not D)
                 (= L K)
                 (= (+ N (* (- 1) M)) 1)))
      (a!23 (and (not J)
                 (not I)
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (not D)
                 (= L K)
                 (= N M))))
  (and (or A P R S (not Q) (not C) (not B) (<= 0 L) a!1)
       (or C P R S (not Q) (not A) (not B) (<= L N) a!2)
       (or C
           P
           R
           S
           (not Q)
           (not A)
           (not B)
           (not (<= L N))
           (and J (not I) (not H) (not G) F E (not D) (= L K) (= N M)))
       (or A
           P
           R
           S
           (not Q)
           (not C)
           (not B)
           (not (<= 0 L))
           (and J (not I) (not H) (not G) F (not E) (not D) (= L K) (= N M)))
       (or C
           P
           Q
           R
           (not S)
           (not A)
           (not B)
           (= O 0)
           (and J (not I) (not H) (not G) (not F) E D (= L K) (= N M)))
       (or P Q R (not S) (not A) (not C) (not B) (<= 0 L) a!3)
       (or A C P Q S (not R) (not B) (<= L N) a!4)
       (or Q
           S
           (not P)
           (not R)
           (not A)
           (not C)
           (not B)
           (= O 0)
           (and J
                (not I)
                (not H)
                (not G)
                (not F)
                (not E)
                (not D)
                (= L K)
                (= N M)))
       (or A C Q (not P) (not R) (not S) (not B) (<= 0 L) a!5)
       (or A Q (not P) (not R) (not S) (not C) (not B) (<= L N) a!6)
       (or A
           Q
           (not P)
           (not R)
           (not S)
           (not C)
           (not B)
           (not (<= L N))
           (and (not J) I H G F (not E) (not D) (= L K) (= N M)))
       (or A
           C
           Q
           (not P)
           (not R)
           (not S)
           (not B)
           (not (<= 0 L))
           (and (not J) I H G (not F) E (not D) (= L K) (= N M)))
       (or Q
           S
           (not P)
           (not R)
           (not A)
           (not C)
           (not B)
           (not (= O 0))
           (and (not J) I H G (not F) (not E) (not D) (= L K) (= N M)))
       (or C
           P
           Q
           (not R)
           (not S)
           (not A)
           (not B)
           (= O 0)
           (and (not J) I H (not G) F E D (= L K) (= N M)))
       (or P Q (not R) (not S) (not A) (not C) (not B) (<= 0 L) a!7)
       (or A C Q R S (not P) (not B) (<= L N) a!8)
       (or C Q R (not P) (not S) (not A) (not B) (<= 0 L) a!9)
       (or Q R (not P) (not S) (not A) (not C) (not B) (<= L N) a!10)
       (or Q
           R
           (not P)
           (not S)
           (not A)
           (not C)
           (not B)
           (not (<= L N))
           (and (not J) I H (not G) (not F) (not E) (not D) (= L K) (= N M)))
       (or C
           Q
           R
           (not P)
           (not S)
           (not A)
           (not B)
           (not (<= 0 L))
           (and (not J) I (not H) G F E (not D) (= L K) (= N M)))
       (or B P Q (not R) (not S) (not A) (not C) (= O 0) a!11)
       (or B
           C
           Q
           R
           S
           (not P)
           (not A)
           (= N L)
           (and (not J) I (not H) G F (not E) (not D) (= L K) (= N M)))
       (or C Q R S (not P) (not A) (not B) (<= 0 L) a!12)
       (or Q R S (not P) (not A) (not C) (not B) (<= L N) a!13)
       (or Q
           R
           S
           (not P)
           (not A)
           (not C)
           (not B)
           (not (<= L N))
           (and (not J) I (not H) G (not F) (not E) (not D) (= L K) (= N M)))
       (or C
           Q
           R
           S
           (not P)
           (not A)
           (not B)
           (not (<= 0 L))
           (and (not J) I (not H) (not G) F E (not D) (= L K) (= N M)))
       (or B
           C
           Q
           R
           S
           (not P)
           (not A)
           (not (= N L))
           (and (not J) I (not H) (not G) F (not E) D (= L K) (= N M)))
       (or A
           C
           Q
           R
           S
           (not P)
           (not B)
           (not (<= L N))
           (and (not J) I (not H) (not G) (not F) E (not D) (= L K) (= N M)))
       (or P
           Q
           (not R)
           (not S)
           (not A)
           (not C)
           (not B)
           (not (<= 0 L))
           (and (not J)
                I
                (not H)
                (not G)
                (not F)
                (not E)
                (not D)
                (= L K)
                (= N M)))
       (or B
           P
           Q
           (not R)
           (not S)
           (not A)
           (not C)
           (not (= O 0))
           (and (not J) (not I) H G F E D (= L K) (= N M)))
       (or C
           P
           Q
           (not R)
           (not S)
           (not A)
           (not B)
           (not (= O 0))
           (and (not J) (not I) H G F E (not D) (= L K) (= N M)))
       (or C
           P
           Q
           S
           (not R)
           (not A)
           (not B)
           (= N L)
           (and (not J) (not I) H G F (not E) D (= L K) (= N M)))
       (or B P Q S (not R) (not A) (not C) (<= 0 L) a!14)
       (or A B C P Q (not R) (not S) (<= L N) a!15)
       (or A
           B
           C
           P
           Q
           (not R)
           (not S)
           (not (<= L N))
           (and (not J) (not I) H G (not F) (not E) D (= L K) (= N M)))
       (or B
           P
           Q
           S
           (not R)
           (not A)
           (not C)
           (not (<= 0 L))
           (and (not J) (not I) H (not G) F E D (= L K) (= N M)))
       (or C
           P
           Q
           S
           (not R)
           (not A)
           (not B)
           (not (= N L))
           (and (not J) (not I) H (not G) F E (not D) (= L K) (= N M)))
       (or A
           C
           P
           Q
           S
           (not R)
           (not B)
           (not (<= L N))
           (and (not J) (not I) H (not G) (not F) E (not D) (= L K) (= N M)))
       (or P
           Q
           R
           (not S)
           (not A)
           (not C)
           (not B)
           (not (<= 0 L))
           (and (not J)
                (not I)
                H
                (not G)
                (not F)
                (not E)
                (not D)
                (= L K)
                (= N M)))
       (or C
           P
           Q
           R
           (not S)
           (not A)
           (not B)
           (not (= O 0))
           (and (not J) (not I) (not H) G F E (not D) (= L K) (= N M)))
       (or C
           P
           Q
           R
           S
           (not A)
           (not B)
           (= N L)
           (and (not J) (not I) (not H) G F (not E) D (= L K) (= N M)))
       (or B P Q R S (not A) (not C) (<= 0 L) a!16)
       (or A B C P Q R (not S) (<= L N) a!17)
       (or A
           B
           C
           P
           Q
           R
           (not S)
           (not (<= L N))
           (and (not J) (not I) (not H) G (not F) (not E) D (= L K) (= N M)))
       (or B
           P
           Q
           R
           S
           (not A)
           (not C)
           (not (<= 0 L))
           (and (not J) (not I) (not H) (not G) F E D (= L K) (= N M)))
       (or C
           P
           Q
           R
           S
           (not A)
           (not B)
           (not (= N L))
           (and (not J) (not I) (not H) (not G) F E (not D) (= L K) (= N M)))
       (or A
           C
           P
           Q
           R
           S
           (not B)
           (not (<= 1 N))
           (and (not J)
                (not I)
                (not H)
                (not G)
                (not F)
                E
                (not D)
                (= L K)
                (= N M)))
       (or P R S (not Q) (not A) (not C) (not B) a!18)
       (or A C Q S (not P) (not R) (not B) a!19)
       (or A Q R S (not P) (not C) (not B) a!20)
       (or A P Q S (not R) (not C) (not B) a!21)
       (or A P Q R S (not C) (not B) a!22)
       (or A B P R (not Q) (not S) (not C) a!1)
       (or A C P R (not Q) (not S) (not B) a!2)
       (or B
           P
           R
           S
           (not Q)
           (not A)
           (not C)
           (and J (not I) (not H) (not G) F E D (= L K) (= N M)))
       (or B
           C
           P
           R
           S
           (not Q)
           (not A)
           (and J (not I) (not H) (not G) F (not E) D (= L K) (= N M)))
       (or A B P R S (not Q) (not C) a!3)
       (or A C P R S (not Q) (not B) a!4)
       (or Q (not P) (not R) (not S) (not A) (not C) (not B) a!5)
       (or B Q (not P) (not R) (not S) (not A) (not C) a!6)
       (or B
           C
           Q
           (not P)
           (not R)
           (not S)
           (not A)
           (and (not J) I H G F (not E) D (= L K) (= N M)))
       (or A
           B
           Q
           (not P)
           (not R)
           (not S)
           (not C)
           (and (not J) I H G (not F) E D (= L K) (= N M)))
       (or A
           B
           C
           Q
           (not P)
           (not R)
           (not S)
           (and (not J) I H G (not F) (not E) D (= L K) (= N M)))
       (or B Q S (not P) (not R) (not A) (not C) a!7)
       (or C Q S (not P) (not R) (not A) (not B) a!8)
       (or B C Q S (not P) (not R) (not A) a!9)
       (or A Q S (not P) (not R) (not C) (not B) a!10)
       (or A
           B
           C
           Q
           S
           (not P)
           (not R)
           (and (not J) I H (not G) (not F) (not E) D (= L K) (= N M)))
       (or B
           Q
           R
           (not P)
           (not S)
           (not A)
           (not C)
           (and (not J) I (not H) G F E D (= L K) (= N M)))
       (or A B C P R S (not Q) a!11)
       (or B C Q R (not P) (not S) (not A) a!11)
       (or A Q R (not P) (not S) (not C) (not B) a!12)
       (or A B Q R (not P) (not S) (not C) a!13)
       (or A
           B
           C
           Q
           R
           (not P)
           (not S)
           (and (not J) I (not H) G (not F) (not E) D (= L K) (= N M)))
       (or B
           Q
           R
           S
           (not P)
           (not A)
           (not C)
           (and (not J) I (not H) (not G) F E D (= L K) (= N M)))
       (or A
           B
           Q
           R
           S
           (not P)
           (not C)
           (and (not J) I (not H) (not G) (not F) E D (= L K) (= N M)))
       (or A
           B
           C
           Q
           R
           S
           (not P)
           (and (not J) I (not H) (not G) (not F) (not E) D (= L K) (= N M)))
       (or B C P Q (not R) (not S) (not A) a!14)
       (or A P Q (not R) (not S) (not C) (not B) a!15)
       (or A
           C
           P
           Q
           (not R)
           (not S)
           (not B)
           (and (not J) (not I) H G (not F) E (not D) (= L K) (= N M)))
       (or P
           Q
           S
           (not R)
           (not A)
           (not C)
           (not B)
           (and (not J) (not I) H G (not F) (not E) (not D) (= L K) (= N M)))
       (or B
           C
           P
           Q
           S
           (not R)
           (not A)
           (and (not J) (not I) H (not G) F (not E) D (= L K) (= N M)))
       (or A
           B
           Q
           S
           (not P)
           (not R)
           (not C)
           (and (not J) (not I) H (not G) F (not E) (not D) (= L K) (= N M)))
       (or A
           B
           P
           Q
           S
           (not R)
           (not C)
           (and (not J) (not I) H (not G) (not F) E D (= L K) (= N M)))
       (or A
           B
           C
           P
           Q
           S
           (not R)
           (and (not J) (not I) H (not G) (not F) (not E) D (= L K) (= N M)))
       (or B
           P
           Q
           R
           (not S)
           (not A)
           (not C)
           (and (not J) (not I) (not H) G F E D (= L K) (= N M)))
       (or B C P Q R (not S) (not A) a!16)
       (or A P Q R (not S) (not C) (not B) a!17)
       (or A
           C
           P
           Q
           R
           (not S)
           (not B)
           (and (not J) (not I) (not H) G (not F) E (not D) (= L K) (= N M)))
       (or P
           Q
           R
           S
           (not A)
           (not C)
           (not B)
           (and (not J)
                (not I)
                (not H)
                G
                (not F)
                (not E)
                (not D)
                (= L K)
                (= N M)))
       (or B
           C
           P
           Q
           R
           S
           (not A)
           (and (not J) (not I) (not H) (not G) F (not E) D (= L K) (= N M)))
       (or A
           B
           C
           P
           R
           (not Q)
           (not S)
           (and (not J)
                (not I)
                (not H)
                (not G)
                F
                (not E)
                (not D)
                (= L K)
                (= N M)))
       (or A B C P Q R S a!23)
       (or A B P Q R (not S) (not C) a!23)
       (or A B P Q (not R) (not S) (not C) a!23)
       (or A C Q R (not P) (not S) (not B) a!23)
       (or A P R (not Q) (not S) (not C) (not B) a!23)
       (or C Q (not P) (not R) (not S) (not A) (not B) a!23)
       (or A
           B
           P
           Q
           R
           S
           (not C)
           (and (not J) (not I) (not H) (not G) (not F) E D (= K 0) (= N M)))
       (or A
           C
           P
           Q
           R
           S
           (not B)
           (<= 1 N)
           (and J (not I) (not H) G (not F) E D (= L K) (= N M)))))
      )
      (state E D F G H I J M K)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Bool) (G Bool) (H Bool) (I Bool) ) 
    (=>
      (and
        (state C B A I H F G E D)
        (or (and (not F) (not G) (not H) I (not A) B C)
    (and (not F) (not G) (not H) I A (not B) (not C))
    (and (not F) (not G) H I (not A) B C)
    (and (not F) (not G) H I A (not B) (not C))
    (and (not F) G (not H) (not I) (not A) (not B) C)
    (and (not F) G (not H) (not I) (not A) B (not C))
    (and (not F) G (not H) I (not A) (not B) C)
    (and (not F) G (not H) I (not A) B (not C))
    (and F (not G) (not H) I (not A) (not B) C)
    (and F (not G) (not H) I (not A) B C)
    (and F (not G) H (not I) (not A) B C)
    (and F (not G) H (not I) A (not B) (not C))
    (and F (not G) H (not I) A (not B) C)
    (and F (not G) H (not I) A B (not C))
    (and F (not G) H I A (not B) C)
    (and F (not G) H I A B C))
      )
      false
    )
  )
)

(check-sat)
(exit)
