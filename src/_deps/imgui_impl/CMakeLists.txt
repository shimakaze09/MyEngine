ADD_TARGET(
        MODE STATIC
        LIB
        glfw
        My::MyGL__deps_glad
        INC
        "include/_deps/detail"
        "include/_deps/imgui"
)