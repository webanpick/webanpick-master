#pragma once
#include <webanpick/protocol/block_header.hpp>
#include <webanpick/protocol/transaction.hpp>

namespace webanpick { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // webanpick::protocol

FC_REFLECT_DERIVED( webanpick::protocol::signed_block, (webanpick::protocol::signed_block_header), (transactions) )
