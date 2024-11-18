function(convert_to_posix_path input_path output_var)
    if(DEFINED ENV{MSYSTEM})
        execute_process(
                COMMAND cygpath -u ${input_path}
                OUTPUT_VARIABLE converted_path
                OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        set(${output_var} ${converted_path} PARENT_SCOPE)
    else()
        set(${output_var} ${input_path} PARENT_SCOPE)
    endif()
endfunction()