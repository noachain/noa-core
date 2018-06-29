/*#ifndef POWER_MARKET_EVALUATOR_HPP
#define POWER_MARKET_EVALUATOR_HPP

#endif // POWER_MARKET_EVALUATOR_HPP
*/
#pragma once
#include <graphene/chain/protocol/operations.hpp>
#include <graphene/chain/evaluator.hpp>
#include <graphene/chain/database.hpp>
#include <graphene/chain/power_market_object.hpp>
#include <graphene/chain/committee_member_object.hpp>

namespace graphene
{
    namespace chain
    {

       class power_market_category_create_evaluator : public evaluator<power_market_category_create_evaluator>
       {
          public:
             typedef power_market_category_create_operation operation_type;

             void_result do_evaluate( const power_market_category_create_operation& o )
            {
                return void_result();
            }
             object_id_type do_apply( const power_market_category_create_operation& o )
            {
                power_market_category_id_type id;
                return id;
            }
       };
       class power_market_category_update_evaluator : public evaluator<power_market_category_update_evaluator>
       {
          public:
             typedef power_market_category_update_operation operation_type;

             void_result do_evaluate( const power_market_category_update_operation& o )
            {
                return void_result();
            }
             void_result do_apply( const power_market_category_update_operation& o )
            {
                return void_result();
            }
       };

    }
} // graphene::chain
