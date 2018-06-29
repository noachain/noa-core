/*#ifndef MODEL_MARKET_EVALUATOR_HPP
#define MODEL_MARKET_EVALUATOR_HPP

#endif // MODEL_MARKET_EVALUATOR_HPP
*/
#pragma once

#include <graphene/chain/protocol/operations.hpp>
#include <graphene/chain/evaluator.hpp>
#include <graphene/chain/database.hpp>
#include <graphene/model_market_object.hpp>
#include <graphene/chain/commitee_member_object.hpp>

namespace graphene { namespace chain {

   class model_market_category_create_evaluator : public evaluator<model_market_category_create_evaluator>
   {
      public:
         typedef model_market_category_create_operation operation_type;

         void_result do_evaluate( const model_market_category_create_operation& o )
    {
        return void_result();
    }
         object_id_type do_apply( const model_market_category_create_operation& o )
    {
        model_market_category_id_type id;
        return id;
    }
   };
   class model_market_category_update_evaluator : public evaluator<model_market_category_update_evaluator>
   {
      public:
         typedef model_market_category_update_operation operation_type;

         void_result do_evaluate( const model_market_category_update_operation& o )
    {
        return void_result();
    }
         void_result do_apply( const model_market_category_update_operation& o )
    {
        return void_result();
    }
   };

} } // graphene::chain
