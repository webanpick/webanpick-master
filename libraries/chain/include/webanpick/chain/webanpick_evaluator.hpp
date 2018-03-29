#pragma once

#include <webanpick/protocol/webanpick_operations.hpp>

#include <webanpick/chain/evaluator.hpp>

namespace webanpick { namespace chain {

using namespace webanpick::protocol;

WEBANPICK_DEFINE_EVALUATOR( account_create )
WEBANPICK_DEFINE_EVALUATOR( account_create_with_delegation )
WEBANPICK_DEFINE_EVALUATOR( account_update )
WEBANPICK_DEFINE_EVALUATOR( transfer )
WEBANPICK_DEFINE_EVALUATOR( transfer_to_vesting )
WEBANPICK_DEFINE_EVALUATOR( witness_update )
WEBANPICK_DEFINE_EVALUATOR( account_witness_vote )
WEBANPICK_DEFINE_EVALUATOR( account_witness_proxy )
WEBANPICK_DEFINE_EVALUATOR( withdraw_vesting )
WEBANPICK_DEFINE_EVALUATOR( set_withdraw_vesting_route )
WEBANPICK_DEFINE_EVALUATOR( comment )
WEBANPICK_DEFINE_EVALUATOR( comment_options )
WEBANPICK_DEFINE_EVALUATOR( delete_comment )
WEBANPICK_DEFINE_EVALUATOR( vote )
WEBANPICK_DEFINE_EVALUATOR( custom )
WEBANPICK_DEFINE_EVALUATOR( custom_json )
WEBANPICK_DEFINE_EVALUATOR( custom_binary )
WEBANPICK_DEFINE_EVALUATOR( pow )
WEBANPICK_DEFINE_EVALUATOR( pow2 )
WEBANPICK_DEFINE_EVALUATOR( feed_publish )
WEBANPICK_DEFINE_EVALUATOR( convert )
WEBANPICK_DEFINE_EVALUATOR( limit_order_create )
WEBANPICK_DEFINE_EVALUATOR( limit_order_cancel )
WEBANPICK_DEFINE_EVALUATOR( report_over_production )
WEBANPICK_DEFINE_EVALUATOR( limit_order_create2 )
WEBANPICK_DEFINE_EVALUATOR( escrow_transfer )
WEBANPICK_DEFINE_EVALUATOR( escrow_approve )
WEBANPICK_DEFINE_EVALUATOR( escrow_dispute )
WEBANPICK_DEFINE_EVALUATOR( escrow_release )
WEBANPICK_DEFINE_EVALUATOR( placeholder_a )
WEBANPICK_DEFINE_EVALUATOR( placeholder_b )
WEBANPICK_DEFINE_EVALUATOR( request_account_recovery )
WEBANPICK_DEFINE_EVALUATOR( recover_account )
WEBANPICK_DEFINE_EVALUATOR( change_recovery_account )
WEBANPICK_DEFINE_EVALUATOR( transfer_to_savings )
WEBANPICK_DEFINE_EVALUATOR( transfer_from_savings )
WEBANPICK_DEFINE_EVALUATOR( cancel_transfer_from_savings )
WEBANPICK_DEFINE_EVALUATOR( decline_voting_rights )
WEBANPICK_DEFINE_EVALUATOR( reset_account )
WEBANPICK_DEFINE_EVALUATOR( set_reset_account )
WEBANPICK_DEFINE_EVALUATOR( claim_reward_balance )
#ifdef WEBANPICK_ENABLE_SMT
WEBANPICK_DEFINE_EVALUATOR( claim_reward_balance2 )
#endif
WEBANPICK_DEFINE_EVALUATOR( delegate_vesting_shares )
WEBANPICK_DEFINE_EVALUATOR( witness_set_properties )
#ifdef WEBANPICK_ENABLE_SMT
WEBANPICK_DEFINE_EVALUATOR( smt_setup )
WEBANPICK_DEFINE_EVALUATOR( smt_cap_reveal )
WEBANPICK_DEFINE_EVALUATOR( smt_refund )
WEBANPICK_DEFINE_EVALUATOR( smt_setup_emissions )
WEBANPICK_DEFINE_EVALUATOR( smt_set_setup_parameters )
WEBANPICK_DEFINE_EVALUATOR( smt_set_runtime_parameters )
WEBANPICK_DEFINE_EVALUATOR( smt_create )
#endif

} } // webanpick::chain
