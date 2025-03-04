GET_TARGET_NAME(CORE "${PROJECT_SOURCE_DIR}/src/core")
ADD_TARGET(
        MODE STATIC
        SOURCE
        "${PROJECT_SOURCE_DIR}/include/_deps/imgui"
        INC
        "include/_deps/imgui"
        LIB
        ${CORE}
)