add_executable( webanpickd main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling webanpickd with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( WEBANPICK_STATIC_BUILD )
   target_link_libraries( webanpickd PRIVATE
      "-static-libstdc++ -static-libgcc"
      appbase
      webanpick_utilities
      webanpick_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
else( WEBANPICK_STATIC_BUILD )
   target_link_libraries( webanpickd PRIVATE
      appbase
      webanpick_utilities
      webanpick_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
endif( WEBANPICK_STATIC_BUILD )

if( CLANG_TIDY_EXE )
   set_target_properties(
      webanpickd PROPERTIES
      CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
   )
endif( CLANG_TIDY_EXE )

install( TARGETS
   webanpickd

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
