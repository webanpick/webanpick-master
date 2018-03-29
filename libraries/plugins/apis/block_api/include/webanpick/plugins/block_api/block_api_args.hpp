#pragma once
#include <webanpick/plugins/block_api/block_api_objects.hpp>

#include <webanpick/protocol/types.hpp>
#include <webanpick/protocol/transaction.hpp>
#include <webanpick/protocol/block_header.hpp>

#include <webanpick/plugins/json_rpc/utility.hpp>

namespace webanpick { namespace plugins { namespace block_api {

/* get_block_header */

struct get_block_header_args
{
   uint32_t block_num;
};

struct get_block_header_return
{
   optional< block_header > header;
};

/* get_block */
struct get_block_args
{
   uint32_t block_num;
};

struct get_block_return
{
   optional< api_signed_block_object > block;
};

} } } // webanpick::block_api

FC_REFLECT( webanpick::plugins::block_api::get_block_header_args,
   (block_num) )

FC_REFLECT( webanpick::plugins::block_api::get_block_header_return,
   (header) )

FC_REFLECT( webanpick::plugins::block_api::get_block_args,
   (block_num) )

FC_REFLECT( webanpick::plugins::block_api::get_block_return,
   (block) )

