# SPDX-FileCopyrightText: (C) The Kokkos-FFT development team, see COPYRIGHT.md file
#
# SPDX-License-Identifier: MIT OR Apache-2.0 WITH LLVM-exception

add_library(common INTERFACE)

target_link_libraries(common
    INTERFACE
    Kokkos::kokkos
)

if(Kokkos_ENABLE_CUDA)
  find_package(CUDAToolkit REQUIRED COMPONENTS cufft)
  target_link_libraries(common INTERFACE CUDA::cufft)
  target_compile_definitions(common INTERFACE KOKKOSFFT_ENABLE_TPL_CUFFT)
  if(KokkosFFT_ENABLE_HOST_AND_DEVICE)
    find_package(FFTW MODULE REQUIRED)
    target_link_libraries(common INTERFACE FFTW::Float FFTW::Double FFTW::FloatOpenMP FFTW::DoubleOpenMP)
    target_compile_definitions(common INTERFACE ENABLE_HOST_AND_DEVICE KOKKOSFFT_ENABLE_TPL_FFTW)
  endif()
elseif(Kokkos_ENABLE_HIP)
  if(KokkosFFT_ENABLE_ROCFFT)
    find_package(rocfft REQUIRED)
    target_link_libraries(common INTERFACE roc::rocfft)
    target_compile_definitions(common INTERFACE KOKKOSFFT_ENABLE_TPL_ROCFFT)
  else()
    find_package(hipfft REQUIRED)
    target_link_libraries(common INTERFACE hip::hipfft)
    target_compile_definitions(common INTERFACE KOKKOSFFT_ENABLE_TPL_HIPFFT)
  endif()
  if(KokkosFFT_ENABLE_HOST_AND_DEVICE)
    find_package(FFTW MODULE REQUIRED)
    target_link_libraries(common INTERFACE FFTW::Float FFTW::Double FFTW::FloatOpenMP FFTW::DoubleOpenMP)
    target_compile_definitions(common INTERFACE ENABLE_HOST_AND_DEVICE KOKKOSFFT_ENABLE_TPL_FFTW)
  endif()
elseif(Kokkos_ENABLE_SYCL)
  find_package(MKL REQUIRED COMPONENTS SYCL)
  target_link_libraries(common INTERFACE MKL::MKL_SYCL)
  target_compile_definitions(common INTERFACE KOKKOSFFT_ENABLE_TPL_ONEMKL)
  if(KokkosFFT_ENABLE_HOST_AND_DEVICE)
    find_package(FFTW MODULE REQUIRED)
    target_link_libraries(common INTERFACE FFTW::Float FFTW::Double FFTW::FloatOpenMP FFTW::DoubleOpenMP)
    target_compile_definitions(common INTERFACE ENABLE_HOST_AND_DEVICE KOKKOSFFT_ENABLE_TPL_FFTW)
  endif()
elseif(Kokkos_ENABLE_OPENMP)
  find_package(FFTW MODULE REQUIRED)
  target_link_libraries(common INTERFACE FFTW::Float FFTW::Double FFTW::FloatOpenMP FFTW::DoubleOpenMP)
  target_compile_definitions(common INTERFACE KOKKOSFFT_ENABLE_TPL_FFTW)
elseif(Kokkos_ENABLE_THREADS)
  find_package(FFTW MODULE REQUIRED)
  target_link_libraries(common INTERFACE FFTW::Float FFTW::Double FFTW::FloatThreads FFTW::DoubleThreads)
  target_compile_definitions(common INTERFACE KOKKOSFFT_ENABLE_TPL_FFTW)
elseif(Kokkos_ENABLE_SERIAL)
  find_package(FFTW MODULE REQUIRED)
  target_link_libraries(common INTERFACE FFTW::Float FFTW::Double)
  target_compile_definitions(common INTERFACE KOKKOSFFT_ENABLE_TPL_FFTW)
endif()

target_compile_features(common INTERFACE cxx_std_17)
target_include_directories(common INTERFACE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:${INSTALL_INCLUDEDIR}>
)