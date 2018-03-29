#include <webanpick/plugins/follow/follow_operations.hpp>

#include <webanpick/protocol/operation_util_impl.hpp>

namespace webanpick { namespace plugins{ namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } } //webanpick::plugins::follow

WEBANPICK_DEFINE_OPERATION_TYPE( webanpick::plugins::follow::follow_plugin_operation )
