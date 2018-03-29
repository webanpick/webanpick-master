#pragma once
#include <webanpick/protocol/base.hpp>

#include <webanpick/chain/evaluator.hpp>


namespace webanpick { namespace plugins { namespace follow {

using namespace std;
using webanpick::protocol::account_name_type;
using webanpick::protocol::base_operation;

class follow_plugin;

struct follow_operation : base_operation
{
    account_name_type follower;
    account_name_type following;
    set< string >     what; /// blog, mute

    void validate()const;

    void get_required_posting_authorities( flat_set<account_name_type>& a )const { a.insert( follower ); }
};

struct reblog_operation : base_operation
{
   account_name_type account;
   account_name_type author;
   string            permlink;

   void validate()const;

   void get_required_posting_authorities( flat_set<account_name_type>& a )const { a.insert( account ); }
};

typedef fc::static_variant<
         follow_operation,
         reblog_operation
      > follow_plugin_operation;

WEBANPICK_DEFINE_PLUGIN_EVALUATOR( follow_plugin, follow_plugin_operation, follow );
WEBANPICK_DEFINE_PLUGIN_EVALUATOR( follow_plugin, follow_plugin_operation, reblog );

} } } // webanpick::plugins::follow

FC_REFLECT( webanpick::plugins::follow::follow_operation, (follower)(following)(what) )
FC_REFLECT( webanpick::plugins::follow::reblog_operation, (account)(author)(permlink) )

WEBANPICK_DECLARE_OPERATION_TYPE( webanpick::plugins::follow::follow_plugin_operation )

FC_REFLECT_TYPENAME( webanpick::plugins::follow::follow_plugin_operation )
