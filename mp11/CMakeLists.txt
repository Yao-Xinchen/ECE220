set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/mp11)

set(TARGET "mp11")
set(SOURCE_FILES
        ece220_lex.yy.c ece220_parse.tab.c ece220_symtab.c ece220_label.c mp11base.c mp11.c)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

add_custom_command(
        OUTPUT ${PROJECT_SOURCE_DIR}/mp11/ece220_lex.yy.c
        COMMAND ${FLEX_EXECUTABLE}
        --outfile=${PROJECT_SOURCE_DIR}/mp11/ece220_lex.yy.c
        --prefix=ece220
        ${CMAKE_CURRENT_SOURCE_DIR}/ece220_lex.f
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/ece220_lex.f ${PROJECT_SOURCE_DIR}/mp11/ece220_parse.tab.h
        COMMENT "Generating ece220_lex.yy.c from ece220_lex.l"
)

add_custom_command(
        OUTPUT ${PROJECT_SOURCE_DIR}/mp11/ece220_parse.tab.c ${PROJECT_SOURCE_DIR}/mp11/ece220_parse.tab.h
        COMMAND ${BISON_EXECUTABLE}
        --defines=${PROJECT_SOURCE_DIR}/mp11/ece220_parse.tab.h
        --output=${PROJECT_SOURCE_DIR}/mp11/ece220_parse.tab.c
        --name-prefix=ece220
        ${CMAKE_CURRENT_SOURCE_DIR}/ece220_parse.y
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/ece220_parse.y
        COMMENT "Generating ece220_parse.tab.c and ece220_parse.tab.h from ece220_parse.y"
)

add_executable(${TARGET} ${SOURCE_FILES} ${BISON_parser_OUTPUTS} ${FLEX_lexer_OUTPUTS})
target_link_libraries(${TARGET} ${FLEX_LIBRARIES} ${BISON_LIBRARIES})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})