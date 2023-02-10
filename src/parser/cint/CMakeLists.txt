target_sources(${EXECUTABLE}
    PRIVATE
        CINTParseVisitor.cpp
        CINTParseVisitor.h
        CINTLexer.cpp
        CINTLexer.h
        CINTListener.cpp
        CINTListener.h
        CINTParser.cpp
        CINTParser.h
        CINTVisitor.cpp
        CINTVisitor.h
        cintparser.cpp
        cintparser.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
