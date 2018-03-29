#pragma once

#include <fc/container/flat.hpp>
#include <webanpick/protocol/operations.hpp>
#include <webanpick/protocol/transaction.hpp>

#include <fc/string.hpp>

namespace webanpick { namespace app {

using namespace fc;

void operation_get_impacted_accounts(
   const webanpick::protocol::operation& op,
   fc::flat_set<protocol::account_name_type>& result );

void transaction_get_impacted_accounts(
   const webanpick::protocol::transaction& tx,
   fc::flat_set<protocol::account_name_type>& result
   );

} } // webanpick::app
