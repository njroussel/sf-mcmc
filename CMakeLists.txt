cmake_minimum_required(VERSION 3.0)
project(sf-mcmc)

find_package(Threads)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
add_subdirectory(ext ext_build)

include_directories(
    # Include files
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    # Pseudorandom number generator
    ${PCG32_INCLUDE_DIR}
    # Python bindings
    ${PYBIND11_INCLUDE_DIR}
    # Eigen
    ${EIGEN_INCLUDE_DIR}
    )

pybind11_add_module(sf-mcmc
    # Header files
    include/sf-mcmc/constant.h
    include/sf-mcmc/contexponential.h
    include/sf-mcmc/contlinear.h
    include/sf-mcmc/contlogarithmic.h
    include/sf-mcmc/contpolynomial.h
    include/sf-mcmc/common.h
    include/sf-mcmc/helpers.h
    include/sf-mcmc/mcmc.h
    include/sf-mcmc/multicompetition.h
    include/sf-mcmc/multimcmc.h
    include/sf-mcmc/sampler.h
    include/sf-mcmc/runner.h

    # Source files
    src/helpers.cpp
    src/sampler.cpp
    src/mcmc.cpp
    src/runner.cpp
    src/multimcmc.cpp
    src/multicompetition.cpp
    src/main.cpp
    )
