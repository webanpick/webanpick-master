#pragma once

#include <webanpick/chain/util/asset.hpp>
#include <webanpick/chain/webanpick_objects.hpp>

#include <webanpick/protocol/asset.hpp>
#include <webanpick/protocol/config.hpp>
#include <webanpick/protocol/types.hpp>
#include <webanpick/protocol/misc_utilities.hpp>

#include <fc/reflect/reflect.hpp>

#include <fc/uint128.hpp>

namespace webanpick { namespace chain { namespace util {

using webanpick::protocol::asset;
using webanpick::protocol::price;
using webanpick::protocol::share_type;

using fc::uint128_t;

struct comment_reward_context
{
   share_type rshares;
   uint16_t   reward_weight = 0;
   asset      max_sbd;
   uint128_t  total_reward_shares2;
   asset      total_reward_fund_webanpick;
   price      current_webanpick_price;
   protocol::curve_id   reward_curve = protocol::quadratic;
   uint128_t  content_constant = WEBANPICK_CONTENT_CONSTANT_HF0;
};

uint64_t get_rshare_reward( const comment_reward_context& ctx );

inline uint128_t get_content_constant_s()
{
   return WEBANPICK_CONTENT_CONSTANT_HF0; // looking good for posters
}

uint128_t evaluate_reward_curve( const uint128_t& rshares, const protocol::curve_id& curve = protocol::quadratic, const uint128_t& content_constant = WEBANPICK_CONTENT_CONSTANT_HF0 );

inline bool is_comment_payout_dust( const price& p, uint64_t webanpick_payout )
{
   return to_sbd( p, asset( webanpick_payout, WEBANPICK_SYMBOL ) ) < WEBANPICK_MIN_PAYOUT_SBD;
}

} } } // webanpick::chain::util

FC_REFLECT( webanpick::chain::util::comment_reward_context,
   (rshares)
   (reward_weight)
   (max_sbd)
   (total_reward_shares2)
   (total_reward_fund_webanpick)
   (current_webanpick_price)
   (reward_curve)
   (content_constant)
   )
