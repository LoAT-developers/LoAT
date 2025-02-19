target_sources(${EXECUTABLE}
    PRIVATE
        itsparser.cpp
        itsparser.hpp
        KoatParseVisitor.h
        KoatParseVisitor.cpp
        KoatVisitor.h
        KoatVisitor.cpp
        KoatListener.h
        KoatListener.cpp
        KoatLexer.cpp
        KoatLexer.h
        KoatParser.cpp
        KoatParser.h
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
