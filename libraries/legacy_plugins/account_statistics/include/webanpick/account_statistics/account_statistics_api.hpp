#pragma once

#include <webanpick/account_statistics/account_statistics_plugin.hpp>

#include <fc/api.hpp>

namespace webanpick { namespace app {
   struct api_context;
} }

namespace webanpick { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl;
}

class account_statistics_api
{
   public:
      account_statistics_api( const webanpick::app::api_context& ctx );

      void on_api_startup();

   private:
      std::shared_ptr< detail::account_statistics_api_impl > _my;
};

} } // webanpick::account_statistics

FC_API( webanpick::account_statistics::account_statistics_api, )