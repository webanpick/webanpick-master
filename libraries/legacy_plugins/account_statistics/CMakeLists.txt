file(GLOB HEADERS "include/webanpick/account_statistics/*.hpp")

add_library( webanpick_account_statistics
             account_statistics_plugin.cpp
             account_statistics_api.cpp
           )

target_link_libraries( webanpick_account_statistics webanpick_chain webanpick_protocol webanpick_app )
target_include_directories( webanpick_account_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   webanpick_account_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)