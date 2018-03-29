#pragma once

#include <webanpick/chain/evaluator.hpp>

#include <webanpick/private_message/private_message_operations.hpp>
#include <webanpick/private_message/private_message_plugin.hpp>

namespace webanpick { namespace private_message {

WEBANPICK_DEFINE_PLUGIN_EVALUATOR( private_message_plugin, webanpick::private_message::private_message_plugin_operation, private_message )

} }
