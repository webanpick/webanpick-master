#pragma once

#include <chainbase/chainbase.hpp>

#include <fc/io/datastream.hpp>
#include <fc/io/raw.hpp>

namespace webanpick { namespace chain {

typedef chainbase::bip::vector< char, chainbase::allocator< char > > buffer_type;

} } // webanpick::chain

namespace fc { namespace raw {

template< typename T > inline void pack_to_buffer( webanpick::chain::buffer_type& raw, const T& v )
{
   auto size = pack_size( v );
   raw.resize( size );
   datastream< char* > ds( raw.data(), size );
   pack( ds, v );
}

template< typename T > inline void unpack_from_buffer( const webanpick::chain::buffer_type& raw, T& v )
{
   datastream< const char* > ds( raw.data(), raw.size() );
   unpack( ds, v );
}

template< typename T > inline T unpack_from_buffer( const webanpick::chain::buffer_type& raw )
{
   T v;
   datastream< const char* > ds( raw.data(), raw.size() );
   unpack( ds, v );
   return v;
}

} } // fc::raw

FC_REFLECT_TYPENAME( webanpick::chain::buffer_type )
