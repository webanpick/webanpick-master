#pragma once

#include <webanpick/protocol/asset.hpp>

namespace webanpick { namespace chain { namespace util {

using webanpick::protocol::asset;
using webanpick::protocol::price;

inline asset to_sbd( const price& p, const asset& webanpick )
{
   FC_ASSERT( webanpick.symbol == WEBANPICK_SYMBOL );
   if( p.is_null() )
      return asset( 0, SBD_SYMBOL );
   return webanpick * p;
}

inline asset to_webanpick( const price& p, const asset& sbd )
{
   FC_ASSERT( sbd.symbol == SBD_SYMBOL );
   if( p.is_null() )
      return asset( 0, WEBANPICK_SYMBOL );
   return sbd * p;
}

} } }
