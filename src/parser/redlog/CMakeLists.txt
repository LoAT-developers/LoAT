target_sources(${EXECUTABLE}
    PRIVATE
        redlogVisitor.h
        redlogVisitor.cpp
        redlogListener.h
        redlogListener.cpp
        redlogparsevisitor.h
        redlogparsevisitor.cpp
        redlogLexer.h
        redlogLexer.cpp
        redlogParser.h
        redlogParser.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
