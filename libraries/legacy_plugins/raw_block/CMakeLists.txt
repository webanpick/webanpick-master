file(GLOB HEADERS "include/webanpick/plugins/raw_block/*.hpp")

add_library( webanpick_raw_block
             ${HEADERS}
             raw_block_plugin.cpp
             raw_block_api.cpp
           )

target_link_libraries( webanpick_raw_block webanpick_app webanpick_chain webanpick_protocol fc )
target_include_directories( webanpick_raw_block
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
