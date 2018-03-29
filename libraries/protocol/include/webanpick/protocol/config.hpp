/*
 * Copyright (c) 2016 webanpickit, Inc., and contributors.
 */
#pragma once
#include <webanpick/protocol/hardfork.hpp>

// WARNING!
// Every symbol defined here needs to be handled appropriately in get_config.cpp
// This is checked by get_config_check.sh called from Dockerfile

#ifdef IS_TEST_NET
#define WEBANPICK_BLOCKCHAIN_VERSION              ( version(0, 21, 0) )

#define WEBANPICK_INIT_PRIVATE_KEY                (fc::ecc::private_key::regenerate(fc::sha256::hash(std::string("init_key"))))
#define WEBANPICK_INIT_PUBLIC_KEY_STR             (std::string( webanpick::protocol::public_key_type(WEBANPICK_INIT_PRIVATE_KEY.get_public_key()) ))
#define WEBANPICK_CHAIN_ID_NAME "testnet"
#define WEBANPICK_CHAIN_ID (fc::sha256::hash(WEBANPICK_CHAIN_ID_NAME))
#define WEBANPICK_ADDRESS_PREFIX                  "TST"

#define WEBANPICK_GENESIS_TIME                    (fc::time_point_sec(1451606400))
#define WEBANPICK_MINING_TIME                     (fc::time_point_sec(1451606400))
#define WEBANPICK_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define WEBANPICK_CASHOUT_WINDOW_SECONDS_PRE_HF12 (WEBANPICK_CASHOUT_WINDOW_SECONDS)
#define WEBANPICK_CASHOUT_WINDOW_SECONDS_PRE_HF17 (WEBANPICK_CASHOUT_WINDOW_SECONDS)
#define WEBANPICK_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define WEBANPICK_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define WEBANPICK_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define WEBANPICK_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define WEBANPICK_MIN_ACCOUNT_CREATION_FEE          0

#define WEBANPICK_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define WEBANPICK_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define WEBANPICK_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define WEBANPICK_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1

#define WEBANPICK_INIT_SUPPLY                     (int64_t( 250 ) * int64_t( 1000000 ) * int64_t( 1000 ))

/// Allows to limit number of total produced blocks.
#define TESTNET_BLOCK_LIMIT                   (3000000)

#else // IS LIVE WEBANPICK NETWORK

#define WEBANPICK_BLOCKCHAIN_VERSION              ( version(0, 19, 4) )

#define WEBANPICK_INIT_PUBLIC_KEY_STR             "STM8GC13uCZbP44HzMLV6zPZGwVQ8Nt4Kji8PapsPiNq1BK153XTX"
#define WEBANPICK_CHAIN_ID_NAME ""
#define WEBANPICK_CHAIN_ID fc::sha256()
#define WEBANPICK_ADDRESS_PREFIX                  "STM"

#define WEBANPICK_GENESIS_TIME                    (fc::time_point_sec(1458835200))
#define WEBANPICK_MINING_TIME                     (fc::time_point_sec(1458838800))
#define WEBANPICK_CASHOUT_WINDOW_SECONDS_PRE_HF12 (60*60*24)    /// 1 day
#define WEBANPICK_CASHOUT_WINDOW_SECONDS_PRE_HF17 (60*60*12)    /// 12 hours
#define WEBANPICK_CASHOUT_WINDOW_SECONDS          (60*60*24*7)  /// 7 days
#define WEBANPICK_SECOND_CASHOUT_WINDOW           (60*60*24*30) /// 30 days
#define WEBANPICK_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24*14) /// 2 weeks
#define WEBANPICK_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define WEBANPICK_UPVOTE_LOCKOUT_HF17             (fc::hours(12))

#define WEBANPICK_MIN_ACCOUNT_CREATION_FEE           1

#define WEBANPICK_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
#define WEBANPICK_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define WEBANPICK_OWNER_UPDATE_LIMIT                          fc::minutes(60)
#define WEBANPICK_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 3186477

#define WEBANPICK_INIT_SUPPLY                     int64_t(0)

#endif

