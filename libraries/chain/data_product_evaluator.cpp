#include <graphene/chain/data_product_evaluator.hpp>
#include <graphene/chain/data_product_object.hpp>
#include <graphene/chain/account_object.hpp>
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
        void_result data_product_create_evaluator::do_evaluate(const data_product_create_operation&o)
        {
           /* try
            {

                return void_result();
            }FC_CAPTURE_AND_RETHROW( (o))*/
            return void_result();
        }

        object_id_type data_product_create_evaluator::do_apply(const data_product_create_operation&o)
        {
            /*try
            {
                return void_result();
            }FC_CAPTURE_AND_RETHROW( (o))*/
            data_product_id_type id;
            return id;
        }

        void_result data_product_update_evaluator::do_evaluate(const data_product_update_operation&o)
        {
           /* try
            {
                return void_result();
            }FC_CAPTURE_AND_RETHROW( (o) )*/
            return void_result();
        }

        object_id_type data_product_update_evaluator::do_apply(const data_product_update_operation&o)
        {
            /*try
            {
                return void_result();
            }FC_CAPTURE_AND_RETHROW( (o))
            */
            data_product_id_type id;
            return id;
        }


    }
}
