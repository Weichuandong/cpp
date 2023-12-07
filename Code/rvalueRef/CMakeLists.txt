set(TARGET_NAME "rvalueRef")

add_executable(${TARGET_NAME}
        "rvalueRef.cpp"
)

target_compile_options(${TARGET_NAME}
        PRIVATE
        -fno-elide-constructors
)
#add_compile_definitions(-fno-elide-constructors)