#define VESTS_SYMBOL  (webanpick::protocol::asset_symbol_type::from_asset_num( WEBANPICK_ASSET_NUM_VESTS ) )
#define WEBANPICK_SYMBOL  (webanpick::protocol::asset_symbol_type::from_asset_num( WEBANPICK_ASSET_NUM_WEBANPICK ) )
#define SBD_SYMBOL    (webanpick::protocol::asset_symbol_type::from_asset_num( WEBANPICK_ASSET_NUM_SBD ) )

#define WEBANPICK_BLOCKCHAIN_HARDFORK_VERSION     ( hardfork_version( WEBANPICK_BLOCKCHAIN_VERSION ) )

#define WEBANPICK_BLOCK_INTERVAL                  3
#define WEBANPICK_BLOCKS_PER_YEAR                 (365*24*60*60/WEBANPICK_BLOCK_INTERVAL)
#define WEBANPICK_BLOCKS_PER_DAY                  (24*60*60/WEBANPICK_BLOCK_INTERVAL)
#define WEBANPICK_START_VESTING_BLOCK             (WEBANPICK_BLOCKS_PER_DAY * 7)
#define WEBANPICK_START_MINER_VOTING_BLOCK        (WEBANPICK_BLOCKS_PER_DAY * 30)

#define WEBANPICK_INIT_MINER_NAME                 "initminer"
#define WEBANPICK_NUM_INIT_MINERS                 1
#define WEBANPICK_INIT_TIME                       (fc::time_point_sec());

#define WEBANPICK_MAX_WITNESSES                   21

#define WEBANPICK_MAX_VOTED_WITNESSES_HF0         19
#define WEBANPICK_MAX_MINER_WITNESSES_HF0         1
#define WEBANPICK_MAX_RUNNER_WITNESSES_HF0        1

#define WEBANPICK_MAX_VOTED_WITNESSES_HF17        20
#define WEBANPICK_MAX_MINER_WITNESSES_HF17        0
#define WEBANPICK_MAX_RUNNER_WITNESSES_HF17       1

#define WEBANPICK_HARDFORK_REQUIRED_WITNESSES     17 // 17 of the 21 dpos witnesses (20 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.
#define WEBANPICK_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define WEBANPICK_MAX_MEMO_SIZE                   2048
#define WEBANPICK_MAX_PROXY_RECURSION_DEPTH       4
#define WEBANPICK_VESTING_WITHDRAW_INTERVALS_PRE_HF_16 104
#define WEBANPICK_VESTING_WITHDRAW_INTERVALS      13
#define WEBANPICK_VESTING_WITHDRAW_INTERVAL_SECONDS (60*60*24*7) /// 1 week per interval
#define WEBANPICK_MAX_WITHDRAW_ROUTES             10
#define WEBANPICK_SAVINGS_WITHDRAW_TIME        	(fc::days(3))
#define WEBANPICK_SAVINGS_WITHDRAW_REQUEST_LIMIT  100
#define WEBANPICK_VOTE_REGENERATION_SECONDS       (5*60*60*24) // 5 day
#define WEBANPICK_MAX_VOTE_CHANGES                5
#define WEBANPICK_REVERSE_AUCTION_WINDOW_SECONDS  (60*30) /// 30 minutes
#define WEBANPICK_MIN_VOTE_INTERVAL_SEC           3
#define WEBANPICK_VOTE_DUST_THRESHOLD             (50000000)

#define WEBANPICK_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(60*5)) // 5 minutes
#define WEBANPICK_MIN_REPLY_INTERVAL              (fc::seconds(20)) // 20 seconds
#define WEBANPICK_POST_AVERAGE_WINDOW             (60*60*24u) // 1 day
#define WEBANPICK_POST_WEIGHT_CONSTANT            (uint64_t(4*WEBANPICK_100_PERCENT) * (4*WEBANPICK_100_PERCENT))// (4*WEBANPICK_100_PERCENT) -> 2 posts per 1 days, average 1 every 12 hours

#define WEBANPICK_MAX_ACCOUNT_WITNESS_VOTES       30

