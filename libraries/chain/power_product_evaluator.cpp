#include <graphene/chain/power_product_evaluator.hpp>
#include <graphene/chain/power_product_object.hpp>
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
        void_result power_product_create_evaluator::do_evaluate(const power_product_create_operation&o)
        {
            return void_result();
        }

        object_id_type power_product_create_evaluator::do_apply(const power_product_create_operation&o)
        {
            power_product_id_type id;
            return id;
        }

        void_result power_product_update_evaluator::do_evaluate(const power_product_update_operation&o)
        {
            return void_result();
        }

        object_id_type power_product_update_evaluator::do_apply(const power_product_update_operation&o)
        {
            power_product_id_type id;
            return id;
        }
    }
}
