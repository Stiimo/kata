add_library(calculator
    lib/calculator.h
    lib/calculator.cpp
    lib/calculationerror.h
)
target_include_directories(calculator PUBLIC lib)

add_executable(kata app/main.cpp)
target_link_libraries(kata PRIVATE
calculator
)