#define WEBANPICK_100_PERCENT                     10000
#define WEBANPICK_1_PERCENT                       (WEBANPICK_100_PERCENT/100)
#define WEBANPICK_DEFAULT_SBD_INTEREST_RATE       (10*WEBANPICK_1_PERCENT) ///< 10% APR

#define WEBANPICK_INFLATION_RATE_START_PERCENT    (978) // Fixes block 7,000,000 to 9.5%
#define WEBANPICK_INFLATION_RATE_STOP_PERCENT     (95) // 0.95%
#define WEBANPICK_INFLATION_NARROWING_PERIOD      (250000) // Narrow 0.01% every 250k blocks
#define WEBANPICK_CONTENT_REWARD_PERCENT          (75*WEBANPICK_1_PERCENT) //75% of inflation, 7.125% inflation
#define WEBANPICK_VESTING_FUND_PERCENT            (15*WEBANPICK_1_PERCENT) //15% of inflation, 1.425% inflation

#define WEBANPICK_MINER_PAY_PERCENT               (WEBANPICK_1_PERCENT) // 1%
#define WEBANPICK_MAX_RATION_DECAY_RATE           (1000000)

#define WEBANPICK_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define WEBANPICK_BANDWIDTH_PRECISION             (uint64_t(1000000)) ///< 1 million
#define WEBANPICK_MAX_COMMENT_DEPTH_PRE_HF17      6
#define WEBANPICK_MAX_COMMENT_DEPTH               0xffff // 64k
#define WEBANPICK_SOFT_MAX_COMMENT_DEPTH          0xff // 255

#define WEBANPICK_MAX_RESERVE_RATIO               (20000)

#define WEBANPICK_CREATE_ACCOUNT_WITH_WEBANPICK_MODIFIER 30
#define WEBANPICK_CREATE_ACCOUNT_DELEGATION_RATIO    5
#define WEBANPICK_CREATE_ACCOUNT_DELEGATION_TIME     fc::days(30)

#define WEBANPICK_MINING_REWARD                   asset( 1000, WEBANPICK_SYMBOL )
#define WEBANPICK_EQUIHASH_N                      140
#define WEBANPICK_EQUIHASH_K                      6

#define WEBANPICK_LIQUIDITY_TIMEOUT_SEC           (fc::seconds(60*60*24*7)) // After one week volume is set to 0
#define WEBANPICK_MIN_LIQUIDITY_REWARD_PERIOD_SEC (fc::seconds(60)) // 1 minute required on books to receive volume
#define WEBANPICK_LIQUIDITY_REWARD_PERIOD_SEC     (60*60)
#define WEBANPICK_LIQUIDITY_REWARD_BLOCKS         (WEBANPICK_LIQUIDITY_REWARD_PERIOD_SEC/WEBANPICK_BLOCK_INTERVAL)
#define WEBANPICK_MIN_LIQUIDITY_REWARD            (asset( 1000*WEBANPICK_LIQUIDITY_REWARD_BLOCKS, WEBANPICK_SYMBOL )) // Minumum reward to be paid out to liquidity providers
#define WEBANPICK_MIN_CONTENT_REWARD              WEBANPICK_MINING_REWARD
#define WEBANPICK_MIN_CURATE_REWARD               WEBANPICK_MINING_REWARD
#define WEBANPICK_MIN_PRODUCER_REWARD             WEBANPICK_MINING_REWARD
#define WEBANPICK_MIN_POW_REWARD                  WEBANPICK_MINING_REWARD

#define WEBANPICK_ACTIVE_CHALLENGE_FEE            asset( 2000, WEBANPICK_SYMBOL )
#define WEBANPICK_OWNER_CHALLENGE_FEE             asset( 30000, WEBANPICK_SYMBOL )
#define WEBANPICK_ACTIVE_CHALLENGE_COOLDOWN       fc::days(1)
#define WEBANPICK_OWNER_CHALLENGE_COOLDOWN        fc::days(1)

