#ifndef TEST_TYPES_HPP
#define TEST_TYPES_HPP

#include <Kokkos_Complex.hpp>
using execution_space = Kokkos::DefaultExecutionSpace;
template <typename T>
using View1D = Kokkos::View<T*, execution_space>;
template <typename T>
using View2D = Kokkos::View<T**, execution_space>;
template <typename T>
using View3D = Kokkos::View<T***, execution_space>;
template <typename T>
using View4D = Kokkos::View<T****, execution_space>;
template <typename T>
using View5D = Kokkos::View<T*****, execution_space>;
template <typename T>
using View6D = Kokkos::View<T******, execution_space>;
template <typename T>
using View7D = Kokkos::View<T*******, execution_space>;
template <typename T>
using View8D = Kokkos::View<T********, execution_space>;

// Layout Left
template <typename T>
using LeftView2D = Kokkos::View<T**, Kokkos::LayoutLeft, execution_space>;
template <typename T>
using LeftView3D = Kokkos::View<T***, Kokkos::LayoutLeft, execution_space>;

// Layout Right
template <typename T>
using RightView2D = Kokkos::View<T**, Kokkos::LayoutRight, execution_space>;
template <typename T>
using RightView3D = Kokkos::View<T***, Kokkos::LayoutRight, execution_space>;

#endif