; ./prepared/vmt/./ctigar/sendmail-mime-fromqp.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Bool) (I Bool) ) 
    (=>
      (and
        (and (not C) (not B) (= A true) (not I) (not H) (not D))
      )
      (state D A B C I H E F G)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Bool) (S Bool) ) 
    (=>
      (and
        (state D A B C S R L N P)
        (let ((a!1 (and J (not I) (not H) G F E (= L K) (= N M) (= P O)))
      (a!2 (and J (not I) (not H) (not G) F E (= L K) (= N M) (= P O)))
      (a!3 (and J
                (not I)
                (not H)
                (not G)
                (not F)
                (not E)
                (= L K)
                (= N M)
                (= P O)))
      (a!4 (and (not J) I H G F E (= L K) (= N M) (= P O)))
      (a!5 (and (not J) (not I) H (not G) F E (= L K) (= N M) (= P O)))
      (a!6 (and (not J) (not I) (not H) G F E (= L K) (= N M) (= P O)))
      (a!7 (and (not J)
                (not I)
                (not H)
                (not G)
                F
                (not E)
                (= L K)
                (= N M)
                (= P O)))
      (a!8 (and (not J)
                (not I)
                (not H)
                (not G)
                (not F)
                E
                (= L K)
                (= N M)
                (= P O)))
      (a!9 (and J
                (not I)
                H
                (not G)
                (not F)
                (not E)
                (= N M)
                (= P O)
                (= (+ L (* (- 1) K)) (- 1))))
      (a!10 (and (not J)
                 I
                 H
                 (not G)
                 F
                 (not E)
                 (= N M)
                 (= P O)
                 (= (+ L (* (- 1) K)) (- 1))))
      (a!11 (and J
                 (not I)
                 (not H)
                 G
                 (not F)
                 E
                 (= L K)
                 (= P O)
                 (= (+ N (* (- 1) M)) (- 1))))
      (a!12 (and (not J)
                 I
                 (not H)
                 G
                 F
                 E
                 (= L K)
                 (= P O)
                 (= (+ N (* (- 1) M)) (- 1))))
      (a!13 (and (not J) I H (not G) F E (= L K) (= N M) (= P O)))
      (a!14 (and (not J)
                 (not I)
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (= L K)
                 (= N M)
                 (= P O))))
  (and (or B
           D
           S
           (not R)
           (not C)
           (not A)
           (= Q 0)
           (and J (not I) H G (not F) E (= L K) (= N M) (= P O)))
       (or A
           B
           C
           S
           (not R)
           (not D)
           (not (<= P L))
           (and J (not I) H G (not F) (not E) (= L K) (= N M) (= P O)))
       (or B
           D
           S
           (not R)
           (not C)
           (not A)
           (not (= Q 0))
           (and J (not I) H (not G) (not F) E (= L K) (= N M) (= P O)))
       (or A C D S (not R) (not B) (<= 0 N) a!1)
       (or A
           C
           D
           S
           (not R)
           (not B)
           (not (<= 0 N))
           (and J (not I) (not H) G F (not E) (= L K) (= N M) (= P O)))
       (or C
           D
           R
           S
           (not B)
           (not A)
           (= Q 0)
           (and J (not I) (not H) G (not F) (not E) (= L K) (= N M) (= P O)))
       (or A C S (not R) (not B) (not D) (not (<= P N)) a!2)
       (or A
           B
           C
           S
           (not R)
           (not D)
           (<= P L)
           (and J (not I) (not H) (not G) F (not E) (= L K) (= N M) (= P O)))
       (or A B D R (not S) (not C) (<= 0 N) a!3)
       (or A B R (not S) (not C) (not D) (not (<= P N)) a!4)
       (or A
           C
           R
           (not S)
           (not B)
           (not D)
           (not (<= P L))
           (and (not J) I H G F (not E) (= L K) (= N M) (= P O)))
       (or A
           B
           R
           (not S)
           (not C)
           (not D)
           (<= P N)
           (and (not J) I H G (not F) E (= L K) (= N M) (= P O)))
       (or R
           S
           (not C)
           (not B)
           (not D)
           (not A)
           (= Q 0)
           (and (not J) I H G (not F) (not E) (= L K) (= N M) (= P O)))
       (or B
           C
           R
           (not S)
           (not D)
           (not A)
           (= Q 0)
           (and (not J) I (not H) G F (not E) (= L K) (= N M) (= P O)))
       (or A
           B
           D
           R
           (not S)
           (not C)
           (not (<= 0 N))
           (and (not J) I (not H) G (not F) E (= L K) (= N M) (= P O)))
       (or B
           C
           R
           (not S)
           (not D)
           (not A)
           (not (= Q 0))
           (and (not J) I (not H) (not G) F (not E) (= L K) (= N M) (= P O)))
       (or A
           C
           R
           (not S)
           (not B)
           (not D)
           (<= P L)
           (and (not J) I (not H) (not G) (not F) E (= L K) (= N M) (= P O)))
       (or R
           S
           (not C)
           (not B)
           (not D)
           (not A)
           (not (= Q 0))
           (and (not J)
                I
                (not H)
                (not G)
                (not F)
                (not E)
                (= L K)
                (= N M)
                (= P O)))
       (or A
           C
           R
           S
           (not B)
           (not D)
           (= Q 0)
           (and (not J) (not I) H G F E (= L K) (= N M) (= P O)))
       (or A
           C
           R
           S
           (not B)
           (not D)
           (not (= Q 0))
           (and (not J) (not I) H G F (not E) (= L K) (= N M) (= P O)))
       (or A
           B
           R
           S
           (not C)
           (not D)
           (<= P N)
           (and (not J) (not I) H G (not F) E (= L K) (= N M) (= P O)))
       (or A
           B
           C
           R
           S
           (not D)
           (not (<= P 0))
           (and (not J) (not I) H G (not F) (not E) (= L K) (= N M) (= P O)))
       (or A B D R S (not C) (<= 0 N) a!5)
       (or C
           D
           R
           S
           (not B)
           (not A)
           (not (= Q 0))
           (and (not J) (not I) H (not G) F (not E) (= L K) (= N M) (= P O)))
       (or A B R S (not C) (not D) (not (<= P N)) a!6)
       (or A
           C
           D
           R
           S
           (not B)
           (not (= Q 0))
           (and (not J) (not I) (not H) G F (not E) (= L K) (= N M) (= P O)))
       (or A
           B
           D
           R
           S
           (not C)
           (not (<= 0 N))
           (and (not J) (not I) (not H) G (not F) E (= L K) (= N M) (= P O)))
       (or A B C R S (not D) (<= P 0) a!7)
       (or A C D R S (not B) (= Q 0) a!8)
       (or B C D S (not R) (not A) a!9)
       (or C D R (not S) (not B) (not A) a!10)
       (or A B D S (not R) (not C) a!11)
       (or A D R (not S) (not C) (not B) a!12)
       (or C
           D
           S
           (not R)
           (not B)
           (not A)
           (and J (not I) H (not G) F (not E) (= L K) (= N M) (= P O)))
       (or D S (not R) (not C) (not B) (not A) a!1)
       (or A D S (not R) (not C) (not B) a!2)
       (or C
           S
           (not R)
           (not B)
           (not D)
           (not A)
           (and J (not I) (not H) (not G) (not F) E (= L K) (= N M) (= P O)))
       (or A B C D S (not R) a!3)
       (or R (not S) (not C) (not B) (not D) (not A) a!4)
       (or B S (not R) (not C) (not D) (not A) a!13)
       (or D R (not S) (not C) (not B) (not A) a!13)
       (or B
           D
           R
           (not S)
           (not C)
           (not A)
           (and (not J) I H (not G) (not F) E (= L K) (= N M) (= P O)))
       (or B
           R
           (not S)
           (not C)
           (not D)
           (not A)
           (and (not J) I (not H) (not G) F E (= L K) (= N M) (= P O)))
       (or A R S (not C) (not B) (not D) a!5)
       (or B
           D
           R
           S
           (not C)
           (not A)
           (and (not J) (not I) H (not G) (not F) E (= L K) (= N M) (= P O)))
       (or D R S (not C) (not B) (not A) a!6)
       (or B
           R
           S
           (not C)
           (not D)
           (not A)
           (and (not J) (not I) (not H) (not G) F E (= L K) (= N M) (= P O)))
       (or A B C R (not S) (not D) a!7)
       (or A R (not S) (not C) (not B) (not D) a!7)
       (or A B S (not R) (not C) (not D) a!8)
       (or A C D R (not S) (not B) a!8)
       (or B C S (not R) (not D) (not A) a!8)
       (or C R S (not B) (not D) (not A) a!8)
       (or C R (not S) (not B) (not D) (not A) a!8)
       (or A B C D R S a!14)
       (or A D R S (not C) (not B) a!14)
       (or B C R S (not D) (not A) a!14)
       (or B
           C
           D
           R
           (not S)
           (not A)
           (and (not J) I H (not G) (not F) (not E) (= K 0) (= N M) (= P O)))
       (or A
           B
           C
           D
           R
           (not S)
           (and (not J) I (not H) G (not F) (not E) (= M 0) (= L K) (= P O)))
       (or B
           C
           D
           R
           S
           (not A)
           (and (not J)
                (not I)
                H
                (not G)
                (not F)
                (not E)
                (= M 0)
                (= K 0)
                (= P O)))
       (or A
           C
           S
           (not R)
           (not B)
           (not D)
           (<= P N)
           (and J (not I) H G F (not E) (= L K) (= N M) (= P O)))))
      )
      (state H G F E I J K M O)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Bool) (I Bool) ) 
    (=>
      (and
        (state D A B C I H E F G)
        (or (and (not H) (not I) (not A) B C D)
    (and (not H) (not I) A B C (not D))
    (and (not H) I A B C D)
    (and H (not I) (not A) (not B) (not C) (not D))
    (and H (not I) (not A) B C (not D))
    (and H (not I) A B C (not D)))
      )
      false
    )
  )
)

(check-sat)
(exit)
