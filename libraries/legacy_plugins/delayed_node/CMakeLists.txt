file(GLOB HEADERS "include/webanpick/delayed_node/*.hpp")

add_library( webanpick_delayed_node
             delayed_node_plugin.cpp
           )

target_link_libraries( webanpick_delayed_node webanpick_chain webanpick_protocol webanpick_app )
target_include_directories( webanpick_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   webanpick_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
