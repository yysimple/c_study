cmake_minimum_required(VERSION 3.21)
project(c_study C)

set(CMAKE_C_STANDARD 99)

add_executable(c_study main.c
        type/type.c type/type.h
        constant/constant.c constant/constant.h
        cal/cal.c cal/cal.h
        arr/array.c arr/array.h
        enum/enum.c enum/enum.h
        point/point.c point/point.h
        str/str.c str/str.h
        struct/struct.c struct/struct.h
        file/file.c file/file.h
        predefine/pre.c predefine/pre.h
        error/error.c error/error.h
        test/net/domian_analysis.c test/net/domian_analysis.h
        test/util/dns_util.c test/util/dns_util.h)
