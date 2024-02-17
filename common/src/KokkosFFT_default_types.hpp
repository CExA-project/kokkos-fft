#ifndef KOKKOSFFT_DEFAULT_TYPES_HPP
#define KOKKOSFFT_DEFAULT_TYPES_HPP

#include <Kokkos_Core.hpp>

#if defined(KOKKOS_ENABLE_CUDA)
#include "KokkosFFT_Cuda_types.hpp"
#elif defined(KOKKOS_ENABLE_HIP)
#include "KokkosFFT_HIP_types.hpp"
#elif defined(KOKKOS_ENABLE_SYCL)
#include "KokkosFFT_SYCL_types.hpp"
#elif defined(KOKKOS_ENABLE_OPENMP)
#include "KokkosFFT_OpenMP_types.hpp"
#elif defined(KOKKOS_ENABLE_THREADS)
#include "KokkosFFT_OpenMP_types.hpp"
#else
#include "KokkosFFT_OpenMP_types.hpp"
#endif

#include "KokkosFFT_utils.hpp"

namespace KokkosFFT {
namespace Impl {
// Define fft data types
template <typename ExecutionSpace, typename T>
struct fft_data_type {
  using type = std::conditional_t<
      std::is_same_v<T, float>,
      typename KokkosFFT::Impl::FFTDataType<ExecutionSpace>::float32,
      typename KokkosFFT::Impl::FFTDataType<ExecutionSpace>::float64>;
};

template <typename ExecutionSpace, typename T>
struct fft_data_type<ExecutionSpace, Kokkos::complex<T>> {
  using type = std::conditional_t<
      std::is_same_v<T, float>,
      typename KokkosFFT::Impl::FFTDataType<ExecutionSpace>::complex64,
      typename KokkosFFT::Impl::FFTDataType<ExecutionSpace>::complex128>;
};
}  // namespace Impl
}  // namespace KokkosFFT

#endif