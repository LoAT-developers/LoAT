; ./vmt/./ctigar/MADWiFi-encode_ie_ok.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Bool) (J Bool) (K Bool) ) 
    (=>
      (and
        (and (not A) (not K) (not J) (not I) (= B true))
      )
      (state A B K I J H G F E D C)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) ) 
    (=>
      (and
        (state A B V T U S Q O M K I)
        (let ((a!1 (and G
                (not F)
                E
                D
                (not C)
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
      (a!2 (not (<= (- 1) (+ S (* (- 1) O)))))
      (a!3 (and G
                (not F)
                E
                (not D)
                C
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
      (a!4 (or A
               B
               T
               V
               (not U)
               (<= (- 1) (+ S (* (- 1) O)))
               (and G
                    (not F)
                    (not E)
                    (not D)
                    C
                    (= I H)
                    (= K J)
                    (= M L)
                    (= O N)
                    (= Q P)
                    (= S R))))
      (a!5 (not (<= 0 (+ Q (* (- 2) K)))))
      (a!6 (or B
               U
               V
               (not T)
               (not A)
               (<= 0 (+ Q (* (- 2) K)))
               (and (not G)
                    F
                    (not E)
                    D
                    C
                    (= I H)
                    (= K J)
                    (= M L)
                    (= O N)
                    (= Q P)
                    (= S R))))
      (a!7 (or A
               U
               (not T)
               (not V)
               (not B)
               (and (not (<= K I)) (not (<= Q 2)))
               (and G
                    (not F)
                    E
                    D
                    C
                    (= I H)
                    (= K J)
                    (= M L)
                    (= O N)
                    (= Q P)
                    (= S R))))
      (a!8 (and G
                (not F)
                E
                (not D)
                (not C)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= (+ I (* (- 1) H)) (- 1))))
      (a!9 (and (not G)
                F
                (not E)
                (not D)
                C
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= S R)
                (= (+ Q (* (- 1) P) (* (- 1) M)) 0)))
      (a!10 (and (not G)
                 F
                 (not E)
                 D
                 (not C)
                 (= I H)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= (+ S (* (- 1) R) M) 0)))
      (a!11 (and G
                 (not F)
                 (not E)
                 D
                 C
                 (= I H)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= (+ S (* (- 1) R)) (- 2))))
      (a!12 (and (not G)
                 (not F)
                 (not E)
                 (not D)
                 (not C)
                 (= I H)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= S R))))
  (and (or A
           T
           U
           V
           (not B)
           (not (<= M 0))
           (and G
                F
                (not E)
                D
                (not C)
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or B
           T
           U
           V
           (not A)
           (not (<= Q 0))
           (and G
                F
                (not E)
                (not D)
                C
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or T
           U
           V
           (not A)
           (not B)
           (not (<= K 0))
           (and G
                F
                (not E)
                (not D)
                (not C)
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or B U (not T) (not V) (not A) (<= 0 S) a!1)
       (or A B T V (not U) a!2 a!3)
       a!4
       (or B
           U
           (not T)
           (not V)
           (not A)
           (not (<= 0 S))
           (and (not G) F E D C (= I H) (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or B
           U
           V
           (not T)
           (not A)
           a!5
           (and (not G)
                F
                E
                (not D)
                (not C)
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       a!6
       (or A
           B
           T
           U
           (not V)
           (not (<= M Q))
           (and (not G)
                (not F)
                E
                D
                (not C)
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           B
           T
           U
           (not V)
           (<= M Q)
           (and (not G)
                (not F)
                E
                (not D)
                C
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or T
           U
           V
           (not A)
           (not B)
           (<= K 0)
           (and (not G)
                (not F)
                E
                (not D)
                (not C)
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or B
           T
           U
           V
           (not A)
           (<= Q 0)
           (and (not G)
                (not F)
                (not E)
                D
                C
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           T
           U
           V
           (not B)
           (<= M 0)
           (and (not G)
                (not F)
                (not E)
                D
                (not C)
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       a!7
       (or T V (not U) (not A) (not B) a!8)
       (or T
           U
           (not V)
           (not A)
           (not B)
           (and (not G)
                F
                (not E)
                (not D)
                (not C)
                (= I H)
                (= K J)
                (= M L)
                (= Q P)
                (= Q N)
                (= S R)))
       (or A B U V (not T) a!9)
       (or A U V (not T) (not B) a!10)
       (or B T V (not U) (not A) a!11)
       (or B T (not U) (not V) (not A) a!1)
       (or A T (not U) (not V) (not B) a!3)
       (or A
           T
           V
           (not U)
           (not B)
           (and G
                (not F)
                (not E)
                D
                (not C)
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or U
           (not T)
           (not V)
           (not A)
           (not B)
           (and G
                (not F)
                (not E)
                (not D)
                (not C)
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           B
           T
           (not U)
           (not V)
           (and (not G)
                F
                E
                (not D)
                C
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A B T U V a!12)
       (or A B V (not U) (not T) a!12)
       (or A T U (not V) (not B) a!12)
       (or A V (not U) (not T) (not B) a!12)
       (or B V (not U) (not T) (not A) a!12)
       (or T (not U) (not V) (not A) (not B) a!12)
       (or U V (not T) (not A) (not B) a!12)
       (or A
           B
           U
           (not T)
           (not V)
           (and (not G)
                F
                E
                (not D)
                C
                (= H 0)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or B
           T
           U
           (not V)
           (not A)
           (and (not G)
                (not F)
                E
                D
                C
                (= R 0)
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)))
       (or A
           U
           (not T)
           (not V)
           (not B)
           (<= K I)
           (<= Q 2)
           (and (not G)
                F
                E
                D
                (not C)
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))))
      )
      (state D C E F G R P N L J H)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Bool) (J Bool) (K Bool) ) 
    (=>
      (and
        (state A B K I J H G F E D C)
        (or (and (not I) J K (not A) B) (and (not I) J K A (not B)))
      )
      false
    )
  )
)

(check-sat)
(exit)
