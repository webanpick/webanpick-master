file(GLOB HEADERS "include/webanpick/schema/*.hpp")
add_library( webanpick_schema schema.cpp ${HEADERS} )
target_link_libraries( webanpick_schema fc )
target_include_directories( webanpick_schema PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   webanpick_schema

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/webanpick/schema" )
