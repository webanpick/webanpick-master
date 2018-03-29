#ifdef IS_TEST_NET
#include <webanpick/chain/generic_custom_operation_interpreter.hpp>
#include <webanpick/chain/account_object.hpp>

#include <boost/test/unit_test.hpp>

#include "../db_fixture/database_fixture.hpp"

using namespace webanpick::chain;
using namespace webanpick::chain::test;
/*
namespace webanpick { namespace plugin_tests {

using namespace webanpick::app;
using namespace webanpick::chain;

struct test_a_operation : base_operation
{
   string account;

   void validate() { FC_ASSERT( account.size() ); }
};

struct test_b_operation : base_operation
{
   string account;

   void validate() { FC_ASSERT( account.size() ); }
};

typedef fc::static_variant<
   test_a_operation,
   test_b_operation >   test_op;

class test_plugin : public plugin
{
   public:
      test_plugin( application* app );

      std::string plugin_name()const override { return "TEST"; }

      std::shared_ptr< generic_custom_operation_interpreter< test_op > > _evaluator_registry;
};

WEBANPICK_DEFINE_PLUGIN_EVALUATOR( test_plugin, test_a_operation, test_a );
WEBANPICK_DEFINE_PLUGIN_EVALUATOR( test_plugin, test_b_operation, test_b );

void test_a_evaluator::do_apply( const test_a_operation& o )
{
   const auto& account = db().get_account( o.account );

   db().modify( account, [&]( account_object& a )
   {
      a.json_metadata = "a";
   });
}

void test_b_evaluator::do_apply( const test_b_operation& o )
{
   const auto& account = db().get_account( o.account );

   db().modify( account, [&]( account_object& a )
   {
      a.json_metadata = "b";
   });
}

test_plugin::test_plugin( application* app ) : plugin( app )
{
   _evaluator_registry = std::make_shared< generic_custom_operation_interpreter< test_op > >( database() );

   _evaluator_registry->register_evaluator< test_a_evaluator >( *this );
   _evaluator_registry->register_evaluator< test_b_evaluator >( *this );

   database().set_custom_operation_interpreter( plugin_name(), _evaluator_registry );
}

} } // webanpick::plugin_tests

WEBANPICK_DEFINE_PLUGIN( test, webanpick::plugin_tests::test_plugin )

FC_REFLECT( webanpick::plugin_tests::test_a_operation, (account) )
FC_REFLECT( webanpick::plugin_tests::test_b_operation, (account) )

WEBANPICK_DECLARE_OPERATION_TYPE( webanpick::plugin_tests::test_op );
FC_REFLECT_TYPENAME( webanpick::plugin_tests::test_op );
WEBANPICK_DEFINE_OPERATION_TYPE( webanpick::plugin_tests::test_op );
*/

BOOST_FIXTURE_TEST_SUITE( plugin_ops, clean_database_fixture );
/*
BOOST_AUTO_TEST_CASE( custom_json )
{
   try
   {

   }
   FC_LOG_AND_RETHROW()
}

BOOST_AUTO_TEST_CASE( custom_binary )
{
   try
   {

   }
   FC_LOG_AND_RETHROW()
}
*/
BOOST_AUTO_TEST_SUITE_END()
#endif