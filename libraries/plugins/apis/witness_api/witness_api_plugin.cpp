#include <webanpick/plugins/witness_api/witness_api_plugin.hpp>
#include <webanpick/plugins/witness_api/witness_api.hpp>


namespace webanpick { namespace plugins { namespace witness {

witness_api_plugin::witness_api_plugin() {}
witness_api_plugin::~witness_api_plugin() {}

void witness_api_plugin::set_program_options( options_description& cli, options_description& cfg ) {}

void witness_api_plugin::plugin_initialize( const variables_map& options )
{
   api = std::make_shared< witness_api >();
}

void witness_api_plugin::plugin_startup() {}
void witness_api_plugin::plugin_shutdown() {}

} } } // webanpick::plugins::witness
