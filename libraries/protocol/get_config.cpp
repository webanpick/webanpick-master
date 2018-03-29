#include <webanpick/protocol/get_config.hpp>
#include <webanpick/protocol/config.hpp>
#include <webanpick/protocol/asset.hpp>
#include <webanpick/protocol/types.hpp>
#include <webanpick/protocol/version.hpp>

namespace webanpick { namespace protocol {

fc::variant_object get_config()
{
   fc::mutable_variant_object result;

#ifdef IS_TEST_NET
   result[ "IS_TEST_NET" ] = true;
   result["TESTNET_BLOCK_LIMIT"] = TESTNET_BLOCK_LIMIT;
#else
   result[ "IS_TEST_NET" ] = false;
#endif
#ifdef WEBANPICK_ENABLE_SMT
   result[ "WEBANPICK_ENABLE_SMT" ] = true;
   result["SMT_VESTING_WITHDRAW_INTERVAL_SECONDS"] = SMT_VESTING_WITHDRAW_INTERVAL_SECONDS;
   result["SMT_UPVOTE_LOCKOUT"] = SMT_UPVOTE_LOCKOUT;
   result["SMT_MAX_VOTABLE_ASSETS"] = SMT_MAX_VOTABLE_ASSETS;
#else
   result[ "WEBANPICK_ENABLE_SMT" ] = false;
#endif

   result["SBD_SYMBOL"] = SBD_SYMBOL;
   result["WEBANPICK_INITIAL_VOTE_POWER_RATE"] = WEBANPICK_INITIAL_VOTE_POWER_RATE;
   result["WEBANPICK_REDUCED_VOTE_POWER_RATE"] = WEBANPICK_REDUCED_VOTE_POWER_RATE;
   result["WEBANPICK_100_PERCENT"] = WEBANPICK_100_PERCENT;
   result["WEBANPICK_1_PERCENT"] = WEBANPICK_1_PERCENT;
   result["WEBANPICK_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD"] = WEBANPICK_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD;
   result["WEBANPICK_ACTIVE_CHALLENGE_COOLDOWN"] = WEBANPICK_ACTIVE_CHALLENGE_COOLDOWN;
   result["WEBANPICK_ACTIVE_CHALLENGE_FEE"] = WEBANPICK_ACTIVE_CHALLENGE_FEE;
   result["WEBANPICK_ADDRESS_PREFIX"] = WEBANPICK_ADDRESS_PREFIX;
   result["WEBANPICK_APR_PERCENT_MULTIPLY_PER_BLOCK"] = WEBANPICK_APR_PERCENT_MULTIPLY_PER_BLOCK;
   result["WEBANPICK_APR_PERCENT_MULTIPLY_PER_HOUR"] = WEBANPICK_APR_PERCENT_MULTIPLY_PER_HOUR;
   result["WEBANPICK_APR_PERCENT_MULTIPLY_PER_ROUND"] = WEBANPICK_APR_PERCENT_MULTIPLY_PER_ROUND;
   result["WEBANPICK_APR_PERCENT_SHIFT_PER_BLOCK"] = WEBANPICK_APR_PERCENT_SHIFT_PER_BLOCK;
   result["WEBANPICK_APR_PERCENT_SHIFT_PER_HOUR"] = WEBANPICK_APR_PERCENT_SHIFT_PER_HOUR;
   result["WEBANPICK_APR_PERCENT_SHIFT_PER_ROUND"] = WEBANPICK_APR_PERCENT_SHIFT_PER_ROUND;
   result["WEBANPICK_BANDWIDTH_AVERAGE_WINDOW_SECONDS"] = WEBANPICK_BANDWIDTH_AVERAGE_WINDOW_SECONDS;
   result["WEBANPICK_BANDWIDTH_PRECISION"] = WEBANPICK_BANDWIDTH_PRECISION;
   result["WEBANPICK_BLOCKCHAIN_PRECISION"] = WEBANPICK_BLOCKCHAIN_PRECISION;
   result["WEBANPICK_BLOCKCHAIN_PRECISION_DIGITS"] = WEBANPICK_BLOCKCHAIN_PRECISION_DIGITS;
   result["WEBANPICK_BLOCKCHAIN_HARDFORK_VERSION"] = WEBANPICK_BLOCKCHAIN_HARDFORK_VERSION;
   result["WEBANPICK_BLOCKCHAIN_VERSION"] = WEBANPICK_BLOCKCHAIN_VERSION;
   result["WEBANPICK_BLOCK_INTERVAL"] = WEBANPICK_BLOCK_INTERVAL;
   result["WEBANPICK_BLOCKS_PER_DAY"] = WEBANPICK_BLOCKS_PER_DAY;
   result["WEBANPICK_BLOCKS_PER_HOUR"] = WEBANPICK_BLOCKS_PER_HOUR;
   result["WEBANPICK_BLOCKS_PER_YEAR"] = WEBANPICK_BLOCKS_PER_YEAR;
   result["WEBANPICK_CASHOUT_WINDOW_SECONDS"] = WEBANPICK_CASHOUT_WINDOW_SECONDS;
   result["WEBANPICK_CASHOUT_WINDOW_SECONDS_PRE_HF12"] = WEBANPICK_CASHOUT_WINDOW_SECONDS_PRE_HF12;
   result["WEBANPICK_CASHOUT_WINDOW_SECONDS_PRE_HF17"] = WEBANPICK_CASHOUT_WINDOW_SECONDS_PRE_HF17;
   result["WEBANPICK_CHAIN_ID"] = WEBANPICK_CHAIN_ID;
   result["WEBANPICK_CHAIN_ID_NAME"] = WEBANPICK_CHAIN_ID_NAME;
   result["WEBANPICK_COMMENT_REWARD_FUND_NAME"] = WEBANPICK_COMMENT_REWARD_FUND_NAME;
   result["WEBANPICK_CONTENT_APR_PERCENT"] = WEBANPICK_CONTENT_APR_PERCENT;
   result["WEBANPICK_CONTENT_CONSTANT_HF0"] = WEBANPICK_CONTENT_CONSTANT_HF0;
   result["WEBANPICK_CONTENT_REWARD_PERCENT"] = WEBANPICK_CONTENT_REWARD_PERCENT;
   result["WEBANPICK_CONVERSION_DELAY"] = WEBANPICK_CONVERSION_DELAY;
   result["WEBANPICK_CONVERSION_DELAY_PRE_HF_16"] = WEBANPICK_CONVERSION_DELAY_PRE_HF_16;
   result["WEBANPICK_CREATE_ACCOUNT_DELEGATION_RATIO"] = WEBANPICK_CREATE_ACCOUNT_DELEGATION_RATIO;
   result["WEBANPICK_CREATE_ACCOUNT_DELEGATION_TIME"] = WEBANPICK_CREATE_ACCOUNT_DELEGATION_TIME;
   result["WEBANPICK_CREATE_ACCOUNT_WITH_WEBANPICK_MODIFIER"] = WEBANPICK_CREATE_ACCOUNT_WITH_WEBANPICK_MODIFIER;
   result["WEBANPICK_CURATE_APR_PERCENT"] = WEBANPICK_CURATE_APR_PERCENT;
   result["WEBANPICK_DEFAULT_SBD_INTEREST_RATE"] = WEBANPICK_DEFAULT_SBD_INTEREST_RATE;
   result["WEBANPICK_EQUIHASH_K"] = WEBANPICK_EQUIHASH_K;
   result["WEBANPICK_EQUIHASH_N"] = WEBANPICK_EQUIHASH_N;
   result["WEBANPICK_FEED_HISTORY_WINDOW"] = WEBANPICK_FEED_HISTORY_WINDOW;
   result["WEBANPICK_FEED_HISTORY_WINDOW_PRE_HF_16"] = WEBANPICK_FEED_HISTORY_WINDOW_PRE_HF_16;
   result["WEBANPICK_FEED_INTERVAL_BLOCKS"] = WEBANPICK_FEED_INTERVAL_BLOCKS;
   result["WEBANPICK_GENESIS_TIME"] = WEBANPICK_GENESIS_TIME;
   result["WEBANPICK_HARDFORK_REQUIRED_WITNESSES"] = WEBANPICK_HARDFORK_REQUIRED_WITNESSES;
   result["WEBANPICK_INFLATION_NARROWING_PERIOD"] = WEBANPICK_INFLATION_NARROWING_PERIOD;
   result["WEBANPICK_INFLATION_RATE_START_PERCENT"] = WEBANPICK_INFLATION_RATE_START_PERCENT;
   result["WEBANPICK_INFLATION_RATE_STOP_PERCENT"] = WEBANPICK_INFLATION_RATE_STOP_PERCENT;
   result["WEBANPICK_INIT_MINER_NAME"] = WEBANPICK_INIT_MINER_NAME;
   result["WEBANPICK_INIT_PUBLIC_KEY_STR"] = WEBANPICK_INIT_PUBLIC_KEY_STR;
#if 0
   // do not expose private key, period.
   // we need this line present but inactivated so CI check for all constants in config.hpp doesn't complain.
   result["WEBANPICK_INIT_PRIVATE_KEY"] = WEBANPICK_INIT_PRIVATE_KEY;
#endif
   result["WEBANPICK_INIT_SUPPLY"] = WEBANPICK_INIT_SUPPLY;
   result["WEBANPICK_INIT_TIME"] = WEBANPICK_INIT_TIME;
   result["WEBANPICK_IRREVERSIBLE_THRESHOLD"] = WEBANPICK_IRREVERSIBLE_THRESHOLD;
   result["WEBANPICK_LIQUIDITY_APR_PERCENT"] = WEBANPICK_LIQUIDITY_APR_PERCENT;
   result["WEBANPICK_LIQUIDITY_REWARD_BLOCKS"] = WEBANPICK_LIQUIDITY_REWARD_BLOCKS;
   result["WEBANPICK_LIQUIDITY_REWARD_PERIOD_SEC"] = WEBANPICK_LIQUIDITY_REWARD_PERIOD_SEC;
   result["WEBANPICK_LIQUIDITY_TIMEOUT_SEC"] = WEBANPICK_LIQUIDITY_TIMEOUT_SEC;
   result["WEBANPICK_MAX_ACCOUNT_NAME_LENGTH"] = WEBANPICK_MAX_ACCOUNT_NAME_LENGTH;
   result["WEBANPICK_MAX_ACCOUNT_WITNESS_VOTES"] = WEBANPICK_MAX_ACCOUNT_WITNESS_VOTES;
   result["WEBANPICK_MAX_ASSET_WHITELIST_AUTHORITIES"] = WEBANPICK_MAX_ASSET_WHITELIST_AUTHORITIES;
   result["WEBANPICK_MAX_AUTHORITY_MEMBERSHIP"] = WEBANPICK_MAX_AUTHORITY_MEMBERSHIP;
   result["WEBANPICK_MAX_BLOCK_SIZE"] = WEBANPICK_MAX_BLOCK_SIZE;
   result["WEBANPICK_SOFT_MAX_BLOCK_SIZE"] = WEBANPICK_SOFT_MAX_BLOCK_SIZE;
   result["WEBANPICK_MAX_CASHOUT_WINDOW_SECONDS"] = WEBANPICK_MAX_CASHOUT_WINDOW_SECONDS;
   result["WEBANPICK_MAX_COMMENT_DEPTH"] = WEBANPICK_MAX_COMMENT_DEPTH;
   result["WEBANPICK_MAX_COMMENT_DEPTH_PRE_HF17"] = WEBANPICK_MAX_COMMENT_DEPTH_PRE_HF17;
   result["WEBANPICK_MAX_FEED_AGE_SECONDS"] = WEBANPICK_MAX_FEED_AGE_SECONDS;
   result["WEBANPICK_MAX_INSTANCE_ID"] = WEBANPICK_MAX_INSTANCE_ID;
   result["WEBANPICK_MAX_MEMO_SIZE"] = WEBANPICK_MAX_MEMO_SIZE;
   result["WEBANPICK_MAX_WITNESSES"] = WEBANPICK_MAX_WITNESSES;
   result["WEBANPICK_MAX_MINER_WITNESSES_HF0"] = WEBANPICK_MAX_MINER_WITNESSES_HF0;
   result["WEBANPICK_MAX_MINER_WITNESSES_HF17"] = WEBANPICK_MAX_MINER_WITNESSES_HF17;
   result["WEBANPICK_MAX_PERMLINK_LENGTH"] = WEBANPICK_MAX_PERMLINK_LENGTH;
   result["WEBANPICK_MAX_PROXY_RECURSION_DEPTH"] = WEBANPICK_MAX_PROXY_RECURSION_DEPTH;
   result["WEBANPICK_MAX_RATION_DECAY_RATE"] = WEBANPICK_MAX_RATION_DECAY_RATE;
   result["WEBANPICK_MAX_RESERVE_RATIO"] = WEBANPICK_MAX_RESERVE_RATIO;
   result["WEBANPICK_MAX_RUNNER_WITNESSES_HF0"] = WEBANPICK_MAX_RUNNER_WITNESSES_HF0;
   result["WEBANPICK_MAX_RUNNER_WITNESSES_HF17"] = WEBANPICK_MAX_RUNNER_WITNESSES_HF17;
   result["WEBANPICK_MAX_SATOSHIS"] = WEBANPICK_MAX_SATOSHIS;
   result["WEBANPICK_MAX_SHARE_SUPPLY"] = WEBANPICK_MAX_SHARE_SUPPLY;
   result["WEBANPICK_MAX_SIG_CHECK_DEPTH"] = WEBANPICK_MAX_SIG_CHECK_DEPTH;
   result["WEBANPICK_MAX_TIME_UNTIL_EXPIRATION"] = WEBANPICK_MAX_TIME_UNTIL_EXPIRATION;
   result["WEBANPICK_MAX_TRANSACTION_SIZE"] = WEBANPICK_MAX_TRANSACTION_SIZE;
   result["WEBANPICK_MAX_UNDO_HISTORY"] = WEBANPICK_MAX_UNDO_HISTORY;
   result["WEBANPICK_MAX_URL_LENGTH"] = WEBANPICK_MAX_URL_LENGTH;
   result["WEBANPICK_MAX_VOTE_CHANGES"] = WEBANPICK_MAX_VOTE_CHANGES;
   result["WEBANPICK_MAX_VOTED_WITNESSES_HF0"] = WEBANPICK_MAX_VOTED_WITNESSES_HF0;
   result["WEBANPICK_MAX_VOTED_WITNESSES_HF17"] = WEBANPICK_MAX_VOTED_WITNESSES_HF17;
   result["WEBANPICK_MAX_WITHDRAW_ROUTES"] = WEBANPICK_MAX_WITHDRAW_ROUTES;
   result["WEBANPICK_MAX_WITNESS_URL_LENGTH"] = WEBANPICK_MAX_WITNESS_URL_LENGTH;
   result["WEBANPICK_MIN_ACCOUNT_CREATION_FEE"] = WEBANPICK_MIN_ACCOUNT_CREATION_FEE;
   result["WEBANPICK_MIN_ACCOUNT_NAME_LENGTH"] = WEBANPICK_MIN_ACCOUNT_NAME_LENGTH;
   result["WEBANPICK_MIN_BLOCK_SIZE_LIMIT"] = WEBANPICK_MIN_BLOCK_SIZE_LIMIT;
   result["WEBANPICK_MIN_BLOCK_SIZE"] = WEBANPICK_MIN_BLOCK_SIZE;
   result["WEBANPICK_MIN_CONTENT_REWARD"] = WEBANPICK_MIN_CONTENT_REWARD;
   result["WEBANPICK_MIN_CURATE_REWARD"] = WEBANPICK_MIN_CURATE_REWARD;
   result["WEBANPICK_MIN_PERMLINK_LENGTH"] = WEBANPICK_MIN_PERMLINK_LENGTH;
   result["WEBANPICK_MIN_REPLY_INTERVAL"] = WEBANPICK_MIN_REPLY_INTERVAL;
   result["WEBANPICK_MIN_ROOT_COMMENT_INTERVAL"] = WEBANPICK_MIN_ROOT_COMMENT_INTERVAL;
   result["WEBANPICK_MIN_VOTE_INTERVAL_SEC"] = WEBANPICK_MIN_VOTE_INTERVAL_SEC;
   result["WEBANPICK_MINER_ACCOUNT"] = WEBANPICK_MINER_ACCOUNT;
   result["WEBANPICK_MINER_PAY_PERCENT"] = WEBANPICK_MINER_PAY_PERCENT;
   result["WEBANPICK_MIN_FEEDS"] = WEBANPICK_MIN_FEEDS;
   result["WEBANPICK_MINING_REWARD"] = WEBANPICK_MINING_REWARD;
   result["WEBANPICK_MINING_TIME"] = WEBANPICK_MINING_TIME;
   result["WEBANPICK_MIN_LIQUIDITY_REWARD"] = WEBANPICK_MIN_LIQUIDITY_REWARD;
   result["WEBANPICK_MIN_LIQUIDITY_REWARD_PERIOD_SEC"] = WEBANPICK_MIN_LIQUIDITY_REWARD_PERIOD_SEC;
   result["WEBANPICK_MIN_PAYOUT_SBD"] = WEBANPICK_MIN_PAYOUT_SBD;
   result["WEBANPICK_MIN_POW_REWARD"] = WEBANPICK_MIN_POW_REWARD;
   result["WEBANPICK_MIN_PRODUCER_REWARD"] = WEBANPICK_MIN_PRODUCER_REWARD;
   result["WEBANPICK_MIN_TRANSACTION_EXPIRATION_LIMIT"] = WEBANPICK_MIN_TRANSACTION_EXPIRATION_LIMIT;
   result["WEBANPICK_MIN_TRANSACTION_SIZE_LIMIT"] = WEBANPICK_MIN_TRANSACTION_SIZE_LIMIT;
   result["WEBANPICK_MIN_UNDO_HISTORY"] = WEBANPICK_MIN_UNDO_HISTORY;
   result["WEBANPICK_NULL_ACCOUNT"] = WEBANPICK_NULL_ACCOUNT;
   result["WEBANPICK_NUM_INIT_MINERS"] = WEBANPICK_NUM_INIT_MINERS;
   result["WEBANPICK_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM"] = WEBANPICK_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM;
   result["WEBANPICK_OWNER_AUTH_RECOVERY_PERIOD"] = WEBANPICK_OWNER_AUTH_RECOVERY_PERIOD;
   result["WEBANPICK_OWNER_CHALLENGE_COOLDOWN"] = WEBANPICK_OWNER_CHALLENGE_COOLDOWN;
   result["WEBANPICK_OWNER_CHALLENGE_FEE"] = WEBANPICK_OWNER_CHALLENGE_FEE;
   result["WEBANPICK_OWNER_UPDATE_LIMIT"] = WEBANPICK_OWNER_UPDATE_LIMIT;
   result["WEBANPICK_POST_AVERAGE_WINDOW"] = WEBANPICK_POST_AVERAGE_WINDOW;
   result["WEBANPICK_POST_REWARD_FUND_NAME"] = WEBANPICK_POST_REWARD_FUND_NAME;
   result["WEBANPICK_POST_WEIGHT_CONSTANT"] = WEBANPICK_POST_WEIGHT_CONSTANT;
   result["WEBANPICK_POW_APR_PERCENT"] = WEBANPICK_POW_APR_PERCENT;
   result["WEBANPICK_PRODUCER_APR_PERCENT"] = WEBANPICK_PRODUCER_APR_PERCENT;
   result["WEBANPICK_PROXY_TO_SELF_ACCOUNT"] = WEBANPICK_PROXY_TO_SELF_ACCOUNT;
   result["WEBANPICK_SBD_INTEREST_COMPOUND_INTERVAL_SEC"] = WEBANPICK_SBD_INTEREST_COMPOUND_INTERVAL_SEC;
   result["WEBANPICK_SECONDS_PER_YEAR"] = WEBANPICK_SECONDS_PER_YEAR;
   result["WEBANPICK_RECENT_RSHARES_DECAY_TIME_HF19"] = WEBANPICK_RECENT_RSHARES_DECAY_TIME_HF19;
   result["WEBANPICK_RECENT_RSHARES_DECAY_TIME_HF17"] = WEBANPICK_RECENT_RSHARES_DECAY_TIME_HF17;
   result["WEBANPICK_REVERSE_AUCTION_WINDOW_SECONDS"] = WEBANPICK_REVERSE_AUCTION_WINDOW_SECONDS;
   result["WEBANPICK_ROOT_POST_PARENT"] = WEBANPICK_ROOT_POST_PARENT;
   result["WEBANPICK_SAVINGS_WITHDRAW_REQUEST_LIMIT"] = WEBANPICK_SAVINGS_WITHDRAW_REQUEST_LIMIT;
   result["WEBANPICK_SAVINGS_WITHDRAW_TIME"] = WEBANPICK_SAVINGS_WITHDRAW_TIME;
   result["WEBANPICK_SBD_START_PERCENT"] = WEBANPICK_SBD_START_PERCENT;
   result["WEBANPICK_SBD_STOP_PERCENT"] = WEBANPICK_SBD_STOP_PERCENT;
   result["WEBANPICK_SECOND_CASHOUT_WINDOW"] = WEBANPICK_SECOND_CASHOUT_WINDOW;
   result["WEBANPICK_SOFT_MAX_COMMENT_DEPTH"] = WEBANPICK_SOFT_MAX_COMMENT_DEPTH;
   result["WEBANPICK_START_MINER_VOTING_BLOCK"] = WEBANPICK_START_MINER_VOTING_BLOCK;
   result["WEBANPICK_START_VESTING_BLOCK"] = WEBANPICK_START_VESTING_BLOCK;
   result["WEBANPICK_TEMP_ACCOUNT"] = WEBANPICK_TEMP_ACCOUNT;
   result["WEBANPICK_UPVOTE_LOCKOUT_HF7"] = WEBANPICK_UPVOTE_LOCKOUT_HF7;
   result["WEBANPICK_UPVOTE_LOCKOUT_HF17"] = WEBANPICK_UPVOTE_LOCKOUT_HF17;
   result["WEBANPICK_VESTING_FUND_PERCENT"] = WEBANPICK_VESTING_FUND_PERCENT;
   result["WEBANPICK_VESTING_WITHDRAW_INTERVALS"] = WEBANPICK_VESTING_WITHDRAW_INTERVALS;
   result["WEBANPICK_VESTING_WITHDRAW_INTERVALS_PRE_HF_16"] = WEBANPICK_VESTING_WITHDRAW_INTERVALS_PRE_HF_16;
   result["WEBANPICK_VESTING_WITHDRAW_INTERVAL_SECONDS"] = WEBANPICK_VESTING_WITHDRAW_INTERVAL_SECONDS;
   result["WEBANPICK_VOTE_DUST_THRESHOLD"] = WEBANPICK_VOTE_DUST_THRESHOLD;
   result["WEBANPICK_VOTE_REGENERATION_SECONDS"] = WEBANPICK_VOTE_REGENERATION_SECONDS;
   result["WEBANPICK_SYMBOL"] = WEBANPICK_SYMBOL;
   result["VESTS_SYMBOL"] = VESTS_SYMBOL;
   result["WEBANPICK_VIRTUAL_SCHEDULE_LAP_LENGTH"] = WEBANPICK_VIRTUAL_SCHEDULE_LAP_LENGTH;
   result["WEBANPICK_VIRTUAL_SCHEDULE_LAP_LENGTH2"] = WEBANPICK_VIRTUAL_SCHEDULE_LAP_LENGTH2;

   return result;
}

} } // webanpick::protocol