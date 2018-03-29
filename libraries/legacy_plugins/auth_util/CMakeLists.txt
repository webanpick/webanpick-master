file(GLOB HEADERS "include/webanpick/plugins/auth_util/*.hpp")

add_library( webanpick_auth_util
             ${HEADERS}
             auth_util_plugin.cpp
             auth_util_api.cpp
           )

target_link_libraries( webanpick_auth_util webanpick_app webanpick_chain webanpick_protocol fc )
target_include_directories( webanpick_auth_util
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