#define WEBANPICK_POST_REWARD_FUND_NAME           ("post")
#define WEBANPICK_COMMENT_REWARD_FUND_NAME        ("comment")
#define WEBANPICK_RECENT_RSHARES_DECAY_TIME_HF17    (fc::days(30))
#define WEBANPICK_RECENT_RSHARES_DECAY_TIME_HF19    (fc::days(15))
#define WEBANPICK_CONTENT_CONSTANT_HF0            (uint128_t(uint64_t(2000000000000ll)))
// note, if redefining these constants make sure calculate_claims doesn't overflow

// 5ccc e802 de5f
// int(expm1( log1p( 1 ) / BLOCKS_PER_YEAR ) * 2**WEBANPICK_APR_PERCENT_SHIFT_PER_BLOCK / 100000 + 0.5)
// we use 100000 here instead of 10000 because we end up creating an additional 9x for vesting
#define WEBANPICK_APR_PERCENT_MULTIPLY_PER_BLOCK          ( (uint64_t( 0x5ccc ) << 0x20) \
                                                        | (uint64_t( 0xe802 ) << 0x10) \
                                                        | (uint64_t( 0xde5f )        ) \
                                                        )
// chosen to be the maximal value such that WEBANPICK_APR_PERCENT_MULTIPLY_PER_BLOCK * 2**64 * 100000 < 2**128
#define WEBANPICK_APR_PERCENT_SHIFT_PER_BLOCK             87

#define WEBANPICK_APR_PERCENT_MULTIPLY_PER_ROUND          ( (uint64_t( 0x79cc ) << 0x20 ) \
                                                        | (uint64_t( 0xf5c7 ) << 0x10 ) \
                                                        | (uint64_t( 0x3480 )         ) \
                                                        )

#define WEBANPICK_APR_PERCENT_SHIFT_PER_ROUND             83

// We have different constants for hourly rewards
// i.e. hex(int(math.expm1( math.log1p( 1 ) / HOURS_PER_YEAR ) * 2**WEBANPICK_APR_PERCENT_SHIFT_PER_HOUR / 100000 + 0.5))
#define WEBANPICK_APR_PERCENT_MULTIPLY_PER_HOUR           ( (uint64_t( 0x6cc1 ) << 0x20) \
                                                        | (uint64_t( 0x39a1 ) << 0x10) \
                                                        | (uint64_t( 0x5cbd )        ) \
                                                        )

// chosen to be the maximal value such that WEBANPICK_APR_PERCENT_MULTIPLY_PER_HOUR * 2**64 * 100000 < 2**128
#define WEBANPICK_APR_PERCENT_SHIFT_PER_HOUR              77

// These constants add up to GRAPHENE_100_PERCENT.  Each GRAPHENE_1_PERCENT is equivalent to 1% per year APY
// *including the corresponding 9x vesting rewards*
#define WEBANPICK_CURATE_APR_PERCENT              3875
#define WEBANPICK_CONTENT_APR_PERCENT             3875
#define WEBANPICK_LIQUIDITY_APR_PERCENT            750
#define WEBANPICK_PRODUCER_APR_PERCENT             750
#define WEBANPICK_POW_APR_PERCENT                  750

#define WEBANPICK_MIN_PAYOUT_SBD                  (asset(20,SBD_SYMBOL))

#define WEBANPICK_SBD_STOP_PERCENT                (5*WEBANPICK_1_PERCENT ) // Stop printing SBD at 5% Market Cap
#define WEBANPICK_SBD_START_PERCENT               (2*WEBANPICK_1_PERCENT) // Start reducing printing of SBD at 2% Market Cap

#define WEBANPICK_MIN_ACCOUNT_NAME_LENGTH          3
#define WEBANPICK_MAX_ACCOUNT_NAME_LENGTH         16

#define WEBANPICK_MIN_PERMLINK_LENGTH             0
#define WEBANPICK_MAX_PERMLINK_LENGTH             256
#define WEBANPICK_MAX_WITNESS_URL_LENGTH          2048

#define WEBANPICK_MAX_SHARE_SUPPLY                int64_t(1000000000000000ll)
#define WEBANPICK_MAX_SATOSHIS                    int64_t(4611686018427387903ll)
#define WEBANPICK_MAX_SIG_CHECK_DEPTH             2

#define WEBANPICK_MIN_TRANSACTION_SIZE_LIMIT      1024
#define WEBANPICK_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

