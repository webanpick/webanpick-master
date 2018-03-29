file(GLOB HEADERS "include/webanpick/blockchain_statistics/*.hpp")

add_library( webanpick_blockchain_statistics
             blockchain_statistics_plugin.cpp
             blockchain_statistics_api.cpp
           )

target_link_libraries( webanpick_blockchain_statistics webanpick_chain webanpick_protocol webanpick_app )
target_include_directories( webanpick_blockchain_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   webanpick_blockchain_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)