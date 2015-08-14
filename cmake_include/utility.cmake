macro(cpy_dir source distination)
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${source}
    ${distination}
)
endmacro (cpy_dir)
