FROM loat/base:latest
LABEL author="Florian Frohn"

RUN xbps-install -yS boost-devel cln-devel gmp-devel

COPY --from=loat/z3 /usr/local/lib64/libz3.a /usr/local/lib64/
COPY --from=loat/z3 /usr/local/include/z3*.h /usr/local/include/

COPY --from=loat/poly /usr/local/include/poly /usr/local/include/poly
COPY --from=loat/poly /usr/local/lib/libpoly.a /usr/local/lib/

COPY --from=loat/cudd /usr/local/include/cudd.h /usr/local/include/cudd.h
COPY --from=loat/cudd /usr/local/lib/libcudd.a /usr/local/lib/libcudd.a

COPY --from=loat/ntl /usr/local/include/NTL /usr/local/include/NTL
COPY --from=loat/ntl /usr/local/lib/libntl.a /usr/local/lib/libntl.a

COPY --from=loat/yices /usr/local/include/yices*.h /usr/local/include/
COPY --from=loat/yices /usr/local/lib/libyices.a /usr/local/lib/libyices.a

COPY --from=loat/ginac /usr/local/lib64/libginac.a /usr/local/lib64/libginac.a
COPY --from=loat/ginac /usr/local/include/ginac /usr/local/include/ginac

COPY --from=loat/purrs /usr/local/lib/libpurrs.a /usr/local/lib/libpurrs.a
COPY --from=loat/purrs /usr/local/include/purrs.hh /usr/local/include/purrs.hh

COPY --from=loat/antlr4 /usr/local/lib/libantlr4-runtime.a /usr/local/lib/libantlr4-runtime.a
COPY --from=loat/antlr4 /usr/local/include/antlr4-runtime/ /usr/local/include/

COPY --from=loat/faudes /usr/local/lib/libfaudes.a /usr/local/lib/libfaudes.a
COPY --from=loat/faudes /usr/local/include/faudes/ /usr/local/include/
