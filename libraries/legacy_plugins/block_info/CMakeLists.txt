file(GLOB HEADERS "include/webanpick/plugins/block_info/*.hpp")

add_library( webanpick_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( webanpick_block_info webanpick_app webanpick_chain webanpick_protocol fc )
target_include_directories( webanpick_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
