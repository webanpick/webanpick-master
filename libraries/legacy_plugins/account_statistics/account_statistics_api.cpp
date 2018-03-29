#include <webanpick/account_statistics/account_statistics_api.hpp>

namespace webanpick { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl
   {
      public:
         account_statistics_api_impl( webanpick::app::application& app )
            :_app( app ) {}

         webanpick::app::application& _app;
   };
} // detail

account_statistics_api::account_statistics_api( const webanpick::app::api_context& ctx )
{
   _my= std::make_shared< detail::account_statistics_api_impl >( ctx.app );
}

void account_statistics_api::on_api_startup() {}

} } // webanpick::account_statistics