#define WEBANPICK_SBD_INTEREST_COMPOUND_INTERVAL_SEC  (60*60*24*30)
#define WEBANPICK_MAX_TRANSACTION_SIZE            (1024*64)
#define WEBANPICK_MIN_BLOCK_SIZE_LIMIT            (WEBANPICK_MAX_TRANSACTION_SIZE)
#define WEBANPICK_MAX_BLOCK_SIZE                  (WEBANPICK_MAX_TRANSACTION_SIZE*WEBANPICK_BLOCK_INTERVAL*2000)
#define WEBANPICK_SOFT_MAX_BLOCK_SIZE             (2*1024*1024)
#define WEBANPICK_MIN_BLOCK_SIZE                  115
#define WEBANPICK_BLOCKS_PER_HOUR                 (60*60/WEBANPICK_BLOCK_INTERVAL)
#define WEBANPICK_FEED_INTERVAL_BLOCKS            (WEBANPICK_BLOCKS_PER_HOUR)
#define WEBANPICK_FEED_HISTORY_WINDOW_PRE_HF_16   (24*7) /// 7 days * 24 hours per day
#define WEBANPICK_FEED_HISTORY_WINDOW             (12*7) // 3.5 days
#define WEBANPICK_MAX_FEED_AGE_SECONDS            (60*60*24*7) // 7 days
#define WEBANPICK_MIN_FEEDS                       (WEBANPICK_MAX_WITNESSES/3) /// protects the network from conversions before price has been established
#define WEBANPICK_CONVERSION_DELAY_PRE_HF_16      (fc::days(7))
#define WEBANPICK_CONVERSION_DELAY                (fc::hours(WEBANPICK_FEED_HISTORY_WINDOW)) //3.5 day conversion

#define WEBANPICK_MIN_UNDO_HISTORY                10
#define WEBANPICK_MAX_UNDO_HISTORY                10000

#define WEBANPICK_MIN_TRANSACTION_EXPIRATION_LIMIT (WEBANPICK_BLOCK_INTERVAL * 5) // 5 transactions per block
#define WEBANPICK_BLOCKCHAIN_PRECISION            uint64_t( 1000 )

#define WEBANPICK_BLOCKCHAIN_PRECISION_DIGITS     3
#define WEBANPICK_MAX_INSTANCE_ID                 (uint64_t(-1)>>16)
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define WEBANPICK_MAX_AUTHORITY_MEMBERSHIP        10
#define WEBANPICK_MAX_ASSET_WHITELIST_AUTHORITIES 10
#define WEBANPICK_MAX_URL_LENGTH                  127

#define WEBANPICK_IRREVERSIBLE_THRESHOLD          (75 * WEBANPICK_1_PERCENT)

#define WEBANPICK_VIRTUAL_SCHEDULE_LAP_LENGTH  ( fc::uint128(uint64_t(-1)) )
#define WEBANPICK_VIRTUAL_SCHEDULE_LAP_LENGTH2 ( fc::uint128::max_value() )

#define WEBANPICK_INITIAL_VOTE_POWER_RATE (40)
#define WEBANPICK_REDUCED_VOTE_POWER_RATE (10)

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current witnesses
#define WEBANPICK_MINER_ACCOUNT                   "miners"
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define WEBANPICK_NULL_ACCOUNT                    "null"
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define WEBANPICK_TEMP_ACCOUNT                    "temp"
/// Represents the canonical account for specifying you will vote for directly (as opposed to a proxy)
#define WEBANPICK_PROXY_TO_SELF_ACCOUNT           ""
/// Represents the canonical root post parent account
#define WEBANPICK_ROOT_POST_PARENT                (account_name_type())
///@}

#ifdef WEBANPICK_ENABLE_SMT

#define SMT_MAX_VOTABLE_ASSETS 2
#define SMT_VESTING_WITHDRAW_INTERVAL_SECONDS   (60*60*24*7) /// 1 week per interval
#define SMT_UPVOTE_LOCKOUT                      (60*60*12)  /// 12 hours

#endif /// WEBANPICK_ENABLE_SMT

