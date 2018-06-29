#include <graphene/chain/model_product_evaluator.hpp>
#include <graphene/chain/model_product_object.hpp>
#include <graphene/chain/market_object.hpp>
#include <graphene/chain/database.hpp>
#include <graphene/chain/exceptions.hpp>
#include <graphene/chain/hardfork.hpp>
#include <graphene/chain/is_authorized_asset.hpp>

#include <functional>

namespace graphene
{
    namespace chain
    {
        void_result model_product_create_evaluator::do_evaluate(const model_product_create_operation&o)
        {
            return void_result();
        }

        object_id_type model_product_create_evaluator::do_apply(const model_product_create_operation&o)
        {
            model_product_id_type id;
            return id;
        }

        void_result model_product_update_evaluator::do_evaluator(const model_product_update_operation&o)
        {
            return void_result();
        }

        object_id_type model_product_update_evaluator::do_apply(const  model_product_update_operation&o)
        {
            model_product_id_type id;
            return id;
        }
    }
}
