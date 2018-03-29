file(GLOB HEADERS "include/webanpick/private_message/*.hpp")

add_library( webanpick_private_message
             private_message_plugin.cpp
           )

target_link_libraries( webanpick_private_message webanpick_chain webanpick_protocol webanpick_app )
target_include_directories( webanpick_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   webanpick_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
